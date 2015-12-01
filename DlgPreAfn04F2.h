#if !defined(AFX_DLGPREAFN04F2_H__61FB6B32_F5D8_4DA4_A732_91C6A0019EC1__INCLUDED_)
#define AFX_DLGPREAFN04F2_H__61FB6B32_F5D8_4DA4_A732_91C6A0019EC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPreAfn04F2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPreAfn04F2 dialog
#include "NxConfig.h"
#include "BtnST.h"
#include "ShadeButtonST.h"
#define  sMcMstParaOne_NUM_MAX 10  // 20 �Ѿ��㹻�� 
// ���ò��� comb����
typedef enum
{
	INDEX_AFN_4_F1_CON_UP_CFG          ,// 0x0401,       // ��Ϣ�����뽻���ն�����ͨ�ſ�ͨ�Ų���
	INDEX_AFN_4_F2_MST_PARA            ,// 0x0402,       // ��(��)վ����
	INDEX_AFN_4_F3_CON_AUTH_PARA       ,// 0x0403,       // ��Ϣ�����뽻���ն�����ͨ����Ϣ��֤����
	INDEX_AFN_4_F4_TEAM_ADDR           ,// 0x0404,       // ��Ϣ�����뽻���ն����ַ
	INDEX_AFN_4_F5_CON_IP_PORT         ,// 0x0405,       // ��Ϣ�����뽻���ն�IP��ַ�Ͷ˿�
	INDEX_AFN_4_F6_CON_CASC            ,// 0x0406,       // ��Ϣ�����뽻���ն˼���ͨ�Ų���
	INDEX_AFN_4_F7_CON_DOWN_CFG        ,// 0x0407,       // ��Ϣ�����뽻���ն�������̫���˿�ͨ�Ų���

	// ��2   pn:p0/����ն˺�
	INDEX_AFN_4_F9_CON_EVENT_CFG       ,// 0x0409,       // �¼���¼����
	INDEX_AFN_4_F10_CON_STATE_INPUT    ,// 0x040A,       // �豸״̬���������

	// ��3   pn:����ն˺�
	INDEX_AFN_4_F17_TML_UP_CFG         ,// 0x0411,       // ����ն�����ͨ�Ų�������

	// ��4   pn:�����������
	INDEX_AFN_4_F25_ELEC_MP_CFG        ,// 0x0419,       // �������������ò���
	INDEX_AFN_4_F26_ELEC_MP_BASE       ,// 0x041A,       // �����������������
	INDEX_AFN_4_F27_ELEC_LMIT_POWER    ,// 0x041B,       // �����������������ֵ����
	INDEX_AFN_4_F28_ELEC_LMIT_FACTR    ,// 0x041C,       // ���������㹦������Խ��ֵ����
	INDEX_AFN_4_F29_ELEC_FIX_HARM      ,// 0x041D,       // ����������г��������Խ�޶�ֵ
	INDEX_AFN_4_F30_ELEC_FLASH         ,// 0x041E,       // ��������������Խ�޲���

	// ��5   pn:�ǵ����������
	INDEX_AFN_4_F33_NELC_MP_CFG        ,// 0x0421,       // �ǵ������������ò���
	INDEX_AFN_4_F34_NELC_MP_PARA       ,// 0x0422,       // �ǵ������������ݲ���
	INDEX_AFN_4_F35_NELC_MP_LMIT       ,// 0x0423,       // �ǵ���������Խ�����ݲ���

	// ��7  pn:�����
	INDEX_AFN_4_F49_FREZ_TASK_PARA     ,// 0x0431,       // ���������������
	INDEX_AFN_4_MAX
};

typedef struct  
{
	eMcmd eCmd;
	CString name;
}sCmdSetName;


class CDlgPreAfn04F2 : public CDialog
{
// Construction
public:
	CDlgPreAfn04F2(CWnd* pParent = NULL);   // standard constructor
	BOOL m_bPreMaster;  // �Ƿ�������վ�Ĳ���
	void GetCurValues();
	void SetNewValues();
	void EnableCtrls(BOOL bEnable);
	int  m_totalNum;  // �ܵ�����վ������
	int  m_index;     // ��ǰ���õ������
	sMcMstParaOne m_sMcMstParaOne[sMcMstParaOne_NUM_MAX];
	sCmdSetName m_set[INDEX_AFN_4_MAX];
// Dialog Data
	//{{AFX_DATA(CDlgPreAfn04F2)
	enum { IDD = IDD_DLG_PRE_AFN04_F2 };
	CComboBox	m_cmb_cmd;
	CTabCtrl	m_tab;
	CIPAddressCtrl	m_ip_main;
	CIPAddressCtrl	m_ip_back;
	CShadeButtonST	m_btn_no;
	CShadeButtonST	m_btn_ok;
	int		m_edit_total;
	int		m_edit_index;
	CString	m_edit_apn;
	int		m_edit_port_back;
	int		m_edit_port_main;
	CString	m_edit_pwd;
	CString	m_edit_usr;
	UINT	m_edit_id;
	UINT	m_edit_usPn;
	CString	m_static_pn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPreAfn04F2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPreAfn04F2)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditNumTotal();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditId();
	afx_msg void OnRadioValid();
	afx_msg void OnRadioInvalid();
	afx_msg void OnFieldchangedIpMain(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditPortMain();
	afx_msg void OnChangeEditPortBack();
	afx_msg void OnFieldchangedIpBack(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditApn();
	afx_msg void OnChangeEditUsr();
	afx_msg void OnChangeEditPwd();
	afx_msg void OnEditchangeCombCmd();
	afx_msg void OnSelendokCombCmd();
	afx_msg void OnChangeEditPn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPREAFN04F2_H__61FB6B32_F5D8_4DA4_A732_91C6A0019EC1__INCLUDED_)
