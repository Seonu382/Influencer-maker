#pragma once
#include "afxdialogex.h"

#define HAPPYENDING 0
#define BADENDING_1 1
#define BADENDING_2 2


// CEndingDlg 대화 상자

class CEndingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEndingDlg)

public:
	CEndingDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEndingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENDING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_EndingBkg;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedSkipButton();
	int m_nCount;
	int m_EndingType;
};
