
// exp6.2View.h : Cexp62View 类的接口
//

#pragma once

#include "MyDlg.h"
class Cexp62View : public CView
{
protected: // 仅从序列化创建
	Cexp62View();
	DECLARE_DYNCREATE(Cexp62View)

// 特性
public:
	Cexp62Doc* GetDocument() const;

// 操作
public:
	MyDlg *pD;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // exp6.2View.cpp 中的调试版本
inline Cexp62Doc* Cexp62View::GetDocument() const
   { return reinterpret_cast<Cexp62Doc*>(m_pDocument); }
#endif

