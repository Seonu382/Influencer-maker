// CStoryDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Influencer-maker.h"
#include "afxdialogex.h"
#include "CStoryDlg.h"
#include "CMainDlg.h"


// CStoryDlg 대화 상자

IMPLEMENT_DYNAMIC(CStoryDlg, CDialogEx)

CStoryDlg::CStoryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STORY_DIALOG, pParent)
{

}

CStoryDlg::~CStoryDlg()
{
}

void CStoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STORY_BKG, m_StoryBKG);
}


BEGIN_MESSAGE_MAP(CStoryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SKIP_BUTTON, &CStoryDlg::OnClickedSkipButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CStoryDlg 메시지 처리기


void CStoryDlg::FadeIn()
{
	// TODO: 여기에 구현 코드 추가.
	for (int i = 0; i <= 255; i += 5) {
		SetLayeredWindowAttributes(0, i, LWA_ALPHA);
		Sleep(10);
	}
}


BOOL CStoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

    // 투명도 조절
	ModifyStyleEx(0, WS_EX_LAYERED);

	SetLayeredWindowAttributes(0, 0, LWA_ALPHA);

    // 배경 이미지
	HBITMAP hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STORY_1));
	m_StoryBKG.SetBitmap(hBit);
	CRect rt;
	GetClientRect(&rt);
	m_StoryBKG.SetWindowPos(NULL, 0, 0, rt.Width(), rt.Height(), SWP_SHOWWINDOW);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

extern int count = 0;

void CStoryDlg::OnClickedSkipButton()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    HBITMAP hBit = nullptr;

    if (count == 0) {
        hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STORY_2));
        count++;
    }
    else if (count == 1) {
        hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STORY_3));
        count++;
    }
    else if (count == 2) {
        hBit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STORY_4));
        count++;
    }
    else if (count == 3) {
        CMainDlg* pMainDlg = new CMainDlg();
        pMainDlg->Create(IDD_MAIN_DIALOG);

        CRect parentRect, currentRect;
        GetWindowRect(&parentRect);
        pMainDlg->GetWindowRect(&currentRect);
        pMainDlg->SetWindowPos(NULL, parentRect.left, parentRect.top, currentRect.Width(), currentRect.Height(), SWP_SHOWWINDOW);

        DestroyWindow();
        count = 0;
        return;
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
        m_StoryBKG.SetBitmap((HBITMAP)resizedImg.Detach());

        // 원본 비트맵 리소스 삭제
        img.Detach();
    }
}



void CStoryDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	

	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}
