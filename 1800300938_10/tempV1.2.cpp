//ѧ������ϵͳ					BY:AngryBeast		2019.6
#define _CRT_SECURE_NO_DEPRECATE					//��fopen_s,fscanf_s���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int admin;										//adminģʽ   1����  0�ر�
int lenth;
struct Student* pHead;
void FunctionList();								//��ӡ�����б���
void Admin_FunctionList();							//admin�����б�
void Login();										//��½admin
void TravelList(struct Student* pHead);				//��������
void Choose();										//ѡ����
void Singe_print(struct Student* p);				//������ӡѧ����Ϣ
void FreeAll(struct Student* p);					//ɾ������
struct Student Search_name(struct Student* p);		//��������
struct Student Search_num(struct Student* p);		//����ѧ��
void Search_classname(struct Student* p);			//�����γ�����
struct Student FileR(struct Student* pHead);		//�ļ���ȡ
struct Student Cheak(struct Student* p);			//����Ƿ������뵽�ڴ�
struct Student
{
	char name[16];				//����
	char lessonname[16];		//�γ�����
	int classroom;				//�༶
	int number;					//ѧ��
	int normal;					//ƽʱ�ɼ�
	int exam;					//���Գɼ�
	int score;					//�ܷ�
	struct Student* next;
};
int main()
{
	int in1, in2;					// �Ӽ����������
	admin = 0;
	lenth = sizeof(Student);
	system("color f5");		//����������������ɫ
	pHead = (struct Student*)malloc(lenth);
	Cheak(pHead);
	pHead->next = NULL;
	while (!admin)			//�ǹ���Աģʽ
	{
		FunctionList();		//��ӡ�����б�
		Choose();
		printf("\n\n\n");
	}
	while (admin)					//�й���ԱȨ��ʱ
	{
		system("color 1c");
		Admin_FunctionList();
		scanf_s("%d", &in1);
		printf("\n\n\n");
	}

}
void FunctionList()					//��ӡ�����б���
{
	printf_s("*******************************************************************\n");
	printf_s("\t\t\t***  ѧ���ɼ�����ϵͳ  ***\n");
	printf_s("\t\t�޹���ԱȨ��\n");
	printf("0���˳�����\n");
	printf("1�����ļ���ȡѧ����Ϣ\n");
	printf("2����ѯ��\n");
	printf("3��������\n");
	printf("4�����Ƴɼ�\n");
	printf("5���鿴�༶�����ʡ���������\n");
	printf("6���鿴��ǰ����ѧ���ĳɼ�\n");
	printf("9���������Աģʽ\n");
}

void Admin_FunctionList()
{
	printf_s("*******************************************************************\n");
	printf_s("\t\t\t***  ѧ���ɼ�����ϵͳ  ***\n");
	printf_s("\t\t=======Admin mode========\n");
	printf("0���˳�����\n");
	printf("1�����ļ���ȡѧ����Ϣ\n");
	printf("2����ѯ��\n");
	printf("3��������\n");
	printf("4�����Ƴɼ�\n");
	printf("5���鿴�༶������\n");
	printf("6������ѧ����Ϣ\n");
	printf("7���޸�ѧ����Ϣ\n");
	printf("8��ɾ��ѧ����Ϣ\n");
	printf("9���鿴��ǰ����ѧ���ĳɼ�\n");
	printf("99���˳�����Աģʽ\n");
}

void Login()
{
	char account[16] = { "AngryBeast" };			//����Ա�˻�
	char password[16] = { "Admin111" };			//����Ա����
	char buffer[16] = { 0 };
	int flag1, flag2, i;
	flag1 = flag2 = -1;
	i = 0;
	printf_s("�����˺�:");
	rewind(stdin);
	gets_s(buffer);
	flag1 = strcmp(buffer, account);
	printf_s("��������:");
	rewind(stdin);								//��ջ�����
	gets_s(buffer);
	flag2 = strcmp(buffer, password);
	if (flag1 == 0 || flag2 == 0)
		admin = 1;
	else
		printf_s("�û����������������\n");
	return;
}

struct Student Cheak(struct Student* p)
{
	if (p == NULL)
	{
		printf_s("error  �޷����뵽�ڴ�\n");
		system("pause");
		exit(-1);
	}
}

struct Student FileR(struct Student *pHead)
{
	int temp_normal,temp_exam,temp_score;
	char buffer[16];					//������
	int i = 0;
	FILE* fpRead = NULL;
	struct Student* p,* ptemp;
	errno_t err;						//��fopen���
	if ((err = fopen_s(&fpRead, "stu.txt", "r")) != NULL)		//�ɹ�����0�����ɹ����ط�0
	{
		printf("δ�ҵ�stu.txt�ļ�\n");
		system("pause");
		exit(-1);
	}
	ptemp = pHead;
	while (!feof(fpRead))
	{
		p = (struct Student*)malloc(lenth);
		Cheak(p);
		p->next = NULL;
		fgets(p->name, sizeof(buffer), fpRead);									//��ȡѧ������	
		fgets(p->lessonname, sizeof(buffer), fpRead);							//��ȡ�γ���     
		fscanf(fpRead, "%d", &p->classroom);									//��ȡ�༶
		fscanf(fpRead, "%d", &p->number);										//��ȡѧ��
		fscanf(fpRead, "%d", &temp_normal);										//��ƽʱ��ȡ��
		fscanf(fpRead, "%d", &temp_exam);										//�����Է���ȡ��
		fgets(buffer, sizeof(buffer), fpRead);									//����س�
		temp_score = (int)((0.20 * temp_normal) + (0.80 * temp_exam) + 0.5);		//���㲢��������
		p->normal = temp_normal;
		p->exam = temp_exam;
		p->score = temp_score;

		ptemp->next = p;				//��������
		ptemp = p;
		//printf("%s",p->name);							//�����ã����
		//printf("%s", p->lessonname);
		//printf("\t%d\t", p->classroom);
		//printf("%d\t", p->number);
		//printf("%d\t", p->normal);
		//printf("%d\t", p->exam);
		//printf("%d\t", p->score);
		//printf("\n");

	}
	fclose(fpRead);
	printf("�ɹ���ȡ�ļ�\n");
	system("pause");
	return *pHead;
}

void TravelList(struct Student* pHead)					//��������
{
	struct Student * p;
	p = pHead->next;
	while (p)
	{
		printf("%s",p->name);							//�����ã����
		printf("%s", p->lessonname);
		printf("\t%d\t", p->classroom);
		printf("%d\t", p->number);
		printf("%d\t", p->normal);
		printf("%d\t", p->exam);
		printf("%d\t", p->score);
		printf("\n");
		p = p->next;
	}
}

void Choose()
{
	FileR(pHead);								//������
	TravelList(pHead);							//������
	char templessonname[32];
	int operation1, operation2;
	struct Student* temp = NULL;
	printf("�����������:");
	scanf_s("%d", &operation1);
	switch (operation1)
	{
	case 0:
		if (pHead != NULL)
			FreeAll(pHead);
		exit(0);
		break;
	case 1:
		FileR(pHead);
		break;
	case 2:
		printf("1����������ѯѧ����Ϣ\n");
		printf("2����ѧ�Ų�ѯѧ����Ϣ\n");
		printf("3�����γ����Ʋ�ѯѧ����Ϣ\n");
		scanf_s("%d", &operation2);
		switch (operation2)
		{
		case 1:
			temp = &Search_name(pHead);
			Singe_print(temp);
			break;
		case 2:
			temp = &Search_num(pHead);
			Singe_print(temp);
			break;
		case 3:
			Search_classname(pHead);
			break;
		}
		break;
	case 3:
		printf("1���ܳɼ��ɸߵ���\n");
		printf("2���ܳɼ��ɵ͵���\n");
		printf("3�����Գɼ��ɵ͵���\n");
		printf("4�����Գɼ��ɵ͵���\n");
		scanf_s("%d", &operation2);
		switch (operation2)
		{
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		}
		break;
	case 4:
		printf("��������Ҫ��ѯ�Ŀγ�����:  ");
		gets_s(templessonname);
		//



		break;
	case 5:
		printf("������Ҫ��ѯ�İ༶��  ");
		break;
	case 6:
		TravelList(pHead);
		break;
	case 7:break;
	case 8:break;
	case 9:Login(); break;
	default:
		printf("��Ч�Ĳ�����\n");
		system("pause");
	}
}

struct Student Search_num(struct Student *p)
{
	int temp;
	rewind(stdin);						//��ջ�����
	printf("������Ҫ������ѧ��:");
	scanf_s("%d", &temp);
	p = p->next;
	while (p)
	{
		if (p->number == temp)
		{
			return *p;
		}
		p = p->next;
		if (p == NULL)
		{
			printf("δ�ҵ���ѧ��ѧ���ĳɼ�\n");
		}
	}
	return *pHead;
}

void Singe_print(struct Student* p)
{
	printf("*****************************************************************\n");
	printf("����   �γ�����    �༶           ѧ��          ƽʱ�ɼ�      ���Գɼ�      �ܷ�\n");
	printf("%s", p->name);
	printf("\t%s", p->lessonname);
	printf("\t\t   %d\t", p->classroom);
	printf("%d\t  ", p->number);
	printf("%d    ", p->normal);
	printf("	  %d    ", p->exam);
	printf("      %d   ", p->score);
	printf("\n");
}

void FreeAll(struct Student* p)
{
	struct Student* temp = NULL;
	while (p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}

struct Student Search_name(struct Student* p)
{
	char buffer[16];
	int flag = 1;			//�ж��Ƿ����
	int i = 0;
	rewind(stdin);			//��ջ�����
	printf("������Ҫ��ѯѧ��������:");
	gets_s(buffer);
	while (buffer[i] != 0)
	{
		i++;
	}
	buffer[i] = '\n';				//������һλ�Ļ��з�
	buffer[i + 1] = 0;				//�����ַ���������
	p = p->next;
	while (p)
	{
		flag = strcmp(buffer, p->name);
		if (flag == 0)
		{
			printf("���ҵ�ѧ��%s",buffer);
			return *p;
		}
		p = p->next;
		if (p == NULL)
		{
			printf("δ�ҵ�ѧ��%s", buffer);
			system("pause");
		}
	}
	return *pHead;
}

void Search_classname(struct Student* p)
{
	char buffer[16];				//������
	int flag = 1;					//�ж��Ƿ����
	int i = 0;
	int found = 0;
	rewind(stdin);			//��ջ�����
	printf("������Ҫ��ѯ�γ̵�����:");
	gets_s(buffer);
	while (buffer[i] != 0)
	{
		i++;
	}
	buffer[i] = '\n';				//������һλ�Ļ��з�
	buffer[i + 1] = 0;				//�����ַ���������
	p = p->next;
	while (p)						//��ʼ����
	{
		flag = strcmp(buffer, p->lessonname);
		if (flag == 0)
		{
			Singe_print(p);
			flag = 1;
			found = 1;
		}
		p = p->next;
	}
	if (found == 0)
	{
		printf("δ�ҵ��ÿγ�\n");
	}
}