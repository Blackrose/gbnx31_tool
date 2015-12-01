// Qgdw3761api.h: interface for the CQgdw3761api class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QGDW3761API_H__EBD79D34_E069_44C8_8DF5_5EBB464200FC__INCLUDED_)
#define AFX_QGDW3761API_H__EBD79D34_E069_44C8_8DF5_5EBB464200FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




/******************************************************************************

                  ��Ȩ���� (C), 2005-2015, ���ҵ���ͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : qgdw_3761_api.h
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��7��25�� ������
  ����޸�   :
  ��������   : Q/GDW 376.1 2009 ��վ��ɼ��ն�ͨ��Э����� C���� api
               ���ļ��������ҵ�����ҵ��׼376.1Э����صĶ��弰Э������Ļ����ӿ�
  ��д˵��   : ��վ    master       -> m 
               ������  concentrator -> c
               �ն�    terminal     -> t
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��7��25�� ������
    ��    ��   : liming(email: vliming@126.com)
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef _QGDW_3761_API_H_
#define _QGDW_3761_API_H_

// ����һ�ֽڶ���
//#pragma pack(push) 
//#pragma pack(1)


// ���Ͷ���
#ifndef _TYPE_DEF_LM_
#define _TYPE_DEF_LM_
#ifndef __RTL_H__
#define __RTL_H__
//typedef char                BOOL;
#endif
//#define TRUE                (1)
//#define FALSE               (0)
typedef unsigned char       UCHAR;
typedef char                CHAR;
typedef unsigned short      USHORT;
typedef short               SHORT;
typedef unsigned long       ULONG;
typedef long                LONG;

#ifndef _TYPE_DEF_
#define _TYPE_DEF_
typedef char                INT8;       //c
typedef short               INT16;      //s
typedef int                 INT32;      //l
typedef unsigned char       UINT8;      //uc
typedef unsigned short      UINT16;     //us
typedef unsigned int        UINT32;     //ul

#ifdef MACHINE_64_BITS
//typedef long                INT64;
//typedef unsigned long       UINT64;
#else
//typedef long long           INT64;
//typedef unsigned long long  UINT64;
#endif

typedef char*               STRING;     //str
typedef char                ISBOOL;     //b
typedef unsigned int        IPADDR;     //ip
typedef double              DOUBLE;
typedef void*               FRWK_HANDLE;
#endif
#endif



/*******************************************************
 *  �����ļ� �����
 *  �ô�API֮ǰ�����ú�
 *
{*///

#define MT_CFG_SPT_MST         (1)         // �Ƿ�֧����վ �����ļ� ��֧�ֽ����Ϊ 0 
#define MT_CFG_SPT_TML         (1)         // �Ƿ�֧����վ �����ļ� ��֧�ֽ����Ϊ 0
#define MT_CFG_MEDIUM_NET      (1)         // ͨ�Ž���,���������ĵ���󳤶� �������̫��1 ������0 
#define MT_CFG_ENCRYPT         (0)         // �Ƿ���Ҫ���� 
///*}

/*******************************************************
 *  Э����غ궨��
 *  
{*///

#define METER_ADDR_LEN         (12)         // ����ַ����                     
/****************************************
 *  ��ַ��
 *  �ն˵�ַA2ѡַ��ΧΪ1��65535��
 *  A2=0000HΪ��Ч��ַ��A2=FFFFH��A3��D0λΪ"1"ʱ��ʾϵͳ�㲥��ַ��
 *  
 *           
 *         
{*///

#define MT_TML_ADDR_MIN        (1)         // �ն˻�������ַ���ֵ
#define MT_TML_ADDR_MAX        (65535)     // ��վ��ַ���ֵ
#define MT_TML_ADDR_BRD        (0xFFFF)    // ��վ��ַ���ֵ

#define MT_MST_ADDR_MIN        (0)         // ��վ��ַ���ֵ
#define MT_MST_ADDR_MAX        (127)       // ��վ��ַ���ֵ

///*}

/****************************************
 *  Ӧ�������� ���ݵ�Ԫ��ʶ
 *  ����һ��ȷ����DaDt�ṹ,���֧�� 8��Pn ͬʱ����Ӧ�����±� 8��Fn
 *  ������Ҫ 8*8�����ݵ�Ԫ
 *  
 *           
 *         
{*///

#define PN_INDEX_MAX       (8)          // �������ݵ�Ԫ����֯
#define FN_INDEX_MAX       (8)          // �������ݵ�Ԫ����֯
///*}


/****************************************
 *  ��⡢��װ��ز����ֽڳ�
 *  
 *           
 *         
{*///
#define MT_PW_LEN           (16)         // ��Ϣ��֤����
#define MT_PN_MAX           (2040)       // ���ݵ�Ԫ��ʶ DA Pn ���ֵ 
#define MT_PN_MIN           (0)          // ���ݵ�Ԫ��ʶ Da Pn ��Сֵ
#define MT_PN_NONE          (0xFFFF)     // ���ݵ�Ԫ��ʶ Da Pn ��Чֵ �����ù��ĵ�ֵ

#define MT_FN_MAX           (248)        // ���ݵ�Ԫ��ʶ Dt Fn ���ֵ
#define MT_FN_MIN           (1)          // ���ݵ�Ԫ��ʶ Dt Fn ��Сֵ
#define MT_FN_NONE          (0xFF)       // ���ݵ�Ԫ��ʶ Dt Fn ��Чֵ �����ù��ĵ�ֵ

#define MT_UNIT_DATA_MAX    (128)        // �������ݵ�Ԫ�ֳ�

#define MT_FRM_MAX_WRLESS   (255)        // ����ר�����������ŵ�,����L1������255
#define MT_FRM_MAX_NET      (16384)      // �������紫��,����L1������16383
#define MT_SEQ2CS_MAX       (2048)       // ÿ��֡����SEQ��CS֮�������ֽ������ֵ
#define MT_CA_LEN           (8)          // ���������ַ�����ֳ� 
#define MT_CANS_LEN         (8)          // ������C ��ַ��A AFN SEQ�ֽ��ܳ�
#define MT_HCANS_LEN        (13)         // ������C ��ַ��A AFN SEQ 0x68 0x16 �ֽ��ܳ� 
#define MT_UN_USER_LEN      (8)          // �����з��������ܳ���  0x68 0x68 L L CS 0x16
#define MT_DADT_LEN         (4)          // ���ݱ�ʶ�ֳ� DaDt  
#define MT_AFN_LEN          (1)          // AFN �ֳ�
#define MT_DADT_ERR_LEN     (MT_DADT_LEN + 1)  // DaDt �� ERR���ֳ�

// ֡������ֳ�
#if MT_CFG_MEDIUM_NET 
#define MT_FRM_LEN_MAX      MT_FRM_MAX_NET      
#else
#define MT_FRM_LEN_MAX      MT_FRM_MAX_WRLESS
#endif

#define MT_SEQ2CS_BYTES_MAX (MT_FRM_LEN_MAX - MT_HCANS_LEN)  // ÿ��֡����SEQ��CS֮�������ֽ������ֵ
//#define MT_USER_MAX         (1024*MT_SEQ2CS_BYTES_MAX)          // �û���ȱ䳤�ṹ smtPack smtBasePack ��󳤶�

#define MT_USER_MAX         (1024*1024*50)
// ֡����С�ֳ�
#define MT_FRM_LEN_MIN      (20)                             // ��������¼��֡����С
///*}

///*}

/*******************************************************
 *  Ӧ�ò㹦���� AFN
 *
{*///
typedef enum
{
    AFN_00_CONF  = 0x00,     // ȷ�Ϸ���
    AFN_01_RSET  = 0x01,     // ��λ
    AFN_02_LINK  = 0x02,     // ��·�ӿڼ��
    AFN_03_RELY  = 0x03,     // �м�վ����
    AFN_04_SETP  = 0x04,     // ���ò���
    AFN_05_CTRL  = 0x05,     // ��������
    AFN_06_AUTH  = 0x06,     // �����֤����ԿЭ��
    AFN_07_BACK  = 0x07,     // ����
    AFN_08_CASC  = 0x08,     // ���󱻼����ն������ϱ�
    AFN_09_CFIG  = 0x09,     // �����ն�����
    AFN_0A_GETP  = 0x0A,     // ��ѯ����
    AFN_0B_ASKT  = 0x0B,     // ������������
    AFN_0C_ASK1  = 0x0C,     // ����1������ (ʵʱ����)
    AFN_0D_ASK2  = 0x0D,     // ����2������ (��ʷ����)
    AFN_0E_ASK3  = 0x0E,     // ����3������ (�¼�����)
    AFN_0F_FILE  = 0x0F,     // �ļ�����
    AFN_10_DATA  = 0x10,     // ����ת��
    AFN_11_MAX   = 0x11, 
    AFN_NULL     = 0xFF      // �����ڵ�AFN

}eMtAFN;    
 ///*} 

/*******************************************************
 *  �����붨��
 *  �������� CMD_AFN_(xx)_F(xx)_NAME  
 *  xx ��ʾ���� 
 *  F  ��ʾ��Ϣ���ʶ
 *  ����Э�����, ÿ���ڵ����8��Fn�������һ�����ݱ�ʶ
 *  ����: �ն˻���������վ
 *  ����: ��վ���ն˻�����
 *
{*///
typedef enum
{
    CMD_AFN_F_UNKOWN,                                // δ֪����

    /**********************************
     * ȷ��/����
     * AFN : 00H
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_0_F1_ALL_OK              = 0x0001,       // ȫ��ȷ�ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��
    CMD_AFN_0_F2_ALL_DENY            = 0x0002,       // ȫ�����ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ���з���
    CMD_AFN_0_F3_ONE_BY_ONE          = 0x0003,       // �����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����
    ///*}                                            // F4 - F248 ����

    /**********************************
     * ��λ����
     * AFN : 01
     *  PN : p0
     * ����: AFN 00H ȷ��/����
     * ����: ��
    {*///
    CMD_AFN_1_F1_HARD_INIT           = 0x0101,       // Ӳ����ʼ��
    CMD_AFN_1_F2_DATA_INIT           = 0x0102,       // ��������ʼ��
    CMD_AFN_1_F3_FACTORY_RESET       = 0x0103,       // ������ȫ����������ʼ�������ָ����������ã�
    CMD_AFN_1_F4_PARA_INIT           = 0x0104,       // ����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��
    ///*}                                            // F5 - F248 ����
    
    /**********************************
     * ��·�ӿڼ��
     * AFN : 02
     *  PN : p0
     * ����: ��
     * ����: AFN 00H ȷ��/����
    {*///
    CMD_AFN_2_F1_LOG_IN              = 0x0201,       // ��¼
    CMD_AFN_2_F2_LOG_OUT             = 0x0202,       // �˳���¼
    CMD_AFN_2_F3_HEART_BEAT          = 0x0203,       // ����
    ///*}                                            // F4 - F248 ����
    
    /**********************************
     * �м�վ����
     * AFN : 03
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_3_F1_RELAY_CTRL          = 0x0301,       // �м�վ����״̬����
    CMD_AFN_3_F2_RELAY_STAT_QUERY    = 0x0302,       // �м�վ����״̬��ѯ
    CMD_AFN_3_F3_RELAY_RECD_QUERY    = 0x0303,       // �м�վ����״̬�л���¼����
    CMD_AFN_3_F4_HEART_DATA_QUERY    = 0x0304,       // �м�վ����״̬ͳ�Ʋ�ѯ
    ///*}                                            // F4 - F248 ����
    
    /**********************************
     * ���ò���
     * AFN : 04
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0
    CMD_AFN_4_F1_TML_UP_CFG          = 0x0401,       // �ն�����ͨ�ſ�ͨ�Ų�������
    CMD_AFN_4_F2_TML_WIRELESS_CFG    = 0x0402,       // �ն�����ͨ�ſ������м�ת������
    CMD_AFN_4_F3_MST_IP_PORT         = 0x0403,       // ��վIP��ַ�Ͷ˿�
    CMD_AFN_4_F4_MST_PHONE_SMS       = 0x0404,       // ��վ�绰����Ͷ������ĺ���
    CMD_AFN_4_F5_TML_UP_AUTH         = 0x0405,       // �ն�����ͨ����Ϣ��֤��������
    CMD_AFN_4_F6_TEAM_ADDR           = 0x0406,       // ���������ַ����
    CMD_AFN_4_F7_TML_IP_PORT         = 0x0407,       // ������IP��ַ�Ͷ˿�
    CMD_AFN_4_F8_TML_UP_WAY          = 0x0408,       // ����������ͨ�Ź�����ʽ(��̫ר��������ר��)

    // ��2   pn:p0
    CMD_AFN_4_F9_TML_EVENT_CFG       = 0x0409,       // �ն��¼���¼��������
    CMD_AFN_4_F10_TML_POWER_CFG      = 0x040A,       // �ն˵��ܱ�/��������װ�����ò���
    CMD_AFN_4_F11_TML_PULSE_CFG      = 0x040B,       // �ն��������ò���
    CMD_AFN_4_F12_TML_STATE_INPUT    = 0x040C,       // �ն�/������״̬���������
    CMD_AFN_4_F13_TML_SIMULA_CFG     = 0x040D,       // �ն˵�ѹ/����ģ�������ò���
    CMD_AFN_4_F14_TML_GRUP_TOTL      = 0x040E,       // �ն��ܼ������ò���
    CMD_AFN_4_F15_HAVE_DIFF_EVENT    = 0x040F,       // �й��ܵ�����������¼���������
    CMD_AFN_4_F16_VPN_USER_PWD       = 0x0410,       // ����ר���û���������

    // ��3   pn:p0
    CMD_AFN_4_F17_TML_SAFE_VALUE     = 0x0411,       // �ն˱�����ֵ
    CMD_AFN_4_F18_TML_PCTRL_PERD     = 0x0412,       // �ն˹���ʱ��
    CMD_AFN_4_F19_TML_PCTRL_FACTOR   = 0x0413,       // �ն�ʱ�ι��ض�ֵ����ϵ��
    CMD_AFN_4_F20_TML_MONTH_FACTOR   = 0x0414,       // �ն��µ������ض�ֵ����ϵ��
    CMD_AFN_4_F21_TML_POWER_FACTOR   = 0x0415,       // �ն˵���������ʱ�κͷ�����
    CMD_AFN_4_F22_TML_POWER_RATE     = 0x0416,       // �ն˵���������
    CMD_AFN_4_F23_TML_WARNING_CFG    = 0x0417,       // �ն˴߸澯����
                                                     // F24 ����
    // ��4   pn:�������
    CMD_AFN_4_F25_MP_BASE_CFG        = 0x0419,       // �������������
    CMD_AFN_4_F26_MP_LIMIT_CFG       = 0x041A,       // ��������ֵ����
    CMD_AFN_4_F27_MP_LOSS_CFG        = 0x041B,       // ������ͭ���������
    CMD_AFN_4_F28_MP_PERIOD_FACTOR   = 0x041C,       // �����㹦�������ֶ���ֵ
    CMD_AFN_4_F29_TML_METER_ID       = 0x041D,       // �ն˵��ص��ܱ���ʾ��
    CMD_AFN_4_F30_TML_AUTO_READ      = 0x041E,       // �ն�̨�����г���ͣ��/Ͷ������
    CMD_AFN_4_F31_SLAVE_ADDR         = 0x041F,       // �ز��ӽڵ㸽���ڵ��ַ
                                                     // F31~F32 ����
    // ��5   pn:p0
    CMD_AFN_4_F33_TML_READ_CFG       = 0x0421,       // �ն˳������в�������
    CMD_AFN_4_F34_CON_DOWN_CFG       = 0x0422,       // ����������ͨ��ģ��Ĳ�������
    CMD_AFN_4_F35_TML_READ_VIP       = 0x0423,       // �ն�̨�����г����ص㻧����
    CMD_AFN_4_F36_TML_UP_LIMIT       = 0x0424,       // �ն�����ͨ��������������
    CMD_AFN_4_F37_TML_CASC_CFG       = 0x0425,       // �ն˼���ͨ�Ų���
    CMD_AFN_4_F38_CFG_ASK_1          = 0x0426,       // 1��������������(���ն�֧�ֵ�1������������)
    CMD_AFN_4_F39_CFG_ASK_2          = 0x0427,       // 2��������������(���ն�֧�ֵ�2������������)
                                                     // F40 ����
    // ��6   pn:�ܼ����
    CMD_AFN_4_F41_PERIOD_VALUE       = 0x0429,       // ʱ�ι��ض�ֵ
    CMD_AFN_4_F42_FACTORY_HOLIDAY    = 0x042A,       // ���ݹ��ز���
    CMD_AFN_4_F43_SLIDE_TIME         = 0x042B,       // ���ʿ��ƵĹ��ʼ��㻬��ʱ��
    CMD_AFN_4_F44_SHUTOUT_CFG        = 0x042C,       // Ӫҵ��ͣ�ز���
    CMD_AFN_4_F45_CTRL_TURN_CFG      = 0x042D,       // �����ִ��趨
    CMD_AFN_4_F46_MONTH_FIX_VALUE    = 0x042E,       // �µ����ض�ֵ
    CMD_AFN_4_F47_BUY_COUNT          = 0x042F,       // ������(��)�ز���
    CMD_AFN_4_F48_ELEC_TURN_CFG      = 0x0430,       // ����ִ��趨
                                                   
    // ��7  pn:�����ִ�
    CMD_AFN_4_F49_WARNING_TIME       = 0x0431,       // ���ظ澯ʱ��
                                                     // F50~F56 ����
    // ��8  pn:�ܼ����
    CMD_AFN_4_F57_TML_WARN_SOUND     = 0x0439,       // �ն������澯����/��ֹ����
    CMD_AFN_4_F58_TML_ATUO_PROTECT   = 0x043A,       // �ն��Զ���������
    CMD_AFN_4_F59_METER_LIMIT        = 0x043B,       // ���ܱ��쳣�б���ֵ����
    CMD_AFN_4_F60_HUMOR_LIMIT        = 0x043C,       // г����ֵ
    CMD_AFN_4_F61_DC_SIMULA          = 0x043D,       // ֱ��ģ�����������
                                                     // F62~F64 ����
    // ��9  pn:�����
    CMD_AFN_4_F65_CFG_AUTO_1         = 0x0441,       // ��ʱ�ϱ�1��������������
    CMD_AFN_4_F66_CFG_AUTO_2         = 0x0442,       // ��ʱ�ϱ�2��������������
    CMD_AFN_4_F67_GOP_AUTO_1         = 0x0443,       // ��ʱ�ϱ�1��������������/ֹͣ���� 
    CMD_AFN_4_F68_GOP_AUTO_2         = 0x0444,       // ��ʱ�ϱ�2��������������/ֹͣ���� 
                                                     // F69~F72 ����
    // ��10  pn:�������                                             
    CMD_AFN_4_F73_CAPA_CFG           = 0x0449,       // ����������
    CMD_AFN_4_F74_CAPA_RUN_CFG       = 0x044A,       // ������Ͷ�����в���
    CMD_AFN_4_F75_CAPA_PROT_PARA     = 0x044B,       // ��������������
    CMD_AFN_4_F76_CAPA_CTRL_WAY      = 0x044C,       // ������Ͷ�п��Ʒ�ʽ
                                                     // F77~F80 ����
    // ��11 pn:ֱ��ģ�����˿ں�                                                
    CMD_AFN_4_F81_CD_CHANGE_RATE     = 0x0451,       // ֱ��ģ�������
    CMD_AFN_4_F82_CD_LIMIT           = 0x0452,       // ֱ��ģ������ֵ
    CMD_AFN_4_F83_CD_FREEZE_PARA     = 0x0453,       // ֱ��ģ�����������
    ///*}                                            // F83~F248 ����

     /**********************************
     * ��������
     * AFN : 05
     *  PN : ���鶨��
     * ����: AFN 00H ȷ��/����
     * ����: ��
    {*///
    // ��1  pn:�����ִ�                                               
    CMD_AFN_5_F1_REMOTE_TURN_OFF     = 0x0501,       // ң����բ
    CMD_AFN_5_F2_PERMIT_TURN_ON      = 0x0502,       // �����բ
                                                     // F3~F8 ����
    // ��2  pn:�ܼ����                                                
    CMD_AFN_5_F9_PERIOD_GO           = 0x0509,       // ʱ�ι���Ͷ��
    CMD_AFN_5_F10_HOLIDAY_GO         = 0x050A,       // ���ݹ���Ͷ��
    CMD_AFN_5_F11_SHUTOUT_GO         = 0x050B,       // Ӫҵ��ͣ����Ͷ��
    CMD_AFN_5_F12_DOWN_GO            = 0x050C,       // ��ǰ�����¸���Ͷ��
                                                     // F13~F14 ����
    CMD_AFN_5_F15_MONTH_GO           = 0x050F,       // �µ��Ͷ��
    CMD_AFN_5_F16_BUY_GO             = 0x0510,       // �����Ͷ��                                              

    // ��3  pn:�ܼ����
    CMD_AFN_5_F17_PERIOD_STOP        = 0x0511,       // ʱ�ι��ؽ��
    CMD_AFN_5_F18_HOLIDAY_STOP       = 0x0512,       // ���ݹ��ؽ��
    CMD_AFN_5_F19_SHUTOUT_STOP       = 0x0513,       // Ӫҵ��ͣ���ؽ��
    CMD_AFN_5_F20_DOWN_STOP          = 0x0514,       // ��ǰ�����¸��ؽ��
                                                     // F21~F22 ����
    CMD_AFN_5_F23_MONTH_STOP         = 0x0517,       // �µ�ؽ��
    CMD_AFN_5_F24_BUY_STOP           = 0x0518,       // ����ؽ��  

    // ��4  pn:p0 
    CMD_AFN_5_F25_TML_PROTECT_GO     = 0x0519,       // �ն˵籣Ͷ��
    CMD_AFN_5_F26_WARN_PAY_GO        = 0x051A,       // �߷Ѹ澯Ͷ��
    CMD_AFN_5_F27_PERMIT_TALK_GO     = 0x051B,       // �����ն�����վͨ��
    CMD_AFN_5_F28_TAKE_OFF_TML_GO    = 0x051C,       // �ն��޳�Ͷ��
    CMD_AFN_5_F29_AUTO_SAY_GO        = 0x051D,       // �����ն������ϱ�
                                                     // F30 ����
    CMD_AFN_5_F31_CHECK_TIME         = 0x051F,       // ��ʱ����
    CMD_AFN_5_F32_CHINESE_INFO       = 0x0520,       // ������Ϣ

    // ��5 pn:p0 
    CMD_AFN_5_F33_TML_PROTECT_STOP   = 0x0521,       // �ն˵籣���
    CMD_AFN_5_F34_WARN_PAY_STOP      = 0x0522,       // �߷Ѹ澯���
    CMD_AFN_5_F35_PERMIT_TALK_STOP   = 0x0523,       // ��ֹ�ն�����վͨ��
    CMD_AFN_5_F36_TAKE_OFF_TML_STOP  = 0x0524,       // �ն��޳����
    CMD_AFN_5_F37_AUTO_SAY_STOP      = 0x0525,       // ��ֹ�ն������ϱ�
    CMD_AFN_5_F38_TML_LINK_ON        = 0x0526,       // �����ն�������վ
    CMD_AFN_5_F39_TML_LINK_OFF       = 0x0527,       // �����ն˶Ͽ�����
                                                     // F40 ����
    // ��6 pn:������� 
    CMD_AFN_5_F41_CAPA_CTRL_GO       = 0x0529,       // ����������Ͷ��
    CMD_AFN_5_F42_CAPA_CTRL_STOP     = 0x052A,       // ���������ƽ��
                                                     // F43~F48 ����
    // ��7 pn:p0  
    CMD_AFN_5_F49_READ_METER_STOP    = 0x0531,       // ����ָ��ͨ�Ŷ˿���ͣ����
    CMD_AFN_5_F50_READ_METER_GO      = 0x0532,       // ����ָ��ͨ�Ŷ˿ڻָ�����
    CMD_AFN_5_F51_READ_METER_REDO    = 0x0533,       // ����ָ��ͨ�Ŷ˿����³���
    CMD_AFN_5_F52_INIT_ROUTE         = 0x0534,       // ��ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ
    CMD_AFN_5_F53_DELET_ALL_METER    = 0x0535,       // ɾ��ָ��ͨ�Ŷ˿��µ�ȫ�����
    ///*}                                            // F53~F248 ����
    
   /**********************************
     * �����֤����ԿЭ��
     * AFN : 06
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_6_F1_ID_AUTH_Q           = 0x0601,       // �����֤����
    CMD_AFN_6_F2_ID_AUTH_A           = 0x0602,       // �����֤��Ӧ
    CMD_AFN_6_F3_RAND_Q              = 0x0603,       // ȡ���������
    CMD_AFN_6_F4_RAND_A              = 0x0604,       // ȡ�������Ӧ
    ///*}                                            // F4 - F248 ����

    /**********************************
     * ���󱻼����ն������ϱ�
     * AFN : 08
     *  PN : p0
     * ����: �������ϱ�����ʱ,
     *       �������ϱ�����ʱ, Ӧ����ϱ��� CMD_AFN_0_F2_ALL_DENY
     * ����: ��
    {*///
    CMD_AFN_8_F1_CALL_AUTO_REPT      = 0x0801,       // ���󱻼����ն������ϱ�
    ///*} 
    
   /**********************************
     * �����ն����ü���Ϣ
     * AFN : 09
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_9_F1_TML_VERSION         = 0x0901,       // �ն˰汾��Ϣ
    CMD_AFN_9_F2_TML_INPUT_OUT       = 0x0902,       // �ն�֧�ֵ����롢�����ͨ�Ŷ˿�����
    CMD_AFN_9_F3_TML_OTHER_CFG       = 0x0903,       // �ն�֧�ֵ���������
    CMD_AFN_9_F4_SUPPORT_PARA_CFG    = 0x0904,       // �ն�֧�ֵĲ�������
    CMD_AFN_9_F5_SUPPORT_CTRL_CFG    = 0x0905,       // �ն�֧�ֵĿ�������
    CMD_AFN_9_F6_SUPPORT_ASK1_CFG    = 0x0906,       // �ն�֧�ֵ�1����������
    CMD_AFN_9_F7_SUPPORT_ASK2_CFG    = 0x0907,       // �ն�֧�ֵ�2����������
    CMD_AFN_9_F8_SUPPORT_EVNT_CFG    = 0x0908,       // �ն�֧�ֵ��¼���¼����
    ///*}                                            // F9 - F248 ����
  
   /**********************************
     * ��ѯ����
     * AFN : 0A
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0
    CMD_AFN_A_F1_TML_UP_CFG          = 0x0A01,       // �ն�����ͨ�ſ�ͨ�Ų�������
    CMD_AFN_A_F2_TML_WIRELESS_CFG    = 0x0A02,       // �ն�����ͨ�ſ������м�ת������
    CMD_AFN_A_F3_MST_IP_PORT         = 0x0A03,       // ��վIP��ַ�Ͷ˿�
    CMD_AFN_A_F4_MST_PHONE_SMS       = 0x0A04,       // ��վ�绰����Ͷ������ĺ���
    CMD_AFN_A_F5_TML_UP_AUTH         = 0x0A05,       // �ն�����ͨ����Ϣ��֤��������
    CMD_AFN_A_F6_TEAM_ADDR           = 0x0A06,       // ���������ַ����
    CMD_AFN_A_F7_TML_IP_PORT         = 0x0A07,       // ������IP��ַ�Ͷ˿�
    CMD_AFN_A_F8_TML_UP_WAY          = 0x0A08,       // ����������ͨ�Ź�����ʽ(��̫ר��������ר��)

    // ��2   pn:p0
    CMD_AFN_A_F9_TML_EVENT_CFG       = 0x0A09,       // �ն��¼���¼��������
    CMD_AFN_A_F10_TML_POWER_CFG      = 0x0A0A,       // �ն˵��ܱ�/��������װ�����ò���
    CMD_AFN_A_F11_TML_PULSE_CFG      = 0x0A0B,       // �ն��������ò���
    CMD_AFN_A_F12_TML_STATE_INPUT    = 0x0A0C,       // �ն�/������״̬���������
    CMD_AFN_A_F13_TML_SIMULA_CFG     = 0x0A0D,       // �ն˵�ѹ/����ģ�������ò���
    CMD_AFN_A_F14_TML_GRUP_TOTL      = 0x0A0E,       // �ն��ܼ������ò���
    CMD_AFN_A_F15_HAVE_DIFF_EVENT    = 0x0A0F,       // �й��ܵ�����������¼���������
    CMD_AFN_A_F16_VPN_USER_PWD       = 0x0A10,       // ����ר���û���������

    // ��3   pn:p0
    CMD_AFN_A_F17_TML_SAFE_VALUE     = 0x0A11,       // �ն˱�����ֵ
    CMD_AFN_A_F18_TML_PCTRL_PERD     = 0x0A12,       // �ն˹���ʱ��
    CMD_AFN_A_F19_TML_PCTRL_FACTOR   = 0x0A13,       // �ն�ʱ�ι��ض�ֵ����ϵ��
    CMD_AFN_A_F20_TML_MONTH_FACTOR   = 0x0A14,       // �ն��µ������ض�ֵ����ϵ��
    CMD_AFN_A_F21_TML_POWER_FACTOR   = 0x0A15,       // �ն˵���������ʱ�κͷ�����
    CMD_AFN_A_F22_TML_POWER_RATE     = 0x0A16,       // �ն˵���������
    CMD_AFN_A_F23_TML_WARNING_CFG    = 0x0A17,       // �ն˴߸澯����
                                                     // F24 ����
    // ��4   pn:�������
    CMD_AFN_A_F25_MP_BASE_CFG        = 0x0A19,       // �������������
    CMD_AFN_A_F26_MP_LIMIT_CFG       = 0x0A1A,       // ��������ֵ����
    CMD_AFN_A_F27_MP_LOSS_CFG        = 0x0A1B,       // ������ͭ���������
    CMD_AFN_A_F28_MP_PERIOD_FACTOR   = 0x0A1C,       // �����㹦�������ֶ���ֵ
    CMD_AFN_A_F29_TML_METER_ID       = 0x0A1D,       // �ն˵��ص��ܱ���ʾ��
    CMD_AFN_A_F30_TML_AUTO_READ      = 0x0A1E,       // �ն�̨�����г���ͣ��/Ͷ������
    CMD_AFN_A_F31_SLAVE_ADDR         = 0x0A1F,       // �ز��ӽڵ㸽���ڵ��ַ
                                                     // F31~F32 ����
    // ��5   pn:p0
    CMD_AFN_A_F33_TML_READ_CFG       = 0x0A21,       // �ն˳������в�������
    CMD_AFN_A_F34_CON_DOWN_CFG       = 0x0A22,       // ����������ͨ��ģ��Ĳ�������
    CMD_AFN_A_F35_TML_READ_VIP       = 0x0A23,       // �ն�̨�����г����ص㻧����
    CMD_AFN_A_F36_TML_UP_LIMIT       = 0x0A24,       // �ն�����ͨ��������������
    CMD_AFN_A_F37_TML_CASC_CFG       = 0x0A25,       // �ն˼���ͨ�Ų���
    CMD_AFN_A_F38_CFG_ASK_1          = 0x0A26,       // 1��������������(���ն�֧�ֵ�1������������)
    CMD_AFN_A_F39_CFG_ASK_2          = 0x0A27,       // 2��������������(���ն�֧�ֵ�2������������)
                                                     // F40 ����
    // ��6   pn:�ܼ����
    CMD_AFN_A_F41_PERIOD_VALUE       = 0x0A29,       // ʱ�ι��ض�ֵ
    CMD_AFN_A_F42_FACTORY_HOLIDAY    = 0x0A2A,       // ���ݹ��ز���
    CMD_AFN_A_F43_SLIDE_TIME         = 0x0A2B,       // ���ʿ��ƵĹ��ʼ��㻬��ʱ��
    CMD_AFN_A_F44_SHUTOUT_CFG        = 0x0A2C,       // Ӫҵ��ͣ�ز���
    CMD_AFN_A_F45_CTRL_TURN_CFG      = 0x0A2D,       // �����ִ��趨
    CMD_AFN_A_F46_MONTH_FIX_VALUE    = 0x0A2E,       // �µ����ض�ֵ
    CMD_AFN_A_F47_BUY_COUNT          = 0x0A2F,       // ������(��)�ز���
    CMD_AFN_A_F48_ELEC_TURN_CFG      = 0x0A30,       // ����ִ��趨
                                                   
    // ��7  pn:�����ִ�
    CMD_AFN_A_F49_WARNING_TIME       = 0x0A31,       // ���ظ澯ʱ��
                                                     // F50~F56 ����
    // ��8  pn:�ܼ���� 
    CMD_AFN_A_F57_TML_WARN_SOUND     = 0x0A39,       // �ն������澯����/��ֹ����
    CMD_AFN_A_F58_TML_ATUO_PROTECT   = 0x0A3A,       // �ն��Զ���������
    CMD_AFN_A_F59_METER_LIMIT        = 0x0A3B,       // ���ܱ��쳣�б���ֵ����
    CMD_AFN_A_F60_HUMOR_LIMIT        = 0x0A3C,       // г����ֵ
    CMD_AFN_A_F61_DC_SIMULA          = 0x0A3D,       // ֱ��ģ�����������
                                                     // F62~F64 ����
    // ��9  pn:�����
    CMD_AFN_A_F65_CFG_AUTO_1         = 0x0A41,       // ��ʱ�ϱ�1��������������
    CMD_AFN_A_F66_CFG_AUTO_2         = 0x0A42,       // ��ʱ�ϱ�2��������������
    CMD_AFN_A_F67_GOP_AUTO_1         = 0x0A43,       // ��ʱ�ϱ�1��������������/ֹͣ���� 
    CMD_AFN_A_F68_GOP_AUTO_2         = 0x0A44,       // ��ʱ�ϱ�2��������������/ֹͣ���� 
                                                     // F69~F72 ����
    // ��10  pn:�������                                             
    CMD_AFN_A_F73_CAPA_CFG           = 0x0A49,       // ����������
    CMD_AFN_A_F74_CAPA_RUN_CFG       = 0x0A4A,       // ������Ͷ�����в���
    CMD_AFN_A_F75_CAPA_PROT_PARA     = 0x0A4B,       // ��������������
    CMD_AFN_A_F76_CAPA_CTRL_WAY      = 0x0A4C,       // ������Ͷ�п��Ʒ�ʽ
                                                     // F77~F80 ����
    // ��11 pn:ֱ��ģ�����˿ں�                                                
    CMD_AFN_A_F81_CD_CHANGE_RATE     = 0x0A51,       // ֱ��ģ�������
    CMD_AFN_A_F82_CD_LIMIT           = 0x0A52,       // ֱ��ģ������ֵ
    CMD_AFN_A_F83_CD_FREEZE_PARA     = 0x0A53,       // ֱ��ģ�����������
    ///*}                                            // F83~F248 ����

    /**********************************
     * ������������
     * AFN : 0B
     *  PN : �����
     * ����: ���ݲ�ͬ����,�ֱ�������1�����ݺ�����2���������б��Ľ���Ӧ��
     * ����: ��
    {*///
    CMD_AFN_B_F1_TIMING_REPORT_1     = 0x0B01,       // ����ʱ�ϱ�1����������
    CMD_AFN_B_F2_TIMING_REPORT_2     = 0x0B02,       // ����ʱ�ϱ�2����������
    ///*} 

    /**********************************
     * ����1������
     * AFN : 0C
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0                                   // F1 ���� 
    CMD_AFN_C_F2_TML_CLOCK           = 0x0C02,       // �ն�����ʱ��
    CMD_AFN_C_F3_TML_PARA_STATE      = 0x0C03,       // �ն˲���״̬
    CMD_AFN_C_F4_TML_UPCOM_STATE     = 0x0C04,       // �ն�����ͨ��״̬
    CMD_AFN_C_F5_TML_CTRL_SET        = 0x0C05,       // �ն˿�������״̬
    CMD_AFN_C_F6_TML_CTRL_STATE      = 0x0C06,       // �ն˵�ǰ����״̬
    CMD_AFN_C_F7_TML_EC_VALUE        = 0x0C07,       // �ն��¼���������ǰֵ
    CMD_AFN_C_F8_TML_EVNT_FLAG       = 0x0C08,       // �ն��¼���־״̬

    // ��2   pn:p0
    CMD_AFN_C_F9_TML_STATE_BIT       = 0x0C09,       // �ն�״̬������λ��־
    CMD_AFN_C_F10_TML_MONTH_FLOW     = 0x0C0A,       // �ն�����վ���ա���ͨ������
    CMD_AFN_C_F11_TML_READ_METER     = 0x0C0B,       // �ն˼��г���״̬��Ϣ
                                                     // F12~F16 ����
    // ��3   pn:�ܼ����
    CMD_AFN_C_F17_TOTAL_POWER_HAVE   = 0x0C11,       // ��ǰ�ܼ��й�����
    CMD_AFN_C_F18_TOTAL_POWER_NONE   = 0x0C12,       // ��ǰ�ܼ��޹�����
    CMD_AFN_C_F19_DAY_POWER_HAVE     = 0x0C13,       // �����ܼ��й�������(�ܡ����� 1~M)
    CMD_AFN_C_F20_DAY_POWER_NONE     = 0x0C14,       // �����ܼ��޹�������(�ܡ����� 1~M)
    CMD_AFN_C_F21_MONTH_POWER_HAVE   = 0x0C15,       // �����ܼ��й�������(�ܡ����� 1~M)
    CMD_AFN_C_F22_MONTH_POWER_NONE   = 0x0C16,       // �����ܼ��޹�������(�ܡ����� 1~M)
    CMD_AFN_C_F23_TML_LEFT_POWER     = 0x0C17,       // �ն˵�ǰʣ�����(��)
    CMD_AFN_C_F24_DOWN_FREZ_VALUE    = 0x0C18,       // ��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ
                                               
    // ��4   pn:�������
    CMD_AFN_C_F25_POWER_RATE_CUR     = 0x0C19,       // ��ǰ���༰����/�޹����ʡ���������, �����ѹ��������������������ڹ���
    CMD_AFN_C_F26_DROP_PHASE_LAST    = 0x0C1A,       // A��B��C�������ͳ�����ݼ����һ�ζ����¼
    CMD_AFN_C_F27_METER_PROG_TIME    = 0x0C1B,       // ���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��
    CMD_AFN_C_F28_METER_WORD_CBIT    = 0x0C1C,       // �������״̬�ּ����λ��־
    CMD_AFN_C_F29_COPER_IRON_CUR     = 0x0C1D,       // ��ǰͭ�������й��ܵ���ʾֵ
    CMD_AFN_C_F30_COPER_IRON_LAST    = 0x0C1E,       // ��һ�����յ�ǰͭ�������й��ܵ���ʾֵ
    CMD_AFN_C_F31_POWER_CUR          = 0x0C1F,       // ��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ
    CMD_AFN_C_F32_POWER_LAST         = 0x0C20,       // ��һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ

    // ��5   pn:�������
    CMD_AFN_C_F33_FRTH_POWR_P1P4_C   = 0x0C21,       // ��ǰ������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_C_F34_BACK_POWR_P2P3_C   = 0x0C22,       // ��ǰ������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_C_F35_FRTH_DMND_M        = 0x0C23,       // ����������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_C_F36_BACK_DMND_M        = 0x0C24,       // ���·�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_C_F37_FRTH_POWR_P1P4_L   = 0x0C25,       // ���£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_C_F38_BACK_POWR_P2P3_L   = 0x0C26,       // ���£���һ�����գ�������/�޹�������޹�2������ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_C_F39_FRTH_DMND_L        = 0x0C27,       // ���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_C_F40_BACK_DMND_L        = 0x0C28,       // ���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��

    // ��6  pn:�������
    CMD_AFN_C_F41_FRTH_HAVE_POWR_D   = 0x0C29,       // ���������й����������ܡ�����1��M��
    CMD_AFN_C_F42_FRTH_NONE_POWR_D   = 0x0C2A,       // ���������޹����������ܡ�����1��M��
    CMD_AFN_C_F43_BACK_HAVE_POWR_D   = 0x0C2B,       // ���շ����й����������ܡ�����1��M��
    CMD_AFN_C_F44_BACK_NONE_POWR_D   = 0x0C2C,       // ���շ����޹����������ܡ�����1��M��
    CMD_AFN_C_F45_FRTH_HAVE_POWR_M   = 0x0C2D,       // ���������й����������ܡ�����1��M��
    CMD_AFN_C_F46_FRTH_NONE_POWR_M   = 0x0C2E,       // ���������޹����������ܡ�����1��M��
    CMD_AFN_C_F47_BACK_HAVE_POWR_M   = 0x0C2F,       // ���·����й����������ܡ�����1��M��
    CMD_AFN_C_F48_BACK_NONE_POWR_M   = 0x0C30,       // ���·����޹����������ܡ�����1��M��
                                                   
    // ��7  pn:�������
    CMD_AFN_C_F49_CURT_PHASE_ANGLE   = 0x0C31,       // ��ǰ��ѹ��������λ��
                                                     // F50~F56 ����
    // ��8  pn:�������
    CMD_AFN_C_F57_CURT_HARM_VALUE    = 0x0C39,       // ��ǰA��B��C�����ѹ������2��N��г����Чֵ
    CMD_AFN_C_F58_CURT_HARM_RATE     = 0x0C3A,       // ��ǰA��B��C�����ѹ������2��N��г��������
                                                     // F59~F64 ����
    // ��9  pn:�������
    CMD_AFN_C_F65_CURT_CAPA_SWITCH   = 0x0C41,       // ��ǰ������Ͷ��״̬
    CMD_AFN_C_F66_CURT_CAPA_TIME     = 0x0C42,       // ��ǰ�������ۼƲ���Ͷ��ʱ��ʹ���
    CMD_AFN_C_F67_CURT_CAPA_POWR     = 0x0C43,       // ���ա����µ������ۼƲ������޹������� 
                                                     // F68~F72 ����
    // ��10  pn:ֱ��ģ�����˿ں�                                             
    CMD_AFN_C_F73_DC_RLTM_DATA       = 0x0C49,       // ֱ��ģ����ʵʱ����
                                                     // F74~F80 ����
    // ��11 pn:�ܼ����                                                
    CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE = 0x0C51,      // Сʱ�����ܼ��й�����
    CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE = 0x0C52,      // Сʱ�����ܼ��޹�����
    CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE = 0x0C53,      // Сʱ�����ܼ��й��ܵ�����
    CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE = 0x0C54,      // Сʱ�����ܼ��޹��ܵ�����
                                                     // F85~F88 ����
    // ��12 pn:�������
    CMD_AFN_C_F89_HFRZ_RATE_HAVE     = 0x0C59,       // Сʱ�����й�����
    CMD_AFN_C_F90_HFRZ_RATE_HAVE_A   = 0x0C5A,       // Сʱ����A���й�����
    CMD_AFN_C_F91_HFRZ_RATE_HAVE_B   = 0x0C5B,       // Сʱ����B���й�����
    CMD_AFN_C_F92_HFRZ_RATE_HAVE_C   = 0x0C5C,       // Сʱ����C���й�����
    CMD_AFN_C_F93_HFRZ_RATE_NONE     = 0x0C5D,       // Сʱ�����޹�����
    CMD_AFN_C_F94_HFRZ_RATE_NONE_A   = 0x0C5E,       // Сʱ����A���޹�����
    CMD_AFN_C_F95_HFRZ_RATE_NONE_B   = 0x0C5F,       // Сʱ����B���޹�����
    CMD_AFN_C_F96_HFRZ_RATE_NONE_C   = 0x0C60,       // Сʱ����C���޹�����

    // ��13 pn:�������
    CMD_AFN_C_F97_HFRZ_VOLT_A        = 0x0C61,       // Сʱ����A���ѹ
    CMD_AFN_C_F98_HFRZ_VOLT_B        = 0x0C62,       // Сʱ����B���ѹ
    CMD_AFN_C_F99_HFRZ_VOLT_C        = 0x0C63,       // Сʱ����C���ѹ
    CMD_AFN_C_F100_HFRZ_ELEC_A       = 0x0C64,       // Сʱ����A�����
    CMD_AFN_C_F101_HFRZ_ELEC_B       = 0x0C65,       // Сʱ����B�����
    CMD_AFN_C_F102_HFRZ_ELEC_C       = 0x0C66,       // Сʱ����C�����
    CMD_AFN_C_F103_HFRZ_ELEC_ZERO    = 0x0C67,       // Сʱ�����������
                                                     // F104 ����

    // ��14 pn:�������
    CMD_AFN_C_F105_HFRZ_FRTH_HAVE    = 0x0C69,       // Сʱ���������й��ܵ�����
    CMD_AFN_C_F106_HFRZ_FRTH_NONE    = 0x0C6A,       // Сʱ���������޹��ܵ�����
    CMD_AFN_C_F107_HFRZ_BACK_HAVE    = 0x0C6B,       // Сʱ���ᷴ���й��ܵ�����
    CMD_AFN_C_F108_HFRZ_BACK_NONE    = 0x0C6C,       // Сʱ���ᷴ���޹��ܵ�����
    CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S  = 0x0C6D,       // Сʱ���������й��ܵ���ʾֵ
    CMD_AFN_C_F110_HFRZ_FRTH_NONE_S  = 0x0C6E,       // Сʱ���������޹��ܵ���ʾֵ
    CMD_AFN_C_F111_HFRZ_BACK_HAVE_S  = 0x0C6F,       // Сʱ���ᷴ���й��ܵ���ʾֵ
    CMD_AFN_C_F112_HFRZ_BACK_NONE_S  = 0x0C70,       // Сʱ���ᷴ���޹��ܵ���ʾֵ

    // ��15 pn:�������
    CMD_AFN_C_F113_HFRZ_FACT_TOTAL   = 0x0C71,       // Сʱ�����ܹ�������
    CMD_AFN_C_F114_HFRZ_FACT_A       = 0x0C72,       // Сʱ����A�๦������
    CMD_AFN_C_F115_HFRZ_FACT_B       = 0x0C73,       // Сʱ����B�๦������
    CMD_AFN_C_F116_HFRZ_FACT_C       = 0x0C74,       // Сʱ����C�๦������
                                                     // F117~F120 ����    
    // ��16 pn:�������
    CMD_AFN_C_F121_HFRZ_DC_VALUE     = 0x0C79,       // Сʱ����ֱ��ģ����
                                                     // F122~F128 ����
    // ��17 pn:�������
    CMD_AFN_C_F129_FRTH_HAVE_POWR_C  = 0x0C81,       // ��ǰ�����й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F130_FRTH_NONE_POWR_C  = 0x0C82,       // ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F131_BACK_HAVE_POWR_C  = 0x0C83,       // ��ǰ�����й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F132_BACK_NONE_POWR_C  = 0x0C84,       // ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F133_NONE_POWR_P1_C    = 0x0C85,       // ��ǰһ�����޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F134_NONE_POWR_P2_C    = 0x0C86,       // ��ǰ�������޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F135_NONE_POWR_P3_C    = 0x0C87,       // ��ǰ�������޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F136_NONE_POWR_P4_C    = 0x0C88,       // ��ǰ�������޹�����ʾֵ���ܡ�����1��M��

    // ��18 pn:�������
    CMD_AFN_C_F137_FRTH_HAVE_POWR_L  = 0x0C89,       // ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F138_FRTH_NONE_POWR_L  = 0x0C8A,       // ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F139_BACK_HAVE_POWR_L  = 0x0C8B,       // ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F140_BACK_NONE_POWR_L  = 0x0C8C,       // ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F141_NONE_POWR_P1_L    = 0x0C8D,       // ���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F142_NONE_POWR_P2_L    = 0x0C8E,       // ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F143_NONE_POWR_P3_L    = 0x0C8F,       // ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F144_NONE_POWR_P4_L    = 0x0C90,       // ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��

    // ��19 pn:�������
    CMD_AFN_C_F145_FRTH_HAVE_DMND_C  = 0x0C91,       // ���������й��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F146_FRTH_NONE_DMND_C  = 0x0C92,       // ���������޹��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F147_BACK_HAVE_DMND_C  = 0x0C93,       // ���·����й��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F148_BACK_NONE_DMND_C  = 0x0C94,       // ���·����޹��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F149_FRTH_HAVE_DMND_L  = 0x0C95,       // ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F150_FRTH_NONE_DMND_L  = 0x0C96,       // ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F151_BACK_HAVE_DMND_L  = 0x0C97,       // ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
    CMD_AFN_C_F152_BACK_NONE_DMND_L  = 0x0C98,       // ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��

    // ��20 pn:�������
    CMD_AFN_C_F153_FREZ_ZONE_1       = 0x0C99,       // ��һʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F154_FREZ_ZONE_2       = 0x0C9A,       // �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F155_FREZ_ZONE_3       = 0x0C9B,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F156_FREZ_ZONE_4       = 0x0C9C,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F157_FREZ_ZONE_5       = 0x0C9D,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F158_FREZ_ZONE_6       = 0x0C9E,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F159_FREZ_ZONE_7       = 0x0C9F,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_C_F160_FREZ_ZONE_8       = 0x0CA0,       // �ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��

    // ��21 pn:�������
    CMD_AFN_C_F161_METR_REMOTE_CTRL  = 0x0CA1,       // ���ܱ�Զ�̿���ͨ�ϵ�״̬����¼
                                                     // F162~F164 ����
    CMD_AFN_C_F165_METR_SWITCH_RECD  = 0x0CA5,       // ���ܱ��ز���������ʱ��
    CMD_AFN_C_F166_METR_MODIFY_RECD  = 0x0CA6,       // ���ܱ�����޸Ĵ�����ʱ��
    CMD_AFN_C_F167_METR_BUY_USE      = 0x0CA7,       // ���ܱ����õ���Ϣ
    CMD_AFN_C_F168_METR_BALANCE      = 0x0CA8,       // ���ܱ������Ϣ

    // ��22 pn:�������
    CMD_AFN_C_F169_READ_ROUTE        = 0x0CA9,       // ���г����м�·����Ϣ
    CMD_AFN_C_F170_READ_METER        = 0x0CAA,       // ���г���������Ϣ
    ///*}                                            // F171~F248 ����

     /**********************************
     * ����2������
     * AFN : 0D
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1  ����ʾֵ�����������������      pn:�������   (�ն���)                 
    CMD_AFN_D_F1_FRTH_POWR_P1P4_D    = 0x0D01,       // ������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F2_BACK_POWR_P2P3_D    = 0x0D02,       // ������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F3_FRTH_DMND_TIME_D    = 0x0D03,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_D_F4_BACK_DMND_TIME_D    = 0x0D04,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_D_F5_FRTH_HAVE_POWR_D    = 0x0D05,       // �����й����������ܡ�����1��M��
    CMD_AFN_D_F6_FRTH_NONE_POWR_D    = 0x0D06,       // �����޹����������ܡ�����1��M��
    CMD_AFN_D_F7_BACK_HAVE_POWR_D    = 0x0D07,       // �����й����������ܡ�����1��M��
    CMD_AFN_D_F8_BACK_NONE_POWR_D    = 0x0D08,       // �����޹����������ܡ�����1��M��

    // ��2  ����ʾֵ��������� pn:������� (�����ն���)
    CMD_AFN_D_F9_FRTH_POWR_P1P4_R    = 0x0D09,       // ������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F10_BACK_POWR_P2P3_R   = 0x0D0A,       // ������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F11_FRTH_DMND_TIME_R   = 0x0D0B,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_D_F12_BACK_DMND_TIME_R   = 0x0D0C,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
                                                     // F13~F16 ����
                                                    
    // ��3  ����ʾֵ����������������� pn:������� (�¶���)
    CMD_AFN_D_F17_FRTH_POWR_P1P4_M   = 0x0D11,       // ������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F18_BACK_POWR_P2P3_M   = 0x0D12,       // ������/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
    CMD_AFN_D_F19_FRTH_DMND_TIME_M   = 0x0D13,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_D_F20_BACK_DMND_TIME_M   = 0x0D14,       // ������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
    CMD_AFN_D_F21_FRTH_HAVE_POWR_M   = 0x0D15,       // �����й����������ܡ�����1��M��
    CMD_AFN_D_F22_FRTH_NONE_POWR_M   = 0x0D16,       // �����޹����������ܡ�����1��M��
    CMD_AFN_D_F23_BACK_HAVE_POWR_M   = 0x0D17,       // �����й����������ܡ�����1��M��
    CMD_AFN_D_F24_BACK_NONE_POWR_M   = 0x0D18,       // �����޹����������ܡ�����1��M��
                                               
    // ��4   pn:������� �ն���
    CMD_AFN_D_F25_POWR_FRZE_D        = 0x0D19,       // ���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��
    CMD_AFN_D_F26_DMND_FRZE_D        = 0x0D1A,       // ���ܼ������������������ʱ��
    CMD_AFN_D_F27_VOLT_FRZE_D        = 0x0D1B,       // �յ�ѹͳ������
    CMD_AFN_D_F28_UBLN_OVER_D        = 0x0D1C,       // �ղ�ƽ���Խ���ۼ�ʱ��
    CMD_AFN_D_F29_ELEC_OVER_D        = 0x0D1D,       // �յ���Խ��ͳ��
    CMD_AFN_D_F30_POWR_RATE_D        = 0x0D1E,       // �����ڹ���Խ���ۼ�ʱ��
    CMD_AFN_D_F31_LOAD_RATE_D        = 0x0D1F,       // �ո�������ͳ��
    CMD_AFN_D_F32_METR_DROP_D        = 0x0D20,       // �յ��ܱ��������

    // ��5   pn:�������
    CMD_AFN_D_F33_POWR_FRZE_M        = 0x0D21,       // ���ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ�� �¶���
    CMD_AFN_D_F34_DMND_FRZE_M        = 0x0D22,       // ���ܼ������й��������������ʱ�� �¶���
    CMD_AFN_D_F35_VOLT_FRZE_M        = 0x0D23,       // �µ�ѹͳ������         �¶���
    CMD_AFN_D_F36_UBLN_OVER_M        = 0x0D24,       // �²�ƽ���Խ���ۼ�ʱ�� �¶���
    CMD_AFN_D_F37_ELEC_OVER_M        = 0x0D25,       // �µ���Խ��ͳ��         �¶���
    CMD_AFN_D_F38_POWR_RATE_M        = 0x0D26,       // �����ڹ���Խ���ۼ�ʱ�� �¶���
    CMD_AFN_D_F39_LOAD_RATE_M        = 0x0D27,       // �¸�������ͳ��         �¶���
                                                     // F40 ����
    // ��6  pn:�������
    CMD_AFN_D_F41_CAPA_TIME_D        = 0x0D29,       // ������Ͷ���ۼ�ʱ��ʹ��� �ն���
    CMD_AFN_D_F42_CAPA_NONE_D        = 0x0D2A,       // �ա��µ������ۼƲ������޹������� �ն���
    CMD_AFN_D_F43_FACT_TIME_D        = 0x0D2B,       // �չ������������ۼ�ʱ�� �ն���
    CMD_AFN_D_F44_FACT_TIME_M        = 0x0D2C,       // �¹������������ۼ�ʱ�� �¶���
    CMD_AFN_D_F45_COPR_IRON_D        = 0x0D2D,       // ͭ�������й�����ʾֵ �ն���
    CMD_AFN_D_F46_COPR_IRON_M        = 0x0D2E,       // ͭ�������й�����ʾֵ �¶���
                                                     // F47��F48 ����
    // ��7 �ն�ͳ������ pn:�������
    CMD_AFN_D_F49_TML_ONOF_D         = 0x0D31,       // �ն��չ���ʱ�䡢�ո�λ�ۼƴ���
    CMD_AFN_D_F50_TML_CTRL_D         = 0x0D32,       // �ն��տ���ͳ������
    CMD_AFN_D_F51_TML_ONOF_M         = 0x0D33,       // �ն��¹���ʱ�䡢�¸�λ�ۼƴ���
    CMD_AFN_D_F52_TML_CTRL_M         = 0x0D34,       // �ն��¿���ͳ������
    CMD_AFN_D_F53_TML_FLOW_D         = 0x0D35,       // �ն�����վ��ͨ������   
    CMD_AFN_D_F54_TML_FLOW_M         = 0x0D36,       // �ն�����վ��ͨ������ 
                                                     // F55��F56 ���� 
    // ��8  �ܼ���ͳ������  pn:�ܼ����
    CMD_AFN_D_F57_GRUP_RATE_D        = 0x0D39,       // �ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �ն���
    CMD_AFN_D_F58_GRUP_HAVE_D        = 0x0D3A,       // �ܼ������ۼ��й����������ܡ�����1��M�� �ն���
    CMD_AFN_D_F59_GRUP_NONE_D        = 0x0D3B,       // �ܼ������ۼ��޹����������ܡ�����1��M�� �ն���
    CMD_AFN_D_F60_GRUP_RATE_M        = 0x0D3C,       // �ܼ����������С�й����ʼ��䷢��ʱ��,�й�����Ϊ�����ۼ�ʱ�� �¶���
    CMD_AFN_D_F61_GRUP_HAVE_M        = 0x0D3D,       // �ܼ������ۼ��й����������ܡ�����1��M�� �¶���
    CMD_AFN_D_F62_GRUP_NONE_M        = 0x0D3E,       // �ܼ������ۼ��޹����������ܡ�����1��M�� �¶���
                                                     // F63��F64 ����
    // ��9  �ܼ���Խ��ͳ������ pn:�ܼ����
    CMD_AFN_D_F65_GRUP_RATE_OVER     = 0x0D41,       // �ܼ��鳬���ʶ�ֵ�����ۼ�ʱ�䡢���ۼƵ�����  �¶���
    CMD_AFN_D_F66_GRUP_POWR_OVER     = 0x0D42,       // �ܼ��鳬�µ�������ֵ�����ۼ�ʱ�䡢�ۼƵ����� �¶���
                                                     // F67��F72 ����
    // ��10 �ܼ�������         pn:�ܼ����                                             
    CMD_AFN_D_F73_CURVE_RATE_HAVE    = 0x0D49,       // �ܼ����й���������
    CMD_AFN_D_F74_CURVE_RATE_NONE    = 0x0D4A,       // �ܼ����޹���������
    CMD_AFN_D_F75_CURVE_POWR_HAVE    = 0x0D4B,       // �ܼ����й�����������
    CMD_AFN_D_F76_CURVE_POWR_NONE    = 0x0D4C,       // �ܼ����޹�����������
                                                     // F77��F80 ����
    // ��11  �������� pn:�������                                                
    CMD_AFN_D_F81_CURVE_HAVE         = 0x0D51,       // �й���������
    CMD_AFN_D_F82_CURVE_HAVE_A       = 0x0D52,       // A���й���������
    CMD_AFN_D_F83_CURVE_HAVE_B       = 0x0D53,       // B���й���������
    CMD_AFN_D_F84_CURVE_HAVE_C       = 0x0D54,       // C���й���������
    CMD_AFN_D_F85_CURVE_NONE         = 0x0D55,       // �޹���������
    CMD_AFN_D_F86_CURVE_NONE_A       = 0x0D56,       // A���޹���������
    CMD_AFN_D_F87_CURVE_NONE_B       = 0x0D57,       // B���޹���������
    CMD_AFN_D_F88_CURVE_NONE_C       = 0x0D58,       // C���޹���������
         
    // ��12 ��ѹ�������� pn:�������
    CMD_AFN_D_F89_CURVE_VOLT_A       = 0x0D59,       // A���ѹ����
    CMD_AFN_D_F90_CURVE_VOLT_B       = 0x0D5A,       // B���ѹ����
    CMD_AFN_D_F91_CURVE_VOLT_C       = 0x0D5B,       // C���ѹ����
    CMD_AFN_D_F92_CURVE_ELEC_A       = 0x0D5C,       // A���������
    CMD_AFN_D_F93_CURVE_ELEC_B       = 0x0D5D,       // B���������
    CMD_AFN_D_F94_CURVE_ELEC_C       = 0x0D5E,       // C���������
    CMD_AFN_D_F95_CURVE_ZERO_E       = 0x0D5F,       // �����������
                                                     // F96 ����
    // ��13 �ܵ��������ܵ���ʾֵ���� pn:�������
    CMD_AFN_D_F97_CURVE_FRTH_HAVE    = 0x0D61,       // �����й��ܵ����� ����
    CMD_AFN_D_F98_CURVE_FRTH_NONE    = 0x0D62,       // �����޹��ܵ����� ����
    CMD_AFN_D_F98_CURVE_BACK_HAVE    = 0x0D63,       // �����й��ܵ����� ����
    CMD_AFN_D_F100_CURVE_BACK_HAVE   = 0x0D64,       // �����޹��ܵ����� ����
    CMD_AFN_D_F101_CURVE_FRTH_HAVE   = 0x0D65,       // �����й��ܵ���ʾֵ ����
    CMD_AFN_D_F102_CURVE_FRTH_NONE   = 0x0D66,       // �����޹��ܵ���ʾֵ ����
    CMD_AFN_D_F103_CURVE_BACK_HAVE   = 0x0D67,       // �����й��ܵ���ʾֵ ����
    CMD_AFN_D_F104_CURVE_BACK_NONE   = 0x0D68,       // �����޹��ܵ���ʾֵ ����

    // ��14 ������������ѹ��λ�����ߡ�������λ������ pn:�������
    CMD_AFN_D_F105_CURVE_FACTOR_T    = 0x0D69,       // �ܹ�������
    CMD_AFN_D_F106_CURVE_FACTOR_A    = 0x0D6A,       // A�๦������
    CMD_AFN_D_F107_CURVE_FACTOR_B    = 0x0D6B,       // B�๦������
    CMD_AFN_D_F108_CURVE_FACTOR_C    = 0x0D6C,       // C�๦������
    CMD_AFN_D_F109_ANGLE_CURVE_VOLT  = 0x0D6D,       // ��ѹ��λ������
    CMD_AFN_D_F110_ANGLE_CURVE_ELEC  = 0x0D6E,       // ������λ������
                                                     // F111��F112 ����

    // ��15 г�����ͳ������ pn:�������
    CMD_AFN_D_F113_ELEC_HARM_TIME_A  = 0x0D71,       // A��2��19��г�����������ֵ������ʱ�� �ն���
    CMD_AFN_D_F114_ELEC_HARM_TIME_B  = 0x0D72,       // B��2��19��г�����������ֵ������ʱ�� �ն���
    CMD_AFN_D_F115_ELEC_HARM_TIME_C  = 0x0D73,       // C��2��19��г�����������ֵ������ʱ�� �ն���
    CMD_AFN_D_F116_VOLT_HARM_TIME_A  = 0x0D74,       // A��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���
    CMD_AFN_D_F117_VOLT_HARM_TIME_B  = 0x0D75,       // B��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���
    CMD_AFN_D_F118_VOLT_HARM_TIME_C  = 0x0D76,       // C��2��19��г����ѹ�����ʼ��ܻ����������ֵ������ʱ�� �ն���
                                                     // F119~F120 ����    
    // ��16 г��Խ��ͳ������ pn:�������
    CMD_AFN_D_F121_HARM_OVER_A       = 0x0D79,       // A��г��Խ����ͳ������ �ն���
    CMD_AFN_D_F122_HARM_OVER_B       = 0x0D7A,       // B��г��Խ����ͳ������ �ն���
    CMD_AFN_D_F123_HARM_OVER_C       = 0x0D7B,       // C��г��Խ����ͳ������ �ն���
                                                     // F122~F128 ����
    // ��17 ֱ��ģ��������     pn:ֱ��ģ�����˿ں�
    CMD_AFN_D_F129_DC_D              = 0x0D81,       // ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �ն���
    CMD_AFN_D_F130_DC_M              = 0x0D82,       // ֱ��ģ����Խ�����ۼ�ʱ�䡢���/��Сֵ������ʱ�� �¶���
                                                     // F131��F136 ����
    // ��18 ֱ��ģ������������ pn:�������
    CMD_AFN_D_F138_DC_CURVE          = 0x0D8A,       // ֱ��ģ������������

    // ��19 �ĸ������޹��ܵ���ʾֵ���� pn:�������
    CMD_AFN_D_F145_CURVE_PHASE_1     = 0x0D91,       // һ�����޹��ܵ���ʾֵ����
    CMD_AFN_D_F146_CURVE_PHASE_4     = 0x0D92,       // �������޹��ܵ���ʾֵ����
    CMD_AFN_D_F147_CURVE_PHASE_2     = 0x0D93,       // �������޹��ܵ���ʾֵ����
    CMD_AFN_D_F148_CURVE_PHASE_3     = 0x0D94,       // �������޹��ܵ���ʾֵ����
                                                     // F149��F152 ����

    // ��20 �������ʾֵ pn:�������
    CMD_AFN_D_F153_FRTH_HAVE_D       = 0x0D99,       // �ն�����������й�����ʾֵ �ն���
    CMD_AFN_D_F154_FRTH_NONE_D       = 0x0D9A,       // �ն�����������޹�����ʾֵ �ն���
    CMD_AFN_D_F155_BACK_HAVE_D       = 0x0D9B,       // �ն�����෴���й�����ʾֵ �ն���
    CMD_AFN_D_F156_BACK_NONE_D       = 0x0D9C,       // �ն�����෴���޹�����ʾֵ �ն���
    CMD_AFN_D_F157_FRTH_HAVE_M       = 0x0D9D,       // �¶�����������й�����ʾֵ �¶���
    CMD_AFN_D_F158_FRTH_NONE_M       = 0x0D9E,       // �¶�����������޹�����ʾֵ �¶���
    CMD_AFN_D_F159_BACK_HAVE_M       = 0x0D9F,       // �¶�����෴���й�����ʾֵ �¶���
    CMD_AFN_D_F160_BACK_NONE_M       = 0x0DA0,       // �¶�����෴���޹�����ʾֵ �¶���

    // ��21 pn:�������
    CMD_AFN_D_F161_HAVE_FRTH_D       = 0x0DA1,       // �����й�����ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F162_NONE_FRTM_D       = 0x0DA2,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F163_HAVE_BACK_D       = 0x0DA3,       // �����й�����ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F164_NONE_BACK_D       = 0x0DA4,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F165_NONE_D_PHASE_1    = 0x0DA5,       // һ�����޹�����ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F166_NONE_D_PHASE_2    = 0x0DA6,       // �������޹�����ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F167_NONE_D_PHASE_3    = 0x0DA7,       // �������޹�����ʾֵ���ܡ�����1��M���ն���
    CMD_AFN_D_F168_NONE_D_PHASE_4    = 0x0DA8,       // �������޹�����ʾֵ���ܡ�����1��M���ն���

    // ��22 pn:������� �����ն���
    CMD_AFN_D_F169_HAVE_FRTH_R       = 0x0DA9,       // �����й�����ʾֵ���ܡ�����1��M��  �����ն���
    CMD_AFN_D_F170_NONE_FRTM_R       = 0x0DAA,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M�� �����ն���
    CMD_AFN_D_F171_HAVE_BACK_R       = 0x0DAB,       // �����й�����ʾֵ���ܡ�����1��M��  �����ն���
    CMD_AFN_D_F172_NONE_BACK_R       = 0x0DAC,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M�������ն���
    CMD_AFN_D_F173_NONE_R_PHASE_1    = 0x0DAD,       // һ�����޹�����ʾֵ���ܡ�����1��M�������ն���
    CMD_AFN_D_F174_NONE_R_PHASE_2    = 0x0DAE,       // �������޹�����ʾֵ���ܡ�����1��M�������ն���
    CMD_AFN_D_F175_NONE_R_PHASE_3    = 0x0DAF,       // �������޹�����ʾֵ���ܡ�����1��M�������ն���
    CMD_AFN_D_F176_NONE_R_PHASE_4    = 0x0DB0,       // �������޹�����ʾֵ���ܡ�����1��M�������ն���

    // ��23 pn:�������
    CMD_AFN_D_F177_HAVE_FRTH_M       = 0x0DB1,       // �����й�����ʾֵ���ܡ�����1��M��   �¶���
    CMD_AFN_D_F178_NONE_FRTM_M       = 0x0DB2,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���
    CMD_AFN_D_F179_HAVE_BACK_M       = 0x0DB3,       // �����й�����ʾֵ���ܡ�����1��M��   �¶���
    CMD_AFN_D_F180_NONE_BACK_M       = 0x0DB4,       // �����޹�������޹�1������ʾֵ���ܡ�����1��M���¶���
    CMD_AFN_D_F181_NONE_M_PHASE_1    = 0x0DB5,       // һ�����޹�����ʾֵ���ܡ�����1��M�� �¶���
    CMD_AFN_D_F182_NONE_M_PHASE_2    = 0x0DB6,       // �������޹�����ʾֵ���ܡ�����1��M�� �¶���
    CMD_AFN_D_F183_NONE_M_PHASE_3    = 0x0DB7,       // �������޹�����ʾֵ���ܡ�����1��M�� �¶���
    CMD_AFN_D_F184_NONE_M_PHASE_4    = 0x0DB8,       // �������޹�����ʾֵ���ܡ�����1��M�� �¶���

    // ��24 pn:�������
    CMD_AFN_D_F185_HAVE_DMND_FRTH_D  = 0x0DB9,       // �����й��������������ʱ�䣨�ܡ�����1��M���ն���
    CMD_AFN_D_F186_NONE_DMND_FRTH_D  = 0x0DBA,       // �����޹��������������ʱ�䣨�ܡ�����1��M���ն���
    CMD_AFN_D_F187_HAVE_DMND_BACK_D  = 0x0DBB,       // �����й��������������ʱ�䣨�ܡ�����1��M���ն���
    CMD_AFN_D_F188_NONE_DMND_BACK_D  = 0x0DBC,       // �����޹��������������ʱ�䣨�ܡ�����1��M���ն���
    CMD_AFN_D_F189_HAVE_DMND_FRTH_R  = 0x0DBD,       // �����й��������������ʱ�䣨�ܡ�����1��M�������ն���
    CMD_AFN_D_F190_NONE_DMND_FRTH_R  = 0x0DBE,       // �����޹��������������ʱ�䣨�ܡ�����1��M�������ն���
    CMD_AFN_D_F191_HAVE_DMND_BACK_R  = 0x0DBF,       // �����й��������������ʱ�䣨�ܡ�����1��M�������ն���
    CMD_AFN_D_F192_NONE_DMND_BACK_R  = 0x0DC0,       // �����޹��������������ʱ�䣨�ܡ�����1��M�������ն���

    // ��25 pn:�������
    CMD_AFN_D_F193_HAVE_DMND_FRTH_M  = 0x0DC1,       // �����й��������������ʱ�䣨�ܡ�����1��M�� �¶���
    CMD_AFN_D_F194_NONE_DMND_FRTH_M  = 0x0DC2,       // �����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���
    CMD_AFN_D_F195_HAVE_DMND_BACK_M  = 0x0DC3,       // �����й��������������ʱ�䣨�ܡ�����1��M�� �¶���
    CMD_AFN_D_F196_NONE_DMND_BACK_M  = 0x0DC4,       // �����޹��������������ʱ�䣨�ܡ�����1��M�� �¶���
                                                     // F197��F200 ����
    // ��26 pn:�������
    CMD_AFN_D_F201_FREZ_ZONE_1       = 0x0DC9,       // ��һʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F202_FREZ_ZONE_2       = 0x0DCA,       // �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F203_FREZ_ZONE_3       = 0x0DCB,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F204_FREZ_ZONE_4       = 0x0DCC,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F205_FREZ_ZONE_5       = 0x0DCD,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F206_FREZ_ZONE_6       = 0x0DCE,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F207_FREZ_ZONE_7       = 0x0DCF,       // ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
    CMD_AFN_D_F208_FREZ_ZONE_8       = 0x0DD0,       // �ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
    
    // ��27 pn:�������
    CMD_AFN_D_F209_METR_REMOTE_INFO  = 0x0DD1,       // ���ܱ�Զ�̿���ͨ�ϵ�״̬����¼
                                                     // F210��F212 ����
    CMD_AFN_D_F213_METR_SWITCH_INFO  = 0x0DD5,       // ���ܱ��ز���������ʱ��
    CMD_AFN_D_F214_METR_MODIFY_INFO  = 0x0DD6,       // ���ܱ�����޸Ĵ�����ʱ��
    CMD_AFN_D_F215_METR_BUY_USR      = 0x0DD7,       // ���ܱ����õ���Ϣ
    CMD_AFN_D_F216_METR_BALANCE      = 0x0DD8,       // ���ܱ������Ϣ

    // ��27 pn:�������
    CMD_AFN_D_F217_WHITE_YAWP_CURVE  = 0x0DD9,       // ̨�����г����ز����ڵ����������
    CMD_AFN_D_F218_COLOR_YAWP_CURVE  = 0x0DDA,       // ̨�����г����ز����ڵ�ɫ��������
    ///*}                                            // F219��F248 ����
   
    /**********************************
     * ����3������
     * AFN : 0E
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_E_F1_EVENT_1             = 0x0E01,       // ������Ҫ�¼�
    CMD_AFN_E_F2_EVENT_2             = 0x0E02,       // ����һ���¼�
    ///*}                                            // F3-F248 ����

    /**********************************
     * �ļ�����
     * AFN : 0F
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    CMD_AFN_F_F1_TRANS_WAY          = 0x0E01,        // �ļ����䷽ʽ1
    ///*}                                            // F2��F248 ����  

    /**********************************
     * ����ת��
     * AFN : 10H
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    // ��1 Pn:P0
    CMD_AFN_10_F1_TRANSMIT           = 0x1001,       // ͸��ת��
                                                     // F2��F8    ����    
    // ��2 Pn:P0
    CMD_AFN_10_F9_TRANS_READ         = 0x1009,       // ת����վֱ�Ӷ��ն˵ĳ�����������
    CMD_AFN_10_F10_TRANS_SWITCH      = 0x100A,       // ת����վֱ�Ӷ��ն˵�ң����բ/�����բ����
    CMD_AFN_10_F11_TRANS_POWER       = 0x100B,       // ת����վֱ�Ӷ��ն˵�ң���͵�����
    ///*}                                            // F12��F248 ����    

    
    /* ����֮�������չ������ */
    CMD_AFN_FN_MAX  
}eMtCmd;
///*}

/*******************************************************
 *  �����붨�� eMtErr
 *
{*///
typedef enum
{  
    MT_OK,             // �޴���                    0 
    MT_ERR_NULL,       // ָ��Ϊ��                  1 
    MT_ERR_OUTRNG,     // ����Խ��                  2
    MT_ERR_NONE,       // ������,û���ҵ�           3    
    MT_ERR_IO,         // IO����                    4
    MT_ERR_RES,        // ��Դ����                  5
    MT_ERR_INIT,       // û�г�ʼ��                6
    MT_ERR_PARA,       // ��������                  7
    MT_ERR_FN,         // ָ��Afn �в�֧�ֵ� Fn     8 
    MT_ERR_PN,         // ָ��Afn �в�֧�ֵ� Pn     9 
    MT_ERR_ADDR,       // ��Ч��ַ                  10
    MT_ERR_CTRL,       // ���������                11
    MT_ERR_SEQ,        // SEQ�����                 12
    MT_ERR_SEQ2CS,     // SEQ2CS �������           13
    MT_ERR_AFN,        // AFN ����                  14
    MT_ERR_UNCOMP,     // ��������Э���            15
    MT_ERR_0x68,       // ����ı�����ʼ            16
    MT_ERR_PROTO,      // �����Э���ʶ            17
    MT_ERR_CS,         // ����ļ���              18
    MT_ERR_0x16,       // ����Ľ�β��              19
    MT_ERR_LOGIC,      // ����Ĵ����߼�            20
    MT_ERR_PACK,       // ����һ����Ч�İ�          21
    MT_ERR_PFC,        // ���кŲ���Ӧ              22
    MT_ERR_TIMEOUT,    // ���ĳ�ʱ                  23
    MT_ERR_PRM,        // ����վ��ʶ��              24 
    MT_ERR_TEAM,       // Fn��Pn����ͬһ����        25
    MT_ERR_ENCRYPT,    // ���ܴ���                  26
    MT_ERR_DECRYPT,    // ���ܴ���                  27
    
}eMtErr;    
///*} 

/*******************************************************
 *  �¼����Ͷ��� eMtErc
 *
{*///
typedef enum
{
    MT_ERC_UNKOWN,            // δ֪�¼���¼����
    MT_ERC_1_INIT,            // ERC1�����ݳ�ʼ���Ͱ汾�����¼
    MT_ERC_2_PARA_LOSS,       // ERC2��������ʧ��¼
    MT_ERC_3_PARA_MODIFY,     // ERC3�����������¼
    MT_ERC_4_STATE_CHANGE,    // ERC4��״̬����λ��¼
    MT_ERC_5_REMOTE_SWITCH,   // ERC5��ң����բ��¼
    MT_ERC_6_PCTRL_SWITCH,    // ERC6��������բ��¼
    MT_ERC_7_ECTRL_SWITCH,    // ERC7�������բ��¼
    MT_ERC_8_METER_CHANGE,    // ERC8�����ܱ�������
    MT_ERC_9_ELEC_EXCP,       // ERC9��������·�쳣
    MT_ERC_10_VOLT_EXCP,      // ERC10����ѹ��·�쳣
    MT_ERC_11_PHASE_EXCP,     // ERC11�������쳣
    MT_ERC_12_METER_TIME,     // ERC12�����ܱ�ʱ�䳬��
    MT_ERC_13_METER_FAULT,    // ERC13����������Ϣ
    MT_ERC_14_TML_ON_OFF,     // ERC14���ն�ͣ/�ϵ��¼�
    MT_ERC_15_HARM_OVER,      // ERC15��г��Խ�޸澯
    MT_ERC_16_DC_OVER,        // ERC16��ֱ��ģ����Խ�޼�¼
    MT_ERC_17_UNBL_OVER,      // ERC17����ѹ/������ƽ���Խ�޼�¼
    MT_ERC_18_CAPA_LOCK,      // ERC18��������Ͷ��������¼
    MT_ERC_19_BUY_PARA,       // ERC19������������ü�¼
    MT_ERC_20_AUTH_ERROR,     // ERC20����Ϣ��֤�����¼
    MT_ERC_21_TML_FAULT,      // ERC21���ն˹��ϼ�¼
    MT_ERC_22_HAVE_OVER,      // ERC22���й��ܵ������Խ���¼���¼
    MT_ERC_23_ECTRL_WARN,     // ERC23����ظ澯�¼���¼
    MT_ERC_24_VOLT_OVER,      // ERC24����ѹԽ�޼�¼
    MT_ERC_25_ELEC_OVER,      // ERC25������Խ�޼�¼
    MT_ERC_26_SP_OVER,        // ERC26�����ڹ���Խ�޼�¼
    MT_ERC_27_POWER_DOWN,     // ERC27�����ܱ�ʾ���½���¼
    MT_ERC_28_POWER_OVER,     // ERC28�������������¼
    MT_ERC_29_METER_FLY,      // ERC29�����ܱ���߼�¼
    MT_ERC_30_METER_STOP,     // ERC30�����ܱ�ͣ�߼�¼
    MT_ERC_31_READ_FAULT,     // ERC31���ն�485����ʧ���¼���¼
    MT_ERC_32_FLOW_OVER,      // ERC32���ն�����վͨ�������������¼���¼
    MT_ERC_33_METER_WORD,     // ERC33�����ܱ�����״̬�ֱ�λ�¼���¼
    MT_ERC_34_CT_EXCP,        // ERC34��CT�쳣�¼���¼
    MT_ERC_35_UNKOWN,         // ERC35������δ֪����¼���¼
    
}eMtEventRecord, eMtErc; // �¼����Ͷ���

/*******************************************************
 *  ֡�����û��� ���ݽṹת���������Ͷ���
 *
{*///

typedef enum
{
    MT_TRANS_UNKOWN,    // δ֪����
    MT_TRANS_U2F,       // �û������ݽṹ��֡���ݽṹ
    MT_TRANS_F2U,       // ֡�����ݽṹ���û������ݽṹ 
 
}eMtTrans;              // �û�����֡�����ݽṹת������

// ת��֡�����û������ݽṹ�ĺ���ָ������
// pusLen Ϊ��װ��֡��������ֽڳ�
typedef eMtErr (*pMtFunc)(eMtTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);  

///*} 

/*******************************************************
 *  ��������ܺ���
 *  �ؼ����ݵļ���
 *  �����㷨:����Ӧ�ò���Ҫ���ܵĹؼ�����,���öԳ��㷨�������ݼӽ���
 *  ���ܲ���:Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 *  ���ܳ���:ͨ����������öԳ���Կ�㷨���������ݼ��ܳ�����,�û����ݳ��Ȼ���Ӧ�ı�
 *           �ն����յ����öԳ���Կ�㷨���ܵ�������Ϣ��,�����ݽ��н���
 *           ���ܳɹ�����ԭʼ��������Ϣ��������Ϣ�����ݳ���
 *  ��������:��Ҫ���ܵı�������
 *           (1)��λ��������б���
 *           (2)���ò�����������б���
 *           (3)������������б���
 *
 *  �ҵ�����: AFN�Ƿ�Ӧ�ü���   ���ĳ���ܽ��޷������ĸ����ͼ���
 *
{*///
#if MT_CFG_ENCRYPT

// ���ܺ�������
typedef eMtErr (*peMtEncryptFunc)(UINT8* pInData, int nInLen, UINT8* pOutData, int *pOutLen);  

// ���ܺ�������
typedef eMtErr (*peMtDecryptFunc)(UINT8* pInData, int nInLen, UINT8* pOutData, int *pOutLen);  

#endif
///*} 

/*******************************************************************
 *  ʵ�ָ�¼ A.1 ~ A.28 ���ݸ�ʽ�Ķ�����ת������
 *
{*///

/*********************************************
 *  ���ݸ�ʽ01 ���ڱ�A.1
 *  ��ʽ: 
 *  �ֳ�: 6
 *  +-------+------+------+------+------+------+------+------+------+
 *  |              |                       �ֽڸ�ʽ                 |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |����-��| ����BCD��λ        |��BCD |        ��BCD���λ        |
 *  |     |               |��ʮλ|                           |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  ���ڶ������£�D5 ~ D7�����ʾ 0 ~ 7��0����Ч��1-7���α�ʾ����һ��������
{*///

// �û���
typedef struct 
{
    UINT8 ucYear;      //�ն�����ʱ����
    UINT8 ucMonth;     //�ն�����ʱ����
    UINT8 ucWeek;      //�ն�����ʱ������
    UINT8 ucDay;       //�ն�������
    UINT8 ucHour;      //�ն�����ʱ��Сʱ
    UINT8 ucMinute;    //�ն�����ʱ�ӷ���
    UINT8 ucSecond;    //�ն�����ʱ����
    
}sMtUserClock, sMtFmt01, sMtYYWWMMDDhhmmss, sMtYWMDhms;

    
// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  bcd_sec_0:4;  //��
    UINT8  bcd_sec_1:4;
    UINT8  bcd_min_0:4;  // ��
    UINT8  bcd_min_1:4;
    UINT8  bcd_hur_0:4;  // ʱ
    UINT8  bcd_hur_1:4;
    UINT8  bcd_day_0:4;  // ��
    UINT8  bcd_day_1:4;
    UINT8  bcd_mon_0:4;  // ��
    UINT8  bcd_mon_1:1;
    UINT8  bcd_wek_0:3;  // ����
    UINT8  bcd_yea_0:4;  // ��
    UINT8  bcd_yea_1:4;
    
}sMtFrmClock, sMtFmt01_f, sMtYYWWMMDDhhmmss_f;
#pragma pack()

// ת������
eMtErr emt_trans_YYWWMMDDhhmmss(eMtTrans eTrans, sMtUserClock* psUser, sMtFrmClock* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ02 ���ڱ�A.2
 *  ��ʽ: (+/-)XXX * 10(-3~4)   
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |  G3  |  G2  |  G1  |  S   |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  -- 
 *  S       : ����λ
 *  --
 *  G3 G2 G1:
 *  +-------+-------+-------+----------+
 *  |   G3  |  G2   |  G1   |   ����   |
 *  +-------+-------+-------+----------+
 *  |   0   |   0   |   0   |   10(4)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   0   |   1   |   10(3)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   1   |   0   |   10(2)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   1   |   1   |   10(1)  |
 *  +-------+-------+-------+----------+
 *  |   1   |   0   |   0   |   10(0)  |
 *  +-------+-------+-------+----------+
 *  |   1   |   1   |   0   |   10(-1) |
 *  +-------+-------+-------+----------+
 *  |   0   |   0   |   0   |   10(-2) |
 *  +-------+-------+-------+----------+
 *  |   1   |   1   |   1   |   10(-3) |
 *  +-------+-------+-------+----------+
 *
{*///

// �û���
//float fXXX;

// ֡��
typedef struct
{
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :4; // BCD ��λ
    UINT8 S      :1; // ����λ
    UINT8 G1     :1; // 0
    UINT8 G2     :1; // ��λ
    UINT8 G3     :1; // 0
    
}sMtFmt02_f,sMtsXXX;

// ת������
eMtErr emt_trans_sXXX(eMtTrans eTrans, float* psUser, sMtsXXX* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ03 ���ڱ�A.4
 *  ��ʽ: (+/-)XXXXXXX
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD��ǧλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |        BCD��ʮ��λ        |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |  0   |   G  |  0   |  S   |         BCD�����λ       |
 *  +-------+------+------+------+------+------+------+------+------+
 *  G �Ķ��� G = 0, ��ʾ��λΪKWh����; G =1 ��ʾ��λΪMWh��Ԫ
 *
{*///

// �û���
typedef enum
{
    MT_UNIT_UNKOWN,     // δ֪��λ
    MT_UINT_KWH_LI,     // KWh����
    MT_UINT_MWH_YUAN,   // MWh��Ԫ

}eMtUint;

#define MT_SX7_MIN     (-9999999)  
#define MT_SX7_MAX     (9999999)

typedef struct
{
    eMtUint eUnit;
    INT32   nData;   
}sMtWh,sMtMoney, sMtFmt03, sMtFmt_sX7;

// ֡��
typedef struct
{
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :4; // BCD ��λ
    UINT8 BCD_3  :4; // BCD ǧλ
    UINT8 BCD_4  :4; // BCD ��λ
    UINT8 BCD_5  :4; // BCD ʮ��λ
    UINT8 BCD_6  :4; // BCD ����λ
    UINT8 S      :1; // ����λ
    UINT8 rev0   :1; // 0
    UINT8 G      :1; // ��λ
    UINT8 rev1   :1; // 0
    
}sMtFmt03_f,sMtFmt_sX7_f;

// ת������
eMtErr emt_trans_sX7(eMtTrans eTrans, sMtFmt_sX7* psUser, sMtFmt_sX7_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ04 ���ڱ�A.5
 *  ��ʽ: (�ϸ�/�¸�)XX (0 ~ 79)
 *  �ֳ�: 1
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |   S0 |  BCD��ʮλ(0~7)    |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *
 *  S0���壺S0=0����ʾ�ϸ���S0=1����ʾ�¸���
 *
{*///
typedef enum
{
    MT_FLOAT_DIR_UNKOWN,  // δ֪��������
    MT_FLOAT_DIR_UP,      // ֹ��
    MT_FLOAT_DIR_DOWN,    // �¸�

}eMtFloatDir;

#define MT_FLOAT_MIN    (0)
#define MT_FLOAT_MAX    (79)

// �û���
typedef struct
{
    eMtFloatDir eDir;     // ��������
    UINT8       ucValue;  // ������ֵ
}sMtFloat, sMtsXX, sMtFmt04;

// ֡��
typedef struct
{
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :3; // BCD ʮλ
    UINT8 S0     :1; // ����λ
}sMtFmt04_f,sMtsXX_f;

// ת������
eMtErr emt_trans_sXX(eMtTrans eTrans, sMtsXX* psUser, sMtsXX_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ05 ���ڱ�A.6
 *  ��ʽ: (+/-)XXX.X
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD�����λ        |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |  S   |     BCD���λ      |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///
// �û���
// float fsXXX.X

// ֡��
typedef struct
{
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :3; // BCD ��λ
    UINT8 S      :1; // BCD ����λ
}sMtFmt05,sMtFmt05_f, sMtFmt_sXXX_X;

// ת������
eMtErr emt_trans_sXXX_X(eMtTrans eTrans, float* psUser, sMtFmt05* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ06 ���ڱ�A.7
 *  ��ʽ: (+/-)XX.XX
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |  S   |     BCD��ʮλ      |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXX.XX

// ֡��
typedef struct
{
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 S      :1; // ����λ
}sMtFmt06,sMtFmt_sXX_XX;

// ת������
eMtErr emt_trans_sXX_XX(eMtTrans eTrans, float* psUser, sMtFmt06* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ07 ���ڱ�A.8
 *  ��ʽ: (+)XXX.X
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD�����λ        |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD���λ         |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXXX.X

// ֡��
typedef struct
{
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :4; // BCD ��λ
}sMtFmt07, sMtFmt07_f, sMtFmt_XXX_X;

// ת������
eMtErr emt_trans_XXX_X(eMtTrans eTrans, float* psUser, sMtFmt07* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ08 ���ڱ�A.9
 *  ��ʽ: XXXX
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ǧλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// UINT16  xxxx

// ֡��
typedef struct
{
    UINT8 BCD_4:4;  // BCD ��λ
    UINT8 BCD_3:4;  // BCD ʮλ
    UINT8 BCD_2:4;  // BCD ��λ
    UINT8 BCD_1:4;  // BCD ǧλ
}sMtFmt08, sMtFmt08_f, sMtFmt_XXXX;

// ת������
eMtErr emt_trans_XXXX(eMtTrans eTrans, UINT16* psUser, sMtFmt08* psFrame);
///*} 


/*********************************************
 *  ���ݸ�ʽ09 ���ڱ�A.10
 *  ��ʽ: (+/-)XX.XXXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |  S   |     BCD��ʮλ      |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXX.XXXX

// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD ���λ
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :3;  // BCD ʮλ
    UINT8 S      :1;  // ����λ
}sMtFmt09, sMtFmt_sXX_XXXX;

// 10 exp�η� exp < 10
int  nMtPow(UINT8 exp); 

// ת������
eMtErr emt_trans_sXX_XXXX(eMtTrans eTrans, float* psUser, sMtFmt09* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ10 ���ڱ�A.11
 *  ��ʽ: XXXXXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ǧλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |        BCD��ʮ��λ        |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// UINT32 ulXXXXXX

// ֡��
typedef struct
{
  UINT8 BCD_6:4;  // BCD ��λ
  UINT8 BCD_5:4;  // BCD ʮλ
  UINT8 BCD_4:4;  // BCD ��λ
  UINT8 BCD_3:4;  // BCD ǧλ
  UINT8 BCD_2:4;  // BCD ��λ
  UINT8 BCD_1:4;  // BCD ʮ��λ
  
}sMtFmt_XXXXXX, sMtFmt10_f;

// ת������
eMtErr emt_trans_XXXXXX(eMtTrans eTrans, UINT32* psUser, sMtFmt_XXXXXX* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ11 ���ڱ�A.12
 *  ��ʽ: (+)XXXXXX.XX
 *  �ֳ�: 4
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ǧλ         |         BCD���λ         | 
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |        BCD��ʮ��λ        |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// double dXXXXXX.XX

// ֡��
typedef struct
{
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    UINT8 BCD_4  :4;  // BCD ��λ
    UINT8 BCD_5  :4;  // BCD ʮ��λ
    
}sMtFmt11, sMtFmt11_f, sMtFmt_XXXXXX_XX;

// ת������
eMtErr emt_trans_XXXXXX_XX(eMtTrans eTrans, double* psUser, sMtFmt_XXXXXX_XX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ12 ���ڱ�A.13
 *  ��ʽ: (+)XXXXXXXXXXXX
 *  �ֳ�: 6
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |       BCD��ʮλ           |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |       BCD��ǧ��λ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |       BCD��ʮ��λ         |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |       BCD��ǧ��λ         |         BCD�����λ       | 
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE5 |       BCD��ʮ��λ         |         BCD����λ         | 
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE6 |       BCD��ǧ��λ         |         BCD�����λ       | 
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// UINT8 ucData[12];

// ֡��
typedef struct
{
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    UINT8 BCD_4  :4;  // BCD ��λ
    UINT8 BCD_5  :4;  // BCD ʮ��λ
    UINT8 BCD_6  :4;  // BCD ����λ
    UINT8 BCD_7  :4;  // BCD ǧ��λ
    UINT8 BCD_8  :4;  // BCD ��λ
    UINT8 BCD_9  :4;  // BCD ʮ��λ
    UINT8 BCD_10 :4;  // BCD ����λ
    UINT8 BCD_11 :4;  // BCD ǧ��λ
    
}sMtFmt12, sMtFmt_XX_6;

// ת������
eMtErr emt_trans_XX_6(eMtTrans eTrans, UINT8* psUser, sMtFmt_XX_6* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ13 ���ڱ�A.14
 *  ��ʽ: (+)XXXX.XXXX
 *  �ֳ�: 4
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ǧλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// double dXXXX.XXXX

// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD ���λ
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    
}sMtFmt13, sMtFmt_XXXX_XXXX, sMtFmt13_f;

// ת������
eMtErr emt_trans_XXXX_XXXX(eMtTrans eTrans, double* psUser, sMtFmt_XXXX_XXXX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ14 ���ڱ�A.15
 *  ��ʽ: (+)XXXXXX.XXXX
 *  �ֳ�: 5
 *  ��ʽ:
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        | 
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |         BCD��ǧλ         |         BCD���λ         | 
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE5 |        BCD��ʮ��λ        |          BCD����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// double dXXXXXX.XXXX

// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD �ٷ�λ
    UINT8 BCD_0_3:4;  // BCD ʮ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    UINT8 BCD_4  :4;  // BCD ��λ
    UINT8 BCD_5  :4;  // BCD ʮ��λ
    
}sMtFmt14, sMtFmt14_f,sMtFmt_XXXXXX_XXXX;

// ת������
eMtErr emt_trans_XXXXXX_XXXX(eMtTrans eTrans, double* psUser, sMtFmt_XXXXXX_XXXX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ15 ���ڱ�A.16
 *  ��λ: ������ʱ��
 *  �ֳ�: 5
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucYY;        // ��
    UINT8  ucMM;        // ��
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
 
}sMtFmt15, sMtYYMMDDhhmm;
 
// ֡��
typedef struct
{
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_hh_0:4;  // ʱ
    UINT8  bcd_hh_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:4;
    UINT8  bcd_YY_0:4;  // ��
    UINT8  bcd_YY_1:4;
    
}sMtFmt15_f,sMtYYMMDDhhmm_f;

// ת������
eMtErr emt_trans_YYMMDDhhmm(eMtTrans eTrans, sMtYYMMDDhhmm* psUser, sMtYYMMDDhhmm_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ16 ���ڱ�A.17
 *  ��λ: ����ʱ��
 *  �ֳ�: 4
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
    UINT8  ucss;        // ��  
}sMtFmt16, sMtDDHHmmss;

// ֡��
typedef struct
{
    UINT8  bcd_ss_0:4;  // ��
    UINT8  bcd_ss_1:4;
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    
}sMtFmt16_f, sMtDDHHmmss_f;

// ת������
eMtErr emt_trans_DDHHmmss(eMtTrans eTrans, sMtDDHHmmss* psDDHHmmss_u, sMtDDHHmmss_f* psDDHHmmss_f);
///*} 

/*********************************************
 *  ���ݸ�ʽ17 ���ڱ�A.18
 *  ��λ: ����ʱ��
 *  �ֳ�: 4
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucMM;        // ��
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
    
}sMtFmt17, sMtMMDDHHmm;

// ֡��
typedef struct
{
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:4;
    
}sMtFmt17_f, sMtMMDDHHmm_f;

// ת������
eMtErr emt_trans_MMDDHHmm(eMtTrans eTrans, sMtMMDDHHmm* psMMDDHHmm_u, sMtMMDDHHmm_f* psMMDDHHmm_f);
///*} 

/*********************************************
 *  ���ݸ�ʽ18 ���ڱ�A.19
 *  ��λ: ����ʱ��
 *  �ֳ�: 3
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
}sMtFmt18, sMtDDHHmm;

// ֡��
typedef struct
{
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
}sMtFmt18_f, sMtDDHHmm_f;

// ת������
eMtErr emt_trans_DDHHmm(eMtTrans eTrans, sMtDDHHmm* psDDHHmm_u, sMtDDHHmm_f* psDDHHmm_f);
///*} 

/*********************************************
 *  ���ݸ�ʽ19 ���ڱ�A.20
 *  ��λ: ����ʱ��
 *  �ֳ�: 2
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
}sMtFmt19, sMtHHmm;

// ֡��
typedef struct
{
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
}sMtFmt19_f, sMtHHmm_f;

// ת������
eMtErr emt_trans_HHmm(eMtTrans eTrans, sMtHHmm* psHHmm_u, sMtHHmm_f* psHHmm_f);
///*} 

/*********************************************
 *  ���ݸ�ʽ20 ���ڱ�A.21
 *  ��λ: ������
 *  �ֳ�: 3
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucYY;        // ��
    UINT8  ucMM;        // ��
    UINT8  ucDD;        // ��
}sMtFmt20, sMtYYMMDD;

// ֡��
typedef struct
{
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:4;
    UINT8  bcd_YY_0:4;  // ��
    UINT8  bcd_YY_1:4;
}sMtFmt20_f, sMtYYMMDD_f;

// ת������
eMtErr emt_trans_YYMMDD(eMtTrans eTrans, sMtYYMMDD* psUser, sMtYYMMDD_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ21 ���ڱ�A.22
 *  ��λ: ����
 *  �ֳ�: 2
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
{*///

// �û���
typedef struct
{
    UINT8  ucYY;        // ��
    UINT8  ucMM;        // ��
    
}sMtFmt21, sMtYYMM;
 
// ֡��
typedef struct
{
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:4;
    UINT8  bcd_YY_0:4;  // ��
    UINT8  bcd_YY_1:4;
    
}sMtFmt21_f, sMtYYMM_f;

// ת������
eMtErr emt_trans_YYMM(eMtTrans eTrans, sMtYYMM* psUser, sMtYYMM_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ22 ���ڱ�A.23
 *  ��ʽ: (+)X.X
 *  �ֳ�: 1
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |          BCD���λ        |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+

{*///

// �û���
// float fX_X;
 
// ֡��
typedef struct
{
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
}sMtFmt22_f,sMtX_X_f;

// ת������
eMtErr emt_trans_X_X(eMtTrans eTrans, float* psUser, sMtFmt22_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ23 ���ڱ�A.24
 *  ��ʽ: (+)X.X
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |          BCD��ʮλ        |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// float fXX_XXXX;
 
// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD�����λ
    UINT8 BCD_0_3:4;  // BCD��ʮ��λ 
    UINT8 BCD_0_2:4;  // BCD��ٷ�λ 
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD��ʮλ 
    UINT8 BCD_1  :4;  // BCD ��λ
    
}sMtFmt23_f,sMtFmt23, sMtFmt_XX_XXXX;

// ת������
eMtErr emt_trans_XX_XXXX(eMtTrans eTrans, float* psUser, sMtFmt23_f* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ25 ���ڱ�A.26
 *  ��ʽ: (+/-)XXX.XXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ٷ�λ        |        BCD��ǧ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD���λ         |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |  S   |     BCD���λ      |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// float fXXX.XXX

// ֡��
typedef struct
{
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :3;  // BCD ��λ
    UINT8 S      :1;  // ����λ
    
}sMtFmt25,sMtFmt25_f,sMtFmt_sXXX_XXX;

// ת������
eMtErr emt_trans_sXXX_XXX(eMtTrans eTrans, float* psUser, sMtFmt25* psFrame);
///*} 


/*********************************************
 *  ���ݸ�ʽ26 ���ڱ�A.27
 *  ��ʽ: (+)X.XXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ٷ�λ        |        BCD��ǧ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD���λ         |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// float fX.XXX

// ֡��
typedef struct
{
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    
}sMtFmt26,sMtFmt_X_XXX;

// ת������
eMtErr emt_trans_X_XXX(eMtTrans eTrans, float* psUser, sMtFmt26* psFrame);
///*} 

/*********************************************
 *  ���ݸ�ʽ27 ���ڱ�A.28
 *  ��ʽ: XXXXXXXX
 *  �ֳ�: 4
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ǧλ          |        BCD���λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |        BCD��ʮ��λ        |        BCD����λ          |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// UINT32 ulXXXXXXXX

// ֡��
typedef struct
{
    UINT8 BCD_8:4;  // BCD ��λ
    UINT8 BCD_7:4;  // BCD ʮλ
    UINT8 BCD_6:4;  // BCD ��λ
    UINT8 BCD_5:4;  // BCD ǧλ
    UINT8 BCD_4:4;  // BCD ��λ
    UINT8 BCD_3:4;  // BCD ʮ��λ
    UINT8 BCD_2:4;  // BCD ����λ
    UINT8 BCD_1:4;  // BCD ǧ��λ
    
}sMtFmt_XXXXXXXX;

// ת������
eMtErr emt_trans_XXXXXXXX(eMtTrans eTrans, UINT32* psUser, sMtFmt_XXXXXXXX* psFrame);
///*} 

/******************************************************************************
 *  ��������:���ݶ����ܶȶ���
 *  ����˵��: ��¼C
 * 
{*///

// �û���
typedef enum
{
    MT_FREZ_NULL  = 0,    // ������
    MT_FREZ_15    = 1,    // ������ʱ�� 15 ���� (15�֡�30�֡�45�֡�0��)
    MT_FREZ_30    = 2,    // ������ʱ�� 30 ���� (30�֡�0��)
    MT_FREZ_60    = 3,    // ������ʱ�� 60 ���� (0��)
    MT_FREZ_5     = 254,  // ������ʱ�� 5  ���� (5�֡�10�֡�15��......��0��)
    MT_FREZ_1     = 255,  // ������ʱ�� 1  ���� (1�֡�2�֡�3�֡�......0��)
 
}eMtFmtFrez;

// ֡��
// UINT8 ucFrez;

// ת������
eMtErr emt_trans_fmt_freeze(eMtTrans eTrans, eMtFmtFrez* psUser, UINT8* psFrame);
///*} 

/******************************************************************************
 *  ��������:float���͵�
 *  ����˵��: 
 *  �������ڻ�����ָ����ʽ��ʾ���ֽ�Ϊ��������β����ָ������ָ���Ĳ��֡� 
 *  �����ǵ����Ȼ���˫�����ڴ洢�ж���Ϊ�������֣�
 1.����λ(Sign) : 0��������1����Ϊ�� 
 2.ָ��λ��Exponent��:���ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�����λ�洢 
 3.β�����֣�Mantissa����β������ 
{*///
typedef union
{
    float v;
    struct
    {
        unsigned mantissa1 : 23;
        unsigned exponent  : 8;
        unsigned sign      : 1;  
    }s;

}uMtFloatFmt;

int    bMtGetFloatSign(float fVal);              // ȡ��һ��flaot�ķ���λ  sign = -1 / +1
void   vMtSetFloatSign(float *pfVal, int sign);  // ����һ���������ķ���λ sign = -1 / +1
///*}

/******************************************************************************
 * ��������: double ���͵ĺϳ����ϳ�
 * ����˵��: 
 * �������ڻ�����ָ����ʽ��ʾ���ֽ�Ϊ��������β����ָ������ָ���Ĳ��֡� 
 * �����ǵ����Ȼ���˫�����ڴ洢�ж���Ϊ�������֣�
 *   1.����λ(Sign) : 0��������1����Ϊ�� 
 *   2.ָ��λ��Exponent��:���ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�����λ�洢 
 *   3.β�����֣�Mantissa����β������ 
 *
{*///

typedef union 
{
    double v;
    struct 
    {
        unsigned mantissa2 : 32;
        unsigned mantissa1 : 20;
        unsigned exponent  : 11;
        unsigned sign      :  1;
    } s;
 
}uMtDoubleFmt;

int    bMtGetDoubleSign(double dVal);              // ȡ��һ��double�ķ���λ sign = -1 / +1
void   vMtSetDoubleSign(double *pdVal, int sign);  // ����һ���������ķ���λ sign = -1 / +1
///*}
///*} 

typedef enum
{
    MT_ROLE_UNKOWN,    // δ֪���
    MT_ROLE_MASTER,    // ��վ
    MT_ROLE_CONTOR,    // ������ �� �ն�
    
}eMtRole;              // Э��Ӧ��ģ������
 
typedef enum
{
    MT_DIR_UNKOWN,     // δ֪���ķ���
    MT_DIR_M2S,        // ��վ�����������ն�  ����
    MT_DIR_S2M,        // ���������ն˵���վ  ����
    
}eMtDir;               // ���ĵķ��ͷ��� 

typedef enum
{
    MT_PN_UNKOWN,      // δ֪PN����
    MT_PN_P0,          // P0 ������PN ����������
    MT_PN_MP,          // �������(measured point)
    MT_PN_GT,          // �ܼ����(group total)
    MT_PN_CT,          // �����ִ�(control times)
    MT_PN_TK,          // �����  (task number)
    MT_PN_DP,          // ֱ��ģ�����˿ں� (direct current simulation port number)
    MT_PN_TM,          // �ն˺�
    
}eMtPn;

/************************************************************
 *  ��������Ϣ�ṹ
 *
{*///
typedef struct
{    
    eMtCmd  eCmd;
    eMtDir  eDir;
    eMtPn   ePn;
    pMtFunc pFunc;
    char*   pName;    
    
}sMtCmdInfor;    
 ///*}

/************************************************************
 *  ���ݱ�ʶ��Ԫ
 *  ÿ�����ݱ�ʶ��Ԫ����Ϣ�������ʽ��֯��
 *  ÿ�����ݱ�ʶ��Ԫ�������(8)��Fn ��������(8)��Pn
 *
 * -----
 * DADT ֡��ṹ
 * ��Ϣ�� | DA | DA1 | D7 D6 D5 D4 D3 D2 D1 D0
 *        |    | DA2 | D7 D6 D5 D4 D3 D2 D1 D0
 * ��Ϣ�� | DT | DT1 | D7 D6 D5 D4 D3 D2 D1 D0
 *        |    | DT2 | D7 D6 D5 D4 D3 D2 D1 D0
 *
 * ---
 * ��Ϣ��DA����Ϣ��ԪDA1����Ϣ����DA2�����ֽڹ���
 * DA1 ��λ��ʾĳһ��Ϣ�����1��8����Ϣ��
 * DA2 ���ö����Ʊ��뷽ʽ��ʾ��Ϣ����
 * DA1��DA2��ͬ������Ϣ���ʶpn��n = 1��2040��
 * ��Ϣ���ʶpn��Ӧ�ڲ�ͬ��Ϣ���ʶFn���������¸��ֺ���
 * ������š��ܼ���š������ִΡ�ֱ��ģ�����˿ںš������
 *
 * ��Ϣ����DA2 | ��Ϣ��ԪDA1
 *       D7~D0 | D7    D6    D5    D4    D3    D2    D1    D0
 *           1 | p8    p7    p6    P5    p4    p3    p2    p1
 *           2 | p16   p15   p14   p13   p12   p11   p10   p9
 *           3 | p24   p23   p22   p21   p20   p19   p18   p17
 *          .. | ...   ...   ...   ...   ...   ...   ...   ...
 *          255| P2040 P2039 P2038 P2037 P2036 P2035 P2034 P2033
 *
 * ---
 * ��Ϣ��DT����Ϣ��ԪDT1����Ϣ����DT2�����ֽڹ���
 * DT1 ��λ��ʾĳһ��Ϣ�����1��8����Ϣ����
 * DT2 ���ö����Ʊ��뷽ʽ��ʾ��Ϣ����
 * DT1 DT2 ��ͬ������Ϣ���ʶFn��n = 1��248��
 *
 * ��Ϣ����DT2 | ��Ϣ��ԪD T1
 *       D7~D0 | D7   D6   D5   D4   D3   D2   D1   D0
 *           0 | F8   F7   F6   F5   F4   F3   F2   F1
 *           1 | F16  F15  F14  F13  F12  F11  F10  F9
 *           2 | F24  F23  F22  F21  F20  F19  F18  F17
 *          .. | ...  ...  ...  ...  ...  ...  ...  ...
 *          30 | F248 F247 F246 F245 F244 F243 F242 F241
 *
{*///

// �û���ṹ
typedef struct
{
    
    UINT16  usPn[PN_INDEX_MAX];         // Pn (0 ~ 2040)
                                        // MT_PN_MAX  ���ֵ
                                        // MT_PN_MIN  ��Сֵ
                                        // MT_PN_NONE ��Чֵ
                                         
    UINT8   ucFn[FN_INDEX_MAX];         // Fn (1 ~ 248) 
                                        // MT_FN_MAX  ���ֵ
                                        // MT_FN_MIN  ��Сֵ
                                        // MT_FN_NONE ��Чֵ
}sMtPnFn;

// ֡��ṹ
typedef struct
{
    UINT8       ucDA1;         // ��Ϣ��Ԫ
    UINT8       ucDA2;         // ��Ϣ����
    UINT8       ucDT1;         // ��Ϣ��Ԫ
    UINT8       ucDT2;         // ��Ϣ����
    
}sMtDaDt;

// ת������
eMtErr emt_pnfn_to_dadt(sMtPnFn* psPnFn, sMtDaDt* psDaDt);
eMtErr emt_dadt_to_pnfn(sMtDaDt* psDaDt, sMtPnFn* psPnFn);


typedef struct
{
    eMtCmd eCmd;
    UINT16 usPn; 
    
}sMtCmdPn;

// ת������
eMtErr emt_add_cmdpn(sMtCmdPn* psCmdPn,sMtCmdPn sNewCmdPn, UINT8 *pucNumCmdPn);
eMtErr emt_pnfn_to_cmdpn(eMtAFN eAfn, sMtPnFn* psPnFn, UINT8 ucNumPnFn,   sMtCmdPn* psCmdPn, UINT8 *pucNumCmdPn);
eMtErr emt_cmdpn_to_pnfn(eMtAFN eAfn, sMtPnFn* psPnFn, UINT8 *pucNumPnFn, sMtCmdPn* psCmdPn, UINT8  ucNumCmdPn);
eMtErr emt_dadt_to_cmdpn(eMtAFN eAfn, sMtDaDt* psDaDt, UINT8 ucNumDaDt,   sMtCmdPn* psCmdPn, UINT8 *pucNumCmdPn);
eMtErr emt_cmdpn_to_dadt(eMtAFN eAfn, sMtDaDt* psDaDt, UINT8 *pucNumDaDt, sMtCmdPn* psCmdPn, UINT8  ucNumCmdPn);


///*}

/************************************************************
 *  ��ַ��ṹ
 *
{*///
// �û���ṹ
typedef struct
{
    UINT8  acRegionCode[4];    // ����������A1 �籱�� 1100, ���������밴GB 2260-91�Ĺ涨ִ��
    UINT16 usTAddress;         // �ն˻�������ַA2 ��Χ(1 ~ 65535)
    BOOL   bTeamAddr;          // Ϊtrue ��ʾulTAddress Ϊ���ַ, Ϊfalse ��ʾulTAddress��һ��ַ
    UINT8  ucMAddress;         // ��վ��ַ�����ַ��־A3, ��Χ(0~127)
    
}sMtAddress;

// ��֡��ṹ
#pragma pack(1) 
typedef struct
{
    UINT8  acRegionCode[2];    // ����������A1           (BCD)  ���ֽ���ǰ  ���ֽ��ں�
    UINT16 usTAddress;         // �ն˵�ַA2             (BIN)  ��Χ(1 ~ 65535)
    //UINT8  ucTeamAddr:1;     // Ϊ1��ʾ usTerminalAddress Ϊ���ַ,A2 == 0xFFFF���㲥��ַ, Ϊ 0 ��ʾ����ַ
    UINT8  ucMAddress;         // ��վ��ַ�����ַ��־A3 (BIN)  ��ò�Ҫ��λ�� 
    
}sMtAddress_f; // ֡��ַ��ʽ����
#pragma pack()

// ת������
eMtErr emt_trans_address(eMtTrans eTrans, sMtAddress *psAddr_u, sMtAddress_f *psAddr_f);
///*}

/************************************************************
 * ֡������ SEQ
 * ����: ��������֮֡��Ĵ������еı仯����
 * ����: ֡��Ϊ1�ֽ�
 * �ṹ: 
 *     +------+------+------+------+------+------+------+------+
 *     |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *     +------+------+------+------+------+------+------+------+
 *     |  TpV |  FIR |  FIN |  CON |         SEQ / RSEQ        |
 *     +------+------+------+------+------+------+------+------+
 *
 * -------------
 * TpV ֡ʱ���ǩ��Чλ
 *     TpV=0����ʾ�ڸ�����Ϣ������ʱ���ǩTp
 *     TpV=1����ʾ�ڸ�����Ϣ������ʱ���ǩTp
 *
 * -------------
 * FIR ��֡��־ ��"1",���ĵĵ�һ֡
 * FIN ĩ֡��־ ��"1",���ĵ����һ֡  
 *
 *     +-----+-----+------------------------+
 *     | FIR | FIN |        Ӧ��˵��        |  
 *     +-----+-----+------------------------+
 *     |  0  |  0  |      ��֡���м�֡      |  
 *     +-----+-----+------------------------+
 *     |  0  |  1  |      ��֡������֡      |  
 *     +-----+-----+------------------------+
 *     |  1  |  0  |  ��֡����1֡ �к���֡  |  
 *     +-----+-----+------------------------+
 *     |  1  |  1  |          ��֡          |  
 *     +-----+-----+------------------------+
 *
 * -------------
 * PFC ����֡֡��ż�����
 *     ÿһ������վ�ʹӶ�վ֮�����1�������ġ���1�ֽڹ��ɵļ�����Χ
 *     Ϊ0��255������֡֡��ż�����PFC,���ڼ�¼��ǰ����֡�����
 *     ����վÿ����1֡���ĸü�������1,��0��255ѭ����1����,�ط�֡�򲻼�1  
 * 
 * -------------
 *
 * PSEQ ����֡���
 *      PSEQ ȡ��1�ֽڵ�����֡������PFC�ĵ�4λ����ֵ0��15
 *
 * RSEQ ��Ӧ֡���
 *      ��Ӧ֡���RSEQ�����������е�PSEQ��Ϊ��һ����Ӧ֡���
 *      ������Ӧ֡�����RSEQ�Ļ�����ѭ����1����,��ֵ��ΧΪ0��15
 * 
 * 
{*///

typedef enum
{
    MT_POS_UNKOWN,    // δ֪֡λ����Ϣ
    MT_POS_SIGLE,     // ��֡
    MT_POS_MUL_S,     // ��֡��ʼ֡���к���֡
    MT_POS_MUL_M,     // ��֡�м�֡
    MT_POS_MUL_E,     // ��֡���֡
    
}eMtPos;              // ֡��λ������

// �û���
typedef struct
{
    BOOL     bTpv;     // ��ʾ֡����û�� ʱ���ǩ Tp
    BOOL     bCon;     // �Ƿ���Ҫȷ��
    eMtPos   ePos;     // λ��
    UINT8    ucSeq;    // pseq/rseq (0~15) 
    
}sMtSEQ;

// ֡��
typedef struct
{
    UINT8   SEQ : 4;
    UINT8   CON : 1;
    UINT8   FIN : 1;
    UINT8   FIR : 1;
    UINT8   TPV : 1;
    
}sMtSEQ_f;

// ת������
eMtErr emt_trans_seq(eMtTrans eTrans, sMtSEQ *puSEQ, sMtSEQ_f *pfSEQ);
///*}

/************************************************************
 *  ������ṹ��ת������ 
 *
 *  ��֡��Ϊ1�ֽ�
 *      +------+------+------+------+------+------+------+------+
 *      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *      +------+------+------+------+------+------+------+------+
 * ���� |  DIR | PRM  |  FCB |  FCV |           FUNCODE         |
 *------+------+------+------+------+------+------+------+------+
 * ���� |  DIR | PRM  |  ACD |      |           FUNCODE         |
 *      +------+------+------+------+------+------+------+------+
 *
 * DIR ���䷽��λ   DIR = 0 ��ʾ��֡����������վ���������б��� 
 *                  DIR = 1 ��ʾ��֡���������ն˷��������б���
 *  
 * PRM ������־λ   PRM = 1 ��ʾ��֡������������վ
 *                  PRM = 0 ��ʾ��֡�������ԴӶ�վ
 *
 * FCB ֡����λ     (ֻ���������б�����) 
 *                  ��֡������ЧλFCV=1ʱ,FCB��ʾÿ��վ�����ķ���/ȷ��
 *                  ��������/��Ӧ����ı仯λ, FCBλ������ֹ��Ϣ����Ķ�ʧ���ظ�
 *                  ��λ�����е�FCB=0���Ӷ�վ���ո�λ�����FCB��"0"
 *
 * FCV ֡������Чλ (ֻ���������б�����) 
 *                  FCV = 1 ��ʾFCBλ��Ч
 *                  FCV = 0 ��ʾFCBλ��Ч
 *
 * ACD Ҫ�����λ   (ֻ���������б�����) 
 *                  ACD = 1 ��ʾ�ն�����Ҫ�¼��ȴ�����
 *                  ACD = 0 ��ʾ�ն����¼����ݵȴ�����
 * 
 * FUNCODE ������ ���ĵ�����վ���Ӷ�վ�Ĺ����붨�岻ͬ
 *
{*///

typedef enum
{
    MT_PRM_UNKWON,                   // δ֪����
    MT_PRM_ACTIVE,                   // ��֡����������վ
    MT_PRM_PASIVE,                   // ��֡�����ڴӶ�վ
    
}eMtPRM;                             // ��������PRM�ֶ����� 

typedef enum
{
    MT_FCD_RPM1_RESET     = 1,        // ��λ����
    MT_FCD_RPM1_USER      = 4,        // �û�����
    MT_FCD_RPM1_LINK      = 9,        // ��·����
    MT_FCD_RPM1_ASK_1     = 10,       // ����1������
    MT_FCD_RPM1_ASK_2     = 11,       // ����2������
    
}eMtFcodeRpm1;                        // ���б��Ŀ���������

typedef enum
{
    MT_FCD_RPM0_OK        = 0,        // �Ͽ�
    MT_FCD_RPM0_USER      = 8,        // �û�����
    MT_FCD_RPM0_NONE      = 9,        // ����:�����ٻ�������
    MT_FCD_RPM0_LINK      = 11,       // ��·״̬
    
}eMtFcodeRpm0;                        // ���б��Ŀ���������

// �û���
typedef struct
{
    eMtDir     eDir;                   // ������
    eMtPRM     ePRM;                   // ��־�ñ�������������վ ���ǴӶ�վ
    BOOL       bFcv;                   // ֡������ЧλFCV
    BOOL       bAcd_Fcb;               // ACD Ҫ�����λ��Ч (bFcv Ϊ��ʱ)
                                       // ���ϴ��յ����ĺ����µ���Ҫ�¼���ACDλ��"1"��
                                       // �յ���վ�����¼����Ĳ�ִ�к�ACDλ��"0"��
                                       // FCB ֡����λ  ��Ч (bFcv Ϊ��ʱ) 
                                       // ����վ��ͬһ�Ӷ�վ�����µķ���/ȷ�ϻ�����/��Ӧ�������ʱ����FCBȡ�෴ֵ��
                                       // ����վ����ÿһ���Ӷ�վFCBֵ������ʱδ�յ��Ӷ�վ�ı��ģ�����ճ��ֲ��
                                       // ������վ���ı�FCB��״̬���ظ�ԭ���ķ���/ȷ�ϻ�������/��Ӧ����
                                       // ��λ�����е�FCB=0���Ӷ�վ���ո�λ�����FCB��"0"��
    union
    {
        eMtFcodeRpm0 eFcdPrm0;         // �Ӷ�վ
        eMtFcodeRpm1 eFcdPrm1;         // ����վ
    }uFCode;

}sMtCtrl;

// ֡��
// UINT8 ucMtCtrl;

// ת������
eMtErr emt_trans_ctrl(eMtTrans eTrans, sMtCtrl* puCtrl, UINT8* pfCtrl);

// ��װ����
eMtErr emt_get_ctrl(eMtAFN eAFN, eMtDir eDir, eMtPRM ePRM, BOOL bAcd_Fcb, sMtCtrl *psCtrl);
///*}

/************************************************************
 *  �¼�������EC
 *
{*///
typedef struct
{
    UINT8  ucEC1;                      // ��Ҫ�¼�������
    UINT8  ucEC2;                      // һ���¼�������   
    
}sMtEC;                                // �¼�������  
///*}

/************************************************************
 *  ֡��ʱ���ǩ��ʽTP
 *
{*///
// �û���ṹ
typedef struct
{
    UINT8           ucPFC;                 // ����֡֡��ż�����PFC
    UINT8           ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��
    sMtDDHHmmss     sDDHHmmss;             // ����֡����ʱ��
    
}sMtTP;                          

// ֡��ṹ
#pragma pack(1) 
typedef struct
{
     UINT8          ucPFC;                 // ����֡֡��ż�����PFC
     sMtDDHHmmss_f  sDDHHmmss;             // ����֡����ʱ��
     UINT8          ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��
     
}sMtTP_f;           
#pragma pack()

// ת������
eMtErr emt_trans_tp(eMtTrans eTrans, sMtTP* pTP_u, sMtTP_f* pTP_f);

// ��õ�ǰ�û���Tpԭʼ���� 
eMtErr emt_get_tp(UINT8 ucPFC, sMtTP *psuTp);   

// �Ե�ǰʱ��Ϊ��׼�ж�һ��tp�Ƿ�ʱ
BOOL  bmt_tp_timeout(sMtTP *psTP);

// ��õ�ǰ�������Ͷ�Ӧ��aux(tp ec pw)���ֳ�
UINT16 usmt_get_aux_len(eMtAFN eAFN, eMtDir eDir, BOOL bEc, BOOL bTp);  // ��ñ������������֡������ֽ�����
///*}

/************************************************************
 *  �ڲ��ӿ�
 *
{*///
// ͨ���������ͺͱ��ķ����ø������Ӧ�������Ϣ
eMtErr eMtGetCmdInfor(eMtCmd eCmd, eMtDir eDir, sMtCmdInfor* psInfor);

/*******************************************
 *  ���������
 *  Э������Ӧ����ÿ��ʵ�ʵ�������Ϊ��,��֡����Ҫ�����������������0xEE
{*///
BOOL   bmt_is_0xEE(UINT8* pData, UINT16 usLen);  // �ж�֡��ĳ�������Ƿ�����Ч��
void   vmt_set_0xEE(UINT8* pData, UINT16 usLen);  // ��֡��ĳ����������Ϊ��Ч

BOOL   bmt_is_none(UINT8* pData, UINT16 usLen);   // ������ȱ��
void   vmt_set_none(UINT8* pData, UINT16 usLen); // ������������Ϊȱ��
///*}

/*******************************************
 *  ������
 *
{*///
BOOL   bmt_have_pw(eMtAFN eAFN, eMtDir eDir);  // ���౨�����Ƿ�Ӧ����pw�ֶ�
BOOL   bmt_have_ec(eMtAFN eAFN, eMtDir eDir);  // ���౨�����Ƿ�Ӧ����EC�ֶ�
BOOL   bmt_have_tp(eMtAFN eAFN, eMtDir eDir);  // ���౨�����Ƿ�Ӧ����tp�ֶ�
BOOL   bmt_need_con(eMtAFN eAFN, eMtDir eDir); // ���౨���Ƿ���Ҫȷ��
///*}

/*******************************************
 * ���ȷ�������
 *
{*///
// �û�������

typedef struct
{
    eMtCmd      eCmd;         // 
    UINT16      usPn;         // Pn  0 ~ 2040
    BOOL        bOk;
    
}sMtCmdErr;                   // ȷ������� �û������ݽṹ


typedef struct
{
    eMtAFN      eAFN;          // ��Ҫȷ�ϵ�AFN
    UINT8       ucNum;         // ��Ҫȷ�� �� ���ϵ� Fn����
    sMtCmdErr   sOne[1];       // ucNum ��sMtUFnPnErr  
    
}sMtOnebyOne;                  // ȷ������� (�û������ݽṹ)

// ֡������
#pragma pack(1) 
typedef struct
{
    sMtPnFn     sPnFn;
    BOOL        bOk;
    
}sMtFnPnErr;                   // ȷ������� �û������ݽṹ

typedef struct
{
    sMtDaDt     sDaDt;         // ���ݵ�Ԫ��ʶ
    UINT8       ucErr;         // ���� ��ʶ   (0 ��ȷ 1 ����)
 
}sMtOne_f;                     // ȷ�������  ֡�����ݽṹ   

typedef struct
{
    UINT8       ucAFN;
    sMtOne_f    sOne[1];
 
}sMtOneByOne_f;
#pragma pack()
// ת������
eMtErr emtTrans_OneByOne(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: �м�վ����״̬����
 * ��ӦAFN : AFN_03_RELY
 * ��ӦCMD : CMD_AFN_3_F1_RELAY_CTRL
 * PN ���� : P0
{*///

// �û���
typedef struct
{
    // δʵ��
    UINT8 ucData;
}sMtRelayStateCtrl, sMtAfn03F1;   // �м�վ����״̬����

// ֡��
// UINT8 ucRelayCtrl


// ת������
eMtErr emtTrans_afn03f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F1���ն�����ͨ�ſ�ͨ�Ų�������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F1_TML_UP_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F1_TML_UP_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucRTS;             // �ն���������ʱʱ��RTS
    UINT8  ucRTM;             // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
    UINT8  ucReSendTimes;     // �ط����� (0~3)   0 ��ʾ�������ط�
    UINT8  ucHeartBeat;       // ��������
    UINT16 usTmWaitTimeoutS;  // �������ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ�� ���� 0~4095
    BOOL   bAutoReportAsk_1;  // �����Զ��ϱ�1�����ݣ�ͬʱ��Ҫ��վȷ��
    BOOL   bAutoReportAsk_2;  // �����Զ��ϱ�2�����ݣ�ͬʱ��Ҫ��վȷ��
    BOOL   bAutoReportAsk_3;  // �����Զ��ϱ�3�����ݣ�ͬʱ��Ҫ��վȷ��
    
}sMtTmlUpCfg, sMtAfn04F1;   

// ֡��
typedef struct
{
    UINT8  ucRTS;             // �ն���������ʱʱ��RTS
    UINT8  ucRTM;             // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
    UINT8  ucSWTS1;           // �ն˵ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ����ط����� wait ts
    UINT8  ucSWTS2;           // �ն˵ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ����ط����� wait ts
    UINT8  bs8Con;            // ��Ҫ��վȷ�ϵ�ͨ�ŷ���CON=1���ı�־
    UINT8  ucHeartBeat;       // ��������

}sMtTmlUpCfg_f, sMtAfn04F1_f;   

// ת������
eMtErr emtTrans_afn04f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F2���ն�����ͨ�ſ������м�ת������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F2_TML_WIRELESS_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F2_TML_WIRELESS_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    BOOL   bPermit;           // ����M��ֹ���ɵ�1�ֽڵ� D7��ʾ������ֹ�ն�ת������"0"����ֹ���� "1"������
    UINT8  ucAddrCount;       // ��ת�����ն˵�ַ��n���ɵ�1�ֽڵ�D0��D6λ��ʾ����ֵ��Χ0��16��
    UINT16 usAddress[16];     // ��ת���ն˵�ַ��ÿ����ַΪ2�ֽڣ����ն˵�ַA2������ͬ

}sMtTmlConUpWireless, sMtAfn04F2;   

// ֡��
typedef struct
{
    UINT8  ucPermit   :1;      // ����M��ֹ���ɵ�1�ֽڵ� D7��ʾ������ֹ�ն�ת������"0"����ֹ���� "1"������
    UINT8  ucAddrCount:7;      // ��ת�����ն˵�ַ��n���ɵ�1�ֽڵ�D0��D6λ��ʾ����ֵ��Χ0��16��
    UINT16 usAddress[1];       // ��ת���ն˵�ַ��ÿ����ַΪ2�ֽڣ����ն˵�ַA2������ͬ
    
}sMtTmlConUpWireless_f, sMtAfn04F2_f;   

// ת������
eMtErr emtTrans_afn04f2(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F3����վIP��ַ�Ͷ˿�
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F3_MST_IP_PORT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F3_MST_IP_PORT ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT32  ulMainIP;        // ���õ�ַ
    UINT16  usMainPort;      // ���ö˿�
    UINT32  ulBackIP;        // ���õ�ַ
    UINT16  usBackPort;      // ���ö˿� 
    UINT8   ucascAPN[16];    // APN

}sMtMasterIpPort, sMtAfn04F3;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucMainIP[4];     // ���õ�ַ
    UINT16 usMainPort;      // ���ö˿�
    UINT8  ucBackIP[4];     // ���õ�ַ
    UINT16 usBackPort;      // ���ö˿� 
    UINT8  ucascAPN[16];    // APN
    
}sMtMasterIpPort_f, sMtAfn04F3_f;   
#pragma pack()

// ת������
eMtErr emtTrans_afn04f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F4����վ�绰����Ͷ������ĺ���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F4_MST_PHONE_SMS
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F4_MST_PHONE_SMS ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8 ucPhoneMaster[17]; // ��վ�绰����         �֧��16λ�绰����
    UINT8 ucPhoneSMS[17];    // ���ŷ������ĵ绰���� �֧��16λ�绰����
    
}sMtMasterPhoneSms, sMtAfn04F4;   

// ֡��
typedef struct
{
    UINT8 bcdPhoneMaster[8];
    UINT8 bcdPhoneSMS[8]; 
    
}sMtMasterPhoneSms_f, sMtAfn04F4_f;   

// ת������
eMtErr emtTrans_afn04f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F5���ն�����ͨ����Ϣ��֤��������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F5_TML_UP_AUTH
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F5_TML_UP_AUTH ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlUpAuth, sMtAfn04F5;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlUpAuth_f, sMtAfn04F5_f;   
#pragma pack()

// ת������
eMtErr emtTrans_afn04f5(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F6���ն����ַ����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F6_TEAM_ADDR
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F6_TEAM_ADDR ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlTeamAddr, sMtAfn04F6;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlTeamAddr_f, sMtAfn04F6_f;   
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f6(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F7���ն�IP��ַ�Ͷ˿�
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F7_TML_IP_PORT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F7_TML_IP_PORT ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlIpPort, sMtAfn04F7;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlIpPort_f, sMtAfn04F7_f;   
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f7(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F8���ն�����ͨ�Ź�����ʽ����̫ר��������ר����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F8_TML_UP_WAY
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F8_TML_UP_WAY ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlUpWay, sMtAfn04F8;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlUpWay_f, sMtAfn04F8_f;   
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f8(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F9���ն��¼���¼��������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F9_TML_EVENT_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F9_TML_EVENT_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlEventCfg, sMtAfn04F9;   

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucSchemeNum; 
    UINT16 usPara;
    
}sMtTmlEventCfg_f, sMtAfn04F9_f;   
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f9(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F10���ն˵��ܱ�/��������װ�����ò���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F10_TML_POWER_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F10_TML_POWER_CFG ��Ӧ�����нṹ��ͬ
{*///

#define  MT_PAYRATE_NUM_MIN     (1)  // ��������Сֵ
#define  MT_PAYRATE_NUM_MAX     (48) // ���������ֵ

typedef enum
{
    MT_BAUD_DEFAULT,             // 0����ʾ�������û�ʹ��Ĭ�ϵ�
    MT_BAUD_600,                 // ������ 600
    MT_BAUD_1200,                // ������ 1200
    MT_BAUD_2400,                // ������ 2400
    MT_BAUD_4800,                // ������ 4800
    MT_BAUD_7200,                // ������ 7200
    MT_BAUD_9600,                // ������ 9600
    MT_BAUD_19200,               // ������ 19200

}eMtBaudRate;                    // ���������Ͷ���

#define MT_METER_ID_MIN          (1)
#define MT_METER_ID_MAX          (2040)

typedef enum
{
    MT_PROTO_DEFAULT,            // ��ʾ�ն�����Ա���ŵĵ��ܱ�/��������װ�ý��г���
    MT_PROTO_DLT645_97,          // DL/T 645-1997
    MT_PROTO_DLT645_07,          // DL/T 645-2007
    MT_PROTO_AC,                 // ��������װ��ͨ��Э��
    MT_PROTO_SERIAL,             // "���нӿ�����խ����ѹ�ز�ͨ��ģ��"�ӿ�Э��
    MT_PROTO_UNKOWN,             // ����������

}eMtMeterProto;                  // ͨ��Э������


#define MT_DNUM_INTGR_MIN       (4) // ����λ����Сֵ
#define MT_DNUM_INTGR_MAX       (7) // ����λ�����ֵ

#define MT_DNUM_DECIM_MIN       (1) // С��λ����Сֵ
#define MT_DNUM_DECIM_MAX       (4) // С��λ�����ֵ

typedef struct
{
    UINT8       ucInteger;       // ͨ�Ž���ĵ��ܱ���й�����ʾֵ������λ����(4~7)
    UINT8       ucDecimal;       // ͨ�Ž���ĵ��ܱ���й�����ʾֵ��С��λ����(1~4)
}sMtDigitNum;                    // ������С��λ��


#define MT_METER_PORT_MIN       (1)  // ͨ�Ŷ˿ں���Сֵ
#define MT_METER_PORT_MAX       (31) // ͨ�Ŷ˿ں����ֵ

typedef struct
{
    eMtBaudRate    eBaudRate;        // �����ʾ���ܱ���������װ�����ն˵�ͨ�Ų�����
    UINT8          ucPort;           // ���ܱ���������װ�����ն���������Ӧ���ն�ͨ�Ŷ˿ںţ���ֵ��Χ1��31������ֵ��Ч��
}sMtBaudPort;                        // ͨ�����ʼ��˿ں�

#define MT_USER_CLASS_MIN        (1)  // �û���������Сֵ 
#define MT_USER_CLASS_MAX        (16) // �û����������ֵ

typedef struct
{
    UINT8        ucBig;          // �����ʾ�����ܱ��������û�����ţ���ֵ��Χ0��15��
                                 // ���α�ʾ16���û������
    UINT8        ucSmall;        // �����ʾ�����ܱ��������û�С��ţ���ֵ��Χ0��15��
                                 // ���α�ʾ16��1���2������������ã�Ӧ���ն�֧�ֵ�1���2���������÷�Χ�ڣ���
}sMtUserClass;                   // �û����


typedef struct
{
    // �����ֶ�
    BOOL           busMeterID;          // ���ܱ�/��������װ����ţ���ֵ��Χ1��2040
    BOOL           busPn;               // ����������ţ���ֵ��Χ0��2040����Ϊ"0"��
    BOOL           bsBaudPort;          // ͨ�����ʼ��˿ں�
    BOOL           beProto;             // ͨ��Э������
    BOOL           bacMeterAddr;        // ͨ�ŵ�ַ����ֵ��Χ0��999999999999��
    BOOL           bacPwd;              // ͨ�����룺�ն�����ܱ�ͨ�ŵ�����
    BOOL           bucPayRateNum;       // ���ܷ��ʸ��� ��ʾͨ�Ž���Ĳ�����ĵ��ܷ��ʸ�������ֵ��Χ1��48
    BOOL           bsDigit;             // �й�����ʾֵ����λ��С��λ����
    BOOL           bacGathrAddr;        // �����ɼ���ͨ�ŵ�ַ����ֵ��Χ0��999999999999����Ϊ"0"����ʾ�����ܱ�δͨ���ɼ�������
    BOOL           bsUserClass;         // �û�����ż��û�С���

    // ʵ������
    UINT16         usMeterID;           // ���ܱ�/��������װ����ţ���ֵ��Χ1��2040 MT_METER_ID_MIN
    UINT16         usPn;                // ����������ţ���ֵ��Χ0��2040����Ϊ"0"��
    sMtBaudPort    sBaudPort;           // ͨ�����ʼ��˿ں�
    eMtMeterProto  eProto;              // ͨ��Э������
    UINT8          acMeterAddr[12];     // ͨ�ŵ�ַ����ֵ��Χ0��999999999999��
    UINT8          acPwd[6];            // ͨ�����룺�ն�����ܱ�ͨ�ŵ�����
    UINT8          ucPayRateNum;        // ���ܷ��ʸ��� ��ʾͨ�Ž���Ĳ�����ĵ��ܷ��ʸ�������ֵ��Χ1��48
    sMtDigitNum    sDigit;              // �й�����ʾֵ����λ��С��λ����
    UINT8          acGathrAddr[12];     // �����ɼ���ͨ�ŵ�ַ����ֵ��Χ0��999999999999����Ϊ"0"����ʾ�����ܱ�δͨ���ɼ�������
    sMtUserClass   sUserClass;          // �û�����ż��û�С���
    
}sMtTmlPowerCfgOne;                     // �ն˵��ܱ�/����װ���������ݵ�Ԫ��ʽ


// �û���
typedef struct
{
    UINT16             usNum;        // ���ε��ܱ�/��������װ����������n����ֵ��Χ0��2040
    sMtTmlPowerCfgOne  sOne[1];      // usCfgNum ��������Ϣ
    
}sMtTmlPowerCfg, sMtAfn04F10;   

// ֡��
#pragma pack(1) 
typedef struct
{    
    UINT8          ucPort    :5;    // ���ܱ���������װ�����ն���������Ӧ���ն�ͨ�Ŷ˿ںţ���ֵ��Χ1��31������ֵ��Ч��
    UINT8          ucBaudRate:3;    // �����ʾ���ܱ���������װ�����ն˵�ͨ�Ų�����
    
}sMtBaudPort_f;                     // ͨ�����ʼ��˿ں�

typedef struct
{   
    UINT8       ucDecimal:2;        // D1��D0�������ʾͨ�Ž���ĵ��ܱ���й�����ʾֵ��С��λ��������ֵ��Χ0��3���α�ʾ1��4λС����
    UINT8       ucInteger:2;        // D3��D2�������ʾͨ�Ž���ĵ��ܱ���й�����ʾֵ������λ��������ֵ��Χ0��3���α�ʾ4��7λ������
    UINT8       ucRev    :4;        //  D7��D6�����á�
}sMtDigitNum_f;  


typedef struct
{ 
    UINT8        ucSmall:4;       // �����ʾ�����ܱ��������û�С��ţ���ֵ��Χ0��15��
                                  // ���α�ʾ16��1���2������������ã�Ӧ���ն�֧�ֵ�1���2���������÷�Χ�ڣ���
    UINT8        ucBig  :4;       // �����ʾ�����ܱ��������û�����ţ���ֵ��Χ0��15��
                                  // ���α�ʾ16���û������
}sMtUserClass_f;                  // �û����

typedef struct
{
    UINT16         usMeterID;           // ���ܱ�/��������װ����ţ���ֵ��Χ1��2040
    UINT16         usPn;                // ����������ţ���ֵ��Χ0��2040����Ϊ"0"��
    sMtBaudPort_f  sBaudPort;           // ͨ�����ʼ��˿ں�
    UINT8          ucProto;             // ͨ��Э������
    sMtFmt_XX_6    acMeterAddr;         // ͨ�ŵ�ַ����ֵ��Χ0��999999999999��
    UINT8          acPwd[6];            // ͨ�����룺�ն�����ܱ�ͨ�ŵ�����
    UINT8          ucPayRateNum;        // ���ܷ��ʸ��� ��ʾͨ�Ž���Ĳ�����ĵ��ܷ��ʸ�������ֵ��Χ1��48
    sMtDigitNum_f  sDigit;              // �й�����ʾֵ����λ��С��λ����
    sMtFmt_XX_6    acGathrAddr;         // �����ɼ���ͨ�ŵ�ַ����ֵ��Χ0��999999999999����Ϊ"0"����ʾ�����ܱ�δͨ���ɼ�������
    sMtUserClass_f sUserClass;          // �û�����ż��û�С���

}sMtTmlPowerCfgOne_f; 

typedef struct
{
    UINT16              usNum;        // ���ε��ܱ�/��������װ����������n����ֵ��Χ0��2040
    sMtTmlPowerCfgOne_f sOne[1];      // usCfgNum ��������Ϣ
    
}sMtTmlPowerCfg_f, sMtAfn04F10_f;   
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f10(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F11���ն��������ò���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F11_TML_PULSE_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F11_TML_PULSE_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
#define MT_PULSE_CFG_MIN    (0)
#define MT_PULSE_CFG_MAX    (64)

#define MT_PULSE_PORT_MIN   (1)   // ��������˿ں� ��Сֵ
#define MT_PULSE_PORT_MAX   (64)  // ��������˿ں� ���ֵ

typedef enum
{
    MT_PULSE_FORTH_HAVE,    // �����й�
    MT_PULSE_FORTH_NONE,    // �����޹�
    MT_PULSE_BACK_HAVE,     // �����й�
    MT_PULSE_BACK_NONE,     // �����޹�
    
}sMtPulse;                  // ��������

typedef struct
{
    UINT8     ucPort;           // ��������˿ںţ���������ն˵���������˿ںţ���ֵ��Χ1��64��
    UINT8     ucPn;             // ����������ţ���ֵ��Χ0��64����Ϊ"0"����ʾ���˿ڵ�����δָ���κβ����㣬����"ɾ��"��
    sMtPulse  ePulse;           // ��������
    UINT16    usK;              // �����k
    
}sMtTmlPulseCfgOne;

typedef struct
{
    UINT8             ucNum;            // ������������·��n����ֵ��Χ0��64  MT_PULSE_CFG_MAX
    sMtTmlPulseCfgOne aTmlPulseCfg[1];  // ucNum������

}sMtTmlPulseCfg,sMtAfn04F11;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucPort;           // ��������˿ںţ���������ն˵���������˿ںţ���ֵ��Χ1��64��
    UINT8  ucPn;             // ����������ţ���ֵ��Χ0��64����Ϊ"0"����ʾ���˿ڵ�����δָ���κβ����㣬����"ɾ��"��
    UINT8  ucPulse;          // ��������
    UINT16 usK;              // �����k

}sMtTmlPulseCfgOne_f;

typedef struct
{
    UINT8              ucNum;             // ������������·��n����ֵ��Χ0��64��
    sMtTmlPulseCfgOne_f aTmlPulseCfg[1];  // ucNum������

}sMtTmlPulseCfg_f,sMtAfn04F11_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f11(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F12���ն�״̬���������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F12_TML_STATE_INPUT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F12_TML_STATE_INPUT ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
    MT_INPUT_UNKOWN,   // δ֪
    MT_INPUT_ON,       // ����
    MT_INPUT_OFF       // δ����
    
}eMtStateInput;        // ״̬�������־

typedef enum
{
    MT_ATTR_UNKOWN,    // δ֪
    MT_ATTR_ON,        // ��������
    MT_ATTR_OFF,       // ���մ���
    
}eMtStateAttr;         // ״̬�����Ա�־λ

// �û���
typedef struct
{
    eMtStateInput aeStateInput[8];  // 1��8·״̬�����룬��"1"������    ��"0"��δ����
    eMtStateAttr  aeStateAttr[8];   // 1��8·״̬�����룬��"1"��������  ��"0"�����մ���

}sMtTmlStateInput, sMtAfn04F12;

// ֡��
typedef struct
{
    UINT8 ucStateInput;
    UINT8 ucStateAttr;

}sMtTmlStateInput_f, sMtAfn04F12_f;

// ת������
eMtErr emtTrans_afn04f12(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F13���ն˵�ѹ/����ģ�������ò���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F13_TML_SIMULA_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F13_TML_SIMULA_CFG ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
    MT_SIMU_UNKOWN,     // δ֪
    MT_SIMA_UA,         // A���ѹ
    MT_SIMA_UB,         // B���ѹ
    MT_SIMA_UC,         // C���ѹ
    MT_SIMA_IA,         // A�����
    MT_SIMA_IB,         // B�����
    MT_SIMA_IC,         // C�����
    
}eMtSimulaType;         // ��ѹ/����ģ��������

typedef struct
{
    UINT8         ucPort;       // ��ѹ/����ģ��������˿ںţ���ѹ/����ģ���������ն˵�ģ��������˿ںţ���ֵ��Χ1��64
    UINT8         ucPn;         // ����������ţ���ֵ��Χ0��64����Ϊ"0"����ʾ���˿ڵĵ�ѹ/����ģ����δָ���κβ����㣬����"ɾ��"   
    eMtSimulaType eType;        // ��ѹ/����ģ��������
    
}sMtTmlSimulaCfgOne;

// �û���
typedef struct
{
    UINT8               ucNum;       // ���ε�ѹ/����ģ��������·��n����ֵ��Χ0��64��
    sMtTmlSimulaCfgOne  sOne[1];     // ucNum ��������Ϣ
    
}sMtTmlSimulaCfg, sMtAfn04F13;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8         ucPort;       // ��ѹ/����ģ��������˿ںţ���ѹ/����ģ���������ն˵�ģ��������˿ںţ���ֵ��Χ1��64
    UINT8         ucPn;         // ����������ţ���ֵ��Χ0��64����Ϊ"0"����ʾ���˿ڵĵ�ѹ/����ģ����δָ���κβ����㣬����"ɾ��"   
    UINT8         ucType;       // ��ѹ/����ģ��������
}sMtTmlSimulaCfgOne_f;

typedef struct
{
    UINT8                 ucNum;       // ���ε�ѹ/����ģ��������·��n����ֵ��Χ0��64��
    sMtTmlSimulaCfgOne_f  sOne[1];     // ucNum ��������Ϣ
}sMtTmlSimulaCfg_f, sMtAfn04F13_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f13(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F14���ն��ܼ������ò���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F14_TML_GRUP_TOTL
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F14_TML_GRUP_TOTL ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
    MT_MPDIR_UNKOWN,    // δ֪
    MT_MPDIR_FORTH,     // ����
    MT_MPDIR_BACK,      // ����
}eMtMpDir;              // ��ʾ������������Ƿ����й�/�޹����ʡ��й�/�޹������������ܼӵı�־

typedef enum
{
    MT_MTOPER_PLUS,     // ������
    MT_MTOPER_SUBS,     // ������
}eMtMpOper;             // �����ܼ�������������־

typedef struct
{
    UINT8         ucPort;       // ��ʾ0��63��˳���Ӧ��1����64��������š�
    eMtMpDir      eMpDir;       // ��ʾ������������Ƿ����й�/�޹����ʡ��й�/�޹������������ܼӵı�־
    eMtMpOper     eMpOper;      // ��ʾ�����ܼ�������������־����"0"��"��"���㣻��"1"��"��"���㡣
}sMtMpDir;

typedef struct
{
    UINT8  ucGroupID;           // �ܼ�����ţ���ֵ��Χ1��8
    UINT8  ucM;                 // �ܼ���Ĳ���������m����ֵ��Χ0��64����Ϊ"0"����ʾ���ܼ���û��Ҫ�����ܼӵĲ����㣬����"ɾ��"��
    sMtMpDir sOne[64];          // ��1 ~ M ��������ż��ܼӱ�־
}sMtTmlGrupTotlOne;

// �û���
typedef struct
{
    UINT8               ucN;         // �����ܼ�����������n����ֵ��Χ1��8��
    sMtTmlGrupTotlOne   sOne[1];     // ucN��������Ϣ
}sMtTmlGrupTotl, sMtAfn04F14;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucGroupID;           // �ܼ�����ţ���ֵ��Χ1��8
    UINT8  ucM;                 // �ܼ���Ĳ���������m����ֵ��Χ0��64����Ϊ"0"����ʾ���ܼ���û��Ҫ�����ܼӵĲ����㣬����"ɾ��"��
    UINT8  ucOne[1];            // ��1 ~ M ��������ż��ܼӱ�־
}sMtTmlGrupTotlOne_f;

typedef struct
{
    UINT8                 ucN;       // ���ε�ѹ/����ģ��������·��n����ֵ��Χ0��64��
    sMtTmlGrupTotlOne_f   sOne[1];   // ucN ��������Ϣ
}sMtTmlGrupTotl_f, sMtAfn04F14_f;
#pragma pack() 
// ת������
eMtErr emtTrans_afn04f14(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F15���й��ܵ������Խ���¼���������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F15_HAVE_DIFF_EVENT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F15_HAVE_DIFF_EVENT ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
    MT_DIFF_TIME_UNKOWN, 
    MT_DIFF_TIME_15,     // 15���ӵ���
    MT_DIFF_TIME_30,     // 30���ӵ���
    MT_DIFF_TIME_60,     // 60���ӵ���
    
}eMtDiffTime;            // ��������ʱ����

typedef enum
{
    MT_DIFF_COMPR_REL,     // ��ԶԱ�
    MT_DIFF_COMPR_ABS,     // ���ԶԱ�
}eMtDiffCompr;             // �Աȷ�����־

typedef struct
{
    eMtDiffTime  eTime;   // ��������ʱ����
    eMtDiffCompr eCompr;  // �Աȷ�����־
}sMtDiffCompr;

typedef struct
{
    UINT8        ucDiffID;            // �й��ܵ����������ţ���ֵ��Χ1��8
    UINT8        ucComprID;           // �Աȵ��ܼ������ ��ֵ��Χ0��8�����������е���һ��Ϊ"0"����ʾ�����û��Ҫ����Աȵ��ܼ��飬����"ɾ��"��
    UINT8        ucReferID;           // ���յ��ܼ������ ��ֵ��Χ0��8�����������е���һ��Ϊ"0"����ʾ�����û��Ҫ����Աȵ��ܼ��飬����"ɾ��"��
    sMtDiffCompr sDiff;               // �����ĵ�������ʱ�����估�Աȷ�����־
    UINT8        ucValueRel;          // �Խ�����ƫ��ֵ(��)
    sMtFmt_sX7   sValueAbs;           // �Խ�޾���ƫ��ֵ(kWh)
}sMtHaveDiffEventOne;

// �û���
typedef struct
{
    UINT8                 ucN;          // �����й��ܵ����������������n����ֵ��Χ1��8��
    sMtHaveDiffEventOne   sOne[1];      // ucN��������Ϣ

}sMtHaveDiffEvent, sMtAfn04F15;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8        ucDiffID;            // �й��ܵ����������ţ���ֵ��Χ1��8
    UINT8        ucComprID;           // �Աȵ��ܼ������ ��ֵ��Χ0��8�����������е���һ��Ϊ"0"����ʾ�����û��Ҫ����Աȵ��ܼ��飬����"ɾ��"��
    UINT8        ucReferID;           // ���յ��ܼ������ ��ֵ��Χ0��8�����������е���һ��Ϊ"0"����ʾ�����û��Ҫ����Աȵ��ܼ��飬����"ɾ��"��
    UINT8        ucDiff;               // �����ĵ�������ʱ�����估�Աȷ�����־
    UINT8        ucValueRel;          // �Խ�����ƫ��ֵ(��)
    sMtFmt_sX7_f sValueAbs;           // �Խ�޾���ƫ��ֵ(kWh)

}sMtHaveDiffEventOne_f;

typedef struct
{
    UINT8                   ucN;       // �����й��ܵ����������������n����ֵ��Χ1��8��
    sMtHaveDiffEventOne_f   sOne[1];   // ucN��������Ϣ

}sMtHaveDiffEvent_f, sMtAfn04F15_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f15(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F16������ר���û���������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F16_VPN_USER_PWD
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F16_VPN_USER_PWD ��Ӧ�����нṹ��ͬ
{*///

#define MT_VPN_PWD_LEN         (32)
#define MT_VPN_USR_LEN         (32)

// �û���
typedef struct
{
    UINT8  ucUser[MT_VPN_USR_LEN]; // ����ר���û���
    UINT8  ucPwd[MT_VPN_PWD_LEN];  // ����ר������

}sMtVpnUserPwd, sMtVpnUserPwd_f,sMtAfn04F16_f;

// ֡��
// sMtVpnUserPwd_f,sMtAfn04F16_f


// ת������
eMtErr emtTrans_afn04f16(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F17���ն˱�����ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F17_TML_SAFE_VALUE
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F17_TML_SAFE_VALUE ��Ӧ�����нṹ��ͬ
{*///

// �û���
// float fTmlSafeValue;

// ֡�� 
//sMtFmt02_f sXXX;

// ת������
eMtErr emtTrans_afn04f17(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F18���ն˹���ʱ��
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F18_TML_PCTRL_PERD
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F18_TML_PCTRL_PERD ��Ӧ�����нṹ��ͬ
{*///
typedef enum
{
    MT_PCTRL_UNKOWN, // δ֪���Ʒ�ʽ
    MT_PCTRL_NONE,   // ������
    MT_PCTRL_1,      // ����1
    MT_PCTRL_2,      // ����1

}eMtPCtrl;

typedef struct
{
   eMtPCtrl eFrntHalf;   // ǰ��Сʱ
   eMtPCtrl eBackHalf;   // ���Сʱ
  
}sMtPCtrlHour;

// �û���
typedef struct
{
   sMtPCtrlHour sPCtrlHour[24];  

}sMtPCtrl;            // �ն˹���ʱ�����ݵ�Ԫ��ʽ

// ֡�� 
typedef struct
{
    UINT8 uc2Hour[12];
    
}sMtPCtrl_f;

// ת������
eMtErr emtTrans_afn04f18(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F19���ն�ʱ�ι��ض�ֵ����ϵ��
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F19_TML_PCTRL_FACTOR
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F19_TML_PCTRL_FACTOR ��Ӧ�����нṹ��ͬ
{*///

// �û���
// sMtFloat sTmlPCtrlFactor;

// ֡�� 
//sMtFmt04_f sXXX;

// ת������
eMtErr emtTrans_afn04f19(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F20���ն��µ������ض�ֵ����ϵ��
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F20_TML_MONTH_FACTOR
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F20_TML_MONTH_FACTOR ��Ӧ�����нṹ��ͬ
{*///

// �û���
// sMtFloat sTmlMonthFactor;

// ֡�� 
//sMtFmt04_f sXXX;

// ת������
eMtErr emtTrans_afn04f20(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F21���ն˵���������ʱ�κͷ�����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F21_TML_POWER_FACTOR
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F21_TML_POWER_FACTOR ��Ӧ�����нṹ��ͬ
{*///

// #define MT_PAYRATE_NUM_MAX
// #define MT_PAYRATE_NUM_MIN

#define MT_PAYRATE_ID_MAX   MT_PAYRATE_NUM_MAX
#define MT_PAYRATE_ID_MIN   MT_PAYRATE_NUM_MIN

// �û���
typedef struct
{
    UINT8 ucPayRateID[48];  // ���ʺ�   ���α�ʾ (0��00��0��30) .... (23��30��0��00) ʱ�η��ʺ�
    UINT8 ucPayRateNum;     // ������

}sMtTmlPowerFactor, sMtTmlPowerFactor_f;

// ֡�� 
//sMtTmlPowerFactor_f;

// ת������
eMtErr emtTrans_afn04f21(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F22���ն˵���������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F22_TML_POWER_RATE
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F22_TML_POWER_RATE ��Ӧ�����нṹ��ͬ
{*///

// #define MT_PAYRATE_NUM_MAX
// #define MT_PAYRATE_NUM_MIN

// �û���
typedef struct
{
    UINT8     ucM;             // ������M
    sMtMoney  sPayRate[1];     // ��1 ~ M ����

}sMtTmlPowerRate, sMtAfn04f22;

// ֡�� 
#pragma pack(1) 
typedef struct
{
    UINT8     ucM;               // ������M
    sMtFmt03_f  sPayRate[1];     // ��1 ~ M ����

}sMtTmlPowerRate_f, sMtAfn04f22_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f22(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F23���ն˴߷Ѹ澯����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F23_TML_WARNING_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F23_TML_WARNING_CFG ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
   MT_WARN_UNKOWN,   // δ֪
   MT_WARN_GO,       // �澯
   MT_WARN_STOP,     // ���澯
   
}eMtWarning;

// �û���
typedef struct
{
   eMtWarning eHour[24];         // ��ʾ�� 0��00��1��00 ÿ��Сʱʱ���Ƿ�澯

}sMtTmlWarningCfg, sMtAfn04f23;  // �ն˴߷Ѹ澯�������ݵ�Ԫ��ʽ

// ֡�� 
typedef struct
{
    UINT8 ucHour[3];            // D0��D23��˳���λ��ʾ0��23�㣬ÿλ��Ӧ��ʾ1��Сʱ����"1"���澯����"0"�����澯��

}sMtTmlWarningCfg_f, sMtAfn04f23_f;

// ת������
eMtErr emtTrans_afn04f23(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F25���������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F25_MP_BASE_CFG
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F25_MP_BASE_CFG ��Ӧ�����нṹ��ͬ
{*///
typedef enum
{   
    MT_CONCT_UNKOWN, // δ֪
    MT_CONCT_P3_L3,  // ��������
    MT_CONCT_P3_L4,  // ��������
    MT_CONCT_P1,     // �����
    
}eMtConnect;

typedef enum
{
    MT_PHASE_UNKOWN, // δ֪
    MT_PHASE_A,      // A ��
    MT_PHASE_B,      // B ��
    MT_PHASE_C,      // C ��
    
}eMtPhase;

typedef struct
{
    eMtConnect eConnect;
    eMtPhase   ePhase;
    
}sMtConnectWay; // ��Դ���߷�ʽ

// �û���
typedef struct
{ 
    UINT16         usTimesU;            // ��ѹ����������
    UINT16         usTimesI;            // ��������������
    float          fU;                  // ���ѹ   (+)XXX.X  (V)
    float          fI;                  // �����
    float          fP;                  // �����
    
}sMtMpBaseCfg, sMtAfn04f25;             // ����������������ݵ�Ԫ��ʽ

// ֡�� 
#pragma pack(1) 
typedef struct
{
    UINT16         usTimesU;            // ��ѹ����������
    UINT16         usTimesI;            // ��������������
    sMtFmt_XXX_X   fU;                  // ���ѹ   (+)XXX.X  (V)
    sMtX_X_f       fI;                  // �����
    sMtFmt_XX_XXXX fP;                  // �����
    
}sMtMpBaseCfg_f, sMtAfn04f25_f;         // ����������������ݵ�Ԫ��ʽ
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F26����������ֵ����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F26_MP_LIMIT_CFG
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F26_MP_LIMIT_CFG ��Ӧ�����нṹ��ͬ
{*///

typedef struct
{
    float    fMax;        // ��ѹ�ϸ�����   XXX.X  (V)
    float    fMin;        // ��ѹ�ϸ�����   XXX.X  (V)
    float    fDrop;       // ��ѹ��������   XXX.X  (V)

}sMtStandRateU;           // ��ѹ�ϸ����б����

typedef struct
{
    float    fMax;        // ��ѹ�����ޣ���ѹ���ޣ�XXX.X  (V)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtOverU;                // ��ѹ�б���� 

typedef struct
{
    float    fMin;        // ��ѹ�����ޣ�Ƿѹ���ޣ�XXX.X  (V)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)

}sMtLossU;                // Ƿѹ�б����

typedef struct
{
    float    fMax;        // ����������ޣ��������ޣ�(+/-)XXX.XXX (A)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtOverI;                // �����б���� 

typedef struct
{
    float    fMax;        // ��������ޣ���������ޣ�(+/-)XXX.XXX (A)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtExcesI;               // ��������б���� 

typedef struct
{
    float    fMax;        // ��������ޣ���������ޣ�(+/-)XXX.XXX (A)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtOverI0;               // ������������б����
 
typedef struct
{
    float    fMax;        // ��������ޣ���������ޣ�(+/-)XX_XXXX (A)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUpLimitS;             // ���ڹ��ʳ��������б����

typedef struct
{
    float    fMax;        // ��������ޣ���������ޣ�(+/-)XX_XXXX (A)
    UINT8    ucMins;      // Խ�޳���ʱ��  (min)
    float    fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtLimitS;               // ���ڹ��ʳ������б����

typedef struct
{
    float    fLimit;       // �����ѹ��ƽ����ֵ XXX.X (%)
    UINT8    ucMins;       // Խ�޳���ʱ��  (min)
    float    fRenew;       // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUbU;                   // �����ѹ��ƽ�ⳬ���б����

typedef struct
{
    float    fLimit;        // ���������ƽ����ֵ XXX.X (%)
    UINT8    ucMins;       // Խ�޳���ʱ��  (min)
    float    fRenew;       // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUbI;                   // ���������ƽ�ⳬ���б����


// �û���
typedef struct
{
    sMtStandRateU  sU;       // ��ѹ�ϸ����б����   
    sMtOverU       sOverU;   // ��ѹ�б���� 
    sMtLossU       sLossU;   // Ƿѹ�б����
    sMtOverI       sOverI;   // �����б����
    sMtExcesI      sExcesI;  // ��������б����
    sMtOverI0      sOverI0;  // ������������б����
    sMtUpLimitS    sUpS;     // ���ڹ��ʳ��������б����
    sMtLimitS      sLiS;     // ���ڹ��ʳ������б����
    sMtUbU         sUbU;     // �����ѹ��ƽ�ⳬ���б����
    sMtUbI         sUbI;     // ���������ƽ�ⳬ���б����
    UINT8          ucMLossU; // ����ʧѹʱ����ֵ
}sMtMpLimitCfg;

// ֡�� 
#pragma pack(1) 
typedef struct
{
    sMtFmt07   fMax;        // ��ѹ�ϸ�����   XXX.X  (V)
    sMtFmt07   fMin;        // ��ѹ�ϸ�����   XXX.X  (V)
    sMtFmt07   fDrop;       // ��ѹ��������   XXX.X  (V)

}sMtStandRateU_f;           // ��ѹ�ϸ����б����

typedef struct
{
    sMtFmt07   fMax;        // ��ѹ�����ޣ���ѹ���ޣ�XXX.X  (V)
    UINT8      ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05   fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
    
}sMtOverU_f;                // ��ѹ�б���� 

typedef struct
{
    sMtFmt07   fMin;        // ��ѹ�����ޣ�Ƿѹ���ޣ�XXX.X  (V)
    UINT8      ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05   fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)

}sMtLossU_f;                // Ƿѹ�б����

typedef struct
{
    sMtFmt25  fMax;        // ����������ޣ��������ޣ�(+/-)XXX.XXX (A)
    UINT8     ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
    
}sMtOverI_f;               // �����б���� 

typedef struct
{
    sMtFmt25  fMax;        // ��������ޣ���������ޣ�(+/-)XXX.XXX (A)
    UINT8     ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
    
}sMtExcesI_f;              // ��������б���� 

typedef struct
{
    sMtFmt25  fMax;        // ��������ޣ���������ޣ�(+/-)XXX.XXX (A)
    UINT8     ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtOverI0_f;              // ������������б����
 
typedef struct
{
    sMtFmt23  fMax;        // ��������ޣ���������ޣ�(+/-)XX_XXXX (A)
    UINT8     ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;      // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUpLimitS_f;            // ���ڹ��ʳ��������б����

typedef struct
{
    sMtFmt23  fMax;        // ��������ޣ���������ޣ�(+/-)XX_XXXX (A)
    UINT8     ucMins;      // Խ�޳���ʱ��  (min)
    sMtFmt05  Renew;       // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtLimitS_f;              // ���ڹ��ʳ������б����

typedef struct
{
    sMtFmt05  fLimit;       // �����ѹ��ƽ����ֵ XXX.X (%)
    UINT8     ucMins;       // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;       // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUbU_f;                  // �����ѹ��ƽ�ⳬ���б����

typedef struct
{
    sMtFmt05  fLimit;        // ���������ƽ����ֵ XXX.X (%)
    UINT8     ucMins;        // Խ�޳���ʱ��  (min)
    sMtFmt05  fRenew;        // Խ�޻ָ�ϵ��  XXX.X (%)
}sMtUbI_f;                   // ���������ƽ�ⳬ���б����

typedef struct
{
    sMtStandRateU_f  sU;       // ��ѹ�ϸ����б����   
    sMtOverU_f       sOverU;   // ��ѹ�б���� 
    sMtLossU_f       sLossU;   // Ƿѹ�б����
    sMtOverI_f       sOverI;   // �����б����
    sMtExcesI_f      sExcesI;  // ��������б����
    sMtOverI0_f      sOverI0;  // ������������б����
    sMtUpLimitS_f    sUpS;     // ���ڹ��ʳ��������б����
    sMtLimitS_f      sLiS;     // ���ڹ��ʳ������б����
    sMtUbU_f         sUbU;     // �����ѹ��ƽ�ⳬ���б����
    sMtUbI_f         sUbI;     // ���������ƽ�ⳬ���б����
    UINT8            ucMLossU; // ����ʧѹʱ����ֵ (����)

}sMtMpLimitCfg_f,sMtAfn04f26_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f26(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F27��������ͭ��������� 
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F27_MP_LOSS_CFG
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F27_MP_LOSS_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    float    fRa;                // A�����RA   (��)
    float    fXa;                // A��翹XA   (��)
    float    fGa;                // A��絼GA (S)
    float    fBa;                // A�����BA (S)
    
    float    fRb;                // B�����RB (��)
    float    fXb;                // B��翹XB (��)
    float    fGb;                // B��絼GB (S)
    float    fBb;                // B�����BB (S)

    float    fRc;                 // C�����RC (��)
    float    fXc;                 // C��翹XC (��)
    float    fGc;                 // C��絼GC (S)
    float    fBc;                 // C�����BC (S)

}sMtMpLossCfg, sMtAfn04f27;

// ֡��
#pragma pack(1) 
typedef struct
{
    sMtFmt26    fRa;               // A�����RA (��)
    sMtFmt26    fXa;               // A��翹XA (��)
    sMtFmt26    fGa;               // A��絼GA (S)
    sMtFmt26    fBa;               // A�����BA (S)
    
    sMtFmt26    fRb;               // B�����RB (��)
    sMtFmt26    fXb;               // B��翹XB (��)
    sMtFmt26    fGb;               // B��絼GB (S)
    sMtFmt26    fBb;               // B�����BB (S)

    sMtFmt26    fRc;               // C�����RC (��)
    sMtFmt26    fXc;               // C��翹XC (��)
    sMtFmt26    fGc;               // C��絼GC (S)
    sMtFmt26    fBc;               // C�����BC (S)

}sMtMpLossCfg_f, sMtAfn04f27_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn04f27(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F28�������㹦�������ֶ���ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F28_MP_PERIOD_FACTOR
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F28_MP_PERIOD_FACTOR ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    float  fLimit_1;     // ���������ֶ���ֵ1 (+/-)XXX.X   ��
    float  fLimit_2;     // ���������ֶ���ֵ2 (+/-)XXX.X   ��

}sMtMpPeriodFactor, sMtAfn04f28;

// ֡��
#pragma pack(1) 
typedef struct
{
    sMtFmt05  fLimit_1;     // ���������ֶ���ֵ1 (+/-)XXX.X   ��
    sMtFmt05  fLimit_2;     // ���������ֶ���ֵ2 (+/-)XXX.X   ��

}sMtMpPeriodFactor_f, sMtAfn04f28_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f28(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F29���ն˵��ص��ܱ���ʾ�� 
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F29_TML_METER_ID
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F29_TML_METER_ID ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
   UINT8  ucMeterID[12];       // �ն˵��ص��ܱ���ʾ��

}sMtTmlMeterID, sMtAfn04f29,sMtTmlMeterID_f, sMtAfn04f29_f;
// ֡��


// ת������
eMtErr emtTrans_afn04f29(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F30��̨�����г���ͣ��/Ͷ������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F30_TML_AUTO_READ
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F30_TML_AUTO_READ ��Ӧ�����нṹ��ͬ
{*///

typedef enum
{
    MT_AUTO_READ_UNKOWN,       // δ֪
    MT_AUTO_READ_GO,           // Ͷ��
    MT_AUTO_READ_STOP,         // ͣ�� 
}eMtAutoRead;

// �û���
typedef struct
{
   eMtAutoRead  bRead;       // ̨�����г���ͣ��/Ͷ������

}sMtTmlAutoRead, sMtAfn04f30;

// ֡��
#pragma pack(1) 
typedef struct
{
   UINT8 bRead;             // ̨�����г���ͣ��/Ͷ������

}sMtTmlAutoRead_f, sMtAfn04f30_f;
#pragma pack()



// ת������
eMtErr emtTrans_afn04f30(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F31���ز��ӽڵ㸽���ڵ��ַ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F31_SLAVE_ADDR
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F31_SLAVE_ADDR ��Ӧ�����нṹ��ͬ
{*///

typedef struct
{
    UINT8 ucAddr[12];
    
}sMtSlaveAddr;

// �û���
typedef struct
{
    UINT8         ucN;               // �������õ��ز��ӽڵ㸽���ڵ��ַ���� n��n��20��
    sMtSlaveAddr  sAddr[1];          // 0 ~ N����ַ��Ϣ
    
}sMtSlaveAddrCfg, sMtAfn04f31;
// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8        ucN;                // �������õ��ز��ӽڵ㸽���ڵ��ַ���� n��n��20��
    sMtFmt12     sAddr[1];           // 0 ~ N����ַ��Ϣ

}sMtSlaveAddrCfg_f, sMtAfn04f31_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn04f31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F33���ն˳������в������� 
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F33_TML_READ_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F33_TML_READ_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    sMtHHmm sBegin;        // ������ʱ�ο�ʼʱ��
    sMtHHmm sEnd;          // ������ʱ�ο�ʼʱ��

}sMtBeginEnd;

typedef struct
{
    UINT8          ucPort;                    // �ն�ͨ�Ŷ˿ںţ����ݷ�Χ1��31
    UINT16         usWord;                    // ̨�����г������п�����
    UINT32         ulReadDate;                // �����հ�������
    sMtHHmm        sHHmm;                     // ������-ʱ��
    UINT8          ucPeriod;                  // �ն˳�����Ϊ�ն�ʵʱ�����ʱ������ȡֵ��ΧΪ1��60���ӡ�
    sMtDDHHmm      sDDHHmm;                   // �Ե��㲥Уʱ��ʱʱ��
    UINT8          ucM;                       // ������ʱ����m��0��m��24��
    sMtBeginEnd    sTime[1];                  // 0 ~ m��
}sMtTmlReadCfgOne;

typedef struct
{
    UINT8              ucN;                // �������õĲ��������n����ֵ��Χ1��31
    sMtTmlReadCfgOne   sOne[1];            // 0 ~ N

}sMtTmlReadCfg, sMtAfn04f33;

// ֡��
#pragma pack(1) 
typedef struct
{
    sMtFmt19_f sBegin;        // ������ʱ�ο�ʼʱ��
    sMtFmt19_f sEnd;          // ������ʱ�ο�ʼʱ��

}sMtBeginEnd_f;

typedef struct
{
    UINT8          ucPort;                    // �ն�ͨ�Ŷ˿ںţ����ݷ�Χ1��31
    UINT16         usWord;                    // ̨�����г������п�����
    UINT32         ulReadDate;                // �����հ�������
    sMtFmt19_f     sHHmm;                     // ������-ʱ��
    UINT8          ucPeriod;                  // �ն˳�����Ϊ�ն�ʵʱ�����ʱ������ȡֵ��ΧΪ1��60���ӡ�
    sMtFmt18_f     sDDHHmm;                   // �Ե��㲥Уʱ��ʱʱ��
    UINT8          ucM;                       // ������ʱ����m��0��m��24��
    sMtBeginEnd_f  sTime[1];                  // 0 ~ m��
}sMtTmlReadCfgOne_f;

typedef struct
{
    UINT8                ucN;                // �������õĲ��������n����ֵ��Χ1��31
    sMtTmlReadCfgOne_f   sOne[1];            // 0 ~ N

}sMtTmlReadCfg_f, sMtAfn04f33_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f33(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F34������������ͨ��ģ��Ĳ�������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F34_CON_DOWN_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F34_CON_DOWN_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT8  ucPort;       // �ն�ͨ�Ŷ˿ں�
    UINT8  ucWord;       // ���ն˽ӿڶ˵�ͨ�ſ�����
    UINT8  ucBaud;       // ���ն˽ӿڶ˵�ͨ�ſ�����
}sMtConDownCfgOne;

typedef struct
{
    UINT8                ucN;           // �������õĲ��������n
    sMtConDownCfgOne     sOne[1];       // 1~N����Ϣ

}sMtConDownCfg, sMtAfn04f34;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucPort;       // �ն�ͨ�Ŷ˿ں�
    UINT8  ucWord;       // ���ն˽ӿڶ˵�ͨ�ſ�����
    UINT8  ucBaud;       // ���ն˽ӿڶ˵�ͨ�ſ�����
}sMtConDownCfgOne_f;

typedef struct
{
    UINT8                ucN;           // �������õĲ��������n
    sMtConDownCfgOne_f   sOne[1];       // 1~N����Ϣ

}sMtConDownCfg_f, sMtAfn04f34_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn04f34(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F35��̨�����г����ص㻧����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F35_TML_READ_VIP
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F35_TML_READ_VIP ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{
    UINT16 usMeterID;
   
}sMtTmlReadVipOne;

typedef struct
{
    UINT8                ucN;           // �������õĲ��������n
    sMtTmlReadVipOne     sOne[1];       // 1~N����Ϣ

}sMtTmlReadVip, sMtAfn04f35;

// ֡��
#pragma pack(1) 
typedef struct
{
   UINT16 usMeterID;
   
}sMtTmlReadVipOne_f;

typedef struct
{
    UINT8                  ucN;           // �������õĲ��������n
    sMtTmlReadVipOne_f     sOne[1];       // 1~N����Ϣ

}sMtTmlReadVip_f, sMtAfn04f35_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f35(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F36���ն�����ͨ��������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F36_TML_UP_LIMIT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F36_TML_UP_LIMIT ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{    
    UINT32 ulLimit;         // ��ͨ����������Ϊ0����ʾϵͳ����Ҫ�ն˽����������ơ�

}sMtTmlUpLimit, sMtAfn04f36;

// ֡��
typedef struct
{
     UINT32 ulLimit;       // ��ͨ����������Ϊ0����ʾϵͳ����Ҫ�ն˽����������ơ�
}sMtTmlUpLimit_f, sMtAfn04f36_f;

// ת������
eMtErr emtTrans_afn04f36(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F37���ն˼���ͨ�Ų���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F37_TML_CASC_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F37_TML_CASC_CFG ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{    
    UINT8 ucN;               // ����/��������־�������Ӧ�ı�����/�������ն˸���n

}sMtTmlCascCfg, sMtAfn04f37;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucBCD[2];
    UINT16 usAddr;

}sMtCascOne_f;

typedef struct
{
    UINT8 ucPort;            // �ն˼���ͨ�Ŷ˿ں�
    UINT8 ucWord;            // �ն˼���ͨ�ſ�����
    UINT8 ucGramTimeOut;     // ���յȴ����ĳ�ʱʱ��
    UINT8 ucByteTimeOut;     // ���յȴ��ֽڳ�ʱʱ��
    UINT8 ucReTryTimes;      // ������������վ������ʧ���ط�����
    UINT8 ucTime;            // ����Ѳ������
    UINT8 ucN;               // ����/��������־�������Ӧ�ı�����/�������ն˸���n
    sMtCascOne_f sOne[1];    // 

}sMtTmlCascCfg_f, sMtAfn04f37_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f37(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F38��1�������������� �����ն�֧�ֵ�1�����������ڣ�
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F38_CFG_ASK_1
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F38_CFG_ASK_1 ��Ӧ�����нṹ��ͬ
{*///

#define MT_ASK_M_MIN   (1)   // �������õ�����m ��Сֵ
#define MT_ASK_M_MAX   (16)  // �������õ�����m ���ֵ

// �û���
typedef struct
{    
    UINT8   ucSmall;                    //  �û�С��� (0 ~ 15)           
    UINT8   ucFN;                       //  ֧�ֵ��������  0 ~ 248
    eMtCmd  eCmd[MT_FN_MAX];            //  ֧�ֵ�һ������������ CMD_AFN_C_F2_TML_CLOCK �� CMD_AFN_C_F170_READ_METER
}sMtAsk1CfgOne;

typedef struct
{    
    UINT8          ucBig;                //  �û������  (0 ~ 15)          
    UINT8          ucM;                  // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    sMtAsk1CfgOne  sOne[MT_ASK_M_MAX];   // M����Ϣ
    
}sMtAsk1Cfg, sMtAfn04f38;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8 ucSmall;            // �û�С���            
    UINT8 ucN;                // ��Ϣ������n����ֵ��Χ0��31��Ϊ0��ʾ����֧�֡�        
    UINT8 ucF8n[1];           // ��1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ
    
}sMtAsk1CfgOne_f;

typedef struct
{ 
    UINT8            ucBig;    // ������������Ӧ���û������
    UINT8            ucM;      // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    //sMtAsk1CfgOne_f  sOne[1];  // 
    UINT8            sOne[1];  // ����ṹ��  sMtAsk1CfgOne_f

}sMtAsk1Cfg_f, sMtAfn04f38_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn04f38(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F39��2�������������ã����ն�֧�ֵ�2�����������ڣ�
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F39_CFG_ASK_2
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F39_CFG_ASK_2 ��Ӧ�����нṹ��ͬ
{*///

// �û���
typedef struct
{    
    UINT8 ucSmall;              //  �û�С���            
    UINT8   ucFN;               //  ֧�ֵ��������  0 ~ 248
    eMtCmd  eCmd[MT_FN_MAX];    //  ֧�ֵ�һ������������ CMD_AFN_D_F1_FRTH_POWR_P1P4_D �� CMD_AFN_D_F218_COLOR_YAWP_CURVE

}sMtAsk2CfgOne;

typedef struct
{    
    UINT8          ucBig;           //  �û�С���            
    UINT8          ucM;             // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    sMtAsk2CfgOne  sOne[1];         // M����Ϣ
    
}sMtAsk2Cfg, sMtAfn04f39;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8 ucSmall;            // �û�С���            
    UINT8 ucN;                // ��Ϣ������n����ֵ��Χ0��31��Ϊ0��ʾ����֧�֡�        
    UINT8 ucF8n[1];           // ��1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ
}sMtAsk2CfgOne_f;

typedef struct
{ 
    UINT8            ucBig;    // ������������Ӧ���û������
    UINT8            ucM;      // �������õ�����m��m�ܸ��û��������֧�ֵ��û�С��Ÿ�����
    //sMtAsk1CfgOne_f  sOne[1];  // 
    UINT8            sOne[1];  // ����ṹ��  sMtAsk1CfgOne_f

}sMtAsk2Cfg_f, sMtAfn04f39_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f39(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F41��ʱ�ι��ض�ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F41_PERIOD_VALUE
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F41_PERIOD_VALUE ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f41(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F42�����ݹ��ز���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F42_FACTORY_HOLIDAY
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F42_FACTORY_HOLIDAY ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f42(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F43�����ʿ��ƵĹ��ʼ��㻬��ʱ��
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F43_SLIDE_TIME
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F43_SLIDE_TIME ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f43(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F44��Ӫҵ��ͣ�ز���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F44_SHUTOUT_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F44_SHUTOUT_CFG ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f44(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F45�������ִ��趨
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F45_CTRL_TURN_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F45_CTRL_TURN_CFG ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f45(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F46���µ����ض�ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F46_MONTH_FIX_VALUE
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F46_MONTH_FIX_VALUE ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f46(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F47�����������ѣ��ز���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F47_BUY_COUNT
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F47_BUY_COUNT ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f47(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F48������ִ��趨
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F48_ELEC_TURN_CFG
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F48_ELEC_TURN_CFG ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f48(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F49�����ظ澯ʱ��
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F49_WARNING_TIME
 * PN ���� : P0
 * �ṹ˵��: �� CMD_AFN_A_F49_WARNING_TIME ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F57���ն������澯����M��ֹ����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F57_TML_WARN_SOUND
 * PN ���� : �ܼ����
 * �ṹ˵��: �� CMD_AFN_A_F57_TML_WARN_SOUND ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f57(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F58���ն��Զ��������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F58_TML_ATUO_PROTECT
 * PN ���� : �ܼ����
 * �ṹ˵��: �� CMD_AFN_A_F58_TML_ATUO_PROTECT ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f58(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F59�����ܱ��쳣�б���ֵ�趨
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F59_METER_LIMIT
 * PN ���� : �ܼ����
 * �ṹ˵��: �� CMD_AFN_A_F59_METER_LIMIT ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f59(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F60��г����ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F60_HUMOR_LIMIT
 * PN ���� : �ܼ����
 * �ṹ˵��: �� CMD_AFN_A_F60_HUMOR_LIMIT ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f60(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F61��ֱ��ģ�����������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F61_DC_SIMULA
 * PN ���� : �ܼ����
 * �ṹ˵��: �� CMD_AFN_A_F61_DC_SIMULA ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f61(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F65����ʱ�ϱ�1��������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F65_CFG_AUTO_1
 * PN ���� : �����(1 ~ 61)
 * �ṹ˵��: �� CMD_AFN_A_F65_CFG_AUTO_1 ��Ӧ�����нṹ��ͬ
{*///

#define MT_R_MIN     (1)     // �������ݳ�ȡ����R ��Сֵ
#define MT_R_MAX     (96)    // �������ݳ�ȡ����R ���ֵ

#define MT_PRD_MIN   (1)     // ��ʱ�ϱ�������Сֵ
#define MT_PRD_MAX   (63)    // ��ʱ�ϱ��������ֵ

// �û���
typedef enum
{
    MT_RPT_UNKOWN,         // δ֪
    MT_RPT_mm,             // ��
    MT_RPT_HH,             // ʱ
    MT_RPT_DD,             // ��
    MT_RPT_MM              // ��
    
}eMtRptUnit;               // ��ʱ�ϱ����ڵ�λ

typedef struct
{
    eMtRptUnit    eUnit;    // ��ʱ�ϱ����ڵ�λ(�֡�ʱ���ա���)
    UINT8         ucPeriod; // ��ʱ�ϱ�����   ��Χ(MT_PRD_MIN ~ MT_PRD_MAX)
    sMtYWMDhms    sTime;    // �ϱ���׼ʱ�䣺���ʱ������
    UINT8         ucR;      // �������ݳ�ȡ����R (1��96)
    UINT8         ucN;      // ���ݵ�Ԫ��ʶ����n
    sMtCmdPn      sCmdPn[MT_FN_MAX];   // N�����ݵ�Ԫ��ʶ  

}sMtCfgAuto_1, sMtAfn04f65;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8         ucPeriod:6;  // ��ʱ�ϱ����ڵ�λ(�֡�ʱ���ա���)
    UINT8         ucUnit:2;    // ��ʱ�ϱ�����
    sMtFmt01_f    sTime;       // �ϱ���׼ʱ�䣺���ʱ������
    UINT8         ucR;         // �������ݳ�ȡ����R (1��96)
    UINT8         ucN;         // ���ݵ�Ԫ��ʶ����n
    sMtDaDt       sDaDt[1];   // N�����ݵ�Ԫ��ʶ  
    
}sMtCfgAuto_1_f, sMtAfn04f65_f;
#pragma pack() 

// ת������

eMtErr emtTrans_afn04f65(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F66����ʱ�ϱ�2��������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F66_CFG_AUTO_2
 * PN ���� : �����
 * �ṹ˵��: �� CMD_AFN_A_F66_CFG_AUTO_2 ��Ӧ�����нṹ��ͬ
{*///
// �û���
typedef struct
{
    eMtRptUnit    eUnit;    // ��ʱ�ϱ����ڵ�λ(�֡�ʱ���ա���)
    UINT8         ucPeriod; // ��ʱ�ϱ�����
    sMtYWMDhms    sTime;    // �ϱ���׼ʱ�䣺���ʱ������
    UINT8         ucR;      // �������ݳ�ȡ����R (1��96)
    UINT8         ucN;      // ���ݵ�Ԫ��ʶ����n
    sMtCmdPn      sCmdPn[MT_FN_MAX];   // N�����ݵ�Ԫ��ʶ  

}sMtCfgAuto_2, sMtAfn04f66;

// ֡��
#pragma pack(1) 

typedef struct
{
    UINT8        ucPeriod:6;  // ��ʱ�ϱ����ڵ�λ(�֡�ʱ���ա���)
    UINT8        ucUnit:2;    // ��ʱ�ϱ�����
    sMtFmt01_f   sTime;       // �ϱ���׼ʱ�䣺���ʱ������
    UINT8        ucR;         // �������ݳ�ȡ����R (1��96)
    UINT8        ucN;         // ���ݵ�Ԫ��ʶ����n
    sMtDaDt      sDaDt[1];    // N�����ݵ�Ԫ��ʶ  
}sMtCfgAuto_2_f, sMtAfn04f66_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f66(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F67����ʱ�ϱ�1��������������/ֹͣ����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F67_GOP_AUTO_1
 * PN ���� : �����
 * �ṹ˵��: �� CMD_AFN_A_F67_GOP_AUTO_1 ��Ӧ�����нṹ��ͬ
{*///
// �û���

typedef enum
{
    MT_AUTO_UNKOWN,  // ��Чֵ
    MT_AUTO_GO,      // ����
    MT_AUTO_STOP,    // ֹͣ
}eMtAutoGo;

typedef struct
{
    eMtAutoGo eGo;       
    
}sMtGopAuto_1, sMtAfn04f67;


// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8 ucGo;
    
}sMtGopAuto_1_f, sMtAfn04f67_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn04f67(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F68����ʱ�ϱ�2��������������/ֹͣ����
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_4_F68_GOP_AUTO_2
 * PN ���� : �����
 * �ṹ˵��: �� CMD_AFN_A_F68_GOP_AUTO_2 ��Ӧ�����нṹ��ͬ
{*///
// �û���
typedef struct
{
    eMtAutoGo eGo;       
    
}sMtGopAuto_2, sMtAfn04f68;


// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8 ucGo;
    
}sMtGopAuto_2_f, sMtAfn04f68_f;
#pragma pack() 
// ת������
eMtErr emtTrans_afn04f68(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F73������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F73_CAPA_CFG
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F73_CAPA_CFG ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f73(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F74��������Ͷ�����в���
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F74_CAPA_RUN_CFG
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F74_CAPA_RUN_CFG ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f74(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F75����������������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F75_CAPA_PROT_PARA
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F75_CAPA_PROT_PARA ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f75(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F76��������Ͷ�п��Ʒ�ʽ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F76_CAPA_CTRL_WAY
 * PN ���� : �������
 * �ṹ˵��: �� CMD_AFN_A_F76_CAPA_CTRL_WAY ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f76(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F81��ֱ��ģ����������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F81_CD_CHANGE_RATE
 * PN ���� : ֱ��ģ�����˿ں�
 * �ṹ˵��: �� CMD_AFN_A_F81_CD_CHANGE_RATE ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f81(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F82��ֱ��ģ������ֵ
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F82_CD_LIMIT
 * PN ���� : ֱ��ģ�����˿ں�
 * �ṹ˵��: �� CMD_AFN_A_F82_CD_LIMIT ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f82(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F83��ֱ��ģ�����������
 * ��ӦAFN : AFN_04_SETP
 * ��ӦCMD : CMD_AFN_A_F83_CD_FREEZE_PARA
 * PN ���� : ֱ��ģ�����˿ں�
 * �ṹ˵��: �� CMD_AFN_A_F83_CD_FREEZE_PARA ��Ӧ�����нṹ��ͬ
{*///

// ת������
eMtErr emtTrans_afn04f83(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F1��ң����բ
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F1_REMOTE_TURN_OFF
 * PN ���� : �����ִ�
{*///

// �û���
typedef struct
{
    UINT8 ucResTime;   // �޵�ʱ��      0��15 (��λ: ��Сʱ)  Ϊ0ʱ����ʾ�����޵磬����ʱ���޵磬���Զ�����޵�״̬����Ϊ0ʱ�������õ��޵�ʱ������޵硣
    UINT8 ucWarnTime;  // �澯��ʱʱ��  0��15����λ��min      Ϊ0ʱ����ʾ������բ����Ϊ0ʱ�������õĸ澯ʱ����и澯��

}sMtRemoteTurnOff,sMtRemoteTurnOff_f;

// ֡��

// ת������
eMtErr emtTrans_afn05f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F9��ʱ�ι���Ͷ��
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F9_PERIOD_GO
 * PN ���� : �����ִ�
{*///

// �û���
typedef struct
{
    BOOL  bPeriod[8];  // ��ʾ��1����8ʱ�Σ���"1"����Ч����"0"����Ч
    UINT8 ucWayID;     // ��ֵ��Χ��0��2���α�ʾ��1����3�׷���������ֵ��Ч��
}sMtPeriodGo, sMtAfn05F9; 

// ֡��
typedef struct
{
    UINT8 ucPeriod;    // ��ʾ��1����8ʱ�Σ���"1"����Ч����"0"����Ч
    UINT8 ucWayID;     // ��ֵ��Χ��0��2���α�ʾ��1����3�׷���������ֵ��Ч��
}sMtPeriodGo_f, sMtAfn05F9_f; 

// ת������
eMtErr emtTrans_afn05f9(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F12����ǰ�����¸���Ͷ��
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F12_DOWN_GO
 * PN ���� : �����ִ�
{*///

// �û���
typedef struct
{
    
}sMtDownGo, sMtAfn05F12; 

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8      ucSlideTime;       // ��ǰ�����¸��ض�ֵ����ʱ��
    sMtFmt04_f sFactor;           // ��ǰ�����¸��ض�ֵ����ϵ��
    UINT8      ucDelayTime;       // �غ��ܼ��й����ʶ�����ʱʱ��
    UINT8      ucCtrlTime;        // ��ǰ�����¸��صĿ���ʱ��
    UINT8      ucWarnTime1;       // ��ǰ�����¸��ص�1�ָ澯ʱ��
    UINT8      ucWarnTime2;       // ��ǰ�����¸��ص�2�ָ澯ʱ��
    UINT8      ucWarnTime3;       // ��ǰ�����¸��ص�3�ָ澯ʱ��
    UINT8      ucWarnTime4;       // ��ǰ�����¸��ص�4�ָ澯ʱ��

}sMtDownGo_f, sMtAfn05F12_f; 
#pragma pack()

// ת������
eMtErr emtTrans_afn05f12(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F25���ն˱���Ͷ��
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F25_TML_PROTECT_GO
 * PN ���� : �����ִ�
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F31����ʱ����
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F31_CHECK_TIME
 * PN ���� : p0 
{*///

// �û���
//sMtYYWWMMDDhhmmss  sTime; 

// ֡��
//sMtYYWWMMDDhhmmss_f sTime;

// ת������
eMtErr emtTrans_afn05f31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F32��������Ϣ
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F32_CHINESE_INFO
 * PN ���� : p0 
{*///

#define  MT_CHINESE_INFO_MAX   (200) // ������Ϣ��󳤶�

// �û���
typedef enum
{
    MT_CHIN_INFO_NORMAL, // ��ͨ��Ϣ
    MT_CHIN_INFO_IMPORT, // ��Ҫ��Ϣ
}eMtChInInfo;

typedef struct
{
    eMtChInInfo eType;     // ��ʾ��Ϣ���ݵķ��࣬Ϊ"0"��ʾ��ͨ��Ϣ��Ϊ"1"��ʾ��Ҫ��Ϣ��������ֵ���á�
    UINT8       ucSerID;   // ĳ��������Ϣ�ı�����Ϣ�ı�ţ���ֵȡ�����ն����ܴ洢����Ϣ��������
    UINT8       ucLen;     // ����Lcn����200��
    UINT8       ucInfo[MT_CHINESE_INFO_MAX]; // Lcn���ĺ�����Ϣ
}sMtChineseInfo, sMtAfn05F32;


// ֡��
typedef struct
{
    UINT8  ucTypeID;       // ��ʾ��Ϣ���ݵķ��࣬Ϊ"0"��ʾ��ͨ��Ϣ��Ϊ"1"��ʾ��Ҫ��Ϣ��������ֵ���á�
    UINT8  ucLen;          // ĳ��������Ϣ�ı�����Ϣ�ı�ţ���ֵȡ�����ն����ܴ洢����Ϣ��������
    UINT8  ucInfo[1];      // Lcn���ĺ�����Ϣ
    
}sMtChineseInfo_f, sMtAfn05F32_f;

// ת������
eMtErr emtTrans_afn05f32(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F41������������Ͷ��
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F41_CAPA_CTRL_GO
 * PN ���� : �������
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f41(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F42�������������г�
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F42_CAPA_CTRL_STOP
 * PN ���� : �������
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f42(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F49������ָ��ͨ�Ŷ˿���ͣ����
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F49_READ_METER_STOP
 * PN ���� : P0
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F50������ָ��ͨ�Ŷ˿ڻָ�����
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F50_READ_METER_GO
 * PN ���� : P0
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f50(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F51������ָ��ͨ�Ŷ˿����³���
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F51_READ_METER_REDO
 * PN ���� : P0
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f51(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F52����ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F52_INIT_ROUTE
 * PN ���� : P0
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f52(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F53��ɾ��ָ��ͨ�Ŷ˿��µ�ȫ�����
 * ��ӦAFN : AFN_05_CTRL
 * ��ӦCMD : CMD_AFN_5_F53_DELET_ALL_METER
 * PN ���� : �������
{*///

// �û���

// ֡��


// ת������
eMtErr emtTrans_afn05f53(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F1�������֤����
 * ��ӦAFN : AFN_06_AUTH
 * ��ӦCMD : CMD_AFN_6_F1_ID_AUTH_Q
 * PN ���� : p0
{*///

// �û���
typedef struct
{
    UINT8 ucQuerry[16];
}sMtIdAuthQ,sMtIdAuthQ_f;

// ֡��

// ת������
eMtErr emtTrans_afn06f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F2�������֤��Ӧ
 * ��ӦAFN : AFN_06_AUTH
 * ��ӦCMD : CMD_AFN_6_F2_ID_AUTH_A
 * PN ���� : p0
{*///

// �û���
typedef struct
{
    UINT8 ucAnswer[16];
}sMtIdAuthA,sMtIdAuthA_f;

// ֡��

// ת������
eMtErr emtTrans_afn06f2(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F3��ȡ�����
 * ��ӦAFN : AFN_06_AUTH
 * ��ӦCMD : CMD_AFN_6_F3_RAND_Q
 * PN ���� : p0
{*///

// �û���
typedef struct
{
    UINT8 ucQuerry[16];
}sMtRandQ,sMtRandQ_f;

// ֡��

// ת������
eMtErr emtTrans_afn06f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F4��ȡ�������Ӧ
 * ��ӦAFN : AFN_06_AUTH
 * ��ӦCMD : CMD_AFN_6_F4_RAND_A
 * PN ���� : p0
{*///

// �û���
typedef struct
{
    UINT8 ucAnswer[16];
}sMtRandA,sMtRandA_f;

// ֡��

// ת������
eMtErr emtTrans_afn06f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F1���ն˰汾��Ϣ
 * ��ӦAFN : AFN_09_CFIG
 * ��ӦCMD : CMD_AFN_9_F1_TML_VERSION
 * PN ���� : p0
{*///

// �û���
typedef struct
{
    UINT8      ucFactoryID[4];           // ���̴��� (ASCII)
    UINT8      ucDeviceID[8];            // �豸��� (ASCII)
    UINT8      ucSoftwareID[4];          // �ն�����汾��
    sMtYYMMDD  sDateSoftware;            // �ն�����������ڣ�������
    UINT8      ucInfoCodeCap[11];        // �ն�����������Ϣ��  (ASCII)
    UINT8      ucProtolID[4];            // �ն�ͨ��Э��.�汾�� (ASCII)
    UINT8      ucHardWareID[4];          // �ն�ͨ��Э��.�汾�� (ASCII)
    sMtYYMMDD  sDateHardware;            // �ն�Ӳ���������ڣ�������
    
}sMtTmlVersion, sMtAfn09F1;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8       ucFactoryID[4];           // ���̴��� (ASCII)
    UINT8       ucDeviceID[8];            // �豸��� (ASCII)
    UINT8       ucSoftwareID[4];          // �ն�����汾��
    sMtFmt20_f  sDateSoftware;            // �ն�����������ڣ�������
    UINT8       ucInfoCodeCap[11];        // �ն�����������Ϣ��  (ASCII)
    UINT8       ucProtolID[4];            // �ն�ͨ��Э��.�汾�� (ASCII)
    UINT8       ucHardWareID[4];          // �ն�ͨ��Э��.�汾�� (ASCII)
    sMtFmt20_f  sDateHardware;            // �ն�Ӳ���������ڣ�������
  
}sMtTmlVersion_f, sMtAfn09F1_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn09f1(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F2���ն�֧�ֵ����롢�����ͨ�Ŷ˿�����
 * ��ӦAFN : AFN_09_CFIG
 * ��ӦCMD : CMD_AFN_9_F2_TML_INPUT_OUT
 * PN ���� : p0
{*///

typedef struct
{
    UINT8 ucMac[6];

}sMtMac;

#define MT_CIRCLE_MAX              (64)  // ·�����ֵ
#define MT_CIRCLE_MIN              (0)   // ·����Сֵ

typedef enum
{
    MT_INTER_RS485,                      // ֱ��RS485�ӿ�
    MT_INTER_RS232,                      // ֱ��RS232�ӿ�
    MT_INTER_SERIW,                      // ���нӿ�����խ����ѹ�ز�ͨ��ģ��
    
}eMtInterface;                           // ͨ������
 
typedef enum
{
    MT_PORR_USE_EXP,                     // ר�䡢���䳭��
    MT_PORR_USE_CNG,                     // ���վ����
    MT_PORR_USE_GTH,                     // ̨����ѹ����
    MT_PORR_USE_SHR,                     // �����û������ݹ���

}eMtPortUse;                             // ��;����ֵ��Χ��0��3���α�ʾר�䡢���䳭�����վ����̨����ѹ�����������û������ݹ���


#define MT_PORT_ID_MIN           (1)     //  �˿���Сֵ
#define MT_PORT_ID_MAX           (31)    //  �˿����ֵ

typedef struct
{
    UINT8        ucPort;                 // ͨ�Ŷ˿ڵĶ˿ں� (��ֵ��Χ1��31)
    eMtInterface eInter;                 // ͨ������
    BOOL         bStandard;              // �Ƿ�Ϊ ��׼�첽���п�
    eMtPortUse   eUse;                   // ��;
    UINT32       ulBaud;                 // ͨ�Ŷ˿�֧�ֵ���߲����ʣ�bps��
    UINT16       usDevNum;               // �˿���֧�ֵ��豸���� (0��2040)
    UINT16       usRecvBuf;              // �˿�֧�ֵ������ջ������ֽ��� (256~16383)
    UINT16       usSendBuf;              // �˿�֧�ֵ�����ͻ������ֽ��� (256~16383)
    
}sMtPortOne;

#define MT_READ_METER_MAX           (2040)
#define MT_READ_METER_MIN           (0)

#define MT_SEND_REC_MAX             (16383)
#define MT_SEND_REC_MIN             (256)

// �û���
typedef struct
{
    UINT8  ucPulseInputNum;               // ����������·�� (0~64)
    UINT8  ucSwitchInputNum;              // ����������·�� (0~64)
    UINT8  ucDcNum;                       // ֱ��ģ��������·�� (0~64)
    UINT8  ucSwitchOutputNum;             // ����������·�� (0~64)
    UINT16 usReadMeterNum;                // ֧�ֵĳ����ܱ�/��������װ�������� (0~2040)  MT_READ_METER_MAX
    UINT16 usTmlRecvBuf;                  // ֧�ֵ��ն�����ͨ�������ջ������ֽ��� (256~16383) MT_SEND_REC_MAX
    UINT16 usTmlSendBuf;                  // ֧�ֵ��ն�����ͨ������ͻ������ֽ��� (256~16383) MT_SEND_REC_MAX
    sMtMac sMacAddr;                      // MAC��ַ
    UINT8  ucPortNum;                     // ͨ�Ŷ˿�����n  0��31
    sMtPortOne sPort[1];                  // ucPortNum�˿�����

}sMtTmlInputOut, sMtAfn09F2;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8   ucPort     :5;               // �����ʾ��ͨ�ſڵĶ˿ںţ���ֵ��Χ1��31��
    UINT8   eInter     :2;               // �����ʾ��ͨ�Ŷ˿ڵĽӿڼ�ͨ�����ͣ���ֵ��Χ��0��3
    UINT8   bStandard  :1;               // D7=0��ʾ��ͨ�ſ�Ϊ��׼�첽���пڣ�D7=1��ʾΪ�Ǳ�׼�첽���пڡ�
    UINT8   ucRes      :5;               // ����
    UINT8   eUse       :3;               // 0��3���α�ʾר�䡢���䳭�����վ����̨����ѹ�����������û������ݹ���

}sMtPortWord_f;

typedef struct
{
    sMtPortWord_f sWord;                  // ͨ�Ŷ˿ڵĶ˿ںż���Ϣ��
    UINT32        ulBaud;                 // ͨ�Ŷ˿�֧�ֵ���߲����ʣ�bps��
    UINT16        usDevNum;               // �˿���֧�ֵ��豸���� (0��2040)
    UINT16        usRecvBuf;              // �˿�֧�ֵ������ջ������ֽ��� (256~16383) MT_SEND_REC_MAX
    UINT16        usSendBuf;              // �˿�֧�ֵ�����ͻ������ֽ��� (256~16383) MT_SEND_REC_MAX
    
}sMtPortOne_f;

typedef struct
{
    UINT8        ucPulseInputNum;               // ����������·�� (0~64)
    UINT8        ucSwitchInputNum;              // ����������·�� (0~64)
    UINT8        ucDcNum;                       // ֱ��ģ��������·�� (0~64)
    UINT8        ucSwitchOutputNum;             // ����������·�� (0~64)
    UINT16       usReadMeterNum;                // ֧�ֵĳ����ܱ�/��������װ�������� (0~2040)
    UINT16       usTmlRecvBuf;                  // ֧�ֵĳ����ܱ�/��������װ�������� (256~16383)
    UINT16       usTmlSendBuf;                  // ֧�ֵĳ����ܱ�/��������װ�������� (256~16383)
    sMtMac       sMacAddr;                      // MAC��ַ
    UINT8        ucPortNum;                     // ͨ�Ŷ˿�����n  0��31
    sMtPortOne_f sPort[1];                      // ucPortNum�˿�����

}sMtTmlInputOut_f, sMtAfn09F2_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn09f2(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F3���ն�֧�ֵ���������
 * ��ӦAFN : AFN_09_CFIG
 * ��ӦCMD : CMD_AFN_9_F3_TML_OTHER_CFG
 * PN ���� : p0
{*///

#define MT_TASK_MIN     (0)     // ֧�ֵ����������� ��Сֵ
#define MT_TASK_MAX     (64)    // ֧�ֵ����������� ���ֵ

#define MT_GROUP_MIN    (0)     // ֧�ֵ��ܼ������������Сֵ
#define MT_GROUP_MAX    (8)     // ֧�ֵ��ܼ�������������ֵ

#define MT_DAY_MIN      (0)     // ������Сֵ
#define MT_DAY_MAX      (31)    // �������ֵ

#define MT_MONTH_MIN    (0)     // �·���Сֵ
#define MT_MONTH_MAX    (12)    // �·����ֵ

#define MT_PCTRL_MIN    (0)
#define MT_PCTRL_MAX    (3)

#define MT_HARM_MIN     (0)     // г��������Сֵ
#define MT_HARM_MAX     (19)    // г���������ֵ

#define MT_VIP_MIN      (0)     // ֧�ֵ�̨�����г����ص㻧��໧�� ��Сֵ
#define MT_VIP_MAX      (20)    // ֧�ֵ�̨�����г����ص㻧��໧�� ���ֵ

#define MT_CAPA_MIN     (0)     // ֧�ֵ��޹�������������������� ��Сֵ
#define MT_CAPA_MAX     (16)    // ֧�ֵ��޹�������������������� ���ֵ

// �û���
typedef struct
{
    UINT16         usMp;        // ֧�ֵĲ����������� (0 ~ 2040)
    UINT8          ucGroup;     // ֧�ֵ��ܼ���������� (0 ~ 8)
    UINT8          ucTask;      // ֧�ֵ�����������   (0 ~ 64)
    UINT8          ucTeam;      // ֧�ֵ��й��ܵ��������������� (0��8)
    eMtFmtFrez     eFrezMp;     // ֧�ֵĲ�����������󶳽��ܶ�
    eMtFmtFrez     eFrezP;      // ֧�ֵ��ܼ����й�����������󶳽��ܶ�
    eMtFmtFrez     eFrezQ;      // ֧�ֵ��ܼ����޹�����������󶳽��ܶ�
    eMtFmtFrez     eFrezPt;     // ֧�ֵ��ܼ����й�������������󶳽��ܶ�
    eMtFmtFrez     eFrezQt;     // ֧�ֵ��ܼ����޹�������������󶳽��ܶ�
    UINT8          ucDay;       // ֧�ֵ���������������� (0 ~ 31)
    UINT8          ucMonth;     // ֧�ֵ���������������� (0 ~ 12)
    UINT8          ucPCtrl;     // ֧�ֵ�ʱ�ι��ض�ֵ���������� (0 ~ 3)
    UINT8          ucHarm;      // ֧�ֵ�г��������г������ (0 ~ 19)
    UINT8          ucCapa;      // ֧�ֵ��޹�������������������� (0 ~ 16)
    UINT8          ucVip;       // ֧�ֵ�̨�����г����ص㻧��໧�� (0 ~ 20)
    BOOL           bBig[MT_USER_CLASS_MAX];    // ֧�ֵ��û�����ű�־
                                               // ���ηֱ��Ӧ��0��15���û����࣬��"1"��ʾ֧�֣���"0"��ʾ��֧�֣�
                                               // �Ҷ�Ӧ��"֧���û�С��Ÿ���"ӦΪ0��
    UINT8          ucSmall[MT_USER_CLASS_MAX]; // ֧��0 ~ 15���û������µ��û�С��Ÿ���

}sMtTmlOtherCfg, sMtAfn09F3;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT16         usMp;        // ֧�ֵĲ����������� (0 ~ 2040)
    UINT8          ucGroup;     // ֧�ֵ��ܼ���������� (0 ~ 8)
    UINT8          ucTask;      // ֧�ֵ�����������   (0 ~ 64)
    UINT8          ucTeam;      // ֧�ֵ��й��ܵ��������������� (0��8)
    UINT8          eFrezMp;     // ֧�ֵĲ�����������󶳽��ܶ�
    UINT8          eFrezP;      // ֧�ֵ��ܼ����й�����������󶳽��ܶ�
    UINT8          eFrezQ;      // ֧�ֵ��ܼ����޹�����������󶳽��ܶ�
    UINT8          eFrezPt;     // ֧�ֵ��ܼ����й�������������󶳽��ܶ�
    UINT8          eFrezQt;     // ֧�ֵ��ܼ����޹�������������󶳽��ܶ�
    UINT8          ucDay;       // ֧�ֵ���������������� (0 ~ 31)
    UINT8          ucMonth;     // ֧�ֵ���������������� (0 ~ 12)
    UINT8          ucPCtrl;     // ֧�ֵ�ʱ�ι��ض�ֵ���������� (0 ~ 3)
    UINT8          ucHarm;      // ֧�ֵ�г��������г������ (0 ~ 19)
    UINT8          ucCapa;      // ֧�ֵ��޹�������������������� (0 ~ 16)
    UINT8          ucVip;       // ֧�ֵ�̨�����г����ص㻧��໧�� (0 ~ 20)
    UINT16         bBig;        // ֧�ֵ��û�����ű�־
                                // ���ηֱ��Ӧ��0��15���û����࣬��"1"��ʾ֧�֣���"0"��ʾ��֧�֣�
                                // �Ҷ�Ӧ��"֧���û�С��Ÿ���"ӦΪ0��
    UINT8          ucSmall[MT_USER_CLASS_MAX]; // ֧��0 ~ 15���û������µ��û�С��Ÿ���

}sMtTmlOtherCfg_f, sMtAfn09F3_f;
#pragma pack() 
 
// ת������
eMtErr emtTrans_afn09f3(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F4���ն�֧�ֵĲ�������
* ��ӦAFN : AFN_09_CFIG
* ��ӦCMD : CMD_AFN_9_F4_SUPPORT_PARA_CFG
* PN ���� : P0
* ����˵��: �Կ����õ����� �����ֽ���˵��  ���ò�����AFN=04H��
            CMD_AFN_4_F1_TML_UP_CFG �� CMD_AFN_4_F83_CD_FREEZE_PARA
{*///

// �û���
typedef struct
{
    UINT8   ucNum;       // ֧�ֵ����õĲ����ĸ���
    eMtCmd  eCfgCmd[1];  // ֧�ֵ�����  CMD_AFN_4_F1_TML_UP_CFG �� CMD_AFN_4_F83_CD_FREEZE_PARA

}sMtSuptParaCfg, sMtAfn09F4;

// ֡��
typedef struct
{
    UINT8  ucTeam;        // ֧�ֵ���Ϣ������n
    UINT8  ucFlag[1];     // ֧�ֵĵ�1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ

}sMtSuptParaCfg_f, sMtAfn09F4_f;

// ��������
eMtErr emtTrans_afn09f4_ast(eMtTrans eTrans,eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam);

// ת������
eMtErr emtTrans_afn09f4(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F5���ն�֧�ֵĿ�������
* ��ӦAFN : AFN_09_CFIG
* ��ӦCMD : CMD_AFN_9_F5_SUPPORT_CTRL_CFG
* PN ���� : P0
* ����˵��: �Կ����õ����� �����ֽ���˵��  ���ò�����AFN=04H��
            CMD_AFN_5_F1_REMOTE_TURN_OFF �� CMD_AFN_5_F53_DELET_ALL_METER
{*///

// �û���
typedef struct
{
    UINT8   ucNum;       // ֧�ֵĿ�������ĸ���
    eMtCmd  eCfgCmd[1];  // ֧�ֵĿ��������������  CMD_AFN_5_F1_REMOTE_TURN_OFF �� CMD_AFN_5_F53_DELET_ALL_METER

}sMtSuptCtrlCfg, sMtAfn09F5;

// ֡��
typedef struct
{
    UINT8  ucTeam;        // ֧�ֵ���Ϣ������n
    UINT8  ucFlag[1];     // ֧�ֵĵ�1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ

}sMtSuptCtrlCfg_f, sMtAfn09F5_f;

// ��������
eMtErr emtTrans_afn09f5_ast(eMtTrans eTrans,eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam);

// ת������
eMtErr emtTrans_afn09f5(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F6���ն�֧�ֵ�1����������
* ��ӦAFN : AFN_09_CFIG
* ��ӦCMD : CMD_AFN_9_F6_SUPPORT_ASK1_CFG
* PN ���� : P0
* ����˵��: �Կ����õ����� �����ֽ���˵��  ���ò�����AFN=04H��
            CMD_AFN_C_F2_TML_CLOCK �� CMD_AFN_C_F170_READ_METER
{*///

// �û���
typedef struct
{
    UINT8   ucNum;       // �ն�֧�ֵ�1�����������
    eMtCmd  eCfgCmd[1];  // ucNum ������    CMD_AFN_C_F2_TML_CLOCK �� CMD_AFN_C_F170_READ_METER

}sMtSuptAsk1, sMtAfn09F6;

// ֡��
typedef struct
{
    UINT8  ucBigClass;     // D0��D15���ηֱ��Ӧ��0��15���û����࣬��"1"��ʾ֧�֣���"0"��ʾ��֧�֡�
    UINT8  ucTeam;        // ֧�ֵ���Ϣ������n
    UINT8  ucFlag[1];     // ֧�ֵĵ�1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ

}sMtSuptAsk1_f, sMtAfn09F6_f;

// ��������
eMtErr emtTrans_afn09f6_ast(eMtTrans eTrans,eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam);

// ת������
eMtErr emtTrans_afn09f6(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F7���ն�֧�ֵ�2����������
* ��ӦAFN : AFN_09_CFIG
* ��ӦCMD : CMD_AFN_9_F7_SUPPORT_ASK2_CFG
* PN ���� : P0
* ����˵��: �Կ����õ����� �����ֽ���˵��  ���ò�����AFN=04H��
            CMD_AFN_D_F1_FRTH_POWR_P1P4_D �� CMD_AFN_D_F218_COLOR_YAWP_CURVE
{*///

// �û���
typedef struct
{
    UINT8   ucNum;     // ֧�ֵĿ��������FN����
    eMtCmd  eCfgCmd[1];  // ֧�ֵĿ��������������  CMD_AFN_D_F1_FRTH_POWR_P1P4_D �� CMD_AFN_D_F218_COLOR_YAWP_CURVE

}sMtSuptAsk2, sMtAfn09F7;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8  ucBigClass;    // D0��D15���ηֱ��Ӧ��0��15���û����࣬��"1"��ʾ֧�֣���"0"��ʾ��֧�֡�
    UINT8  ucTeam;        // ֧�ֵ���Ϣ������n
    UINT8  ucFlag[1];     // ֧�ֵĵ�1~n����Ϣ��������Ӧ����Ϣ��Ԫ��־λ

}sMtSuptAsk2_f, sMtAfn09F7_f;
#pragma pack() 

// ��������
eMtErr emtTrans_afn09f7_ast(eMtTrans eTrans,eMtCmd eCmd, UINT8 *pArray, UINT8 *pucTeam);

// ת������
eMtErr emtTrans_afn09f7(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F8���ն�֧�ֵ��¼���¼����
* ��ӦAFN : AFN_09_CFIG
* ��ӦCMD : CMD_AFN_9_F8_SUPPORT_EVNT_CFG
* PN ���� : P0
* ����˵��: MT_ERC_1_INIT �� MT_ERC_35_UNKOWN
            
{*///

// �û���
typedef struct
{
    UINT8   ucNum;       // �ն�֧�ֵ��¼�����
    eMtErc  eErc[1];     // MT_ERC_1_INIT �� MT_ERC_35_UNKOWN

}sMtSuptEvent, sMtAfn09F8;

// ֡��
typedef struct
{
    UINT8  ucFlag[8];     // ֧�ֵ��¼���¼��־λ��
                          // D0��D63��˳���λ��ʾ�¼�����ERC1��ERC64��������¼���λֵΪ"0"��ʾ��֧�֣�Ϊ"1"��ʾ֧�֡�

}sMtSuptEvent_f, sMtAfn09F8_f;


// ת������
eMtErr emtTrans_afn09f8(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}




/*******************************************
* ���ݽṹ: F2: �ն�����ʱ��
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F2_TML_CLOCK
* PN ����: P0
{*///

//�û���
typedef sMtUserClock sMtAfn0cF02;

// ֡��
typedef sMtFrmClock  sMtAfn0cF02_f;

eMtErr emtTrans_afn0cf02(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F3: �ն˲���״̬
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F3_TML_PARA_STATE
* PN ����: P0
{*///

#define MT_TERMINAL_STATUS_USER_MAX (248)
#define MT_TERMINAL_STATUS_FRM_MAX (31)
//�û���
typedef struct 
{
    BOOL bParaStatus[MT_TERMINAL_STATUS_USER_MAX];  // �ն˲���״̬
    
}sMtParaSta,sMtAfn0cF03;

// ֡��
typedef struct
{
    UINT8  bParaStatus[MT_TERMINAL_STATUS_FRM_MAX];
    
}sMtAfn0cF03_f;

eMtErr emtTrans_afn0cf03(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F4: �ն�����ͨ��״̬
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F4_TML_UPCOM_STATE
* PN ����: P0
{*///

#define MT_AFN0CF04_ENABLE  1
#define MT_AFN0CF04_DISABLE 0

//�û���
typedef struct 
{
    BOOL    bCom;            // ����/ ��ֹͨ��
    BOOL    bUp;             // ����/ ��ֹ�ϱ�
    
}sMtTmlUpComState, sMtAfn0cF04;

// ֡��
typedef struct
{
    UINT8   ucUpStat:2;     // �ն������ϱ�״̬
    UINT8   ucComStat:2;    // �ն�ͨ��״̬
    UINT8   ucReserve:4;    // ��������
}sMtTmlUpComState_f, sMtAfn0cF04_f;

eMtErr emtTrans_afn0cf04(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
* ���ݽṹ: F5: �ն�ͨ��״̬
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F5_TML_CTRL_SET
* PN ����: P0
{*///

// ֡��
#pragma pack(1) 
typedef struct 
{
    UINT8 ucPowerNum;          // ���ض�ֵ������
    UINT8 ucPowerFlag;         // ����ʱ����Ч��־λ
    UINT8 ucPowerSta;          // ����״̬
    UINT8 ucElecSta;           // ���״̬
    UINT8 ucPowerTimeSta;      // �����ִ�״̬
    UINT8 ucElecTimeSta;       // ����ִ�״̬
    
}sMtComGroupSta_f;

typedef struct 
{
    UINT8             ucWarnSta;         // ���硢�޳��ʹ߷Ѹ澯Ͷ��״̬
    UINT8             ucGroupFlag;       // �ܼ�����Ч��־λ
    sMtComGroupSta_f  sGroup[1];  // �ܼ��� 
    
}sMtAfn0cF05_f;
#pragma pack()

// �û���
#define MT_AFN0CF05_MAXGROUPS   8

#define MT_AFN0CF05_REMAIN_ENABLE   (UINT8)(0X01)   // ����״̬ʹ��
#define MT_AFN0CF05_DELETE_ENABLE   (UINT8)(0X02)   // �޳�״̬ʹ��
#define MT_AFN0CF05_PAYWAR_ENABLE   (UINT8)(0X04)   // �߷Ѹ澯״̬ʹ��

typedef enum
{
    MT_AFN0CF05_SCHM_0,     
    MT_AFN0CF05_SCHM_1,
    MT_AFN0CF05_SCHM_2,
    MT_AFN0CF05_SCHM_3,
    
}eMtAfn0cf05_Schm;      //  ���ض�ֵ������

#define MT_AFN0CF05_TIME_CTRL_ENABLE   (UINT8)(0X01)   // ʱ�ο�ʹ��
#define MT_AFN0CF05_REST_CTRL_ENABLE   (UINT8)(0X02)   // ���ݿ�ʹ��
#define MT_AFN0CF05_STOP_CTRL_ENABLE   (UINT8)(0X04)   // Ӫҵ��ͣʹ��
#define MT_AFN0CF05_DOWN_CTRL_ENABLE   (UINT8)(0X08)   // ��ǰ�����¸���ʹ��

#define MT_AFN0CF05_MONTH_CTRL_ENABLE   (UINT8)(0X01)   // �¿�ʹ��
#define MT_AFN0CF05_BUY_CTRL_ENABLE     (UINT8)(0X02)   // �����ʹ��

typedef struct 
{
    UINT8   ucScheme;   // ���ض�ֵ������
    BOOL    bPowerCtrl[8];  // ��˳���λ��ʾ1 ~ 8ʱ�ο�Ͷ�������Чʱ��
    BOOL    bTimeCtrl;  // ʱ�ο�Ͷ��״̬
    BOOL    bRestCtrl;  // ���ݿ�Ͷ��״̬
    BOOL    bStopCtrl;  // Ӫҵ��ͣ��Ͷ��״̬
    BOOL    bDownCtrl;  // ��ǰ�����¸���Ͷ��״̬
    BOOL    bMonthCtrl; // �µ��Ͷ��״̬
    BOOL    bBuyCtrl;   // �����Ͷ��״̬
    BOOL    bPowerTimeSta[8];   // ��˳���λ��ʾ1 ~ 8�ִο��ع����ܿ�״̬
    BOOL    bElecTimeSta[8];    // ��˳���λ��ʾ1 ~ 8�ִο��ص���ܿ�״̬
}sMtComGroupSta;

typedef struct
{
    BOOL    bRemain;            // ����Ͷ��״̬
    BOOL    bDelete;            // �޳�Ͷ��״̬
    BOOL    bPayWarn;           // �߷Ѹ澯Ͷ��״̬
    UINT8   ucGroupNum;         // �ܼ������
    BOOL    bGroup[MT_AFN0CF05_MAXGROUPS];        // �ն��ܼ����Ӧ1 ~ 8 �ܼ���
    sMtComGroupSta sGroup[MT_AFN0CF05_MAXGROUPS]; // �ܼ���״̬��Ӧ1 ~ 8 �ܼ���
}sMtAfn0cF05;

eMtErr emtTrans_afn0cf05(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F6: �ն˿���״̬
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F6_TML_CTRL_STATE
* PN ����: P0
{*///

//  ֡��
typedef struct 
{
    sMtFmt02_f sCurPower;       // ��ǰ���ʶ�ֵ
    sMtFmt04_f sPowerDrift;      // ��ǰ�����¸��ظ�����ϵ��
    UINT8      ucPowerOutSta;     // ������բ���״̬
    UINT8      ucMonthElecOutSta; // �µ����բ���״̬
    UINT8      ucBuyElecOutSta;   // �������բ���״̬
    UINT8      ucPowerWarnSta;    // ����Խ�޸澯״̬
    UINT8      ucElecWarnSta;     // ����Խ�޸澯״̬ 
}sMtCtrlGroupSta_f;

typedef struct 
{
    UINT8    ucTripOutSta;      // ң����բ���״̬
    UINT8    ucPayWarnSta;      // ��ǰ�߷Ѹ澯״̬
    UINT8    ucGroupFlag;       // �ܼ�����Ч��־λ
    sMtCtrlGroupSta_f sGroup[1];  // �ܼ��� 
}sMtAfn0cF06_f;

#define MT_AFN0CF06_PAYWARNING_ENABLE   (UINT8)(0X01)   // ���ڴ߷Ѹ澯״̬ 
#define MT_AFN0CF06_PAYWARNING_DISABLE  (UINT8)(0X00)   // �����ڴ߷Ѹ澯״̬ 

// �û���

#define MT_AFN0CF06_TIME_CTRL_STAT   (UINT8)(0X01)   // ʱ�ο�״̬
#define MT_AFN0CF06_REST_CTRL_STAT   (UINT8)(0X02)   // ���ݿ�״̬
#define MT_AFN0CF06_STOP_CTRL_STAT   (UINT8)(0X04)   // Ӫҵ��ͣ״̬
#define MT_AFN0CF06_DOWN_CTRL_STAT   (UINT8)(0X08)   // ��ǰ�����¸���״̬

#define MT_AFN0CF06_MONTH_CTRL_STAT   (UINT8)(0X01)   // �¿�״̬
#define MT_AFN0CF06_BUY_CTRL_STAT     (UINT8)(0X02)   // �����״̬

typedef struct 
{
    float       fCurPower;              // ��ǰ���ʶ�ֵ
    sMtFloat    sPowerDrift;            // ��ǰ�����¸��ظ�����ϵ��
    BOOL        bPowerOutSta[8];        // ��˳���λ��ʾ1 ~ 8 �ִι�����բ���״̬
    BOOL        bMonthElecOutSta[8];    // ��˳���λ��ʾ1 ~ 8 �ִ��µ����բ���״̬
    BOOL        bBuyElecOutSta[8];      // ��˳���λ��ʾ1 ~ 8 �ִι������բ���״̬
    BOOL        bTimeCtrlSta;           // ʱ�ο�״̬
    BOOL        bRestCtrlSta;           // ���ݿ�״̬
    BOOL        bStopCtrlSta;           // Ӫҵ��ͣ״̬
    BOOL        bDownCtrlSta;           // ��ǰ�����¸���״̬
    BOOL        bMonthCtrlSta;          // �µ��״̬
    BOOL        bBuyCtrlSta;            // �����״̬
}sMtCtrlGroupSta;

typedef struct
{
    BOOL    bTrip[8];        // ��˳���λ��ʾ�ն�1 ~ 8 �ִ�ң����բ���״̬
    UINT8   ucPayWarn;       // �ն��Ƿ��ڴ߷Ѿ���״̬ 
    BOOL    bGroup[8];       // �ն��ܼ����Ӧ1 ~ 8 �ܼ���
    sMtCtrlGroupSta sGroup[8];  // �ܼ��鵱ǰ����״̬
}sMtAfn0cF06;

eMtErr emtTrans_afn0cf06(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
* ���ݽṹ: F7: �ն��¼���������ǰֵ
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F7_TML_EC_VALUE
* PN ����: P0
{*///

//  ֡��
typedef struct 
{
    UINT8   ucEc1;  // ��Ҫ�¼�������EC1
    UINT8   ucEc2;  // ��Ҫ�¼�������EC2
}sMtAfn0cF07_f;

// �û���
typedef sMtAfn0cF07_f sMtAfn0cF07;

eMtErr emtTrans_afn0cf07(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F8: �ն��¼���־״̬
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F8_TML_EVNT_FLAG
* PN ����: P0
{*///

//  ֡��
typedef struct 
{
    UINT32  ucErcLow;   //��λ��ʾERC1 ~ ERC32 
    UINT32  ucErcHigh;  // ��λ��ʾERC33 ~ ERC64
}sMtAfn0cF08_f;

// �û���
#define MT_AFN0CF08_ERC_MAX   (64)   // ERC�ն�ʱ�������
typedef struct
{
    BOOL bErc[MT_AFN0CF08_ERC_MAX];  // �����������ڼ��㳤��
}sMtAfn0cF08;

eMtErr emtTrans_afn0cf08(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F9: �ն�״̬������λ��־
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F9_TML_STATE_BIT
* PN ����: P0
{*///

//  ֡��
typedef struct 
{
    UINT8 ucReserve[2]; // �����������ڼ��㳤�� 
    
}sMtAfn0cF09_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF09;

eMtErr emtTrans_afn0cf09(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F10: �ն�����վ���ա���ͨ������
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F10_TML_MONTH_FLOW
* PN ����: P0
{*///

//  ֡��
typedef struct 
{
    UINT8 ucReserve[8]; // �����������ڼ��㳤�� 
    
}sMtAfn0cF10_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF10;

eMtErr emtTrans_afn0cf10(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F11: �ն˼��г���״̬��Ϣ
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F11_TML_READ_METER
* PN ����: P0
{*///

//  ֡��
#pragma pack(1) 
typedef struct 
{
    UINT8 ucTmlComPort;       // �ն�ͨ�Ŷ˿ں�
    UINT16 usMeterNum;        // Ҫ���������
    UINT8 ucWorkState;        // ��ǰ������״̬��־
    UINT16 ucReadOkNum;       // ����ɹ�����
    UINT8 ucKeyMeterOkNum;    // ���ص��ɹ�����
    sMtFrmClock sStartTime;   // ��ʼʱ��
    sMtFrmClock sEndTime;     // ����ʱ��
    
}sMtDataBlock;

typedef struct 
{
    UINT8   ucBlockNum;
    sMtDataBlock sDataBlock[1];
    
}sMtAfn0cF11_f;
#pragma pack()

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF11;

eMtErr emtTrans_afn0cf11(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F17: ��ǰ�ܼ��й�����
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F17_TOTAL_POWER_HAVE
* PN ����: �ܼ����
{*///

//  ֡��
typedef sMtsXXX sMtAfn0cF17_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF17;

eMtErr emtTrans_afn0cf17(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F18: ��ǰ�ܼ��޹�����
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F18_TOTAL_POWER_NONE
* PN ����: �ܼ����
{*///

//  ֡��
typedef sMtsXXX sMtAfn0cF18_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF18;

eMtErr emtTrans_afn0cf18(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F19: �����ܼ��й�������(�ܡ����� 1~M)
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F19_DAY_POWER_HAVE
* PN ����: �ܼ����
{*///

//  ֡��
#pragma pack(1) 
typedef struct
{
    UINT8   ucRateNum;               // ������M
    sMtFmt_sX7_f sTotalPowerHave;    // �����ܼ��й��ܵ���
    sMtFmt_sX7_f sDayPowerHave[1];   // ����n�����ܼ��й�������
    
}sMtAfn0cF19_f;
#pragma pack() 

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF19;

eMtErr emtTrans_afn0cf19(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F20: �����ܼ��޹�������(�ܡ����� 1~M)
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F20_DAY_POWER_NONE
* PN ����: �ܼ����
{*///

//  ֡��
#pragma pack(1) 
typedef struct
{
    UINT8   ucRateNum;               // ������M
    sMtFmt_sX7_f sTotalPowerNone;    // �����ܼ��й��ܵ���
    sMtFmt_sX7_f sDayPowerNone[1];   // ����n�����ܼ��й�������
    
}sMtAfn0cF20_f;
#pragma pack()

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
 
}sMtAfn0cF20;

eMtErr emtTrans_afn0cf20(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F21: �����ܼ��й�������(�ܡ����� 1~M)
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F21_MONTH_POWER_HAVE
* PN ����: �ܼ����
{*///

//  ֡��
typedef  sMtAfn0cF19_f sMtAfn0cF21_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF21;

eMtErr emtTrans_afn0cf21(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F22: �����ܼ��޹�������(�ܡ����� 1~M)
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F22_MONTH_POWER_NONE
* PN ����: �ܼ����
{*///

//  ֡��
typedef sMtAfn0cF20_f sMtAfn0cF22_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF22;

eMtErr emtTrans_afn0cf22(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F23: �ն˵�ǰʣ�����(��)
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F23_TML_LEFT_POWER
* PN ����: �ܼ����
{*///

//  ֡��
typedef sMtFmt_sX7_f sMtAfn0cF23_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF23;

eMtErr emtTrans_afn0cf23(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F24: ��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F24_DOWN_FREZ_VALUE
* PN ����: �ܼ����
{*///

//  ֡��
typedef sMtsXXX sMtAfn0cF24_f;

// �û���
typedef struct
{
    UINT8 ucReserve;  // �����������ڼ��㳤��
    
}sMtAfn0cF24;

eMtErr emtTrans_afn0cf24(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ���
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F25_POWER_RATE_CUR
 * PN ���� : �������
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL            bsReadTime;     // �ն˳���ʱ��    (��ʱ������)
    BOOL            bfP;            // ��ǰ���й�����  (KW) (+/-)XX.XXXX 
    BOOL            bfPa;           // ��ǰA���й����� (KW) (+/-)XX.XXXX 
    BOOL            bfPb;           // ��ǰB���й����� (KW) (+/-)XX.XXXX 
    BOOL            bfPc;           // ��ǰC���й����� (KW) (+/-)XX.XXXX 

    BOOL            bfQ;            // ��ǰ���޹�����  (KW) (+/-)XX.XXXX 
    BOOL            bfQa;           // ��ǰA���޹����� (KW) (+/-)XX.XXXX 
    BOOL            bfQb;           // ��ǰB���޹����� (KW) (+/-)XX.XXXX 
    BOOL            bfQc;           // ��ǰC���޹����� (KW) (+/-)XX.XXXX 

    BOOL            bfPf;           // ��ǰ�ܹ�������  (%)  (+/-)XXX.X
    BOOL            bfPfa;          // ��ǰA�๦������ (%)  (+/-)XXX.X
    BOOL            bfPfb;          // ��ǰB�๦������ (%)  (+/-)XXX.X
    BOOL            bfPfc;          // ��ǰC�๦������ (%)  (+/-)XXX.X

    BOOL            bfUa;           // ��ǰA���ѹ     (V)       XXX.X
    BOOL            bfUb;           // ��ǰB���ѹ     (V)       XXX.X
    BOOL            bfUc;           // ��ǰC���ѹ     (V)       XXX.X

    BOOL            bfIa;           // ��ǰA�����     (A)  (+/-)XXX.XXX     
    BOOL            bfIb;           // ��ǰB�����     (A)  (+/-)XXX.XXX     
    BOOL            bfIc;           // ��ǰC�����     (A)  (+/-)XXX.XXX     
    BOOL            bfI0;           // ��ǰ�������    (A)  (+/-)XXX.XXX   
    
    BOOL            bfS;            // ��ǰ�����ڹ���  (KW) (+/-)XX.XXXX 
    BOOL            bfSa;           // ��ǰA�����ڹ��� (KW) (+/-)XX.XXXX 
    BOOL            bfSb;           // ��ǰB�����ڹ��� (KW) (+/-)XX.XXXX 
    BOOL            bfSc;           // ��ǰC�����ڹ��� (KW) (+/-)XX.XXXX            

    // ʵ������
    sMtYYMMDDhhmm   sReadTime;      // �ն˳���ʱ��    (��ʱ������)
    float           fP;             // ��ǰ���й�����  (KW) (+/-)XX.XXXX 
    float           fPa;            // ��ǰA���й����� (KW) (+/-)XX.XXXX 
    float           fPb;            // ��ǰB���й����� (KW) (+/-)XX.XXXX 
    float           fPc;            // ��ǰC���й����� (KW) (+/-)XX.XXXX 

    float           fQ;             // ��ǰ���޹�����  (KW) (+/-)XX.XXXX 
    float           fQa;            // ��ǰA���޹����� (KW) (+/-)XX.XXXX 
    float           fQb;            // ��ǰB���޹����� (KW) (+/-)XX.XXXX 
    float           fQc;            // ��ǰC���޹����� (KW) (+/-)XX.XXXX 

    float           fPf;            // ��ǰ�ܹ�������  (%)  (+/-)XXX.X
    float           fPfa;           // ��ǰA�๦������ (%)  (+/-)XXX.X
    float           fPfb;           // ��ǰB�๦������ (%)  (+/-)XXX.X
    float           fPfc;           // ��ǰC�๦������ (%)  (+/-)XXX.X

    float           fUa;            // ��ǰA���ѹ     (V)       XXX.X
    float           fUb;            // ��ǰB���ѹ     (V)       XXX.X
    float           fUc;            // ��ǰC���ѹ     (V)       XXX.X

    float           fIa;            // ��ǰA�����     (A)  (+/-)XXX.XXX     
    float           fIb;            // ��ǰB�����     (A)  (+/-)XXX.XXX     
    float           fIc;            // ��ǰC�����     (A)  (+/-)XXX.XXX     
    float           fI0;            // ��ǰ�������    (A)  (+/-)XXX.XXX   
    
    float           fS;             // ��ǰ�����ڹ���  (KW) (+/-)XX.XXXX 
    float           fSa;            // ��ǰA�����ڹ��� (KW) (+/-)XX.XXXX 
    float           fSb;            // ��ǰB�����ڹ��� (KW) (+/-)XX.XXXX 
    float           fSc;            // ��ǰC�����ڹ��� (KW) (+/-)XX.XXXX 
    
}sMtCurPQUI, sMtAfn0cF25;

// ֡��
#pragma pack(1) 
typedef struct
{
    sMtYYMMDDhhmm_f           sReadTime;      // �ն˳���ʱ��    (��ʱ������)
    sMtFmt_sXX_XXXX           fP;             // ��ǰ���й�����  (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fPa;            // ��ǰA���й����� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fPb;            // ��ǰB���й����� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fPc;            // ��ǰC���й����� (KW) (+/-)XX.XXXX 

    sMtFmt_sXX_XXXX           fQ;             // ��ǰ���޹�����  (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fQa;            // ��ǰA���޹����� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fQb;            // ��ǰB���޹����� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fQc;            // ��ǰC���޹����� (KW) (+/-)XX.XXXX 

    sMtFmt_sXXX_X             fPf;            // ��ǰ�ܹ�������  (%)  (+/-)XXX.X
    sMtFmt_sXXX_X             fPfa;           // ��ǰA�๦������ (%)  (+/-)XXX.X
    sMtFmt_sXXX_X             fPfb;           // ��ǰB�๦������ (%)  (+/-)XXX.X
    sMtFmt_sXXX_X             fPfc;           // ��ǰC�๦������ (%)  (+/-)XXX.X

    sMtFmt_XXX_X              fUa;            // ��ǰA���ѹ     (V)       XXX.X
    sMtFmt_XXX_X              fUb;            // ��ǰB���ѹ     (V)       XXX.X
    sMtFmt_XXX_X              fUc;            // ��ǰC���ѹ     (V)       XXX.X

    sMtFmt_sXXX_XXX           fIa;            // ��ǰA�����     (A)  (+/-)XXX.XXX     
    sMtFmt_sXXX_XXX           fIb;            // ��ǰB�����     (A)  (+/-)XXX.XXX     
    sMtFmt_sXXX_XXX           fIc;            // ��ǰC�����     (A)  (+/-)XXX.XXX     
    sMtFmt_sXXX_XXX           fI0;            // ��ǰ�������    (A)  (+/-)XXX.XXX   
    
    sMtFmt_sXX_XXXX           fS;             // ��ǰ�����ڹ���  (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fSa;            // ��ǰA�����ڹ��� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fSb;            // ��ǰB�����ڹ��� (KW) (+/-)XX.XXXX 
    sMtFmt_sXX_XXXX           fSc;            // ��ǰC�����ڹ��� (KW) (+/-)XX.XXXX 
}sMtCurPUIQ_f, sMtAfn0cF25_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn0cf25(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);

///*}

/*******************************************
* ���ݽṹ: F26:   A��B��C�������ͳ�����ݼ����һ�ζ����¼
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F26_DROP_PHASE_LAST
* PN ����: �������
{*///

//  ֡��
#pragma pack(1) 
typedef struct 
{
    sMtYYMMDDhhmm_f sTime;              // �ն˳���ʱ��
    sMtFmt_XXXX   sTotalPhaseBreakNum;  // �ն��ܶ������
    sMtFmt_XXXX   sAPhaseBreakNum;      // A ��������
    sMtFmt_XXXX   sBPhaseBreakNum;      // B ��������
    sMtFmt_XXXX   sCPhaseBreakNum;      // C ��������
    sMtFmt_XXXXXX sTotalBreakTime;      // ����ʱ���ۼ�ֵ
    sMtFmt_XXXXXX sABreakTime;          // A �����ʱ���ۼ�ֵ
    sMtFmt_XXXXXX sBBreakTime;          // B �����ʱ���ۼ�ֵ
    sMtFmt_XXXXXX sCBreakTime;          // B �����ʱ���ۼ�ֵ
    sMtMMDDHHmm_f sStartClkLast;        // ���һ�ζ�����ʼʱ��
    sMtMMDDHHmm_f sAStartClkLast;       // A�����������ʼʱ��
    sMtMMDDHHmm_f sBStartClkLast;       // B�����������ʼʱ��
    sMtMMDDHHmm_f sCStartClkLast;       // C�����������ʼʱ��
    sMtMMDDHHmm_f sEndClkLast;          // ���һ�ζ������ʱ��
    sMtMMDDHHmm_f sAEndClkLast;         // A�����������ʼʱ��
    sMtMMDDHHmm_f sBEndClkLast;         // B�����������ʼʱ��
    sMtMMDDHHmm_f sCEndClkLast;         // C�����������ʼʱ��
    
}sMtAfn0cF26_f;
#pragma pack()

// �û���
typedef struct
{
    UINT8 ucReserve;    // �����������ڼ��㳤��
    
}sMtAfn0cF26;

eMtErr emtTrans_afn0cf26(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F27:   ���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F27_METER_PROG_TIME
* PN ����: �������
{*///

//  ֡��
#pragma pack(1) 
typedef struct 
{
    sMtYYMMDDhhmm_f sTime;            // �ն˳���ʱ��
    sMtFrmClock   sClock;             // �ն�����ʱ��
    sMtFmt_XXXXXXXX sBatteryTime;     // ��ع���ʱ��
    sMtFmt_XXXXXX sProgramTimes;      // ����ܴ���
    sMtFrmClock   sProgramClkLast;    // ���һ�α�̷���ʱ��
    sMtFmt_XXXXXX sMtZeroTimes;       // ��������ܴ���
    sMtFrmClock   sMtZeroClkLast;     // ���һ�����㷢��ʱ��
    sMtFmt_XXXXXX sNeedsZeroTimes;    // ���������ܴ���
    sMtFrmClock   sNeedsZeroClkLast;  // ���һ���������㷢��ʱ��
    sMtFmt_XXXXXX sEventZeroTimes;    // �¼������ܴ���
    sMtFrmClock   sEventZeroClkLast;  // ���һ���¼����㷢��ʱ��
    sMtFmt_XXXXXX sTimingTimes;       // Уʱ�ܴ���
    sMtFrmClock   sTimingClkLast;     // ���һ��Уʱ����ʱ��
    
}sMtAfn0cF27_f;
#pragma pack()

// �û���
typedef struct
{
    UINT8 ucReserve;    // �����������ڼ��㳤��
    
}sMtAfn0cF27;

eMtErr emtTrans_afn0cf27(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F28:   �������״̬�ּ����λ��־
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F28_METER_WORD_CBIT
* PN ����: �������
{*///

//  ֡��
typedef struct 
{
    sMtYYMMDDhhmm_f sTime;               // �ն˳���ʱ��
    UINT16          usMtStateFlag[7];    // �������״̬�ֱ�λ��־
    UINT16          usMtState[7];        // �������״̬��
    
}sMtAfn0cF28_f;

// �û���
typedef struct
{
    UINT8 ucReserve;    // �����������ڼ��㳤��
    
}sMtAfn0cF28;

eMtErr emtTrans_afn0cf28(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F29:   ��ǰͭ�������й��ܵ���ʾֵ
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F29_COPER_IRON_CUR
* PN ����: �������
{*///

//  ֡��
#pragma pack(1) 
typedef struct 
{
  sMtYYMMDDhhmm_f   sTime;          // �ն˳���ʱ��
  union
    {
        sMtFmt_XXXXXX_XXXX sCopperValueCur;     // ��ǰͭ���й��ܵ���ʾֵ
        sMtFmt_XXXXXX_XXXX sCopperValueLast;    // ��һ����ͭ���й�����ʾֵ
        
    }uCopperValue;

  union
  {
    sMtFmt_XXXXXX_XXXX sIronValueCur;          // ��ǰ�����й��ܵ���ʾֵ
    sMtFmt_XXXXXX_XXXX sIronValueLast;         // ��һ���������й�����ʾֵ
    
  }uIronValue;        
  
}sMtAfn0cF29_f;
#pragma pack()

// �û���
typedef struct
{
    UINT8 ucReserve;        // �����������ڼ��㳤��
    
}sMtAfn0cF29;

eMtErr emtTrans_afn0cf29(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
* ���ݽṹ: F30:   ��һ������ͭ�������й��ܵ���ʾֵ
* ��ӦAFN: AFN_0C_ASK1
* ��ӦCMD: CMD_AFN_C_F30_COPER_IRON_LAST
* PN ����: �������
{*///

//  ֡��
typedef sMtAfn0cF29_f sMtAfn0cF30_f;

// �û���
typedef struct
{
    UINT8 ucReserve;        // �����������ڼ��㳤��
    
}sMtAfn0cF30;

eMtErr emtTrans_afn0cf30(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F31����ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F31_POWER_CUR
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{   
    double dFrthHavePower;    // �����й�����ʾֵ  XXXXXX_XXXX (kWh)
    double dBackHavePower;    // �����й�����ʾֵ  XXXXXX_XXXX (kWh)
    double  fComNonePower1;    // ����޹�1����ʾֵ XXXXXX_XX   (Kvarh)
    double  fComNonePower2;    // ����޹�2����ʾֵ XXXXXX_XX   (Kvarh)
    
}sMtPowerPhase;               // ���� ����ʾֵ

typedef struct
{
    sMtYYMMDDhhmm  sTime;    // �ն˳���ʱ��
    sMtPowerPhase  sPhaseA;  // ��ǰA��
    sMtPowerPhase  sPhaseB;  // ��ǰB��
    sMtPowerPhase  sPhaseC;  // ��ǰC��
    
}sMtPower, sMtAfn0cf31;

// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtFmt14_f  dFrthHavePower;    // �����й�����ʾֵ  XXXXXX_XXXX (kWh)
    sMtFmt14_f  dBackHavePower;    // �����й�����ʾֵ  XXXXXX_XXXX (kWh)
    sMtFmt11_f  fComNonePower1;    // ����޹�1����ʾֵ XXXXXX_XX   (Kvarh)
    sMtFmt11_f  fComNonePower2;    // ����޹�2����ʾֵ XXXXXX_XX   (Kvarh)
    
}sMtPowerPhase_f;                  // ���� ����ʾֵ

typedef struct
{
    sMtFmt15_f       sTime;    // �ն˳���ʱ��
    sMtPowerPhase_f  sPhaseA;  // ��ǰA��
    sMtPowerPhase_f  sPhaseB;  // ��ǰB��
    sMtPowerPhase_f  sPhaseC;  // ��ǰC��
    
}sMtPower_f, sMtAfn0cf31_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn0cf31(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F32����һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F32_POWER_LAST
 * PN ���� : �������
 *
{*///

// �û���
typedef sMtAfn0cf31 sMtAfn0cf32;

// ֡��
typedef sMtAfn0cf31_f sMtAfn0cf32_f;

// ת������
eMtErr emtTrans_afn0cf32(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F33����ǰ������/ �޹�����ʾֵ��һ/ �����޹�����ʾֵ ( �ܡ�����1  ~ M, 1 <= M  <= 12)
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F33_FRTH_POWR_P1P4_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef struct 
{
    sMtFmt14_f  sTotalPower;
    sMtFmt14_f  sPower[1];
}sMtHaveValue;        // �й�����ʾֵ

typedef struct 
{
    sMtFmt11_f  sTotalPower;
    sMtFmt11_f  sPower[1];
}sMtNoneValue;       // �޹�����ʾֵ 

typedef sMtHaveValue sMtCurFrthHaveValue;        // ��ǰ�����й�����ʾֵ

typedef sMtNoneValue sMtCurFrthNoneValue;        // ��ǰ�����޹�����ʾֵ

typedef sMtNoneValue sMtCurP1NoneValue;           // ��ǰһ�����޹�����ʾֵ

typedef sMtNoneValue sMtCurP4NoneValue;           // ��ǰ�������޹�����ʾֵ       

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
    
}sMtAfn0cf33_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn0cf33(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F34����ǰ������/ �޹�����ʾֵ����/ �����޹�����ʾֵ ( �ܡ�����1  ~ M, 1 <= M  <= 12)
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F34_BACK_POWR_P2P3_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��

typedef sMtHaveValue sMtCurBackHaveValue;        // ��ǰ�����й�����ʾֵ

typedef sMtNoneValue sMtCurBackNoneValue;        // ��ǰ�����޹�����ʾֵ

typedef sMtNoneValue sMtP3NoneValue;               // ��ǰ�������޹�����ʾֵ

typedef sMtNoneValue sMtP2NoneValue;               // ��ǰ�������޹�����ʾֵ

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf34_f;

// ת������
eMtErr emtTrans_afn0cf34(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F35�� ����������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F35_FRTH_DMND_M
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef struct 
{
    sMtFmt23_f  sMaxDmnd;       
    sMtFmt23_f  sDmnd[1];    
}sMtDmnd;                   // ���������

typedef struct 
{
    sMtFmt17_f  sDmndTime;
    sMtFmt17_f  sTime[1];
    
}sMtDmndTime;            // �������������ʱ��


typedef sMtDmnd sMtCurFrthHaveDmnd;     // ���������й����������

typedef sMtDmnd sMtCurFrthNoneDmnd;     // ���������޹����������

typedef sMtDmndTime sMtCurFrthHaveTime; // ���������й��������������ʱ��

typedef sMtDmndTime sMtCurFrthNoneTime; // ���������޹��������������ʱ��

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf35_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf35(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F36�����·�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F36_BACK_DMND_M
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef sMtDmnd sMtCurBackHaveDmnd;     // ���·����й����������

typedef sMtDmnd sMtCurBackNoneDmnd;     // ���������޹����������

typedef sMtDmndTime sMtCurBackHaveTime; // ���·����й��������������ʱ��

typedef sMtDmndTime sMtCurBackNoneTime; // ���·����޹��������������ʱ��

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf36_f;
#pragma pack()

// ת������
eMtErr emtTrans_afn0cf36(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F37�����£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F37_FRTH_POWR_P1P4_L
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef sMtHaveValue sMtLastFrthHaveValue;      // ����( ��һ������) �����й�����ʾֵ

typedef sMtNoneValue sMtLastFrthNoneValue;      //  ����(��һ������) �����޹�����ʾֵ

typedef sMtNoneValue sMtLastP1NoneValue;         //  ����(��һ������) һ�����޹�����ʾֵ

typedef sMtNoneValue sMtLastP4NoneValue;         //  ����(��һ������) �������޹�����ʾֵ

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf37_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf37(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F38�����£���һ�����գ�������/�޹�������޹�1������ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F38_BACK_POWR_P2P3_L
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef sMtHaveValue sMtLastBackHaveValue;      // ����( ��һ������) �����й�����ʾֵ

typedef sMtNoneValue sMtLastBackNoneValue;      //  ����(��һ������) �����޹�����ʾֵ

typedef sMtNoneValue sMtLastP2NoneValue;         //  ����(��һ������) �������޹�����ʾֵ

typedef sMtNoneValue sMtLastP3NoneValue;         //  ����(��һ������) �������޹�����ʾֵ

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf38_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf38(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F39�� ���£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F39_FRTH_DMND_L
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef sMtDmnd sMtLastFrthHaveDmnd;     // ���£���һ�����գ������й����������

typedef sMtDmnd sMtLastFrthNoneDmnd;     // ���£���һ�����գ������޹����������

typedef sMtDmndTime sMtLastFrthHaveTime; // ���£���һ�����գ������й��������������ʱ��

typedef sMtDmndTime sMtLastFrthNoneTime; // ���£���һ�����գ������޹��������������ʱ��

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf39_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf39(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F40�����£���һ�����գ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F40_BACK_DMND_L
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
#pragma pack() 
typedef sMtDmnd sMtLastBackHaveDmnd;     // ���£���һ�����գ������й����������

typedef sMtDmnd sMtLastBackNoneDmnd;     //���£���һ�����գ������޹����������

typedef sMtDmndTime sMtLastBackHaveTime; // ���£���һ�����գ������й��������������ʱ��

typedef sMtDmndTime sMtLastBackNoneTime; // ���£���һ�����գ������޹��������������ʱ��

typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucRateM;        // ������
}sMtAfn0cf40_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf40(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���������й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F41_FRTH_HAVE_POWR_D
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

#define      MT_PAY_RATE_MAX    (64)
// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdForthHavePowerD;                   // ���������й��ܵ�����
    BOOL                bdForthHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dForthHavePowerD;                   // ���������й��ܵ�����
    double              dForthHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й�������  
    
}sMtForthHavePowerD, sMtAfn0cF41;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dForthHavePowerD;                   // ���������й��ܵ�����
    sMtFmt_XXXX_XXXX    dForthHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й�������  
    
}sMtForthHavePowerD_f, sMtAfn0cF41_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf41(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���������޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F42_FRTH_NONE_POWR_D
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdForthNonePowerD;                   // ���������޹��ܵ�����
    BOOL                bdForthNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dForthNonePowerD;                   // ���������޹��ܵ�����
    double              dForthNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹�������  
    
}sMtForthNonePowerD, sMtAfn0cF42;

// ֡��
#pragma pack(1) 
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dForthNonePowerD;                   // ���������޹��ܵ�����
    sMtFmt_XXXX_XXXX    dForthNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹�������  
    
}sMtForthNonePowerD_f, sMtAfn0cF42_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf42(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���շ����й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F43_BACK_HAVE_POWR_D
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdBackHavePowerD;                   // ���շ����й��ܵ�����
    BOOL                bdBackHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dBackHavePowerD;                   // ���շ����й��ܵ�����
    double              dBackHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й�������  
    
}sMtBackHavePowerDay, sMtAfn0cF43;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dBackHavePowerD;                   // ���շ����й��ܵ�����
    sMtFmt_XXXX_XXXX    dBackHavePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����й�������  
    
}sMtBackHavePowerDay_f, sMtAfn0cF43_f;

// ת������
eMtErr emtTrans_afn0cf43(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���շ����޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F44_BACK_NONE_POWR_D
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdBackNonePowerD;                   // ���շ����޹�������
    BOOL                bdBackNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dBackNonePowerD;                   // ���շ����޹��ܵ�����
    double              dBackNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹�������  
    
}sMtBackNonePowerDay, sMtAfn0cF44;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dBackNonePowerD;                   // ���շ����޹�������
    sMtFmt_XXXX_XXXX    dBackNonePowerMD[MT_PAY_RATE_MAX]; // ���շ���(1 ~ M)�����޹�������  
    
}sMtBackNonePowerDay_f, sMtAfn0cF44_f;

// ת������
eMtErr emtTrans_afn0cf44(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���������й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F45_FRTH_HAVE_POWR_M
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdForthHavePowerM;                   // ���������й��ܵ�����
    BOOL                bdForthHavePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����й������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dForthHavePowerM;                   // ���������й��ܵ�����
    double              dForthHavePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����й�������  
    
}sMtForthHavePowerM, sMtAfn0cF45;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dForthHavePowerM;                   // ���������й��ܵ�����
    sMtFmt_XXXX_XXXX    dForthHavePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����й�������  
    
}sMtForthHavePowerM_f, sMtAfn0cF45_f;

// ת������
eMtErr emtTrans_afn0cf45(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���������޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F46_FRTH_NONE_POWR_M
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdForthNonePowerM;                   // ���������޹��ܵ�����
    BOOL                bdForthNonePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����޹������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dForthNonePowerM;                   // ���������޹��ܵ�����
    double              dForthNonePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����޹�������  
    
}sMtForthNonePowerM, sMtAfn0cF46;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dForthNonePowerM;                   // ���������޹��ܵ�����
    sMtFmt_XXXX_XXXX    dForthNonePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����޹�������  
    
}sMtForthNonePowerM_f, sMtAfn0cF46_f;

// ת������
eMtErr emtTrans_afn0cf46(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���·����й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F47_BACK_HAVE_POWR_M
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdBackHavePowerM;                   // ���·����й��ܵ�����
    BOOL                bdBackHavePowerMM[MT_PAY_RATE_MAX]; // ���·���(1 ~ M)�����й������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dBackHavePowerM;                    // ���·����й��ܵ�����
    double              dBackHavePowerMM[MT_PAY_RATE_MAX];  // ���·���(1 ~ M)�����й�������  
    
}sMtBackHavePowerMc, sMtAfn0cF47;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dBackHavePowerM;                    // ���·����й��ܵ�����
    sMtFmt_XXXX_XXXX    dBackHavePowerMM[MT_PAY_RATE_MAX];  // ���·���(1 ~ M)�����й�������  
    
}sMtBackHavePowerMc_f, sMtAfn0cF47_f;

// ת������
eMtErr emtTrans_afn0cf47(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ���·����޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F48_BACK_NONE_POWR_M
 * PN ���� : �������
 * ���ʷ�Χ:  M (1 ~ 14) (DLT645 1997)
 * ���ʷ�Χ:  M (1 ~ 63) (DLT645 2007)
{*///

// �û���
typedef struct
{
    // �������� �ֱ��Ӧʵ������ Ϊ�����ʾ��Ч
    BOOL                bucM;                                // ������M
    BOOL                bdBackNonePowerM;                    // ���·����޹�������
    BOOL                bdBackNonePowerMM[MT_PAY_RATE_MAX];  // ���·���(1 ~ M)�����޹������� 
    
    // ʵ������
    UINT8               ucM;                                // ������M
    double              dBackNonePowerM;                    // ���·����޹��ܵ�����
    double              dBackNonePowerMM[MT_PAY_RATE_MAX];  // ���·���(1 ~ M)�����޹�������  
    
}sMtBackNonePowerMc, sMtAfn0cF48;

// ֡��
typedef struct
{
    UINT8               ucM;                                // ������M
    sMtFmt_XXXX_XXXX    dBackNonePowerM;                    // ���·����޹�������
    sMtFmt_XXXX_XXXX    dBackNonePowerMM[MT_PAY_RATE_MAX];  // ���·���(1 ~ M)�����޹�������  
    
}sMtBackNonePowerMc_f, sMtAfn0cF48_f;

// ת������
eMtErr emtTrans_afn0cf48(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F49����ǰ��ѹ��������λ��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F49_CURT_PHASE_ANGLE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{
    sMtFmt05    sUab;            // Uab/Ua��λ��
    sMtFmt05    sUb;             // Ub��λ��
    sMtFmt05    sUcb;            // Ucb/Uc��λ��
    sMtFmt05    sIa;             // Ia��λ��
    sMtFmt05    sIb;             // Ib��λ��
    sMtFmt05    sIc;             // Ic��λ��
}sMtAfn0cf49_f;

// ת������
eMtErr emtTrans_afn0cf49(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F57����ǰA��B��C�����ѹ������2��N��г����Чֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F57_CURT_HARM_VALUE
 * PN ���� : �������
{*///

#define MT_HARM_TIMES_MIN          (2)    // г��������Сֵ
#define MT_HARM_TIMES_MAX          (19)   // г���������ֵ

typedef struct
{
    BOOL  bfXXX_X[MT_HARM_TIMES_MAX];     // ���޶�Ӧ������
    float fXXX_X[MT_HARM_TIMES_MAX];      // ��ѹг�� ��ʽ XXX.X (V)

}sMtHarmU;

typedef struct
{
    BOOL  bfsXX_XX[MT_HARM_TIMES_MAX];    // ���޶�Ӧ������
    float fsXX_XX[MT_HARM_TIMES_MAX];     // ����г�� ��ʽ (+/-) XX.XX (A)

}sMtHarmI;

// �û���
typedef struct
{
    UINT8        ucN;                     // г������N��2 ��N ��19��
    sMtHarmU     sUa;                     // A��2��~N��г����ѹ
    sMtHarmU     sUb;                     // B��2��~N��г����ѹ
    sMtHarmU     sUc;                     // C��2��~N��г����ѹ
    sMtHarmI     sIa;                     // A��2��~N��г������
    sMtHarmI     sIb;                     // B��2��~N��г������
    sMtHarmI     sIc;                     // C��2��~N��г������
    
}sMtCurtHarmValue, sMtAfn0cF57;

// ֡��
typedef union
{       
    sMtFmt_XXX_X   XXX_X;
    sMtFmt_sXX_XX  sXX_XX;
}uMtHarm;

typedef struct
{
     UINT8      ucN;                     // г������N��2 ��N ��19��
     uMtHarm    uHarm[1];                // 6 * (N-1)��
    
}sMtCurtHarmValue_f, sMtAfn0cF57_f;

// ת������
eMtErr emtTrans_afn0cf57(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F58����ǰA��B��C�����ѹ������2��N��г��������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F58_CURT_HARM_RATE
 * PN ���� : �������
{*///

typedef struct
{
    BOOL  bfsXXX_X;                       // ���޶�Ӧ������
    float fsXXX_X;                        // г����ѹ������ ��ʽ  (+/-) XXX.X (%)

}sMtHarmRateUt;

typedef struct
{
    sMtHarmRateUt sTotal;                  // ��г����ѹ������
    BOOL  bfsXXX_X[MT_HARM_TIMES_MAX];     // ���޶�Ӧ������
    float fsXXX_X[MT_HARM_TIMES_MAX];      // г����ѹ������ ��ʽ  (+/-) XXX.X (%)

}sMtHarmRateU;

typedef struct
{
    BOOL  bfsXXX_X;                        // ���޶�Ӧ������
    float fsXXX_X;                         // г������������ ��ʽ (+/-) XXX.X (%)

}sMtHarmRateIt;

typedef struct
{
    sMtHarmRateIt   sTotal;               // ��г������������
    BOOL  bfsXXX_X[MT_HARM_TIMES_MAX];    // ���޶�Ӧ������
    float fsXXX_X[MT_HARM_TIMES_MAX];     // г������������ ��ʽ (+/-) XXX.X (%)

}sMtHarmRateI;

// �û���
typedef struct
{
    UINT8            ucN;                  // г������N��2 ��N ��19��

    sMtHarmRateU     sUa;                  // A��2��~N��г����ѹ������
    sMtHarmRateU     sUb;                  // B��2��~N��г����ѹ������
    sMtHarmRateU     sUc;                  // C��2��~N��г����ѹ������

    sMtHarmRateI     sIa;                  // A��2��~N��г������������
    sMtHarmRateI     sIb;                  // B��2��~N��г������������
    sMtHarmRateI     sIc;                  // C��2��~N��г������������
    
}sMtCurtHarmRate, sMtAfn0cF58;

// ֡��
#pragma pack(1) 
typedef struct
{
     UINT8            ucN;                 // г������N��2 ��N ��19��
     sMtFmt_sXXX_X    sXXX_X[1];           // 6 * (N-1)��
    
}sMtCurtHarmRate_f, sMtAfn0cF58_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf58(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F65����ǰ������Ͷ��״̬
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F65_CURT_CAPA_SWITCH
 * PN ���� : �������
 *
{*///

// �û���


// ֡��

typedef struct 
{
   UINT8    ucRunMode;      // ���з�ʽ
   UINT16   usCapaSwtich;   // ��������Ͷ��״̬
}sMtAfn0cf65_f;

// ת������
eMtErr emtTrans_afn0cf65(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F66����ǰ�������ۼƲ���Ͷ��ʱ��ʹ���
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F66_CURT_CAPA_TIME
 * PN ���� : �������
 *
{*///

// �û���


// ֡��

typedef struct 
{
   UINT32   uiSeconds[9];   // ��ǰn��������ۼ�Ͷ��ʱ��(��)
   UINT16   uiTimes[9];     // ��ǰn��������ۼ�Ͷ�����
}sMtAfn0cf66_f;

// ת������
eMtErr emtTrans_afn0cf66(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F67�����ա����µ������ۼƲ������޹�������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F67_CURT_CAPA_POWR
 * PN ���� : �������
 *
{*///

// �û���


// ֡��

typedef struct 
{
   sMtFmt13  sCurDayNonePower;      // ��ǰ�ղ������޹�������
   sMtFmt13  sCurMonthNonePower;    // ��ǰ�²������޹�������
}sMtAfn0cf67_f;

// ת������
eMtErr emtTrans_afn0cf67(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F73��ֱ��ģ������ǰ����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F73_DC_RLTM_DATA
 * PN ���� : �������
 *
{*///

// �û���


// ֡��

typedef sMtFmt02_f sMtAfn0cf73_f;   // ֱ��ģ������ǰ����

// ת������
eMtErr emtTrans_afn0cf73(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F81��Сʱ�����ܼ��й�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F81_HFRZ_GRUP_RATE_HAVE
 * PN ���� : �ܼ����
 *
{*///

// �û���


// ֡��

typedef struct 
{
    UINT8   ucReserve:2;        // ��������
    UINT8   ucHourDec:2;        // ����ʱ��ʮλ( 0 ~ 23)
    UINT8   ucHour:4;           // ����ʱ���λ
    UINT8   ucFrzFreq;          // �����ܶ�
}sMtTimeStamp;

enum
{
    MT_FRZ_NONE,            // ������
    MT_FRZ_15,              // 15���Ӷ���һ��
    MT_FRZ_30,              // 30���Ӷ���һ��
    MT_FRZ_60,              // 60���Ӷ���һ��
    MT_FRZ_5 = 254,        // 5���Ӷ���һ��
    MT_FRZ_1 = 255,        // 1���Ӷ���һ��
    MT_FRZ_UNKNOWN,        // ��������
};

typedef struct 
{
    sMtTimeStamp    sTimeStamp;     // Сʱ����������ʱ��
    sMtFmt02_f      sPower[1];      // ����
}sMtFrzGrupPower;

typedef sMtFrzGrupPower sMtAfn0cf81_f;

// ת������
eMtErr emtTrans_afn0cf81(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F82��Сʱ�����ܼ��޹�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F82_HFRZ_GRUP_RATE_NONE
 * PN ���� :  �ܼ����
 *
{*///

// �û���


// ֡��

typedef sMtFrzGrupPower sMtAfn0cf82_f;

// ת������
eMtErr emtTrans_afn0cf82(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F83��Сʱ�����ܼ��й��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F83_HFRZ_GRUP_POWR_HAVE
 * PN ���� : �ܼ����
 *
{*///

// �û���


// ֡��

typedef struct 
{
    sMtTimeStamp    sTimeStamp;     // Сʱ����������ʱ��
    sMtFmt03_f      sValue[1];      // ����
}sMtFrzGrupValue;           // ���������

typedef sMtFrzGrupValue sMtAfn0cf83_f;

// ת������
eMtErr emtTrans_afn0cf83(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F84��Сʱ�����ܼ��޹��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F84_HFRZ_GRUP_POWR_NONE
 * PN ���� : �ܼ����
 *
{*///

// �û���


// ֡��

typedef sMtFrzGrupValue sMtAfn0cf84_f;

// ת������
eMtErr emtTrans_afn0cf84(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F89��Сʱ�����й�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F89_HFRZ_RATE_HAVE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt09        sPower[1];
}sMtFrzPower;

typedef sMtFrzPower sMtAfn0cf89_f;

// ת������
eMtErr emtTrans_afn0cf89(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F90��Сʱ����A���й�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F90_HFRZ_RATE_HAVE_A
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf90_f;

// ת������
eMtErr emtTrans_afn0cf90(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F91��Сʱ����B ���й�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F91_HFRZ_RATE_HAVE_B
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf91_f;

// ת������
eMtErr emtTrans_afn0cf91(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F92��Сʱ����C ���й�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F92_HFRZ_RATE_HAVE_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf92_f;

// ת������
eMtErr emtTrans_afn0cf92(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F93��Сʱ�����޹�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F93_HFRZ_RATE_NONE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf93_f;

// ת������
eMtErr emtTrans_afn0cf93(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F94��Сʱ����A  ���޹�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F94_HFRZ_RATE_NONE_A
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf94_f;

// ת������
eMtErr emtTrans_afn0cf94(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F95��Сʱ����B  ���޹�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F95_HFRZ_RATE_NONE_B
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf95_f;

// ת������
eMtErr emtTrans_afn0cf95(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F96��Сʱ����C  ���޹�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F96_HFRZ_RATE_NONE_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzPower sMtAfn0cf96_f;

// ת������
eMtErr emtTrans_afn0cf96(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F97��Сʱ����A���ѹ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F97_HFRZ_VOLT_A
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt07        sVolt[1];
}sMtFrzVolt;

typedef sMtFrzVolt sMtAfn0cf97_f;

// ת������
eMtErr emtTrans_afn0cf97(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F98��Сʱ����B���ѹ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F97_HFRZ_VOLT_B
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzVolt sMtAfn0cf98_f;

// ת������
eMtErr emtTrans_afn0cf98(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F99��Сʱ����C���ѹ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F97_HFRZ_VOLT_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzVolt sMtAfn0cf99_f;

// ת������
eMtErr emtTrans_afn0cf99(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F100��Сʱ����A�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F100_HFRZ_ELEC_A
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt25        sElec[1];
}sMtFrzElec;

typedef sMtFrzElec sMtAfn0cf100_f;

// ת������
eMtErr emtTrans_afn0cf100(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F101��Сʱ����B�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F101_HFRZ_ELEC_B
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzElec sMtAfn0cf101_f;

// ת������
eMtErr emtTrans_afn0cf101(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F102��Сʱ����C�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F102_HFRZ_ELEC_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzElec sMtAfn0cf102_f;

// ת������
eMtErr emtTrans_afn0cf102(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F103��Сʱ�����������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F103_HFRZ_ELEC_ZERO
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzElec sMtAfn0cf103_f;

// ת������
eMtErr emtTrans_afn0cf103(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F105��Сʱ���������й��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F105_HFRZ_FRTH_HAVE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt13        sErgy[1];
}sMtFrzErgy;                

typedef sMtFrzErgy sMtAfn0cf105_f;

// ת������
eMtErr emtTrans_afn0cf105(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F106��Сʱ���������޹��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F106_HFRZ_FRTH_NONE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzErgy sMtAfn0cf106_f;

// ת������
eMtErr emtTrans_afn0cf106(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F107��Сʱ���ᷴ���й��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F107_HFRZ_BACK_HAVE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzErgy sMtAfn0cf107_f;

// ת������
eMtErr emtTrans_afn0cf107(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F108��Сʱ���ᷴ���޹��ܵ�����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F108_HFRZ_BACK_NONE
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzElec sMtAfn0cf108_f;

// ת������
eMtErr emtTrans_afn0cf108(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F109��Сʱ���������й��ܵ���ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F109_HFRZ_FRTH_HAVE_S
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt11        sValue[1];
}sMtFrzValue;                

typedef sMtFrzValue sMtAfn0cf109_f;

// ת������
eMtErr emtTrans_afn0cf109(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F110��Сʱ���������޹��ܵ���ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F110_HFRZ_FRTH_NONE_S
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzValue sMtAfn0cf110_f;

// ת������
eMtErr emtTrans_afn0cf110(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F111��Сʱ���ᷴ���й��ܵ���ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F111_HFRZ_BACK_HAVE_S
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzValue sMtAfn0cf111_f;

// ת������
eMtErr emtTrans_afn0cf111(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F112�� Сʱ���ᷴ���޹��ܵ���ʾֵ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F112_HFRZ_BACK_NONE_S
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef sMtFrzValue sMtAfn0cf112_f;

// ת������
eMtErr emtTrans_afn0cf112(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F113��Сʱ�����ܹ�������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F113_HFRZ_FACT_TOTAL
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
typedef struct 
{ 
    sMtTimeStamp    sTimeStamp;
    sMtFmt05        sFact[1];
}sMtFrzFact;                

typedef sMtFrzFact sMtAfn0cf113_f;

// ת������
eMtErr emtTrans_afn0cf113(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F114��Сʱ����A�๦������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F114_HFRZ_FACT_A
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
      
typedef sMtFrzFact sMtAfn0cf114_f;

// ת������
eMtErr emtTrans_afn0cf114(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F115��Сʱ����B�๦������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F115_HFRZ_FACT_B
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
      
typedef sMtFrzFact sMtAfn0cf115_f;

// ת������
eMtErr emtTrans_afn0cf115(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F116��Сʱ����C�๦������
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F116_HFRZ_FACT_C
 * PN ���� : �������
 *
{*///

// �û���


// ֡��
      
typedef sMtFrzFact sMtAfn0cf116_f;

// ת������
eMtErr emtTrans_afn0cf116(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F121��Сʱ����ֱ��ģ����
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F121_HFRZ_DC_VALUE
 * PN ���� :  ֱ��ģ�����˿ں�
 *
{*///

// �û���


// ֡��

typedef sMtFrzGrupPower sMtAfn0cf121_f;

// ת������
eMtErr emtTrans_afn0cf121(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F129����ǰ�����й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F129_FRTH_HAVE_POWR_C
 * PN ���� :  �������
 *
{*///

// �û���
typedef struct 
{
    sMtFmt15    sTime;          // �ն˳���ʱ��
    UINT8       ucM;            // ������M >= 1
    double      dTotalValue;   // �����й�����ʾֵ dXXXXXX.XXXX
    double      dValueItem[1]; // ����m �����й�����ʾֵ dXXXXXX.XXXX
}sMtAfn0cf129;


// ֡��
typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucM;            // ������M >= 1
    sMtFmt14_f  sTotalValue;   // �����й�����ʾֵ
    sMtFmt14_f  sValueItem[1]; // ����m �����й�����ʾֵ
}sMtAfn0cf129_f;

// ת������
eMtErr emtTrans_afn0cf129(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F130����ǰ�����й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F130_FRTH_NONE_POWR_C
 * PN ���� :  �������
 *
{*///

// �û���
typedef struct 
{
    sMtFmt15 sTime;          // �ն˳���ʱ��
    UINT8    ucM;            // ������M
    DOUBLE   dTotalValue;   // �����й�����ʾֵ dXXXXXX.XX
    DOUBLE   dValueItem[1]; // ����m �����й�����ʾֵ dXXXXXX.XX
}sMtAfn0cf130;

// ֡��
typedef struct 
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucM;        // ������M
    sMtFmt11_f  sTotalValue;   // �����й�����ʾֵ
    sMtFmt11_f  sValueItem[1]; // ����m �����й�����ʾֵ
}sMtAfn0cf130_f;

// ת������
eMtErr emtTrans_afn0cf130(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F131����ǰ�����й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F131_BACK_HAVE_POWR_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf129_f sMtAfn0cf131_f;

// ת������
eMtErr emtTrans_afn0cf131(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F132����ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F132_BACK_NONE_POWR_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf132_f;

// ת������
eMtErr emtTrans_afn0cf132(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F133����ǰһ�����޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F133_NONE_POWR_P1_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf133_f;

// ת������
eMtErr emtTrans_afn0cf133(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F134����ǰ�������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F134_NONE_POWR_P2_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf134_f;

// ת������
eMtErr emtTrans_afn0cf134(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F135����ǰ�������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F135_NONE_POWR_P3_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf135_f;

// ת������
eMtErr emtTrans_afn0cf135(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F136����ǰ�������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F136_NONE_POWR_P4_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf136_f;

// ת������
eMtErr emtTrans_afn0cf136(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F137�����£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F137_FRTH_HAVE_POWR_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf129_f sMtAfn0cf137_f;

// ת������
eMtErr emtTrans_afn0cf137(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F138�����£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F138_FRTH_NONE_POWR_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf138_f;

// ת������
eMtErr emtTrans_afn0cf138(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F139�����£���һ�����գ������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F139_BACK_HAVE_POWR_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf129_f sMtAfn0cf139_f;

// ת������
eMtErr emtTrans_afn0cf139(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F140�����£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F140_BACK_NONE_POWR_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf140_f;

// ת������
eMtErr emtTrans_afn0cf140(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F141�� ���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F141_NONE_POWR_P1_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf141_f;

// ת������
eMtErr emtTrans_afn0cf141(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F142�� ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F142_NONE_POWR_P2_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf142_f;

// ת������
eMtErr emtTrans_afn0cf142(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F143�� ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F143_NONE_POWR_P3_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf143_f;

// ת������
eMtErr emtTrans_afn0cf143(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F144�� ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F144_NONE_POWR_P4_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef sMtAfn0cf130_f sMtAfn0cf144_f;

// ת������
eMtErr emtTrans_afn0cf144(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F145�� ���������й��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F145_FRTH_HAVE_DMND_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef struct 
{
    sMtFmt23_f  sDmnd;          // �������
    sMtFmt17_f  sClock;         // �����������ʱ��
}sMtDmndClock;

typedef struct
{
    sMtFmt15_f      sTime;          // �ն˳���ʱ��
    UINT8           ucRateM;        // ������M
    sMtDmndClock    sDmndClock[1]; // �ն��������������ʱ��
}sMtAfn0cf145_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf145(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F146�����������޹��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F146_FRTH_NONE_DMND_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf146_f;

// ת������
eMtErr emtTrans_afn0cf146(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F147�����·����й��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F147_BACK_HAVE_DMND_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf147_f;

// ת������
eMtErr emtTrans_afn0cf147(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F148�����·����޹��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F148_BACK_NONE_DMND_C
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf148_f;

// ת������
eMtErr emtTrans_afn0cf148(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F149�����£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F149_FRTH_HAVE_DMND_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf149_f;

// ת������
eMtErr emtTrans_afn0cf149(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F150�����£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F150_FRTH_NONE_DMND_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf150_f;

// ת������
eMtErr emtTrans_afn0cf150(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F151�����£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F151_BACK_HAVE_DMND_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf151_f;

// ת������
eMtErr emtTrans_afn0cf151(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F152�����£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F152_BACK_NONE_DMND_L
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf145_f sMtAfn0cf152_f;

// ת������
eMtErr emtTrans_afn0cf152(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F153�� ��һʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F153_FREZ_ZONE_1
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf153_f;

// ת������
eMtErr emtTrans_afn0cf153(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F154�� �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F154_FREZ_ZONE_2
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf154_f;

// ת������
eMtErr emtTrans_afn0cf154(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F155�� ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F155_FREZ_ZONE_3
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf155_f;

// ת������
eMtErr emtTrans_afn0cf155(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F156�� ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F156_FREZ_ZONE_4
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf156_f;

// ת������
eMtErr emtTrans_afn0cf156(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F157�� ����ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F157_FREZ_ZONE_5
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf157_f;

// ת������
eMtErr emtTrans_afn0cf157(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F158������ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F158_FREZ_ZONE_6
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf158_f;

// ת������
eMtErr emtTrans_afn0cf158(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F159������ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F159_FREZ_ZONE_7
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf159_f;

// ת������
eMtErr emtTrans_afn0cf159(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F160���ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F160_FREZ_ZONE_8
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��

typedef sMtAfn0cf129_f sMtAfn0cf160_f;

// ת������
eMtErr emtTrans_afn0cf160(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F161�����ܱ�Զ�̿���ͨ�ϵ�״̬����¼
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F161_METR_REMOTE_CTRL
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
enum 
{   
    MT_ON,              // 0 ��ʾ�ϵ�
    MT_OFF = 17,       // 11H ��ʾͨ��
};

typedef struct
{
    sMtFmt15_f  sTime;          // �ն˳���ʱ��
    UINT8       ucMtOnOff;      // �ն�ͨ�� ״̬( 0 - �ϵ磬11H - ͨ��)
    sMtFmt15_f  sOnTimeLast;    // ���һ�ε��ܱ�Զ�̿���ͨ��ʱ��
    sMtFmt15_f  sOffTimeLast;   // ���һ�ε��ܱ�Զ�̿��ƶϵ�ʱ��
}sMtAfn0cf161_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf161(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F165�����ܱ��ز���������ʱ��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F165_METR_SWITCH_RECD
 * PN ���� :  �������
 *
{*///

// �û���
typedef struct 
{   
    UINT16      usTimes;    // ��������
    sMtFmt15    sClock;     // ���һ�η���ʱ��
}sMtOptLog;

typedef struct
{
    sMtFmt15      sTime;           // �ն˳���ʱ��
    sMtOptLog     sOne;            // ��ĳ������Ĵ��������һ�η���ʱ��
    sMtOptLog     sOther;          // ����һ������Ĵ��������һ�η���ʱ��   
}sMtAfn0cf165;

// ֡��
#pragma pack(1) 
typedef struct 
{
    sMtFmt08    sTimes;     // ����
    sMtFmt15_f  sClock;     // ����ʱ��
}sMtOptLog_f;

typedef struct
{
    sMtFmt15_f      sTime;           // �ն˳���ʱ��
    sMtOptLog_f     sOne;            // ��ĳ������Ĵ��������һ�η���ʱ��
    sMtOptLog_f     sOther;          // ����һ������Ĵ��������һ�η���ʱ��   
}sMtAfn0cf165_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf165(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F166�����ܱ�����޸Ĵ�����ʱ��
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F166_METR_MODIFY_RECD
 * PN ���� :  �������
 *
{*///

// �û���

typedef sMtAfn0cf165 sMtAfn0cf166;
// ֡��
typedef sMtAfn0cf165_f sMtAfn0cf166_f;

// ת������
eMtErr emtTrans_afn0cf166(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F167�����ܱ����õ���Ϣ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F167_METR_BUY_USE
 * PN ���� :  �������
 *
{*///

// �û���

typedef struct 
{
    sMtFmt15    sTime;      // �ն˳���ʱ��
    UINT16      usBuyTimes;  //  �������
    DOUBLE      dCashLeft;  // ʣ���� dXXXXXX.XXXX
    DOUBLE      dCashTotal; // �ۼƹ����� dXXXXXX.XXXX
    DOUBLE      dElecLeft;  // ʣ�����double dXXXXXX.XX
    DOUBLE      dElecOut;   // ͸֧����double dXXXXXX.XX
    DOUBLE      dElecTotal; // �ۼƹ�����double dXXXXXX.XX
    DOUBLE      dElecLimit; // ��Ƿ���޵���double dXXXXXX.XX
    DOUBLE      dElecWarn;  // ��������double dXXXXXX.XX
    DOUBLE      dElecFault; // ���ϵ���double dXXXXXX.XX  
}sMtAfn0cf167;

// ֡��
#pragma pack(1) 
typedef struct
{
    sMtFmt15_f  sTime;      // �ն˳���ʱ��
    sMtFmt08    sBuyTimes;  //  �������
    sMtFmt14_f  sCashLeft;  // ʣ����
    sMtFmt14_f  sCashTotal; // �ۼƹ�����
    sMtFmt11_f  sElecLeft;  // ʣ�����
    sMtFmt11_f  sElecOut;   // ͸֧����
    sMtFmt11_f  sElecTotal; // �ۼƹ�����
    sMtFmt11_f  sElecLimit; // ��Ƿ���޵���
    sMtFmt11_f  sElecWarn;  // ��������
    sMtFmt11_f  sElecFault; // ���ϵ���
}sMtAfn0cf167_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf167(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F168�����ܱ������Ϣ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F168_METR_BALANCE
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef struct
{
    sMtFmt15_f  sTime;      // �ն˳���ʱ��
    UINT16      usRateM;    // ������M
    UINT8       ucErgy[1];  // ���� 
}sMtAfn0cf168_f;

// ת������
eMtErr emtTrans_afn0cf168(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F169�����г����м�·����Ϣ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F169_READ_ROUTE
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
#pragma pack(1) 
typedef struct 
{
    UINT8       m;             // ��n ���м�·�ɼ���
    sMtFmt12    sAddress[1];   // ��n ���м�·�ɵĵ�Mn ����ַ
}sMtRoute;

typedef struct
{
    UINT8       ucPort;       // �����ն�ͨ�Ŷ˿ں�
    UINT8       ucRoutN;      // �м�·�ɸ���N 
    sMtRoute    sRoute[1];    // �м�·�ɼ����͵�ַ
}sMtAfn0cf169_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0cf169(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F170�� ���г���������Ϣ
 * ��ӦAFN : AFN_0C_ASK1
 * ��ӦCMD : CMD_AFN_C_F170_READ_METER
 * PN ���� :  �������
 *
{*///

// �û���


// ֡��
typedef struct
{
    UINT8       ucPort;             // �����ն�ͨ�Ŷ˿ں�
    UINT8       ucRoutN;            // �м�·�ɸ���N 
    UINT8       ucSignalPhase;      // �ز���ʹͨ����λ
    UINT8       ucSignalQuality;    // �ز��ź�Ʒ��
    UINT8       ucReadFlagLast;     // ���һ�γ���ɹ�/ ʧ�ܱ�־
    sMtFmt01_f  sTimeOkLast;        // ���һ�γ���ɹ�ʱ��
    sMtFmt01_f  sTimeFailLast;      // ���һ�γ���ʧ��ʱ��
    UINT8       ucTimesFailTotal;   // �������ʧ���ۼƴ���
}sMtAfn0cf170_f;

// ת������
eMtErr emtTrans_afn0cf170(eMtTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���Ͷ���: ����2�����ݸ����Ͷ���
 * ����˵��: ����2�������������б������ݵ�Ԫ���ݽ�������ʱ��
 *           ����ʱ�����������������ݵ���ʼʱ��ts�������ܶ�m�����ݵ���n
 * ʱ������: Td_h��Td_c��Td_d��Td_m
 * 
{*///

/*******************************************
 * ���ݽṹ: Сʱ����������ʱ�����ݸ�ʽ
 * ��Ӧ����: Td_h
 * ����˵��: ��ʾ��һ�����Сʱʱ�䣬��ֵ��Χ0��23
{*///
#define MT_TD_H_MIN       (0)   // Сʱʱ����Сֵ
#define MT_TD_H_MAX       (23)  // Сʱʱ�����ֵ

// �û���
typedef struct
{
    UINT8           ucHH;        // ����Сʱʱ�� (0 ~ 23)
    
}sMtTd_h;
    
// ֡��
typedef struct
{
     UINT8          ucBCD_0 : 4;  // Сʱ����λ��
     UINT8          ucBCD_1 : 2;  // Сʱ��ʮλ��
     UINT8          ucRes   : 2;  // ����
    
}sMtTd_h_f;

// ת������
eMtErr emtTrans_td_h(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ����������ʱ�����ݸ�ʽ
 * ��Ӧ����: Td_c
 *
{*///

// �û���
typedef struct
{
    sMtYYMMDDhhmm     sT;     // ��ʼʱ��ts����ʱ������
    UINT8             ucM;    // ���ݶ����ܶ�m
    UINT8             ucN;    // ���ݵ���n
    
}sMtTd_c;
    
// ֡��
typedef struct
{
    sMtFmt15_f       sT;      // ��ʼʱ��ts����ʱ������
    UINT8            ucM;     // ���ݶ����ܶ�m
    UINT8            ucN;     // ���ݵ���n
    
}sMtTd_c_f;

// ת������
eMtErr emtTrans_td_c(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: �ն���������ʱ��Td_d
 * ��Ӧ����: Td_d
 * ����˵��: �ն���������ָ�ն���ÿ����ĩ24��ʱ�������������
 *           �����ɳ���õ�����������ĩ24��ʱ�������ض���ĵ������
 *           �����ն���������ָ�ն˰���վ���õ��ն˳�������ĩ24��ʱ�������ض���ĵ������
 *
{*///

// �û���
typedef struct
{
    sMtYYMMDD      sT;     // ������
    
}sMtTd_d;
    
// ֡��
typedef struct
{
    sMtFmt20_f     sT;    // ������
 
}sMtTd_d_f;

// ת������
eMtErr emtTrans_td_d(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: �¶���������ʱ��Td_m
 * ��Ӧ����: Td_m
 * ����˵��: �¶���������ָ�ն���ÿ����ĩ24��ʱ�������������
 *           �����ɳ���õ�����������ĩ24��ʱ�������ض���ĵ������
 *
{*///

// �û���
typedef struct
{
    sMtYYMM      sT;     // ����
    
}sMtTd_m;
    
// ֡��
typedef struct
{
    sMtYYMM_f    sT;    // ����
 
}sMtTd_m_f;

// ת������
eMtErr emtTrans_td_m(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: F1���ն���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F1_FRTH_POWR_P1P4_D
 * PN ���� : �������
 *
{*///

 #define MT_M_MIN      (1)                        // ��������Сֵ
 #define MT_M_MAX      (12)                       // ���������ֵ

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                           // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                           // �ն˳���ʱ��
    UINT8         ucM;                             // ������M��1��M��12��
    double        dFrthHavePowerT;                 // �����й��ܵ���ʾֵ              (+)XXXXXX.XXXX
    double        dFrthHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ   (+)XXXXXX.XXXX
    double        dFrthNonePowerT;                 // �����޹��ܵ���ʾֵ              (+)XXXXXX.XX
    double        dFrthNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ   (+)XXXXXX.XX
    double        dNonePowerP1T;                   // һ�����޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP1[MT_M_MAX];          // ����(1 ~ ucM)һ�����޹�����ʾֵ (+)XXXXXX.XX
    double        dNonePowerP4T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP4[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
   
}sMtFrthPowerP1P2D, sMtAfn0dF1;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                           // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                           // �ն˳���ʱ��
    UINT8        ucM;                             // ������M��1��M��12��
    UINT8        ucPower[1];                      // 
    //sMtFmt14_f   dFrthHavePowerT;                 // �����й��ܵ���ʾֵ             (+)XXXXXX.XXXX
    //sMtFmt14_f   dFrthHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ  (+)XXXXXX.XXXX
    //sMtFmt11_f   dFrthNonePowerT;                 // �����޹��ܵ���ʾֵ             (+)XXXXXX.XX
    //sMtFmt11_f   dFrthNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ  (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP1T;                   // һ�����޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP1[MT_M_MAX];          // ����(1 ~ ucM)һ�����޹�����ʾֵ (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP4T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP4[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
  
}sMtFrthPowerP1P2D_f, sMtAfn0dF1_f;

// ת������
eMtErr emtTrans_afn0df1(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F2���ն��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F2_BACK_POWR_P2P3_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                           // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                           // �ն˳���ʱ��
    UINT8         ucM;                             // ������M��1��M��12��
    double        dBackHavePowerT;                 // �����й��ܵ���ʾֵ              (+)XXXXXX.XXXX
    double        dBackHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ   (+)XXXXXX.XXXX
    double        dBackNonePowerT;                 // �����޹��ܵ���ʾֵ              (+)XXXXXX.XX
    double        dBackNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ   (+)XXXXXX.XX
    double        dNonePowerP2T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP2[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
    double        dNonePowerP3T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP3[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
   
}sMtFrthPowerP2P3D, sMtAfn0dF2;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                           // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                           // �ն˳���ʱ��
    UINT8        ucM;                             // ������M��1��M��12��
    UINT8        ucPower[1];                      // 
    //sMtFmt14_f   dBackHavePowerT;                 // �����й��ܵ���ʾֵ             (+)XXXXXX.XXXX
    //sMtFmt14_f   dBackHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ  (+)XXXXXX.XXXX
    //sMtFmt11_f   dBackNonePowerT;                 // �����޹��ܵ���ʾֵ             (+)XXXXXX.XX
    //sMtFmt11_f   dBackNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ  (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP2T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP2[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP3T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP3[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
  
}sMtFrthPowerP2P3D_f, sMtAfn0dF2_f;

// ת������
eMtErr emtTrans_afn0df2(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F3���ն���������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F3_FRTH_DMND_TIME_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��

    float         fFrthHaveT;                // �����й����������                     (+)XX.XXXX
    float         fFrthHave[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeFrthHaveT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeFrthHave[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    float         fFrthNoneT;                // �����й����������                     (+)XX.XXXX
    float         fFrthNone[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeFrthNoneT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeFrthNone[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    
}sMtFrthDemand, sMtAfn0dF3;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    UINT8        ucDemand[1];                // Ϊ�˻�õ�ַ
    
    #if 0
    // ���½ṹ����, ����Mֵ��ͬ���䳤
    sMtFmt23_f   fFrthHaveT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fFrthHave[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeFrthHaveT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeFrthHave[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    sMtFmt23_f   fFrthNoneT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fFrthNone[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeFrthNoneT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeFrthNone[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    #endif
    
}sMtFrthDemand_f, sMtAfn0dF3_f;

// ת������
eMtErr emtTrans_afn0df3(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F4���ն��ᷴ����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F4_BACK_DMND_TIME_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��

    float         fBackHaveT;                // �����й����������                     (+)XX.XXXX
    float         fBackHave[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeBackHaveT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeBackHave[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    float         fBackNoneT;                // �����й����������                     (+)XX.XXXX
    float         fBackNone[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeBackNoneT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeBackNone[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    
}sMtBackDemand, sMtBackDemandD, sMtAfn0dF4;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    UINT8        ucDemand[1];                // Ϊ�˻�õ�ַ
    
    #if 0
    // ���½ṹ����, ����Mֵ��ͬ���䳤
    sMtFmt23_f   fBackHaveT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fBackHave[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeBackHaveT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeBackHave[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    sMtFmt23_f   fBackNoneT;                 // �����޹����������                     (+)XX.XXXX
    sMtFmt23_f   fBackNone[MT_M_MAX];        // ����(1 ~ ucM)�����޹��������          (+)XX.XXXX
    sMtFmt17_f   sTimeBackNoneT;             // �����޹��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeBackNone[MT_M_MAX];    // ����(1 ~ ucM)�����޹������������ʱ��  ��ʱ����
    #endif
    
}sMtBackDemand_f, sMtBackDemandD_f, sMtAfn0dF4_f;

// ת������
eMtErr emtTrans_afn0df4(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F5���ն��������й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F5_FRTH_HAVE_POWR_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dFrthHaveT;                // �������й��ܵ�����            (+)XXXX.XXXX
    double        dFrthHave[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthHavePowerD, sMtAfn0dF5;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dFrthHaveT;                 // �������й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dFrthHave[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthHavePowerD_f, sMtAfn0dF5_f;

// ת������
eMtErr emtTrans_afn0df5(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F6���ն��������޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F6_FRTH_NONE_POWR_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dFrthNoneT;                // �������й��ܵ�����            (+)XXXX.XXXX
    double        dFrthNone[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthNonePowerD, sMtAfn0dF6;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dFrthNoneT;                 // �������й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dFrthNone[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthNonePowerD_f, sMtAfn0dF6_f;

// ת������
eMtErr emtTrans_afn0df6(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F7���ն��ᷴ���й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F7_BACK_HAVE_POWR_D
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dBackHaveT;                // �շ����й��ܵ�����            (+)XXXX.XXXX
    double        dBackHave[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackHavePowerD, sMtAfn0dF7;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dBackHaveT;                 // �շ����й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dBackHave[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackHavePowerD_f, sMtAfn0dF7_f;

// ת������
eMtErr emtTrans_afn0df7(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F8���ն��ᷴ���޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F8_BACK_NONE_POWR_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d       sTd_d;                     // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dBackNoneT;                // �շ����й��ܵ�����            (+)XXXX.XXXX
    double        dBackNone[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackNonePowerD, sMtAfn0dF8;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_d;                      // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dBackNoneT;                 // �շ����й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dBackNone[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackNonePowerD_f, sMtAfn0dF8_f;

// ת������
eMtErr emtTrans_afn0df8(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F9�������ն���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F9_FRTH_POWR_P1P4_R
 * PN ���� : �������
 *
{*///
// �û���
typedef sMtFrthPowerP1P2D    sMtFrthPowerP1P2R, sMtAfn0dF9;

// ֡��
typedef sMtFrthPowerP1P2D_f sMtFrthPowerP1P2R_f, sMtAfn0dF9_f;

// ת������
eMtErr emtTrans_afn0df9(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F10�������ն��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F10_BACK_POWR_P2P3_R
 * PN ���� : �������
 *
{*///
// �û���
typedef sMtFrthPowerP2P3D    sMtFrthPowerP2P3R, sMtAfn0dF10;

// ֡��
typedef sMtFrthPowerP2P3D_f    sMtFrthPowerP2P3R_f, sMtAfn0dF10_f;

// ת������
eMtErr emtTrans_afn0df10(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F11�������ն�����ܱ�������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F11_FRTH_DMND_TIME_R
 * PN ���� : �������
 *
{*///
// �û���
typedef sMtFrthDemand    sMtFrthDemandR, sMtAfn0dF11;

// ֡��
typedef sMtFrthDemand_f  sMtFrthDemandR_f, sMtAfn0dF11_f;

// ת������
eMtErr emtTrans_afn0df11(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F12�������ն�����ܱ�����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F12_BACK_DMND_TIME_R
 * PN ���� : �������
 *
{*///
// �û���
typedef sMtBackDemand    sMtBackDemandR, sMtAfn0dF12;

// ֡��
typedef sMtBackDemand_f  sMtBackDemandR_f, sMtAfn0dF12_f;

// ת������
eMtErr emtTrans_afn0df12(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F17���¶���������/�޹�����ʾֵ��һ/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F17_FRTH_POWR_P1P4_M
 * PN ���� : �������
 *
{*///

// #define MT_M_MIN      (1)                        // ��������Сֵ
// #define MT_M_MAX      (12)                       // ���������ֵ

// �û���
typedef struct
{
    sMtTd_m       sTd_m;                           // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                           // �ն˳���ʱ��
    UINT8         ucM;                             // ������M��1��M��12��
    double        dFrthHavePowerT;                 // �����й��ܵ���ʾֵ              (+)XXXXXX.XXXX
    double        dFrthHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ   (+)XXXXXX.XXXX
    double        dFrthNonePowerT;                 // �����޹��ܵ���ʾֵ              (+)XXXXXX.XX
    double        dFrthNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ   (+)XXXXXX.XX
    double        dNonePowerP1T;                   // һ�����޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP1[MT_M_MAX];          // ����(1 ~ ucM)һ�����޹�����ʾֵ (+)XXXXXX.XX
    double        dNonePowerP4T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP4[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
   
}sMtFrthPowerP1P2M, sMtAfn0dF17;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                           // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                           // �ն˳���ʱ��
    UINT8        ucM;                             // ������M��1��M��12��
    UINT8        ucPower[1];                      // ��λ,����ȡ��ַ
    //sMtFmt14_f   dFrthHavePowerT;               // �����й��ܵ���ʾֵ              (+)XXXXXX.XXXX
    //sMtFmt14_f   dFrthHavePower[MT_M_MAX];      // ����(1 ~ ucM)�����й�����ʾֵ   (+)XXXXXX.XXXX
    //sMtFmt11_f   dFrthNonePowerT;               // �����޹��ܵ���ʾֵ              (+)XXXXXX.XX
    //sMtFmt11_f   dFrthNonePower[MT_M_MAX];      // ����(1 ~ ucM)�����޹�����ʾֵ   (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP1T;                 // һ�����޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP1[MT_M_MAX];        // ����(1 ~ ucM)һ�����޹�����ʾֵ (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP4T;                 // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP4[MT_M_MAX];        // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
  
}sMtFrthPowerP1P2M_f, sMtAfn0dF17_f;

// ת������
eMtErr emtTrans_afn0df17(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: FF18���¶��ᷴ����/�޹�����ʾֵ����/�������޹�����ʾֵ���ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F18_BACK_POWR_P2P3_M
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_m       sTd_m;                           // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                           // �ն˳���ʱ��
    UINT8         ucM;                             // ������M��1��M��12��
    double        dBackHavePowerT;                 // �����й��ܵ���ʾֵ              (+)XXXXXX.XXXX
    double        dBackHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ   (+)XXXXXX.XXXX
    double        dBackNonePowerT;                 // �����޹��ܵ���ʾֵ              (+)XXXXXX.XX
    double        dBackNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ   (+)XXXXXX.XX
    double        dNonePowerP2T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP2[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
    double        dNonePowerP3T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    double        dNonePowerP3[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
   
}sMtFrthPowerP2P3M, sMtAfn0dF18;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                           // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                           // �ն˳���ʱ��
    UINT8        ucM;                             // ������M��1��M��12��
    UINT8        ucPower[1];                      // 
    //sMtFmt14_f   dBackHavePowerT;                 // �����й��ܵ���ʾֵ             (+)XXXXXX.XXXX
    //sMtFmt14_f   dBackHavePower[MT_M_MAX];        // ����(1 ~ ucM)�����й�����ʾֵ  (+)XXXXXX.XXXX
    //sMtFmt11_f   dBackNonePowerT;                 // �����޹��ܵ���ʾֵ             (+)XXXXXX.XX
    //sMtFmt11_f   dBackNonePower[MT_M_MAX];        // ����(1 ~ ucM)�����޹�����ʾֵ  (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP2T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP2[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP3T;                   // �������޹��ܵ���ʾֵ            (+)XXXXXX.XX
    //sMtFmt11_f   dNonePowerP3[MT_M_MAX];          // ����(1 ~ ucM)�������޹�����ʾֵ (+)XXXXXX.XX
  
}sMtFrthPowerP2P3M_f, sMtAfn0dF18_f;

// ת������
eMtErr emtTrans_afn0df18(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F19��������/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F19_FRTH_DMND_TIME_M
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_m       sTd_m;                     // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��

    float         fFrthHaveT;                // �����й����������                     (+)XX.XXXX
    float         fFrthHave[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeFrthHaveT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeFrthHave[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    float         fFrthNoneT;                // �����й����������                     (+)XX.XXXX
    float         fFrthNone[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeFrthNoneT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeFrthNone[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    
}sMtFrthDemandM, sMtAfn0dF19;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    UINT8        ucDemand[1];                // Ϊ�˻�õ�ַ
    
    #if 0
    // ���½ṹ����, ������Mֵ��ͬ���䳤
    sMtFmt23_f   fFrthHaveT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fFrthHave[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeFrthHaveT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeFrthHave[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    sMtFmt23_f   fFrthNoneT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fFrthNone[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeFrthNoneT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeFrthNone[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    #endif
    
}sMtFrthDemandM_f, sMtAfn0dF19_f;

// ת������
eMtErr emtTrans_afn0df19(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F20���¶��ᷴ����/�޹��������������ʱ�䣨�ܡ�����1��M��1��M��12��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F20_BACK_DMND_TIME_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m       sTd_m;                     // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��

    float         fBackHaveT;                // �����й����������                     (+)XX.XXXX
    float         fBackHave[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeBackHaveT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeBackHave[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    float         fBackNoneT;                // �����й����������                     (+)XX.XXXX
    float         fBackNone[MT_M_MAX];       // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtMMDDHHmm   sTimeBackNoneT;            // �����й��������������ʱ��             ��ʱ����
    sMtMMDDHHmm   sTimeBackNone[MT_M_MAX];   // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����
    
}sMtBackDemandM, sMtAfn0dF20;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    UINT8        ucDemand[1];                // Ϊ�˻�õ�ַ
    
    #if 0
    // ���½ṹ����, ����Mֵ��ͬ���䳤
    sMtFmt23_f   fBackHaveT;                 // �����й����������                     (+)XX.XXXX
    sMtFmt23_f   fBackHave[MT_M_MAX];        // ����(1 ~ ucM)�����й��������          (+)XX.XXXX
    sMtFmt17_f   sTimeBackHaveT;             // �����й��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeBackHave[MT_M_MAX];    // ����(1 ~ ucM)�����й������������ʱ��  ��ʱ����

    sMtFmt23_f   fBackNoneT;                 // �����޹����������                     (+)XX.XXXX
    sMtFmt23_f   fBackNone[MT_M_MAX];        // ����(1 ~ ucM)�����޹��������          (+)XX.XXXX
    sMtFmt17_f   sTimeBackNoneT;             // �����޹��������������ʱ��             ��ʱ����
    sMtFmt17_f   sTimeBackNone[MT_M_MAX];    // ����(1 ~ ucM)�����޹������������ʱ��  ��ʱ����
    #endif
    
}sMtBackDemandM_f, sMtAfn0dF20_f;

// ת������
eMtErr emtTrans_afn0df20(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F21���¶��������й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F22_FRTH_NONE_POWR_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m       sTd_m;                      // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dFrthHaveT;                // �������й��ܵ�����            (+)XXXX.XXXX
    double        dFrthHave[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthHavePowerM, sMtAfn0dF21;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dFrthHaveT;                 // �������й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dFrthHave[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthHavePowerM_f, sMtAfn0dF21_f;

// ת������
eMtErr emtTrans_afn0df21(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F22���¶��������޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F6_FRTH_NONE_POWR_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m       sTd_m;                     // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dFrthNoneT;                // �������й��ܵ�����            (+)XXXX.XXXX
    double        dFrthNone[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthNonePowerM, sMtAfn0dF22;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dFrthNoneT;                 // �������й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dFrthNone[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtFrthNonePowerM_f, sMtAfn0dF22_f;

// ת������
eMtErr emtTrans_afn0df22(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F23���¶��ᷴ���й����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F23_BACK_HAVE_POWR_M
 * PN ���� : �������
 *
{*///

// �û���
typedef struct
{
    sMtTd_m       sTd_m;                     // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dBackHaveT;                // �շ����й��ܵ�����            (+)XXXX.XXXX
    double        dBackHave[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackHavePowerM, sMtAfn0dF23;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dBackHaveT;                 // �շ����й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dBackHave[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackHavePowerM_f, sMtAfn0dF23_f;

// ת������
eMtErr emtTrans_afn0df23(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F24���¶��ᷴ���޹����������ܡ�����1��M��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F24_BACK_NONE_POWR_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m       sTd_m;                     // �¶���������ʱ��Td_m
    sMtYYMMDDhhmm sTime;                     // �ն˳���ʱ��
    UINT8         ucM;                       // ������M��1��M��12��
    double        dBackNoneT;                // �շ����й��ܵ�����            (+)XXXX.XXXX
    double        dBackNone[1];              // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackNonePowerM, sMtAfn0dF24;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt15_f   sTime;                      // �ն˳���ʱ��
    UINT8        ucM;                        // ������M��1��M��12��
    sMtFmt13_f   dBackNoneT;                 // �շ����й��ܵ�����            (+)XXXX.XXXX
    sMtFmt13_f   dBackNone[1];               // �շ���(1 ~ ucM)�����й������� (+)XXXX.XXXX
 
}sMtBackNonePowerM_f, sMtAfn0dF24_f;

// ת������
eMtErr emtTrans_afn0df24(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F25���ն������ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F25_POWR_FRZE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d     sTd_m;                       // �ն���������ʱ��Td_d
    float       fPowerRateT;                 // ����������й�����         (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateT;             // ����������й����ʷ���ʱ�� (��ʱ��)
    float       fPowerRateA;                 // A������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateA;             // A������й����ʷ���ʱ��    (��ʱ��)
    float       fPowerRateB;                 // B������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateB;             // B������й����ʷ���ʱ��    (��ʱ��)
    float       fPowerRateC;                 // C������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateC;             // C������й����ʷ���ʱ��    (��ʱ��)
    UINT16      usMinutesZeroT;              // �������й�����Ϊ��ʱ��     (����)
    UINT16      usMinutesZeroA;              // A���й�����Ϊ��ʱ��        (����)
    UINT16      usMinutesZeroB;              // B���й�����Ϊ��ʱ��        (����)
    UINT16      usMinutesZeroC;              // C���й�����Ϊ��ʱ��        (����)
  
}sMtPowerFreezeD, sMtAfn0dF25;
    
// ֡��
typedef struct
{   
    sMtTd_d_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt23_f   fPowerRateT;                // ����������й����� (kW) (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateT;            // ����������й����ʷ���ʱ�� (��ʱ��)
    sMtFmt23_f   fPowerRateA;                // A������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateA;            // A������й����ʷ���ʱ��    (��ʱ��)
    sMtFmt23_f   fPowerRateB;                // B������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateB;            // B������й����ʷ���ʱ��    (��ʱ��)
    sMtFmt23_f   fPowerRateC;                // C������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateC;            // C������й����ʷ���ʱ��    (��ʱ��)
    UINT16       usMinutesZeroT;             // �������й�����Ϊ��ʱ��     (����)
    UINT16       usMinutesZeroA;             // A���й�����Ϊ��ʱ��        (����)
    UINT16       usMinutesZeroB;             // B���й�����Ϊ��ʱ��        (����)
    UINT16       usMinutesZeroC;             // C���й�����Ϊ��ʱ��        (����)
   
}sMtPowerFreezeD_f, sMtAfn0dF25_f;

// ת������
eMtErr emtTrans_afn0df25(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F26���ն������ܼ������й��������������ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F26_DMND_FRZE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d     sTd_d;                    // �ն���������ʱ��Td_d
    float       fDemandT;                 // �����й����������         (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandT;             // �����й��������������ʱ�� (��ʱ��)
    float       fDemandA;                 // A���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandA;             // A���й������������ʱ��    (��ʱ��)
    float       fDemandB;                 // B���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandB;             // B���й������������ʱ��    (��ʱ��)
    float       fDemandC;                 // C���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandC;             // C���й������������ʱ��    (��ʱ��)
    
}sMtDemandFreezeD, sMtAfn0dF26;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    sMtFmt23_f   fDemandT;                // �����й���������� (kW) (+)XX.XXXX
    sMtFmt18_f   sTimeDemandT;            // �����й��������������ʱ�� (��ʱ��)
    sMtFmt23_f   fDemandA;                // A���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandA;            // A���й������������ʱ��    (��ʱ��)
    sMtFmt23_f   fDemandB;                // B���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandB;            // B���й������������ʱ��    (��ʱ��)
    sMtFmt23_f   fDemandC;                // C���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandC;            // C���й������������ʱ��    (��ʱ��)
 
}sMtDemandFreezeD_f, sMtAfn0dF26_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df26(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F27���ն����յ�ѹͳ������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F27_VOLT_FRZE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    UINT16 usOverUpUp;                  // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverDownDown;              // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverUp;                    // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOverDown;                  // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOk;                        // ��ѹ�ϸ����ۼ�ʱ��     (����)

}sMtVoltFrzeTime;

typedef struct
{
    float       fMin;                   // ��ѹ��Сֵ           (+)XXX.X  (V)   
    sMtDDHHmm   sTimeMin;               // ��ѹ��Сֵ����ʱ��   (��ʱ��)
    float       fMax;                   // ��ѹ���ֵ           (+)XXX.X  (V)
    sMtDDHHmm   sTimeMax;               // ��ѹ���ֵ����ʱ��   (��ʱ��)

}sMtVoltLimit;

typedef struct
{
    sMtTd_d          sTd_d;              // �ն���������ʱ��Td_d
    sMtVoltFrzeTime  sTimeA;             // A��
    sMtVoltFrzeTime  sTimeB;             // B��
    sMtVoltFrzeTime  sTimeC;             // C��
    sMtVoltLimit     sVoltA;             // A��
    sMtVoltLimit     sVoltB;             // B��
    sMtVoltLimit     sVoltC;             // C��
    float            fAveA;              // A��ƽ����ѹ (+)XXX.X  (V)
    float            fAveB;              // B��ƽ����ѹ (+)XXX.X  (V)
    float            fAveC;              // C��ƽ����ѹ (+)XXX.X  (V)

}sMtVoltFreezeD, sMtAfn0dF27;
    
// ֡��
#pragma pack(1) 
typedef struct
{
    UINT16 usOverUpUp;                  // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverDownDown;              // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverUp;                    // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOverDown;                  // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOk;                        // ��ѹ�ϸ����ۼ�ʱ��     (����)

}sMtVoltFrzeTime_f;

typedef struct
{
    sMtFmt07_f    fMin;                   // ��ѹ��Сֵ         (+)XXX.X  (V)
    sMtFmt18_f    sTimeMin;               // ��ѹ��Сֵ����ʱ�� (��ʱ��)
    sMtFmt07_f    fMax;                   // ��ѹ���ֵ         (+)XXX.X  (V)
    sMtFmt18_f    sTimeMax;               // ��ѹ���ֵ����ʱ�� (��ʱ��)
    
}sMtVoltLimit_f;

typedef struct
{   
    sMtTd_d_f          sTd_d;              // �ն���������ʱ��Td_d
    sMtVoltFrzeTime_f  sTimeA;             // A��
    sMtVoltFrzeTime_f  sTimeB;             // B��
    sMtVoltFrzeTime_f  sTimeC;             // C��
    sMtVoltLimit_f     sVoltA;             // A��
    sMtVoltLimit_f     sVoltB;             // B��
    sMtVoltLimit_f     sVoltC;             // C��
    sMtFmt07_f         fAveA;              // A��ƽ����ѹ      (+)XXX.X  (V)
    sMtFmt07_f         fAveB;              // B��ƽ����ѹ      (+)XXX.X  (V)
    sMtFmt07_f         fAveC;              // C��ƽ����ѹ      (+)XXX.X  (V)
    
}sMtVoltFreezeD_f, sMtAfn0dF27_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df27(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F28���ն����ղ�ƽ���Խ���ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F28_UBLN_OVER_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d     sTd_d;                    // �ն���������ʱ��Td_d
    UINT16      usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16      usCalVolt;                // ��ѹ��ƽ���Խ�����ۼ�ʱ�� (min)
    float       fMaxElec;                 // ������ƽ�����ֵ           (+)XXX.X (%)
    sMtDDHHmm   sTimeMaxElec;             // ������ƽ�����ֵ����ʱ��   (��ʱ��)
    float       fMaxVolt;                 // ��ѹ��ƽ�����ֵ           (+)XXX.X (%)
    sMtDDHHmm   sTimeMaxVolt;             // ��ѹ��ƽ�����ֵ����ʱ��   (��ʱ��)
 
}sMtUblnOverD, sMtAfn0dF28;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                    // �ն���������ʱ��Td_d
    UINT16       usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16       usCalVolt;                // ��ѹ��ƽ���Խ�����ۼ�ʱ�� (min)
    sMtFmt05_f   fMaxElec;                 // ������ƽ�����ֵ
    sMtFmt18_f   sTimeMaxElec;             // ������ƽ�����ֵ����ʱ��
    sMtFmt05_f   fMaxVolt;                 // ��ѹ��ƽ�����ֵ
    sMtFmt18_f   sTimeMaxVolt;             // ��ѹ��ƽ�����ֵ����ʱ��
}sMtUblnOverD_f, sMtAfn0dF28_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df28(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F29���ն����յ���Խ������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F29_ELEC_OVER_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d      sTd_d;                    // �ն���������ʱ��Td_d
    UINT16       usOverUpUpA;              // A�����Խ�������ۼ�ʱ��
    UINT16       usOverUpA;                // A�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpB;              // B�����Խ�������ۼ�ʱ��
    UINT16       usOverUpB;                // B�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpC;              // C�����Խ�������ۼ�ʱ��
    UINT16       usOverUpC;                // C�����Խ�����ۼ�ʱ��
    UINT16       usOverUpZ;                // �������Խ�����ۼ�ʱ��
    float        fMaxA;                    // A��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxA;               // A��������ֵ����ʱ��
    float        fMaxB;                    // B��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxB;               // B��������ֵ����ʱ��
    float        fMaxC;                    // C��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxC;               // C��������ֵ����ʱ��
    float        fMaxZ;                    // ����������ֵ        (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxZ;               // ����������ֵ����ʱ��
    
}sMtElecOverD, sMtAfn0dF29;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                    // �ն���������ʱ��Td_d
    UINT16       usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16       usOverUpUpA;              // A�����Խ�������ۼ�ʱ��
    UINT16       usOverUpA;                // A�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpB;              // B�����Խ�������ۼ�ʱ��
    UINT16       usOverUpB;                // B�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpC;              // C�����Խ�������ۼ�ʱ��
    UINT16       usOverUpC;                // C�����Խ�����ۼ�ʱ��
    UINT16       usOverUpZ;                // �������Խ�����ۼ�ʱ��
    sMtFmt25_f   fMaxA;                    // A��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxA;               // A��������ֵ����ʱ��
    sMtFmt25_f   fMaxB;                    // B��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxB;               // B��������ֵ����ʱ��
    sMtFmt25_f   fMaxC;                    // C��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxC;               // C��������ֵ����ʱ��
    sMtFmt25_f   fMaxZ;                    // ����������ֵ        (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxZ;               // ����������ֵ����ʱ��
    
}sMtElecOverD_f, sMtAfn0dF29_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df29(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F30���ն��������ڹ���Խ���ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F30_POWR_RATE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d      sTd_d;                   // �ն���������ʱ��Td_d
    UINT16       usOverUpUp;              // ���ڹ���Խ�������ۼ�ʱ��
    UINT16       usOverUp;                // ���ڹ���Խ�����ۼ�ʱ��
   
    
}sMtSPowerRateD, sMtAfn0dF30;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    UINT16       usOverUpUp;              // ���ڹ���Խ�������ۼ�ʱ��
    UINT16       usOverUp;                // ���ڹ���Խ�����ۼ�ʱ��
  
}sMtSPowerRateD_f, sMtAfn0dF30_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df30(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F31���ո�����ͳ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F31_LOAD_RATE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d      sTd_d;                   // �ն���������ʱ��Td_d
    float        fMax;                    // ���������ֵ         (+/-)XXX.X (%) 
    sMtDDHHmm    sTimeMax;                // ���������ֵ����ʱ�� (��ʱ��)   
    float        fMin;                    // ���������ֵ         (+/-)XXX.X (%) 
    sMtDDHHmm    sTimeMin;                // ��������Сֵ����ʱ�� (��ʱ��)
    
}sMtLoadRateD, sMtAfn0dF31;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    sMtFmt05_f   fMax;                    // ���������ֵ         (%) 
    sMtFmt18_f   sTimeMax;                // ���������ֵ����ʱ�� (��ʱ��)   
    sMtFmt05_f   fMin;                    // ���������ֵ         (%)
    sMtFmt18_f   sTimeMin;                // ��������Сֵ����ʱ�� (��ʱ��)
  
}sMtLoadRateD_f, sMtAfn0dF31_f;

#pragma pack() 

// ת������
eMtErr emtTrans_afn0df31(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F32���ն�����ܱ��������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F32_METR_DROP_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d       sTd_d;                   // �ն���������ʱ��Td_d
    sMtYYMMDDhhmm sTime;                   // �ն˳���ʱ��
    UINT16        usDropT;                 // �ܶ������    (+)XXXX
    UINT16        usDropA;                 // A��������   (+)XXXX
    UINT16        usDropB;                 // B��������   (+)XXXX
    UINT16        usDropC;                 // C��������   (+)XXXX
    UINT32        ulMinutesT;              // �����ۼ�ʱ��  (+)XXXXXX (����)
    UINT32        ulMinutesA;              // A�����ۼ�ʱ�� (+)XXXXXX (����)
    UINT32        ulMinutesB;              // B�����ۼ�ʱ�� (+)XXXXXX (����)
    UINT32        ulMinutesC;              // C�����ۼ�ʱ�� (+)XXXXXX (����)
    sMtMMDDHHmm   sTimeStart;              // ���һ�ζ�����ʼʱ�� (��ʱ����)
    sMtMMDDHHmm   sTimeStartA;             // A�����������ʼʱ��  (��ʱ����)
    sMtMMDDHHmm   sTimeStartB;             // B�����������ʼʱ��  (��ʱ����)
    sMtMMDDHHmm   sTimeStartC;             // C�����������ʼʱ��  (��ʱ����)
    sMtMMDDHHmm   sTimeEnd;                // ���һ�ζ������ʱ�� (��ʱ����)
    sMtMMDDHHmm   sTimeEndA;               // A������������ʱ��  (��ʱ����)
    sMtMMDDHHmm   sTimeEndB;               // B������������ʱ��  (��ʱ����)
    sMtMMDDHHmm   sTimeEndC;               // C������������ʱ��  (��ʱ����)
    
}sMtMeterDropD, sMtAfn0dF32;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    sMtFmt15_f   sTime;                   // �ն˳���ʱ��
    sMtFmt08_f   usDropT;                 // �ܶ������    (+)XXXX
    sMtFmt08_f   usDropA;                 // A��������   (+)XXXX
    sMtFmt08_f   usDropB;                 // B��������   (+)XXXX
    sMtFmt08_f   usDropC;                 // C��������   (+)XXXX
    sMtFmt10_f   ulMinutesT;              // �����ۼ�ʱ��  (+)XXXXXX (����)
    sMtFmt10_f   ulMinutesA;              // A�����ۼ�ʱ�� (+)XXXXXX (����)
    sMtFmt10_f   ulMinutesB;              // B�����ۼ�ʱ�� (+)XXXXXX (����)
    sMtFmt10_f   ulMinutesC;              // C�����ۼ�ʱ�� (+)XXXXXX (����)
    sMtFmt17_f   sTimeStart;              // ���һ�ζ�����ʼʱ�� (��ʱ����)
    sMtFmt17_f   sTimeStartA;             // A�����������ʼʱ��  (��ʱ����)
    sMtFmt17_f   sTimeStartB;             // B�����������ʼʱ��  (��ʱ����)
    sMtFmt17_f   sTimeStartC;             // C�����������ʼʱ��  (��ʱ����)
    sMtFmt17_f   sTimeEnd;                // ���һ�ζ������ʱ�� (��ʱ����)
    sMtFmt17_f   sTimeEndA;               // A������������ʱ��  (��ʱ����)
    sMtFmt17_f   sTimeEndB;               // B������������ʱ��  (��ʱ����)
    sMtFmt17_f   sTimeEndC;               // C������������ʱ��  (��ʱ����)

}sMtMeterDropD_f, sMtAfn0dF32_f;

#pragma pack() 

// ת������
eMtErr emtTrans_afn0df32(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F33���¶������ܼ���������й����ʼ�����ʱ�䡢�й�����Ϊ��ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F33_POWR_FRZE_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m     sTd_m;                       // �¶���������ʱ��Td_m
    float       fPowerRateT;                 // ����������й�����         (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateT;             // ����������й����ʷ���ʱ�� (��ʱ��)
    float       fPowerRateA;                 // A������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateA;             // A������й����ʷ���ʱ��    (��ʱ��)
    float       fPowerRateB;                 // B������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateB;             // B������й����ʷ���ʱ��    (��ʱ��)
    float       fPowerRateC;                 // C������й�����            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimePowerRateC;             // C������й����ʷ���ʱ��    (��ʱ��)
    UINT16      usMinutesZeroT;              // �������й�����Ϊ��ʱ��     (����)
    UINT16      usMinutesZeroA;              // A���й�����Ϊ��ʱ��        (����)
    UINT16      usMinutesZeroB;              // B���й�����Ϊ��ʱ��        (����)
    UINT16      usMinutesZeroC;              // C���й�����Ϊ��ʱ��        (����)
  
}sMtPowerFreezeM, sMtAfn0dF33;
    
// ֡��
typedef struct
{   
    sMtTd_m_f    sTd_m;                      // �¶���������ʱ��Td_m
    sMtFmt23_f   fPowerRateT;                // ����������й����� (kW) (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateT;            // ����������й����ʷ���ʱ�� (��ʱ��)
    sMtFmt23_f   fPowerRateA;                // A������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateA;            // A������й����ʷ���ʱ��    (��ʱ��)
    sMtFmt23_f   fPowerRateB;                // B������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateB;            // B������й����ʷ���ʱ��    (��ʱ��)
    sMtFmt23_f   fPowerRateC;                // C������й�����            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimePowerRateC;            // C������й����ʷ���ʱ��    (��ʱ��)
    UINT16       usMinutesZeroT;             // �������й�����Ϊ��ʱ��     (����)
    UINT16       usMinutesZeroA;             // A���й�����Ϊ��ʱ��        (����)
    UINT16       usMinutesZeroB;             // B���й�����Ϊ��ʱ��        (����)
    UINT16       usMinutesZeroC;             // C���й�����Ϊ��ʱ��        (����)
   
}sMtPowerFreezeM_f, sMtAfn0dF33_f;

// ת������
eMtErr emtTrans_afn0df33(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F34���¶������ܼ������й��������������ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F34_DMND_FRZE_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m     sTd_m;                    // �¶���������ʱ��Td_m
    float       fDemandT;                 // �����й����������         (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandT;             // �����й��������������ʱ�� (��ʱ��)
    float       fDemandA;                 // A���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandA;             // A���й������������ʱ��    (��ʱ��)
    float       fDemandB;                 // B���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandB;             // B���й������������ʱ��    (��ʱ��)
    float       fDemandC;                 // C���й��������            (kW)      (+)XX.XXXX
    sMtDDHHmm   sTimeDemandC;             // C���й������������ʱ��    (��ʱ��)
    
}sMtDemandFreezeM, sMtAfn0dF34;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                   // �¶���������ʱ��Td_m
    sMtFmt23_f   fDemandT;                // �����й���������� (kW) (+)XX.XXXX
    sMtFmt18_f   sTimeDemandT;            // �����й��������������ʱ�� (��ʱ��)
    sMtFmt23_f   fDemandA;                // A���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandA;            // A���й������������ʱ��    (��ʱ��)
    sMtFmt23_f   fDemandB;                // B���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandB;            // B���й������������ʱ��    (��ʱ��)
    sMtFmt23_f   fDemandC;                // C���й��������            (kW)      (+)XX.XXXX
    sMtFmt18_f   sTimeDemandC;            // C���й������������ʱ��    (��ʱ��)
 
}sMtDemandFreezeM_f, sMtAfn0dF34_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df34(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F35���¶����µ�ѹͳ������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F35_VOLT_FRZE_M
 * PN ���� : �������
 *
{*///
// �û���
/*
typedef struct
{
    UINT16 usOverUpUp;                  // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverDownDown;              // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverUp;                    // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOverDown;                  // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOk;                        // ��ѹ�ϸ����ۼ�ʱ��     (����)

}sMtVoltFrzeTime;

typedef struct
{
    float       fMin;                   // ��ѹ��Сֵ           (+)XXX.X  (V)   
    sMtDDHHmm   sTimeMin;               // ��ѹ��Сֵ����ʱ��   (��ʱ��)
    float       fMax;                   // ��ѹ���ֵ           (+)XXX.X  (V)
    sMtDDHHmm   sTimeMax;               // ��ѹ���ֵ����ʱ��   (��ʱ��)

}sMtVoltLimit;
*/
typedef struct
{
    sMtTd_m          sTd_m;              // �¶���������ʱ��Td_m
    sMtVoltFrzeTime  sTimeA;             // A��
    sMtVoltFrzeTime  sTimeB;             // B��
    sMtVoltFrzeTime  sTimeC;             // C��
    sMtVoltLimit     sVoltA;             // A��
    sMtVoltLimit     sVoltB;             // B��
    sMtVoltLimit     sVoltC;             // C��
    float            fAveA;              // A��ƽ����ѹ (+)XXX.X  (V)
    float            fAveB;              // B��ƽ����ѹ (+)XXX.X  (V)
    float            fAveC;              // C��ƽ����ѹ (+)XXX.X  (V)

}sMtVoltFreezeM, sMtAfn0dF35;
    
// ֡��
#pragma pack(1) 
/*
typedef struct
{
    UINT16 usOverUpUp;                  // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverDownDown;              // ��ѹԽ���������ۼ�ʱ�� (����)
    UINT16 usOverUp;                    // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOverDown;                  // ��ѹԽ�������ۼ�ʱ��   (����)
    UINT16 usOk;                        // ��ѹ�ϸ����ۼ�ʱ��     (����)

}sMtVoltFrzeTime_f;

typedef struct
{
    sMtFmt07_f    fMin;                   // ��ѹ��Сֵ         (+)XXX.X  (V)
    sMtFmt18_f    sTimeMin;               // ��ѹ��Сֵ����ʱ�� (��ʱ��)
    sMtFmt07_f    fMax;                   // ��ѹ���ֵ         (+)XXX.X  (V)
    sMtFmt18_f    sTimeMax;               // ��ѹ���ֵ����ʱ�� (��ʱ��)
    
}sMtVoltLimit_f;

*/
typedef struct
{   
    sMtTd_m_f          sTd_m;              // �¶���������ʱ��Td_m
    sMtVoltFrzeTime_f  sTimeA;             // A��
    sMtVoltFrzeTime_f  sTimeB;             // B��
    sMtVoltFrzeTime_f  sTimeC;             // C��
    sMtVoltLimit_f     sVoltA;             // A��
    sMtVoltLimit_f     sVoltB;             // B��
    sMtVoltLimit_f     sVoltC;             // C��
    sMtFmt07_f         fAveA;              // A��ƽ����ѹ      (+)XXX.X  (V)
    sMtFmt07_f         fAveB;              // B��ƽ����ѹ      (+)XXX.X  (V)
    sMtFmt07_f         fAveC;              // C��ƽ����ѹ      (+)XXX.X  (V)
    
}sMtVoltFreezeM_f, sMtAfn0dF35_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df35(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F36���¶����²�ƽ���Խ���ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F36_UBLN_OVER_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m     sTd_m;                    // �¶���������ʱ��Td_m
    UINT16      usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16      usCalVolt;                // ��ѹ��ƽ���Խ�����ۼ�ʱ�� (min)
    float       fMaxElec;                 // ������ƽ�����ֵ           (+)XXX.X (%)
    sMtMMDDHHmm sTimeMaxElec;             // ������ƽ�����ֵ����ʱ��   (��ʱ����)
    float       fMaxVolt;                 // ��ѹ��ƽ�����ֵ           (+)XXX.X (%)
    sMtMMDDHHmm sTimeMaxVolt;             // ��ѹ��ƽ�����ֵ����ʱ��   (��ʱ����)
 
}sMtUblnOverM, sMtAfn0dF36;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                    // �¶���������ʱ��Td_m
    UINT16       usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16       usCalVolt;                // ��ѹ��ƽ���Խ�����ۼ�ʱ�� (min)
    sMtFmt05_f   fMaxElec;                 // ������ƽ�����ֵ
    sMtFmt17_f   sTimeMaxElec;             // ������ƽ�����ֵ����ʱ��
    sMtFmt05_f   fMaxVolt;                 // ��ѹ��ƽ�����ֵ
    sMtFmt17_f   sTimeMaxVolt;             // ��ѹ��ƽ�����ֵ����ʱ��
    
}sMtUblnOverM_f, sMtAfn0dF36_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df36(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F37���¶����µ���Խ������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F37_ELEC_OVER_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m      sTd_m;                    // �¶���������ʱ��Td_m
    UINT16       usOverUpUpA;              // A�����Խ�������ۼ�ʱ��
    UINT16       usOverUpA;                // A�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpB;              // B�����Խ�������ۼ�ʱ��
    UINT16       usOverUpB;                // B�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpC;              // C�����Խ�������ۼ�ʱ��
    UINT16       usOverUpC;                // C�����Խ�����ۼ�ʱ��
    UINT16       usOverUpZ;                // �������Խ�����ۼ�ʱ��
    float        fMaxA;                    // A��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxA;               // A��������ֵ����ʱ��
    float        fMaxB;                    // B��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxB;               // B��������ֵ����ʱ��
    float        fMaxC;                    // C��������ֵ         (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxC;               // C��������ֵ����ʱ��
    float        fMaxZ;                    // ����������ֵ        (+)XXX.XXX (A)
    sMtDDHHmm    sTimefMaxZ;               // ����������ֵ����ʱ��
    
}sMtElecOverM, sMtAfn0dF37;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                    // �¶���������ʱ��Td_m
    UINT16       usCalElec;                // ������ƽ���Խ�����ۼ�ʱ�� (min)
    UINT16       usOverUpUpA;              // A�����Խ�������ۼ�ʱ��
    UINT16       usOverUpA;                // A�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpB;              // B�����Խ�������ۼ�ʱ��
    UINT16       usOverUpB;                // B�����Խ�����ۼ�ʱ��
    UINT16       usOverUpUpC;              // C�����Խ�������ۼ�ʱ��
    UINT16       usOverUpC;                // C�����Խ�����ۼ�ʱ��
    UINT16       usOverUpZ;                // �������Խ�����ۼ�ʱ��
    sMtFmt25_f   fMaxA;                    // A��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxA;               // A��������ֵ����ʱ��
    sMtFmt25_f   fMaxB;                    // B��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxB;               // B��������ֵ����ʱ��
    sMtFmt25_f   fMaxC;                    // C��������ֵ         (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxC;               // C��������ֵ����ʱ��
    sMtFmt25_f   fMaxZ;                    // ����������ֵ        (+)XXX.XXX (A)
    sMtFmt18_f   sTimefMaxZ;               // ����������ֵ����ʱ��
    
}sMtElecOverM_f, sMtAfn0dF37_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df37(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F38���¶��������ڹ���Խ���ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F38_POWR_RATE_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m      sTd_m;                   // �¶���������ʱ��Td_m
    UINT16       usOverUpUp;              // ���ڹ���Խ�������ۼ�ʱ��
    UINT16       usOverUp;                // ���ڹ���Խ�����ۼ�ʱ��
    
}sMtSPowerRateM, sMtAfn0dF38;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                   // �¶���������ʱ��Td_m
    UINT16       usOverUpUp;              // ���ڹ���Խ�������ۼ�ʱ��
    UINT16       usOverUp;                // ���ڹ���Խ�����ۼ�ʱ��
  
}sMtSPowerRateM_f, sMtAfn0dF38_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df38(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F39���¸�����ͳ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F39_LOAD_RATE_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m      sTd_m;                   // �¶���������ʱ��Td_m
    float        fMax;                    // ���������ֵ         (+/-)XXX.X (%) 
    sMtDDHHmm    sTimeMax;                // ���������ֵ����ʱ�� (��ʱ��)   
    float        fMin;                    // ���������ֵ         (+/-)XXX.X (%) 
    sMtDDHHmm    sTimeMin;                // ��������Сֵ����ʱ�� (��ʱ��)
    
}sMtLoadRateM, sMtAfn0dF39;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                   // �¶���������ʱ��Td_m
    sMtFmt05_f   fMax;                    // ���������ֵ         (%) 
    sMtFmt18_f   sTimeMax;                // ���������ֵ����ʱ�� (��ʱ��)   
    sMtFmt05_f   fMin;                    // ���������ֵ         (%)
    sMtFmt18_f   sTimeMin;                // ��������Сֵ����ʱ�� (��ʱ��)
  
}sMtLoadRateM_f, sMtAfn0dF39_f;

#pragma pack() 

// ת������
eMtErr emtTrans_afn0df39(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F41���ն���������ۼ�Ͷ��ʱ��ʹ���
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F41_CAPA_TIME_D
 * PN ���� : �������
 *
{*///
// �û���
#define MT_CAPA_TEAM       (9)            // Ͷ�����������
typedef struct
{
    sMtTd_d      sTd_d;                   // �ն���������ʱ��Td_d
    UINT32       ulSeconds[MT_CAPA_TEAM]; // ��(1~9)��������ۼ�Ͷ��ʱ�� (��)
    UINT32       ulTimes[MT_CAPA_TEAM];   // ��(1~9)��������ۼ�Ͷ����� (��)
    
}sMtCapaTimeD, sMtAfn0dF41;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    UINT32       ulSeconds[MT_CAPA_TEAM]; // ��(1~9)��������ۼ�Ͷ��ʱ�� (��)
    UINT32       ulTimes[MT_CAPA_TEAM];   // ��(1~9)��������ۼ�Ͷ����� (��)
    
}sMtCapaTimeD_f, sMtAfn0dF41_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df41(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F42���ն����ա��µ������ۼƲ������޹�������
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F42_CAPA_NONE_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d      sTd_d;                   // �ն���������ʱ��Td_d
    double       dPowerD;                 // �ղ������޹�������   (+)XXXX.XXXX (kvarh)
    double       dPowerM;                 // �²������޹�������   (+)XXXX.XXXX (kvarh)
    
}sMtCapaNoneD, sMtAfn0dF42;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    sMtFmt13_f   dPowerD;                 // �ղ������޹�������
    sMtFmt13_f   dPowerM;                 // �²������޹�������
 
}sMtCapaNoneD_f, sMtAfn0dF42_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df42(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F43���ն����չ������������ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F43_FACT_TIME_D
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_d      sTd_d;                   // �ն���������ʱ��Td_d
    UINT16       usTime_1;                // ����1�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_2;                // ����2�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_3;                // ����3�ۼ�ʱ�䣨������������ֵ1��(min)
    
}sMtFactTimeD, sMtAfn0dF43;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_d_f    sTd_d;                   // �ն���������ʱ��Td_d
    UINT16       usTime_1;                // ����1�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_2;                // ����2�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_3;                // ����3�ۼ�ʱ�䣨������������ֵ1��(min)
 
}sMtFactTimeD_f, sMtAfn0dF43_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df43(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: F44���¶����¹������������ۼ�ʱ��
 * ��ӦAFN : AFN_0D_ASK2
 * ��ӦCMD : CMD_AFN_D_F44_FACT_TIME_M
 * PN ���� : �������
 *
{*///
// �û���
typedef struct
{
    sMtTd_m      sTd_m;                   // �¶���������ʱ��Td_m
    UINT16       usTime_1;                // ����1�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_2;                // ����2�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_3;                // ����3�ۼ�ʱ�䣨������������ֵ1��(min)
    
}sMtFactTimeM, sMtAfn0dF44;
    
// ֡��
#pragma pack(1) 
typedef struct
{   
    sMtTd_m_f    sTd_m;                   // �¶���������ʱ��Td_m
    UINT16       usTime_1;                // ����1�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_2;                // ����2�ۼ�ʱ�䣨������������ֵ1��(min)
    UINT16       usTime_3;                // ����3�ۼ�ʱ�䣨������������ֵ1��(min)
 
}sMtFactTimeM_f, sMtAfn0dF44_f;
#pragma pack() 

// ת������
eMtErr emtTrans_afn0df44(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}



///*}



/*******************************************
 * ���Ͷ���: ���¼���¼�����ݸ�ʽ
 * 
{*///

/*******************************************
 * ���ݽṹ: ERC1�����ݳ�ʼ���Ͱ汾�����¼
 * ��Ӧ����: MT_ERC_1_INIT
 *
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_1_INIT
    sMtYYMMDDhhmm  sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    BOOL           bInit;          // ��"��"���ն˽��в�������������ʼ������¼��ʼ��ʱ�䣻��"��"���޳�ʼ������
    BOOL           bModify;        // ��"��"���ն˰汾�������¼���ʱ��ͱ��ǰ��汾�ţ���"��"���汾δ���
    UINT8          ucPreVerson[4]; // ���ǰ����汾��
    UINT8          ucNewVerson[4]; // ���������汾��
}sMtRec1, sMtRecInit;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 1
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucFlag;         // �¼���־
    UINT8          ucPreVerson[4]; // ���ǰ����汾��
    UINT8          ucNewVerson[4]; // ���������汾��

}sMtRec1_f, sMtRecInit_f;

// ת������
eMtErr emtTrans_rec_1(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC2��������ʧ��¼
 * ��Ӧ����: MT_ERC_2_PARA_LOSS
 *
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_2_PARA_LOSS
    sMtYYMMDDhhmm  sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    BOOL           bTmlParaLoss;   // ��"1"���ն˲�����ʧ����"0"������δ��ʧ��
    BOOL           bMpParaLoss;    // ��"1"�������������ʧ����"0"������δ��ʧ��
   
}sMtRec2, sMtRecParaLoss;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 2
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucFlag;         // �¼���־

}sMtRec2_f, sMtRecParaLoss_f;

// ת������
eMtErr emtTrans_rec_2(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);

///*}

/*******************************************
 * ���ݽṹ: ERC3�����������¼
 * ��Ӧ����: MT_ERC_3_PARA_MODIFY
 * 
{*///
typedef struct
{
    eMtCmd eCmd;                  // ������: �ǲ���ֻ�����ò�������ЩCMD ����֧����������?
    UINT16 ucPn;

}sMtRec2One;

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_3_PARA_MODIFY
    sMtYYMMDDhhmm  sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucMstAddr;      // ����վ��ַ
    UINT8          ucNum;          // ������������ݵ�Ԫ��ʶ����
    sMtRec2One     sDIndex[1];     // ����������ݵ�Ԫ��ʶ1 ~ i (ucNum ��)
   
}sMtRec3, sMtRecParaModify;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 3
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucMstAddr;      // ����վ��ַ
    sMtDaDt        sDaDt[1];       // ����������ݵ�Ԫ��ʶ1 ~ i (ucLe ������)
}sMtRec3_f, sMtRecParaModify_f;

// ת������
eMtErr emtTrans_rec_3(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);

///*}

/*******************************************
 * ���ݽṹ: ERC4��״̬����λ��¼
 * ��Ӧ����: MT_ERC_4_STATE_CHANGE
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_4_STATE_CHANGE
    sMtYYMMDDhhmm  sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucMstAddr;      // ����վ��ַ
    BOOL           bIsChange[8];   // ״̬��λ ��"1"��������λ����"0"���ޱ�λ������
    BOOL           bChange[8];     // ��λ��״̬
    
}sMtRec4, sMtRecStateChange;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 4
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          bIsChange;      // ״̬��λ ��"1"��������λ����"0"���ޱ�λ������
    UINT8          bChange;        // ��λ��״̬
}sMtRec4_f, sMtRecStateChange_f;

// ת������
eMtErr emtTrans_rec_4(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC5��ң����բ��¼
 * ��Ӧ����: MT_ERC_5_REMOTE_SWITCH
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_5_REMOTE_SWITCH
    sMtYYMMDDhhmm  sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucMstAddr;      // ����վ��ַ
    BOOL           bIsOff[8];      // ��բ�ִΣ�0��7��˳���λ��ʾ1��8�������ִΣ���"��"�����ִ���բ����"��"�����ִ�δ��բ��
    float          fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    float          fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    }sMtRec5, sMtRecRemoteSwitch;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 5
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          bIsOff;         // ��λ��״̬
    sMtFmt02_f     fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    sMtFmt02_f     fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    
}sMtRec5_f, sMtRecRemoteSwitch_f;

// ת������
eMtErr emtTrans_rec_5(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC6��������բ��¼
 * ��Ӧ����: MT_ERC_6_PCTRL_SWITCH
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_6_PCTRL_SWITCH
    sMtYYMMDDhhmm  sTime;          // ��բʱ�䣺��ʱ������
    UINT8          ucPn;           //  pn���ܼ���ţ�
    BOOL           bIsOff[8];      // ��բ�ִΣ�0��7��˳���λ��ʾ1��8�������ִΣ���"��"�����ִ���բ����"��"�����ִ�δ��բ��
    BOOL           bPeriod;        // ʱ�ο�      �Ƿ���Ч
    BOOL           bFactoryHolidy; // ���ݿ�      �Ƿ���Ч
    BOOL           bShutOut;       // Ӫҵ��ͣ��  �Ƿ���Ч
    BOOL           bDownGo;        // ��ǰ�����¸���
    float          fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    float          fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    float          fPowerFix;      // ��բʱ���ʶ�ֵ
    
}sMtRec6, sMtRecPCtrlSwitch;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 5
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucPn;           //  pn���ܼ���ţ�
    UINT8          ucNum;          //  ��բ�ִ�
    UINT8          ucType;         //  �������
    
    sMtFmt02_f     fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    sMtFmt02_f     fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    sMtFmt02_f     fPowerFix;      // ��բʱ���ʶ�ֵ
    
}sMtRec6_f, sMtRecPCtrlSwitch_f;

// ת������
eMtErr emtTrans_rec_6(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC7�������բ��¼
 * ��Ӧ����: MT_ERC_7_ECTRL_SWITCH
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_7_ECTRL_SWITCH
    sMtYYMMDDhhmm  sTime;          // ��բʱ�䣺��ʱ������
    UINT8          ucPn;           //  pn���ܼ���ţ�
    BOOL           bIsOff[8];      // ��բ�ִΣ�0��7��˳���λ��ʾ1��8�������ִΣ���"��"�����ִ���բ����"��"�����ִ�δ��բ��
    BOOL           bPeriod;        // ʱ�ο�      �Ƿ���Ч
    BOOL           bFactoryHolidy; // ���ݿ�      �Ƿ���Ч
    BOOL           bShutOut;       // Ӫҵ��ͣ��  �Ƿ���Ч
    BOOL           bDownGo;        // ��ǰ�����¸���
    float          fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    float          fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    float          fPowerFix;      // ��բʱ���ʶ�ֵ
    
}sMtRec7, sMtRecECtrlSwitch;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 7
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucPn;           //  pn���ܼ���ţ�
    UINT8          ucNum;          //  ��բ�ִ�
    UINT8          ucType;         //  �������
    
    sMtFmt02_f     fPower;         // ��բʱ���ʣ��ܼӹ��ʣ�
    sMtFmt02_f     fPower2m;       // ��բ��2���ӵĹ��ʣ��ܼӹ��ʣ�
    sMtFmt02_f     fPowerFix;      // ��բʱ���ʶ�ֵ
    
}sMtRec7_f, sMtRecECtrlSwitch_f;

// ת������
eMtErr emtTrans_rec_7(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC8�����ܱ�������
 * ��Ӧ����: MT_ERC_8_METER_CHANGE
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_8_METER_CHANGE
    sMtYYMMDDhhmm  sTime;          // ��բʱ�䣺��ʱ������
    UINT8          ucPn;           // pn���ܼ���ţ�
    BOOL           bPayRate;       // ��"1"�����ܱ����ʱ�α仯����"0"��������ʱ���ޱ����
    BOOL           bPramTime;      // ��"1"�����ܱ���ʱ����ģ���"0"�����ʱ��δ���ģ�
    BOOL           bReadMeter;     // ��"1"�����ܱ����ո��ģ�  ��"0"��������δ���ģ�
    BOOL           bPulse;         // ��"1"�����ܱ����峣�����ģ���"0"�����峣��δ���ģ�
    BOOL           bInduct;        // ��"1"�����ܱ�Ļ��������ʸ��ģ���"0"������������δ���ģ�
    BOOL           bDemand;        // ��"1"�����ܱ�����������㣬��"0"���������δ�����㣻
}sMtRec8, sMtRecMeterChange;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 8
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ��ʼ��/�汾���ʱ�䣺��ʱ������
    UINT8          ucPn;           // pn���ܼ���ţ�
    UINT8          ucFlag;         // �����־
    
}sMtRec8_f, sMtRecMeterChange_f;

// ת������
eMtErr emtTrans_rec_8(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC9��������·�쳣
 * ��Ӧ����: MT_ERC_9_ELEC_EXCP
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_9_ELEC_EXCP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec9, sMtRecElecExcp;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 9
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec9_f, sMtRecElecExcp_f;

// ת������
eMtErr emtTrans_rec_9(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC10����ѹ��·�쳣
 * ��Ӧ����: MT_ERC_10_VOLT_EXCP
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_10_VOLT_EXCP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec10, sMtRecVoltExcp;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 10
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec10_f, sMtRecVoltExcp_f;

// ת������
eMtErr emtTrans_rec_10(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC11�������쳣
 * ��Ӧ����: MT_ERC_11_PHASE_EXCP
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_9_ELEC_EXCP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec11, sMtRecPhaseExcp;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 9
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec11_f, sMtRecPhaseExcp_f;

// ת������
eMtErr emtTrans_rec_11(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC12�����ܱ�ʱ�䳬��
 * ��Ӧ����: MT_ERC_12_METER_TIME
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_9_ELEC_EXCP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec12, sMtRecMeterTime;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 9
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec12_f, sMtRecMeterTime_f;

// ת������
eMtErr emtTrans_rec_12(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC13����������Ϣ
 * ��Ӧ����: MT_ERC_13_METER_FAULT
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_13_METER_FAULT
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec13, sMtRecMeterFault;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 13
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec13_f, sMtRecMeterFault_f;

// ת������
eMtErr emtTrans_rec_13(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC14���ն�ͣ/�ϵ��¼�
 * ��Ӧ����: MT_ERC_14_TML_ON_OFF
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_14_TML_ON_OFF
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec14, sMtRecTmlOnOff;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 14
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec14_f, sMtRecTmlOnOff_f;

// ת������
eMtErr emtTrans_rec_14(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC15��г��Խ�޸澯
 * ��Ӧ����: MT_ERC_15_HARM_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_15_HARM_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec15, sMtRecHarmOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 15
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec15_f, sMtRecHarmOver_f;

// ת������
eMtErr emtTrans_rec_15(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC16��ֱ��ģ����Խ�޼�¼
 * ��Ӧ����: MT_ERC_16_DC_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_16_DC_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec16, sMtRecDcOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 16
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec16_f, sMtRecDcOver_F;

// ת������
eMtErr emtTrans_rec_16(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC17����ѹ/������ƽ���Խ�޼�¼
 * ��Ӧ����: MT_ERC_17_UNBL_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_17_UNBL_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec17, sMtRecUnblOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 17
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec17_f, sMtRecUnblOver_f;

// ת������
eMtErr emtTrans_rec_17(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC18��������Ͷ��������¼
 * ��Ӧ����: MT_ERC_18_CAPA_LOCK
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_18_CAPA_LOCK
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec18, sMtRecCapaLock;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 18
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec18_f, sMtRecCapaLock_f;

// ת������
eMtErr emtTrans_rec_18(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC19������������ü�¼
 * ��Ӧ����: MT_ERC_19_BUY_PARA
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_19_BUY_PARA
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec19, sMtRecBuyPara;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 19
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec19_f, sMtRecBuyPara_f;

// ת������
eMtErr emtTrans_rec_19(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC20����Ϣ��֤�����¼
 * ��Ӧ����: MT_ERC_20_AUTH_ERROR
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_20_AUTH_ERROR
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec20, sMtRecAuthError;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 20
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec20_f, sMtRecAuthError_f;

// ת������
eMtErr emtTrans_rec_20(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC21���ն˹��ϼ�¼
 * ��Ӧ����: MT_ERC_21_TML_FAULT
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_21_TML_FAULT
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec21, sMtRecTmlFault;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 21
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec21_f, sMtRecTmlFault_f;

// ת������
eMtErr emtTrans_rec_21(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC22���й��ܵ������Խ���¼���¼
 * ��Ӧ����: MT_ERC_22_HAVE_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_22_HAVE_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec22, sMtRecHaveOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 22
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec22_f, sMtRecHaveOver_f;

// ת������
eMtErr emtTrans_rec_22(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC23����ظ澯�¼���¼
 * ��Ӧ����: MT_ERC_23_ECTRL_WARN
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_23_ECTRL_WARN
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec23, sMtRecECtrlWarn;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 23
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec23_f, sMtRecECtrlWarn_f;

// ת������
eMtErr emtTrans_rec_23(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC24����ѹԽ�޼�¼
 * ��Ӧ����: MT_ERC_24_VOLT_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_24_VOLT_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec24, sMtRecVoltOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 24
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec24_f, sMtRecVoltOver_f;

// ת������
eMtErr emtTrans_rec_24(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC25������Խ�޼�¼
 * ��Ӧ����: MT_ERC_25_ELEC_OVER
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_25_ELEC_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec25, sMtRecElecOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 25
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec25_f, sMtRecElecOver_f;

// ת������
eMtErr emtTrans_rec_25(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC26�����ڹ���Խ�޼�¼
 * ��Ӧ����: MT_ERC_26_SP_OVER
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_26_SP_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec26, sMtRecSpOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 26
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
}sMtRec26_f, sMtRecSpOver_f;

// ת������
eMtErr emtTrans_rec_26(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC27�����ܱ�ʾ���½���¼
 * ��Ӧ����: MT_ERC_27_POWER_DOWN
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_27_POWER_DOWN
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec27, sMtRecPowerDown;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 27
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec27_f, sMtRecPowerDown_F;

// ת������
eMtErr emtTrans_rec_27(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC28�������������¼
 * ��Ӧ����: MT_ERC_28_POWER_OVER
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_28_POWER_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec28, sMtRecPowerOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 28
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec28_f, sMtRecPowerOver_f;

// ת������
eMtErr emtTrans_rec_28(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC29�����ܱ���߼�¼
 * ��Ӧ����: MT_ERC_29_METER_FLY
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_29_METER_FLY
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec29, sMtRecMeterFly;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 29
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec29_f, sMtRecMeterFly_f;

// ת������
eMtErr emtTrans_rec_29(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC30�����ܱ�ͣ�߼�¼
 * ��Ӧ����: MT_ERC_30_METER_STOP
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_30_METER_STOP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec30, sMtRecMeterStop;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 30
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
}sMtRec30_f, sMtRecMeterStop_f;

// ת������
eMtErr emtTrans_rec_30(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC31���ն�485����ʧ���¼���¼
 * ��Ӧ����: MT_ERC_31_READ_FAULT
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_31_READ_FAULT
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec31, sMtRecReadFault;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 31
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec31_f, sMtRecReadFault_f;

// ת������
eMtErr emtTrans_rec_31(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}


/*******************************************
 * ���ݽṹ: ERC32���ն�����վͨ�������������¼���¼
 * ��Ӧ����: MT_ERC_32_FLOW_OVER
 * 
{*///
// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_32_FLOW_OVER
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec32, sMtRecFlowOver;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 32
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec32_f, sMtRecFlowOver_f;

// ת������
eMtErr emtTrans_rec_32(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC33�����ܱ�����״̬�ֱ�λ�¼���¼
 * ��Ӧ����: MT_ERC_33_METER_WORD
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_9_ELEC_EXCP
    sMtYYMMDDhhmm  sTime;          // MT_ERC_33_METER_WORD
    
}sMtRec33, sMtRecMeterWord;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 33
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
     
}sMtRec33_f, sMtRecMeterWord_f;

// ת������
eMtErr emtTrans_rec_33(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC34��CT�쳣�¼���¼
 * ��Ӧ����: MT_ERC_34_CT_EXCP
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_34_CT_EXCP
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec34, sMtRecCtExcp;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 34
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
  
    
}sMtRec34_f, sMtRecCtExcp_f;

// ת������
eMtErr emtTrans_rec_34(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}

/*******************************************
 * ���ݽṹ: ERC35������δ֪����¼���¼
 * ��Ӧ����: MT_ERC_35_UNKOWN
 * 
{*///

// �û���
typedef struct
{ 
    eMtEventRecord eRec;           // = MT_ERC_35_UNKOWN
    sMtYYMMDDhhmm  sTime;          // ����ʱ�䣺��ʱ������
    
}sMtRec35, sMtRecUnkown;

// ֡��
typedef struct
{
    UINT8          ucRec;          // ERC = 35
    UINT8          ucLe;           // ����Le
    sMtFmt15_f     sTime;          // ����ʱ�䣺��ʱ������
   
}sMtRec35_f, sMtRecUnkown_f;

// ת������
eMtErr emtTrans_rec_35(eMtTrans eTrans, void* psUser, void* psFrame, UINT16* pusfLen);
///*}
///*}

/*********************************************
 *  BCD ת������
 *  
 *  
{*///
UINT8 ucmt_get_bcd_0(UINT8 ucData);        // ��ø�����BCD��λ
UINT8 ucmt_get_bcd_1(UINT8 ucData);        // ��ø�����BCD��λ
///*} 

/***************************************************************************
 * BCD �� �ַ�����ת������
 * len ����Ϊż��
 *
{*///
eMtErr emt_str_to_bcd(const UINT8* pstr, UINT8* pbcd, INT32 len); 
eMtErr emt_bcd_to_str(const UINT8* pbcd, UINT8* pstr, INT32 len);
///*}

/***************************************************************************
 * �ֽ���ת������
 * ���ֽ���ǰ�����ֽ��ں�
 *
{*///
// �ж��������Ƿ�Ϊ���ֽ���
BOOL   bmt_big_endian();

// ��һ��UINT16��ֵ��С�ֽ���д���ַpWrite
eMtErr emt_write_uint16_small_endian(UINT16 usData, UINT8* pWrite);  

// ��һ��UINT32��ֵ��С�ֽ���д���ַpWrite
eMtErr emt_write_uint32_small_endian(UINT32 ulData, UINT8* pWrite); 

// ��ָ����ַλ����С�ֽ���ķ�ʽ����һ������
eMtErr emt_read_uint16_small_endian(UINT8* pRead, UINT16* pUint16);

// ��ָ����ַλ����С�ֽ���ķ�ʽ����һ��������
eMtErr emt_read_uint32_small_endian(UINT8* pRead, UINT32* pUint32);  
///*}

/***************************************************************************
 *  ���ݵ�Ԫ Ӧ�ò����ݽṹ����
 *  ����������ͬ���͵����ݽṹ��ʱ��һ����
 *  
 *  �ն�����Ӧ��վ���ն˵Ĳ�������������ʱ,
 *    ���ն�û�������ĳ��������,��Ӧ������DT�Ķ�Ӧ��־λ�����
 *    ���ն˽���û��ĳ���������еĲ������ݣ���Ӧ�����������е���ȱ����
 *    ���ݵ�ÿ���ֽ���д��EEH����
 *    ע��:����չӦ�ò����ݵ�Ԫʱ,��Ҫ��ÿ��������Ϊÿ����������� 
 *         ��/�޵ı�ʶ ������һ��BOOL ����ʾ 
 *  
{*///
typedef union
{
  /***************************************
     *  ������ͨ��
     *  ��վ����վ �� ��վ����վ
     *  ˫��ͬ�������ݽṹ
    {*///
    sMtOnebyOne      sOneByOne;        // ���ȷ�ϻ����                  CMD_AFN_0_F3_ONE_BY_ONE
    sMtTmlUpCfg      sTmlUpCfg;        // �ն�����ͨ�ſ�ͨ�Ų�������      CMD_AFN_4_F1_TML_UP_CFG          CMD_AFN_A_F1_TML_UP_CFG
    sMtTmlPowerCfg   sTmlPowerCfg;     // �ն˵��ܱ�/��������װ�����ò��� CMD_AFN_A_F10_TML_POWER_CFG
    float            fTmlSafeValue;    // �ն˱�����ֵ                    CMD_AFN_A_F17_TML_SAFE_VALUE
    sMtFloat         sTmlPCtrlFactor;  // �ն�ʱ�ι��ض�ֵ����ϵ��        CMD_AFN_4_F19_TML_PCTRL_FACTOR   CMD_AFN_A_F19_TML_PCTRL_FACTOR
    sMtFloat         sTmlMonthFactor;  // �ն��µ������ض�ֵ����ϵ��      CMD_AFN_4_F20_TML_MONTH_FACTOR   CMD_AFN_A_F20_TML_MONTH_FACTOR
    sMtAsk1Cfg       sAsk1Cfg;         // 1��������������                 CMD_AFN_4_F38_CFG_ASK_1          CMD_AFN_A_F38_CFG_ASK_1
    sMtAsk2Cfg       sAsk2Cfg;         // 2��������������                 CMD_AFN_4_F39_CFG_ASK_2          CMD_AFN_A_F39_CFG_ASK_2
    sMtCfgAuto_1     sCfgAuto_1;       // ��ʱ�ϱ�1��������������         CMD_AFN_4_F65_CFG_AUTO_1         CMD_AFN_A_F65_CFG_AUTO_1
    sMtCfgAuto_2     sCfgAuto_2;       // ��ʱ�ϱ�2��������������         CMD_AFN_4_F66_CFG_AUTO_2         CMD_AFN_A_F66_CFG_AUTO_2
    sMtGopAuto_1     sGopAuto_1;       // ��ʱ�ϱ�1��������������/ֹͣ����CMD_AFN_4_F67_GOP_AUTO_1         CMD_AFN_A_F67_GOP_AUTO_1
    sMtGopAuto_2     sGopAuto_2;       // ��ʱ�ϱ�2��������������/ֹͣ����CMD_AFN_4_F68_GOP_AUTO_2         CMD_AFN_A_F68_GOP_AUTO_2
    ///*}


    
    /***************************************
     *  ����
     *  ��վ����վ
     *  ͨ����Ӧ�� ��Ӧ
    {*///
    sMtCurPQUI       sCurPQUI;         // ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ��� CMD_AFN_C_F25_POWER_RATE_CUR
    sMtTmlVersion    sTmlVersion;      // �ն˰汾��Ϣ  CMD_AFN_9_F1_TML_VERSION
    sMtTmlInputOut   sTmlInputOut;     // �ն�֧�ֵ����롢�����ͨ�Ŷ˿����� CMD_AFN_9_F2_TML_INPUT_OUT
    sMtTmlOtherCfg   sTmlOtherCfg;     // �ն�֧�ֵ���������      CMD_AFN_9_F3_TML_OTHER_CFG
    sMtSuptParaCfg   sTmlSuptParaCfg;  // �ն�֧�ֵĲ�������      CMD_AFN_9_F4_SUPPORT_PARA_CFG
    sMtSuptCtrlCfg   sTmlSuptCtrlCfg;  // �ն�֧�ֵĿ�������      CMD_AFN_9_F5_SUPPORT_CTRL_CFG
    sMtSuptAsk1      sTmlSuptAsk1;     // �ն�֧�ֵ�1����������   CMD_AFN_9_F6_SUPPORT_ASK1_CFG
    sMtSuptAsk2      sTmlSuptAsk2;     // �ն�֧�ֵ�2����������   CMD_AFN_9_F7_SUPPORT_ASK2_CFG
    sMtSuptEvent     sTmlSuptEvent;    // �ն�֧�ֵ��¼���¼����  CMD_AFN_9_F8_SUPPORT_EVNT_CFG
    sMtUserClock     sTmlClock;        // �ն�����ʱ��            CMD_AFN_C_F2_TML_CLOCK
    sMtAfn0cF03      sTmlParaStat;     // �ն˲���״̬            CMD_AFN_C_F3_TML_PARA_STATE 
    sMtAfn0cF04      sTmlUpComStat;    // �ն�����ͨ��״̬        CMD_AFN_C_F4_TML_UPCOM_STATE 
    sMtAfn0cF05      sTmlCtrlStat;     // �ն˿�������״̬        CMD_AFN_C_F5_TML_CTRL_SET
    sMtAfn0cF06      sTmlCurCtrlStat;  // �ն˿�������״̬        CMD_AFN_C_F6_TML_CTRL_STATE
    sMtAfn0cF07      sTmlEcValue;       // �ն˿�������״̬        CMD_AFN_C_F7_TML_EC_VALUE
    sMtAfn0cF08      sTmlErcSta;        // �ն�ʱ���־״̬         CMD_AFN_C_F8_TML_EVNT_FLAG
    sMtAfn0cf31      sTmlPowerCur;      // ��ǰA ��B ��C������/ ���й�����ʾֵ������޹�1/2 ����ʾֵ CMD_AFN_C_F31_POWER_CUR
    sMtAfn0cF57      sTmlCurtHarmValue; // ��ǰA��B��C�����ѹ������2��N��г����ЧֵCMD_AFN_C_F57_CURT_HARM_VALUE
    sMtAfn0cF58      sTmlCurtHarmRate;  // ��ǰA��B��C�����ѹ������2��N��г��������CMD_AFN_C_F58_CURT_HARM_RATE
    sMtAfn0cf129     sTmlFrthHavePowrC; // ��ǰ�����й�����ʾֵ���ܡ�����1��M��CMD_AFN_C_F129_FRTH_HAVE_POWR_C
    sMtAfn0cf130     sTmlFrthNonePowrC; // ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��CMD_AFN_C_F130_FRTH_NONE_POWR_C
    sMtAfn0cf166     sTmlMetrModifyRecd; // ���ܱ�����޸Ĵ�����ʱ�� CMD_AFN_C_F166_METR_MODIFY_RECD
    sMtAfn0cf167     sTmlMetrBuyUse;     // ���ܱ����õ���ϢCMD_AFN_C_F167_METR_BUY_USE
    ///*}

    /***************************************
     *  ����
     *  ��վ����վ
     *  ͨ�������� ����
    {*///
    sMtUserClock     sCheckTime;       // ��ʱ����  CMD_AFN_5_F31_CHECK_TIME
    ///*}

    // ������ռλ ��Ӧ������
    UINT8            ucRev[MT_UNIT_DATA_MAX];
    
}uMtApp;
///*}

/***************************************
 *  ֡�������ݽṹ �û���  (�ͼ�����)
 *  ���ڷ�װ�����
 *  �䳤�ṹ
{*///

typedef struct
{
    sMtPnFn    sPnFn;
    uMtApp     *puApp[PN_INDEX_MAX][FN_INDEX_MAX];
}sMtLiteData;

typedef struct
{
    sMtAddress    sAddress;      // ��ַ��
    sMtCtrl       sCtrl;         // ������

    // ������
    UINT8         acPW[16];      // pw�ֶ�  ��Ϣ��֤���ֶ�PW������Ҫ���б����У�
                                 // ��16�ֽ����,PW������վ��ϵͳԼ������֤�㷨����
                                 // ������վ���͵ı������·����ն�
                                 // ���ն˽���У����֤,ͨ������Ӧ��վ����,��֮�����
                                 // �ն����յ�����PW�ı���,��������֤ͨ����,������Ӧ���

    sMtEC         sEC;           // �¼�������
    sMtTP         sTP;           // ʱ���ǩ
 
    // Ӧ�ò�������  
    eMtAFN        eAFN;          // ������
    sMtSEQ        sSEQ;          // ֡������
    
    // ���ݵ�Ԫ��  �䳤��
    UINT16        usDataNum;     // ���ݵ�Ԫ��ĸ���
    sMtLiteData   sData[1];      // ���ݵ�Ԫ��
}smtLitePack;

// ��֡����
eMtErr emtLitePack(smtLitePack* psPack, UINT16* pusLen, UINT8* pOutBuf);   

// ��֡����
eMtErr emtLiteUnPack(smtLitePack *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}

/***************************************
 *  ���ݵ�Ԫ��ʶ���Ӧ�����ݵ�Ԫ (�ͼ�����)
 *  
 * ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯������,��������������ȡ�
 * ������֯��˳������Ȱ�pn��С�����ٰ�Fn��С����Ĵ���,
 * �������һ����Ϣ��pi��������Ϣ��Fn�Ĵ�����ٽ�����һ��pi+1�Ĵ���
 * 
{*///

typedef struct
{
    sMtPnFn    sPnFn;
    uMtApp     uApp[PN_INDEX_MAX][FN_INDEX_MAX];
}sMtBaseData;

// �����ܼ�����Ч��־λ��ȡ�ܼ������
UINT8 emtGetGroupNum(UINT8 ucGroupFlag);

// �ж���8��Pn�Ƿ���ͬһ����Ϣ����,ͬʱȡ����������Ϣ����
BOOL bmt_same_team_pn(UINT16 *pUsPn8, UINT8* pucDa2);

// �ж�һ��Pn�Ƿ�Ϊ0
BOOL bmt_is_p0(UINT16 *pUsPn8);

// ���pn��Ӧ����Ϣ����
UINT8 ucmt_get_pn_team(UINT16 usPn); 

// ���һ��pn��Ӧ����Ϣ����
UINT8 ucmt_get_pn8_team(UINT16 *pusPn); 

// �ж�ĳһ��pn�Ƿ���һ��8��pn��
BOOL bmt_in_pn8(UINT16 usPn, UINT16 *pusPn8);

// �ж���8��Fn�Ƿ���ͬһ����Ϣ����,ͬʱȡ����������Ϣ����
BOOL bmt_same_team_fn(UINT8  *pUcFn8, UINT8* pucDt2);

// ���Fn��Ӧ����Ϣ����
UINT8 ucmt_get_fn_team(UINT8 ucFn); 

// ���Fn��Ӧ����Ϣ����ĳ���bit
UINT8 ucmt_get_fn_bit(UINT8 ucFn);

// ���һ��Fn��Ӧ����Ϣ����
UINT8 ucmt_get_fn8_team(UINT8 *pucFn); 

// �ж�ĳһ��fn�Ƿ���һ��8��fn��
BOOL bmt_in_fn8(UINT8 ucFn, UINT8 *pucFn8);

///*}

/***************************************
 *  ֡�������ݽṹ �û���  (�ͼ�����)
 *  ���ڷ�װ�����
 *  �䳤�ṹ
{*///
typedef struct
{
    sMtAddress    sAddress;      // ��ַ��
    sMtCtrl       sCtrl;         // ������

    // ������
    UINT8         acPW[16];      // pw�ֶ�  ��Ϣ��֤���ֶ�PW������Ҫ���б����У�
                                 // ��16�ֽ����,PW������վ��ϵͳԼ������֤�㷨����
                                 // ������վ���͵ı������·����ն�
                                 // ���ն˽���У����֤,ͨ������Ӧ��վ����,��֮�����
                                 // �ն����յ�����PW�ı���,��������֤ͨ����,������Ӧ���

    sMtEC         sEC;           // �¼�������
    sMtTP         sTP;           // ʱ���ǩ
 
    // Ӧ�ò�������  
    eMtAFN        eAFN;          // ������
    sMtSEQ        sSEQ;          // ֡������
    
    // ���ݵ�Ԫ��  �䳤��
    UINT16        usDataNum;     // ���ݵ�Ԫ��ĸ���
    sMtBaseData   sData[1];      // ���ݵ�Ԫ��
}smtBasePack;

// ��֡����
eMtErr emtBasePack(smtBasePack* psPack, UINT16* pusLen, UINT8* pOutBuf);   

// ��֡����
eMtErr emtBaseUnPack(smtBasePack *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}

/***************************************
 *  ͨ�ò��ַ�װ����  (�ͼ�����)
 *  �ڸú�����ʵ�ּ�������ܹ���
 *  
{*///

// �û�������
typedef struct
{
    sMtAddress  sAddr;            // ��ַ��Ϣ
    sMtCtrl     sCtrl;
    sMtSEQ      sSEQ;         

    UINT16      usSeq2CsLen;     // ��SEQ �� CS ֮������ݵĳ���
    UINT8       *pSeq2Cs;        // ��SEQ �� CS ֮�������
}sMtComPack;

// ����֡ͷ
typedef struct
{
    UINT8         f68;          // 0x68
    
    UINT8         p10:2;        // ��Э���ʶ  10
    UINT8         L1 :6;        // 
    UINT8         L2;           // L ��һ��
    UINT8         p10_2:2;      //   10
    UINT8         L1_2 :6;      // ��Э���ʶ
    UINT8         L2_2;         // L �ڶ���
    
    UINT8         s68;          // 0x68
    UINT8         C;            // ������
    sMtAddress_f  A;            // ��ַ��
    UINT8         AFN;          // ��������
    UINT8         SEQ;          // ֡����
    
}sMtfComHead;                   // ֡�๫����ͷ�ṹ

// ������ͺ���
UINT8 ucmt_get_check_sum(UINT8 *pStartPos, UINT16 usLen);

// ��װÿ��֡�Ĺ�ͬ���� 
eMtErr emt_pack_common(eMtAFN eAFN, sMtComPack *psCommon,  UINT16 *pusLen, UINT8  *pOutBuf); 
///*}

/*******************************************************
 *  �ⲿ�ӿ�
 *
{*///

/***************************************
 *  Э��ģ���ʼ��
 *  ʹ��Э��API��Ҫ�Ƚ��г�ʼ��
 *  
{*///
typedef struct
{
    eMtRole eRole;                  // ��ݣ���վ���Ǵ�վ
    UINT8   ucPermitDelayMinutes;   // ����ʱ��
    UINT8   aucPw[MT_PW_LEN];       // ����

#if MT_CFG_ENCRYPT
    peMtEncryptFunc   EncryptFunc;  // ���ܽӿ�
    peMtDecryptFunc   DecryptFunc;  // ���ܽӿ�
#endif
    
}sMtInit;                           // Э���ʼ�����ݽṹ

// ��ʼ������
eMtErr eMtInit(sMtInit* psInit);
///*}

// ��ø����͵ı��ĵ�������
eMtPRM emtGetPrm(eMtDir eDir, eMtAFN eAfn, BOOL bAuto);

// �ж�һ�������Ƿ�����һ����Ч��376.1֡
eMtErr emtIsValidPack(const UINT8* pOutBuf, UINT16 usLen);

// ��֡���������ҵ���һ����Ч��֡��λ�ü�����
eMtErr emtFindValidPack(UINT8* pinBuf, UINT16 usLen, UINT16* pusFirstOff, UINT16* pusFirstLen);

// �����¼�������
void  vmtSetEC(UINT8 ucEC1, UINT8 ucEC2);

// ���ַ�����ʽ��������
void  vmtSetPw(char *pPw);

// ��buffer ��ʽ���õ�¼����
void vmtSetPwBuf(UINT8* buf);

// ����ҵ����
eMtRole emtWhoAmI();

// ��������Ӧ��AFN
eMtAFN eGetCmdAfn(eMtCmd eCmd);

// ��������Ӧ��Fn
UINT8  ucGetCmdFn(eMtCmd eCmd);
/***************************************
 *  ���ݵ�Ԫ��ʶ���Ӧ�����ݵ�Ԫ (�߼�����)
 *  
 * ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯������,��������������ȡ�
 * ������֯��˳�������ɢ��ʽ
 * ���������ʶ ���ݵ�Ԫ һһ��Ӧ�ķ�ʽ
 * 
{*///
typedef struct
{
    eMtCmd       eCmd;        // ������
    UINT16       usPN;        // Pn (0 <= pn <= 2040 )
    BOOL         bApp;        // �Ƿ������ݵ�Ԫ
    uMtApp       uApp;        // ��Ӧ��ͬ����������, ������������, Ӧ�ò�����ʱ��ʱ��
    
}sMtData;
///*}

/***************************************
 *  ֡�������ݽṹ �û���  (�߼�����)
 *  ���ڷ�װ
 *  �䳤�ṹ
{*///
typedef struct
{
    sMtAddress    sAddress;        // ��ַ��
    eMtAFN        eAFN;            // ��������  ͬ֡�б�����ͬһ�����������µĲ�ͬ����������
    eMtDir        eDir;            // ������
    eMtPRM        ePRM;            // ��־�ñ�������������վ ���ǴӶ�վ
    eMtPos        ePos;            // λ��
    UINT8         ucSeq;           // pseq/rseq (0~15) 
 
    BOOL          bAcdFcb;         // FCB ֡����λ �����б�������Ч
                                   /*
                                      ����վ��ͬһ�Ӷ�վ�����µķ���/ȷ�ϻ�����/��Ӧ�������ʱ����FCBȡ�෴ֵ��
                                      ����վ����ÿһ���Ӷ�վFCBֵ������ʱδ�յ��Ӷ�վ�ı��ģ�����ճ��ֲ��
                                      ������վ���ı�FCB��״̬���ظ�ԭ���ķ���/ȷ�ϻ�������/��Ӧ����
                                      ��λ�����е�FCB=0���Ӷ�վ���ո�λ�����FCB��"0"
                                   */
                           
                                   // ACD �¼��������λ, �������Ҫ�¼���Ҫ��վ����, ����
                                   // ֻ�����б����� ��Ч
    BOOL          bCon;            // �Ƿ���Ҫȷ��

    // ������
    BOOL          bPW;             // ��û��Pw�ֶ�
    BOOL          bEC;             // ��û��EC �ֶ�
    BOOL          bTP;             // �Ƿ���Tp�ֶ�

    
    UINT8         acPW[MT_PW_LEN]; // pw�ֶ�  ��Ϣ��֤���ֶ�PW������Ҫ���б����У�
                                   // ��16�ֽ����,PW������վ��ϵͳԼ������֤�㷨����
                                   // ������վ���͵ı������·����ն�
                                   // ���ն˽���У����֤,ͨ������Ӧ��վ����,��֮�����
                                   // �ն����յ�����PW�ı���,��������֤ͨ����,������Ӧ���
    sMtEC         sEC;             // �¼�������
    sMtTP         sTP;             // ʱ���ǩ
 

    // ���ݵ�Ԫ��  �䳤��
    UINT16        usDataNum;      // ���ݵ�Ԫ��ĸ���
    sMtData       sData[1];       // ���ݵ�Ԫ�� �䳤 ����û�� ���ܶ��
    
}smtPack;

// ��װ����
eMtErr emtPackBase(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf);   

// ��֡����
eMtErr emtUnPackBase(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen);

// ��װ����
eMtErr emtPackLite(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf);   

// ��֡����
eMtErr emtUnPackLite(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen);

// �߼��ӿ�
// ��װ����
eMtErr emtPack(smtPack* psPack, UINT16* pusLen, UINT8* pOutBuf);   

// ��֡����
eMtErr emtUnPack(smtPack *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}
///*}
 
#endif // _QGDW_3761_API_H_


///////////////////////////////////


class CQgdw3761api  
{
public:
	BOOL    CStringToHexBuffer(CString strText, char *pOutBuf, UINT16 *pLen);
	CString GetAfnName(eMtAFN eAfn);
	CString BufferToHex(char* pBuf, UINT16 usLen);
	CQgdw3761api();
	virtual ~CQgdw3761api();
	char * getErrMessage( eMtErr err );

};

#endif // !defined(AFX_QGDW3761API_H__EBD79D34_E069_44C8_8DF5_5EBB464200FC__INCLUDED_)
