
// exp6.4View.h : Cexp64View ��Ľӿ�
//

#pragma once


class Cexp64View : public CView
{
protected: // �������л�����
	Cexp64View();
	DECLARE_DYNCREATE(Cexp64View)

// ����
public:
	Cexp64Doc* GetDocument() const;

// ����
public:

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
	virtual ~Cexp64View();
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

#ifndef _DEBUG  // exp6.4View.cpp �еĵ��԰汾
inline Cexp64Doc* Cexp64View::GetDocument() const
   { return reinterpret_cast<Cexp64Doc*>(m_pDocument); }
#endif

