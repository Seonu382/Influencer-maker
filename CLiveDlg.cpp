// CLiveDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CLiveDlg.h"
#include "CRandomChoiceDlg.h"
#include "Player.h"


// CLiveDlg 대화 상자

IMPLEMENT_DYNAMIC(CLiveDlg, CDialogEx)

CLiveDlg::CLiveDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIVE_DIALOG, pParent)
{

}

CLiveDlg::~CLiveDlg()
{
}

void CLiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLiveDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CLiveDlg 메시지 처리기


BOOL CLiveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(0, 3000, NULL);

	CStatic* p_lamp_image = (CStatic*)GetDlgItem(IDC_LIVE);
	CBitmap lamp_image;
	HBITMAP h_old_bitmap = nullptr;


	switch (Player::instance.GetCurrentTheme())
	{
	case GAME:
		lamp_image.LoadBitmap(IDB_LIVE_GAME);
		break;
	case TALK:
		lamp_image.LoadBitmap(IDB_LIVE_TALK);
		break;
	case MUKBANG:
		lamp_image.LoadBitmap(IDB_LIVE_MUKBANG);
		break;
	case BEAUTY:
		lamp_image.LoadBitmap(IDB_LIVE_BEAUTY);
		break;

	case EXERCISE:
		lamp_image.LoadBitmap(IDB_LIVE_EXERCISE);
		break;
	default:
		break;
	}

	h_old_bitmap = p_lamp_image->SetBitmap(lamp_image);
	if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);
	lamp_image.Detach();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CLiveDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0) {
		showRandomChoice(false);
	}
	else if (nIDEvent == 1) {
		showRandomChoice(true);
		ShowWindow(SW_HIDE);
	}
	KillTimer(nIDEvent);


	CDialogEx::OnTimer(nIDEvent);
}


void CLiveDlg::showRandomChoice(bool _afterLive)
{
	// TODO: 여기에 구현 코드 추가.
	CRandomChoiceDlg* pRandomChoiceDlg = new CRandomChoiceDlg();
	pRandomChoiceDlg->Create(IDD_RANDOMCHOICE_DIALOG);
	pRandomChoiceDlg->m_bAfterLive = _afterLive;
	pRandomChoiceDlg->setParentDialog(this);

	CRect parentRect, currentRect;
	GetWindowRect(&parentRect);
	pRandomChoiceDlg->GetWindowRect(&currentRect);
	pRandomChoiceDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);
}

HBRUSH CLiveDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	if (nCtlColor == CTLCOLOR_LISTBOX) {
		if (pWnd->GetDlgCtrlID() == IDC_LIVE_CHAT) {
			// Change text color
			pDC->SetTextColor(RGB(0, 0, 0)); // Yellow text

			// Change background color
			pDC->SetBkColor(RGB(253, 253, 253));

			// Use a brush to set the background color
			static CBrush brush(RGB(253, 253, 253));
			return (HBRUSH)brush.GetSafeHandle();
		}
	}

	// Default handling for other controls
	return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}



BOOL CLiveDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->FillSolidRect(rect, RGB(253, 253, 253));
	return TRUE;

	return CDialogEx::OnEraseBkgnd(pDC);
}
