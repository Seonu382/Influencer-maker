// CInformationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CInformationDlg.h"
#include "CStoryDlg.h"
#include "Player.h"
#include "CLiveChat.h"
#include <string>


// CInformationDlg 대화 상자

IMPLEMENT_DYNAMIC(CInformationDlg, CDialogEx)

CInformationDlg::CInformationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INFORMATION_DIALOG, pParent)
	, m_strName(_T(""))
{

}

CInformationDlg::~CInformationDlg()
{
}

void CInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
}


BEGIN_MESSAGE_MAP(CInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CONFIRM_BUTTON, &CInformationDlg::OnClickedConfirmButton)
END_MESSAGE_MAP()


// CInformationDlg 메시지 처리기


void CInformationDlg::OnClickedConfirmButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	Player::instance.InitializePlayerStat();
	Player::instance.SetName(std::string(CT2A(m_strName)));

	CLiveChat::InitializeLiveChat();

	CStoryDlg* pStoryDlg = new CStoryDlg();
	pStoryDlg->Create(IDD_STORY_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pStoryDlg->GetWindowRect(&currentRect);
	pStoryDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	pStoryDlg->FadeIn();
	DestroyWindow();

}
