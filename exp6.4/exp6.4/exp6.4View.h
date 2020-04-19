
// exp6.4View.h : Cexp64View 类的接口
//

#pragma once


class Cexp64View : public CView
{
protected: // 仅从序列化创建
	Cexp64View();
	DECLARE_DYNCREATE(Cexp64View)

// 特性
public:
	Cexp64Doc* GetDocument() const;

// 操作
public:

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
	virtual ~Cexp64View();
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

#ifndef _DEBUG  // exp6.4View.cpp 中的调试版本
inline Cexp64Doc* Cexp64View::GetDocument() const
   { return reinterpret_cast<Cexp64Doc*>(m_pDocument); }
#endif

