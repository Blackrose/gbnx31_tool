// NxMasterDlg.h : header file
//

#if !defined(AFX_NXMASTERDLG_H__17C20C4A_A48A_44E0_AB02_8A8D36A840C0__INCLUDED_)
#define AFX_NXMASTERDLG_H__17C20C4A_A48A_44E0_AB02_8A8D36A840C0__INCLUDED_

#include "ServerSock.h"
#include "TerminalSock.h"
#include "Terminal.h"
#include "ColorListCtrl.h"
#include "ListCtrlSock.h"
#include "MyRichEdit.h"
#include "TabDlgPack.h"
#include "TabDlgUnpack.h"
#include "TabDlgPreMaster.h"
#include "TabDlgPreTml.h"
#include "TabDlgTask.h"

#include "CJColorPicker.h"
#include "CJFlatComboBox.h"
#include "XPTabCtrl.h"
//#include "NxRuler.h"
#include "NxConfig.h"
#include "Qgdw3761api.h"


#include "BtnST.h"
#include "ShadeButtonST.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNxMasterDlg dialog
#define NX_MASTER_DBG   // debug switch
//#undef  NX_MASTER_DBG

// ������tab�ؼ���
typedef enum
{
	TAB_INDEX_PACK,
	TAB_INDEX_PRE_MASTER,
	TAB_INDEX_PRE_TERMINAL,

	TAB_INDEX_UNPACK,
	TAB_INDEX_TASK,
	TAB_INDEX_MAX
		
}TAB_INDEX;


#define TAB_NAME_PRE_MASTER     "��վԤ��"
#define TAB_NAME_PRE_TERMINAL   "�ն�Ԥ��"
#define TAB_NAME_PACK           "��Լ��װ"
#define TAB_NAME_UNPACK         "��Լ����" 
#define TAB_NAME_TASK           "�ƻ�����"



class CNxMasterDlg : public CDialog
{
// Construction
public:
	CNxMasterDlg(CWnd* pParent = NULL);	// standard constructor
	void ClickSendBtn();
	BOOL SendToList( CString strSend); // �����ķ��͸��б��й�ѡ��ÿһ��������
	CImageList* m_imagelist;                   /*ͼ���б�*/
// Dialog Data
	//{{AFX_DATA(CNxMasterDlg)
	enum { IDD = IDD_NXMASTER_DIALOG };
// 	CButton	m_btn_stop_link;
// 	CButton	m_btn_start_link;

	CShadeButtonST	m_btn_stop_link;
	CShadeButtonST	m_btn_start_link;


	CButton	m_check_auto_respone;
	CButton	m_check_omit_heart;
	CButton	m_check_auto_unpack;
	CCJColorPicker	m_btn_clr_info;
	CCJColorPicker	m_btn_clr_unpack;
	CCJColorPicker	m_btn_clr_terminal;
	CCJColorPicker	m_btn_clr_master;
	CButton	m_static_cmd_cach;
	CEdit	m_cmd_cach;
	CShadeButtonST m_btn_send_cmd;
	CEdit	m_edit_send;
	CMyRichEdit m_rich_edit;
	CListCtrlSock  m_list_tml;
	CXPTabCtrl	m_tab;
	CIPAddressCtrl	m_ctrl_ip;
	int		m_sev_port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNxMasterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNxMasterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioMaster();
	afx_msg void OnRadioTerminal();
	afx_msg void OnBtnStart();
	afx_msg void OnFieldchangedIpAddr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnStop();
	afx_msg void OnBtnSendCmd();
	afx_msg void OnItemchangedListTml(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetClrMasterMsg();  // ������վ��Ϣ��ʽ
	afx_msg void OnSetTmlCf();        // �����ն���ʾ
	afx_msg void OnSetUnpackCf();
	afx_msg void OnBtnAsClient();
	afx_msg void OnCheckAutoUnpack();
	afx_msg void OnAbout();
	afx_msg void OnSetInfoCf();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClearRichEdit();
	afx_msg void OnChangeEditPort();
	afx_msg void OnCheckAutoRespone();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	afx_msg void OnDestroy();
	afx_msg void OnDataPreSet();
	afx_msg void OnRclickRicheditMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClickRicheditMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRichClr();
	afx_msg void OnRichTrans();
	afx_msg void OnRichCopy();
	afx_msg void OnRichAddt();
	afx_msg void OnIdTkSet();
	afx_msg void OnRichInsetLen();
	//}}AFX_MSG
	afx_msg void OnSelEndOK(UINT lParam, LONG wParam); // colorpicker
	DECLARE_MESSAGE_MAP()
public:
	void insetLineStype();
	void  showUnpackText(smtPack *psmtPack);// �ı���ʽ��ʾ�������
	void  showUnpackText31(smcPack *psmcPack); // ���ı���ʽ��ʾgb3-1�ı��Ľ������
	void  showSubData(sMtData *psMtData, eMtDir eDir,COLORREF crText);     // ��ʾ��������Ϣ ��Ӧ�ò����� 3761
	void  showSubData31(sMcData *psMtData, eMcDir eDir,COLORREF crText);     // ��ʾ��������Ϣ ��Ӧ�ò����� gb31
	void  insertLine();
	CString charToCString(char *pStr, int n);
	char *pStrGetErcName(UINT8 ucErc);
	void showTabDlg(int index);
	void InitTabCtrl();
	CTerminal* GetCTerminal(CServerSock *pSock);
	void InsertInfoMasterSend(CTerminal *pTml, int len); // ��վ��ĳ�ն˷���len�������ʾ��Ϣ���������richedit
	void InsertInfoMasterRecv(CTerminal *pTml, int len); // ��վ�յ�ĳ�ն˷���len����ʾ��Ϣ���������richedit

	void insertInfoTmlSend(CTerminalSock *pSock, int len); // terminal��ĳ��վ����lenӦ�����ʾ��Ϣ���������richedit
	void insertInfoTmlRecv(CTerminalSock *pSock, int len); // terminal�յ���վ����len�������ʾ��Ϣ���������richedit

	CString GetCurTime();
	CString GetCurDate();
	void SetListTmlCtrlPos();
	int tmlSendMsg(CTerminalSock *pSock, CString strSend);
	int sevSendMsg(CServerSock   *pSock, CString strSend);
	void tmlReceveMsg(CTerminalSock *pSockTml);
	void sevReceveMsg(CServerSock   *pSockSev);
	void TmlOnClose(CTerminalSock *pSock);  // �������رպ����Ӧ
	void SocketStop(CServerSock *pSevSock); // �ͻ����˳������Ӧ
	void SevAcceptConnect();
	void    draw_main_tab();
	int     GetLocalHostName(CString &sHostName);
	int     GetIpAddress(const CString & sHostName,CString & sIpAddress);
	bool    bStartServer(int port,  CString strIp);     // ����������
	bool    bConnectServer(int port,CString strIp);    // ���ӷ�����
	bool    m_bServerRun;                              // �������Ƿ��Ѿ�����
	bool    m_bClientLink;                             // ��վ�Ƿ����ӵ�������
	void    AutoUnpack(char *buf, UINT16 usLen);       // ��������
	
    // ��վ�Զ��ظ�
	void    AutoResponseMaster(CTerminal *pTml, char *buf, UINT16 usLen);  
	void    AutoResponseMasterTimer();
	int     m_AutoResponseMasterSeconds;
	CTerminal *m_pTmlAutoResponseMaster;
	char    *m_sendBuferAutoResponseMaster;
    UINT16  m_usSendBufLenMaster;

	void    AutoResponseTerminal(char *buf, UINT16 usLen); // ��վ�Զ��ظ�
	void    MasterDealLink(CTerminal *pTml, char *pBuf, UINT16 usLen);   // //�����������¼����
	CString m_strLocalIP;    // ����IP��ַ
	CString m_strServerIP;   // �������ӷ�������IP
	int     m_nSerPort;      // �������˿ں�
	bool    m_bMaster;       // ��վ�����ն�
	bool    m_bSevStop;      // �������Ƿ�ֹͣ
	CServerSock   m_sockSev;
	int     m_terminalId;    // ��Ϊ�ն�ʱ��ID

	CTerminalSock m_sockTml;
	CPtrList      m_listTml; // ����վ�������ӵ��ն�����
//	CNxRuler      m_nxRuler;
	BOOL          m_bAutoUnpack;   // �Ƿ�ѡ���Զ�����
	BOOL          m_bAutoResponse; // �Ƿ�ѡ���Զ�Ӧ��

private:
	CTabDlgTask      m_tabDlgTask;
	CTabDlgUnpack    m_tabDlgUnpack;
	CTabDlgPack      m_tabDlgPack;
	CTabDlgPreMaster m_tabDlgPreMst;
	CTabDlgPreTml    m_tabDlgPreTml;
	CNxConfig        m_preConfig;     // Ԥ���ö���
	


public:
	BOOL IsAdministrator();
	void SetRegAdmin();
	CString ReturnPath();

	// ���ú��� ��ʽ�汾�����عر�
#ifdef NX_MASTER_DBG
	void test_GetMstPreAfn04F1();

#endif

private:
	void setMsgRichEditPos();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NXMASTERDLG_H__17C20C4A_A48A_44E0_AB02_8A8D36A840C0__INCLUDED_)
