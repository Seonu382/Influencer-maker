// CLiveChoiceDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CLiveChoiceDlg.h"
#include "CLiveDlg.h"
#include "Player.h"
#include "CMainDlg.h"

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
	ON_BN_CLICKED(IDC_LIVE_BACK, &CLiveChoiceDlg::OnBnClickedLiveBack)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
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


void CLiveChoiceDlg::OnBnClickedLiveBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CMainDlg* pMainDlg = new CMainDlg();
	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}


BOOL CLiveChoiceDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);

}


HBRUSH CLiveChoiceDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(253, 253, 253));
		hbr = ::CreateSolidBrush(RGB(253, 253, 253));
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;

}
