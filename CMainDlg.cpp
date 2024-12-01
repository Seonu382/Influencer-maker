// CMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CMainDlg.h"
#include "CLiveChoiceDlg.h"
#include "CTrendResultDlg.h"
#include "CShopDlg.h"


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
	DDX_Control(pDX, IDC_LIVE_BUTTON, m_bbLiveButton);
	DDX_Control(pDX, IDC_REST_BUTTON, m_bbRestButton);
	DDX_Control(pDX, IDC_SHOP_BUTTON, m_bbShopButton);
	DDX_Control(pDX, IDC_TREND_BUTTON, m_bbTrendButton);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_LIVE_BUTTON, &CMainDlg::OnClickedLiveButton)
	ON_BN_CLICKED(IDC_TREND_BUTTON, &CMainDlg::OnClickedTrendButton)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_SHOP_BUTTON, &CMainDlg::OnBnClickedShopButton)
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


void CMainDlg::OnBnClickedShopButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CShopDlg* pShopDlg = new CShopDlg();
	pShopDlg->Create(IDD_SHOP_DIALOG);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pShopDlg->GetWindowRect(&currentRect);
	pShopDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

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

	// 그래픽 추가
	Player::instance.UpdatePreviousStasis();

	m_bbLiveButton.LoadBitmaps(IDB_SEL_LIVE, NULL, NULL, NULL);
	m_bbLiveButton.SizeToContent();

	m_bbTrendButton.LoadBitmaps(IDB_SEL_TREND, NULL, NULL, NULL);
	m_bbTrendButton.SizeToContent();

	m_bbShopButton.LoadBitmaps(IDB_SEL_SHOP, NULL, NULL, NULL);
	m_bbShopButton.SizeToContent();

	m_bbRestButton.LoadBitmaps(IDB_SEL_REST, NULL, NULL, NULL);
	m_bbRestButton.SizeToContent();

	CStatic* p_lamp_image = (CStatic*)GetDlgItem(IDC_MAIN);
	CBitmap lamp_image;

	if (Player::instance.GetFollower() >= 500000)
		lamp_image.LoadBitmap(IDB_MAIN_HYPER);
	else if (Player::instance.GetFollower() >= 100000)
		lamp_image.LoadBitmap(IDB_MAIN_HIGH);
	else
	{

	}
		lamp_image.LoadBitmap(IDB_MAIN_LOW);

	HBITMAP h_old_bitmap = p_lamp_image->SetBitmap(lamp_image);
	if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);
	lamp_image.Detach();

	// 초기화 작업
	Player::instance.InitializePlayerStat();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CMainDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH CMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


