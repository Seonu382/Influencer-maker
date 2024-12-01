// CEndingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CEndingDlg.h"


// CEndingDlg 대화 상자

IMPLEMENT_DYNAMIC(CEndingDlg, CDialogEx)

CEndingDlg::CEndingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENDING_DIALOG, pParent)
{

}

CEndingDlg::~CEndingDlg()
{
}

void CEndingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENDING_BKG, m_EndingBkg);
}


BEGIN_MESSAGE_MAP(CEndingDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SKIP_BUTTON, &CEndingDlg::OnClickedSkipButton)
END_MESSAGE_MAP()


// CEndingDlg 메시지 처리기


BOOL CEndingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	HBITMAP hBit = NULL;

	switch (m_EndingType)
	{
	case BADENDING_1:
		hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BADENDING1_1));
		break;
	case BADENDING_2:
		hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BADENDING2_1));
		break;
	case HAPPYENDING:
		hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_HAPPYENDING_1));
		break;

	default:
		break;
	}
	m_EndingBkg.SetBitmap(hBit);
	CRect rt;
	GetClientRect(&rt);
	m_EndingBkg.SetWindowPos(NULL, 0, 0, rt.Width(), rt.Height(), SWP_SHOWWINDOW);

	m_nCount = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CEndingDlg::OnClickedSkipButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	HBITMAP hBit = nullptr;

	if (m_EndingType == BADENDING_1) {
		if (m_nCount == 0) {
			hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BADENDING1_2));
			m_nCount++;
		}
		else if (m_nCount == 1) {
			hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BADENDING1_3));
			m_nCount++;
		}
		else {
			DestroyWindow();
			m_nCount = 0;
		}
	}
	else if (m_EndingType == BADENDING_2) {
		if (m_nCount == 0) {
			hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BADENDING2_2));
			m_nCount++;
		}
		else {
			DestroyWindow();
			m_nCount = 0;
		}
	}
	else if (m_EndingType == HAPPYENDING) {
		if (m_nCount == 0) {
			hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_HAPPYENDING_2));
			m_nCount++;
		}
		else if (m_nCount == 1) {
			hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_HAPPYENDING_3));
			m_nCount++;
		}
		else {
			DestroyWindow();
			m_nCount = 0;
		}
	}


	if (hBit != nullptr) {
		// 창 크기를 가져옵니다.
		CRect rt;
		GetClientRect(&rt);

		// 비트맵의 원본 크기를 가져옵니다.   
		BITMAP bmp;
		GetObject(hBit, sizeof(BITMAP), &bmp);

		// 비트맵 크기를 조정합니다.
		CImage img;
		img.Attach(hBit);
		CImage resizedImg;
		resizedImg.Create(rt.Width(), rt.Height(), img.GetBPP());
		HDC hResizedDC = resizedImg.GetDC();
		img.StretchBlt(hResizedDC, 0, 0, rt.Width(), rt.Height(), 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
		resizedImg.ReleaseDC();

		// 조정된 이미지를 배경으로 설정합니다.
		m_EndingBkg.SetBitmap((HBITMAP)resizedImg.Detach());

		// 원본 비트맵 리소스 삭제
		img.Detach();
	}
}
