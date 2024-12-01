#pragma once
#include "afxdialogex.h"
#include "CLiveDlg.h"
#include "RandomEvent.h"


// CRandomChoiceDlg 대화 상자

class CRandomChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRandomChoiceDlg)

public:
	CRandomChoiceDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRandomChoiceDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANDOMCHOICE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedYesButton();
	afx_msg void OnClickedNoButton();
	bool m_bAfterLive;
	void showRandomResultDlg(bool _Choice);
	CLiveDlg* m_pLiveDlg;
	void setParentDialog(CLiveDlg* pParent);
	virtual BOOL OnInitDialog();
	CStatic m_tRandomEvent;
	RandomEvent m_liveRandomEvent;
	CButton m_btnYesButton;
	CButton m_btnNoButton;
};
