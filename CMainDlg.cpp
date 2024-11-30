// CMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CMainDlg.h"
#include "CLiveChoiceDlg.h"
#include "CTrendResultDlg.h"


// CMainDlg 대화 상자

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DAY, m_tDay);
	DDX_Control(pDX, IDC_FOLLOWER, m_tFollower);
	DDX_Control(pDX, IDC_HEALTH, m_tHealth);
	DDX_Control(pDX, IDC_MONEY, m_tMoney);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LIVE_BUTTON, &CMainDlg::OnClickedLiveButton)
	ON_BN_CLICKED(IDC_TREND_BUTTON, &CMainDlg::OnClickedTrendButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMainDlg 메시지 처리기


void CMainDlg::OnClickedLiveButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CLiveChoiceDlg* pLiveChoiceDlg = new CLiveChoiceDlg();
	pLiveChoiceDlg->Create(IDD_LIVECHOICE_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pLiveChoiceDlg->GetWindowRect(&currentRect);
	pLiveChoiceDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}

void CMainDlg::OnClickedTrendButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CTrendResultDlg* pTrendResultDlg = new CTrendResultDlg();
	pTrendResultDlg->Create(IDD_TRENDRESULT_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pTrendResultDlg->GetWindowRect(&currentRect);
	pTrendResultDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

	DestroyWindow();
}


void CMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	CString strDay;
	CString strFollower;
	CString strMoney;
	CString strHealth;

	strDay.Format(_T("DAY %d"), Player::instance.GetDay());
	strFollower.Format(_T(": %d"), Player::instance.GetFollower());
	strMoney.Format(_T(": %d"), Player::instance.GetMoney());
	strHealth.Format(_T(": %d"), Player::instance.GetHealth());

	m_tDay.SetWindowTextW(strDay);
	m_tFollower.SetWindowTextW(strFollower);
	m_tMoney.SetWindowTextW(strMoney);
	m_tHealth.SetWindowTextW(strHealth);

	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}


BOOL CMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	Player::instance.UpdatePreviousStasis();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
