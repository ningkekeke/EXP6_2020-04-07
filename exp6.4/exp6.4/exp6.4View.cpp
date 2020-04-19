
// exp6.4View.cpp : Cexp64View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp6.4.h"
#endif

#include "exp6.4Doc.h"
#include "exp6.4View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp64View

IMPLEMENT_DYNCREATE(Cexp64View, CView)

BEGIN_MESSAGE_MAP(Cexp64View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &Cexp64View::OnPopout)
END_MESSAGE_MAP()

// Cexp64View 构造/析构

Cexp64View::Cexp64View()
{
	// TODO: 在此处添加构造代码

}

Cexp64View::~Cexp64View()
{
}

BOOL Cexp64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp64View 绘制

void Cexp64View::OnDraw(CDC* /*pDC*/)
{
	Cexp64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp64View 打印

BOOL Cexp64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp64View 诊断

#ifdef _DEBUG
void Cexp64View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp64Doc* Cexp64View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp64Doc)));
	return (Cexp64Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp64View 消息处理程序


void Cexp64View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
}
