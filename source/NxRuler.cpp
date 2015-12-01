// NxRuler.cpp: implementation of the CNxRuler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NxMaster.h"
#include "NxRuler.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#if 0
#define  MT_DBG_ON // ���Կ���
//#undef   MT_DBG_ON


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNxRuler::CNxRuler()
{
	m_role = MT_ROLE_MASTER;
	initMapCmdInfor();
	m_bInit = FALSE;
}

CNxRuler::CNxRuler( eMtRole eRole )
{

	m_bInit = FALSE;
	m_role = eRole;
	initMapCmdInfor();
}

CNxRuler::~CNxRuler()
{

}


/*****************************************************************************
 �� �� ��  : eMtGetCmdInfor
 ��������  : ��ø������ֶ�Ӧ����Ϣ
 �������  : eMtCmd eCmd           
             eMtDir eDir           
             sMtCmdInfor *psInfor  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��21��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::eMtGetCmdInfor(eMtCmd eCmd, eMtDir eDir, sMtCmdInfors *psInfors)
{
	if(psInfors == NULL)
	{
		return MT_NULL;
	}

	sMtCmdInfors sCmdInfors;


/*  map ��ʽ
	BOOL bHave = m_mapCmdInfor.Lookup(eCmd, sCmdInfors);
	if(bHave == TRUE)
	{
		if(sCmdInfors.eDir == eDir || sCmdInfors.eDir == MT_DIR_ALL)
		{
			*psInfors = sCmdInfors;
			return MT_OK;
		}
	}

*/



	/* vector ��ʽ	*/

    int nCount = 0;
	int i = 0;

	nCount = m_vCmdInfor.size();
	for (i = 0; i < nCount; i++)
	{
		sCmdInfors = m_vCmdInfor.at(i);
		if((sCmdInfors.eCmd == eCmd) && (sCmdInfors.eDir == eDir || sCmdInfors.eDir ==  MT_DIR_ALL))
		{
			*psInfors = sCmdInfors;
			return MT_OK;
		}
	}
	
	

	return MT_NONE;
}

eMtRole CNxRuler::eMtWhoAmI()
{
	return m_role;
}





eMtAFN CNxRuler::GetCmdAfn(eMtCmd eCmd)
{	
	UINT16 usCmd = (UINT16)eCmd;
	UINT8  ucAfn = (usCmd & 0xFF00) >> 8;
	eMtAFN eAfn  = (eMtAFN)ucAfn;   
	
	
	switch(eAfn)
	{
		
	case AFN_00_CONF:
	case AFN_01_RSET:
	case AFN_02_LINK:
	case AFN_03_RELY:
	case AFN_04_SETP:
	case AFN_05_CTRL:
	case AFN_06_AUTH:
	case AFN_08_CASC:
	case AFN_09_CFIG:
	case AFN_0A_GETP:
	case AFN_0B_ASKT:
	case AFN_0C_ASK1:
	case AFN_0D_ASK2:
	case AFN_0E_ASK3:
	case AFN_0F_FILE:
	case AFN_10_DATA:
	break;
					
					// û�ж�Ӧ��afn
	default:
		eAfn = AFN_NULL;
		break;
	}

    return eAfn;
}

/*****************************************************************************
 �� �� ��  : GetResponeAfn
 ��������  : ͨ���յ�����ı�ʶ �� �յ�����ݻ��Ӧ�ûظ���afn���ͣ����ظ�����û���ҵ���Ӧ������
		     return AFN_NULL
 �������  : eMtCmd eCmd
			 eMtRole eRole
			                    
 �������  :  
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtAFN CNxRuler::GetResponeAfn(eMtRole eRole, eMtCmd eCmd)
{
	eMtAFN eAfn,eResAfn;
	eAfn = GetCmdAfn(eCmd);

	if(eAfn == AFN_NULL)
	{
		return AFN_NULL;
	}


	if (MT_ROLE_MASTER == eRole)
	{
		switch(eAfn)
		{
		case AFN_00_CONF:
			eResAfn = AFN_NULL;
			break;


		default:
			break;

		}
	}
	else if(MT_ROLE_CONTOR == eRole)
	{
		switch(eAfn)
		{
		case AFN_00_CONF:
			eResAfn = AFN_NULL;
			break;
	//	case :

			//break;
			
			
		default:
			break;
			
		}

	}
	else
	{
		eResAfn = AFN_NULL;
	}

	return eResAfn;
}

void CNxRuler::SetAtMap(eMtCmd eCmd, eMtDir eDir, eMtPn ePn, pNxTransFunc pFunc, CString strName)
{
	sMtCmdInfors sCmdInfor;
	sCmdInfor.eCmd   = eCmd;
	sCmdInfor.eDir    = eDir;
	sCmdInfor.ePn     = ePn;
	sCmdInfor.pFunc   = pFunc;
	sCmdInfor.strName = strName;	
    //m_mapCmdInfor.SetAt(eCmd, sCmdInfor);
	m_vCmdInfor.push_back(sCmdInfor);
}

/*****************************************************************************
 �� �� ��  : initMapCmdInfor
 ��������  : ��ʼ��m_mapCmdInfor ��Ա���ú���Ӧ��Ӧ��Э��ģ��ǰ����
		     ��Ҫ����
 �������  : 			 		                    
 �������  :  
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���
	
*****************************************************************************/
void CNxRuler::initMapCmdInfor()
{

    /* (0)ȷ�ϨM���ϣ�AFN=00H�� */
    // ˫��
    SetAtMap(CMD_AFN_0_FN_1_ALL_OK,     MT_DIR_ALL, MT_PN_0,  NULL,     "ȫ��ȷ�ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��");
    SetAtMap(CMD_AFN_0_FN_2_ALL_DENY,   MT_DIR_ALL, MT_PN_0,  NULL,     "ȫ�����ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ���з���");
    SetAtMap(CMD_AFN_0_FN_3_ONE_BY_ONE, MT_DIR_ALL, MT_PN_0,  emtTrans_OneByOne,     "�����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����");

    /* (1)��λ���AFN=01H�� */
    // ����
    SetAtMap(CMD_AFN_1_FN_1_HARD_INIT,  MT_DIR_M2S, MT_PN_0,  NULL,     "Ӳ����ʼ��");
    SetAtMap(CMD_AFN_1_FN_2_DATA_INIT,  MT_DIR_M2S, MT_PN_0,  NULL,     "��������ʼ��");
    SetAtMap(CMD_AFN_1_FN_3_FACTORY_RESET, MT_DIR_M2S, MT_PN_0,  NULL,  "������ȫ����������ʼ�������ָ����������ã�");
    SetAtMap(CMD_AFN_1_FN_4_PARA_INIT,  MT_DIR_M2S, MT_PN_0,  NULL,     "����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��");

    // ����
    // ȷ�ϨM���ϣ�AFN=00H)

    /* (2) ��·�ӿڼ�⣨AFN=02H�� */
    // ����
    // ȷ�ϨM���ϣ�AFN=00H)
     
    // ����
    SetAtMap(CMD_AFN_2_FN_1_LOG_IN,     MT_DIR_S2M, MT_PN_0,  NULL,     "��¼");
    SetAtMap(CMD_AFN_2_FN_2_LOG_OUT,    MT_DIR_S2M, MT_PN_0,  NULL,     "�˳���¼");
    SetAtMap(CMD_AFN_2_FN_3_HEART_BEAT, MT_DIR_S2M, MT_PN_0,  NULL,     "����");

    /* (4) ���ò�����AFN == 04H�� */
    // ����
	SetAtMap(CMD_AFN_4_FN_1_CON_UP_CFG,    MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F1_ConUpPortPara, "����������ͨ�ſ�ͨ�Ų�������");
	//SetAtMap(CMD_AFN_4_FN_2_CON_UP_WAY_ETH,MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F2_ConUpPortParaWireless, "����������ͨ�Ź�����ʽ����̫ר��������ר����");
	SetAtMap(CMD_AFN_4_FN_2_CON_UP_REWORD,MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F2_ConUpPortParaWireless, "����������ͨ�Ź�����ʽ����̫ר��������ר����");

	SetAtMap(CMD_AFN_4_FN_3_MST_IP_PORT,   MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F3_MasterIpPort,   "��վIP��ַ�Ͷ˿�"); 
	SetAtMap(CMD_AFN_4_FN_4_PHONE_MST_SMS, MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F4_MstSmsPhone, "��վ�绰����Ͷ������ĺ���");  
	SetAtMap(CMD_AFN_4_FN_5_CON_UP_PARA,   MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F5_UpMsgAuth,     "����������ͨ����Ϣ��֤��������");
	SetAtMap(CMD_AFN_4_FN_6_TEAM_ADDR,     MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04f6_ConGroupAddr,   "���������ַ����");
	SetAtMap(CMD_AFN_4_FN_7_CON_IP_PORT,   MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F7_ConIpPort,      "������IP��ַ�Ͷ˿�"); 
	SetAtMap(CMD_AFN_4_FN_8_CON_UP_WAY,    MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F8_ConUpComWay,   "����������ͨ�Ź�����ʽ����̫ר��������ר����"); 
	SetAtMap(CMD_AFN_4_FN_9_CFG_TML_MNT,   MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F9_Con2TmlComPara,"���������ն�ͨ�Ŷ�ȡ�������в�������");
	SetAtMap(CMD_AFN_4_FN_10_CON_DOWN_CFG, MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F10_ConDownPara, "����������ͨ��ģ��Ĳ�������");
	SetAtMap(CMD_AFN_4_FN_11_VPN_PWD,      MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F11_VpnPwd,      "����ר���û���������"); 
	SetAtMap(CMD_AFN_4_FN_12_CON_UP_LIMIT, MT_DIR_M2S, MT_PN_0,   emt_trans_Afn04F12_ConUpLimit,  "����������ͨ��������������"); 
	SetAtMap(CMD_AFN_4_FN_13_CON_CASC_CFG, MT_DIR_M2S, MT_PN_0,    NULL, "����������ͨ�Ų������ݵ�Ԫ��ʽ"); 
    SetAtMap(CMD_AFN_4_FN_17_CFG_EVENT,    MT_DIR_M2S, MT_PN_0,    NULL, "�������¼���¼��������"); 
    SetAtMap(CMD_AFN_4_FN_18_CFG_TM_STATE, MT_DIR_M2S, MT_PN_0,    NULL, "������״̬���������"); 
    SetAtMap(CMD_AFN_4_FN_19_CFG_METERING, MT_DIR_M2S, MT_PN_0,    NULL, "������������û�������"); 
    SetAtMap(CMD_AFN_4_FN_25_POWER_LIMIT,  MT_DIR_M2S, MT_PN_0,    NULL, "��������ֵ����"); 
    SetAtMap(CMD_AFN_4_FN_26_FACTOR_LIMIT, MT_DIR_M2S, MT_PN_0,    NULL, "�����㹦�������ֶ���ֵ"); 
    SetAtMap(CMD_AFN_4_FN_28_CFG_POWER,    MT_DIR_M2S, MT_PN_0,    NULL, "�������������ò���"); 
    SetAtMap(CMD_AFN_4_FN_29_CFG_UN_POWER, MT_DIR_M2S, MT_PN_0,    NULL, "�ǵ����������ò���"); 
    //SetAtMap(CMD_AFN_4_FN_33_TIMING_REPORT_1, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������"); 
    SetAtMap(CMD_AFN_4_FN_33_CFG_NOT_ELEC, MT_DIR_M2S, MT_PN_TP,    emtTrans_CfgNotElecValue, "�ǵ������������ݲ�������"); 
    SetAtMap(CMD_AFN_4_FN_34_TIMING_REPORT_2, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������"); 
    SetAtMap(CMD_AFN_4_FN_35_STOP_TIMING_REPORT_1, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������/ֹͣ����"); 
    SetAtMap(CMD_AFN_4_FN_36_STOP_TIMING_REPORT_2, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������/ֹͣ����"); 
    SetAtMap(CMD_AFN_4_FN_41_CFG_TML_MNT,   MT_DIR_M2S, MT_PN_0,    NULL, "�ն����û�����������"); 
    SetAtMap(CMD_AFN_4_FN_42_CFG_TML_STATE, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�״̬���������"); 
    SetAtMap(CMD_AFN_4_FN_43_CFG_TML_TRANS, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�͸���豸����"); 
    // ����
    // ȷ�ϨM���ϣ�AFN=00H)
  
    /* (5) �������AFN=05H�� */
    // ����
    SetAtMap(CMD_AFN_5_FN_1_REMOTE_SWITCH_OFF, MT_DIR_M2S, MT_PN_TM, emt_trans_Afn05F1_RemoteCtrlTrip, "ң����բ"); 
    SetAtMap(CMD_AFN_5_FN_2_PERMIT_SWITCH_ON,  MT_DIR_M2S, MT_PN_TM, NULL, "�����բ"); 
    SetAtMap(CMD_AFN_5_FN_29_STRT_AUTO_REPORT, MT_DIR_M2S, MT_PN_0,  NULL, "�������������ϱ�"); 
    SetAtMap(CMD_AFN_5_FN_31_TIME_TICK,        MT_DIR_M2S, MT_PN_0,  emt_trans_Afn05F31_TimeTick, "��ʱ����"); 
    SetAtMap(CMD_AFN_5_FN_37_STOP_AUTO_REPORT, MT_DIR_M2S, MT_PN_0,  NULL, "��ֹ�����������ϱ�"); 
    SetAtMap(CMD_AFN_5_FN_38_LINK_MST_TML,     MT_DIR_M2S, MT_PN_0,  NULL, "�������������վ"); 
    SetAtMap(CMD_AFN_5_FN_39_UNLINK_MST_TML,   MT_DIR_M2S, MT_PN_0,  NULL, "��������Ͽ�����"); 
    SetAtMap(CMD_AFN_5_FN_49_PORT_TML_SUSPEND, MT_DIR_M2S, MT_PN_0,  emt_trans_Afn05F49_PortSuspend, "����ָ��ͨ�Ŷ˿���ͣ���ն�ͨ�Ŷ�ȡ����"); 
    SetAtMap(CMD_AFN_5_FN_50_PORT_TML_RESUME,  MT_DIR_M2S, MT_PN_0,  emt_trans_Afn05F50_PortResume, "����ָ��ͨ�Ŷ˿ڻָ����ն�ͨ�Ŷ�ȡ����"); 
    SetAtMap(CMD_AFN_5_FN_51_PORT_TML_AGAIN,   MT_DIR_M2S, MT_PN_0,  emt_trans_Afn05F51_PortAgain, "����ָ��ͨ�Ŷ˿��������ն�ͨ�Ŷ�ȡ����"); 
    SetAtMap(CMD_AFN_5_FN_52_INIT_ROUT_INFO,   MT_DIR_M2S, MT_PN_0,  NULL, "��ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ"); 
    SetAtMap(CMD_AFN_5_FN_53_DEL_ALL_TML,      MT_DIR_M2S, MT_PN_0,  NULL, "ɾ��ָ��ͨ�Ŷ˿��µ�ȫ���ն�"); 

    // ����
    // ȷ�ϨM���ϣ�AFN=00H)
  
    /* (6) �����֤����ԿЭ�̣�AFN=06H�� */
    // ����
    SetAtMap(CMD_AFN_6_FN_1_ID_AUTH_Q,   MT_DIR_ALL, MT_PN_0,  emt_trans_Afn06F1_IdAuthQ, "�����֤����");
    SetAtMap(CMD_AFN_6_FN_2_ID_AUTH_A,   MT_DIR_ALL, MT_PN_0,  emt_trans_Afn06F2_IdAuthA, "�����֤��Ӧ"); 
    SetAtMap(CMD_AFN_6_FN_3_RAND_Q,      MT_DIR_ALL, MT_PN_0,  emt_trans_Afn06F3_RandQ,   "ȡ���������"); 
    SetAtMap(CMD_AFN_6_FN_4_RAND_A,      MT_DIR_ALL, MT_PN_0,  emt_trans_Afn06F4_RandA,   "ȡ�������Ӧ"); 


    /* (9) �����������ü���Ϣ��AFN=09H�� */
    // ����
//     SetAtMap(CMD_AFN_9_FN_1_CON_VERSION,       MT_DIR_M2S, MT_PN_0,  NULL,   "�������汾��Ϣ"); 
//     SetAtMap(CMD_AFN_9_FN_4_SUPPORT_PARA_CFG,  MT_DIR_M2S, MT_PN_0,  NULL,   "������֧�ֵĲ�������"); 
//     SetAtMap(CMD_AFN_9_FN_5_SUPPORT_CTRL_CFG,  MT_DIR_M2S, MT_PN_0,  NULL,   "������֧�ֵĿ�������"); 
//     SetAtMap(CMD_AFN_9_FN_6_SUPPORT_ASK1_CFG,  MT_DIR_M2S, MT_PN_0,  NULL,   "������֧�ֵ�1����������"); 
//     SetAtMap(CMD_AFN_9_FN_7_SUPPORT_ASK2_CFG,  MT_DIR_M2S, MT_PN_0,  NULL,   "������֧�ֵ�2����������"); 
// 	SetAtMap(CMD_AFN_9_FN_8_SUPPORT_EVNT_CFG,  MT_DIR_M2S, MT_PN_0,  NULL,   "������֧�ֵ��¼���¼����"); 

    // ���� 
    SetAtMap(CMD_AFN_9_FN_1_CON_VERSION,       MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F1_ConVersion,   "�������汾��Ϣ"); 
    SetAtMap(CMD_AFN_9_FN_4_SUPPORT_PARA_CFG,  MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F4_ConParaCfg,   "������֧�ֵĲ�������"); 
    SetAtMap(CMD_AFN_9_FN_5_SUPPORT_CTRL_CFG,  MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F5_ConCtrlCfg,   "������֧�ֵĿ�������"); 
    SetAtMap(CMD_AFN_9_FN_6_SUPPORT_ASK1_CFG,  MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F6_ConAsk1Cfg,   "������֧�ֵ�1����������"); 
    SetAtMap(CMD_AFN_9_FN_7_SUPPORT_ASK2_CFG,  MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F7_ConAsk2Cfg,   "������֧�ֵ�2����������"); 
	SetAtMap(CMD_AFN_9_FN_8_SUPPORT_EVNT_CFG,  MT_DIR_ALL, MT_PN_0,  emt_trans_Afn09F8_ConEvntCfg,   "������֧�ֵ��¼���¼����"); 



    /* (10)  ��ѯ������AFN=0AH�� */
    // ����
//     SetAtMap(CMD_AFN_A_FN_1_CON_UP_CFG,       MT_DIR_M2S, MT_PN_0,   NULL, "����������ͨ�ſ�ͨ�Ų�������");
// 	SetAtMap(CMD_AFN_A_FN_2_CON_UP_WAY_ETH,   MT_DIR_M2S, MT_PN_0,   NULL, "����������ͨ�Ź�����ʽ����̫ר��������ר����");
// 	SetAtMap(CMD_AFN_A_FN_3_MST_IP_PORT,      MT_DIR_M2S, MT_PN_0,   NULL,   "��վIP��ַ�Ͷ˿�"); 
// 	SetAtMap(CMD_AFN_A_FN_4_PHONE_MST_SMS,    MT_DIR_M2S, MT_PN_0,   NULL, "��վ�绰����Ͷ������ĺ���");  
// 	SetAtMap(CMD_AFN_A_FN_5_CON_UP_PARA,      MT_DIR_M2S, MT_PN_0,   NULL,     "����������ͨ����Ϣ��֤��������");
// 	SetAtMap(CMD_AFN_A_FN_6_TEAM_ADDR,        MT_DIR_M2S, MT_PN_0,   NULL,   "���������ַ����");
// 	SetAtMap(CMD_AFN_A_FN_7_CON_IP_PORT,      MT_DIR_M2S, MT_PN_0,   NULL,      "������IP��ַ�Ͷ˿�"); 
// 	SetAtMap(CMD_AFN_A_FN_8_CON_UP_WAY,       MT_DIR_M2S, MT_PN_0,   NULL,   "����������ͨ�Ź�����ʽ����̫ר��������ר����"); 
// 	SetAtMap(CMD_AFN_A_FN_9_CFG_TML_MNT,      MT_DIR_M2S, MT_PN_0,   NULL,"���������ն�ͨ�Ŷ�ȡ�������в�������");
// 	SetAtMap(CMD_AFN_A_FN_10_CON_DOWN_CFG,    MT_DIR_M2S, MT_PN_0,   NULL, "����������ͨ��ģ��Ĳ�������");
// 	SetAtMap(CMD_AFN_A_FN_11_VPN_PWD,         MT_DIR_M2S, MT_PN_0,   NULL,      "����ר���û���������"); 
// 	SetAtMap(CMD_AFN_A_FN_12_CON_UP_LIMIT,    MT_DIR_M2S, MT_PN_0,   NULL,  "����������ͨ��������������"); 
// 	SetAtMap(CMD_AFN_A_FN_13_CON_CASC_CFG,    MT_DIR_M2S, MT_PN_0,    NULL, "����������ͨ�Ų������ݵ�Ԫ��ʽ"); 
//     SetAtMap(CMD_AFN_A_FN_17_CFG_EVENT,       MT_DIR_M2S, MT_PN_0,    NULL,    "�������¼���¼��������"); 
//     SetAtMap(CMD_AFN_A_FN_18_CFG_TM_STATE,    MT_DIR_M2S, MT_PN_0,    NULL, "������״̬���������"); 
//     SetAtMap(CMD_AFN_A_FN_19_CFG_METERING,    MT_DIR_M2S, MT_PN_0,    NULL, "������������û�������"); 
//     SetAtMap(CMD_AFN_A_FN_25_POWER_LIMIT,     MT_DIR_M2S, MT_PN_0,    NULL, "��������ֵ����"); 
//     SetAtMap(CMD_AFN_A_FN_26_FACTOR_LIMIT,    MT_DIR_M2S, MT_PN_0,    NULL, "�����㹦�������ֶ���ֵ"); 
//     SetAtMap(CMD_AFN_A_FN_28_CFG_POWER,       MT_DIR_M2S, MT_PN_0,    NULL, "�������������ò���"); 
//     SetAtMap(CMD_AFN_A_FN_29_CFG_UN_POWER,    MT_DIR_M2S, MT_PN_0,    NULL, "�ǵ����������ò���"); 
//     SetAtMap(CMD_AFN_A_FN_33_TIMING_REPORT_1, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������"); 
//     SetAtMap(CMD_AFN_A_FN_34_TIMING_REPORT_2, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������"); 
//     SetAtMap(CMD_AFN_A_FN_35_STOP_TIMING_REPORT_1, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������/ֹͣ����"); 
//     SetAtMap(CMD_AFN_A_FN_36_STOP_TIMING_REPORT_2, MT_DIR_M2S, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������/ֹͣ����"); 
//     SetAtMap(CMD_AFN_A_FN_41_CFG_TML_MNT,   MT_DIR_M2S, MT_PN_0,    NULL, "�ն����û�����������"); 
//     SetAtMap(CMD_AFN_A_FN_42_CFG_TML_STATE, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�״̬���������"); 
//     SetAtMap(CMD_AFN_A_FN_43_CFG_TML_TRANS, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�͸���豸����"); 

    // ���� 
    SetAtMap(CMD_AFN_A_FN_1_CON_UP_CFG,       MT_DIR_S2M, MT_PN_0,   NULL, "����������ͨ�ſ�ͨ�Ų�������");
	SetAtMap(CMD_AFN_A_FN_2_CON_UP_WAY_ETH,   MT_DIR_S2M, MT_PN_0,   NULL, "����������ͨ�Ź�����ʽ����̫ר��������ר����");
	SetAtMap(CMD_AFN_A_FN_3_MST_IP_PORT,      MT_DIR_S2M, MT_PN_0,   NULL,   "��վIP��ַ�Ͷ˿�"); 
	SetAtMap(CMD_AFN_A_FN_4_PHONE_MST_SMS,    MT_DIR_S2M, MT_PN_0,   NULL, "��վ�绰����Ͷ������ĺ���");  
	SetAtMap(CMD_AFN_A_FN_5_CON_UP_PARA,      MT_DIR_S2M, MT_PN_0,   NULL,     "����������ͨ����Ϣ��֤��������");
	SetAtMap(CMD_AFN_A_FN_6_TEAM_ADDR,        MT_DIR_S2M, MT_PN_0,   NULL,   "���������ַ����");
	SetAtMap(CMD_AFN_A_FN_7_CON_IP_PORT,      MT_DIR_S2M, MT_PN_0,   NULL,      "������IP��ַ�Ͷ˿�"); 
	SetAtMap(CMD_AFN_A_FN_8_CON_UP_WAY,       MT_DIR_S2M, MT_PN_0,   NULL,   "����������ͨ�Ź�����ʽ����̫ר��������ר����"); 
	SetAtMap(CMD_AFN_A_FN_9_CFG_TML_MNT,      MT_DIR_S2M, MT_PN_0,   NULL,"���������ն�ͨ�Ŷ�ȡ�������в�������");
	SetAtMap(CMD_AFN_A_FN_10_CON_DOWN_CFG,    MT_DIR_S2M, MT_PN_0,   NULL, "����������ͨ��ģ��Ĳ�������");
	SetAtMap(CMD_AFN_A_FN_11_VPN_PWD,         MT_DIR_S2M, MT_PN_0,   NULL,      "����ר���û���������"); 
	SetAtMap(CMD_AFN_A_FN_12_CON_UP_LIMIT,    MT_DIR_S2M, MT_PN_0,   NULL,  "����������ͨ��������������"); 
	SetAtMap(CMD_AFN_A_FN_13_CON_CASC_CFG,    MT_DIR_S2M, MT_PN_0,    NULL, "����������ͨ�Ų������ݵ�Ԫ��ʽ"); 
    SetAtMap(CMD_AFN_A_FN_17_CFG_EVENT,       MT_DIR_S2M, MT_PN_0,    NULL,    "�������¼���¼��������"); 
    SetAtMap(CMD_AFN_A_FN_18_CFG_TM_STATE,    MT_DIR_S2M, MT_PN_0,    NULL, "������״̬���������"); 
    SetAtMap(CMD_AFN_A_FN_19_CFG_METERING,    MT_DIR_S2M, MT_PN_0,    NULL, "������������û�������"); 
    SetAtMap(CMD_AFN_A_FN_25_POWER_LIMIT,     MT_DIR_S2M, MT_PN_0,    NULL, "��������ֵ����"); 
    SetAtMap(CMD_AFN_A_FN_26_FACTOR_LIMIT,    MT_DIR_S2M, MT_PN_0,    NULL, "�����㹦�������ֶ���ֵ"); 
    SetAtMap(CMD_AFN_A_FN_28_CFG_POWER,       MT_DIR_S2M, MT_PN_0,    NULL, "�������������ò���"); 
    SetAtMap(CMD_AFN_A_FN_29_CFG_UN_POWER,    MT_DIR_S2M, MT_PN_0,    NULL, "�ǵ����������ò���"); 
    SetAtMap(CMD_AFN_A_FN_33_TIMING_REPORT_1, MT_DIR_S2M, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������"); 
    SetAtMap(CMD_AFN_A_FN_34_TIMING_REPORT_2, MT_DIR_S2M, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������"); 
    SetAtMap(CMD_AFN_A_FN_35_STOP_TIMING_REPORT_1, MT_DIR_S2M, MT_PN_0,    NULL, "��ʱ�ϱ�1��������������/ֹͣ����"); 
    SetAtMap(CMD_AFN_A_FN_36_STOP_TIMING_REPORT_2, MT_DIR_S2M, MT_PN_0,    NULL, "��ʱ�ϱ�2��������������/ֹͣ����"); 
    SetAtMap(CMD_AFN_A_FN_41_CFG_TML_MNT,   MT_DIR_S2M, MT_PN_0,    NULL, "�ն����û�����������"); 
    SetAtMap(CMD_AFN_A_FN_42_CFG_TML_STATE, MT_DIR_S2M, MT_PN_0,    NULL, "�ն�״̬���������"); 
    SetAtMap(CMD_AFN_A_FN_43_CFG_TML_TRANS, MT_DIR_S2M, MT_PN_0,    NULL, "�ն�͸���豸����"); 
  
    /* (11) �����������ݣ�AFN=0BH�� */
    // ����
    SetAtMap(CMD_AFN_B_FN_1_TIMING_REPORT_1, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�״̬���������"); 
    SetAtMap(CMD_AFN_B_FN_2_TIMING_REPORT_2, MT_DIR_M2S, MT_PN_0,    NULL, "�ն�͸���豸����"); 

    // ���� 
    // CMD_AFN_B_FN_1_TIMING_REPORT_1 ����1�����ݣ�AFN=0CH�������б���Ӧ��
    // CMD_AFN_B_FN_1_TIMING_REPORT_2 ����2�����ݣ�AFN=0DH�������б���Ӧ��
  
    /* (12) ����1�����ݣ�AFN=0CH�� */


	// ����
	SetAtMap(CMD_AFN_C_FN_90_NOT_ELEC, MT_DIR_M2S, MT_PN_TP,    emtTrans_NotElecValue, "�ǵ�����");
	
	
	// ���� 
	SetAtMap(CMD_AFN_C_FN_90_NOT_ELEC, MT_DIR_S2M, MT_PN_TP,    emtTrans_NotElecValue, "�ǵ�����");

   
    
		


  
    /* (13) ����2�����ݣ�AFN=0DH�� */
    // ����
    

    // ���� 

  
    /* (14) ����3�����ݣ�AFN=0EH�� */
    // ����
    

    // ���� 

    /* (15) �ļ����䣨AFN=0FH�� */
  
    /* (16) ����ת����AFN=10H�� */
    // ����
    

    // ���� 

    SetAtMap(CMD_AFN_FN_MAX, MT_DIR_UNKOWN, MT_PN_0,  NULL,     "���������, û��ʵ������");

}





// ȫ�ֺ���



/*****************************************************************************
 �� �� ��  : eMtTransDaDt_to_PnFn_g
 ��������  : ��������Ϣ��Ԫ��ʶ��DaDt�ṹת��ΪPnFn�ṹ
 �������  : sMtDaDt *psDaDt  
             sMtPnFn *psPnFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr eMtTransDaDt_to_PnFn_g(sMtDaDt *psDaDt, sMtPnFn *psPnFn)
{
	if(!psPnFn || !psDaDt)
	{
		return MT_NULL;
	}

	if(psDaDt->ucDT2 > 30)
	{
		return MT_OUT_RNG;
	}

    UINT8 ucShift = 0;

    if(psDaDt->ucDA1 == 0 && psDaDt->ucDA2 == 0)
    {
        psPnFn->usPn = 0;
    }
    else
    {
        switch(psDaDt->ucDA1)
        {
            case 0x01:
                ucShift = 1;
                break;
                
            case 0x02:
                ucShift = 2; 
                break;
                
            case 0x04:
                ucShift = 3;
                break;
                
            case 0x08:
                ucShift = 4; 
                break;

            case 0x10:
                ucShift = 5;
                break;
                
            case 0x20:
                ucShift = 6; 
                break;
                
            case 0x40:
                ucShift = 7;
                break;
                
            case 0x80:
                ucShift = 8; 
                break;

            default:
                  return MT_ERR_PARA;
                  //break;

        }
        
       psPnFn->usPn = ((psDaDt->ucDA2 - 1) * 8 + ucShift);
    }


    if(psDaDt->ucDT1 == 0 && psDaDt->ucDT2 == 0)
    {
        psPnFn->usFn = 0;
    }
    else
    {
         switch(psDaDt->ucDT1)
        {
            case 0x01:
                ucShift = 1;
                break;
                
            case 0x02:
                ucShift = 2; 
                break;
                
            case 0x04:
                ucShift = 3;
                break;
                
            case 0x08:
                ucShift = 4; 
                break;

            case 0x10:
                ucShift = 5;
                break;
                
            case 0x20:
                ucShift = 6; 
                break;
                
            case 0x40:
                ucShift = 7;
                break;
                
            case 0x80:
                ucShift = 8; 
                break;

            default:
                  return MT_ERR_PARA;
                  //break;

        }

        psPnFn->usFn = (psDaDt->ucDT2 * 8 + ucShift);

    }
    
    #ifdef MT_DBG_ON
    printf("eMtTransDaDt_to_PnFn() in sPnFn.usfn = %d sPnFn.usPn = %d\n", psPnFn->usFn, psPnFn->usPn);
    printf("eMtTransDaDt_to_PnFn() out Da1 = %d Da2 = %d Dt1 = %d Dt2 = %d\n", 
            psDaDt->ucDA1,
            psDaDt->ucDA2,
            psDaDt->ucDT1,
            psDaDt->ucDT2);
    #endif 
	return MT_OK;
}
/*****************************************************************************
 �� �� ��  : eMtTransPnFn_to_DaDt_g
 ��������  : ��������Ϣ��ʶ��PnFn�ṹת��ΪData�ṹ
 �������  : sMtPnFn *psPnFn  
             sMtDaDt *psDaDt  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr eMtTransPnFn_to_DaDt_g(sMtPnFn *psPnFn, sMtDaDt *psDaDt)
{
	if(!psPnFn || !psDaDt)
	{
		return MT_NULL;
	}
	
	if(psPnFn->usPn > MT_DA_PN_MAX || psPnFn->usFn > MT_DT_FN_MAX)
	{
		return MT_OUT_RNG;
	}
	
    UINT8 ucShift = 0; 
    UINT8 ucMask  = 0x01;
    
    if(psPnFn->usPn == 0)
    {
        psDaDt->ucDA1 = 0;
        psDaDt->ucDA2 = 0;
    }
    else
    {
        ucShift = psPnFn->usPn % 8;
        ucShift = ucShift == 0 ? 7 : (ucShift -1);
        psDaDt->ucDA1 = (UINT8)(ucMask << ucShift);
		psDaDt->ucDA2 = (UINT8)((psPnFn->usPn - 1) / 8 + 1);
    }
	
	if(psPnFn->usFn == 0)
	{
        psDaDt->ucDT1 = 0;
        psDaDt->ucDT2 = 0;
    }
    else
    {
        ucShift = psPnFn->usFn % 8;
        ucShift = ucShift == 0 ? 7 : (ucShift -1);
        
        psDaDt->ucDT1 = (UINT8)(ucMask << ucShift);
		psDaDt->ucDT2 = (UINT8)((psPnFn->usFn -1) / 8);
		
    }
	
	return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_Afn04F1_ConUpPortPara
 ��������  : ���ݽṹת������
 �������  : eMtTransDir eDir                      
             sMtAfn04F1  *psUser    
             sMtAfn04F1_f  *psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��3��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_Afn04F1_ConUpPortPara(eMtTransDir eDir, 
								       void *pUser, 
									   void *pFrame, 
									   UINT16 *pusfLen)
{

	if(!pUser || !pUser || !pusfLen)
    {
        return MT_NULL;
    }

	sMtAfn04F1 *psUser  = (sMtAfn04F1 *)pUser;
	sMtAfn04F1_f *psFrame = (sMtAfn04F1_f *)pFrame;
    
    UINT8 bs8Con = 0;
    
    if(MT_TRANS_U2F == eDir)
    {
		
        psFrame->ucRTS       = psUser->ucRTS;
        psFrame->ucRTM       = psUser->ucRTM;
        psFrame->ucHeartBeat = psUser->ucHeartBeat;
        psFrame->ucSWTS1     = (psUser->usTmWaitTimeoutS & 0xFF);
        psFrame->ucSWTS2     = ((psUser->usTmWaitTimeoutS & 0x0F00) >> 8);
        psFrame->ucSWTS2    |= ((psUser->ucReSendTimes & 0x03) << 4);
        
        if(psUser->bAutoReportAsk_1 == TRUE)
        {
            bs8Con |= 0x01;
        }
		
        if(psUser->bAutoReportAsk_2 == TRUE)
        {
            bs8Con |= 0x02;
        }
		
        if(psUser->bAutoReportAsk_3 == TRUE)
        {
            bs8Con |= 0x04;
        }
		
        psFrame->bs8Con   = bs8Con;
		
    }
    else if(MT_TRANS_F2U == eDir)
    {
        psUser->ucRTS            = psFrame->ucRTS;
        psUser->ucRTM            = psFrame->ucRTM;
        psUser->ucHeartBeat      = psFrame->ucHeartBeat;
        psUser->usTmWaitTimeoutS = (((psFrame->ucSWTS2 & 0x0F) << 8)  |  psFrame->ucSWTS1);
        psUser->ucReSendTimes    = (psFrame->ucSWTS2 >> 4) & 0x03;
        psUser->bAutoReportAsk_1 = ((psFrame->bs8Con & 0x01) ? TRUE : FALSE);
        psUser->bAutoReportAsk_2 = ((psFrame->bs8Con & 0x02) ? TRUE : FALSE);
        psUser->bAutoReportAsk_3 = ((psFrame->bs8Con & 0x04) ? TRUE : FALSE);
		
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn04F1_f);
    return MT_OK;
}
/*****************************************************************************
 �� �� ��  : emt_trans_Afn04F2_ConUpPortParaWireless
 ��������  : ����ת������
 �������  : eMtTransDir eDir                             
             sMtAfn04F2_ConUpPortParaWireless_u  *psUser   
             sMtAfn04F2_ConUpPortParaWireless_f  *psFrame  
             UINT16 *pusfLen                              
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��3��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_Afn04F2_ConUpPortParaWireless(eMtTransDir eDir,
                                               void  *pUser,
                                               void  *pFrame,
                                               UINT16 *pusfLen)
{
   	if(!pUser || !pUser || !pusfLen)
    {
        return MT_NULL;
    }

	sMtAfn04F2_ConUpPortParaWireless_u  *psUser  = (sMtAfn04F2_ConUpPortParaWireless_u *)pUser;
	sMtAfn04F2_ConUpPortParaWireless_f  *psFrame = (sMtAfn04F2_ConUpPortParaWireless_f *)pFrame;



    UINT16 usfLen = 0;
    int i = 0;
    int nAddrCount = 0;
    
    if(MT_TRANS_U2F == eDir)
    {
        if(psUser->bPermit == TRUE)
        {
            psFrame->ucPermit = 1;
        }
        else
        {
            psFrame->ucPermit = 0;
        }

        nAddrCount = (int)(psUser->ucAddrCount);
       
        if(nAddrCount > 16)
        {
            return MT_ERR_PARA;    // ��ֵ�����Գ���16 
        }
        else
        {
            psFrame->ucAddrCount = psUser->ucAddrCount;
        }

        for(i = 0; i < nAddrCount; i++)
        {
            psFrame->usAddress[i] = psUser->usAddress[i];
        }

        usfLen = 1 + nAddrCount*sizeof(UINT16);

        #ifdef MT_DBG_ON
        printf("emt_trans_Afn04F2_ConUpPortParaWireless() user to frame\n");
        printf("ucPermit\t= %d\n",    psFrame->ucPermit);
        printf("ucAddrCount\t= %d\n", psFrame->ucAddrCount);
        for(i = 0; i < nAddrCount; i++)
        {
            printf("usAddress[%d]\t= %d\n", i+1, psFrame->usAddress[i]);
        }     
        #endif
        
    }
    else if(MT_TRANS_F2U == eDir)
    {
        psUser->bPermit     = (psFrame->ucPermit == 1) ? TRUE:FALSE;
        psUser->ucAddrCount = psFrame->ucAddrCount;
        nAddrCount          = (int)(psFrame->ucAddrCount);
        
        for(i = 0; i < nAddrCount; i++)
        {
          psUser->usAddress[i] = psFrame->usAddress[i];
        }

        usfLen = 1 + nAddrCount*sizeof(UINT16);

#ifdef MT_DBG_ON
        printf("emt_trans_Afn04F2_ConUpPortParaWireless() frame to user\n");
        printf("ucPermit\t= %s\n", psUser->bPermit == TRUE ? "true" : "false");
        printf("ucAddrCount\t= %d\n", psUser->ucAddrCount);
        for(i = 0; i < nAddrCount; i++)
        {
            printf("usAddress[%d]\t= %d\n", i+1, psUser->usAddress[i]);
        }
#endif
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usfLen;
    
    return MT_OK;
}





eMtErr emt_trans_Afn04F3_MasterIpPort(eMtTransDir eDir,
                                      void  *pUser,
                                      void  *pFrame,
                                      UINT16 *pusfLen)
{
	
    if(!pUser || !pFrame || !pusfLen)
    {
        return MT_NULL;
    }

	sMtAfn04F3_MasterIpPort_u  *psUser = (sMtAfn04F3_MasterIpPort_u  *)pUser;
	sMtAfn04F3_MasterIpPort_f  *psFrame = (sMtAfn04F3_MasterIpPort_f  *)pFrame;

    
    if(MT_TRANS_U2F == eDir)
    {
        psFrame->ucMainIP[0] =  psUser->ulMainIP & 0xFF;
        psFrame->ucMainIP[1] = (psUser->ulMainIP & 0xFF00)     >> 8;
        psFrame->ucMainIP[2] = (psUser->ulMainIP & 0xFF0000)   >> 16;
        psFrame->ucMainIP[3] = (psUser->ulMainIP & 0xFF000000) >> 24;
		
        psFrame->ucBackIP[0] = psUser->ulBackIP  & 0xFF;
        psFrame->ucBackIP[1] = (psUser->ulBackIP & 0xFF00)     >> 8;
        psFrame->ucBackIP[2] = (psUser->ulBackIP & 0xFF0000)   >> 16;
        psFrame->ucBackIP[3] = (psUser->ulBackIP & 0xFF000000) >> 24;
		
        psFrame->usMainPort  = psUser->usMainPort;
        psFrame->usBackPort  = psUser->usBackPort;
        memcpy(psFrame->ucascAPN, psUser->ucascAPN, 16);
		
    }
    else if(MT_TRANS_F2U == eDir)
    {
        psUser->ulMainIP =    psFrame->ucMainIP[0] 
			| psFrame->ucMainIP[1] << 8
			| psFrame->ucMainIP[2] << 16
			| psFrame->ucMainIP[3] << 24;
		
        psUser->ulBackIP =    psFrame->ucBackIP[0] 
			| psFrame->ucBackIP[1] << 8
			| psFrame->ucBackIP[2] << 16
			| psFrame->ucBackIP[3] << 24;
		
        psUser->usMainPort = psFrame->usMainPort;
        psUser->usBackPort = psFrame->usBackPort;
        memcpy(psUser->ucascAPN, psFrame->ucascAPN, 16);
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn04F3_MasterIpPort_f);
    return MT_OK;
}




eMtErr emt_trans_Afn04F4_MstSmsPhone(eMtTransDir eDir,
                                     void  *psUser,
                                     void  *psFrame,
                                     UINT16 *pusfLen)
{

// 	sMtAfn04F4_MstSmsPhone_u  *psUser,
// 		sMtAfn04F4_MstSmsPhone_f  *psFrame,

    
    return MT_OK;
}


eMtErr emt_trans_Afn04F5_UpMsgAuth(eMtTransDir eDir,
                                   void  *psUser,
                                   void  *psFrame,
                                   UINT16 *pusfLen)
{

// 	sMtAfn04F5_UpMsgAuth_u  *psUser,
//                                    sMtAfn04F5_UpMsgAuth_f  *psFrame,
    
    return MT_OK;
}


eMtErr emt_trans_Afn04f6_ConGroupAddr(eMtTransDir eDir,
									  void  *psUser,
                                      void  *psFrame,
                                    //sMtAfn04F6_ConGroupAddr_u  *psUser,
                                    //sMtAfn04F6_ConGroupAddr_f  *psFrame,
                                    UINT16 *pusfLen)
{


     return MT_OK;

}


eMtErr emt_trans_Afn04F7_ConIpPort(eMtTransDir eDir,
								   void  *psUser,
                                   void  *psFrame,
//                                   sMtAfn04F7_ConIpPort_u  *psUser,
//                                   sMtAfn04F7_ConIpPort_f  *psFrame,
                                  UINT16 *pusfLen)                             
{


     return MT_OK;

}

eMtErr emt_trans_Afn04F8_ConUpComWay(eMtTransDir eDir,
									 void  *psUser,
                                   void  *psFrame,
//                                      sMtAfn04F8_ConUpComWay_u  *psUser,
//                                      sMtAfn04F8_ConUpComWay_f  *psFrame,
                                     UINT16 *pusfLen)
{


    return MT_OK;
}


eMtErr emt_trans_Afn04F9_Con2TmlComPara(eMtTransDir eDir,
										void  *psUser,
                                   void  *psFrame,
//                                         sMtAfn04F9_Con2TmlComPara_u  *psUser,
//                                         sMtAfn04F9_Con2TmlComPara_f  *psFrame,
                                        UINT16 *pusfLen)
{


    return MT_OK;
}

eMtErr emt_trans_Afn04F10_ConDownPara(eMtTransDir eDir,
									  void  *psUser,
                                   void  *psFrame,
//                                       sMtAfn04F10_ConDownPara_u  *psUser,
//                                       sMtAfn04F10_ConDownPara_f  *psFrame,
                                       UINT16 *pusfLen)
{return MT_OK;}

eMtErr emt_trans_Afn04F11_VpnPwd(eMtTransDir eDir,
								 void  *psUser,
                                   void  *psFrame,
//                                  sMtAfn04F11_VpnPwd_u  *psUser,
//                                  sMtAfn04F11_VpnPwd_f  *psFrame,
                                 UINT16 *pusfLen)
{return MT_OK;}        


eMtErr emt_trans_Afn04F12_ConUpLimit(eMtTransDir eDir,
									 void  *psUser,
                                   void  *psFrame,
//                                      sMtAfn04F12_ConUpLimit_u  *psUser,
//                                      sMtAfn04F12_ConUpLimit_f  *psFrame,
                                     UINT16 *pusfLen)
{return MT_OK;}   



/*****************************************************************************
 �� �� ��  : emt_trans_Afn05F1_RemoteCtrlTrip
 ��������  : Զ��ҡ����բ ���ݽṹת������ ��������������֡����ֳ���
 �������  : eMtTransDir eDir                       
             sMtAfn05F1_RemoteCtrlTrip_u  *psUser   
             sMtAfn05F1_RemoteCtrlTrip_f  *psFrame  
             UINT16 *pusfLen                        
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��3��19��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_Afn05F1_RemoteCtrlTrip(eMtTransDir eDir,
										void  *pUser,
                                        void  *pFrame,                                  
                                        UINT16 *pusfLen)
{


    if(!pUser || !pFrame || !pusfLen)
    {
        return MT_NULL;
    }

// 	sMtAfn05F1_RemoteCtrlTrip_u  *psUser  = (sMtAfn05F1_RemoteCtrlTrip_u  *)pUser,
//     sMtAfn05F1_RemoteCtrlTrip_f  *psFrame = (sMtAfn05F1_RemoteCtrlTrip_f  *)pFrame;
// 
//     if(MT_TRANS_U2F == eDir)
//     {
//         if(psUser->ucLimitPowerTime > 15 || psUser->ucHoldAlarmTime > 15)
//         {
//             return MT_ERR_PARA;
//         }
//         
//         psFrame->ucLimitPowerTime = psUser->ucLimitPowerTime;
//         psFrame->ucHoldAlarmTime  = psUser->ucHoldAlarmTime;
//     }
//     else if(MT_TRANS_F2U == eDir)
//     {
//        psUser->ucLimitPowerTime   =  psFrame->ucLimitPowerTime;
//        psUser->ucHoldAlarmTime    =  psFrame->ucHoldAlarmTime;
//     }
//     else
//     {
//         return MT_ERR_PARA;
//     }
//     
//     *pusfLen = sizeof(sMtAfn05F1_RemoteCtrlTrip_f);
    return MT_OK;
}       




/*****************************************************************************
 �� �� ��  : emt_trans_Afn05F31_TimeTick
 ��������  : ��ʱ���ݽṹת������
 �������  : eMtTransDir eDir                  
             sMtAfn05F31_TimeTick_u  *psUser   
             sMtAfn05F31_TimeTick_f  *psFrame  
             UINT16 *pusfLen                   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��3��19��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_Afn05F31_TimeTick(eMtTransDir eDir,
								   void  *psUser,
                                   void  *psFrame,
//                                    sMtAfn05F31_TimeTick_u  *psUser,
//                                    sMtAfn05F31_TimeTick_f  *psFrame,
                                   UINT16 *pusfLen)
{


    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}       


eMtErr emt_trans_Afn05F49_PortSuspend(eMtTransDir eDir,
									  void  *psUser,
                                   void  *psFrame,
//                                       sMtAfn05F49_PortSuspend_u  *psUser,
//                                       sMtAfn05F49_PortSuspend_f  *psFrame,
                                      UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}


eMtErr emt_trans_Afn05F50_PortResume(eMtTransDir eDir,
									 void  *psUser,
                                   void  *psFrame,
//                                      sMtAfn05F50_PortResume_u  *psUser,
//                                      sMtAfn05F50_PortResume_f  *psFrame,
                                     UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}

eMtErr emt_trans_Afn05F51_PortAgain(eMtTransDir eDir,
									void  *psUser,
                                   void  *psFrame,
//                                     sMtAfn05F51_PortAgain_u  *psUser,
//                                     sMtAfn05F51_PortAgain_f  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}


eMtErr emt_trans_Afn06F1_IdAuthQ(eMtTransDir eDir,
								 void  *psUser,
                                   void  *psFrame,
//                                  sMtAfn06F1_IdAuthQ_u  *psUser,
//                                  sMtAfn06F1_IdAuthQ_f  *psFrame,
                                 UINT16 *pusfLen)
{

//     if(!psUser || !psFrame || !pusfLen)
//     {
//         return MT_NULL;
//     }
// 
//     if(MT_TRANS_U2F == eDir)
//     {
//         memcpy(psFrame->aCiphertext, psUser->aCiphertext, 16);
//     }
//     else if(MT_TRANS_F2U == eDir)
//     {
//         memcpy(psUser->aCiphertext, psFrame->aCiphertext, 16);
//     }
//     else
//     {
//         return MT_ERR_PARA;
//     }
//     
//     *pusfLen = sizeof(sMtAfn06F1_IdAuthQ_f);
    return MT_OK;
}


eMtErr emt_trans_Afn06F2_IdAuthA(eMtTransDir eDir,
								 void  *psUser,
                                   void  *psFrame,
//                                  sMtAfn06F2_IdAuthA_u  *psUser,
//                                  sMtAfn06F2_IdAuthA_f  *psFrame,
                                 UINT16 *pusfLen)
{

	/*
    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }


    if(MT_TRANS_U2F == eDir)
    {
        memcpy(psFrame->aCiphertext, psUser->aCiphertext, 16);
    }
    else if(MT_TRANS_F2U == eDir)
    {
        memcpy(psUser->aCiphertext, psFrame->aCiphertext, 16);
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn06F2_IdAuthA_f);
*/
    return MT_OK;
}

eMtErr emt_trans_Afn06F3_RandQ(eMtTransDir eDir,
							   void  *psUser,
                                   void  *psFrame,
//                                sMtAfn06F3_RandQ_u  *psUser,
//                                sMtAfn06F3_RandQ_f  *psFrame,
                               UINT16 *pusfLen)
{

     if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }
/*

    if(MT_TRANS_U2F == eDir)
    {
        memcpy(psFrame->aCiphertext, psUser->aCiphertext, 16);
    }
    else if(MT_TRANS_F2U == eDir)
    {
        memcpy(psUser->aCiphertext, psFrame->aCiphertext, 16);
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn06F3_RandQ_f);
*/
    return MT_OK;
}

eMtErr emt_trans_Afn06F4_RandA(eMtTransDir eDir,
							   void  *psUser,
                                   void  *psFrame,
//                                sMtAfn06F4_RandA_u  *psUser,
//                                sMtAfn06F4_RandA_f  *psFrame,
                               UINT16 *pusfLen)
{

     if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }
/*

    if(MT_TRANS_U2F == eDir)
    {
        memcpy(psFrame->aCiphertext, psUser->aCiphertext, 16);
    }
    else if(MT_TRANS_F2U == eDir)
    {
        memcpy(psUser->aCiphertext, psFrame->aCiphertext, 16);
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn06F4_RandA_f);
*/


    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_Afn09F1_ConVersion
 ��������  : �������汾��Ϣ���ݽṹת������
 �������  : eMtTransDir eDir                   
             sMtAfn09F1_ConVersion_u  *psUser   
             sMtAfn09F1_ConVersion_f  *psFrame  
             UINT16 *pusfLen                    
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��3��19��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_Afn09F1_ConVersion(eMtTransDir eDir,
									void  *psUser,
                                   void  *psFrame,
//                                     sMtAfn09F1_ConVersion_u  *psUser,
//                                     sMtAfn09F1_ConVersion_f  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}

eMtErr emt_trans_Afn09F4_ConParaCfg(eMtTransDir eDir,
									void  *psUser,
                                   void  *psFrame,
//                                     sMtAfn09F4_ConParaCfg_u *psUser,
//                                     sMtAfn09F4_ConParaCfg_f  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}

eMtErr emt_trans_Afn09F5_ConCtrlCfg(eMtTransDir eDir,
									void  *psUser,
                                   void  *psFrame,
//                                     sMtAfn09F5_ConCtrlCfg_u *psUser,
//                                     sMtAfn09F5_ConCtrlCfg_f  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }



    
    return MT_OK;
}


eMtErr emt_trans_Afn09F6_ConAsk1Cfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }

// 	sMtAfn09F6_ConAsk1Cfg_u *psUser,
//                                     sMtAfn09F6_ConAsk1Cfg_f  *psFrame,

    
    return MT_OK;
}


eMtErr emt_trans_Afn09F7_ConAsk2Cfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }
// 
// 	sMtAfn09F7_ConAsk2Cfg_u *psUser,
//                                     sMtAfn09F7_ConAsk2Cfg_f  *psFrame,

    
    return MT_OK;
}       



eMtErr emt_trans_Afn09F8_ConEvntCfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen)
{

    if(!psUser || !psFrame || !pusfLen)
    {
        return MT_NULL;
    }

// 	sMtAfn09F8_ConEvntCfg_u *psUser,
//   sMtAfn09F8_ConEvntCfg_f  *psFrame,


    
    return MT_OK;
}       


/*****************************************************************************
 �� �� ��  : eMtPackCommon
 ��������  : ���ķ�װ����
 �������  : eMtAFN         eAFN      
             sMtPackCommon *psCommon  
             UINT16 *pusLen           
             UINT8  *pOutBuf          
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::eMtPackCommon(eMtAFN eAFN, sMtPackCommon *psCommon, UINT16 *pusLen, UINT8 *pOutBuf)
{
	eMtErr eErr     = MT_OK;
    UINT16 usBufLen = 0;
    UINT8  ucCtrl   = 0;
    UINT16 usUserDataLen = 0; // �û��������ֳ� ����CS �� ������ 
    
    UINT8 *pucSeq  = NULL;
    UINT8 *pucCtrl = NULL;   // ���ڼ���CS
    UINT8 *pucCS   = NULL;
    sMtfComHead *psHead = NULL;
   
    if(!psCommon || !pusLen || !pOutBuf)
    {
        return MT_NULL;
    }


    if(m_bInit != TRUE)
    {
        return MT_ERR_INIT;
    }

    // ֡���Ƿ���
    if(psCommon->usSeq2CsLen > MT_SEQ2CS_BYTES_MAX)
    {
        return MT_OUT_RNG;
    }

    if(!(psCommon->pSeq2Cs))
    {
        return MT_ERR_SEQ2CS;
    }
       
    psHead = (sMtfComHead *)pOutBuf;

    // 0x68
    psHead->f68 = 0x68;
    psHead->s68 = 0x68;

    // AFN 
    psHead->AFN  = eAFN;
    
    // ����Ӧ�ò����ݵĳ���
    usUserDataLen  = psCommon->usSeq2CsLen + MT_CANS_LEN;  
    psHead->L1 = (usUserDataLen & 0x003F);
    psHead->L2 = (usUserDataLen & 0x3FC0) >> 6;

    psHead->p10 = 3;
    
    // ���������
    eErr = emt_trans_ctrl(MT_TRANS_U2F, &(psCommon->suCtrl), &ucCtrl);
    if(eErr != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("emt_trans_ctrl failed: %d\n", eErr);
        #endif 
        return MT_ERR_CTRL;
    }


   
    psHead->C = ucCtrl;

    // ��ַ��
    eErr = emt_trans_addr(MT_TRANS_U2F, &(psCommon->suAddr), &(psHead->A));
    if(eErr != MT_OK)
    {
        return MT_ERR_ADDR;
    }
        
    // ����SEQ
    eErr = emt_trans_SEQ(MT_TRANS_U2F, &(psCommon->suSEQ), (sMtfSEQ*)&(psHead->SEQ));

    if(eErr != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("emt_trans_SEQ failed: %d\n", eErr);
        #endif 
        return MT_ERR_SEQ;
    }

    // ����SEQ �� CS ֮�������
    pucSeq = (UINT8*)&(psHead->SEQ);
    pucSeq++;  // ȡ��Ӧ�ò������׵�ַ
      
    memcpy((void*)pucSeq, (void*)(psCommon->pSeq2Cs), psCommon->usSeq2CsLen);

    // ����CS
    pucCtrl = (UINT8*)&(psHead->C);   // ������ʼλ��
    pucCS   = (UINT8*)(pucCtrl + usUserDataLen);
    
    *pucCS = ucmt_get_check_sum(pucCtrl, usUserDataLen);

    // 0x16H
    pucCS++;
    *pucCS = 0x16;    

    // �����ܳ�
    usBufLen = usUserDataLen + MT_UN_USER_LEN;

    // ����װ��ı��� ����ص�
    

    // ���ݷ���ֵ��ͬ�Ĵ���
  




    // �������
    *pusLen = usBufLen;

    #ifdef MT_DBG_ON
    printf("\\------eMtPackCommon()-----------------/\n");
    #endif
    // �����������
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_trans_ctrl
 ��������  : �������û����֡������ת������
 �������  : eMtTransDir eDir  
             sMtuCtrl *puCtrl  
             UINT8* pfCtrl     
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_trans_ctrl(eMtTransDir eDir, sMtuCtrl *puCtrl, UINT8 *pfCtrl)
{
	
   UINT8 ucfCtrl = 0;

    if(!puCtrl || !pfCtrl)
    {
        return MT_NULL;
    }
    
    if(MT_TRANS_U2F == eDir)       // �û���ת��Ϊ֡��
    {

        (puCtrl->eDir == MT_DIR_M2S)  ? (ucfCtrl &= 0x7F) : (ucfCtrl |= 0x80);
        (puCtrl->ePRM == MT_PRM_ACTIVE) ? (ucfCtrl |= 0x40) : (ucfCtrl &= 0xBF);

        if(puCtrl->eDir == MT_DIR_M2S)
        { 
            //���б��� 
            (puCtrl->uDir.sDown.bFcv == TRUE) ? (ucfCtrl |= 0x10) : (ucfCtrl &= 0xEF);
            (puCtrl->uDir.sDown.btFCB == 1)   ? (ucfCtrl |= 0x10) : (ucfCtrl &= 0xEF);
           
        }
        else
        {
            // ���б���
            (puCtrl->uDir.sUp.bAcd == TRUE) ? (ucfCtrl |= 0x20) : (ucfCtrl &= 0xDF);
        }

        // ������
        if(puCtrl->ePRM == MT_PRM_ACTIVE)
        {
            ucfCtrl |= (puCtrl->uFCode.eFcdPrm0 & 0x0F);
        }
        else
        {
            ucfCtrl |= (puCtrl->uFCode.eFcdPrm1 & 0x0F);
        } 

        *pfCtrl = ucfCtrl;

    }
    else if (MT_TRANS_F2U == eDir)
    { 

       ucfCtrl = * pfCtrl;
       if(ucfCtrl & 0x80)
       {
            puCtrl->eDir = MT_DIR_S2M;  // ����
            (ucfCtrl & 0x20) ?  (puCtrl->uDir.sUp.bAcd =  TRUE)  : (puCtrl->uDir.sUp.bAcd = FALSE);
       }
       else
       {
            puCtrl->eDir = MT_DIR_M2S;  // ����
            (ucfCtrl & 0x20) ?  (puCtrl->uDir.sDown.bFcv =  TRUE)  : (puCtrl->uDir.sDown.bFcv  = FALSE);
            (ucfCtrl & 0x10) ?  (puCtrl->uDir.sDown.btFCB = 1)     :  (puCtrl->uDir.sDown.btFCB = 0);
       }

       (ucfCtrl & 0x40) ?  (puCtrl->ePRM = MT_PRM_ACTIVE)     : (puCtrl->ePRM = MT_PRM_PASIVE);
  
        puCtrl->uFCode.eFcdPrm0 = (eFcodePrm0)(ucfCtrl & 0x0F);


        
        
    }
    else
    {   
        return MT_ERR_PARA;
    }




    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_trans_addr
 ��������  : ��ַ��Ϣ �û�����֡�����ݽṹת������
 �������  : eMtTransDir eDir     
             sMtAddress *puAddr  
             sMtfAddress *pfAddr  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��20��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_trans_addr(eMtTransDir eDir, sMtuAddress *puAddr, sMtfAddress *pfAddr)
{
#ifdef MT_DBG_ON_emt_trans_addr
	printf("------emt_trans_addr() \n");
#endif 
    
	if(!puAddr || !pfAddr)
	{
		return MT_NULL;
	}
	
	if(eDir != MT_TRANS_U2F && eDir != MT_TRANS_F2U)
	{
		
		return MT_ERR_PARA;
	}
	
	if(eDir == MT_TRANS_U2F)  // user interface to frame  
	{
        if(puAddr->usTAddress == 0)
		{
			
			return MT_ERR_ADDR;  // 0x0000Ϊ��Ч��ַ
		}
		
        if(puAddr->ucMAddress > MT_MST_ADDR_MAX)
        {
            return MT_ERR_ADDR; // �������վ�ĵ�ַ
        }
        
		
		(void)emt_str_to_bcd((char*)puAddr->acRegionCode, (char*)pfAddr->ucRegionCode , 4);
	

		(void)emt_write_uint16_small_endian(puAddr->usTAddress, (UINT8*)&(pfAddr->usTAddress));
		
#ifdef MT_DBG_ON_emt_trans_addr
        printf("emt_trans_addr() frame terminal address = %x\n", *(UINT32*)&(pfAddr->usTAddress));
        printf("emt_trans_addr() user  terminal address = %x\n", puAddr->ulTAddress);
#endif 
        
        pfAddr->ucMAddress = (puAddr->ucMAddress << 1);
		if(puAddr->bTeamAddr == TRUE)
		{
			
			pfAddr->ucMAddress |= 0x01;
		}
		else
		{
			
			pfAddr->ucMAddress &= 0xFE;
		}
		
		
	}
	else // frame to user interface
	{
		
		(void)emt_bcd_to_str((char*)(pfAddr->ucRegionCode), (char*)(puAddr->acRegionCode), 2);
		puAddr->usTAddress = usmt_read_uint16_small_endian((UINT8*)&(pfAddr->usTAddress));
		puAddr->bTeamAddr  = (pfAddr->ucMAddress & 0x01) ? TRUE : FALSE;
		puAddr->ucMAddress = (pfAddr->ucMAddress >> 1) & 0x7F;
 
	}
    
	return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_trans_SEQ
 ��������  : ��SEQ�ֶδ��û��ൽ֡��ת������
 �������  : eMtTransDir eDir  
             sMtuSEQ *puSEQ    
             sMtfSEQ *pfSEQ    
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��20��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_trans_SEQ(eMtTransDir eDir, sMtuSEQ *puSEQ, sMtfSEQ *pfSEQ)
{
	if(!puSEQ || !pfSEQ)
	{
		
		return MT_NULL;
	}
	
	if(MT_TRANS_F2U == eDir)
	{
		       
		puSEQ->bTpv  = (pfSEQ->TpV == 1) ? TRUE :FALSE;
		puSEQ->bCon  = (pfSEQ->CON == 1) ? TRUE :FALSE;
		puSEQ->ucSEQ = pfSEQ->SEQ;
		
		if(pfSEQ->FIR == 1)
		{
			
			if(pfSEQ->FIN == 1)
			{
				
				puSEQ->ePos = MT_POS_SIGLE;
			}
			else
			{
				
				puSEQ->ePos = MT_POS_MUL_S;
			}
		}
		else
		{
			
			if(pfSEQ->FIN == 1)
			{
				
				puSEQ->ePos = MT_POS_MUL_E;
			}
			else
			{
				
				puSEQ->ePos = MT_POS_MUL_M;
			}
		}
		
        
	}
	else if(MT_TRANS_U2F == eDir)
	{
		
		pfSEQ->TpV = (puSEQ->bTpv == TRUE) ? 1 : 0;
		pfSEQ->CON = (puSEQ->bCon == TRUE) ? 1 : 0;
		pfSEQ->SEQ =  puSEQ->ucSEQ & 0x0F;
		
		switch(puSEQ->ePos)
		{
			
		case MT_POS_SIGLE:
			pfSEQ->FIR = 1;
			pfSEQ->FIN = 1;
			break;
			
		case MT_POS_MUL_S:
			pfSEQ->FIR = 1;
			pfSEQ->FIN = 0;
			break;
			
		case MT_POS_MUL_M:
			pfSEQ->FIR = 0;
			pfSEQ->FIN = 0;
			break;
			
		case MT_POS_MUL_E:
			pfSEQ->FIR = 0;
			pfSEQ->FIN = 1;
			break;
			
		default:
			return MT_ERR_PARA;
			//break;
		}
		
	}
	else
	{
		
		return MT_ERR_PARA;
	}
	
	return MT_OK;

}

/*****************************************************************************
 �� �� ��  : ucmt_get_check_sum
 ��������  : ����У��ͺ���
 �������  : UINT8 *pStartPos  
             UINT16 usLen      
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��16��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 CNxRuler::ucmt_get_check_sum(UINT8 *pStartPos, UINT16 usLen)
{
	UINT8 ucCheckSum = 0;
    int i = 0;
	
    for(i = 0; i < usLen; i++)
    {
        ucCheckSum += pStartPos[i];
    }
	
    return ucCheckSum;
}

/*****************************************************************************
 �� �� ��  : emt_str_to_bcd
 ��������  : ������Ϊlen���ַ���ת��ΪBCD ����Ϊ len/2
 �������  : const char *pstr  
             UINT8 *pbcd       
             int len           
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��19��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_str_to_bcd(const char *pstr, char *pbcd, int len)
{
	if(!pstr || !pbcd)
	{
		
		return MT_NULL;
	}
	
	if(len < 0)
	{
		
		return MT_ERR_PARA;
	}
	
	UINT8 tmpValue;
	int i;
	int j;
	int m;
	int sLen;
	
	sLen = strlen(pstr);
	for(i = 0; i < sLen; i++)
	{
		if((pstr[i] < '0')
			||((pstr[i] > '9') && (pstr[i] < 'A')) 
			||((pstr[i] > 'F') && (pstr[i] < 'a')) 
			||(pstr[i] > 'f'))
		{
			sLen=i;
			break;
		}
	}
	
	sLen = (sLen <= (len * 2) ) ?  sLen : sLen * 2;
	memset((void *)pbcd, 0x00, len);
	
	for(i = sLen-1, j = 0, m = 0; (i>=0) && (m<len); i--, j++)
	{
		if((pstr[i] >= '0') && (pstr[i] <= '9'))
		{
			tmpValue=pstr[i] - '0';
		}
		else if((pstr[i] >= 'A') && (pstr[i] <= 'F'))
		{
			tmpValue=pstr[i] - 'A' + 0x0A;
		}
		else if((pstr[i] >= 'a') && (pstr[i] <= 'f'))
		{
			tmpValue=pstr[i] - 'a' + 0x0A;
		}
		else
		{
			tmpValue=0;
		}
		
		if((j%2) == 0)
		{
			pbcd[m] = tmpValue;		
		}
		else
		{
			pbcd[m++] |= (tmpValue << 4);
		}
		
		if((tmpValue==0) && (pstr[i] != '0'))
		{
			break;
		}
	}
	
	return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_write_uint32_small_endian
 ��������  : ��һ��ulong����С�ֽ���ķ�ʽд��ָ���ڴ�
 �������  : UINT32 ulData  
             UINT8* pWrite  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��16��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_write_uint32_small_endian(UINT32 ulData, UINT8 *pWrite)
{
	UINT8 *pucData;
    BOOL  bBigEndian = FALSE;
    
    if(!pWrite)
	{

		return MT_NULL;
	}
    
	bBigEndian = bMtIsBigEndian();

	if(bBigEndian == TRUE)
	{

		pucData = (UINT8 *)pWrite;
        *pucData++ = (UINT8)(ulData & 0xFF);
        *pucData++ = (UINT8)((ulData & 0xFF00)     >> 8);
		*pucData++ = (UINT8)((ulData & 0xFF0000)   >> 16);
        *pucData++ = (UINT8)((ulData & 0xFF000000) >> 24);
	}
	else
	{

		//*(UINT32*)pWrite = ulData;
        memcpy((void*)pWrite, (void*)&ulData, sizeof(UINT32));

	}
		
	return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_bcd_to_str
 ��������  : ������Ϊlen��BCD��תΪ2*len�����ַ���
 �������  : const char* pbcd  
             char *pstr        
             int len           
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��19��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_bcd_to_str(const char *pbcd, char *pstr, int len)
{
	if(!pstr || !pbcd)
	{
		
		return MT_NULL;
	}
	
	if(len < 0)
	{
		
		return MT_ERR_PARA;
	}
	
	int i = 0,j= 0;
	char c1 = 0,c0 = 0;
	
	for(i = len - 1,j = 0; i >= 0; i--)
	{
		c0 = pbcd[i] & 0xF;
		c1 = (pbcd[i] >> 4) & 0xF;
		if(c1 >= 0 && c1 <= 9)
		{
			pstr[j++] = c1 + '0';	
		}
		else
		{
			pstr[j++] = c1 + 'A';
		}
		
		if(c0 >= 0 && c0 <= 9)
		{
			pstr[j++] = c0 + '0';			
		}
		else
		{
			pstr[j++] = c0 + 'A';
		}	
	}
	
	return MT_OK;

}

/*****************************************************************************
 �� �� ��  : ulmt_read_uint32_small_endian
 ��������  : ��С�ֽ���ķ�ʽ����һ����������
 �������  : UINT8 *pRead  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��16��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT32 CNxRuler::ulmt_read_uint32_small_endian(UINT8 *pRead)
{
	UINT8 ucData[4];
	UINT32 ulRet = 0;
    BOOL bBigEndian = FALSE;
    
    if(!pRead)
	{
		
		return 0xFFFFFFFF;
	}
	
	bBigEndian = bMtIsBigEndian();
	
	if(bBigEndian == TRUE)
	{
		
		ucData[3] = *(pRead + 0);
		ucData[2] = *(pRead + 1);
        ucData[1] = *(pRead + 2);
		ucData[0] = *(pRead + 3);
		ulRet = *(UINT32*)ucData;		
	}
	else
	{
		
		//ulRet = *(UINT32*)pRead;
        memcpy((void*)&ulRet, (void*)pRead, sizeof(UINT32));
	}
	
	return ulRet;

}
/*****************************************************************************
 �� �� ��  : bMtIsBigEndian
 ��������  : �ж��������Ƿ�Ϊ���ֽ���
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��20��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL CNxRuler::bMtIsBigEndian()
{
	UINT16 usData = 0x1234;
	
	if(*(UINT8*)&usData == 0x12)
	{
		
		return TRUE;
	}
	else
	{
		
		return FALSE;
	}

}


/*****************************************************************************
 �� �� ��  : emt_find_frist_valid_pack
 ��������  : �ҵ���һ����Ч֡��λ�ü�����
 �������  : UINT8  *pinBuf     
             UINT16 usLen       
             UINT16 *pusFirstOff ��һ����Ч֡��ƫ��  
             UINT16 *pusFirstLen   ��һ����Ч֡�ĳ���
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��26��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_find_frist_valid_pack(UINT8 *pinBuf, UINT16 usLen, UINT16 *pusFirstOff, UINT16 *pusFirstLen)
{
	if(!pinBuf || !pusFirstOff || !pusFirstLen)
    {
        return MT_NULL;
    }
    
    eMtErr eRet = MT_OK;
    int i = 0, j = 0, k = 0;
    UINT16 usValidLen = 0;
    
	
    for(i = 0; i < usLen; i++)
    {
        if(pinBuf[i] == 0x68)
        {
#ifdef MT_DBG_ON
            //printf("eMtIsValidPack() first 0x68 i = %d\n", i);
#endif
            // �ж��������ֽ�λ���ǲ���0x68
            if(pinBuf[i+3] == 0x68)
            {
#ifdef MT_DBG_ON
                //printf("eMtIsValidPack() second 0x68 i = %d\n", i+2);
#endif
				
                for(j = i+4; j < usLen; j++)
                {
                    if(pinBuf[j] == 0x16)
                    {                        
                        usValidLen = j + 1;
                        eRet = eMtIsValidPack((UINT8*)(pinBuf + i), usValidLen);
                        if(eRet == MT_OK)
                        {
                            *pusFirstOff = i;
                            *pusFirstLen = usValidLen;
#ifdef MT_DBG_ON
                            //printf("emt_find_frist_valid_pack() pusFirstOff = %d pusFirstLen = %d\n", *pusFirstOff, usValidLen);
#endif
                            return MT_OK;
                        }
                        
                    }
                }
				
                continue;
            }
        }
    }
    
    return MT_NONE;

}

/*****************************************************************************
 �� �� ��  : eMtIsValidPack
 ��������  : �ж�һ����0x68��ͷ��0x16��β��buffer�Ƿ�Ϊһ����Ч��367.1����
 �������  : UINT8  *pOutBuf  
             UINT16 usLen     
 �������  : ��
 �� �� ֵ  : �����һ����Ч�������ı��ģ�����MT_OK�� ���򷵻ش�������
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��26��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::eMtIsValidPack(UINT8 *pOutBuf, UINT16 usLen)
{
	if(!pOutBuf)
    {
        return MT_NULL;
    }
	
    UINT16 usUserLen   = 0;     
    UINT8  ucCheckSumP = 0;    
    UINT8  ucCheckSumC = 0;   
    UINT8  uc0x16      = 0;
    UINT16 usProtoLen  = 0; //ʵ��Ӧ�õ�Э�����ݳ���
    
    sMtfComHead *pfComHead = NULL;
    pfComHead = (sMtfComHead *)pOutBuf;
	
    if(pfComHead->f68 != 0x68 || pfComHead->s68 != 0x68)
    {
        return MT_ERR_0x68;
    }
	
    if(pfComHead->p10 != 3)
    {
        return MT_ERR_PROTO;
    }
	
    usUserLen =  ((pfComHead->L2 << 6) & 0x3FC0 )| (pfComHead->L1 & 0x003F) ; 
	
	
    ucCheckSumP =  *(UINT8*)((UINT8*)&(pfComHead->C) + usUserLen);
#ifdef MT_DBG_ON
    printf("ucCheckSumP = %d\n", ucCheckSumP);

#endif 
	
    ucCheckSumC = ucmt_get_check_sum((UINT8*)&(pfComHead->C), usUserLen);
    
#ifdef MT_DBG_ON
	printf("ucCheckSumC = %d\n", ucCheckSumC);
#endif 
	
    if(ucCheckSumC != ucCheckSumP)
    {
        return MT_ERR_CS;
    }
	
    // Э��Ӧ�õ����ݳ���
    usProtoLen = usUserLen + MT_UN_USER_LEN;
    if(usLen < usProtoLen)
    {   
        return MT_ERR_UNCOMP;
    }
	
    uc0x16 = *(UINT8*)((UINT8*)&(pfComHead->C) + usUserLen + 1);
#ifdef MT_DBG_ON
    //printf("uc0x16 = %d\n", uc0x16);
#endif 
	
    if(uc0x16 != 0x16)
    {
        return MT_ERR_0x16;
    }
	
    
	
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_write_uint16_small_endian
 ��������  : ��һ��UINT16��С�ֽ���ķ�ʽд��ָ����ַ
 �������  : UINT16 usData  
             UINT8* pWrite  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��20��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_write_uint16_small_endian(UINT16 usData, UINT8 *pWrite)
{
	if(!pWrite)
	{
		
		return MT_NULL;
	}
	
	UINT8 ucByteHi = 0, ucByteLo = 0;
	BOOL bBigEndian = bMtIsBigEndian();
	
	if(bBigEndian == TRUE)
	{
		
		ucByteHi    = *(UINT8*)&usData;
		ucByteLo    = *((UINT8*)&usData + 1);
		*pWrite     = ucByteLo;
		*(pWrite+1) = ucByteHi;
		
	}
	else
	{
		
		*(UINT16*)pWrite = usData;
	}
	
	return MT_OK;	

}

/*****************************************************************************
 �� �� ��  : usmt_read_uint16_small_endian
 ��������  : ��С�ֽڷ�ʽ��ȡһ��short
 �������  : UINT8 *pRead  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��16��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT16 CNxRuler::usmt_read_uint16_small_endian(UINT8 *pRead)
{
	if(!pRead)
	{
		
		return 0xFFFF;
	}
	
	BOOL bBigEndian = bMtIsBigEndian();
	UINT8 ucData[2];
	UINT16 usRet = 0;
	
	if(bBigEndian == TRUE)
	{
		
		ucData[1] = *pRead;
		ucData[0] = *(pRead+1);
		usRet = *(UINT16*)ucData;		
	}
	else
	{
		
		usRet = *(UINT16*)pRead;
	}
	
	return usRet;

}

/*****************************************************************************
 �� �� ��  : emtPack
 ��������  : ��װ����֡����
 �������  : smtPack *sPack   
             UINT16 *pusLen   
             UINT8  *pOutBuf  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 ����˵��  : ���Է�װ������������֡, 
 
 �޸���ʷ      :
  1.��    ��   : 2013��4��17�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emtPack(smtPack *psPack, UINT16 *pusLen, UINT8 *pOutBuf)
{
    // ���뺯��
   
    if(!psPack || !pusLen || !pOutBuf)
    {
        return MT_NULL;
    }

    if(m_bInit != TRUE)
    {
        return MT_ERR_INIT; 
    }

    eMtErr         eRet        = MT_OK;
    eMtCmd         eCmd        = CMD_AFN_0_FN_0_UNKOWN;
    eMtDir         eDir        = MT_DIR_UNKOWN;
    eMtAFN         eAFN        = AFN_NULL;
    INT32          i           = 0;
    UINT16         usPn        = 0;
    UINT16         usSeq2CsLen = 0;
    UINT16         usSeq2CsPos = 0; 
    UINT16         usfDataLen  = 0;      // ֡�����ݵ�Ԫ�ֳ�
    UINT8          *pSeq2Cs    = NULL;
    UINT8          *puData     = NULL;   // ���ݵ�Ԫ�û�������
    sMtDaDt        *pDaDt      = NULL;   // ���ݵ�Ԫ��ʶ
    UINT8          *pData      = NULL;   // ���ݵ�Ԫ
    sMtEC          *psEC       = NULL;
    sMtfTp         *psfTp      = NULL;   // ֡��Tp�ֶ�
    
    pMtTransFunc   pFunc       = NULL;
    sMtuCtrl       suCtrl;
    sMtCmdInfors   sCmdInfor;
    sMtPackCommon  sPackCommon;
    sMtPnFn        sPnFn;
    //sMtuTp         suTp;    // �û���Tp�ֶ���Ϣ

    if(m_role == MT_ROLE_MASTER)
    {
        eDir = MT_DIR_M2S;
    }
    else
    {
        eDir = MT_DIR_S2M;
    }


    /* ��װpackCommon ��� */

    // ����ͨ�÷������
    pSeq2Cs = (UINT8*)malloc(MT_SEQ2CS_BYTES_MAX);

    if(pSeq2Cs == NULL)
    {
        return MT_ERR_IO;
    }

    // ��װ�䳤�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��
    if(psPack->ucSubNum == 0)
    {
        return MT_ERR_PROTO;
    }
	
	
    // ��װ����һ�����ݱ�ʶ�����ݵ�Ԫ���
    for(i = 0; i < (INT32)psPack->ucSubNum; i++)
    {    
        eCmd  = (eMtCmd)((psPack->sSub[i].eSubCmd) & 0xFFFF); //ȥ�������ϱ������ʶ
        usPn  = psPack->sSub[i].usPN;
        pDaDt = (sMtDaDt*)(pSeq2Cs + usSeq2CsPos);
        
        // ��ȡ�������ֶ�Ӧ����Ϣ
        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
        if(eRet != MT_OK)
        {          
            vMtfree(pSeq2Cs);
            return eRet;
        }
		
        /* ���ݵ�Ԫ��ʶ */
        // ����������Ӧ��pn����Ϊ P0 �����û������Pnֵ
        if(sCmdInfor.ePn == MT_PN_0) 
        {
            usPn = 0;
        }

        usSeq2CsPos += sizeof(sMtDaDt);
        sPnFn.usFn  = eCmd & 0xFF;
        sPnFn.usPn  = usPn;
        eRet = eMtTransPnFn_to_DaDt(&sPnFn, pDaDt);
        if(eRet != MT_OK)
        {
            vMtfree(pSeq2Cs);
            return eRet;
        }

        // ���ݵ�Ԫ
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        pFunc = sCmdInfor.pFunc;

        if(pFunc != NULL)
        {
            puData = (UINT8*)&(psPack->sSub[i].uAppData);
            eRet = pFunc(MT_TRANS_U2F, puData, pData, &usfDataLen);
            if(eRet != MT_OK)
            {
                vMtfree(pSeq2Cs);
                return eRet;
            }

            usSeq2CsPos += usfDataLen;
			CString str;
			str.Format("data %d",usSeq2CsPos);
	     	//AfxMessageBox(str);
        }
		
    }
    
	
	/* ������Ϣ��AUX */
    eAFN = psPack->eMainCmd;
	
    // ���������
    eRet = eMtGetCtrl(eAFN, eDir, psPack->sCtrl.ePRM, &suCtrl);
    if(eRet != MT_OK)
    {
        vMtfree(pSeq2Cs);
        return eRet;
    }

    // ����� EC
    if(bmt_have_ec(eAFN, eDir) == TRUE)
     {       
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psEC  = (sMtEC*)pData;
        psEC->ucEC1 = m_EC.ucEC1;
        psEC->ucEC2 = m_EC.ucEC2;
        usSeq2CsPos += sizeof(sMtEC);
     }
    
    // ����� pw  pw������Ҫ�����б�����,����վ����,�ն���֤��ͨ����ִ��(16�ֽ�)
    if(bmt_have_pw(eAFN, eDir) == TRUE)    
    {
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        // ��Ϣ��֤�㷨, ��ʽ��Ϊ��16���ֽ�, Ĭ��Ϊ0
        memcpy((void*)pData, (void*)m_aucPw, MT_PW_LEN); 
        usSeq2CsPos += MT_PW_LEN;

		CString str;
		str.Format("pw %d",usSeq2CsPos);
		//AfxMessageBox(str);
        
    }

    // ����� TP
    if(bmt_have_tp(eAFN, eDir) == TRUE)  // ����������������б�����
    {
		CString str;
		str.Format("tp %d",usSeq2CsPos);
	     //	AfxMessageBox(str);

        //pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psfTp = (sMtfTp *)(pSeq2Cs + usSeq2CsPos);;
        //(void)emt_get_mtutp(m_ucPFC, &suTp);
        (void)emt_trans_tp(MT_TRANS_U2F, &psPack->sTP, psfTp);
        usSeq2CsPos += sizeof(sMtfTp);
        sPackCommon.suSEQ.bTpv = TRUE;
    }
	else
	{
		sPackCommon.suSEQ.bTpv = FALSE;
	}

    // �ñ����Ƿ���Ҫ�Ӷ�վȷ��
	sPackCommon.suSEQ.bCon = bmt_need_con(eAFN, eDir);
  

    // �ܽ�����
    usSeq2CsLen             = usSeq2CsPos;
    sPackCommon.suSEQ.ePos  = MT_POS_SIGLE;    // Ŀǰ���ǵ�֡��
    sPackCommon.suSEQ.ucSEQ = psPack->sTP.ucPFC & 0x0F;
    sPackCommon.suAddr      = psPack->sAddress;
    sPackCommon.pSeq2Cs     = pSeq2Cs;
    sPackCommon.usSeq2CsLen = usSeq2CsLen;
    sPackCommon.suCtrl      = suCtrl;
    
    // ͨ��ͨ�÷������pack
    eRet = eMtPackCommon(eAFN,  &sPackCommon, pusLen, pOutBuf);   
    if(eRet != MT_OK)
    {
        #ifdef MT_DBG_ON
		CString strdbg;
		strdbg.Format("eMtPackCommon failed: %d\n", eRet);
		OutputDebugString(strdbg);
        #endif 

        vMtfree(pSeq2Cs);
        return eRet;
    }
	else
	{
		OutputDebugString("eMtPackCommon()�ɹ�");
	}

  
    #ifdef MT_DBG_ON
    printf("\\----------------------------eMtPack()----------------------------/\n");
    #endif 
    vMtfree(pSeq2Cs);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : vMtfree
 ��������  : ���malloc ������ڴ��ڼ�
 �������  : UINT8 *pBuf  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void CNxRuler::vMtfree(UINT8 *pBuf)
{
	if(pBuf != NULL)
    {
        free(pBuf);
        pBuf = NULL;
    }

}

/*****************************************************************************
 �� �� ��  : eMtTransPnFn_to_DaDt
 ��������  : ��������Ϣ��ʶ��PnFn�ṹת��ΪData�ṹ
 �������  : sMtPnFn *psPnFn  
             sMtDaDt *psDaDt  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::eMtTransPnFn_to_DaDt(sMtPnFn *psPnFn, sMtDaDt *psDaDt)
{
	if(!psPnFn || !psDaDt)
	{
		return MT_NULL;
	}
	
	if(psPnFn->usPn > MT_DA_PN_MAX || psPnFn->usFn > MT_DT_FN_MAX)
	{
		return MT_OUT_RNG;
	}
	
    UINT8 ucShift = 0; 
    UINT8 ucMask  = 0x01;
    
    if(psPnFn->usPn == 0)
    {
        psDaDt->ucDA1 = 0;
        psDaDt->ucDA2 = 0;
    }
    else
    {
        ucShift = psPnFn->usPn % 8;
        ucShift = ucShift == 0 ? 7 : (ucShift -1);
        psDaDt->ucDA1 = (UINT8)(ucMask << ucShift);
		psDaDt->ucDA2 = (UINT8)((psPnFn->usPn - 1) / 8 + 1);
    }
	
	if(psPnFn->usFn == 0)
	{
        psDaDt->ucDT1 = 0;
        psDaDt->ucDT2 = 0;
    }
    else
    {
        ucShift = psPnFn->usFn % 8;
        ucShift = ucShift == 0 ? 7 : (ucShift -1);
        
        psDaDt->ucDT1 = (UINT8)(ucMask << ucShift);
		psDaDt->ucDT2 = (UINT8)((psPnFn->usFn -1) / 8);
		
    }
	
#ifdef MT_DBG_ON
    printf("eMtTransPnFn_to_DaDt() in sPnFn.usfn = %d sPnFn.usPn = %d\n", psPnFn->usFn, psPnFn->usPn);
    printf("eMtTransPnFn_to_DaDt() out Da1 = %d Da2 = %d Dt1 = %d Dt2 = %d\n", 
		psDaDt->ucDA1,
		psDaDt->ucDA2,
		psDaDt->ucDT1,
		psDaDt->ucDT2);
	
#endif 
	return MT_OK;
}

eMtErr CNxRuler::eMtGetCtrl(eMtAFN eAFN, eMtDir eDir, eMtPRM ePRM, sMtuCtrl *psuCtrl)
{
	
    if(!psuCtrl)
    {
        return MT_NULL;
    }
    
    // �������
    if(eDir != MT_DIR_M2S && eDir != MT_DIR_S2M)
    {
       return  MT_ERR_PARA;
    }

    // ����վ�Ӷ�վ��������
    if(ePRM != MT_PRM_ACTIVE && ePRM != MT_PRM_PASIVE)
    {
        return MT_ERR_PARA;
    }


    psuCtrl->eDir = eDir;
    psuCtrl->ePRM = ePRM;


    switch(eAFN)
    {
        
        case AFN_00_CONF:

             if(ePRM == MT_PRM_PASIVE) //  ȷ�Ϸ��ϱ���ֻ�ܴӶ�վ����
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_OK; 
             }
             else
             {
                return MT_ERR_LOGIC;
             }
            
             if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
                
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;
             }

            break; 
            
        case AFN_01_RSET:
            
             if(eDir == MT_DIR_M2S && ePRM == MT_PRM_ACTIVE)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
                
                psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_RESET; 
             }
             else                    // ����
             {
                return MT_ERR_LOGIC;
             }


            break;
            
        case AFN_02_LINK:
            
             if(eDir == MT_DIR_S2M && ePRM == MT_PRM_ACTIVE)    // ������ֻ�����е�����
             {
                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_LINK; 
             }
             else                   
             {
                  return MT_ERR_LOGIC;
             }

            
        case AFN_03_RELY:

#if 0
            if(eDir == MT_DIR_M2S && ePRM == MT_PRM_ACTIVE)   // ֻ����������  
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
                
                psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_USER; 
             }
             else                     // ����
             {
                 return MT_ERR_LOGIC;
             }
#endif
            break;

            
        case AFN_04_SETP:
             if(eDir == MT_DIR_M2S && ePRM == MT_PRM_ACTIVE)   // ֻ����������  
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
                
                psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_USER; 
             }
             else                     // ����
             {
                 return MT_ERR_LOGIC;
             }

            break;

        case AFN_05_CTRL:
            if(eDir == MT_DIR_M2S && ePRM == MT_PRM_ACTIVE)   // ֻ����������  
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
                
                psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_RESET; 
             }
             else                     // ����
             {
                 return MT_ERR_LOGIC;
             }

            break;
            
        case AFN_06_AUTH:
             if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = FALSE;  //EC
             }


             if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_RESET;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;
            
        case AFN_08_CASC:
             if(eDir == MT_DIR_M2S)   // ����
             {
                
             }
             else                     // ����
             {

             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {


             }
             else                                         //�Ӷ�վ
             {

             }
            break;
            
        case AFN_09_CFIG:
             if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;  //EC
             }

              if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_RESET;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;
            
        case AFN_0A_GETP:
              if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;  //EC
             }

              if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_USER;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;
            

        case AFN_0B_ASKT:
           if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;  //EC
             }

              if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_USER;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;
        case AFN_0C_ASK1:
           if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;  //EC
             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_ASK_1;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;

            
        case AFN_0D_ASK2:
          if(eDir == MT_DIR_M2S)   // ����
             {
                psuCtrl->uDir.sDown.bFcv = FALSE; 
                psuCtrl->uDir.sDown.btFCB = 1; 
                psuCtrl->uDir.sDown.btRcv = 0; 
             }
             else                     // ����
             {
                psuCtrl->uDir.sUp.bAcd = TRUE;  //EC
             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {

                 psuCtrl->uFCode.eFcdPrm1 = FCD_PRM_1_ASK_2;    
             }
             else                                         //�Ӷ�վ
             {
                  psuCtrl->uFCode.eFcdPrm0 = FCD_PRM_0_USER;   
             }
            break;

            
        case AFN_0E_ASK3:
           if(eDir == MT_DIR_M2S)   // ����
             {
                
             }
             else                     // ����
             {

             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {


             }
             else                                         //�Ӷ�վ
             {

             }
            break;
        case AFN_0F_FILE:
           if(eDir == MT_DIR_M2S)   // ����
             {
                
             }
             else                     // ����
             {

             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {


             }
             else                                         //�Ӷ�վ
             {

             }
            break;
        case AFN_10_DATA:
             if(eDir == MT_DIR_M2S)   // ����
             {
                
             }
             else                     // ����
             {

             }

             if(ePRM == MT_PRM_ACTIVE) //����վ
             {


             }
             else                                         //�Ӷ�վ
             {

             }
            break;

        default:
            return MT_ERR_PARA;
            //break;

    }

 
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : bmt_have_ec
 ��������  : ���౨�����Ƿ�Ӧ�ú���ec�ֶ�
 �������  : eMtAFN eAFN 
             eMtDir eDir  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL CNxRuler::bmt_have_ec(eMtAFN eAFN, eMtDir eDir)
{
	if((eAFN == AFN_00_CONF) ||                              // ȷ�Ϸ��ϱ��� �����ж���EC
		(eAFN != AFN_02_LINK && eAFN != AFN_06_AUTH && MT_DIR_S2M == eDir))     // ������·�������������б��Ķ���EC
    {
        return TRUE;
    }
	
	
    return FALSE;

}

/*****************************************************************************
 �� �� ��  : bmt_have_pw
 ��������  : �˱������Ƿ�Ӧ�û���pw�ֶ�
 �������  : eMtAFN eAFN    
             eMtDir eDir 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL CNxRuler::bmt_have_pw(eMtAFN eAFN, eMtDir eDir)
{
    if(((MT_DIR_M2S == eDir) &&
        (AFN_01_RSET == eAFN  ||
		AFN_04_SETP == eAFN  || 
		AFN_05_CTRL == eAFN  ||
		AFN_10_DATA == eAFN  ||
		AFN_0F_FILE == eAFN))        // PW�ֶ�ֻ���������б�����
		|| (AFN_06_AUTH == eAFN))    // ˫�������֤�����ж���PW
    {
        return TRUE;
    }
	
    return FALSE;
}




/*****************************************************************************
 �� �� ��  : bmt_have_tp
 ��������  : �˱���(�� eRole ���͵ı���)���Ƿ�Ӧ�û���tp�ֶ�
 �������  : eMtAFN eAFN    
             eMtDir eDir 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL CNxRuler::bmt_have_tp(eMtAFN eAFN, eMtDir eDir)
{
    if(eAFN == AFN_02_LINK &&  MT_DIR_S2M == eDir)  // ����������������б�����
    {
         return FALSE;
    }

   return TRUE;
}



/*****************************************************************************
 �� �� ��  : bmt_need_con
 ��������  : �˱����Ƿ���Ҫȷ��
 �������  : eMtAFN eAFN  
             eMtDir eDir  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��4��23�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL CNxRuler::bmt_need_con(eMtAFN eAFN, eMtDir eDir)
{
  // �ñ����Ƿ���Ҫ�Ӷ�վȷ��
    if((MT_DIR_M2S == eDir) &&
       (AFN_01_RSET == eAFN || 
        AFN_02_LINK == eAFN || 
        AFN_04_SETP == eAFN ||
        AFN_05_CTRL == eAFN))
    {
       return TRUE;
    }
    else
    {
        return FALSE;
    }

    
}
/*****************************************************************************
 �� �� ��  : emt_trans_tp
 ��������  : ʱ���ǩTPת������
 �������  : eMtTransDir eDir  
             sMtuTp* puTp      
             sMtfTp* pfTp      
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_trans_tp(eMtTransDir eDir, sMtuTp *puTp, sMtfTp *pfTp)
{

    if(!puTp || !pfTp)
    {
        return MT_OK;
    }

    if(MT_TRANS_U2F == eDir)
    {
        pfTp->ucPFC = puTp->ucPFC;
        pfTp->ucPermitDelayMinutes = puTp->ucPermitDelayMinutes;

        // ��ʱ����
        pfTp->sTime.ddBCD_0 = ucmt_get_bcd(puTp->ucDD, 0);
        pfTp->sTime.ddBCD_1 = ucmt_get_bcd(puTp->ucDD, 1);
        pfTp->sTime.hhBCD_0 = ucmt_get_bcd(puTp->ucHH, 0);
        pfTp->sTime.hhBCD_1 = ucmt_get_bcd(puTp->ucHH, 1);
        pfTp->sTime.mmBCD_0 = ucmt_get_bcd(puTp->ucmm, 0);
        pfTp->sTime.mmBCD_1 = ucmt_get_bcd(puTp->ucmm, 1);
        pfTp->sTime.ssBCD_0 = ucmt_get_bcd(puTp->ucss, 0);
        pfTp->sTime.ssBCD_1 = ucmt_get_bcd(puTp->ucss, 1);
    }
    else if(MT_TRANS_F2U == eDir)
    {
        puTp->ucPFC = pfTp->ucPFC;
        puTp->ucPermitDelayMinutes = pfTp->ucPermitDelayMinutes;

        // ��ʱ����
        puTp->ucDD =   (pfTp->sTime.ddBCD_1 * 10) + pfTp->sTime.ddBCD_0;
        puTp->ucHH =   (pfTp->sTime.hhBCD_1 * 10) + pfTp->sTime.hhBCD_0;
        puTp->ucmm =   (pfTp->sTime.mmBCD_1 * 10) + pfTp->sTime.mmBCD_0; 
        puTp->ucss =   (pfTp->sTime.ssBCD_1 * 10) + pfTp->sTime.ssBCD_0;
    }
    else
    {
        return MT_ERR_PARA;
    }
    

   return MT_OK;

}



/*****************************************************************************
 �� �� ��  : emt_get_mtutp
 ��������  : ��õ�ǰ�û���Tpԭʼ����
 �������  : UINT8 ucPFC ����֡������
 �������  : sMtuTp *psuTp 
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emt_get_mtutp(UINT8 ucPFC, sMtuTp *psuTp)
{
    time_t now;
    struct tm* timenow;
    
    if(!psuTp)
    {
        return MT_NULL;
    }

    // ��ȡϵͳ��ǰʱ��
    time(&now);
    timenow = localtime(&now);
    
    psuTp->ucDD = timenow->tm_mday;
    psuTp->ucHH = timenow->tm_hour;
    psuTp->ucmm = timenow->tm_min;
    psuTp->ucss = timenow->tm_sec;

    psuTp->ucPermitDelayMinutes = m_ucPermitDelayMinutes;
    psuTp->ucPFC = ucPFC;

    #ifdef MT_DBG_ON
    printf("emt_get_mtutp() \n");
    printf("DD = %d HH = %d mm = %d ss =%d\n", psuTp->ucDD, psuTp->ucHH, psuTp->ucmm, psuTp->ucss);
    printf("PermitDelayMinutes = %d\n", psuTp->ucPermitDelayMinutes);
    printf("PFC = %d\n", psuTp->ucPFC);
    #endif
    
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : ucmt_get_bcd
 ��������  : ���һ��������ĳһλ��Ӧ��BCD��
             ucPos = 
             0 ����
             1 ʮλ
             2 ��λ
             3 ǧλ
             4 ��λ
             5 
 �������  : UINT32 ulData  
             UINT8 ucPos    
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��1��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 CNxRuler::ucmt_get_bcd(UINT32 ulData, UINT8 ucPos)
{
    //UINT8 ucBCD;
    UINT8 aucBCD[10];
    int i = 0;
    UINT32 ulTmp = 0;

    if(ucPos > 9)
    {
        return 0;
    }

    ulTmp = ulData;
    
    for(i = 0; i < 10; i++)
    {
        aucBCD[i] = ulTmp % 10;
        ulTmp = ulTmp / 10;
    }

    return aucBCD[ucPos];    

}


eMtErr CNxRuler::emtUnPack(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{

#ifdef MT_DBG_ON
    printf("-----------------eMtUnpack()------------------\n");
#endif 

    if(!psUnpack || !pInBuf)
    {
        return MT_NULL;
    }

    eMtErr      eRet       = MT_OK;
    eMtDir      eDir       = MT_DIR_UNKOWN;
    eMtAFN      eAFN       = AFN_MAX;
    eMtCmd      eCmd       = CMD_AFN_0_FN_0_UNKOWN;
    sMtPnFn     sPnFn;
    sMtuSEQ     suSEQ;
    sMtCmdInfors sCmdInfor;
    sMtfComHead *psHead    = NULL;
    sMtDaDt     *pDaDt     = NULL;
    UINT8       *pucTemp   = NULL;
    sMtEC       *psEC      = NULL;
    sMtfTp      *psfTp     = NULL;     // ֡��Tp�ֶ�
    pMtTransFunc pFunc     = NULL;
    UINT16      usUsrdLen  = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16      usLenPack  = 0;
    UINT16      usLenEcPwTp    = 0;    // ������֡��EcPwTp֡��ļ�����Ĳ��ֳ�
    UINT16      usLenUserField = 0;    // �û�����������   
    
    INT32       nLenUserField  = 0;    // ÿ�ν���һ�����������ݵ�Ԫ����û��������ֳ� 
    INT32       i          = 0;
    
    if(usLen < MT_PACK_LEN_MIN)
    {
        #ifdef MT_DBG_ON
        printf("eMtUnpack usLen = %d\n", usLen);
        #endif 
        return MT_ERR_UNCOMP;
    }

    // ��鱨�ĵ���Ч��
    eRet = eMtIsValidPack(pInBuf, usLen);
    if(eRet != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("eMtUnpack eMtIsValidPack() error = %d\n", eRet);
        #endif 
        return eRet;
    }

    // user date field
    psHead = (sMtfComHead *)pInBuf;
    //usLenUserField = (psHead->L2 & 0x3F) | ((psHead->L1 << 6) & 0x3FC0); 
    
    usLenUserField =  ((psHead->L2 << 6) & 0x3FC0 )| (psHead->L1 & 0x003F) ; 
    
    #ifdef MT_DBG_ON
    printf("eMtUnpack() usLenUserField = %d\n", usLenUserField);
    #endif

    // address
    eRet = emt_trans_addr(MT_TRANS_F2U, &(psUnpack->sAddress), &(psHead->A));
    if(eRet != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("eMtUnpack() emt_trans_addr() error = %d\n", eRet);
        #endif
        return eRet;
    }

    // ctrl field
    eRet = emt_trans_ctrl(MT_TRANS_F2U, &(psUnpack->sCtrl), &(psHead->C));
    if(eRet != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("eMtUnpack() emt_trans_ctrl() error = %d\n", eRet);
        #endif
        return eRet;
    }
    
    if(psUnpack->sCtrl.eDir == MT_DIR_S2M && psUnpack->sCtrl.uDir.sUp.bAcd == TRUE)
    {
        psUnpack->bEC = TRUE;
    }
    else
    {
        psUnpack->bEC = FALSE;
    }
    

    // SEQ
    eRet = emt_trans_SEQ(MT_TRANS_F2U, &suSEQ, (sMtfSEQ*)&(psHead->SEQ));
    if(eRet != MT_OK)
    {
        #ifdef MT_DBG_ON
        printf("eMtUnpack() emt_trans_SEQ() error = %d\n", eRet);
        #endif
        return eRet;
    }
    
    psUnpack->ucSEQ = suSEQ.ucSEQ;
    psUnpack->bTP   = suSEQ.bTpv;
    psUnpack->bCon  = suSEQ.bCon;



    // AFN
    psUnpack->eMainCmd = (eMtAFN)psHead->AFN;
    eAFN               = (eMtAFN)psHead->AFN;
    #ifdef MT_DBG_ON
    printf("eMtUnpack() afn = 0x%02X\n", psHead->AFN);
    #endif

    // ������˸������Ӧ�ò������ֳ�
    eDir = psUnpack->sCtrl.eDir;
    usLenEcPwTp = usmt_get_ec_pw_tp_len(eAFN, eDir);
    nLenUserField = (INT32)(usLenUserField - usLenEcPwTp - MT_CANS_LEN);

	pucTemp = (UINT8*)((UINT8*)&(psHead->SEQ) + 1) ;

    while(nLenUserField > 0)
    {
        // ��ʼ��
        usUsrdLen = 0;
        
        // cmd
        
        pDaDt = (sMtDaDt*)pucTemp;
        eMtTransDaDt_to_PnFn(pDaDt, &sPnFn);
        #ifdef MT_DBG_ON
        printf("eMtUnpack() fn = %d pn = %d\n", sPnFn.usFn, sPnFn.usPn);
        #endif
        
        eCmd =(eMtCmd)( (psHead->AFN << 8) | ( sPnFn.usFn & 0xFF));
        #ifdef MT_DBG_ON
        printf("eMtUnpack() eCmd = 0x%04X\n", eCmd);
        #endif   

       
        pucTemp += sizeof(sMtDaDt);
       
        // user data field
       
        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG_ON
            printf("eMtUnpack() eMtGetCmdInfor() error = %d\n", eRet);
            #endif
            return eRet;
        }
        
        pFunc = sCmdInfor.pFunc;
        if(pFunc != NULL)
        {
		    if(CMD_AFN_0_FN_3_ONE_BY_ONE == eCmd)
			{
                 usUsrdLen = nLenUserField - sizeof(sMtDaDt);;

			}
            eRet = pFunc(MT_TRANS_F2U, (void*)&(psUnpack->sSub[i].uAppData), (void*)pucTemp, &usUsrdLen);
            if(eRet != MT_OK)
            {
                #ifdef MT_DBG_ON
                printf("eMtUnpack() transfunc() error = %d\n", eRet);
                #endif
                return eRet;
            }

            pucTemp += usUsrdLen;
        }
		
        // �������
        
        psUnpack->ucSubNum++;
        psUnpack->sSub[i].eSubCmd = eCmd;
        psUnpack->sSub[i].usPN = sPnFn.usPn;
        psUnpack->sSub[i].usLen = usUsrdLen;

        // ���ȼ���
        nLenUserField -= sizeof(sMtDaDt);
        nLenUserField -= usUsrdLen;

        i++;
       
        
    }
    
    // �����EC
    if(bmt_have_ec(eAFN, eDir) == TRUE)
    {
        printf("unpack ec()\n");
        psUnpack->bEC = TRUE;
        psEC = (sMtEC *)pucTemp;
        psUnpack->sEC.ucEC1 = psEC->ucEC1;
        psUnpack->sEC.ucEC2 = psEC->ucEC2;

        pucTemp += sizeof(sMtEC);
    }
    
    // �����pw
    if(TRUE == bmt_have_pw(eAFN, eDir))
    {
        psUnpack->bPW = TRUE;
        memcpy((void*)(psUnpack->aucPW), (void*)pucTemp, MT_PW_LEN);
        #ifdef MT_DBG_ON
        int i;
        printf("eMtUnpack pw:");
        for(i = 0; i < MT_PW_LEN; i++)
        {
            printf("%d", (UINT8)psUnpack->aucPW[i]);
        }
        printf("\n");
        #endif

        pucTemp += MT_PW_LEN;
    }


    // �����TP
    if(TRUE == psUnpack->bTP)
    {
        eRet = emt_trans_tp(MT_TRANS_F2U, (sMtuTp*)&(psUnpack->sTP), (sMtfTp*)pucTemp);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG_ON
            printf("eMtUnpack() emt_trans_tp() error = %d\n", eRet);
            #endif
            return eRet;
        }

        //pucTemp += sizeof(sMtfTp);
    }
#ifdef MT_DBG_ON
    else
    {
        printf("unpack have none tp\n");
    }
#endif
    
    
    


#ifdef MT_DBG_ON
    printf("-------eMtUnpack()------------------\n");
#endif 
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : usmt_get_ec_pw_tp_len
 ��������  : ����һ������������ �� ���ĵĴ��ͷ��򣬼�������������ֳ�
 �������  : eMtAFN eAFN  
             eMtDir eDir  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��4��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT16 CNxRuler::usmt_get_ec_pw_tp_len(eMtAFN eAFN, eMtDir eDir)
{

    UINT16 usLenEcPwTp = 0;
    BOOL   bEc = FALSE;
    BOOL   bPw = FALSE;
    BOOL   bTp = FALSE;
	
    bEc = bmt_have_ec(eAFN, eDir);
    bPw = bmt_have_pw(eAFN, eDir);
    bTp = bmt_have_tp(eAFN, eDir);
	
    if(bEc == TRUE)
    {
        usLenEcPwTp += sizeof(sMtEC);
    }
	
    
    if(bPw == TRUE)
    {
        usLenEcPwTp += MT_PW_LEN;
    }
	
	
    if(bTp == TRUE)
    {
        usLenEcPwTp += sizeof(sMtfTp);
    }
	
    
    return usLenEcPwTp;
}


/*****************************************************************************
 �� �� ��  : eMtTransDaDt_to_PnFn
 ��������  : ��������Ϣ��Ԫ��ʶ��DaDt�ṹת��ΪPnFn�ṹ
 �������  : sMtDaDt *psDaDt  
             sMtPnFn *psPnFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::eMtTransDaDt_to_PnFn(sMtDaDt *psDaDt, sMtPnFn *psPnFn)
{
	if(!psPnFn || !psDaDt)
	{
		return MT_NULL;
	}

	if(psDaDt->ucDT2 > 30)
	{
		return MT_OUT_RNG;
	}

    UINT8 ucShift = 0;

    if(psDaDt->ucDA1 == 0 && psDaDt->ucDA2 == 0)
    {
        psPnFn->usPn = 0;
    }
    else
    {
        switch(psDaDt->ucDA1)
        {
            case 0x01:
                ucShift = 1;
                break;
                
            case 0x02:
                ucShift = 2; 
                break;
                
            case 0x04:
                ucShift = 3;
                break;
                
            case 0x08:
                ucShift = 4; 
                break;

            case 0x10:
                ucShift = 5;
                break;
                
            case 0x20:
                ucShift = 6; 
                break;
                
            case 0x40:
                ucShift = 7;
                break;
                
            case 0x80:
                ucShift = 8; 
                break;

            default:
                  return MT_ERR_PARA;
                  //break;

        }
        
       psPnFn->usPn = ((psDaDt->ucDA2 - 1) * 8 + ucShift);
    }


    if(psDaDt->ucDT1 == 0 && psDaDt->ucDT2 == 0)
    {
        psPnFn->usFn = 0;
    }
    else
    {
         switch(psDaDt->ucDT1)
        {
            case 0x01:
                ucShift = 1;
                break;
                
            case 0x02:
                ucShift = 2; 
                break;
                
            case 0x04:
                ucShift = 3;
                break;
                
            case 0x08:
                ucShift = 4; 
                break;

            case 0x10:
                ucShift = 5;
                break;
                
            case 0x20:
                ucShift = 6; 
                break;
                
            case 0x40:
                ucShift = 7;
                break;
                
            case 0x80:
                ucShift = 8; 
                break;

            default:
                  return MT_ERR_PARA;
                  //break;

        }

        psPnFn->usFn = (psDaDt->ucDT2 * 8 + ucShift);

    }
    
    #ifdef MT_DBG_ON
    printf("eMtTransDaDt_to_PnFn() in sPnFn.usfn = %d sPnFn.usPn = %d\n", psPnFn->usFn, psPnFn->usPn);
    printf("eMtTransDaDt_to_PnFn() out Da1 = %d Da2 = %d Dt1 = %d Dt2 = %d\n", 
            psDaDt->ucDA1,
            psDaDt->ucDA2,
            psDaDt->ucDT1,
            psDaDt->ucDT2);
    #endif 
	return MT_OK;
}


void CNxRuler::add( UINT8 ucFn )
{
	
}


// Э���ʼ��
eMtErr CNxRuler::emt_init( sMtInit *psInit )
{
	if(!psInit)
	{
		return MT_NULL;
	}
	
	m_role = psInit->eRole ;
	//m_address = psInit->sAdress;
	m_ucPermitDelayMinutes = psInit->ucPermitDelayMinutes;
	
	//initMapCmdInfor();
	m_bInit = TRUE;
	
	return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtPackLite
 ��������  : ������������������û������ĵ�����
 �������  : sMtDaDt *psDaDt  
             sMtPnFn *psPnFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��12��17��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr CNxRuler::emtPackLite( smtPackLite *psPackLite, UINT16 *pusLen, UINT8 *pOutBuf )
{
	if(!psPackLite || !pusLen || !pOutBuf)
	{
		return MT_NULL;
	}

	char *pPara = (char *)malloc (MT_PACK_LEN_MAX);
	if(!pPara)
	{
		return MT_ERR_IO;
	}

	if(m_bInit == FALSE)
	{
		return MT_ERR_INIT;
	}
	
	smtPack *psPack = (smtPack *)pPara;
	sMtuCtrl     sCtrl;
	eMtAFN eAfn;
	eMtDir eDir;
	eMtPRM ePRM;
	eMtErr eRet;
	sMtuSEQ suSEQ;
	UINT8 ucSEQ = 0;

	eDir = (m_role == MT_ROLE_MASTER) ? MT_DIR_M2S : MT_DIR_S2M;
	ePRM = (psPackLite->bActive == TRUE) ? MT_PRM_ACTIVE : MT_PRM_PASIVE;
	eAfn = psPackLite->eMainCmd;
	// ���� emtPack()����
	psPack->sAddress = psPackLite->sAddress;
	psPack->eMainCmd = eAfn;
	

	eRet = eMtGetCtrl(eAfn, eDir, ePRM, &sCtrl);
	if(eRet != MT_OK)
	{
		return MT_ERR_CTRL;
	}
	psPack->sCtrl = sCtrl;
	//psPack->ucPFC = psPackLite->ucPFC;


	suSEQ.bCon = bmt_need_con(eAfn,eDir);
	suSEQ.bTpv = bmt_have_tp(eAfn,eDir);
	suSEQ.ePos = MT_POS_SIGLE;
	suSEQ.ucSEQ = m_ucPFC & 0x0F;
	eRet = emt_trans_SEQ(MT_TRANS_U2F,&suSEQ,(sMtfSEQ*)&ucSEQ);
	if(eRet != MT_OK)
	{
		return MT_ERR_SEQ;
	}

	//psPack->ucSEQ = ucSEQ;
	
	psPack->bCon = suSEQ.bCon;
	psPack->bEC = bmt_have_ec(eAfn,eDir);
	psPack->bPW = bmt_have_pw(eAfn,eDir);
	psPack->bTP = suSEQ.bTpv;

	// ���� emtPack()
	psPack->sEC = psPackLite->sEC;
	psPack->sTP = psPackLite->sTP;
	
	m_EC = psPackLite->sEC;
	


	for(int i = 0; i < 16; i++)
	{
		psPack->aucPW[i] = psPackLite->aucPW[i];
	}
	
	psPack->ucSubNum = psPackLite->ucSubNum;
	
	memcpy(psPack->sSub, psPackLite->sSub, psPack->ucSubNum * sizeof(smtSub));
	
	

	eRet = emtPack(psPack,pusLen,pOutBuf);
	if(eRet != MT_OK)
	{
		return eRet;
	}


	
	if(pPara != NULL)
	{
		free(pPara);
		pPara = NULL;
	}
	return MT_OK;
}

char * CNxRuler::getErrMessage( eMtErr err )
{
	char * pRet;
	switch(err)
	{
	case MT_OK:             // �޴���   
		pRet = "MT_OK";
		break;
	case MT_NULL:           // ָ��Ϊ��    
        pRet = "MT_NULL";
		break;
	case MT_OUT_RNG:        // ����Խ��  
		pRet = "MT_OUT_RNG";
		break;
	case MT_NONE:           // ������:û���ҵ�  
		pRet = "MT_NONE";
		break;
	case MT_ERR_IO:         // IO����    
		pRet = "MT_ERR_IO";
		break;
	case MT_ERR_RES:        // ��Դ����
		pRet = "MT_ERR_RES";
		break;
	case MT_ERR_INIT:       // û�г�ʼ��
		pRet = "MT_ERR_INIT";
		break;
	case MT_ERR_PARA:       // ��������
		pRet = "MT_ERR_PARA";
		break;
	case MT_ERR_FN:         // ָ��Afn �в�֧�ֵ� Fn
		pRet = "MT_ERR_FN";
		break;
	case MT_ERR_PN:         // ָ��Afn Fn �в�֧�ֵ� Pn
		pRet = "MT_ERR_PN";
		break;
	case MT_ERR_ADDR:       // ��Ч��ַ
		pRet = "MT_ERR_ADDR";
		break;
	case MT_ERR_CTRL:       // ��������� 
		pRet = "MT_ERR_CTRL";
		break;
	case MT_ERR_SEQ:        // SEQ�����
		pRet = "MT_ERR_SEQ";
		break;
	case MT_ERR_SEQ2CS:     // 
		pRet = "MT_ERR_SEQ2CS";
		break;
	case MT_ERR_AFN:        // AFN ����
		pRet = "MT_ERR_AFN";
		break;
	case MT_ERR_UNCOMP:     // ��������Э���
		pRet = "MT_ERR_UNCOMP";
		break;
	case MT_ERR_0x68:       // ����ı�����ʼ
		pRet = "MT_ERR_0x68";
		break;
	case MT_ERR_PROTO:      // �����Э���ʶ
		pRet = "MT_ERR_PROTO";
		break;
	case MT_ERR_CS:         // ����ļ���
		pRet = "MT_ERR_CS";
		break;
	case MT_ERR_0x16:       // ����Ľ�β��
		pRet = "MT_ERR_0x16";
		break;
	case MT_ERR_LOGIC:      // ����Ĵ����߼�
		pRet = "MT_ERR_LOGIC";
		break;
	case MT_ERR_PACK:       // ����һ����Ч�İ� 
		pRet = "MT_ERR_PACK";
	break;
	default:
		pRet = "unkown";
		break;

	}

	return pRet;
}

CString CNxRuler::BufferToHex( char* pBuf, UINT16 usLen )
{
	CString strOut;
	CString strTmp;
	int len;
	len = (int)usLen;
	int i;
	for (i = 0; i < len; i++)
	{
		strTmp.Format("%02X ",(UINT8)pBuf[i]);
		strOut+= strTmp;
		
	}

	return strOut;
	
}



/************************************************************************
�������ƣ�CStringToHexBuffer
�������ܣ����ַ��� ת����16���Ƶ�char[],������䳤��
���������strText
���������pOutBuf
		  pLen
����ֵ��  BOOL ת���ɹ� true ���� false
����˵����

************************************************************************/
BOOL CNxRuler::CStringToHexBuffer( CString strText, char *pOutBuf, UINT16 *pLen )
{
	if(!pOutBuf || !pLen)
	{
		return FALSE;
	}

	// ȥ���ո�
	strText.Replace(" ",NULL);
	int StrLen     = 0;
	int BufLen     = 0;
	int strLenLeft = 0;
	int i          = 0;
	char *pBuf     = NULL;
	CString strHex, strTmp;

	StrLen = strText.GetLength();

	if(StrLen%2 != 0)
	{
		return FALSE;
	}
	
	BufLen = StrLen/2;
	strLenLeft = StrLen;

	for (i = 0; i < BufLen; i++)
	{
		strHex = strText.Left(2);
		pOutBuf[i] = strtol(strHex, NULL, 16);
		strLenLeft -= 2;
		strText = strText.Right(strLenLeft);

	}

	*pLen = BufLen;


	return TRUE;	
}


CString CNxRuler::GetAfnName( eMtAFN eAfn )
{
	CString strName;
	switch(eAfn)
	{
	case AFN_00_CONF:
		strName = "AFN_00_CONF ȷ�Ϸ���";
		break;
	case AFN_01_RSET:
		strName = "AFN_01_RSET ��λ";
		break;
	case AFN_02_LINK:
		strName = "AFN_02_LINK �ӿڼ��";
		break;
	case AFN_03_RELY:
		strName = "AFN_03_RELY �м�վ����";
		break;
	case AFN_04_SETP:
		strName = "AFN_04_SETP ���ò���";
		break;
	case AFN_05_CTRL:
		strName = "AFN_05_CTRL ��������";
		break;
	case AFN_06_AUTH:
		strName = "AFN_06_AUTH �����֤";
		break;
	case AFN_08_CASC:
		strName = "AFN_08_CASC ���󱻼����ն������ϱ�";
		break;
	case AFN_09_CFIG:
		strName = "AFN_09_CFIG �����ն�����";
		break;
	case AFN_0A_GETP:
		strName = "AFN_0A_GETP ��ѯ����";
		break;
	case AFN_0B_ASKT:
		strName = "AFN_0B_ASKT ������������";
		break;
	case AFN_0C_ASK1:
		strName = "AFN_0C_ASK1 ����1������ ʵʱ����";
		break;
	case AFN_0D_ASK2:
		strName = "AFN_0D_ASK2 ����2������ ��ʷ����";
		break;
	case AFN_0E_ASK3:
		strName = "AFN_0E_ASK3 ����3������ �¼�����";
		break;
	case AFN_0F_FILE:
		strName = "AFN_0F_FILE �ļ�����";
		break;
	case AFN_10_DATA:
		strName = "AFN_10_DATA ����ת��";
		break;
	default:
		break;
	}

	return strName;
}


/************************************************************************
��ø���������͵�PRM                                              
BOOL bAuto  �Ƿ������ϱ�
                                      
************************************************************************/
eMtPRM CNxRuler::getPrm( eMtDir eDir, eMtAFN eAfn, BOOL bAuto )
{
	
	eMtPRM ePrm;
	
	switch(eAfn)
	{
	case AFN_00_CONF:
		ePrm = MT_PRM_PASIVE;
		break;
	
	case AFN_01_RSET:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_UNKWON;
		}
		else
		{
		  ePrm = MT_PRM_ACTIVE;
		}
	
		break;
	case AFN_02_LINK:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_ACTIVE;
		}
		else
		{
			ePrm = MT_PRM_UNKWON;
		}
		
		break;
	case AFN_03_RELY:
		ePrm = MT_PRM_PASIVE;
		break;
	case AFN_04_SETP:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_UNKWON;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;
	case AFN_05_CTRL:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_UNKWON;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;
	case AFN_06_AUTH:  // ���������˫�򣬲�ͬ����������Ͳ�ͬ����Ҫ�����ڲ�д��

		ePrm = MT_PRM_UNKWON;
		break;
	case AFN_09_CFIG:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_UNKWON;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;

	case AFN_0A_GETP:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_PASIVE;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;


	case AFN_0B_ASKT:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_PASIVE;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;


	case AFN_0C_ASK1:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_PASIVE;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;

	case AFN_0D_ASK2:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_PASIVE;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;

	case AFN_0E_ASK3:
		if (eDir == MT_DIR_S2M)
		{
			ePrm = MT_PRM_PASIVE;
		}
		else
		{
			ePrm = MT_PRM_ACTIVE;
		}
		break;


	default:
			ePrm = MT_PRM_UNKWON;
		break;
	}



	if (eDir == MT_DIR_S2M && bAuto)
	{
	}


	return ePrm;
		
}

void CNxRuler::setEC( sMtEC sEC )
{
	m_EC = sEC;
}


void CNxRuler::setPw( CString strPw )
{
	CString str = "0000000000000000";
	CString strPwLast;
	int lenInput = 0;
	lenInput = strPw.GetLength();
	if (lenInput > 16)
	{
		lenInput = 16;
		strPwLast = strPw.Left(16);
	}
	else
	{
		strPwLast = str.Left(16 - lenInput) + strPw;
	}
	
	char *pw = strPwLast.GetBuffer(16);
	memcpy(m_aucPw, pw, 16);
	strPwLast.ReleaseBuffer();
}




/*
������������������Ϣ���ڶ��ַ�ʽ��ԭ����map�о���
*/
void CNxRuler::AddInforVector( eMtCmd eCmd, eMtDir eDir, eMtPn ePn, pNxTransFunc pFunc, CString strName )
{


	sMtCmdInfors sCmdInfor;
	sCmdInfor.eCmd    = eCmd;
	sCmdInfor.eDir    = eDir;
	sCmdInfor.ePn     = ePn;
	sCmdInfor.pFunc   = pFunc;
	sCmdInfor.strName = strName;	

	m_vCmdInfor.push_back(sCmdInfor);
	
}


/*****************************************************************************
 �� �� ��  : bMtGetDoubleSign
 ��������  : ���һ��double �ķ���λ
 �������  : double dVal  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
#if 0
int bMtGetDoubleSign( double dVal )
{
	uMtDoubleFmt  doubleFmt;
	doubleFmt.v = dVal;
	
	return doubleFmt.s.sign;
}

/*****************************************************************************
 �� �� ��  : vMtSetDoubleSign
 ��������  : ���ø������ķ���λ
 �������  : int sign   >= 0 ʱ������Ϊ������ < 0ʱ����Ϊ����    
 �������  : double *pdVal  
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
void vMtSetDoubleSign( double *pdVal, int sign )
{
	uMtDoubleFmt  *pdoubleFmt;
	pdoubleFmt = (uMtDoubleFmt*)pdVal;
	
	if(sign > 0)
	{
		pdoubleFmt->s.sign = 0;
	}
	else
	{
		pdoubleFmt->s.sign = 1;
	}
}
#endif
/*****************************************************************************
 �� �� ��  : bMtTrans_fmtsMillion_to_double
 ��������  : �� sMtFmtsMillion ת��Ϊdouble
 �������  : sMtFmtsMillion *psMtFmtsMillion                           
 �������  : double *pdValue    
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 ����˵��  : double  : 1bit������λ�� 11bits��ָ��λ�� 52bits��β��λ�� 
 			 2^52 = 4503599627370496
 �޸���ʷ      :
  1.��    ��   : 2013��5��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bMtTrans_fmtsMillion_to_double( sMtFmtsMillion *psMtFmtsMillion, double *pdValue )
{
	int  valid   = 0;      // ��Чλ
	double  exp  = 0.0;    // ָ��λ
	int  sign    = 0;      // ����λ
	int  i       = 0;
	double  dRet = 0.0;
	UINT8 bcd[7] = {0};
	
	bcd[0] = (UINT8) psMtFmtsMillion->BCD_0;
	bcd[1] = (UINT8) psMtFmtsMillion->BCD_1;
	bcd[2] = (UINT8) psMtFmtsMillion->BCD_2;
	bcd[3] = (UINT8) psMtFmtsMillion->BCD_3;
	bcd[4] = (UINT8) psMtFmtsMillion->BCD_4;
	bcd[5] = (UINT8) psMtFmtsMillion->BCD_5;
	bcd[6] = (UINT8) psMtFmtsMillion->BCD_6;
	
	for(i = 0; i < 7; i++)
	{
		if(bcd[i] > 9)
		{
			return FALSE;
		}
	}
	
	for(i = 0; i < 7; i++)
	{
		valid += bcd[i]*nMtPow(i);
	}
	
	
	sign = psMtFmtsMillion->S == 0 ? 1 : -1;
	
	if(psMtFmtsMillion->G3 == 0)
	{
		if(psMtFmtsMillion->G2 == 0 && psMtFmtsMillion->G1 == 0)
		{
			exp = 4.0;
		}
		
		if(psMtFmtsMillion->G2 == 0 && psMtFmtsMillion->G1 == 1)
		{
			exp = 3.0;
		}
		
		if(psMtFmtsMillion->G2 == 1 && psMtFmtsMillion->G1 == 0)
		{
			exp = 2.0;
		}
		
		if(psMtFmtsMillion->G2 == 1 && psMtFmtsMillion->G1 == 1)
		{
			exp = 1.0;
		}
		
	}
	else
	{
		if(psMtFmtsMillion->G2 == 0 && psMtFmtsMillion->G1 == 0)
		{
			exp = 0.0;
		}
		
		if(psMtFmtsMillion->G2 == 0 && psMtFmtsMillion->G1 == 1)
		{
			exp = -1.0;
		}
		
		if(psMtFmtsMillion->G2 == 1 && psMtFmtsMillion->G1 == 0)
		{
			exp = -2.0;
		}
		
		if(psMtFmtsMillion->G2 == 1 && psMtFmtsMillion->G1 == 1)
		{
			exp = -3.0;
		}
		
	}
	
	
	dRet = sign * valid * pow(10.0,exp);
	
	*pdValue = dRet;
	
	return TRUE;
	
}


/*****************************************************************************
 �� �� ��  : eMtTrans_double_to_fmtsMillion
 ��������  : ��doubleת��ΪsMillon�ṹ
 �������  : double dValue                    
             int exp  4 3 2 1 0 -1 -2 -3                         
             
 �������  : sMtFmtsMillion *psMtFmtsMillion  
 �� �� ֵ  : eMtErr
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr eMtTrans_double_to_fmtsMillion( double dValue, int nExp, sMtFmtsMillion *psMtFmtsMillion )
{
	if(!psMtFmtsMillion)
	{
		return MT_NULL;
	}

	double zhengshu = 0.0;
	int    sign     = 0;   // ����λ
	const  int index = 6;
	
	switch(nExp)
	{

		case 4:
			{
				if(dValue > 99999990000.0 || dValue < -99999990000.0)
				{
					return MT_OUT_RNG;
				}

				modf(dValue/10000, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 1;
				psMtFmtsMillion->G2 = 0;
				psMtFmtsMillion->G3 = 0;	
			}
			break;

		case 3:// ֻ���ĵ�ǧλ����λ, ʮλ ��λ��С��������
			{
				
				if(dValue > 9999999000.0 || dValue < -9999999000.0)
				{
					return MT_OUT_RNG;
				}
				
				modf(dValue/1000, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);
				
				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 1;
				psMtFmtsMillion->G2 = 0;
				psMtFmtsMillion->G3 = 0;	
			}
			break;
		case 2:// // ֻ���ĵ���λ, ʮλ ��λ��С��������
			{
				if(dValue > 999999900.0 || dValue < -999999900.0)
				{
					return MT_OUT_RNG;
				}

				modf(dValue/100, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);

				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);
				
				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 0;
				psMtFmtsMillion->G2 = 1;
				psMtFmtsMillion->G3 = 0;	
			}
			break;
		case 1: // ֻ���ĵ�ʮλ ��λ��С��������
			{
				if(dValue > 99999990.0 || dValue < -99999990.0)
				{
					return MT_OUT_RNG;
				}

				modf(dValue/10, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 1;
				psMtFmtsMillion->G2 = 1;
				psMtFmtsMillion->G3 = 0;	
			}
			break;
		case 0:	  //ֻ���ĵ���λ	
			{
				if(dValue > 9999999.0 || dValue < -9999999.0)
				{
					return MT_OUT_RNG;
				}
				
				modf(dValue, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 0;
				psMtFmtsMillion->G2 = 0;
				psMtFmtsMillion->G3 = 1;	
			}
			break;
			
		case -1: // ֻ���ĵ�С�����һλ, ��ߵ����ݽ�����
			   {
				if(dValue > 999999.9 || dValue < -999999.9)
				{
					return MT_OUT_RNG;
				}

				modf(dValue*10, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 1;
				psMtFmtsMillion->G2 = 0;
				psMtFmtsMillion->G3 = 1;	
			}
			break;
		case -2: // ֻ���ĵ�С�����2λ, ��ߵ����ݽ�����
			{
				if(dValue > 99999.99 || dValue < -99999.99)
				{
					return MT_OUT_RNG;
				}

				modf(dValue*100, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 0;
				psMtFmtsMillion->G2 = 1;
				psMtFmtsMillion->G3 = 1;	
			}
			break;
		case -3:// ֻ���ĵ�С�����3λ, ��ߵ����ݽ�����
			{
				if(dValue > 9999.999 || dValue < -9999.999)
				{
					return MT_OUT_RNG;
				}

				modf(dValue*1000, &zhengshu);
				sign = bMtGetDoubleSign(zhengshu);
				vMtSetDoubleSign(&zhengshu, 1);
				
				char buf[8] = {0};
				sprintf(buf, "%07.0lf\n", zhengshu, 7);

				//����ṹ
				psMtFmtsMillion->BCD_0 = buf[index - 0] - '0';
				psMtFmtsMillion->BCD_1 = buf[index - 1] - '0';
				psMtFmtsMillion->BCD_2 = buf[index - 2] - '0';
				psMtFmtsMillion->BCD_3 = buf[index - 3] - '0';		
				psMtFmtsMillion->BCD_4 = buf[index - 4] - '0';
				psMtFmtsMillion->BCD_5 = buf[index - 5] - '0';
				psMtFmtsMillion->BCD_6 = buf[index - 6] - '0';

				psMtFmtsMillion->S  = sign;
				psMtFmtsMillion->G1 = 1;
				psMtFmtsMillion->G2 = 1;
				psMtFmtsMillion->G3 = 1;	
			}
			break;
		default:
			break;


	}



	return MT_OK;
}

#if 0
/*****************************************************************************
 �� �� ��  : nMtPow
 ��������  : ��10��N�η�
 �������  : UINT8 exp  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int nMtPow( UINT8 exp )
{
	if(exp > 10)
	{
		return -1;
	}
	
	if(exp == 0)
	{
		return 1;
	}
	
	return 10 * nMtPow(exp -1);
	
}

#endif


/*****************************************************************************
 �� �� ��  : emtTrans_CfgNotElecValue
 ��������  : �ǵ������������ݽṹת������  (AFN04 F33)
 �������  : eMtTransDir eDir  
             void *psUser      
             void *psFrame     
             UINT16 *pusfLen   
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_CfgNotElecValue(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen)
{

	if(!psUser || !psFrame || !pusfLen)
	{
		return MT_NULL;
	}

	sMtCfgNotElec    *psMtCfgNotElec_u;
	sMtCfgNotElec_f  *psMtCfgNotElec_f;
	
	psMtCfgNotElec_u = (sMtCfgNotElec  *)psUser;
	psMtCfgNotElec_f = (sMtCfgNotElec_f*)psFrame;
	eMtErr eRet      = MT_OK;
	int    nExp      = 0;   // ����   4 3 2 1 0 -1 -2 -3
	BOOL   bTrans    = FALSE;

	if(MT_TRANS_U2F == eDir)
	{

		switch(psMtCfgNotElec_u->eType)
		{
			case MT_NELEC_TEMP:
			case MT_NELEC_FLOW:
			case MT_NELEC_FLOW_V:
			case MT_NELEC_PRESS:
			case MT_NELEC_HUMID:
			case MT_NELEC_ILLUM:
			case MT_NELEC_ROTATE:
				nExp = -2;      // ���������ʵ���������ϸ����
				break;

			default:
				return MT_NONE;
				//break;

		}

		// type
		psMtCfgNotElec_f->ucType = (UINT8)psMtCfgNotElec_u->eType;
		eRet = eMtTrans_double_to_fmtsMillion(psMtCfgNotElec_u->dMin, nExp, &(psMtCfgNotElec_f->sMin));
		if(eRet != MT_OK)
		{
			return eRet;
		}
		eRet = eMtTrans_double_to_fmtsMillion(psMtCfgNotElec_u->dMax, nExp, &(psMtCfgNotElec_f->sMax));
		if(eRet != MT_OK)
		{
			return eRet;
		}
		

	}
	else if(MT_TRANS_F2U == eDir)
	{
		psMtCfgNotElec_u->eType = (eMtNotElec)(psMtCfgNotElec_f->ucType);
		
		bTrans = bMtTrans_fmtsMillion_to_double(&(psMtCfgNotElec_f->sMin), &(psMtCfgNotElec_u->dMin));
		if(bTrans != TRUE)
		{
			return MT_ERR_PARA;
		}
		bTrans = bMtTrans_fmtsMillion_to_double(&(psMtCfgNotElec_f->sMax), &(psMtCfgNotElec_u->dMax));
		if(bTrans != TRUE)
		{
			return MT_ERR_PARA;
		}

	}
	
	*pusfLen = sizeof(sMtCfgNotElec_f);
	return MT_OK;
}




/*****************************************************************************
 �� �� ��  : emtTrans_NotElecValue
 ��������  : �ǵ��������ݽṹת������  (AFN05 F90)
 �������  : eMtTransDir eDir  
             void *psUser      
             void *psFrame     
             UINT16 *pusfLen   
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_NotElecValue(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen)
{
	if(!psUser || !psFrame || !pusfLen)
	{
		//DEBUG("MT_NULL");
		return MT_NULL;
	}

	sMtNotElec    *psMtNotElec_u;
	sMtNotElec_f  *psMtNotElec_f;
	
	psMtNotElec_u = (sMtNotElec  *)psUser;
	psMtNotElec_f = (sMtNotElec_f*)psFrame;
	eMtErr eRet      = MT_OK;
	int    nExp      = 0;   // ����   4 3 2 1 0 -1 -2 -3
	BOOL   bTrans    = FALSE;

	if(MT_TRANS_U2F == eDir)
	{

		switch(psMtNotElec_u->eType)
		{
			case MT_NELEC_TEMP:
			case MT_NELEC_FLOW:
			case MT_NELEC_FLOW_V:
			case MT_NELEC_PRESS:
			case MT_NELEC_HUMID:
			case MT_NELEC_ILLUM:
			case MT_NELEC_ROTATE:
				nExp = -2;      // ���������ʵ���������ϸ����
				break;

			default:
				//DEBUG("MT_NELEC_UNKOWN");
				return MT_NONE;
				//break;

		}

		// type
		psMtNotElec_f->ucType = (UINT8)psMtNotElec_u->eType;
		eRet = eMtTrans_double_to_fmtsMillion(psMtNotElec_u->dValue, nExp, &(psMtNotElec_f->sValue));
		if(eRet != MT_OK)
		{
			//DEBUG("eMtTrans_double_to_fmtsMillion() error = %d", eRet );
			return eRet;
		}

	}
	else if(MT_TRANS_F2U == eDir)
	{
		psMtNotElec_u->eType = (eMtNotElec)(psMtNotElec_f->ucType);
		
		bTrans = bMtTrans_fmtsMillion_to_double(&(psMtNotElec_f->sValue), &(psMtNotElec_u->dValue));
		if(bTrans != TRUE)
		{
			//DEBUG("bMtTrans_fmtsMillion_to_double() error = %d", eRet );
			return MT_ERR_PARA;
		}
	}
	
	*pusfLen = sizeof(sMtNotElec_f);
	return MT_OK;
}






/*****************************************************************************
 �� �� ��  : emtTrans_OneByOne
 ��������  : ���ȷ�Ϸ���ת������
 �������  : eMtTransDir eDir  
             void *psUser      
             void *psFrame     
             UINT16 *pusfLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��6��9��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_OneByOne(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen)
{
	if(!psFrame || !psUser || !pusfLen)
	{
		return MT_NULL;
	}

	sMtOneByOne_f *psOneByOne_f = (sMtOneByOne_f *)psFrame;
	sMtOnebyOne   *psOneByOne_u = (sMtOnebyOne   *)psUser;
	int i = 0;
	sMtPnFn sPnFn = {0};
	eMtErr  eRet  = MT_OK;
	int     nNum  = 0;   // ��
	
	if(MT_TRANS_F2U == eDir)
	// ֡��תΪ�û���
	{
		// ����ʱ����Ӧ�ò����ݳ���
		nNum = (int)*pusfLen;
		
		nNum -= sizeof(UINT8);
		nNum /= sizeof(sMtOne_f); // ���㺬��ȷ�Ϸ��ϸ���

		if(nNum > MT_DT_FN_MAX)
		{
		
			return MT_OUT_RNG;
		}

		psOneByOne_u->eAFN = (eMtAFN)psOneByOne_f->ucAFN;
		psOneByOne_u->ucNum = nNum;
		for(i = 0; i < nNum; i++)
		{
			psOneByOne_u->sOne[i].bOk = psOneByOne_f->sOne[i].ucErr == 0 ? TRUE : FALSE;

			eRet = eMtTransDaDt_to_PnFn_g(&(psOneByOne_f->sOne[i].sDaDt), &sPnFn);
			if(eRet != MT_OK)
			{
			
				return eRet;
			}
			
			psOneByOne_u->sOne[i].eCmd = (eMtCmd) (psOneByOne_u->eAFN << 8 | sPnFn.usFn);
			psOneByOne_u->sOne[i].usPn = (UINT8)sPnFn.usPn;
		}

	}
	else 
	// �û���תΪ֡��
	{
		psOneByOne_f->ucAFN  = (UINT8)psOneByOne_u->eAFN;
		for(i = 0; i < psOneByOne_u->ucNum; i++)
		{
			sPnFn.usFn = (UINT8)psOneByOne_u->sOne[i].eCmd;
			sPnFn.usPn = psOneByOne_u->sOne[i].usPn;
			eRet = eMtTransPnFn_to_DaDt_g(&sPnFn, &(psOneByOne_f->sOne[i].sDaDt));
			if(eRet != MT_OK)
			{
			
				return eRet;
			}

			// right or error
			psOneByOne_f->sOne[i].ucErr = psOneByOne_u->sOne[i].bOk == TRUE ? 0 : 1;
			
		}
	}

	// ������֡����ֽڳ���
	*pusfLen = sizeof(UINT8) + sizeof(sMtOne_f) * psOneByOne_u->ucNum;
	
	return MT_OK;
}

#endif