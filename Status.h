/*��  ��: ���״̬�뼰�꺯���б� */ 

#ifndef STATUS_H
#define STATUS_H

/* ״̬�� */
#define	TRUE		1			//�� 
#define	FALSE		0			//��
#define YES			1			//��
#define NO          0			//�� 
#define	OK			1			//ͨ��
#define	ERROR		0			//����
#define SUCCESS		1			//�ɹ� 
#define UNSUCCESS	0			//ʧ�� 
#define	INFEASIBLE	-1			//������

#ifndef _MATH_H_ 				//ϵͳ�����д�״̬�붨�壬Ҫ�����ͻ 
#define	OVERFLOW	-2			//��ջ����
#define UNDERFLOW	-3			//��ջ����
#endif 

/* ״̬��ʶ������ */
typedef int Status;
#endif
