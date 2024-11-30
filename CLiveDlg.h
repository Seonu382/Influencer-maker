#pragma once
#include "afxdialogex.h"


// CLiveDlg 대화 상자

class CLiveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLiveDlg)

public:
	CLiveDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLiveDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIVE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void showRandomChoice(bool _afterLive);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
