
// exp6.2View.cpp : Cexp62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp6.2.h"
#endif

#include "exp6.2Doc.h"
#include "exp6.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp62View

IMPLEMENT_DYNCREATE(Cexp62View, CView)

BEGIN_MESSAGE_MAP(Cexp62View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &Cexp62View::OnPopout)
END_MESSAGE_MAP()

// Cexp62View 构造/析构

Cexp62View::Cexp62View()
{
	// TODO: 在此处添加构造代码
	pD = NULL;
}

Cexp62View::~Cexp62View()
{
}

BOOL Cexp62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp62View 绘制

void Cexp62View::OnDraw(CDC* /*pDC*/)
{
	Cexp62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp62View 打印

BOOL Cexp62View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp62View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp62View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp62View 诊断

#ifdef _DEBUG
void Cexp62View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp62Doc* Cexp62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp62Doc)));
	return (Cexp62Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp62View 消息处理程序


void Cexp62View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
}
