
// exp6.2View.h : Cexp62View ��Ľӿ�
//

#pragma once

#include "MyDlg.h"
class Cexp62View : public CView
{
protected: // �������л�����
	Cexp62View();
	DECLARE_DYNCREATE(Cexp62View)

// ����
public:
	Cexp62Doc* GetDocument() const;

// ����
public:
	MyDlg *pD;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cexp62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // exp6.2View.cpp �еĵ��԰汾
inline Cexp62Doc* Cexp62View::GetDocument() const
   { return reinterpret_cast<Cexp62Doc*>(m_pDocument); }
#endif

