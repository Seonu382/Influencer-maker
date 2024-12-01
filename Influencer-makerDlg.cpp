
// Influencer-makerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Influencer-maker.h"
#include "Influencer-makerDlg.h"
#include "afxdialogex.h"
#include "CInformationDlg.h"
#include "RandomEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnColorizationColorChanged(DWORD dwColorizationColor, BOOL bOpacity);
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_ERASEBKGND()
//ON_WM_DWMCOLORIZATIONCOLORCHANGED()
//ON_WM_CTLCOLOR()
//ON_WM_ERASEBKGND()
//ON_WM_ERASEBKGND()
//ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CInfluencermakerDlg 대화 상자



CInfluencermakerDlg::CInfluencermakerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INFLUENCERMAKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInfluencermakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_START_PIC, m_Start);
	DDX_Control(pDX, IDC_START_PIC, m_StartBKG);
	DDX_Control(pDX, IDC_START_BUTTON, m_bbStartButton);
}

BEGIN_MESSAGE_MAP(CInfluencermakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BUTTON, &CInfluencermakerDlg::OnClickedStartButton)
END_MESSAGE_MAP()


// CInfluencermakerDlg 메시지 처리기

BOOL CInfluencermakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	HBITMAP hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_LOGO_RERE));
	m_StartBKG.SetBitmap(hBit);
	CRect rt;
	GetClientRect(&rt);
	m_StartBKG.SetWindowPos(NULL, 0, 0, rt.Width(), rt.Height(), SWP_SHOWWINDOW);

	m_bbStartButton.LoadBitmaps(IDB_START, NULL, NULL, NULL);
	m_bbStartButton.SizeToContent();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	RandomEvent::InitializeDatabase();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CInfluencermakerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CInfluencermakerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CInfluencermakerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInfluencermakerDlg::OnClickedStartButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInformationDlg* pInformationDlg = new CInformationDlg();
	pInformationDlg->Create(IDD_INFORMATION_DIALOG);

	CRect rect;
	GetWindowRect(&rect);
	pInformationDlg->SetWindowPos(NULL, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW);


}


//HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
	// TODO:  여기서 DC의 특성을 변경합니다.

//	if (nCtlColor == CTLCOLOR_STATIC)
//	{
//		pDC->SetBkColor(RGB(253, 253, 253));
//		hbr = ::CreateSolidBrush(RGB(253, 253, 253));
//	}
//
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
//	return hbr;
//}




//BOOL CAboutDlg::OnEraseBkgnd(CDC* pDC)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CRect rect;
//	GetClientRect(rect);
//
//	pDC->FillSolidRect(rect, RGB(253, 253, 253));
//	return TRUE;
//
//	return CDialogEx::OnEraseBkgnd(pDC);
//}




//HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
	// TODO:  여기서 DC의 특성을 변경합니다.

//	if (nCtlColor == CTLCOLOR_STATIC)
//	{
//		pDC->SetBkColor(RGB(253, 253, 253));
//		hbr = ::CreateSolidBrush(RGB(253, 253, 253));
//	}
//
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
//	return hbr;
//}


//BOOL CAboutDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

//	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
//}
