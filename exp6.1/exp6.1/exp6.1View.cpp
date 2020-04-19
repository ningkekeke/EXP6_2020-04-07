
// exp6.1View.cpp : Cexp61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp61View ����/����

Cexp61View::Cexp61View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp61View ����

void Cexp61View::OnDraw(CDC* pDC)
{
	Cexp61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	CRect rect = CRect(Points[0], Points[2]);
	pDC->Rectangle(rect);
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
} 

// Cexp61View ��ӡ

BOOL Cexp61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp61View ���

#ifdef _DEBUG
void Cexp61View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp61Doc* Cexp61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp61Doc)));
	return (Cexp61Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp61View ��Ϣ�������


void Cexp61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	IsReadyToMove = false;   // ��ʼ���һ�²����ƶ�
	if (Points[0].x <= point.x && point.x <= Points[2].x &&
		Points[0].y <= point.y && point.y <= Points[2].y)
	{
		p1 = point;
		IsReadyToMove = true; // ���һ�¿����ƶ���
	}
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}


void Cexp61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (true == IsReadyToMove)
	{
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // ���ù��Ϊ�˸�����   
												  // ���õ�ǰ���λ�úͳ�ʼ��¼��λ�����޸ľ��ε�ÿ�����㣬����ͼ����궯��Ч��
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (true == IsReadyToMove)
	{
		p1 = NULL;      // ����ƶ���Ϣ
	}
	IsReadyToMove = false;   // ���һ�´�ʱ�������ƶ���
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}
