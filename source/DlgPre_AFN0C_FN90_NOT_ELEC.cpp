// DlgPre_AFN0C_FN90_NOT_ELEC.cpp : implementation file
//

#include "stdafx.h"
#include "NxMaster.h"
#include "DlgPre_AFN0C_FN90_NOT_ELEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPre_AFN0C_FN90_NOT_ELEC dialog


CDlgPreAfn0cF90_NotElec::CDlgPreAfn0cF90_NotElec(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPreAfn0cF90_NotElec::IDD, pParent)
{
	m_strTile = "��վԤ�� (AFN 0C F90)�ǵ������������";
	m_bMaster = FALSE;
	//{{AFX_DATA_INIT(CDlgPre_AFN0C_FN90_NOT_ELEC)

		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgPreAfn0cF90_NotElec::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPre_AFN0C_FN90_NOT_ELEC)
	DDX_Control(pDX, IDC_EDIT_VALUE, m_edit_value);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comb_type);
	DDX_Control(pDX, IDC_EDIT_PN, m_edit_pn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPreAfn0cF90_NotElec, CDialog)
	//{{AFX_MSG_MAP(CDlgPre_AFN0C_FN90_NOT_ELEC)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgPreAfn0cF90_NotElec::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(m_strTile);
	InitCombType();
	GetPreData();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPreAfn0cF90_NotElec::setTitle( CString strTitle )
{
	m_strTile = strTitle;
}


// get pre data and show them
void CDlgPreAfn0cF90_NotElec::GetPreData()
{
	CNxConfig cfg;
	
	UINT16 usPn = 0;
	//sMtNotElec sNotElec;
	CString strPn, strValue, strType;
	
	if(m_bMaster == TRUE)
	{
		//cfg.GetPreAfn0CF90_NotElec(&usPn,&sNotElec, MT_ROLE_MASTER);
	}
	else
	{
    //	cfg.GetPreAfn0CF90_NotElec(&usPn,&sNotElec, MT_ROLE_CONTOR);
	}

	
	
	


		/*
	switch (sNotElec.eType)
	{
	case MT_NELEC_TEMP:
		strType = "�¶�";
		break;
	case MT_NELEC_FLOW:
		strType = "����";
		break;
	case MT_NELEC_FLOW_V:
		strType = "����";
		break;
	case MT_NELEC_PRESS:
		strType = "ѹ��";
		break;
	case MT_NELEC_HUMID:
		strType = "ʪ��";
		break;
	case MT_NELEC_ILLUM:
		strType = "�ն�";
		break;
		
	case MT_NELEC_ROTATE:
		strType = "ת��";
		break;
		
	default:
		strType = "δ֪�ǵ�����";
		break;
	}
	*/
	
	
	// �����б���ʾ
	CString   name_pn      = "�������";            
	CString   name_type    = "�ǵ���������";           
	CString   name_max     = "��������";     
	CString   name_min     = "��������";      
	
//	strValue.Format("%0.3lf",sNotElec.dValue);
	strPn.Format("%d", usPn);
	
	m_edit_pn.SetWindowText(strPn);
//	m_comb_type.SetCurSel(sNotElec.eType - 1);
	if(m_bMaster == TRUE)
	{
		m_edit_value.EnableWindow(FALSE);
	}
	else
	{
		m_edit_value.EnableWindow(TRUE);
		m_edit_value.SetWindowText(strValue);
	}
	
}

// set new data into regedit
void CDlgPreAfn0cF90_NotElec::SetPreData()
{
	CNxConfig cfg;
	UINT16 usPn = 0;
//	sMtNotElec sNotElec;
	CString strValue;
	CString strPn;
	
	//sNotElec.eType = eMtNotElec(m_comb_type.GetCurSel() + 1);
	
	m_edit_value.GetWindowText(strValue);
//	sNotElec.dValue  = atof(strValue);

	m_edit_pn.GetWindowText(strPn);
	usPn = atoi(strPn);
	if(usPn > 2040 )
	{
		MessageBox("���������0~2040֮�䣬��������!");
		return;

	}
	if (m_bMaster == TRUE)
	{
    //	cfg.SetPreAfn0CF90_NotElec(usPn,&sNotElec, MT_ROLE_MASTER);
	}
	else
	{
    //	cfg.SetPreAfn0CF90_NotElec(usPn,&sNotElec, MT_ROLE_CONTOR);
	}

	
}

/////////////////////////////////////////////////////////////////////////////
// CDlgPre_AFN0C_FN90_NOT_ELEC message handlers
void CDlgPreAfn0cF90_NotElec::InitCombType()
{
	
	m_type_name[0] = "�¶�";
	m_type_name[1] = "����";
	m_type_name[2] = "����";
	m_type_name[3] = "ѹ��";
	m_type_name[4] = "ʪ��";
	m_type_name[5] = "�ն�";
	m_type_name[6] = "ת��";
	
	int i;
	for (i = 0; i < 7 ;i ++)
	{
		m_comb_type.InsertString(i, m_type_name[i]);
	}
	
	m_comb_type.SetCurSel(0);
	
}

void CDlgPreAfn0cF90_NotElec::setRole( BOOL bMaster /*= TRUE*/ )
{
	m_bMaster = bMaster;
}

void CDlgPreAfn0cF90_NotElec::OnButtonOk() 
{
	// TODO: Add your control notification handler code here

	CString strPn;
	UINT16 usPn;
	m_edit_pn.GetWindowText(strPn);
	usPn = atoi(strPn);
	if(usPn > 2040 )
	{
		MessageBox("���������0~2040֮�䣬��������!");
		m_edit_pn.SetFocus();
		m_edit_pn.SetSel(0,strPn.GetLength());

		return;
		
	}
	else
	{
		SetPreData();
        CDialog::OnOK();
	}

}
