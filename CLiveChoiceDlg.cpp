// CLiveChoiceDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CLiveChoiceDlg.h"
#include "CLiveDlg.h"
#include "Player.h"


// CLiveChoiceDlg 대화 상자

IMPLEMENT_DYNAMIC(CLiveChoiceDlg, CDialogEx)

CLiveChoiceDlg::CLiveChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIVECHOICE_DIALOG, pParent)
{

}

CLiveChoiceDlg::~CLiveChoiceDlg()
{
}

void CLiveChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLiveChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_GAME_BUTTON, &CLiveChoiceDlg::OnClickedGameButton)
	ON_BN_CLICKED(IDC_TALK_BUTTON, &CLiveChoiceDlg::OnClickedTalkButton)
	ON_BN_CLICKED(IDC_MUKBANG_BUTTON, &CLiveChoiceDlg::OnClickedMukbangButton)
	ON_BN_CLICKED(IDC_BEAUTY_BUTTON, &CLiveChoiceDlg::OnClickedBeautyButton)
	ON_BN_CLICKED(IDC_EXERCISE_BUTTON, &CLiveChoiceDlg::OnClickedExerciseButton)
END_MESSAGE_MAP()


// CLiveChoiceDlg 메시지 처리기


void CLiveChoiceDlg::showLiveDlg()
{
	// TODO: 여기에 구현 코드 추가.
	CLiveDlg* pLiveDlg = new CLiveDlg();
	pLiveDlg->Create(IDD_LIVE_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pLiveDlg->GetWindowRect(&currentRect);
	pLiveDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}


void CLiveChoiceDlg::OnClickedGameButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.SetCurrentTheme(GAME);
	showLiveDlg();
}


void CLiveChoiceDlg::OnClickedTalkButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.SetCurrentTheme(TALK);
	showLiveDlg();
}


void CLiveChoiceDlg::OnClickedMukbangButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.SetCurrentTheme(MUKBANG);
	showLiveDlg();
}


void CLiveChoiceDlg::OnClickedBeautyButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.SetCurrentTheme(BEAUTY);
	showLiveDlg();
}


void CLiveChoiceDlg::OnClickedExerciseButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Player::instance.SetCurrentTheme(EXERCISE);
	showLiveDlg();
}
