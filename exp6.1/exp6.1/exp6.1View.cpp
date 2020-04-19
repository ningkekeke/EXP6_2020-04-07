
// exp6.1View.cpp : Cexp61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp6.1.h"
#endif

#include "exp6.1Doc.h"
#include "exp6.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp61View

IMPLEMENT_DYNCREATE(Cexp61View, CView)

BEGIN_MESSAGE_MAP(Cexp61View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp61View 构造/析构

Cexp61View::Cexp61View()
{
	// TODO: 在此处添加构造代码
	IsReadyToMove = false;
	p1 = 0;
	Points[0] = CPoint(121, 100);
	Points[1] = CPoint(367, 100);
	Points[2] = CPoint(367, 245);
	Points[3] = CPoint(121, 245);
}

Cexp61View::~Cexp61View()
{
}

BOOL Cexp61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp61View 绘制

void Cexp61View::OnDraw(CDC* pDC)
{
	Cexp61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	CRect rect = CRect(Points[0], Points[2]);
	pDC->Rectangle(rect);
	
	// TODO: 在此处为本机数据添加绘制代码
} 

// Cexp61View 打印

BOOL Cexp61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp61View 诊断

#ifdef _DEBUG
void Cexp61View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp61Doc* Cexp61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp61Doc)));
	return (Cexp61Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp61View 消息处理程序


void Cexp61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	IsReadyToMove = false;   // 初始标记一下不能移动
	if (Points[0].x <= point.x && point.x <= Points[2].x &&
		Points[0].y <= point.y && point.y <= Points[2].y)
	{
		p1 = point;
		IsReadyToMove = true; // 标记一下可以移动了
	}
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}


void Cexp61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (true == IsReadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向   
												  // 利用当前鼠标位置和初始记录的位置来修改矩形的每个顶点，做到图随鼠标动的效果
		for (int i = 0; i < 4; i++)
		{
			Points[i] += point - p1;
		}
		p1 = point;
	}
	dc.SetROP2(R2_NOT);
	this->Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void Cexp61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (true == IsReadyToMove)
	{
		p1 = NULL;      // 清空移动信息
	}
	IsReadyToMove = false;   // 标记一下此时不可以移动了
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}
