#pragma once
#include "afxdialogex.h"


// CStoryDlg 대화 상자

class CStoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStoryDlg)

public:
	CStoryDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CStoryDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STORY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void FadeIn();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedSkipButton();
	afx_msg void OnPaint();
	CStatic m_StoryBKG;
};
