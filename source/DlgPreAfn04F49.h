#if !defined(AFX_DLGPREAFN04F49_H__1D368CBD_0A8E_429D_9A63_06DDC8888F46__INCLUDED_)
#define AFX_DLGPREAFN04F49_H__1D368CBD_0A8E_429D_9A63_06DDC8888F46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPreAfn04F49.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPreAfn04F49 dialog
#include "BtnST.h"
#include "ShadeButtonST.h"
#include "NxConfig.h"
#include "ColorListCtrl.h"

typedef enum
{

	INDEX_AFN_D_F1_CLOCK,//����ʱ��
	INDEX_AFN_D_F2_PARA_STATE,//����״̬��־
	INDEX_AFN_D_F3_EVENT_1,//��Ҫ�¼���������ǰֵ
	INDEX_AFN_D_F4_EVENT_2,//һ���¼���������ǰֵ
	INDEX_AFN_D_F5_EVENT_STATE,//�¼�״̬��־
	INDEX_AFN_D_F6_POWR_TIMES,//�ϵ����

	//��2pn:p0/����ն˺�
	INDEX_AFN_D_F9_STATE,//״̬������λ��־
	INDEX_AFN_D_F10_SWITCH,//���������·���ؽ���״̬������λ��־

	//��4pn:p0/�����������
	INDEX_AFN_D_F25_POWR_HAVE_T,//���й�����
	INDEX_AFN_D_F26_POWR_NONE_T,//���޹�����
	INDEX_AFN_D_F27_FACTR_T,//�ܹ�������
	INDEX_AFN_D_F28_FACTR_A,//A�๦������
	INDEX_AFN_D_F29_FACTR_B,//B�๦������
	INDEX_AFN_D_F30_FACTR_C,//C�๦������

	//��5pn:p0/�����������
	INDEX_AFN_D_F33_DEMAND,//����
	INDEX_AFN_D_F34_DEMAND_MAX,//���������
	INDEX_AFN_D_F35_DEMAND_TIME,//�������������ʱ��

	//��6pn:�����������
	INDEX_AFN_D_F41_POWR_HAVE_A,//A���й�����
	INDEX_AFN_D_F42_POWR_HAVE_B,//B���й�����
	INDEX_AFN_D_F43_POWR_HAVE_C,//C���й�����
	INDEX_AFN_D_F44_POWR_NONE_A,//A���޹�����
	INDEX_AFN_D_F45_POWR_NONE_B,//B���޹�����
	INDEX_AFN_D_F46_POWR_NONE_C,//C���޹�����

	//��7pn:�����������
	INDEX_AFN_D_F49_POWR_HAVE_FRTH,//�������й��ܵ���ʾ��
	INDEX_AFN_D_F50_POWR_HAVE_BACK,//�������й��ܵ���ʾ��
	INDEX_AFN_D_F51_POWR_NONE_FRTH,//�������޹��ܵ���ʾ��
	INDEX_AFN_D_F52_POWR_NONE_BACK,//�������޹��ܵ���ʾ��

	//��8pn:�����������
	INDEX_AFN_D_F57_VOLT_A,//A���ѹ
	INDEX_AFN_D_F58_VOLT_B,//B���ѹ
	INDEX_AFN_D_F59_VOLT_C,//C���ѹ
	INDEX_AFN_D_F60_VANGL_A,//A���ѹ��λ��
	INDEX_AFN_D_F61_VANGL_B,//B���ѹ��λ��
	INDEX_AFN_D_F62_VANGL_C,//C���ѹ��λ��
	INDEX_AFN_D_F63_VOLT_UBL,//��ѹ��ƽ���
	INDEX_AFN_D_F64_CIRCLE_V0,//�ܲ�

	//��9pn:�����������
	INDEX_AFN_D_F65_ELEC_A,//A�����
	INDEX_AFN_D_F66_ELEC_B,//B�����
	INDEX_AFN_D_F67_ELEC_C,//C�����
	INDEX_AFN_D_F68_ELEC_M,//�����ߵ���
	INDEX_AFN_D_F69_EANGL_A,//A�������λ��
	INDEX_AFN_D_F70_EANGL_B,//B�������λ��
	INDEX_AFN_D_F71_EANGL_C,//C�������λ��
	INDEX_AFN_D_F72_ELEC_UBL,//������ƽ���

	//��10pn:�����������
	INDEX_AFN_D_F73_VDMAX_A,//��A���ѹ����ֵ
	INDEX_AFN_D_F74_VDMAX_A_TIME,//��A���ѹ����ֵ����ʱ��
	INDEX_AFN_D_F75_VDMAX_B,//��A���ѹ����ֵ
	INDEX_AFN_D_F76_VDMAX_B_TIME,//��A���ѹ����ֵ����ʱ��
	INDEX_AFN_D_F77_VDMAX_C,//��A���ѹ����ֵ
	INDEX_AFN_D_F78_VDMAX_C_TIME,//��A���ѹ����ֵ����ʱ��

	//��11pn:�����������
	INDEX_AFN_D_F81_IDMAX_A,//��A���������ֵ
	INDEX_AFN_D_F82_IDMAX_A_TIME,//��A���������ֵ����ʱ��
	INDEX_AFN_D_F83_IDMAX_B,//��B���������ֵ
	INDEX_AFN_D_F84_IDMAX_B_TIME,//��B���������ֵ����ʱ��
	INDEX_AFN_D_F85_IDMAX_C,//��C���������ֵ
	INDEX_AFN_D_F86_IDMAX_C_TIME,//��C���������ֵ����ʱ��

	//��12pn:�����������
	INDEX_AFN_D_F89_TFW_HAVE,//�ܻ����й�����(TotalFundamentalWave)
	INDEX_AFN_D_F90_TFW_NONE,//�ܻ����޹�����
	INDEX_AFN_D_F91_THW_HAVE,//��г���й�����(TotalHarmonicWave)
	INDEX_AFN_D_F92_THW_NONE,//�ܻ����޹�����

	//��13pn:�����������
	INDEX_AFN_D_F97_VDPP_TIME_A,//A���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F98_VDPP_TIME_B,//B���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F99_VDPP_TIME_C,//C���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F100_VDNN_TIME_A,//A���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F101_VDNN_TIME_B,//B���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F102_VDNN_TIME_C,//C���ѹԽ���������ۼ�ʱ��

	//��14pn:�����������
	INDEX_AFN_D_F105_VMPP_TIME_A,//A���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F106_VMPP_TIME_B,//B���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F107_VMPP_TIME_C,//C���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F108_VMNN_TIME_A,//A���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F109_VMNN_TIME_B,//B���ѹԽ���������ۼ�ʱ��
	INDEX_AFN_D_F110_VMNN_TIME_C,//C���ѹԽ���������ۼ�ʱ��

	//��15pn:�����������(aberrance)
	INDEX_AFN_D_F113_VABR_TOTL_A,//A���ѹ�ܻ�����
	INDEX_AFN_D_F114_VABR_TOTL_B,//B���ѹ�ܻ�����
	INDEX_AFN_D_F115_VABR_TOTL_C,//C���ѹ�ܻ�����
	INDEX_AFN_D_F116_EABR_TOTL_A,//A������ܻ�����
	INDEX_AFN_D_F117_EABR_TOTL_B,//B������ܻ�����
	INDEX_AFN_D_F118_EABR_TOTL_C,//C������ܻ�����

	//��16pn:�����������
	INDEX_AFN_D_F121_VABR_ODD_A,//A���ѹ��λ�����
	INDEX_AFN_D_F122_VABR_EVN_A,//A���ѹż�λ�����
	INDEX_AFN_D_F123_VABR_ODD_B,//B���ѹ��λ�����
	INDEX_AFN_D_F124_VABR_EVN_B,//B���ѹż�λ�����
	INDEX_AFN_D_F125_VABR_ODD_C,//C���ѹ��λ�����
	INDEX_AFN_D_F126_VABR_EVN_C,//C���ѹż�λ�����

	//��17pn:�����������
	INDEX_AFN_D_F128_EABR_OOD_A0,//A�������λ�����
	INDEX_AFN_D_F129_EABR_EVN_A,//A�����ż�λ�����
	INDEX_AFN_D_F130_EABR_OOD_B,//B�������λ�����
	INDEX_AFN_D_F131_EABR_EVN_B,//B�����ż�λ�����
	INDEX_AFN_D_F132_EABR_OOD_C,//C�������λ�����
	INDEX_AFN_D_F133_EABR_EVN_C,//C�����ż�λ�����

	//��18pn:�����������
	INDEX_AFN_D_F137_FLS_SHRT_A,//A���ʱ����
	INDEX_AFN_D_F138_FLS_SHRT_B,//B���ʱ����
	INDEX_AFN_D_F139_FLS_SHRT_C,//C���ʱ����
	INDEX_AFN_D_F140_FLS_LONG_A,//A�೤ʱ����
	INDEX_AFN_D_F141_FLS_LONG_B,//B�೤ʱ����
	INDEX_AFN_D_F142_FLS_LONG_C,//C�೤ʱ����

	//��19pn:�����������
	INDEX_AFN_D_F145_HARM_VOLT_A,//A��N��г����ѹ
	INDEX_AFN_D_F146_HARM_VOLT_B,//B��N��г����ѹ
	INDEX_AFN_D_F147_HARM_VOLT_C,//C��N��г����ѹ
	INDEX_AFN_D_F148_HARM_ELEC_A,//A��N��г������
	INDEX_AFN_D_F149_HARM_ELEC_B,//B��N��г������
	INDEX_AFN_D_F150_HARM_ELEC_C,//C��N��г������

	//��20pn:�����������
	INDEX_AFN_D_F153_HARM_VINC_A,//A��N��г����ѹ������
	INDEX_AFN_D_F154_HARM_VINC_B,//B��N��г����ѹ������
	INDEX_AFN_D_F155_HARM_VINC_C,//C��N��г����ѹ������
	INDEX_AFN_D_F156_HARM_EINC_A,//A��N��г������������
	INDEX_AFN_D_F157_HARM_EINC_B,//B��N��г������������
	INDEX_AFN_D_F158_HARM_EINC_C,//C��N��г������������

	//��30pn:�ǵ����������
	INDEX_AFN_D_F233_NELC_VALUE,//�ǵ�����
	
	INDEX_MCMD_MAX,

}eRealFnIndex; // ��������

typedef struct  
{
	eMcmd eCmd;
	CString sName;

}sRealCmdName;
 
typedef enum
{
	FREZ_MONTH,   // ��
	FREZ_DAY,     // ��
	FREZ_HOUR,    // ʱ
	FREZ_MIN,     // ����
	FREZ_SEC,     // ��
	FREZ_MS,      // ����
	FREZ_MAX	
}eUnitFrez_index;

typedef enum
{
	REPT_MONTH,   // ��
	REPT_DAY,     // ��
	REPT_HOUR,    // ʱ
	REPT_MIN,     // ����
	REPT_MAX

}eUnitRpt_index;



class CDlgPreAfn04F49 : public CDialog
{
// Construction
public:
	CDlgPreAfn04F49(CWnd* pParent = NULL);   // standard constructor
	sRealCmdName m_cmdName[INDEX_MCMD_MAX];

	BOOL AddCmdPnList(sMcmdPn cmdPn);
	CString m_strFrezUint[FREZ_MAX];
	CString m_strReptUint[REPT_MAX];

	void GetCurValues();
	void SetNewValues();
	
// Dialog Data
	//{{AFX_DATA(CDlgPreAfn04F49)
	enum { IDD = IDD_DLG_PRE_AFN04_F49 };
	CDateTimeCtrl	m_time_rept;
	CDateTimeCtrl	m_date_rept;
	CComboBox	m_cmb_rept_unit;
	CComboBox	m_cmb_frez_uint;
	CDateTimeCtrl	m_time_frez;
	CDateTimeCtrl	m_date_frez;
	CColorListCtrl	m_list;
	CComboBox	m_cmb_fn_add;
	CShadeButtonST	m_btn_ok;
	CShadeButtonST	m_btn_no;
	UINT	m_edit_pn;
	UINT	m_edit_frez_ucTimes;
	UINT	m_edit_Frez_usPeriod;
	UINT	m_edit_rept_ucPeriod;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPreAfn04F49)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPreAfn04F49)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDel();
	afx_msg void OnEditchangeCmbFnAdd();
	afx_msg void OnSelendokCmbFnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPREAFN04F49_H__1D368CBD_0A8E_429D_9A63_06DDC8888F46__INCLUDED_)
