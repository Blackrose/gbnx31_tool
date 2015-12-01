// TabDlgPreMaster.cpp : implementation file
//

#include "stdafx.h"
#include "NxMaster.h"
#include "TabDlgPreMaster.h"


#include "DlgPreAfn04F1.h"
#include "DlgPreAfn04F33.h"
#include "DlgPreA00F1.h"
#include "DlgPreAfn04F2.h"
#include "DlgPreAfn04F3.h"
#include "DlgPreAfn04F4.h"
#include "DlgPreAfn04F5.h"
#include "DlgPreAfn04F6.h"
#include "DlgPreAfn04F7.h"
#include "DlgPreAfn04F9.h"
#include "DlgPreAfn04F10.h"
#include "DlgPreAfn04F17.h"
#include "DlgPreAfn04F25_33.h"
#include "DlgPreAfn04F26.h"
#include "DlgPreAfn04F27.h"
#include "DlgPreAfn04F28.h"
#include "DlgPreAfn04F29.h"
#include "DlgPreAfn04F30.h"
#include "DlgPreAfn04F34.h"
#include "DlgPreAfn04F35.h"
#include "DlgPreAfn04F49.h"
#include "DlgPreAfn0aF2.h"
#include "DlgPreAfn0AF7Q.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDlgPreMaster dialog


CTabDlgPreMaster::CTabDlgPreMaster(CWnd* pParent /*=NULL*/)
	: CDialog(CTabDlgPreMaster::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabDlgPreMaster)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT



}

CTabDlgPreMaster::~CTabDlgPreMaster()
{

}

void CTabDlgPreMaster::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDlgPreMaster)
	DDX_Control(pDX, IDC_BTN_MODIFY, m_btn_modify);
	DDX_Control(pDX, IDC_EDIT_PN, m_edit_pn);
	DDX_Control(pDX, IDC_TREE_PRE_MST, m_tree);
	DDX_Control(pDX, IDC_LIST_PRE_MST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabDlgPreMaster, CDialog)
	//{{AFX_MSG_MAP(CTabDlgPreMaster)
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_NOTIFY(TVN_ITEMEXPANDED, IDC_TREE_PRE_MST, OnItemexpandedTreePreMst)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_PRE_MST, OnSelchangedTreePreMst)
	ON_BN_CLICKED(IDC_BTN_MODIFY, OnBtnModify)
	ON_EN_CHANGE(IDC_EDIT_PN, OnChangeEditPn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDlgPreMaster message handlers

void CTabDlgPreMaster::initList()
{
	m_list.SetHeadings(_T("��������,150;��������,100;��λ��ʽ,80;��Χ˵��,100"));
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
}



// ��ʼ�� ��վ����Ԥ�� �����ϵ�Э��ѡ����
void CTabDlgPreMaster::initProtoTree()
{
	m_imagelist = new CImageList();
	m_tree.SetItemHeight(m_tree.GetItemHeight()+2);
    //m_imagelist->Create(16,16,ILC_COLOR32,0,0);
	m_imagelist->Create(16,16,ILC_COLOR32,0,0);
	m_imagelist->SetBkColor(RGB(255,255,255));

	
	#define ICON_MAX 3
	int i = 0;
	HICON hicon[ICON_MAX];
	int ico_afn;
	int ico_fn;
	int ico_sel;

	hicon[ico_afn = 0] = AfxGetApp()->LoadIcon(IDI_ICON9);
	hicon[ico_sel = 1] = AfxGetApp()->LoadIcon(IDI_ICON_CHECK);
	hicon[ico_fn  = 2] = AfxGetApp()->LoadIcon(IDI_ICON_CHECK_NO);


	for (i = 0; i < ICON_MAX; i++)
	{
		m_imagelist->Add(hicon[i]);
	}
	
	m_tree.SetImageList(m_imagelist,TVSIL_NORMAL);


	HTREEITEM hitem;
	//afn 00
	hitem = m_tree.InsertItem(STR_AFN_00_CONF,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_00_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	//m_tree.InsertItem(STR_AFN_00_F2,ico_fn,ico_sel,hitem,TVI_LAST);

	// afn 01
	hitem = m_tree.InsertItem(STR_AFN_01_RSET,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_01_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_01_F2,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_01_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_01_F4,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_01_F5,ico_fn,ico_sel,hitem,TVI_LAST);

	// afn 02
	hitem = m_tree.InsertItem(STR_AFN_02_LINK,ico_afn,ico_afn,TVI_ROOT);
	//m_tree.InsertItem(STR_AFN_02_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	//m_tree.InsertItem(STR_AFN_02_F2,ico_fn,ico_sel,hitem,TVI_LAST);
	//m_tree.InsertItem(STR_AFN_02_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_02_F4,ico_fn,ico_sel,hitem,TVI_LAST);

	// afn 04
	hitem = m_tree.InsertItem(STR_AFN_04_SETP,ico_afn,ico_afn,TVI_ROOT);
	
	m_tree.InsertItem(STR_AFN_04_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F2,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F4,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F5,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F6,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F7,ico_fn,ico_sel,hitem,TVI_LAST);
	// m_tree.InsertItem(STR_AFN_04_F8,ico_fn,ico_sel,hitem,TVI_LAST);
	
	m_tree.InsertItem(STR_AFN_04_F9,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F10,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F11,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F12,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F13,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F14,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F15,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F16,ico_fn,ico_sel,hitem,TVI_LAST);
	
	m_tree.InsertItem(STR_AFN_04_F17,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F18,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F19,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F20,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F21,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F22,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F23,ico_fn,ico_sel,hitem,TVI_LAST);
	
	m_tree.InsertItem(STR_AFN_04_F25,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F26,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F27,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F28,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F29,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F30,ico_fn,ico_sel,hitem,TVI_LAST);
	
	// m_tree.InsertItem(STR_AFN_04_F31,ico_fn,ico_sel,hitem,TVI_LAST);
	
	m_tree.InsertItem(STR_AFN_04_F33,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F34,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F35,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_04_F49,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F36,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F37,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F38,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F39,ico_fn,ico_sel,hitem,TVI_LAST);
// 	
// 	m_tree.InsertItem(STR_AFN_04_F41,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F42,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F43,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F44,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F45,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F46,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F47,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F48,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F57,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F58,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F59,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F60,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F61,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F65,ico_fn,ico_sel,hitem,TVI_LAST);
// 	
// 	m_tree.InsertItem(STR_AFN_04_F66,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F67,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F68,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F73,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F74,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F75,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F76,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F81,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_04_F82,ico_fn,ico_sel,hitem,TVI_LAST);
	// 	m_tree.InsertItem(STR_AFN_04_F83,ico_fn,ico_sel,hitem,TVI_LAST);

	// afn 05
	hitem = m_tree.InsertItem(STR_AFN_05_CTRL,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_05_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F2,ico_fn,ico_sel,hitem,TVI_LAST);	
	m_tree.InsertItem(STR_AFN_05_F3,ico_fn,ico_sel,hitem,TVI_LAST);	
	m_tree.InsertItem(STR_AFN_05_F4,ico_fn,ico_sel,hitem,TVI_LAST);	
	m_tree.InsertItem(STR_AFN_05_F5,ico_fn,ico_sel,hitem,TVI_LAST);	
	m_tree.InsertItem(STR_AFN_05_F6,ico_fn,ico_sel,hitem,TVI_LAST);	
    m_tree.InsertItem(STR_AFN_05_F9,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F10,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F11,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F12,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F15,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F16,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F17,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F18,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F19,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F20,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F23,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F24,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F25,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F26,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F27,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_05_F28,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F29,ico_fn,ico_sel,hitem,TVI_LAST);		
// 	m_tree.InsertItem(STR_AFN_05_F31,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F32,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F33,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F34,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F35,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F36,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F37,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F38,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F39,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F41,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F42,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F49,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F50,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F51,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_05_F52,ico_fn,ico_sel,hitem,TVI_LAST);
//     m_tree.InsertItem(STR_AFN_05_F53,ico_fn,ico_sel,hitem,TVI_LAST);

	
	// afn06
	hitem = m_tree.InsertItem(STR_AFN_06_AUTH,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_06_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_06_F2,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_06_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_06_F4,ico_fn,ico_sel,hitem,TVI_LAST);

	// afn 09
// 	hitem = m_tree.InsertItem(STR_AFN_09_CFIG,ico_afn,ico_afn,TVI_ROOT);
// 	m_tree.InsertItem(STR_AFN_09_F1,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_09_F4,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_09_F5,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_09_F6,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_09_F7,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_09_F8,ico_fn,ico_sel,hitem,TVI_LAST);

	// AFN 0A
	hitem = m_tree.InsertItem(STR_AFN_0A_GETP,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_0A_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F2,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F4,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F5,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F6,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F7,ico_fn,ico_sel,hitem,TVI_LAST);
	// m_tree.InsertItem(STR_AFN_0A_F8,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F9,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F10,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F11,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F12,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F13,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F14,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F15,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F16,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F17,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F18,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F19,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F20,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F21,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F22,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F23,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F25,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F26,ico_fn,ico_sel,hitem,TVI_LAST);

	 m_tree.InsertItem(STR_AFN_0A_F27,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F28,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F29,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F30,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F31,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F33,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F34,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F35,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F36,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F36,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F37,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F38,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F39,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F41,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F42,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F43,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F44,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F45,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F46,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F47,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F48,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F49,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0A_F57,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F58,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F59,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F60,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F61,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F65,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F66,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F67,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F68,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F73,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F74,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F75,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F76,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F81,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0A_F82,ico_fn,ico_sel,hitem,TVI_LAST);
// 		m_tree.InsertItem(STR_AFN_0A_F83,ico_fn,ico_sel,hitem,TVI_LAST);

	
	// AFN 0B
// 	hitem = m_tree.InsertItem(STR_AFN_0B_ASKT,ico_afn,ico_afn,TVI_ROOT);
// 	m_tree.InsertItem(STR_AFN_0B_F1,ico_fn,ico_sel,hitem,TVI_LAST);
// 	m_tree.InsertItem(STR_AFN_0B_F2,ico_fn,ico_sel,hitem,TVI_LAST);

	// 	AFN 0C
	hitem = m_tree.InsertItem(STR_AFN_0C_ASKT,ico_afn,ico_afn,TVI_ROOT);
	
		m_tree.InsertItem( STR_AFN_0C_F1 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F3�ն˲���״̬"
		m_tree.InsertItem( STR_AFN_0C_F9 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F3�ն˲���״̬"
// 		m_tree.InsertItem( STR_AFN_0C_F4 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F4�ն�����ͨ��״̬"
// 		m_tree.InsertItem( STR_AFN_0C_F5 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F5�ն˿�������״̬"
// 		m_tree.InsertItem( STR_AFN_0C_F6 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F6�ն˵�ǰ����״̬"
// 		m_tree.InsertItem( STR_AFN_0C_F7 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F7�ն��¼���������ǰֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F8 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F8�ն��¼���־״̬"
// 		
// 		//2
// 		m_tree.InsertItem( STR_AFN_0C_F9 ,ico_fn,ico_sel,hitem,TVI_LAST);//"F9�ն�״̬������λ��־"
// 		m_tree.InsertItem( STR_AFN_0C_F10   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F10  �ն�����վ���ա���ͨ������"
// 		m_tree.InsertItem( STR_AFN_0C_F11   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F10  �ն˼��г���״̬��Ϣ"
// 		
// 		//3
// 		m_tree.InsertItem( STR_AFN_0C_F17   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F17  ��ǰ�ܼ��й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F18   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F18  ��ǰ�ܼ��޹�����"
// 		m_tree.InsertItem( STR_AFN_0C_F19   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F19  �����ܼ��й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F20   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F20  �����ܼ��޹�������"
// 		m_tree.InsertItem( STR_AFN_0C_F21   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F21  �����ܼ��й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F22   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F22  �����ܼ��޹�������"
// 		m_tree.InsertItem( STR_AFN_0C_F23   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F23  �ն˵�ǰʣ�����(��)"
// 		m_tree.InsertItem( STR_AFN_0C_F24   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F24  ��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ"
// 		
// 		//4
// 		m_tree.InsertItem( STR_AFN_0C_F25   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F25  ��ǰ���༰����/�޹����ʡ��������� , �����ѹ��������������������ڹ���"
// 		m_tree.InsertItem( STR_AFN_0C_F26   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F26  A��B��C�������ͳ�����ݼ����һ�ζ����¼"
// 		m_tree.InsertItem( STR_AFN_0C_F27   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F27  ���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F28   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F28  �������״̬�ּ����λ��־"
// 		m_tree.InsertItem( STR_AFN_0C_F29   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F29  ��ǰͭ�������й��ܵ���ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F30   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F30  ��һ�����յ�ǰͭ�������й��ܵ���ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F31   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F31  ��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F32   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F32  ��һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"
// 		
// 		//5
// 		m_tree.InsertItem( STR_AFN_0C_F33   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F33  ��ǰ������/�޹�(����޹�1)����ʾֵ��һ/�������޹�����ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F34   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F34  ��ǰ������/�޹�(����޹�2)����ʾֵ����/�������޹�����ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F35   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F35  ����������/�޹��������������ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F36   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F36  ���·�����/�޹��������������ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F37   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F37  ����(��һ������)������/�޹�(����޹�1)����ʾֵ��һ/�������޹�����ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F38   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F38  ����(��һ������)������/�޹�(����޹�2)����ʾֵ����/�������޹�����ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F39   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F39  ���£���һ�����գ�������/�޹��������������ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F40   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F40  ���£���һ�����գ�������/�޹��������������ʱ��"
// 		
// 		//6
// 		m_tree.InsertItem( STR_AFN_0C_F41   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F41  ���������й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F42   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F42  ���������޹�������"
// 		m_tree.InsertItem( STR_AFN_0C_F43   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F43  ���շ����й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F44   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F44  ���շ����޹�������"
// 		m_tree.InsertItem( STR_AFN_0C_F45   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F45  ���������й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F46   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F46  ���������޹�������"
// 		m_tree.InsertItem( STR_AFN_0C_F47   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F47  ���·����й�������"
// 		m_tree.InsertItem( STR_AFN_0C_F48   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F48  ���·����޹�������"
// 		
// 		//7
// 		m_tree.InsertItem( STR_AFN_0C_F49   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F49  ��ǰ��ѹ��������λ��"
// 		
// 		//8
// 		
// 		m_tree.InsertItem( STR_AFN_0C_F57   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F57  ��ǰA��B��C�����ѹ������2��N��г����Чֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F58   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F58  ��ǰA��B��C�����ѹ������2��N��г��������"
// 		
// 		//9
// 		m_tree.InsertItem( STR_AFN_0C_F65   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F65  ��ǰ������Ͷ��״̬"
// 		m_tree.InsertItem( STR_AFN_0C_F66   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F66  ��ǰ�������ۼƲ���Ͷ��ʱ��ʹ���"
// 		m_tree.InsertItem( STR_AFN_0C_F67   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F67  ���ա����µ������ۼƲ������޹�������"
// 		
// 		//10
// 		
// 		m_tree.InsertItem( STR_AFN_0C_F73   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F73  ֱ��ģ����ʵʱ����"
// 		//11
// 		m_tree.InsertItem( STR_AFN_0C_F81   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F81  Сʱ�����ܼ��й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F82   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F82  Сʱ�����ܼ��޹�����"
// 		m_tree.InsertItem( STR_AFN_0C_F83   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F83  Сʱ�����ܼ��й��ܵ�����"
// 		m_tree.InsertItem( STR_AFN_0C_F84   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F84  Сʱ�����ܼ��޹��ܵ�����"
// 		
// 		//12
// 		m_tree.InsertItem( STR_AFN_0C_F89   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F89  Сʱ�����й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F90   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F90  Сʱ����A���й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F91   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F91  Сʱ����B���й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F92   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F92  Сʱ����C���й�����"
// 		m_tree.InsertItem( STR_AFN_0C_F93   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F93  Сʱ�����޹�����"
// 		m_tree.InsertItem( STR_AFN_0C_F94   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F94  Сʱ����A���޹�����"
// 		m_tree.InsertItem( STR_AFN_0C_F95   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F95  Сʱ����B���޹�����"
// 		m_tree.InsertItem( STR_AFN_0C_F96   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F96  Сʱ����C���޹�����"
// 		//13
// 		m_tree.InsertItem( STR_AFN_0C_F97   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F97  Сʱ����A���ѹ"
// 		m_tree.InsertItem( STR_AFN_0C_F98   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F98  Сʱ����B���ѹ"
// 		m_tree.InsertItem( STR_AFN_0C_F99   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F99  Сʱ����C���ѹ"
// 		m_tree.InsertItem( STR_AFN_0C_F100   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F100  Сʱ����A�����"
// 		m_tree.InsertItem( STR_AFN_0C_F101   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F101  Сʱ����B�����"
// 		m_tree.InsertItem( STR_AFN_0C_F102   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F102  Сʱ����C�����"
// 		m_tree.InsertItem( STR_AFN_0C_F103   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F103  Сʱ�����������"
// 		
// 		//14
// 		m_tree.InsertItem( STR_AFN_0C_F105   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F105  Сʱ���������й��ܵ�����"
// 		m_tree.InsertItem( STR_AFN_0C_F106   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F106  Сʱ���������޹��ܵ�����"
// 		m_tree.InsertItem( STR_AFN_0C_F107   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F107  Сʱ���ᷴ���й��ܵ�����"
// 		m_tree.InsertItem( STR_AFN_0C_F108   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F108  Сʱ���ᷴ���޹��ܵ�����"
// 		m_tree.InsertItem( STR_AFN_0C_F109   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F109  Сʱ���������й��ܵ���ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F110   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F110  Сʱ���������޹��ܵ���ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F111   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F111  Сʱ���ᷴ���й��ܵ���ʾֵ"
// 		m_tree.InsertItem( STR_AFN_0C_F112   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F112  Сʱ���ᷴ���޹��ܵ���ʾֵ"
// 		
// 		//15
// 		m_tree.InsertItem( STR_AFN_0C_F113   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F113  Сʱ�����ܹ�������"
// 		m_tree.InsertItem( STR_AFN_0C_F114   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F114  Сʱ����A�๦������"
// 		m_tree.InsertItem( STR_AFN_0C_F115   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F115  Сʱ����B�๦������"
// 		m_tree.InsertItem( STR_AFN_0C_F116   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F116  Сʱ����C�๦������"
// 		
// 		// 16
// 		m_tree.InsertItem( STR_AFN_0C_F121   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F121  Сʱ����ֱ��ģ����"
// 		
// 		//17
// 		m_tree.InsertItem( STR_AFN_0C_F129   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F129  ��ǰ�����й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F130   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F130  ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F131   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F131  ��ǰ�����й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F132   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F132  ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F133   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F133  ��ǰһ�����޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F134   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F134  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F135   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F135  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F136   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F136  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// 		//18
// 		m_tree.InsertItem( STR_AFN_0C_F137   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F137  ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F138   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F138  ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F139   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F139  ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F140   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F140  ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F141   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F141  ���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F142   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F142  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F143   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F143  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F144   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F144  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// 		
// 		//19
// 		m_tree.InsertItem( STR_AFN_0C_F145   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F145  ���������й��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F146   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F146  ���������޹��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F147   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F147  ���·����й��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F148   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F148  ���·����޹��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F149   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F149  ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F150   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F150  ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F151   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F151  ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F152   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F152  ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"
// 		//20
// 		m_tree.InsertItem( STR_AFN_0C_F153   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F153  ��һʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F154   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F154  �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F155   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F155  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F156   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F156  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F157   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F157  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F158   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F158  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F159   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F159  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		m_tree.InsertItem( STR_AFN_0C_F160   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F160  �ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// 		//21
// 		m_tree.InsertItem( STR_AFN_0C_F161   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F161  ���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"
// 		m_tree.InsertItem( STR_AFN_0C_F165   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F165  ���ܱ��ز���������ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F166   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F166  ���ܱ�����޸Ĵ�����ʱ��"
// 		m_tree.InsertItem( STR_AFN_0C_F167   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F167  ���ܱ����õ���Ϣ"
// 		m_tree.InsertItem( STR_AFN_0C_F168   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F168  ���ܱ������Ϣ"
// 		
// 		//22
// 		m_tree.InsertItem( STR_AFN_0C_F169   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F169  ���г����м�·����Ϣ"
// 		m_tree.InsertItem( STR_AFN_0C_F170   ,ico_fn,ico_sel,hitem,TVI_LAST);//"F170  ���г���������Ϣ"

		
	// AFN 0D
	hitem = m_tree.InsertItem(STR_AFN_0D_ASKR,ico_afn,ico_afn,TVI_ROOT);
	//��1 pn: p0/����ն˺�
	m_tree.InsertItem(STR_CMD_AFN_D_F1_CLOCK, ico_fn,ico_sel,hitem,TVI_LAST);//����ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F2_PARA_STATE, ico_fn,ico_sel,hitem,TVI_LAST);//����״̬��־
	m_tree.InsertItem(STR_CMD_AFN_D_F3_EVENT_1, ico_fn,ico_sel,hitem,TVI_LAST);//��Ҫ�¼���������ǰֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F4_EVENT_2, ico_fn,ico_sel,hitem,TVI_LAST);//һ���¼���������ǰֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F5_EVENT_STATE, ico_fn,ico_sel,hitem,TVI_LAST);//�¼�״̬��־
	m_tree.InsertItem(STR_CMD_AFN_D_F6_POWR_TIMES, ico_fn,ico_sel,hitem,TVI_LAST);//�ϵ���� 
	//��2 pn:p0/����ն˺�
	m_tree.InsertItem(STR_CMD_AFN_D_F9_STATE, ico_fn,ico_sel,hitem,TVI_LAST);//״̬������λ��־
	m_tree.InsertItem(STR_CMD_AFN_D_F10_SWITCH, ico_fn,ico_sel,hitem,TVI_LAST);//���������·���ؽ���״̬������λ��־ 
	//��4 pn:p0/�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F25_POWR_HAVE_T, ico_fn,ico_sel,hitem,TVI_LAST);//���й�����
	m_tree.InsertItem(STR_CMD_AFN_D_F26_POWR_NONE_T, ico_fn,ico_sel,hitem,TVI_LAST);//���޹�����
	m_tree.InsertItem(STR_CMD_AFN_D_F27_FACTR_T, ico_fn,ico_sel,hitem,TVI_LAST);//�ܹ�������
	m_tree.InsertItem(STR_CMD_AFN_D_F28_FACTR_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�๦������
	m_tree.InsertItem(STR_CMD_AFN_D_F29_FACTR_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�๦������
	m_tree.InsertItem(STR_CMD_AFN_D_F30_FACTR_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�๦������
	//��5 pn:p0/�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F33_DEMAND, ico_fn,ico_sel,hitem,TVI_LAST);//����
	m_tree.InsertItem(STR_CMD_AFN_D_F34_DEMAND_MAX, ico_fn,ico_sel,hitem,TVI_LAST);//���������
	m_tree.InsertItem(STR_CMD_AFN_D_F35_DEMAND_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//�������������ʱ�� 
	//��6 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F41_POWR_HAVE_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���й�����
	m_tree.InsertItem(STR_CMD_AFN_D_F42_POWR_HAVE_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���й�����
	m_tree.InsertItem(STR_CMD_AFN_D_F43_POWR_HAVE_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���й�����
	m_tree.InsertItem(STR_CMD_AFN_D_F44_POWR_NONE_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���޹�����
	m_tree.InsertItem(STR_CMD_AFN_D_F45_POWR_NONE_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���޹�����
	m_tree.InsertItem(STR_CMD_AFN_D_F46_POWR_NONE_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���޹����� 
	//��7 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F49_POWR_HAVE_FRTH, ico_fn,ico_sel,hitem,TVI_LAST);//�������й��ܵ���ʾ��
	m_tree.InsertItem(STR_CMD_AFN_D_F50_POWR_HAVE_BACK, ico_fn,ico_sel,hitem,TVI_LAST);//�������й��ܵ���ʾ��
	m_tree.InsertItem(STR_CMD_AFN_D_F51_POWR_NONE_FRTH, ico_fn,ico_sel,hitem,TVI_LAST);//�������޹��ܵ���ʾ��
	m_tree.InsertItem(STR_CMD_AFN_D_F52_POWR_NONE_BACK, ico_fn,ico_sel,hitem,TVI_LAST);//�������޹��ܵ���ʾ�� 
	//��8 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F57_VOLT_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F58_VOLT_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F59_VOLT_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F60_VANGL_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹ��λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F61_VANGL_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹ��λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F62_VANGL_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹ��λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F63_VOLT_UBL, ico_fn,ico_sel,hitem,TVI_LAST);//��ѹ��ƽ���
	m_tree.InsertItem(STR_CMD_AFN_D_F64_CIRCLE_V, ico_fn,ico_sel,hitem,TVI_LAST);//�ܲ�
	//��9 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F65_ELEC_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�����
	m_tree.InsertItem(STR_CMD_AFN_D_F66_ELEC_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�����
	m_tree.InsertItem(STR_CMD_AFN_D_F67_ELEC_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�����
	m_tree.InsertItem(STR_CMD_AFN_D_F68_ELEC_M, ico_fn,ico_sel,hitem,TVI_LAST);//�����ߵ���
	m_tree.InsertItem(STR_CMD_AFN_D_F69_EANGL_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�������λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F70_EANGL_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�������λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F71_EANGL_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�������λ��
	m_tree.InsertItem(STR_CMD_AFN_D_F72_ELEC_UBL, ico_fn,ico_sel,hitem,TVI_LAST);//������ƽ��� 
	//��10 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F73_VDMAX_A, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F74_VDMAX_A_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ����ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F75_VDMAX_B, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F76_VDMAX_B_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ����ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F77_VDMAX_C, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F78_VDMAX_C_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��A���ѹ����ֵ����ʱ�� 
	//��11 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F81_IDMAX_A, ico_fn,ico_sel,hitem,TVI_LAST);//��A���������ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F82_IDMAX_A_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��A���������ֵ����ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F83_IDMAX_B, ico_fn,ico_sel,hitem,TVI_LAST);//��B���������ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F84_IDMAX_B_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��B���������ֵ����ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F85_IDMAX_C, ico_fn,ico_sel,hitem,TVI_LAST);//��C���������ֵ
	m_tree.InsertItem(STR_CMD_AFN_D_F86_IDMAX_C_TIME, ico_fn,ico_sel,hitem,TVI_LAST);//��C���������ֵ����ʱ�� 
	//��12 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F89_TFW_HAVE, ico_fn,ico_sel,hitem,TVI_LAST);//�ܻ����й�����(Total Fundamental Wave)
	m_tree.InsertItem(STR_CMD_AFN_D_F90_TFW_NONE, ico_fn,ico_sel,hitem,TVI_LAST);//�ܻ����޹�����
	m_tree.InsertItem(STR_CMD_AFN_D_F91_THW_HAVE, ico_fn,ico_sel,hitem,TVI_LAST);//��г���й�����(Total Harmonic Wave)
	m_tree.InsertItem(STR_CMD_AFN_D_F92_THW_NONE, ico_fn,ico_sel,hitem,TVI_LAST);//�ܻ����޹����� 
	//��13 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F97_VDPP_TIME_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F98_VDPP_TIME_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F99_VDPP_TIME_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F100_VDNN_TIME_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F101_VDNN_TIME_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F102_VDNN_TIME_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹԽ���������ۼ�ʱ��
	//��14 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F105_VMPP_TIME_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F106_VMPP_TIME_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F107_VMPP_TIME_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F108_VMNN_TIME_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F109_VMNN_TIME_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹԽ���������ۼ�ʱ��
	m_tree.InsertItem(STR_CMD_AFN_D_F110_VMNN_TIME_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹԽ���������ۼ�ʱ�� 
	//��15 pn:����������� (aberrance)
	m_tree.InsertItem(STR_CMD_AFN_D_F113_VABR_TOTL_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹ�ܻ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F114_VABR_TOTL_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹ�ܻ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F115_VABR_TOTL_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹ�ܻ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F116_EABR_TOTL_A, ico_fn,ico_sel,hitem,TVI_LAST);//A������ܻ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F117_EABR_TOTL_B, ico_fn,ico_sel,hitem,TVI_LAST);//B������ܻ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F118_EABR_TOTL_C, ico_fn,ico_sel,hitem,TVI_LAST);//C������ܻ����� 
	//��16 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F121_VABR_ODD_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹ��λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F122_VABR_EVN_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ѹż�λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F123_VABR_ODD_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹ��λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F124_VABR_EVN_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ѹż�λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F125_VABR_ODD_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹ��λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F126_VABR_EVN_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ѹż�λ����� 
	//��17 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F128_EABR_OOD_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�������λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F129_EABR_EVN_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�����ż�λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F130_EABR_OOD_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�������λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F131_EABR_EVN_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�����ż�λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F132_EABR_OOD_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�������λ�����
	m_tree.InsertItem(STR_CMD_AFN_D_F133_EABR_EVN_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�����ż�λ�����
	//��18 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F137_FLS_SHRT_A, ico_fn,ico_sel,hitem,TVI_LAST);//A���ʱ����
	m_tree.InsertItem(STR_CMD_AFN_D_F138_FLS_SHRT_B, ico_fn,ico_sel,hitem,TVI_LAST);//B���ʱ����
	m_tree.InsertItem(STR_CMD_AFN_D_F139_FLS_SHRT_C, ico_fn,ico_sel,hitem,TVI_LAST);//C���ʱ����
	m_tree.InsertItem(STR_CMD_AFN_D_F140_FLS_LONG_A, ico_fn,ico_sel,hitem,TVI_LAST);//A�೤ʱ����
	m_tree.InsertItem(STR_CMD_AFN_D_F141_FLS_LONG_B, ico_fn,ico_sel,hitem,TVI_LAST);//B�೤ʱ����
	m_tree.InsertItem(STR_CMD_AFN_D_F142_FLS_LONG_C, ico_fn,ico_sel,hitem,TVI_LAST);//C�೤ʱ���� 
	//��19 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F145_HARM_VOLT_A, ico_fn,ico_sel,hitem,TVI_LAST);//A��N��г����ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F146_HARM_VOLT_B, ico_fn,ico_sel,hitem,TVI_LAST);//B��N��г����ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F147_HARM_VOLT_C, ico_fn,ico_sel,hitem,TVI_LAST);//C��N��г����ѹ
	m_tree.InsertItem(STR_CMD_AFN_D_F148_HARM_ELEC_A, ico_fn,ico_sel,hitem,TVI_LAST);//A��N��г������
	m_tree.InsertItem(STR_CMD_AFN_D_F149_HARM_ELEC_B, ico_fn,ico_sel,hitem,TVI_LAST);//B��N��г������
	m_tree.InsertItem(STR_CMD_AFN_D_F150_HARM_ELEC_C, ico_fn,ico_sel,hitem,TVI_LAST);//C��N��г������ 
	//��20 pn:�����������
	m_tree.InsertItem(STR_CMD_AFN_D_F153_HARM_VINC_A, ico_fn,ico_sel,hitem,TVI_LAST);//A��N��г����ѹ������
	m_tree.InsertItem(STR_CMD_AFN_D_F154_HARM_VINC_B, ico_fn,ico_sel,hitem,TVI_LAST);//B��N��г����ѹ������
	m_tree.InsertItem(STR_CMD_AFN_D_F155_HARM_VINC_C, ico_fn,ico_sel,hitem,TVI_LAST);//C��N��г����ѹ������
	m_tree.InsertItem(STR_CMD_AFN_D_F156_HARM_EINC_A, ico_fn,ico_sel,hitem,TVI_LAST);//A��N��г������������
	m_tree.InsertItem(STR_CMD_AFN_D_F157_HARM_EINC_B, ico_fn,ico_sel,hitem,TVI_LAST);//B��N��г������������
	m_tree.InsertItem(STR_CMD_AFN_D_F158_HARM_EINC_C, ico_fn,ico_sel,hitem,TVI_LAST);//C��N��г������������ 
	//��30 pn:�ǵ����������
	m_tree.InsertItem(STR_CMD_AFN_D_F233_NELC_VALUE, ico_fn,ico_sel,hitem,TVI_LAST);//�ǵ�����


	// 0E
	hitem = m_tree.InsertItem(STR_AFN_0E_ASKE,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_0E_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_0E_F2,ico_fn,ico_sel,hitem,TVI_LAST);
		m_tree.InsertItem(STR_AFN_0E_F3,ico_fn,ico_sel,hitem,TVI_LAST);
	
	// 0F
	hitem = m_tree.InsertItem(STR_AFN_0F_FILE,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_0F_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	
	// 10
	hitem = m_tree.InsertItem(STR_AFN_10_DATA,ico_afn,ico_afn,TVI_ROOT);
	m_tree.InsertItem(STR_AFN_10_F1,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_10_F9,ico_fn,ico_sel,hitem,TVI_LAST);
	m_tree.InsertItem(STR_AFN_10_F10,ico_fn,ico_sel,hitem,TVI_LAST);
    m_tree.InsertItem(STR_AFN_10_F11,ico_fn,ico_sel,hitem,TVI_LAST);
}

void CTabDlgPreMaster::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

BOOL CTabDlgPreMaster::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	initProtoTree();
	initList();


		m_btn_modify.SetShade(CShadeButtonST::SHS_VSHADE,8,50,5,RGB(255,255,55));
	m_btn_modify.SetIcon(IDI_ICON_NOTE);
	m_btn_modify.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(255, 0, 0));
	m_btn_modify.SetColor(CButtonST::BTNST_COLOR_FG_OUT, RGB(0, 0, 0));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CTabDlgPreMaster::setTreePos()
{
	
	RECT rect_tree, rect_list,rect_client;
	GetClientRect(&rect_client);

	// tree
	const int top    = 10;
	const int border = 3;
	const int weight = 270;
	const int height = 250;
	rect_tree.top    = rect_client.top  + top;
	rect_tree.left   = rect_client.left + border;
	rect_tree.right  = rect_client.right   - border;
	rect_tree.bottom = rect_tree.top    + height;

	if(m_tree.m_hWnd)
	{
		m_tree.MoveWindow(&rect_tree);
	}


	// list
	rect_list.top = rect_tree.bottom + top + 50;
	rect_list.left = rect_tree.left;
	rect_list.right = rect_client.right - border;
	rect_list.bottom = rect_client.bottom - border;
	if(m_list.m_hWnd)
	{
		m_list.MoveWindow(&rect_list);
	}


}


void CTabDlgPreMaster::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	setTreePos();
}

void CTabDlgPreMaster::OnItemexpandedTreePreMst(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}



void CTabDlgPreMaster::ShowMstPreAfn04F1()
{
	/*

	// ȡ��Ԥ������
	sMtAfn04F1 sCnf;
	m_nxCfg.GetMstPreAfn04F1(&sCnf);
	
	// �����б���ʾ
	CString   name_ucRTS             = "�ն���������ʱʱ��RTS";             // �ն���������ʱʱ��RTS
	CString   name_ucRTM             = "�ն���Ϊ����վ�����ʹ�����ʱʱ��";           
	CString   name_ucReSendTimes     = "�ط�����";     // �ط����� (0~3)   0 ��ʾ�������ط�
	CString   name_ucHeartBeat       = "��������";       // 
	CString   name_usTmWaitTimeoutS  = "�������ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ��";  //  ���� 0~4095
	CString   name_bAutoReportAsk_1  = "�����Զ��ϱ�1�����ݣ�ͬʱ��Ҫ��վȷ��";  // 
	CString   name_bAutoReportAsk_2  = "�����Զ��ϱ�2�����ݣ�ͬʱ��Ҫ��վȷ��";  // 
	CString   name_bAutoReportAsk_3  = "�����Զ��ϱ�3�����ݣ�ͬʱ��Ҫ��վȷ��";  // 
	
	CString   value_ucRTS;             // �ն���������ʱʱ��RTS
	CString   value_ucRTM;             // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
	CString   value_ucReSendTimes;     // �ط����� (0~3)   0 ��ʾ�������ط�
	CString   value_ucHeartBeat;       // ��������
	CString   value_usTmWaitTimeoutS;  // �������ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ�� ���� 0~4095
	CString   value_bAutoReportAsk_1;  // �����Զ��ϱ�1�����ݣ�ͬʱ��Ҫ��վȷ��
	CString   value_bAutoReportAsk_2;  // �����Զ��ϱ�2�����ݣ�ͬʱ��Ҫ��վȷ��
    CString   value_bAutoReportAsk_3;  // �����Զ��ϱ�3�����ݣ�ͬʱ��Ҫ��վȷ��
	
	value_ucRTS.Format("%d",sCnf.ucRTS);
	value_ucRTM.Format("%d",sCnf.ucRTM);
	value_ucReSendTimes.Format("%d",sCnf.ucReSendTimes);
	value_ucHeartBeat.Format("%d",  sCnf.ucHeartBeat);
	value_usTmWaitTimeoutS.Format("%d",sCnf.usTmWaitTimeoutS);
	value_bAutoReportAsk_1.Format("%s",sCnf.bAutoReportAsk_1 == TRUE ? "����":"��ֹ");
	value_bAutoReportAsk_2.Format("%s",sCnf.bAutoReportAsk_2 == TRUE ? "����":"��ֹ");
	value_bAutoReportAsk_3.Format("%s",sCnf.bAutoReportAsk_3 == TRUE ? "����":"��ֹ");
		
	CString   format_ucRTS            = FMT_MS_20;             // �ն���������ʱʱ��RTS
	CString   format_ucRTM            = FMT_MINUTE;             // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
	CString   format_ucReSendTimes    = FMT_TIMES;     // �ط����� (0~3)   0 ��ʾ�������ط�
	CString   format_ucHeartBeat      = FMT_MINUTE;       // ��������
	CString   format_usTmWaitTimeoutS = FMT_SECOND;  // �������ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ�� ���� 0~4095
	CString   format_bAutoReportAsk_1 = FMT_BOOL;  // �����Զ��ϱ�1�����ݣ�ͬʱ��Ҫ��վȷ��
	CString   format_bAutoReportAsk_2 = FMT_BOOL;  // �����Զ��ϱ�2�����ݣ�ͬʱ��Ҫ��վȷ��
    CString   format_bAutoReportAsk_3 = FMT_BOOL;  // �����Զ��ϱ�3�����ݣ�ͬʱ��Ҫ��վȷ��
	
		
	CString   limit_ucRTS;             // �ն���������ʱʱ��RTS
	CString   limit_ucRTM;             // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
	CString   limit_ucReSendTimes = "0 ~ 3";     // �ط����� (0~3)   0 ��ʾ�������ط�
	CString   limit_ucHeartBeat;       // ��������
	CString   limit_usTmWaitTimeoutS = "0 ~ 4095";  // �������ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ�� ���� 0~4095
	CString   limit_bAutoReportAsk_1;  // �����Զ��ϱ�1�����ݣ�ͬʱ��Ҫ��վȷ��
	CString   limit_bAutoReportAsk_2;  // �����Զ��ϱ�2�����ݣ�ͬʱ��Ҫ��վȷ��
    CString   limit_bAutoReportAsk_3;  // �����Զ��ϱ�3�����ݣ�ͬʱ��Ҫ��վȷ��
	
	
	m_list.DeleteAllItems();
	
	m_list.AddItem(name_ucRTS,value_ucRTS,format_ucRTS,limit_ucRTS);
	m_list.AddItem(name_ucRTM,value_ucRTM,format_ucRTM,limit_ucRTM);
	m_list.AddItem(name_ucReSendTimes,value_ucReSendTimes,format_ucReSendTimes,limit_ucReSendTimes);
	m_list.AddItem(name_ucHeartBeat,value_ucHeartBeat,format_ucHeartBeat,limit_ucHeartBeat);
	m_list.AddItem(name_usTmWaitTimeoutS,value_usTmWaitTimeoutS,format_usTmWaitTimeoutS,limit_usTmWaitTimeoutS);
	m_list.AddItem(name_bAutoReportAsk_1,value_bAutoReportAsk_1,format_bAutoReportAsk_1,limit_bAutoReportAsk_1);
	m_list.AddItem(name_bAutoReportAsk_2,value_bAutoReportAsk_2,format_bAutoReportAsk_2,limit_bAutoReportAsk_2);
	m_list.AddItem(name_bAutoReportAsk_3,value_bAutoReportAsk_3,format_bAutoReportAsk_3,limit_bAutoReportAsk_3);
*/

	/* ����Ϊԭ3761ʵ��*/
	sMcAfn04f1 sData;
	m_nxCfg.GetPreAfn04F1(&sData,TRUE);
	
	// �����б���ʾ
	CString   name_ucPermitDelayM             = "��������Ϊ����վ��������ʱʱ��";           
	CString   name_ucReSendTimes             = "�ط����� (0~3)   0 ��ʾ�������ط�";           
	CString   name_ucHeartBeat       = "��������";      
	CString   name_usWaitTimeoutS  = "����Ϊ����վ�ȴ�Ӧ��ĳ�ʱʱ��";  
	CString   name_bPermitRt  = "ʵʱ���� ����ȷ��";  
	CString   name_bPermitTk  = "�������� ����ȷ��";  
	CString   name_bPermitEv  = "�¼����� ����ȷ��"; 
	
    
	CString   value_ucRTM;           
	CString   value_ucReSendTimes;    
	CString   value_ucHeartBeat;     
	CString   value_usTmWaitTimeoutS; 
	CString   value_bPermitRt; 
	CString   value_bPermitTk;  
    CString   value_bPermitEv;  
	
	
	value_ucRTM.Format("%d",sData.ucPermitDelayM);
	value_ucReSendTimes.Format("%d",sData.ucReSendTimes);
	value_ucHeartBeat.Format("%d",  sData.ucHeartBeat);
	value_usTmWaitTimeoutS.Format("%d",sData.usWaitTimeoutS);
	value_bPermitRt.Format("%s",sData.bPermitRt == TRUE ? "����":"��ֹ");
	value_bPermitTk.Format("%s",sData.bPermitTk == TRUE ? "����":"��ֹ");
	value_bPermitEv.Format("%s",sData.bPermitEv == TRUE ? "����":"��ֹ");
	
	
	CString   format_ucRTM            = FMT_MINUTE;         
	CString   format_ucReSendTimes    = FMT_TIMES;   
	CString   format_ucHeartBeat      = FMT_MINUTE;    
	CString   format_usTmWaitTimeoutS = FMT_SECOND;  
	CString   format_bPermitRt = FMT_BOOL; 
	CString   format_bPermitTk = FMT_BOOL; 
    CString   format_bPermitEv = FMT_BOOL; 
	
	
	
	CString   limit_ucRTM;           
	CString   limit_ucReSendTimes = "0 ~ 3";     
	CString   limit_ucHeartBeat;     
	CString   limit_usTmWaitTimeoutS = "0 ~ 4095";  
	CString   limit_bPermitRt; 
	CString   limit_bPermitTk; 
    CString   limit_bPermitEv;  
	
	
	m_list.DeleteAllItems();
	
	
	m_list.AddItem(name_ucPermitDelayM,value_ucRTM,format_ucRTM,limit_ucRTM);
	m_list.AddItem(name_ucReSendTimes,value_ucReSendTimes,format_ucReSendTimes,limit_ucReSendTimes);
	m_list.AddItem(name_ucHeartBeat,value_ucHeartBeat,format_ucHeartBeat,limit_ucHeartBeat);
	m_list.AddItem(name_usWaitTimeoutS,value_usTmWaitTimeoutS,format_usTmWaitTimeoutS,limit_usTmWaitTimeoutS);
	m_list.AddItem(name_bPermitRt,value_bPermitRt,format_bPermitRt,limit_bPermitRt);
	m_list.AddItem(name_bPermitTk,value_bPermitTk,format_bPermitTk,limit_bPermitTk);
	m_list.AddItem(name_bPermitEv,value_bPermitEv,format_bPermitEv,limit_bPermitEv);

}

void CTabDlgPreMaster::ShowMstPreAfn04F34()
{
	CNxConfig cfg;
	sMcAfn04f34 sAfn04f34;		
	cfg.GetPreAfn04F34(&sAfn04f34, TRUE);

	CString strUp, strDn;
	CString name_type = "�ǵ�����";
	CString name_up   = "��������";
	CString name_dn   = "��������";
	
	CString val_type;
	CString formt_value;
	CString info_up,info_dn;

	
	switch (sAfn04f34.eType)
	{
	case MC_NELC_TEMP:
		val_type = "�¶�";
		break;
		
	case MC_NELC_FLOW:
		val_type = "����";
		break;

	case MC_NELC_FV:
		val_type = "����";
		break;
		
	case MC_NELC_PRESS:
		val_type = "ѹ��";
		break;
		
	case MC_NELC_HUMI:
		val_type = "ʪ��";
		break;
		
	case MC_NELC_LIGHT:
		val_type = "�ն�";
		break;
		
	case MC_NELC_RV:
		val_type = "ת��";
		break;
		
	case MC_NELC_420MA:
		val_type = "4~20MA";
		break;
		
	default:
		val_type = "δ֪����";
		break;
	}

	
	switch(sAfn04f34.sUp.ePrec)
	{
	case MC_PREC_P4:
		info_up = "0, (+/-)10000~99999990000\n";
		break;
		
	case MC_PREC_P3:
		info_up = "0, (+/-)1000~9999999000\n";
		break;
		
	case MC_PREC_P2:
		info_up = "0, (+/-)100~999999900\n";
		break;
		
	case MC_PREC_P1:
		info_up = "0, (+/-)10~99999990\n";
		break;
		
	case MC_PREC_P0:
		info_up = "0, (+/-)1~9999999\n";
		break;
		
	case MC_PREC_N1:
		info_up = "0, (+/-)0.1~999999.9\n";
		
		break;				
		
	case MC_PREC_N2:
		info_up = "0, (+/-)0.01~99999.99\n";
		break;
		
	case MC_PREC_N3:
		info_up = "0, (+/-)0.001~9999.999\n";
		break;	
		
	default:
		info_up = "δ֪\n";
		break;
	}


	switch (sAfn04f34.sUp.ePrec)
	{
	case  MC_PREC_P4:
	case MC_PREC_P3:
	case MC_PREC_P2:
	case MC_PREC_P1:
	case MC_PREC_P0:
		strUp.Format("%0.0f", sAfn04f34.sUp.dValue);
		strDn.Format("%0.0f", sAfn04f34.sDown.dValue);
		formt_value = "����";
		break;
		
	case MC_PREC_N1:
		strUp.Format("%0.1f", sAfn04f34.sUp.dValue);
		strDn.Format("%0.1f", sAfn04f34.sDown.dValue);
		formt_value = "������";
		break;
		
		
	case MC_PREC_N2:
		strUp.Format("%0.2f", sAfn04f34.sUp.dValue);
		strDn.Format("%0.2f", sAfn04f34.sDown.dValue);
		formt_value = "������";
		break;
		
		
	case MC_PREC_N3:
		strUp.Format("%0.3f", sAfn04f34.sUp.dValue);
		strDn.Format("%0.3f", sAfn04f34.sDown.dValue);
		formt_value = "������";
		break;
		
	default:
		break;
	}

	
	m_list.DeleteAllItems();
	m_list.AddItem(name_type,val_type,"�Զ���","");
	m_list.AddItem(name_up,strUp,formt_value,info_up);
	m_list.AddItem(name_dn,strDn,formt_value,info_up);
	
}

// ��ʾ �ǵ�������������Ԥ����Ϣ
void CTabDlgPreMaster::ShowMstPreAfn04F33()
{
#if 0
	CNxConfig cfg;
	
	UINT16 usPn = 0;
	sMtCfgNotElec sCfgNotElec;
	CString strPn, strMax, strMin, strType;
	
	cfg.GetPreAfn04F33(&usPn,&sCfgNotElec, MT_ROLE_MASTER);
	
	
	


	// �����б���ʾ
	CString   name_pn      = "�������";            
	CString   name_type    = "�ǵ���������";           
	CString   name_max     = "��������";     
	CString   name_min     = "��������";      

	
	strMax.Format("%0.3lf",sCfgNotElec.dMax);
	strMin.Format("%0.3lf",sCfgNotElec.dMin);
	switch (sCfgNotElec.eType)
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
		
	strPn.Format("%d", usPn);

	
	CString   format_pn     = FMT_PN;            
	CString   format_type   = "";           
	CString   format_max    = "";    
	CString   format_min    = "";      
	
	CString   limit_pn     = "0 ~ 65535";             
	CString   limit_type   = "1 - 7";            
	CString   limit_max = "9999.999";    
	CString   limit_min = "-9999.999"; ;       
	
	m_edit_pn.SetWindowText(strPn);
	m_edit_pn.EnableWindow(TRUE);

	m_list.DeleteAllItems();
	m_list.AddItem(name_pn,strPn,format_pn,limit_pn);
	m_list.AddItem(name_type,strType,format_type,limit_type);
	m_list.AddItem(name_max,strMax,format_max,limit_max);
	m_list.AddItem(name_min,strMin,format_min,limit_min);

#endif
}


void CTabDlgPreMaster::setItemColors()
{
	int i, nItemCount = 0;
	nItemCount = m_list.GetItemCount();
	for (i = 0; i < nItemCount; i++)
	{
		m_list.SetItemColor(i,0,RGB(0,64,128),RGB(255,255,255));
		m_list.SetItemColor(i,1,RGB(255,0,255),RGB(255,255,255));
		m_list.SetItemColor(i,2,RGB(128,64,0),RGB(255,255,255));
		m_list.SetItemColor(i,3,RGB(255,0,0),RGB(255,255,255));
	}
}



void CTabDlgPreMaster::OnSelchangedTreePreMst(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	HTREEITEM hParent, hChild;
	CString strChildText, strParentText,str;
	eMcErr eRet = MC_OK;
	hChild = pNMTreeView->itemNew.hItem;
	strChildText = m_tree.GetItemText(hChild);
	hParent      = m_tree.GetParentItem(hChild);

	m_eCmd = CMD_AFN_F_UNKOWN;
	m_mcmd = MCMD_AFN_F_UNKOWN;
	// �����ʾ�б�
	m_list.DeleteAllItems();

    GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(FALSE);
    GetDlgItem(IDC_EDIT_PN)->EnableWindow(FALSE);

	if (hParent == NULL)
	{
			//AfxMessageBox("root");
			return;
	}

	strParentText = m_tree.GetItemText(hParent);

	UINT16 usCmd = 0;
	UINT8 ucAfn = 0;
	UINT8 ucFn  = 0;

	// �������������ݲ���
	if(strParentText == STR_AFN_00_CONF)
	{
		if(strChildText == STR_AFN_00_F1)
		{
			GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
			m_mcmd = MCMD_AFN_0_F1_ALL_OK_DENY;
			showMstPreAfn00F1();	
		}
	}

	if(strParentText == STR_AFN_01_RSET)
	{
		if(strChildText != STR_AFN_01_F5)
		{
			showMstNullData();	
		}
	}

	if(strParentText == STR_AFN_02_LINK)
	{
		showMstNullData();	
	}




	// ���ò���
	if(strParentText == STR_AFN_04_SETP)
	{
		if(strChildText == STR_AFN_04_F1)
		{
			GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
			m_mcmd = MCMD_AFN_4_F1_CON_UP_CFG;
			ShowMstPreAfn04F1();	
		}
		
#if 0
		if (strChildText == STR_AFN_04_F33)
		{
			GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
		//	m_eCmd = CMD_AFN_4_FN_33_CFG_NOT_ELEC;
			ShowMstPreAfn04F33();
		}

#endif
		if (strChildText == STR_AFN_04_F34)
		{
		
			ShowMstPreAfn04F34();
		}

		if (strChildText == STR_AFN_04_F35)
		{
			
			ShowMstPreAfn04F35();
		}

		if (strChildText == STR_AFN_04_F3)
		{
			ShowMstPreAfn04F3();
		}


		if (strChildText == STR_AFN_04_F4)
		{
			ShowMstPreAfn04F4();
		}

		
		if (strChildText == STR_AFN_04_F7)
		{
			ShowMstPreAfn04F7();
		}
	}
	
	// ����һ������
	if(strParentText == STR_AFN_0C_ASKT)
	{
// 		if(strChildText == STR_AFN_0C_F90)
// 		{
// 			GetDlgItem(IDC_BTN_MODIFY)->EnableWindow(TRUE);
// 			//m_eCmd = CMD_AFN_C_FN_90_NOT_ELEC;
// 			//showMstPreAfn0cF90_NotElec();	
// 		}
	
	}


	// �ϳ�����
	if(strParentText == STR_AFN_00_CONF)
	{
		ucAfn = 0;
	}
	else if(strParentText == STR_AFN_01_RSET)
	{
		ucAfn = 1;
	}
	else if(strParentText == STR_AFN_02_LINK)
	{
		ucAfn = 2;
	}
// 	else if(strParentText == STR_AFN_03_RELY)
// 	{
// 		ucAfn = 3;
// 	}
	else if(strParentText == STR_AFN_04_SETP)
	{
		ucAfn = 4;
	}	
	else if(strParentText == STR_AFN_05_CTRL)
	{
		ucAfn = 5;
	}
	else if(strParentText == STR_AFN_06_AUTH)
	{
		ucAfn = 6;
	}
	else if(strParentText == STR_AFN_08_CASC)
	{
		ucAfn = 8;
	}
// 	else if(strParentText == STR_AFN_09_CFIG)
// 	{
// 		ucAfn = 9;
// 	}
	else if(strParentText == STR_AFN_0A_GETP)
	{
		ucAfn = 0x0A;
	}	
// 	else if(strParentText == STR_AFN_0B_ASKT)
// 	{
// 		ucAfn = 0x0B;
// 	}
	else if(strParentText == STR_AFN_0C_ASKT)
	{
		ucAfn = 0x0C;
	}
	else if(strParentText == STR_AFN_0D_ASKR)
	{
		ucAfn = 0x0D;
	}
	else if(strParentText == STR_AFN_0E_ASKE)
	{
		ucAfn = 0x0E;
	}	
	else if(strParentText == STR_AFN_0F_FILE)
	{
		ucAfn = 0xF;
	}
	else if(strParentText == STR_AFN_10_DATA)
	{
		ucAfn = 0x10;
	}


	CString strTmp;
	strTmp = strChildText.Left(strChildText.Find(" "));
	strTmp = strTmp.Right(strTmp.GetLength() - 1);
	ucFn = atoi(strTmp);
	
	usCmd = ucFn + (ucAfn << 8);
	//m_eCmd = (eMtCmd)usCmd;
	m_mcmd = (eMcmd)usCmd;
	// ��ʾPn
	//��ø����������
		
	//sMtCmdInfor sCmdInfor;
	//	eRet = eMtGetCmdInfor(m_eCmd, MT_DIR_M2S, &sCmdInfor);

	
	sMcmdInfor sCmdInfor;
	eRet = eMcGetCmdInfor(m_mcmd, MC_DIR_M2S, &sCmdInfor);
	if(MC_OK != eRet)
	{
		return;
	}
		
	if (sCmdInfor.pFunc == NULL)
	{
		m_btn_modify.EnableWindow(FALSE);
		showMstNullData();
	}
	else
	{
		m_btn_modify.EnableWindow(TRUE);
	}
		

	// pn = p0
	if(sCmdInfor.ePn == MC_PN_P0)
	{
		m_edit_pn.EnableWindow(FALSE);
		m_edit_pn.SetWindowText("0:������");
	}
	else
	{
		m_edit_pn.EnableWindow(TRUE);
		CString strPn;
		// ��ע����и������Ӧ��Ԥ���õ�pnֵ������
		m_nxCfg.GetPrePnStr31(m_mcmd, MC_ROLE_MASTER, &strPn);
		m_edit_pn.SetWindowText(strPn);
	}

	setItemColors();
	*pResult = 0;
}

void CTabDlgPreMaster::OnBtnModify() 
{
	// TODO: Add your control notification handler code here
	switch (m_mcmd)
	{


	case MCMD_AFN_0_F1_ALL_OK_DENY:
		{
			CDlgPreA00F1 dlg;
			if (dlg.DoModal() == IDOK)
			{
		    	showMstPreAfn00F1();
			}
		}
		break;

	case MCMD_AFN_4_F1_CON_UP_CFG:
		{
			CDlgPreAfn04F1 dlg;
			dlg.setTitle("AFN04_F1 ��Ϣ�����뽻���ն�����ͨ�ſ�ͨ�Ų���");
			dlg.m_bPreMaster = TRUE;
			if(dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F1();
			}

		}
		break;
		
		
	case MCMD_AFN_4_F2_MST_PARA:
		{
			CDlgPreAfn04F2 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F2();
			}
		}
		break;


	case MCMD_AFN_4_F3_CON_AUTH_PARA:
		{
			CDlgPreAfn04F3 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F3();
			}
		}
		break;

	case MCMD_AFN_4_F4_TEAM_ADDR:
		{
			CDlgPreAfn04F4 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F4();
			}
		}
		break;


	case MCMD_AFN_4_F5_CON_IP_PORT:
		{
			CDlgPreAfn04F5 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F4();
			}
		}
		break;

	case MCMD_AFN_4_F6_CON_CASC:
		{
			CDlgPreAfn04F6 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F4();
			}
		}
		break;


	case MCMD_AFN_4_F7_CON_DOWN_CFG:
		{
			CDlgPreAfn04F7 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F7();
			}
		}
		break;

	case MCMD_AFN_4_F9_CON_EVENT_CFG:
		{
			CDlgPreAfn04F9 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F7();
			}
		}
		break;
	case MCMD_AFN_4_F17_TML_UP_CFG:
		{
			CDlgPreAfn04F17 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F7();
			}
		}
		break;
	case MCMD_AFN_4_F10_CON_STATE_INPUT:
		{
			CDlgPreAfn04F10 dlg;
			dlg.m_bPreMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F7();
			}
		}
		break;

	case MCMD_AFN_4_F25_ELEC_MP_CFG:
		{
			CDlgPreAfn04F25_33 dlg;
			dlg.m_bF25Elec = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}
		
		break;
		
	case MCMD_AFN_4_F26_ELEC_MP_BASE:
		{
			CDlgPreAfn04F26 dlg;
			dlg.m_bMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}
		break;
		
	case MCMD_AFN_4_F27_ELEC_LMIT_POWER:
		{
			CDlgPreAfn04F27 dlg;
			dlg.m_bMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}	
		break;

	case MCMD_AFN_4_F28_ELEC_LMIT_FACTR:
		{
			CDlgPreAfn04F28 dlg;
			dlg.m_bMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}	
		break;

	case MCMD_AFN_4_F30_ELEC_FLASH:
		{
			CDlgPreAfn04F30 dlg;
			dlg.m_bMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}	
		break;

	case MCMD_AFN_4_F29_ELEC_FIX_HARM:
		{
			CDlgPreAfn04F29 dlg;
			dlg.m_bMaster = TRUE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}	
		break;

	case MCMD_AFN_4_F33_NELC_MP_CFG:
		{
			CDlgPreAfn04F25_33 dlg;
			dlg.m_bF25Elec = FALSE;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F34();
			}
		}
		
		break;


	case MCMD_AFN_4_F34_NELC_MP_PARA:
		{
			CDlgPreAfn04F34 dlg;
			if (dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F34();
			}
		}

		break;
	
	case MCMD_AFN_4_F35_NELC_MP_LMIT:
		{
			CDlgPreAfn04F35 dlg;
			if (dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F35();
			}
		}

	break;

	case MCMD_AFN_4_F49_FREZ_TASK_PARA:
		{
			CDlgPreAfn04F49 dlg;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F35();
			}
		}
		
	break;

	case MCMD_AFN_A_F2_MST_PARA:
		{
			CDlgPreAfn0aF2 dlg;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F35();
			}
		}
		
	break;

	case MCMD_AFN_A_F7_CON_DOWN_CFG:
		{
			CDlgPreAfn0AF7Q dlg;
			if (dlg.DoModal() == IDOK)
			{
				//ShowMstPreAfn04F35();
			}
		}
		
	break;

/*
	case CMD_AFN_4_F1_TML_UP_CFG:
		{
			CDlgPreAfn04F1 dlg;
			dlg.setTitle("��վԤ���� (AFN_04 F1) ����������ͨ�ſ�ͨ�Ų�������");
			dlg.m_bPreMaster = TRUE;
			if(dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F1();
			}
		}
	  break;

	case CMD_AFN_4_FN_33_CFG_NOT_ELEC:
		{
			
			CDlgPreAfn04F33 dlg;
	
			if(dlg.DoModal() == IDOK)
			{
				ShowMstPreAfn04F33();
			}
		}
	  break;
		
	case CMD_AFN_C_FN_90_NOT_ELEC:
		{
			CDlgPreAfn0cF90_NotElec dlg;
			dlg.setRole(TRUE);
			if(dlg.DoModal() == IDOK)
			{
				showMstPreAfn0cF90_NotElec();
			}
		
		}
		break;

		*/
	default:
		break;
	}

	
	setItemColors();
}

void CTabDlgPreMaster::showMstPreAfn0cF90_NotElec()
{
	/*
	CNxConfig cfg;
	
	UINT16 usPn = 0;
	sMtNotElec sNotElec;
	CString strPn, strValue, strMin, strType;
	
	cfg.GetPreAfn0CF90_NotElec(&usPn,&sNotElec, MT_ROLE_MASTER);
	
	
	
	
	
	// �����б���ʾ
	CString   name_pn      = "�������";            
	CString   name_type    = "�ǵ���������";           
	CString   name_max     = "��������";     
	CString   name_min     = "��������";      
	
	
	strValue.Format("%0.3lf",sNotElec.dValue);
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
	
	strPn.Format("%d", usPn);
	
	
	CString   format_pn     = FMT_PN;            
	CString   format_type   = "";           
	CString   format_max    = "";    
	CString   format_min    = "";      
	
	CString   limit_pn     = "0 ~ 65535";             
	CString   limit_type   = "1 - 7";            
	CString   limit_max = "9999.999";    
	CString   limit_min = "-9999.999"; ;       
	
	m_edit_pn.SetWindowText(strPn);
	m_edit_pn.EnableWindow(TRUE);
	
	m_list.DeleteAllItems();
	m_list.AddItem(name_pn,strPn,format_pn,limit_pn);
	m_list.AddItem(name_type,strType,format_type,limit_type);
//	m_list.AddItem(name_max,strValue,format_max,limit_max);
	//m_list.AddItem(name_min,strMin,format_min,limit_min);
	
	  */
}



void CTabDlgPreMaster::OnChangeEditPn() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString strPn;
	m_edit_pn.GetWindowText(strPn);
    m_nxCfg.SetPrePnStr31(m_mcmd, MC_ROLE_MASTER, strPn, TRUE);
}

void CTabDlgPreMaster::showMstPreAfn00F1()
{
	
	// ȡ��Ԥ������
	eMcResCode eResCode;
	m_nxCfg.GetPreAfn00F1(&eResCode, TRUE);
	
	// �����б���ʾ
	CString   name_rescode  = "ȷ�Ϸ�����Ϣ��";          
	CString   value_rescode;             
	CString   format_rescode = FMT_UINT8;  
	CString   limit_rescode = "0-7,255"; 
	
	value_rescode.Format("%d ",eResCode);

	switch(eResCode)
	{
		
	case MC_RES_OK:
		value_rescode += "ȷ��";
		break;
		
	case MC_RES_NONE:
		value_rescode += "����������ݡ������õĲ�������Ҫִ�еĹ���";
		break;
		
	case MC_RES_NOT_READY:
		value_rescode += "���������δ����������ִ��δ����";
		break;
		
	case MC_RES_REMOVE:
		value_rescode += "����������Ѿ����Ƴ����洰��";
		break;
		
	case MC_RES_DATA_OTRNG:
		value_rescode += "��������ݳ���֧�ֵ���Ϣ�㷶Χ";
		break;
		
	case MC_RES_PARA_OTRNG:
		value_rescode += "���õĲ�������֧�ֵ���Ϣ�㷶Χ";
		break;
		
	case MC_RES_NOT_SAME:
		value_rescode += "���õĽ���˿ںż�������ʵ�ʲ���";
		break;
		
	case MC_RES_NOT_SUPT:
		value_rescode += "ָ���ӿڲ�֧��ת��";
		break;
		
	case MC_RES_DENY:
		value_rescode += "����";
		break;
		
	default:
		value_rescode += "δ֪ȷ��";
		break;
		
	}
	
	m_list.DeleteAllItems();	
	m_list.AddItem(name_rescode,value_rescode,format_rescode,limit_rescode);
}

void CTabDlgPreMaster::showMstNullData()
{
	m_list.DeleteAllItems();

	CString   name    = "��";          
	CString   svalue  = "��";             
	CString   format  = "��";  
	CString   limit   = "��"; 
	m_list.AddItem(name,svalue,format,limit);
}

void CTabDlgPreMaster::ShowMstPreAfn04F35()
{
	CNxConfig cfg;
	sMcAfn04f35 sAfn04f35;		
	cfg.GetPreAfn04F35(&sAfn04f35, TRUE);

	CString strUp, strDn;
	CString name_type = "�ǵ�����";
	CString name_up   = "��������";
	CString name_dn   = "��������";
	
	CString val_type;
	CString formt_value;
	CString info_up,info_dn;

	
	switch (sAfn04f35.eType)
	{
	case MC_NELC_TEMP:
		val_type = "�¶�";
		break;
		
	case MC_NELC_FLOW:
		val_type = "����";
		break;

	case MC_NELC_FV:
		val_type = "����";
		break;
		
	case MC_NELC_PRESS:
		val_type = "ѹ��";
		break;
		
	case MC_NELC_HUMI:
		val_type = "ʪ��";
		break;
		
	case MC_NELC_LIGHT:
		val_type = "�ն�";
		break;
		
	case MC_NELC_RV:
		val_type = "ת��";
		break;
		
	case MC_NELC_420MA:
		val_type = "4~20MA";
		break;
		
	default:
		val_type = "δ֪����";
		break;
	}

	
	switch(sAfn04f35.sUp.ePrec)
	{
	case MC_PREC_P4:
		info_up = "0, (+/-)10000~99999990000\n";
		break;
		
	case MC_PREC_P3:
		info_up = "0, (+/-)1000~9999999000\n";
		break;
		
	case MC_PREC_P2:
		info_up = "0, (+/-)100~999999900\n";
		break;
		
	case MC_PREC_P1:
		info_up = "0, (+/-)10~99999990\n";
		break;
		
	case MC_PREC_P0:
		info_up = "0, (+/-)1~9999999\n";
		break;
		
	case MC_PREC_N1:
		info_up = "0, (+/-)0.1~999999.9\n";
		
		break;				
		
	case MC_PREC_N2:
		info_up = "0, (+/-)0.01~99999.99\n";
		break;
		
	case MC_PREC_N3:
		info_up = "0, (+/-)0.001~9999.999\n";
		break;	
		
	default:
		info_up = "δ֪\n";
		break;
	}


	switch (sAfn04f35.sUp.ePrec)
	{
	case  MC_PREC_P4:
	case MC_PREC_P3:
	case MC_PREC_P2:
	case MC_PREC_P1:
	case MC_PREC_P0:
		strUp.Format("%0.0f", sAfn04f35.sUp.dValue);
		strDn.Format("%0.0f", sAfn04f35.sDown.dValue);
		formt_value = "����";
		break;
		
	case MC_PREC_N1:
		strUp.Format("%0.1f", sAfn04f35.sUp.dValue);
		strDn.Format("%0.1f", sAfn04f35.sDown.dValue);
		formt_value = "������";
		break;
		
		
	case MC_PREC_N2:
		strUp.Format("%0.2f", sAfn04f35.sUp.dValue);
		strDn.Format("%0.2f", sAfn04f35.sDown.dValue);
		formt_value = "������";
		break;
		
		
	case MC_PREC_N3:
		strUp.Format("%0.3f", sAfn04f35.sUp.dValue);
		strDn.Format("%0.3f", sAfn04f35.sDown.dValue);
		formt_value = "������";
		break;
		
	default:
		break;
	}

	
	m_list.DeleteAllItems();
	m_list.AddItem(name_type,val_type,"�Զ���","");
	m_list.AddItem(name_up,strUp,formt_value,info_up);
	m_list.AddItem(name_dn,strDn,formt_value,info_up);
}

void CTabDlgPreMaster::ShowMstPreAfn04F3()
{
	CNxConfig cfg;
	sMcAfn04f3 sAfn04f3;		
	cfg.GetPreAfn04F3(&sAfn04f3, TRUE);

	CString val_type;
	val_type.Format("%d", sAfn04f3.ucTypeID);
	m_list.DeleteAllItems();
	m_list.AddItem("��Ϣ��֤������",val_type,"����","0~255 0����֤��255Ӳ����֤�����������֤");
	val_type.Format("%d", sAfn04f3.usAuthPara);
	m_list.AddItem("��Ϣ��֤��������",val_type,"����","0~65535");
}

void CTabDlgPreMaster::ShowMstPreAfn04F4()
{
	CNxConfig cfg;
	sMcAfn04f4 sAfn04f4;	
	int i = 0;
	cfg.GetPreAfn04F4(&sAfn04f4, TRUE);
	

	m_list.DeleteAllItems();

	CString str_name, str_val, str_format, str_info;
	
	str_format = "����";
	for (i = 0; i < 8; i++)
	{
		str_name.Format("���ַ %d", i+1);
		str_val.Format("%u", sAfn04f4.ulAddr[i]);
		if (sAfn04f4.ulAddr[i] == 0)
		{
			str_info = "�������ַ";
		}
		else
		{
			str_info = "";
		}

	m_list.AddItem(str_name, str_val, str_format, str_info);
		
	}
}

void CTabDlgPreMaster::ShowMstPreAfn04F7()
{
	m_list.DeleteAllItems();

	CNxConfig cfg;
	sMcAfn04f7 sData;	
	int i = 0;
	cfg.GetPreAfn04F7(&sData, TRUE);
	


	CString strName, strVal, strFmt, strInfor;
	CString strIp;
	CString strValue;
	
	CString str_ucPort;
	
	cfg.GetPreAfn04F7(&sData, TRUE);
	

	// ucPort
	strName = "���������ж˿ں�";
	strVal.Format("%d", sData.ucPort);
	strFmt = "";
	strIp = "0 ~ 255";
	m_list.AddItem(strName, strVal, strFmt, strInfor);
	
	// main ip
	strName = "����IP��ַ";
	strFmt = "";
	strInfor = "";
	strVal.Format("%d.%d.%d.%d", 
		sData.sMainIp.ip[0],
		sData.sMainIp.ip[1],
		sData.sMainIp.ip[2],
		sData.sMainIp.ip[3]);
	m_list.AddItem(strName, strVal, strFmt, strInfor);

	// main port
	strName = "���ö˿�";
	strVal.Format("%d", sData.usMainPort);
	strFmt = "";
	strInfor = "0 ~ 65535";
	m_list.AddItem(strName, strVal, strFmt, strInfor);

	// main ip
	strName = "����IP��ַ";
	strFmt = "";
	strInfor = "";
	strVal.Format("%d.%d.%d.%d", 
		sData.sBackIp.ip[0],
		sData.sBackIp.ip[1],
		sData.sBackIp.ip[2],
		sData.sBackIp.ip[3]);
	m_list.AddItem(strName, strVal, strFmt, strInfor);

	// main port
	strName = "���ö˿�";
	strVal.Format("%d", sData.usBackPort);
	strFmt = "";
	strInfor = "0 ~ 65535";
	m_list.AddItem(strName, strVal, strFmt, strInfor);


	
	#define  LEN_BUF 34
	char pStr[LEN_BUF];
	
	// apn
	memset(pStr, 0, LEN_BUF);
	memcpy(pStr, sData.ucAPN, 16);
	strVal.Format("%s", pStr);

	strName = "APN";
	strFmt = "";
	strInfor = "";
	m_list.AddItem(strName, strVal, strFmt, strInfor);

	
	// usr
	memset(pStr, 0, LEN_BUF);
	memcpy(pStr, sData.ucUsr, 32);
	strVal.Format("%s", pStr);
	strName = "�û���";
	strFmt = "";
	strInfor = "";
	m_list.AddItem(strName, strVal, strFmt, strInfor);
	
	// pwd
	memset(pStr, 0, LEN_BUF);
	memcpy(pStr, sData.ucPwd, 32);
	strVal.Format("%s", pStr);	
	strName = "����";
	strFmt = "";
	strInfor = "";
	m_list.AddItem(strName, strVal, strFmt, strInfor);



}