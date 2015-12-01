// NxConfig.h: interface for the CNxConfig class.
// ʵ�ֶԵ�ַ�����Ӧ���Ӧ�ò����ݽ���Ԥ���ã�����Щ��Ϣд��ע���
// 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NXCONFIG_H__1DD12D49_5364_4329_A836_16957971D23E__INCLUDED_)
#define AFX_NXCONFIG_H__1DD12D49_5364_4329_A836_16957971D23E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Registry.h"
//#include "NxRulerTypes.h"
#include "Qgdw3761api.h"
#include "Gbnx_31.h"

#define INDEX_AFN_00_CONF   0//AFN 00 ȷ�Ϸ���     
#define INDEX_AFN_01_RSET   1 //AFN 01 ��λ����
#define INDEX_AFN_02_LINK   2//AFN 02 ��·�ӿڼ��     
//#define INDEX_AFN_03_RELY   3//AFN 03 �м�վ����     
#define INDEX_AFN_04_SETP   3//AFN 04 ���ò���     
#define INDEX_AFN_05_CTRL   4//AFN 05 ��������     
#define INDEX_AFN_06_AUTH   5//AFN 06 �����֤����ԿЭ��     
#define INDEX_AFN_08_CASC   6 //AFN 08 ���󱻼����ն������ϱ�     
//#define INDEX_AFN_09_CFIG   7//AFN 09 �����������ü���Ϣ    
#define INDEX_AFN_0A_GETP   7//AFN 0A ��ѯ����     
//#define INDEX_AFN_0B_ASKT   9//AFN 0B ������������    
#define INDEX_AFN_0C_ASKT   8//AFN 0C ����1������    
#define INDEX_AFN_0D_ASKR   9//AFN 0D ����2������    
#define INDEX_AFN_0E_ASKE   10//AFN 0E ����3������     
#define INDEX_AFN_0F_FILE   11//AFN 0F �ļ�����     
#define INDEX_AFN_10_DATA   12//AFN 10 ����ת��    


#define STR_AFN_00_CONF   "AFN 00 ȷ�Ϸ���"     // ȷ�Ϸ���
#define STR_AFN_01_RSET   "AFN 01 ��λ����"     // ��λ
#define STR_AFN_02_LINK   "AFN 02 ��·���"     // �ӿڼ��
//#define STR_AFN_03_RELY   "AFN 03 �м�վ���� "     // �м�վ����
#define STR_AFN_04_SETP   "AFN 04 ���ò���"     // ���ò���
#define STR_AFN_05_CTRL   "AFN 05 ��������"     // ��������
#define STR_AFN_06_AUTH   "AFN 06 �����֤����ԿЭ��"     // �����֤
#define STR_AFN_08_CASC   "AFN 08 ���󱻼����ն������ϱ�"     // ���󱻼����ն������ϱ� 
//#define STR_AFN_09_CFIG   "AFN 09 �����������ü���Ϣ"     // �����ն�����
#define STR_AFN_0A_GETP   "AFN 0A ��ѯ����"     // ��ѯ����
//#define STR_AFN_0B_ASKT   "AFN 0B ������������"     // ������������
#define STR_AFN_0C_ASKT   "AFN 0C ������������"     // ����1������ ʵʱ����
#define STR_AFN_0D_ASKR   "AFN 0D ����ʵʱ����"     // ����2������ ��ʷ����
#define STR_AFN_0E_ASKE   "AFN 0E �����¼���¼"     // ����3������ �¼�����
#define STR_AFN_0F_FILE   "AFN 0F �ļ�����"     // �ļ�����
#define STR_AFN_10_DATA   "AFN 10 ����ת��"     // ����ת��

/*
#define STR_AFN_00_CONF    "ȷ�Ϸ���(AFN=00H)"     // ȷ�Ϸ���
#define STR_AFN_01_RSET   "��λ����(AFN=01H)"     // ��λ
#define STR_AFN_02_LINK   "��·�ӿڼ��(AFN=02H)"     // �ӿڼ��
#define STR_AFN_03_RELY   "�м�վ����(AFN=04H)"     // �м�վ����
#define STR_AFN_04_SETP    "���ò���(AFN=04H)"     // ���ò���
#define STR_AFN_05_CTRL    "��������(AFN=05H)"     // ��������
#define STR_AFN_06_AUTH    "�����֤����ԿЭ��(AFN=06H)"     // �����֤
#define STR_AFN_08_CASC    0x08     // ���󱻼����ն������ϱ� 
#define STR_AFN_09_CFIG    "�����������ü���Ϣ(AFN=09H)"     // �����ն�����
#define STR_AFN_0A_GETP    "��ѯ����(AFN=0AH)"     // ��ѯ����
#define STR_AFN_0B_ASKT   "������������(AFN=0BH)"     // ������������
#define STR_AFN_0C_ASK1     "����1������(AFN=0CH)"     // ����1������ ʵʱ����
#define STR_AFN_0D_ASK2  "����2������(AFN=0DH)"     // ����2������ ��ʷ����
#define STR_AFN_0E_ASK3   "����3������(AFN=0EH)"     // ����3������ �¼�����
#define STR_AFN_0F_FILE    "�ļ�����(AFN=0FH)"     // �ļ�����
#define STR_AFN_10_DATA    "����ת��(AFN=10H)"     // ����ת��


*/

// AFN_00
#define STR_AFN_00_F1  "F1   ȫ��ȷ��/����"
#define STR_AFN_00_F2  "F2   �����ݵ�Ԫ��ʶȷ�Ϻͷ���"
//#define STR_AFN_00_F3  "F3   �����ݵ�Ԫ��ʶȷ�Ϻͷ���"

// AFN_01
#define STR_AFN_01_F1   "F1   Ӳ����ʼ��"
#define STR_AFN_01_F2   "F2   ��������ʼ��"
#define STR_AFN_01_F3   "F3   ������ȫ����������ʼ��(���ָ�����������)"
#define STR_AFN_01_F4   "F4   ����(����ϵͳ��վͨ���йص�)��ȫ����������ʼ��"
#define STR_AFN_01_F5   "F5   ָ����������"

// AFN_02
#define STR_AFN_02_F1   "F1   ��¼"
#define STR_AFN_02_F2   "F2   �˳�"
#define STR_AFN_02_F3   "F3   ����"
#define STR_AFN_02_F4   "F4   ȷ�ϣ���¼���˳���������"

// AFN_03
#define STR_AFN_03_F1   "F1   �м�վ����״̬����"
#define STR_AFN_03_F2   "F2   �м�վ����״̬��ѯ"
#define STR_AFN_03_F3   "F3   �м�վ����״̬�л���¼����"
#define STR_AFN_03_F4   "F4   �м�վ����״̬ͳ�Ʋ�ѯ"

// AFN 04
#define STR_AFN_04_F1   "F1   ��Ϣ�����뽻���ն�����ͨ�ſ�ͨ�Ų���"
#define STR_AFN_04_F2   "F2   ��(��)վ����"
#define STR_AFN_04_F3   "F3   ��Ϣ�����뽻���ն�����ͨ����Ϣ��֤����"
#define STR_AFN_04_F4   "F4   ��Ϣ�����뽻���ն����ַ"
#define STR_AFN_04_F5   "F5   ��Ϣ�����뽻���ն�IP��ַ�Ͷ˿�"
#define STR_AFN_04_F6   "F6   ��Ϣ�����뽻���ն˼���ͨ�Ų���"
#define STR_AFN_04_F7   "F7   ��Ϣ�����뽻���ն�������̫���˿�ͨ�Ų���"
// #define STR_AFN_04_F8   "F8   ����������ͨ�Ź�����ʽ(��̫ר��������ר��)"

#define STR_AFN_04_F9   "F9   �¼���¼����"
#define STR_AFN_04_F10  "F10  �豸״̬���������"
// #define STR_AFN_04_F11  "F11  �ն��������ò���"
// #define STR_AFN_04_F12  "F12  �ն�/������״̬���������"
// #define STR_AFN_04_F13  "F13  �ն˵�ѹ/����ģ�������ò���"
// #define STR_AFN_04_F14  "F14  �ն��ܼ������ò���"
// #define STR_AFN_04_F15  "F15  �й��ܵ�����������¼���������"
// #define STR_AFN_04_F16  "F16  ����ר���û���������"

#define STR_AFN_04_F17  "F17  ����ն�����ͨ�Ų�������"
// #define STR_AFN_04_F18  "F18  �ն˹���ʱ��"
// #define STR_AFN_04_F19  "F19  �ն�ʱ�ι��ض�ֵ����ϵ��"
// #define STR_AFN_04_F20  "F20  �ն��µ������ض�ֵ����ϵ��"
// #define STR_AFN_04_F21  "F21  �ն˵���������ʱ�κͷ�����"
// #define STR_AFN_04_F22  "F22  �ն˵���������"
// #define STR_AFN_04_F23  "F23  �ն˴߸澯����"

#define STR_AFN_04_F25  "F25  �������������ò���"
#define STR_AFN_04_F26  "F26  �����������������"
#define STR_AFN_04_F27  "F27  �����������������ֵ����"
#define STR_AFN_04_F28  "F28  ���������㹦������Խ��ֵ����"
#define STR_AFN_04_F29  "F29  ����������г��������Խ�޶�ֵ"
#define STR_AFN_04_F30  "F30  ��������������Խ�޲���"
// #define STR_AFN_04_F31  "F31  �ز��ӽڵ㸽���ڵ��ַ"


#define STR_AFN_04_F33  "F33  �ǵ������������ò���"
#define STR_AFN_04_F34  "F34  �ǵ������������ݲ���"
#define STR_AFN_04_F35  "F35  �ǵ���������Խ�����ݲ���"
// #define STR_AFN_04_F36  "F36  �ն�����ͨ��������������"
// #define STR_AFN_04_F37  "F37  �ն˼���ͨ�Ų���"
// #define STR_AFN_04_F38  "F38  1��������������"
// #define STR_AFN_04_F39  "F39  2��������������"

//6
// #define STR_AFN_04_F41  "F41  ʱ�ι��ض�ֵ"
// #define STR_AFN_04_F42  "F42  ���ݹ��ز���"
// #define STR_AFN_04_F43  "F43  ���ʿ��ƵĹ��ʼ��㻬��ʱ��"
// #define STR_AFN_04_F44  "F44  Ӫҵ��ͣ�ز���"
// #define STR_AFN_04_F45  "F45  �����ִ��趨"
// #define STR_AFN_04_F46  "F46  �µ����ض�ֵ"
// #define STR_AFN_04_F47  "F47  ������(��)�ز���"
// #define STR_AFN_04_F48  "F48  ����ִ��趨"

//7
#define STR_AFN_04_F49  "F49  ���������������"

// 8
// #define STR_AFN_04_F57  "F57  �ն������澯����/��ֹ����"
// #define STR_AFN_04_F58  "F58  �ն��Զ���������"
// #define STR_AFN_04_F59  "F59  ���ܱ��쳣�б���ֵ����"
// #define STR_AFN_04_F60  "F60  г����ֵ"
// #define STR_AFN_04_F61  "F61  ֱ��ģ�����������"
// 
// 9
// #define STR_AFN_04_F65  "F65  ��ʱ�ϱ�1��������������"
// #define STR_AFN_04_F66  "F66  ��ʱ�ϱ�2��������������"
// #define STR_AFN_04_F67  "F67  ��ʱ�ϱ�1��������������/ֹͣ����"
// #define STR_AFN_04_F68  "F68  ��ʱ�ϱ�2��������������/ֹͣ����"
// 10
// #define STR_AFN_04_F73  "F73  ����������"
// #define STR_AFN_04_F74  "F74  ������Ͷ�����в���"
// #define STR_AFN_04_F75  "F75  ��������������"
// #define STR_AFN_04_F76  "F76  ������Ͷ�п��Ʒ�ʽ"
// 
// 11
// #define STR_AFN_04_F81  "F81  ֱ��ģ�������"
// #define STR_AFN_04_F82  "F82  ֱ��ģ������ֵ"
// #define STR_AFN_04_F83  "F83  ֱ��ģ�����������"

// AFN 05
//1
#define STR_AFN_05_F1    "F1   Уʱ����"
#define STR_AFN_05_F2    "F2   ��ʱ��������"
#define STR_AFN_05_F3    "F3   ������Ϣ�����뽻���ն������ϱ�"
#define STR_AFN_05_F4    "F4   ��ֹ��Ϣ�����뽻���ն������ϱ�"
#define STR_AFN_05_F5    "F5   ������Ϣ�����뽻���ն�������(��)վ"
#define STR_AFN_05_F6    "F6   ������Ϣ�����뽻���ն˶Ͽ�����"
// 2
#define STR_AFN_05_F9    "F9   ң����բ"
#define STR_AFN_05_F10   "F10  �����բ"
// #define STR_AFN_05_F11   "F11  Ӫҵ��ͣ����Ͷ��"
// #define STR_AFN_05_F12   "F12  ��ǰ�����¸���Ͷ��"
// #define STR_AFN_05_F15   "F15  �µ��Ͷ��"
// #define STR_AFN_05_F16   "F16  �����Ͷ��"

//3
#define STR_AFN_05_F17   "F17  ��Чģ����Ч"
#define STR_AFN_05_F18   "F18  ��Чģ�����"
#define STR_AFN_05_F19   "F19  ������Ӧ��Ϣ��Ч"
#define STR_AFN_05_F20   "F20  ������Ӧ��Ϣ���"
// #define STR_AFN_05_F23   "F23  �µ�ؽ��"
// #define STR_AFN_05_F24   "F24  ����ؽ��"

//4
#define STR_AFN_05_F25   "F25  ������ʱ�ϱ�������������"
#define STR_AFN_05_F26   "F26  ��ֹ��ʱ�ϱ�������������"
#define STR_AFN_05_F27   "F27  ����������������"
#define STR_AFN_05_F28   "F28  ������������ֹͣ"
// #define STR_AFN_05_F29   "F29  �����ն������ϱ�"
// 
// #define STR_AFN_05_F31   "F31  ��ʱ����"
// #define STR_AFN_05_F32   "F32  ������Ϣ"
// 
// //5
// #define STR_AFN_05_F33  "F33  �ն˵籣���"
// #define STR_AFN_05_F34  "F34  �߷Ѹ澯���"
// #define STR_AFN_05_F35  "F35  ��ֹ�ն�����վͨ��"
// #define STR_AFN_05_F36  "F36  �ն��޳����"
// #define STR_AFN_05_F37  "F37  ��ֹ�ն������ϱ�"
// #define STR_AFN_05_F38  "F38  �����ն�������վ"
// #define STR_AFN_05_F39  "F39  �����ն˶Ͽ�����"
// 
// //6
// #define STR_AFN_05_F41  "F41  ����������Ͷ��"
// #define STR_AFN_05_F42  "F42  ���������ƽ��"
// 
// //7
// #define STR_AFN_05_F49  "F49  ����ָ��ͨ�Ŷ˿���ͣ����"
// #define STR_AFN_05_F50  "F50  ����ָ��ͨ�Ŷ˿ڻָ�����"
// #define STR_AFN_05_F51  "F51  ����ָ��ͨ�Ŷ˿����³���"
// #define STR_AFN_05_F52  "F52  ��ʼ��ָ��ͨ�Ŷ˿��µ�ȫ���м�·����Ϣ"
// #define STR_AFN_05_F53  "F53  ɾ��ָ��ͨ�Ŷ˿��µ�ȫ�����"




// afn 06
#define STR_AFN_06_F1   "F1  �����֤����"
#define STR_AFN_06_F2   "F2  �����֤��Ӧ"
#define STR_AFN_06_F3   "F3  ȡ���������"
#define STR_AFN_06_F4   "F4  ȡ�������Ӧ"

// afn 8
#define STR_AFN_08_F1   "F1  ���󱻼����ն������ϱ�"

// afn 09
//1
// #define STR_AFN_09_F1   "F1  �ն˰汾��Ϣ"
// #define STR_AFN_09_F2   "F2  �ն�֧�ֵ����롢�����ͨ�Ŷ˿�����"
// #define STR_AFN_09_F3   "F3  �ն�֧�ֵ���������"
// 
// #define STR_AFN_09_F4   "F4  �ն�֧�ֵĲ�������"
// #define STR_AFN_09_F5   "F5  �ն�֧�ֵĿ�������"
// #define STR_AFN_09_F6   "F6  �ն�֧�ֵ�1����������"
// #define STR_AFN_09_F7   "F7  �ն�֧�ֵ�2����������"
// #define STR_AFN_09_F8   "F8  �ն�֧�ֵ��¼���¼����"


// AFN 0A  ��ѯ����
//1 
#define STR_AFN_0A_F1   "F1   ��ѯ��Ϣ�����뽻���ն�����ͨ�ſ�ͨ�Ų���"
#define STR_AFN_0A_F2   "F2   ��ѯ��(��)վ����"
#define STR_AFN_0A_F3   "F3   ��ѯ��Ϣ�����뽻���ն�����ͨ����Ϣ��֤����"
#define STR_AFN_0A_F4   "F4   ��ѯ��Ϣ�����뽻���ն����ַ"
#define STR_AFN_0A_F5   "F5   ��ѯ��Ϣ�����뽻���ն�IP��ַ�Ͷ˿�"
#define STR_AFN_0A_F6   "F6   ��ѯ��Ϣ�����뽻���ն˼���ͨ�Ų���"
#define STR_AFN_0A_F7   "F7   ��Ϣ�����뽻���ն�������̫���˿�ͨ�Ų���"
// #define STR_AFN_0A_F8   "F8   ����������ͨ�Ź�����ʽ"
//2
#define STR_AFN_0A_F9   "F9   ��ѯ�¼���¼����"
#define STR_AFN_0A_F10  "F10  ��ѯ�豸״̬���������"
#define STR_AFN_0A_F11  "F11  �豸�߼���ַ"
#define STR_AFN_0A_F12  "F12  ��ѯ�豸�汾��Ϣ"
#define STR_AFN_0A_F13  "F13  �����õ�����������Ϣ"
#define STR_AFN_0A_F14  "F14  �����÷ǵ�����������Ϣ"
#define STR_AFN_0A_F15  "F15  �豸֧�ֵ��¼���¼"
/*#define STR_AFN_0A_F16  "F16  ����ר���û���������"*/

// 3
#define STR_AFN_0A_F17  "F17  ��ѯ����ն˵�����ͨ�Ų���"
// #define STR_AFN_0A_F18  "F18  �ն˹���ʱ��"
// #define STR_AFN_0A_F19  "F19  �ն�ʱ�ι��ض�ֵ����ϵ��"
// #define STR_AFN_0A_F20  "F20  �ն��µ������ض�ֵ����ϵ��"
// #define STR_AFN_0A_F21  "F21  �ն˵���������ʱ�κͷ�����"
// #define STR_AFN_0A_F22  "F22  �ն˵���������"
// #define STR_AFN_0A_F23  "F23  �ն˴߸澯����"


//4
#define STR_AFN_0A_F25  "F25  ��ѯ�������������ò���"
#define STR_AFN_0A_F26  "F26  ��ѯ�����������������"
#define STR_AFN_0A_F27  "F27  ��ѯ�����������������ֵ����"
#define STR_AFN_0A_F28  "F28  ��ѯ���������㹦������Խ��ֵ����"
#define STR_AFN_0A_F29  "F29  ��ѯ����������г��������Խ�޶�ֵ"
#define STR_AFN_0A_F30  "F30  ��ѯ��������������Խ�޲���"
// #define STR_AFN_0A_F31  "F31  �ز��ӽڵ㸽���ڵ��ַ"

//5
#define STR_AFN_0A_F33  "F33  ��ѯ�ǵ������������ò���"
#define STR_AFN_0A_F34  "F34  ��ѯ�ǵ������������ݲ���"
#define STR_AFN_0A_F35  "F35  ��ѯ�ǵ�������������Խ�޲�������"
// #define STR_AFN_0A_F36  "F36  �ն�����ͨ��������������"
// #define STR_AFN_0A_F37  "F37  �ն˼���ͨ�Ų���"
// #define STR_AFN_0A_F38  "F38  1��������������"
// #define STR_AFN_0A_F39  "F39  1��������������"

//6
// #define STR_AFN_0A_F41  "F41  ʱ�ι��ض�ֵ"
// #define STR_AFN_0A_F42  "F42  ���ݹ��ز���"
// #define STR_AFN_0A_F43  "F43  ���ʿ��ƵĹ��ʼ��㻬��ʱ��"
// #define STR_AFN_0A_F44  "F44  Ӫҵ��ͣ�ز���"
// #define STR_AFN_0A_F45  "F45  �����ִ��趨"
// #define STR_AFN_0A_F46  "F46  �µ����ض�ֵ"
// #define STR_AFN_0A_F47  "F47  ������(��)�ز���"
// #define STR_AFN_0A_F48  "F48  ����ִ��趨"

//7
#define STR_AFN_0A_F49  "F49  ��ѯ���������������"

//8
#define STR_AFN_0A_F57  "F57  ��ѯ�����ü���ն���Ϣ"
// #define STR_AFN_0A_F58  "F58  �ն��Զ���������"
// #define STR_AFN_0A_F59  "F59  ���ܱ��쳣�б���ֵ����"
// #define STR_AFN_0A_F60  "F60  г����ֵ"
// #define STR_AFN_0A_F61  "F61  ֱ��ģ�����������"

// 9
// #define STR_AFN_0A_F65  "F65  ��ʱ�ϱ�1��������������"
// #define STR_AFN_0A_F66  "F66  ��ʱ�ϱ�2��������������"
// #define STR_AFN_0A_F67  "F67  ��ʱ�ϱ�1��������������/ֹͣ����"
// #define STR_AFN_0A_F68  "F68  ��ʱ�ϱ�2��������������/ֹͣ����"
// 10
// #define STR_AFN_0A_F73  "F73  ����������"
// #define STR_AFN_0A_F74  "F74  ������Ͷ�����в���"
// #define STR_AFN_0A_F75  "F75  ��������������"
// #define STR_AFN_0A_F76  "F76  ������Ͷ�п��Ʒ�ʽ"
// 
// 11
// #define STR_AFN_0A_F81  "F81  ֱ��ģ�������"
// #define STR_AFN_0A_F82  "F82  ֱ��ģ������ֵ"
// #define STR_AFN_0A_F83  "F83  ֱ��ģ�����������"


// AFN 0B
#define STR_AFN_0B_F1   "F1   ����ʱ�ϱ�1����������" 
#define STR_AFN_0B_F2   "F2   ����ʱ�ϱ�2����������"


// AFN 0C
//1 
#define STR_AFN_0C_F1   "F1   ������ʱ��������Ķ�������"
// #define STR_AFN_0C_F2   "F2   ���󣨶�ʱ�ϱ���������������"

// #define STR_AFN_0C_F4   "F4   �ն�����ͨ��״̬"
// #define STR_AFN_0C_F5   "F5   �ն˿�������״̬"
// #define STR_AFN_0C_F6   "F6   �ն˵�ǰ����״̬"
// #define STR_AFN_0C_F7   "F7   �ն��¼���������ǰֵ"
// #define STR_AFN_0C_F8   "F8   �ն��¼���־״̬"

//2
#define STR_AFN_0C_F9   "F9   ���󣨶�ʱ�ϱ���������������"
// #define STR_AFN_0C_F10  "F10  �ն�����վ���ա���ͨ������"
// #define STR_AFN_0C_F11  "F10  �ն˼��г���״̬��Ϣ"
// 
// //3
// #define STR_AFN_0C_F17  "F17  ��ǰ�ܼ��й�����"
// #define STR_AFN_0C_F18  "F18  ��ǰ�ܼ��޹�����"
// #define STR_AFN_0C_F19  "F19  �����ܼ��й�������"
// #define STR_AFN_0C_F20  "F20  �����ܼ��޹�������"
// #define STR_AFN_0C_F21  "F21  �����ܼ��й�������"
// #define STR_AFN_0C_F22  "F22  �����ܼ��޹�������"
// #define STR_AFN_0C_F23  "F23  �ն˵�ǰʣ�����(��)"
// #define STR_AFN_0C_F24  "F24  ��ǰ�����¸��ؿغ��ܼ��й����ʶ���ֵ"
// 
// //4
// #define STR_AFN_0C_F25  "F25  ��ǰ���༰����/�޹����ʡ���������, �����ѹ��������������������ڹ���"
// #define STR_AFN_0C_F26  "F26  A��B��C�������ͳ�����ݼ����һ�ζ����¼"
// #define STR_AFN_0C_F27  "F27  ���ܱ�����ʱ�ӡ���̴����������һ�β���ʱ��"
// #define STR_AFN_0C_F28  "F28  �������״̬�ּ����λ��־"
// #define STR_AFN_0C_F29  "F29  ��ǰͭ�������й��ܵ���ʾֵ"
// #define STR_AFN_0C_F30  "F30  ��һ�����յ�ǰͭ�������й��ܵ���ʾֵ"
// #define STR_AFN_0C_F31  "F31  ��ǰA��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"
// #define STR_AFN_0C_F32  "F32  ��һ������A��B��C������/�����й�����ʾֵ������޹�1/2����ʾֵ"
// 
// //5
// #define STR_AFN_0C_F33  "F33  ��ǰ������/�޹�(����޹�1)����ʾֵ��һ/�������޹�����ʾֵ"
// #define STR_AFN_0C_F34  "F34  ��ǰ������/�޹�(����޹�2)����ʾֵ����/�������޹�����ʾֵ"
// #define STR_AFN_0C_F35  "F35  ����������/�޹��������������ʱ��"
// #define STR_AFN_0C_F36  "F36  ���·�����/�޹��������������ʱ��"
// #define STR_AFN_0C_F37  "F37  ����(��һ������)������/�޹�(����޹�1)����ʾֵ��һ/�������޹�����ʾֵ"
// #define STR_AFN_0C_F38  "F38  ����(��һ������)������/�޹�(����޹�2)����ʾֵ����/�������޹�����ʾֵ"
// #define STR_AFN_0C_F39  "F39  ���£���һ�����գ�������/�޹��������������ʱ��"
// #define STR_AFN_0C_F40  "F40  ���£���һ�����գ�������/�޹��������������ʱ��"
// 
// //6
// #define STR_AFN_0C_F41  "F41  ���������й�������"
// #define STR_AFN_0C_F42  "F42  ���������޹�������"
// #define STR_AFN_0C_F43  "F43  ���շ����й�������"
// #define STR_AFN_0C_F44  "F44  ���շ����޹�������"
// #define STR_AFN_0C_F45  "F45  ���������й�������"
// #define STR_AFN_0C_F46  "F46  ���������޹�������"
// #define STR_AFN_0C_F47  "F47  ���·����й�������"
// #define STR_AFN_0C_F48  "F48  ���·����޹�������"
// 
// //7
// #define STR_AFN_0C_F49  "F49  ��ǰ��ѹ��������λ��"
// 
// //8
// 
// #define STR_AFN_0C_F57  "F57  ��ǰA��B��C�����ѹ������2��N��г����Чֵ"
// #define STR_AFN_0C_F58  "F58  ��ǰA��B��C�����ѹ������2��N��г��������"
// 
// //9
// #define STR_AFN_0C_F65  "F65  ��ǰ������Ͷ��״̬"
// #define STR_AFN_0C_F66  "F66  ��ǰ�������ۼƲ���Ͷ��ʱ��ʹ���"
// #define STR_AFN_0C_F67  "F67  ���ա����µ������ۼƲ������޹�������"
// 
// //10
// 
// #define STR_AFN_0C_F73  "F73  ֱ��ģ����ʵʱ����"
// //11
// #define STR_AFN_0C_F81  "F81  Сʱ�����ܼ��й�����"
// #define STR_AFN_0C_F82  "F82  Сʱ�����ܼ��޹�����"
// #define STR_AFN_0C_F83  "F83  Сʱ�����ܼ��й��ܵ�����"
// #define STR_AFN_0C_F84  "F84  Сʱ�����ܼ��޹��ܵ�����"
// 
// //12
// #define STR_AFN_0C_F89  "F89  Сʱ�����й�����"
// #define STR_AFN_0C_F90  "F90  Сʱ����A���й�����"
// #define STR_AFN_0C_F91  "F91  Сʱ����B���й�����"
// #define STR_AFN_0C_F92  "F92  Сʱ����C���й�����"
// #define STR_AFN_0C_F93  "F93  Сʱ�����޹�����"
// #define STR_AFN_0C_F94  "F94  Сʱ����A���޹�����"
// #define STR_AFN_0C_F95  "F95  Сʱ����B���޹�����"
// #define STR_AFN_0C_F96  "F96  Сʱ����C���޹�����"
// //13
// #define STR_AFN_0C_F97  "F97  Сʱ����A���ѹ"
// #define STR_AFN_0C_F98  "F98  Сʱ����B���ѹ"
// #define STR_AFN_0C_F99  "F99  Сʱ����C���ѹ"
// #define STR_AFN_0C_F100  "F100  Сʱ����A�����"
// #define STR_AFN_0C_F101  "F101  Сʱ����B�����"
// #define STR_AFN_0C_F102  "F102  Сʱ����C�����"
// #define STR_AFN_0C_F103  "F103  Сʱ�����������"
// 
// //14
// #define STR_AFN_0C_F105  "F105  Сʱ���������й��ܵ�����"
// #define STR_AFN_0C_F106  "F106  Сʱ���������޹��ܵ�����"
// #define STR_AFN_0C_F107  "F107  Сʱ���ᷴ���й��ܵ�����"
// #define STR_AFN_0C_F108  "F108  Сʱ���ᷴ���޹��ܵ�����"
// #define STR_AFN_0C_F109  "F109  Сʱ���������й��ܵ���ʾֵ"
// #define STR_AFN_0C_F110  "F110  Сʱ���������޹��ܵ���ʾֵ"
// #define STR_AFN_0C_F111  "F111  Сʱ���ᷴ���й��ܵ���ʾֵ"
// #define STR_AFN_0C_F112  "F112  Сʱ���ᷴ���޹��ܵ���ʾֵ"
// 
// //15
// #define STR_AFN_0C_F113  "F113  Сʱ�����ܹ�������"
// #define STR_AFN_0C_F114  "F114  Сʱ����A�๦������"
// #define STR_AFN_0C_F115  "F115  Сʱ����B�๦������"
// #define STR_AFN_0C_F116  "F116  Сʱ����C�๦������"
// 
// // 16
// #define STR_AFN_0C_F121  "F121  Сʱ����ֱ��ģ����"
// 
// //17
// #define STR_AFN_0C_F129  "F129  ��ǰ�����й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F130  "F130  ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F131  "F131  ��ǰ�����й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F132  "F132  ��ǰ�����޹�������޹�1������ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F133  "F133  ��ǰһ�����޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F134  "F134  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F135  "F135  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F136  "F136  ��ǰ�������޹�����ʾֵ���ܡ�����1��M��"
// //18
// #define STR_AFN_0C_F137  "F137  ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F138  "F138  ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F139  "F139  ���£���һ�����գ������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F140  "F140  ���£���һ�����գ������޹�������޹�1������ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F141  "F141  ���£���һ�����գ�һ�����޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F142  "F142  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F143  "F143  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F144  "F144  ���£���һ�����գ��������޹�����ʾֵ���ܡ�����1��M��"
// 
// //19
// #define STR_AFN_0C_F145  "F145  ���������й��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F146  "F146  ���������޹��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F147  "F147  ���·����й��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F148  "F148  ���·����޹��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F149  "F149  ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F150  "F150  ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F151  "F151  ���£���һ�����գ������й��������������ʱ�䣨�ܡ�����1��M��"
// #define STR_AFN_0C_F152  "F152  ���£���һ�����գ������޹��������������ʱ�䣨�ܡ�����1��M��"
// //20
// #define STR_AFN_0C_F153  "F153  ��һʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F154  "F154  �ڶ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F155  "F155  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F156  "F156  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F157  "F157  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F158  "F158  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F159  "F159  ����ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// #define STR_AFN_0C_F160  "F160  �ڰ�ʱ�����������й�����ʾֵ���ܡ�����1��M��"
// //21
// #define STR_AFN_0C_F161  "F161  ���ܱ�Զ�̿���ͨ�ϵ�״̬����¼"
// #define STR_AFN_0C_F165  "F165  ���ܱ��ز���������ʱ��"
// #define STR_AFN_0C_F166  "F166  ���ܱ�����޸Ĵ�����ʱ��"
// #define STR_AFN_0C_F167  "F167  ���ܱ����õ���Ϣ"
// #define STR_AFN_0C_F168  "F168  ���ܱ������Ϣ"
// 
// //22
// #define STR_AFN_0C_F169  "F169  ���г����м�·����Ϣ"
// #define STR_AFN_0C_F170  "F170  ���г���������Ϣ"



 //��1   pn: p0/����ն˺�
#define STR_CMD_AFN_D_F1_CLOCK                     "F1  ����ʱ��"
#define STR_CMD_AFN_D_F2_PARA_STATE                "F2  ����״̬��־"
#define STR_CMD_AFN_D_F3_EVENT_1                   "F3  ��Ҫ�¼���������ǰֵ"
#define STR_CMD_AFN_D_F4_EVENT_2                   "F4  һ���¼���������ǰֵ"
#define STR_CMD_AFN_D_F5_EVENT_STATE               "F5  �¼�״̬��־"
#define STR_CMD_AFN_D_F6_POWR_TIMES                "F6  �ϵ����"   
//��2   pn:p0/����ն˺�
#define STR_CMD_AFN_D_F9_STATE                     "F9  ״̬������λ��־"
#define STR_CMD_AFN_D_F10_SWITCH                   "F10 ���������·���ؽ���״̬������λ��־"   
//��4   pn:p0/�����������
#define STR_CMD_AFN_D_F25_POWR_HAVE_T              "F25 ���й�����"
#define STR_CMD_AFN_D_F26_POWR_NONE_T              "F26 ���޹�����"
#define STR_CMD_AFN_D_F27_FACTR_T                  "F27 �ܹ�������"
#define STR_CMD_AFN_D_F28_FACTR_A                  "F28 A�๦������"
#define STR_CMD_AFN_D_F29_FACTR_B                  "F29 B�๦������"
#define STR_CMD_AFN_D_F30_FACTR_C                  "F30 C�๦������"    
//��5   pn:p0/�����������
#define STR_CMD_AFN_D_F33_DEMAND                   "F33 ����"
#define STR_CMD_AFN_D_F34_DEMAND_MAX               "F34 ���������"
#define STR_CMD_AFN_D_F35_DEMAND_TIME              "F35 �������������ʱ��"   
 //��6   pn:�����������
#define STR_CMD_AFN_D_F41_POWR_HAVE_A              "F41 A���й�����"
#define STR_CMD_AFN_D_F42_POWR_HAVE_B              "F42 B���й�����"
#define STR_CMD_AFN_D_F43_POWR_HAVE_C              "F43 C���й�����"
#define STR_CMD_AFN_D_F44_POWR_NONE_A              "F44 A���޹�����"
#define STR_CMD_AFN_D_F45_POWR_NONE_B              "F45 B���޹�����"
#define STR_CMD_AFN_D_F46_POWR_NONE_C              "F46 C���޹�����"   
 //��7   pn:�����������
#define STR_CMD_AFN_D_F49_POWR_HAVE_FRTH           "F49 (����)�й��ܵ���ʾ��"
#define STR_CMD_AFN_D_F50_POWR_HAVE_BACK           "F50 (����)�й��ܵ���ʾ��"
#define STR_CMD_AFN_D_F51_POWR_NONE_FRTH           "F51 (����)�޹��ܵ���ʾ��"
#define STR_CMD_AFN_D_F52_POWR_NONE_BACK           "F52 (����)�޹��ܵ���ʾ��"   
 //��8 pn:�����������
#define STR_CMD_AFN_D_F57_VOLT_A                   "F57 A���ѹ"
#define STR_CMD_AFN_D_F58_VOLT_B                   "F58 B���ѹ"
#define STR_CMD_AFN_D_F59_VOLT_C                   "F59 C���ѹ"
#define STR_CMD_AFN_D_F60_VANGL_A                  "F60 A���ѹ��λ��"
#define STR_CMD_AFN_D_F61_VANGL_B                  "F61 B���ѹ��λ��"
#define STR_CMD_AFN_D_F62_VANGL_C                  "F62 C���ѹ��λ��"
#define STR_CMD_AFN_D_F63_VOLT_UBL                 "F63 ��ѹ��ƽ���"
#define STR_CMD_AFN_D_F64_CIRCLE_V                 "F64 �ܲ�"    
//��9 pn:�����������
#define STR_CMD_AFN_D_F65_ELEC_A                   "F65 A�����"
#define STR_CMD_AFN_D_F66_ELEC_B                   "F66 B�����"
#define STR_CMD_AFN_D_F67_ELEC_C                   "F67 C�����"
#define STR_CMD_AFN_D_F68_ELEC_M                   "F68 �����ߵ���"
#define STR_CMD_AFN_D_F69_EANGL_A                  "F69 A�������λ��"
#define STR_CMD_AFN_D_F70_EANGL_B                  "F70 B�������λ��"
#define STR_CMD_AFN_D_F71_EANGL_C                  "F71 C�������λ��"
#define STR_CMD_AFN_D_F72_ELEC_UBL                 "F72 ������ƽ���"   
 //��10 pn:�����������
#define STR_CMD_AFN_D_F73_VDMAX_A                  "F73 ��A���ѹ����ֵ"
#define STR_CMD_AFN_D_F74_VDMAX_A_TIME             "F74 ��A���ѹ����ֵ����ʱ��"
#define STR_CMD_AFN_D_F75_VDMAX_B                  "F75 ��B���ѹ����ֵ"
#define STR_CMD_AFN_D_F76_VDMAX_B_TIME             "F76 ��B���ѹ����ֵ����ʱ��"
#define STR_CMD_AFN_D_F77_VDMAX_C                  "F77 ��C���ѹ����ֵ"
#define STR_CMD_AFN_D_F78_VDMAX_C_TIME             "F78 ��C���ѹ����ֵ����ʱ��"   
 //��11 pn:�����������
#define STR_CMD_AFN_D_F81_IDMAX_A                  "F81 ��A���������ֵ"
#define STR_CMD_AFN_D_F82_IDMAX_A_TIME             "F82 ��A���������ֵ����ʱ��"
#define STR_CMD_AFN_D_F83_IDMAX_B                  "F83 ��B���������ֵ"
#define STR_CMD_AFN_D_F84_IDMAX_B_TIME             "F84 ��B���������ֵ����ʱ��"
#define STR_CMD_AFN_D_F85_IDMAX_C                  "F85 ��C���������ֵ"
#define STR_CMD_AFN_D_F86_IDMAX_C_TIME             "F86 ��C���������ֵ����ʱ��"   
 //��12 pn:�����������
#define STR_CMD_AFN_D_F89_TFW_HAVE                 "F89 �ܻ����й�����"
#define STR_CMD_AFN_D_F90_TFW_NONE                 "F90 �ܻ����޹�����"
#define STR_CMD_AFN_D_F91_THW_HAVE                 "F91 ��г���й�����"
#define STR_CMD_AFN_D_F92_THW_NONE                 "F92 �ܻ����޹�����"   
 //��13 pn:�����������
#define STR_CMD_AFN_D_F97_VDPP_TIME_A              "F97 A���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F98_VDPP_TIME_B              "F98 B���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F99_VDPP_TIME_C              "F99 C���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F100_VDNN_TIME_A             "F100 A���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F101_VDNN_TIME_B             "F101 B���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F102_VDNN_TIME_C             "F102 C���ѹԽ���������ۼ�ʱ��"  
  //��14 pn:�����������
#define STR_CMD_AFN_D_F105_VMPP_TIME_A             "F105 A���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F106_VMPP_TIME_B             "F106 B���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F107_VMPP_TIME_C             "F107 C���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F108_VMNN_TIME_A             "F108 A���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F109_VMNN_TIME_B             "F109 B���ѹԽ���������ۼ�ʱ��"
#define STR_CMD_AFN_D_F110_VMNN_TIME_C             "F110 C���ѹԽ���������ۼ�ʱ��"   
 //��15 pn:����������� (aberrance)"
#define STR_CMD_AFN_D_F113_VABR_TOTL_A             "F113 A���ѹ�ܻ�����"
#define STR_CMD_AFN_D_F114_VABR_TOTL_B             "F114 B���ѹ�ܻ�����"
#define STR_CMD_AFN_D_F115_VABR_TOTL_C             "F115 C���ѹ�ܻ�����"
#define STR_CMD_AFN_D_F116_EABR_TOTL_A             "F116 A������ܻ�����"
#define STR_CMD_AFN_D_F117_EABR_TOTL_B             "F117 B������ܻ�����"
#define STR_CMD_AFN_D_F118_EABR_TOTL_C             "F118 C������ܻ�����"   
 //��16 pn:�����������
#define STR_CMD_AFN_D_F121_VABR_ODD_A              "F121 A���ѹ��λ�����"
#define STR_CMD_AFN_D_F122_VABR_EVN_A              "F122 A���ѹż�λ�����"
#define STR_CMD_AFN_D_F123_VABR_ODD_B              "F123 B���ѹ��λ�����"
#define STR_CMD_AFN_D_F124_VABR_EVN_B              "F124 B���ѹż�λ�����"
#define STR_CMD_AFN_D_F125_VABR_ODD_C              "F125 C���ѹ��λ�����"
#define STR_CMD_AFN_D_F126_VABR_EVN_C              "F126 C���ѹż�λ�����"   
 //��17 pn:�����������
#define STR_CMD_AFN_D_F128_EABR_OOD_A              "F128 A�������λ�����"
#define STR_CMD_AFN_D_F129_EABR_EVN_A              "F129 A�����ż�λ�����"
#define STR_CMD_AFN_D_F130_EABR_OOD_B              "F130 B�������λ�����"
#define STR_CMD_AFN_D_F131_EABR_EVN_B              "F131 B�����ż�λ�����"
#define STR_CMD_AFN_D_F132_EABR_OOD_C              "F132 C�������λ�����"
#define STR_CMD_AFN_D_F133_EABR_EVN_C              "F133 C�����ż�λ�����"  
  //��18 pn:�����������
#define STR_CMD_AFN_D_F137_FLS_SHRT_A              "F137 A���ʱ����"
#define STR_CMD_AFN_D_F138_FLS_SHRT_B              "F138 B���ʱ����"
#define STR_CMD_AFN_D_F139_FLS_SHRT_C              "F139 C���ʱ����"
#define STR_CMD_AFN_D_F140_FLS_LONG_A              "F140 A�೤ʱ����"
#define STR_CMD_AFN_D_F141_FLS_LONG_B              "F141 B�೤ʱ����"
#define STR_CMD_AFN_D_F142_FLS_LONG_C              "F142 C�೤ʱ����"   
 //��19 pn:�����������
#define STR_CMD_AFN_D_F145_HARM_VOLT_A             "F145 A��N��г����ѹ"
#define STR_CMD_AFN_D_F146_HARM_VOLT_B             "F146 B��N��г����ѹ"
#define STR_CMD_AFN_D_F147_HARM_VOLT_C             "F147 C��N��г����ѹ"
#define STR_CMD_AFN_D_F148_HARM_ELEC_A             "F148 A��N��г������"
#define STR_CMD_AFN_D_F149_HARM_ELEC_B             "F149 B��N��г������"
#define STR_CMD_AFN_D_F150_HARM_ELEC_C             "F150 C��N��г������"   
 //��20 pn:�����������
#define STR_CMD_AFN_D_F153_HARM_VINC_A             "F153 A��N��г����ѹ������"
#define STR_CMD_AFN_D_F154_HARM_VINC_B             "F154 B��N��г����ѹ������"
#define STR_CMD_AFN_D_F155_HARM_VINC_C             "F155 C��N��г����ѹ������"
#define STR_CMD_AFN_D_F156_HARM_EINC_A             "F156 A��N��г������������"
#define STR_CMD_AFN_D_F157_HARM_EINC_B             "F157 B��N��г������������"
#define STR_CMD_AFN_D_F158_HARM_EINC_C             "F158 C��N��г������������"   
 //��30 pn:�ǵ����������
#define STR_CMD_AFN_D_F233_NELC_VALUE              "F233 �ǵ�����"


// ����3������
#define STR_AFN_0E_F1   "F1  ������Ҫ�¼�"
#define STR_AFN_0E_F2   "F2  ����һ���¼�"
#define STR_AFN_0E_F3   "F3  ����ָ���¼�"

// AFN 0F
#define STR_AFN_0F_F1   "F1  �ļ����䷽ʽ1"

// AFN 10
#define STR_AFN_10_F1   "F1   ͸��ת��"
#define STR_AFN_10_F9   "F9   ת����վֱ�Ӷ��ն˵ĳ�����������"
#define STR_AFN_10_F10  "F10  ת����վֱ�Ӷ��ն˵�ң����բ/�����բ����"
#define STR_AFN_10_F11  "F11  ת����վֱ�Ӷ��ն˵�ң���͵�����"




// ��λ���Ͷ���
#define FMT_MINUTE "��"
#define FMT_SECOND "��"
#define FMT_MS_20  "20ms"
#define FMT_TIMES   "��"
#define FMT_BOOL    "����ֵ"
#define FMT_PN      "�������"
#define FMT_NULL      ""
#define FMT_UINT8      "UINT8"


typedef struct _CHAR2DECIMAL
{
	char c;
	unsigned char bValue;
}CHAR2DECIMAL, *PCHAR2DECIMAL;

const CHAR2DECIMAL c2a[22] = {
	{'0', 0},
	{'1', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'a', 10},
	{'A', 10},
	{'b', 11},
	{'B', 11},
	{'c', 12},
	{'C', 12},
	{'d', 13},
	{'D', 13},
	{'e', 14},
	{'E', 14},
	{'f', 15},
	{'F', 15}
};


class CNxConfig  
{
public:
		void initConfig();

private:
	HKEY    m_hRootKey;    // д��ע��ĸ�λ��
 	CString m_rootName;  // ��վԤ����ע���������
	CString m_mstPreName;  // ��վԤ����ע���������
	CString m_tmlPreName;  // �ն�Ԥ����ע���������
	CString m_configMst;   // ��վ��ַ �˿ں� ����ʱ�ӣ������
	CString m_configTml;   // �ն˵�ַ �˿ں� ����ʱ��  �����

	
public:
	UINT8 GetIpNum(CString strIp, int index);
	// ��ַ
	void SetPreAddress(sMcAddress *psAddr, BOOL bMaster, BOOL bReWrite = TRUE); // ���õ�ַԤ����Ϣ
	void GetPreAddress(sMcAddress *psAddr, BOOL bMaster = TRUE); // ��ȡ��ַԤ����Ϣ





	// afn00
	void SetPreAfn00F1(sMcAfn00F1 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	void GetPreAfn00F1(sMcAfn00F1 *pData, BOOL bMaster = TRUE);


    // afn 04
	// f1
	BOOL SetPreAfn04F1(sMcAfn04f1 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F1(sMcAfn04f1 *pData, BOOL bMaster = TRUE);
	// f2
	BOOL SetPreAfn04F2(sMcAfn04f2 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F2(sMcAfn04f2 *pData, BOOL bMaster = TRUE);


	
	// F3
	BOOL SetPreAfn04F3(sMcAfn04f3 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F3(sMcAfn04f3 *pData, BOOL bMaster = TRUE);

	// F4
	BOOL SetPreAfn04F4(sMcAfn04f4 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F4(sMcAfn04f4 *pData, BOOL bMaster = TRUE);
	
	// F5
	BOOL SetPreAfn04F5(sMcAfn04f5 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F5(sMcAfn04f5 *pData, BOOL bMaster = TRUE);
	
	// F6
	BOOL SetPreAfn04F6(sMcAfn04f6 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F6(sMcAfn04f6 *pData, BOOL bMaster = TRUE);

	// F7
	BOOL SetPreAfn04F7(sMcAfn04f7 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F7(sMcAfn04f7 *pData, BOOL bMaster = TRUE);
	
	// F9
	BOOL SetPreAfn04F9(sMcAfn04f9 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F9(sMcAfn04f9 *pData, BOOL bMaster = TRUE);

	// F10
	BOOL SetPreAfn04F10(sMcAfn04f10 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F10(sMcAfn04f10 *pData, BOOL bMaster = TRUE);

	// F17
	BOOL SetPreAfn04F17(sMcAfn04f17 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F17(sMcAfn04f17 *pData, BOOL bMaster = TRUE);

	// f25
	BOOL SetPreAfn04F25(sMcAfn04f25 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F25(sMcAfn04f25 *pData, BOOL bMaster = TRUE);

	// f26
	BOOL SetPreAfn04F26(sMcAfn04f26 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F26(sMcAfn04f26 *pData, BOOL bMaster = TRUE);

	// f27
	BOOL SetPreAfn04F27(sMcAfn04f27 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F27(sMcAfn04f27 *pData, BOOL bMaster = TRUE);

	// f28
	BOOL SetPreAfn04F28(sMcAfn04F28 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F28(sMcAfn04F28 *pData, BOOL bMaster = TRUE);

	// f29
	BOOL SetPreAfn04F29(sMcAfn04F29 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F29(sMcAfn04F29 *pData, BOOL bMaster = TRUE);

	// f30
	BOOL SetPreAfn04F30(sMcAfn04f30 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F30(sMcAfn04f30 *pData, BOOL bMaster = TRUE);

	// f33
	BOOL SetPreAfn04F33(sMcAfn04f33 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F33(sMcAfn04f33 *pData,  BOOL bMaster = TRUE);
	
	// f25 33ͨ��
	BOOL SetPreAfn04F25_f33(CString strKeyName, sMcAfn04f25 *pData,  BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F25_f33(CString strKeyName, sMcAfn04f25 *pData,  BOOL bMaster = TRUE);
	void trans_zigbee(bool strtobuf, CString &strZigbee, char*bufZigbee);
	// f34
	BOOL SetPreAfn04F34(sMcAfn04f34 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F34(sMcAfn04f34 *pData, BOOL bMaster = TRUE);

	// f34
	BOOL SetPreAfn04F35(sMcAfn04f35 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F35(sMcAfn04f35 *pData, BOOL bMaster = TRUE);


	// f49
	BOOL SetPreAfn04F49(sMcAfn04f49 *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn04F49(sMcAfn04f49 *pData, BOOL bMaster = TRUE);

	// afn 0af2
	BOOL SetPreAfn0aF2q(sMcAfn11f2q *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn0aF2q(sMcAfn11f2q *pData, BOOL bMaster = TRUE);

	// afn 0af7
	BOOL SetPreAfn0aF7q(sMcAfn10f7q *pData, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn0aF7q(sMcAfn10f7q *pData, BOOL bMaster = TRUE);

	// afn 0d
	BOOL SetPreAfn0DFS(CString *pData, eMcmd eCmd, BOOL bMaster, BOOL bReWrite = TRUE);
	BOOL GetPreAfn0DFS(CString *pData, eMcmd eCmd, BOOL bMaster = TRUE);


	// pw
	void SetPrePw(CString pw, BOOL bMaster = TRUE);
	void GetPrePw(CString *pw, BOOL bMaster = TRUE);
	void SetMstPreAfn04F1(sMtAfn04F1 *psCfg, BOOL bReWrite = TRUE);
	void GetMstPreAfn04F1(sMtAfn04F1 *psCfg);
	void SetTmlPreAfn04F1(sMtAfn04F1 *psCfg, BOOL bReWrite = TRUE);
	void GetTmlPreAfn04F1(sMtAfn04F1 *psCfg);
	void SetPrePn(eMtCmd eCmd, eMtRole eRole,UINT16 *pusPN, UINT8 ucNum, BOOL bReWrite = TRUE);
		void SetPrePn31(eMcmd eCmd, eMcRole eRole,UINT16 *pusPN, UINT8 ucNum, BOOL bReWrite = TRUE);

	void GetPrePn(eMtCmd eCmd, eMtRole eRole,UINT16 *pusPN, UINT8 *pucNum);
	void GetPrePn31(eMcmd eCmd,  eMcRole eRole,UINT16 *pusPN, UINT8 *pucNum);

	void SetPrePnStr(eMtCmd eCmd, eMtRole eRole,CString strValue, BOOL bReWrite = TRUE);
	void SetPrePnStr31(eMcmd eCmd, eMcRole eRole,CString strValue, BOOL bReWrite = TRUE);

	void GetPrePnStr(eMtCmd eCmd, eMtRole eRole,CString *pStr);
	void GetPrePnStr31(eMcmd eCmd, eMcRole eRole,CString *pStr);



	

	unsigned char GetCharValue(char cAscii);
	//get hex string
	void ConverToHexString(char *strHexData, const char* pszSrc, int nLen);
	int HexStringToString(unsigned char* strDest, int nDestLen, const char* pszHexSrc);


	CNxConfig();
	virtual ~CNxConfig();
	


private:


};

#endif // !defined(AFX_NXCONFIG_H__1DD12D49_5364_4329_A836_16957971D23E__INCLUDED_)
