// CTrendResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CTrendResultDlg.h"
#include "CMainDlg.h"
#include "Player.h"


// CTrendResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CTrendResultDlg, CDialogEx)

CTrendResultDlg::CTrendResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRENDRESULT_DIALOG, pParent)
{

}

CTrendResultDlg::~CTrendResultDlg()
{
}

void CTrendResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTrendResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXTDAY_BUTTON, &CTrendResultDlg::OnClickedNextdayButton)
END_MESSAGE_MAP()


// CTrendResultDlg 메시지 처리기


void CTrendResultDlg::OnClickedNextdayButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	goNextDay();
	
}


void CTrendResultDlg::goNextDay()
{
	// TODO: 여기에 구현 코드 추가.

	Player::instance.AddDay();
	showMainDlg();
}

void CTrendResultDlg::showMainDlg() {

	CMainDlg* pMainDlg = new CMainDlg();
	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}
