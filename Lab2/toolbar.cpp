#include "framework.h"
#include "resource1.h"
#include "toolbar.h"
#include "resource.h"
#include <commctrl.h>


ToolBar::ToolBar(void) {}

void ToolBar::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    TBBUTTON tbb[5]; //??? Toolbar ? ??????? ????????
    ZeroMemory(tbb, sizeof(tbb));
    tbb[0].iBitmap = 0; //?????????? ??????????
    tbb[0].fsState = TBSTATE_ENABLED;
    tbb[0].fsStyle = TBSTYLE_BUTTON; //??? ???????? - ??????
    tbb[0].idCommand = ID_TOOL_POINT; //??? ID ???? ? ???????????? WM_COMMAND

    tbb[1].iBitmap = 1;
    tbb[1].fsState = TBSTATE_ENABLED;
    tbb[1].fsStyle = TBSTYLE_BUTTON;
    tbb[1].idCommand = ID_TOOL_LINE;

    tbb[2].iBitmap = 2;
    tbb[2].fsState = TBSTATE_ENABLED;
    tbb[2].fsStyle = TBSTYLE_BUTTON;
    tbb[2].idCommand = ID_TOOL_RECT;

    tbb[3].iBitmap = 3;
    tbb[3].fsState = TBSTATE_ENABLED;
    tbb[3].fsStyle = TBSTYLE_BUTTON;
    tbb[3].idCommand = ID_TOOL_ELLIPSE;

    tbb[4].iBitmap = 4;
    tbb[4].fsState = TBSTATE_ENABLED;
    tbb[2].fsStyle = TBSTYLE_BUTTON;
    tbb[4].idCommand = ID_TOOL_POINTPLUS;

    SendMessage(hwndToolBar, TB_ADDBUTTONS, 5, (LPARAM)&tbb);

    hwndToolBar = CreateToolbarEx(hWnd, //??????????? ?????
        WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP |
        TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR, //ID ?????????? ????? Toolbar
        5,
        hInst,
        IDB_BITMAP1,
        tbb, //????? ????? ??????
        5, //????????? ??????
        24, 24, 24, 24, //???????????? ?? ???????
        sizeof(TBBUTTON));
}

void ToolBar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar)
    {
        GetClientRect(hWnd, &rc); //???? ??????? ????????? ?????
        GetWindowRect(hwndToolBar, &rw); //??? ???????? ????? ?????? Toolbar
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
}

void ToolBar::OnTool(HWND hWnd, LPARAM lParam)
{
    if (oldlParam)
    {
        SendMessage(hwndToolBar, TB_PRESSBUTTON, oldlParam, 0); //release old button
    }
    SendMessage(hwndToolBar, TB_PRESSBUTTON, lParam, 1); // press new button
    oldlParam = lParam;
}

void ToolBar::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    LPNMHDR pnmh = (LPNMHDR)lParam;
    if (pnmh->code == TTN_NEEDTEXT)
    {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
        switch (lpttt->hdr.idFrom)
        {

        case ID_TOOL_POINT:
            lstrcpy(lpttt->szText, L"??????");
            break;

        case ID_TOOL_LINE:
            lstrcpy(lpttt->szText, L"˳???");
            break;

        case ID_TOOL_RECT:
            lstrcpy(lpttt->szText, L"???????????");
            break;

        case ID_TOOL_ELLIPSE:
            lstrcpy(lpttt->szText, L"?????");
            break;
        case ID_TOOL_POINTPLUS:
            lstrcpy(lpttt->szText, L"?????? ??????");
            break;

        default: lstrcpy(lpttt->szText, L"???? ????????");
        }
    }
}
