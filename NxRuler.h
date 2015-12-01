// NxRuler.h: interface for the CNxRuler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NXRULER_H__410AFF02_F248_4933_924F_A13E450903C9__INCLUDED_)
#define AFX_NXRULER_H__410AFF02_F248_4933_924F_A13E450903C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if 0
/******************************************************************************

              ��Ȩ���� (C), 2001-2015, �������Ժͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : NxRuler.h
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��2��21��
  ����޸�   :
  ��������   : Q/GDW376.1 Э��apiʵ��ͷ�ļ�
  ����˵��   : (1)master -> mst ��վ   (2)concentrator -> con  ������   (3)terminal -> tml �ն�
               (4)mt ��վ�����������ն�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��5��13��
    ��    ��   : liming
    �޸�����   : �����ļ�

******************************************************************************/
//#include "NxRulerTypes.h"
#include <vector>
#include <afxtempl.h>
using namespace std;

typedef eMtErr (*pNxTransFunc)(eMtTransDir eDir, void* pUser, void* pFrame, UINT16 *pusfLen);  // pusFLenΪ��������֡��ĳ���

typedef struct
{
	eMtCmd         eCmd;
	eMtDir         eDir;      // ���ֱ����ܷ��ķ���
	eMtPn 		   ePn;
	pNxTransFunc   pFunc;
	CString        strName;
}sMtCmdInfors;     // �뵥һ��������ص���Ϣ



typedef CMap<eMtCmd,eMtCmd,sMtCmdInfors,sMtCmdInfors> mapCmdInfor;






typedef struct
{
    /* ��ѡ�� */
    sMtuAddress  sAddress;               // ��ַ��Ϣ
    eMtAFN       eMainCmd;               // ��������
    BOOL         bActive;                // ���������ģ���������վ�� ����վ�������վ���������Զ��ϱ���Ϊtrue
    UINT8        ucPFC;                  // ֡������

    // ������
    sMtEC  sEC;                         // �¼�������
    sMtuTp sTP;                         // tp�ֶ�
    UINT8  aucPW[16];                   // pw�ֶ�
	
    /* �䳤�� */
    UINT8    ucSubNum;                  // ��֡�а����������ֵĸ������ֵ(255)
	smtSub   sSub[1];                   // ���������ͼ�Ӧ�ò����� �䳤
	
}smtPackLite;       // �û����װ��ͷ�װ���ݽṹ ���򣬻��Զ��������



typedef struct  
{
	eMtRole      eRole;                    // ���   
	//sMtuAddress  sAdress; 
	UINT8        ucPermitDelayMinutes;     // ����ʱ��
}sMtInit;






class CNxRuler  
{
public:
	eMtErr emt_init(sMtInit *psInit);
	eMtErr emtPack(smtPack *psPack, UINT16 *pusLen, UINT8  *pOutBuf);
	eMtErr emtUnPack(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen);

public:
	void setEC(sMtEC sEC);
	void setPw(CString strPw);
	eMtPRM getPrm(eMtDir eDir, eMtAFN eAfn, BOOL bAuto = FALSE);
	char * getErrMessage(eMtErr err);

	eMtErr emtPackLite(smtPackLite *psPackLite, UINT16 *pusLen, UINT8  *pOutBuf);


	BOOL bmt_need_con(eMtAFN eAFN, eMtDir eDir);
	BOOL bmt_have_tp(eMtAFN eAFN, eMtDir eDir);
	BOOL bmt_have_pw(eMtAFN eAFN, eMtDir eDir);
	BOOL bmt_have_ec(eMtAFN eAFN, eMtDir eDir);
	eMtErr eMtIsValidPack(UINT8  *pOutBuf, UINT16 usLen);
	eMtErr emt_find_frist_valid_pack(UINT8  *pinBuf, UINT16 usLen, UINT16 *pusFirstOff, UINT16 *pusFirstLen);
	eMtErr eMtPackCommon(eMtAFN     eAFN,    sMtPackCommon *psCommon,UINT16 *pusLen, UINT8  *pOutBuf);


	eMtAFN  GetResponeAfn( eMtRole eRole, eMtCmd eCmd);// ��ö�ĳcmd�Ĵ�����
	eMtAFN  GetCmdAfn(eMtCmd eCmd);        // ���ĳ��cmd��������afn
	eMtErr  eMtGetCmdInfor(eMtCmd eCmd, eMtDir eDir, sMtCmdInfors *psInfors);
	eMtRole eMtWhoAmI();
	BOOL bMtIsBigEndian();
	CString BufferToHex(char* pBuf, UINT16 usLen);
	BOOL    CStringToHexBuffer(CString strText, char *pOutBuf, UINT16 *pLen);
	CString GetAfnName(eMtAFN eAfn);
	void add(UINT8 ucFn);


	CNxRuler();
	CNxRuler(eMtRole eRole);
	virtual ~CNxRuler();



private:
	void initMapCmdInfor();
	void SetAtMap(eMtCmd eCmd, eMtDir eDir, eMtPn ePn, pNxTransFunc pFunc, CString strName);
	void AddInforVector(eMtCmd eCmd, eMtDir eDir, eMtPn ePn, pNxTransFunc pFunc, CString strName);

	UINT32 ulmt_read_uint32_small_endian(UINT8 *pRead);
	UINT16 usmt_read_uint16_small_endian(UINT8 *pRead);	
	eMtErr emt_write_uint32_small_endian(UINT32 ulData,   UINT8* pWrite);
	eMtErr emt_write_uint16_small_endian(UINT16 usData, UINT8* pWrite);
	UINT16 usmt_get_ec_pw_tp_len(eMtAFN eAFN, eMtDir eDir);
	UINT8 ucmt_get_bcd(UINT32 ulData, UINT8 ucPos);
	eMtErr eMtGetCtrl(eMtAFN eAFN, eMtDir eDir, eMtPRM ePRM, sMtuCtrl *psuCtrl);

	eMtErr emt_bcd_to_str(const char* pbcd, char *pstr, int len);
	eMtErr eMtTransDaDt_to_PnFn(sMtDaDt *psDaDt, sMtPnFn *psPnFn);
	eMtErr emt_str_to_bcd(const char *pstr, char *pbcd, int len);
	UINT8 ucmt_get_check_sum(UINT8 *pStartPos, UINT16 usLen);
	eMtErr emt_trans_SEQ(eMtTransDir eDir, sMtuSEQ *puSEQ, sMtfSEQ *pfSEQ);
	eMtErr emt_trans_addr(eMtTransDir eDir, sMtuAddress *puAddr, sMtfAddress *pfAddr);
	eMtErr emt_trans_ctrl(eMtTransDir eDir, sMtuCtrl *puCtrl, UINT8* pfCtrl);
	eMtErr emt_get_mtutp(UINT8 ucPFC, sMtuTp *psuTp);
	eMtErr emt_trans_tp(eMtTransDir eDir, sMtuTp* puTp, sMtfTp* pfTp);
	eMtErr eMtTransPnFn_to_DaDt(sMtPnFn *psPnFn, sMtDaDt *psDaDt);
	void vMtfree(UINT8 *pBuf);
	
	eMtRole      m_role;                    // ���   
	sMtuAddress  m_address; 
	mapCmdInfor  m_mapCmdInfor;             // cmd���൱��Ϣ��Ӧmap
	BOOL         m_bInit;                   // �Ƿ��Ѿ���ʼ��
	UINT8        m_ucPermitDelayMinutes;    // ����ʱ��
	UINT8        m_ucPFC;                   // ֡����
	sMtEC        m_EC;                      // �¼�������
	UINT8        m_aucPw[MT_PW_LEN];        // ����

	vector<UINT8>  m_fnList;
	eMtAFN       m_eAfn;
	
	vector<sMtCmdInfors> m_vCmdInfor;

};

#endif
#endif // !defined(AFX_NXRULER_H__410AFF02_F248_4933_924F_A13E450903C9__INCLUDED_)
