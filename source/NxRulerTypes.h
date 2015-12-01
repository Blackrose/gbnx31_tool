/*******************************************************************************
	File name: 		NxRulerTypes.h
	Author: 		����
	Version:  		1.0
	Date:    		2013��5��13��
	Description: 	Nxruler QGW 376.1 ���Ͷ���ͷ�ļ�
	                               
	Others:       
    Function List: 
    1. History: 
                    
          1)  Date:
          2)  Author:
          3)  Modification:  Created
    2. ...
*******************************************************************************/
#if !defined(_NX_RULER_TYPES_H_)
#define _NX_RULER_TYPES_H_

#pragma pack(push)  // ����һ�ֽڶ���
#pragma pack(1)
#if 0
typedef unsigned char  UINT8;
typedef unsigned short UINT16;



// Э����غ궨��
#define MT_PN_MAX    (2033)
#define MT_SEQ2CS_BYTES_MAX    (16384)             // ÿ��֡����SEQ��CS֮�������ֽ������ֵ
// ���֡�����ֳ�
#define MT_CA_LEN                 (8)                // ���������ַ�����ֳ� 
#define MT_CANS_LEN               (8)               // ������C ��ַ��A AFN SEQ�ֽ��ܳ�
#define MT_UN_USER_LEN            (6)                // �����з��������ܳ���  0x68 0x68 L L CS 0x16
#define MT_DADT_LEN               (4)                // ���ݱ�ʶ�ֳ� DaDt  
#define MT_AFN_LEN                (1)                // AFN �ֳ�
#define MT_DADT_ERR_LEN           (MT_DADT_LEN + 1)  // DaDt �� ERR���ֳ�


#define MT_TM_ADDR_MAX            (65535)            // �ն˵�ַ�����ֵ
#define MT_TM_ADDR_MIN            (1)                // �ն˵�ַ����Сֵ

#define MT_CTRL_DIR_M2T           (0x80)             // ������ ���䷽�� ��վ���ն�(����)
#define MT_CTRL_DIR_T2M           (0x7F)             // ������ ���䷽�� �ն˵�����(����)

#define MT_CTRL_PRM_MASTR         (0x40)             // ������ ������־ ����վ
#define MT_CTRL_PRM_SLAVE         (0xBF)             // ������ ������־ �Ӷ�վ

#define MT_CTRL_FCB_ENABLE        (0x20)             // ֡����λ 
#define MT_CTRL_FCV_ENABLE        (0x10)             // ֡����λ��Чλ,Ϊ1ʱ FCB ��Ч

#define MT_CTRL_ACD_EVENT_HAVE    (0x20)             // �������λ Ϊ 1 �ն����¼���Ҫ�ϱ�
#define MT_CTRL_ACD_EVENT_NONE    (0xDF)             // �������λ Ϊ 0 �ն����¼���Ҫ�ϱ�

// bit set 
#define MT_BSET_SEQ_TPV           (0x80)             // bit set seq tpv �ֶ�
#define MT_BSET_SEQ_FIR           (0x40)             // bit set seq fir �ֶ�
#define MT_BSET_SEQ_FIN           (0x20)             // bit set seq fin �ֶ�
#define MT_BSET_SEQ_CON           (0x10)             // bit set seq con �ֶ�

#define   MT_SEND_LEN_MAX   (10240)                  // һ������buffer����󳤶�

#define MT_DA_PN_MAX            (2040)               // DA Pn ���ֵ 
#define MT_DA_PN_MIN            (0)                  // Da Pn ��Сֵ
#define MT_DT_FN_MAX            (248)                // Dt Fn ���ֵ
#define MT_DT_FN_MIN            (1)                  // Dt Fn ��Сֵ
#define MT_PW_LEN               (16)                 // ��Ϣ��֤����
#define MT_PACK_LEN_MIN         (18)                 // ��Ϣ����С����
#define MT_PACK_LEN_MAX         (16384)               // ��Ϣ��󳤶ȣ�Ŀǰ�ݶ�2048
#define MT_MST_ADDR_MAX         (127)                // ��վ��ַ���ֵ
// 376.1 ��Լ������
// ��֯���� AFN_XX_FN_X  ��ռһ���ֽ�   AFN ��8λ�� FN ��8λ

typedef enum
{
    CMD_AFN_0_FN_0_UNKOWN,                         // δ֪����     

    /* (0)ȷ�ϨM���ϣ�AFN=00H�� */
    CMD_AFN_0_FN_1_ALL_OK          = 0x0001,       // ȫ��ȷ��
    CMD_AFN_0_FN_2_ALL_DENY        = 0x0002,       // ȫ������
    CMD_AFN_0_FN_3_ONE_BY_ONE      = 0x0003,       // �����ݵ�Ԫ��ʶȷ�Ϻͷ���
    // F4 - F248 ����

    /* (1)��λ���AFN=01H�� */
    CMD_AFN_1_FN_1_HARD_INIT       = 0x0101,       // Ӳ����ʼ��
    CMD_AFN_1_FN_2_DATA_INIT       = 0x0102,       // ��������ʼ��
    CMD_AFN_1_FN_3_FACTORY_RESET   = 0x0103,       // ������ȫ����������ʼ�������ָ����������ã�
    CMD_AFN_1_FN_4_PARA_INIT       = 0x0104,       // ����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��
    // F5 - F248 ����

    /* (2) ��·�ӿڼ�⣨AFN=02H�� */
    CMD_AFN_2_FN_1_LOG_IN          = 0x0201,       // ��¼
    CMD_AFN_2_FN_2_LOG_OUT         = 0x0202,       // �˳���¼
    CMD_AFN_2_FN_3_HEART_BEAT      = 0x0203,       // ����
    // F4 - F248 ����

    /* (4) ���ò�����AFN == 04H�� */
    CMD_AFN_4_FN_1_CON_UP_CFG       = 0x0401,       // ����������ͨ�ſ�ͨ�Ų�������
    //CMD_AFN_4_FN_2_CON_UP_WAY_ETH   = 0x0402,       // ����������ͨ�Ź�����ʽ����̫ר��������ר���� 
	CMD_AFN_4_FN_2_CON_UP_REWORD    = 0x4002,       // ����������ͨ�ſ��м�ת������
    CMD_AFN_4_FN_3_MST_IP_PORT      = 0x0403,       // ��վIP��ַ�Ͷ˿�
    CMD_AFN_4_FN_4_PHONE_MST_SMS    = 0x0404,       // ��վ�绰����Ͷ������ĺ���
    CMD_AFN_4_FN_5_CON_UP_PARA      = 0x0405,       // ����������ͨ����Ϣ��֤��������
    CMD_AFN_4_FN_6_TEAM_ADDR        = 0x0406,       // ���������ַ����
    CMD_AFN_4_FN_7_CON_IP_PORT      = 0x0407,       // ������IP��ַ�Ͷ˿�
    CMD_AFN_4_FN_8_CON_UP_WAY       = 0x0408,       // ����������ͨ�Ź�����ʽ
    CMD_AFN_4_FN_9_CFG_TML_MNT      = 0x0409,       // ���������ն�ͨ�Ŷ�ȡ�������в�������
    CMD_AFN_4_FN_10_CON_DOWN_CFG    = 0x040A,       // ����������ͨ��ģ��Ĳ�������
    CMD_AFN_4_FN_11_VPN_PWD         = 0x040B,       // ����ר���û���������
    CMD_AFN_4_FN_12_CON_UP_LIMIT    = 0x040C,       // ����������ͨ��������������
    CMD_AFN_4_FN_13_CON_CASC_CFG    = 0x040D,       // ����������ͨ�Ų���
    CMD_AFN_4_FN_17_CFG_EVENT       = 0x0411,       // �������¼���¼��������
    CMD_AFN_4_FN_18_CFG_TM_STATE    = 0x0412,       // ������״̬���������
    CMD_AFN_4_FN_19_CFG_METERING    = 0x0413,       // ������������û�������
    CMD_AFN_4_FN_25_POWER_LIMIT     = 0x0419,       // ��������ֵ����
    CMD_AFN_4_FN_26_FACTOR_LIMIT    = 0x041A,       // �����㹦�������ֶ���ֵ
    CMD_AFN_4_FN_28_CFG_POWER       = 0x041C,       // �������������ò���
    CMD_AFN_4_FN_29_CFG_UN_POWER    = 0x041D,       // �ǵ����������ò���
    //CMD_AFN_4_FN_33_TIMING_REPORT_1 = 0x0421,       // ��ʱ�ϱ�1��������������
	CMD_AFN_4_FN_33_CFG_NOT_ELEC	  = 0x0421,       // �ǵ������������ݲ�������
    CMD_AFN_4_FN_34_TIMING_REPORT_2 = 0x0422,       // ��ʱ�ϱ�2��������������
    CMD_AFN_4_FN_35_STOP_TIMING_REPORT_1   = 0x0423,// ��ʱ�ϱ�1��������������/ֹͣ����
    CMD_AFN_4_FN_36_STOP_TIMING_REPORT_2   = 0x0424,// ��ʱ�ϱ�2��������������/ֹͣ����
    CMD_AFN_4_FN_41_CFG_TML_MNT       = 0x0429,     // �ն����û�����������
    CMD_AFN_4_FN_42_CFG_TML_STATE     = 0x042A,     // �ն�״̬���������
    CMD_AFN_4_FN_43_CFG_TML_TRANS     = 0x042B,     // �ն�͸���豸����


    /* (5) �������AFN=05H�� */
    CMD_AFN_5_FN_1_REMOTE_SWITCH_OFF = 0x0501,       // ң����բ
    CMD_AFN_5_FN_2_PERMIT_SWITCH_ON  = 0x0502,       // �����բ
    CMD_AFN_5_FN_29_STRT_AUTO_REPORT = 0x051D,       // �������������ϱ�
    CMD_AFN_5_FN_31_TIME_TICK        = 0x051F,       // ��ʱ����
    CMD_AFN_5_FN_37_STOP_AUTO_REPORT = 0x0525,       // ��ֹ�����������ϱ�
    CMD_AFN_5_FN_38_LINK_MST_TML     = 0x0526,       // �������������վ
    CMD_AFN_5_FN_39_UNLINK_MST_TML   = 0x0527,       // ��������Ͽ�����
    CMD_AFN_5_FN_49_PORT_TML_SUSPEND = 0x0531,       // ����ָ��ͨ�Ŷ˿���ͣ���ն�ͨ�Ŷ�ȡ����
    CMD_AFN_5_FN_50_PORT_TML_RESUME  = 0x0532,       // ����ָ��ͨ�Ŷ˿ڻָ����ն�ͨ�Ŷ�ȡ����
    CMD_AFN_5_FN_51_PORT_TML_AGAIN   = 0x0533,       // ����ָ��ͨ�Ŷ˿��������ն�ͨ�Ŷ�ȡ����
    CMD_AFN_5_FN_52_INIT_ROUT_INFO   = 0x0534,       // ��ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ
    CMD_AFN_5_FN_53_DEL_ALL_TML      = 0x0535,       // ɾ��ָ��ͨ�Ŷ˿��µ�ȫ���ն�
    

    /* (6) �����֤����ԿЭ�̣�AFN=06H�� */
    CMD_AFN_6_FN_1_ID_AUTH_Q         = 0x0601,       // �����֤����
    CMD_AFN_6_FN_2_ID_AUTH_A         = 0x0602,       // �����֤��Ӧ
    CMD_AFN_6_FN_3_RAND_Q            = 0x0603,       // ȡ���������
    CMD_AFN_6_FN_4_RAND_A            = 0x0604,       // ȡ�������Ӧ
 
    /* (9) �����������ü���Ϣ��AFN=09H�� */
    CMD_AFN_9_FN_1_CON_VERSION        = 0x0901,       // �������汾��Ϣ
    CMD_AFN_9_FN_4_SUPPORT_PARA_CFG  = 0x0904,       // ������֧�ֵĲ�������
    CMD_AFN_9_FN_5_SUPPORT_CTRL_CFG  = 0x0905,       // ������֧�ֵĿ�������
    CMD_AFN_9_FN_6_SUPPORT_ASK1_CFG  = 0x0906,       // ������֧�ֵ�1����������
    CMD_AFN_9_FN_7_SUPPORT_ASK2_CFG  = 0x0907,       // ������֧�ֵ�2����������
    CMD_AFN_9_FN_8_SUPPORT_EVNT_CFG  = 0x0908,       // ������֧�ֵ��¼���¼����

 

    /* (10)  ��ѯ������AFN=0AH�� */
    CMD_AFN_A_FN_1_CON_UP_CFG        = 0x0A01,       // ����������ͨ�ſ�ͨ�Ų�������
    CMD_AFN_A_FN_2_CON_UP_WAY_ETH    = 0x0A02,       // ����������ͨ�Ź�����ʽ����̫ר��������ר����
    CMD_AFN_A_FN_3_MST_IP_PORT       = 0x0A03,       // ��վIP��ַ�Ͷ˿�
    CMD_AFN_A_FN_4_PHONE_MST_SMS     = 0x0A04,       // ��վ�绰����Ͷ������ĺ���
    CMD_AFN_A_FN_5_CON_UP_PARA       = 0x0A05,       // ����������ͨ����Ϣ��֤��������
    CMD_AFN_A_FN_6_TEAM_ADDR         = 0x0A06,       // ���������ַ����
    CMD_AFN_A_FN_7_CON_IP_PORT       = 0x0A07,       // ������IP��ַ�Ͷ˿�
    CMD_AFN_A_FN_8_CON_UP_WAY        = 0x0A08,       // ����������ͨ�Ź�����ʽ
    CMD_AFN_A_FN_9_CFG_TML_MNT       = 0x0A09,       // ���������ն�ͨ�Ŷ�ȡ�������в�������
    CMD_AFN_A_FN_10_CON_DOWN_CFG     = 0x0A0A,       // ����������ͨ��ģ��Ĳ�������
    CMD_AFN_A_FN_11_VPN_PWD          = 0x0A0B,       // ����ר���û���������
    CMD_AFN_A_FN_12_CON_UP_LIMIT     = 0x0A0C,       // ����������ͨ��������������
    CMD_AFN_A_FN_13_CON_CASC_CFG     = 0x0A0D,       // ����������ͨ�Ų���
    CMD_AFN_A_FN_17_CFG_EVENT       = 0x0A11,       // �������¼���¼��������
    CMD_AFN_A_FN_18_CFG_TM_STATE    = 0x0A12,       // ������״̬���������
    CMD_AFN_A_FN_19_CFG_METERING    = 0x0A13,       // ������������û�������
    CMD_AFN_A_FN_25_POWER_LIMIT     = 0x0A19,       // ��������ֵ����
    CMD_AFN_A_FN_26_FACTOR_LIMIT    = 0x0A1A,       // �����㹦�������ֶ���ֵ
    CMD_AFN_A_FN_28_CFG_POWER       = 0x0A1C,       // �������������ò���
    CMD_AFN_A_FN_29_CFG_UN_POWER    = 0x0A1D,       // �ǵ����������ò���
    CMD_AFN_A_FN_33_TIMING_REPORT_1 = 0x0A21,       // ��ʱ�ϱ�1��������������
    CMD_AFN_A_FN_34_TIMING_REPORT_2 = 0x0A22,       // ��ʱ�ϱ�2��������������
    CMD_AFN_A_FN_35_STOP_TIMING_REPORT_1     = 0x0A23,       // ��ʱ�ϱ�1��������������/ֹͣ����
    CMD_AFN_A_FN_36_STOP_TIMING_REPORT_2     = 0x0A24,       // ��ʱ�ϱ�2��������������/ֹͣ����
    CMD_AFN_A_FN_41_CFG_TML_MNT        = 0x0A09,       // �ն����û�����������
    CMD_AFN_A_FN_42_CFG_TML_STATE      = 0x0A09,       // �ն�״̬���������
    CMD_AFN_A_FN_43_CFG_TML_TRANS      = 0x0A09,       // �ն�͸���豸����

    /* (11) �����������ݣ�AFN=0BH�� */
    CMD_AFN_B_FN_1_TIMING_REPORT_1    = 0x0B01,       // ����ʱ�ϱ�1����������
    CMD_AFN_B_FN_2_TIMING_REPORT_2    = 0x0B02,       // ����ʱ�ϱ�2����������

    /* (12) ����1�����ݣ�AFN=0CH�� */
    CMD_AFN_C_FN_1_CON_CALENDAR_CLOCK  = 0x0C01,       // ����������ʱ��
    CMD_AFN_C_FN_2_CON_PARA_STATE      = 0x0C02,       // ����������״̬
    CMD_AFN_C_FN_3_CON_UPCOM_STATE     = 0x0C03,       // ����������ͨ��״̬
    CMD_AFN_C_FN_4_CON_EC_VALUE        = 0x0C04,       // �������¼���������ǰֵ
    CMD_AFN_C_FN_5_CON_EVNT_FLAG       = 0x0C05,       // �������¼���־״̬
    CMD_AFN_C_FN_6_CON_STATE_BIT       = 0x0C06,       // ������״̬������λ��־
    CMD_AFN_C_FN_7_CON_MONTH_FLOW      = 0x0C07,       // ����������վ���ա���ͨ������
    CMD_AFN_C_FN_9_CURENT_ELEC         = 0x0C09,       // ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ���
    CMD_AFN_C_FN_10_DROP_PHASE         = 0x0C0A,       // A��B��C�������ͳ�����ݼ����һ�ζ����¼
    CMD_AFN_C_FN_12_POWER_HAVE         = 0x0C0C,       // ��ǰA��B��C������/�����й�������ʾֵ������޹�1/2����ʾֵ
    CMD_AFN_C_FN_13_POWER_FORTH        = 0x0C0D,       // ��ǰ������/�޹�����ʾֵ��һ/�������޹�����ʾֵ
    CMD_AFN_C_FN_14_POWER_BACK         = 0x0C0E,       // ��ǰ������/�޹�����ʾֵ����/�������޹�����ʾֵ
    CMD_AFN_C_FN_13_PHASE_ANGLE        = 0x0C0D,       // ��ǰ��ѹ��������λ��
    CMD_AFN_C_FN_17_CUR_CURVE          = 0x0C11,       // ��ǰ�ܻ���/г���й�/�޹�����
    CMD_AFN_C_FN_18_HARM_VALID         = 0x0C12,       // ��ǰA��B��C�����ѹ������2��N��г����Чֵ
    CMD_AFN_C_FN_19_HARM_ROTIO         = 0x0C13,       // ��ǰA��B��C�����ѹ������2��N��г��������
    CMD_AFN_C_FN_20_HARM_ROTIO_V       = 0x0C14,       // ��ǰA��B��C�����ѹ20~N��г��������
    CMD_AFN_C_FN_21_HARM_ROTIO_E       = 0x0C15,       // ��ǰA��B��C�������20~N��г��������
    
    CMD_AFN_C_FN_22_FLICKER_LONG       = 0x0C16,       // ������
    CMD_AFN_C_FN_23_FLICKER_SHORT      = 0x0C17,       // ������
    CMD_AFN_C_FN_25_DC_REAL_TIME       = 0x0C19,       // ֱ��ģ��ʵʱ����
    CMD_AFN_C_FN_26_UNBALAN_E_V        = 0x0C1A,       // ��ѹ��������ƽ���
    CMD_AFN_C_FN_27_UNBALAN_FREZ_V     = 0x0C1B,       // Сʱ�����ѹ��ƽ���
    CMD_AFN_C_FN_28_UNBALAN_FREZ_E     = 0x0C1C,       // Сʱ���������ƽ���
    CMD_AFN_C_FN_29_FREZ_NOR_POWER     = 0x0C1D,       // Сʱ����ǵ�������
    CMD_AFN_C_FN_33_FREZ_HAVE_POWER    = 0x0C21,       // Сʱ�����й�����
    CMD_AFN_C_FN_34_FREZ_HAVE_POWER_A  = 0x0C22,       // Сʱ����A���й�����
    CMD_AFN_C_FN_35_FREZ_HAVE_POWER_B  = 0x0C23,       // Сʱ����B���й�����
    CMD_AFN_C_FN_36_FREZ_HAVE_POWER_C  = 0x0C24,       // Сʱ����C���й�����
    CMD_AFN_C_FN_37_FREZ_NONE_POWER    = 0x0C25,       // Сʱ�����޹�����
    CMD_AFN_C_FN_38_FREZ_NONE_POWER_A  = 0x0C26,       // Сʱ����A���޹�����
    CMD_AFN_C_FN_39_FREZ_NONE_POWER_B  = 0x0C27,       // Сʱ����B���޹�����
    CMD_AFN_C_FN_40_FREZ_NONE_POWER_C  = 0x0C28,       // Сʱ����C���޹�����
    
    CMD_AFN_C_FN_41_FREZ_V_A           = 0x0C29,       // Сʱ����A���ѹ
    CMD_AFN_C_FN_42_FREZ_V_B           = 0x0C2A,       // Сʱ����B���ѹ
    CMD_AFN_C_FN_43_FREZ_V_C           = 0x0C2B,       // Сʱ����C���ѹ
    CMD_AFN_C_FN_44_FREZ_E_A           = 0x0C2C,       // Сʱ����A�����
    CMD_AFN_C_FN_45_FREZ_E_B           = 0x0C2D,       // Сʱ����B�����
    CMD_AFN_C_FN_46_FREZ_E_C           = 0x0C2E,       // Сʱ����C�����
    
    CMD_AFN_C_FN_47_CFG_TML_MNT     = 0x0C2F,       // Сʱ�����������
    CMD_AFN_C_FN_49_CFG_TML_MNT     = 0x0C31,       // Сʱ���������й��ܵ���ʾֵ
    CMD_AFN_C_FN_50_CFG_TML_MNT     = 0x0C32,       // Сʱ���������޹��ܵ���ʾֵ
    CMD_AFN_C_FN_51_CFG_TML_MNT     = 0x0C33,       // Сʱ���ᷴ���й��ܵ���ʾֵ
    CMD_AFN_C_FN_52_CFG_TML_MNT     = 0x0C34,       // Сʱ���ᷴ���޹��ܵ���ʾֵ
    CMD_AFN_C_FN_53_CFG_TML_MNT     = 0x0C35,       // Сʱ�����ܹ�������
    CMD_AFN_C_FN_54_CFG_TML_MNT     = 0x0C36,       // Сʱ����A�๦������
    CMD_AFN_C_FN_55_CFG_TML_MNT     = 0x0C37,       // Сʱ����B�๦������
    CMD_AFN_C_FN_56_CFG_TML_MNT     = 0x0C38,       // Сʱ����C�๦������
    CMD_AFN_C_FN_57_CFG_TML_MNT     = 0x0C39,       // �ն�����ʱ��
    CMD_AFN_C_FN_90_NOT_ELEC        = 0x0C5A,       // ȡ�÷ǵ�����
    
    /* (13) ����2�����ݣ�AFN=0DH�� */
    CMD_AFN_D_FN_1_TM_UP_CFG        = 0x0D01,       // ����������ʱ��
    CMD_AFN_D_FN_2_TM_UP_WAY_ETH    = 0x0D02,       // ����������״̬
    CMD_AFN_D_FN_3_MST_IP_PORT      = 0x0D03,       // ����������ͨ��״̬
    CMD_AFN_D_FN_4_PHONE_SMS        = 0x0D04,       // �������¼���������ǰֵ
    CMD_AFN_D_FN_5_TM_UP_PARA       = 0x0D05,       // �������¼���־״̬
    CMD_AFN_D_FN_6_TEAM_ADDR        = 0x0D06,       // ������״̬������λ��־
    CMD_AFN_D_FN_7_TML_IP_PORT      = 0x0D07,       // ����������վ���ա���ͨ������
    CMD_AFN_D_FN_8_TM_UP_WAY        = 0x0D08,       // ��ǰ���༰����/�޹����ʡ����������������ѹ��������������������ڹ���
    CMD_AFN_D_FN_9_CFG_TML_MNT      = 0x0D09,       // A��B��C�������ͳ�����ݼ����һ�ζ����¼
    CMD_AFN_D_FN_10_TM_DOWN_CFG     = 0x0D0A,       // ��ǰA��B��C������/�����й�������ʾֵ������޹�1/2����ʾֵ
    CMD_AFN_D_FN_11_VPN_PWD         = 0x0D0B,       // ��ǰ������/�޹�����ʾֵ��һ/�������޹�����ʾֵ
    CMD_AFN_D_FN_12_TM_UP_LIMIT     = 0x0D0C,       // ��ǰ������/�޹�����ʾֵ����/�������޹�����ʾֵ
    CMD_AFN_D_FN_13_TM_CASC_CFG     = 0x0D0D,       // ��ǰ��ѹ��������λ��
    CMD_AFN_D_FN_14_CFG_EVENT       = 0x0D11,       // ��ǰ�ܻ���/г���й�/�޹�����
    CMD_AFN_D_FN_15_CFG_TM_STATE    = 0x0D12,       // ��ǰA��B��C�����ѹ������2��N��г����Чֵ
    CMD_AFN_D_FN_17_CFG_METERING    = 0x0D13,       // ��ǰA��B��C�����ѹ������2��N��г��������
    CMD_AFN_D_FN_18_POWER_LIMIT     = 0x0D19,       // ��ǰA��B��C�����ѹ20~N��г��������
    CMD_AFN_D_FN_19_FACTOR_LIMIT    = 0x0D1A,       // ��ǰA��B��C�������20~N��г��������
    CMD_AFN_D_FN_20_CFG_POWER       = 0x0D1C,       // ������
    CMD_AFN_D_FN_21_CFG_UN_POWER    = 0x0D1D,       // ������
    CMD_AFN_D_FN_22_TIMING_REPORT_1 = 0x0D21,       // ֱ��ģ��ʵʱ����
    CMD_AFN_D_FN_23_TIMING_REPORT_2 = 0x0D22,       // ��ѹ��������ƽ���
    CMD_AFN_D_FN_25_STOP_TIMING_REPORT_1     = 0x0D23,       // Сʱ�����ѹ��ƽ���
    CMD_AFN_D_FN_26_STOP_TIMING_REPORT_2     = 0x0D24,       // Сʱ���������ƽ���
    CMD_AFN_D_FN_27_CFG_TML_MNT     = 0x0D09,       // Сʱ����ǵ�������
    CMD_AFN_D_FN_28_CFG_TML_MNT     = 0x0D09,       // Сʱ�����й�����
    CMD_AFN_D_FN_29_CFG_TML_MNT     = 0x0D09,       // Сʱ����A���й�����
    CMD_AFN_D_FN_33_CFG_TML_MNT     = 0x0D09,       // Сʱ����B���й�����
    CMD_AFN_D_FN_34_CFG_TML_MNT     = 0x0D09,       // Сʱ����C���й�����
    CMD_AFN_D_FN_35_CFG_TML_MNT     = 0x0D09,       // Сʱ�����޹�����
    CMD_AFN_D_FN_36_CFG_TML_MNT     = 0x0D09,       // Сʱ����A���޹�����
    CMD_AFN_D_FN_37_CFG_TML_MNT     = 0x0D09,       // Сʱ����B���޹�����
    CMD_AFN_D_FN_38_CFG_TML_MNT     = 0x0D09,       // Сʱ����C���޹�����
    
    CMD_AFN_D_FN_39_CFG_TML_MNT     = 0x0D09,       // Сʱ����A���ѹ
    CMD_AFN_D_FN_40_CFG_TML_MNT     = 0x0D09,       // Сʱ����B���ѹ
    CMD_AFN_D_FN_41_CFG_TML_MNT     = 0x0D09,       // Сʱ����C���ѹ
    CMD_AFN_D_FN_42_CFG_TML_MNT     = 0x0D09,       // Сʱ����A�����
    CMD_AFN_D_FN_43_CFG_TML_MNT     = 0x0D09,       // Сʱ����B�����
    CMD_AFN_D_FN_44_CFG_TML_MNT     = 0x0D09,       // Сʱ����C�����
    
    CMD_AFN_D_FN_45_CFG_TML_MNT     = 0x0D09,       // Сʱ�����������
    CMD_AFN_D_FN_46_CFG_TML_MNT     = 0x0D09,       // Сʱ���������й��ܵ���ʾֵ
    CMD_AFN_D_FN_47_CFG_TML_MNT     = 0x0D09,       // Сʱ���������޹��ܵ���ʾֵ
    CMD_AFN_D_FN_48_CFG_TML_MNT     = 0x0D09,       // Сʱ���ᷴ���й��ܵ���ʾֵ
    CMD_AFN_D_FN_52_CFG_TML_MNT     = 0x0D09,       // Сʱ���ᷴ���޹��ܵ���ʾֵ
    CMD_AFN_D_FN_53_CFG_TML_MNT     = 0x0D09,       // Сʱ�����ܹ�������
    CMD_AFN_D_FN_54_CFG_TML_MNT     = 0x0D09,       // Сʱ����A�๦������
    CMD_AFN_D_FN_55_CFG_TML_MNT     = 0x0D09,       // Сʱ����B�๦������
    CMD_AFN_D_FN_56_CFG_TML_MNT     = 0x0D09,       // Сʱ����C�๦������
    CMD_AFN_D_FN_57_CFG_TML_MNT     = 0x0D09,       // �ն�����ʱ��

    /* (14) ����3�����ݣ�AFN=0EH�� */
    CMD_AFN_E_FN_1_EVENT_1          = 0x0E01,       // ������Ҫ�¼�
    CMD_AFN_E_FN_2_EVENT_2          = 0x0E02,       // ����һ���¼�
	
    /* (15) �ļ����䣨AFN=0FH�� */
     CMD_AFN_F_FN_1_TRANS_WAY       = 0x0E01,       // �ļ����䷽ʽ1

    /* (16) ����ת����AFN=10H�� */
    CMD_AFN_G_FN_1_CFG_TML_MNT     = 0x1001,       // ͸��ת��
    CMD_AFN_G_FN_9_CFG_TML_MNT     = 0x1009,       // ת����վֱ�Ӷ��ն˵ĳ�����������
    CMD_AFN_G_FN_10_CFG_TML_MNT    = 0x100A,       // ת����վֱ�Ӷ��ն˵�ң����բ/�����բ����
    CMD_AFN_G_FN_11_CFG_TML_MNT    = 0x100B,       // ת����վֱ�Ӷ��ն˵�ң���͵�����

    /* ����֮�������չ������ */
    CMD_AFN_FN_MAX                                 // 
}eMtCmd;

typedef enum
{
	AFN_00_CONF  = 0x00,     // ȷ�Ϸ���
	AFN_01_RSET  = 0x01,     // ��λ
	AFN_02_LINK  = 0x02,     // �ӿڼ��
	AFN_03_RELY  = 0x03,     // �м�վ����
	AFN_04_SETP  = 0x04,     // ���ò���
	AFN_05_CTRL  = 0x05,     // ��������
	AFN_06_AUTH  = 0x06,     // �����֤
	AFN_08_CASC  = 0x08,     // ���󱻼����ն������ϱ� 
	AFN_09_CFIG  = 0x09,     // �����ն�����
	AFN_0A_GETP  = 0x0A,     // ��ѯ����
	AFN_0B_ASKT  = 0x0B,     // ������������
	AFN_0C_ASK1  = 0x0C,     // ����1������ ʵʱ����
	AFN_0D_ASK2  = 0x0D,     // ����2������ ��ʷ����
	AFN_0E_ASK3  = 0x0E,     // ����3������ �¼�����
	AFN_0F_FILE  = 0x0F,     // �ļ�����
	AFN_10_DATA  = 0x10,     // ����ת��
    AFN_MAX,
	AFN_NULL     = 0xFF,     // û�ж�Ӧ�Ĵ����� ������             
	
}eMtAFN; //  Ӧ�ò㹦����AFN


typedef enum
{
	MT_OK,             // �޴���                 0 
	MT_NULL,           // ָ��Ϊ��               1 
	MT_OUT_RNG,        // ����Խ��    2
	MT_NONE,           // ������,û���ҵ�    3    
	MT_ERR_IO,         // IO����              4
	MT_ERR_RES,        // ��Դ����6
	MT_ERR_INIT,       // û�г�ʼ��7
	MT_ERR_PARA,       // ��������8
	MT_ERR_FN,         // ָ��Afn �в�֧�ֵ� Fn9
	MT_ERR_PN,         // ָ��Afn Fn �в�֧�ֵ� Pn10
	MT_ERR_ADDR,       // ��Ч��ַ
	MT_ERR_CTRL,       // ��������� 
	MT_ERR_SEQ,        // SEQ�����13
	MT_ERR_SEQ2CS,     // 14
	MT_ERR_AFN,        // AFN ����15
	MT_ERR_UNCOMP,     // ��������Э���16
	MT_ERR_0x68,       // ����ı�����ʼ17
    MT_ERR_PROTO,      // �����Э���ʶ18
    MT_ERR_CS,         // ����ļ���19
    MT_ERR_0x16,       // ����Ľ�β��20
    MT_ERR_LOGIC,      // ����Ĵ����߼�
    MT_ERR_PACK,       // ����һ����Ч�İ�

    
}eMtErr;  // MT ģ�鷵����

typedef enum
{

	MT_POS_UNKOWN, // δ֪֡λ����Ϣ
	MT_POS_SIGLE,  // ��֡
	MT_POS_MUL_S,  // ��֡��ʼ֡���к���֡
	MT_POS_MUL_M,  // ��֡�м�֡
	MT_POS_MUL_E,  // ��֡���֡
	
}eMtFmPos; // ֡��λ������


typedef enum
{
	MT_PN_UNKOWN,       // δ֪PN ����
	MT_PN_0,            // P0
	MT_PN_TM,           // �ն˺�
	MT_PN_TP,           // ������� test point
	MT_PN_GT,           // �ܼ���� GROUP_TOTAL
	MT_PN_CT,           // �����ִ� control times
	MT_PN_TK,           // ����� task number
	MT_PN_DN,           // ֱ��ģ�����˿ں� direct current simulation port number
}eMtPn;


typedef struct
{

	UINT8 ucDA1;         // ��Ϣ��Ԫ
	UINT8 ucDA2;         // ��Ϣ����
	UINT8 ucDT1;         // ��Ϣ��Ԫ
	UINT8 ucDT2;         // ��Ϣ����
}sMtDaDt;

typedef struct
{
	UINT16 usPn;         // Pn
	UINT16 usFn;         // Fn
}sMtPnFn;


typedef struct
{
    UINT8 ucEC1; // ��Ҫ�¼�������
    UINT8 ucEC2; // һ���¼�������
    
}sMtEC;    // �¼�������  

typedef enum
{
	MT_DIR_UNKOWN,   // δ֪���ķ���
	MT_DIR_M2S,      // ����վ���Ӷ�վ    ����
	MT_DIR_S2M,      // �Ӷ�վ������վ    ����
	MT_DIR_ALL,      // �����뷴��
	
}eMtDir;

typedef enum
{
	//MT_TRANS_UNKOWN,    // δ֪����
	MT_TRANS_U2F,       // �û������ݽṹ��֡���ݽṹ
	MT_TRANS_F2U,       // ֡�����ݽṹ���û������ݽṹ	
}eMtTransDir;             // �û�����֡�����ݽṹת������

/*  ���ݵ�Ԫ��ʽ���� */
typedef struct
{

	UINT8 ssBCD_0:4;  // ��
	UINT8 ssBCD_1:4;
	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:1;  
	UINT8 wwBCD_0:3;  // ����
	UINT8 yyBCD_0:4;  // ��
	UINT8 yyBCD_1:4;
}sMtFmt01;   // һ��6���ֽ�


// ���ݸ�ʽ02
typedef struct
{

	UINT8 BCD_0:4;
	UINT8 BCD_1:4;
	UINT8 ucG321:3;
	UINT8 signal:1;
	UINT8 BCD_2:4;
}sMtFmt02;

typedef struct
{

	UINT8 BCD_0:4;
	UINT8 BCD_1:4;
	UINT8 BCD_2:4;
	UINT8 BCD_3:4;
	UINT8 BCD_4:4;
	UINT8 BCD_5:4;
	UINT8 BCD_6:4;
	UINT8 S:1;
	UINT8 Res0:1;
	UINT8 G:1;
	UINT8 Res1:1;

}sMtFmt03;

typedef struct
{

	UINT8 BCD_0:4;  // BCD ��λ
	UINT8 BCD_1:3;  // BCD ʮλ(0-7)
	UINT8 S0:1;     // S0���壺S0=0����ʾ�ϸ���S0=1����ʾ�¸���

}sMtFmt04;

typedef struct
{

	UINT8 BCD_0_1:4; 	// BCD ʮ��λ
	UINT8 BCD_0  :4;	// BCD ��λ
	UINT8 BCD_1  :4;	// BCD ʮλ
	UINT8 BCD_2  :3;	// BCD ��λ
	UINT8 S      :1;	// BCD ����λ
}sMtFmt05;

typedef struct
{

	UINT8 BCD_0_2:4;   // �ٷ�λ
	UINT8 BCD_0_1:4;   // ʮ��λ
	UINT8 BCD_0:4;     // ��λ
	UINT8 BCD_1:3;     // ʮλ
	UINT8 S:1;         // ����

}sMtFmt06;

typedef struct
{
	UINT8 BCD_0_1:4;  // BCD ʮ��λ
	UINT8 BCD_0  :4;  // BCD ��λ
	UINT8 BCD_1  :4;  // BCD ʮλ
	UINT8 BCD_2  :4;  // BCD ��λ

}sMtFmt07;

typedef struct
{

	UINT8 BCD_0:4;  // BCD��λ
	UINT8 BCD_1:4;  // BCDʮλ
	UINT8 BCD_2:4;  // BCD��λ
	UINT8 BCD_3:4;  // BCDǧλ
}sMtFmt08;

typedef struct
{

	UINT8 BCD_0_4:4;  // BCD ���λ
	UINT8 BCD_0_3:4;  // BCD ǧ��λ
	UINT8 BCD_0_2:4;  // BCD �ٷ�λ
	UINT8 BCD_0_1:4;  // BCD ʮ��λ
	UINT8 BCD_0  :4;  // BCD ��λ
	UINT8 BCD_1  :3;  // BCD ʮλ
    UINT8 S      :1;  // ����λ
}sMtFmt09;

typedef struct
{

	UINT8 BCD_0:4;   //BCD ��λ
	UINT8 BCD_1:4;   //BCD ʮλ
	UINT8 BCD_2:4;   //BCD ��λ
	UINT8 BCD_3:4;   //BCD ǧλ
	UINT8 BCD_4:4;   //BCD ��λ
	UINT8 BCD_5:4;   //BCD ʮ��λ

}sMtFmt10;

typedef struct
{

	UINT8 BCD_0_2:4;   // BCD �ٷ�λ
	UINT8 BCD_0_1:4;   // BCD ʮ��λ
	UINT8 BCD_0  :4;   //BCD ��λ
	UINT8 BCD_1  :4;   //BCD ʮλ
	UINT8 BCD_2  :4;   //BCD ��λ
	UINT8 BCD_3  :4;   //BCD ǧλ
	UINT8 BCD_4  :4;   //BCD ��λ
	UINT8 BCD_5  :4;   //BCD ʮ��λ

}sMtFmt11;

typedef struct
{

	UINT8 BCD_0 :4;    //BCD ��λ
	UINT8 BCD_1 :4;    //BCD ʮλ
	UINT8 BCD_2 :4;    //BCD ��λ
	UINT8 BCD_3 :4;    //BCD ǧλ
	UINT8 BCD_4 :4;    //BCD ��λ
	UINT8 BCD_5 :4;    //BCD ʮ��λ
	UINT8 BCD_6 :4;    //BCD ����λ
	UINT8 BCD_7 :4;    //BCD ǧ��λ
	UINT8 BCD_8 :4;    //BCD ��λ
	UINT8 BCD_9 :4;    //BCD ʮ��λ
	UINT8 BCD_10:4;    //BCD ����λ
	UINT8 BCD_11:4;    //BCD ǧ��λ
}sMtFmt12;


typedef struct
{

	UINT8 BCD_0_4:4;   // BCD ���λ
	UINT8 BCD_0_3:4;   // BCD ǧ��λ
	UINT8 BCD_0_2:4;   // BCD �ٷ�λ
	UINT8 BCD_0_1:4;   // BCD ʮ��λ
	UINT8 BCD_0  :4;   //BCD ��λ
	UINT8 BCD_1  :4;   //BCD ʮλ
	UINT8 BCD_2  :4;   //BCD ��λ
	UINT8 BCD_3  :4;   //BCD ǧλ

}sMtFmt13;


typedef struct
{

	UINT8 BCD_0_4:4;   // BCD ���λ
	UINT8 BCD_0_3:4;   // BCD ǧ��λ
	UINT8 BCD_0_2:4;   // BCD �ٷ�λ
	UINT8 BCD_0_1:4;   // BCD ʮ��λ
	UINT8 BCD_0  :4;   //BCD ��λ
	UINT8 BCD_1  :4;   //BCD ʮλ
	UINT8 BCD_2  :4;   //BCD ��λ
	UINT8 BCD_3  :4;   //BCD ǧλ
	UINT8 BCD_4 :4;    //BCD ��λ
	UINT8 BCD_5 :4;    //BCD ʮ��λ

}sMtFmt14;

typedef struct
{

	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:4;  
	UINT8 yyBCD_0:4;  // ��
	UINT8 yyBCD_1:4;

}sMtFmt15;

typedef struct
{

	UINT8 ssBCD_0:4;  // ��
	UINT8 ssBCD_1:4;
	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;

}sMtFmt16;

typedef struct
{

	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:4;  
}sMtFmt17;

typedef struct
{

	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
}sMtFmt18;

typedef struct
{

	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
}sMtFmt19;

typedef struct
{

	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:4;  
	UINT8 yyBCD_0:4;  // ��
	UINT8 yyBCD_1:4;

}sMtFmt20;

typedef struct
{

	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:4;  
	UINT8 yyBCD_0:4;  // ��
	UINT8 yyBCD_1:4;

}sMtFmt21;


typedef struct
{

	UINT8 BCD_0_1:4;  // ʮ��λ
	UINT8 BCD_0  :4;  // ��λ

}sMtFmt22;

typedef struct
{

	UINT8 BCD_0_4:4;   // BCD ���λ
	UINT8 BCD_0_3:4;   // BCD ǧ��λ
	UINT8 BCD_0_2:4;   // BCD �ٷ�λ
	UINT8 BCD_0_1:4;   // BCD ʮ��λ
	UINT8 BCD_0  :4;   //BCD ��λ
	UINT8 BCD_1  :4;   //BCD ʮλ
}sMtFmt23;

typedef struct
{

	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
}sMtFmt24;

typedef struct
{

	UINT8 BCD_0_3:4;  // BCD ǧ��λ
	UINT8 BCD_0_2:4;  // BCD �ٷ�λ
	UINT8 BCD_0_1:4;  // BCD ʮ��λ
	UINT8 BCD_0  :4;  // BCD ��λ
	UINT8 BCD_1  :3;  // BCD ʮλ
    UINT8 S      :1;  // ����λ
}sMtFmt25;

typedef struct
{

	UINT8 BCD_0_3:4;  // BCD ǧ��λ
	UINT8 BCD_0_2:4;  // BCD �ٷ�λ
	UINT8 BCD_0_1:4;  // BCD ʮ��λ
	UINT8 BCD_0  :4;  // BCD ��λ

}sMtFmt26;


typedef struct
{

	UINT8 BCD_0 :4;    //BCD ��λ
	UINT8 BCD_1 :4;    //BCD ʮλ
	UINT8 BCD_2 :4;    //BCD ��λ
	UINT8 BCD_3 :4;    //BCD ǧλ
	UINT8 BCD_4 :4;    //BCD ��λ
	UINT8 BCD_5 :4;    //BCD ʮ��λ
	UINT8 BCD_6 :4;    //BCD ����λ
	UINT8 BCD_7 :4;    //BCD ǧ��λ

}sMtFmt27;


typedef struct
{

	UINT8 ucIP1;
	UINT8 ucIP2;
	UINT8 ucIP3;
	UINT8 ucIP4;
}sMtIP;

typedef struct
{

	UINT8 ucMask1;
	UINT8 ucMask2;
	UINT8 ucMask3;
	UINT8 ucMask4;
}sMtMask;




/***************************************************************************
 * ���ȷ�������
 *
{*///

// �û�������
typedef struct
{
	eMtCmd  eCmd;         // Fn  1 ~ 241
	UINT16  usPn;         // Pn  0 ~ 2033
	BOOL    bOk;
}sMtuFnPnErr;   // ȷ������� �û������ݽṹ

typedef struct
{
	eMtAFN      eAFN;        // ��Ҫȷ�ϵ�AFN
	UINT8       ucNum;        // ��Ҫȷ�� �� ���ϵ� Fn����
    sMtuFnPnErr sOne[1];  // ucNum ��sMtUFnPnErr
}sMtOnebyOne;                 // �û��� Afn00 F3���ݽṹ




// ֡������
typedef struct
{
	sMtDaDt sDaDt;  // ���ݵ�Ԫ��ʶ
	UINT8   ucErr;  // ���� ��ʶ                  0 ��ȷ 1 ����
}sMtOne_f;       // ȷ������� ֡�����ݽṹ   

typedef struct
{
	UINT8    ucAFN;
	sMtOne_f sOne[1];
}sMtOneByOne_f;


// ת������
eMtErr emtTrans_OneByOne(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen);
///*}


// afn = 04H 
typedef struct
{

	UINT8  ucRTS;        // �ն���������ʱʱ��RTS
	UINT8  ucRTM;        // �ն���Ϊ����վ�����ʹ�����ʱʱ�� slave recieve time out minute
	UINT8  ucSWTS1;      // �ն˵ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ����ط����� wait ts
    UINT8  ucSWTS2;      // �ն˵ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ����ط����� wait ts
	UINT8  bs8Con;       // ��Ҫ��վȷ�ϵ�ͨ�ŷ���CON=1���ı�־
	UINT8  ucHeartBeat;  // ��������

}sMtAfn04F1_ConUpPortPara_f;  //����ͨ�ſ�ͨ�Ų����������ݵ�Ԫ��ʽ (AFN04_F1)    ֡������


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

}sMtAfn04F1_ConUpPortPara_u; //����ͨ�ſ�ͨ�Ų����������ݵ�Ԫ��ʽ (AFN04_F1)    �û�������


typedef struct
{

	UINT8  ucPermit   :1;        // ����M��ֹ���ɵ�1�ֽڵ� D7��ʾ������ֹ�ն�ת������"0"����ֹ���� "1"������
	UINT8  ucAddrCount:7;        // ��ת�����ն˵�ַ��n���ɵ�1�ֽڵ�D0��D6λ��ʾ����ֵ��Χ0��16��
	UINT16 usAddress[1];         // ��ת���ն˵�ַ��ÿ����ַΪ2�ֽڣ����ն˵�ַA2������ͬ
	//UINT16 usAddress[0];         // ��ת���ն˵�ַ��ÿ����ַΪ2�ֽڣ����ն˵�ַA2������ͬ

}sMtAfn04F2_ConUpPortParaWireless_f; // ����ͨ�������м�ת���������ݵ�Ԫ��ʽ(AFN04_F2) 


typedef struct
{

	BOOL   bPermit;           // ����M��ֹ���ɵ�1�ֽڵ� D7��ʾ������ֹ�ն�ת������"0"����ֹ���� "1"������
	UINT8  ucAddrCount;       // ��ת�����ն˵�ַ��n���ɵ�1�ֽڵ�D0��D6λ��ʾ����ֵ��Χ0��16��
	UINT16 usAddress[16];     // ��ת���ն˵�ַ��ÿ����ַΪ2�ֽڣ����ն˵�ַA2������ͬ

}sMtAfn04F2_ConUpPortParaWireless_u; // ����ͨ�������м�ת���������ݵ�Ԫ��ʽ(AFN04_F2) 





typedef struct
{
	UINT8  ucMainIP[4];     // ���õ�ַ
	UINT16 usMainPort;      // ���ö˿�
	UINT8  ucBackIP[4];	    // ���õ�ַ
	UINT16 usBackPort;      // ���ö˿�	
	UINT8  ucascAPN[16];    //    
}sMtAfn04F3_MasterIpPort_f;    // ��վIP��ַ�Ͷ˿����ݵ�Ԫ��ʽ


typedef struct
{
	UINT32  ulMainIP;        // ���õ�ַ
	UINT16  usMainPort;      // ���ö˿�
	UINT32  ulBackIP;	     // ���õ�ַ
	UINT16  usBackPort;      // ���ö˿�	
	UINT8   ucascAPN[16];    //    
}sMtAfn04F3_MasterIpPort_u;    // ��վIP��ַ�Ͷ˿����ݵ�Ԫ��ʽ




/*  sMtAfn04F4_MstSmSTelephoneSm_u

--��ͨ�绰�ŵ���ǰ8�ֽ���Ч������16λ�绰���룬��8�ֽ���Ч��
  ÿλ�������ݷ�Χ0��B��0��9��ʾ�绰����0����9��AΪ"��"��������ͣ�٣���ʱ����BΪ"#"��
--GSM/CDMA�ŵ���ǰ8�ֽڴ�����վ�ֻ��绰���룬��8�ֽڴ������Ϣ�������ĵ绰���롣
--Z0��Z15��Ӧ�绰�����һλ����ĩλ������δ����������FH��

*/

typedef struct
{

    UINT8 ucPhoneMaster[17]; // ��վ�绰����         �֧��16λ�绰����
    UINT8 ucPhoneSMS[17];    // ���ŷ������ĵ绰���� �֧��16λ�绰����

}sMtAfn04F4_MstSmsPhone_u;   // ��վ�绰�����ź������ݵ�Ԫ��ʽ

typedef struct
{

    UINT8 bcdPhoneMaster[8];
    UINT8 bcdPhoneSMS[8]; 

}sMtAfn04F4_MstSmsPhone_f;   // ��վ�绰�����ź������ݵ�Ԫ��ʽ


typedef struct
{

	UINT8  ucSchemeNum; 
	UINT16 usPara;

}sMtAfn04F5_UpMsgAuth_u;   //����ͨ����Ϣ��֤�����������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8  ucSchemeNum; 
	UINT16 usPara;

}sMtAfn04F5_UpMsgAuth_f;   //����ͨ����Ϣ��֤�����������ݵ�Ԫ��ʽ



// afn04_f6 �ն����ַ�������ݵ�Ԫ��ʽ
typedef struct
{

	UINT32 ulGroupAddress[8];

}sMtAfn04F6_ConGroupAddr_u; 

typedef struct
{

	UINT32 ulGroupAddress[8];

}sMtAfn04F6_ConGroupAddr_f; 


// afn04_f7 ������IP��ַ�Ͷ˿� ��������
typedef struct
{

	sMtIP    sTmIp;
	sMtIP    sMask;
	sMtIP    sGate;
	UINT8    ucAgent;
	sMtIP    sAgentSever;
	UINT16   usAgnetPort;
	UINT8    ucAgentLink;
	UINT8    ucUserNameLen;   // 0~20 0 ʱ��ʾû���û��� Ϊ��0ʱ��ʾ��ʱ��Ҫ�û�����֤
    /*  �������ݽṹΪ�䳤
	UINT8    aUserName[ucUserNameLen];   
	UINT8    ucPassWordLen;  // 0~20   0ʱ��ʾû�����룬Ϊ��0 ʱ��ʾ��ʱ��Ҫ������֤
	UINT8    aPassWord[ucPassWordLen];
	UINT16   usTmLisenPort;
	*/
}sMtAfn04F7_ConIpPort_f;

typedef struct
{

	sMtIP    sTmIp;
	sMtIP    sMask;
	sMtIP    sGate;
	UINT8    ucAgent;
	sMtIP    sAgentSever;
	UINT16   usAgnetPort;
	UINT8    ucAgentLink;
	UINT16   usTmLisenPort;
	UINT8    aUserName[21];   // �֧��20λ�û��� ����Ϊ�գ���ʾ����Ҫ�û�����֤   
	UINT8    aPassWord[21];   // �֧��20λ������֤ ����Ϊ�գ���ʾ����Ҫ������֤

}sMtAfn04F7_ConIpPort_u;



// ����������ͨ�Ź�����ʽ����̫ר��������ר����
typedef struct
{

	UINT8  bs8WorkWay;
	UINT16 usTimeInterval;
	UINT8  ucReCallTimes;
	UINT8  ucAutoDropTime;
	UINT8  bs24Permit[3];
}sMtAfn04F8_ConUpComWay_f;


typedef struct
{

	UINT8  bs8WorkWay;
	UINT16 usTimeInterval;
	UINT8  ucReCallTimes;
	UINT8  ucAutoDropTime;
	UINT8  bs24Permit[3];
}sMtAfn04F8_ConUpComWay_u;



// ���������ն�ͨ�Ŷ�ȡ�������в�������
typedef struct
{

	UINT8 bs64EventRecord[8];
	UINT8 bs64EventWeight[8];

}sMtAfn04F9_Con2TmlComPara_f;

typedef struct
{

	UINT8 bs64EventRecord[8];
	UINT8 bs64EventWeight[8];

}sMtAfn04F9_Con2TmlComPara_u;



// ����������ͨ��ģ��Ĳ�������
typedef struct
{

}sMtAfn04F10_ConDownPara_u;



typedef struct
{

}sMtAfn04F10_ConDownPara_f;


// ����ר���û���������
typedef struct
{

}sMtAfn04F11_VpnPwd_u;

typedef struct
{

}sMtAfn04F11_VpnPwd_f;


// ����������ͨ��������������
typedef struct
{

}sMtAfn04F12_ConUpLimit_f;

typedef struct
{

}sMtAfn04F12_ConUpLimit_u;




typedef struct
{

	UINT16 usConfigCount;
    UINT16 usDevSerNum;
	UINT16 usTestPoint;
	UINT8  ucPort;
	UINT8  ucProtocol;
	UINT8  ucbcdIP[4];
	//UINT8 

}sMtAfn04F10_TmMeterConfig;  // �ն˵��ܱ�/����װ���������ݵ�Ԫ��ʽ




typedef struct
{

	UINT8  ucInputPort;   // ��������˿ں�
	UINT8  ucTestPoint;   // �����������
	UINT8  bs8PulseWord;  // ��������
	UINT16 usMeterK;      // �����k

}sMtTmPulseConfig;

typedef struct
{

	UINT8 ucItemCount;   // ������������·��n
	//sMtTmPulseConfig  sItem[0];
	sMtTmPulseConfig  sItem[1];
	
}sMtAfn04F11_TmPulseConfig;

typedef struct
{

	UINT8 bs8StateAccess;
	UINT8 bs8StateAttr;

}sMtAfn04F12_TmStateInput;  // �ն�״̬������������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 ucItemN;
	
}sMtAfn04F13_TmVoltElecAnalog;   // �ն˵�ѹ/����ģ�������ò���

typedef struct
{

	UINT8 ucItemN;

}sMtAfn04F14_TmGroupTotal; // �ն��ܼ������ò������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 ucItemN;

}sMtAfn04F15_HaveLimitEvent;     // �й��ܵ����Խ���¼������������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 strUserName[32];
	UINT8 strPassword[32];

}sMtAfn04F16_VpnUser;//����ר���û������������ݵ�Ԫ��ʽ

typedef struct
{

	sMtFmt02 sFmt02;
	
}sMtAfn04F17_TmGuardValue;

typedef struct
{

	UINT8 bs8CtrlWord[12];
}sMtAfn04F18_TmPowerCtrl; // �ն˹���ʱ�����ݵ�Ԫ��ʽ

typedef struct
{

	sMtFmt04 sFmt04;
}sMtAfn04F19_TmPeriodPowerCtrl; //ʱ�ι��ض�ֵ����ϵ�����ݵ�Ԫ��ʽ

typedef struct
{

	sMtFmt04 sFmt04;
}sMtAfn04F20_TmMonthPowerCtrl; // �µ����ض�ֵ����ϵ�����ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 ucRateID[48];
	UINT8 ucRateNum;

}sMtAfn04F21_TmPeriodRate; // ����������ʱ�κͷ��������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 ucRateNum;
	//sMtFmt03 sFmt03[0];  // ucRateNum ��
	sMtFmt03 sFmt03[1];  // ucRateNum ��

}sMtAfn04F22_TmPowerRate;  // �ն˵������������ݵ�Ԫ��ʽ

typedef struct
{

	UINT8 bs24Alarm[3];

}sMtAfn04F23_TmPayAlarm; // �ն˴߷Ѹ澯�������ݵ�Ԫ��ʽ



typedef struct
{
	UINT16   usVtRatio;// voltage transformer; potential transformer
    UINT16   usCtRatio;// current transformer
    sMtFmt06 sVR;      // voltage rating; rated voltage; nominal voltage 
    sMtFmt22 sCR;       // �����       rated current; current rating
}sMtAfn04F25_TestPoint; // ����������������ݵ�Ԫ��ʽ


typedef struct
{
	sMtFmt07 sQVMax;    // ��ѹ�ϸ�����
	sMtFmt07 sQVMin;    // ��ѹ�ϸ�����
	sMtFmt07 sDropV;    // ��ѹ��������
	sMtFmt07 sOverV;    // ��ѹ����
	UINT8    ucOverVmm; // Խ�޳���ʱ��
	sMtFmt05 sOverVrec; // Խ�޻ָ�ϵ��
	sMtFmt07 sLessV;    // ��ѹ�����ޣ�Ƿѹ���ޣ�
     
}sMtAfn04F26_TestPointLimit; // ��������ֵ�������ݵ�Ԫ��ʽ

typedef struct
{

	sMtFmt26 sRa;
	sMtFmt26 sXa;
	sMtFmt26 sGa;
	sMtFmt26 sBa;
	sMtFmt26 sRb;
	sMtFmt26 sXb;
	sMtFmt26 sGb;
	sMtFmt26 sBb;
	sMtFmt26 sRc;
	sMtFmt26 sXc;
	sMtFmt26 sGc;
	sMtFmt26 sBc;
}sMtAfn04F27_TpCopperIronLoss;//������ͭ������������ݵ�Ԫ��ʽ

/*
 * ��������: double ���͵ĺϳ����ϳ�
 * ����˵��: �������ڻ�����ָ����ʽ��ʾ���ֽ�Ϊ��������β����ָ������ָ���Ĳ��֡� 
 *   �����ǵ����Ȼ���˫�����ڴ洢�ж���Ϊ�������֣�
	1.����λ(Sign) : 0��������1����Ϊ�� 
	2.ָ��λ��Exponent��:���ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�����λ�洢 
	3.β�����֣�Mantissa����β������ 
{*///

typedef union 
{
	double v;
	struct 
	{
		unsigned mantissa2 : 32;
		unsigned mantissa1 : 20;
		unsigned exponent : 11;
		unsigned sign :  1;
	} s;
}uMtDoubleFmt;


int    bMtGetDoubleSign(double dVal);              // ȡ��һ��double�ķ���λ sign = -1 / +1
void   vMtSetDoubleSign(double *pdVal, int sign);  // ����һ���������ķ���λ sign = -1 / +1

///*}

/*
 * ��������: (+/-) ���� * 10(4 ~ -4)  
 * ���ݷ�Χ: (+/-) 9999.999 ~ 99999990000   
 * ����˵��: �û���ʱ��Ҫ��Double  
 * float   : 1bit������λ�� 8bits ��ָ��λ�� 23bits��β��λ��   2^23 = 8388608
 * double  : 1bit������λ�� 11bits��ָ��λ�� 52bits��β��λ��   2^52 = 4503599627370496
 * ת������: bMtTrans_fmtsMillion_to_double
 *           bMtTrans_double_to_fmtsMillion  
 * ���ݸ�ʽ: 
 *
	+--------+----+----+----+----+----+----+----+----+
	|        | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
	+--------+----+----+----+----+----+----+----+----+
	| BYTE 1 |     BCD��ʮλ     |   BCD ���λ      |
	+--------+----+----+----+----+----+----+----+----+
	| BYTE 2 |     BCD��ǧλ     |   BCD ���λ      |
	+--------+----+----+----+----+----+----+----+----+
	| BYTE 3 |    BCD��ʮ��λ    |   BCD ����λ      |
	+--------+----+----+----+----+----+----+----+----+
	| BYTE 4 | G3 | G2 | G1 | S  |   BCD �����λ    |
	+--------+----+----+----+----+----+----+----+----+
	

	+-------+-------+-------+----------+
	|   G3  |  G2   |  G1   |   ����   |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(4)  |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(3)  |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(2)  |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(1)  |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(0)  |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(-1) |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(-2) |
	+-------+-------+-------+----------+
	|   0   |   0   |   0   |   10(-3) |
	+-------+-------+-------+----------+

   S ����λ:S = 0 ���� S = 1 ��ʾ����
	
{*///

typedef struct
{
	UINT8 BCD_0 :4;    // BCD ��λ
	UINT8 BCD_1 :4;    // BCD ʮλ
	UINT8 BCD_2 :4;    // BCD ��λ
	UINT8 BCD_3 :4;    // BCD ǧλ
	UINT8 BCD_4 :4;    // BCD ��λ
	UINT8 BCD_5 :4;    // BCD ʮ��λ
	UINT8 BCD_6 :4;    // BCD ����λ
	UINT8 S     :1;    // ����λ      0 Ϊ�� 1 Ϊ��
	UINT8 G1    :1;    // ָ��bit 0
	UINT8 G2    :1;    // ָ��bit 1
	UINT8 G3    :1;    // ָ������λ
}sMtFmtsMillion;


#define MT_SMILLION_MIN -99999990000.0
#define MT_SMILLION_MAX  99999990000.0


BOOL   bMtTrans_fmtsMillion_to_double(sMtFmtsMillion *psMtFmtsMillion, double *pdValue);
eMtErr eMtTrans_double_to_fmtsMillion(double dValue, int nExp, sMtFmtsMillion *psMtFmtsMillion);
int  nMtPow(UINT8 exp);   // 10 exp�η� exp < 10

///*}


/* 
 * ��������:�ǵ�������������  
 * ��������:CMD_AFN_4_FN_33_CFG_NOT_ELEC
 * ����˵��:�ǵ�����ͳһ�ø����ݽṹ������
 * 1���¶ȣ�2��������3�����٣�4��ѹ����5��ʪ�ȣ�6���նȣ�7��ת�٣�����������
{*///

typedef enum
{
	MT_NELEC_UNKOWN,  // δ֪�ǵ�����
	MT_NELEC_TEMP,    // �¶�
	MT_NELEC_FLOW,    // ����
	MT_NELEC_FLOW_V,  // ����
    MT_NELEC_PRESS,   // ѹ��
	MT_NELEC_HUMID,   // ʪ�� humidity
	MT_NELEC_ILLUM,   // �ն� illumination
	MT_NELEC_ROTATE,  // ת�� rotate speed
}eMtNotElec;

#define MT_NOT_ELEC_RANG_MAX   99999990000.0
#define MT_NOT_ELEC_RANG_MIN  -99999990000.0

typedef struct
{
	eMtNotElec eType;  // ����
	double     dMin;   // ��������  ����С�� MT_NOT_ELEC_RANG_MIN
	double     dMax;   // ��������  ���ܴ��� MT_NOT_ELEC_RANG_MAX
	
}sMtCfgNotElec;   


typedef struct
{
	UINT8          ucType;
	sMtFmtsMillion sMin;
	sMtFmtsMillion sMax;
}sMtCfgNotElec_f; 

eMtErr emtTrans_CfgNotElecValue(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen);
///*} �ǵ�������������




/* 
 * ��������:�ǵ�����  
 * ��������:CMD_AFN_C_FN_90_NOT_ELEC
 * ����˵��:�ǵ�����ͳһ�ø����ݽṹ������
 * 1���¶ȣ�2��������3�����٣�4��ѹ����5��ʪ�ȣ�6���նȣ�7��ת�٣�����������
{*///


typedef struct
{	
	eMtNotElec eType;    // ����
	double     dValue;   // ����
}sMtNotElec;   


typedef struct
{
	UINT8          ucType;
	sMtFmtsMillion sValue;
}sMtNotElec_f; 

eMtErr emtTrans_NotElecValue(eMtTransDir eDir,void *psUser, void *psFrame, UINT16 *pusfLen);
///*} �ǵ�������������





typedef struct
{


	UINT8 ucLimitPowerTime:4; // �޵�ʱ��
	UINT8 ucHoldAlarmTime :4; // �澯��ʱʱ��
	
}sMtAfn05F1_RemoteCtrlTrip_f; // ң����բ���ݵ�Ԫ��ʽ


typedef struct
{

	UINT8 ucLimitPowerTime;   // �޵�ʱ�� ��ֵ��Χ0��15����λ��0.5h�����Сʱ����
	                          //Ϊ0ʱ����ʾ������բ������ʱ����բ�����Զ������բ״̬��
	                          //��Ϊ0ʱ�������õ��޵�ʱ������޵硣
	UINT8 ucHoldAlarmTime;    // �澯��ʱʱ�� 
	                          // ��ֵ��Χ0��15����λ��min��Ϊ"0"ʱ����ʾ������բ��
	                          // ��Ϊ0ʱ�������õĸ澯ʱ����и澯��
	
}sMtAfn05F1_RemoteCtrlTrip_u; // ң����բ���ݵ�Ԫ��ʽ



typedef struct
{

	UINT8 bs8Word;
    UINT8 ucWay;

}sMtAfn05F9_PeriodPowerCtrl;  // ʱ�ι���Ͷ�����ݵ�Ԫ��ʽ



typedef struct
{
    UINT8 ssBCD_0:4;  // ��
	UINT8 ssBCD_1:4;
	UINT8 mmBCD_0:4;  // ��
	UINT8 mmBCD_1:4;
	UINT8 hhBCD_0:4;  // ʱ
	UINT8 hhBCD_1:4;
	UINT8 ddBCD_0:4;  // ��
	UINT8 ddBCD_1:4;
	UINT8 MMBCD_0:4;  // ��
	UINT8 MMBCD_1:1;  
	UINT8 wwBCD_0:3;  // ����
	UINT8 yyBCD_0:4;  // ��
	UINT8 yyBCD_1:4;

}sMtAfn05F31_TimeTick_f;  // ��ʱ�������ݽṹ �û���


typedef struct
{
    UINT8 ucYY;   // year   ��ʽ YY
    UINT8 ucMM;   // month  �� 
    UINT8 ucWW;   // weak   ����  0 ��ʾ��Ч  1 - 7
    UINT8 ucDD;   // Day    ��
    UINT8 ucHH;   // hour   ʱ
    UINT8 ucmm;   // minute ����
    UINT8 ucss;   // second ��
    
}sMtAfn05F31_TimeTick_u;  // ��ʱ�������ݽṹ �û���


typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F49_PortSuspend_u;



typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F49_PortSuspend_f;




typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F50_PortResume_u;



typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F50_PortResume_f;



typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F51_PortAgain_u;


typedef struct
{
    UINT8 ucPort;    // 1 - 31
}sMtAfn05F51_PortAgain_f;





// �����֤����Ӧ��
typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F1_IdAuthQ_u;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F1_IdAuthQ_f;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F2_IdAuthA_f;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F2_IdAuthA_u;



// �����������Ӧ��
typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F3_RandQ_f;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F3_RandQ_u;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F4_RandA_f;

typedef struct
{
    UINT8 aCiphertext[16];
}sMtAfn06F4_RandA_u;



typedef struct
{

}sMtAfn09F1_ConVersion_u;  // �������汾��Ϣ


typedef struct
{

}sMtAfn09F1_ConVersion_f;  // �������汾��Ϣ





typedef struct
{


}sMtAfn09F4_ConParaCfg_u; // ������֧�ֵĲ�������


typedef struct
{


}sMtAfn09F4_ConParaCfg_f; // ������֧�ֵĲ�������



typedef struct
{


}sMtAfn09F5_ConCtrlCfg_u; // ������֧�ֵĿ�������    CMD_AFN_9_FN_5_SUPPORT_CTRL_CFG


typedef struct
{


}sMtAfn09F5_ConCtrlCfg_f; // ������֧�ֵĿ�������




typedef struct
{


}sMtAfn09F6_ConAsk1Cfg_u; // ������֧�ֵ�1���������� CMD_AFN_9_FN_6_SUPPORT_ASK1_CFG


typedef struct
{


}sMtAfn09F6_ConAsk1Cfg_f; // ������֧�ֵ�1����������



typedef struct
{


}sMtAfn09F7_ConAsk2Cfg_u; // ������֧�ֵ�1���������� CMD_AFN_9_FN_7_SUPPORT_ASK2_CFG


typedef struct
{


}sMtAfn09F7_ConAsk2Cfg_f; // ������֧�ֵ�1����������



typedef struct
{


}sMtAfn09F8_ConEvntCfg_u; // ������֧�ֵ��¼���¼���� CMD_AFN_9_FN_8_SUPPORT_EVNT_CFG


typedef struct
{


}sMtAfn09F8_ConEvntCfg_f; // ������֧�ֵ��¼���¼����









// ���ݵ�Ԫ�ṹת������
typedef eMtErr (*pMtTransFunc)(eMtTransDir eDir, void* pUser, void* pFrame, UINT16 *pusfLen);  // pusFLenΪ��������֡��ĳ���

/*

typedef struct
{

	eMtCmd 		   eCmd;
	eMtDir         eDir;      // ���ֱ����ܷ��ķ���
	eMtPn 		   ePn;
	pMtTransFunc   pFunc;
	//char*  		   pstrName;
	CString        strName;
}sMtCmdInfor;     // �뵥һ��������ص���Ϣ
*/
typedef enum
{

	MT_ROLE_UNKOWN,   // δ֪���
	MT_ROLE_MASTER,   // ��վ
	MT_ROLE_CONTOR,   // ������ �� �ն�

}eMtRole;


typedef struct
{
    eMtRole eRole;                  // ��ݣ���վ���Ǵ�վ
    UINT8   ucPermitDelayMinutes;   // ����ʱ��
    UINT8   aucPw[MT_PW_LEN];
    

}sMtProtoInit;    // Э���ʼ�����ݽṹ

typedef struct
{
	UINT8  ucRegionCode[2];          // ����������(BCD)  ���ֽ���ǰ  ���ֽ��ں�
	UINT16 usTAddress;               // �ն˵�ַ  (BIN) A2  ��Χ(1 ~ 4294967295)
	//UINT8  ucTeamAddr:1;             // Ϊ1��ʾ usTerminalAddress Ϊ���ַ,A2 == 0xFFFF���㲥��ַ, Ϊ 0 ��ʾ����ַ
	UINT8  ucMAddress;        // ��վ��ַ	 ��ò�Ҫ��λ��
	
}sMtfAddress; // ֡��ַ��ʽ����


typedef struct
{

	UINT8  acRegionCode[5];    // ����������(BCD)  �籱�� 1100   
    //UINT16  usRegionCode;		 // ����������(BCD)  �籱�� 1100  
	//UINT32 ulTAddress;           // �ն˻�������ַ  (BIN) A2 ��Χ(1 ~ 4294967295)
    UINT16 usTAddress;           // �ն˻�������ַ  (BIN) A2 ��Χ(1 ~ 65535)
	BOOL   bTeamAddr;            // Ϊtrue��ʾ ulTAddress Ϊ���ַ�� Ϊ false ��ʾulTAddress����ַ
	UINT8  ucMAddress;           // ��վ��ַ	��Χ(0~127)

}sMtuAddress;

typedef struct
{

	BOOL     bTpv;     // ��ʾ֡����û�� ʱ���ǩ Tp
	BOOL     bCon;     // �Ƿ���Ҫȷ��
	eMtFmPos ePos;     // λ��
	UINT8    ucSEQ;    // SEQ = PFC & 0x0F
}sMtuSEQ;

typedef struct
{

	UINT8 SEQ:4;
	UINT8 CON:1;
	UINT8 FIN:1;
	UINT8 FIR:1;
	UINT8 TpV:1;
}sMtfSEQ;

typedef struct
{
    UINT8 ucPFC;                 // ����֡֡��ż�����PFC
    UINT8 ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��
    UINT8 ucDD;                  // ��
    UINT8 ucHH;                  // ʱ
    UINT8 ucmm;                  // ��
    UINT8 ucss;                  // ��
}sMtuTp;                         // ʱ���ǩ��ʽTP �û������ݽṹ


typedef struct
{
     UINT8    ucPFC;                 // ����֡֡��ż�����PFC
     sMtFmt16 sTime;                 // ����֡����ʱ��
     UINT8    ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��
}sMtfTp;     // ֡��ʱ���ǩ��ʽTP���ݽṹ


/*
+------+------+-------+------+------+------+------+------+
|  D7  |  D6  |  D5   |  D4  |  D3  |  D2  |  D1  |  D0  |
+------+------+-------+------+------+------+------+------+
|  DIR | PRM  |FCB/ACD|  FCV |  
+------+------+-------+------+------+------+
*/

typedef enum
{

    MT_PRM_UNKWON,    // δ֪����
	MT_PRM_ACTIVE,    // ��֡����������վ
	MT_PRM_PASIVE,    // ��֡�����ڴӶ�վ

}eMtPRM;      // ��������PRM�ֶ����� 

typedef enum
{
    FCD_PRM_1_RESET     = 1,        // ��λ����
    FCD_PRM_1_USER      = 4,        // �û�����
    FCD_PRM_1_LINK      = 9,        // ��·����
    FCD_PRM_1_ASK_1     = 10,       // ����1������
    FCD_PRM_1_ASK_2     = 11,       // ����2������

}eFcodePrm1; // ���б��Ŀ���������

typedef enum
{
    FCD_PRM_0_OK        = 0,        // �Ͽ�
    FCD_PRM_0_USER      = 8,        // �û�����
    FCD_PRM_0_NONE      = 9,        // ����:�����ٻ�������
    FCD_PRM_0_LINK      = 11,       // ��·״̬

}eFcodePrm0; // ���б��Ŀ���������

typedef struct
{
    BOOL             bAcd;       // Ҫ�����λ
   
}sMtuCtrlUp;  // ���п�����������Ϣ�ṹ

typedef struct
{    
    BOOL           bFcv;       // ֡������ЧλFCV
    UINT8          btFCB:1;    // ֡����λ
    UINT8          btRcv:7;    // ��������   
}sMtuCtrlDown; // ���п�����������Ϣ�ṹ

typedef struct
{

	eMtDir eDir;       // 0 ��ʾ���б���  1 ��ʾ����
	eMtPRM ePRM;       // ��־�ñ�������������վ ���ǴӶ�վ

    union
	{
       sMtuCtrlUp sUp;          // ����
       sMtuCtrlDown sDown;      // ����
    }uDir;

    union
    {
        eFcodePrm0 eFcdPrm0;   // �Ӷ�վ
        eFcodePrm1 eFcdPrm1;   // ����վ
    }uFCode;  // ������
    	
}sMtuCtrl;   //�������û������ݽṹ 

typedef struct
{
    sMtuAddress suAddr;          // ��ַ��Ϣ
    sMtuCtrl    suCtrl;
    sMtuSEQ     suSEQ;         
    
    UINT8       *pSeq2Cs;        // ��SEQ �� CS ֮�������
    UINT16      usSeq2CsLen;     // ��SEQ �� CS ֮������ݵĳ���
}sMtPackCommon;


typedef struct
{

	UINT8       f68;          // 1
	UINT8       p10:2;        // ��Э���ʶ  1 1
	UINT8       L1 :6;        // 2
	UINT8       L2;           // 3
	UINT8       s68;          // 4
	UINT8       C;            // 5
	sMtfAddress A;            // 6 (+7) ~ 12
	UINT8       AFN;          // 13
	UINT8       SEQ;          // 14

}sMtfComHead;                // ֡�๫����ͷ�ṹ



typedef struct
{
    // ��ѡ��
    sMtuAddress  suAddress;          // ��ַ��Ϣ
    eMtCmd eCmd;                     // ������
    UINT16 usPn;                     // ��Ϣ��Ԫ���� (0 ~ 2033)
    UINT8  ucPFC;                    // ����֡������ ÿ������վ�ʹӶ�վ֮�䶼��ά��һ�������ĸü�����

    // ��ѡ��
    union
    {
        sMtAfn04F1_ConUpPortPara_u sMtAfn04F1_TmUpPortPara; // ����Ӧ���� CMD_AFN_4_FN_1_TM_UP_CFG 
      
    }uData;

}sMtuPack;   // ��װ֡����


typedef struct
{
     // ��ѡ��
    sMtuAddress  suAddress;          // ��ַ��Ϣ
    eMtCmd eCmd;                     // ������
    UINT16 usPn;                     // ��Ϣ��Ԫ���� (0 ~ 2033)
    // UINT8  ucPFC;                 // ����֡������ ÿ������վ�ʹӶ�վ֮�䶼��ά��һ�������ĸü�����

    UINT8    ucSEQ;   
    eMtFmPos ePos;     // λ��
    // Э�������
    sMtuCtrl    suCtrl;

    // ���������ֶ�����Ч��
    BOOL bEC;
    BOOL bPW;
    BOOL bTP;
	BOOL bCon;     // �Ƿ���Ҫȷ��
	

    // ��������
    sMtEC  sEC;         // �¼�������
    sMtuTp sTP;         // tp�ֶ�
    UINT8  aucPW[16];   // pw�ֶ�

    // Ӧ�ò�����
    union
    {
        sMtAfn04F1_ConUpPortPara_u sMtAfn04F1_TmUpPortPara; // ����Ӧ���� CMD_AFN_4_FN_1_TM_UP_CFG 

    }uData;
     
}sMtuUnpack; // ���װ���ݽṹ



typedef struct
{
    eMtCmd eSubCmd;     // ��������
    UINT16 usPN;        // ��������һ������
    UINT16 usLen;       // ���������ӦӦ�ò����ݵĳ���, ����ͬһ���������֡�Ӧ�ò�����ʱ��ʱ��
    union
    {
		
        sMtAfn04F1_ConUpPortPara_u          sAfn04F1_ConUpPortPara; 
        sMtAfn04F2_ConUpPortParaWireless_u  sAfn04F2_ConUpPortParaWireless;
        sMtAfn04F3_MasterIpPort_u           sAfn04F3_MasterIpPort;
        sMtAfn05F1_RemoteCtrlTrip_u         sAfn05F1_RemoteCtrlTrip;
        sMtAfn05F31_TimeTick_u              sAfn05F31_TimeTick;
        sMtAfn06F1_IdAuthQ_u                sAfn06F1_IdAuthQ;
        sMtAfn06F2_IdAuthA_u                sAfn06F2_IdAuthA;
        sMtAfn06F3_RandQ_u                  sAfn06F3_RandQ;
        sMtAfn06F4_RandA_u                  sAfn06F4_RandA;
        sMtOnebyOne                         sAfn00F3_OneByOne;
     
		
		//
		sMtCfgNotElec                       sCfgNotElec;
		sMtNotElec                          sNotElec;
    }uAppData;// Ӧ�ò����� ����

}smtSub; // �����Ӧ�ò�����


typedef struct
{
    /* ��ѡ�� */
    sMtuAddress  sAddress;               // ��ַ��Ϣ
    eMtAFN       eMainCmd;               // ��������
	
	// ������
    sMtuCtrl     sCtrl;                  // ������   �������Ϣ
    eMtFmPos     ePos;                   // λ��   ���ʱ�����Ըò���
    UINT8        ucSEQ;                  // SEQ�ֶ� �� P/RSEQ  ��Χ(0~15)
    BOOL         bCon;                   // �Ƿ���Ҫȷ��	

    // ������
    BOOL bEC;
    BOOL bPW;
    BOOL bTP;

    sMtEC  sEC;                         // �¼�������
    sMtuTp sTP;                         // tp�ֶ�
    UINT8  aucPW[17];                   // pw�ֶ�

    /* �䳤�� */
    UINT8    ucSubNum;                  // ��֡�а����������ֵĸ������ֵ(255)
	smtSub   sSub[1];                   // ���������ͼ�Ӧ�ò����� �䳤

}smtPack;       // �û����װ��ͷ�װ���ݽṹ















// ת����������������
// �û������ݽṹ��֡�����ݽṹת��





eMtErr emt_trans_Afn04F1_ConUpPortPara(eMtTransDir eDir,
                                      void  *pUser,
                                      void  *pFrame,
                                      UINT16 *pusfLen);


eMtErr emt_trans_Afn04F2_ConUpPortParaWireless(eMtTransDir eDir,
                                              void  *pUser,
                                              void  *pFrame,
                                              UINT16 *pusfLen);


eMtErr emt_trans_Afn04F3_MasterIpPort(eMtTransDir eDir,
                                      void  *pUser,
                                      void  *pFrame,
                                      UINT16 *pusfLen);



eMtErr emt_trans_Afn04F4_MstSmsPhone(eMtTransDir eDir,
                                        void  *psUser,
                                        void  *psFrame,
                                        UINT16 *pusfLen);



eMtErr emt_trans_Afn04F5_UpMsgAuth(eMtTransDir eDir,
                                   void  *psUser,
                                   void  *psFrame,
                                   UINT16 *pusfLen);


eMtErr emt_trans_Afn04f6_ConGroupAddr(eMtTransDir eDir,
                                      void  *psUser,
                                      void  *psFrame,
                                      UINT16 *pusfLen);

// ������ip��ַ�����������ݽṹת������
eMtErr emt_trans_Afn04F7_ConIpPort(eMtTransDir eDir,
                                   void  *psUser,
                                   void  *psFrame,
                                   UINT16 *pusfLen);

// ����������ͨ�Ź�����ʽ����̫ר��������ר����
eMtErr emt_trans_Afn04F8_ConUpComWay(eMtTransDir eDir,
                                    void  *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);


// ���������ն�ͨ�Ŷ�ȡ�������в������� ���ݽṹת������
eMtErr emt_trans_Afn04F9_Con2TmlComPara(eMtTransDir eDir,
                                        void  *psUser,
                                        void  *psFrame,
                                        UINT16 *pusfLen);




eMtErr emt_trans_Afn04F10_ConDownPara(eMtTransDir eDir,
                                      void  *psUser,
                                      void  *psFrame,
                                       UINT16 *pusfLen);



eMtErr emt_trans_Afn04F11_VpnPwd(eMtTransDir eDir,
                                 void  *psUser,
                                 void  *psFrame,
                                 UINT16 *pusfLen);



eMtErr emt_trans_Afn04F12_ConUpLimit(eMtTransDir eDir,
                                     void  *psUser,
                                     void  *psFrame,
                                     UINT16 *pusfLen);






eMtErr emt_trans_Afn05F1_RemoteCtrlTrip(eMtTransDir eDir,
                                        void  *psUser,
                                        void  *psFrame,
                                        UINT16 *pusfLen);



eMtErr emt_trans_Afn05F31_TimeTick(eMtTransDir eDir,
                                   void  *psUser,
                                   void  *psFrame,
                                   UINT16 *pusfLen);


eMtErr emt_trans_Afn05F49_PortSuspend(eMtTransDir eDir,
                                      void  *psUser,
                                      void  *psFrame,
                                      UINT16 *pusfLen);


eMtErr emt_trans_Afn05F50_PortResume(eMtTransDir eDir,
                                     void  *psUser,
                                     void  *psFrame,
                                     UINT16 *pusfLen);


eMtErr emt_trans_Afn05F51_PortAgain(eMtTransDir eDir,
                                    void  *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);




// �����֤�������ݽṹת������
eMtErr emt_trans_Afn06F1_IdAuthQ(eMtTransDir eDir,
                                 void  *psUser,
                                 void  *psFrame,
                                 UINT16 *pusfLen);

eMtErr emt_trans_Afn06F2_IdAuthA(eMtTransDir eDir,
                                 void  *psUser,
                                 void  *psFrame,
                                 UINT16 *pusfLen);



eMtErr emt_trans_Afn06F3_RandQ(eMtTransDir eDir,
                               void  *psUser,
                               void  *psFrame,
                               UINT16 *pusfLen);

eMtErr emt_trans_Afn06F4_RandA(eMtTransDir eDir,
                               void  *psUser,
                               void  *psFrame,
                               UINT16 *pusfLen);



eMtErr emt_trans_Afn09F1_ConVersion(eMtTransDir eDir,
                                    void  *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);




eMtErr emt_trans_Afn09F4_ConParaCfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);


eMtErr emt_trans_Afn09F5_ConCtrlCfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);





eMtErr emt_trans_Afn09F6_ConAsk1Cfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);




eMtErr emt_trans_Afn09F7_ConAsk2Cfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);




eMtErr emt_trans_Afn09F8_ConEvntCfg(eMtTransDir eDir,
                                    void *psUser,
                                    void  *psFrame,
                                    UINT16 *pusfLen);











#endif
#pragma pack(pop)  // һ�ֽڶ���

#endif // _NX_RULER_TYPES_H_