#if !defined(AFX_DLGPREAFN04F25_33_H__DA251A4E_13AC_424C_8FFE_043658EE128C__INCLUDED_)
#define AFX_DLGPREAFN04F25_33_H__DA251A4E_13AC_424C_8FFE_043658EE128C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPreAfn04F25_33.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPreAfn04F25_33 dialog

#include "BtnST.h"
#include "ShadeButtonST.h"
#include "NxConfig.h"

typedef enum eProType_e
{
	PROT_GBNX_32,     // GB/TXXXX.3.1-2013
	RROT_DLT645_97,   // DL/T645-1997
	PROT_DLT645_07,   // DL/T645-2007
	PROT_MODBUS,      // Modbus
	PROT_USER ,  // (128~255)��ʾ�Զ���
	PROT_NUM_MAX ,  

}eProType;

typedef enum ePortType_e
{
  PORT_DC,         // ֱ��ģ����
  PORT_AC,         // ����ģ����
  PORT_SER,        // ����(RS485/RS232)
  PORT_ETH,        // ��̫��
  PORT_ZIGB,       // zigbee
  PORT_USER , // 128~255 �û��Զ���
  PORT_NUM_MAX,
}ePortType;


typedef enum eBaud_e
{
	INDEX_BAUD_1200,            
	INDEX_BAUD_2400,
	INDEX_BAUD_4800,
	INDEX_BAUD_9600,
	INDEX_BAUD_19200,
	INDEX_BAUD_38400,         
	INDEX_BAUD_76800,   
	BAUD_NUM_MAX,
}eBaud;


typedef enum
{
	CHECK_NONE,
	CHECK_ODD,
	CHECK_EVEN,
	CHECK_NUM_MAX,
	
}eCheck;

typedef enum
{
	STOP_1,
	STOP_2,
	STOP_NUM_MAX,
}eStopBit;

typedef enum
{
	DBIT_5,
	DBIT_6,
	DBIT_7,
	DBIT_8,
	DBIT_NUM_MAX,
}eDataBit;


// ��������AFN04F25 AFN04F33
class CDlgPreAfn04F25_33 : public CDialog
{
// Construction
public:
	CDlgPreAfn04F25_33(CWnd* pParent = NULL);   // standard constructor
	BOOL m_bF25Elec;  // ���õ��ǵ�������������
	BOOL m_bMaster;   // ��������վԤ��
	CString m_protoName[PROT_NUM_MAX];
	CString m_portName[PORT_NUM_MAX];
	CString m_BaudName[BAUD_NUM_MAX];
	CString m_checkName[CHECK_NUM_MAX];
	CString m_stopName[STOP_NUM_MAX];
	CString m_DBitName[DBIT_NUM_MAX];
	

	void    ShowPortSet(ePortType eType);
	void    GetCurValues();
	void    SetNewValues();

// Dialog Data
	//{{AFX_DATA(CDlgPreAfn04F25_33)
	enum { IDD = IDD_DLG_PRE_AFN04_F25_F33 };
	CIPAddressCtrl	m_ip_sAccess;
	CIPAddressCtrl	m_ip_acs;
	CComboBox	m_comb_stop;
	CComboBox	m_comb_databit;
	CComboBox	m_comb_check;
	CComboBox	m_comb_baud;
	CComboBox	m_comb_port;
	CComboBox	m_comb_proto;
	CShadeButtonST	m_btn_ok;
	CShadeButtonST	m_btn_no;
	UINT	m_edit_usID;
	UINT	m_edit_ucPort;
	CString	m_edit_ucAddr;
	CString	m_edit_pwd;
	UINT	m_edit_acs_port;
	UINT	m_edit_usAcsPort;
	CString	m_edit_zigbee_mac;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPreAfn04F25_33)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPreAfn04F25_33)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokCombPort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPREAFN04F25_33_H__DA251A4E_13AC_424C_8FFE_043658EE128C__INCLUDED_)
