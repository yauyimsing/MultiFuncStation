﻿
// MultiFuncStationView.cpp: CMultiFuncStationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MultiFuncStation.h"
#endif

#include "MultiFuncStationDoc.h"
#include "MultiFuncStationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiFuncStationView

IMPLEMENT_DYNCREATE(CMultiFuncStationView, CView)

BEGIN_MESSAGE_MAP(CMultiFuncStationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMultiFuncStationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMultiFuncStationView 构造/析构

CMultiFuncStationView::CMultiFuncStationView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMultiFuncStationView::~CMultiFuncStationView()
{
}

BOOL CMultiFuncStationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMultiFuncStationView 绘图

void CMultiFuncStationView::OnDraw(CDC* /*pDC*/)
{
	CMultiFuncStationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMultiFuncStationView 打印


void CMultiFuncStationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMultiFuncStationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMultiFuncStationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMultiFuncStationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMultiFuncStationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMultiFuncStationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultiFuncStationView 诊断

#ifdef _DEBUG
void CMultiFuncStationView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiFuncStationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiFuncStationDoc* CMultiFuncStationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiFuncStationDoc)));
	return (CMultiFuncStationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiFuncStationView 消息处理程序
