#pragma once
#include "afxdialogex.h"
#include "CMainDlg.h"


// CTrendResultDlg 대화 상자

class CTrendResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTrendResultDlg)

public:
	CTrendResultDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTrendResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRENDRESULT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedNextdayButton();
	void goNextDay();
	void showMainDlg();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
