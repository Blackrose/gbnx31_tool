#if !defined(AFX_TABDLGTASK_H__4266EAF1_6485_49DB_B844_9D465BD98F96__INCLUDED_)
#define AFX_TABDLGTASK_H__4266EAF1_6485_49DB_B844_9D465BD98F96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabDlgTask.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabDlgTask dialog

#include "BtnST.h"
#include "ShadeButtonST.h"

class CTabDlgTask : public CDialog
{
// Construction
public:
	void initListCtrl();
	void setCtrlPos();
	void SendOneTimer();  // ������������Ķ�ʱ����Ӧ����
	void SendListTimer(); // ������������Ķ�ʱ����Ӧ����
	void setMainDlg(CNxMasterDlg *pNxMstDlg);
	void setOneText(CString str);
	CTabDlgTask(CWnd* pParent = NULL);   // standard constructor
	BOOL m_bOneRun;
	BOOL m_bListRun;
	int  m_nOneZq;         //�������͵�����
	int  m_nOneMaxTime;    //�������͵�������
	int  m_nOneLeftTime;   // �������͵�ʣ�����

	int  m_nListZq;        //�������͵�����
	int  m_nListMaxTime;   //�������͵�������
	int  m_nListLeftTime;  // �������͵�ʣ�����

private:
	CNxMasterDlg *m_pNxMstDlg;
 
// Dialog Data
	//{{AFX_DATA(CTabDlgTask)
	enum { IDD = IDD_DLG_TASK };
	CShadeButtonST	m_btn_clr;
	CShadeButtonST	m_btn_go_stop_list;
	CShadeButtonST  m_btn_go_stop;
	CEdit	m_edit_one;
	CListCtrl	m_list_task;
	CButton	m_static_one;
	CButton	m_static_list;
	int		m_zqOne;
	int		m_timesOne;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDlgTask)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabDlgTask)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtnGoStop();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnListGoStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnClr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLGTASK_H__4266EAF1_6485_49DB_B844_9D465BD98F96__INCLUDED_)
