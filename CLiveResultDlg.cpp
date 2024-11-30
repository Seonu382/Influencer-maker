// CLiveResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CLiveResultDlg.h"
#include "CMainDlg.h"
#include "Player.h"


// CLiveResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CLiveResultDlg, CDialogEx)

CLiveResultDlg::CLiveResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIVERESULT_DIALOG, pParent)
{

}

CLiveResultDlg::~CLiveResultDlg()
{
}

void CLiveResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PREVIOUSFOLLOWER, m_tPreviousFollower);
	DDX_Control(pDX, IDC_PREVIOUSMONEY, m_tPreviousMoney);
	DDX_Control(pDX, IDC_PREVIOUSHEALTH, m_tPreviousHealth);
	DDX_Control(pDX, IDC_CURRENTFOLLOWER, m_tCurrentFollower);
	DDX_Control(pDX, IDC_CURRENTHEALTH, m_tCurrentHealth);
	DDX_Control(pDX, IDC_CURRENTMONEY, m_tCurrentMoney);
}


BEGIN_MESSAGE_MAP(CLiveResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEXTDAY_BUTTON, &CLiveResultDlg::OnClickedNextdayButton)
END_MESSAGE_MAP()


// CLiveResultDlg 메시지 처리기


void CLiveResultDlg::OnClickedNextdayButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	goNextDay();

}


void CLiveResultDlg::showMainDlg()
{
	// TODO: 여기에 구현 코드 추가.

	CMainDlg* pMainDlg = new CMainDlg();
	
	pMainDlg->Create(IDD_MAIN_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pMainDlg->GetWindowRect(&currentRect);
	pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();


}


void CLiveResultDlg::goNextDay()
{
	// TODO: 여기에 구현 코드 추가.

	Player::instance.AddDay();

	showMainDlg();
}


BOOL CLiveResultDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	int dFollower = 0;

	switch (Player::instance.GetCurrentTheme()) {

	case GAME:
		dFollower = Player::instance.GetGame();
		Player::instance.SetGame(Player::instance.GetGame() + 1);
		break;

	case TALK:
		dFollower = Player::instance.GetTalk();
		Player::instance.SetTalk(Player::instance.GetTalk() + 1);
		break;

	case MUKBANG:
		dFollower = Player::instance.GetMukbang();
		Player::instance.SetMukbang(Player::instance.GetMukbang() + 1);
		break;

	case BEAUTY:
		dFollower = Player::instance.GetBeauty();
		Player::instance.SetBeauty(Player::instance.GetBeauty() + 1);
		break;

	case EXERCISE:
		dFollower = Player::instance.GetExercise();
		Player::instance.SetExercise(Player::instance.GetExercise() + 1);
		break;

	}

	Player::instance.AddFollower(static_cast<int>(Player::instance.GetFollower() * dFollower / 100.0f));

	CString previousFollower;
	CString previousMoney;
	CString previousHealth;
	CString currentFollower;
	CString currentMoney;
	CString currentHealth;

	previousFollower.Format(_T("%d"), Player::instance.GetPreviousFollower());
	previousMoney.Format(_T("%d"), Player::instance.GetPreviousMoney());
	previousHealth.Format(_T("%d"), Player::instance.GetPreviousHealth());
	currentFollower.Format(_T("%d"), Player::instance.GetFollower());
	currentMoney.Format(_T("%d"), Player::instance.GetMoney());
	currentHealth.Format(_T("%d"), Player::instance.GetHealth());

	m_tPreviousFollower.SetWindowTextW(previousFollower);
	m_tPreviousMoney.SetWindowTextW(previousMoney);
	m_tPreviousHealth.SetWindowTextW(previousHealth);
	m_tCurrentFollower.SetWindowTextW(currentFollower);
	m_tCurrentMoney.SetWindowTextW(currentMoney);
	m_tCurrentHealth.SetWindowTextW(currentHealth);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
