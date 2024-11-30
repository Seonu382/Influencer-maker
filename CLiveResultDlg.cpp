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
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
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
		Player::instance.SkilledGame();
		break;

	case TALK:
		dFollower = Player::instance.GetTalk();
		Player::instance.SkilledTalk();
		break;

	case MUKBANG:
		dFollower = Player::instance.GetMukbang();
		Player::instance.SkilledMukbang();
		break;

	case BEAUTY:
		dFollower = Player::instance.GetBeauty();
		Player::instance.SkilledBeauty();
		break;

	case EXERCISE:
		dFollower = Player::instance.GetExercise();
		Player::instance.SkilledExercise();
		break;

	}

	Player::instance.AddFollower(static_cast<int>(Player::instance.GetFollower() * dFollower / 1000.0f));

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


BOOL CLiveResultDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}



HBRUSH CLiveResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
