// Qgdw3761api.cpp: implementation of the CQgdw3761api class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NxMaster.h"
#include "Qgdw3761api.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/******************************************************************************

            ��Ȩ���� (C), 2001-2015, �������Ժͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : qgdw_3761_api.c
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��7��29��
  ����޸�   :
  ��������   : Q/GDW 376.1 Э�����api ʵ��Դ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��7��29��
    ��    ��   : liming
    �޸�����   : �����ļ�

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


// ���Կ���
#define MT_DBG
 #undef  MT_DBG           // ��ʽ��ʱȥ������ע��

#ifdef MT_DBG
#define DEBUG(format,...) printf("File: "__FILE__", Line: %d: "format"\n", __LINE__, ##__VA_ARGS__)  
#endif

#ifdef MT_DBG
/*****************************************************************************
 �� �� ��  : smtGetErr
 ��������  : ���ش������������
 �������  : ��
 �������  : ��
 �� �� ֵ  : char
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
char * smtGetErr(eMtErr eErr)
{
    char *pStr = NULL;
    switch(eErr)
    {
        case MT_OK:
            pStr = "MT_OK";
            break;
            
        case MT_ERR_NULL:
            pStr = "MT_ERR_NULL";
            break;
            
        case MT_ERR_OUTRNG:
            pStr = "MT_ERR_OUTRNG";
            break;
            
        case MT_ERR_NONE:
            pStr = "MT_ERR_NONE";
            break;
            
        case MT_ERR_IO:
            pStr = "MT_ERR_IO";
            break;
            
        case MT_ERR_RES:
            pStr = "MT_ERR_RES";
            break;

        case MT_ERR_INIT:
            pStr = "MT_ERR_INIT";
            break;
            
        case MT_ERR_PARA:
            pStr = "MT_ERR_PARA";
            break;
            
        case MT_ERR_FN:
            pStr = "MT_ERR_FN";
            break;
            
        case MT_ERR_PN:
            pStr = "MT_ERR_PN";
            break;
            
        case MT_ERR_ADDR:
            pStr = "MT_ERR_ADDR";
            break;
            
        case MT_ERR_CTRL:
            pStr = "MT_ERR_CTRL";
            break;
            
        case MT_ERR_SEQ:
            pStr = "MT_ERR_SEQ";
            break;
            
        case MT_ERR_SEQ2CS:
            pStr = "MT_ERR_SEQ2CS";
            break;
            
         case MT_ERR_AFN:
            pStr = "MT_ERR_AFN";
            break;
            
        case MT_ERR_UNCOMP:
            pStr = "MT_ERR_UNCOMP";
            break;
            
        case MT_ERR_0x68:
            pStr = "MT_ERR_0x68";
            break;
            
        case MT_ERR_PROTO:
            pStr = "MT_ERR_PROTO";
            break;
            
        case MT_ERR_CS:
            pStr = "MT_ERR_CS";
            break;
            
        case MT_ERR_0x16:
            pStr = "MT_ERR_0x16";
            break;

        case MT_ERR_LOGIC:
            pStr = "MT_ERR_LOGIC";
            break;
           
        case MT_ERR_PACK:
            pStr = "MT_ERR_PACK";
            break;
            
        case MT_ERR_PFC:
            pStr = "MT_ERR_PFC";
            break;
            
        case MT_ERR_TIMEOUT:
            pStr = "MT_ERR_TIMEOUT";
            break;
            
        case MT_ERR_PRM:
            pStr = "MT_ERR_PRM";
            break;
            
        case MT_ERR_TEAM:
            pStr = "MT_ERR_TEAM";
            break;
            
         default:
            pStr = "Unkown Err";
            break;
    }

    return pStr;
    
}
#endif

/*****************************************************************************
 �� �� ��  : MT_FREE
 ��������  : �ͷ�malloc������ڴ�ռ�
 �������  : UINT8 *pBuf  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
#define  MT_FREE(pBuf)\
if(pBuf != NULL)\
{\
    free(pBuf);\
    pBuf = NULL;\
}

/*******************************************************
 *  ȫ�ֲ�����Ϣ
 *  �ṩ�������� �� Pn���͡����������Ĺ�ϵӳ��  
 *
{*////
BOOL      g_bMtInit = FALSE;             // Э���Ƿ��ʼ��
eMtRole   g_eMtRole = MT_ROLE_UNKOWN;    // ��ݣ���վ���Ǵ�վ
UINT8     g_ucMtPermitDelayMinutes = 0;  // ����ʱ��
UINT8     g_aucPw[MT_PW_LEN] = {0};
sMtEC     g_tEC;                         // �¼������� ���ն���֧��

#if MT_CFG_ENCRYPT
    peMtEncryptFunc   g_peMtEncryptFunc = NULL;  // ���ܽӿ�
    peMtDecryptFunc   g_peMtDecryptFunc = NULL;  // ���ܽӿ�
#endif
///*}
    
/*******************************************************
 *  ������Ϣ��
 *  �ṩ�������� �� Pn���͡����������Ĺ�ϵӳ��  
 *
{*////
const sMtCmdInfor gmt_cmdinfor[] = 
{
     /*******************************
     *  (0) ȷ��/���ϣ�AFN=00H��
     *
     *  ����: ������ 
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    {CMD_AFN_0_F1_ALL_OK,            MT_DIR_M2S, MT_PN_P0,  NULL,                  "ȫ��ȷ�ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��"},
    {CMD_AFN_0_F1_ALL_OK,            MT_DIR_S2M, MT_PN_P0,  NULL,                  "ȫ��ȷ�ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��"},
    {CMD_AFN_0_F2_ALL_DENY,          MT_DIR_M2S, MT_PN_P0,  NULL,                  "ȫ�����ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ���з���"},
    {CMD_AFN_0_F2_ALL_DENY,          MT_DIR_S2M, MT_PN_P0,  NULL,                  "ȫ�����ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ���з���"},
    {CMD_AFN_0_F3_ONE_BY_ONE,        MT_DIR_M2S, MT_PN_P0,  emtTrans_OneByOne,     "�����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����"},
    {CMD_AFN_0_F3_ONE_BY_ONE,        MT_DIR_S2M, MT_PN_P0,  emtTrans_OneByOne,     "�����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����"},
    ///*}

     /*******************************
     *  (1) ��λ���AFN=01H)
     *
     *  ����: AFN 00H ȷ��/����
     *  ����: ������
     *  ����: ��Ҫ
     *  
    {*///
    {CMD_AFN_1_F1_HARD_INIT,         MT_DIR_M2S, MT_PN_P0,  NULL,                  "Ӳ����ʼ��"},
    {CMD_AFN_1_F2_DATA_INIT,         MT_DIR_M2S, MT_PN_P0,  NULL,                  "��������ʼ��"},
    {CMD_AFN_1_F3_FACTORY_RESET,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "������ȫ����������ʼ�������ָ����������ã�"},
    {CMD_AFN_1_F4_PARA_INIT,         MT_DIR_M2S, MT_PN_P0,  NULL,                  "����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��"},
    ///*}
 
     /*******************************
     *  (2) ��·�ӿڼ�⣨AFN=02H��
     *
     *  ����: ������
     *  ����: AFN 00H ȷ��/����  
     *  ����: ����Ҫ
     *
    {*///
    {CMD_AFN_2_F1_LOG_IN,            MT_DIR_S2M, MT_PN_P0,  NULL,                  "��¼"},
    {CMD_AFN_2_F2_LOG_OUT,           MT_DIR_S2M, MT_PN_P0,  NULL,                  "�˳���¼"},
    {CMD_AFN_2_F3_HEART_BEAT,        MT_DIR_S2M, MT_PN_P0,  NULL,                  "����"},
    ///*}

     /*******************************
     *  (3) �м�վ����(AFN=03H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
    {*///
    // ����
    {CMD_AFN_3_F1_RELAY_CTRL,        MT_DIR_S2M, MT_PN_P0,  emtTrans_afn03f1,      "�м�վ����״̬����"},
    {CMD_AFN_3_F2_RELAY_STAT_QUERY,  MT_DIR_S2M, MT_PN_P0,  NULL,                  "�м�վ����״̬��ѯ"},
    {CMD_AFN_3_F3_RELAY_RECD_QUERY,  MT_DIR_S2M, MT_PN_P0,  NULL,                  "�м�վ����״̬�л���¼����"},
    {CMD_AFN_3_F4_HEART_DATA_QUERY,  MT_DIR_S2M, MT_PN_P0,  NULL,                  "�м�վ����״̬ͳ�Ʋ�ѯ"},
    // ����
    {CMD_AFN_3_F1_RELAY_CTRL,        MT_DIR_M2S, MT_PN_P0,  emtTrans_afn03f1,      "�м�վ����״̬����"},
    {CMD_AFN_3_F2_RELAY_STAT_QUERY,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�м�վ����״̬��ѯ"},
    {CMD_AFN_3_F3_RELAY_RECD_QUERY,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�м�վ����״̬�л���¼����"},
    {CMD_AFN_3_F4_HEART_DATA_QUERY,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�м�վ����״̬ͳ�Ʋ�ѯ"},
    ///*}


     /*******************************
     *  (4) ���ò���(AFN=04H��
     *
     *  ����: AFN 00H ȷ��/���� 
     *  ����: ������
     *  ����: ��Ҫ
     *
    {*///
    // ��1   pn:p0
    {CMD_AFN_4_F1_TML_UP_CFG,        MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f1,      "�ն�����ͨ�ſ�ͨ�Ų�������"},
    {CMD_AFN_4_F2_TML_WIRELESS_CFG,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f2,      "�ն�����ͨ�ſ������м�ת������"},
    {CMD_AFN_4_F3_MST_IP_PORT,       MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f3,      "��վIP��ַ�Ͷ˿�"},
    {CMD_AFN_4_F4_MST_PHONE_SMS,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f4,      "��վ�绰����Ͷ������ĺ���"},
    {CMD_AFN_4_F5_TML_UP_AUTH,       MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f5,      "�ն�����ͨ����Ϣ��֤��������"},
    {CMD_AFN_4_F6_TEAM_ADDR,         MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f6,      "���������ַ����"},
    {CMD_AFN_4_F7_TML_IP_PORT,       MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f7,      "������IP��ַ�Ͷ˿�"},
    {CMD_AFN_4_F8_TML_UP_WAY,        MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f8,      "����������ͨ�Ź�����ʽ"},

    // ��2   pn:p0
    {CMD_AFN_4_F9_TML_EVENT_CFG,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f9,      "�ն��¼���¼��������"},
    {CMD_AFN_4_F10_TML_POWER_CFG,    MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f10,     "�ն˵��ܱ�/��������װ�����ò���"},
    {CMD_AFN_4_F11_TML_PULSE_CFG,    MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f11,     "�ն��������ò���"},
    {CMD_AFN_4_F12_TML_STATE_INPUT,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f12,     "�ն�/������״̬���������"},
    {CMD_AFN_4_F13_TML_SIMULA_CFG,   MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f13,     "�ն˵�ѹ/����ģ�������ò���"},
    {CMD_AFN_4_F14_TML_GRUP_TOTL,    MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f14,     "�ն��ܼ������ò���"},
    {CMD_AFN_4_F15_HAVE_DIFF_EVENT,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f15,     "�й��ܵ�����������¼���������"},
    {CMD_AFN_4_F16_VPN_USER_PWD,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f16,     "����ר���û���������"},

    // ��3   pn:p0
    {CMD_AFN_4_F17_TML_SAFE_VALUE,   MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f17,     "�ն˱�����ֵ"},
    {CMD_AFN_4_F18_TML_PCTRL_PERD,   MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f18,     "�ն˹���ʱ��"},
    {CMD_AFN_4_F19_TML_PCTRL_FACTOR, MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f19,     "�ն�ʱ�ι��ض�ֵ����ϵ��"},
    {CMD_AFN_4_F20_TML_MONTH_FACTOR, MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f20,     "�ն��µ������ض�ֵ����ϵ��"},
    {CMD_AFN_4_F21_TML_POWER_FACTOR, MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f21,     "�ն˵���������ʱ�κͷ�����"},
    {CMD_AFN_4_F22_TML_POWER_RATE,   MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f22,     "�ն˵���������"},
    {CMD_AFN_4_F23_TML_WARNING_CFG,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f23,     "�ն˴߸澯����"},

    // ��4   pn:�������
    {CMD_AFN_4_F25_MP_BASE_CFG,      MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f25,     "�������������"},
    {CMD_AFN_4_F26_MP_LIMIT_CFG,     MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f26,     "��������ֵ����"},
    {CMD_AFN_4_F27_MP_LOSS_CFG,      MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f27,     "������ͭ���������"},
    {CMD_AFN_4_F28_MP_PERIOD_FACTOR, MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f28,     "�����㹦�������ֶ���ֵ"},
    {CMD_AFN_4_F29_TML_METER_ID,     MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f29,     "�ն˵��ص��ܱ���ʾ��"},
    {CMD_AFN_4_F30_TML_AUTO_READ,    MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f30,     "�ն�̨�����г���ͣ��/Ͷ������"},
    {CMD_AFN_4_F31_SLAVE_ADDR,       MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f31,     "�ز��ӽڵ㸽���ڵ��ַ"},

    // ��5   pn:p0
    {CMD_AFN_4_F33_TML_READ_CFG,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f33,     "�ն˳������в�������"},
    {CMD_AFN_4_F34_CON_DOWN_CFG,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f34,     "����������ͨ��ģ��Ĳ�������"},
    {CMD_AFN_4_F35_TML_READ_VIP,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f35,     "�ն�̨�����г����ص㻧����"},
    {CMD_AFN_4_F36_TML_UP_LIMIT,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f36,     "�ն�����ͨ��������������"},
    {CMD_AFN_4_F37_TML_CASC_CFG,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f37,     "�ն˼���ͨ�Ų���"},
    {CMD_AFN_4_F38_CFG_ASK_1,        MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f38,     "1��������������(���ն�֧�ֵ�1������������)"},
    {CMD_AFN_4_F39_CFG_ASK_2,        MT_DIR_M2S, MT_PN_P0,  emtTrans_afn04f39,     "2��������������(���ն�֧�ֵ�2������������)"},

    // ��6   pn:�ܼ����
    {CMD_AFN_4_F41_PERIOD_VALUE,     MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f41,     "ʱ�ι��ض�ֵ"},
    {CMD_AFN_4_F42_FACTORY_HOLIDAY,  MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f42,     "���ݹ��ز���"},
    {CMD_AFN_4_F43_SLIDE_TIME,       MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f43,     "���ʿ��ƵĹ��ʼ��㻬��ʱ��"},
    {CMD_AFN_4_F44_SHUTOUT_CFG,      MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f44,     "Ӫҵ��ͣ�ز���"},
    {CMD_AFN_4_F45_CTRL_TURN_CFG,    MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f45,     "�����ִ��趨"},
    {CMD_AFN_4_F46_MONTH_FIX_VALUE,  MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f46,     "�µ����ض�ֵ"},
    {CMD_AFN_4_F47_BUY_COUNT,        MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f47,     "������(��)�ز���"},
    {CMD_AFN_4_F48_ELEC_TURN_CFG,    MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f48,     "����ִ��趨"},

    // ��7  pn:�����ִ�
    {CMD_AFN_4_F49_WARNING_TIME,     MT_DIR_M2S, MT_PN_CT,  emtTrans_afn04f49,     "���ظ澯ʱ��"},

    // ��8  pn:�ܼ����
    {CMD_AFN_4_F57_TML_WARN_SOUND,   MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f57,     "�ն������澯����/��ֹ����"},
    {CMD_AFN_4_F58_TML_ATUO_PROTECT, MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f58,     "�ն��Զ���������"},
    {CMD_AFN_4_F59_METER_LIMIT,      MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f59,     "���ܱ��쳣�б���ֵ����"},
    {CMD_AFN_4_F60_HUMOR_LIMIT,      MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f60,     "г����ֵ"},
    {CMD_AFN_4_F61_DC_SIMULA,        MT_DIR_M2S, MT_PN_GT,  emtTrans_afn04f61,     "ֱ��ģ�����������"},

    // ��9  pn:�����
    {CMD_AFN_4_F65_CFG_AUTO_1,       MT_DIR_M2S, MT_PN_TK,  emtTrans_afn04f65,     "��ʱ�ϱ�1��������������"},
    {CMD_AFN_4_F66_CFG_AUTO_2,       MT_DIR_M2S, MT_PN_TK,  emtTrans_afn04f66,     "��ʱ�ϱ�2��������������"},
    {CMD_AFN_4_F67_GOP_AUTO_1,       MT_DIR_M2S, MT_PN_TK,  emtTrans_afn04f67,     "��ʱ�ϱ�1��������������/ֹͣ����"},
    {CMD_AFN_4_F68_GOP_AUTO_2,       MT_DIR_M2S, MT_PN_TK,  emtTrans_afn04f68,     "��ʱ�ϱ�2��������������/ֹͣ����"},

    // ��10  pn:�������   
    {CMD_AFN_4_F73_CAPA_CFG,         MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f73,     "����������"},
    {CMD_AFN_4_F74_CAPA_RUN_CFG,     MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f74,     "������Ͷ�����в���"},
    {CMD_AFN_4_F75_CAPA_PROT_PARA,   MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f75,     "��������������"},
    {CMD_AFN_4_F76_CAPA_CTRL_WAY,    MT_DIR_M2S, MT_PN_MP,  emtTrans_afn04f76,     "������Ͷ�п��Ʒ�ʽ"},

    // ��11 pn:ֱ��ģ�����˿ں�   
    {CMD_AFN_4_F81_CD_CHANGE_RATE,   MT_DIR_M2S, MT_PN_DP,  emtTrans_afn04f81,     "ֱ��ģ�������"},
    {CMD_AFN_4_F82_CD_LIMIT,         MT_DIR_M2S, MT_PN_DP,  emtTrans_afn04f82,     "ֱ��ģ������ֵ"},
    {CMD_AFN_4_F83_CD_FREEZE_PARA,   MT_DIR_M2S, MT_PN_DP,  emtTrans_afn04f83,     "ֱ��ģ�����������"}, 
    ///*}

     /*******************************
     *  (5) ��������(AFN=05H��
     *
     *  ����: AFN 00H ȷ��/���� 
     *  ����: ������
     *  ����: ��Ҫ
     *
    {*///
    // ��1  pn:�����ִ�   
    {CMD_AFN_5_F1_REMOTE_TURN_OFF,   MT_DIR_M2S, MT_PN_CT,  emtTrans_afn05f1,      "ң����բ"},
    {CMD_AFN_5_F2_PERMIT_TURN_ON,    MT_DIR_M2S, MT_PN_CT,  NULL,                  "�����բ"},   
              
    // ��2  pn:�ܼ����        
    {CMD_AFN_5_F9_PERIOD_GO,         MT_DIR_M2S, MT_PN_GT,  emtTrans_afn05f9,      "ʱ�ι���Ͷ��"},
    {CMD_AFN_5_F10_HOLIDAY_GO,       MT_DIR_M2S, MT_PN_GT,  NULL,                  "���ݹ���Ͷ��"},   
    {CMD_AFN_5_F11_SHUTOUT_GO,       MT_DIR_M2S, MT_PN_GT,  NULL,                  "Ӫҵ��ͣ����Ͷ��"},
    {CMD_AFN_5_F12_DOWN_GO,          MT_DIR_M2S, MT_PN_GT,  NULL,                  "��ǰ�����¸���Ͷ��"},   
    {CMD_AFN_5_F15_MONTH_GO,         MT_DIR_M2S, MT_PN_GT,  emtTrans_afn05f12,     "�µ��Ͷ��"},
    {CMD_AFN_5_F16_BUY_GO,           MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����Ͷ��"},   

    // ��3  pn:�ܼ����
    {CMD_AFN_5_F17_PERIOD_STOP,      MT_DIR_M2S, MT_PN_GT,  NULL,                  "ʱ�ι��ؽ��"},
    {CMD_AFN_5_F18_HOLIDAY_STOP,     MT_DIR_M2S, MT_PN_GT,  NULL,                  "���ݹ��ؽ��"},   
    {CMD_AFN_5_F19_SHUTOUT_STOP,     MT_DIR_M2S, MT_PN_GT,  NULL,                  "Ӫҵ��ͣ���ؽ��"},
    {CMD_AFN_5_F20_DOWN_STOP,        MT_DIR_M2S, MT_PN_GT,  NULL,                  "��ǰ�����¸��ؽ��"},   
    {CMD_AFN_5_F23_MONTH_STOP,       MT_DIR_M2S, MT_PN_GT,  NULL,                  "�µ�ؽ��"},
    {CMD_AFN_5_F24_BUY_STOP,         MT_DIR_M2S, MT_PN_GT,  NULL,                  "����ؽ��"},   

    // ��4  pn:p0 
    {CMD_AFN_5_F25_TML_PROTECT_GO,   MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f25,     "�ն˵籣Ͷ��"},
    {CMD_AFN_5_F26_WARN_PAY_GO,      MT_DIR_M2S, MT_PN_P0,  NULL,                  "�߷Ѹ澯Ͷ��"},   
    {CMD_AFN_5_F27_PERMIT_TALK_GO,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�����ն�����վͨ��"},
    {CMD_AFN_5_F28_TAKE_OFF_TML_GO,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��޳�Ͷ��"},   
    {CMD_AFN_5_F29_AUTO_SAY_GO,      MT_DIR_M2S, MT_PN_P0,  NULL,                  "�����ն������ϱ�"},
    {CMD_AFN_5_F31_CHECK_TIME,       MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f31,     "��ʱ����"},   
    {CMD_AFN_5_F32_CHINESE_INFO,     MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f32,     "������Ϣ"},   

    // ��5 pn:p0 
    {CMD_AFN_5_F33_TML_PROTECT_STOP, MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵籣���"},
    {CMD_AFN_5_F34_WARN_PAY_STOP,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�߷Ѹ澯���"},   
    {CMD_AFN_5_F35_PERMIT_TALK_STOP, MT_DIR_M2S, MT_PN_P0,  NULL,                  "��ֹ�ն�����վͨ��"},
    {CMD_AFN_5_F36_TAKE_OFF_TML_STOP,MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��޳����"},   
    {CMD_AFN_5_F37_AUTO_SAY_STOP,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "��ֹ�ն������ϱ�"},
    {CMD_AFN_5_F38_TML_LINK_ON,      MT_DIR_M2S, MT_PN_P0,  NULL,                  "�����ն�������վ"},   
    {CMD_AFN_5_F39_TML_LINK_OFF,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�����ն˶Ͽ�����"},   

    // ��6 pn:������� 
    {CMD_AFN_5_F41_CAPA_CTRL_GO,     MT_DIR_M2S, MT_PN_MP,  emtTrans_afn05f41,     "����������Ͷ��"},
    {CMD_AFN_5_F42_CAPA_CTRL_STOP,   MT_DIR_M2S, MT_PN_MP,  emtTrans_afn05f42,     "���������ƽ��"},   

    // ��7 pn:p0  
    {CMD_AFN_5_F49_READ_METER_STOP,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f49,     "����ָ��ͨ�Ŷ˿���ͣ����"},
    {CMD_AFN_5_F50_READ_METER_GO,    MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f50,     "����ָ��ͨ�Ŷ˿ڻָ�����"},   
    {CMD_AFN_5_F51_READ_METER_REDO,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f51,     "����ָ��ͨ�Ŷ˿����³���"},
    {CMD_AFN_5_F52_INIT_ROUTE,       MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f52,     "��ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ"},   
    {CMD_AFN_5_F53_DELET_ALL_METER,  MT_DIR_M2S, MT_PN_P0,  emtTrans_afn05f53,     "ɾ��ָ��ͨ�Ŷ˿��µ�ȫ�����"}, 
    ///*}

     /*******************************
     *  (6) �����֤����ԿЭ��(AFN=06H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *  
    {*///
    // ����
    {CMD_AFN_6_F1_ID_AUTH_Q,         MT_DIR_S2M, MT_PN_P0,  emtTrans_afn06f1,     "�����֤����"},
    {CMD_AFN_6_F2_ID_AUTH_A,         MT_DIR_S2M, MT_PN_P0,  emtTrans_afn06f2,     "�����֤��Ӧ"},
    {CMD_AFN_6_F3_RAND_Q,            MT_DIR_S2M, MT_PN_P0,  emtTrans_afn06f3,     "ȡ���������"},
    {CMD_AFN_6_F4_RAND_A,            MT_DIR_S2M, MT_PN_P0,  emtTrans_afn06f4,     "ȡ�������Ӧ"},

    // ����
    {CMD_AFN_6_F1_ID_AUTH_Q,         MT_DIR_M2S, MT_PN_P0,  emtTrans_afn06f1,     "�����֤����"},
    {CMD_AFN_6_F2_ID_AUTH_A,         MT_DIR_M2S, MT_PN_P0,  emtTrans_afn06f2,     "�����֤��Ӧ"},
    {CMD_AFN_6_F3_RAND_Q,            MT_DIR_M2S, MT_PN_P0,  emtTrans_afn06f3,     "ȡ���������"},
    {CMD_AFN_6_F4_RAND_A,            MT_DIR_M2S, MT_PN_P0,  emtTrans_afn06f4,     "ȡ�������Ӧ"},
    ///*}


     /*******************************
     *  (7) ���󱻼����ն������ϱ�(AFN=08H��
     *
     *  ����: �������ϱ�������ʱ, �ֱ�������1�����ݺ�����2���������б��Ľ���Ӧ��
     *        �������ϱ�������ʱ, AFN 00H ���� CMD_AFN_0_F2_ALL_DENY
     *  ����: ������
     *  ����: ����Ҫ 
     *
    {*///
    {CMD_AFN_8_F1_CALL_AUTO_REPT,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "���󱻼����ն������ϱ�"},
    ///*}

     /*******************************
     *  (8) �����ն����ü���Ϣ(AFN=09H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *  
    {*///
    // ����
    {CMD_AFN_9_F1_TML_VERSION,       MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f1,      "�ն˰汾��Ϣ"},
    {CMD_AFN_9_F2_TML_INPUT_OUT,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f2,      "�ն�֧�ֵ����롢�����ͨ�Ŷ˿�����"},
    {CMD_AFN_9_F3_TML_OTHER_CFG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f3,      "�ն�֧�ֵ���������"},
    {CMD_AFN_9_F4_SUPPORT_PARA_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f4,      "�ն�֧�ֵĲ�������"},
    {CMD_AFN_9_F5_SUPPORT_CTRL_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f5,      "�ն�֧�ֵĿ�������"},
    {CMD_AFN_9_F6_SUPPORT_ASK1_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f6,      "�ն�֧�ֵ�1����������"},
    {CMD_AFN_9_F7_SUPPORT_ASK2_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f7,      "�ն�֧�ֵ�2����������"},
    {CMD_AFN_9_F8_SUPPORT_EVNT_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn09f8,      "�ն�֧�ֵ��¼���¼����"},

    // ����
    {CMD_AFN_9_F1_TML_VERSION,       MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˰汾��Ϣ"},
    {CMD_AFN_9_F2_TML_INPUT_OUT,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵ����롢�����ͨ�Ŷ˿�����"},
    {CMD_AFN_9_F3_TML_OTHER_CFG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵ���������"},
    {CMD_AFN_9_F4_SUPPORT_PARA_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵĲ�������"},
    {CMD_AFN_9_F5_SUPPORT_CTRL_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵĿ�������"},
    {CMD_AFN_9_F6_SUPPORT_ASK1_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵ�1����������"},
    {CMD_AFN_9_F7_SUPPORT_ASK2_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵ�2����������"},
    {CMD_AFN_9_F8_SUPPORT_EVNT_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�֧�ֵ��¼���¼����"},
    ///*}


     /*******************************
     *  (9) ��ѯ����(AFN=0AH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *  
    {*///
    /** { ���� **/ 
    // ��1   pn:p0
    {CMD_AFN_A_F1_TML_UP_CFG,        MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f1,      "�ն�����ͨ�ſ�ͨ�Ų�������"},
    {CMD_AFN_A_F2_TML_WIRELESS_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f2,      "�ն�����ͨ�ſ������м�ת������"},
    {CMD_AFN_A_F3_MST_IP_PORT,       MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f3,      "��վIP��ַ�Ͷ˿�"},
    {CMD_AFN_A_F4_MST_PHONE_SMS,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f4,      "��վ�绰����Ͷ������ĺ���"},
    {CMD_AFN_A_F5_TML_UP_AUTH,       MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f5,      "�ն�����ͨ����Ϣ��֤��������"},
    {CMD_AFN_A_F6_TEAM_ADDR,         MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f6,      "���������ַ����"},
    {CMD_AFN_A_F7_TML_IP_PORT,       MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f7,      "������IP��ַ�Ͷ˿�"},
    {CMD_AFN_A_F8_TML_UP_WAY,        MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f8,      "����������ͨ�Ź�����ʽ"},

    // ��2   pn:p0
    {CMD_AFN_A_F9_TML_EVENT_CFG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f9,      "�ն��¼���¼��������"},
    {CMD_AFN_A_F10_TML_POWER_CFG,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f10,     "�ն˵��ܱ�/��������װ�����ò���"},
    {CMD_AFN_A_F11_TML_PULSE_CFG,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f11,     "�ն��������ò���"},
    {CMD_AFN_A_F12_TML_STATE_INPUT,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f12,     "�ն�/������״̬���������"},
    {CMD_AFN_A_F13_TML_SIMULA_CFG,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f13,     "�ն˵�ѹ/����ģ�������ò���"},
    {CMD_AFN_A_F14_TML_GRUP_TOTL,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f14,     "�ն��ܼ������ò���"},
    {CMD_AFN_A_F15_HAVE_DIFF_EVENT,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f15,     "�й��ܵ�����������¼���������"},
    {CMD_AFN_A_F16_VPN_USER_PWD,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f16,     "����ר���û���������"},

    // ��3   pn:p0
    {CMD_AFN_A_F17_TML_SAFE_VALUE,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f17,     "�ն˱�����ֵ"},
    {CMD_AFN_A_F18_TML_PCTRL_PERD,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f18,     "�ն˹���ʱ��"},
    {CMD_AFN_A_F19_TML_PCTRL_FACTOR, MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f19,     "�ն�ʱ�ι��ض�ֵ����ϵ��"},
    {CMD_AFN_A_F20_TML_MONTH_FACTOR, MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f20,     "�ն��µ������ض�ֵ����ϵ��"},
    {CMD_AFN_A_F21_TML_POWER_FACTOR, MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f21,     "�ն˵���������ʱ�κͷ�����"},
    {CMD_AFN_A_F22_TML_POWER_RATE,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f22,     "�ն˵���������"},
    {CMD_AFN_A_F23_TML_WARNING_CFG,  MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f23,     "�ն˴߸澯����"},

    // ��4   pn:�������
    {CMD_AFN_A_F25_MP_BASE_CFG,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f25,     "�������������"},
    {CMD_AFN_A_F26_MP_LIMIT_CFG,     MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f26,     "��������ֵ����"},
    {CMD_AFN_A_F27_MP_LOSS_CFG,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f27,     "������ͭ���������"},
    {CMD_AFN_A_F28_MP_PERIOD_FACTOR, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f28,     "�����㹦�������ֶ���ֵ"},
    {CMD_AFN_A_F29_TML_METER_ID,     MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f29,     "�ն˵��ص��ܱ���ʾ��"},
    {CMD_AFN_A_F30_TML_AUTO_READ,    MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f30,     "�ն�̨�����г���ͣ��/Ͷ������"},
    {CMD_AFN_A_F31_SLAVE_ADDR,       MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f31,     "�ز��ӽڵ㸽���ڵ��ַ"},

    // ��5   pn:p0
    {CMD_AFN_A_F33_TML_READ_CFG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f33,     "�ն˳������в�������"},
    {CMD_AFN_A_F34_CON_DOWN_CFG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f34,     "����������ͨ��ģ��Ĳ�������"},
    {CMD_AFN_A_F35_TML_READ_VIP,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f35,     "�ն�̨�����г����ص㻧����"},
    {CMD_AFN_A_F36_TML_UP_LIMIT,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f36,     "�ն�����ͨ��������������"},
    {CMD_AFN_A_F37_TML_CASC_CFG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f37,     "�ն˼���ͨ�Ų���"},
    {CMD_AFN_A_F38_CFG_ASK_1,        MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f38,     "1��������������(���ն�֧�ֵ�1������������)"},
    {CMD_AFN_A_F39_CFG_ASK_2,        MT_DIR_S2M, MT_PN_P0,  emtTrans_afn04f39,     "2��������������(���ն�֧�ֵ�2������������)"},

    // ��6   pn:�ܼ����
    {CMD_AFN_A_F41_PERIOD_VALUE,     MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f41,     "ʱ�ι��ض�ֵ"},
    {CMD_AFN_A_F42_FACTORY_HOLIDAY,  MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f42,     "���ݹ��ز���"},
    {CMD_AFN_A_F43_SLIDE_TIME,       MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f43,     "���ʿ��ƵĹ��ʼ��㻬��ʱ��"},
    {CMD_AFN_A_F44_SHUTOUT_CFG,      MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f44,     "Ӫҵ��ͣ�ز���"},
    {CMD_AFN_A_F45_CTRL_TURN_CFG,    MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f45,     "�����ִ��趨"},
    {CMD_AFN_A_F46_MONTH_FIX_VALUE,  MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f46,     "�µ����ض�ֵ"},
    {CMD_AFN_A_F47_BUY_COUNT,        MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f47,     "������(��)�ز���"},
    {CMD_AFN_A_F48_ELEC_TURN_CFG,    MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f48,     "����ִ��趨"},

    // ��7  pn:�����ִ�
    {CMD_AFN_A_F49_WARNING_TIME,     MT_DIR_S2M, MT_PN_CT,  emtTrans_afn04f49,     "���ظ澯ʱ��"},

    // ��8  pn:�ܼ����
    {CMD_AFN_A_F57_TML_WARN_SOUND,   MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f57,     "�ն������澯����/��ֹ����"},
    {CMD_AFN_A_F58_TML_ATUO_PROTECT, MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f58,     "�ն��Զ���������"},
    {CMD_AFN_A_F59_METER_LIMIT,      MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f59,     "���ܱ��쳣�б���ֵ����"},
    {CMD_AFN_A_F60_HUMOR_LIMIT,      MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f60,     "г����ֵ"},
    {CMD_AFN_A_F61_DC_SIMULA,        MT_DIR_S2M, MT_PN_GT,  emtTrans_afn04f61,     "ֱ��ģ�����������"},

    // ��9  pn:�����
    {CMD_AFN_A_F65_CFG_AUTO_1,       MT_DIR_S2M, MT_PN_TK,  emtTrans_afn04f65,     "��ʱ�ϱ�1��������������"},
    {CMD_AFN_A_F66_CFG_AUTO_2,       MT_DIR_S2M, MT_PN_TK,  emtTrans_afn04f66,     "��ʱ�ϱ�2��������������"},
    {CMD_AFN_A_F67_GOP_AUTO_1,       MT_DIR_S2M, MT_PN_TK,  emtTrans_afn04f67,     "��ʱ�ϱ�1��������������/ֹͣ����"},
    {CMD_AFN_A_F68_GOP_AUTO_2,       MT_DIR_S2M, MT_PN_TK,  emtTrans_afn04f68,     "��ʱ�ϱ�2��������������/ֹͣ����"},

    // ��10  pn:�������   
    {CMD_AFN_A_F73_CAPA_CFG,         MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f73,     "����������"},
    {CMD_AFN_A_F74_CAPA_RUN_CFG,     MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f74,     "������Ͷ�����в���"},
    {CMD_AFN_A_F75_CAPA_PROT_PARA,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f75,     "��������������"},
    {CMD_AFN_A_F76_CAPA_CTRL_WAY,    MT_DIR_S2M, MT_PN_MP,  emtTrans_afn04f76,     "������Ͷ�п��Ʒ�ʽ"},

    // ��11 pn:ֱ��ģ�����˿ں�   
    {CMD_AFN_A_F81_CD_CHANGE_RATE,   MT_DIR_S2M, MT_PN_DP,  emtTrans_afn04f81,     "ֱ��ģ�������"},
    {CMD_AFN_A_F82_CD_LIMIT,         MT_DIR_S2M, MT_PN_DP,  emtTrans_afn04f82,     "ֱ��ģ������ֵ"},
    {CMD_AFN_A_F83_CD_FREEZE_PARA,   MT_DIR_S2M, MT_PN_DP,  emtTrans_afn04f83,     "ֱ��ģ�����������"}, 
    /** } ���� **/ 

    /** { ���� **/ 
    // ��1   pn:p0
    {CMD_AFN_A_F1_TML_UP_CFG,        MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ͨ�ſ�ͨ�Ų�������"},
    {CMD_AFN_A_F2_TML_WIRELESS_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ͨ�ſ������м�ת������"},
    {CMD_AFN_A_F3_MST_IP_PORT,       MT_DIR_M2S, MT_PN_P0,  NULL,                  "��վIP��ַ�Ͷ˿�"},
    {CMD_AFN_A_F4_MST_PHONE_SMS,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "��վ�绰����Ͷ������ĺ���"},
    {CMD_AFN_A_F5_TML_UP_AUTH,       MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ͨ����Ϣ��֤��������"},
    {CMD_AFN_A_F6_TEAM_ADDR,         MT_DIR_M2S, MT_PN_P0,  NULL,                  "���������ַ����"},
    {CMD_AFN_A_F7_TML_IP_PORT,       MT_DIR_M2S, MT_PN_P0,  NULL,                  "������IP��ַ�Ͷ˿�"},
    {CMD_AFN_A_F8_TML_UP_WAY,        MT_DIR_M2S, MT_PN_P0,  NULL,                  "����������ͨ�Ź�����ʽ"},

    // ��2   pn:p0
    {CMD_AFN_A_F9_TML_EVENT_CFG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��¼���¼��������"},
    {CMD_AFN_A_F10_TML_POWER_CFG,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵��ܱ�/��������װ�����ò���"},
    {CMD_AFN_A_F11_TML_PULSE_CFG,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��������ò���"},
    {CMD_AFN_A_F12_TML_STATE_INPUT,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�/������״̬���������"},
    {CMD_AFN_A_F13_TML_SIMULA_CFG,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵�ѹ/����ģ�������ò���"},
    {CMD_AFN_A_F14_TML_GRUP_TOTL,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��ܼ������ò���"},
    {CMD_AFN_A_F15_HAVE_DIFF_EVENT,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�й��ܵ�����������¼���������"},
    {CMD_AFN_A_F16_VPN_USER_PWD,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "����ר���û���������"},

    // ��3   pn:p0
    {CMD_AFN_A_F17_TML_SAFE_VALUE,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˱�����ֵ"},
    {CMD_AFN_A_F18_TML_PCTRL_PERD,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˹���ʱ��"},
    {CMD_AFN_A_F19_TML_PCTRL_FACTOR, MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�ʱ�ι��ض�ֵ����ϵ��"},
    {CMD_AFN_A_F20_TML_MONTH_FACTOR, MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��µ������ض�ֵ����ϵ��"},
    {CMD_AFN_A_F21_TML_POWER_FACTOR, MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵���������ʱ�κͷ�����"},
    {CMD_AFN_A_F22_TML_POWER_RATE,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵���������"},
    {CMD_AFN_A_F23_TML_WARNING_CFG,  MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˴߸澯����"},

    // ��4   pn:�������
    {CMD_AFN_A_F25_MP_BASE_CFG,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "�������������"},
    {CMD_AFN_A_F26_MP_LIMIT_CFG,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "��������ֵ����"},
    {CMD_AFN_A_F27_MP_LOSS_CFG,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "������ͭ���������"},
    {CMD_AFN_A_F28_MP_PERIOD_FACTOR, MT_DIR_M2S, MT_PN_MP,  NULL,                  "�����㹦�������ֶ���ֵ"},
    {CMD_AFN_A_F29_TML_METER_ID,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "�ն˵��ص��ܱ���ʾ��"},
    {CMD_AFN_A_F30_TML_AUTO_READ,    MT_DIR_M2S, MT_PN_MP,  NULL,                  "�ն�̨�����г���ͣ��/Ͷ������"},
    {CMD_AFN_A_F31_SLAVE_ADDR,       MT_DIR_M2S, MT_PN_MP,  NULL,                  "�ز��ӽڵ㸽���ڵ��ַ"},

    // ��5   pn:p0
    {CMD_AFN_A_F33_TML_READ_CFG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˳������в�������"},
    {CMD_AFN_A_F34_CON_DOWN_CFG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "����������ͨ��ģ��Ĳ�������"},
    {CMD_AFN_A_F35_TML_READ_VIP,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�̨�����г����ص㻧����"},
    {CMD_AFN_A_F36_TML_UP_LIMIT,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ͨ��������������"},
    {CMD_AFN_A_F37_TML_CASC_CFG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˼���ͨ�Ų���"},
    {CMD_AFN_A_F38_CFG_ASK_1,        MT_DIR_M2S, MT_PN_P0,  NULL,                  "1��������������(���ն�֧�ֵ�1������������)"},
    {CMD_AFN_A_F39_CFG_ASK_2,        MT_DIR_M2S, MT_PN_P0,  NULL,                  "2��������������(���ն�֧�ֵ�2������������)"},

    // ��6   pn:�ܼ����
    {CMD_AFN_A_F41_PERIOD_VALUE,     MT_DIR_M2S, MT_PN_GT,  NULL,                  "ʱ�ι��ض�ֵ"},
    {CMD_AFN_A_F42_FACTORY_HOLIDAY,  MT_DIR_M2S, MT_PN_GT,  NULL,                  "���ݹ��ز���"},
    {CMD_AFN_A_F43_SLIDE_TIME,       MT_DIR_M2S, MT_PN_GT,  NULL,                  "���ʿ��ƵĹ��ʼ��㻬��ʱ��"},
    {CMD_AFN_A_F44_SHUTOUT_CFG,      MT_DIR_M2S, MT_PN_GT,  NULL,                  "Ӫҵ��ͣ�ز���"},
    {CMD_AFN_A_F45_CTRL_TURN_CFG,    MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����ִ��趨"},
    {CMD_AFN_A_F46_MONTH_FIX_VALUE,  MT_DIR_M2S, MT_PN_GT,  NULL,                  "�µ����ض�ֵ"},
    {CMD_AFN_A_F47_BUY_COUNT,        MT_DIR_M2S, MT_PN_GT,  NULL,                  "������(��)�ز���"},
    {CMD_AFN_A_F48_ELEC_TURN_CFG,    MT_DIR_M2S, MT_PN_GT,  NULL,                  "����ִ��趨"},

    // ��7  pn:�����ִ�
    {CMD_AFN_A_F49_WARNING_TIME,     MT_DIR_M2S, MT_PN_CT,  NULL,                  "���ظ澯ʱ��"},

    // ��8  pn:�ܼ����
    {CMD_AFN_A_F57_TML_WARN_SOUND,   MT_DIR_M2S, MT_PN_GT,  NULL,                  "�ն������澯����/��ֹ����"},
    {CMD_AFN_A_F58_TML_ATUO_PROTECT, MT_DIR_M2S, MT_PN_GT,  NULL,                  "�ն��Զ���������"},
    {CMD_AFN_A_F59_METER_LIMIT,      MT_DIR_M2S, MT_PN_GT,  NULL,                  "���ܱ��쳣�б���ֵ����"},
    {CMD_AFN_A_F60_HUMOR_LIMIT,      MT_DIR_M2S, MT_PN_GT,  NULL,                  "г����ֵ"},
    {CMD_AFN_A_F61_DC_SIMULA,        MT_DIR_M2S, MT_PN_GT,  NULL,                  "ֱ��ģ�����������"},

    // ��9  pn:�����
    {CMD_AFN_A_F65_CFG_AUTO_1,       MT_DIR_M2S, MT_PN_TK,  NULL,                  "��ʱ�ϱ�1��������������"},
    {CMD_AFN_A_F66_CFG_AUTO_2,       MT_DIR_M2S, MT_PN_TK,  NULL,                  "��ʱ�ϱ�2��������������"},
    {CMD_AFN_A_F67_GOP_AUTO_1,       MT_DIR_M2S, MT_PN_TK,  NULL,                  "��ʱ�ϱ�1��������������/ֹͣ����"},
    {CMD_AFN_A_F68_GOP_AUTO_2,       MT_DIR_M2S, MT_PN_TK,  NULL,                  "��ʱ�ϱ�2��������������/ֹͣ����"},

    // ��10  pn:�������   
    {CMD_AFN_A_F73_CAPA_CFG,         MT_DIR_M2S, MT_PN_MP,  NULL,                  "����������"},
    {CMD_AFN_A_F74_CAPA_RUN_CFG,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "������Ͷ�����в���"},
    {CMD_AFN_A_F75_CAPA_PROT_PARA,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��������������"},
    {CMD_AFN_A_F76_CAPA_CTRL_WAY,    MT_DIR_M2S, MT_PN_MP,  NULL,                  "������Ͷ�п��Ʒ�ʽ"},

    // ��11 pn:ֱ��ģ�����˿ں�   
    {CMD_AFN_A_F81_CD_CHANGE_RATE,   MT_DIR_M2S, MT_PN_DP,  NULL,                  "ֱ��ģ�������"},
    {CMD_AFN_A_F82_CD_LIMIT,         MT_DIR_M2S, MT_PN_DP,  NULL,                  "ֱ��ģ������ֵ"},
    {CMD_AFN_A_F83_CD_FREEZE_PARA,   MT_DIR_M2S, MT_PN_DP,  NULL,                  "ֱ��ģ�����������"}, 
    /** } ���� **/ 
    ///*}

     /*******************************
     *  (10) ������������(AFN=0BH��
     *
     *  ����: ���ݲ�ͬ����,�ֱ�������1�����ݺ�����2���������б��Ľ���Ӧ��
     *  ����: ������
     *  ����: ����Ҫ  
     *  
    {*///
    {CMD_AFN_B_F1_TIMING_REPORT_1,   MT_DIR_M2S, MT_PN_TK,  NULL,                  "����ʱ�ϱ�1����������"},
    {CMD_AFN_B_F2_TIMING_REPORT_2,   MT_DIR_M2S, MT_PN_TK,  NULL,                  "����ʱ�ϱ�2����������"},
    ///*}


     /*******************************
     *  (11) ����1������(AFN=0CH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *  
    {*///
    /** { ���� **/ 
    // ��1   pn:p0   
    {CMD_AFN_C_F2_TML_CLOCK,         MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf02,     "�ն�����ʱ��"},
    {CMD_AFN_C_F3_TML_PARA_STATE,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf03,     "�ն˲���״̬"},
    {CMD_AFN_C_F4_TML_UPCOM_STATE,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf04,     "�ն�����ͨ��״̬"},
    {CMD_AFN_C_F5_TML_CTRL_SET,      MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf05,     "�ն˿�������״̬"},
    {CMD_AFN_C_F6_TML_CTRL_STATE,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf06,     "�ն˵�ǰ����״̬"},
    {CMD_AFN_C_F7_TML_EC_VALUE,      MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf07,     "�ն��¼���������ǰֵ"},
    {CMD_AFN_C_F8_TML_EVNT_FLAG,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf08,     "�ն��¼���־״̬"}, 

    // ��2   pn:p0
    {CMD_AFN_C_F9_TML_STATE_BIT,     MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf09,     "�ն�״̬������λ��־"},
    {CMD_AFN_C_F10_TML_MONTH_FLOW,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf10,     "�ն�����վ���ա���ͨ������"},
    {CMD_AFN_C_F11_TML_READ_METER,   MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0cf11,     "�ն˼��г���״̬��Ϣ"},

    // ��3   pn:�ܼ����
    {CMD_AFN_C_F17_TOTAL_POWER_HAVE, MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf17,     "��ǰ�ܼ��й�����"},
    {CMD_AFN_C_F18_TOTAL_POWER_NONE, MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf18,     "��ǰ�ܼ��޹�����"},
    {CMD_AFN_C_F19_DAY_POWER_HAVE,   MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf19,     "�����ܼ��й�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F20_DAY_POWER_NONE,   MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf20,     "�����ܼ��޹�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F21_MONTH_POWER_HAVE, MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf21,     "�����ܼ��й�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F22_MONTH_POWER_NONE, MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf22,     "�����ܼ��޹�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F23_TML_LEFT_POWER,   MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf23,     "�ն˵�ǰʣ�����(��)"},
    {CMD_AFN_C_F24_DOWN_FREZ_VALUE,  MT_DIR_S2M, MT_PN_GT,  emtTrans_afn0cf24,     "��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ"},
           
    // ��4   pn:�������
    {CMD_AFN_C_F25_POWER_RATE_CUR,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf25,     "��ǰ���༰����/�޹����ʡ���������, �����ѹ��������������������ڹ���"},
    {CMD_AFN_C_F26_DROP_PHASE_LAST,  MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf26,     "A��B��C�������ͳ�����ݼ����һ�ζ����¼"},
    {CMD_AFN_C_F27_METER_PROG_TIME,  MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf27,     "���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��"},
    {CMD_AFN_C_F28_METER_WORD_CBIT,  MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf28,     "�������״̬�ּ����λ��־"},
    {CMD_AFN_C_F29_COPER_IRON_CUR,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf29,     "��ǰͭ�������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F30_COPER_IRON_LAST,  MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf30,     "��һ�����յ�ǰͭ�������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F31_POWER_CUR,        MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf31,     "��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"},
    {CMD_AFN_C_F32_POWER_LAST,       MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf32,     "��һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"},

    // ��5   pn:�������
    {CMD_AFN_C_F33_FRTH_POWR_P1P4_C, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf33,     "��ǰ������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F34_BACK_POWR_P2P3_C, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf34,     "��ǰ������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F35_FRTH_DMND_M,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf35,     "����������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F36_BACK_DMND_M,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf36,     "���·�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F37_FRTH_POWR_P1P4_L, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf37,     "���£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F38_BACK_POWR_P2P3_L, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf38,     "���£���һ�����գ�������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F39_FRTH_DMND_L,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf39,     "���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F40_BACK_DMND_L,      MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf40,     "���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12"},

    // ��6  pn:�������
    {CMD_AFN_C_F41_FRTH_HAVE_POWR_D, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf41,     "���������й����������ܡ�����1��M��"},
    {CMD_AFN_C_F42_FRTH_NONE_POWR_D, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf42,     "���������޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F43_BACK_HAVE_POWR_D, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf43,     "���շ����й����������ܡ�����1��M��"},
    {CMD_AFN_C_F44_BACK_NONE_POWR_D, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf44,     "���շ����޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F45_FRTH_HAVE_POWR_M, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf45,     "���������й����������ܡ�����1��M��"},
    {CMD_AFN_C_F46_FRTH_NONE_POWR_M, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf46,     "���������޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F47_BACK_HAVE_POWR_M, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf47,     "���·����й����������ܡ�����1��M��"},
    {CMD_AFN_C_F48_BACK_NONE_POWR_M, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf48,     "���·����޹����������ܡ�����1��M��"},
               
    // ��7  pn:�������
    {CMD_AFN_C_F49_CURT_PHASE_ANGLE, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf49,     "��ǰ��ѹ��������λ��"},

    // ��8  pn:�������
    {CMD_AFN_C_F57_CURT_HARM_VALUE,  MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf57,     "��ǰA��B��C�����ѹ������2��N��г����Чֵ"},
    {CMD_AFN_C_F58_CURT_HARM_RATE,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf58,     "��ǰA��B��C�����ѹ������2��N��г��������"},

    // ��9  pn:�������
    {CMD_AFN_C_F65_CURT_CAPA_SWITCH, MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf65,     "��ǰ������Ͷ��״̬"},
    {CMD_AFN_C_F66_CURT_CAPA_TIME,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf66,     "��ǰ�������ۼƲ���Ͷ��ʱ��ʹ���"},
    {CMD_AFN_C_F67_CURT_CAPA_POWR,   MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf67,     "���ա����µ������ۼƲ������޹�������"},

    // ��10  pn:ֱ��ģ�����˿ں�   
    {CMD_AFN_C_F73_DC_RLTM_DATA,     MT_DIR_S2M, MT_PN_MP,  emtTrans_afn0cf73,     "ֱ��ģ����ʵʱ����"}, 

    // ��11 pn:�ܼ����      
    {CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE, MT_DIR_S2M, MT_PN_GT, emtTrans_afn0cf81,   "Сʱ�����ܼ��й�����"},
    {CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE, MT_DIR_S2M, MT_PN_GT, emtTrans_afn0cf82,   "Сʱ�����ܼ��޹�����"},
    {CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE, MT_DIR_S2M, MT_PN_GT, emtTrans_afn0cf83,   "Сʱ�����ܼ��й��ܵ�����"},
    {CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE, MT_DIR_S2M, MT_PN_GT, emtTrans_afn0cf84,   "Сʱ�����ܼ��޹��ܵ�����"},

    // ��12 pn:�������
    {CMD_AFN_C_F89_HFRZ_RATE_HAVE,   MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf89,   "Сʱ�����й�����"},
    {CMD_AFN_C_F90_HFRZ_RATE_HAVE_A, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf90,   "Сʱ����A���й�����"},
    {CMD_AFN_C_F91_HFRZ_RATE_HAVE_B, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf91,   "Сʱ����B���й�����"},
    {CMD_AFN_C_F92_HFRZ_RATE_HAVE_C, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf92,   "Сʱ����C���й�����"},
    {CMD_AFN_C_F93_HFRZ_RATE_NONE,   MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf93,   "Сʱ�����޹�����"},
    {CMD_AFN_C_F94_HFRZ_RATE_NONE_A, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf94,   "Сʱ����A���޹�����"},
    {CMD_AFN_C_F95_HFRZ_RATE_NONE_B, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf95,   "Сʱ����B���޹�����"},
    {CMD_AFN_C_F96_HFRZ_RATE_NONE_C, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf96,   "Сʱ����C���޹�����"},

    // ��13 pn:�������
    {CMD_AFN_C_F97_HFRZ_VOLT_A,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf97,   "Сʱ����A���ѹ"},
    {CMD_AFN_C_F98_HFRZ_VOLT_B,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf98,   "Сʱ����B���ѹ"},
    {CMD_AFN_C_F99_HFRZ_VOLT_C,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf99,   "Сʱ����C���ѹ"},
    {CMD_AFN_C_F100_HFRZ_ELEC_A,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf100,  "Сʱ����A�����"},
    {CMD_AFN_C_F101_HFRZ_ELEC_B,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf101,  "Сʱ����B�����"},
    {CMD_AFN_C_F102_HFRZ_ELEC_C,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf102,  "Сʱ����C�����"},
    {CMD_AFN_C_F103_HFRZ_ELEC_ZERO,  MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf103,  "Сʱ�����������"},

    // ��14 pn:�������
    {CMD_AFN_C_F105_HFRZ_FRTH_HAVE,  MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf105,  "Сʱ���������й��ܵ�����"},
    {CMD_AFN_C_F106_HFRZ_FRTH_NONE,  MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf106,  "Сʱ���������޹��ܵ�����"},
    {CMD_AFN_C_F107_HFRZ_BACK_HAVE,  MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf107,  "Сʱ���ᷴ���й��ܵ�����"},
    {CMD_AFN_C_F108_HFRZ_BACK_NONE,  MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf108,  "Сʱ���ᷴ���޹��ܵ�����"},
    {CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S,MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf109,  "Сʱ���������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F110_HFRZ_FRTH_NONE_S,MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf110,  "Сʱ���������޹��ܵ���ʾֵ"},
    {CMD_AFN_C_F111_HFRZ_BACK_HAVE_S,MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf111,  "Сʱ���ᷴ���й��ܵ���ʾֵ"},
    {CMD_AFN_C_F112_HFRZ_BACK_NONE_S,MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf112,  "Сʱ���ᷴ���޹��ܵ���ʾֵ"}, 

    // ��15 pn:�������
    {CMD_AFN_C_F113_HFRZ_FACT_TOTAL, MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf113,  "Сʱ�����ܹ�������"},
    {CMD_AFN_C_F114_HFRZ_FACT_A,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf114,  "Сʱ����A�๦������"},
    {CMD_AFN_C_F115_HFRZ_FACT_B,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf115,  "Сʱ����B�๦������"},
    {CMD_AFN_C_F116_HFRZ_FACT_C,     MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf116,  "Сʱ����C�๦������"},

    // ��16 pn:�������
    {CMD_AFN_C_F121_HFRZ_DC_VALUE,   MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0cf121,  "Сʱ����ֱ��ģ����"},

    // ��17 pn:������� C��ʾ��ǰcurrent
    {CMD_AFN_C_F129_FRTH_HAVE_POWR_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf129,  "��ǰ�����й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F130_FRTH_NONE_POWR_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf130,  "��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F131_BACK_HAVE_POWR_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf131,  "��ǰ�����й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F132_BACK_NONE_POWR_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf132,  "��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F133_NONE_POWR_P1_C,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf133,  "��ǰһ�����޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F134_NONE_POWR_P2_C,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf134,  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F135_NONE_POWR_P3_C,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf135,  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F136_NONE_POWR_P4_C,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf136,  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},

    // ��18 pn:������� L��ʾ��һ�����ջ����� Last Month 
    {CMD_AFN_C_F137_FRTH_HAVE_POWR_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf137,  "���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F138_FRTH_NONE_POWR_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf138,  "���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F139_BACK_HAVE_POWR_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf139,  "���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F140_BACK_NONE_POWR_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf140,  "���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F141_NONE_POWR_P1_L,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf141,  "���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F142_NONE_POWR_P2_L,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf142,  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F143_NONE_POWR_P3_L,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf143,  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F144_NONE_POWR_P4_L,   MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf144,  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},

    // ��19 pn:�������
    {CMD_AFN_C_F145_FRTH_HAVE_DMND_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf145,  "���������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F146_FRTH_NONE_DMND_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf146,  "���������޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F147_BACK_HAVE_DMND_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf147,  "���·����й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F148_BACK_NONE_DMND_C, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf148,  "���·����޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F149_FRTH_HAVE_DMND_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf149,  "���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F150_FRTH_NONE_DMND_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf150,  "���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F151_BACK_HAVE_DMND_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf151,  "���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F152_BACK_NONE_DMND_L, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf152,  "���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"},

    // ��20 pn:�������
    {CMD_AFN_C_F153_FREZ_ZONE_1,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf153,  "��һʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F154_FREZ_ZONE_2,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf154,  "�ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F155_FREZ_ZONE_3,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf155,  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F156_FREZ_ZONE_4,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf156,  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F157_FREZ_ZONE_5,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf157,  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F158_FREZ_ZONE_6,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf158,  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F159_FREZ_ZONE_7,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf159,  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F160_FREZ_ZONE_8,      MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf160,  "�ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},

    // ��21 pn:�������
    {CMD_AFN_C_F161_METR_REMOTE_CTRL, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf161,  "���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"},
    {CMD_AFN_C_F165_METR_SWITCH_RECD, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf165,  "���ܱ��ز���������ʱ��"},
    {CMD_AFN_C_F166_METR_MODIFY_RECD, MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf166,  "���ܱ�����޸Ĵ�����ʱ��"},
    {CMD_AFN_C_F167_METR_BUY_USE,     MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf167,  "���ܱ����õ���Ϣ"},
    {CMD_AFN_C_F168_METR_BALANCE,     MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf168,  "���ܱ������Ϣ"},

    // ��22 pn:�������
    {CMD_AFN_C_F169_READ_ROUTE,       MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf169,  "���г����м�·����Ϣ"},
    {CMD_AFN_C_F170_READ_METER,       MT_DIR_S2M, MT_PN_MP,   emtTrans_afn0cf170,  "���г���������Ϣ"},
    /** } ���� **/ 

    /** { ���� **/ 
    // ��1   pn:p0   
    {CMD_AFN_C_F2_TML_CLOCK,         MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ʱ��"},
    {CMD_AFN_C_F3_TML_PARA_STATE,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˲���״̬"},
    {CMD_AFN_C_F4_TML_UPCOM_STATE,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����ͨ��״̬"},
    {CMD_AFN_C_F5_TML_CTRL_SET,      MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˿�������״̬"},
    {CMD_AFN_C_F6_TML_CTRL_STATE,    MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˵�ǰ����״̬"},
    {CMD_AFN_C_F7_TML_EC_VALUE,      MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��¼���������ǰֵ"},
    {CMD_AFN_C_F8_TML_EVNT_FLAG,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն��¼���־״̬"}, 

    // ��2   pn:p0
    {CMD_AFN_C_F9_TML_STATE_BIT,     MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�״̬������λ��־"},
    {CMD_AFN_C_F10_TML_MONTH_FLOW,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն�����վ���ա���ͨ������"},
    {CMD_AFN_C_F11_TML_READ_METER,   MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ն˼��г���״̬��Ϣ"},

    // ��3   pn:�ܼ����
    {CMD_AFN_C_F17_TOTAL_POWER_HAVE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "��ǰ�ܼ��й�����"},
    {CMD_AFN_C_F18_TOTAL_POWER_NONE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "��ǰ�ܼ��޹�����"},
    {CMD_AFN_C_F19_DAY_POWER_HAVE,   MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����ܼ��й�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F20_DAY_POWER_NONE,   MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����ܼ��޹�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F21_MONTH_POWER_HAVE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����ܼ��й�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F22_MONTH_POWER_NONE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "�����ܼ��޹�������(�ܡ����� 1~M)"},
    {CMD_AFN_C_F23_TML_LEFT_POWER,   MT_DIR_M2S, MT_PN_GT,  NULL,                  "�ն˵�ǰʣ�����(��)"},
    {CMD_AFN_C_F24_DOWN_FREZ_VALUE,  MT_DIR_M2S, MT_PN_GT,  NULL,                  "��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ"},
           
    // ��4   pn:�������
    {CMD_AFN_C_F25_POWER_RATE_CUR,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ���༰����/�޹����ʡ���������, �����ѹ��������������������ڹ���"},
    {CMD_AFN_C_F26_DROP_PHASE_LAST,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "A��B��C�������ͳ�����ݼ����һ�ζ����¼"},
    {CMD_AFN_C_F27_METER_PROG_TIME,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��"},
    {CMD_AFN_C_F28_METER_WORD_CBIT,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "�������״̬�ּ����λ��־"},
    {CMD_AFN_C_F29_COPER_IRON_CUR,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰͭ�������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F30_COPER_IRON_LAST,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "��һ�����յ�ǰͭ�������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F31_POWER_CUR,        MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"},
    {CMD_AFN_C_F32_POWER_LAST,       MT_DIR_M2S, MT_PN_MP,  NULL,                  "��һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"},

    // ��5   pn:�������
    {CMD_AFN_C_F33_FRTH_POWR_P1P4_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F34_BACK_POWR_P2P3_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F35_FRTH_DMND_M,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F36_BACK_DMND_M,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "���·�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F37_FRTH_POWR_P1P4_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F38_BACK_POWR_P2P3_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ�������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F39_FRTH_DMND_L,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_C_F40_BACK_DMND_L,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12"},

    // ��6  pn:�������
    {CMD_AFN_C_F41_FRTH_HAVE_POWR_D, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������й����������ܡ�����1��M��"},
    {CMD_AFN_C_F42_FRTH_NONE_POWR_D, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F43_BACK_HAVE_POWR_D, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���շ����й����������ܡ�����1��M��"},
    {CMD_AFN_C_F44_BACK_NONE_POWR_D, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���շ����޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F45_FRTH_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������й����������ܡ�����1��M��"},
    {CMD_AFN_C_F46_FRTH_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������޹����������ܡ�����1��M��"},
    {CMD_AFN_C_F47_BACK_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���·����й����������ܡ�����1��M��"},
    {CMD_AFN_C_F48_BACK_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���·����޹����������ܡ�����1��M��"},
               
    // ��7  pn:�������
    {CMD_AFN_C_F49_CURT_PHASE_ANGLE, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ��ѹ��������λ��"},

    // ��8  pn:�������
    {CMD_AFN_C_F57_CURT_HARM_VALUE,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰA��B��C�����ѹ������2��N��г����Чֵ"},
    {CMD_AFN_C_F58_CURT_HARM_RATE,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰA��B��C�����ѹ������2��N��г��������"},

    // ��9  pn:�������
    {CMD_AFN_C_F65_CURT_CAPA_SWITCH, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ������Ͷ��״̬"},
    {CMD_AFN_C_F66_CURT_CAPA_TIME,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�������ۼƲ���Ͷ��ʱ��ʹ���"},
    {CMD_AFN_C_F67_CURT_CAPA_POWR,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ա����µ������ۼƲ������޹�������"},

    // ��10  pn:ֱ��ģ�����˿ں�   
    {CMD_AFN_C_F73_DC_RLTM_DATA,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "ֱ��ģ����ʵʱ����"}, 

    // ��11 pn:�ܼ����      
    {CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "Сʱ�����ܼ��й�����"},
    {CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "Сʱ�����ܼ��޹�����"},
    {CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "Сʱ�����ܼ��й��ܵ�����"},
    {CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE, MT_DIR_M2S, MT_PN_GT,  NULL,                  "Сʱ�����ܼ��޹��ܵ�����"},

    // ��12 pn:�������
    {CMD_AFN_C_F89_HFRZ_RATE_HAVE,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ�����й�����"},
    {CMD_AFN_C_F90_HFRZ_RATE_HAVE_A, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����A���й�����"},
    {CMD_AFN_C_F91_HFRZ_RATE_HAVE_B, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����B���й�����"},
    {CMD_AFN_C_F92_HFRZ_RATE_HAVE_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����C���й�����"},
    {CMD_AFN_C_F93_HFRZ_RATE_NONE,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ�����޹�����"},
    {CMD_AFN_C_F94_HFRZ_RATE_NONE_A, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����A���޹�����"},
    {CMD_AFN_C_F95_HFRZ_RATE_NONE_B, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����B���޹�����"},
    {CMD_AFN_C_F96_HFRZ_RATE_NONE_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����C���޹�����"},

    // ��13 pn:�������
    {CMD_AFN_C_F97_HFRZ_VOLT_A,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����A���ѹ"},
    {CMD_AFN_C_F98_HFRZ_VOLT_B,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����B���ѹ"},
    {CMD_AFN_C_F99_HFRZ_VOLT_C,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����C���ѹ"},
    {CMD_AFN_C_F100_HFRZ_ELEC_A,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����A�����"},
    {CMD_AFN_C_F101_HFRZ_ELEC_B,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����B�����"},
    {CMD_AFN_C_F102_HFRZ_ELEC_C,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����C�����"},
    {CMD_AFN_C_F103_HFRZ_ELEC_ZERO,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ�����������"},

    // ��14 pn:�������
    {CMD_AFN_C_F105_HFRZ_FRTH_HAVE,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���������й��ܵ�����"},
    {CMD_AFN_C_F106_HFRZ_FRTH_NONE,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���������޹��ܵ�����"},
    {CMD_AFN_C_F107_HFRZ_BACK_HAVE,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���ᷴ���й��ܵ�����"},
    {CMD_AFN_C_F108_HFRZ_BACK_NONE,  MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���ᷴ���޹��ܵ�����"},
    {CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S,MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���������й��ܵ���ʾֵ"},
    {CMD_AFN_C_F110_HFRZ_FRTH_NONE_S,MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���������޹��ܵ���ʾֵ"},
    {CMD_AFN_C_F111_HFRZ_BACK_HAVE_S,MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���ᷴ���й��ܵ���ʾֵ"},
    {CMD_AFN_C_F112_HFRZ_BACK_NONE_S,MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ���ᷴ���޹��ܵ���ʾֵ"}, 

    // ��15 pn:�������
    {CMD_AFN_C_F113_HFRZ_FACT_TOTAL, MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ�����ܹ�������"},
    {CMD_AFN_C_F114_HFRZ_FACT_A,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����A�๦������"},
    {CMD_AFN_C_F115_HFRZ_FACT_B,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����B�๦������"},
    {CMD_AFN_C_F116_HFRZ_FACT_C,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����C�๦������"},

    // ��16 pn:�������
    {CMD_AFN_C_F121_HFRZ_DC_VALUE,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "Сʱ����ֱ��ģ����"},

    // ��17 pn:������� C��ʾ��ǰcurrent
    {CMD_AFN_C_F129_FRTH_HAVE_POWR_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�����й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F130_FRTH_NONE_POWR_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F131_BACK_HAVE_POWR_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�����й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F132_BACK_NONE_POWR_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F133_NONE_POWR_P1_C,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰһ�����޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F134_NONE_POWR_P2_C,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F135_NONE_POWR_P3_C,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F136_NONE_POWR_P4_C,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "��ǰ�������޹�����ʾֵ���ܡ�����1��M��"},

    // ��18 pn:������� L��ʾ��һ�����ջ����� Last Month 
    {CMD_AFN_C_F137_FRTH_HAVE_POWR_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F138_FRTH_NONE_POWR_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F139_BACK_HAVE_POWR_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F140_BACK_NONE_POWR_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F141_NONE_POWR_P1_L,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F142_NONE_POWR_P2_L,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F143_NONE_POWR_P3_L,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F144_NONE_POWR_P4_L,   MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"},

    // ��19 pn:�������
    {CMD_AFN_C_F145_FRTH_HAVE_DMND_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F146_FRTH_NONE_DMND_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���������޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F147_BACK_HAVE_DMND_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���·����й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F148_BACK_NONE_DMND_C, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���·����޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F149_FRTH_HAVE_DMND_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F150_FRTH_NONE_DMND_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F151_BACK_HAVE_DMND_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"},
    {CMD_AFN_C_F152_BACK_NONE_DMND_L, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"},

    // ��20 pn:�������
    {CMD_AFN_C_F153_FREZ_ZONE_1,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "��һʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F154_FREZ_ZONE_2,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "�ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F155_FREZ_ZONE_3,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F156_FREZ_ZONE_4,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F157_FREZ_ZONE_5,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F158_FREZ_ZONE_6,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F159_FREZ_ZONE_7,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_C_F160_FREZ_ZONE_8,      MT_DIR_M2S, MT_PN_MP,  NULL,                  "�ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},

    // ��21 pn:�������
    {CMD_AFN_C_F161_METR_REMOTE_CTRL, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"},
    {CMD_AFN_C_F165_METR_SWITCH_RECD, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ��ز���������ʱ��"},
    {CMD_AFN_C_F166_METR_MODIFY_RECD, MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ�����޸Ĵ�����ʱ��"},
    {CMD_AFN_C_F167_METR_BUY_USE,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ����õ���Ϣ"},
    {CMD_AFN_C_F168_METR_BALANCE,     MT_DIR_M2S, MT_PN_MP,  NULL,                  "���ܱ������Ϣ"},

    // ��22 pn:�������
    {CMD_AFN_C_F169_READ_ROUTE,       MT_DIR_M2S, MT_PN_MP,  NULL,                  "���г����м�·����Ϣ"},
    {CMD_AFN_C_F170_READ_METER,       MT_DIR_M2S, MT_PN_MP,  NULL,                  "���г���������Ϣ"},
    /** } ���� **/ 
    ///*}

     /*******************************
     *  (12) ����2������(AFN=0DH��
     *
     *  ����: ���ݲ�ͬ����,�ֱ�������1�����ݺ�����2���������б��Ľ���Ӧ��
     *  ����: ������
     *  ����: ����Ҫ
     *  
    {*///
    /** { ���� **/ 
    // ��1  ����ʾֵ�����������������      pn:�������   (�ն���)    _D ��ʾ�ն��� freeze_day
    {CMD_AFN_D_F1_FRTH_POWR_P1P4_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df1,     "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F2_BACK_POWR_P2P3_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df2,     "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F3_FRTH_DMND_TIME_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df3,     "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F4_BACK_DMND_TIME_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df4,     "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F5_FRTH_HAVE_POWR_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df5,     "�����й����������ܡ�����1��M��"},
    {CMD_AFN_D_F6_FRTH_NONE_POWR_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df6,     "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F7_BACK_HAVE_POWR_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df7,     "�����й����������ܡ�����1��M��"}, 
    {CMD_AFN_D_F8_BACK_NONE_POWR_D,    MT_DIR_S2M, MT_PN_P0,  emtTrans_afn0df8,     "�����޹����������ܡ�����1��M��"},

    // ��2  ����ʾֵ��������� pn:������� (�����ն���) _R ��ʾ������ freeze_read_meter
    {CMD_AFN_D_F9_FRTH_POWR_P1P4_R,    MT_DIR_M2S, MT_PN_MP,  emtTrans_afn0df9,     "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F10_BACK_POWR_P2P3_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_afn0df10,    "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F11_FRTH_DMND_TIME_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_afn0df11,    "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F12_BACK_DMND_TIME_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_afn0df12,    "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
                
    // ��3  ����ʾֵ����������������� pn:������� (�¶���) _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F17_FRTH_POWR_P1P4_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df17,    "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F18_BACK_POWR_P2P3_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df18,    "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12"},
    {CMD_AFN_D_F19_FRTH_DMND_TIME_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df19,    "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F20_BACK_DMND_TIME_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df20,    "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F21_FRTH_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df21,    "�����й����������ܡ�����1��M��"},
    {CMD_AFN_D_F22_FRTH_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df22,    "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F23_BACK_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df23,    "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F24_BACK_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_afn0df24,    "�����޹����������ܡ�����1��M��"},
            
    // ��4   pn:������� �ն���   _D ��ʾ�ն��� freeze_day
    {CMD_AFN_D_F25_POWR_FRZE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df25,    "���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��"},
    {CMD_AFN_D_F26_DMND_FRZE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df26,    "���ܼ������������������ʱ��"},
    {CMD_AFN_D_F27_VOLT_FRZE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df27,    "�յ�ѹͳ������"},
    {CMD_AFN_D_F28_UBLN_OVER_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df28,    "�ղ�ƽ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F29_ELEC_OVER_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df29,    "�յ���Խ��ͳ��"},
    {CMD_AFN_D_F30_POWR_RATE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df30,    "�����ڹ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F31_LOAD_RATE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df31,    "�ո�������ͳ��"}, 
    {CMD_AFN_D_F32_METR_DROP_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df32,    "�յ��ܱ��������"},

    // ��5   pn:�������  _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F33_POWR_FRZE_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df33,    "���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��"},
    {CMD_AFN_D_F34_DMND_FRZE_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df34,    "���ܼ������й��������������ʱ��"},
    {CMD_AFN_D_F35_VOLT_FRZE_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df35,    "�µ�ѹͳ������"},
    {CMD_AFN_D_F36_UBLN_OVER_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df36,    "�²�ƽ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F37_ELEC_OVER_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df37,    "�µ���Խ��ͳ��"},
    {CMD_AFN_D_F38_POWR_RATE_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df38,    "�����ڹ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F39_LOAD_RATE_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df39,    "�¸�������ͳ��"}, 

    // ��6  pn:�������   _D ��ʾ�ն��� freeze_day _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F41_CAPA_TIME_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df41,    "������Ͷ���ۼ�ʱ��ʹ���"},
    {CMD_AFN_D_F42_CAPA_NONE_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df42,    "�ա��µ������ۼƲ������޹�������"},
    {CMD_AFN_D_F43_FACT_TIME_D,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df43,    "�չ������������ۼ�ʱ��"},
    {CMD_AFN_D_F44_FACT_TIME_M,      MT_DIR_S2M, MT_PN_MP,    emtTrans_afn0df44,    "�¹������������ۼ�ʱ��"},
    {CMD_AFN_D_F45_COPR_IRON_D,      MT_DIR_S2M, MT_PN_MP,    NULL,        "ͭ�������й�����ʾֵ"},
    {CMD_AFN_D_F46_COPR_IRON_M,      MT_DIR_S2M, MT_PN_MP,    NULL,        "ͭ�������й�����ʾֵ"},

    // ��7 �ն�ͳ������ pn:������� _D ��ʾ�ն��� freeze_day _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F49_TML_ONOF_D,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն��չ���ʱ�䡢�ո�λ�ۼƴ���"},
    {CMD_AFN_D_F50_TML_CTRL_D,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն��տ���ͳ������"},
    {CMD_AFN_D_F51_TML_ONOF_M,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն��¹���ʱ�䡢�¸�λ�ۼƴ���"},
    {CMD_AFN_D_F52_TML_CTRL_M,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն��¿���ͳ������"},
    {CMD_AFN_D_F53_TML_FLOW_D,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն�����վ��ͨ������"},
    {CMD_AFN_D_F54_TML_FLOW_M,       MT_DIR_S2M, MT_PN_P0,    NULL,        "�ն�����վ��ͨ������"},

    // ��8  �ܼ���ͳ������  pn:�ܼ����
    {CMD_AFN_D_F57_GRUP_RATE_D,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �ն���"},
    {CMD_AFN_D_F58_GRUP_HAVE_D,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ������ۼ��й����������ܡ�����1��M���ն���"},
    {CMD_AFN_D_F59_GRUP_NONE_D,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ������ۼ��޹����������ܡ�����1��M���ն���"},
    {CMD_AFN_D_F60_GRUP_RATE_M,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �¶���"},
    {CMD_AFN_D_F61_GRUP_HAVE_M,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ������ۼ��й����������ܡ�����1��M���¶���"},
    {CMD_AFN_D_F62_GRUP_NONE_M,      MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ������ۼ��޹����������ܡ�����1��M���¶���"},

    // ��9  �ܼ���Խ��ͳ������ pn:�ܼ����
    {CMD_AFN_D_F65_GRUP_RATE_OVER,   MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ��鳬���ʶ�ֵ�����ۼ�ʱ�䡢���ۼƵ�����  �¶���"},
    {CMD_AFN_D_F66_GRUP_POWR_OVER,   MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ��鳬�µ�������ֵ�����ۼ�ʱ�䡢�ۼƵ����� �¶���"},

    // ��10 �ܼ�������         pn:�ܼ����    
    {CMD_AFN_D_F73_CURVE_RATE_HAVE,  MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����й���������"},
    {CMD_AFN_D_F74_CURVE_RATE_NONE,  MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����޹���������"},
    {CMD_AFN_D_F75_CURVE_POWR_HAVE,  MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����й�����������"},
    {CMD_AFN_D_F76_CURVE_POWR_NONE,  MT_DIR_S2M, MT_PN_GT,    NULL,        "�ܼ����޹�����������"},

    // ��11  �������� pn:�������      
    {CMD_AFN_D_F81_CURVE_HAVE,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "�й���������"},
    {CMD_AFN_D_F82_CURVE_HAVE_A,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "A���й���������"},
    {CMD_AFN_D_F83_CURVE_HAVE_B,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "B���й���������"},
    {CMD_AFN_D_F84_CURVE_HAVE_C,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "C���й���������"},
    {CMD_AFN_D_F85_CURVE_NONE,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "�޹���������"},
    {CMD_AFN_D_F86_CURVE_NONE_A,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "A���޹���������"},
    {CMD_AFN_D_F87_CURVE_NONE_B,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "B���޹���������"},
    {CMD_AFN_D_F88_CURVE_NONE_C,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "C���޹���������"},

    // ��12 ��ѹ�������� pn:�������
    {CMD_AFN_D_F89_CURVE_VOLT_A,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "A���ѹ����"},
    {CMD_AFN_D_F90_CURVE_VOLT_B,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "B���ѹ����"},
    {CMD_AFN_D_F91_CURVE_VOLT_C,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "C���ѹ����"},
    {CMD_AFN_D_F92_CURVE_ELEC_A,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "A���������"},
    {CMD_AFN_D_F93_CURVE_ELEC_B,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "B���������"},
    {CMD_AFN_D_F94_CURVE_ELEC_C,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "C���������"},
    {CMD_AFN_D_F95_CURVE_ZERO_E,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����������"},

    // ��13 �ܵ��������ܵ���ʾֵ���� pn:�������
    {CMD_AFN_D_F97_CURVE_FRTH_HAVE,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��ܵ���������"},
    {CMD_AFN_D_F98_CURVE_FRTH_NONE,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��ܵ���������"},
    {CMD_AFN_D_F98_CURVE_BACK_HAVE,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��ܵ���������"},
    {CMD_AFN_D_F100_CURVE_BACK_HAVE, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��ܵ���������"},
    {CMD_AFN_D_F101_CURVE_FRTH_HAVE, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F102_CURVE_FRTH_NONE, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F103_CURVE_BACK_HAVE, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F104_CURVE_BACK_NONE, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��ܵ���ʾֵ����"},

    // ��14 ������������ѹ��λ�����ߡ�������λ������ pn:�������
    {CMD_AFN_D_F105_CURVE_FACTOR_T,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ܹ�����������"},
    {CMD_AFN_D_F106_CURVE_FACTOR_A,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "A�๦����������"},
    {CMD_AFN_D_F107_CURVE_FACTOR_B,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "B�๦����������"},
    {CMD_AFN_D_F108_CURVE_FACTOR_C,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "C�๦����������"},
    {CMD_AFN_D_F109_ANGLE_CURVE_VOLT,MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F110_ANGLE_CURVE_ELEC,MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��ܵ���ʾֵ����"},

    // ��15 г�����ͳ������ pn:�������
    {CMD_AFN_D_F113_ELEC_HARM_TIME_A,MT_DIR_S2M, MT_PN_MP,  NULL,                  "A��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F114_ELEC_HARM_TIME_B,MT_DIR_S2M, MT_PN_MP,  NULL,                  "B��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F115_ELEC_HARM_TIME_C,MT_DIR_S2M, MT_PN_MP,  NULL,                  "C��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F116_VOLT_HARM_TIME_A,MT_DIR_S2M, MT_PN_MP,  NULL,                  "A��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F117_VOLT_HARM_TIME_B,MT_DIR_S2M, MT_PN_MP,  NULL,                  "B��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F118_VOLT_HARM_TIME_C,MT_DIR_S2M, MT_PN_MP,  NULL,                  "C��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},

    // ��16 г��Խ��ͳ������ pn:�������
    {CMD_AFN_D_F121_HARM_OVER_A,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "A��г��Խ����ͳ������ �ն���"},
    {CMD_AFN_D_F122_HARM_OVER_B,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "B��г��Խ����ͳ������ �ն���"},
    {CMD_AFN_D_F123_HARM_OVER_C,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "C��г��Խ����ͳ������ �ն���"},

    // ��17 ֱ��ģ��������     pn:ֱ��ģ�����˿ں�
    {CMD_AFN_D_F129_DC_D,            MT_DIR_S2M, MT_PN_MP,  NULL,                  "ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F130_DC_M,            MT_DIR_S2M, MT_PN_MP,  NULL,                  "ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �¶���"},

    // ��18 ֱ��ģ������������ pn:�������
    {CMD_AFN_D_F138_DC_CURVE,        MT_DIR_S2M, MT_PN_MP,  NULL,                  "ֱ��ģ������������"},

    // ��19 �ĸ������޹��ܵ���ʾֵ���� pn:�������
    {CMD_AFN_D_F145_CURVE_PHASE_1,   MT_DIR_S2M, MT_PN_MP,  NULL,                  "һ�����޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F146_CURVE_PHASE_4,   MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F147_CURVE_PHASE_2,   MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F148_CURVE_PHASE_3,   MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹��ܵ���ʾֵ����"},

    // ��20 �������ʾֵ pn:�������
    {CMD_AFN_D_F153_FRTH_HAVE_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ն�����������й�����ʾֵ �ն���"},
    {CMD_AFN_D_F154_FRTH_NONE_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ն�����������޹�����ʾֵ �ն���"},
    {CMD_AFN_D_F155_BACK_HAVE_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ն�����෴���й�����ʾֵ �ն���"},
    {CMD_AFN_D_F156_BACK_NONE_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ն�����෴���޹�����ʾֵ �ն���"},
    {CMD_AFN_D_F157_FRTH_HAVE_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�¶�����������й�����ʾֵ �¶���"},
    {CMD_AFN_D_F158_FRTH_NONE_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�¶�����������޹�����ʾֵ �¶���"},
    {CMD_AFN_D_F159_BACK_HAVE_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�¶�����෴���й�����ʾֵ �¶���"},
    {CMD_AFN_D_F160_BACK_NONE_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�¶�����෴���޹�����ʾֵ �¶���"},

    // ��21 pn:�������
    {CMD_AFN_D_F161_HAVE_FRTH_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M�� �ն���"},
    {CMD_AFN_D_F162_NONE_FRTM_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F163_HAVE_BACK_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F164_NONE_BACK_D,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F165_NONE_D_PHASE_1,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "һ�����޹�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F166_NONE_D_PHASE_2,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F167_NONE_D_PHASE_3,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M���ն��� �¶���"},
    {CMD_AFN_D_F168_NONE_D_PHASE_4,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M���ն��� �¶���"},

    // ��22 pn:������� �����ն���
    {CMD_AFN_D_F169_HAVE_FRTH_R,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M��  �����ն���"},
    {CMD_AFN_D_F170_NONE_FRTM_R,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M�� �����ն���"},
    {CMD_AFN_D_F171_HAVE_BACK_R,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M��  �����ն���"},
    {CMD_AFN_D_F172_NONE_BACK_R,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F173_NONE_R_PHASE_1,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "һ�����޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F174_NONE_R_PHASE_2,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F175_NONE_R_PHASE_3,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F176_NONE_R_PHASE_4,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},

    // ��23 pn:�������
    {CMD_AFN_D_F177_HAVE_FRTH_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F178_NONE_FRTM_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���"},
    {CMD_AFN_D_F179_HAVE_BACK_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F180_NONE_BACK_M,     MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���"},
    {CMD_AFN_D_F181_NONE_M_PHASE_1,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "һ�����޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F182_NONE_M_PHASE_2,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F183_NONE_M_PHASE_3,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F184_NONE_M_PHASE_4,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},

    // ��24 pn:�������
    {CMD_AFN_D_F185_HAVE_DMND_FRTH_D, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F186_NONE_DMND_FRTH_D, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F187_HAVE_DMND_BACK_D, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F188_NONE_DMND_BACK_D, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F189_HAVE_DMND_FRTH_R, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F190_NONE_DMND_FRTH_R, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F191_HAVE_DMND_BACK_R, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F192_NONE_DMND_BACK_R, MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M�������ն���"},

    // ��25 pn:�������
    {CMD_AFN_D_F193_HAVE_DMND_FRTH_M,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F194_NONE_DMND_FRTH_M,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F195_HAVE_DMND_BACK_M,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����й��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F196_NONE_DMND_BACK_M,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "�����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���"},

    // ��26 pn:�������
    {CMD_AFN_D_F201_FREZ_ZONE_1,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "��һʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F202_FREZ_ZONE_2,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F203_FREZ_ZONE_3,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F204_FREZ_ZONE_4,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F205_FREZ_ZONE_5,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F206_FREZ_ZONE_6,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F207_FREZ_ZONE_7,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F208_FREZ_ZONE_8,       MT_DIR_S2M, MT_PN_MP,  NULL,                  "�ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},

    // ��27 pn:�������
    {CMD_AFN_D_F209_METR_REMOTE_INFO,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"},
    {CMD_AFN_D_F213_METR_SWITCH_INFO,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "���ܱ��ز���������ʱ��"},
    {CMD_AFN_D_F214_METR_MODIFY_INFO,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "���ܱ�����޸Ĵ�����ʱ��"},
    {CMD_AFN_D_F215_METR_BUY_USR,      MT_DIR_S2M, MT_PN_MP,  NULL,                  "���ܱ����õ���Ϣ"},
    {CMD_AFN_D_F216_METR_BALANCE,      MT_DIR_S2M, MT_PN_MP,  NULL,                  "���ܱ������Ϣ"},

    // ��27 pn:�������
    {CMD_AFN_D_F217_WHITE_YAWP_CURVE,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "̨�����г����ز����ڵ����������"},
    {CMD_AFN_D_F218_COLOR_YAWP_CURVE,  MT_DIR_S2M, MT_PN_MP,  NULL,                  "̨�����г����ز����ڵ�ɫ��������"},
    /** } ���� **/ 

    /** { ���� **/ 
    // ��1  ����ʾֵ�����������������      pn:�������   (�ն���)    _D ��ʾ�ն��� freeze_day
    {CMD_AFN_D_F1_FRTH_POWR_P1P4_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F2_BACK_POWR_P2P3_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F3_FRTH_DMND_TIME_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F4_BACK_DMND_TIME_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F5_FRTH_HAVE_POWR_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "�����й����������ܡ�����1��M��"},
    {CMD_AFN_D_F6_FRTH_NONE_POWR_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F7_BACK_HAVE_POWR_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "�����й����������ܡ�����1��M��"}, 
    {CMD_AFN_D_F8_BACK_NONE_POWR_D,    MT_DIR_M2S, MT_PN_P0,  emtTrans_td_d,        "�����޹����������ܡ�����1��M��"},

    // ��2  ����ʾֵ��������� pn:������� (�����ն���) _R ��ʾ������ freeze_read_meter
    {CMD_AFN_D_F9_FRTH_POWR_P1P4_R,    MT_DIR_M2S, MT_PN_MP,  emtTrans_td_d,        "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F10_BACK_POWR_P2P3_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_td_d,        "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F11_FRTH_DMND_TIME_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_td_d,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F12_BACK_DMND_TIME_R,   MT_DIR_M2S, MT_PN_MP,  emtTrans_td_d,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
                
    // ��3  ����ʾֵ����������������� pn:������� (�¶���) _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F17_FRTH_POWR_P1P4_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F18_BACK_POWR_P2P3_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12"},
    {CMD_AFN_D_F19_FRTH_DMND_TIME_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F20_BACK_DMND_TIME_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��"},
    {CMD_AFN_D_F21_FRTH_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����й����������ܡ�����1��M��"},
    {CMD_AFN_D_F22_FRTH_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F23_BACK_HAVE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����޹����������ܡ�����1��M��"},
    {CMD_AFN_D_F24_BACK_NONE_POWR_M, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����޹����������ܡ�����1��M��"},
            
    // ��4   pn:������� �ն���   _D ��ʾ�ն��� freeze_day
    {CMD_AFN_D_F25_POWR_FRZE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��"},
    {CMD_AFN_D_F26_DMND_FRZE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "���ܼ������������������ʱ��"},
    {CMD_AFN_D_F27_VOLT_FRZE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�յ�ѹͳ������"},
    {CMD_AFN_D_F28_UBLN_OVER_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ղ�ƽ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F29_ELEC_OVER_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�յ���Խ��ͳ��"},
    {CMD_AFN_D_F30_POWR_RATE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�����ڹ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F31_LOAD_RATE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ո�������ͳ��"}, 
    {CMD_AFN_D_F32_METR_DROP_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�յ��ܱ��������"},

    // ��5   pn:�������  _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F33_POWR_FRZE_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��"},
    {CMD_AFN_D_F34_DMND_FRZE_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "���ܼ������й��������������ʱ��"},
    {CMD_AFN_D_F35_VOLT_FRZE_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�µ�ѹͳ������"},
    {CMD_AFN_D_F36_UBLN_OVER_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�²�ƽ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F37_ELEC_OVER_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�µ���Խ��ͳ��"},
    {CMD_AFN_D_F38_POWR_RATE_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�����ڹ���Խ���ۼ�ʱ��"},
    {CMD_AFN_D_F39_LOAD_RATE_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�¸�������ͳ��"}, 

    // ��6  pn:�������   _D ��ʾ�ն��� freeze_day _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F41_CAPA_TIME_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "������Ͷ���ۼ�ʱ��ʹ���"},
    {CMD_AFN_D_F42_CAPA_NONE_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ա��µ������ۼƲ������޹�������"},
    {CMD_AFN_D_F43_FACT_TIME_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�չ������������ۼ�ʱ��"},
    {CMD_AFN_D_F44_FACT_TIME_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�¹������������ۼ�ʱ��"},
    {CMD_AFN_D_F45_COPR_IRON_D,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "ͭ�������й�����ʾֵ"},
    {CMD_AFN_D_F46_COPR_IRON_M,      MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "ͭ�������й�����ʾֵ"},

    // ��7 �ն�ͳ������ pn:������� _D ��ʾ�ն��� freeze_day _M ��ʾ�¶��� freeze_month
    {CMD_AFN_D_F49_TML_ONOF_D,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ն��չ���ʱ�䡢�ո�λ�ۼƴ���"},
    {CMD_AFN_D_F50_TML_CTRL_D,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ն��տ���ͳ������"},
    {CMD_AFN_D_F51_TML_ONOF_M,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�ն��¹���ʱ�䡢�¸�λ�ۼƴ���"},
    {CMD_AFN_D_F52_TML_CTRL_M,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�ն��¿���ͳ������"},
    {CMD_AFN_D_F53_TML_FLOW_D,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_d,        "�ն�����վ��ͨ������"},
    {CMD_AFN_D_F54_TML_FLOW_M,       MT_DIR_M2S, MT_PN_P0,    emtTrans_td_m,        "�ն�����վ��ͨ������"},

    // ��8  �ܼ���ͳ������  pn:�ܼ����
    {CMD_AFN_D_F57_GRUP_RATE_D,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_d,        "�ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �ն���"},
    {CMD_AFN_D_F58_GRUP_HAVE_D,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_d,        "�ܼ������ۼ��й����������ܡ�����1��M���ն���"},
    {CMD_AFN_D_F59_GRUP_NONE_D,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_d,        "�ܼ������ۼ��޹����������ܡ�����1��M���ն���"},
    {CMD_AFN_D_F60_GRUP_RATE_M,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_m,        "�ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �¶���"},
    {CMD_AFN_D_F61_GRUP_HAVE_M,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_m,        "�ܼ������ۼ��й����������ܡ�����1��M���¶���"},
    {CMD_AFN_D_F62_GRUP_NONE_M,      MT_DIR_M2S, MT_PN_GT,    emtTrans_td_m,        "�ܼ������ۼ��޹����������ܡ�����1��M���¶���"},

    // ��9  �ܼ���Խ��ͳ������ pn:�ܼ����
    {CMD_AFN_D_F65_GRUP_RATE_OVER,   MT_DIR_M2S, MT_PN_GT,    emtTrans_td_m,        "�ܼ��鳬���ʶ�ֵ�����ۼ�ʱ�䡢���ۼƵ�����  �¶���"},
    {CMD_AFN_D_F66_GRUP_POWR_OVER,   MT_DIR_M2S, MT_PN_GT,    emtTrans_td_m,        "�ܼ��鳬�µ�������ֵ�����ۼ�ʱ�䡢�ۼƵ����� �¶���"},

    // ��10 �ܼ�������         pn:�ܼ����    
    {CMD_AFN_D_F73_CURVE_RATE_HAVE,  MT_DIR_M2S, MT_PN_GT,    emtTrans_td_c,        "�ܼ����й���������"},
    {CMD_AFN_D_F74_CURVE_RATE_NONE,  MT_DIR_M2S, MT_PN_GT,    emtTrans_td_c,        "�ܼ����޹���������"},
    {CMD_AFN_D_F75_CURVE_POWR_HAVE,  MT_DIR_M2S, MT_PN_GT,    emtTrans_td_c,        "�ܼ����й�����������"},
    {CMD_AFN_D_F76_CURVE_POWR_NONE,  MT_DIR_M2S, MT_PN_GT,    emtTrans_td_c,        "�ܼ����޹�����������"},

    // ��11  �������� pn:�������      
    {CMD_AFN_D_F81_CURVE_HAVE,       MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�й���������"},
    {CMD_AFN_D_F82_CURVE_HAVE_A,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "A���й���������"},
    {CMD_AFN_D_F83_CURVE_HAVE_B,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "B���й���������"},
    {CMD_AFN_D_F84_CURVE_HAVE_C,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "C���й���������"},
    {CMD_AFN_D_F85_CURVE_NONE,       MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�޹���������"},
    {CMD_AFN_D_F86_CURVE_NONE_A,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "A���޹���������"},
    {CMD_AFN_D_F87_CURVE_NONE_B,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "B���޹���������"},
    {CMD_AFN_D_F88_CURVE_NONE_C,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "C���޹���������"},

    // ��12 ��ѹ�������� pn:�������
    {CMD_AFN_D_F89_CURVE_VOLT_A,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "A���ѹ����"},
    {CMD_AFN_D_F90_CURVE_VOLT_B,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "B���ѹ����"},
    {CMD_AFN_D_F91_CURVE_VOLT_C,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "C���ѹ����"},
    {CMD_AFN_D_F92_CURVE_ELEC_A,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "A���������"},
    {CMD_AFN_D_F93_CURVE_ELEC_B,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "B���������"},
    {CMD_AFN_D_F94_CURVE_ELEC_C,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "C���������"},
    {CMD_AFN_D_F95_CURVE_ZERO_E,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����������"},

    // ��13 �ܵ��������ܵ���ʾֵ���� pn:�������
    {CMD_AFN_D_F97_CURVE_FRTH_HAVE,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����й��ܵ���������"},
    {CMD_AFN_D_F98_CURVE_FRTH_NONE,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����޹��ܵ���������"},
    {CMD_AFN_D_F98_CURVE_BACK_HAVE,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����й��ܵ���������"},
    {CMD_AFN_D_F100_CURVE_BACK_HAVE, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����޹��ܵ���������"},
    {CMD_AFN_D_F101_CURVE_FRTH_HAVE, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F102_CURVE_FRTH_NONE, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F103_CURVE_BACK_HAVE, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F104_CURVE_BACK_NONE, MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����޹��ܵ���ʾֵ����"},

    // ��14 ������������ѹ��λ�����ߡ�������λ������ pn:�������
    {CMD_AFN_D_F105_CURVE_FACTOR_T,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�ܹ�����������"},
    {CMD_AFN_D_F106_CURVE_FACTOR_A,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "A�๦����������"},
    {CMD_AFN_D_F107_CURVE_FACTOR_B,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "B�๦����������"},
    {CMD_AFN_D_F108_CURVE_FACTOR_C,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "C�๦����������"},
    {CMD_AFN_D_F109_ANGLE_CURVE_VOLT,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����й��ܵ���ʾֵ����"},
    {CMD_AFN_D_F110_ANGLE_CURVE_ELEC,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�����޹��ܵ���ʾֵ����"},

    // ��15 г�����ͳ������ pn:�������
    {CMD_AFN_D_F113_ELEC_HARM_TIME_A,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "A��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F114_ELEC_HARM_TIME_B,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "B��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F115_ELEC_HARM_TIME_C,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "C��2��19��г�����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F116_VOLT_HARM_TIME_A,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "A��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F117_VOLT_HARM_TIME_B,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "B��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F118_VOLT_HARM_TIME_C,MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "C��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���"},

    // ��16 г��Խ��ͳ������ pn:�������
    {CMD_AFN_D_F121_HARM_OVER_A,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "A��г��Խ����ͳ������ �ն���"},
    {CMD_AFN_D_F122_HARM_OVER_B,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "B��г��Խ����ͳ������ �ն���"},
    {CMD_AFN_D_F123_HARM_OVER_C,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "C��г��Խ����ͳ������ �ն���"},

    // ��17 ֱ��ģ��������     pn:ֱ��ģ�����˿ں�
    {CMD_AFN_D_F129_DC_D,            MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �ն���"},
    {CMD_AFN_D_F130_DC_M,            MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �¶���"},

    // ��18 ֱ��ģ������������ pn:�������
    {CMD_AFN_D_F138_DC_CURVE,        MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "ֱ��ģ������������"},

    // ��19 �ĸ������޹��ܵ���ʾֵ���� pn:�������
    {CMD_AFN_D_F145_CURVE_PHASE_1,   MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "һ�����޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F146_CURVE_PHASE_4,   MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�������޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F147_CURVE_PHASE_2,   MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�������޹��ܵ���ʾֵ����"},
    {CMD_AFN_D_F148_CURVE_PHASE_3,   MT_DIR_M2S, MT_PN_MP,    emtTrans_td_c,        "�������޹��ܵ���ʾֵ����"},

    // ��20 �������ʾֵ pn:�������
    {CMD_AFN_D_F153_FRTH_HAVE_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�ն�����������й�����ʾֵ �ն���"},
    {CMD_AFN_D_F154_FRTH_NONE_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�ն�����������޹�����ʾֵ �ն���"},
    {CMD_AFN_D_F155_BACK_HAVE_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�ն�����෴���й�����ʾֵ �ն���"},
    {CMD_AFN_D_F156_BACK_NONE_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�ն�����෴���޹�����ʾֵ �ն���"},
    {CMD_AFN_D_F157_FRTH_HAVE_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�¶�����������й�����ʾֵ �¶���"},
    {CMD_AFN_D_F158_FRTH_NONE_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�¶�����������޹�����ʾֵ �¶���"},
    {CMD_AFN_D_F159_BACK_HAVE_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�¶�����෴���й�����ʾֵ �¶���"},
    {CMD_AFN_D_F160_BACK_NONE_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�¶�����෴���޹�����ʾֵ �¶���"},

    // ��21 pn:�������
    {CMD_AFN_D_F161_HAVE_FRTH_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����й�����ʾֵ���ܡ�����1��M�� �ն���"},
    {CMD_AFN_D_F162_NONE_FRTM_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F163_HAVE_BACK_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����й�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F164_NONE_BACK_D,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F165_NONE_D_PHASE_1,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "һ�����޹�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F166_NONE_D_PHASE_2,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M���ն���"},
    {CMD_AFN_D_F167_NONE_D_PHASE_3,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M���ն��� �¶���"},
    {CMD_AFN_D_F168_NONE_D_PHASE_4,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M���ն��� �¶���"},

    // ��22 pn:������� �����ն���
    {CMD_AFN_D_F169_HAVE_FRTH_R,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����й�����ʾֵ���ܡ�����1��M��  �����ն���"},
    {CMD_AFN_D_F170_NONE_FRTM_R,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M�� �����ն���"},
    {CMD_AFN_D_F171_HAVE_BACK_R,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����й�����ʾֵ���ܡ�����1��M��  �����ն���"},
    {CMD_AFN_D_F172_NONE_BACK_R,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F173_NONE_R_PHASE_1,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "һ�����޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F174_NONE_R_PHASE_2,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F175_NONE_R_PHASE_3,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F176_NONE_R_PHASE_4,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_d,        "�������޹�����ʾֵ���ܡ�����1��M�������ն���"},

    // ��23 pn:�������
    {CMD_AFN_D_F177_HAVE_FRTH_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����й�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F178_NONE_FRTM_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���"},
    {CMD_AFN_D_F179_HAVE_BACK_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����й�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F180_NONE_BACK_M,     MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���"},
    {CMD_AFN_D_F181_NONE_M_PHASE_1,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "һ�����޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F182_NONE_M_PHASE_2,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F183_NONE_M_PHASE_3,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F184_NONE_M_PHASE_4,  MT_DIR_M2S, MT_PN_MP,    emtTrans_td_m,        "�������޹�����ʾֵ���ܡ�����1��M�� �¶���"},

    // ��24 pn:�������
    {CMD_AFN_D_F185_HAVE_DMND_FRTH_D, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����й��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F186_NONE_DMND_FRTH_D, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����޹��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F187_HAVE_DMND_BACK_D, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����й��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F188_NONE_DMND_BACK_D, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����޹��������������ʱ�䣨�ܡ�����1��M���ն���"},
    {CMD_AFN_D_F189_HAVE_DMND_FRTH_R, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����й��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F190_NONE_DMND_FRTH_R, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����޹��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F191_HAVE_DMND_BACK_R, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����й��������������ʱ�䣨�ܡ�����1��M�������ն���"},
    {CMD_AFN_D_F192_NONE_DMND_BACK_R, MT_DIR_M2S, MT_PN_MP,   emtTrans_td_d,        "�����޹��������������ʱ�䣨�ܡ�����1��M�������ն���"},

    // ��25 pn:�������
    {CMD_AFN_D_F193_HAVE_DMND_FRTH_M,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�����й��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F194_NONE_DMND_FRTH_M,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F195_HAVE_DMND_BACK_M,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�����й��������������ʱ�䣨�ܡ�����1��M�� �¶���"},
    {CMD_AFN_D_F196_NONE_DMND_BACK_M,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���"},

    // ��26 pn:�������
    {CMD_AFN_D_F201_FREZ_ZONE_1,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "��һʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F202_FREZ_ZONE_2,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F203_FREZ_ZONE_3,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F204_FREZ_ZONE_4,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F205_FREZ_ZONE_5,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F206_FREZ_ZONE_6,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F207_FREZ_ZONE_7,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "����ʱ�����������й�����ʾֵ���ܡ�����1��M��"},
    {CMD_AFN_D_F208_FREZ_ZONE_8,       MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "�ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"},

    // ��27 pn:�������
    {CMD_AFN_D_F209_METR_REMOTE_INFO,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_d,        "���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"},
    {CMD_AFN_D_F213_METR_SWITCH_INFO,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "���ܱ��ز���������ʱ��"},
    {CMD_AFN_D_F214_METR_MODIFY_INFO,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "���ܱ�����޸Ĵ�����ʱ��"},
    {CMD_AFN_D_F215_METR_BUY_USR,      MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "���ܱ����õ���Ϣ"},
    {CMD_AFN_D_F216_METR_BALANCE,      MT_DIR_M2S, MT_PN_MP,  emtTrans_td_m,        "���ܱ������Ϣ"},

    // ��28 pn:�������
    {CMD_AFN_D_F217_WHITE_YAWP_CURVE,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_c,        "̨�����г����ز����ڵ����������"},
    {CMD_AFN_D_F218_COLOR_YAWP_CURVE,  MT_DIR_M2S, MT_PN_MP,  emtTrans_td_c,        "̨�����г����ز����ڵ�ɫ��������"},
    /** } ���� **/ 
    ///*}

     /*******************************
     *  (13) ����3������(AFN=0EH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ  
     *  
    {*///
    // ����
    {CMD_AFN_E_F1_EVENT_1,             MT_DIR_S2M, MT_PN_P0,  NULL,                  "������Ҫ�¼�"},
    {CMD_AFN_E_F2_EVENT_2,             MT_DIR_S2M, MT_PN_P0,  NULL,                  "����һ���¼�"},
    // ����
    {CMD_AFN_E_F1_EVENT_1,             MT_DIR_M2S, MT_PN_P0,  NULL,                  "������Ҫ�¼�"},
    {CMD_AFN_E_F2_EVENT_2,             MT_DIR_M2S, MT_PN_P0,  NULL,                  "����һ���¼�"},
    ///*}

     /*******************************
     *  (14) �ļ�����(AFN=0FH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ  
     *  
    {*///
    // ����
    {CMD_AFN_F_F1_TRANS_WAY,           MT_DIR_S2M, MT_PN_P0,  NULL,                  "�ļ����䷽ʽ1"},
    // ����
    {CMD_AFN_F_F1_TRANS_WAY,           MT_DIR_M2S, MT_PN_P0,  NULL,                  "�ļ����䷽ʽ1"},
    ///*}

     /*******************************
     *  (15) ����ת��(AFN=11H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ  
     *  
    {*///
    // ����
    {CMD_AFN_10_F1_TRANSMIT,            MT_DIR_S2M, MT_PN_P0,  NULL,                  "͸��ת��"},
    {CMD_AFN_10_F9_TRANS_READ,          MT_DIR_S2M, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵ĳ�����������"},
    {CMD_AFN_10_F10_TRANS_SWITCH,       MT_DIR_S2M, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵�ң����բ/�����բ����"},
    {CMD_AFN_10_F11_TRANS_POWER,        MT_DIR_S2M, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵�ң���͵�����"},
    // ����
    {CMD_AFN_10_F1_TRANSMIT,            MT_DIR_M2S, MT_PN_P0,  NULL,                  "͸��ת��"},
    {CMD_AFN_10_F9_TRANS_READ,          MT_DIR_M2S, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵ĳ�����������"},
    {CMD_AFN_10_F10_TRANS_SWITCH,       MT_DIR_M2S, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵�ң����բ/�����բ����"},
    {CMD_AFN_10_F11_TRANS_POWER,        MT_DIR_M2S, MT_PN_P0,  NULL,                  "ת����վֱ�Ӷ��ն˵�ң���͵�����"},
    ///*}


     /*******************************
     *  (16) ������� 
     *   
     *  �ڴ�֮����չ
     *  ����: ����Ҫ  
     *  
    {*///
    {CMD_AFN_FN_MAX,            MT_DIR_UNKOWN, MT_PN_P0,  NULL,                  "�������ֵ"}
    ///*}
};
////*}

/*****************************************************************************
 �� �� ��  : eMtInit
 ��������  : Э���ʼ��
 �������  : sMtInit* sInit  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��2�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr eMtInit(sMtInit* psInit)
{
    if(g_bMtInit == TRUE)
    {
        return MT_OK;
    }

    if(!psInit)
    {
        #ifdef MT_DBG
        DEBUG("eMtInit() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(MT_ROLE_MASTER != psInit->eRole && MT_ROLE_CONTOR != psInit->eRole)
    {
        #ifdef MT_DBG
        DEBUG("eMtInit() para error!");
        #endif
        return MT_ERR_PARA;
    }

    g_ucMtPermitDelayMinutes = psInit->ucPermitDelayMinutes;
    g_eMtRole = psInit->eRole;

    #if MT_CFG_SPT_MST
    if(psInit->eRole == MT_ROLE_CONTOR)
    {
        g_tEC.ucEC1 = 0;
        g_tEC.ucEC2 = 0;
    }
    #endif

    //pw
    memcpy(g_aucPw,psInit->aucPw, MT_PW_LEN);

    // ����������㷨 
#if MT_CFG_ENCRYPT
    g_peMtEncryptFunc = psInit->EncryptFunc;  // ���ܽӿ�
    g_peMtDecryptFunc = psInit->DecryptFunc;  // ���ܽӿ�
#endif
    
    g_bMtInit = TRUE;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : bmt_is_0xEE
 ��������  : �ж�usLen����pData���������Ƿ���0xEE 
 �������  : UINT8* pData  
             UINT16 usLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   bmt_is_0xEE(UINT8* pData, UINT16 usLen)
{
    if(!pData)
    {
        return FALSE;
    }
    
    INT32 i = 0;
    for(i = 0; i < usLen; i++)
    {
        if(0xEE != pData[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*****************************************************************************
 �� �� ��  : vmt_set_0xEE
 ��������  : ��usLen������pData�����ݶ�����Ϊ0xEE
 �������  : UINT8* pData  
             UINT16 usLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vmt_set_0xEE(UINT8* pData, UINT16 usLen) 
{
    INT32 i = 0;
    
    if(!pData)
    {
        return;
    }
    
    for(i = 0; i < usLen; i++)
    {
        pData[i] = 0xEE;
    }
}

/*****************************************************************************
 �� �� ��  : bmt_is_none
 ��������  : �Ƿ�һ��������Ϊȱʡ
 �������  : UINT8* pData  
             UINT16 usLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   bmt_is_none(UINT8* pData, UINT16 usLen)
{
    return bmt_is_0xEE(pData, usLen);
}

/*****************************************************************************
 �� �� ��  : vmt_set_none
 ��������  : ��ĳ����������Ϊȱʡ
 �������  : UINT8* pData  
             UINT16 usLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vmt_set_none(UINT8* pData, UINT16 usLen)
{
    vmt_set_0xEE(pData, usLen);
}

/*****************************************************************************
 �� �� ��  : eMtGetCmdInfor
 ��������  : ͨ���������ͺͱ��ķ����ø������Ӧ�������Ϣ
 �������  : eMTmd eCmd          
             eMTDir eDir         
             sMTmdInfo *psInfor  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��29�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr eMtGetCmdInfor(eMtCmd eCmd, eMtDir eDir, sMtCmdInfor *psInfor)
{
    INT32 i   = 0;
    INT32 Num = 0;

    if(!psInfor)
    {
        #ifdef MT_DBG
        DEBUG("eMtGetCmdInfor() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    #ifdef MT_DBG
    // DEBUG("[in]eMtGetCmdInfor() eCmd = 0x%X", eCmd);
    // DEBUG("[in]eMtGetCmdInfor() eDir = %s", eDir == MT_DIR_M2S ? "MT_DIR_M2S" : "MT_DIR_S2M");
    #endif
    
    Num = sizeof(gmt_cmdinfor) / sizeof(sMtCmdInfor);

    for(i = 0; i < Num; i++)
    {
        if(gmt_cmdinfor[i].eCmd == eCmd && gmt_cmdinfor[i].eDir == eDir)
        {
            psInfor->eCmd  = eCmd;
            psInfor->eDir  = eDir;
            psInfor->ePn   = gmt_cmdinfor[i].ePn;
            psInfor->pFunc = gmt_cmdinfor[i].pFunc;
            psInfor->pName = gmt_cmdinfor[i].pName;
            return MT_OK;
        }
    }

    #ifdef MT_DBG
   // DEBUG("eMtGetCmdInfor() MT_ERR_NONE!");
    #endif
    return MT_ERR_NONE;
}

/*****************************************************************************
 �� �� ��  : emtGetPrm
 ��������  : ���ĳ���͵ı��ĵ�������
 �������  : eMtDir eDir  
             eMtAFN eAfn  
             BOOL bAuto   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��5�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtPRM emtGetPrm(eMtDir eDir, eMtAFN eAfn, BOOL bAuto)
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
    	case AFN_06_AUTH: 

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
        ePrm = MT_PRM_ACTIVE;
	}

	return ePrm;
}
/*****************************************************************************
 �� �� ��  : emtIsValidPack
 ��������  : �ж�һ��֡�Ƿ���һ����Ч��3761.1�ı���
             �ж�һ����0x68 ��ͷ��0x16��β��һ��buffer�Ƿ���һ��������Ч��376.1����
 �������  : UINT8  *pOutBuf  
             UINT16 usLen     
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtIsValidPack(const UINT8* pOutBuf, UINT16 usLen)
{
    if(!pOutBuf)
    {
       #ifdef MT_DBG
       DEBUG("emtIsValidPack() pointer is null!");
       #endif
       return MT_ERR_NULL;
    }

    UINT8  ucCheckSumP = 0;    
    UINT8  ucCheckSumC = 0;   
    UINT8  uc0x16      = 0;
    UINT16 usProtoLen  = 0; //ʵ��Ӧ�õ�Э�����ݳ���
    UINT16 usUserLen   = 0;     

    sMtfComHead *pfComHead = NULL;
    pfComHead = (sMtfComHead *)pOutBuf;

    if(0x68 != pfComHead->f68 || 0x68 != pfComHead->s68)
    {
        return MT_ERR_0x68;
    }

    if(2 != pfComHead->p10)
    {
        return MT_ERR_PROTO;
    }

    usUserLen =  ((pfComHead->L2 << 6) & 0x3FC0 ) | (pfComHead->L1 & 0x003F); 

    // ֡�е�ʵ��У���
    ucCheckSumP =  *(UINT8*)((UINT8*)&(pfComHead->C) + usUserLen);
   
    // ���������У���
    ucCheckSumC = ucmt_get_check_sum((UINT8*)&(pfComHead->C), usUserLen);
    
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

    if(uc0x16 != 0x16)
    {
        return MT_ERR_0x16;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : vmtSetEC
 ��������  : �����¼�������
 �������  : UINT8 ucEC1  
             UINT8 ucEC2  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void  vmtSetEC(UINT8 ucEC1, UINT8 ucEC2)
{
    g_tEC.ucEC1 = ucEC1;
    g_tEC.ucEC2 = ucEC2;
}  

/*****************************************************************************
 �� �� ��  : vmtSetPw
 ��������  : ���ַ�����ʽ���õ�¼����
             ������Ȳ���16, ����Զ���'0'����
 �������  : char *pPw  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void  vmtSetPw(char *pPw)
{
    if(!pPw)
    {
        return;
    }

    memset((void*)g_aucPw, '0', MT_PW_LEN);
    int len = 0, lenLeft = 0;
    len = strlen(pPw);

    if(len >= MT_PW_LEN)
    {
        memcpy((void*)g_aucPw, (void*)pPw, MT_PW_LEN); 
    }
    else
    {
        lenLeft =  MT_PW_LEN - len;
        memcpy((void*)((UINT8*)g_aucPw + lenLeft), (void*)pPw, len); 
    }
}

/*****************************************************************************
 �� �� ��  : vmtSetPwBuf
 ��������  : ��buffer�ķ�ʽ����PW
 �������  : UINT8* buf  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void vmtSetPwBuf(UINT8* buf)
{
    if(!buf)
    {
        return;
    }

    memcpy((void*)g_aucPw, (void*)buf, MT_PW_LEN); 
}

/*****************************************************************************
 �� �� ��  : emtWhoAmI
 ��������  : ��õ�ǰʹ�øýӿڵ���ݣ���վ���Ǵ�վ
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtRole emtWhoAmI()
{
    return g_eMtRole; 
}

/*****************************************************************************
 �� �� ��  : emtFindValidPack
 ��������  : ��֡���������ҵ���һ����Ч��֡��λ�ü�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtFindValidPack(UINT8* pinBuf, UINT16 usLen, UINT16* pusFirstOff, UINT16* pusFirstLen)
{
    if(!pinBuf || !pusFirstOff || !pusFirstLen)
    {
        #ifdef MT_DBG
        DEBUG("emtFindValidPack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    eMtErr eRet = MT_OK;
    int i = 0, j = 0;
    UINT16 usValidLen = 0;

    for(i = 0; i < usLen; i++)
    {
        if(0x68 == pinBuf[i])
        {   
            // �ж��������ֽ�λ���ǲ���0x68 usLen
            if(0x68 == pinBuf[i+5])
             {
                for(j = i+6; j < usLen; j++)
                {
                    if(pinBuf[j] == 0x16)
                    {    
                        usValidLen = j + 1;
                        eRet = emtIsValidPack((UINT8*)(pinBuf + i), usValidLen);

                        if(MT_OK == eRet)
                        {
                            *pusFirstOff = i;
                            *pusFirstLen = usValidLen;
                            return MT_OK;
                        }
                    }
                }

                continue;
            }
        }
    }
    
    return MT_ERR_NONE;
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
BOOL   bmt_have_ec(eMtAFN eAFN, eMtDir eDir)
{   
    if((AFN_00_CONF == eAFN) ||    // ȷ�Ϸ��ϱ��� �����ж���EC
       (AFN_02_LINK != eAFN  &&
        AFN_06_AUTH != eAFN  &&
        MT_DIR_S2M == eDir))       // ������·�������������б��Ķ���EC
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
BOOL   bmt_have_pw(eMtAFN eAFN, eMtDir eDir)
{
    if(((MT_DIR_M2S == eDir)  &&
        (AFN_01_RSET == eAFN  ||
         AFN_04_SETP == eAFN  || 
         AFN_05_CTRL == eAFN  ||
         AFN_10_DATA == eAFN  ||
         AFN_0F_FILE == eAFN))||        // PW�ֶ�ֻ���������б�����
        (AFN_06_AUTH == eAFN))           // ˫�������֤�����ж���PW
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
BOOL  bmt_have_tp(eMtAFN eAFN, eMtDir eDir)
{
    if(AFN_02_LINK == eAFN &&  MT_DIR_S2M == eDir)  // ����������������б�����
    {
         return FALSE;
    }

    if(MT_DIR_M2S == eDir && AFN_00_CONF == eAFN)
    {
        return FALSE;
    }

    if(MT_DIR_M2S == eDir && AFN_04_SETP == eAFN)
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
BOOL   bmt_need_con(eMtAFN eAFN, eMtDir eDir)
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
 �� �� ��  : bmt_is_p0
 ��������  : �ж�һ��Pn�Ƿ�Ϊ0, ��P0
 �������  : UINT16 *pUsPn8  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bmt_is_p0(UINT16 *pUsPn8)
{
    if(!pUsPn8)
    {
        return FALSE;
    }

    INT32 i = 0;
    for(i = 0; i < PN_INDEX_MAX; i++)
    {
        if(pUsPn8[i] != 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*****************************************************************************
 �� �� ��  : ucmt_get_pn_team
 ��������  : ���1��Pn��Ӧ����Ϣ�����
 �������  : UINT16 usPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_pn_team(UINT16 usPn)
{
    UINT8 ucTeam;
    
    if(0 == usPn)
    {
        return 0;
    }

    ucTeam = (usPn - 1)/8 + 1;
    return ucTeam;
}

/*****************************************************************************
 �� �� ��  : ucmt_get_pn8_team
 ��������  : ���8��Pn��Ӧ����Ϣ�����
 �������  : UINT16 *pusPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_pn8_team(UINT16 *pusPn)
{
    if(!pusPn)
    {
        return 0xFF;
    }

    BOOL bP0;
    bP0 = bmt_is_p0(pusPn);
    if(TRUE == bP0)
    {
        return 0;
    }

    int i = 0;
    UINT8 ucTeam;
    for(i = 0; i < 8; i++)
    {
        if(pusPn[i] != MT_PN_NONE)
        {
           ucTeam  = ucmt_get_pn_team(pusPn[i]);
           return ucTeam;
        }
    }

    return 0xFF;
}

/*****************************************************************************
 �� �� ��  : bmt_in_pn8
 ��������  : �ж�ĳһ��pn�Ƿ���һ��8��pn��
 �������  : UINT16 usPn     
             UINT16 *pusPn8  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��17�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bmt_in_pn8(UINT16 usPn, UINT16 *pusPn8)
{
    if((!pusPn8) || (usPn > MT_PN_MAX))
    {
        return FALSE;
    }

    INT32 i = 0;
    
    for(i = 0; i < 8; i++)
    {
        if(usPn == pusPn8[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*****************************************************************************
 �� �� ��  : ucGetCmdFn
 ��������  : ��������FN
 �������  : eMtCmd eCmd  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��8�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8  ucGetCmdFn(eMtCmd eCmd)
{
    UINT8 ucFn;
    ucFn = (UINT8)( eCmd & 0xFF);
    return ucFn;
}

/*****************************************************************************
 �� �� ��  : eGetCmdAfn
 ��������  : ͨ�������ֻ�ȡ�����Ӧ��AFN
 �������  : eMtCmd eCmd  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��5��21�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtAFN eGetCmdAfn(eMtCmd eCmd)
{
    eMtAFN eAfn;
    UINT32 ulCmd = 0;
    UINT8  ucAfn = 0;
    ulCmd = (UINT32)eCmd;   
    ucAfn = (UINT8)((ulCmd & 0x0000FF00 ) >> 8);
    eAfn  = (eMtAFN)ucAfn;
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

        default:
            eAfn = AFN_NULL;
            break;
    }
   
    return eAfn;
}

/*****************************************************************************
 �� �� ��  : bmt_same_team_pn
 ��������  : �ж�һ����8��Ԫ�ص�Pn����,���8��Pn�Ƿ�����ͬһ����Ϣ����
             ������ЧPn
             �������ͬһ��,�����ȡ��
 �������  : UINT16 *pUsPn8  
 �������  : ��
 �� �� ֵ  : ��ͬһ�鷵����
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bmt_same_team_pn(UINT16 *pUsPn8, UINT8* pucDa2)
{
    if(!pUsPn8)
    {
        return FALSE;
    }

    UINT16 usPn[8]   = {0};
    UINT8  ucTeam[8] = {0}; // ÿ��Pn��Ӧ����Ϣ����
    INT32  nPnNum    = 0;   // ��ЧPn�ĸ���
    INT32  i         = 0;
    BOOL   bP0       = FALSE;

    // �ж��Ƿ���P0
    bP0 = bmt_is_p0(pUsPn8);
    if(TRUE == bP0)
    {
        if(pucDa2 != NULL)
        {
           *pucDa2 = 0;
        }
        
        return TRUE;
    }

    for(i = 0; i < 8; i++)
    {
        if(MT_PN_NONE == pUsPn8[i])
        {
            // �Ϸ�,������Ч��ֵ
        }
        else if(pUsPn8[i] < MT_PN_MIN || pUsPn8[i] > MT_PN_MAX)
        {
            #ifdef MT_DBG
            DEBUG("bmt_same_team_pn() Pn para err!");
            #endif
            return FALSE;
        }
        // ����һ��Ϊ0���������
        else if(0 == pUsPn8[i])
        {
            return FALSE;
        }
        else
        {
            usPn[nPnNum++] = pUsPn8[i];
        }
    }

    if(0 == nPnNum)
    {
        // ������Ч��ֵ,�������û������,Ҳ��Ϊ����һ��
        return FALSE;
    }
    else if(1 == nPnNum)
    {
        //*pucTeam = (usPN[0] - 1) / 8  + 1;
        //return TRUE;
    }
    else
    {
        for(i = 0; i < nPnNum; i++)
        {
            ucTeam[i] = (usPn[i] - 1) / 8  + 1; 
        }
        
        for(i = 1; i < nPnNum; i++)
        {
            if(ucTeam[i] != ucTeam[0])
            {
                return FALSE;
            }
        }
    }

    if(pucDa2 != NULL)
    {
       *pucDa2 = (usPn[0] - 1) / 8  + 1;
    }
    
    return TRUE;
}

/*****************************************************************************
 �� �� ��  : ucmt_get_fn_team
 ��������  : ���һ��fn��Ӧ����Ϣ����
 �������  : UINT8 ucFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_fn_team(UINT8 ucFn)
{
    UINT8 ucTeam = 0;
  
    // �ж��Ƿ��ǺϷ���Fn
    if(ucFn == MT_FN_NONE)
    {
        ucTeam = 0xFF;
    }
    else
    {
        if(ucFn > MT_FN_MAX || ucFn < MT_FN_MIN)
        {
            ucTeam = 0xFF;
            #ifdef MT_DBG
            DEBUG("ucmt_get_fn_team() Fn para err!");
            #endif
        }
        else
        {
            ucTeam = (ucFn - 1)/8 ;
        }
    }
    
    return ucTeam;  
}

/*****************************************************************************
 �� �� ��  : ucmt_get_fn_bit
 ��������  : ���һ��Fn��Ӧĳ��Ϣ�����е�bitֵ
 �������  : UINT8 ucFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��12�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_fn_bit(UINT8 ucFn)
{
    UINT8 ucBit = 0;
  
    // �ж��Ƿ��ǺϷ���Fn
    if(ucFn == MT_FN_NONE)
    {
        ucBit = 0xFF;
    }
    else
    {
        if(ucFn > MT_FN_MAX || ucFn < MT_FN_MIN)
        {
            ucBit = 0xFF;
            #ifdef MT_DBG
            DEBUG("ucmt_get_fn_bit() Fn para err ucFn = %d!", ucFn);
            #endif
        }
        else
        {
            ucBit = (0x01 << ((ucFn - 1) % 8));
        }
    }
    
    return ucBit;  
}

/*****************************************************************************
 �� �� ��  : ucmt_get_fn8_team
 ��������  : ���8��fn��Ӧ����Ϣ����
 �������  : UINT8 *pucFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_fn8_team(UINT8 *pucFn)
{
    if(!pucFn)
    {
        return 0xFF;
    }

    int i = 0; 
    UINT8 ucTeam = 0xFF;
    
    for(i = 0 ;i < 8; i++)
    {
        if(pucFn[i] != MT_FN_NONE)
        {
            ucTeam = ucmt_get_fn_team(pucFn[i]);
            break;
        }
    }

    return ucTeam;
}

/*****************************************************************************
 �� �� ��  : bmt_in_fn8
 ��������  : �ж�ĳһ��fn�Ƿ���һ��8��fn��
 �������  : UINT8 ucFn     
             UINT8 *pucFn8  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��17�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bmt_in_fn8(UINT8 ucFn, UINT8 *pucFn8)
{
    if((ucFn < MT_FN_MIN) || (!pucFn8) || (ucFn > MT_FN_MAX))
    {
        return FALSE;
    }

    INT32 i = 0;
    
    for(i = 0; i < 8; i++)
    {
        if(ucFn == pucFn8[i])
        {
            return TRUE;
        }
    }
    
    return FALSE;
}

/*****************************************************************************
 �� �� ��  : bmt_same_team_fn
 ��������  : �ж�һ����8��Ԫ�ص�Fn����,���8��Fn�Ƿ�����ͬһ����Ϣ����
             ������ЧFn
             �������ͬһ��,�����ȡ��
 �������  : UINT16 *pUcFn8  
 �������  : ��
 �� �� ֵ  : ��ͬһ�鷵����
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL bmt_same_team_fn(UINT8  *pUcFn8, UINT8* pucDt2)
{
    if(!pUcFn8)
    {
        return FALSE;
    }
     
    UINT8  ucFn[8]   = {0};
    UINT8  ucTeam[8] = {0}; // ÿ��Pn��Ӧ����Ϣ����
    INT32  nFnNum    = 0;   // ��ЧPn�ĸ���
    INT32  i         = 0;

    #if 0
    #ifdef MT_DBG
    DEBUG("[in]bmt_same_team_fn()");
    for(i = 0; i < 8; i++)
    {
        printf("fn[%d] = %d\n", i, (UINT8)pUcFn8[i]);
    }
    #endif
    #endif
    
    for(i = 0; i < 8; i++)
    {
        if(MT_FN_NONE == pUcFn8[i])
        {
            // �Ϸ�,������Ч��ֵ
        }
        else if(pUcFn8[i] < MT_FN_MIN || pUcFn8[i] > MT_FN_MAX)
        {
            #ifdef MT_DBG
            DEBUG("bmt_same_team_fn() Fn para err!");
            #endif
            return FALSE;
        }
        else
        {
            ucFn[nFnNum++] = pUcFn8[i];
        }
    }

    if(0 == nFnNum)
    {
        // ������Ч��ֵ,�������û������,Ҳ��Ϊ����һ��
        return FALSE;
    }
    else if(1 == nFnNum)
    {
        //*pucTeam = (usPN[0] - 1) / 8  + 1;
        //return TRUE;
    }
    else
    {
        for(i = 0; i < nFnNum; i++)
        {
            ucTeam[i] = (ucFn[i] - 1) / 8 ; 
        }
        
        for(i = 1; i < nFnNum; i++)
        {
            if(ucTeam[i] != ucTeam[0])
            {
                return FALSE;
            }
        }
    }
    
    if(pucDt2 != NULL)
    { 
        *pucDt2 = (ucFn[0] - 1) / 8;
    }
    
    return TRUE;
}

/*****************************************************************************
 �� �� ��  : emt_pnfn_to_dadt
 ��������  : ���ݵ�Ԫ��ʶת������
 �������  : sMtPnFn* psPnFn  
             sMtDaDt* psDaDt  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_pnfn_to_dadt(sMtPnFn* psPnFn, sMtDaDt* psDaDt)
{
    INT32  i           = 0;
    UINT8  ucDa1       = 0;
    UINT8  ucDa2       = 0;
    UINT8  ucDt1       = 0;
    UINT8  ucDt2       = 0;
    const UINT8 ucMask = 0x01;
    UINT8  ucShit      = 0;  // λ�Ƹ���
    BOOL   bSameTeam   = FALSE;
    BOOL   bPn0        = FALSE;

    // �������
    if(!psPnFn || !psDaDt)
    {
        #ifdef MT_DBG
        DEBUG("emt_pnfn_to_dadt() para pointer is null !");
        #endif
        return MT_ERR_NULL;
    }

    // �ж�Pn �Ƿ���ͬһ����
    bSameTeam = bmt_same_team_pn(psPnFn->usPn, &ucDa2);
    if(FALSE == bSameTeam)
    {
        #ifdef MT_DBG
        DEBUG("emt_pnfn_to_dadt() Pn is not in a same team!");
        #endif
        return MT_ERR_TEAM;
    }

    // �ж�Fn �Ƿ���ͬһ����
    bSameTeam = bmt_same_team_fn(psPnFn->ucFn, &ucDt2);
    if(FALSE == bSameTeam)
    {
        #ifdef MT_DBG
        DEBUG("emt_pnfn_to_dadt() Fn is not in a same team!");
        #endif
        return MT_ERR_TEAM;
    }

    // ��װ Da1
    bPn0 = bmt_is_p0(psPnFn->usPn);
    if(TRUE == bPn0)
    {
         ucDa1 = 0;
    }
    else
    {
        for(i = 0; i < PN_INDEX_MAX; i++)
        {
            if(MT_PN_NONE != psPnFn->usPn[i])
            {
                ucShit = (psPnFn->usPn[i] - 1) % 8;
                ucDa1 |= (ucMask << ucShit);
            }
        }
    }

    // ��װDt1
    for(i = 0; i < FN_INDEX_MAX; i++)
    {
        if(MT_FN_NONE != psPnFn->ucFn[i])
        {
            ucShit = (psPnFn->ucFn[i] - 1) % 8;
            ucDt1 |= (ucMask << ucShit);
        }
    }
    
    // ���Ϸ���fn pn ��װ�� DaDt
    psDaDt->ucDA1 = ucDa1;
    psDaDt->ucDA2 = ucDa2;
    psDaDt->ucDT1 = ucDt1;
    psDaDt->ucDT2 = ucDt2;

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_dadt_to_pnfn
 ��������  : ���ݱ�ʶ��Ԫת������
 �������  : sMtDaDt* psDaDt  
             sMtPnFn* psPnFn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_dadt_to_pnfn(sMtDaDt* psDaDt, sMtPnFn* psPnFn)
{
    INT32  i      = 0;
    UINT16 usPn   = 0;
    UINT8  ucFn   = 0;
    UINT8  ucMask = 0x01;
    UINT8  ucTmp  = 0;
    
    if(!psPnFn || !psDaDt)
    {
        #ifdef MT_DBG
        DEBUG("emt_dadt_to_pnfn() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    #if 0
    #ifdef MT_DBG
    DEBUG("[in]emt_dadt_to_pnfn()");
    DEBUG("ucDA1 = 0x%X", psDaDt->ucDA1);
    DEBUG("ucDA2 = 0x%X", psDaDt->ucDA2);
    DEBUG("ucDT1 = 0x%X", psDaDt->ucDT1);
    DEBUG("ucDT2 = 0x%X", psDaDt->ucDT2);
    #endif
    #endif 
    
    // ��������ʼ��
    memset(psPnFn, 0x00, sizeof(sMtPnFn));
    
    // Fn
    if(psDaDt->ucDT2 > 30)
    {
        #ifdef MT_DBG
        DEBUG("emt_dadt_to_pnfn() para out of range! ucDT2 = %d", psDaDt->ucDT2);
        #endif
        return MT_ERR_OUTRNG;
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            ucTmp = ucMask << i;
            if(psDaDt->ucDT1 & ucTmp)
            {
                ucFn = ((psDaDt->ucDT2) * 8) + i + 1;
            }
            else
            {
                ucFn = MT_FN_NONE;
            }
            
            psPnFn->ucFn[i] = ucFn;   
        }
    }

    // P0
    if(0 == psDaDt->ucDA2)
    {
        if(0 == psDaDt->ucDA1)
        {
            for(i = 0; i < 8; i++)
            {
               psPnFn->usPn[i] = 0; 
            }
        }
        else
        {
           #ifdef MT_DBG
           DEBUG("emt_dadt_to_pnfn() para err!");
           #endif
           return MT_ERR_PARA;  
        }
    }
    // Pn
    else 
    {
        for(i = 0; i < 8; i++)
        {
            ucTmp = ucMask << i;
            if(psDaDt->ucDA1 & ucTmp)
            {
                usPn = (psDaDt->ucDA2-1) * 8 + i + 1;
            }
            else
            {
                usPn = MT_PN_NONE;
            }
            
            psPnFn->usPn[i] = usPn;   
        }
    }

    #if 0
    #ifdef MT_DBG
    DEBUG("[out]emt_dadt_to_pnfn()");
    BOOL bP0 = bmt_is_p0(psPnFn->usPn);
    if(bP0 == TRUE)
    {
         DEBUG("usPn = 0");     
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            if(psPnFn->usPn[i] == MT_PN_NONE)
            {
               DEBUG("Pn[%d] = NONE", i+1); 
            }
            else
            {
               DEBUG("Pn[%d] = %d", i+1, psPnFn->usPn[i]); 
            }
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(psPnFn->ucFn[i] == MT_FN_NONE)
        {
            DEBUG("Fn[%d] = NONE", i+1);    
        }
        else
        {
            DEBUG("Fn[%d] = %d", i+1, psPnFn->ucFn[i]);    
        }
    }
    #endif
    #endif
    
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_add_cmdpn
 ��������  : ����*pucNumCmdPn��sMtCmdPn�������һ���µ�
             ����Ѿ�����һ��ͬ����������PN��,�����
             ������Ӻ����,����������
 �������  : sMtCmdPn* psCmdPn   
             UINT8 *pucNumCmdPn  
             sMtCmdPn sNewCmdPn
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_add_cmdpn(sMtCmdPn* psCmdPn,sMtCmdPn sNewCmdPn, UINT8 *pucNumCmdPn)
{
    if(!psCmdPn || !pucNumCmdPn)
    {
        #ifdef MT_DBG
        DEBUG("emt_add_cmdpn() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    INT32 i   = 0;
    UINT8 ucN = 0;
    ucN = *pucNumCmdPn;

    for(i = 0; i < ucN; i++)
    {
        if(sNewCmdPn.eCmd == psCmdPn[i].eCmd)
        {
            if(sNewCmdPn.usPn == psCmdPn[i].usPn)
            {
                return MT_OK;
            }
        }
    }

    // û���ҵ�ͬ���������һ���µĽ�����
    psCmdPn[ucN].eCmd = sNewCmdPn.eCmd;
    psCmdPn[ucN].usPn = sNewCmdPn.usPn;

    *pucNumCmdPn = (ucN + 1);

    return MT_OK;
}
/*****************************************************************************
 �� �� ��  : emt_pnfn_to_cmdpn
 ��������  : ʵ��ucNumPnFn ��sMtPnFn�ṹ���� �� sMtCmdPn �ṹ���ݵ�ת�� 
             �����ת�����������
 �������  : eMtAFN eAfn         
             sMtPnFn* psPnFn     
             UINT8 ucNumPnFn     
            
 �������  : sMtCmdPn* psCmdPn   
             UINT8 *pucNumCmdPn  
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_pnfn_to_cmdpn(eMtAFN eAfn, sMtPnFn* psPnFn, UINT8 ucNumPnFn,   sMtCmdPn* psCmdPn, UINT8 *pucNumCmdPn)
{
    if(!psPnFn || !psCmdPn || !pucNumCmdPn)
    {
        #ifdef MT_DBG
        DEBUG("emt_pnfn_to_cmdpn() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    UINT8   ucFn  = 0;
    UINT8   ucAFN = 0;
    UINT16  usCmd = 0;
    INT32   i     = 0;
    INT32   j     = 0;
    INT32   k     = 0;
    eMtCmd  eCmd  = CMD_AFN_F_UNKOWN;
    eMtErr  eRet  = MT_OK;
    sMtDaDt sDaDt;
    sMtCmdPn sNew ;
    
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

            ucAFN = (UINT8)eAfn;
            break;
            
         default:
            #ifdef MT_DBG
            DEBUG("emt_pnfn_to_cmdpn() para err!");
            #endif
            return MT_ERR_PARA;  
            //break;

    }

    for(i = 0; i < ucNumPnFn; i++)
    {
        eRet = emt_pnfn_to_dadt(&(psPnFn[i]), &sDaDt);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emt_pnfn_to_cmdpn() emt_pnfn_to_dadt  err %d", eRet);
            #endif
            return eRet;  
        }

        // p0�����
        if(0 == sDaDt.ucDA1 && 0 == sDaDt.ucDA2)
        {
            sNew.usPn = 0;

            for(j = 0; j < 8; j++)
            {
                if(sDaDt.ucDT1 & (0x01 << j))
                {
                    ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                    usCmd = (UINT16)(ucAFN << 8 | ucFn);
                    eCmd  = (eMtCmd)usCmd;
                    sNew.eCmd = eCmd;
                    (void)emt_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                }
            }
        }
        else
        {
            for(k = 0; k < 8; k++)
            {
                if(sDaDt.ucDA1 & (0x01 << k))
                {
                    sNew.usPn = ((sDaDt.ucDA2-1) * 8 + k + 1);
                    for(j = 0; j < 8; j++)
                    {
                        if(sDaDt.ucDT1 & (0x01 << j))
                        {
                            ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                            usCmd = (UINT16)(ucAFN << 8 | ucFn);
                            eCmd  = (eMtCmd)usCmd;
                            sNew.eCmd = eCmd;
                            (void)emt_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                        }
                    }
                }
            }
        }
    }
    
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_cmdpn_to_pnfn
 ��������  : ʵ�ֽ�ucNumCmdPn��sMtCmdPn���� ת����sMtPnFn����
             �����ת����ĸ���pucNumPnFn
 �������  : eMtAFN eAfn        
             sMtPnFn* psPnFn    
             UINT8 *pucNumPnFn  
             sMtCmdPn* psCmdPn  
             UINT8  ucNumCmdPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_cmdpn_to_pnfn(eMtAFN eAfn, sMtPnFn* psPnFn, UINT8 *pucNumPnFn, sMtCmdPn* psCmdPn, UINT8  ucNumCmdPn)
{

    if(!psPnFn || !psCmdPn || !pucNumPnFn)
    {
        #ifdef MT_DBG
        DEBUG("pucNumPnFn() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    UINT8   ucTeamPn     = 0xFF;
    UINT8   ucTeamPnBase = 0xFF;
    UINT8   ucTeamFn     = 0xFF;
    UINT8   ucTeamFnBase = 0xFF;
    UINT8   ucFn         = 0;
    UINT8   ucNumPnFn    = 0; 
    UINT16  usPn         = 0;
    INT32   i            = 0;
    INT32   j            = 0;
    INT32   k            = 0;
    INT32   FnIndex      = 0;
    INT32   PnIndex      = 0;
    INT32   nPos         = 0;   
    BOOL    bFind        = FALSE;
    eMtCmd  eCmd         = CMD_AFN_F_UNKOWN;
    eMtAFN  eCmdAfn      = AFN_NULL;

    for(i = 0; i < ucNumCmdPn; i++)
    {
        eCmd    = psCmdPn[i].eCmd;
        usPn    = psCmdPn[i].usPn;
        ucFn    = ucGetCmdFn(eCmd); 
        eCmdAfn = eGetCmdAfn(eCmd);

        if(eCmdAfn != eAfn)  
        {
            #ifdef MT_DBG
            DEBUG("emt_cmdpn_to_pnfn() cmd is not is a same Afn");
            #endif
            return MT_ERR_TEAM;
        }

        nPos = ucNumPnFn;
        
        // ��ʼ��PnFn��
        for(k = 0; k < 8; k++)
        {
            psPnFn[nPos].ucFn[k] = MT_FN_NONE;
            psPnFn[nPos].usPn[k] = MT_PN_NONE;
        }

        for(j = 0; j < ucNumPnFn; j++)
        {
            // �ҵ���nDataPos���ҵ���λ��
            // ���ж�Pn�Ƿ���ͬһ��
            ucTeamPn     = ucmt_get_pn_team(usPn);
            ucTeamPnBase = ucmt_get_pn8_team(psPnFn[j].usPn);
            
            if(ucTeamPn == ucTeamPnBase)
            {
                // ���ж�Fn�Ƿ�����ͬһ����
                ucTeamFn     = ucmt_get_fn_team(ucFn);
                ucTeamFnBase = ucmt_get_fn8_team(psPnFn[j].ucFn);

                if(ucTeamFn == ucTeamFnBase)
                {
                    bFind = TRUE;
                    nPos  = j;
                    break;
                }
            }
        }

         // δ�ҵ�������һ��  
        if(FALSE == bFind)
        {
            ucNumPnFn  += 1;
        }

        if(0 == usPn)
        {
            PnIndex = 0;
            
            for(k = 0; k < 8; k++)
            {
                psPnFn[nPos].usPn[k] = 0;
            }
        }
        else
        {
            PnIndex = (usPn - 1) % 8; 
            psPnFn[nPos].usPn[PnIndex] =  usPn;
        }
      
        FnIndex = (ucFn - 1) % 8;
        psPnFn[nPos].ucFn[FnIndex] = ucFn;

        // ����δ�ҵ�״̬
        bFind = FALSE;
        
    }
    
    *pucNumPnFn = ucNumPnFn;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_dadt_to_cmdpn
 ��������  : ʵ��ucNumDaDt ��sMtDaDt�ṹ���� �� sMtCmdPn �ṹ���ݵ�ת�� 
             �����ת����ĸ���
 �������  : eMtAFN eAfn         
             sMtDaDt* psDaDt     
             UINT8 ucNumDaDt     
             sMtCmdPn* psCmdPn   
             UINT8 *pucNumCmdPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_dadt_to_cmdpn(eMtAFN eAfn, sMtDaDt* psDaDt, UINT8 ucNumDaDt, sMtCmdPn* psCmdPn, UINT8 *pucNumCmdPn)
{
    if(!psDaDt || !psCmdPn || !pucNumCmdPn)
    {
        #ifdef MT_DBG
        DEBUG("emt_dadt_to_cmdpn() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    UINT8   ucFn  = 0;
    UINT8   ucAFN = 0;
    UINT16  usCmd = 0;
    INT32   i     = 0;
    INT32   j     = 0;
    INT32   k     = 0;
    eMtCmd  eCmd  = CMD_AFN_F_UNKOWN;
    sMtDaDt sDaDt = {0};
    sMtCmdPn sNew ;
    
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

            ucAFN = (UINT8)eAfn;
            break;
            
         default:
            #ifdef MT_DBG
            DEBUG("emt_pnfn_to_cmdpn() para err!");
            #endif
            return MT_ERR_PARA;  
            //break;

    }

    for(i = 0; i < ucNumDaDt; i++)
    {
        sDaDt.ucDA1 = psDaDt[i].ucDA1;
        sDaDt.ucDA2 = psDaDt[i].ucDA2;
        sDaDt.ucDT1 = psDaDt[i].ucDT1;
        sDaDt.ucDT2 = psDaDt[i].ucDT2;

        // p0�����
        if(0 == sDaDt.ucDA1 && 0 == sDaDt.ucDA2)
        {
            sNew.usPn = 0;

            for(j = 0; j < 8; j++)
            {
                if(sDaDt.ucDT1 & (0x01 << j))
                {
                    ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                    usCmd = (UINT16)(ucAFN << 8 | ucFn);
                    eCmd  = (eMtCmd)usCmd;
                    sNew.eCmd = eCmd;
                    (void)emt_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                }
            }
        }
        else
        {
            for(k = 0; k < 8; k++)
            {
                if(sDaDt.ucDA1 & (0x01 << k))
                {
                    sNew.usPn = ((sDaDt.ucDA2-1) * 8 + k + 1);
                    for(j = 0; j < 8; j++)
                    {
                        if(sDaDt.ucDT1 & (0x01 << j))
                        {
                            ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                            usCmd = (UINT16)(ucAFN << 8 | ucFn);
                            eCmd  = (eMtCmd)usCmd;
                            sNew.eCmd = eCmd;
                            (void)emt_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                        }
                    }
                }
            }
        }
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_cmdpn_to_dadt
 ��������  : ʵ�ֽ�ucNumCmdPn��sMtCmdPn���� ת����sMtDaDt����
             �����ת����ĸ���pucNumDaDt
 �������  : eMtAFN eAfn        
             sMtDaDt* psDaDt    
             UINT8 *pucNumDaDt  
             sMtCmdPn* psCmdPn  
             UINT8  ucNumCmdPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_cmdpn_to_dadt(eMtAFN eAfn, sMtDaDt* psDaDt, UINT8 *pucNumDaDt, sMtCmdPn* psCmdPn, UINT8  ucNumCmdPn)
{
    if(!psDaDt || !psCmdPn || !pucNumDaDt)
    {
        #ifdef MT_DBG
        DEBUG("emt_cmdpn_to_dadt() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtPnFn *psPnFn   = NULL; 
    UINT8   ucNumPnFn = 0;
    INT32   i         = 0;
    eMtErr  eRet      = MT_OK;
    
    psPnFn = (sMtPnFn*)malloc(sizeof(sMtPnFn)*(ucNumCmdPn+1));
    if(!psPnFn)
    {
        #ifdef MT_DBG
        DEBUG("emt_cmdpn_to_dadt() MT_ERR_IO");
        #endif
        return MT_ERR_IO;
    }

    #if 0
    #ifdef MT_DBG
    printf("ucNumCmdPn = %d\n", ucNumCmdPn);
    for(i = 0; i < ucNumCmdPn; i++)
    {
       printf("psCmdPn[%d].eCmd = 0x%04X\n",i, psCmdPn[i].eCmd);
       printf("psCmdPn[%d].usPn = %d\n\n",i, psCmdPn[i].usPn);
    }
    #endif
    #endif
    
    eRet = emt_cmdpn_to_pnfn(eAfn, psPnFn, &ucNumPnFn, psCmdPn, ucNumCmdPn);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_cmdpn_to_dadt() emt_cmdpn_to_pnfn() error = %d", eRet);
        #endif
        MT_FREE(psPnFn);
        return eRet;
    }

    #if 0
    #ifdef MT_DBG
    int j = 0;
    printf("ucNumPnFn = %d\n", ucNumPnFn);
    for(i = 0; i < ucNumPnFn; i++)
    {
        for(j = 0; j < 8; j++)
        {
            printf("psPnFn[%d].ucFn[%d] = %d\n", i,j ,psPnFn[i].ucFn[j]); 
            printf("psPnFn[%d].usPn[%d] = %d\n\n", i,j ,psPnFn[i].usPn[j]); 
            
        }
    }
    #endif
    #endif

    for(i = 0; i < ucNumPnFn; i++)
    {
        eRet = emt_pnfn_to_dadt(&(psPnFn[i]), &(psDaDt[i]));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emt_cmdpn_to_dadt() emt_pnfn_to_dadt() error = %d", eRet);
            #endif
            MT_FREE(psPnFn);
            return eRet;
        }
    }

    *pucNumDaDt = ucNumPnFn;
    MT_FREE(psPnFn);
    return MT_OK;
}
/*****************************************************************************
 �� �� ��  : bMtGetFloatSign
 ��������  : ���һ��Float�ķ���λ  0 1
 �������  : float fVal  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int    bMtGetFloatSign(float fVal)
{
    uMtFloatFmt floatFmt;
    floatFmt.v = fVal;
    return floatFmt.s.sign;
}

/*****************************************************************************
 �� �� ��  : vMtSetFloatSign
 ��������  : ����һ��������Float�ķ���λ
 �������  : float *pfVal  
             int sign     ���ڵ���0Ϊ����С��0Ϊ��  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vMtSetFloatSign(float *pfVal, int sign)
{
    uMtFloatFmt *pFloatFmt;
    pFloatFmt = (uMtFloatFmt *)pfVal;
    
    if(sign >= 0)
    {
        pFloatFmt->s.sign = 0;
    }
    else
    {
        pFloatFmt->s.sign = 1;
    } 
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
int    bMtGetDoubleSign(double dVal)
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
void   vMtSetDoubleSign(double *pdVal, int sign)
{
    uMtDoubleFmt  *pdoubleFmt;
    pdoubleFmt = (uMtDoubleFmt*)pdVal;

    if(sign >= 0)
    {
        pdoubleFmt->s.sign = 0;
    }
    else
    {
        pdoubleFmt->s.sign = 1;
    }
}

/*****************************************************************************
 �� �� ��  : emcTrans_OneByOne
 ��������  : ���ȷ�Ϸ���ת������
 �������  : eMTTransDir eDir  
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
eMtErr emtTrans_OneByOne(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    sMtOneByOne_f *psOneByOne_f = (sMtOneByOne_f *)psFrame;
    sMtOnebyOne   *psOneByOne_u = (sMtOnebyOne   *)psUser;
    INT32       i         = 0;
    INT32       j         = 0;
    INT32       k         = 0;
    INT32       fi        = 0;
    INT32       pi        = 0;
    eMtErr      eRet      = MT_OK;
    INT32       nNum      = 0;  
    INT32       nDaDtNum  = 0;      // ��װpackbase����Ϣ��ʶ��64�����ݵ�Ԫ����ܸ���
    INT32       nDaDtPos  = 0;      // ÿ��Ӧ����packbase����Ϣ��ʶ�������
    UINT16      usCMD     = 0;
    UINT16      usPn      = 0;
    UINT8       ucFn      = 0;
    eMtCmd      eCmd      = CMD_AFN_F_UNKOWN;
    eMtAFN      eAFN      = AFN_NULL;
    eMtAFN      eAFNCmd   = AFN_NULL;
    BOOL        bOK       = FALSE;
    BOOL        bFindDaDt = FALSE;  // �Ƿ��ҵ�֮ǰ���ڵ���
    BOOL        bP0       = FALSE;
    INT32       nCyc      = 0;
    sMtPnFn     sPnFn;
    UINT8*      pMem      = NULL;
    sMtFnPnErr* psFnPnErr = NULL;
    #define     MT_TEAM_MAX  (50)   // ���ܵ��������

    if(!psFrame || !psUser || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_OneByOne() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    memset(&(sPnFn), 0x00, sizeof(sMtPnFn));

    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // ����ʱ����Ӧ�ò����ݳ���
        nNum = (int)*pusfLen;
        nNum -= sizeof(UINT8);
        nNum /= sizeof(sMtOne_f); // ���㺬��ȷ�Ϸ��ϸ���

        if(nNum > MT_FN_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_OneByOne() MT_ERR_OUTRNG");
            #endif
            return MT_ERR_OUTRNG;
        }

        eAFN = (eMtAFN)psOneByOne_f->ucAFN;
        psOneByOne_u->eAFN = eAFN;
        psOneByOne_u->ucNum = nNum;
        for(i = 0; i < nNum; i++)
        {
            bOK = psOneByOne_f->sOne[i].ucErr == 0 ? TRUE : FALSE;
            eRet = emt_dadt_to_pnfn(&(psOneByOne_f->sOne[i].sDaDt), &sPnFn);
            if(eRet != MT_OK)
            {   
                #ifdef MT_DBG
                DEBUG("Error:emt_dadt_to_pnfn() error = %d %s\n", eRet, smtGetErr(eRet));
                #endif
                return eRet;
            }

            // �Ƿ�Ϊp0�����
            bP0 = bmt_is_p0(sPnFn.usPn);
            if(TRUE == bP0)
            {
                nCyc = 1;
            }
            else
            {
                nCyc = PN_INDEX_MAX;
            }
            
            for(pi = 0; pi < nCyc; pi++)
            {
                if(MT_PN_NONE != sPnFn.usPn[pi])
                {
                    for(fi = 0; fi < FN_INDEX_MAX; fi++)
                    {
                        if(MT_FN_NONE != sPnFn.ucFn[fi])
                        { 
                            usCMD = (UINT16)((eAFN << 8) | sPnFn.ucFn[fi]);
                            eCmd  = (eMtCmd)usCMD; 
                            psOneByOne_u->sOne[j].bOk = bOK;
                            psOneByOne_u->sOne[j].usPn = sPnFn.usPn[pi];
                            psOneByOne_u->sOne[j].eCmd = eCmd;
                            j++;
                        }
                    }
                }            
            }
        }
    }
    else 
    // �û���תΪ֡��
    {
        eAFN = psOneByOne_u->eAFN;
        psOneByOne_f->ucAFN  = (UINT8)psOneByOne_u->eAFN;

        pMem = (UINT8*)malloc(sizeof(sMtFnPnErr) * MT_TEAM_MAX);
        if(!pMem)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_OneByOne() MT_ERR_IO");
            #endif
            return MT_ERR_IO;
        }
            
        psFnPnErr = (sMtFnPnErr*)pMem;
            
        for(i = 0; i < psOneByOne_u->ucNum; i++)
        {
            // �жϸ������Ƿ�����AFN��������
            eAFNCmd = eGetCmdAfn(psOneByOne_u->sOne[i].eCmd);
            if(eAFNCmd != eAFN)  
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_OneByOne() cmd is not is a same Afn ");
                DEBUG("eAFNCmd = %d", eAFNCmd);
                DEBUG("eAFN = %d", eAFN);
                #endif
                MT_FREE(pMem);
                return MT_ERR_TEAM;
            }

            usPn = psOneByOne_u->sOne[i].usPn;
            ucFn = ucGetCmdFn(psOneByOne_u->sOne[i].eCmd);
            bOK  = psOneByOne_u->sOne[i].bOk;

            /*
                �жϸúϷ������ݵ�Ԫ��ʶ,�����ݵ�Ԫ�Ƿ��Ѿ�����Ӧ��λ�� psBasePack
                ����ظ�,���߸���ǰ��,Da2 �벻ͬ��Dt2���, 
                �������ͬ�ı�ʶ�����ݵ�Ԫ��,����nDaTaNum�ĸ���
                
            */
            nDaDtPos = nDaDtNum;
            // ��ʼ��PnFn��
            for(k = 0; k < 8; k++)
            {
                psFnPnErr[nDaDtPos].sPnFn.ucFn[k] = MT_FN_NONE;
                psFnPnErr[nDaDtPos].sPnFn.usPn[k] = MT_PN_NONE;
            }
            
            if( nDaDtPos > MT_TEAM_MAX)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_OneByOne() MT_TEAM_MAX too small");
                #endif
                MT_FREE(pMem);
                return MT_ERR_OUTRNG;
            }
            
            for(j = 0; j < nDaDtNum; j++)
            {
                // �ҵ���nDataPos���ҵ���λ��
                // ���ж�Pn�Ƿ���ͬһ��
                UINT8 ucTeamPn     = 0xFF;
                UINT8 ucTeamPnBase = 0xFF;
                ucTeamPn     = ucmt_get_pn_team(usPn);
                ucTeamPnBase = ucmt_get_pn8_team(psFnPnErr[j].sPnFn.usPn);
                
                if(ucTeamPn == ucTeamPnBase)
                {
                    // ���ж�Fn�Ƿ�����ͬһ����
                    UINT8 ucTeamFn     = 0xFF;
                    UINT8 ucTeamFnBase = 0xFF;
                    ucTeamFn     = ucmt_get_fn_team(ucFn);
                    ucTeamFnBase = ucmt_get_fn8_team(psFnPnErr[j].sPnFn.ucFn);

                    if(ucTeamFn == ucTeamFnBase)
                    {
                         if(bOK == psFnPnErr[j].bOk)
                         {
                            bFindDaDt = TRUE;
                            nDaDtPos  = j;
                            break;
                         }                        
                    }
                }
            }

            // δ�ҵ���nDaTaNum++
            if(FALSE == bFindDaDt)
            {
                nDaDtNum  += 1; // ����һ��  
            }
            
            // ���� DaTa�鼰���ݵ�Ԫ
            if(0 == usPn)
            {
                pi = 0;
                for(k = 0; k < 8; k++)
                {
                    psFnPnErr[nDaDtPos].sPnFn.usPn[k] = 0;
                }
            }
            else
            {
                pi = (usPn - 1) % 8; 
                psFnPnErr[nDaDtPos].sPnFn.usPn[pi] = usPn;
            }
          
            fi = (ucFn - 1) % 8;
            psFnPnErr[nDaDtPos].sPnFn.ucFn[fi] = ucFn;

            // ���ݵ�Ԫ
            psFnPnErr[j].bOk = bOK;
            
            // ����δ�ҵ�״̬
            bFindDaDt = FALSE;
        }

        //sMtFnPnErr ʵ�� sMtOne_f ת��
        for(i = 0; i < nDaDtNum; i++)
        {
            eRet = emt_pnfn_to_dadt(&psFnPnErr[i].sPnFn, &(psOneByOne_f->sOne[i].sDaDt));
            if(eRet != MT_OK)
            {
                #ifdef MT_DBG
                DEBUG("Error:emt_pnfn_to_dadt() error = %d %s\n", eRet, smtGetErr(eRet));
                #endif
                return eRet;
            }
                    
            // right or error
            psOneByOne_f->sOne[i].ucErr = psFnPnErr[i].bOk == TRUE ? 0 : 1;
        }
     }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(UINT8) + sizeof(sMtOne_f) * psOneByOne_u->ucNum;
 
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn03f1
 ��������  : �м�վ����״̬���� 
 ��ӦAFN   : AFN_03_RELY 
 ��Ӧ����  : CMD_AFN_3_F1_RELAY_CTRL
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn03f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{

    // ������֡����ֽڳ���
    *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f1
 ��������  : F1���ն�����ͨ�ſ�ͨ�Ų������� 
             CMD_AFN_4_F1_TML_UP_CFG  
             CMD_AFN_A_F1_TML_UP_CFG 
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f1() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn04F1    *psAfn04F1   = (sMtAfn04F1*)psUser;
    sMtAfn04F1_f  *psAfn04F1_f = (sMtAfn04F1_f*)psFrame;
     
    UINT8 bs8Con = 0;
    
    if(MT_TRANS_U2F == eTrans)
    {
        psAfn04F1_f->ucRTS       = psAfn04F1->ucRTS;
        psAfn04F1_f->ucRTM       = psAfn04F1->ucRTM;
        psAfn04F1_f->ucHeartBeat = psAfn04F1->ucHeartBeat;
        psAfn04F1_f->ucSWTS1     = (psAfn04F1->usTmWaitTimeoutS & 0xFF);
        psAfn04F1_f->ucSWTS2     = ((psAfn04F1->usTmWaitTimeoutS & 0x0F00) >> 8);
        psAfn04F1_f->ucSWTS2    |= ((psAfn04F1->ucReSendTimes & 0x03) << 4);
        
        if(psAfn04F1->bAutoReportAsk_1 == TRUE)
        {
            bs8Con |= 0x01;
        }

        if(psAfn04F1->bAutoReportAsk_2 == TRUE)
        {
            bs8Con |= 0x02;
        }

        if(psAfn04F1->bAutoReportAsk_3 == TRUE)
        {
            bs8Con |= 0x04;
        }

        psAfn04F1_f->bs8Con   = bs8Con;

        #if 0
        #ifdef MT_DBG
        printf("emt_trans_Afn04F1_ConUpPortPara() user to frame\n");
        printf("ucRTS = %d\n", psAfn04F1_f->ucRTS);
        printf("ucRTM = %d\n", psAfn04F1_f->ucRTM);
        printf("ucHeartBeat = %d\n", psAfn04F1_f->ucHeartBeat);
        printf("ucSWTS1 = %x\n",  psAfn04F1_f->ucSWTS1);
        printf("ucSWTS2 = %x\n",  psAfn04F1_f->ucSWTS2);
        printf("bs8Con = %x\n",  psAfn04F1_f->bs8Con);
        #endif
        #endif
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psAfn04F1->ucRTS            = psAfn04F1_f->ucRTS;
        psAfn04F1->ucRTM            = psAfn04F1_f->ucRTM;
        psAfn04F1->ucHeartBeat      = psAfn04F1_f->ucHeartBeat;
        psAfn04F1->usTmWaitTimeoutS = (((psAfn04F1_f->ucSWTS2 & 0x0F) << 8)  | psAfn04F1_f->ucSWTS1);
        psAfn04F1->ucReSendTimes    = (psAfn04F1_f->ucSWTS2 >> 4) & 0x03;
        psAfn04F1->bAutoReportAsk_1 = ((psAfn04F1_f->bs8Con & 0x01) ? TRUE : FALSE);
        psAfn04F1->bAutoReportAsk_2 = ((psAfn04F1_f->bs8Con & 0x02) ? TRUE : FALSE);
        psAfn04F1->bAutoReportAsk_3 = ((psAfn04F1_f->bs8Con & 0x04) ? TRUE : FALSE);

        #if 0
        #ifdef MT_DBG
        printf("emtTrans_afn04f1() frame to user\n");
        printf("ucRTS = %d\n", psAfn04F1->ucRTS);
        printf("ucRTM = %d\n", psAfn04F1->ucRTM);
        printf("ucHeartBeat = %d\n", psAfn04F1->ucHeartBeat);
        printf("usTmWaitTimeoutS = %d\n", psAfn04F1->usTmWaitTimeoutS);
        printf("ucReSendTimes = %d\n", psAfn04F1->ucReSendTimes);
        printf("bAutoReportAsk_1 = %s\n", psAfn04F1->bAutoReportAsk_1 == TRUE ? "true" : "flase");
        printf("bAutoReportAsk_2 = %s\n", psAfn04F1->bAutoReportAsk_2 == TRUE ? "true" : "flase");
        printf("bAutoReportAsk_3 = %s\n", psAfn04F1->bAutoReportAsk_3 == TRUE ? "true" : "flase");
        #endif
        #endif
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn04F1_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f2
 ��������  :  F2���ն�����ͨ�ſ������м�ת������ CMD_AFN_4_F2_TML_WIRELESS_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f2(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f2() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    UINT16 usfLen  = 0;
    int    i       = 0;
    int nAddrCount = 0;
    
    sMtAfn04F2    *psAfn04F2;
    sMtAfn04F2_f  *psAfn04F2_f;

    psAfn04F2    = (sMtAfn04F2*)psUser;
    psAfn04F2_f  = (sMtAfn04F2_f*)psFrame;
    
    if(MT_TRANS_U2F == eTrans)
    {
        if(psAfn04F2->bPermit == TRUE)
        {
            psAfn04F2_f->ucPermit = 1;
        }
        else
        {
            psAfn04F2_f->ucPermit = 0;
        }

        nAddrCount = (int)(psAfn04F2->ucAddrCount);
       
        if(nAddrCount > 16)
        {
            return MT_ERR_PARA;    // ��ֵ�����Գ���16 
        }
        else
        {
            psAfn04F2_f->ucAddrCount = psAfn04F2->ucAddrCount;
        }

        for(i = 0; i < nAddrCount; i++)
        {
            psAfn04F2_f->usAddress[i] = psAfn04F2->usAddress[i];
        }

        usfLen = 1 + nAddrCount*sizeof(UINT16);
        
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psAfn04F2->bPermit     = (psAfn04F2_f->ucPermit == 1) ? TRUE:FALSE;
        psAfn04F2->ucAddrCount = psAfn04F2_f->ucAddrCount;
        nAddrCount             = (int)(psAfn04F2_f->ucAddrCount);
        
        for(i = 0; i < nAddrCount; i++)
        {
            psAfn04F2->usAddress[i] = psAfn04F2_f->usAddress[i];
        }

        usfLen = 1 + nAddrCount*sizeof(UINT16);
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usfLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f3
 ��������  : F3����վIP��ַ�Ͷ˿� CMD_AFN_4_F3_MST_IP_PORT CMD_AFN_A_F3_MST_IP_PORT
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f3() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn04F3   *psAfn04F3   = (sMtAfn04F3*)psUser;
    sMtAfn04F3_f *psAfn04F3_f = (sMtAfn04F3_f*)psFrame;
    
    if(MT_TRANS_U2F == eTrans)
    {
        psAfn04F3_f->ucMainIP[0] =  psAfn04F3->ulMainIP & 0xFF;
        psAfn04F3_f->ucMainIP[1] = (psAfn04F3->ulMainIP & 0xFF00)     >> 8;
        psAfn04F3_f->ucMainIP[2] = (psAfn04F3->ulMainIP & 0xFF0000)   >> 16;
        psAfn04F3_f->ucMainIP[3] = (psAfn04F3->ulMainIP & 0xFF000000) >> 24;

        psAfn04F3_f->ucBackIP[0] = psAfn04F3->ulBackIP  & 0xFF;
        psAfn04F3_f->ucBackIP[1] = (psAfn04F3->ulBackIP & 0xFF00)     >> 8;
        psAfn04F3_f->ucBackIP[2] = (psAfn04F3->ulBackIP & 0xFF0000)   >> 16;
        psAfn04F3_f->ucBackIP[3] = (psAfn04F3->ulBackIP & 0xFF000000) >> 24;

        psAfn04F3_f->usMainPort  = psAfn04F3->usMainPort;
        psAfn04F3_f->usBackPort  = psAfn04F3->usBackPort;
        memcpy(psAfn04F3_f->ucascAPN, psAfn04F3->ucascAPN, 16);

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psAfn04F3->ulMainIP  =   psAfn04F3_f->ucMainIP[0] 
                               | psAfn04F3_f->ucMainIP[1] << 8
                               | psAfn04F3_f->ucMainIP[2] << 16
                               | psAfn04F3_f->ucMainIP[3] << 24;

        psAfn04F3->ulBackIP  =   psAfn04F3_f->ucBackIP[0] 
                               | psAfn04F3_f->ucBackIP[1] << 8
                               | psAfn04F3_f->ucBackIP[2] << 16
                               | psAfn04F3_f->ucBackIP[3] << 24;

        psAfn04F3->usMainPort = psAfn04F3_f->usMainPort;
        psAfn04F3->usBackPort = psAfn04F3_f->usBackPort;
        memcpy(psAfn04F3->ucascAPN, psAfn04F3_f->ucascAPN, 16);
    }
    else
    {
        return MT_ERR_PARA;
    }
    
    *pusfLen = sizeof(sMtAfn04F3_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f4
 ��������  : F4����վ�绰����Ͷ������ĺ��� CMD_AFN_4_F4_MST_PHONE_SMS CMD_AFN_A_F4_MST_PHONE_SMS
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F4_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f5
 ��������  : F5���ն�����ͨ����Ϣ��֤�������� CMD_AFN_4_F5_TML_UP_AUTH CMD_AFN_A_F5_TML_UP_AUTH
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f5(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F5_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f6
 ��������  : F6���ն����ַ���� CMD_AFN_4_F6_TEAM_ADDR CMD_AFN_A_F6_TEAM_ADDR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f6(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F6_f);
    return MT_OK;
}   

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f7
 ��������  : F6���ն����ַ���� 
             CMD_AFN_4_F7_TML_IP_PORT
             CMD_AFN_A_F7_TML_IP_PORT
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f7(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F7_f);
    return MT_OK;
}   

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f8
 ��������  : F8���ն�����ͨ�Ź�����ʽ����̫ר��������ר���� 
             CMD_AFN_4_F8_TML_UP_WAY 
             CMD_AFN_A_F8_TML_UP_WAY
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f8(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F8_f);
    return MT_OK;
}     

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f9
 ��������  : F9���ն��¼���¼�������� 
             CMD_AFN_4_F9_TML_EVENT_CFG 
             CMD_AFN_A_F9_TML_EVENT_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f9(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F9_f);
    return MT_OK;
}     

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f10
 ��������  : F10���ն˵��ܱ�/��������װ�����ò��� 
             CMD_AFN_4_F10_TML_POWER_CFG 
             CMD_AFN_A_F10_TML_POWER_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f10(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
         #ifdef MT_DBG
         DEBUG("emtTrans_afn04f10() pointer is null");
         #endif
         return MT_ERR_NULL;
    }

    BOOL      bNsOne    = FALSE;
    UINT8     ucTmp    = 0;
    UINT16    usCfgNum = 0;
    UINT16    usTmp    = 0;
    INT32     i        = 0;
    eMtBaudRate   eBaudRate     = MT_BAUD_DEFAULT;
    sMtAfn04F10   *psAfn04F10   = (sMtAfn04F10*)psUser;
    sMtAfn04F10_f *psAfn04F10_f = (sMtAfn04F10_f*)psFrame;
  
    if(MT_TRANS_U2F == eTrans)
    {
        usCfgNum =  psAfn04F10->usNum;
        psAfn04F10_f->usNum = usCfgNum;

        for(i = 0; i < usCfgNum; i++)
        {
            // usMeterID
            if(TRUE == psAfn04F10->sOne[i].busMeterID)
            {
                usTmp = psAfn04F10->sOne[i].usMeterID;
                if(usTmp > 2040 || usTmp < 1)
                {
                    #ifdef MT_DBG
              DEBUG("emtTrans_afn04f10() usMeterID MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                psAfn04F10_f->sOne[i].usMeterID = usTmp;
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].usMeterID), sizeof(UINT16));
            }

            // usPn
            if(TRUE == psAfn04F10->sOne[i].busPn)
            {
                if(psAfn04F10->sOne[i].busPn > 2040 ||
                   psAfn04F10->sOne[i].busPn < 1)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() busPn MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                psAfn04F10_f->sOne[i].usPn = psAfn04F10->sOne[i].usPn;
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].usPn), sizeof(UINT16));
            }

            // sBaudPort
            if(TRUE == psAfn04F10->sOne[i].bsBaudPort)
            {
                ucTmp = psAfn04F10->sOne[i].sBaudPort.ucPort;
                if(ucTmp > MT_METER_PORT_MAX || ucTmp < MT_METER_PORT_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucPort MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                else
                {
                    psAfn04F10_f->sOne[i].sBaudPort.ucPort = psAfn04F10->sOne[i].sBaudPort.ucPort;
                }

                eBaudRate = psAfn04F10->sOne[i].sBaudPort.eBaudRate;
                switch(eBaudRate)
                {
                    case MT_BAUD_DEFAULT:
                        ucTmp = 0;
                        break;
                        
                    case MT_BAUD_600:
                        ucTmp = 1;
                        break;
                        
                    case MT_BAUD_1200:
                        ucTmp = 2;
                        break;
                        
                    case MT_BAUD_2400:
                        ucTmp = 3;
                        break;
                        
                    case MT_BAUD_4800:
                        ucTmp = 4;
                        break;
                        
                    case MT_BAUD_7200:
                        ucTmp = 5;
                        break;
                        
                    case MT_BAUD_9600:
                        ucTmp = 6;
                        break;
                        
                    case MT_BAUD_19200:
                        ucTmp = 7;
                        break;

                    default:
                        #ifdef MT_DBG
                        DEBUG("emtTrans_afn04f10() eBaudRate MT_ERR_OUTRNG!");
                        #endif
                        return MT_ERR_OUTRNG;
                       // break;
                }
                
                psAfn04F10_f->sOne[i].sBaudPort.ucBaudRate =  ucTmp;
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].sBaudPort), sizeof(sMtBaudPort_f));
            }  

            // ucProto
            if(TRUE == psAfn04F10->sOne[i].beProto)
            {
               switch(psAfn04F10->sOne[i].eProto)
               {
                   case MT_PROTO_DEFAULT:
                        ucTmp = 0;
                        break;
                        
                   case MT_PROTO_DLT645_97:
                        ucTmp = 1;
                        break;
                          
                   case MT_PROTO_DLT645_07:
                        ucTmp = 30;
                        break;
                          
                   case MT_PROTO_AC:
                        ucTmp = 2;
                        break;
                          
                   case MT_PROTO_SERIAL:
                        ucTmp = 31;
                        break;

                  default:
                        #ifdef MT_DBG
                        DEBUG("emtTrans_afn04f10() eProto MT_ERR_OUTRNG!");
                        #endif
                        return MT_ERR_OUTRNG;
                        //break;
               }

                psAfn04F10_f->sOne[i].ucProto = ucTmp;

            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].ucProto), sizeof(UINT8));
            }

            // acMeterAddr
            if(TRUE == psAfn04F10->sOne[i].bacMeterAddr)
            {
                (void)emt_trans_XX_6(MT_TRANS_U2F, 
                                       (psAfn04F10->sOne[i].acMeterAddr),
                                       &(psAfn04F10_f->sOne[i].acMeterAddr));  
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].acMeterAddr), sizeof(sMtFmt_XX_6));
            }

            // acPwd
            if(TRUE == psAfn04F10->sOne[i].bacPwd)
            {
                memcpy(psAfn04F10_f->sOne[i].acPwd, psAfn04F10->sOne[i].acPwd, 6); 
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].acPwd), 6);
            }

            // ucPayRateNum
            if(TRUE == psAfn04F10->sOne[i].bucPayRateNum)
            {
                ucTmp = psAfn04F10->sOne[i].ucPayRateNum;
                if(ucTmp > MT_PAYRATE_NUM_MAX || ucTmp < MT_PAYRATE_NUM_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() PayRateNum MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10_f->sOne[i].ucPayRateNum = ucTmp;
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].ucPayRateNum), sizeof(UINT8));
            }

            // sDigit
            if(TRUE == psAfn04F10->sOne[i].bsDigit)
            {
                // С��λ��
                ucTmp = psAfn04F10->sOne[i].sDigit.ucDecimal;
                if(ucTmp > MT_DNUM_DECIM_MAX || ucTmp < MT_DNUM_DECIM_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucDecimal MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10_f->sOne[i].sDigit.ucDecimal = ucTmp - 1;

                // ����λ��
                ucTmp = psAfn04F10->sOne[i].sDigit.ucInteger;
                if(ucTmp > MT_DNUM_INTGR_MAX || ucTmp < MT_DNUM_INTGR_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucInteger MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10_f->sOne[i].sDigit.ucInteger = ucTmp - 4;

            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].sDigit), sizeof(sMtDigitNum_f));
            }

            // acGathrAddr
            if(TRUE == psAfn04F10->sOne[i].bacGathrAddr)
            {
                (void)emt_trans_XX_6(MT_TRANS_U2F, 
                                       (psAfn04F10->sOne[i].acGathrAddr),
                                       &(psAfn04F10_f->sOne[i].acGathrAddr));  
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].acGathrAddr), sizeof(sMtFmt_XX_6));
            }

            // sUserClass
            if(TRUE == psAfn04F10->sOne[i].bsUserClass)
            {
                // �����
                ucTmp = psAfn04F10->sOne[i].sUserClass.ucBig;
                if(ucTmp > MT_USER_CLASS_MAX || ucTmp < MT_USER_CLASS_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucBig user class  MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10_f->sOne[i].sUserClass.ucBig = ucTmp - 1;
                
                // С����
                ucTmp = psAfn04F10->sOne[i].sUserClass.ucSmall;
                if(ucTmp > MT_USER_CLASS_MAX || ucTmp < MT_USER_CLASS_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucSmall user class  MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10_f->sOne[i].sUserClass.ucSmall = ucTmp - 1;
            }
            else
            {
                vmt_set_none((UINT8*)&(psAfn04F10_f->sOne[i].sUserClass), sizeof(sMtUserClass_f));
            }
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        usCfgNum = psAfn04F10_f->usNum;
        psAfn04F10->usNum = usCfgNum;
        for(i = 0; i < usCfgNum; i++)
        {
            // usMeterID
            usTmp = psAfn04F10_f->sOne[i].usMeterID;
            bNsOne = bmt_is_none((UINT8*)&usTmp, sizeof(UINT16));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].busMeterID = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].busMeterID = TRUE;
                if(usTmp > MT_METER_ID_MAX || usTmp < MT_METER_ID_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() usMeterID MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                psAfn04F10->sOne[i].usMeterID = usTmp;
            }

            // usPn
            usTmp = psAfn04F10_f->sOne[i].usPn;
            bNsOne = bmt_is_none((UINT8*)&usTmp, sizeof(UINT16));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].busPn = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].busPn = TRUE;
                if(usTmp > MT_PN_MAX || usTmp < MT_PN_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() usPn MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                psAfn04F10->sOne[i].usPn = usTmp;
            }

            // sBaudPort
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].sBaudPort), sizeof(sMtBaudPort_f));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bsBaudPort = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bsBaudPort = TRUE;
                // Baud
                ucTmp = psAfn04F10_f->sOne[i].sBaudPort.ucBaudRate;
                psAfn04F10->sOne[i].sBaudPort.eBaudRate = (eMtBaudRate)ucTmp;

                // Port
                ucTmp = psAfn04F10_f->sOne[i].sBaudPort.ucPort;
                if(ucTmp > MT_METER_PORT_MAX || ucTmp < MT_METER_PORT_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucPort MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                else
                {
                   psAfn04F10->sOne[i].sBaudPort.ucPort = ucTmp;
                }
            
            }

            // eProto
            ucTmp = psAfn04F10_f->sOne[i].ucProto;
            bNsOne = bmt_is_none(&ucTmp, sizeof(UINT8));
            if(TRUE == bNsOne)
            {
               psAfn04F10->sOne[i].beProto = FALSE;
            }
            else
            {
               psAfn04F10->sOne[i].beProto = TRUE;

               switch(ucTmp)
               {
                case 0:
                    psAfn04F10->sOne[i].eProto = MT_PROTO_DEFAULT;
                    break;

                case 1:
                    psAfn04F10->sOne[i].eProto = MT_PROTO_DLT645_97;
                    break;

                case 2:
                    psAfn04F10->sOne[i].eProto = MT_PROTO_AC;
                    break;

                case 30:
                    psAfn04F10->sOne[i].eProto = MT_PROTO_DLT645_07;
                    break;
                    
                case 31:
                    psAfn04F10->sOne[i].eProto = MT_PROTO_SERIAL;
                    break;

                 default:
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() eProto MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                    //break;
               }
            }
            
            // acMeterAddr
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].acMeterAddr), sizeof(sMtFmt_XX_6));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bacMeterAddr = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bacMeterAddr = TRUE;
                (void)emt_trans_XX_6(MT_TRANS_F2U, 
                                     (psAfn04F10->sOne[i].acMeterAddr),
                                     &(psAfn04F10_f->sOne[i].acMeterAddr));  
            }

            // acPwd
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].acPwd), 6);
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bacPwd = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bacPwd = TRUE;
                memcpy(psAfn04F10->sOne[i].acPwd, psAfn04F10_f->sOne[i].acPwd, 6); 
            }

            // ucPayRateNum
            bNsOne = bmt_is_none(&(psAfn04F10_f->sOne[i].ucPayRateNum), sizeof(UINT8));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bucPayRateNum = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bucPayRateNum = TRUE;
                ucTmp = psAfn04F10_f->sOne[i].ucPayRateNum;
                if(ucTmp > MT_PAYRATE_NUM_MAX || ucTmp < MT_PAYRATE_NUM_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() PayRateNum MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10->sOne[i].ucPayRateNum = ucTmp;
            }
            // sDigit
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].sDigit), sizeof(sMtDigitNum_f));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bsDigit = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bsDigit = TRUE;

                // С��λ��
                ucTmp = psAfn04F10_f->sOne[i].sDigit.ucDecimal + 1;
                if(ucTmp > MT_DNUM_DECIM_MAX || ucTmp < MT_DNUM_DECIM_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucDecimal MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10->sOne[i].sDigit.ucDecimal = ucTmp;

                // ����λ��
                ucTmp = psAfn04F10_f->sOne[i].sDigit.ucInteger + 4;
                if(ucTmp > MT_DNUM_INTGR_MAX || ucTmp < MT_DNUM_INTGR_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucInteger MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10->sOne[i].sDigit.ucInteger = ucTmp;
            }
            
            // acMeterAddr
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].acGathrAddr), sizeof(sMtFmt_XX_6));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bacGathrAddr = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bacGathrAddr = TRUE;
                (void)emt_trans_XX_6(MT_TRANS_F2U, 
                                     (psAfn04F10->sOne[i].acGathrAddr),
                                     &(psAfn04F10_f->sOne[i].acGathrAddr));  
            }

            // sUserClass
            bNsOne = bmt_is_none((UINT8*)&(psAfn04F10_f->sOne[i].sUserClass), sizeof(sMtUserClass_f));
            if(TRUE == bNsOne)
            {
                psAfn04F10->sOne[i].bsUserClass = FALSE;
            }
            else
            {
                psAfn04F10->sOne[i].bsUserClass = TRUE;
                // �����
                ucTmp = psAfn04F10_f->sOne[i].sUserClass.ucBig + 1;
                if(ucTmp > MT_USER_CLASS_MAX || ucTmp < MT_USER_CLASS_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucBig user class  MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10->sOne[i].sUserClass.ucBig = ucTmp;
                
                // С����
                ucTmp = psAfn04F10_f->sOne[i].sUserClass.ucSmall + 1;
                if(ucTmp > MT_USER_CLASS_MAX || ucTmp < MT_USER_CLASS_MIN)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f10() ucSmall user class  MT_ERR_OUTRNG!");
                    #endif
                    return MT_ERR_OUTRNG;
                }
                
                psAfn04F10->sOne[i].sUserClass.ucSmall = ucTmp; 
            }
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(sMtTmlPowerCfgOne_f)* usCfgNum + sizeof(UINT16);
    return MT_OK;
}     

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f11
 ��������  : F11���ն��������ò��� 
             CMD_AFN_4_F11_TML_PULSE_CFG 
             CMD_AFN_A_F11_TML_PULSE_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��14�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f11(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f11() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8 ucNum = 0;
    sMtAfn04F11_f * psAfn04F11_f = (sMtAfn04F11_f*)psFrame;
    sMtAfn04F11*    psAfn04F11   = (sMtAfn04F11*)psUser;
  
    if(MT_TRANS_U2F == eTrans)
    {
        ucNum = psAfn04F11->ucNum;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucNum = psAfn04F11_f->ucNum;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(sMtAfn04F11_f)* ucNum + sizeof(UINT8);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f12
 ��������  : F12���ն�״̬���������
             CMD_AFN_4_F12_TML_STATE_INPUT 
             CMD_AFN_A_F12_TML_STATE_INPUT
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��16�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f12(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F12_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f13
 ��������  : F13���ն˵�ѹ/����ģ�������ò���
             CMD_AFN_4_F13_TML_SIMULA_CFG 
             CMD_AFN_A_F13_TML_SIMULA_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��16�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f13(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f13() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8 ucNum = 0;
    sMtAfn04F13_f * psAfn04F13_f = (sMtAfn04F13_f*)psFrame;
    sMtAfn04F13*    psAfn04F13   = (sMtAfn04F13*)psUser;
  
    if(MT_TRANS_U2F == eTrans)
    {
        ucNum = psAfn04F13->ucNum;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucNum = psAfn04F13_f->ucNum;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(sMtAfn04F13_f)* ucNum + sizeof(UINT8);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f14
 ��������  : F14���ն��ܼ������ò���
             CMD_AFN_4_F14_TML_GRUP_TOTL 
             CMD_AFN_A_F14_TML_GRUP_TOTL
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��16�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f14(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f14() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucNum = 0;
    UINT8  ucM   = 0;
    UINT16 usLen = 0;
    INT32  i     = 0;
    INT32  j     = 0;
    sMtAfn04F14_f * psAfn04F14_f = (sMtAfn04F14_f*)psFrame;
    sMtAfn04F14*    psAfn04F14   = (sMtAfn04F14*)psUser;
  
    if(MT_TRANS_U2F == eTrans)
    {
        ucNum = psAfn04F14->ucN;
        if(ucNum > 8 || ucNum < 1)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f14() ucNum is err ucNum = %d", ucNum);
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            for(i = 0; i < ucNum; i++)
            {
                usLen += 2;
                
                ucM = psAfn04F14->sOne[i].ucM;
                if(ucM > 64)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f14() ucM is err ucNum = %d", ucM);
                    #endif
                    return MT_ERR_OUTRNG;
                }

                usLen += ucM;
            }
        }

        usLen += 1;
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psAfn04F14_f = psAfn04F14_f;
        j = j;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f15
 ��������  : F15���й��ܵ������Խ���¼���������
             CMD_AFN_4_F15_HAVE_DIFF_EVENT 
             CMD_AFN_A_F15_HAVE_DIFF_EVENT
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��16�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f15(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f15() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucNum = 0;
    UINT16 usLen = 0;
    INT32  i     = 0;
    sMtAfn04F15_f * psAfn04F15_f = (sMtAfn04F15_f*)psFrame;
    sMtAfn04F15*    psAfn04F15   = (sMtAfn04F15*)psUser;
  
    if(MT_TRANS_U2F == eTrans)
    {
        ucNum = psAfn04F15->ucN;
        if(ucNum > 8 || ucNum < 1)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f15() ucNum is err ucNum = %d", ucNum);
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            usLen += sizeof(sMtAfn04F15_f)  * ucNum;
        }

        usLen += 1;
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psAfn04F15_f = psAfn04F15_f;
        i = i;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f16
 ��������  : F16������ר���û���������
             CMD_AFN_4_F16_VPN_USER_PWD 
             CMD_AFN_A_F16_VPN_USER_PWD
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��16�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f16(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04F16_f);
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f17
 ��������  : F17���ն˱�����ֵ
             CMD_AFN_4_F17_TML_SAFE_VALUE
             CMD_AFN_A_F17_TML_SAFE_VALUE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f17(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet = emt_trans_sXXX(eTrans, (float*)psUser, (sMtsXXX*)psFrame);
    *pusfLen = sizeof(sMtsXXX);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f18
 ��������  : F18���ն˹���ʱ��
             CMD_AFN_4_F18_TML_PCTRL_PERD
             CMD_AFN_A_F18_TML_PCTRL_PERD
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f18(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtPCtrl_f);  
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f19
 ��������  : F19���ն�ʱ�ι��ض�ֵ����ϵ��
             CMD_AFN_4_F19_TML_PCTRL_FACTOR
             CMD_AFN_A_F19_TML_PCTRL_FACTOR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f19(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet = emt_trans_sXX(eTrans, (sMtsXX*)psUser, (sMtsXX_f*)psFrame);
    *pusfLen = sizeof(sMtsXX_f);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f20
 ��������  : F20���ն��µ������ض�ֵ����ϵ��
             CMD_AFN_4_F20_TML_MONTH_FACTOR
             CMD_AFN_A_F20_TML_MONTH_FACTOR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f20(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet = emt_trans_sXX(eTrans, (sMtsXX*)psUser, (sMtsXX_f*)psFrame);
    *pusfLen = sizeof(sMtsXX_f);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f21
 ��������  : F21���ն˵���������ʱ�κͷ�����
             CMD_AFN_4_F21_TML_POWER_FACTOR
             CMD_AFN_A_F21_TML_POWER_FACTOR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f21(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f21() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtTmlPowerFactor   *psPowerFactor   = (sMtTmlPowerFactor*)psUser;
    sMtTmlPowerFactor_f *psPowerFactor_f = (sMtTmlPowerFactor_f*)psFrame;
    INT32 i =  0;

    if(MT_TRANS_U2F == eTrans)
    {
        for(i = 0; i < 48; i++)
        {
            if(psPowerFactor->ucPayRateID[i] > MT_PAYRATE_ID_MAX || 
               psPowerFactor->ucPayRateID[i] > MT_PAYRATE_ID_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f21() ucPayRateID is out range");
                #endif
                return MT_ERR_OUTRNG;
            }

            psPowerFactor_f->ucPayRateID[i] = psPowerFactor->ucPayRateID[i];            
        }

        if(psPowerFactor->ucPayRateNum > MT_PAYRATE_NUM_MAX || 
           psPowerFactor->ucPayRateNum > MT_PAYRATE_NUM_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f21() ucPayRateNum is out range");
            #endif
            return MT_ERR_OUTRNG;
        }

        psPowerFactor_f->ucPayRateNum = psPowerFactor->ucPayRateNum;     

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        for(i = 0; i < 48; i++)
        {
            if(psPowerFactor_f->ucPayRateID[i] > MT_PAYRATE_ID_MAX || 
               psPowerFactor_f->ucPayRateID[i] > MT_PAYRATE_ID_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f21() ucPayRateID is out range");
                #endif
                return MT_ERR_OUTRNG;
            }

            psPowerFactor->ucPayRateID[i] = psPowerFactor_f->ucPayRateID[i];            
        }

        if(psPowerFactor_f->ucPayRateNum > MT_PAYRATE_NUM_MAX || 
           psPowerFactor_f->ucPayRateNum > MT_PAYRATE_NUM_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f21() ucPayRateNum is out range");
            #endif
            return MT_ERR_OUTRNG;
        }

        psPowerFactor->ucPayRateNum = psPowerFactor_f->ucPayRateNum; 

    }
    else
    {
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f22
 ��������  : F22���ն˵���������
             CMD_AFN_4_F22_TML_POWER_RATE
             CMD_AFN_A_F22_TML_POWER_RATE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f22(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f22() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    INT32         i     = 0;
    UINT8         ucM   = 0;
    eMtErr        eRet  = MT_OK;
    sMtAfn04f22   *pUsr = (sMtAfn04f22*)psUser;
    sMtAfn04f22_f *pFrm = (sMtAfn04f22_f*)psFrame;


    if(MT_TRANS_U2F == eTrans)
    {   
       ucM = pUsr->ucM;
       
        if(ucM > MT_PAYRATE_NUM_MAX || 
           ucM > MT_PAYRATE_NUM_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f22() PayRateNum is out range");
            #endif
            return MT_ERR_OUTRNG;
        }
        
        pFrm->ucM = ucM;
        for(i = 0; i < ucM; i++)
        {
           eRet = emt_trans_sX7(eTrans, 
                                (sMtFmt_sX7*)&(pUsr->sPayRate[i]), 
                                (sMtFmt_sX7_f*)&(pFrm->sPayRate[i]));
           if(MT_OK != eRet)
           {
                #ifdef MT_DBG
                DEBUG("emt_trans_sX7() err %d", eRet);
                #endif
                return eRet;
           }
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucM = pFrm->ucM;
       
        if(ucM > MT_PAYRATE_NUM_MAX || 
           ucM > MT_PAYRATE_NUM_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f22() PayRateNum is out range");
            #endif
            return MT_ERR_OUTRNG;
        }
        
        pUsr->ucM = ucM;
        for(i = 0; i < ucM; i++)
        {
           eRet = emt_trans_sX7(eTrans, 
                                (sMtFmt_sX7*)&(pUsr->sPayRate[i]), 
                                (sMtFmt_sX7_f*)&(pFrm->sPayRate[i]));
           if(MT_OK != eRet)
           {
                #ifdef MT_DBG
                DEBUG("emt_trans_sX7() err %d", eRet);
                #endif
                return eRet;
           }
        }

    }
    else
    {
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f23
 ��������  : F23���ն˴߷Ѹ澯����
             CMD_AFN_4_F23_TML_WARNING_CFG
             CMD_AFN_A_F23_TML_WARNING_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f23(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04f23_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f25
 ��������  : F25���������������
             CMD_AFN_4_F25_MP_BASE_CFG
             CMD_AFN_A_F25_MP_BASE_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04f25_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0af26
 ��������  : F26����������ֵ����
             CMD_AFN_4_F26_MP_LIMIT_CFG
             CMD_AFN_A_F26_MP_LIMIT_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f26(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04f26_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f27
 ��������  : F27��������ͭ��������� 
             CMD_AFN_4_F27_MP_LOSS_CFG
             CMD_AFN_A_F27_MP_LOSS_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f27(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn04f27_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f28
 ��������  : F28�������㹦�������ֶ���ֵ 
             CMD_AFN_4_F28_MP_PERIOD_FACTOR
             CMD_AFN_A_F28_MP_PERIOD_FACTOR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f28(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = sizeof(sMtAfn04f28_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f29
 ��������  : F29���ն˵��ص��ܱ���ʾ��  
             CMD_AFN_4_F29_TML_METER_ID
             CMD_AFN_A_F29_TML_METER_ID
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f29(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = sizeof(sMtAfn04f29_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f30
 ��������  : F30��̨�����г���ͣ��/Ͷ������
             CMD_AFN_4_F30_TML_AUTO_READ
             CMD_AFN_A_F30_TML_AUTO_READ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f30(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = sizeof(sMtAfn04f30_f);
     return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f31
 ��������  : F31���ز��ӽڵ㸽���ڵ��ַ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f31() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8 ucN;
    sMtAfn04f31   *psAfn04f31   = (sMtAfn04f31*)psUser;
    sMtAfn04f31_f *psAfn04f31_f = (sMtAfn04f31_f*)psFrame;
    
    if(MT_TRANS_U2F == eTrans)
    {
        ucN = psAfn04f31->ucN;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psAfn04f31_f->ucN;
    }
    else
    {
        return MT_ERR_PARA;
    }


     *pusfLen = sizeof(sMtFmt12) * ucN + 1;
    return MT_OK;

}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f33
 ��������  : F33���ն˳������в������� 
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f33(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f31() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucN   = 0;
    UINT8  ucM   = 0;
    INT32  i     = 0;
    UINT16 usLen = 0;
    UINT16 usLn  = 0;
    sMtAfn04f33   *psAfn04f33   = (sMtAfn04f33*)psUser;
    sMtAfn04f33_f *psAfn04f33_f = (sMtAfn04f33_f*)psFrame;
    
    usLn = sizeof(sMtFmt18_f) + sizeof(sMtFmt19_f) + 9;
    
    if(MT_TRANS_U2F == eTrans)
    {
        ucN = psAfn04f33->ucN;
        for(i = 0; i < ucN; i++)
        {
            usLen += usLn;
            ucM = psAfn04f33->sOne[i].ucM;
            usLen += ucM * sizeof(sMtFmt19_f);
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psAfn04f33_f->ucN;

        for(i = 0; i < ucN; i++)
        {
            usLen += usLn;
            ucM = psAfn04f33_f->sOne[i].ucM;
            usLen += ucM * sizeof(sMtFmt19_f);
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usLen;
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f34
 ��������  : F34������������ͨ��ģ��Ĳ�������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f34(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f34() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucN   = 0;
    sMtAfn04f34   *psU  = (sMtAfn04f34*)psUser;
    sMtAfn04f34_f *psF  = (sMtAfn04f34_f*)psFrame;

    if(MT_TRANS_U2F == eTrans)
    {
        ucN = psU->ucN;
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psF->ucN;       
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = ucN * sizeof(sMtConDownCfgOne_f) + sizeof(UINT8);
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f35
 ��������  : F35��̨�����г����ص㻧����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f35(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f35() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucN   = 0;
    sMtAfn04f35   *psU  = (sMtAfn04f35*)psUser;
    sMtAfn04f35_f *psF  = (sMtAfn04f35_f*)psFrame;

    if(MT_TRANS_U2F == eTrans)
    {
        ucN = psU->ucN;
       
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psF->ucN;

       
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = ucN * sizeof(sMtTmlReadVipOne_f) + sizeof(UINT8);
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f36
 ��������  : F36���ն�����ͨ��������������
             CMD_AFN_4_F36_TML_UP_LIMIT
             CMD_AFN_A_F36_TML_UP_LIMIT
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f36(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(UINT32);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f37
 ��������  : F37���ն˼���ͨ�Ų���
             CMD_AFN_4_F37_TML_CASC_CFG
             CMD_AFN_A_F37_TML_CASC_CFG
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f37(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f37() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8  ucN   = 0;
    sMtAfn04f37   *psU  = (sMtAfn04f37*)psUser;
    sMtAfn04f37_f *psF  = (sMtAfn04f37_f*)psFrame;

    if(MT_TRANS_U2F == eTrans)
    {
        ucN = psU->ucN;
       
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psF->ucN;

    }
    else
    {
        return MT_ERR_PARA;
    }

     *pusfLen = ucN * sizeof(sMtCascOne_f) + 7 * sizeof(UINT8);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f38
 ��������  : F38��1�������������� �����ն�֧�ֵ�1�����������ڣ�
             CMD_AFN_4_F38_CFG_ASK_1
             CMD_AFN_A_F38_CFG_ASK_1
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f38(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f38() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8         ucFN   = 0;
    UINT8         ucN    = 0;
    UINT8         ucM    = 0;
    UINT8         ucTmp  = 0;
    UINT8         ucAfn  = 0;
    UINT8         ucFn   = 0;
    UINT8         ucTeam = 0;
    UINT8         ucTMax = 0;
    UINT8         ucBit  = 0;
    UINT16        usLen  = 0;
    UINT16        usCmd  = 0;
    INT32         i      = 0;
    INT32         m      = 0;
    INT32         n      = 0;
    eMtCmd        eCmd   = CMD_AFN_F_UNKOWN;
    eMtErr        eRet   = MT_OK;
    sMtCmdInfor   sCmdInfor;
    

    sMtAfn04f38     *psU    = (sMtAfn04f38*)psUser;
    sMtAfn04f38_f   *psF    = (sMtAfn04f38_f*)psFrame;
    sMtAsk1CfgOne_f *psAsk1CfgOne_f = NULL;
    sMtAsk1CfgOne   *psAsk1CfgOne   = NULL;
    UINT8           *pTmp   = NULL;
        
    if(MT_TRANS_U2F == eTrans)
    {
        ucTmp = psU->ucBig;
        if(MT_USER_CLASS_MIN > ucTmp || MT_USER_CLASS_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f38() ucBig is out of range ucBig = %d", ucTmp);
            #endif
            return MT_ERR_OUTRNG;
        }
    
        psF->ucBig = ucTmp;
        
        ucM = psU->ucM;
        if(MT_ASK_M_MIN > ucM || MT_ASK_M_MAX < ucM)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f38() ucM is out of range ucBig = %d", ucM);
            #endif
            return MT_ERR_OUTRNG;
        }

        psF->ucM = ucM;
        
        // ���㳤��
        usLen = 2;
        
        psAsk1CfgOne_f = (sMtAsk1CfgOne_f *)&(psF->sOne[0]);
        pTmp = (UINT8*)&(psAsk1CfgOne_f->ucF8n[0]);

        for(m = 0; m < ucM; m++)
        {
            psAsk1CfgOne = &(psU->sOne[m]);
            psAsk1CfgOne_f->ucSmall = psAsk1CfgOne->ucSmall;
            ucFN = psAsk1CfgOne->ucFN;
            for(n = 0; n < ucFN; n++)
            {
                eCmd  = psAsk1CfgOne->eCmd[n];
                usCmd = (UINT16)eCmd;
                ucAfn = (usCmd & 0xFF00) >> 8;
                ucFn  = usCmd & 0xFF;

                if(ucAfn != AFN_0C_ASK1)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f38() Afn of Cmd is out of range ucAfn = %d", ucAfn);
                    #endif
                    return MT_ERR_OUTRNG;
                }

                // ��ø�Fn��Ӧ���鼰�ڸ����ֵ
                ucTeam = ucmt_get_fn_team(ucFn);
                if(0xFF == ucTeam)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f38() ucTeam is out of range");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                ucBit  = ucmt_get_fn_bit(ucFn);
                if(0xFF == ucBit)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f38() ucBit is out of range");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                pTmp[ucTeam] |= ucBit;
                ucTMax = ((ucTMax > ucTeam) ?  ucTMax : ucTeam);
                
            }
            
            psAsk1CfgOne_f->ucN = (ucTMax + 1);
            pTmp  += (ucTMax + 3);

             // ���㳤��
            usLen += (ucTMax + 3);

            // ȷ����һ��֡�б䳤����ָ��
            psAsk1CfgOne_f = (sMtAsk1CfgOne_f*)pTmp;
    
        }       
    }
    else if(MT_TRANS_F2U == eTrans)
    {  
        ucTmp = psF->ucBig;
        if(MT_USER_CLASS_MIN > ucTmp || MT_USER_CLASS_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f38() ucBig is out of range ucBig = %d", ucTmp);
            #endif
            return MT_ERR_OUTRNG;
        }
    
        psU->ucBig = ucTmp;
        
        ucM = psF->ucM;
        if(MT_ASK_M_MIN > ucM || MT_ASK_M_MAX < ucM)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f38() ucM is out of range ucBig = %d", ucM);
            #endif
            return MT_ERR_OUTRNG;
        }

        psU->ucM = ucM;
        
        usLen = 2;
        pTmp  = (UINT8*)&(psF->sOne);

        for(m = 0; m < ucM; m++)
        {
           ucFN = 0;
           psAsk1CfgOne_f = (sMtAsk1CfgOne_f *)pTmp;
           psU->sOne[m].ucSmall = psAsk1CfgOne_f->ucSmall;
           
           ucN = psAsk1CfgOne_f->ucN;
           usLen += 2;
           pTmp  += 2;
           
           if(ucN > 31)
           {
              #ifdef MT_DBG
              DEBUG("emtTrans_afn04f38() ucN is out of range ucN = %d", ucN);
              #endif
              return MT_ERR_OUTRNG;
           }
           
           for(n = 0; n < ucN; n++)
           {
                ucFn = psAsk1CfgOne_f->ucF8n[n];

                if(0 == ucFn)
                {
                    continue;
                }

                for(i = 0; i < 8; i++)
                {
                    ucBit = (0x01 << i);

                    if(ucFn & ucBit)
                    {
                        // �ϳ�����
                        usCmd = ((AFN_0C_ASK1 << 8) | (8 * n + i + 1));
                        eCmd = (eMtCmd)usCmd;

                        //�ж������Ƿ�Ϸ�
                        eRet = eMtGetCmdInfor(eCmd, MT_DIR_S2M, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtTrans_afn04f38() eCmd err = 0x%04X", eCmd);
                            #endif
                            return MT_ERR_NONE; 
                        }

                        psU->sOne[m].eCmd[ucFN++] = eCmd;
                    }
                }
            }
           
            psU->sOne[m].ucFN = ucFN;
           
            usLen += ucN;
            pTmp  += ucFN;
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f39
 ��������  : F39��2�������������ã����ն�֧�ֵ�2�����������ڣ�
             CMD_AFN_4_F39_CFG_ASK_2
             CMD_AFN_A_F39_CFG_ASK_2
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f39(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f39() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8         ucFN   = 0;
    UINT8         ucN    = 0;
    UINT8         ucM    = 0;
    UINT8         ucTmp  = 0;
    UINT8         ucAfn  = 0;
    UINT8         ucFn   = 0;
    UINT8         ucTeam = 0;
    UINT8         ucTMax = 0;
    UINT8         ucBit  = 0;
    UINT16        usLen  = 0;
    UINT16        usCmd  = 0;
    INT32         i      = 0;
    INT32         m      = 0;
    INT32         n      = 0;
    eMtCmd        eCmd   = CMD_AFN_F_UNKOWN;
    eMtErr        eRet   = MT_OK;
    sMtCmdInfor   sCmdInfor;
    

    sMtAfn04f39     *psU    = (sMtAfn04f39*)psUser;
    sMtAfn04f39_f   *psF    = (sMtAfn04f39_f*)psFrame;
    sMtAsk2CfgOne_f *psAsk2CfgOne_f = NULL;
    sMtAsk2CfgOne   *psAsk2CfgOne   = NULL;
    UINT8           *pTmp   = NULL;
        
    if(MT_TRANS_U2F == eTrans)
    {
        ucTmp = psU->ucBig;
        if(MT_USER_CLASS_MIN > ucTmp || MT_USER_CLASS_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f39() ucBig is out of range ucBig = %d", ucTmp);
            #endif
            return MT_ERR_OUTRNG;
        }
    
        psF->ucBig = ucTmp;
        
        ucM = psU->ucM;
        if(MT_ASK_M_MIN > ucM || MT_ASK_M_MAX < ucM)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f39() ucM is out of range ucBig = %d", ucM);
            #endif
            return MT_ERR_OUTRNG;
        }

        psF->ucM = ucM;
        
        // ���㳤��
        usLen = 2;
        
        psAsk2CfgOne_f = (sMtAsk2CfgOne_f *)&(psF->sOne[0]);
        pTmp = (UINT8*)&(psAsk2CfgOne_f->ucF8n[0]);

        for(m = 0; m < ucM; m++)
        {
            psAsk2CfgOne = &(psU->sOne[m]);
            psAsk2CfgOne_f->ucSmall = psAsk2CfgOne->ucSmall;
            ucFN = psAsk2CfgOne->ucFN;
            for(n = 0; n < ucFN; n++)
            {
                eCmd  = psAsk2CfgOne->eCmd[n];
                usCmd = (UINT16)eCmd;
                ucAfn = (usCmd & 0xFF00) >> 8;
                ucFn  = usCmd & 0xFF;

                if(ucAfn != AFN_0D_ASK2)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f39() Afn of Cmd is out of range ucAfn = %d", ucAfn);
                    #endif
                    return MT_ERR_OUTRNG;
                }

                // ��ø�Fn��Ӧ���鼰�ڸ����ֵ
                ucTeam = ucmt_get_fn_team(ucFn);
                if(0xFF == ucTeam)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f39() ucTeam is out of range");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                ucBit  = ucmt_get_fn_bit(ucFn);
                if(0xFF == ucBit)
                {
                    #ifdef MT_DBG
                    DEBUG("emtTrans_afn04f39() ucBit is out of range");
                    #endif
                    return MT_ERR_OUTRNG;
                }

                pTmp[ucTeam] |= ucBit;
                ucTMax = ((ucTMax > ucTeam) ?  ucTMax : ucTeam);
                
            }
            
            psAsk2CfgOne_f->ucN = (ucTMax + 1);
            pTmp  += (ucTMax + 3);

             // ���㳤��
            usLen += (ucTMax + 3);

            // ȷ����һ��֡�б䳤����ָ��
            psAsk2CfgOne_f = (sMtAsk2CfgOne_f*)pTmp;
    
        }       
    }
    else if(MT_TRANS_F2U == eTrans)
    {  
        ucTmp = psF->ucBig;
        if(MT_USER_CLASS_MIN > ucTmp || MT_USER_CLASS_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f39() ucBig is out of range ucBig = %d", ucTmp);
            #endif
            return MT_ERR_OUTRNG;
        }
    
        psU->ucBig = ucTmp;
        
        ucM = psF->ucM;
        if(MT_ASK_M_MIN > ucM || MT_ASK_M_MAX < ucM)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f39() ucM is out of range ucBig = %d", ucM);
            #endif
            return MT_ERR_OUTRNG;
        }

        psU->ucM = ucM;
        
        usLen = 2;
        pTmp  = (UINT8*)&(psF->sOne);

        for(m = 0; m < ucM; m++)
        {
           ucFN = 0;
           psAsk2CfgOne_f = (sMtAsk2CfgOne_f *)pTmp;
           psU->sOne[m].ucSmall = psAsk2CfgOne_f->ucSmall;
           
           ucN = psAsk2CfgOne_f->ucN;
           usLen += 2;
           pTmp  += 2;
           
           if(ucN > 31)
           {
              #ifdef MT_DBG
              DEBUG("emtTrans_afn04f39() ucN is out of range ucN = %d", ucN);
              #endif
              return MT_ERR_OUTRNG;
           }
           
           for(n = 0; n < ucN; n++)
           {
                ucFn = psAsk2CfgOne_f->ucF8n[n];
                printf("ucFn[%d] = 0x%02X\n", n, ucFn);

                if(0 == ucFn)
                {
                    continue;
                }

                for(i = 0; i < 8; i++)
                {
                    ucBit = (0x01 << i);

                    if(ucFn & ucBit)
                    {
                        // �ϳ�����
                        usCmd = ((AFN_0D_ASK2 << 8) | (8 * n + i + 1));
                        eCmd = (eMtCmd)usCmd;

                        //�ж������Ƿ�Ϸ�
                        eRet = eMtGetCmdInfor(eCmd, MT_DIR_S2M, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtTrans_afn04f39() eCmd err = 0x%04X", eCmd);
                            #endif
                           // return MT_ERR_NONE; 
                        }

                        psU->sOne[m].eCmd[ucFN++] = eCmd;
                    }
                }
            }
           
            psU->sOne[m].ucFN = ucFN;
           
            usLen += ucN;
            pTmp  += ucFN;
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f41
 ��������  : F41��ʱ�ι��ض�ֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f41(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     //*pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f42
 ��������  : F42�����ݹ��ز���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f42(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 6;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f42
 ��������  : F43�����ʿ��ƵĹ��ʼ��㻬��ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f43(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f44
 ��������  : F44��Ӫҵ��ͣ�ز���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f44(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 8;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f45
 ��������  : F45�������ִ��趨
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f45(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f46
 ��������  : F46���µ����ض�ֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f46(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 4;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f47
 ��������  : F47�����������ѣ��ز���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f47(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 17;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f48
 ��������  : F48������ִ��趨
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f48(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f49
 ��������  : F49�����ظ澯ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f57
 ��������  : F57���ն������澯����M��ֹ����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f57(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 3;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f58
 ��������  : F58���ն��Զ��������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f58(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 4;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f59
 ��������  : F59�����ܱ��쳣�б���ֵ�趨
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f59(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 4;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f60
 ��������  : F60��г����ֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f60(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 2 * (4+19*2);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f61
 ��������  : F61��ֱ��ģ�����������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f61(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f65
 ��������  : F65����ʱ�ϱ�1��������������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f65(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f65() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8         ucTmp  = 0;
    eMtErr        eRet   = MT_OK;
    sMtAfn04f65     *psU    = (sMtAfn04f65*)psUser;
    sMtAfn04f65_f   *psF    = (sMtAfn04f65_f*)psFrame;
        
    if(MT_TRANS_U2F == eTrans)
    {
        switch(psU->eUnit)
        {
            case MT_RPT_mm:
                ucTmp = 0;
                break;
                
            case MT_RPT_HH:
                ucTmp = 1;
                break;

            case MT_RPT_DD:
                ucTmp = 2;
                break;

            case MT_RPT_MM:
                ucTmp = 3;
                break;

            default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f65() eUint is out range");
                #endif
                return MT_ERR_OUTRNG;    
                //break;

        }
        
        psF->ucUnit = ucTmp;

        // ucPeriod 
        ucTmp = psU->ucPeriod;
        if(MT_PRD_MIN > ucTmp ||MT_PRD_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() eUint is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psF->ucPeriod = ucTmp;

        // sTime
        eRet = emt_trans_YYWWMMDDhhmmss(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() emt_trans_YYWWMMDDhhmmss is error eRet = %d", eRet);
            #endif
            return eRet; 
        }

        // ucR
        ucTmp = psU->ucR;
        if(MT_R_MIN > ucTmp || MT_R_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() ucR is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psF->ucR = ucTmp;

        // �����ʶ
        eRet = emt_cmdpn_to_dadt(AFN_0C_ASK1, &(psF->sDaDt[0]),  &(psF->ucN), &(psU->sCmdPn[0]), psU->ucN); 
        if(MT_OK != eRet)
        {           
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() emt_cmdpn_to_dadt() error = %d", eRet);
            #endif
            return eRet;
        }

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucTmp = psF->ucUnit;
        switch(ucTmp)
        {
            case 0:
                psU->eUnit = MT_RPT_mm;
                break;
                
            case 1:
                psU->eUnit = MT_RPT_HH;
                break;

            case 2:
                psU->eUnit = MT_RPT_DD;
                break;

            case 3:
                psU->eUnit = MT_RPT_MM;
                break;

            default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f65() ucUnit is out range");
                #endif
                return MT_ERR_OUTRNG;    
                //break;

        }
        
        // ucPeriod 
        ucTmp = psF->ucPeriod;
        if(MT_PRD_MIN > ucTmp ||MT_PRD_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() eUint is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psU->ucPeriod = ucTmp;

        // sTime
        eRet = emt_trans_YYWWMMDDhhmmss(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() emt_trans_YYWWMMDDhhmmss is error eRet = %d", eRet);
            #endif
            return eRet; 
        }

        // ucR
        ucTmp = psF->ucR;
        if(MT_R_MIN > ucTmp || MT_R_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() ucR is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psU->ucR = ucTmp;

        // �����ʶ
        eRet = emt_dadt_to_cmdpn(AFN_0C_ASK1, &(psF->sDaDt[0]),  psF->ucN, &(psU->sCmdPn[0]), &(psU->ucN)); 
        if(MT_OK != eRet)
        {           
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f65() emt_dadt_to_cmdpn() error = %d", eRet);
            #endif
            return eRet;
        }     
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * 3 + sizeof(sMtFmt01_f) +  psF->ucN * sizeof(sMtDaDt);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f66
 ��������  : F66����ʱ�ϱ�2��������������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f66(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f66() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    UINT8         ucTmp  = 0;
    eMtErr        eRet   = MT_OK;
    sMtAfn04f66     *psU    = (sMtAfn04f66*)psUser;
    sMtAfn04f66_f   *psF    = (sMtAfn04f66_f*)psFrame;
        
    if(MT_TRANS_U2F == eTrans)
    {
        switch(psU->eUnit)
        {
            case MT_RPT_mm:
                ucTmp = 0;
                break;
                
            case MT_RPT_HH:
                ucTmp = 1;
                break;

            case MT_RPT_DD:
                ucTmp = 2;
                break;

            case MT_RPT_MM:
                ucTmp = 3;
                break;

            default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f66() eUint is out range");
                #endif
                return MT_ERR_OUTRNG;    
                //break;

        }
        
        psF->ucUnit = ucTmp;

        // ucPeriod 
        ucTmp = psU->ucPeriod;
        if(MT_PRD_MIN > ucTmp ||MT_PRD_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() eUint is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psF->ucPeriod = ucTmp;

        // sTime
        eRet = emt_trans_YYWWMMDDhhmmss(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() emt_trans_YYWWMMDDhhmmss is error eRet = %d", eRet);
            #endif
            return eRet; 
        }

        // ucR
        ucTmp = psU->ucR;
        if(MT_R_MIN > ucTmp || MT_R_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() ucR is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psF->ucR = ucTmp;

        // �����ʶ
        eRet = emt_cmdpn_to_dadt(AFN_0D_ASK2, &(psF->sDaDt[0]),  &(psF->ucN), &(psU->sCmdPn[0]), psU->ucN); 
        if(MT_OK != eRet)
        {           
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() emt_cmdpn_to_dadt() error = %d", eRet);
            #endif
            return eRet;
        }

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucTmp = psF->ucUnit;
        switch(ucTmp)
        {
            case 0:
                psU->eUnit = MT_RPT_mm;
                break;
                
            case 1:
                psU->eUnit = MT_RPT_HH;
                break;

            case 2:
                psU->eUnit = MT_RPT_DD;
                break;

            case 3:
                psU->eUnit = MT_RPT_MM;
                break;

            default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn04f66() ucUnit is out range");
                #endif
                return MT_ERR_OUTRNG;    
                //break;

        }
        
        // ucPeriod 
        ucTmp = psF->ucPeriod;
        if(MT_PRD_MIN > ucTmp ||MT_PRD_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() eUint is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psU->ucPeriod = ucTmp;

        // sTime
        eRet = emt_trans_YYWWMMDDhhmmss(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() emt_trans_YYWWMMDDhhmmss is error eRet = %d", eRet);
            #endif
            return eRet; 
        }

        // ucR
        ucTmp = psF->ucR;
        if(MT_R_MIN > ucTmp || MT_R_MAX < ucTmp)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() ucR is out range");
            #endif
            return MT_ERR_OUTRNG; 
        }

        psU->ucR = ucTmp;

        // �����ʶ
        eRet = emt_dadt_to_cmdpn(AFN_0D_ASK2, &(psF->sDaDt[0]),  psF->ucN, &(psU->sCmdPn[0]), &(psU->ucN)); 
        if(MT_OK != eRet)
        {           
            #ifdef MT_DBG
            DEBUG("emtTrans_afn04f66() emt_dadt_to_cmdpn() error = %d", eRet);
            #endif
            return eRet;
        }     
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * 3 + sizeof(sMtFmt01_f) +  psF->ucN * sizeof(sMtDaDt);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f67
 ��������  : F67����ʱ�ϱ�1��������������/ֹͣ����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f67(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f67() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn04f67     *psU    = (sMtAfn04f67*)psUser;
    sMtAfn04f67_f   *psF    = (sMtAfn04f67_f*)psFrame;
    
    if(MT_TRANS_U2F == eTrans)
    {
        switch(psU->eGo)
        {
            case MT_AUTO_GO:
                psF->ucGo = 0x55;
                break;
                
            case MT_AUTO_STOP:
                psF->ucGo = 0xAA;
                break;

            default:
                 #ifdef MT_DBG
                 DEBUG("emtTrans_afn04f67() eGo is out range");
                 #endif
                 return MT_ERR_OUTRNG;   
                 //break;
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        if(0x55 == psF->ucGo)
        {
            psU->eGo = MT_AUTO_GO;
        }
        else if(0xAA == psF->ucGo)
        {
            psU->eGo = MT_AUTO_STOP;
        }   
        else
        {
            psU->eGo = MT_AUTO_UNKOWN;
        }
    }
    else
    {
       return MT_ERR_PARA;
    }
      
    *pusfLen = sizeof(sMtAfn04f67_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f68
 ��������  : F68����ʱ�ϱ�2��������������/ֹͣ����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f68(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn04f68() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn04f68     *psU    = (sMtAfn04f68*)psUser;
    sMtAfn04f68_f   *psF    = (sMtAfn04f68_f*)psFrame;
    
    if(MT_TRANS_U2F == eTrans)
    {
        switch(psU->eGo)
        {
            case MT_AUTO_GO:
                psF->ucGo = 0x55;
                break;
                
            case MT_AUTO_STOP:
                psF->ucGo = 0xAA;
                break;

            default:
                 #ifdef MT_DBG
                 DEBUG("emtTrans_afn04f68() eGo is out range");
                 #endif
                 return MT_ERR_OUTRNG;   
                 //break;
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        if(0x55 == psF->ucGo)
        {
            psU->eGo = MT_AUTO_GO;
        }
        else if(0xAA == psF->ucGo)
        {
            psU->eGo = MT_AUTO_STOP;
        }   
        else
        {
            psU->eGo = MT_AUTO_UNKOWN;
        }
    }
    else
    {
       return MT_ERR_PARA;
    }
      
    *pusfLen = sizeof(sMtAfn04f68_f);
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f73
 ��������  : F73������������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f73(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 16 * 3;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f74
 ��������  : F74��������Ͷ�����в���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f74(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 10;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f75
 ��������  : F75����������������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f75(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 16;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f76
 ��������  : F76��������Ͷ�п��Ʒ�ʽ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f76(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn04f81
 ��������  : F81��ֱ��ģ����������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f81(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 4;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f82
 ��������  : F82��ֱ��ģ������ֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f82(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 4;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn04f83
 ��������  : F83��ֱ��ģ�����������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn04f83(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f1
 ��������  : F1��ң����բ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtRemoteTurnOff_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f9
 ��������  : F9��ʱ�ι���Ͷ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f9(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn05F9_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f12
 ��������  : F12����ǰ�����¸���Ͷ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f12(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = sizeof(sMtAfn05F12_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f12
 ��������  : F25���ն˱���Ͷ�� CMD_AFN_5_F25_TML_PROTECT_GO
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    *pusfLen = 1;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f31
 ��������  : F31����ʱ����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn05f31() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    eMtErr              eRet = MT_OK;
    sMtYYWWMMDDhhmmss   *psU = (sMtYYWWMMDDhhmmss*)psUser;
    sMtYYWWMMDDhhmmss_f *psF = (sMtYYWWMMDDhhmmss_f*)psFrame;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {

    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn05f31() para error!");
        #endif
        return MT_ERR_PARA;
    }

    eRet = emt_trans_YYWWMMDDhhmmss(eTrans, psU, psF);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYWWMMDDhhmmss() para error = %d", eRet);
        #endif
        return eRet;
    }
    
 // ������֡����ֽڳ���
 *pusfLen = sizeof(sMtYYWWMMDDhhmmss_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f32
 ��������  : F32��������Ϣ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f32(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn05f32() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    //eMtErr        eRet  = MT_OK;
    UINT8         ucLen = 0;
    sMtAfn05F32   *psU  = (sMtAfn05F32*)psUser;
    sMtAfn05F32_f *psF  = (sMtAfn05F32_f*)psFrame;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        ucLen = psF->ucLen;

    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        ucLen = psU->ucLen;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn05f32() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(UINT8) * (2 + ucLen);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f41
 ��������  : F41������������Ͷ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f41(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f42
 ��������  : F42�������������г�
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f42(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f49
 ��������  : F49������ָ��ͨ�Ŷ˿���ͣ����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f50
 ��������  : F50������ָ��ͨ�Ŷ˿ڻָ�����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f50(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f51
 ��������  : F51������ָ��ͨ�Ŷ˿����³���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f51(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f52
 ��������  : F52����ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f52(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn05f53
 ��������  : F53��ɾ��ָ��ͨ�Ŷ˿��µ�ȫ�����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn05f53(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 2;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn06f1
 ��������  : F1�������֤����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn06f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 16;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn06f2
 ��������  : F2�������֤��Ӧ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn06f2(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 16;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn06f3
 ��������  : F3��ȡ�����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn06f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 16;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn06f4
 ��������  : F4��ȡ�������Ӧ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn06f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = 16;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f1
 ��������  : F1���ն˰汾��Ϣ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f1() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F1_f * psF  = (sMtAfn09F1_f*)psFrame;
    sMtAfn09F1*    psU  = (sMtAfn09F1*)psUser;
    eMtErr         eRet = MT_OK; 
  
    if(MT_TRANS_U2F == eTrans)
    {
        memcpy(psF->ucFactoryID, psU->ucFactoryID, 4);
        memcpy(psF->ucDeviceID, psU->ucDeviceID, 8);
        memcpy(psF->ucSoftwareID, psU->ucSoftwareID, 4);
        memcpy(psF->ucInfoCodeCap, psU->ucInfoCodeCap, 11);
        memcpy(psF->ucProtolID, psU->ucProtolID, 4);
        memcpy(psF->ucHardWareID, psU->ucHardWareID, 4);
        eRet = emt_trans_YYMMDD(eTrans, &(psU->sDateSoftware), &(psF->sDateSoftware));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f1() emt_trans_YYMMDD() error = %d", eRet);
            #endif
            return eRet;
        }

        eRet = emt_trans_YYMMDD(eTrans, &(psU->sDateHardware), &(psF->sDateHardware));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f1() emt_trans_YYMMDD() error = %d", eRet);
            #endif
            return eRet;
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        memcpy(psU->ucFactoryID, psF->ucFactoryID, 4);
        memcpy(psU->ucDeviceID, psF->ucDeviceID, 8);
        memcpy(psU->ucSoftwareID, psF->ucSoftwareID, 4);
        memcpy(psU->ucInfoCodeCap, psF->ucInfoCodeCap, 11);
        memcpy(psU->ucProtolID, psF->ucProtolID, 4);
        memcpy(psU->ucHardWareID, psF->ucHardWareID, 4);
        eRet = emt_trans_YYMMDD(eTrans, &(psU->sDateSoftware), &(psF->sDateSoftware));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f1() emt_trans_YYMMDD() error = %d", eRet);
            #endif
            return eRet;
        }

        eRet = emt_trans_YYMMDD(eTrans, &(psU->sDateHardware), &(psF->sDateHardware));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f1() emt_trans_YYMMDD() error = %d", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(sMtAfn09F1_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f2
 ��������  : F2���ն�֧�ֵ����롢�����ͨ�Ŷ˿�����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f2(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f2() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F2_f * psF   = (sMtAfn09F2_f*)psFrame;
    sMtAfn09F2*    psU   = (sMtAfn09F2*)psUser;
    UINT8          ucTmp = 0;
    UINT16         usTmp = 0;
    INT32          i     = 0;
    UINT8          ucN   = 0;
    
  
    if(MT_TRANS_U2F == eTrans)
    {
        // ucPulseInputNum
        ucTmp = psU->ucPulseInputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() PulseInputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->ucPulseInputNum = ucTmp;

        // ucSwitchInputNum
        ucTmp = psU->ucSwitchInputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() SwitchInputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->ucSwitchInputNum = ucTmp;

        // ucDcNum
        ucTmp = psU->ucDcNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucDcNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->ucDcNum = ucTmp;

        // ucSwitchOutputNum
        ucTmp = psU->ucSwitchOutputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucSwitchOutputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->ucSwitchOutputNum = ucTmp;

        // usReadMeterNum
        usTmp = psU->usReadMeterNum;
        if(usTmp > MT_READ_METER_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usReadMeterNum is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->usReadMeterNum = usTmp;

        // usTmlRecvBuf
        usTmp = psU->usTmlRecvBuf;
        if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usTmlRecvBuf is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->usTmlRecvBuf = usTmp;

        // usTmlSendBuf
        usTmp = psU->usTmlSendBuf;
        if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usTmlSendBuf is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->usTmlSendBuf = usTmp;

        // MAC��ַ
        psF->sMacAddr = psU->sMacAddr;

        // PortNum
        ucTmp = psU->ucPortNum;
        if(ucTmp > MT_PORT_ID_MAX )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucPortNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psF->ucPortNum = ucTmp;
        ucN            = ucTmp;
        // sOne
        for(i = 0; i < ucN; i++)
        {
            // port
           ucTmp = psU->sPort[i].ucPort;
           if(ucTmp > MT_PORT_ID_MAX || ucTmp < MT_PORT_ID_MIN)
           {
               #ifdef MT_DBG
               DEBUG("emtTrans_afn09f2() ucPort is out range %d", ucTmp);
               #endif            
               return MT_ERR_OUTRNG;
           }

           psF->sPort[i].sWord.ucPort = ucTmp;

           // eInter
           switch(psU->sPort[i].eInter)
           {
            case MT_INTER_RS485:
                psF->sPort[i].sWord.eInter = 0;
                break;
                
            case MT_INTER_RS232:
                psF->sPort[i].sWord.eInter = 1;
                break;
                
            case MT_INTER_SERIW:
                psF->sPort[i].sWord.eInter = 2;
                break;
                
           default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() eInter is out range %d", psU->sPort[i].eInter);
                #endif            
                return MT_ERR_OUTRNG;
                //break;
           }

           // bStandard
           if(TRUE == psU->sPort[i].bStandard)
           {
               psF->sPort[i].sWord.bStandard = 0;
           }
           else
           {
               psF->sPort[i].sWord.bStandard = 1;
           }

           // eUse
           switch(psU->sPort[i].eUse)
           {
            case MT_PORR_USE_EXP:
                psF->sPort[i].sWord.eUse = 0;
                break;     
                
            case MT_PORR_USE_CNG:
                psF->sPort[i].sWord.eUse = 1;
                break;
                
            case MT_PORR_USE_GTH:
                psF->sPort[i].sWord.eUse = 2;
                break;

            case MT_PORR_USE_SHR:
                psF->sPort[i].sWord.eUse = 3;
                break;   

                default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() eUse is out range %d", psU->sPort[i].eUse);
                #endif  
                return MT_ERR_OUTRNG;
                // break;
            }

            // ulBaud
            psF->sPort[i].ulBaud =  psU->sPort[i].ulBaud;

            //usDevNum
            usTmp = psU->sPort[i].usDevNum;
            if(usTmp > MT_READ_METER_MAX )
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usDevNum is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psF->sPort[i].usDevNum = usTmp;

            // usRecvBuf
            usTmp = psU->sPort[i].usRecvBuf;
            if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usRecvBuf is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psF->sPort[i].usRecvBuf = usTmp;

            // usSendBuf
            usTmp = psU->sPort[i].usSendBuf;
            if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usSendBuf is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psF->sPort[i].usSendBuf = usTmp;


        }
        
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        // ucPulseInputNum
        ucTmp = psF->ucPulseInputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() PulseInputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->ucPulseInputNum = ucTmp;

        // ucSwitchInputNum
        ucTmp = psF->ucSwitchInputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() SwitchInputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->ucSwitchInputNum = ucTmp;

        // ucDcNum
        ucTmp = psF->ucDcNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucDcNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->ucDcNum = ucTmp;

        // ucSwitchOutputNum
        ucTmp = psF->ucSwitchOutputNum;
        if(ucTmp > MT_CIRCLE_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucSwitchOutputNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->ucSwitchOutputNum = ucTmp;

        // usReadMeterNum
        usTmp = psF->usReadMeterNum;
        if(usTmp > MT_READ_METER_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usReadMeterNum is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->usReadMeterNum = usTmp;

        // usTmlRecvBuf
        usTmp = psF->usTmlRecvBuf;
        if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usTmlRecvBuf is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->usTmlRecvBuf = usTmp;

        // usTmlSendBuf
        usTmp = psF->usTmlSendBuf;
        if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() usTmlSendBuf is out range %d", usTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->usTmlSendBuf = usTmp;

        // MAC��ַ
        psU->sMacAddr = psF->sMacAddr;

        // PortNum
        ucTmp = psF->ucPortNum;
        if(ucTmp > MT_PORT_ID_MAX )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f2() ucPortNum is out range %d", ucTmp);
            #endif            
            return MT_ERR_OUTRNG;
        }

        psU->ucPortNum = ucTmp;
        ucN            = ucTmp;
        // sOne
        for(i = 0; i < ucN; i++)
        {
            // port
           ucTmp = psF->sPort[i].sWord.ucPort;
           if(ucTmp > MT_PORT_ID_MAX || ucTmp < MT_PORT_ID_MIN)
           {
               #ifdef MT_DBG
               DEBUG("emtTrans_afn09f2() ucPort is out range %d", ucTmp);
               #endif            
               return MT_ERR_OUTRNG;
           }

           psU->sPort[i].ucPort = ucTmp;

           // eInter
           switch(psF->sPort[i].sWord.eInter)
           {
            case 0:
                psU->sPort[i].eInter = MT_INTER_RS485;
                break;
                
            case 1:
                psU->sPort[i].eInter = MT_INTER_RS232;
                break;
                
            case 2:
                psU->sPort[i].eInter = MT_INTER_SERIW;
                break;
                
           default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() eInter is out range %d", psF->sPort[i].sWord.eInter);
                #endif            
                return MT_ERR_OUTRNG;
                //break;
           }

           // bStandard
           if(psF->sPort[i].sWord.bStandard == 0)
           {
               psU->sPort[i].bStandard = TRUE;
           }
           else
           {
               psU->sPort[i].bStandard = FALSE;
           }

           // eUse
           switch(psF->sPort[i].sWord.eUse)
           {
            case 0:
                psU->sPort[i].eUse = MT_PORR_USE_EXP;
                break;     
                
            case 1:
                psU->sPort[i].eUse = MT_PORR_USE_CNG;
                break;
                
            case 2:
                psU->sPort[i].eUse = MT_PORR_USE_GTH;
                break;

            case 3:              
                psU->sPort[i].eUse = MT_PORR_USE_SHR;
                break;   

                default:
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() eUse is out range %d", psF->sPort[i].sWord.eUse);
                #endif  
                return MT_ERR_OUTRNG;
                // break;
            }

            // ulBaud
            psU->sPort[i].ulBaud =  psF->sPort[i].ulBaud;

            //usDevNum
            usTmp = psF->sPort[i].usDevNum;
            if(usTmp > MT_READ_METER_MAX )
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usDevNum is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psU->sPort[i].usDevNum = usTmp;

            // usRecvBuf
            usTmp = psF->sPort[i].usRecvBuf;
            if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usRecvBuf is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psU->sPort[i].usRecvBuf = usTmp;

            // usSendBuf
            usTmp = psF->sPort[i].usSendBuf;
            if(usTmp > MT_SEND_REC_MAX || usTmp < MT_SEND_REC_MIN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f2() usSendBuf is out range %d", usTmp);
                #endif            
                return MT_ERR_OUTRNG;
            }

            psU->sPort[i].usSendBuf = usTmp;

        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = 17 +  sizeof(sMtPortOne_f) * ucN;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f3
 ��������  : F3���ն�֧�ֵ���������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f3() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F3_f * psF   = (sMtAfn09F3_f*)psFrame;
    sMtAfn09F3*    psU   = (sMtAfn09F3*)psUser;
    UINT8          ucTmp = 0;
    UINT16         usTmp = 0;
    INT32          i     = 0;
    eMtErr         eRet  = MT_OK;
    
  
    if(MT_TRANS_U2F == eTrans)
    {
        // usMp
        usTmp = psU->usMp;
        if(usTmp > MT_PN_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() usMp is out range %d", usTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->usMp = usTmp;

        // ucGroup
        ucTmp = psU->ucGroup;
        if(ucTmp > MT_GROUP_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucGroup is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucGroup = ucTmp;

        // ucTask
        ucTmp = psU->ucTask;
        if(ucTmp > MT_TASK_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucTask is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucTask = ucTmp;

        // ucTask
        ucTmp = psU->ucTeam;
        if(ucTmp > 8)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucTeam is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucTeam = ucTmp;

        // eFrezMp
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezMp), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        
        psF->eFrezMp = ucTmp;

        // eFrezP
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezP), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }

        psF->eFrezP = ucTmp;
        
        // eFrezQ
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezQ), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        
        psF->eFrezQ = ucTmp;
        
        // eFrezPt
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezPt), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        
        psF->eFrezPt = ucTmp;
        
        // eFrezQt
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezQt), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        psF->eFrezQt = ucTmp;

        // ucDay
        ucTmp = psU->ucDay;
        if(ucTmp > MT_DAY_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucDay is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucDay = ucTmp;
        
        // ucMonth
        ucTmp = psU->ucMonth;
        if(ucTmp > MT_MONTH_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucMonth is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucMonth = ucTmp;

        // ucPCtrl
        ucTmp = psU->ucPCtrl;
        if(ucTmp > MT_PCTRL_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucDay is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucPCtrl = ucTmp;
        
        // ucHarm
        ucTmp = psU->ucHarm;
        if(ucTmp > MT_HARM_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucHarm is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucHarm = ucTmp;
        
        // ucCapa
        ucTmp = psU->ucCapa;
        if(ucTmp > MT_CAPA_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucCapa is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucCapa = ucTmp;

        // ucVip
        ucTmp = psU->ucVip;
        if(ucTmp > MT_CAPA_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucVip is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psF->ucVip = ucTmp;

        // bigclass
        usTmp = 0;
        for(i = 0; i < 16; i++)
        {
            if(TRUE == psU->bBig[i])
            {
                usTmp |= (0x01 << i);
            }
        }

        psF->bBig = usTmp;

        // ucSmall
        for(i = 0; i < 16; i++)
        {
            ucTmp = psU->ucSmall[i];
            if(ucTmp > MT_USER_CLASS_MAX)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f3() ucSmall is out range %d", ucTmp);
                #endif 
                return MT_ERR_OUTRNG;
            }

            psF->ucSmall[i] = ucTmp;
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        // usMp
        usTmp = psF->usMp;
        if(usTmp > MT_PN_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() usMp is out range %d", usTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->usMp = usTmp;

        // ucGroup
        ucTmp = psF->ucGroup;
        if(ucTmp > MT_GROUP_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucGroup is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucGroup = ucTmp;

        // ucTask
        ucTmp = psF->ucTask;
        if(ucTmp > MT_TASK_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucTask is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucTask = ucTmp;

        // ucTask
        ucTmp = psF->ucTeam;
        if(ucTmp > 8)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucTeam is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucTeam = ucTmp;

        // eFrezMp
        ucTmp = psF->eFrezMp;
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezMp), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        

        // eFrezP
        ucTmp = psF->eFrezP;
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezP), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }

        
        // eFrezQ
        ucTmp = psF->eFrezQ;
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezQ), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
        
        // eFrezPt
        ucTmp = psF->eFrezPt;
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezPt), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }
                
        // eFrezQt
        ucTmp = psF->eFrezQt;
        eRet = emt_trans_fmt_freeze(eTrans, &(psU->eFrezQt), &ucTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() emt_trans_fmt_freeze() error %d", eRet);
            #endif 
            return eRet;
        }

        // ucDay
        ucTmp = psF->ucDay;
        if(ucTmp > MT_DAY_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucDay is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucDay = ucTmp;
        
        // ucMonth
        ucTmp = psF->ucMonth;
        if(ucTmp > MT_MONTH_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucMonth is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucMonth = ucTmp;

        // ucPCtrl
        ucTmp = psF->ucPCtrl;
        if(ucTmp > MT_PCTRL_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucDay is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucPCtrl = ucTmp;
        
        // ucHarm
        ucTmp = psF->ucHarm;
        if(ucTmp > MT_HARM_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucHarm is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucHarm = ucTmp;
        
        // ucCapa
        ucTmp = psF->ucCapa;
        if(ucTmp > MT_CAPA_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucCapa is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucCapa = ucTmp;

        // ucVip
        ucTmp = psF->ucVip;
        if(ucTmp > MT_CAPA_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f3() ucVip is out range %d", ucTmp);
            #endif 
            return MT_ERR_OUTRNG;
        }

        psU->ucVip = ucTmp;

        // bigclass
        usTmp = psF->bBig;
        for(i = 0; i < 16; i++)
        {
            if(usTmp & (0x01 << i))
            {
               psU->bBig[i] = TRUE;
            }
        }

        // ucSmall
        for(i = 0; i < 16; i++)
        {
            ucTmp = psF->ucSmall[i];
            if(ucTmp > MT_USER_CLASS_MAX)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f3() ucSmall is out range %d", ucTmp);
                #endif 
                return MT_ERR_OUTRNG;
            }

            psU->ucSmall[i] = ucTmp;
        }
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(sMtAfn09F3_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f4_ast
 ��������  : F4���ն�֧�ֵĲ������� ��������
 �������  : eMtCmd eCmd      
             UINT8 *pArray    
             pucTeam ��������Ϣ�� 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtTrans_afn09f4
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f4_ast(eMtTrans eTrans, eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam)
{
    if(!pArray || !pucTeam)
    {
      return MT_ERR_NULL;
    }

    UINT8 ucN    = 0;
    UINT8 ucF    = 0;
    UINT8 ucSift = 0;
    
    switch(eCmd)
    {
        case CMD_AFN_4_F1_TML_UP_CFG:
        case CMD_AFN_4_F2_TML_WIRELESS_CFG:      
        case CMD_AFN_4_F3_MST_IP_PORT:
        case CMD_AFN_4_F4_MST_PHONE_SMS:    
        case CMD_AFN_4_F5_TML_UP_AUTH:
        case CMD_AFN_4_F6_TEAM_ADDR:    
        case CMD_AFN_4_F7_TML_IP_PORT:
        case CMD_AFN_4_F8_TML_UP_WAY:   
        case CMD_AFN_4_F9_TML_EVENT_CFG:
        case CMD_AFN_4_F10_TML_POWER_CFG:
        case CMD_AFN_4_F11_TML_PULSE_CFG:
        case CMD_AFN_4_F12_TML_STATE_INPUT:
        case CMD_AFN_4_F13_TML_SIMULA_CFG:
        case CMD_AFN_4_F14_TML_GRUP_TOTL:
        case CMD_AFN_4_F15_HAVE_DIFF_EVENT:
        case CMD_AFN_4_F16_VPN_USER_PWD:
        case CMD_AFN_4_F17_TML_SAFE_VALUE:    
        case CMD_AFN_4_F18_TML_PCTRL_PERD:
        case CMD_AFN_4_F19_TML_PCTRL_FACTOR:  
        case CMD_AFN_4_F20_TML_MONTH_FACTOR:
        case CMD_AFN_4_F21_TML_POWER_FACTOR:  
        case CMD_AFN_4_F22_TML_POWER_RATE:
        case CMD_AFN_4_F23_TML_WARNING_CFG:  
        case CMD_AFN_4_F25_MP_BASE_CFG:
        case CMD_AFN_4_F26_MP_LIMIT_CFG:
        case CMD_AFN_4_F27_MP_LOSS_CFG:
        case CMD_AFN_4_F28_MP_PERIOD_FACTOR:  
        case CMD_AFN_4_F29_TML_METER_ID:
        case CMD_AFN_4_F30_TML_AUTO_READ:
        case CMD_AFN_4_F31_SLAVE_ADDR:
        case CMD_AFN_4_F33_TML_READ_CFG:
        case CMD_AFN_4_F34_CON_DOWN_CFG:
        case CMD_AFN_4_F35_TML_READ_VIP:
        case CMD_AFN_4_F36_TML_UP_LIMIT:
        case CMD_AFN_4_F37_TML_CASC_CFG:
        case CMD_AFN_4_F38_CFG_ASK_1:
        case CMD_AFN_4_F39_CFG_ASK_2:
        case CMD_AFN_4_F41_PERIOD_VALUE:
        case CMD_AFN_4_F42_FACTORY_HOLIDAY:
        case CMD_AFN_4_F43_SLIDE_TIME:
        case CMD_AFN_4_F44_SHUTOUT_CFG:
        case CMD_AFN_4_F45_CTRL_TURN_CFG:
        case CMD_AFN_4_F46_MONTH_FIX_VALUE:
        case CMD_AFN_4_F47_BUY_COUNT:
        case CMD_AFN_4_F48_ELEC_TURN_CFG:
        case CMD_AFN_4_F49_WARNING_TIME:
        case CMD_AFN_4_F57_TML_WARN_SOUND:
        case CMD_AFN_4_F58_TML_ATUO_PROTECT:
        case CMD_AFN_4_F59_METER_LIMIT:
        case CMD_AFN_4_F60_HUMOR_LIMIT:
        case CMD_AFN_4_F61_DC_SIMULA:
        case CMD_AFN_4_F65_CFG_AUTO_1:
        case CMD_AFN_4_F66_CFG_AUTO_2:
        case CMD_AFN_4_F67_GOP_AUTO_1:
        case CMD_AFN_4_F68_GOP_AUTO_2:
        case CMD_AFN_4_F73_CAPA_CFG:
        case CMD_AFN_4_F74_CAPA_RUN_CFG:
        case CMD_AFN_4_F75_CAPA_PROT_PARA:
        case CMD_AFN_4_F76_CAPA_CTRL_WAY:
        case CMD_AFN_4_F81_CD_CHANGE_RATE:
        case CMD_AFN_4_F82_CD_LIMIT:
        case CMD_AFN_4_F83_CD_FREEZE_PARA:

        ucF = (UINT8)(eCmd & 0xFF);
        break;

        default:
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f4_ast() para cfg para is out range %X", eCmd);
        #endif 
        return MT_ERR_OUTRNG;
        //break;
    }

    if(MT_TRANS_U2F == eTrans)
    {
        ucSift       = (ucF - 1) % 8;
        ucN          = ucF / 8;
        *pucTeam     = ucN + 1;
        pArray[ucN] |=  (0x01 << ucSift);
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f4
 ��������  : F4���ն�֧�ֵĲ�������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : emtTrans_afn09f4_ast
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f4() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F4_f * psF    = (sMtAfn09F4_f*)psFrame;
    sMtAfn09F4*    psU    = (sMtAfn09F4*)psUser;
    eMtErr         eRet   = MT_OK;
    eMtCmd         eCmd   = CMD_AFN_F_UNKOWN;
    UINT8         *pFlag  = NULL;
    UINT8          ucN    = 0;
    UINT8          ucNTmp = 0;
    UINT8          ucFnN  = 0;
    UINT8          ucTmp  = 0;
    INT32          i      = 0;
    INT32          j      = 0;    
    
    if(MT_TRANS_U2F == eTrans)
    {      
        pFlag = (UINT8*)&(psF->ucFlag[0]);
        for(i = 0; i < psU->ucNum; i++)
        {
            eCmd = psU->eCfgCmd[i];
            eRet = emtTrans_afn09f4_ast(eTrans, eCmd, pFlag, &ucNTmp);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f4() emtTrans_afn09f4_ast() error %d", eRet);
                #endif 
                return eRet;
            }

            // ȡ�������ֵ
            ucN = (ucN > ucNTmp) ? ucN : ucNTmp;
        }
        
        psF->ucTeam = ucN;
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psF->ucTeam;
        
        for(i = 0; i < ucN; i++)
        {
            ucTmp = psF->ucFlag[i];

            for(j = 0; j < 8; j++)
            {
                if(ucTmp & (0x01 << j))
                {
                   eCmd = (eMtCmd)((8 * i + j + 1) | 0x0400);
                   eRet = emtTrans_afn09f4_ast(eTrans, eCmd, &ucNTmp, &ucNTmp);
                   if(MT_OK != eRet)
                   {
                       #ifdef MT_DBG
                       DEBUG("emtTrans_afn09f4() emtTrans_afn09f4_ast() error %d", eRet);
                       #endif 
                       return eRet;
                   }

                   psU->eCfgCmd[ucFnN++] = eCmd;
                }
            }
        }

       psU->ucNum =  ucFnN;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * (ucN + 1);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f5_ast
 ��������  : F5���ն�֧�ֵĿ������� ��������
 �������  : eMtCmd eCmd      
             UINT8 *pArray    
             pucTeam ��������Ϣ�� 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtTrans_afn09f5
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f5_ast(eMtTrans eTrans, eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam)
{
    if(!pArray || !pucTeam)
    {
      return MT_ERR_NULL;
    }

    UINT8 ucN    = 0;
    UINT8 ucF    = 0;
    UINT8 ucSift = 0;
    
    switch(eCmd)
    {
        case CMD_AFN_5_F1_REMOTE_TURN_OFF:
        case CMD_AFN_5_F2_PERMIT_TURN_ON:      
        case CMD_AFN_5_F9_PERIOD_GO:
        case CMD_AFN_5_F10_HOLIDAY_GO:    
        case CMD_AFN_5_F11_SHUTOUT_GO:
        case CMD_AFN_5_F12_DOWN_GO:    
        case CMD_AFN_5_F15_MONTH_GO:
        case CMD_AFN_5_F16_BUY_GO:   
        case CMD_AFN_5_F17_PERIOD_STOP:
        case CMD_AFN_5_F18_HOLIDAY_STOP:
        case CMD_AFN_5_F19_SHUTOUT_STOP:
        case CMD_AFN_5_F20_DOWN_STOP:
        case CMD_AFN_5_F23_MONTH_STOP:
        case CMD_AFN_5_F24_BUY_STOP:
        case CMD_AFN_5_F25_TML_PROTECT_GO:
        case CMD_AFN_5_F26_WARN_PAY_GO:
        case CMD_AFN_5_F27_PERMIT_TALK_GO:    
        case CMD_AFN_5_F28_TAKE_OFF_TML_GO:
        case CMD_AFN_5_F29_AUTO_SAY_GO:  
        case CMD_AFN_5_F31_CHECK_TIME:
        case CMD_AFN_5_F32_CHINESE_INFO:  
        case CMD_AFN_5_F33_TML_PROTECT_STOP:
        case CMD_AFN_5_F34_WARN_PAY_STOP:  
        case CMD_AFN_5_F35_PERMIT_TALK_STOP:
        case CMD_AFN_5_F36_TAKE_OFF_TML_STOP:
        case CMD_AFN_5_F37_AUTO_SAY_STOP:
        case CMD_AFN_5_F38_TML_LINK_ON:
        case CMD_AFN_5_F39_TML_LINK_OFF:  
        case CMD_AFN_5_F41_CAPA_CTRL_GO:
        case CMD_AFN_5_F42_CAPA_CTRL_STOP:
        case CMD_AFN_5_F49_READ_METER_STOP:
        case CMD_AFN_5_F50_READ_METER_GO:
        case CMD_AFN_5_F51_READ_METER_REDO:
        case CMD_AFN_5_F52_INIT_ROUTE:
        case CMD_AFN_5_F53_DELET_ALL_METER:

        ucF = (UINT8)(eCmd & 0xFF);
        break;

        default:
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f5_ast() para cfg para is out range %X", eCmd);
        #endif 
        return MT_ERR_OUTRNG;
        //break;
    }

    if(MT_TRANS_U2F == eTrans)
    {
        ucSift       = (ucF - 1) % 8;
        ucN          = ucF / 8;
        *pucTeam     = ucN + 1;
        pArray[ucN] |=  (0x01 << ucSift);
    }
    
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f5
 ��������  : F5���ն�֧�ֵĿ�������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : emtTrans_afn09f5_ast
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f5(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f5() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F5_f * psF    = (sMtAfn09F5_f*)psFrame;
    sMtAfn09F5*    psU    = (sMtAfn09F5*)psUser;
    eMtErr         eRet   = MT_OK;
    eMtCmd         eCmd   = CMD_AFN_F_UNKOWN;
    UINT8         *pFlag  = NULL;
    UINT8          ucN    = 0;
    UINT8          ucNTmp = 0;
    UINT8          ucFnN  = 0;
    UINT8          ucTmp  = 0;
    INT32          i      = 0;
    INT32          j      = 0;    
    
    if(MT_TRANS_U2F == eTrans)
    {      
        pFlag = (UINT8*)&(psF->ucFlag[0]);
        for(i = 0; i < psU->ucNum; i++)
        {
            eCmd = psU->eCfgCmd[i];
            eRet = emtTrans_afn09f5_ast(eTrans, eCmd, pFlag, &ucNTmp);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f5() emtTrans_afn09f5_ast() error %d", eRet);
                #endif 
                return eRet;
            }

            // ȡ�������ֵ
            ucN = (ucN > ucNTmp) ? ucN : ucNTmp;
        }

        psF->ucTeam = ucN;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        ucN = psF->ucTeam;
        
        for(i = 0; i < ucN; i++)
        {
            ucTmp = psF->ucFlag[i];

            for(j = 0; j < 8; j++)
            {
                if(ucTmp & (0x01 << j))
                {
                   eCmd = (eMtCmd)((8 * i + j + 1) | 0x0500);
                   printf("cmd = %X\n", eCmd);
                   eRet = emtTrans_afn09f5_ast(eTrans, eCmd, &ucNTmp, &ucNTmp);
                   if(MT_OK != eRet)
                   {
                       #ifdef MT_DBG
                       DEBUG("emtTrans_afn09f5() emtTrans_afn09f5_ast() error %d", eRet);
                       #endif 
                       return eRet;
                   }

                   psU->eCfgCmd[ucFnN++] = eCmd;
                }
            }
        }

       psU->ucNum =  ucFnN;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * (ucN + 1);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f6_ast
 ��������  : F6���ն�֧�ֵ�1���������� ��������
 �������  : eMtCmd eCmd      
             UINT8 *pArray    
             pucTeam ��������Ϣ�� 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtTrans_afn09f5
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f6_ast(eMtTrans eTrans, eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam)
{
    if(!pArray || !pucTeam)
    {
      return MT_ERR_NULL;
    }

    UINT8 ucN    = 0;
    UINT8 ucF    = 0;
    UINT8 ucSift = 0;
    
    switch(eCmd)
    {
        case CMD_AFN_C_F2_TML_CLOCK:
        case CMD_AFN_C_F3_TML_PARA_STATE:      
        case CMD_AFN_C_F4_TML_UPCOM_STATE:
        case CMD_AFN_C_F5_TML_CTRL_SET:    
        case CMD_AFN_C_F6_TML_CTRL_STATE:
        case CMD_AFN_C_F7_TML_EC_VALUE:    
        case CMD_AFN_C_F8_TML_EVNT_FLAG:
        case CMD_AFN_C_F9_TML_STATE_BIT:   
        case CMD_AFN_C_F10_TML_MONTH_FLOW:
        case CMD_AFN_C_F11_TML_READ_METER:
        case CMD_AFN_C_F17_TOTAL_POWER_HAVE:
        case CMD_AFN_C_F18_TOTAL_POWER_NONE:
        case CMD_AFN_C_F19_DAY_POWER_HAVE:
        case CMD_AFN_C_F20_DAY_POWER_NONE:
        case CMD_AFN_C_F21_MONTH_POWER_HAVE:
        case CMD_AFN_C_F22_MONTH_POWER_NONE:
        case CMD_AFN_C_F23_TML_LEFT_POWER:    
        case CMD_AFN_C_F24_DOWN_FREZ_VALUE:
        case CMD_AFN_C_F25_POWER_RATE_CUR:  
        case CMD_AFN_C_F26_DROP_PHASE_LAST:
        case CMD_AFN_C_F27_METER_PROG_TIME:  
        case CMD_AFN_C_F28_METER_WORD_CBIT:
        case CMD_AFN_C_F29_COPER_IRON_CUR:  
        case CMD_AFN_C_F30_COPER_IRON_LAST:
        case CMD_AFN_C_F31_POWER_CUR:
        case CMD_AFN_C_F32_POWER_LAST:
        case CMD_AFN_C_F33_FRTH_POWR_P1P4_C:  
        case CMD_AFN_C_F34_BACK_POWR_P2P3_C:
        case CMD_AFN_C_F35_FRTH_DMND_M:
        case CMD_AFN_C_F36_BACK_DMND_M:
        case CMD_AFN_C_F37_FRTH_POWR_P1P4_L:
        case CMD_AFN_C_F38_BACK_POWR_P2P3_L:
        case CMD_AFN_C_F39_FRTH_DMND_L:
        case CMD_AFN_C_F40_BACK_DMND_L:
        case CMD_AFN_C_F41_FRTH_HAVE_POWR_D:
        case CMD_AFN_C_F42_FRTH_NONE_POWR_D:
        case CMD_AFN_C_F43_BACK_HAVE_POWR_D:
        case CMD_AFN_C_F44_BACK_NONE_POWR_D:
        case CMD_AFN_C_F45_FRTH_HAVE_POWR_M:
        case CMD_AFN_C_F46_FRTH_NONE_POWR_M:
        case CMD_AFN_C_F47_BACK_HAVE_POWR_M:
        case CMD_AFN_C_F48_BACK_NONE_POWR_M:
        case CMD_AFN_C_F49_CURT_PHASE_ANGLE:
        case CMD_AFN_C_F57_CURT_HARM_VALUE:
        case CMD_AFN_C_F58_CURT_HARM_RATE:
        case CMD_AFN_C_F65_CURT_CAPA_SWITCH:
        case CMD_AFN_C_F66_CURT_CAPA_TIME:
        case CMD_AFN_C_F67_CURT_CAPA_POWR:
        case CMD_AFN_C_F73_DC_RLTM_DATA:
        case CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE:
        case CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE:
        case CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE:
        case CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE:
        case CMD_AFN_C_F89_HFRZ_RATE_HAVE:
        case CMD_AFN_C_F90_HFRZ_RATE_HAVE_A:
        case CMD_AFN_C_F91_HFRZ_RATE_HAVE_B:
        case CMD_AFN_C_F92_HFRZ_RATE_HAVE_C:
        case CMD_AFN_C_F93_HFRZ_RATE_NONE:
        case CMD_AFN_C_F94_HFRZ_RATE_NONE_A:
        case CMD_AFN_C_F95_HFRZ_RATE_NONE_B:
        case CMD_AFN_C_F96_HFRZ_RATE_NONE_C:
        case CMD_AFN_C_F97_HFRZ_VOLT_A:
        case CMD_AFN_C_F99_HFRZ_VOLT_C:
        case CMD_AFN_C_F100_HFRZ_ELEC_A:
        case CMD_AFN_C_F101_HFRZ_ELEC_B:
        case CMD_AFN_C_F102_HFRZ_ELEC_C:
        case CMD_AFN_C_F103_HFRZ_ELEC_ZERO:
        case CMD_AFN_C_F105_HFRZ_FRTH_HAVE:
        case CMD_AFN_C_F106_HFRZ_FRTH_NONE:
        case CMD_AFN_C_F107_HFRZ_BACK_HAVE:
        case CMD_AFN_C_F108_HFRZ_BACK_NONE:
        case CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S:
        case CMD_AFN_C_F110_HFRZ_FRTH_NONE_S:
        case CMD_AFN_C_F111_HFRZ_BACK_HAVE_S:
        case CMD_AFN_C_F112_HFRZ_BACK_NONE_S:
        case CMD_AFN_C_F113_HFRZ_FACT_TOTAL:
        case CMD_AFN_C_F114_HFRZ_FACT_A:
        case CMD_AFN_C_F115_HFRZ_FACT_B:
        case CMD_AFN_C_F116_HFRZ_FACT_C:
        case CMD_AFN_C_F121_HFRZ_DC_VALUE:
        case CMD_AFN_C_F129_FRTH_HAVE_POWR_C:
        case CMD_AFN_C_F130_FRTH_NONE_POWR_C:
        case CMD_AFN_C_F131_BACK_HAVE_POWR_C:
        case CMD_AFN_C_F132_BACK_NONE_POWR_C:
        case CMD_AFN_C_F133_NONE_POWR_P1_C:
        case CMD_AFN_C_F134_NONE_POWR_P2_C:
        case CMD_AFN_C_F135_NONE_POWR_P3_C:
        case CMD_AFN_C_F136_NONE_POWR_P4_C:
        case CMD_AFN_C_F137_FRTH_HAVE_POWR_L:
        case CMD_AFN_C_F138_FRTH_NONE_POWR_L:
        case CMD_AFN_C_F139_BACK_HAVE_POWR_L:
        case CMD_AFN_C_F140_BACK_NONE_POWR_L:
        case CMD_AFN_C_F141_NONE_POWR_P1_L:
        case CMD_AFN_C_F142_NONE_POWR_P2_L:
        case CMD_AFN_C_F143_NONE_POWR_P3_L:
        case CMD_AFN_C_F144_NONE_POWR_P4_L:
        case CMD_AFN_C_F145_FRTH_HAVE_DMND_C:
        case CMD_AFN_C_F146_FRTH_NONE_DMND_C:
        case CMD_AFN_C_F147_BACK_HAVE_DMND_C:
        case CMD_AFN_C_F148_BACK_NONE_DMND_C:
        case CMD_AFN_C_F149_FRTH_HAVE_DMND_L:
        case CMD_AFN_C_F150_FRTH_NONE_DMND_L:
        case CMD_AFN_C_F151_BACK_HAVE_DMND_L:
        case CMD_AFN_C_F152_BACK_NONE_DMND_L:
        case CMD_AFN_C_F153_FREZ_ZONE_1:
        case CMD_AFN_C_F154_FREZ_ZONE_2:
        case CMD_AFN_C_F155_FREZ_ZONE_3:
        case CMD_AFN_C_F156_FREZ_ZONE_4:
        case CMD_AFN_C_F157_FREZ_ZONE_5:
        case CMD_AFN_C_F158_FREZ_ZONE_6:
        case CMD_AFN_C_F159_FREZ_ZONE_7:
        case CMD_AFN_C_F160_FREZ_ZONE_8:
        case CMD_AFN_C_F161_METR_REMOTE_CTRL:
        case CMD_AFN_C_F165_METR_SWITCH_RECD:
        case CMD_AFN_C_F166_METR_MODIFY_RECD:
        case CMD_AFN_C_F167_METR_BUY_USE:
        case CMD_AFN_C_F168_METR_BALANCE:
        case CMD_AFN_C_F169_READ_ROUTE:
        case CMD_AFN_C_F170_READ_METER:

        ucF = (UINT8)(eCmd & 0xFF);
        break;

        default:
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f6_ast() para cfg para is out range %X", eCmd);
        #endif 
        return MT_ERR_OUTRNG;
        //break;
    }

    if(MT_TRANS_U2F == eTrans)
    {
        ucSift       = (ucF - 1) % 8;
        ucN          = ucF / 8 ;
        *pucTeam     = ucN + 1;
        pArray[ucN] |=  (0x01 << ucSift);
    }
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn09f6
 ��������  : F6���ն�֧�ֵ�1����������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : emtTrans_afn09f5_ast
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f6(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f6() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F6_f * psF    = (sMtAfn09F6_f*)psFrame;
    sMtAfn09F6*    psU    = (sMtAfn09F6*)psUser;
    eMtErr         eRet   = MT_OK;
    eMtCmd         eCmd   = CMD_AFN_F_UNKOWN;
    UINT8         *pFlag  = NULL;
    UINT8          ucN    = 0;
    UINT8          ucNTmp = 0;
    UINT8          ucFnN  = 0;
    UINT8          ucTmp  = 0;
    INT32          i      = 0;
    INT32          j      = 0;    
    
    if(MT_TRANS_U2F == eTrans)
    {        
        pFlag = (UINT8*)&(psF->ucFlag[0]);
        for(i = 0; i < psU->ucNum; i++)
        {
            eCmd = psU->eCfgCmd[i];
            eRet = emtTrans_afn09f6_ast(eTrans, eCmd, pFlag, &ucNTmp);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f6() emtTrans_afn09f6_ast() error %d", eRet);
                #endif 
                return eRet;
            }

            // ȡ�������ֵ
            ucN = (ucN > ucNTmp) ? ucN : ucNTmp;
        }

        psF->ucTeam     = ucN;
        psF->ucBigClass = AFN_0C_ASK1;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        if(AFN_0C_ASK1 != psF->ucBigClass)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f6() ucBigClass() error %d", psF->ucBigClass);
            #endif 
            return MT_ERR_AFN;
        }
        
        ucN = psF->ucTeam;
        
        for(i = 0; i < ucN; i++)
        {
            ucTmp = psF->ucFlag[i];

            for(j = 0; j < 8; j++)
            {
                if(ucTmp & (0x01 << j))
                {
                   eCmd = (eMtCmd)((8 * i + j + 1) | 0x0C00);
                   eRet = emtTrans_afn09f6_ast(eTrans, eCmd, &ucNTmp, &ucNTmp);
                   if(MT_OK != eRet)
                   {
                       #ifdef MT_DBG
                       DEBUG("emtTrans_afn09f6() emtTrans_afn09f6_ast() error %d", eRet);
                       #endif 
                       return eRet;
                   }

                   psU->eCfgCmd[ucFnN++] = eCmd;
                }
            }
        }

       psU->ucNum =  ucFnN;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * (ucN + 2);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f7_ast
 ��������  : F7���ն�֧�ֵ�2���������� ��������
 �������  : eMtCmd eCmd      
             UINT8 *pArray    
             pucTeam ��������Ϣ�� 
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtTrans_afn09f5
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f7_ast(eMtTrans eTrans, eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam)
{
    if(!pArray || !pucTeam)
    {
      return MT_ERR_NULL;
    }

    UINT8 ucN    = 0;
    UINT8 ucF    = 0;
    UINT8 ucSift = 0;
    
    switch(eCmd)
    {
        case CMD_AFN_D_F1_FRTH_POWR_P1P4_D:
        case CMD_AFN_D_F2_BACK_POWR_P2P3_D:
        case CMD_AFN_D_F3_FRTH_DMND_TIME_D:
        case CMD_AFN_D_F4_BACK_DMND_TIME_D:
        case CMD_AFN_D_F5_FRTH_HAVE_POWR_D:
        case CMD_AFN_D_F6_FRTH_NONE_POWR_D:
        case CMD_AFN_D_F7_BACK_HAVE_POWR_D:
        case CMD_AFN_D_F8_BACK_NONE_POWR_D:
        case CMD_AFN_D_F9_FRTH_POWR_P1P4_R:
        case CMD_AFN_D_F10_BACK_POWR_P2P3_R:  
        case CMD_AFN_D_F11_FRTH_DMND_TIME_R:   
        case CMD_AFN_D_F12_BACK_DMND_TIME_R:
        case CMD_AFN_D_F17_FRTH_POWR_P1P4_M:   
        case CMD_AFN_D_F18_BACK_POWR_P2P3_M:
        case CMD_AFN_D_F19_FRTH_DMND_TIME_M:
        case CMD_AFN_D_F20_BACK_DMND_TIME_M:
        case CMD_AFN_D_F21_FRTH_HAVE_POWR_M:
        case CMD_AFN_D_F22_FRTH_NONE_POWR_M:
        case CMD_AFN_D_F23_BACK_HAVE_POWR_M:
        case CMD_AFN_D_F24_BACK_NONE_POWR_M:              
        case CMD_AFN_D_F25_POWR_FRZE_D:  
        case CMD_AFN_D_F26_DMND_FRZE_D:  
        case CMD_AFN_D_F27_VOLT_FRZE_D:  
        case CMD_AFN_D_F28_UBLN_OVER_D: 
        case CMD_AFN_D_F29_ELEC_OVER_D:  
        case CMD_AFN_D_F30_POWR_RATE_D:  
        case CMD_AFN_D_F31_LOAD_RATE_D:  
        case CMD_AFN_D_F32_METR_DROP_D:  
        case CMD_AFN_D_F33_POWR_FRZE_M: 
        case CMD_AFN_D_F34_DMND_FRZE_M:  
        case CMD_AFN_D_F35_VOLT_FRZE_M:  
        case CMD_AFN_D_F36_UBLN_OVER_M:  
        case CMD_AFN_D_F37_ELEC_OVER_M: 
        case CMD_AFN_D_F38_POWR_RATE_M:  
        case CMD_AFN_D_F39_LOAD_RATE_M:  
        case CMD_AFN_D_F41_CAPA_TIME_D:  
        case CMD_AFN_D_F42_CAPA_NONE_D: 
        case CMD_AFN_D_F43_FACT_TIME_D: 
        case CMD_AFN_D_F44_FACT_TIME_M:  
        case CMD_AFN_D_F45_COPR_IRON_D:  
        case CMD_AFN_D_F46_COPR_IRON_M:  
        case CMD_AFN_D_F49_TML_ONOF_D:  
        case CMD_AFN_D_F50_TML_CTRL_D: 
        case CMD_AFN_D_F51_TML_ONOF_M:  
        case CMD_AFN_D_F52_TML_CTRL_M:  
        case CMD_AFN_D_F53_TML_FLOW_D:  
        case CMD_AFN_D_F54_TML_FLOW_M:  
        case CMD_AFN_D_F57_GRUP_RATE_D: 
        case CMD_AFN_D_F58_GRUP_HAVE_D:  
        case CMD_AFN_D_F59_GRUP_NONE_D:
        case CMD_AFN_D_F60_GRUP_RATE_M: 
        case CMD_AFN_D_F61_GRUP_HAVE_M:  
        case CMD_AFN_D_F62_GRUP_NONE_M:  
        case CMD_AFN_D_F65_GRUP_RATE_OVER: 
        case CMD_AFN_D_F66_GRUP_POWR_OVER: 
        case CMD_AFN_D_F73_CURVE_RATE_HAVE:  
        case CMD_AFN_D_F74_CURVE_RATE_NONE:  
        case CMD_AFN_D_F75_CURVE_POWR_HAVE:  
        case CMD_AFN_D_F76_CURVE_POWR_NONE:  
        case CMD_AFN_D_F81_CURVE_HAVE: 
        case CMD_AFN_D_F82_CURVE_HAVE_A:  
        case CMD_AFN_D_F83_CURVE_HAVE_B:  
        case CMD_AFN_D_F84_CURVE_HAVE_C:  
        case CMD_AFN_D_F85_CURVE_NONE: 
        case CMD_AFN_D_F86_CURVE_NONE_A:
        case CMD_AFN_D_F87_CURVE_NONE_B: 
        case CMD_AFN_D_F88_CURVE_NONE_C:
        case CMD_AFN_D_F89_CURVE_VOLT_A: 
        case CMD_AFN_D_F90_CURVE_VOLT_B:
        case CMD_AFN_D_F91_CURVE_VOLT_C:  
        case CMD_AFN_D_F92_CURVE_ELEC_A: 
        case CMD_AFN_D_F93_CURVE_ELEC_B:
        case CMD_AFN_D_F94_CURVE_ELEC_C:  
        case CMD_AFN_D_F95_CURVE_ZERO_E:  
        case CMD_AFN_D_F97_CURVE_FRTH_HAVE:  
        case CMD_AFN_D_F98_CURVE_FRTH_NONE:  
        case CMD_AFN_D_F98_CURVE_BACK_HAVE: 
        case CMD_AFN_D_F100_CURVE_BACK_HAVE: 
        case CMD_AFN_D_F101_CURVE_FRTH_HAVE: 
        case CMD_AFN_D_F102_CURVE_FRTH_NONE: 
        case CMD_AFN_D_F103_CURVE_BACK_HAVE:  
        case CMD_AFN_D_F104_CURVE_BACK_NONE:
        case CMD_AFN_D_F105_CURVE_FACTOR_T:
        case CMD_AFN_D_F106_CURVE_FACTOR_A:
        case CMD_AFN_D_F107_CURVE_FACTOR_B:
        case CMD_AFN_D_F108_CURVE_FACTOR_C:
        case CMD_AFN_D_F109_ANGLE_CURVE_VOLT: 
        case CMD_AFN_D_F110_ANGLE_CURVE_ELEC:
        case CMD_AFN_D_F113_ELEC_HARM_TIME_A:
        case CMD_AFN_D_F114_ELEC_HARM_TIME_B:
        case CMD_AFN_D_F115_ELEC_HARM_TIME_C: 
        case CMD_AFN_D_F116_VOLT_HARM_TIME_A:
        case CMD_AFN_D_F117_VOLT_HARM_TIME_B: 
        case CMD_AFN_D_F118_VOLT_HARM_TIME_C:
        case CMD_AFN_D_F121_HARM_OVER_A:
        case CMD_AFN_D_F122_HARM_OVER_B:  
        case CMD_AFN_D_F123_HARM_OVER_C:  
        case CMD_AFN_D_F129_DC_D: 
        case CMD_AFN_D_F130_DC_M:
        case CMD_AFN_D_F138_DC_CURVE:  
        case CMD_AFN_D_F145_CURVE_PHASE_1:  
        case CMD_AFN_D_F146_CURVE_PHASE_4: 
        case CMD_AFN_D_F147_CURVE_PHASE_2:  
        case CMD_AFN_D_F148_CURVE_PHASE_3:  
        case CMD_AFN_D_F153_FRTH_HAVE_D:  
        case CMD_AFN_D_F154_FRTH_NONE_D:  
        case CMD_AFN_D_F155_BACK_HAVE_D:  
        case CMD_AFN_D_F156_BACK_NONE_D:  
        case CMD_AFN_D_F157_FRTH_HAVE_M:  
        case CMD_AFN_D_F158_FRTH_NONE_M:  
        case CMD_AFN_D_F159_BACK_HAVE_M:     
        case CMD_AFN_D_F160_BACK_NONE_M:  
        case CMD_AFN_D_F161_HAVE_FRTH_D:  
        case CMD_AFN_D_F162_NONE_FRTM_D:  
        case CMD_AFN_D_F163_HAVE_BACK_D:  
        case CMD_AFN_D_F164_NONE_BACK_D:  
        case CMD_AFN_D_F165_NONE_D_PHASE_1: 
        case CMD_AFN_D_F166_NONE_D_PHASE_2:  
        case CMD_AFN_D_F167_NONE_D_PHASE_3:  
        case CMD_AFN_D_F168_NONE_D_PHASE_4: 
        case CMD_AFN_D_F169_HAVE_FRTH_R:  
        case CMD_AFN_D_F170_NONE_FRTM_R:  
        case CMD_AFN_D_F171_HAVE_BACK_R:  
        case CMD_AFN_D_F172_NONE_BACK_R: 
        case CMD_AFN_D_F173_NONE_R_PHASE_1:  
        case CMD_AFN_D_F174_NONE_R_PHASE_2:  
        case CMD_AFN_D_F175_NONE_R_PHASE_3:  
        case CMD_AFN_D_F176_NONE_R_PHASE_4: 
        case CMD_AFN_D_F177_HAVE_FRTH_M:  
        case CMD_AFN_D_F178_NONE_FRTM_M:  
        case CMD_AFN_D_F179_HAVE_BACK_M:  
        case CMD_AFN_D_F180_NONE_BACK_M:  
        case CMD_AFN_D_F181_NONE_M_PHASE_1: 
        case CMD_AFN_D_F182_NONE_M_PHASE_2:  
        case CMD_AFN_D_F183_NONE_M_PHASE_3:
        case CMD_AFN_D_F184_NONE_M_PHASE_4:
        case CMD_AFN_D_F185_HAVE_DMND_FRTH_D:
        case CMD_AFN_D_F186_NONE_DMND_FRTH_D:
        case CMD_AFN_D_F187_HAVE_DMND_BACK_D:
        case CMD_AFN_D_F188_NONE_DMND_BACK_D:
        case CMD_AFN_D_F189_HAVE_DMND_FRTH_R:
        case CMD_AFN_D_F190_NONE_DMND_FRTH_R:
        case CMD_AFN_D_F191_HAVE_DMND_BACK_R:
        case CMD_AFN_D_F192_NONE_DMND_BACK_R:
        case CMD_AFN_D_F193_HAVE_DMND_FRTH_M:
        case CMD_AFN_D_F194_NONE_DMND_FRTH_M:
        case CMD_AFN_D_F195_HAVE_DMND_BACK_M: 
        case CMD_AFN_D_F196_NONE_DMND_BACK_M:  
        case CMD_AFN_D_F201_FREZ_ZONE_1:  
        case CMD_AFN_D_F202_FREZ_ZONE_2:  
        case CMD_AFN_D_F203_FREZ_ZONE_3: 
        case CMD_AFN_D_F204_FREZ_ZONE_4:  
        case CMD_AFN_D_F205_FREZ_ZONE_5:  
        case CMD_AFN_D_F206_FREZ_ZONE_6: 
        case CMD_AFN_D_F207_FREZ_ZONE_7:
        case CMD_AFN_D_F208_FREZ_ZONE_8:
        case CMD_AFN_D_F209_METR_REMOTE_INFO: 
        case CMD_AFN_D_F213_METR_SWITCH_INFO:
        case CMD_AFN_D_F214_METR_MODIFY_INFO:
        case CMD_AFN_D_F215_METR_BUY_USR:
        case CMD_AFN_D_F216_METR_BALANCE:  
        case CMD_AFN_D_F217_WHITE_YAWP_CURVE:
        case CMD_AFN_D_F218_COLOR_YAWP_CURVE:

        ucF = (UINT8)(eCmd & 0xFF);
        break;

        default:
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f7_ast() para cfg para is out range %X", eCmd);
        #endif 
        return MT_ERR_OUTRNG;
        //break;
    }

    if(MT_TRANS_U2F == eTrans)
    {
        ucSift       = (ucF - 1) % 8;
        ucN          = ucF / 8 ;
        *pucTeam     = ucN + 1;
        pArray[ucN] |=  (0x01 << ucSift);
    }
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f7
 ��������  : F7���ն�֧�ֵ�2����������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : eMtErr
 ���ú���  : emtTrans_afn09f5_ast
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f7(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f7() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F7_f * psF    = (sMtAfn09F7_f*)psFrame;
    sMtAfn09F7*    psU    = (sMtAfn09F7*)psUser;
    eMtErr         eRet   = MT_OK;
    eMtCmd         eCmd   = CMD_AFN_F_UNKOWN;
    UINT8         *pFlag  = NULL;
    UINT8          ucN    = 0;
    UINT8          ucNTmp = 0;
    UINT8          ucFnN  = 0;
    UINT8          ucTmp  = 0;
    INT32          i      = 0;
    INT32          j      = 0;    
    
    if(MT_TRANS_U2F == eTrans)
    {        
        pFlag = (UINT8*)&(psF->ucFlag[0]);
        for(i = 0; i < psU->ucNum; i++)
        {
            eCmd = psU->eCfgCmd[i];
            eRet = emtTrans_afn09f7_ast(eTrans, eCmd, pFlag, &ucNTmp);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f7() emtTrans_afn09f7_ast() error %d", eRet);
                #endif 
                return eRet;
            }

            // ȡ�������ֵ
            ucN = (ucN > ucNTmp) ? ucN : ucNTmp;
        }

        psF->ucTeam     = ucN;
        psF->ucBigClass = AFN_0D_ASK2;

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        if(AFN_0D_ASK2 != psF->ucBigClass)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn09f7() ucBigClass() error %d", psF->ucBigClass);
            #endif 
            return MT_ERR_AFN;
        }
        
        ucN = psF->ucTeam;
        
        for(i = 0; i < ucN; i++)
        {
            ucTmp = psF->ucFlag[i];

            for(j = 0; j < 8; j++)
            {
                if(ucTmp & (0x01 << j))
                {
                   eCmd = (eMtCmd)((8 * i + j) | 0x0D00);
                   eRet = emtTrans_afn09f7_ast(eTrans, eCmd, &ucNTmp, &ucNTmp);
                   if(MT_OK != eRet)
                   {
                       #ifdef MT_DBG
                       DEBUG("emtTrans_afn09f7() emtTrans_afn09f7_ast() error %d", eRet);
                       #endif 
                       return eRet;
                   }
				   
                   psU->eCfgCmd[ucFnN++] = eCmd;
                }
            }
        }

       psU->ucNum =  ucFnN;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * (ucN + 2);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn09f8
 ��������  : F8���ն�֧�ֵ��¼���¼����
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��27�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn09f8(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn09f8() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn09F8_f * psF    = (sMtAfn09F8_f*)psFrame;
    sMtAfn09F8*    psU    = (sMtAfn09F8*)psUser;
    eMtErc         eErc   = MT_ERC_UNKOWN;
    UINT8          ucN    = 0;
    UINT8          ucTmp  = 0;
    INT32          i      = 0;
    INT32          j      = 0;    
    UINT8          ucSift = 0;
    
    if(MT_TRANS_U2F == eTrans)
    {
        // ��ʼ��
        for(i = 0; i < 8; i++)
        {
            psF->ucFlag[i] = 0;
        }
        
        ucN = psU->ucNum;
        for(i = 0; i < ucN; i++)
        {
            eErc = psU->eErc[i];
            if(eErc > MT_ERC_35_UNKOWN || eErc < MT_ERC_UNKOWN)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn09f8() eErc out of range %d", eErc);
                #endif 
                return MT_ERR_OUTRNG;
            }
            
            ucTmp  = (UINT8)eErc;
            j      = ucTmp / 8;  
            ucSift = ucTmp % 8;
            psF->ucFlag[j] |= (0x01 << ucSift);
        }

    }
    else if(MT_TRANS_F2U == eTrans)
    {
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                if(psF->ucFlag[i] & (0x01 << j))
                {
                    eErc = (eMtErc)(i * 8 + j + 1);
                    if(eErc > MT_ERC_35_UNKOWN || eErc < MT_ERC_UNKOWN)
                    {
                        #ifdef MT_DBG
                        DEBUG("emtTrans_afn09f8() eErc out of range %d", eErc);
                        #endif 
                        return MT_ERR_OUTRNG;
                    }
					
                    psU->eErc[ucN++] = eErc;
                    
                }
            }
        }

        psU->ucNum = ucN;
    }
    else
    {
        return MT_ERR_PARA;
    }

    *pusfLen = sizeof(UINT8) * (ucN + 2);
    return MT_OK;
}   

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf02
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F02���ն�����ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf02(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet = emt_trans_YYWWMMDDhhmmss(eTrans, (sMtUserClock *)psUser,(sMtFrmClock *)psFrame);

    *pusfLen = sizeof(sMtFrmClock);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf03
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F03���ն˲���״̬
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf03(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf03() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    sMtAfn0cF03     *psAfn0cF03   = (sMtAfn0cF03*)psUser;
    sMtAfn0cF03_f   *psAfn0cF03_f = (sMtAfn0cF03_f*)psFrame;
    INT32       i,j;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        for ( i = 0; i < MT_TERMINAL_STATUS_FRM_MAX; i++)
        {
            for (j = 0; j < 8; j++)
            {
                psAfn0cF03->bParaStatus[i * 8 + j] = (BOOL)((psAfn0cF03_f->bParaStatus[i] >> j) & 0x01);
            }
        }
    }
    else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        memset(psAfn0cF03_f,0,sizeof(sMtAfn0cF03_f));
        for (i = 0; i < MT_TERMINAL_STATUS_USER_MAX; )
        {
            for ( j = 0; j < 8; j++,i++)
            {
                psAfn0cF03_f->bParaStatus[i / 8] |= (psAfn0cF03->bParaStatus[i] << j);
            }
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf03() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF03_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf04
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F04���ն�����ͨ��״̬
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf04(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf04() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cF04     *psAfn0cF04   = (sMtAfn0cF04*)psUser;
    sMtAfn0cF04_f   *psAfn0cF04_f = (sMtAfn0cF04_f*)psFrame;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        psAfn0cF04->bCom = (psAfn0cF04_f->ucComStat >> 1) ^ (psAfn0cF04_f->ucComStat);
        psAfn0cF04->bUp  = (psAfn0cF04_f->ucUpStat >> 1) ^ (psAfn0cF04_f->ucUpStat);
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        psAfn0cF04_f->ucComStat = ( psAfn0cF04->bCom == TRUE) ? MT_AFN0CF04_ENABLE : MT_AFN0CF04_DISABLE;
        psAfn0cF04_f->ucUpStat  = ( psAfn0cF04->bUp == TRUE) ? MT_AFN0CF04_ENABLE : MT_AFN0CF04_DISABLE;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf04() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF04_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf05
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F05���ն�ͨ��״̬
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf05(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf05() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    sMtAfn0cF05     *psAfn0cF05   = (sMtAfn0cF05*)psUser;
    sMtAfn0cF05_f   *psAfn0cF05_f = (sMtAfn0cF05_f*)psFrame;
    UINT8   n = 0;
    INT32 i,j,k;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        n = emtGetGroupNum(psAfn0cF05_f->ucGroupFlag);
        psAfn0cF05->bRemain = (psAfn0cF05_f->ucWarnSta & MT_AFN0CF05_REMAIN_ENABLE) ? TRUE : FALSE;
        psAfn0cF05->bDelete = (psAfn0cF05_f->ucWarnSta & MT_AFN0CF05_DELETE_ENABLE) ? TRUE : FALSE;
        psAfn0cF05->bPayWarn = (psAfn0cF05_f->ucWarnSta & MT_AFN0CF05_PAYWAR_ENABLE) ? TRUE : FALSE;
        psAfn0cF05->ucGroupNum = n;

        // ������Ч�ܼ���
        for ( i = 0; i < MT_AFN0CF05_MAXGROUPS;i++)
        {
            psAfn0cF05->bGroup[i] = ((1 << i) & psAfn0cF05_f->ucGroupFlag) ? TRUE : FALSE;
        }

        for ( i = 0,j = 0; i < MT_AFN0CF05_MAXGROUPS;i++)
        {
            if( psAfn0cF05->bGroup[i])
            {
                psAfn0cF05->sGroup[i].ucScheme = psAfn0cF05_f->sGroup[j].ucPowerNum;

                // ���㹦��ʱ����Ч��־
                for ( k = 0; k < 8;k++)
                {
                    psAfn0cF05->sGroup[i].bPowerCtrl[k]  = 
                        ((1 << k) & psAfn0cF05_f->sGroup[j].ucPowerFlag) ? TRUE : FALSE;
                }

                // ���㹦��״̬
                psAfn0cF05->sGroup[i].bTimeCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucPowerSta & MT_AFN0CF05_TIME_CTRL_ENABLE) ? TRUE : FALSE;

                psAfn0cF05->sGroup[i].bRestCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucPowerSta & MT_AFN0CF05_REST_CTRL_ENABLE) ? TRUE : FALSE;

                psAfn0cF05->sGroup[i].bStopCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucPowerSta & MT_AFN0CF05_STOP_CTRL_ENABLE) ? TRUE : FALSE;

                psAfn0cF05->sGroup[i].bDownCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucPowerSta & MT_AFN0CF05_DOWN_CTRL_ENABLE) ? TRUE : FALSE;

                // ������״̬
                psAfn0cF05->sGroup[i].bMonthCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucElecSta & MT_AFN0CF05_MONTH_CTRL_ENABLE) ? TRUE : FALSE;

                psAfn0cF05->sGroup[i].bBuyCtrl = \
                    (psAfn0cF05_f->sGroup[j].ucElecSta & MT_AFN0CF05_BUY_CTRL_ENABLE) ? TRUE : FALSE;

                // ���㹦���ִ�״̬
                for ( k = 0; k < 8;k++)
                {
                    psAfn0cF05->sGroup[i].bPowerTimeSta[k] = \
                        ( (1 << k) & psAfn0cF05_f->sGroup[j].ucPowerTimeSta) ? TRUE : FALSE;
                }

                // �������ִ�״̬
                for ( k = 0; k < 8;k++)
                {
                    psAfn0cF05->sGroup[i].bElecTimeSta[k] = \
                        ( (1 << k) & psAfn0cF05_f->sGroup[j].ucElecTimeSta) ? TRUE : FALSE;
                }
                j++;
            }
        } 
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ���㱣�硢�޳����߷Ѹ澯Ͷ��״̬
        if( psAfn0cF05->bRemain == TRUE)
        {
            psAfn0cF05_f->ucWarnSta |= MT_AFN0CF05_REMAIN_ENABLE;
        }

        if( psAfn0cF05->bDelete == TRUE)
        {
            psAfn0cF05_f->ucWarnSta |= MT_AFN0CF05_DELETE_ENABLE;
        }

        if( psAfn0cF05->bPayWarn == TRUE)
        {
            psAfn0cF05_f->ucWarnSta |= MT_AFN0CF05_PAYWAR_ENABLE;
        }

        // �����ܼ�����Ч��־λ���ܼ���״̬
        for ( i = 0,j = 0; i < MT_AFN0CF05_MAXGROUPS;i++)
        {
            if (psAfn0cF05->bGroup[i] == TRUE)
            {
                psAfn0cF05_f->ucGroupFlag |= (1 << i);
                // ���ض�ֵ������
                psAfn0cF05_f->sGroup[j].ucPowerNum = psAfn0cF05->sGroup[i].ucScheme;
                
                // ����ʱ����Ч��־λ
                for ( k = 0; k < 8; k++ )
                {
                    if(psAfn0cF05->sGroup[i].bPowerCtrl[k] == TRUE)
                    {
                        psAfn0cF05_f->sGroup[j].ucPowerFlag |= (1 << k);
                    }
                }

                // ����״̬
                if ( psAfn0cF05->sGroup[i].bTimeCtrl == TRUE)
                {
                    psAfn0cF05_f->sGroup[j].ucPowerSta |= MT_AFN0CF05_TIME_CTRL_ENABLE;
                }

                if ( psAfn0cF05->sGroup[i].bRestCtrl == TRUE)
                {
                    psAfn0cF05_f->sGroup[j].ucPowerSta |= MT_AFN0CF05_REST_CTRL_ENABLE;
                }

                if ( psAfn0cF05->sGroup[i].bStopCtrl == TRUE)
                {
                    psAfn0cF05_f->sGroup[j].ucPowerSta |= MT_AFN0CF05_STOP_CTRL_ENABLE;
                }

                if ( psAfn0cF05->sGroup[i].bDownCtrl == TRUE)
                {
                    psAfn0cF05_f->sGroup[j].ucPowerSta |= MT_AFN0CF05_DOWN_CTRL_ENABLE;
                }

                 // ���״̬
                if ( psAfn0cF05->sGroup[i].bMonthCtrl == TRUE )
                {
                    psAfn0cF05_f->sGroup[j].ucElecSta |= MT_AFN0CF05_MONTH_CTRL_ENABLE;
                }

                if ( psAfn0cF05->sGroup[i].bBuyCtrl == TRUE )
                {
                    psAfn0cF05_f->sGroup[j].ucElecSta |= MT_AFN0CF05_BUY_CTRL_ENABLE;
                }

                // �����ִ�״̬
                for ( k=0; k < 8; k++ )
                {
                    if (psAfn0cF05->sGroup[i].bPowerTimeSta[k] == TRUE )
                    {
                        psAfn0cF05_f->sGroup[j].ucPowerTimeSta |= (1 << k);
                    }
                }

                // ����ִ�״̬
                for ( k=0; k < 8; k++ )
                {
                    if (psAfn0cF05->sGroup[i].bElecTimeSta[k] == TRUE )
                    {
                        psAfn0cF05_f->sGroup[j].ucElecTimeSta |= (1 << k);
                    }
                }
                j++;
            }

        }
        n = j;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf05() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF05_f) + n * sizeof(sMtComGroupSta_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf06
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F06���ն˿���״̬
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf06(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf06() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cF06     *psAfn0cF06   = (sMtAfn0cF06*)psUser;
    sMtAfn0cF06_f   *psAfn0cF06_f = (sMtAfn0cF06_f*)psFrame;
    UINT8     n = 0;
    INT32     i,j,k;
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ����ң����բ���״̬
        n = emtGetGroupNum(psAfn0cF06_f->ucGroupFlag);
        for ( i = 0; i < 8; i++)
        {
            psAfn0cF06->bTrip[i] = ((1 << i) & psAfn0cF06_f->ucTripOutSta) ? TRUE : FALSE;
        }

        psAfn0cF06->ucPayWarn = psAfn0cF06_f->ucPayWarnSta;
        j = 0;
        for ( i = 0; i < 8; i++)
        {
            psAfn0cF06->bGroup[i] = (( 1 << i) & psAfn0cF06_f->ucGroupFlag) ? TRUE : FALSE;

            // �ܼ�����Ч
            if ( psAfn0cF06->bGroup[i] )
            {
                // ���㵱ǰ���ʶ�ֵ
                emt_trans_sXXX(eTrans,&(psAfn0cF06->sGroup[i].fCurPower)
                                ,&(psAfn0cF06_f->sGroup[j].sCurPower));

                // ���㵱ǰ�����¸��ظ�����ϵ��
                emt_trans_sXX(eTrans, &(psAfn0cF06->sGroup[i].sPowerDrift)
                    ,&(psAfn0cF06_f->sGroup[j].sPowerDrift));

                // ������բ���״̬
                for ( k = 0; k < 8; k++)
                {
                     psAfn0cF06->sGroup[i].bPowerOutSta[k] = 
                        ((1 << k) & psAfn0cF06_f->sGroup[j].ucPowerOutSta) ? TRUE : FALSE;
                }

                // �µ����բ���״̬
                for ( k = 0; k < 8; k++)
                {
                     psAfn0cF06->sGroup[i].bMonthElecOutSta[k] = 
                        ((1 << k) & psAfn0cF06_f->sGroup[j].ucMonthElecOutSta) ? TRUE : FALSE;
                }

                // �������բ���״̬
                for ( k = 0; k < 8; k++)
                {
                     psAfn0cF06->sGroup[i].bBuyElecOutSta[k] = 
                        ((1 << k) & psAfn0cF06_f->sGroup[j].ucBuyElecOutSta) ? TRUE : FALSE;
                }

                // ��ȡʱ�ο�״̬
                psAfn0cF06->sGroup[i].bTimeCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucPowerWarnSta & MT_AFN0CF06_TIME_CTRL_STAT) ? TRUE : FALSE;

                // ��ȡ���ݿ�״̬
                psAfn0cF06->sGroup[i].bRestCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucPowerWarnSta & MT_AFN0CF06_REST_CTRL_STAT) ? TRUE : FALSE;

                // ��ȡӪҵ��ͣ��״̬
                psAfn0cF06->sGroup[i].bStopCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucPowerWarnSta & MT_AFN0CF06_STOP_CTRL_STAT) ? TRUE : FALSE;

                // ��ȡ��ǰ�����¸���״̬
                psAfn0cF06->sGroup[i].bDownCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucPowerWarnSta & MT_AFN0CF06_DOWN_CTRL_STAT) ? TRUE : FALSE;

                // ��ȡ�µ��״̬
                psAfn0cF06->sGroup[i].bMonthCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucElecWarnSta & MT_AFN0CF06_MONTH_CTRL_STAT) ? TRUE : FALSE;

                 // ��ȡ�����״̬
                psAfn0cF06->sGroup[i].bBuyCtrlSta = \
                    (psAfn0cF06_f->sGroup[j].ucElecWarnSta & MT_AFN0CF06_BUY_CTRL_STAT) ? TRUE : FALSE;

                j++;
            }
        }
         
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ����ң����բ���״̬
        for(i = 0; i < 8; i++)
        {
            if ( psAfn0cF06->bTrip[i] )
            {
                psAfn0cF06_f->ucTripOutSta |= (1 << i);
            }
        }

        // ���õ�ǰ�߷Ѹ澯״̬
        psAfn0cF06_f->ucPayWarnSta = psAfn0cF06->ucPayWarn;
        j = 0;
        for ( i = 0; i < 8 ;i++ )
        {
            if ( psAfn0cF06->bGroup[i] )
            {
                // �ܼ���״̬
                psAfn0cF06_f->ucGroupFlag |= (1 << i);
                 // ���õ�ǰ���ʶ�ֵ
                emt_trans_sXXX(eTrans,&(psAfn0cF06->sGroup[i].fCurPower)
                                ,&(psAfn0cF06_f->sGroup[j].sCurPower));

                // ���õ�ǰ�����¸��ظ�����ϵ��
                emt_trans_sXX(eTrans, &(psAfn0cF06->sGroup[i].sPowerDrift)
                    ,&(psAfn0cF06_f->sGroup[j].sPowerDrift));

                // ���ù�����բ���״̬
                for ( k = 0; k < 8 ; k++)
                {
                    if ( psAfn0cF06->sGroup[i].bPowerOutSta[k] )
                    {
                        psAfn0cF06_f->sGroup[j].ucPowerOutSta |= (1 << k);
                    }
                }

                // �����µ����բ���״̬
                for ( k = 0; k < 8 ; k++)
                {
                    if ( psAfn0cF06->sGroup[i].bMonthElecOutSta[k] )
                    {
                        psAfn0cF06_f->sGroup[j].ucMonthElecOutSta |= (1 << k);
                    }
                }

                // ���ù������բ���״̬
                for ( k = 0; k < 8 ; k++)
                {
                    if ( psAfn0cF06->sGroup[i].bBuyElecOutSta[k] )
                    {
                        psAfn0cF06_f->sGroup[j].ucBuyElecOutSta |= (1 << k);
                    }
                }

                // ʱ�ο�״̬
                if ( psAfn0cF06->sGroup[i].bTimeCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucPowerWarnSta |= MT_AFN0CF06_TIME_CTRL_STAT;
                }

                // ���ݿ�״̬
                if ( psAfn0cF06->sGroup[i].bRestCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucPowerWarnSta |= MT_AFN0CF06_REST_CTRL_STAT;
                }

                // Ӫҵ��ͣ״̬
                if ( psAfn0cF06->sGroup[i].bStopCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucPowerWarnSta |= MT_AFN0CF06_STOP_CTRL_STAT;
                }

                // ��ǰ�����¸���״̬
                if ( psAfn0cF06->sGroup[i].bDownCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucPowerWarnSta |= MT_AFN0CF06_DOWN_CTRL_STAT;
                }

                if ( psAfn0cF06->sGroup[i].bMonthCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucElecWarnSta |= MT_AFN0CF06_MONTH_CTRL_STAT;
                }

                if ( psAfn0cF06->sGroup[i].bBuyCtrlSta )
                {
                    psAfn0cF06_f->sGroup[j].ucElecWarnSta |= MT_AFN0CF06_BUY_CTRL_STAT;
                }
                j++;
            }
        }
        n = j;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf06() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF06_f) + n * sizeof(sMtCtrlGroupSta_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf07
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F07���ն��¼���������ǰֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf07(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf07() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cF07     *psAfn0cF07   = (sMtAfn0cF07*)psUser;
    sMtAfn0cF07_f   *psAfn0cF07_f = (sMtAfn0cF07_f*)psFrame;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // �û����֡�����ݽṹһ��
        psAfn0cF07->ucEc1 = psAfn0cF07_f->ucEc1;
        psAfn0cF07->ucEc2 = psAfn0cF07_f->ucEc2;
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // �û����֡�����ݽṹһ��
        psAfn0cF07_f->ucEc1 = psAfn0cF07->ucEc1;
        psAfn0cF07_f->ucEc2 = psAfn0cF07->ucEc2;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf07() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF07_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf08
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F08���ն��¼���־״̬
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf08(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf08() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF08     *psAfn0cF08   = (sMtAfn0cF08*)psUser;
    sMtAfn0cF08_f   *psAfn0cF08_f = (sMtAfn0cF08_f*)psFrame;
    INT32   i;

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        for( i = 0; i < MT_AFN0CF08_ERC_MAX;i++)
        {
            // ERC 1 ~ 32
            if( i < 32)
            {
                psAfn0cF08->bErc[i] = (psAfn0cF08_f->ucErcLow & (1 << i)) ? TRUE : FALSE;
            }
            else if( i >= 32 && i < 64)
            {
                psAfn0cF08->bErc[i] = ((psAfn0cF08_f->ucErcHigh) & (1 << (i - 32))) ? TRUE : FALSE;
            }
            else
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf08() out of max Erc");
                #endif
                return MT_ERR_OUTRNG;
            }
        }
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        for (i = 0; i < sizeof(UINT32) * 8;i++)
        {
            if( psAfn0cF08->bErc[i] == TRUE)
            {
                psAfn0cF08_f->ucErcLow |= (1 << i);
            }
        }

        for (i = sizeof(UINT32); i < 2 * sizeof(UINT32) * 8;i++)
        {
            if( psAfn0cF08->bErc[i] == TRUE)
            {
                psAfn0cF08_f->ucErcHigh |= (1 << i);
            }
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf08() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF08_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf09
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F09���ն�״̬������λ��־
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf09(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf09() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ��� 
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf09() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF09_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf10
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F10���ն�����վ���ա���ͨ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf10(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf10() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ��� 
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
    // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf10() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF10_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf11
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F11�� �ն˼��г���״̬��Ϣ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf11(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf11() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF11_f *psMtAfn0cF11_f = (sMtAfn0cF11_f *)psFrame;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        if (psMtAfn0cF11_f->ucBlockNum < 1 || psMtAfn0cF11_f->ucBlockNum > 31)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf11() ucBlockNum out of range!");
            #endif
            return MT_ERR_OUTRNG; 
        }
        // δ����ն�ͨ�Ŷ˿ں�(1 ~ 31)
    }
    else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf11() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF11_f) + psMtAfn0cF11_f->ucBlockNum * sizeof(sMtDataBlock);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf17
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F17����ǰ�ܼ��й����� 
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf17(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf17() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf17() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF17_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf18
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F18����ǰ�ܼ��޹����� 
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf18(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf18() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf18() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF18_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf19
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F19�������ܼ��й�������(�ܡ����� 1~M)
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf19(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf19() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF19_f *psMtAfn0cF19_f = (sMtAfn0cF19_f *)psFrame;
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf19() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF19_f) + psMtAfn0cF19_f->ucRateNum * sizeof(sMtFmt_sX7_f);
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf20
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F20�������ܼ��޹�������(�ܡ����� 1~M)
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf20(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf20() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF20_f *psMtAfn0cF20_f = (sMtAfn0cF20_f *)psFrame;
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf20() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF20_f) + psMtAfn0cF20_f->ucRateNum * sizeof(sMtFmt_sX7_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf21
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F21�������ܼ��й�������(�ܡ����� 1~M)
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf21(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    return emtTrans_afn0cf19(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf22
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F22�������ܼ��޹�������(�ܡ����� 1~M)
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf22(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    return emtTrans_afn0cf20(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf23
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F23���ն˵�ǰʣ�����(��)
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf23(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf23() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf23() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF23_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf24
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F24����ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf24(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf24() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
 
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf24() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF24_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf25
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F25����ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf25() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF25     *psAfn0cF25   = (sMtAfn0cF25*)psUser;
    sMtAfn0cF25_f   *psAfn0cF25_f = (sMtAfn0cF25_f*)psFrame;
    BOOL             bNone        = FALSE;
    UINT16           usLen        = 0;
    eMtErr           eRet         = MT_OK;

    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // sReadTime
        usLen = sizeof(sMtYYMMDDhhmm_f);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->sReadTime), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bsReadTime = FALSE;
        }
        else
        {
            psAfn0cF25->bsReadTime = TRUE;
            eRet = emt_trans_YYMMDDhhmm(eTrans, &(psAfn0cF25->sReadTime),
            &(psAfn0cF25_f->sReadTime));
            
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
    
        // fp
        usLen = sizeof(sMtFmt_sXX_XXXX);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fP), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfP = FALSE;
        }
        else
        {
            psAfn0cF25->bfP = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fP),
            &(psAfn0cF25_f->fP));
    
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fpa
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPa = FALSE;
        }
        else
        {
            psAfn0cF25->bfPa = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPa), 
            &(psAfn0cF25_f->fPa));
    
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fpb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPb), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPb = FALSE;
        }
        else
        {
            psAfn0cF25->bfPb = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPb), 
            &(psAfn0cF25_f->fPb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fpc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPc = FALSE;
        }
        else
        {
            psAfn0cF25->bfPc = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPc), 
            &(psAfn0cF25_f->fPc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fQ
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fQ), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfQ = FALSE;
        }
        else
        {
            psAfn0cF25->bfQ = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQ), 
            &(psAfn0cF25_f->fQ));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
        
        // fQa
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fQa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfQa = FALSE;
        }
        else
        {
            psAfn0cF25->bfQa = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQa),
            &(psAfn0cF25_f->fQa));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }  
        
        // fQb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fQb),usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfQb = FALSE;
        }
        else
        {
            psAfn0cF25->bfQb = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQb), 
            &(psAfn0cF25_f->fQb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fQc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fQc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfQc = FALSE;
        }
        else
        {
            psAfn0cF25->bfQc = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQc), 
            &(psAfn0cF25_f->fQc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // Pf
        usLen = sizeof(sMtFmt_sXXX_X);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPf), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPf = FALSE;
        }
        else
        {
            psAfn0cF25->bfPf = TRUE;
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPf), 
            &(psAfn0cF25_f->fPf));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
        
        // Pfa
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPfa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPfa = FALSE;
        }
        else
        {
            psAfn0cF25->bfPfa = TRUE;
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfa),
            &(psAfn0cF25_f->fPfa));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
        
        // Pfb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPfb), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPfb = FALSE;
        }
        else
        {
            psAfn0cF25->bfPfb = TRUE;
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfb), 
            &(psAfn0cF25_f->fPfb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // Pfc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fPfc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfPfc = FALSE;
        }
        else
        {
            psAfn0cF25->bfPfc = TRUE;
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfc), 
            &(psAfn0cF25_f->fPfc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fUa
        usLen = sizeof(sMtFmt_XXX_X);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fUa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfUa = FALSE;
        }
        else
        {
            psAfn0cF25->bfUa = TRUE;
            eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUa), 
            &(psAfn0cF25_f->fUa));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }     
        
        // fUb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fUb), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfUb = FALSE;
        }
        else
        {
            psAfn0cF25->bfUb = TRUE;
            eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUb),
            &(psAfn0cF25_f->fUb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
        
        // fUc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fUc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfUc = FALSE;
        }
        else
        {
            psAfn0cF25->bfUc = TRUE;
            eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUc), 
            &(psAfn0cF25_f->fUc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fIa
        usLen = sizeof(sMtFmt_sXXX_XXX);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fIa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfIa = FALSE;
        }
        else
        {
            psAfn0cF25->bfIa = TRUE;
            eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIa), 
            &(psAfn0cF25_f->fIa));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
        
        // fIb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fIb), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfIb = FALSE;
        }
        else
        {
            psAfn0cF25->bfIb = TRUE;
            eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIb),
            &(psAfn0cF25_f->fIb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }  
        
        // fIc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fIc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfIc = FALSE;
        }
        else
        {
            psAfn0cF25->bfIc = TRUE;
            eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIc), 
            &(psAfn0cF25_f->fIc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fI0
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fI0), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfI0 = FALSE;
        }
        else
        {
            psAfn0cF25->bfI0 = TRUE;
            eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fI0), 
            &(psAfn0cF25_f->fI0));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
        
        // fS
        usLen = sizeof(sMtFmt_sXX_XXXX);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fS), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfS = FALSE;
        }
        else
        {
            psAfn0cF25->bfS = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fS),
            &(psAfn0cF25_f->fS));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }   
            
        // fSa
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fSa), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfSa = FALSE;
        }
        else
        {
            psAfn0cF25->bfSa = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSa), 
            &(psAfn0cF25_f->fSa));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }        
           
        // fSb
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fSb), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfSb = FALSE;
        }
        else
        {
            psAfn0cF25->bfSb = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSb), 
            &(psAfn0cF25_f->fSb));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        }
           
        // fpc
        bNone = bmt_is_none((UINT8*)&(psAfn0cF25_f->fSc), usLen);
        if(TRUE == bNone)
        {
            psAfn0cF25->bfSc = FALSE;
        }
        else
        {
            psAfn0cF25->bfSc = TRUE;
            eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSc), 
            &(psAfn0cF25_f->fSc));
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                #endif
                return eRet;
            }
        } 
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
           // sReadTime
           usLen = sizeof(sMtYYMMDDhhmm_f);
           bNone = psAfn0cF25->bsReadTime;
           if(TRUE == bNone)
           {
               eRet = emt_trans_YYMMDDhhmm(eTrans, &(psAfn0cF25->sReadTime),
               &(psAfn0cF25_f->sReadTime));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->sReadTime), usLen);
           }
   
           // fp
           usLen = sizeof(sMtFmt_sXX_XXXX);
           bNone = psAfn0cF25->bfP;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fP),
               &(psAfn0cF25_f->fP));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fP), usLen);
           }
           
           // fpa
           bNone = psAfn0cF25->bfPa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPa), 
               &(psAfn0cF25_f->fPa));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPa), usLen);
           }
           
           // fpb
           bNone = psAfn0cF25->bfPb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPb), 
               &(psAfn0cF25_f->fPb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPb), usLen);
           }
   
           // fpc
           bNone = psAfn0cF25->bfPc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fPc), 
               &(psAfn0cF25_f->fPc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPc), usLen);
           }
   
           // fQ
           bNone = psAfn0cF25->bfQ;
           if(TRUE == bNone)
           {
                eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQ), 
               &(psAfn0cF25_f->fQ));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fQ), usLen);
           }
           
           // fQa
           bNone = psAfn0cF25->bfQa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQa),
               &(psAfn0cF25_f->fQa));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fQa), usLen);
           }
           
           // fQb
           bNone = psAfn0cF25->bfQb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQb), 
               &(psAfn0cF25_f->fQb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fQb), usLen);
           }
   
           // fQc
           bNone = psAfn0cF25->bfQc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fQc), 
               &(psAfn0cF25_f->fQc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fQc), usLen);
           }
   
           // Pf
           usLen = sizeof(sMtFmt_sXXX_X);
           bNone = psAfn0cF25->bfPf;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPf), 
               &(psAfn0cF25_f->fPf));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fQc), usLen);
           }
           
           // Pfa
           bNone = psAfn0cF25->bfPfa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfa),
               &(psAfn0cF25_f->fPfa));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPfa), usLen);
           }
           
           // Pfb
           bNone = psAfn0cF25->bfPfb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfb), 
               &(psAfn0cF25_f->fPfb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPfb), usLen);
           }
   
           // Pfc
           bNone = psAfn0cF25->bfPfc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF25->fPfc), 
               &(psAfn0cF25_f->fPfc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fPfc), usLen);
           }
   
           // fUa
           usLen = sizeof(sMtFmt_XXX_X);
           bNone = psAfn0cF25->bfUa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUa), 
               &(psAfn0cF25_f->fUa));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fUa), usLen);
           }
           
           // fUb
           bNone = psAfn0cF25->bfUb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUb),
               &(psAfn0cF25_f->fUb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fUb), usLen);
           }
           
           // fUc
           bNone = psAfn0cF25->bfUc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_XXX_X(eTrans, &(psAfn0cF25->fUc), 
               &(psAfn0cF25_f->fUc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fUc), usLen);
           }
   
           // fIa
           usLen = sizeof(sMtFmt_sXXX_XXX);
           bNone = psAfn0cF25->bfIa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIa), 
               &(psAfn0cF25_f->fIa));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fIa), usLen);
           }
           
           // fIb
           bNone = psAfn0cF25->bfIb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIb),
               &(psAfn0cF25_f->fIb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fIb), usLen);
           }
           
           // fIc
           bNone = psAfn0cF25->bfIc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fIc),
               &(psAfn0cF25_f->fIc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fIc), usLen);
           }
   
           // fI0
           bNone = psAfn0cF25->bfI0;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXXX_XXX(eTrans, &(psAfn0cF25->fI0),
               &(psAfn0cF25_f->fI0));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fI0), usLen);
           }
   
           // fS
           usLen = sizeof(sMtFmt_sXX_XXXX);
           bNone = psAfn0cF25->bfS;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fS),
               &(psAfn0cF25_f->fS));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fS), usLen);
           }
           
           // fSa
           bNone = psAfn0cF25->bfSa;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSa),
               &(psAfn0cF25_f->fSa));
                 if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fSa), usLen);
           }
           
           // fSb
           bNone = psAfn0cF25->bfSb;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSb),
               &(psAfn0cF25_f->fSb));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fSb), usLen);
           }
           
           // fpc
           bNone = psAfn0cF25->bfSc;
           if(TRUE == bNone)
           {
               eRet = emt_trans_sXX_XXXX(eTrans, &(psAfn0cF25->fSc),
               &(psAfn0cF25_f->fSc));
               if(MT_OK != eRet)
               {
                   #ifdef MT_DBG
                   DEBUG("emtTrans_afn0cf25() trans error %d ", eRet);
                   #endif
                   return eRet;
               }
           }
           else
           {
               vmt_set_none((UINT8*)&(psAfn0cF25_f->fSc), usLen);
           }
           
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf25() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF25_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf26
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F26�� A��B��C�������ͳ�����ݼ����һ�ζ����¼
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf26(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf26() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
  
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf26() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF26_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf27
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F27��  ���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ?
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf27(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf27() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
  
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf27() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF27_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf28
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F28��   �������״̬�ּ����λ��־
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf28(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf28() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
  
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf28() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF28_f);
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf29
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F29��   ��ǰͭ�������й��ܵ���ʾֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf29(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf29() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
  
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf29() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF29_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf30
 ��������  :  ��ʽת������
              ����1�����ݣ�AFN=0CH��
              F30��   ��һ������ͭ�������й��ܵ���ʾֵ
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��23�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf30(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf30() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
  
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf30() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF30_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf31
 ��������  : F31����ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ
             CMD_AFN_C_F31_POWER_CUR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf31() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf31     *psAfn0cF31   = (sMtAfn0cf31*)psUser;
    sMtAfn0cf31_f   *psAfn0cF31_f = (sMtAfn0cf31_f*)psFrame;
   
    // �ն˳���ʱ��
    emt_trans_YYMMDDhhmm(eTrans, &(psAfn0cF31->sTime),&(psAfn0cF31_f->sTime));

    // ��ǰA�� ��/ ���й�����ʾֵ������޹�1 / 2����ʾֵ
    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseA.dFrthHavePower),&(psAfn0cF31_f->sPhaseA.dFrthHavePower));

    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseA.dBackHavePower),&(psAfn0cF31_f->sPhaseA.dBackHavePower));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseA.fComNonePower1),&(psAfn0cF31_f->sPhaseA.fComNonePower1));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseA.fComNonePower2),&(psAfn0cF31_f->sPhaseA.fComNonePower2));

    // ��ǰB�� ��/ ���й�����ʾֵ������޹�1 / 2����ʾֵ
    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseB.dFrthHavePower),&(psAfn0cF31_f->sPhaseB.dFrthHavePower));

    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseB.dBackHavePower),&(psAfn0cF31_f->sPhaseB.dBackHavePower));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseB.fComNonePower1),&(psAfn0cF31_f->sPhaseB.fComNonePower1));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseB.fComNonePower2),&(psAfn0cF31_f->sPhaseB.fComNonePower2));

     // ��ǰB�� ��/ ���й�����ʾֵ������޹�1 / 2����ʾֵ
    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseC.dFrthHavePower),&(psAfn0cF31_f->sPhaseC.dFrthHavePower));

    emt_trans_XXXXXX_XXXX(eTrans, 
    &(psAfn0cF31->sPhaseC.dBackHavePower),&(psAfn0cF31_f->sPhaseC.dBackHavePower));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseC.fComNonePower1),&(psAfn0cF31_f->sPhaseC.fComNonePower1));

    emt_trans_XXXXXX_XX(eTrans,
        &(psAfn0cF31->sPhaseC.fComNonePower2),&(psAfn0cF31_f->sPhaseC.fComNonePower2));
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf31_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf32
 ��������  : F32����һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ
             CMD_AFN_C_F32_POWER_LAST
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf32(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
   return emtTrans_afn0cf31(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf33
 ��������  : F33����ǰ������/ �޹�����ʾֵ��һ/ �����书����ʾֵ ( �ܡ�����1  ~ M, 1 <= M  <= 12)
             CMD_AFN_C_F33_FRTH_POWR_P1P4_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf33(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf33() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf33_f  *psMtAfn0cf33_f = (sMtAfn0cf33_f *)psFrame;
    UINT16         usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf33_f);     

        // ��ǰ�����й�
        usLen += sizeof(sMtCurFrthHaveValue) + psMtAfn0cf33_f->ucRateM * sizeof(sMtFmt14_f);


        // ��ǰ�����޹�
        usLen += sizeof(sMtCurFrthNoneValue) + psMtAfn0cf33_f->ucRateM * sizeof(sMtFmt11_f);

        // ��ǰһ�����޹�����
        usLen += sizeof(sMtCurP1NoneValue) + psMtAfn0cf33_f->ucRateM * sizeof(sMtFmt11_f);

        // ��ǰ�������޹�����
        usLen += sizeof(sMtCurP4NoneValue) + psMtAfn0cf33_f->ucRateM * sizeof(sMtFmt11_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf33() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf34
 ��������  : F34����ǰ������/ �޹�����ʾֵ����/ �����޹�����ʾֵ ( �ܡ�����1  ~ M, 1 <= M  <= 12)
             CMD_AFN_C_F34_BACK_POWR_P2P3_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf34(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf34() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf34_f *psMtAfn0cf34_f = (sMtAfn0cf34_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf34_f);     

        // ��ǰ�����й�
        usLen += sizeof(sMtCurBackHaveValue) + psMtAfn0cf34_f->ucRateM * sizeof(sMtFmt14_f);

        // ��ǰ�����޹�
        usLen += sizeof(sMtCurBackNoneValue) + psMtAfn0cf34_f->ucRateM * sizeof(sMtFmt11_f);

        // ��ǰ�������޹�����
        usLen += sizeof(sMtP2NoneValue) + psMtAfn0cf34_f->ucRateM * sizeof(sMtFmt11_f);

        // ��ǰ�������޹�����
        usLen += sizeof(sMtP3NoneValue) + psMtAfn0cf34_f->ucRateM * sizeof(sMtFmt11_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf34() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf35
 ��������  : F35��// ����������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
             CMD_AFN_C_F35_FRTH_DMND_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf35(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf35() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf35_f *psMtAfn0cf35_f = (sMtAfn0cf35_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf35_f);     

        // ���������й����������
        usLen += sizeof(sMtCurFrthHaveDmnd) + psMtAfn0cf35_f->ucRateM * sizeof(sMtFmt23_f);

        // ���������й��������������ʱ��
        usLen += sizeof(sMtCurFrthHaveTime) + psMtAfn0cf35_f->ucRateM * sizeof(sMtFmt17_f);

        // ���������޹����������
        usLen += sizeof(sMtCurFrthNoneDmnd) + psMtAfn0cf35_f->ucRateM * sizeof(sMtFmt23_f);

        // ���������޹��������������ʱ��
        usLen += sizeof(sMtCurFrthNoneTime) + psMtAfn0cf35_f->ucRateM * sizeof(sMtFmt17_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf35() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf36
 ��������  : F36�����·�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
             CMD_AFN_C_F36_BACK_DMND_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf36(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf36() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf36_f *psMtAfn0cf36_f = (sMtAfn0cf36_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf36_f);     

        // ���·����й����������
        usLen += sizeof(sMtCurBackHaveDmnd) + psMtAfn0cf36_f->ucRateM * sizeof(sMtFmt23_f);

        // ���·����й��������������ʱ��
        usLen += sizeof(sMtCurBackHaveTime) + psMtAfn0cf36_f->ucRateM * sizeof(sMtFmt17_f);

        // ���·����޹����������
        usLen += sizeof(sMtCurBackNoneDmnd) + psMtAfn0cf36_f->ucRateM * sizeof(sMtFmt23_f);

        // ���·����޹��������������ʱ��
        usLen += sizeof(sMtCurBackNoneTime) + psMtAfn0cf36_f->ucRateM * sizeof(sMtFmt17_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf36() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf37
 ��������  : F37�����£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
             CMD_AFN_C_F37_FRTH_POWR_P1P4_L
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf37(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf37() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf37_f *psMtAfn0cf37_f = (sMtAfn0cf37_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf37_f);     

        // ����( ��һ������) �����й�����ʾֵ
        usLen += sizeof(sMtLastFrthHaveValue) + psMtAfn0cf37_f->ucRateM * sizeof(sMtFmt14_f);

        // ����(��һ������) �����޹�����ʾֵ
        usLen += sizeof(sMtLastFrthNoneValue) + psMtAfn0cf37_f->ucRateM * sizeof(sMtFmt11_f);

        // ����(��һ������) һ�����޹�����ʾֵ
        usLen += sizeof(sMtLastP1NoneValue) + psMtAfn0cf37_f->ucRateM * sizeof(sMtFmt11_f);

        // ����(��һ������) �������޹�����ʾֵ
        usLen += sizeof(sMtLastP4NoneValue) + psMtAfn0cf37_f->ucRateM * sizeof(sMtFmt11_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf37() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf38
 ��������  : F37�����£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
             CMD_AFN_C_F38_BACK_POWR_P2P3_L
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf38(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf38() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf38_f *psMtAfn0cf38_f = (sMtAfn0cf38_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf38_f);     

        // ����( ��һ������) �����й�����ʾֵ
        usLen += sizeof(sMtLastBackHaveValue) + psMtAfn0cf38_f->ucRateM * sizeof(sMtFmt14_f);

        // ����(��һ������) �����޹�����ʾֵ
        usLen += sizeof(sMtLastBackNoneValue) + psMtAfn0cf38_f->ucRateM * sizeof(sMtFmt11_f);

        // ����(��һ������) �������޹�����ʾֵ
        usLen += sizeof(sMtLastP2NoneValue) + psMtAfn0cf38_f->ucRateM * sizeof(sMtFmt11_f);

        // ����(��һ������) �������޹�����ʾֵ
        usLen += sizeof(sMtLastP3NoneValue) + psMtAfn0cf38_f->ucRateM * sizeof(sMtFmt11_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf38() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf39
 ��������  : F39�����£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
             CMD_AFN_C_F39_FRTH_DMND_L
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf39(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf39() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf39_f *psMtAfn0cf39_f = (sMtAfn0cf39_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf39_f);     

        // ���£���һ�����գ������й����������
        usLen += sizeof(sMtLastFrthHaveDmnd) + psMtAfn0cf39_f->ucRateM * sizeof(sMtFmt23_f);

        // ���£���һ�����գ������й��������������ʱ��
        usLen += sizeof(sMtLastFrthHaveTime) + psMtAfn0cf39_f->ucRateM * sizeof(sMtFmt17_f);

        // ���£���һ�����գ������޹����������
        usLen += sizeof(sMtLastFrthNoneDmnd) + psMtAfn0cf39_f->ucRateM * sizeof(sMtFmt23_f);

        // ���£���һ�����գ������޹��������������ʱ��
        usLen += sizeof(sMtLastFrthNoneTime) + psMtAfn0cf39_f->ucRateM * sizeof(sMtFmt17_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf39() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf40
 ��������  : F40�����£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
             CMD_AFN_C_F40_BACK_DMND_L
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf40(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf40() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf40_f *psMtAfn0cf40_f = (sMtAfn0cf40_f *)psFrame;
    UINT16        usLen = 0;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        // ֡ͷ��
        usLen += sizeof(sMtAfn0cf40_f);     

        // ���£���һ�����գ������й����������
        usLen += sizeof(sMtLastBackHaveDmnd) + psMtAfn0cf40_f->ucRateM * sizeof(sMtFmt23_f);

        // ���£���һ�����գ������й��������������ʱ��
        usLen += sizeof(sMtLastBackHaveTime) + psMtAfn0cf40_f->ucRateM * sizeof(sMtFmt17_f);

        // ���£���һ�����գ������޹����������
        usLen += sizeof(sMtLastBackNoneDmnd) + psMtAfn0cf40_f->ucRateM * sizeof(sMtFmt23_f);

        // ���£���һ�����գ������޹��������������ʱ��
        usLen += sizeof(sMtLastBackNoneTime) + psMtAfn0cf40_f->ucRateM * sizeof(sMtFmt17_f);
        
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf40() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = usLen;
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf41
 ��������  : ���������й����������ܡ�����1��M�� CMD_AFN_C_F41_FRTH_HAVE_POWR_D
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf41(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf41() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF41     *psAfn0cF41   = (sMtAfn0cF41*)psUser;
    sMtAfn0cF41_f   *psAfn0cF41_f = (sMtAfn0cF41_f*)psFrame;
    BOOL             bNone        = FALSE;
    UINT16           usLen        = 0;
    INT32            i            = 0;

    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // ����M
        usLen = sizeof(UINT8);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF41_f->ucM), usLen);
        if(TRUE == bNone)
        {
           psAfn0cF41->bucM = FALSE;
        }
        else
        {
            psAfn0cF41->bucM = TRUE;
            psAfn0cF41->ucM = psAfn0cF41_f->ucM;
            usLen = sizeof(sMtFmt_XXXX_XXXX);
            
            if(psAfn0cF41->ucM > MT_PAY_RATE_MAX)
            {
                return MT_ERR_OUTRNG;
            }
            
            for(i = 0; i < psAfn0cF41->ucM; i++)
            {
               bNone = bmt_is_none((UINT8*)&(psAfn0cF41_f->dForthHavePowerMD[i]), usLen);
               if(TRUE == bNone)
               {
                   psAfn0cF41->bdForthHavePowerMD[i] = FALSE;
               }
               else
               {
                   psAfn0cF41->bdForthHavePowerMD[i] = TRUE;
                   emt_trans_XXXX_XXXX(eTrans, &(psAfn0cF41->dForthHavePowerMD[i]), &(psAfn0cF41_f->dForthHavePowerMD[i]));
               }
            }
        }

        // ���������й��ܵ�����
        usLen = sizeof(sMtFmt_XXXX_XXXX);
        bNone = bmt_is_none((UINT8*)&(psAfn0cF41_f->dForthHavePowerD), usLen);
        if(bNone)
        {
           psAfn0cF41->bdForthHavePowerD = FALSE;
        }
        else
        {
            psAfn0cF41->bdForthHavePowerD = TRUE;
            emt_trans_XXXX_XXXX(eTrans, &(psAfn0cF41->dForthHavePowerD), &(psAfn0cF41_f->dForthHavePowerD));
        }
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        bNone = !psAfn0cF41->bucM;
        usLen = sizeof(UINT8);
        if(TRUE == bNone)
        {
            vmt_set_none((UINT8*)&(psAfn0cF41->ucM), usLen);
        }
        else
        {
            psAfn0cF41_f->ucM = psAfn0cF41->ucM;
            if(psAfn0cF41->ucM > MT_PAY_RATE_MAX)
            {
                return MT_ERR_OUTRNG;
            }

            for(i = 0; i < psAfn0cF41->ucM; i++)
            {
                bNone = !psAfn0cF41->bdForthHavePowerMD[i];
                usLen = sizeof(sMtFmt_XXXX_XXXX);
                if(TRUE == bNone)
                {
                  vmt_set_none((UINT8*)&(psAfn0cF41_f->dForthHavePowerMD[i]), usLen);
                }
                else
                {
                    emt_trans_XXXX_XXXX(eTrans, &(psAfn0cF41->dForthHavePowerMD[i]), &(psAfn0cF41_f->dForthHavePowerMD[i])); 
                }
            }
        }

        bNone = !psAfn0cF41->bdForthHavePowerD;
        usLen = sizeof(sMtFmt_XXXX_XXXX);
        if(TRUE == bNone)
        {
            vmt_set_none((UINT8*)&(psAfn0cF41_f->dForthHavePowerD), usLen);
        }
        else
        {
            emt_trans_XXXX_XXXX(eTrans, &(psAfn0cF41->dForthHavePowerD), &(psAfn0cF41_f->dForthHavePowerD)); 
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf41() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF41_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf42
 ��������  : ���������޹����������ܡ�����1��M�� CMD_AFN_C_F42_FRTH_NONE_POWR_D
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf42(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf43
 ��������  : ���շ����й����������ܡ�����1��M��CMD_AFN_C_F43_BACK_HAVE_POWR_D
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf43(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf44
 ��������  : ���շ����޹����������ܡ�����1��M��CMD_AFN_C_F44_BACK_NONE_POWR_D
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf44(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf45
 ��������  : ���������й����������ܡ�����1��M��CMD_AFN_C_F45_FRTH_HAVE_POWR_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf45(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf46
 ��������  : ���������޹����������ܡ�����1��M��CMD_AFN_C_F46_FRTH_NONE_POWR_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf46(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf47
 ��������  : ���·����й����������ܡ�����1��M��CMD_AFN_C_F47_BACK_HAVE_POWR_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf47(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf48
 ��������  : ���·����޹����������ܡ�����1��M��CMD_AFN_C_F48_BACK_NONE_POWR_M
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��13�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf48(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ���ݽṹһ��, ��ͳһ��ת������
    return emtTrans_afn0cf41(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf49
 ��������  : F49����ǰ��ѹ��������λ��
             CMD_AFN_C_F49_CURT_PHASE_ANGLE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf49() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf49() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf49_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf57
 ��������  : F57����ǰA��B��C�����ѹ������2��N��г����Чֵ CMD_AFN_C_F57_CURT_HARM_VALUE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf57(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf57() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF57     *psAfn0cF57   = (sMtAfn0cF57*)psUser;
    sMtAfn0cF57_f   *psAfn0cF57_f = (sMtAfn0cF57_f*)psFrame;
    BOOL             bNone        = FALSE;
    INT32            i            = 0;
    INT32            nCycMax      = 0;
    INT32            nOffset      = 0;
    UINT8            ucN          = 0;
    eMtErr           eRet         = MT_OK;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        ucN     = psAfn0cF57_f->ucN;
        if(MT_HARM_TIMES_MIN > ucN || MT_HARM_TIMES_MAX < ucN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf57() ucN is out of range ucN = %d", ucN);
            #endif
            return MT_ERR_OUTRNG;
        }

        psAfn0cF57->ucN = ucN;
        nCycMax = ucN - 1;

        // ua
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[i]), sizeof(sMtFmt_XXX_X));
            if(TRUE == bNone)
            {
                psAfn0cF57->sUa.bfXXX_X[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sUa.bfXXX_X[i] = TRUE;
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUa.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = nCycMax;

        // Ub
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_XXX_X));
            if(TRUE == bNone)
            {
                psAfn0cF57->sUb.bfXXX_X[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sUb.bfXXX_X[i] = TRUE;
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUb.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 2 * nCycMax;

        // Uc
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_XXX_X));
            if(TRUE == bNone)
            {
                psAfn0cF57->sUc.bfXXX_X[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sUc.bfXXX_X[i] = TRUE;
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUc.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 3 * nCycMax;

        // Ia
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            if(TRUE == bNone)
            {
                psAfn0cF57->sIa.bfsXX_XX[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sIa.bfsXX_XX[i] = TRUE;
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIa.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 4 * nCycMax;
      
        // Ib
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            if(TRUE == bNone)
            {
                psAfn0cF57->sIb.bfsXX_XX[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sIb.bfsXX_XX[i] = TRUE;
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIb.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 5 * nCycMax;

        // Ic
        for(i = 0; i < nCycMax; i++)
        {
            bNone = bmt_is_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            if(TRUE == bNone)
            {
                psAfn0cF57->sIc.bfsXX_XX[i] = FALSE;
            }
            else
            {
                psAfn0cF57->sIc.bfsXX_XX[i] = TRUE;
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIc.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        ucN = psAfn0cF57->ucN;
        if(MT_HARM_TIMES_MIN > ucN || MT_HARM_TIMES_MAX < ucN)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf57() ucN is out of range ucN = %d", ucN);
            #endif
            return MT_ERR_OUTRNG;
        }
        
        psAfn0cF57_f->ucN = ucN;
        nCycMax           = ucN - 1;
        // ua
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sUa.bfXXX_X[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[i]), sizeof(sMtFmt_XXX_X));
            }
            else
            {
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUa.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = nCycMax;
        
        // Ub
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sUb.bfXXX_X[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_XXX_X));
            }
            else
            {
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUb.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }
        
        nOffset = 2 * nCycMax;

        // Uc
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sUc.bfXXX_X[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_XXX_X));
            }
            else
            {
                eRet = emt_trans_XXX_X(eTrans, 
                                       &(psAfn0cF57->sUc.fXXX_X[i]), 
                                       (sMtFmt07*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_XXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }
        
        nOffset = 3 * nCycMax;

        // Ia
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sIa.bfsXX_XX[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            }
            else
            {
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIa.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 4 * nCycMax;

        // Ib
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sIb.bfsXX_XX[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            }
            else
            {
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIb.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        nOffset = 5 * nCycMax;

        // Ic
        for(i = 0; i < nCycMax; i++)
        {
            bNone = !(psAfn0cF57->sIc.bfsXX_XX[i]);
            if(TRUE == bNone)
            {
                vmt_set_none((UINT8*)&(psAfn0cF57_f->uHarm[nOffset + i]), sizeof(sMtFmt_sXX_XX));
            }
            else
            {
                eRet = emt_trans_sXX_XX(eTrans, 
                                       &(psAfn0cF57->sIc.fsXX_XX[i]), 
                                       (sMtFmt06*)&(psAfn0cF57_f->uHarm[nOffset + i]));
                if(MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXX_XX() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf57() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cF57_f) + 6 * sizeof(sMtFmt_sXX_XX) * (ucN - 1);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf58
 ��������  : F58����ǰA��B��C�����ѹ������2��N��г��������
 ��Ӧ����  : CMD_AFN_C_F58_CURT_HARM_RATE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf58(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf58() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cF58     *psAfn0cF58   = (sMtAfn0cF58*)psUser;
    sMtAfn0cF58_f   *psAfn0cF58_f = (sMtAfn0cF58_f*)psFrame;
    UINT8            ucN          = 0;
    BOOL             bNone        = FALSE;
    eMtErr           eRet         = MT_OK;
    UINT8            i,j;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        ucN = psAfn0cF58_f->ucN;
        psAfn0cF58->ucN = ucN;
        j = 0;

        // UA
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sUa.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sUa.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUa.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;

        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sUa.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sUa.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUa.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        // UB
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sUb.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sUb.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUb.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;

        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sUb.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sUb.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUb.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        // UC
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sUc.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sUc.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUc.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;

        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sUc.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sUc.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUc.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        // IA
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sIa.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sIa.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIa.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;

        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sIa.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sIa.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIa.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        // IB
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sIb.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sIb.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIb.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;

        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sIb.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sIb.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIb.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }

        // IC
        bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
        if ( bNone == TRUE) 
        {
            psAfn0cF58->sIc.sTotal.bfsXXX_X = FALSE;
        }else
        {
            psAfn0cF58->sIc.sTotal.bfsXXX_X = TRUE;
            eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIc.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }
        j++;
        
        for(i = 0; i < ucN - 1;i++,j++)
        {
            bNone = bmt_is_none((UINT8 *)&(psAfn0cF58_f->sXXX_X[j]),sizeof(sMtFmt_sXXX_X));
            if ( bNone == TRUE) 
            {
                psAfn0cF58->sIc.bfsXXX_X[i] = FALSE;
            }else
            {
                psAfn0cF58->sIc.bfsXXX_X[i] = TRUE;
                eRet  = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIc.fsXXX_X[i])
                                          , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet)
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }
        }
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        ucN = psAfn0cF58->ucN;
        psAfn0cF58_f->ucN = ucN;
        j = 0;

        // UA
        if ( psAfn0cF58->sUa.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUa.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));
            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++) 
        {
            if ( psAfn0cF58->sUa.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUa.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));
                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }

        // UB
        if ( psAfn0cF58->sUb.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUb.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++) 
        {
             if ( psAfn0cF58->sUb.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUb.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));
                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }

        // UC
        if ( psAfn0cF58->sUc.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUc.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));
            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++ ) 
        {
             if ( psAfn0cF58->sUc.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sUc.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));
                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }

        // IA
        if ( psAfn0cF58->sIa.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIa.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++ ) 
        {
            if ( psAfn0cF58->sIa.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIa.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }

        // IB
        if ( psAfn0cF58->sIb.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIb.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++ ) 
        {
            if ( psAfn0cF58->sIb.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIb.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }

        // IC
        if ( psAfn0cF58->sIc.sTotal.bfsXXX_X == TRUE) 
        {
            eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIc.sTotal.fsXXX_X)
                                      , &(psAfn0cF58_f->sXXX_X[j]));

            if ( MT_OK != eRet )
            {
                #ifdef MT_DBG
                DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                #endif       
                return eRet;
            }
        }else
        {
            vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
        }
        j++;
        
        for( i = 0;i < ucN - 1;i++,j++ ) 
        {
            if ( psAfn0cF58->sIc.bfsXXX_X[i] == TRUE) 
            {
                eRet = emt_trans_sXXX_X(eTrans, &(psAfn0cF58->sIc.fsXXX_X[i])
                                         , &(psAfn0cF58_f->sXXX_X[j]));

                if ( MT_OK != eRet )
                {
                    #ifdef MT_DBG
                    DEBUG("emt_trans_sXXX_X() error = %d", eRet);
                    #endif       
                    return eRet;
                }
            }else
            {
                vmt_set_none((UINT8*)&(psAfn0cF58_f->sXXX_X[j]), sizeof(sMtFmt_sXXX_X));;
            }
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf58() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen =sizeof(sMtAfn0cF58_f) + 6 * sizeof(sMtFmt_sXX_XX) * ucN;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf65
 ��������  : F65����ǰ������Ͷ��״̬
             CMD_AFN_C_F65_CURT_CAPA_SWITCH
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf65(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf65() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf65() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf65_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf66
 ��������  : F66����ǰ�������ۼƲ���Ͷ��ʱ��ʹ���
             CMD_AFN_C_F66_CURT_CAPA_TIME
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf66(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf66() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else if( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf66() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf66_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf67
 ��������  : F67�����ա����µ������ۼƲ������޹�������
             CMD_AFN_C_F67_CURT_CAPA_POWR
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf67(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf67() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf67() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf67_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf73
 ��������  : F73��ֱ��ģ������ǰ����
             CMD_AFN_C_F73_DC_RLTM_DATA
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf73(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf73() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    eMtErr mRet = MT_OK;
    mRet = emt_trans_sXXX(eTrans, (float *)psUser, (sMtFmt02_f *)psFrame);
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf67_f);
     return mRet;
}

/*****************************************************************************
 �� �� ��  : emtGetFrzFreq
 ��������  : ��ȡ��������Ƶ��
 �������  : UINT8 ucFrzFreq
 �������  : ��
 �� �� ֵ  :    ���ض�������Ƶ�ʣ�������-1
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
INT8 emtGetFrzFreq(UINT8 ucFrzFreq)
{
    switch(ucFrzFreq)
    {
        case MT_FRZ_NONE:
            return 0;           // ������
            
        case MT_FRZ_15:         // 15���Ӷ���һ��
            return (60 / 15);   
            
        case MT_FRZ_30:    
            return (60 / 30);   // 30���Ӷ���һ��
            
        case MT_FRZ_60:
            return (60 / 60);   // 60���Ӷ���һ��
            
        case MT_FRZ_5:
            return (60 / 5);    // 5���Ӷ���һ��
            
        case MT_FRZ_1:
            return (60 / 1);    // 1���Ӷ���һ��
            
        //case MT_FRZ_UNKNOWN:
        default:
            return -1;
    }
    
    return -1;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf81
 ��������  : F81��Сʱ�����ܼ��й�����
             CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf81(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf81() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf81_f *psMtAfn0cf81_f  = (sMtAfn0cf81_f *)psFrame;
    INT8           n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf81_f->sTimeStamp.ucFrzFreq);
        if (  n < 0)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf81() timestamp error!");
            #endif
            return MT_ERR_LOGIC;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf81() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf81_f) + n * sizeof(sMtFmt02_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf82
 ��������  : F82��Сʱ�����ܼ��޹�����
             CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf82(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    return emtTrans_afn0cf81(eTrans, psUser, psFrame,pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf83
 ��������  : F83��Сʱ�����ܼ��й��ܵ�����
             CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf83(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf83() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf83_f *psMtAfn0cf83_f  = (sMtAfn0cf83_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf83_f->sTimeStamp.ucFrzFreq);
        if ( n < 0)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf83() timestamp error!");
            #endif
            return MT_ERR_LOGIC;    
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf83() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf83_f) + n * sizeof(sMtFmt03_f);
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf84
 ��������  : F84��Сʱ�����ܼ��޹��ܵ�����
             CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf84(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf83(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf89
 ��������  : F89��Сʱ�����й�����
             CMD_AFN_C_F89_HFRZ_RATE_HAVE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf89(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf89() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf89_f *psMtAfn0cf89_f  = (sMtAfn0cf89_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf89_f->sTimeStamp.ucFrzFreq);
        if ( n < 0 )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf89() timestamp error!");
            #endif
            return MT_ERR_LOGIC;  
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf89() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf89_f) + n * sizeof(sMtFmt09);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf90
 ��������  : F90��Сʱ����A���й�����
             CMD_AFN_C_F90_HFRZ_RATE_HAVE_A
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf90(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf91
 ��������  : F91��Сʱ����B���й�����
             CMD_AFN_C_F90_HFRZ_RATE_HAVE_B
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf91(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf92
 ��������  : F92��Сʱ����C ���й�����
             CMD_AFN_C_F90_HFRZ_RATE_HAVE_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf92(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf93
 ��������  : F93��Сʱ�����޹�����
             CMD_AFN_C_F93_HFRZ_RATE_NONE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf93(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf94
 ��������  : F94��Сʱ����A  ���޹�����
             CMD_AFN_C_F94_HFRZ_RATE_NONE_A
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf94(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf95
 ��������  : F95��Сʱ����B  ���޹�����
             CMD_AFN_C_F95_HFRZ_RATE_NONE_B
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf95(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf96
 ��������  : F96��Сʱ����C  ���޹�����
             CMD_AFN_C_F96_HFRZ_RATE_NONE_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��28�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf96(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf89(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf97
 ��������  : F97��Сʱ����A ���ѹ
             CMD_AFN_C_F97_HFRZ_VOLT_A
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf97(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf97() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf97_f *psMtAfn0cf97_f  = (sMtAfn0cf97_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf97_f->sTimeStamp.ucFrzFreq);
        if ( n < 0 ) 
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf97() timestamp error!");
            #endif
            return MT_ERR_LOGIC;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf97() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf97_f) + n * sizeof(sMtFmt07);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf98
 ��������  : F98��Сʱ����B  ���ѹ
             CMD_AFN_C_F98_HFRZ_VOLT_B
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf98(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf97(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf99
 ��������  : F99��Сʱ����C  ���ѹ
             CMD_AFN_C_F99_HFRZ_VOLT_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf99(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf97(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf100
 ��������  : F100��Сʱ�����й�����
             CMD_AFN_C_F100_HFRZ_ELEC_A
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf100(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf100() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf100_f *psMtAfn0cf100_f  = (sMtAfn0cf100_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf100_f->sTimeStamp.ucFrzFreq);
        if ( n  < 0 )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf100() timestamp error!");
            #endif
            return MT_ERR_LOGIC;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf100() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf100_f) + n * sizeof(sMtFmt25);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf101
 ��������  : F101��Сʱ����B  �����
             CMD_AFN_C_F101_HFRZ_ELEC_B
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf101(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf100(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf102
 ��������  : F102��Сʱ����C  �����
             CMD_AFN_C_F102_HFRZ_ELEC_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf102(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf100(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf103
 ��������  : F103��Сʱ�����������
             CMD_AFN_C_F103_HFRZ_ELEC_ZERO
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf103(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf100(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf105
 ��������  : F105��Сʱ���������й��ܵ�����
             CMD_AFN_C_F105_HFRZ_FRTH_HAVE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf105(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf105() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf105_f *psMtAfn0cf105_f  = (sMtAfn0cf105_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf105_f->sTimeStamp.ucFrzFreq);
        if ( n < 0 )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf105() timestamp error!");
            #endif
            return MT_ERR_PARA;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf105() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf105_f) + n * sizeof(sMtFmt13);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf106
 ��������  : F106��Сʱ���������޹��ܵ�����
                          CMD_AFN_C_F106_HFRZ_FRTH_NONE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf106(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf105(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf107
 ��������  : F107��Сʱ���ᷴ���й��ܵ�����
              CMD_AFN_C_F107_HFRZ_BACK_HAVE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf107(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf105(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf108
 ��������  : F107��Сʱ���ᷴ���޹��ܵ�����
                          CMD_AFN_C_F108_HFRZ_BACK_NONE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf108(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf105(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf109
 ��������  : F109��Сʱ���������й��ܵ���ʾֵ
              CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf109(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf109() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf109_f *psMtAfn0cf109_f  = (sMtAfn0cf109_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf109_f->sTimeStamp.ucFrzFreq);
        if ( n < 0 )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf109() timestamp error!");
            #endif
            return MT_ERR_LOGIC;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf109() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf109_f) + n * sizeof(sMtFmt11);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf110
 ��������  : F110��Сʱ���������޹��ܵ���ʾֵ
                          CMD_AFN_C_F110_HFRZ_FRTH_NONE_S
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf110(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf109(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf111
 ��������  : F111��Сʱ���ᷴ���й��ܵ���ʾֵ
              CMD_AFN_C_F111_HFRZ_BACK_HAVE_S
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf111(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf109(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf112
 ��������  : F112��Сʱ���ᷴ���޹��ܵ���ʾֵ
                          CMD_AFN_C_F112_HFRZ_BACK_NONE_S
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf112(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf109(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf113
 ��������  : F109��Сʱ�����ܹ�������
             CMD_AFN_C_F113_HFRZ_FACT_TOTAL
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf113(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf113() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf113_f *psMtAfn0cf113_f  = (sMtAfn0cf113_f *)psFrame;
    INT8    n;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
        n = emtGetFrzFreq(psMtAfn0cf113_f->sTimeStamp.ucFrzFreq);
        if ( n < 0 )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf113() timestamp error!");
            #endif
            return MT_ERR_LOGIC;
        }
    }
    else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ֡��
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf113() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf113_f) + n * sizeof(sMtFmt05);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf114
 ��������  : F114��Сʱ����A�๦������
                          CMD_AFN_C_F114_HFRZ_FACT_A
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf114(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf113(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf115
 ��������  : F115��Сʱ����B�๦������
             CMD_AFN_C_F115_HFRZ_FACT_B
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf115(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf113(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf116
 ��������  : F116��Сʱ����C�๦������
                          CMD_AFN_C_F116_HFRZ_FACT_C
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf116(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf113(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf121
 ��������  : F121��Сʱ����ֱ��ģ����
             CMD_AFN_C_F121_HFRZ_DC_VALUE
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf121(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    return emtTrans_afn0cf81(eTrans, psUser, psFrame,pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf129
 ��������  : F109����ǰ�����й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F129_FRTH_HAVE_POWR_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf129(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf129_f *psMtAfn0cf129_f  = (sMtAfn0cf129_f *)psFrame;
    sMtAfn0cf129   *psMtAfn0cf129    = (sMtAfn0cf129 *)psUser;
    eMtErr eRet = MT_OK;
    UINT8 i,ucM; 
    
    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMtAfn0cf129->sTime) ,&(psMtAfn0cf129_f->sTime));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() emt_trans_YYMMDDhhmm is %d\n",eRet);
        #endif
        return eRet;
    }
    
    eRet = emt_trans_XXXXXX_XXXX(eTrans,&(psMtAfn0cf129->dTotalValue), &(psMtAfn0cf129_f->sTotalValue));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() emt_trans_XXXXXX_XXXX is %d\n",eRet);
        #endif
        return eRet;
    }

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        psMtAfn0cf129->ucM = psMtAfn0cf129_f->ucM;
        ucM = psMtAfn0cf129_f->ucM;
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        psMtAfn0cf129_f->ucM = psMtAfn0cf129->ucM;
        ucM = psMtAfn0cf129->ucM;
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() para error!");
        #endif
        return MT_ERR_PARA;
    }

    if (ucM < 1)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() ucM Out of range!");
        #endif
        return MT_ERR_OUTRNG;
    }

    for (i = 0;i < ucM; i++)
    {
        eRet = emt_trans_XXXXXX_XXXX(eTrans,&(psMtAfn0cf129->dValueItem[i]), &(psMtAfn0cf129_f->sValueItem[i]));
        if ( MT_OK != eRet )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf129() emt_trans_XXXXXX_XXXX is %d\n",eRet);
            #endif
            return eRet;
        }
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf129_f) + (ucM - 1)* sizeof(sMtFmt14_f);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf130
 ��������  : F130����ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F130_FRTH_NONE_POWR_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf130(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
   if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf130() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf130_f *psMtAfn0cf130_f  = (sMtAfn0cf130_f *)psFrame;
    sMtAfn0cf130   *psMatAfn0cf130     = (sMtAfn0cf130 *)psUser;
    eMtErr eRet = MT_OK;
    UINT8 i,ucM;
    

    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMatAfn0cf130->sTime) ,&(psMtAfn0cf130_f->sTime));
    if( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf130() emt_trans_YYMMDDhhmm is %d",eRet);
        #endif
        return eRet;
    }
    
    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMatAfn0cf130->dTotalValue), &(psMtAfn0cf130_f->sTotalValue));
    if( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf130() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        ucM = psMtAfn0cf130_f->ucM;
        psMatAfn0cf130->ucM = ucM;
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        ucM = psMatAfn0cf130->ucM;
        psMtAfn0cf130_f->ucM = ucM;
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf130() para error!");
        #endif
        return MT_ERR_PARA;
    }

    if (ucM < 1)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf129() ucM Out of range!");
        #endif
        return MT_ERR_OUTRNG;
    }

    
    for (i = 0;i < ucM; i++)
    {
        eRet = emt_trans_XXXXXX_XX(eTrans,&(psMatAfn0cf130->dValueItem[i]), &(psMtAfn0cf130_f->sValueItem[i]));
        if( MT_OK != eRet )
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0cf130() emt_trans_XXXXXX_XX is %d",eRet);
            #endif
            return eRet;
        }
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf130_f) + (ucM - 1)* sizeof(sMtFmt11_f);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf131
 ��������  : F131����ǰ�����й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F131_BACK_HAVE_POWR_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf131(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf132
 ��������  : F132����ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F132_BACK_NONE_POWR_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf132(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf133
 ��������  : F133����ǰһ�����޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F133_NONE_POWR_P1_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf133(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf134
 ��������  : F134����ǰ�������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F134_NONE_POWR_P2_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf134(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf135
 ��������  : F135����ǰ�������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F135_NONE_POWR_P3_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf135(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf136
 ��������  : F136����ǰ�������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F136_NONE_POWR_P4_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf136(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf137
 ��������  : F137�����£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F137_FRTH_HAVE_POWR_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf137(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf138
 ��������  : F138�����£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
             CMD_AFN_C_F138_FRTH_NONE_POWR_L
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf138(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf139
 ��������  : F139�����£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F139_BACK_HAVE_POWR_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf139(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf140
 ��������  : F140�����£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F140_BACK_NONE_POWR_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf140(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf141
 ��������  : F141�����£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F141_NONE_POWR_P1_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf141(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf142
 ��������  : F142�����£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F142_NONE_POWR_P2_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf142(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf143
 ��������  : F143�� ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F143_NONE_POWR_P3_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf143(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf144
 ��������  : F144�� ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F144_NONE_POWR_P4_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf144(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf130(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf145
 ��������  : F145�����������й��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F145_FRTH_HAVE_DMND_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf145(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf145() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf145_f *psMtAfn0cf145_f  = (sMtAfn0cf145_f *)psFrame;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf145() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf145_f) + (psMtAfn0cf145_f->ucRateM + 1) * sizeof(sMtDmndClock);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf146
 ��������  : F146�� ���������޹��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F146_FRTH_NONE_DMND_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf146(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf147
 ��������  : F147�� ���·����й��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F147_BACK_HAVE_DMND_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf147(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf148
 ��������  : F148�� ���·����޹��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F148_BACK_NONE_DMND_C
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf148(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf149
 ��������  : F149�� ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F149_FRTH_HAVE_DMND_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf149(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf150
 ��������  : F150�� ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F150_FRTH_NONE_DMND_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf150(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf151
 ��������  : F151�� ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F151_BACK_HAVE_DMND_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf151(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf152
 ��������  : F152�� ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��
                          CMD_AFN_C_F152_BACK_NONE_DMND_L
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf152(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf145(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf153
 ��������  : F153�� ��һʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F153_FREZ_ZONE_1
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf153(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf154
 ��������  : F154�� �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F154_FREZ_ZONE_2
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf154(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf155
 ��������  : F155�� ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F155_FREZ_ZONE_3
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf155(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf156
 ��������  : F156�� ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F156_FREZ_ZONE_4
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf156(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf157
 ��������  : F157������ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F157_FREZ_ZONE_5
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf157(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf158
 ��������  : F158������ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F158_FREZ_ZONE_6
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf158(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf159
 ��������  : F159������ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F159_FREZ_ZONE_7
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf159(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf160
 ��������  : F160���ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
                          CMD_AFN_C_F160_FREZ_ZONE_8
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf160(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
     return emtTrans_afn0cf129(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf161
 ��������  : F161�����ܱ�Զ�̿���ͨ�ϵ�״̬����¼
                          CMD_AFN_C_F161_METR_REMOTE_CTRL
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf161(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf161() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf161() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf161_f);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf165
 ��������  : F165�����ܱ��ز���������ʱ��
                          CMD_AFN_C_F165_METR_SWITCH_RECD
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf165(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf165() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf165   *psMtAfn0cf65   = (sMtAfn0cf165 *)psUser;
    sMtAfn0cf165_f *psMtAfn0cf65_f = (sMtAfn0cf165_f *)psFrame;
    eMtErr eRet = MT_OK;

    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMtAfn0cf65->sTime) ,&(psMtAfn0cf65_f->sTime));
    if ( MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMMDDhhmm() is %d",eRet);
        #endif
        return eRet; 
    }

    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMtAfn0cf65->sOne.sClock) ,&(psMtAfn0cf65_f->sOne.sClock));
    if ( MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMMDDhhmm() is %d",eRet);
        #endif
        return eRet; 
    }

    eRet = emt_trans_XXXX(eTrans,&(psMtAfn0cf65->sOne.usTimes) ,&(psMtAfn0cf65_f->sOne.sTimes));
    if ( MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXX() is %d",eRet);
        #endif
        return eRet; 
    }

    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMtAfn0cf65->sOther.sClock) ,&(psMtAfn0cf65_f->sOther.sClock));
    if ( MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMMDDhhmm() is %d",eRet);
        #endif
        return eRet; 
    }

    eRet = emt_trans_XXXX(eTrans,&(psMtAfn0cf65->sOther.usTimes) ,&(psMtAfn0cf65_f->sOther.sTimes));
    if ( MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXX() is %d",eRet);
        #endif
        return eRet; 
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf165_f);
     return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf166
 ��������  : F166�����ܱ�����޸Ĵ�����ʱ��
                          CMD_AFN_C_F166_METR_MODIFY_RECD
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf166(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
     return emtTrans_afn0cf165(eTrans, psUser, psFrame, pusfLen);
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf167
 ��������  : F167�����ܱ����õ���Ϣ
                          CMD_AFN_C_F167_METR_BUY_USE
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf167(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0cf167   *psMtAfn0cf167   = (sMtAfn0cf167 *)psUser;
    sMtAfn0cf167_f *psMtAfn0cf167_f = (sMtAfn0cf167_f *)psFrame;
    eMtErr eRet = MT_OK;

    eRet = emt_trans_YYMMDDhhmm(eTrans,&(psMtAfn0cf167->sTime),&(psMtAfn0cf167_f->sTime));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_YYMMDDhhmm is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXX(eTrans,&(psMtAfn0cf167->usBuyTimes),&(psMtAfn0cf167_f->sBuyTimes));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XXXX(eTrans,&(psMtAfn0cf167->dCashLeft),&(psMtAfn0cf167_f->sCashLeft));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XXXX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XXXX(eTrans,&(psMtAfn0cf167->dCashTotal),&(psMtAfn0cf167_f->sCashTotal));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XXXX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecFault),&(psMtAfn0cf167_f->sElecFault));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }
    
    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecLeft),&(psMtAfn0cf167_f->sElecLeft));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecLimit),&(psMtAfn0cf167_f->sElecLimit));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecOut),&(psMtAfn0cf167_f->sElecOut));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecTotal),&(psMtAfn0cf167_f->sElecTotal));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }

    eRet = emt_trans_XXXXXX_XX(eTrans,&(psMtAfn0cf167->dElecWarn),&(psMtAfn0cf167_f->sElecWarn));
    if ( MT_OK != eRet )
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf167() emt_trans_XXXXXX_XX is %d",eRet);
        #endif
        return eRet;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf167_f);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf168
 ��������  : F168�����ܱ������Ϣ
                          CMD_AFN_C_F168_METR_BALANCE
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf168(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf168() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf168_f  *psMtAfn0cf168_f = (sMtAfn0cf168_f *)psFrame;
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf168() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0cf168_f) + (psMtAfn0cf168_f->usRateM + 2) * sizeof(sMtFmt14);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf169
 ��������  : F169�����г����м�·����Ϣ
                          CMD_AFN_C_F169_READ_ROUTE
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf169(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf169() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    sMtAfn0cf169_f  *psMtAfn0cf169_f = (sMtAfn0cf169_f *)psFrame;
    UINT16  usAddress = 0;
    UINT8   i;
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf169() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ���
    for (i = 0; i < psMtAfn0cf169_f->ucRoutN;i++)
    {
        usAddress += psMtAfn0cf169_f->sRoute[i].m;
    }
    
    *pusfLen = sizeof(sMtAfn0cf169_f) + psMtAfn0cf169_f->ucRoutN * sizeof(sMtRoute) + usAddress * sizeof(sMtFmt12);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0cf170
 ��������  : F170�� ���г���������Ϣ
                          CMD_AFN_C_F170_READ_METER
 �������  : eMtTrans eTrans  
                           void* psUser     
                           void* psFrame    
                           UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0cf170(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{   
    if (!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf170() pointer is null");
        #endif
        return MT_ERR_NULL;
    }
    
    if (MT_TRANS_F2U == eTrans) // ֡�ൽ�û���
    {
        // ��ʱ��������ֻ�������ݳ���
    }else if ( MT_TRANS_U2F == eTrans)  // �û��ൽ���
    {
        // ��ʱ��������ֻ�������ݳ���
    }
    else  
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0cf170() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    // ������֡����ֽڳ��� 
    *pusfLen = sizeof(sMtAfn0cf170_f);
    
     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_td_h
 ��������  : Сʱ����������ʱ�����ݸ�ʽ Td_h
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_td_h(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_td_h() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtTd_h     *psU   = (sMtTd_h*)psUser;
    sMtTd_h_f   *psF   = (sMtTd_h_f*)psFrame;
    UINT8        ucHH  = 0;

    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        ucHH = psF->ucBCD_0 + psF->ucBCD_1 * 10;

        if(ucHH > MT_TD_H_MAX || ucHH < MT_TD_H_MIN)
        {
             #ifdef MT_DBG
             DEBUG("emtTrans_td_h() ucHH () out of range %d", ucHH);
             #endif
             return MT_ERR_OUTRNG;
        }

        psU->ucHH = ucHH;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {     
        if(psU->ucHH > MT_TD_H_MAX || psU->ucHH < MT_TD_H_MIN)
        {
             #ifdef MT_DBG
             DEBUG("emtTrans_td_h() ucHH () out of range %d", psU->ucHH);
             #endif
             return MT_ERR_OUTRNG;
        }
 
        psF->ucBCD_0 = ucmt_get_bcd_0(psU->ucHH);
        psF->ucBCD_1 = ucmt_get_bcd_1(psU->ucHH);
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_td_h() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtTd_h_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_td_c
 ��������  : ����������ʱ�����ݸ�ʽ Td_c
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_td_c(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_td_c() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtTd_c     *psU   = (sMtTd_c*)psUser;
    sMtTd_c_f   *psF   = (sMtTd_c_f*)psFrame;
    eMtErr       eRet  = MT_OK;

    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        psF->ucM = psU->ucM;
        psF->ucN = psU->ucN;
        
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sT), &(psF->sT));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_td_c() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        psU->ucM = psF->ucM;
        psU->ucN = psF->ucN;
        
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sT), &(psF->sT));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_td_c() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_td_c() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtTd_c_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_td_d
 ��������  : �ն���������ʱ��Td_d
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_td_d(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emt_trans_YYMMDD(eTrans, (sMtYYMMDD*)psUser, (sMtYYMMDD_f*)psFrame);
    *pusfLen = sizeof(sMtTd_d_f);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_td_m
 ��������  : ���¶���������ʱ��Td_m
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_td_m(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emt_trans_YYMM(eTrans, (sMtYYMM*)psUser, (sMtYYMM_f*)psFrame);
    *pusfLen = sizeof(sMtTd_m_f);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df1
 ��������  : F1���ն���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df1(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df1() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF1     *psU      = (sMtAfn0dF1*)psUser;
    sMtAfn0dF1_f   *psF      = (sMtAfn0dF1_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt14_f    *psFmt14_f = NULL;
    sMtFmt11_f    *psFmt11_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dFrthHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dFrthHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dFrthNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);
        
        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dFrthHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dFrthHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dFrthNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df1() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df1() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df2
 ��������  : F2���ն��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df2(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df2() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF2     *psU      = (sMtAfn0dF2*)psUser;
    sMtAfn0dF2_f   *psF      = (sMtAfn0dF2_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt14_f    *psFmt14_f = NULL;
    sMtFmt11_f    *psFmt11_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dBackHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dBackHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dBackNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dBackNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP2T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dNonePowerP2
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP3T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dNonePowerP3
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);
        
        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dBackHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dBackHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dBackNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dBackNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP2T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dNonePowerP2
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP3T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dNonePowerP3
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df2() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df2() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df3
 ��������  : F3���ն���������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df3(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df3() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF3     *psU      = (sMtAfn0dF3*)psUser;
    sMtAfn0dF3_f   *psF      = (sMtAfn0dF3_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt23_f    *psFmt23_f = NULL;
    sMtFmt17_f    *psFmt17_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fFrthHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fFrthHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fFrthNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fFrthHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fFrthHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fFrthNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df3() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df3() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df4
 ��������  : F4���ն��ᷴ����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df4(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df4() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF4     *psU      = (sMtAfn0dF4*)psUser;
    sMtAfn0dF4_f   *psF      = (sMtAfn0dF4_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt23_f    *psFmt23_f = NULL;
    sMtFmt17_f    *psFmt17_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fBackHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fBackHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fBackNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fBackHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fBackHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fBackNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df4() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df4() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df5
 ��������  : F5���ն��������й����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df5(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df5() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF5     *psU      = (sMtAfn0dF5*)psUser;
    sMtAfn0dF5_f   *psF      = (sMtAfn0dF5_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthHaveT
        psFmt13_f = &(psF->dFrthHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df5() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthHaveT
        psFmt13_f = &(psF->dFrthHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df5() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df5() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df5() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df6
 ��������  : F6���ն��������޹����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df6(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df6() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF6     *psU      = (sMtAfn0dF6*)psUser;
    sMtAfn0dF6_f   *psF      = (sMtAfn0dF6_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthNoneT
        psFmt13_f = &(psF->dFrthNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df6() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthNoneT
        psFmt13_f = &(psF->dFrthNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df6() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df6() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df6() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtTrans_afn0df7
 ��������  : F7���ն��ᷴ���й����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df7(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df7() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF7     *psU      = (sMtAfn0dF7*)psUser;
    sMtAfn0dF7_f   *psF      = (sMtAfn0dF7_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackHaveT
        psFmt13_f = &(psF->dBackHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df7() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackHaveT
        psFmt13_f = &(psF->dBackHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df7() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df7() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df7() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df8
 ��������  : F8���ն��ᷴ���޹����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df8(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df8() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF8     *psU      = (sMtAfn0dF8*)psUser;
    sMtAfn0dF8_f   *psF      = (sMtAfn0dF8_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackNoneT
        psFmt13_f = &(psF->dBackNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df8() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_d(eTrans, &(psU->sTd_d), &(psF->sTd_d), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackNoneT
        psFmt13_f = &(psF->dBackNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df8() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df8() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df8() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df9
 ��������  : F9�������ն���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��2�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df9(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emtTrans_afn0df1(eTrans, psUser, psFrame, pusfLen);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df10
 ��������  : F10�������ն��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��2�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df10(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emtTrans_afn0df2(eTrans, psUser, psFrame, pusfLen);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df11
 ��������  : F11�������ն�����ܱ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��2�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df11(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emtTrans_afn0df3(eTrans, psUser, psFrame, pusfLen);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df12
 ��������  : F12�������ն�����ܱ�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��2�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df12(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    eMtErr eRet = MT_OK;
    eRet =  emtTrans_afn0df4(eTrans, psUser, psFrame, pusfLen);
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df17
 ��������  : F17���¶���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df17(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df17() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF17    *psU       = (sMtAfn0dF17*)psUser;
    sMtAfn0dF17_f  *psF       = (sMtAfn0dF17_f*)psFrame;
    eMtErr         eRet       = MT_OK;
    UINT8          ucM        = 0;
    UINT16         usLen      = 0;
    UINT16         usTmp      = 0;
    INT32          i          = 0;
    UINT8          *pTmp      = NULL;
    sMtFmt14_f    *psFmt14_f  = NULL;
    sMtFmt11_f    *psFmt11_f  = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_d
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dFrthHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dFrthHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dFrthNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // sTd_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);
        
        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dFrthHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dFrthHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dFrthHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dFrthNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dFrthNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP1[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP1T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dFrthNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP4[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df17() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df17() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df18
 ��������  : F18���¶��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��29�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df18(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df18() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF18    *psU      = (sMtAfn0dF18*)psUser;
    sMtAfn0dF18_f  *psF      = (sMtAfn0dF18_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt14_f    *psFmt14_f = NULL;
    sMtFmt11_f    *psFmt11_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dBackHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dBackHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dBackNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dBackNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP2T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dNonePowerP2
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP3T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dNonePowerP3
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emtTrans_td_d() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);
        
        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // psFmt14_f
        pTmp      = (UINT8*)(psF->ucPower);
        psFmt14_f = (sMtFmt14_f*)pTmp;

        // dBackHavePowerT
        eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePowerT), psFmt14_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt14_f);
        
        // dBackHavePower
        for(i = 0; i < ucM; i++)
        {
            psFmt14_f = (sMtFmt14_f*)(pTmp + (i+1)*sizeof(sMtFmt14_f));
            eRet = emt_trans_XXXXXX_XXXX(eTrans, &(psU->dBackHavePower[i]), psFmt14_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt14_f) * ucM;

        // dBackNonePowerT
        pTmp      = (UINT8 *)(psFmt14_f + 1);
        psFmt11_f = (sMtFmt11_f*)pTmp;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePowerT), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dBackNonePower
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dBackNonePower[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP2T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

         usLen += sizeof(sMtFmt11_f);

        // dNonePowerP2
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP2[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;

        // dNonePowerP3T
        psFmt11_f += 1;
        eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3T), psFmt11_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt11_f);

        // dNonePowerP3
        for(i = 0; i < ucM; i++)
        {
            psFmt11_f = (sMtFmt11_f*)(pTmp + (i+1)*sizeof(sMtFmt11_f));
            eRet = emt_trans_XXXXXX_XX(eTrans, &(psU->dNonePowerP3[i]), psFmt11_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df18() emt_trans_XXXXXX_XX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt11_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df18() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df19
 ��������  : F3���ն���������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df19(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df19() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF19    *psU      = (sMtAfn0dF19*)psUser;
    sMtAfn0dF19_f  *psF      = (sMtAfn0dF19_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt23_f    *psFmt23_f = NULL;
    sMtFmt17_f    *psFmt17_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fFrthHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fFrthHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fFrthNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_d
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fFrthHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fFrthHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fFrthNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fFrthNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeFrthNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeFrthNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeFrthNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df19() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df19() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df20
 ��������  : F20���¶��ᷴ����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df20(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df20() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF20     *psU      = (sMtAfn0dF20*)psUser;
    sMtAfn0dF20_f   *psF      = (sMtAfn0dF20_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    UINT8          *pTmp     = NULL;
    sMtFmt23_f    *psFmt23_f = NULL;
    sMtFmt17_f    *psFmt17_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fBackHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fBackHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fBackNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;
        
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // fBackHaveT
        pTmp      = (UINT8*)(psF->ucDemand);
        psFmt23_f = (sMtFmt23_f*)pTmp;

        // fBackHaveT
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHaveT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackHave[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackHaveT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHaveT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackHave
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackHave[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;

        // fBackNoneT
        psFmt17_f += 1;
        psFmt23_f = (sMtFmt23_f*)psFmt17_f;
        eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNoneT), psFmt23_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt23_f);
        
        // fBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt23_f = (sMtFmt23_f*)(pTmp + (i+1) * sizeof(sMtFmt23_f));
            eRet = emt_trans_XX_XXXX(eTrans, &(psU->fBackNone[i]), psFmt23_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_XX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt23_f) * ucM;

        // sTimeBackNoneT
        pTmp      = (UINT8 *)(psFmt23_f + 1);
        psFmt17_f = (sMtFmt17_f*)pTmp;
        eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNoneT), psFmt17_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt17_f);

        // sTimeBackNone
        for(i = 0; i < ucM; i++)
        {
            psFmt17_f = (sMtFmt17_f*)(pTmp + (i+1)*sizeof(sMtFmt17_f));
            eRet = emt_trans_MMDDHHmm(eTrans, &(psU->sTimeBackNone[i]), psFmt17_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df20() emt_trans_MMDDHHmm() error %d", eRet);
                #endif
                return eRet;
            }
        }
        
        usLen += sizeof(sMtFmt17_f) * ucM;      
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df20() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df21
 ��������  : F21���¶��������й����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df21(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df21() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF21    *psU      = (sMtAfn0dF21*)psUser;
    sMtAfn0dF21_f  *psF      = (sMtAfn0dF21_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthHaveT
        psFmt13_f = &(psF->dFrthHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df21() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthHaveT
        psFmt13_f = &(psF->dFrthHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df21() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df21() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df21() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df22
 ��������  : F6���ն��������޹����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df22(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df22() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF22    *psU      = (sMtAfn0dF22*)psUser;
    sMtAfn0dF22_f  *psF      = (sMtAfn0dF22_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthNoneT
        psFmt13_f = &(psF->dFrthNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df22() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dFrthNoneT
        psFmt13_f = &(psF->dFrthNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df22() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dFrthNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dFrthNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df22() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df22() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df23
 ��������  : F7���ն��ᷴ���й����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df23(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df23() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF23     *psU     = (sMtAfn0dF23*)psUser;
    sMtAfn0dF23_f   *psF     = (sMtAfn0dF23_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackHaveT
        psFmt13_f = &(psF->dBackHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df23() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackHaveT
        psFmt13_f = &(psF->dBackHaveT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHaveT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df23() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackHave
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackHave[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df23() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df23() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df24
 ��������  : F24���¶��ᷴ���޹����������ܡ�����1��M��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��30�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df24(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    if(!psUser || !psFrame || !pusfLen)
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df24() pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    sMtAfn0dF24    *psU      = (sMtAfn0dF24*)psUser;
    sMtAfn0dF24_f  *psF      = (sMtAfn0dF24_f*)psFrame;
    eMtErr         eRet      = MT_OK;
    UINT8          ucM       = 0;
    UINT16         usLen     = 0;
    UINT16         usTmp     = 0;
    INT32          i         = 0;
    sMtFmt13_f    *psFmt13_f = NULL;
    
    // ֡��תΪ�û���
    if(MT_TRANS_F2U == eTrans)
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psF->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackNoneT
        psFmt13_f = &(psF->dBackNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df24() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;
    }
    else if(MT_TRANS_U2F == eTrans)
    // �û���תΪ֡��
    {
        // Td_m
        eRet = emtTrans_td_m(eTrans, &(psU->sTd_m), &(psF->sTd_m), &usTmp);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emtTrans_td_m() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmp;

        // sTime
        eRet = emt_trans_YYMMDDhhmm(eTrans, &(psU->sTime), &(psF->sTime));
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emt_trans_YYMMDDhhmm() error %d", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sMtFmt15_f);

        // M
        ucM = psU->ucM;
        if(ucM < MT_M_MIN || ucM > MT_M_MAX)
        {
            #ifdef MT_DBG
            DEBUG("ucM out of range %d", ucM);
            #endif
            return MT_ERR_OUTRNG;     
        }
        
        usLen += 1;

        // dBackNoneT
        psFmt13_f = &(psF->dBackNoneT);

        eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNoneT), psFmt13_f);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtTrans_afn0df24() emt_trans_XXXX_XXXX() error %d", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sMtFmt13_f);
        
        // dBackNone
        for(i = 0; i < ucM; i++)
        {
            ++psFmt13_f;
            eRet = emt_trans_XXXX_XXXX(eTrans, &(psU->dBackNone[i]), psFmt13_f);
            if(MT_OK != eRet)
            {
                #ifdef MT_DBG
                DEBUG("emtTrans_afn0df24() emt_trans_XXXX_XXXX() error %d", eRet);
                #endif
                return eRet;
            }
        }

        usLen += sizeof(sMtFmt13_f) * ucM;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emtTrans_afn0df24() para error!");
        #endif
        return MT_ERR_PARA;
    }

    // ������֡����ֽڳ���
    *pusfLen = usLen;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df25
 ��������  : F25���ն������ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df25(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF25_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df26
 ��������  : F26���ն������ܼ������������������ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df26(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF26_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df27
 ��������  : F27���ն����յ�ѹͳ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df27(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF27_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df28
 ��������  : F28���ն����ղ�ƽ���Խ���ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df28(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF28_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df29
 ��������  : F29���ն����յ���Խ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df29(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{ 
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF29_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df30
 ��������  : F30���ն��������ڹ���Խ���ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df30(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF30_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df31
 ��������  : F31���ո�����ͳ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df31(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF31_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df32
 ��������  : F32���ն�����ܱ��������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df32(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF32_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df32
 ��������  : F33���¶������ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df33(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF33_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df34
 ��������  : F34���¶������ܼ������й��������������ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df34(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF34_f);
    return MT_OK;
}   

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df35
 ��������  : F35���¶����µ�ѹͳ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df35(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF35_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df36
 ��������  : F36���¶����²�ƽ���Խ���ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df36(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF36_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df37
 ��������  : F37���¶����µ���Խ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df37(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF37_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df38
 ��������  : F38���¶��������ڹ���Խ���ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df38(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF38_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df39
 ��������  : F39���¸�����ͳ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df39(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF39_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df41
 ��������  : F41���ն���������ۼ�Ͷ��ʱ��ʹ���
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df41(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF41_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df42
 ��������  : F42���ն����ա��µ������ۼƲ������޹�������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df42(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF42_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df43
 ��������  : F43���ն����չ������������ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df43(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF43_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtTrans_afn0df44
 ��������  : F44���¶����¹������������ۼ�ʱ��
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��9��10�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtTrans_afn0df44(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen)
{
    // ������֡����ֽڳ���
    *pusfLen = sizeof(sMtAfn0dF44_f);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtGetGroupNum
 ��������  :  �����ܼ�����Ч��־λ��ȡ�ܼ������
 �������  : eMtTrans eTrans  
             void* psUser     
             void* psFrame    
             UINT16* pusfLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��20�� ���ڶ�
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 emtGetGroupNum(UINT8 ucGroupFlag)
{
    UINT8 ucRet = 0;
    UINT8 i;

    for ( i = 0; i < 8; i ++)
    {
        if( ucGroupFlag & (1 << i))
        {
            ucRet++;
        }
    }

    return ucRet;
}

/*****************************************************************************
 �� �� ��  : ucmt_get_bcd_0
 ��������  : ���һ��char�������ݵ�BCD��λ
 �������  : UINT8 ucData  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_bcd_0(UINT8 ucData)
{
    return (ucData % 10);
}

/*****************************************************************************
 �� �� ��  : ucmt_get_bcd_1
 ��������  : ���һ��char�������ݵ�BCD��λ
 �������  : UINT8 ucData  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 ucmt_get_bcd_1(UINT8 ucData)
{
    return (ucData / 10);
}

/*****************************************************************************
 �� �� ��  : emt_bcd_to_str
 ��������  : ������Ϊlen��BCD��תΪ2*len�����ַ���
 �������  : const UINT8 *pbcd  
             UINT8 *pstr        
             INT32 len          
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_bcd_to_str(const UINT8* pbcd, UINT8* pstr, INT32 len)
{
    INT32 i  = 0, j  = 0;
    UINT8 c1 = 0, c0 = 0;

    if(!pstr || !pbcd)
    {
        #ifdef MT_DBG
        DEBUG("emt_bcd_to_str() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if(len < 0)
    { 
        #ifdef MT_DBG
        DEBUG("emt_bcd_to_str() para error");
        #endif
        return MT_ERR_PARA;
    }

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
 �� �� ��  : emt_str_to_bcd
 ��������  : ������Ϊlen���ַ���ת��ΪBCD ����Ϊ len/2
 �������  : const UINT8 *pstr  
             UINT8  *pbcd        
             INT32   len           
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_str_to_bcd(const UINT8* pstr, UINT8* pbcd, INT32 len)
{

    UINT8 tmpValue;
    INT32 i;
    INT32 j;
    INT32 m;
    INT32 sLen;
 
    if(!pstr || !pbcd)
    {
        #ifdef MT_DBG
        DEBUG("emt_str_to_bcd() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if(len < 0)
    { 
         #ifdef MT_DBG
         DEBUG("emt_str_to_bcd() para error");
         #endif
         return MT_ERR_PARA;
    }

    sLen = len;
    
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

    sLen = ((sLen <= (len * 2) ) ?  sLen : sLen * 2);
    memset((void *)pbcd, 0x00, len);

    for(i = sLen-1, j = 0, m = 0; (i>=0) && (m<len); i--, j++)
    {
        if((pstr[i] >= '0') && (pstr[i] <= '9'))
        {
            tmpValue = pstr[i] - '0';
        }
        else if((pstr[i] >= 'A') && (pstr[i] <= 'F'))
        {
            tmpValue = (pstr[i] - 'A' + 0x0A);
        }
        else if((pstr[i] >= 'a') && (pstr[i] <= 'f'))
        {
            tmpValue = (pstr[i] - 'a' + 0x0A);
        }
        else
        {
            tmpValue = 0;
        }

        if((j%2) == 0)
        {
            pbcd[m] = tmpValue;  
        }
        else
        {
            pbcd[m++] |= (tmpValue << 4);
        }

        if((tmpValue == 0) && (pstr[i] != '0'))
        {
            break;
        }
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : bmt_big_endian
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
BOOL   bmt_big_endian()
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
eMtErr emt_write_uint16_small_endian(UINT16 usData, UINT8* pWrite)
{
    UINT8 ucByteHi = 0, ucByteLo = 0;
    BOOL bBigEndian = FALSE; 

    if(!pWrite)
    {
        #ifdef MT_DBG
        DEBUG("emt_write_uint16_small_endian() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    bBigEndian = bmt_big_endian();
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
eMtErr emt_write_uint32_small_endian(UINT32 ulData,   UINT8* pWrite)
{
    UINT8 *pucData;
    BOOL  bBigEndian = FALSE;
    
    if(!pWrite)
    {
        #ifdef MT_DBG
        DEBUG("emt_write_uint32_small_endian() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    bBigEndian = bmt_big_endian();
    if(bBigEndian == TRUE)
    {
        pucData    = (UINT8*)pWrite;
        *pucData++ = (UINT8)(ulData  & 0xFF);
        *pucData++ = (UINT8)((ulData & 0xFF00)     >> 8);
        *pucData++ = (UINT8)((ulData & 0xFF0000)   >> 16);
        *pucData++ = (UINT8)((ulData & 0xFF000000) >> 24);
    }
    else
    {
        memcpy((void*)pWrite, (void*)&ulData, sizeof(UINT32));
    }
  
    return MT_OK; 
}

/*****************************************************************************
 �� �� ��  : emt_read_uint16_small_endian
 ��������  : ��С�ֽڷ�ʽ��ȡһ��short
 �������  : UINT8 *pRead     
             UINT16 *pUint16  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_read_uint16_small_endian(UINT8* pRead, UINT16* pUint16)
{
    BOOL bBigEndian = FALSE;
    UINT8 ucData[2];
    UINT16 usRet = 0;

    if(!pRead || !pUint16)
    {
        #ifdef MT_DBG
        DEBUG("emt_read_uint16_small_endian() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    bBigEndian = bmt_big_endian();
    if(bBigEndian == TRUE)
    {
        ucData[1] = *pRead;
        ucData[0] = *(pRead+1);
        usRet     = *(UINT16*)ucData;  
    }
    else
    {
        usRet = *(UINT16*)pRead;
    }

    *pUint16 = usRet;
    return MT_OK;

}

/*****************************************************************************
 �� �� ��  : emt_read_uint32_small_endian
 ��������  : ��ָ����ַλ����С�ֽ���ķ�ʽ����һ��������
 �������  : UINT8 *pRead     
             UINT32* pUint32  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_read_uint32_small_endian(UINT8* pRead, UINT32* pUint32)
{
    UINT8 ucData[4];
    UINT32 ulRet = 0;
    BOOL bBigEndian = FALSE;

    if(!pRead || !pUint32)
    {
        #ifdef MT_DBG
        DEBUG("emt_read_uint32_small_endian() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    bBigEndian = bmt_big_endian();
    if(bBigEndian == TRUE)
    {
        ucData[3] = *(pRead + 0);
        ucData[2] = *(pRead + 1);
        ucData[1] = *(pRead + 2);
        ucData[0] = *(pRead + 3);
        ulRet     = *(UINT32*)ucData;  
    }
    else
    {
        memcpy((void*)&ulRet, (void*)pRead, sizeof(UINT32));
    }

    *pUint32 = ulRet;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_address
 ��������  : ��ַ���û������֡�����ݽṹת������
 �������  : eMtTrans eDir           
             sMtAddress *psAddr_u    
             sMtAddress_f *psAddr_f  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_address(eMtTrans eTrans, sMtAddress* psAddr_u, sMtAddress_f* psAddr_f)
{
    if(!psAddr_u || !psAddr_f)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_address() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(MT_TRANS_U2F == eTrans)
    {
        if(psAddr_u->usTAddress == 0)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_address() terminal address error!");
            #endif  
            return MT_ERR_ADDR;
        }

        if(psAddr_u->ucMAddress > MT_MST_ADDR_MAX ||
        psAddr_u->ucMAddress < MT_MST_ADDR_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_address() masger address error!");
            #endif  
            return MT_ERR_ADDR;
        }

        (void)emt_str_to_bcd((UINT8*)(psAddr_u->acRegionCode), (UINT8*)(psAddr_f->acRegionCode), 4);
        // (void)emt_write_uint16_small_endian(psAddr_u->usTAddress, (UINT8*)&(psAddr_f->usTAddress));
        psAddr_f->usTAddress = psAddr_u->usTAddress;

        psAddr_f->ucMAddress = (psAddr_u->ucMAddress << 1);
        if(psAddr_u->bTeamAddr == TRUE)
        {
            psAddr_f->ucMAddress |= 0x01;
        }
        else
        {
            psAddr_f->ucMAddress &= 0xFE;
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        (void)emt_bcd_to_str((UINT8*)(psAddr_f->acRegionCode), (UINT8*)(psAddr_u->acRegionCode), 2);
        // (void)emt_read_uint16_small_endian((UINT8*)&(psAddr_f->usTAddress), (UINT16*)&(psAddr_u->usTAddress));
        psAddr_u->usTAddress = psAddr_f->usTAddress;
        psAddr_u->bTeamAddr  = (psAddr_f->ucMAddress & 0x01) ? TRUE : FALSE;
        psAddr_u->ucMAddress = (psAddr_f->ucMAddress >> 1) & 0x7F;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_address() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_ctrl
 ��������  : �������û����֡������ת������
 �������  : eMtTrans eDir    
             sMtCtrl *puCtrl  
             UINT8* pfCtrl    
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_ctrl(eMtTrans eTrans, sMtCtrl* puCtrl, UINT8* pfCtrl)
{
    UINT8 ucfCtrl = 0;

    // �û���ת��Ϊ֡��
    if(MT_TRANS_U2F == eTrans)      
    {
        (puCtrl->eDir == MT_DIR_M2S)  ? (ucfCtrl &= 0x7F) : (ucfCtrl |= 0x80);
        (puCtrl->ePRM == MT_PRM_ACTIVE) ? (ucfCtrl |= 0x40) : (ucfCtrl &= 0xBF);

        if(puCtrl->eDir == MT_DIR_M2S)
        { 
            //���б��� 
            (puCtrl->bFcv     == TRUE) ? (ucfCtrl |= 0x10) : (ucfCtrl &= 0xEF);
            (puCtrl->bAcd_Fcb == TRUE) ? (ucfCtrl |= 0x10) : (ucfCtrl &= 0xEF);
        }
        else
        {
            // ���б���
            (puCtrl->bAcd_Fcb == TRUE) ? (ucfCtrl |= 0x20) : (ucfCtrl &= 0xDF);
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
    // ֡��ת��Ϊ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        ucfCtrl = * pfCtrl;
        if(ucfCtrl & 0x80)
        {
            // ����
            puCtrl->eDir = MT_DIR_S2M;  
            puCtrl->bAcd_Fcb = (ucfCtrl & 0x20) ? TRUE : FALSE;
        }
        else
        {   
            // ����
            puCtrl->eDir     = MT_DIR_M2S; 
            puCtrl->bAcd_Fcb = (ucfCtrl & 0x20) ? TRUE : FALSE;
            puCtrl->bFcv     = (ucfCtrl & 0x10) ? TRUE : FALSE;
        }

        puCtrl->ePRM = (ucfCtrl & 0x40) ? MT_PRM_ACTIVE : MT_PRM_PASIVE;
        puCtrl->uFCode.eFcdPrm0 = (eMtFcodeRpm0)(ucfCtrl & 0x0F);
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_ctrl() para error!");
        #endif
        return MT_ERR_PARA;
    }
    
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_get_ctrl
 ��������  : ��ÿ������û�����Ϣ
 �������  : eMtAFN eAFN      
             eMtDir eDir      
             eMtPRM ePRM 
             BOOL bAcd_Fcb
             sMtCtrl *psCtrl  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��7�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_get_ctrl(eMtAFN eAFN, eMtDir eDir, eMtPRM ePRM, BOOL bAcd_Fcb, sMtCtrl *psCtrl)
{
    if(!psCtrl)
    {
        #ifdef MT_DBG
        DEBUG("emt_get_ctrl() para pointer is null");
        #endif
        return MT_ERR_NULL;
    }

    if(MT_DIR_M2S != eDir && MT_DIR_S2M != eDir)
    {
        #ifdef MT_DBG
        DEBUG("emt_get_ctrl() eDir para error");
        #endif
        return MT_ERR_PARA;
    }

    if(MT_PRM_ACTIVE != ePRM && MT_PRM_PASIVE != ePRM)
    {
        #ifdef MT_DBG
        DEBUG("emt_get_ctrl() ePRM para error");
        #endif
        return MT_ERR_PARA;
    }

    psCtrl->eDir = eDir;
    psCtrl->ePRM = ePRM;

    switch(eAFN)
    {
        case AFN_00_CONF:

             if(ePRM == MT_PRM_PASIVE) //  ȷ�Ϸ��ϱ���ֻ�ܴӶ�վ����
             {
                  psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_OK; 
             }
             else
             {
                #ifdef MT_DBG
                DEBUG("emt_get_ctrl() pack logic error");
                #endif
                return MT_ERR_LOGIC;
             }
            
             if(eDir == MT_DIR_M2S)   // ����
             {
                psCtrl->bFcv = TRUE; 
                psCtrl->bAcd_Fcb = bAcd_Fcb; 
             }
             else                     // ����
             {
                 psCtrl->bFcv = FALSE; 
                 psCtrl->bAcd_Fcb = TRUE;
             }

            break; 
            
        case AFN_01_RSET:
            
             if(MT_DIR_M2S == eDir && ePRM == MT_PRM_ACTIVE)   // ����
             {
                /*
                ��֡������ЧλFCV=1ʱ��FCB��ʾÿ��վ�����ķ���/ȷ�ϻ�������/��Ӧ����ı仯λ��
                FCBλ������ֹ��Ϣ����Ķ�ʧ���ظ���
                ����վ��ͬһ�Ӷ�վ�����µķ���/ȷ�ϻ�����/��Ӧ�������ʱ��
                ��FCBȡ�෴ֵ������վ����ÿһ���Ӷ�վFCBֵ������ʱδ�յ��Ӷ�վ�ı���,
                ����ճ��ֲ��������վ���ı�FCB��״̬���ظ�ԭ���ķ���/ȷ�ϻ�������/��Ӧ����
                ��λ�����е�FCB=0���Ӷ�վ���ո�λ�����FCB��"0"��
                */
                psCtrl->bFcv            = TRUE; 
                psCtrl->bAcd_Fcb        = FALSE; 
                psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_RESET; 
             }
             else                    // ����
             {
                #ifdef MT_DBG
                DEBUG("emt_get_ctrl() pack logic error");
                #endif
                return MT_ERR_LOGIC;
             }

            break;
            
        case AFN_02_LINK:
            
             if(MT_DIR_S2M == eDir && MT_PRM_ACTIVE == ePRM)    // ������ֻ�����е�����
             {
                 psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_LINK; 
                 psCtrl->bFcv     = FALSE;   
                 psCtrl->bAcd_Fcb = FALSE;
             }
             else                   
             {
                #ifdef MT_DBG
                DEBUG("emt_get_ctrl() pack logic error");
                #endif
                return MT_ERR_LOGIC;
             }

            break;
            
        case AFN_03_RELY:

            if(MT_DIR_M2S == eDir)  
            {
               if(MT_PRM_ACTIVE == ePRM)
               {
                   psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
                   psCtrl->bFcv     = TRUE;   
                   psCtrl->bAcd_Fcb = bAcd_Fcb;
               }
               else                    
               {
                  #ifdef MT_DBG
                  DEBUG("emt_get_ctrl() pack logic error");
                  #endif
                  return MT_ERR_LOGIC;                
               }
            }
            else 
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                    // �ñ���û��EC
                    psCtrl->bFcv     = FALSE;   
                    psCtrl->bAcd_Fcb = FALSE;
                }
                else                    
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC;                
                }
            }
           
            break;

        case AFN_04_SETP:
            
             if(MT_DIR_M2S == eDir && MT_PRM_ACTIVE == ePRM)   // ֻ����������  
             {     
                psCtrl->bFcv            = TRUE; 
                psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
             }
             else                     
             {
                #ifdef MT_DBG
                DEBUG("emt_get_ctrl() pack logic error");
                #endif
                return MT_ERR_LOGIC;   
             }

            break;

        case AFN_05_CTRL:

            if(eDir == MT_DIR_M2S && ePRM == MT_PRM_ACTIVE)   // ֻ����������  
             {

                psCtrl->bFcv            = TRUE; 
                psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
             }
             else                     // ����
             {
                #ifdef MT_DBG
                DEBUG("emt_get_ctrl() pack logic error");
                #endif
                return MT_ERR_LOGIC;   
             }

            break;
            
        case AFN_06_AUTH:

            if(eDir == MT_DIR_M2S)    // ����
            {              
                psCtrl->bFcv            = TRUE; 
                psCtrl->bAcd_Fcb        = bAcd_Fcb; 
            }
            else                      // ����
            {
                psCtrl->bFcv            = FALSE; 
                psCtrl->bAcd_Fcb        = TRUE; 
            }
             
            if(ePRM == MT_PRM_ACTIVE)  //����վ
            {
                psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER;
            }
            else                       //�Ӷ�վ
            {
                psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER;
            }
             
            break;
            
        case AFN_08_CASC:
            
            if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
               if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = FALSE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }

            break;
           
        case AFN_09_CFIG:
            
             if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
               if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;
            
        case AFN_0A_GETP:

            if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
               if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;

        case AFN_0B_ASKT:
        
           if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
               if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = FALSE;
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;
            
        case AFN_0C_ASK1:
        
           if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_1; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
               if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;
            
        case AFN_0D_ASK2:
        
            if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_2; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;
            
        case AFN_0E_ASK3:

            if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_2; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break; if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_2; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
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
            
           if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_2; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break; if(MT_DIR_M2S == eDir)   // ����
            {
                if(MT_PRM_ACTIVE == ePRM)
                {
                    psCtrl->bFcv            = TRUE; 
                    psCtrl->bAcd_Fcb        = bAcd_Fcb; 
                    psCtrl->uFCode.eFcdPrm1 = MT_FCD_RPM1_ASK_2; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                }            
            }
            else                   
            {
                if(MT_PRM_PASIVE == ePRM)
                {
                    psCtrl->bFcv            = FALSE; 
                    psCtrl->bAcd_Fcb        = TRUE; 
                    psCtrl->uFCode.eFcdPrm0 = MT_FCD_RPM0_USER; 
                }
                else
                {
                    #ifdef MT_DBG
                    DEBUG("emt_get_ctrl() pack logic error");
                    #endif
                    return MT_ERR_LOGIC; 
                } 
            }
            
            break;

        default:
            return MT_ERR_PARA;
            //break;

    }
    
    return MT_OK;
}
/*****************************************************************************
 �� �� ��  : emt_trans_seq
 ��������  : ��SEQ�ֶδ��û��ൽ֡��ת������
 �������  : eMtTrans eTrans  
             sMtSEQ *puSEQ    
             sMtSEQ_f *pfSEQ  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_seq(eMtTrans eTrans, sMtSEQ *puSEQ, sMtSEQ_f *pfSEQ)
{
    if(!puSEQ || !pfSEQ)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_seq() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(MT_TRANS_F2U == eTrans)
    {
        puSEQ->bTpv  = (pfSEQ->TPV == 1) ? TRUE : FALSE;
        puSEQ->bCon  = (pfSEQ->CON == 1) ? TRUE : FALSE;
        puSEQ->ucSeq = pfSEQ->SEQ;

        if(pfSEQ->FIR == 1)
        {
            puSEQ->ePos = (pfSEQ->FIN == 1) ? MT_POS_SIGLE : MT_POS_MUL_S;  
        }
        else
        {
            puSEQ->ePos = (pfSEQ->FIN == 1) ? MT_POS_MUL_E : MT_POS_MUL_M;
        }        
    }
    else if(MT_TRANS_U2F == eTrans)
    {
        pfSEQ->TPV = (puSEQ->bTpv == TRUE) ? 1 : 0;
        pfSEQ->CON = (puSEQ->bCon == TRUE) ? 1 : 0;
        pfSEQ->SEQ =  puSEQ->ucSeq & 0x0F;

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
                #ifdef MT_DBG
                DEBUG("emt_trans_seq() para error!");
                #endif
                return MT_ERR_PARA;
                //break;
        }
    }
    else
    {
         #ifdef MT_DBG
         DEBUG("emt_trans_seq() para error!");
         #endif
         return MT_ERR_PARA;
    }
    
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_tp
 ��������  : TP���ݽṹת������
 �������  : eMtTrans eTrans  
             sMtTP* pTP_u     
             sMtTP_f* pTP_f   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_tp(eMtTrans eTrans, sMtTP* pTP_u, sMtTP_f* pTP_f)
{
    if(!pTP_u || !pTP_f)
    {
         #ifdef MT_DBG
         DEBUG("emt_trans_tp() para pointer is null!");
         #endif
         return MT_ERR_NULL;
    }

    if(MT_TRANS_U2F == eTrans)
    {   
        pTP_f->ucPFC = pTP_u->ucPFC;
        pTP_f->ucPermitDelayMinutes = pTP_u->ucPermitDelayMinutes;
        emt_trans_DDHHmmss(MT_TRANS_U2F, &(pTP_u->sDDHHmmss), &(pTP_f->sDDHHmmss));
    }
    else if(MT_TRANS_F2U == eTrans)
        {
        pTP_u->ucPFC = pTP_f->ucPFC;
        pTP_u->ucPermitDelayMinutes = pTP_f->ucPermitDelayMinutes;
        emt_trans_DDHHmmss(MT_TRANS_F2U, &(pTP_u->sDDHHmmss), &(pTP_f->sDDHHmmss));
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_tp() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : usmt_get_aux_len
 ��������  : ��õ�ǰ���͵ı����и���������ֳ�(ec pw tp)
 �������  : eMtAFN eAFN  
             eMtDir eDir  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT16 usmt_get_aux_len(eMtAFN eAFN, eMtDir eDir, BOOL bEc, BOOL bTp)
{
    UINT16 usAuxLen = 0;

    BOOL   bPw = FALSE;

    bPw = bmt_have_pw(eAFN, eDir);
  
    if(TRUE == bEc)
    {
        usAuxLen += sizeof(sMtEC);
    }
    
    if(TRUE == bPw)
    {
        usAuxLen += MT_PW_LEN;
    }

    if(TRUE == bTp)
    {
        usAuxLen += sizeof(sMtTP_f);
    }

    return usAuxLen;
}  
/*****************************************************************************
 �� �� ��  : emt_get_tp
 ��������  : ��õ�ǰ��ʱ���
 �������  : UINT8 ucPFC   
             sMtTP *psuTp  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��7�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_get_tp(UINT8 ucPFC, sMtTP *psuTp)
{
    if(!psuTp)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_tp() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    // ��ȡϵͳ��ǰʱ��
    time_t now;
    struct tm* timenow;
    time(&now);
    timenow = localtime(&now);
    
    psuTp->sDDHHmmss.ucDD = timenow->tm_mday;
    psuTp->sDDHHmmss.ucHH = timenow->tm_hour;
    psuTp->sDDHHmmss.ucmm = timenow->tm_min;
    psuTp->sDDHHmmss.ucss = timenow->tm_sec;

    psuTp->ucPermitDelayMinutes = g_ucMtPermitDelayMinutes;
    psuTp->ucPFC = ucPFC;

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : bmt_tp_timeout
 ��������  : �Ե�ǰʱ��Ϊ��׼�ж�һ��tp�Ƿ�ʱ
 �������  : sMtTP *psTP  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL  bmt_tp_timeout(sMtTP *psTP)
{
    if(!psTP)
    {
        return TRUE;
    }

    time_t now;
    struct tm* timenow;
    UINT8 ucDelayMinutes;  // ���ʹ�����ʱʱ��
    // ��ȡϵͳ��ǰʱ��
    time(&now);
    timenow = localtime(&now);
    int cDay  = 0;
    int cHour = 0;
    int cMin  = 0;
    int cSec  = 0;

    int rDay  = 0;
    int rHour = 0;
    int rMin  = 0;
    int rSec  = 0;
    
    int minutes = 0;  // ��ص�����
    
    cDay = timenow->tm_mday;
    cHour = timenow->tm_hour;
    cMin = timenow->tm_min;
    cSec = timenow->tm_sec;

    rDay  = psTP->sDDHHmmss.ucDD;
    rHour = psTP->sDDHHmmss.ucHH;
    rMin = psTP->sDDHHmmss.ucmm;
    rSec = psTP->sDDHHmmss.ucss;
    ucDelayMinutes = psTP->ucPermitDelayMinutes;
    minutes = (cDay - rDay)*60*24 + (cHour - rHour)*60 + (cMin - rMin) * 1; 

    if(minutes < 0)
    {
        return TRUE;
    }

    if(minutes <= ucDelayMinutes)
    {
        return FALSE;
    }
     
    return TRUE;
}    

/*****************************************************************************
 �� �� ��  : nMtPow
 ��������  : ��10��N�η� (ע�������Ҫ����10)
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
int  nMtPow(UINT8 exp)
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

/*****************************************************************************
 �� �� ��  : emt_trans_YYWWMMDDhhmmss
 ��������  : ���ݸ�ʽ01 ���ڱ�A.1 ��ʽ 
 �������  : eMtTrans eTrans      
             sMtUserClock* psUser        
             sMtFrmClock* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_YYWWMMDDhhmmss(eMtTrans eTrans, sMtUserClock* psUser, sMtFrmClock* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYWWMMDDhhmmss() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if (MT_TRANS_F2U == eTrans )  // ֡�ൽ�û���
    {
        psUser->ucYear    = psFrame->bcd_yea_0 + psFrame->bcd_yea_1 * 10;
        psUser->ucWeek    = psFrame->bcd_wek_0;
        psUser->ucMonth   = psFrame->bcd_mon_0 + psFrame->bcd_mon_1 * 10;
        psUser->ucDay     = psFrame->bcd_day_0 + psFrame->bcd_day_1 * 10;
        psUser->ucHour    = psFrame->bcd_hur_0 + psFrame->bcd_hur_1 * 10;
        psUser->ucMinute  = psFrame->bcd_min_0 + psFrame->bcd_min_1 * 10;
        psUser->ucSecond  = psFrame->bcd_sec_0 + psFrame->bcd_sec_1 * 10;
    }
     else if (MT_TRANS_U2F == eTrans) // �û��ൽ֡��
    { 
        // ��
        psFrame->bcd_yea_0 = ucmt_get_bcd_0(psUser->ucYear);
        psFrame->bcd_yea_1 = ucmt_get_bcd_1(psUser->ucYear);

        // ��
        if (psUser->ucMonth > 12)
        {
             #ifdef MT_DBG
             DEBUG("emt_trans_YYWWMMDDhhmmss() ucMonth MT_ERR_OUTRNG!");
             #endif
             return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_mon_0 = ucmt_get_bcd_0(psUser->ucMonth);
            psFrame->bcd_mon_1 = ucmt_get_bcd_1(psUser->ucMonth);
        }

        // ����
        if (psUser->ucWeek > 7)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYWWMMDDhhmmss() ucWeek MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_wek_0 = psUser->ucWeek;
        }

        // ��
        if (psUser->ucDay > 31)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYWWMMDDhhmmss() ucDay MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_day_0 = ucmt_get_bcd_0(psUser->ucDay);
            psFrame->bcd_day_1 = ucmt_get_bcd_1(psUser->ucDay);
        }

        // ʱ
        if(psUser->ucHour > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYWWMMDDhhmmss() ucHour MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_hur_0 = ucmt_get_bcd_0(psUser->ucHour);
            psFrame->bcd_hur_1 = ucmt_get_bcd_1(psUser->ucHour);
        }

        // ��
        if(psUser->ucMinute > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYWWMMDDhhmmss() ucMinute MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_min_0 = ucmt_get_bcd_0(psUser->ucMinute);
            psFrame->bcd_min_1 = ucmt_get_bcd_1(psUser->ucMinute);
        }

        // ��
        if(psUser->ucSecond > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYWWMMDDhhmmss() ucSencond MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_sec_0 = ucmt_get_bcd_0(psUser->ucSecond);
            psFrame->bcd_sec_1 = ucmt_get_bcd_1(psUser->ucSecond);
        }
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYWWMMDDhhmmss() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK; 
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXXX
 ��������  : ���ݸ�ʽ02 ���ڱ�A.2 ��ʽ: (+/-)XXX * 10(-3~4)  
 �������  : eMtTrans eTrans      
             float* psUser        
             sMtFmt02_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXXX(eMtTrans eTrans, float* psUser, sMtsXXX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtsXXX   *psXXX  = (sMtsXXX *)psFrame;
    float     fUser   = *psUser;
    float     fTmp    = 0.0f;
    char      cBuf[6] = {0};
    int       nExp    = 0;    //  4 3 2 1 0 -1 -2 -3   

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        // 10(-3)
        if(fUser >= -0.999f && fUser <= 0.999f)
        {
            nExp = -3;
            fTmp = fUser * 1000.0f;
            psXXX->G1 = 1;
            psXXX->G2 = 1;
            psXXX->G3 = 1;
        }
        // 10(-2)
        else if((fUser >= -9.99f && fUser < -0.999f) || 
                (fUser >  0.999f && fUser <= 9.99f))
        {
            nExp = -2;
            fTmp = fUser * 100.0f;
            psXXX->G1 = 0;
            psXXX->G2 = 1;
            psXXX->G3 = 1;
        }
        // 10(-1)
        else if((fUser >= -99.9f && fUser < -9.99f) || 
                (fUser >   9.99f && fUser <= 99.9f))
        {
            nExp = -1;
            fTmp = fUser * 10.0f;
            psXXX->G1 = 1;
            psXXX->G2 = 0;
            psXXX->G3 = 1;
        }
        // 10(0)
        else if((fUser >= -999.0f && fUser < -99.9f) || 
                (fUser >    99.9f && fUser <= 999.0f))
        {
            nExp = 0;
            fTmp = fUser;
            psXXX->G1 = 0;
            psXXX->G2 = 0;
            psXXX->G3 = 1;
        }
        // 10(1)
        else if((fUser >= -9990.0f && fUser < -999.0f) || 
                (fUser >    999.0f && fUser <= 9990.0f))
        {
            nExp = 1;
            fTmp = fUser/10.0f;

            psXXX->G1 = 1;
            psXXX->G2 = 1;
            psXXX->G3 = 0;
        }
        // 10(2)
        else if((fUser >= -99900.0f && fUser < -9990.0f) || 
                (fUser >    9990.0f && fUser <= 99900.0f))
        {
            nExp = 2;
            fTmp = fUser/100.0f;
            psXXX->G1 = 0;
            psXXX->G2 = 1;
            psXXX->G3 = 0;
        }
        // 10(3)
        else if((fUser >= -999000.0f && fUser < -99900.0f) || 
                (fUser >    99900.0f && fUser <= 999000.0f))
        {
            nExp = 3;
            fTmp = fUser/1000.0f;
            psXXX->G1 = 1;
            psXXX->G2 = 0;
            psXXX->G3 = 0;
        }
        // 10(4)
        else if((fUser >= -9990000.0f && fUser < -999000.0f) || 
                (fUser >    999000.0f && fUser <= 9990000.0f))
        {
            nExp = 4;
            fTmp = fUser/10000.0f;
            psXXX->G1 = 0;
            psXXX->G2 = 0;
            psXXX->G3 = 0;
        }
        else
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_sXXX() float out range %f!", fUser);
            #endif
            return MT_ERR_OUTRNG;
        }

        // ����
        psXXX->S = bMtGetFloatSign(fTmp);
        vMtSetFloatSign(&fTmp, 0);

        // ��Ч��
        sprintf(cBuf, "%03.0f", fTmp);
        psXXX->BCD_2 = cBuf[0] - '0';
        psXXX->BCD_1 = cBuf[1] - '0';
        psXXX->BCD_0 = cBuf[2] - '0';

        }
        // ֡�ൽ�û���
        else if(MT_TRANS_F2U == eTrans)
        {
            if(0 == psXXX->G3)
            {
                if(0 == psXXX->G2)
                {
                    if(0 == psXXX->G1)
                    {
                        fTmp =  10000.0f;
                    }
                    else
                    {
                        fTmp =  1000.0f;
                    }
                }
                else
                {
                    if(0 == psXXX->G1)
                    {
                        fTmp =  100.0f;
                    }
                    else
                    {
                        fTmp =  10.0f;
                    }
                }
            }
            else
            {
                if(0 == psXXX->G2)
                {
                    if(0 == psXXX->G1)
                    {
                        fTmp =  1.0f;
                    }
                    else
                    {
                        fTmp =  0.1f;
                    }
                }
                else
                {
                    if(0 == psXXX->G1)
                    {
                        fTmp =  0.01f;
                    }
                    else
                    {
                        fTmp =  0.001f;
                    }
                }
            }

            // ��Ϊ����
            nExp    = (psXXX->S == 1)  ?  -1 : 1;
            fUser   = nExp * (psXXX->BCD_0 + psXXX->BCD_1 * 10.0f + psXXX->BCD_2 *100.0f);
            fUser   = fUser * fTmp;
            *psUser = fUser;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sX7
 ��������  : ���ݸ�ʽ03 ���ڱ�A.4
             ��ʽ: (+/1)XXXXXXX
 �������  : eMtTrans eTrans    
             sMtFmt_sX7* psUser      
             sMtFmt_sX7_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sX7(eMtTrans eTrans, sMtFmt_sX7* psUser, sMtFmt_sX7_f* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sx7() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_sX7      *sX7     = (sMtFmt_sX7*)psUser; 
    sMtFmt_sX7_f    *sX7_f   = (sMtFmt_sX7_f *)psFrame;
    INT32           nData    = 0;
    UINT32          ulData   = 0;
    char           ucBuf[8] = {0};
 
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        nData = sX7->nData;
        if(nData < MT_SX7_MIN || nData > MT_SX7_MAX)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_sx7() nData is out range nData = %d", nData);
            #endif
            return MT_ERR_OUTRNG;
        }

        if(nData < 0)
        {
            ulData = nData * (-1);
            sX7_f->S = 1;
        }
        else
        {
            ulData = nData;
            sX7_f->S = 0;
        }
        
        sprintf(ucBuf, "%d", ulData);

        sX7_f->rev0  = 0;
        sX7_f->rev1  = 0;
        sX7_f->BCD_6 = ucBuf[0] - '0';
        sX7_f->BCD_5 = ucBuf[1] - '0';
        sX7_f->BCD_4 = ucBuf[2] - '0';
        sX7_f->BCD_3 = ucBuf[3] - '0';
        sX7_f->BCD_2 = ucBuf[4] - '0';
        sX7_f->BCD_1 = ucBuf[5] - '0';
        sX7_f->BCD_0 = ucBuf[6] - '0';

        // ��λ
        if(MT_UINT_KWH_LI == sX7->eUnit)
        {
            sX7_f->G = 0;
        }
        else if(MT_UINT_MWH_YUAN == sX7->eUnit)
        {
            sX7_f->G = 1;
        }
        else
        { 
            #ifdef MT_DBG
            DEBUG("emt_trans_sx7() nData is eUnit = %d", sX7->eUnit);
            #endif
            return MT_ERR_OUTRNG;
        }
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        // ��λ
        sX7->eUnit = (sX7_f->G == 0) ? MT_UINT_KWH_LI : MT_UINT_MWH_YUAN;

        // nData
        ulData += sX7_f->BCD_0;
        ulData += sX7_f->BCD_1 * 10;
        ulData += sX7_f->BCD_2 * 100;
        ulData += sX7_f->BCD_3 * 1000;
        ulData += sX7_f->BCD_4 * 10000;
        ulData += sX7_f->BCD_5 * 100000;
        ulData += sX7_f->BCD_6 * 1000000;

        // ����
        nData = (sX7_f->S == 1 ) ? (-1)*ulData : ulData;
        sX7->nData = nData;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sx7() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXX
 ��������  : ���ݸ�ʽ04 ���ڱ�A.5
 ���ݸ�ʽ  : (�ϸ�/�¸�)XX (0 ~ 79)
 �������  : eMtTrans eTrans    
             sMtsXX* psUser     
             sMtsXX_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXX(eMtTrans eTrans, sMtsXX* psUser, sMtsXX_f* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    UINT8 ucTmp = 0;

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(MT_FLOAT_DIR_UP == psUser->eDir)
        {
            psFrame->S0 = 0;
        }
        else if(MT_FLOAT_DIR_DOWN == psUser->eDir)
        {
            psFrame->S0 = 1;
        }
        else
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_sXX() para eDir out range");
            #endif
            return MT_ERR_NULL;
        }

        ucTmp =  psUser->ucValue;
        if(ucTmp > MT_FLOAT_MAX || ucTmp < MT_FLOAT_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_sXX() para ucValue out range");
            #endif
            return MT_ERR_NULL;
        }

        psFrame->BCD_0 = ucmt_get_bcd_0(ucTmp);
        psFrame->BCD_1 = ucmt_get_bcd_1(ucTmp);

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        psUser->eDir = (psFrame->S0 == 0) ? MT_FLOAT_DIR_UP : MT_FLOAT_DIR_DOWN;
        ucTmp = psFrame->BCD_0 + psFrame->BCD_1 * 10;

        if(ucTmp > MT_FLOAT_MAX || ucTmp < MT_FLOAT_MIN)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_sXX() para ucValue out range");
            #endif
            return MT_ERR_NULL;
        }

        psUser->ucValue = ucTmp;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXXX_X
 ��������  : ���ݸ�ʽ05 ���ڱ�A.6
             ��ʽ: (+/1)XXX.X
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt05* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXXX_X(eMtTrans eTrans, float* psUser, sMtFmt05* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX_X() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_sXXX_X    *psFmtsXXX_X;
    float             *pfXXX_X;
    float             fZhengshu;  // ��������

    psFmtsXXX_X    = (sMtFmt_sXXX_X *)psFrame;
    pfXXX_X        = (float *)psUser;
    float fXXX_X   = *pfXXX_X;
    int sign       = 0; 

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXXX_X > 799.9f || fXXX_X < -799.9f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXXX_X*10, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXXX_X->S       = sign;
        psFmtsXXX_X->BCD_2   = buf[0] - '0';
        psFmtsXXX_X->BCD_1   = buf[1] - '0';
        psFmtsXXX_X->BCD_0   = buf[2] - '0';
        psFmtsXXX_X->BCD_0_1 = buf[3] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXXX_X->BCD_0_1;
        bcd[1] = (UINT8)psFmtsXXX_X->BCD_0;
        bcd[2] = (UINT8)psFmtsXXX_X->BCD_1;
        bcd[3] = (UINT8)psFmtsXXX_X->BCD_2;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fXXX_X = valid/10.0f;
        *pfXXX_X = fXXX_X * (psFmtsXXX_X->S == 0 ? 1.0f : -1.0f);
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX_X() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXX_XX
 ��������  : ���ݸ�ʽ06 ���ڱ�A.7
             ��ʽ: (+/1)XX.XX
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt06* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXX_XX(eMtTrans eTrans, float* psUser, sMtFmt06* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX_XX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_sXX_XX    *psFmtsXX_XX;
    float             *pfXX_XX;
    float             fZhengshu;  // ��������

    psFmtsXX_XX    = (sMtFmt_sXX_XX *)psFrame;
    pfXX_XX        = (float *)psUser;
    float fXX_XX   = *pfXX_XX;
    int sign       = 0; 

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXX_XX > 79.99f || fXX_XX < -79.99f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXX_XX*100, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXX_XX->S       = sign;
        psFmtsXX_XX->BCD_1   = buf[0] - '0';
        psFmtsXX_XX->BCD_0   = buf[1] - '0';
        psFmtsXX_XX->BCD_0_1 = buf[2] - '0';
        psFmtsXX_XX->BCD_0_2 = buf[3] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXX_XX->BCD_0_2;
        bcd[1] = (UINT8)psFmtsXX_XX->BCD_0_1;
        bcd[2] = (UINT8)psFmtsXX_XX->BCD_0;
        bcd[3] = (UINT8)psFmtsXX_XX->BCD_1;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fXX_XX = valid/100.0f;
        *pfXX_XX = fXX_XX * (psFmtsXX_XX->S == 0 ? 1.0f : -1.0f);
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX_XX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXX_X
 ��������  : ���ݸ�ʽ07 ���ڱ�A.8 ��ʽ: (+)XXX.X
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt07* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXX_X(eMtTrans eTrans, float* psUser, sMtFmt07* psFrame)
{
    if(!psFrame || !psUser)
    {
         #ifdef MT_DBG
         DEBUG("emt_trans_XXX_X() para pointer is null!");
         #endif
         return MT_ERR_NULL;
    }

    sMtFmt_XXX_X    *psFmtXXX_X;
    float             *pfXXX_X;
    float             fZhengshu;  // ��������

    psFmtXXX_X    = (sMtFmt_XXX_X *)psFrame;
    pfXXX_X        = (float *)psUser;
    float fXXX_X   = *pfXXX_X;

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXXX_X > 999.9f || fXXX_X < 0.0f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXXX_X*10, &fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);
        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtXXX_X->BCD_2   = buf[0] - '0';
        psFmtXXX_X->BCD_1   = buf[1] - '0';
        psFmtXXX_X->BCD_0   = buf[2] - '0';
        psFmtXXX_X->BCD_0_1 = buf[3] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtXXX_X->BCD_0_1;
        bcd[1] = (UINT8)psFmtXXX_X->BCD_0;
        bcd[2] = (UINT8)psFmtXXX_X->BCD_1;
        bcd[3] = (UINT8)psFmtXXX_X->BCD_2;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fXXX_X   = valid / 10.0f;
        *pfXXX_X = fXXX_X;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXX_X() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXX
 ��������  : ���ݸ�ʽ08 ���ڱ�A.9 ��ʽ: XXXX
 �������  : eMtTrans eTrans    
             UINT16* psUser      
             sMtFmt08* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXX(eMtTrans eTrans, UINT16* psUser, sMtFmt08* psFrame)
{
    if(!psFrame || !psUser)
    {
         #ifdef MT_DBG
         DEBUG("emt_trans_XXXX() para pointer is null!");
         #endif
         return MT_ERR_NULL;
    }

    sMtFmt08    *psFmtXXxx;
    UINT16       *pusXXxx;
   
    psFmtXXxx       = (sMtFmt08 *)psFrame;
    pusXXxx         = (UINT16 *)psUser;
    UINT16 usXXxx   = *pusXXxx;

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(usXXxx > (nMtPow(4) - 1) || usXXxx < 0.0f)
        {
            return MT_ERR_OUTRNG;
        }
        
        //����ṹ
        psFmtXXxx->BCD_1   = usXXxx / nMtPow(3);
        usXXxx = usXXxx % nMtPow(3);
        psFmtXXxx->BCD_2   = usXXxx / nMtPow(2);
        usXXxx = usXXxx % nMtPow(2);
        psFmtXXxx->BCD_3   = usXXxx / nMtPow(1);
        usXXxx = usXXxx % nMtPow(1);
        psFmtXXxx->BCD_4 = usXXxx;
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        UINT16   valid = 0;
        
        bcd[0] = (UINT8)psFmtXXxx->BCD_4;
        bcd[1] = (UINT8)psFmtXXxx->BCD_3;
        bcd[2] = (UINT8)psFmtXXxx->BCD_2;
        bcd[3] = (UINT8)psFmtXXxx->BCD_1;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        *pusXXxx = valid;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXX_XXXX
 ��������  : ���ݸ�ʽ09 ���ڱ�A.10
 �������  : eMtTrans eTrans      
             float* psUser     
             sMtFmt09* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXX_XXXX(eMtTrans eTrans, float* psUser, sMtFmt09* psFrame)
{
    if(!psFrame || !psUser)
     {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX_XXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
     }

    sMtFmt_sXX_XXXX   *psFmtsXX_XXXX;
    float             *pfXX_XXXX;
    float             fZhengshu;  // ��������

    psFmtsXX_XXXX  = (sMtFmt_sXX_XXXX *)psFrame;
    pfXX_XXXX      = (float *)psUser;
    float fXX_XXXX = *pfXX_XXXX;
    int sign       = 0; 
 
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXX_XXXX > 79.9999f || fXX_XXXX < -79.9999f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXX_XXXX * 10000.0f, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);
    
        char buf[8] = {0};
        sprintf(buf, "%06.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXX_XXXX->S       = sign;
        psFmtsXX_XXXX->BCD_1   = buf[0] - '0';
        psFmtsXX_XXXX->BCD_0   = buf[1] - '0';
        psFmtsXX_XXXX->BCD_0_1 = buf[2] - '0';
        psFmtsXX_XXXX->BCD_0_2 = buf[3] - '0';  
        psFmtsXX_XXXX->BCD_0_3 = buf[4] - '0';
        psFmtsXX_XXXX->BCD_0_4 = buf[5] - '0';
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[6];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXX_XXXX->BCD_0_4;
        bcd[1] = (UINT8)psFmtsXX_XXXX->BCD_0_3;
        bcd[2] = (UINT8)psFmtsXX_XXXX->BCD_0_2;
        bcd[3] = (UINT8)psFmtsXX_XXXX->BCD_0_1;
        bcd[4] = (UINT8)psFmtsXX_XXXX->BCD_0;
        bcd[5] = (UINT8)psFmtsXX_XXXX->BCD_1;

        for(i = 0; i < 6; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fXX_XXXX = valid/10000.0f;
        *pfXX_XXXX = fXX_XXXX * (psFmtsXX_XXXX->S  == 0 ? 1.0f : -1.0f);

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXX_XXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXXXX
 ��������  : ���ݸ�ʽ10 ���ڱ�A.11 ��ʽ:  XXXXXX
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt07* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXXXX(eMtTrans eTrans, UINT32* psUser, sMtFmt_XXXXXX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    } 

    sMtFmt_XXXXXX   *psFmtXXXXXX;
    UINT32          *puiXXXXXX;

    psFmtXXXXXX     = (sMtFmt_XXXXXX *)psFrame;
    puiXXXXXX       = (UINT32 *)psUser;
    UINT32 uiXXXXXX = *puiXXXXXX;
    
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if((uiXXXXXX > (UINT32)(nMtPow(6) - 1)) || (uiXXXXXX < 0))
        {
            return MT_ERR_OUTRNG;
        }
        
        //����ṹ
        psFmtXXXXXX->BCD_1 = uiXXXXXX / nMtPow(5);
        uiXXXXXX = uiXXXXXX % nMtPow(5);
        psFmtXXXXXX->BCD_2 = uiXXXXXX / nMtPow(4);
        uiXXXXXX = uiXXXXXX % nMtPow(4);
        psFmtXXXXXX->BCD_3 = uiXXXXXX / nMtPow(3);
        uiXXXXXX = uiXXXXXX % nMtPow(3);
        psFmtXXXXXX->BCD_4 = uiXXXXXX / nMtPow(2);
        uiXXXXXX = uiXXXXXX % nMtPow(2);
        psFmtXXXXXX->BCD_5 = uiXXXXXX / nMtPow(1);
        uiXXXXXX = uiXXXXXX % nMtPow(1);
        psFmtXXXXXX->BCD_6 = uiXXXXXX;
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[6];
        UINT32    valid = 0;
        UINT8     i;
        bcd[0] = (UINT8)psFmtXXXXXX->BCD_6;
        bcd[1] = (UINT8)psFmtXXXXXX->BCD_5;
        bcd[2] = (UINT8)psFmtXXXXXX->BCD_4;
        bcd[3] = (UINT8)psFmtXXXXXX->BCD_3;
        bcd[4] = (UINT8)psFmtXXXXXX->BCD_2;
        bcd[5] = (UINT8)psFmtXXXXXX->BCD_1;

        for(i = 0; i < sizeof(bcd); i++)
        {
            valid += bcd[i] * nMtPow(i);
        }

        *puiXXXXXX = valid;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XX_6
 ��������  : ���ݸ�ʽ12 ���ڱ�A.13  
 ���ݸ�ʽ  : XXXXXXXXXXXX
 �������  : eMtTrans eTrans       
             UINT8* psUser        
             sMtFmt_XX_6* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��15�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XX_6(eMtTrans eTrans, UINT8* psUser, sMtFmt_XX_6* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XX_6() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        psFrame->BCD_11    = psUser[0]  - '0';
        psFrame->BCD_10    = psUser[1]  - '0';
        psFrame->BCD_9     = psUser[2]  - '0';
        psFrame->BCD_8     = psUser[3]  - '0'; 
        psFrame->BCD_7     = psUser[4]  - '0';
        psFrame->BCD_6     = psUser[5]  - '0';
        psFrame->BCD_5     = psUser[6]  - '0';
        psFrame->BCD_4     = psUser[7]  - '0'; 
        psFrame->BCD_3     = psUser[8]  - '0';
        psFrame->BCD_2     = psUser[9]  - '0';
        psFrame->BCD_1     = psUser[10] - '0';
        psFrame->BCD_0     = psUser[11] - '0'; 
        
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        psUser[0]  = (UINT8)(psFrame->BCD_11)  + '0';
        psUser[1]  = (UINT8)(psFrame->BCD_10)  + '0';
        psUser[2]  = (UINT8)(psFrame->BCD_9)   + '0';
        psUser[3]  = (UINT8)(psFrame->BCD_8)   + '0';
        psUser[4]  = (UINT8)(psFrame->BCD_7)   + '0';
        psUser[5]  = (UINT8)(psFrame->BCD_6)   + '0';
        psUser[6]  = (UINT8)(psFrame->BCD_5)   + '0';
        psUser[7]  = (UINT8)(psFrame->BCD_4)   + '0';
        psUser[8]  = (UINT8)(psFrame->BCD_3)   + '0';
        psUser[9]  = (UINT8)(psFrame->BCD_2)   + '0';
        psUser[10] = (UINT8)(psFrame->BCD_1)   + '0';
        psUser[11] = (UINT8)(psFrame->BCD_0)   + '0';
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XX_6() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_sXXX_XXX
 ��������  : ���ݸ�ʽ25 ���ڱ�A.26 ��ʽ: (+/1)XXX.XXX
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt25* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_sXXX_XXX(eMtTrans eTrans, float* psUser, sMtFmt25* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX_XXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_sXXX_XXX   *psFmtsXXX_XXX;
    float             *pfXXX_XXX;
    float             fZhengshu;  // ��������

    psFmtsXXX_XXX  = (sMtFmt_sXXX_XXX *)psFrame;
    pfXXX_XXX      = (float *)psUser;
    float fXXX_XXX = *pfXXX_XXX;
    int sign       = 0; 
 
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXXX_XXX > 799.999f || fXXX_XXX < -799.999f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXXX_XXX*1000.0f, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);     // ��÷���λ
        vMtSetFloatSign(&fZhengshu, 0);        // ����Ϊ��

        char buf[8] = {0};
        sprintf(buf, "%06.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXXX_XXX->S       = sign;
        psFmtsXXX_XXX->BCD_2   = buf[0] - '0';
        psFmtsXXX_XXX->BCD_1   = buf[1] - '0';
        psFmtsXXX_XXX->BCD_0   = buf[2] - '0';
        psFmtsXXX_XXX->BCD_0_1 = buf[3] - '0';  
        psFmtsXXX_XXX->BCD_0_2 = buf[4] - '0';
        psFmtsXXX_XXX->BCD_0_3 = buf[5] - '0';
     }
     // ֡�ൽ�û���
     else if(MT_TRANS_F2U == eTrans)
     {
        UINT8    bcd[6];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXXX_XXX->BCD_0_3;
        bcd[1] = (UINT8)psFmtsXXX_XXX->BCD_0_2;
        bcd[2] = (UINT8)psFmtsXXX_XXX->BCD_0_1;
        bcd[3] = (UINT8)psFmtsXXX_XXX->BCD_0;
        bcd[4] = (UINT8)psFmtsXXX_XXX->BCD_1;
        bcd[5] = (UINT8)psFmtsXXX_XXX->BCD_2;

        for(i = 0; i < 6; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fXXX_XXX = valid/1000.0f;
        *pfXXX_XXX = fXXX_XXX * (psFmtsXXX_XXX->S  == 0 ? 1.0f : -1.0f);

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_sXXX_XXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXXXX_XX
 ��������  : ���ݸ�ʽ11 ���ڱ�A.12 ��ʽ: (+)XXXXXX.XX
 �������  : eMtTrans eTrans            
             float* psUser              
             sMtFmt_XXXXXX_XX* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXXXX_XX(eMtTrans eTrans, double* psUser, sMtFmt_XXXXXX_XX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX_XX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_XXXXXX_XX    *psFmtXXXXXX_XX;
    double              *pdXXXXXX_XX;
   
    psFmtXXXXXX_XX      = (sMtFmt_XXXXXX_XX *)psFrame;
    pdXXXXXX_XX         = (double *)psUser;
    double dXXXXXX_XX   = *pdXXXXXX_XX;
   
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(dXXXXXX_XX > 999999.99 || dXXXXXX_XX < -999999.99)
        {
            return MT_ERR_OUTRNG;
        }
        char buf[5] = {0};
        //����ṹ
        psFmtXXXXXX_XX->BCD_5     = (UINT8)(dXXXXXX_XX / nMtPow(5));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_5 * nMtPow(5);
        psFmtXXXXXX_XX->BCD_4     = (UINT8)(dXXXXXX_XX / nMtPow(4));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_4 * nMtPow(4);
        psFmtXXXXXX_XX->BCD_3     = (UINT8)(dXXXXXX_XX / nMtPow(3));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_3 * nMtPow(3);
        psFmtXXXXXX_XX->BCD_2     = (UINT8)(dXXXXXX_XX / nMtPow(2));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_2 * nMtPow(2);
        psFmtXXXXXX_XX->BCD_1     = (UINT8)(dXXXXXX_XX / nMtPow(1));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_1 * nMtPow(1);
        psFmtXXXXXX_XX->BCD_0     = (UINT32)dXXXXXX_XX % nMtPow(1);
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_0;
        sprintf(buf,"%2.2f",dXXXXXX_XX);
        psFmtXXXXXX_XX->BCD_0_1   =  buf[2] - '0';
        psFmtXXXXXX_XX->BCD_0_2   =  buf[3] - '0';  
 
     }
     // ֡�ൽ�û���
     else if(MT_TRANS_F2U == eTrans)
     {
        UINT8    bcd[8];
        int      i;
        UINT32   uiInt,uiFrac;

        uiInt = 0;
        uiFrac = 0;
        
        bcd[0] = (UINT8)psFmtXXXXXX_XX->BCD_0_2;
        bcd[1] = (UINT8)psFmtXXXXXX_XX->BCD_0_1;
        bcd[2] = (UINT8)psFmtXXXXXX_XX->BCD_0;
        bcd[3] = (UINT8)psFmtXXXXXX_XX->BCD_1;
        bcd[4] = (UINT8)psFmtXXXXXX_XX->BCD_2;
        bcd[5] = (UINT8)psFmtXXXXXX_XX->BCD_3;
        bcd[6] = (UINT8)psFmtXXXXXX_XX->BCD_4;
        bcd[7] = (UINT8)psFmtXXXXXX_XX->BCD_5;
        
        for(i = 0; i < 2; i++)
        {
            uiFrac += bcd[i]*nMtPow(i);
        }

        for(; i < 8; i++)
        {
            uiInt+= bcd[i]*nMtPow(i - 2);
        }

        dXXXXXX_XX = (DOUBLE)uiInt + (DOUBLE)uiFrac/100.0;
        *pdXXXXXX_XX = dXXXXXX_XX;
     }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX_XX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXX_XXXX
 ��������  : ���ݸ�ʽ13 ���ڱ�A.14 ��ʽ: (+)XXXX.XXXX
 �������  : eMtTrans eTrans            
             float* psUser              
             sMtFmt_XXXX_XXXX* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXX_XXXX(eMtTrans eTrans, double* psUser, sMtFmt_XXXX_XXXX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXX_XXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_XXXX_XXXX    *psFmtXXXX_XXXX;
    double              *pdXXXX_XXXX;
    double              dZhengshu;  // ��������

    psFmtXXXX_XXXX      = (sMtFmt_XXXX_XXXX *)psFrame;
    pdXXXX_XXXX         = (double *)psUser;
    double dXXXX_XXXX   = *pdXXXX_XXXX;
 
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(dXXXX_XXXX > 9999.9999 || dXXXX_XXXX < -9999.9999)
        {
            return MT_ERR_OUTRNG;
        }

        modf(dXXXX_XXXX*10000, &dZhengshu);
        vMtSetDoubleSign(&dZhengshu, 1);
        char buf[10] = {0};
        sprintf(buf, "%08.0lf\n", dZhengshu);

        //����ṹ
        psFmtXXXX_XXXX->BCD_3     = buf[0] - '0';
        psFmtXXXX_XXXX->BCD_2     = buf[1] - '0';
        psFmtXXXX_XXXX->BCD_1     = buf[2] - '0';
        psFmtXXXX_XXXX->BCD_0     = buf[3] - '0';  
        psFmtXXXX_XXXX->BCD_0_1   = buf[4] - '0';  
        psFmtXXXX_XXXX->BCD_0_2   = buf[5] - '0';  
        psFmtXXXX_XXXX->BCD_0_3   = buf[6] - '0';  
        psFmtXXXX_XXXX->BCD_0_4   = buf[7] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[8];
        int      i;
        double    valid = 0.0;

        bcd[0] = (UINT8)psFmtXXXX_XXXX->BCD_0_4;
        bcd[1] = (UINT8)psFmtXXXX_XXXX->BCD_0_3;
        bcd[2] = (UINT8)psFmtXXXX_XXXX->BCD_0_2;
        bcd[3] = (UINT8)psFmtXXXX_XXXX->BCD_0_1;
        bcd[4] = (UINT8)psFmtXXXX_XXXX->BCD_0;
        bcd[5] = (UINT8)psFmtXXXX_XXXX->BCD_1;
        bcd[6] = (UINT8)psFmtXXXX_XXXX->BCD_2;
        bcd[7] = (UINT8)psFmtXXXX_XXXX->BCD_3;

        for(i = 0; i < 8; i++)
        {
            valid += bcd[i]*nMtPow(i);
        }

        dXXXX_XXXX = valid/10000.0;
        *pdXXXX_XXXX = dXXXX_XXXX;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXX_XXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXXXX_XXXX
 ��������  : ���ݸ�ʽ14 ���ڱ�A.15 ��ʽ: (+)XXXXXX.XXXX
 �������  : eMtTrans eTrans            
             float* psUser              
             sMtFmt_XXXXXX_XXXX* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXXXX_XXXX(eMtTrans eTrans, double* psUser, sMtFmt_XXXXXX_XXXX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX_XXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_XXXXXX_XXXX    *psFmtXXXXXX_XXXX;
    double                *pdXXXXXX_XXXX;
  
    psFmtXXXXXX_XXXX      = (sMtFmt_XXXXXX_XXXX *)psFrame;
    pdXXXXXX_XXXX         = (double *)psUser;
    double dXXXXXX_XXXX   = *pdXXXXXX_XXXX;
 
     // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(dXXXXXX_XXXX > 999999.9999 || dXXXXXX_XXXX < -999999.9999)
        {
            return MT_ERR_OUTRNG;
        }
        CHAR buf[7] = {0};
            
        //����ṹ
        psFmtXXXXXX_XXXX->BCD_5     = (UINT8)(dXXXXXX_XXXX / nMtPow(5));
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_5 * nMtPow(5);
        psFmtXXXXXX_XXXX->BCD_4     = (UINT8)(dXXXXXX_XXXX / nMtPow(4));
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_4 * nMtPow(4);
        psFmtXXXXXX_XXXX->BCD_3     = (UINT8)(dXXXXXX_XXXX / nMtPow(3));
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_3 * nMtPow(3);
        psFmtXXXXXX_XXXX->BCD_2     = (UINT8)(dXXXXXX_XXXX / nMtPow(2));  
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_2 * nMtPow(2);
        psFmtXXXXXX_XXXX->BCD_1     = (UINT8)(dXXXXXX_XXXX / nMtPow(1)); 
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_1 * nMtPow(1);
        psFmtXXXXXX_XXXX->BCD_0     = (UINT8)dXXXXXX_XXXX % nMtPow(1);  
        dXXXXXX_XXXX -= psFmtXXXXXX_XXXX->BCD_0;
     
        sprintf(buf,"%4.4f",dXXXXXX_XXXX);
        psFmtXXXXXX_XXXX->BCD_0_1   = buf[2] - '0';
        psFmtXXXXXX_XXXX->BCD_0_2   = buf[3] - '0';
        psFmtXXXXXX_XXXX->BCD_0_3   = buf[4] - '0';  
        psFmtXXXXXX_XXXX->BCD_0_4   = buf[5] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[10];
        int      i;
        UINT32   uiInt,uiFrac;

        uiInt = 0;
        uiFrac = 0;
        
        bcd[0] = (UINT8)psFmtXXXXXX_XXXX->BCD_0_4;
        bcd[1] = (UINT8)psFmtXXXXXX_XXXX->BCD_0_3;
        bcd[2] = (UINT8)psFmtXXXXXX_XXXX->BCD_0_2;
        bcd[3] = (UINT8)psFmtXXXXXX_XXXX->BCD_0_1;
        bcd[4] = (UINT8)psFmtXXXXXX_XXXX->BCD_0;
        bcd[5] = (UINT8)psFmtXXXXXX_XXXX->BCD_1;
        bcd[6] = (UINT8)psFmtXXXXXX_XXXX->BCD_2;
        bcd[7] = (UINT8)psFmtXXXXXX_XXXX->BCD_3;
        bcd[8] = (UINT8)psFmtXXXXXX_XXXX->BCD_4;
        bcd[9] = (UINT8)psFmtXXXXXX_XXXX->BCD_5;

        for(i = 0; i < 4; i++)
        {
            uiFrac += bcd[i]*nMtPow(i);
        }

        for ( ;i < 10; i++)
        {
            uiInt += bcd[i]*nMtPow(i - 4);
        }

        dXXXXXX_XXXX = (DOUBLE)uiInt + (DOUBLE)uiFrac/10000.0;
        *pdXXXXXX_XXXX = dXXXXXX_XXXX;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXX_XXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_YYMMDD
 ��������  : ���ݸ�ʽת������  ���ݸ�ʽ20 ���ڱ�A.21 ��λ: ������
 �������  : eMtTrans eTrans           
             sMtYYMMDD* psUser     
             sMtYYMMDD_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_YYMMDD(eMtTrans eTrans, sMtYYMMDD* psUser, sMtYYMMDD_f* psFrame)
{
    if(!psUser || !psFrame)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMMDD() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     
        // ��
        psFrame->bcd_YY_0 = ucmt_get_bcd_0(psUser->ucYY);
        psFrame->bcd_YY_1 = ucmt_get_bcd_1(psUser->ucYY);

        // ��
        if(psUser->ucMM > 12)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDD() ucMM MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_MM_0 = ucmt_get_bcd_0(psUser->ucMM);
            psFrame->bcd_MM_1 = ucmt_get_bcd_1(psUser->ucMM);
        }

        // ��
        if(psUser->ucDD > 31)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDD() ucDD MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_DD_0 = ucmt_get_bcd_0(psUser->ucDD);
            psFrame->bcd_DD_1 = ucmt_get_bcd_1(psUser->ucDD);
        }       
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psUser->ucYY = psFrame->bcd_YY_0 + psFrame->bcd_YY_1 * 10;
        psUser->ucMM = psFrame->bcd_MM_0 + psFrame->bcd_MM_1 * 10;
        psUser->ucDD = psFrame->bcd_DD_0 + psFrame->bcd_DD_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("ucmt_get_bcd_0() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_YYMM
 ��������  : ���ݸ�ʽת������  ���ݸ�ʽ21 ���ڱ�A.22 ��λ: ����
 �������  : eMtTrans eTrans           
             sMtYYMM* psUser     
             sMtYYMM_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_YYMM(eMtTrans eTrans, sMtYYMM* psUser, sMtYYMM_f* psFrame)
{
    if(!psUser || !psFrame)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMM() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(MT_TRANS_U2F == eTrans)
    {     
        // ��
        psFrame->bcd_YY_0 = ucmt_get_bcd_0(psUser->ucYY);
        psFrame->bcd_YY_1 = ucmt_get_bcd_1(psUser->ucYY);

        // ��
        if(psUser->ucMM > 12)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMM() ucMM MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_MM_0 = ucmt_get_bcd_0(psUser->ucMM);
            psFrame->bcd_MM_1 = ucmt_get_bcd_1(psUser->ucMM);
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psUser->ucYY = psFrame->bcd_YY_0 + psFrame->bcd_YY_1 * 10;
        psUser->ucMM = psFrame->bcd_MM_0 + psFrame->bcd_MM_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("ucmt_get_bcd_0() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_YYMMDDhhmm
 ��������  : ���ݸ�ʽת������  ���ݸ�ʽ15 ���ڱ�A.16 ��λ: ������ʱ��
 �������  : eMtTrans eTrans           
             sMtYYMMDDhhmm* psUser     
             sMtYYMMDDhhmm_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_YYMMDDhhmm(eMtTrans eTrans, sMtYYMMDDhhmm* psUser, sMtYYMMDDhhmm_f* psFrame)
{
    if(!psUser || !psFrame)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_YYMMDDhhmm() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     
        // ��
        psFrame->bcd_YY_0 = ucmt_get_bcd_0(psUser->ucYY);
        psFrame->bcd_YY_1 = ucmt_get_bcd_1(psUser->ucYY);

        // ��
        if(psUser->ucMM > 12)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDDhhmm() ucMM MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_MM_0 = ucmt_get_bcd_0(psUser->ucMM);
            psFrame->bcd_MM_1 = ucmt_get_bcd_1(psUser->ucMM);
        }

        // ��
        if(psUser->ucDD > 31)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDDhhmm() ucDD MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_DD_0 = ucmt_get_bcd_0(psUser->ucDD);
            psFrame->bcd_DD_1 = ucmt_get_bcd_1(psUser->ucDD);
        }

        // ʱ
        if(psUser->ucHH > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDDhhmm() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_hh_0 = ucmt_get_bcd_0(psUser->ucHH);
            psFrame->bcd_hh_1 = ucmt_get_bcd_1(psUser->ucHH);
        }

        // ��
        if(psUser->ucmm > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_YYMMDDhhmm() ucmm MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_mm_0 = ucmt_get_bcd_0(psUser->ucmm);
            psFrame->bcd_mm_1 = ucmt_get_bcd_1(psUser->ucmm);
        }
           
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psUser->ucYY = psFrame->bcd_YY_0 + psFrame->bcd_YY_1 * 10;
        psUser->ucMM = psFrame->bcd_MM_0 + psFrame->bcd_MM_1 * 10;
        psUser->ucDD = psFrame->bcd_DD_0 + psFrame->bcd_DD_1 * 10;
        psUser->ucHH = psFrame->bcd_hh_0 + psFrame->bcd_hh_1 * 10;
        psUser->ucmm = psFrame->bcd_mm_0 + psFrame->bcd_mm_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("ucmt_get_bcd_0() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_DDHHmmss
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ16 ���ڱ�A.17 ��λ: ��ʱ����
 �������  : eMtTrans eTrans              
             sMtDDhhmmss* psDDhhmmss_u    
             sMtDDhhmmss_f* psDDhhmmss_f  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_DDHHmmss(eMtTrans eTrans, sMtDDHHmmss* psDDHHmmss_u, sMtDDHHmmss_f* psDDHHmmss_f)
{
    if(!psDDHHmmss_u || !psDDHHmmss_f)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_DDhhmmss() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     
        if(psDDHHmmss_u->ucDD > 31 || psDDHHmmss_u->ucDD < 0)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDhhmmss() ucDD MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_DD_0 = ucmt_get_bcd_0(psDDHHmmss_u->ucDD);
            psDDHHmmss_f->bcd_DD_1 = ucmt_get_bcd_1(psDDHHmmss_u->ucDD);
        }

        if(psDDHHmmss_u->ucHH > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDhhmmss() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_HH_0 = ucmt_get_bcd_0(psDDHHmmss_u->ucHH);
            psDDHHmmss_f->bcd_HH_1 = ucmt_get_bcd_1(psDDHHmmss_u->ucHH);
        }

        if(psDDHHmmss_u->ucmm > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDhhmmss() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_mm_0 = ucmt_get_bcd_0(psDDHHmmss_u->ucmm);
            psDDHHmmss_f->bcd_mm_1 = ucmt_get_bcd_1(psDDHHmmss_u->ucmm);
        }

        if(psDDHHmmss_u->ucss > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDhhmmss() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_ss_0 = ucmt_get_bcd_0(psDDHHmmss_u->ucss);
            psDDHHmmss_f->bcd_ss_1 = ucmt_get_bcd_1(psDDHHmmss_u->ucss);
        }         
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psDDHHmmss_u->ucDD = psDDHHmmss_f->bcd_DD_0 + psDDHHmmss_f->bcd_DD_1 * 10;
        psDDHHmmss_u->ucHH = psDDHHmmss_f->bcd_HH_0 + psDDHHmmss_f->bcd_HH_1 * 10;
        psDDHHmmss_u->ucmm = psDDHHmmss_f->bcd_mm_0 + psDDHHmmss_f->bcd_mm_1 * 10;
        psDDHHmmss_u->ucss = psDDHHmmss_f->bcd_ss_0 + psDDHHmmss_f->bcd_ss_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_DDhhmmss() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_MMDDHHmm
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ17 ���ڱ�A.18 ��λ: ����ʱ��
 �������  : eMtTrans eTrans              
             sMtMMDDHHmm* psMMDDHHmm_u  
             sMtMMDDHHmm_f* psMMDDHHmm_f
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_MMDDHHmm(eMtTrans eTrans, sMtMMDDHHmm* psMMDDHHmm_u, sMtMMDDHHmm_f* psMMDDHHmm_f)
{
    if(!psMMDDHHmm_u || !psMMDDHHmm_f)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_MMDDHHmm() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     

        if(psMMDDHHmm_u->ucMM > 12 || psMMDDHHmm_u->ucMM < 1 )
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_MMDDHHmm() ucMM MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psMMDDHHmm_f->bcd_MM_0 = ucmt_get_bcd_0(psMMDDHHmm_u->ucMM);
            psMMDDHHmm_f->bcd_MM_1 = ucmt_get_bcd_1(psMMDDHHmm_u->ucMM);
        }

        if(psMMDDHHmm_u->ucDD > 31 || psMMDDHHmm_u->ucDD < 0)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_MMDDHHmm() ucDD MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psMMDDHHmm_f->bcd_DD_0 = ucmt_get_bcd_0(psMMDDHHmm_u->ucDD);
            psMMDDHHmm_f->bcd_DD_1 = ucmt_get_bcd_1(psMMDDHHmm_u->ucDD);
        }

        if(psMMDDHHmm_u->ucHH > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_MMDDHHmm() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psMMDDHHmm_f->bcd_HH_0 = ucmt_get_bcd_0(psMMDDHHmm_u->ucHH);
            psMMDDHHmm_f->bcd_HH_1 = ucmt_get_bcd_1(psMMDDHHmm_u->ucHH);
        }

        if(psMMDDHHmm_u->ucmm > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_MMDDHHmm() ucmm MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psMMDDHHmm_f->bcd_mm_0 = ucmt_get_bcd_0(psMMDDHHmm_u->ucmm);
            psMMDDHHmm_f->bcd_mm_1 = ucmt_get_bcd_1(psMMDDHHmm_u->ucmm);
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psMMDDHHmm_u->ucDD = psMMDDHHmm_f->bcd_DD_0 + psMMDDHHmm_f->bcd_DD_1 * 10;
        psMMDDHHmm_u->ucHH = psMMDDHHmm_f->bcd_HH_0 + psMMDDHHmm_f->bcd_HH_1 * 10;
        psMMDDHHmm_u->ucmm = psMMDDHHmm_f->bcd_mm_0 + psMMDDHHmm_f->bcd_mm_1 * 10;
        psMMDDHHmm_u->ucMM = psMMDDHHmm_f->bcd_MM_0 + psMMDDHHmm_f->bcd_MM_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_MMDDhhmm() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_MMDDHHmm
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ18 ���ڱ�A.19 ��λ: ��ʱ��
 �������  : eMtTrans eTrans              
             sMtDDhhmm* psDDhhmm_u    
             sMtDDhhmm_f* psDDhhmm_f  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_DDHHmm(eMtTrans eTrans, sMtDDHHmm* psDDHHmm_u, sMtDDHHmm_f* psDDHHmm_f)
{
    if(!psDDHHmm_u || !psDDHHmm_f)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_DDHHmm() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     
        if(psDDHHmm_u->ucDD > 31 || psDDHHmm_u->ucDD < 0)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDHHmm() ucDD MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmm_f->bcd_DD_0 = ucmt_get_bcd_0(psDDHHmm_u->ucDD);
            psDDHHmm_f->bcd_DD_1 = ucmt_get_bcd_1(psDDHHmm_u->ucDD);
        }

        if(psDDHHmm_u->ucHH > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDHHmm() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmm_f->bcd_HH_0 = ucmt_get_bcd_0(psDDHHmm_u->ucHH);
            psDDHHmm_f->bcd_HH_1 = ucmt_get_bcd_1(psDDHHmm_u->ucHH);
        }

        if(psDDHHmm_u->ucmm > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_DDHHmm() ucmm MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psDDHHmm_f->bcd_mm_0 = ucmt_get_bcd_0(psDDHHmm_u->ucmm);
            psDDHHmm_f->bcd_mm_1 = ucmt_get_bcd_1(psDDHHmm_u->ucmm);
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psDDHHmm_u->ucDD = psDDHHmm_f->bcd_DD_0 + psDDHHmm_f->bcd_DD_1 * 10;
        psDDHHmm_u->ucHH = psDDHHmm_f->bcd_HH_0 + psDDHHmm_f->bcd_HH_1 * 10;
        psDDHHmm_u->ucmm = psDDHHmm_f->bcd_mm_0 + psDDHHmm_f->bcd_mm_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_DDhhmm() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_MMHHmm
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ19 ���ڱ�A.20 ��λ: ʱ��
 �������  : eMtTrans eTrans              
             sMthhmm* pshhmm_u    
             sMthhmm_f* pshhmm_f  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_HHmm(eMtTrans eTrans, sMtHHmm* psHHmm_u, sMtHHmm_f* psHHmm_f)
{
    if(!psHHmm_u || !psHHmm_f)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_HHmm() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }
    
    if(MT_TRANS_U2F == eTrans)
    {     
        if(psHHmm_u->ucHH > 24)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_HHmm() ucHH MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psHHmm_f->bcd_HH_0 = ucmt_get_bcd_0(psHHmm_u->ucHH);
            psHHmm_f->bcd_HH_1 = ucmt_get_bcd_1(psHHmm_u->ucHH);
        }

        if(psHHmm_u->ucmm > 60)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_HHmm() ucmm MT_ERR_OUTRNG!");
            #endif
            return MT_ERR_OUTRNG;
        }
        else
        {
            psHHmm_f->bcd_mm_0 = ucmt_get_bcd_0(psHHmm_u->ucmm);
            psHHmm_f->bcd_mm_1 = ucmt_get_bcd_1(psHHmm_u->ucmm);
        }
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        psHHmm_u->ucHH = psHHmm_f->bcd_HH_0 + psHHmm_f->bcd_HH_1 * 10;
        psHHmm_u->ucmm = psHHmm_f->bcd_mm_0 + psHHmm_f->bcd_mm_1 * 10;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_hhmm() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_X_X
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ22 ���ڱ�A.23 
 �������  : eMtTrans eTrans              
             float* psUser 
             sMtFmt22_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_X_X(eMtTrans eTrans, float* psUser, sMtFmt22_f* psFrame)
{
    if(!psUser || !psFrame)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_X_X() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    float fData = *psUser;
    char buf[4] = {0};
    
    if(MT_TRANS_U2F == eTrans)
    {
        if(fData > 9.9f || fData < 0.0f)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_X_X() fData para error! %f", fData);
            #endif
            return MT_ERR_PARA;
        }

        sprintf(buf, "%02.1f", fData);
        psFrame->BCD_0   = buf[0] - '0';
        psFrame->BCD_0_1 = buf[2] - '0';
    }
    else if(MT_TRANS_F2U == eTrans)
    {
        fData = (psFrame->BCD_0_1 + psFrame->BCD_0 * 10.0f) / 10.0f;
        if(fData > 9.9f || fData < 0.0f)
        {
            #ifdef MT_DBG
            DEBUG("emt_trans_X_X() fData para error! %f", fData);
            #endif
            return MT_ERR_PARA;
        }
        
        *psUser = fData;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_X_X() para error!");
        #endif
        return MT_ERR_PARA;
    }
        
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XX_XXXX
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ23 ���ڱ�A.24 
 �������  : eMtTrans eTrans      
             float* psUser        
             sMtFmt23_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XX_XXXX(eMtTrans eTrans, float* psUser, sMtFmt23_f* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XX_XXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_XX_XXXX   *psFmtXX_XXXX;
    float             *pfXX_XXXX;
    float             fZhengshu;  // ��������

    psFmtXX_XXXX  = (sMtFmt_XX_XXXX *)psFrame;
    pfXX_XXXX      = (float *)psUser;
    float fXX_XXXX = *pfXX_XXXX;
    int sign       = 0; 
 
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fXX_XXXX > 99.9999f || fXX_XXXX < 0.0f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fXX_XXXX*10000.0f, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%06.0lf\n", fZhengshu);

        //����ṹ
        psFmtXX_XXXX->BCD_1   = buf[0] - '0';
        psFmtXX_XXXX->BCD_0   = buf[1] - '0';
        psFmtXX_XXXX->BCD_0_1 = buf[2] - '0';
        psFmtXX_XXXX->BCD_0_2 = buf[3] - '0';  
        psFmtXX_XXXX->BCD_0_3 = buf[4] - '0';
        psFmtXX_XXXX->BCD_0_4 = buf[5] - '0';
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[6];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtXX_XXXX->BCD_0_4;
        bcd[1] = (UINT8)psFmtXX_XXXX->BCD_0_3;
        bcd[2] = (UINT8)psFmtXX_XXXX->BCD_0_2;
        bcd[3] = (UINT8)psFmtXX_XXXX->BCD_0_1;
        bcd[4] = (UINT8)psFmtXX_XXXX->BCD_0;
        bcd[5] = (UINT8)psFmtXX_XXXX->BCD_1;

        for(i = 0; i < 6; i++)
        {
        valid+= bcd[i]*nMtPow(i);
        }

        fXX_XXXX = valid/10000.0f;
        *pfXX_XXXX = fXX_XXXX;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XX_XXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

     return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XX_XXXX
 ��������  : ���ݸ�ʽ26 ���ڱ�A.27
 �������  : eMtTrans eTrans      
             float* psUser        
             sMtFmt23_f* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��19�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_X_XXX(eMtTrans eTrans, float* psUser, sMtFmt26* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_X_XXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt26          *psFmtX_XXX;
    float             *pfX_XXX;
    float             fZhengshu;  // ��������

    psFmtX_XXX     = (sMtFmt26 *)psFrame;
    pfX_XXX        = (float *)psUser;
    float fX_XXX   = *pfX_XXX;
    int sign       = 0; 

    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(fX_XXX > 9.999f || fX_XXX < 0.0f)
        {
            return MT_ERR_OUTRNG;
        }

        modff(fX_XXX*1000, &fZhengshu);
        sign = bMtGetFloatSign(fZhengshu);
        vMtSetFloatSign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtX_XXX->BCD_0   = buf[0] - '0';
        psFmtX_XXX->BCD_0_1 = buf[1] - '0';
        psFmtX_XXX->BCD_0_2 = buf[2] - '0';
        psFmtX_XXX->BCD_0_3 = buf[3] - '0';  

    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtX_XXX->BCD_0_3;
        bcd[1] = (UINT8)psFmtX_XXX->BCD_0_2;
        bcd[2] = (UINT8)psFmtX_XXX->BCD_0_1;
        bcd[3] = (UINT8)psFmtX_XXX->BCD_0;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*nMtPow(i);
        }

        fX_XXX = valid/1000.0f;
        *pfX_XXX = fX_XXX;

    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_X_XXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

 return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_XXXXXXXX
 ��������  : ���ݸ�ʽ27 ���ڱ�A.28 ��ʽ:  XXXXXXXX
 �������  : eMtTrans eTrans    
             float* psUser      
             sMtFmt07* psFrame  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��22�� ������
    ��    ��   : liujinlong
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_XXXXXXXX(eMtTrans eTrans, UINT32* psUser, sMtFmt_XXXXXXXX* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXXXX() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    sMtFmt_XXXXXXXX   *psFmtXXxxXXxx;
    UINT32            *puiXXxxXXxx;

    psFmtXXxxXXxx        = (sMtFmt_XXXXXXXX *)psFrame;
    puiXXxxXXxx          = (UINT32 *)psUser;
    UINT32 uiXXxxXXxx    = *puiXXxxXXxx;
    
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        if(uiXXxxXXxx > (UINT32)(nMtPow(8) - 1)|| uiXXxxXXxx < 0)
        {
            return MT_ERR_OUTRNG;
        }
        
        //����ṹ
        psFmtXXxxXXxx->BCD_1 = uiXXxxXXxx / nMtPow(7);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(7);
        psFmtXXxxXXxx->BCD_2 = uiXXxxXXxx / nMtPow(6);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(6);
        psFmtXXxxXXxx->BCD_3 = uiXXxxXXxx / nMtPow(5);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(5);
        psFmtXXxxXXxx->BCD_4 = uiXXxxXXxx / nMtPow(4);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(4);
        psFmtXXxxXXxx->BCD_5 = uiXXxxXXxx / nMtPow(3);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(3);
        psFmtXXxxXXxx->BCD_6 = uiXXxxXXxx / nMtPow(2);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(2);
        psFmtXXxxXXxx->BCD_7 = uiXXxxXXxx / nMtPow(1);
        uiXXxxXXxx = uiXXxxXXxx % nMtPow(1);
        psFmtXXxxXXxx->BCD_8 = uiXXxxXXxx;
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        UINT8    bcd[8];
        UINT32   valid = 0;
        UINT8    i;
        bcd[0] = (UINT8)psFmtXXxxXXxx->BCD_8;
        bcd[1] = (UINT8)psFmtXXxxXXxx->BCD_7;
        bcd[2] = (UINT8)psFmtXXxxXXxx->BCD_6;
        bcd[3] = (UINT8)psFmtXXxxXXxx->BCD_5;
        bcd[4] = (UINT8)psFmtXXxxXXxx->BCD_4;
        bcd[5] = (UINT8)psFmtXXxxXXxx->BCD_3;
        bcd[6] = (UINT8)psFmtXXxxXXxx->BCD_2;
        bcd[7] = (UINT8)psFmtXXxxXXxx->BCD_1;    

        for(i = 0; i < sizeof(bcd); i++)
        {
            valid += bcd[i] * nMtPow(i);
        }

        *puiXXxxXXxx = valid;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_XXXXXXXX() para error!");
        #endif
        return MT_ERR_PARA;
    }

    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emt_trans_fmt_freeze
 ��������  : ��¼c ������
 �������  : eMtTrans eTrans     
             eMtFmtFrez* psUser  
             UINT8* psFrame      
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��26�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_trans_fmt_freeze(eMtTrans eTrans, eMtFmtFrez* psUser, UINT8* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_fmt_freeze() para pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    eMtFmtFrez        *psU;
    UINT8             *psF;
    eMtFmtFrez        eFrez;
    UINT8             ucFrez;

    psU               = (eMtFmtFrez *)psUser;
    eFrez             = *(psU); 
    psF               = (UINT8 *)psFrame;
    
    // �û��ൽ֡��
    if(MT_TRANS_U2F == eTrans)
    {
        switch(eFrez)
        {
            case MT_FREZ_NULL:
                ucFrez = 0;
                break;
                
            case MT_FREZ_15:
                ucFrez = 1;
                break;   
                
            case MT_FREZ_30:
                ucFrez = 2;
                break;   
                
            case MT_FREZ_60:
                ucFrez = 3;
                break;   
                
            case MT_FREZ_5:
                ucFrez = 254;
                break;            

            case MT_FREZ_1:
                ucFrez = 255;
                break;             

                default:
                #ifdef MT_DBG
                DEBUG("emt_trans_fmt_freeze() eFrez para out range %d", eFrez);
                #endif
                return MT_ERR_OUTRNG;
               // break;
        }

        *psF = ucFrez;
    }
    // ֡�ൽ�û���
    else if(MT_TRANS_F2U == eTrans)
    {
        ucFrez = *psF;
        switch(ucFrez)
        {
            case 0:
                eFrez = MT_FREZ_NULL;
                break;
                
            case 1:
                eFrez = MT_FREZ_15;
                break;   
                
            case 2:
                eFrez = MT_FREZ_30;
                break;   
                
            case 3:
                eFrez = MT_FREZ_60;
                break;   
                
            case 254:
                eFrez = MT_FREZ_5;
                break;            

            case 255:
                eFrez = MT_FREZ_1;
                break;             

                default:
                #ifdef MT_DBG
                DEBUG("emt_trans_fmt_freeze() ucFrez para out range %d", ucFrez);
                #endif
                return MT_ERR_OUTRNG;
               // break;
        }

        *(psU) = eFrez;
    }
    else
    {
        #ifdef MT_DBG
        DEBUG("emt_trans_fmt_freeze() para error!");
        #endif
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
UINT8 ucmt_get_check_sum(UINT8 *pStartPos, UINT16 usLen)
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
 �� �� ��  : emt_pack_common
 ��������  : �������� ���ķ�װ����   
 �������  : eMtAFN eAFN           
             sMtComPack *psCommon  
 �������  : UINT16 *pusLen     ��װ���֡��    
             UINT8  *pOutBuf    ��װ���֡����
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtBasePack
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��2�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emt_pack_common(eMtAFN eAFN, sMtComPack *psCommon,  UINT16 *pusLen, UINT8  *pOutBuf)
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
        #ifdef MT_DBG
        DEBUG("emt_pack_common() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(g_bMtInit != TRUE)
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    // ֡���Ƿ���
    if(psCommon->usSeq2CsLen > MT_SEQ2CS_MAX)
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() para out of range!");
        #endif
        return MT_ERR_OUTRNG;
    }

    if(!(psCommon->pSeq2Cs))
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() MT_ERR_SEQ2CS pointer is null!");
        #endif
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
    
    psHead->L1_2 = (usUserDataLen & 0x003F);
    psHead->L2_2 = (usUserDataLen & 0x3FC0) >> 6;

    psHead->p10_2 = 2; 
    psHead->p10   = 2; 
    
    // ���������
    eErr = emt_trans_ctrl(MT_TRANS_U2F, &(psCommon->sCtrl), &ucCtrl);
    if(eErr != MT_OK)
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() emt_trans_ctrl failed: %s\n", smtGetErr(eErr));
        #endif 
        return MT_ERR_CTRL;
    }
  
    psHead->C = ucCtrl;

    // ��ַ��
    eErr = emt_trans_address(MT_TRANS_U2F, &(psCommon->sAddr), &(psHead->A));
    if(eErr != MT_OK)
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() emt_trans_address failed: %s\n", smtGetErr(eErr));
        #endif 
        return MT_ERR_ADDR;
    }
        
    // ����SEQ
    eErr = emt_trans_seq(MT_TRANS_U2F, &(psCommon->sSEQ), (sMtSEQ_f*)&(psHead->SEQ));
    if(eErr != MT_OK)
    {
        #ifdef MT_DBG
        DEBUG("emt_pack_common() emt_trans_seq failed: %s\n", smtGetErr(eErr));
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

    // �����������
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtLitePack
 ��������  : ʵ�ֻ����ı��ķ�װ, ��������㷨�ӿ�
             �ô���Ӧ�ò����ݼ��� ���ܺ���ܿ��ܻ��
             �䳤��,���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
             Ӧ�ò������,���ϲ㴫��Ŀռ�,������emtBasePack��ʡ�ڴ�
             
 �������  : smtLitePack* psPack  
             UINT16* pusLen       
             UINT8* pOutBuf       
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emt_pack_common()
 ��������  : emtPack()
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtLitePack(smtLitePack* psPack, UINT16* pusLen, UINT8* pOutBuf)
{
    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtLitePack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtLitePack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    eMtErr         eRet        = MT_OK;
    eMtCmd         eCmd        = CMD_AFN_F_UNKOWN;
    eMtDir         eDir        = MT_DIR_UNKOWN;
    eMtAFN         eAFN        = AFN_NULL;
    BOOL           bSameTeam   = FALSE;
    BOOL           bP0         = FALSE;
    UINT8          ucPnNum     = 0;
    UINT16         usSeq2CsLen = 0;
    UINT16         usSeq2CsPos = 0; 
    UINT16         usfDataLen  = 0;      // ֡�����ݵ�Ԫ�ֳ�
    UINT16         usCMD       = 0;
    INT32          i           = 0;
    INT32          j           = 0;
    INT32          fi          = 0;
    INT32          pi          = 0;
    UINT8*         pSeq2Cs     = NULL;
    UINT8*         puData      = NULL;   // ���ݵ�Ԫ�û�������
    UINT8*         pData       = NULL;   // ���ݵ�Ԫ
    sMtDaDt*       pDaDt       = NULL;   // ���ݵ�Ԫ��ʶ
    sMtEC*         psEC        = NULL;
    sMtTP_f*       psfTp       = NULL;   // ֡��Tp�ֶ�
    pMtFunc        pFunc       = NULL;
    sMtCmdInfor    sCmdInfor;   
    sMtTP          suTp;                 // �û���Tp�ֶ���Ϣ
    sMtPnFn        sPnFn;
    sMtComPack     sPackCommon;

    // ����
    #if MT_CFG_ENCRYPT
    UINT8*         pEncry_in   = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ���� 
    INT32          nLen_in     = 0;     // ���ĵ����ֳ�
    UINT8*         pEncry_out  = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ���
    INT32          nLen_out    = 0;     // ���ĵ����ֳ�
    #endif
    
    memset(&(sPnFn), 0x00, sizeof(sMtPnFn));
    memset(&sPackCommon, 0x00, sizeof(sMtComPack));

    if(MT_ROLE_MASTER == g_eMtRole)
    {
        eDir = MT_DIR_M2S;
    }
    else
    {
        eDir = MT_DIR_S2M;
    }

    /* ��װsMtComPack ��� */
    // ����ͨ�÷������
    pSeq2Cs = (UINT8*)malloc(MT_SEQ2CS_BYTES_MAX);
    if(!pSeq2Cs)
    {
        #ifdef MT_DBG
        DEBUG("emtLitePack() malloc failed!");
        #endif
        return MT_ERR_IO;
    }

    // ��װ�䳤�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��
    if(0 == psPack->usDataNum)
    {
        #ifdef MT_DBG
        DEBUG("emtLitePack() ucSubNum is 0!");
        #endif
        MT_FREE(pSeq2Cs);
        return MT_ERR_PROTO;
    }

    // ��װ����һ�����ݱ�ʶ�����ݵ�Ԫ���
    for(i = 0; i < psPack->usDataNum; i++)
    {
        for(j = 0; j < PN_INDEX_MAX; j++)
        {
            sPnFn.usPn[j] =  psPack->sData[i].sPnFn.usPn[j];
            sPnFn.ucFn[j] =  psPack->sData[i].sPnFn.ucFn[j];
        }

        // ȷ��ÿ��Pn ������ͬһ����Ϣ����
        bSameTeam = bmt_same_team_pn(sPnFn.usPn, NULL);
        if(FALSE == bSameTeam)
        {
            #ifdef MT_DBG
            DEBUG("emtLitePack() pn is not is same team!");
            #endif
            MT_FREE(pSeq2Cs);
            return MT_ERR_TEAM;
        }
        
        // ȷ��ÿ��Fn ������ͬһ����Ϣ����
        bSameTeam = bmt_same_team_fn(psPack->sData[i].sPnFn.ucFn, NULL);
        if(FALSE == bSameTeam)
        {
            #ifdef MT_DBG
            DEBUG("emtLitePack() Fn is not is same team!");
            #endif
            MT_FREE(pSeq2Cs);
            return MT_ERR_TEAM;
        }

        // ��������
        eAFN = psPack->eAFN;

        // ��װ���ݵ�Ԫ��ʶ
        pDaDt = (sMtDaDt*)(pSeq2Cs + usSeq2CsPos);
        eRet = emt_pnfn_to_dadt(&(sPnFn), pDaDt);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtLitePack() emt_pnfn_to_dadt() failed %d %s!", eRet, smtGetErr(eRet));
            #endif
            return eRet;
        }

        usSeq2CsPos +=  sizeof(sMtDaDt);
        /*
            �����װ���64����Fn Pn���Ӧ�����ݵ�Ԫ
            ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯�����ݣ���������������ȡ�
            ������֯��˳������Ȱ�pn��С�����ٰ�Fn��С����Ĵ��򣬼������һ����Ϣ��pi
            ��������Ϣ��Fn�Ĵ�����ٽ�����һ��pi+1�Ĵ���
        */

        // ���������
        bP0 = bmt_is_p0(psPack->sData[i].sPnFn.usPn);
        if(TRUE == bP0)
        {
             ucPnNum = 1; // 1 - p0
        }
        else
        {
             ucPnNum = PN_INDEX_MAX; // 2 - �������8��Pn 
        }
        
        // Ӧ�ò�������
        for(pi = 0; pi < ucPnNum; pi++)
        {
            if(MT_PN_NONE != psPack->sData[i].sPnFn.usPn[pi])
            {
                for(fi = 0; fi < FN_INDEX_MAX; fi++)
                {
                    if(MT_FN_NONE != psPack->sData[i].sPnFn.ucFn[fi])
                    {
                         // �ϳ�������
                        usCMD = (UINT16)((eAFN << 8) | (psPack->sData[i].sPnFn.ucFn[fi]));
                        eCmd  = (eMtCmd)usCMD; 

                        // ���������Ϣ
                        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtLitePack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            MT_FREE(pSeq2Cs);
                            return eRet;
                        }

                        // ���ݵ�Ԫ
                        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
                        pFunc = sCmdInfor.pFunc;
                        if(NULL != pFunc)
                        {
                            puData = (UINT8*)(psPack->sData[i].puApp[pi][fi]);
                            eRet = pFunc(MT_TRANS_U2F, puData, pData, &usfDataLen);
                            if(MT_OK != eRet)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtLitePack() transU2FpFunc() failed %d %s!", eRet, smtGetErr(eRet));
                                #endif
                                MT_FREE(pSeq2Cs);
                                return eRet;
                            }

                            usSeq2CsPos += usfDataLen;
                        }     
                    }
                }
            }
        }
    }

    // ����
    #if MT_CFG_ENCRYPT
    if(NULL != g_peMtEncryptFunc)
    {
        pEncry_in  = pSeq2Cs;  // ������Ҫ�ٵ���,��ȷ����Ҫ���ܵĲ���
        nLen_in    = usSeq2CsPos;
        pEncry_out = (UINT8*)malloc(MT_SEQ2CS_BYTES_MAX);
        if(!pEncry_out)
        {
            #ifdef MT_DBG
            DEBUG("emtLitePack() malloc failed!");
            #endif
            return MT_ERR_IO; 
        }
        
        eRet = g_peMtEncryptFunc(pEncry_in, nLen_in, pEncry_out, &nLen_out);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtLitePack() encrypt failed! %d", eRet);
            #endif
            MT_FREE(pEncry_out);
            return MT_ERR_ENCRYPT;
        }

        // �滻������
        memcpy((void*)pSeq2Cs, (void*)pEncry_out, nLen_out); 

        // ���³���
        usSeq2CsPos = nLen_out;

    }
    #endif

    /* ������Ϣ��AUX */
    // ����� EC
    if(TRUE == bmt_have_ec(eAFN, eDir))
    {       
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psEC = (sMtEC*)pData;
        if(MT_DIR_S2M == eDir)
        {
            psEC->ucEC1 = g_tEC.ucEC1;
            psEC->ucEC2 = g_tEC.ucEC2;
        }
        else
        {
            // ����: ��վ�ĸ��ֶ���η�װ ȫ��0 ���� 0xEE
            psEC->ucEC1 = 0x0;
            psEC->ucEC2 = 0x0;
        }
       
        usSeq2CsPos += sizeof(sMtEC);
     }
    
    // ����� pw  
    // pw������Ҫ�����б�����,����վ����,�ն���֤��ͨ����ִ��(16�ֽ�)
    if(TRUE == bmt_have_pw(eAFN, eDir))    
    {
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        memcpy((void*)pData, (void*)g_aucPw, MT_PW_LEN); 
        usSeq2CsPos += MT_PW_LEN;
    }

    // ����� TP
    if(TRUE == bmt_have_tp(eAFN, eDir))  // ����������������б�����
    {
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psfTp = (sMtTP_f *)pData;
        suTp  = psPack->sTP;
  
        //(void)emt_get_mtutp(psPack->ucPFC, &suTp); ���ϲ��װʱ���
        (void)emt_trans_tp(MT_TRANS_U2F, &suTp, psfTp);
        usSeq2CsPos += sizeof(sMtTP_f);
    }

    // �ܽ�����
    usSeq2CsLen             = usSeq2CsPos;
    sPackCommon.sAddr       = psPack->sAddress;
    sPackCommon.sCtrl       = psPack->sCtrl;;
    sPackCommon.sSEQ        = psPack->sSEQ;   
    sPackCommon.usSeq2CsLen = usSeq2CsLen;
    sPackCommon.pSeq2Cs     = pSeq2Cs;

    // ͨ��ͨ�÷������pack
    eRet = emt_pack_common(eAFN,  &sPackCommon, pusLen, pOutBuf);   
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtLitePack() emt_pack_common failed:%s!", smtGetErr(eRet));
        #endif

        MT_FREE(pSeq2Cs);
        // �ͷż��ܲ���������ڴ�
        #if MT_CFG_ENCRYPT
        MT_FREE(pEncry_out);
        #endif
        return eRet;
    }

    MT_FREE(pSeq2Cs);
    
    // �ͷż��ܲ���������ڴ�
    #if MT_CFG_ENCRYPT
    MT_FREE(pEncry_out);
    #endif
    
    return MT_OK;
}
   
/*****************************************************************************
 �� �� ��  : emtLiteUnPack
 ��������  : ʵ�ֻ����ı��Ľ��װ, ��������㷨�ӿ�
             �ô���Ӧ�ò����ݽ��� ���ܺ���ܿ��ܻ�ı䳤��,
             ���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 �������  : smtLitePack *psUnpack  
             UINT8* pInBuf          
             UINT16 usLen           
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtUnPack
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtLiteUnPack(smtLitePack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    if(!psUnpack || !pInBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    if(usLen < MT_FRM_LEN_MIN)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() input frame length is too short usLen = %d", usLen);
        #endif 
        return MT_ERR_UNCOMP;
    }
    
    eMtErr      eRet            = MT_OK;
    eMtDir      eDir            = MT_DIR_UNKOWN;
    eMtAFN      eAFN            = AFN_NULL;
    eMtCmd      eCmd            = CMD_AFN_F_UNKOWN;
    BOOL        bP0             = FALSE;
    BOOL        bTp             = FALSE;   
    BOOL        bEc             = FALSE;
    sMtfComHead *psHead         = NULL;
    sMtDaDt     *pDaDt          = NULL;
    UINT8       *pucTemp        = NULL;
    sMtEC       *psEC           = NULL;
    uMtApp      *puApp          = NULL;
    pMtFunc     pFunc           = NULL;
    UINT8       ucFn            = 0;
    UINT8       ucPnCycMax      = 0;        // ��Pnѭ�������ֵ
    UINT16      usPn            = 0;
    UINT16      usUsrdLen       = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16      usUsrdLenTotal  = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16      usAuxLen        = 0;        // ������֡��EcPwTp֡��ļ�����Ĳ��ֳ�
    UINT16      usLenUserField  = 0;        // �û�����������       
    UINT16      usDataNum       = 0;     // ���ݵ�Ԫ��ĸ���
    INT32       nLenUserField   = 0;        // ÿ�ν���һ�����������ݵ�Ԫ����û��������ֳ� 
    INT32       i               = 0;
    INT32       fi              = 0;        // Fn������
    INT32       pi              = 0;        // Pn������

    sMtPnFn     sPnFn;
    sMtCmdInfor sCmdInfor;

    // �жϸ�֡�Ƿ���һ����Ч��֡
    eRet = emtIsValidPack(pInBuf, usLen);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() input is not a valid pack eRet = %d", eRet);
        #endif 
        return MT_ERR_PACK;
    }

    // ����ͷ
    psHead = (sMtfComHead *)pInBuf;
    usLenUserField =  ((psHead->L2 << 6) & 0x3FC0 )| (psHead->L1 & 0x003F); 
  
    // ��ַ��
    eRet = emt_trans_address(MT_TRANS_F2U, &(psUnpack->sAddress), &(psHead->A));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() emt_trans_addr() error = %d\n", eRet);
        #endif
        return eRet;
    }

    // ������
    eRet = emt_trans_ctrl(MT_TRANS_F2U, &(psUnpack->sCtrl), &(psHead->C));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() emt_trans_ctrl() error = %d\n", eRet);
        #endif
        return eRet;
    }

    //
 
    // SEQ
    eRet = emt_trans_seq(MT_TRANS_F2U, &psUnpack->sSEQ, (sMtSEQ_f*)&(psHead->SEQ));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtLiteUnPack() emt_trans_seq() error = %d\n", eRet);
        #endif
        return eRet;
    }

    bTp = psUnpack->sSEQ.bTpv;

    // AFN
    eAFN = (eMtAFN)(psHead->AFN);
    psUnpack->eAFN = eAFN;

    // ������˸������Ӧ�ò������ֳ�
    eDir = psUnpack->sCtrl.eDir;
    if(eDir == MT_DIR_S2M)
    {
         bEc = psUnpack->sCtrl.bAcd_Fcb;
    }
    else
    {
         bEc = bmt_have_ec(eAFN, eDir);
    }
    
    usAuxLen = usmt_get_aux_len(eAFN, eDir, bEc, bTp);
    nLenUserField = (INT32)(usLenUserField - usAuxLen - MT_CANS_LEN);   
    
    #if 0
    #ifdef MT_DBG
    DEBUG("emtLiteUnPack() nLenUserField = %d\n", nLenUserField);
    #endif
    #endif
    
    // Ӧ�ò����� ���ݵ�Ԫ��ʶ�����ݵ�Ԫ��
    pucTemp = (UINT8*)((UINT8*)&(psHead->SEQ) + 1);
    while(nLenUserField > 0)
    {
        // ��ʼ��
        usUsrdLen = nLenUserField;
        
        // ���ݵ�Ԫ��ʶ
        pDaDt = (sMtDaDt*)pucTemp;
        eRet = emt_dadt_to_pnfn(pDaDt, &sPnFn);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtLiteUnPack() emt_dadt_to_pnfn() error = %d\n", eRet);
            #endif
            return eRet;
        }

        pucTemp += sizeof(sMtDaDt);
       
        bP0 = bmt_is_p0(sPnFn.usPn);
        if(TRUE == bP0)
        {  
            //P0���������ѭ�� 
            ucPnCycMax = 1;
        }
        else       
        {  
            // ����P0�������˫��ѭ��
            ucPnCycMax = 8;
        }

        psUnpack->sData[i].sPnFn = sPnFn;
        for(pi = 0; pi < ucPnCycMax; pi++)
        {
            usPn = sPnFn.usPn[pi];
            if(MT_PN_NONE == usPn)
            {
                // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
            }
            else if(usPn < MT_PN_MIN || usPn > MT_PN_MAX)
            {
                // �Ƿ�Fn
                #ifdef MT_DBG
                DEBUG("emtLiteUnPack() usPn error Pn = %d\n", usPn);
                #endif
                return MT_ERR_PARA;
            }
            else
            {
                for(fi = 0; fi < 8; fi++)
                {
                    ucFn = sPnFn.ucFn[fi];
                    if(MT_FN_NONE == ucFn)
                    {
                        // ���������û�и�FN, �Ϸ���������
                    }
                    else if(ucFn < MT_FN_MIN || ucFn > MT_FN_MAX)
                    {
                        // �Ƿ�Fn
                        #ifdef MT_DBG
                        DEBUG("emtLiteUnPack() ucFn error Fn = %d\n", ucFn);
                        #endif
                        return MT_ERR_PARA;
                    }
                    else
                    {
                        eCmd = (eMtCmd)((eAFN << 8) | (sPnFn.ucFn[fi]));
                        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtLiteUnPack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            return eRet;
                        }
         
                        pFunc = sCmdInfor.pFunc;
                        if(NULL != pFunc)
                        {
                            // �����ڴ�,���Ӧ�ò�����, �ɵ������ͷŸ��ڴ�, �ú����ڲ��ͷ�
                            puApp = (uMtApp*)malloc(sizeof(uMtApp));
                            if(!puApp)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtLiteUnPack() malloc failed!");
                                #endif
                                return MT_ERR_IO; 
                            }

                            psUnpack->sData[i].puApp[pi][fi] = puApp;
                            
                            eRet = pFunc(MT_TRANS_F2U, (void*)(psUnpack->sData[i].puApp[pi][fi]), (void*)pucTemp, &usUsrdLen); 
                            if(eRet != MT_OK)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtLiteUnPack() transfunc() error = %d\n", eRet);
                                #endif
                                return eRet;
                            }

                            // ����ָ�����
                            pucTemp += usUsrdLen;

                            // ��¼�����ܳ�
                            usUsrdLenTotal += usUsrdLen;
                        }
                    }
                }
            }
        }
           
        // �������
        usDataNum++;
        
        // ���ȼ���
        nLenUserField -= sizeof(sMtDaDt);
        nLenUserField -= usUsrdLenTotal;

        // ���ü���
        usUsrdLenTotal = 0;
        i++;
    }
    
    // �����EC
    if(TRUE == bEc)
    {
        psEC = (sMtEC*)pucTemp;
        psUnpack->sEC.ucEC1 = psEC->ucEC1;
        psUnpack->sEC.ucEC2 = psEC->ucEC2;
        pucTemp += sizeof(sMtEC);
    }
    
    // �����PW
    if(TRUE == bmt_have_pw((eMtAFN)(psHead->AFN), eDir))
    {
        memcpy((void*)(psUnpack->acPW), (void*)pucTemp, MT_PW_LEN);
        pucTemp += MT_PW_LEN;
    }

    // �����TP
    if(TRUE == bTp)
    {
        eRet = emt_trans_tp(MT_TRANS_F2U, &(psUnpack->sTP), (sMtTP_f*)pucTemp);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG
            DEBUG("eMtUnpack() emt_trans_tp() error = %d\n", eRet);
            #endif
            return eRet;
        }

        //pucTemp += sizeof(sMtfTp);
    }

    psUnpack->usDataNum = usDataNum;
    return MT_OK;
}


/*****************************************************************************
 �� �� ��  : emtPackLite
 ��������  : ��װ����(�߼��ӿ�)
 ʵ�ֹ���  : (1) ʵ����ɢ����Ϣ������Ϣ����Զ�����
             (2) �Զ�ȡ��ǰ��ʱ�����ϳ�tp
             (3) Ϊ�ϲ�������صĲ��� �繦�����
             
 �������  : smtPack* psPack  
             UINT16* pusLen   
             UINT8* pOutBuf   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtLitePack()
 ��������  : emtPack()
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��7�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtPackLite(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf)
{
    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtPackLite() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtPackLite() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    eMtErr         eRet         = MT_OK;
    eMtCmd         eCmd         = CMD_AFN_F_UNKOWN;
    eMtDir         eDir         = MT_DIR_UNKOWN;
    eMtAFN         eAFN         = AFN_NULL;
    eMtAFN         eAFNCmd      = AFN_NULL;  // �����Ӧ��AFN
    UINT8          ucTeamPn     = 0xFF;
    UINT8          ucTeamPnBase = 0xFF;
    UINT8          ucTeamFn     = 0xFF;
    UINT8          ucTeamFnBase = 0xFF;
    UINT8          ucFn         = 0;
    UINT16         usPn         = 0;
    INT32          FnIndex      = 0;
    INT32          PnIndex      = 0;
    INT32          i            = 0;
    INT32          j            = 0;
    INT32          k            = 0;
    INT32          nDaDtNum     = 0;      // ��װpackbase����Ϣ��ʶ��64�����ݵ�Ԫ����ܸ���
    INT32          nDaDtPos     = 0;      // ÿ��Ӧ����packbase����Ϣ��ʶ�������
    BOOL           bFindDaDt    = FALSE;  // �Ƿ��ҵ�֮ǰ���ڵ���
    BOOL           bAcd_Fcb     = FALSE;
    BOOL           bPW          = FALSE;  // ��û��Pw �ֶ�
    BOOL           bEC          = FALSE;  // ��û��EC �ֶ�
    BOOL           bTP          = FALSE;  // �Ƿ���Tp �ֶ�
    BOOL           bInFn8       = FALSE;
    BOOL           bInPn8       = FALSE;
    UINT8*         pMemBase     = NULL;
    smtLitePack*   psLitePack   = NULL;
    sMtCtrl        sCtrl;
    sMtTP          sTp;                 // �û���Tp�ֶ���Ϣ
    sMtCmdInfor    sCmdInfor;

    // Ϊ���������ڴ�
    pMemBase  = (UINT8*)malloc(MT_USER_MAX);
    if(!pMemBase)
    { 
        #ifdef MT_DBG
        DEBUG("emtPackLite() malloc failed!");
        #endif
        return MT_ERR_IO; 
    }

    psLitePack = (smtLitePack*)pMemBase;

    // ��װ�� smtLitePack ����
    eDir = psPack->eDir;
    eAFN = psPack->eAFN;

    // Afn
    psLitePack->eAFN = eAFN;

    // SEQ
    psLitePack->sSEQ.bTpv  = bmt_have_tp(eAFN, eDir);
    psLitePack->sSEQ.bCon  = bmt_need_con(eAFN, eDir);
    psLitePack->sSEQ.ePos  = psPack->ePos;
    psLitePack->sSEQ.ucSeq = psPack->ucSeq;

    // ��ַ��
    psLitePack->sAddress = psPack->sAddress;

    // ������
    bAcd_Fcb = psPack->bAcdFcb;
    
    eRet = emt_get_ctrl(eAFN, eDir, psPack->ePRM, bAcd_Fcb, &sCtrl);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtPackLite() emt_get_ctrl() failed! %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }
    
    psLitePack->sCtrl = sCtrl;
    
    // pw 
    bPW = bmt_have_pw(eAFN, eDir);
    if(TRUE == bPW)
    {
       //memcpy(psBasePack->acPW, psPack->acPW, MT_PW_LEN);
       memcpy(psLitePack->acPW, g_aucPw, MT_PW_LEN);
    }

    // ec
    bEC = bmt_have_ec(eAFN, eDir);
    if(TRUE == bEC)
    {
        psLitePack->sEC.ucEC1 = g_tEC.ucEC1;
        psLitePack->sEC.ucEC2 = g_tEC.ucEC2;
    }

    // tp 
    bTP = bmt_have_tp(eAFN, eDir);
    if(TRUE == bTP)
    {
        (void)emt_get_tp(psPack->sTP.ucPFC, &sTp);
        psLitePack->sTP.sDDHHmmss = sTp.sDDHHmmss;
        psLitePack->sTP.ucPermitDelayMinutes = sTp.ucPermitDelayMinutes;
        // psBasePack->sTP.ucPFC = psBasePack->sTP.ucPFC;// ����Ѿ��ڷ�װʱ���û����
    }

    // ����ɢ�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��ϳ���
    for(i = 0; i < psPack->usDataNum; i++)
    {
        eCmd = psPack->sData[i].eCmd;
        
        // �жϸ������Ƿ��ǺϷ��ġ���֧�ֵ�
        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG
            DEBUG("emtPackLite() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
            #endif
            MT_FREE(pMemBase);
            return eRet;
        }

        // �жϸ������Ƿ�����AFN��������
        eAFNCmd = eGetCmdAfn(eCmd);
        if(eAFNCmd != eAFN)  
        {
            MT_FREE(pMemBase);
            #ifdef MT_DBG
            DEBUG("emtPackLite() cmd is not is a same Afn");
            #endif
            return MT_ERR_TEAM;
        }

        usPn = psPack->sData[i].usPN;
        ucFn = ucGetCmdFn(eCmd);

        /*
            �жϸúϷ������ݵ�Ԫ��ʶ,�����ݵ�Ԫ�Ƿ��Ѿ�����Ӧ��λ�� psBasePack
            ����ظ�,���߸���ǰ��, Da2 �벻ͬ��Dt2���, 
            �������ͬ�ı�ʶ�����ݵ�Ԫ��, ����nDaTaNum�ĸ���
        */
        
        nDaDtPos = nDaDtNum;
        
        // ��ʼ��PnFn��
        for(k = 0; k < 8; k++)
        {
            psLitePack->sData[nDaDtPos].sPnFn.ucFn[k] = MT_FN_NONE;
            psLitePack->sData[nDaDtPos].sPnFn.usPn[k] = MT_PN_NONE;
        }
             
        for(j = 0; j < nDaDtNum; j++)
        {
            // �ҵ���nDataPos���ҵ���λ��
            // ���ж�Pn�Ƿ���ͬһ��
            ucTeamPn     = ucmt_get_pn_team(usPn);
            ucTeamPnBase = ucmt_get_pn8_team(psLitePack->sData[j].sPnFn.usPn);
            
            if(ucTeamPn == ucTeamPnBase)
            {
                // ���ж�Fn�Ƿ�����ͬһ����
                ucTeamFn     = ucmt_get_fn_team(ucFn);
                ucTeamFnBase = ucmt_get_fn8_team(psLitePack->sData[j].sPnFn.ucFn);
                       
                if(ucTeamFn == ucTeamFnBase)
                {
                    //bInPn8 = bmt_in_pn8(usPn, psLitePack->sData[j].sPnFn.usPn);
                    bInFn8 = bmt_in_fn8(ucFn, psLitePack->sData[j].sPnFn.ucFn);

                   // if(TRUE == bInPn8 && TRUE == bInFn8)
					if(TRUE == bInFn8)
                    {
                        bFindDaDt = TRUE;
                        nDaDtPos  = j;
                        break;
                    }
                }
            }
        }

        // δ�ҵ���nDaTaNum++
        if(FALSE == bFindDaDt)
        {
            nDaDtNum  += 1; // ����һ��  
        }

        // ���� DaTa�鼰���ݵ�Ԫ
        if(0 == usPn)
        {
            PnIndex = 0;
            
            for(k = 0; k < 8; k++)
            {
                psLitePack->sData[nDaDtPos].sPnFn.usPn[k] = 0;
            }
        }
        else
        {
            PnIndex = (usPn - 1) % 8; 
            psLitePack->sData[nDaDtPos].sPnFn.usPn[PnIndex] = usPn;
        }
      
        FnIndex = (ucFn - 1) % 8;
        psLitePack->sData[nDaDtPos].sPnFn.ucFn[FnIndex] = ucFn;

        // ���ݵ�Ԫ 
        psLitePack->sData[nDaDtPos].puApp[PnIndex][FnIndex] =  &(psPack->sData[i].uApp);

        // ����δ�ҵ�״̬
        bFindDaDt = FALSE;
        
    }

    psLitePack->usDataNum = nDaDtNum;

    // ���� emtLitePack()
    eRet = emtLitePack(psLitePack, pusLen , pOutBuf);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtPackLite() emtLitePack() failed! code : %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }

    MT_FREE(pMemBase);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtUnPackLite
 ��������  : Э�����(�߼��ӿ�)
             ��emtBaseUnPack������������ϢsmtBasePack, ��װ�ɸ߼�smtPack
             
             (1)����Ҫ��Ϣ��ȡ
             (2)��PnFn���ݵ�Ԫ��ȡ����ɢ��
             
 �������  : smtPack *psUnpack  
             UINT8* pInBuf      
             UINT16 usLen      
             
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtLiteUnPack()
 ��������  : emtUnPack()
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtUnPackLite(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    if(!psUnpack || !pInBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPackLite() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPackLite() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }
    
    eMtErr       eRet          = MT_OK;
    eMtCmd       eCmd          = CMD_AFN_F_UNKOWN;
    eMtAFN       eAFN          = AFN_NULL;
    UINT8*       pMemBase      = NULL;
    smtLitePack* pLiteUnpack   = NULL;
    uMtApp      *puApp         = NULL;
    BOOL         bP0           = FALSE;
    INT32        i             = 0;
    INT32        j             = 0;
    INT32        fi            = 0;
    INT32        pi            = 0;
    INT32        PnCyc         = 0;
    UINT16       usPn          = 0;
    UINT8        ucFn          = 0;
    sMtCmdInfor  sCmdInfor;

    pMemBase = (UINT8*)malloc(MT_USER_MAX);
    if(!pMemBase)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPackLite() malloc failed!");
        #endif
        return MT_ERR_IO;
    }
    
    pLiteUnpack = (smtLitePack*)pMemBase;

    // ���ý�������
    eRet = emtLiteUnPack(pLiteUnpack, pInBuf, usLen);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPackLite() emtLiteUnPack failed! %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }

    // ת�����ݽṹ
    eAFN               = pLiteUnpack->eAFN;
    psUnpack->sAddress = pLiteUnpack->sAddress;
    psUnpack->eAFN     = eAFN;
    psUnpack->eDir     = pLiteUnpack->sCtrl.eDir;
    psUnpack->ePRM     = pLiteUnpack->sCtrl.ePRM;
    psUnpack->ePos     = pLiteUnpack->sSEQ.ePos;
    psUnpack->bCon     = pLiteUnpack->sSEQ.bCon;
    psUnpack->ucSeq    = pLiteUnpack->sSEQ.ucSeq;
    psUnpack->bAcdFcb  = pLiteUnpack->sCtrl.bAcd_Fcb;
    psUnpack->bPW      = bmt_have_pw(psUnpack->eAFN, psUnpack->eDir);
    psUnpack->bEC      = bmt_have_ec(psUnpack->eAFN, psUnpack->eDir);
    psUnpack->bTP      = pLiteUnpack->sSEQ.bTpv;

    if(TRUE == psUnpack->bPW)
    {
        memcpy(psUnpack->acPW, pLiteUnpack->acPW, MT_PW_LEN);
    }
    
    if(TRUE == psUnpack->bEC)
    {
        psUnpack->sEC = pLiteUnpack->sEC;
    }

    if(TRUE == psUnpack->bTP)
    {
        psUnpack->sTP = pLiteUnpack->sTP;
    }

    // Ӧ�ò�����
    for(i = 0; i < pLiteUnpack->usDataNum; i++)
    {
        bP0 = bmt_is_p0(pLiteUnpack->sData[i].sPnFn.usPn);
        PnCyc = ((bP0 == TRUE) ? 1 : 8);
        
        for(pi = 0; pi < PnCyc; pi++)
        {
            usPn = pLiteUnpack->sData[i].sPnFn.usPn[pi];
            if(MT_PN_NONE == usPn)
            {
                // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
            }
            else if(usPn < MT_PN_MIN || usPn > MT_PN_MAX)
            {
                // �Ƿ�Fn
                #ifdef MT_DBG
                DEBUG("emtUnPackLite() usPn error Pn = %d\n", usPn);
                #endif
                MT_FREE(pMemBase);
                return MT_ERR_PARA;
            }
            else
            {
                #if 0
                #ifdef MT_DBG
                for(fi = 0; fi < 8; fi++)
                {   ucFn = pUnpackBase->sData[i].sPnFn.ucFn[fi];                
                    DEBUG("emtUnPack() sData[%d].sPnFn.ucFn[%d] = %d",i, fi, ucFn);
                }
                #endif
                #endif
              
                for(fi = 0; fi < 8; fi++)
                {
                    ucFn = pLiteUnpack->sData[i].sPnFn.ucFn[fi];
                    if(MT_FN_NONE == ucFn)
                    {
                        // ���������û�и�FN, �Ϸ���������
                    }
                    else if(ucFn < MT_FN_MIN || ucFn > MT_FN_MAX)
                    {
                        // �Ƿ�Fn
                        #ifdef MT_DBG
                        DEBUG("emtUnPackLite() ucFn error Fn = %d\n", ucFn);
                        #endif
                        MT_FREE(pMemBase);
                        return MT_ERR_PARA;
                    }
                    else
                    {
                        eCmd = (eMtCmd)((eAFN << 8) | ucFn);
                        eRet = eMtGetCmdInfor(eCmd, psUnpack->eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtUnPackLite() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            MT_FREE(pMemBase);
                            return eRet;
                        }
                        
                        // һ����Ч�����ݵ�Ԫ��ʶ��
                        psUnpack->sData[j].eCmd  = eCmd;
                        psUnpack->sData[j].usPN  = usPn;

                        if(NULL != sCmdInfor.pFunc)
                        {
                            psUnpack->sData[j].bApp = TRUE;
                            puApp = pLiteUnpack->sData[i].puApp[pi][fi];
                            if(!puApp)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtUnPackLite() app date is null");
                                #endif
                                MT_FREE(pMemBase);
                                return MT_ERR_PARA;
                            }

                            memcpy((void*)&(psUnpack->sData[j].uApp), (void*)puApp, sizeof(uMtApp));
                            MT_FREE(puApp);
                        }
                        else
                        {
                            psUnpack->sData[j].bApp = FALSE;
                        }
                    
                        j++;                        
                    }
                }
            }
        }
    }

    psUnpack->usDataNum = j;
    MT_FREE(pMemBase);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtBasePack
 ��������  : ʵ�ֻ����ı��ķ�װ, ��������㷨�ӿ�
             �ô���Ӧ�ò����ݼ��� ���ܺ���ܿ��ܻ��
             �䳤��,���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 �������  : smtBasePack* psPack  
             UINT16* pusLen       
             UINT8* pOutBuf       
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emt_pack_common
 ��������  : emtPackBase
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtBasePack(smtBasePack* psPack, UINT16* pusLen, UINT8* pOutBuf)
{
    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtBasePack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtBasePack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    eMtErr         eRet        = MT_OK;
    eMtCmd         eCmd        = CMD_AFN_F_UNKOWN;
    eMtDir         eDir        = MT_DIR_UNKOWN;
    eMtAFN         eAFN        = AFN_NULL;
    BOOL           bSameTeam   = FALSE;
    BOOL           bP0         = FALSE;
    UINT8          ucPnNum     = 0;
    UINT16         usSeq2CsLen = 0;
    UINT16         usSeq2CsPos = 0; 
    UINT16         usfDataLen  = 0;      // ֡�����ݵ�Ԫ�ֳ�
    UINT16         usCMD       = 0;
    INT32          i           = 0;
    INT32          j           = 0;
    INT32          fi          = 0;
    INT32          pi          = 0;
    UINT8*         pSeq2Cs     = NULL;
    UINT8*         puData      = NULL;   // ���ݵ�Ԫ�û�������
    UINT8*         pData       = NULL;   // ���ݵ�Ԫ
    sMtDaDt*       pDaDt       = NULL;   // ���ݵ�Ԫ��ʶ
    sMtEC*         psEC        = NULL;
    sMtTP_f*       psfTp       = NULL;   // ֡��Tp�ֶ�
    pMtFunc        pFunc       = NULL;
    sMtCmdInfor    sCmdInfor;   
    sMtTP          suTp;                 // �û���Tp�ֶ���Ϣ
    sMtPnFn        sPnFn;
    sMtComPack     sPackCommon;

    // ����
    #if MT_CFG_ENCRYPT
    UINT8*         pEncry_in   = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ���� 
    INT32          nLen_in     = 0;     // ���ĵ����ֳ�
    UINT8*         pEncry_out  = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ���
    INT32          nLen_out    = 0;     // ���ĵ����ֳ�
    #endif
    
    memset(&(sPnFn), 0x00, sizeof(sMtPnFn));
    memset(&sPackCommon, 0x00, sizeof(sMtComPack));

    if(MT_ROLE_MASTER == g_eMtRole)
    {
        eDir = MT_DIR_M2S;
    }
    else
    {
        eDir = MT_DIR_S2M;
    }

    /* ��װsMtComPack ��� */
    // ����ͨ�÷������
    pSeq2Cs = (UINT8*)malloc(MT_SEQ2CS_BYTES_MAX);
    if(!pSeq2Cs)
    {
        #ifdef MT_DBG
        DEBUG("emtBasePack() malloc failed!");
        #endif
        return MT_ERR_IO;
    }

    // ��װ�䳤�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��
    if(0 == psPack->usDataNum)
    {
        #ifdef MT_DBG
        DEBUG("emtBasePack() ucSubNum is 0!");
        #endif
        MT_FREE(pSeq2Cs);
        return MT_ERR_PROTO;
    }

    // ��װ����һ�����ݱ�ʶ�����ݵ�Ԫ���
    for(i = 0; i < psPack->usDataNum; i++)
    {
        for(j = 0; j < PN_INDEX_MAX; j++)
        {
            sPnFn.usPn[j] =  psPack->sData[i].sPnFn.usPn[j];
            sPnFn.ucFn[j] =  psPack->sData[i].sPnFn.ucFn[j];
        }

        // ȷ��ÿ��Pn ������ͬһ����Ϣ����
        bSameTeam = bmt_same_team_pn(sPnFn.usPn, NULL);
        if(FALSE == bSameTeam)
        {
            #ifdef MT_DBG
            DEBUG("emtBasePack() pn is not is same team!");
            #endif
            MT_FREE(pSeq2Cs);
            return MT_ERR_TEAM;
        }
        
        // ȷ��ÿ��Fn ������ͬһ����Ϣ����
        bSameTeam = bmt_same_team_fn(psPack->sData[i].sPnFn.ucFn, NULL);
        if(FALSE == bSameTeam)
        {
            #ifdef MT_DBG
            DEBUG("emtBasePack() Fn is not is same team!");
            #endif
            MT_FREE(pSeq2Cs);
            return MT_ERR_TEAM;
        }

        // ��������
        eAFN = psPack->eAFN;

        // ��װ���ݵ�Ԫ��ʶ
        pDaDt = (sMtDaDt*)(pSeq2Cs + usSeq2CsPos);
        eRet = emt_pnfn_to_dadt(&(sPnFn), pDaDt);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtBasePack() emt_pnfn_to_dadt() failed %d %s!", eRet, smtGetErr(eRet));
            #endif
            return eRet;
        }

        usSeq2CsPos +=  sizeof(sMtDaDt);
        /*
            �����װ���64����Fn Pn���Ӧ�����ݵ�Ԫ
            ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯�����ݣ���������������ȡ�
            ������֯��˳������Ȱ�pn��С�����ٰ�Fn��С����Ĵ��򣬼������һ����Ϣ��pi
            ��������Ϣ��Fn�Ĵ�����ٽ�����һ��pi+1�Ĵ���
        */

        // ���������
        bP0 = bmt_is_p0(psPack->sData[i].sPnFn.usPn);
        if(TRUE == bP0)
        {
             ucPnNum = 1;            // 1 - p0
        }
        else
        {
             ucPnNum = PN_INDEX_MAX; // 2 - �������8��Pn 
        }
        
        // Ӧ�ò�������
        for(pi = 0; pi < ucPnNum; pi++)
        {
            if(MT_PN_NONE != psPack->sData[i].sPnFn.usPn[pi])
            {
                for(fi = 0; fi < FN_INDEX_MAX; fi++)
                {
                    if(MT_FN_NONE != psPack->sData[i].sPnFn.ucFn[fi])
                    {
                         // �ϳ�������
                        usCMD = (UINT16)((eAFN << 8) | (psPack->sData[i].sPnFn.ucFn[fi]));
                        eCmd  = (eMtCmd)usCMD; 

                        // ���������Ϣ
                        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtBasePack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            MT_FREE(pSeq2Cs);
                            return eRet;
                        }

                        // ���ݵ�Ԫ
                        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
                        pFunc = sCmdInfor.pFunc;
                        if(NULL != pFunc)
                        {
                            puData = (UINT8*)&(psPack->sData[i].uApp[pi][fi]);
                            eRet = pFunc(MT_TRANS_U2F, puData, pData, &usfDataLen);
                            if(MT_OK != eRet)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtBasePack() transU2FpFunc() failed %d %s!", eRet, smtGetErr(eRet));
                                #endif
                                MT_FREE(pSeq2Cs);
                                return eRet;
                            }

                            usSeq2CsPos += usfDataLen;
                        }     
                    }
                }
            }
        }
    }

    // ����
    #if MT_CFG_ENCRYPT
    if(NULL != g_peMtEncryptFunc)
    {
        pEncry_in  = pSeq2Cs;  // ������Ҫ�ٵ���,��ȷ����Ҫ���ܵĲ���
        nLen_in    = usSeq2CsPos;
        pEncry_out = (UINT8*)malloc(MT_SEQ2CS_BYTES_MAX);
        if(!pEncry_out)
        {
            #ifdef MT_DBG
            DEBUG("emtBasePack() malloc failed!");
            #endif
            return MT_ERR_IO; 
        }
        
        eRet = g_peMtEncryptFunc(pEncry_in, nLen_in, pEncry_out, &nLen_out);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtBasePack() encrypt failed! %d", eRet);
            #endif
            MT_FREE(pEncry_out);
            return MT_ERR_ENCRYPT;
        }

        // �滻������
        memcpy((void*)pSeq2Cs, (void*)pEncry_out, nLen_out); 

        // ���³���
        usSeq2CsPos = nLen_out;

    }
    #endif

    /* ������Ϣ��AUX */
    // ����� EC
    if(TRUE == bmt_have_ec(eAFN, eDir))
    {       
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psEC = (sMtEC*)pData;
        if(MT_DIR_S2M == eDir)
        {
            psEC->ucEC1 = g_tEC.ucEC1;
            psEC->ucEC2 = g_tEC.ucEC2;
        }
        else
        {
            // ����: ��վ�ĸ��ֶ���η�װ ȫ��0 ���� 0xEE
            psEC->ucEC1 = 0x0;
            psEC->ucEC2 = 0x0;
        }
       
        usSeq2CsPos += sizeof(sMtEC);
     }
    
    // ����� pw  
    // pw������Ҫ�����б�����,����վ����,�ն���֤��ͨ����ִ��(16�ֽ�)
    if(TRUE == bmt_have_pw(eAFN, eDir))    
    {
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        memcpy((void*)pData, (void*)g_aucPw, MT_PW_LEN); 
        usSeq2CsPos += MT_PW_LEN;
    }

    // ����� TP
    if(TRUE == bmt_have_tp(eAFN, eDir))  // ����������������б�����
    {
        pData = (UINT8*)(pSeq2Cs + usSeq2CsPos);
        psfTp = (sMtTP_f *)pData;
        suTp  = psPack->sTP;
  
        //(void)emt_get_mtutp(psPack->ucPFC, &suTp); ���ϲ��װʱ���
        (void)emt_trans_tp(MT_TRANS_U2F, &suTp, psfTp);
        usSeq2CsPos += sizeof(sMtTP_f);
    }

    // �ܽ�����
    usSeq2CsLen             = usSeq2CsPos;
    sPackCommon.sAddr       = psPack->sAddress;
    sPackCommon.sCtrl       = psPack->sCtrl;;
    sPackCommon.sSEQ        = psPack->sSEQ;   
    sPackCommon.usSeq2CsLen = usSeq2CsLen;
    sPackCommon.pSeq2Cs     = pSeq2Cs;

    // ͨ��ͨ�÷������pack
    eRet = emt_pack_common(eAFN,  &sPackCommon, pusLen, pOutBuf);   
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtBasePack() emt_pack_common failed:%s!", smtGetErr(eRet));
        #endif

        MT_FREE(pSeq2Cs);
        // �ͷż��ܲ���������ڴ�
        #if MT_CFG_ENCRYPT
        MT_FREE(pEncry_out);
        #endif
        return eRet;
    }

    MT_FREE(pSeq2Cs);
    
    // �ͷż��ܲ���������ڴ�
    #if MT_CFG_ENCRYPT
    MT_FREE(pEncry_out);
    #endif
    
    return MT_OK;
}
         
/*****************************************************************************
 �� �� ��  : emtBaseUnPack
 ��������  : ʵ�ֻ����ı��Ľ��װ, ��������㷨�ӿ�
             �ô���Ӧ�ò����ݽ��� ���ܺ���ܿ��ܻ�ı䳤��,
             ���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 �������  : smtBasePack *psUnpack  
             UINT8* pInBuf          
             UINT16 usLen           
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtUnPackBase
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtBaseUnPack(smtBasePack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    if(!psUnpack || !pInBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    if(usLen < MT_FRM_LEN_MIN)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() input frame length is too short usLen = %d", usLen);
        #endif 
        return MT_ERR_UNCOMP;
    }
    
    eMtErr      eRet            = MT_OK;
    eMtDir      eDir            = MT_DIR_UNKOWN;
    eMtAFN      eAFN            = AFN_NULL;
    eMtCmd      eCmd            = CMD_AFN_F_UNKOWN;
    BOOL        bP0             = FALSE;
    BOOL        bTp             = FALSE;   
    BOOL        bEc             = FALSE;
    sMtfComHead *psHead         = NULL;
    sMtDaDt     *pDaDt          = NULL;
    UINT8       *pucTemp        = NULL;
    sMtEC       *psEC           = NULL;
    pMtFunc     pFunc           = NULL;
    UINT8       ucFn            = 0;
    UINT8       ucPnCycMax      = 0;        // ��Pnѭ�������ֵ
    UINT16      usPn            = 0;
    UINT16      usUsrdLen       = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16      usUsrdLenTotal  = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16      usAuxLen        = 0;        // ������֡��EcPwTp֡��ļ�����Ĳ��ֳ�
    UINT16      usLenUserField  = 0;        // �û�����������       
    UINT16      usDataNum       = 0;     // ���ݵ�Ԫ��ĸ���
    INT32       nLenUserField   = 0;        // ÿ�ν���һ�����������ݵ�Ԫ����û��������ֳ� 
    INT32       i               = 0;
    INT32       fi              = 0;        // Fn������
    INT32       pi              = 0;        // Pn������
    sMtPnFn     sPnFn;
    sMtCmdInfor sCmdInfor;

    // �жϸ�֡�Ƿ���һ����Ч��֡
    eRet = emtIsValidPack(pInBuf, usLen);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() input is not a valid pack eRet = %d", eRet);
        #endif 
        return MT_ERR_PACK;
    }

    // ����ͷ
    psHead = (sMtfComHead *)pInBuf;
    usLenUserField =  ((psHead->L2 << 6) & 0x3FC0 )| (psHead->L1 & 0x003F); 
  
    // ��ַ��
    eRet = emt_trans_address(MT_TRANS_F2U, &(psUnpack->sAddress), &(psHead->A));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() emt_trans_addr() error = %d\n", eRet);
        #endif
        return eRet;
    }

    // ������
    eRet = emt_trans_ctrl(MT_TRANS_F2U, &(psUnpack->sCtrl), &(psHead->C));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() emt_trans_ctrl() error = %d\n", eRet);
        #endif
        return eRet;
    }

    // SEQ
    eRet = emt_trans_seq(MT_TRANS_F2U, &psUnpack->sSEQ, (sMtSEQ_f*)&(psHead->SEQ));
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtBaseUnPack() emt_trans_seq() error = %d\n", eRet);
        #endif
        return eRet;
    }

    bTp = psUnpack->sSEQ.bTpv;
    eAFN = (eMtAFN)(psHead->AFN);
    psUnpack->eAFN = eAFN;

    // ������˸������Ӧ�ò������ֳ�
    eDir = psUnpack->sCtrl.eDir;
    if(eDir == MT_DIR_S2M)
    {
         bEc = psUnpack->sCtrl.bAcd_Fcb;
    }
    else
    {
         bEc = bmt_have_ec(eAFN, eDir);
    }
    
    usAuxLen = usmt_get_aux_len(eAFN, eDir, bEc, bTp);
    nLenUserField = (INT32)(usLenUserField - usAuxLen - MT_CANS_LEN);   
    
    #if 0
    #ifdef MT_DBG
    DEBUG("emtBaseUnPack() nLenUserField = %d\n", nLenUserField);
    #endif
    #endif
    
    // Ӧ�ò����� ���ݵ�Ԫ��ʶ�����ݵ�Ԫ��
    pucTemp = (UINT8*)((UINT8*)&(psHead->SEQ) + 1);
    while(nLenUserField > 0)
    {
        // ��ʼ��
        usUsrdLen = nLenUserField;
        
        // ���ݵ�Ԫ��ʶ
        pDaDt = (sMtDaDt*)pucTemp;
        eRet = emt_dadt_to_pnfn(pDaDt, &sPnFn);
        if(MT_OK != eRet)
        {
            #ifdef MT_DBG
            DEBUG("emtBaseUnPack() emt_dadt_to_pnfn() error = %d\n", eRet);
            #endif
            return eRet;
        }

        pucTemp += sizeof(sMtDaDt);
      
        bP0 = bmt_is_p0(sPnFn.usPn);
        if(TRUE == bP0)
        {  
            //P0���������ѭ�� 
            ucPnCycMax = 1;
        }
        else       
        {  
            // ����P0�������˫��ѭ��
            ucPnCycMax = 8;
        }

        psUnpack->sData[i].sPnFn = sPnFn;
        for(pi = 0; pi < ucPnCycMax; pi++)
        {
            usPn = sPnFn.usPn[pi];
            if(MT_PN_NONE == usPn)
            {
                // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
            }
            else if(usPn < MT_PN_MIN || usPn > MT_PN_MAX)
            {
                // �Ƿ�Fn
                #ifdef MT_DBG
                DEBUG("emtBaseUnPack() usPn error Pn = %d\n", usPn);
                #endif
                return MT_ERR_PARA;
            }
            else
            {
                for(fi = 0; fi < 8; fi++)
                {
                    ucFn = sPnFn.ucFn[fi];
                    if(MT_FN_NONE == ucFn)
                    {
                        // ���������û�и�FN, �Ϸ���������
                    }
                    else if(ucFn < MT_FN_MIN || ucFn > MT_FN_MAX)
                    {
                        // �Ƿ�Fn
                        #ifdef MT_DBG
                        DEBUG("emtBaseUnPack() ucFn error Fn = %d\n", ucFn);
                        #endif
                        return MT_ERR_PARA;
                    }
                    else
                    {
                        eCmd = (eMtCmd)((eAFN << 8) | (sPnFn.ucFn[fi]));
                        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtBaseUnPack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            return eRet;
                        }
         
                        pFunc = sCmdInfor.pFunc;
                        if(NULL != pFunc)
                        {
                            eRet = pFunc(MT_TRANS_F2U, (void*)&(psUnpack->sData[i].uApp[pi][fi]), (void*)pucTemp, &usUsrdLen); 
                            if(eRet != MT_OK)
                            {
                                #ifdef MT_DBG
                                DEBUG("emtBaseUnPack() transfunc() error = %d\n", eRet);
                                #endif
                                return eRet;
                            }

                            // ����ָ�����
                            pucTemp += usUsrdLen;

                            // ��¼�����ܳ�
                            usUsrdLenTotal += usUsrdLen;
                        }
                    }
                }
            }
        }
           
        // �������
        usDataNum++;
        
        // ���ȼ���
        nLenUserField -= sizeof(sMtDaDt);
        nLenUserField -= usUsrdLenTotal;

        // ���ü���
        usUsrdLenTotal = 0;
        i++;
    }
    
    // �����EC
    if(TRUE == bEc)
    {
        psEC = (sMtEC*)pucTemp;
        psUnpack->sEC.ucEC1 = psEC->ucEC1;
        psUnpack->sEC.ucEC2 = psEC->ucEC2;
        pucTemp += sizeof(sMtEC);
    }
    
    // �����PW
    if(TRUE == bmt_have_pw((eMtAFN)(psHead->AFN), eDir))
    {
        memcpy((void*)(psUnpack->acPW), (void*)pucTemp, MT_PW_LEN);
        pucTemp += MT_PW_LEN;
    }

    // �����TP
    if(TRUE == bTp)
    {
        eRet = emt_trans_tp(MT_TRANS_F2U, &(psUnpack->sTP), (sMtTP_f*)pucTemp);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG
            DEBUG("eMtUnpack() emt_trans_tp() error = %d\n", eRet);
            #endif
            return eRet;
        }

        //pucTemp += sizeof(sMtfTp);
    }

    psUnpack->usDataNum = usDataNum;
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtPackBase
 ��������  : ��װ����(�߼��ӿ�)
 ʵ�ֹ���  : (1) ʵ����ɢ����Ϣ������Ϣ����Զ�����
             (2) �Զ�ȡ��ǰ��ʱ�����ϳ�tp
             (3) Ϊ�ϲ�������صĲ��� �繦�����
             
 �������  : smtPack* psPack  
             UINT16* pusLen   
             UINT8* pOutBuf   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtBasePack
 ��������  : emtPack()
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��7�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtPackBase(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf)
{
    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtPack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtPack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }

    eMtErr         eRet         = MT_OK;
    eMtCmd         eCmd         = CMD_AFN_F_UNKOWN;
    eMtDir         eDir         = MT_DIR_UNKOWN;
    eMtAFN         eAFN         = AFN_NULL;
    eMtAFN         eAFNCmd      = AFN_NULL;  // �����Ӧ��AFN
    UINT8          ucTeamPn     = 0xFF;
    UINT8          ucTeamPnBase = 0xFF;
    UINT8          ucTeamFn     = 0xFF;
    UINT8          ucTeamFnBase = 0xFF;
    UINT8          ucFn         = 0;
    UINT16         usPn         = 0;
    INT32          FnIndex      = 0;
    INT32          PnIndex      = 0;
    INT32          i            = 0;
    INT32          j            = 0;
    INT32          k            = 0;
    INT32          nDaDtNum     = 0;      // ��װpackbase����Ϣ��ʶ��64�����ݵ�Ԫ����ܸ���
    INT32          nDaDtPos     = 0;      // ÿ��Ӧ����packbase����Ϣ��ʶ�������
    BOOL           bFindDaDt    = FALSE;  // �Ƿ��ҵ�֮ǰ���ڵ���
    BOOL           bAcd_Fcb     = FALSE;
    BOOL           bPW          = FALSE;  // ��û��Pw �ֶ�
    BOOL           bEC          = FALSE;  // ��û��EC �ֶ�
    BOOL           bTP          = FALSE;  // �Ƿ���Tp �ֶ�
    BOOL           bInFn8       = FALSE;
    BOOL           bInPn8       = FALSE;
    UINT8*         pMemBase     = NULL;
    smtBasePack*   psBasePack   = NULL;
    sMtCtrl        sCtrl;
    sMtTP          sTp;                 // �û���Tp�ֶ���Ϣ
    sMtCmdInfor    sCmdInfor;

    // Ϊ���������ڴ�
    pMemBase  = (UINT8*)malloc(MT_USER_MAX);
    if(!pMemBase)
    { 
        #ifdef MT_DBG
        DEBUG("emtPack() malloc failed!");
        #endif
        return MT_ERR_IO; 
    }

    psBasePack = (smtBasePack*)pMemBase;

    // ��װ�� smtBasePack ����
    eDir = psPack->eDir;
    eAFN = psPack->eAFN;

    // Afn
    psBasePack->eAFN = eAFN;

    // SEQ
    psBasePack->sSEQ.bTpv  = bmt_have_tp(eAFN, eDir);
    psBasePack->sSEQ.bCon  = bmt_need_con(eAFN, eDir);
    psBasePack->sSEQ.ePos  = psPack->ePos;
    psBasePack->sSEQ.ucSeq = psPack->ucSeq;

    // ��ַ��
    psBasePack->sAddress = psPack->sAddress;

    // ������
    bAcd_Fcb = psPack->bAcdFcb;
    
    eRet = emt_get_ctrl(eAFN, eDir, psPack->ePRM, bAcd_Fcb, &sCtrl);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtPack() emt_get_ctrl() failed! %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }
    
    psBasePack->sCtrl = sCtrl;
    
    // pw 
    bPW = bmt_have_pw(eAFN, eDir);
    if(TRUE == bPW)
    {
       //memcpy(psBasePack->acPW, psPack->acPW, MT_PW_LEN);
       memcpy(psBasePack->acPW, g_aucPw, MT_PW_LEN);
    }

    // ec
    bEC = bmt_have_ec(eAFN, eDir);
    if(TRUE == bEC)
    {
        psBasePack->sEC.ucEC1 = g_tEC.ucEC1;
        psBasePack->sEC.ucEC2 = g_tEC.ucEC2;
    }

    // tp 
    bTP = bmt_have_tp(eAFN, eDir);
    if(TRUE == bTP)
    {
        (void)emt_get_tp(psPack->sTP.ucPFC, &sTp);
        psBasePack->sTP.sDDHHmmss = sTp.sDDHHmmss;
        psBasePack->sTP.ucPermitDelayMinutes = sTp.ucPermitDelayMinutes;
        // psBasePack->sTP.ucPFC = psBasePack->sTP.ucPFC;// ����Ѿ��ڷ�װʱ���û����
    }

    // ����ɢ�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��ϳ���
    for(i = 0; i < psPack->usDataNum; i++)
    {
        eCmd = psPack->sData[i].eCmd;
        
        // �жϸ������Ƿ��ǺϷ��ġ���֧�ֵ�
        eRet = eMtGetCmdInfor(eCmd, eDir, &sCmdInfor);
        if(eRet != MT_OK)
        {
            #ifdef MT_DBG
            DEBUG("emtPack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
            #endif
            MT_FREE(pMemBase);
            return eRet;
        }

        // �жϸ������Ƿ�����AFN��������
        eAFNCmd = eGetCmdAfn(eCmd);
        if(eAFNCmd != eAFN)  
        {
            MT_FREE(pMemBase);
            #ifdef MT_DBG
            DEBUG("emtPack() cmd is not is a same Afn");
            #endif
            return MT_ERR_TEAM;
        }

        usPn = psPack->sData[i].usPN;
        ucFn = ucGetCmdFn(eCmd);

        /*
            �жϸúϷ������ݵ�Ԫ��ʶ,�����ݵ�Ԫ�Ƿ��Ѿ�����Ӧ��λ�� psBasePack
            ����ظ�,���߸���ǰ��, Da2 �벻ͬ��Dt2���, 
            �������ͬ�ı�ʶ�����ݵ�Ԫ��, ����nDaTaNum�ĸ���
        */
        
        nDaDtPos = nDaDtNum;
        
        // ��ʼ��PnFn��
        for(k = 0; k < 8; k++)
        {
            psBasePack->sData[nDaDtPos].sPnFn.ucFn[k] = MT_FN_NONE;
            psBasePack->sData[nDaDtPos].sPnFn.usPn[k] = MT_PN_NONE;
        }
             
        for(j = 0; j < nDaDtNum; j++)
        {
            // �ҵ���nDataPos���ҵ���λ��
            // ���ж�Pn�Ƿ���ͬһ��
            ucTeamPn     = ucmt_get_pn_team(usPn);
            ucTeamPnBase = ucmt_get_pn8_team(psBasePack->sData[j].sPnFn.usPn);
            
            if(ucTeamPn == ucTeamPnBase)
            {
                // ���ж�Fn�Ƿ�����ͬһ����
                ucTeamFn     = ucmt_get_fn_team(ucFn);
                ucTeamFnBase = ucmt_get_fn8_team(psBasePack->sData[j].sPnFn.ucFn);

                if(ucTeamFn == ucTeamFnBase)
                {
                    bInPn8 = bmt_in_pn8(usPn, psBasePack->sData[j].sPnFn.usPn);
                    bInFn8 = bmt_in_fn8(ucFn, psBasePack->sData[j].sPnFn.ucFn);

                    if(TRUE == bInPn8 || TRUE == bInFn8)
                    {
                        bFindDaDt = TRUE;
                        nDaDtPos  = j;
                        break;
                    }
                }
            }
        }

        // δ�ҵ���nDaTaNum++
        if(FALSE == bFindDaDt)
        {
            nDaDtNum  += 1; // ����һ��  
        }

        // ���� DaTa�鼰���ݵ�Ԫ
        if(0 == usPn)
        {
            PnIndex = 0;
            
            for(k = 0; k < 8; k++)
            {
                psBasePack->sData[nDaDtPos].sPnFn.usPn[k] = 0;
            }
        }
        else
        {
            PnIndex = (usPn - 1) % 8; 
            psBasePack->sData[nDaDtPos].sPnFn.usPn[PnIndex] = usPn;
        }
      
        FnIndex = (ucFn - 1) % 8;
        psBasePack->sData[nDaDtPos].sPnFn.ucFn[FnIndex] = ucFn;

        // ���ݵ�Ԫ 
        psBasePack->sData[nDaDtPos].uApp[PnIndex][FnIndex] =  psPack->sData[i].uApp;

        // ����δ�ҵ�״̬
        bFindDaDt = FALSE;
        
    }

    psBasePack->usDataNum = nDaDtNum;

    // ���� emtBasePack()
    eRet = emtBasePack(psBasePack, pusLen , pOutBuf);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtPack() emtBasePack() failed! code : %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }

    MT_FREE(pMemBase);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtUnPackBase
 ��������  : Э�����(�߼��ӿ�)
             ��emtBaseUnPack������������ϢsmtBasePack, ��װ�ɸ߼�smtPack
             
             (1)����Ҫ��Ϣ��ȡ
             (2)��PnFn���ݵ�Ԫ��ȡ����ɢ��
             
 �������  : smtPack *psUnpack  
             UINT8* pInBuf      
             UINT16 usLen      
             
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtBaseUnPack
 ��������  : emtUnPack
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtUnPackBase(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    if(!psUnpack || !pInBuf)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPack() pointer is null!");
        #endif
        return MT_ERR_NULL;
    }

    if(TRUE != g_bMtInit)
    {
        #ifdef MT_DBG
        DEBUG("emtPack() protocol is not init!");
        #endif
        return MT_ERR_INIT;
    }
    
    eMtErr       eRet          = MT_OK;
    eMtCmd       eCmd          = CMD_AFN_F_UNKOWN;
    eMtAFN       eAFN          = AFN_NULL;
    UINT8*       pMemBase      = NULL;
    smtBasePack* pUnpackBase   = NULL;
    BOOL         bP0           = FALSE;
    INT32        i             = 0;
    INT32        j             = 0;
    INT32        fi            = 0;
    INT32        pi            = 0;
    INT32        PnCyc         = 0;
    UINT16       usPn          = 0;
    UINT8        ucFn          = 0;
    sMtCmdInfor  sCmdInfor;

    pMemBase = (UINT8*)malloc(MT_USER_MAX);
    if(!pMemBase)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPack() malloc failed!");
        #endif
        return MT_ERR_IO;
    }
    
    pUnpackBase = (smtBasePack*)pMemBase;

    // ���ý�������
    eRet = emtBaseUnPack(pUnpackBase, pInBuf, usLen);
    if(MT_OK != eRet)
    {
        #ifdef MT_DBG
        DEBUG("emtUnPack() emtBaseUnPack failed! %d %s", eRet, smtGetErr(eRet));
        #endif
        MT_FREE(pMemBase);
        return eRet;
    }

    // ת�����ݽṹ
    eAFN               = pUnpackBase->eAFN;
    psUnpack->sAddress = pUnpackBase->sAddress;
    psUnpack->eAFN     = eAFN;
    psUnpack->eDir     = pUnpackBase->sCtrl.eDir;
    psUnpack->ePRM     = pUnpackBase->sCtrl.ePRM;
    psUnpack->ePos     = pUnpackBase->sSEQ.ePos;
    psUnpack->bCon     = pUnpackBase->sSEQ.bCon;
    psUnpack->ucSeq    = pUnpackBase->sSEQ.ucSeq;
    psUnpack->bAcdFcb  = pUnpackBase->sCtrl.bAcd_Fcb;
    psUnpack->bPW      = bmt_have_pw(psUnpack->eAFN, psUnpack->eDir);
    psUnpack->bEC      = bmt_have_ec(psUnpack->eAFN, psUnpack->eDir);
    psUnpack->bTP      = pUnpackBase->sSEQ.bTpv;

    if(TRUE == psUnpack->bPW)
    {
        memcpy(psUnpack->acPW, pUnpackBase->acPW, MT_PW_LEN);
    }
    
    if(TRUE == psUnpack->bEC)
    {
        psUnpack->sEC = pUnpackBase->sEC;
    }

    if(TRUE == psUnpack->bTP)
    {
        psUnpack->sTP = pUnpackBase->sTP;
    }

    // Ӧ�ò�����
    for(i = 0; i < pUnpackBase->usDataNum; i++)
    {
        bP0 = bmt_is_p0(pUnpackBase->sData[i].sPnFn.usPn);
        PnCyc = ((bP0 == TRUE) ? 1 : 8);
        
        for(pi = 0; pi < PnCyc; pi++)
        {
            usPn = pUnpackBase->sData[i].sPnFn.usPn[pi];
            if(MT_PN_NONE == usPn)
            {
                // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
            }
            else if(usPn < MT_PN_MIN || usPn > MT_PN_MAX)
            {
                // �Ƿ�Fn
                #ifdef MT_DBG
                DEBUG("emtUnPack() usPn error Pn = %d\n", usPn);
                #endif
                MT_FREE(pMemBase);
                return MT_ERR_PARA;
            }
            else
            {
                #if 0
                #ifdef MT_DBG
                for(fi = 0; fi < 8; fi++)
                {   ucFn = pUnpackBase->sData[i].sPnFn.ucFn[fi];                
                    DEBUG("emtUnPack() sData[%d].sPnFn.ucFn[%d] = %d",i, fi, ucFn);
                }
                #endif
                #endif
              
                for(fi = 0; fi < 8; fi++)
                {
                    ucFn = pUnpackBase->sData[i].sPnFn.ucFn[fi];
                    if(MT_FN_NONE == ucFn)
                    {
                        // ���������û�и�FN, �Ϸ���������
                    }
                    else if(ucFn < MT_FN_MIN || ucFn > MT_FN_MAX)
                    {
                        // �Ƿ�Fn
                        #ifdef MT_DBG
                        DEBUG("emtUnPack() ucFn error Fn = %d\n", ucFn);
                        #endif
                        MT_FREE(pMemBase);
                        return MT_ERR_PARA;
                    }
                    else
                    {
                        eCmd = (eMtCmd)((eAFN << 8) | ucFn);
                        eRet = eMtGetCmdInfor(eCmd, psUnpack->eDir, &sCmdInfor);
                        if(MT_OK != eRet)
                        {
                            #ifdef MT_DBG
                            DEBUG("emtUnPack() eMtGetCmdInfor() failed %d %s!", eRet, smtGetErr(eRet));
                            #endif
                            MT_FREE(pMemBase);
                            return eRet;
                        }
                        
                        if(NULL != sCmdInfor.pFunc)
                        {
                            psUnpack->sData[j].bApp = TRUE;
                        }
                        else
                        {
                            psUnpack->sData[j].bApp = FALSE;
                        }

                        // һ����Ч�����ݵ�Ԫ��ʶ��
                        psUnpack->sData[j].eCmd  = eCmd;
                        psUnpack->sData[j].usPN  = usPn;
                        psUnpack->sData[j].uApp  = pUnpackBase->sData[i].uApp[pi][fi];
                        j++;
                    }
                }
            }
        }
    }

    psUnpack->usDataNum = j;
    MT_FREE(pMemBase);
    return MT_OK;
}

/*****************************************************************************
 �� �� ��  : emtPack
 ��������  : ��װ����(�߼��ӿ�)
 ʵ�ֹ���  : (1) ʵ����ɢ����Ϣ������Ϣ����Զ�����
             (2) �Զ�ȡ��ǰ��ʱ�����ϳ�tp
             (3) Ϊ�ϲ�������صĲ��� �繦�����
             
 �������  : smtPack* psPack  
             UINT16* pusLen   
             UINT8* pOutBuf   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : emtBasePack()
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��7�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtPack(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf)
{
    eMtErr eRet = MT_OK;

    // ���ַ�ʽ��ѡĳһ, emtPackBase�Ϸ��ڴ�
    // eRet = emtPackBase(psPack, pusLen, pOutBuf);
    eRet = emtPackLite(psPack, pusLen, pOutBuf);
    
    return eRet;
}

/*****************************************************************************
 �� �� ��  : emtUnPack
 ��������  : Э�����(�߼��ӿ�)
             ��emtBaseUnPack������������ϢsmtBasePack, ��װ�ɸ߼�smtPack
             
             (1)����Ҫ��Ϣ��ȡ
             (2)��PnFn���ݵ�Ԫ��ȡ����ɢ��
             
 �������  : smtPack *psUnpack  
             UINT8* pInBuf      
             UINT16 usLen      
             
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : emtBaseUnPack
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eMtErr emtUnPack(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
     eMtErr eRet = MT_OK;

    // ���ַ�ʽ��ѡĳһ, emtUnPackBase�Ϸ��ڴ�
    //eRet = emtUnPackBase(psUnpack, pInBuf, usLen);
    eRet = emtUnPackLite(psUnpack, pInBuf, usLen);
    
    return eRet;
}



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CQgdw3761api::CQgdw3761api()
{

}

CQgdw3761api::~CQgdw3761api()
{

}


char * CQgdw3761api::getErrMessage( eMtErr err )
{
	char * pRet;
	switch(err)
	{
	case MT_OK:             // �޴���   
		pRet = "MT_OK";
		break;
	case MT_ERR_NULL:           // ָ��Ϊ��    
        pRet = "MT_ERR_NULL";
		break;
	case MT_ERR_OUTRNG:        // ����Խ��  
		pRet = "MT_ERR_OUTRNG";
		break;
	case MT_ERR_NONE:           // ������:û���ҵ�  
		pRet = "MT_ERR_NONE";
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

/************************************************************************
�������ƣ�CStringToHexBuffer
�������ܣ����ַ��� ת����16���Ƶ�char[],������䳤��
���������strText
���������pOutBuf
		  pLen
����ֵ��  BOOL ת���ɹ� true ���� false
����˵����

************************************************************************/
BOOL CQgdw3761api::CStringToHexBuffer( CString strText, char *pOutBuf, UINT16 *pLen )
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
		pOutBuf[i] = (char)strtol(strHex, NULL, 16);
		strLenLeft -= 2;
		strText = strText.Right(strLenLeft);

	}

	*pLen = BufLen;


	return TRUE;	
}


CString CQgdw3761api::GetAfnName( eMtAFN eAfn )
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

CString CQgdw3761api::BufferToHex(char *pBuf, UINT16 usLen)
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
