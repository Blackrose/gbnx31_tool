// FontColorTree.cpp : implementation file
//

#include "stdafx.h"
#include "FontColorTree.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontColorTree





CFontColorTree::CFontColorTree()
{

}

CFontColorTree::~CFontColorTree()
{
	if (!m_map_colorfont.IsEmpty())
	{
		m_map_colorfont.RemoveAll();
	}
	if (m_memDC.m_hDC)
	{
		m_memDC.DeleteDC();
	}
    if (m_memBitmap.m_hObject)
    {
		m_memBitmap.DeleteObject();
    }
	if (m_Rgn.m_hObject)
	{
		m_Rgn.DeleteObject();
	}
}


BEGIN_MESSAGE_MAP(CFontColorTree, CTreeCtrl)
	//{{AFX_MSG_MAP(CFontColorTree)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontColorTree message handlers

//��ýڵ��ı�Bold
BOOL CFontColorTree::GetItemBold(HTREEITEM hItem)
{
	return GetItemState(hItem,TVIS_BOLD)&TVIS_BOLD;
}

//���ýڵ�BOLD
void CFontColorTree::SetItemBold(HTREEITEM hItem, BOOL bBold)
{
	SetItemState(hItem,bBold?TVIS_BOLD:0,TVIS_BOLD);
}

//���ýڵ��ı���ɫ
void CFontColorTree::SetItemColor(HTREEITEM hItem, COLORREF color)
{

	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		cf.logfont.lfFaceName[0]='\0';
	}
	cf.color=color;
	m_map_colorfont[hItem]=cf;
}

//����ı���ɫ
COLORREF CFontColorTree::GetItemColor(HTREEITEM hItem)
{
	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		return (COLORREF)-1;
	}
	return cf.color;

}

//������Ŀ����
void CFontColorTree::SetItemFont(HTREEITEM hItem, LOGFONT logfont)
{

	color_font cf;
	if (!m_map_colorfont.Lookup(hItem,cf))
	{
		cf.color=(COLORREF)-1;
	}
	cf.logfont=logfont;
	m_map_colorfont[hItem]=cf;
}


//��ýڵ�����
BOOL CFontColorTree::GetItemFont(HTREEITEM hItem, LOGFONT *plogfont)
{
	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		return FALSE;
	}
	if (cf.logfont.lfFaceName[0]=='\0')
	{
		return FALSE;
	}
	*plogfont=cf.logfont;
	return true;
}

//�����Զ�����ʽ
void CFontColorTree::SetItemLabel(HTREEITEM hItem, int nlabel)
{
	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		cf.logfont.lfFaceName[0]='\0';
	}
	cf.label=nlabel;
	
	m_map_colorfont[hItem]=cf;
	
	Invalidate(TRUE); 
	
}

//��ýڵ��Զ�����ʽ����
int CFontColorTree::GetItemLabel(HTREEITEM hItem)
{
	color_font cf;

	if (m_map_colorfont.Lookup(hItem,cf))
	{
		cf.logfont.lfFaceName[0]='\0';
	}
	return cf.label;
}

//���ýڵ������»���
void CFontColorTree::SetItemUnderline(HTREEITEM hItem, BOOL bUnderline)
{
	
	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		cf.logfont.lfFaceName[0]='\0';
		
		if (bUnderline)
		{ 
			cf.logfont.lfUnderline=TRUE;
		}
		else
		{
			cf.logfont.lfUnderline=FALSE;
		}
		
	}
	m_map_colorfont[hItem]=cf;

	//Invalidate(TRUE); 
}

//��ýڵ������»���
BOOL CFontColorTree::GetItemUnderline(HTREEITEM hItem)
{
	color_font cf;
	if (m_map_colorfont.Lookup(hItem,cf))
	{
		cf.logfont.lfFaceName[0]='\0';
	}
	
	if (cf.logfont.lfUnderline==TRUE)
	{ 
		return TRUE;
		
	}
	else
	{
		return FALSE;
	}
	
}

//���ýڵ�Ӽ�����
void CFontColorTree::SetItemTextAdd(HTREEITEM hitem, CString strAdd, BOOL bAdd)
{
	
	CString stritem;
	if (bAdd)
	{
		stritem=GetItemText(hitem);
		stritem=stritem+strAdd;
		
	}
	else
	{
		CString str;
		int m_nadd,m_nold,m_nnew;
		m_nadd=strAdd.GetLength();
		stritem=GetItemText(hitem);
		str=stritem.Right(m_nadd);
		if (str!=strAdd)
			return;
		m_nnew=stritem.GetLength();
		m_nold=m_nnew-m_nadd;
		stritem=stritem.Left(m_nold);
	}
	SetItemText(hitem,stritem);
	//Invalidate(TRUE); 
}

void CFontColorTree::OnPaint() 
{
	//Invalidate(FALSE); 
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	if (NULL == m_memDC.m_hDC)
	{
		m_memDC.CreateCompatibleDC(&dc);
	}
	//�ӵ�ǰDC�����ڴ����
	CRect rcClip,rcClient;
	//����CRect��������ȷ������
	dc.GetClipBox(&rcClip);
	GetClientRect(&rcClient);
	
	if (NULL == m_memBitmap.m_hObject)
	{
		m_memBitmap.CreateCompatibleBitmap(&dc,rcClient.Width(),rcClient.Height());
	}	
   
	m_memDC.SelectObject(&m_memBitmap);
	
	if (NULL == m_Rgn.m_hObject)
	{
		m_Rgn.CreateRectRgnIndirect( &rcClip );
	}	
	m_memDC.SelectClipRgn(&m_Rgn);
	m_Rgn.DeleteObject();
 	
// 	
 	CWnd::DefWindowProc( WM_PAINT, (WPARAM)m_memDC.m_hDC, 0 );
	
	HTREEITEM hItem = GetFirstVisibleItem();
	int n = GetVisibleCount()+1;
	while( (hItem!=NULL) && n--)
	{
		
		CRect rect;
		UINT selflag = TVIS_DROPHILITED | TVIS_SELECTED;
		//�������塢��ɫ
		color_font cf;
		//��������
		if ( !(GetItemState( hItem, selflag ) & selflag )
			&& m_map_colorfont.Lookup( hItem, cf ))
		{
			CFont *pFontDC;
			CFont fontDC;
			LOGFONT logfont;
			int m_nlabel;
			
			if( cf.logfont.lfFaceName[0] != '\0' )
			{
				//�û�����������
				logfont = cf.logfont;
			}
			else
			{
				// �û�û�ж��壬ʹ��ϵͳ����
				CFont *pFont = GetFont();
				pFont->GetLogFont( &logfont );
				
			}
			
			
			//�û��Ƿ��趨�ڵ�Ϊ�Ӵ�
			if( GetItemBold( hItem ) )
				logfont.lfWeight = 700;
			
			if (GetItemUnderline(hItem))
			{				
				logfont.lfUnderline=TRUE;
			}
			
			//��������
			fontDC.CreateFontIndirect( &logfont );
			pFontDC = m_memDC.SelectObject( &fontDC );
			
			//����������ɫ
			if( cf.color != (COLORREF)-1 )
				m_memDC.SetTextColor( cf.color );
			
			//��ȡ�ڵ�����
			CString sItem = GetItemText( hItem );
			
			//��ȡ�ڵ�����
			GetItemRect( hItem, &rect, TRUE );
			//���ñ���ɫΪϵͳɫ
			m_memDC.SetBkColor( GetSysColor( COLOR_WINDOW ) );
			//���ڴ��е�ͼƬд������,Ϊ�ýڵ������
			m_nlabel=cf.label;
			m_memDC.TextOut( rect.left+2, rect.top+1, sItem );
			if (m_nlabel==1)
			{
				
				m_memDC.SetTextColor(RGB(255,0,0));
				m_memDC.TextOut(rect.right+2,rect.top+1,"(���ڼ�⡭��)");
			}
            else if (m_nlabel==2)
			{
				m_memDC.SetTextColor(RGB(107,142,35));
				m_memDC.TextOut(rect.right+2,rect.top+1,"(������)");
			}
			
			m_memDC.SelectObject( pFontDC );
			fontDC.DeleteObject();
			
			
		}
		hItem = GetNextVisibleItem( hItem );
	}
	
	
	
	dc.BitBlt( rcClip.left, rcClip.top, rcClip.Width(), rcClip.Height(), &m_memDC,
		rcClip.left, rcClip.top, SRCCOPY );
	
	//m_memBitmap.DeleteObject();

	//////////////////////////////////////////////////////////////////////////
	//2009-11-9-�޸ĵĴ���memdc����û��delet����ڴ治��-�޸��ˣ�������
// 	if (memDC.m_hDC)
// 	{
// 		memDC.DeleteDC();
// 	}
}

//ˢ�����ؼ�
void CFontColorTree::RedrawTree()
{
	Invalidate(FALSE); 	
}



//���ָ���ı�����Ŀ����
HTREEITEM CFontColorTree::GetHitemByText(HTREEITEM hitemstart,CString strtext)
{
	HTREEITEM hchild,hnext;
	hchild=GetChildItem(hitemstart);
	
	while(hchild)
	{
		if (GetItemText(hchild)==strtext)
		{
			return hchild;
		}
		hnext=hchild;
		GetHitemByText(hnext,strtext);
		hchild=GetNextSiblingItem(hchild);
	}	
	return hchild;
}


//�������нڵ㶼ѡ��
void CFontColorTree::SetItemAllCheck(HTREEITEM hitemstart,BOOL bCheck)
{
	
	HTREEITEM hchild,hnext;
	hchild=GetChildItem(hitemstart);
	
	while(hchild)
	{
		if (bCheck)
		{
			SetCheck(hchild,TRUE);
		}
		else
		{
			SetCheck(hchild,FALSE);
		}
		hnext=hchild;
		SetItemAllCheck(hnext,bCheck);
		hchild=GetNextSiblingItem(hchild);
	}
	
}

void CFontColorTree::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//AfxMessageBox("dfdf");
	//����Ϣ����ȡ��
	CTreeCtrl::OnLButtonUp(nFlags, point);
}

void CFontColorTree::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	

	CRect rc;
    TVHITTESTINFO tvInfo;
    tvInfo.pt=point;
	HTREEITEM hitem=HitTest(&tvInfo);
	//GetItemRect(hitem,rc,TRUE);
	GetItemRect(hitem,rc,TRUE);



	CTreeCtrl::OnMouseMove(nFlags, point);
}
