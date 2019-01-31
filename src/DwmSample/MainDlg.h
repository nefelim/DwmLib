// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <atlddx.h>
#include "DwgTabView.h"

class CMainDlg : public CDialogImpl<CMainDlg>
                , public CUpdateUI<CMainDlg>
                , public CWinDataExchange<CMainDlg>
                , public CMessageFilter
                , public CIdleHandler
{
public:
    enum { IDD = IDD_MAINDLG };

    virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual BOOL OnIdle();

    BEGIN_UPDATE_UI_MAP(CMainDlg)
    END_UPDATE_UI_MAP()

    BEGIN_DDX_MAP(CMainDlg)
        DDX_CONTROL(IDC_TABVIEW, m_tabView)
    END_DDX_MAP()

    BEGIN_MSG_MAP_EX(CMainDlg)
        MSG_WM_INITDIALOG(OnInitDialog)
        MSG_WM_DESTROY(OnDestroy)
        COMMAND_ID_HANDLER_EX(IDOK, OnOK)
        COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
    END_MSG_MAP()

    BOOL OnInitDialog(CWindow /*wndFocus*/, LPARAM /*lInitParam*/);
    void OnDestroy();
    void OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/);
    void OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/);

    void CloseDialog(int nVal);
private:
    CDwgTabView m_tabView;
};
