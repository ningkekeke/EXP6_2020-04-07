
// exp6.4View.cpp : Cexp64View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &Cexp64View::OnPopout)
END_MESSAGE_MAP()

// Cexp64View ����/����

Cexp64View::Cexp64View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp64View::~Cexp64View()
{
}

BOOL Cexp64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp64View ����

void Cexp64View::OnDraw(CDC* /*pDC*/)
{
	Cexp64Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp64View ��ӡ

BOOL Cexp64View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp64View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp64View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp64View ���

#ifdef _DEBUG
void Cexp64View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp64View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp64Doc* Cexp64View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp64Doc)));
	return (Cexp64Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp64View ��Ϣ�������


void Cexp64View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t = dlg.DoModal();
}
