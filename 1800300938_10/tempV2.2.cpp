//ѧ������ϵͳ					BY:AngryBeast		2019.6
#define _CRT_SECURE_NO_DEPRECATE					//��fopen_s,fscanf_s���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int admin;											//adminģʽ   1����  0�ر�
int lenth;											//�ṹ�峤��
struct Student* pHead;								//ȫ��ͷָ��
void FunctionList();								//��ӡ�����б���
void Admin_FunctionList();							//admin�����б�
void Login();										//��½admin
void TravelList(struct Student* pHead);				//��������
void Choose();										//ѡ����
void Singe_print(struct Student* p);				//������ӡѧ����Ϣ
void FreeAll(struct Student* p);					//ɾ������
void Add_stu(struct Student* pHead);				//����ѧ��
struct Student Search_name(struct Student* p);		//��������
struct Student Search_num(struct Student* p);		//����ѧ��
void Search_classname(struct Student* p);			//�����γ�����
void Excellent_rate(struct Student* pHead);			//�����ʡ���������
struct Student FileR(struct Student* pHead);		//�ļ���ȡ
struct Student Cheak(struct Student* p);			//����Ƿ������뵽�ڴ�
void Search_classname_LandH(struct Student* p);		// �����γ���߷���ͷ�
void Score_sort(struct Student* pHead, int mode);	//�ܷ�����
void Same_class_score(struct Student* p);			//ͬ�γ�ͬ��
void Modify_information(struct Student* p);			//�޸�ѧ����Ϣ
void Delete_stu(struct Student* p);					//ɾ��ѧ����Ϣ
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
	admin = 0;
	lenth = sizeof(Student);
	//system("color f5");		//����������������ɫ
	system("color f0");
	pHead = (struct Student*)malloc(lenth);
	Cheak(pHead);
	pHead->next = (struct Student*)NULL;
	while (!admin)			//�ǹ���Աģʽ
	{
		FunctionList();		//��ӡ�����б�
		Choose();
		printf("\n\n\n");
	}
	while (admin)					//�й���ԱȨ��ʱ
	{
		//system("color 1c");
		//Admin_FunctionList();
		//scanf_s("%d", &in1);
		//printf("\n\n\n");
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
	printf("7�����տγ���������߷���ͷ�\n");
	printf("8�����ҿγ��µķ���\n");
	printf("10���ӵ�ǰϵͳɾ��ѧ����Ϣ\n");
	printf("11���޸�ѧ����Ϣ\n");
	printf("88������ѧ����Ϣ\n");
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
	printf("8���ӵ�ǰϵͳɾ��ѧ����Ϣ\n");
	printf("9���鿴��ǰ����ѧ���ĳɼ�\n");
	printf("99���˳�����Աģʽ\n");
}

void Login()
{
	char account[16] = { "AngryBeast" };			//����Ա�˻�
	char password[16] = { "Admin111" };				//����Ա����
	char buffer[16] = { 0 };
	int flag1, flag2, i;
	flag1 = flag2 = -1;
	i = 0;
	printf_s("�����˺�:");
	rewind(stdin);
	gets_s(buffer);
	flag1 = strcmp(buffer, account);
	printf_s("��������:");
	rewind(stdin);									//��ջ�����
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
	int temp_normal,temp_exam,temp_score,i;
	char buffer[16];					//������
	FILE* fpRead = NULL;
	struct Student* p,* ptemp,* tail;
	errno_t err;						//��fopen���
	if ((err = fopen_s(&fpRead, "stu.txt", "r")) != NULL)		//�ɹ�����0�����ɹ����ط�0
	{
		printf("δ�ҵ�stu.txt�ļ�\n");
		system("pause");
		exit(-1);
	}
	while (pHead)						//����ֱ�������ĩβ
	{
		pHead = pHead->next;
		printf("1");
	}
	printf("2");
	tail = pHead;							//��¼βָ��
	while (!feof(fpRead))
	{
		p = (struct Student*)malloc(lenth);
		Cheak(p);
		p->next = NULL;
		fgets(buffer, sizeof(buffer), fpRead);									//��ȡѧ������	
		buffer[strlen(buffer) - 1] = 0;							//�������з�
		//for (i = strlen(buffer) - 1; i < 16; i++)
		//	buffer[i] = 0;
		strcpy(p->name, buffer);
		fgets(buffer, sizeof(buffer), fpRead);							//��ȡ�γ���     
		buffer[strlen(buffer) - 1] = 0;
		//for (i = strlen(buffer) - 1; i < 16; i++)
		//	buffer[i] = 0;
		strcpy(p->lessonname, buffer);
		fscanf(fpRead, "%d", &p->classroom);									//��ȡ�༶
		fscanf(fpRead, "%d", &p->number);										//��ȡѧ��
		fscanf(fpRead, "%d", &temp_normal);										//��ƽʱ��ȡ��
		fscanf(fpRead, "%d", &temp_exam);										//�����Է���ȡ��
		fgets(buffer, sizeof(buffer), fpRead);									//����س�
		temp_score = (int)((0.20 * temp_normal) + (0.80 * temp_exam) + 0.5);		//���㲢��������
		p->normal = temp_normal;
		p->exam = temp_exam;
		p->score = temp_score;

		tail->next = p;				//��������
		tail = p;
		//printf("%s\t",p->name);							//�����ã����
		//printf("%s\t", p->lessonname);
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
	//return *pHead;
	return*tail;
}

void TravelList(struct Student* pHead)					//��������
{
	struct Student * p;
	int i;
	p = pHead->next;
	while (p)
	{
		//for (i = 0; i < 16; i++)
		//{
		//	printf("%c",p->name[i]);
		//}
		//printf("\t");
		//for (i = 0; i < 16; i++)
		//{
		//	printf("%c", p->lessonname[i]);
		//}
		//printf("\t");


		printf("%s\t", p->name);
		printf("%s\t", p->lessonname);
		printf("%d\t", p->classroom);
		printf("%d\t", p->number);
		printf("%d\t", p->normal);
		printf("%d\t", p->exam);
		printf("%d\t", p->score);
		printf("\n");
		p = p->next;
	}
	return;
}

void Choose()
{
	//FileR(pHead);									//������
	//TravelList(pHead);							//������
	int operation1, operation2;
	struct Student* temp = NULL;
	if (pHead->next == NULL)
	{
		printf("*********************************\n");
		printf("*\tϵͳ����ѧ����Ϣ\t*\n");
		printf("*********************************\n");
	}
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
		if (pHead->next == NULL)
		{
			printf("ϵͳ����ѧ����Ϣ\n");
			return;
		}
		printf("1����������ѯѧ����Ϣ\n");
		printf("2����ѧ�Ų�ѯѧ����Ϣ\n");
		printf("3�����γ����Ʋ�ѯѧ����Ϣ\n");
		scanf_s("%d", &operation2);
		switch (operation2)
		{
		case 1:
			//temp = &Search_name(pHead);
			//Singe_print(temp);
			Search_name(pHead);
			break;
		case 2:
			temp = &Search_num(pHead);
			Singe_print(temp);
			break;
		case 3:
			Search_classname(pHead);
			break;
		default:printf("��Ч������\n");
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
		break;
	case 5:
		Excellent_rate(pHead);
		break;
	case 6:
		TravelList(pHead);
		break;
	case 7:
		Search_classname_LandH(pHead);
		break;
	case 8:
		Same_class_score(pHead);
		break;
	case 9:Login();
		break;
	case 10:
		Delete_stu(pHead);
		break;
	case 11:
		Modify_information(pHead);
		break;
	case 88:Add_stu(pHead); break;
	default:
		printf("��Ч�Ĳ�����\n");
		printf("�����������:");
		scanf_s("%d", &operation1);
		system("pause");
	}
}

struct Student Search_num(struct Student *p)
{
	int temp;
	rewind(stdin);						//��ջ�����
	printf("������Ҫ������ѧ��:");
	scanf_s("%d", &temp);
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
	while (p)
	{
		flag = strcmp(buffer, p->name);
		if (flag == 0)
		{
			printf("���ҵ�ѧ��%s",buffer);
			Singe_print(p);
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
	//while (buffer[i] != 0)
	//{
	//	i++;
	//}
	//buffer[i] = '\n';				//������һλ�Ļ��з�
	//buffer[i + 1] = 0;				//�����ַ���������
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

void Score_sort(struct Student* pHead,int mode)
{
	//struct Student* p, * pH, * temp;
	//pHead = pHead->next;
	//pH = (struct Student*)malloc(lenth);			//�������ͷָ��
	//Cheak(pH);
	//pH->next = pHead;
	//if (mode == 1)				//��С����			
	//{
	//	while (pHead)
	//	{
	//		temp = pHead->next;						//��ʱ������һ���ڵ�
	//		p = (struct Student*)malloc(lenth);
	//		Cheak(p);
	//		while (p)
	//		{
	//			if (pHead->score < temp->score)
	//				break;
	//			p = p->next;
	//		}

	//		pHead = pHead->next;
	//	}
	//}
}

void Excellent_rate(struct Student* pHead)					//������
{
	int classnum[32][5] = {0};		//[32]�༶����  [5]��һλ���,�ڶ�λ������������λ��������������λ����������
	struct Student* p;
	int i,j,flag,temp;
	float rate;
	flag = i = j = 0;
	p = pHead->next;
	while (p)						//�ȸ�ÿ����һ��λ��
	{
		for (i = 0; i < 32; i++)
		{
			if (p->classroom == classnum[i][0])
				break;
			if (i == 31)
			{
				classnum[j][0] = p->classroom;
				j++;
			}
		}
		p = p->next;
	}
	p = pHead->next;				//�ڶ��α���
	while (p)
	{
		for (i = 0; i < 32; i++)
		{
			if (p->classroom == classnum[i][0])			//�ҵ��༶
			{
				classnum[i][1]++;						//������++
				//printf("%d��   ������:%d  ",classnum[i][0],classnum[i][1]);
				if (p->score >= 90)
					classnum[i][2]++;					//��������++
				//printf("%d��   ��������:%d  ", classnum[i][0], classnum[i][2]);
				if (p->score < 60)
					classnum[i][3]++;					//����������++
				//printf("%d��   ����������:%d  ", classnum[i][0], classnum[i][3]);
				printf("\n");
				break;
			}
		}
		p = p->next;
	}
	i = 0;
	printf("1�������༶��ѯ\n2��ȫ���༶\n�����������:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d",&flag);
	switch(flag)
	{
	case 1:
		printf("������Ҫ���ҵİ༶:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d",&temp);
		while (classnum[i][0] != 0)
		{
			if (classnum[i][0] == temp)
			{
				rate = (float)classnum[i][2] / classnum[i][1];			//����������
				printf("%d��������Ϊ:%.2f\n", classnum[i][0], rate);
				rate = (float)classnum[i][3] / classnum[i][1];			//���㲻������
				printf("%d�಻������Ϊ:%.2f\n", classnum[i][0], rate);
				return;
			}
			i++;
		}
		printf("Ҫ���ҵİ༶������\n");
		return;
	case 2:
		while (classnum[i][0] != 0)							//��ʼ������ӡ
		{
			rate = (float)classnum[i][2] / classnum[i][1];			//����������
			printf("%d��������Ϊ:%.2f\n", classnum[i][0], rate);
			rate = (float)classnum[i][3] / classnum[i][1];			//���㲻������
			printf("%d�಻������Ϊ:%.2f\n", classnum[i][0], rate);
			i++;
		}
		break;
	}
}

void Add_stu(struct Student* pHead)
{
	struct Student* p, * tail;
	char operation = 'Y';
	char buffer[16];
	int temp_score, temp_normal, temp_exam;
	temp_exam = temp_normal = temp_score = 0;
	while (pHead->next)						//����ֱ�������ĩβ
	{
		pHead = pHead->next;
	}
	tail = pHead;							//��¼βָ��
	while (1)
	{
		switch (operation)
		{
		case 'Y':
			p = (struct Student*)malloc(lenth);
			Cheak(p);
			p->next = (struct Student*)NULL;
			printf("������Ҫ�����ѧ��������:");
			rewind(stdin);			//��ջ�����
			gets_s(buffer);
			strcpy(p->name,buffer);
			printf("������Ҫ�����ѧ���Ŀγ�����:");
			rewind(stdin);			//��ջ�����
			gets_s(buffer);
			strcpy(p->lessonname, buffer);
			printf("������Ҫ�����ѧ���İ༶:");
			rewind(stdin);			//��ջ�����
			scanf_s("%d",&p->classroom);
			printf("������Ҫ�����ѧ����ѧ��:");
			rewind(stdin);			//��ջ�����
			scanf_s("%d", &p->number);
			printf("������Ҫ�����ѧ����ƽʱ�ɼ�:");
			rewind(stdin);			//��ջ�����
			scanf_s("%d", &temp_normal);
			p->normal = temp_normal;
			printf("������Ҫ�����ѧ���Ŀ��Գɼ�:");
			rewind(stdin);			//��ջ�����
			scanf_s("%d", &temp_exam);
			p->exam = temp_exam;
			temp_score = (int)((0.20 * temp_normal) + (0.80 * temp_exam) + 0.5);		//���㲢��������
			p->score = temp_score;
			tail->next = p;
			tail = p;
			Singe_print(p);
			printf("�Ƿ�������룿��Y/N��");
			rewind(stdin);			//��ջ�����
			scanf_s("%c",&operation);
			break;
		case 'N':
			return;
		default:
			printf("��������ȷ�Ĳ�����\n");
			system("pause");
			rewind(stdin);			//��ջ�����
			scanf_s("%c", &operation);
		}
	}
}

void Search_classname_LandH(struct Student* pHead)
{
	struct Student* p_l;			//���λ
	struct Student* p_h;			//���λ
	struct Student* p;
	char buffer[16];				//������
	int flag = 1;					//�ж��Ƿ����
	int i = 0;
	int found = 0;
	int temp_score = -1;
	p = pHead;
	p_l = (struct Student*)malloc(lenth);
	Cheak(p_l);
	p_h = (struct Student*)malloc(lenth);
	Cheak(p_h);
	p_l->score = 101;
	p_h->score = -1;
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
			//Singe_print(p);		//�ҵ����ӡ����
			flag = 1;				//��װ��
			found = 1;
			if (p->score > p_h->score)
			{
				p_h = p;
			}
			if (p->score < p_l->score)
			{
				p_l = p;
			}
		}
		p = p->next;
	}
	if (found == 0)
	{
		printf("δ�ҵ��ÿγ�\n");
		return;
	}
	//printf("\n\n");							//ͬ��ֻ��ӡһ��
	//printf("�ÿγ̵���ͷ�Ϊ:\n");
	//Singe_print(p_l);
	//printf("\n\n");
	//printf("�ÿγ̵���߷�Ϊ:\n");
	//Singe_print(p_h);

					//���ò�ѯ�γ����ƺͳɼ�������ӡ����ͬ��

	printf("\n\n");					//�ȴ�ӡ�߷�
	printf("�ÿγ̵���߷�Ϊ\n");
	p = pHead;						//�ص�ͷָ��
	p = p->next;
	temp_score = p_h->score;
	while (p)						//��ʼ����
	{
		flag = strcmp(buffer, p->lessonname);
		if (flag == 0)
		{
			flag = 1;
			if (p->score == temp_score)		//��ȡ����
			{
				found = 1;
				Singe_print(p);
			}
		}
		p = p->next;
	}
	if (found == 0)
	{
		printf("H error\n");
		system("pause");
	}


	printf("\n\n");					//��ӡ�ͷ�
	printf("�ÿγ̵���ͷ�Ϊ\n");
	p = pHead;						//�ص�ͷָ��
	p = p->next;
	temp_score = p_l->score;
	while (p)						//��ʼ����
	{
		flag = strcmp(buffer, p->lessonname);
		if (flag == 0)
		{
			flag = 1;
			if (p->score == temp_score)		//��ȡ����
			{
				found = 1;
				Singe_print(p);
			}
		}
		p = p->next;
	}
	if (found == 0)
	{
		printf("L error\n");
		system("pause");
	}
}

void Same_class_score(struct Student* p)
{
	char buffer[16];				//������
	int flag = 1;					//�ж��Ƿ����
	int i = 0;
	int found = 0;
	int temp_score = -1;
	rewind(stdin);			//��ջ�����
	printf("������Ҫ��ѯ�γ̵�����:");
	gets_s(buffer);
	while (buffer[i] != 0)
	{
		i++;
	}
	buffer[i] = '\n';				//������һλ�Ļ��з�
	buffer[i + 1] = 0;				//�����ַ���������
	printf("������Ҫ���ҵķ���:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d",&temp_score);
	p = p->next;
	while (p)						//��ʼ����
	{
		flag = strcmp(buffer, p->lessonname);
		if (flag == 0)
		{
			flag = 1;
			if (p->score == temp_score)		//��ȡ����
			{
				found = 1;
				Singe_print(p);
			}
		}
		p = p->next;
	}
	if (found == 0)
	{
		printf("δ�ҵ��ÿγ��µĸ÷�����ͬѧ\n");
	}
}

void Delete_stu(struct Student* p)
{
	struct Student* temp;
	int temp_num;
	printf("������Ҫɾ����ѧ����ѧ��:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d",&temp_num);
	while (p->next)
	{
		if (p->next->number == temp_num)	//�ҵ�Ҫɾ���Ľڵ�
		{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
			printf("ɾ���ɹ�\n");
			return;
		}
		p = p->next;
	}
	printf("δ�ҵ���ѧ�ŵ�ѧ��\n");
	return;
}

void Modify_information(struct Student* p)				//�޸�ѧ����Ϣ
{
	char buffer[16];
	int mode,temp,tmep_score;
	temp = mode = -1;
	printf("1���޸�ѧ���İ༶\n");
	printf("2���޸�ѧ����ѧ��\n");
	printf("3���޸�ѧ����ƽʱ�ɼ�\n");
	printf("4���޸�ѧ���Ŀ��Գɼ�\n");
	printf("ѡ����:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d",&mode);
	if (mode >= 1 && mode <= 4)
	{
		printf("��ѧ����ѧ����:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d",&temp);
	}
	else
	{
		printf("����Ĳ�����\n");		//����Ĳ�����ֱ�ӷ��أ�һ�����Ӷ���������ֹ�������б���
		system("pause");
		return;
	}
	while (p)							//�ҵ���ѧ�ŵ�ѧ��
	{
		if (p->number == temp)
		{
			printf("���ҵ���ѧ��\n");
			break;
		}
		p = p->next;
		if (p == NULL)
		{
			printf("δ�ҵ���ѧ��\n");
			system("pause");
			return;
		}
	}
	rewind(stdin);			//��ջ�����
	switch (mode)
	{
	case 1:
		printf("��ѧ���µİ༶��:");
		scanf_s("%d",&temp);
		p->classroom = temp;
		break;
	case 2:
		printf("��ѧ���µ�ѧ����:");
		scanf_s("%d",&temp);
		p->number = temp;
		break;
	case 3:
		printf("��ѧ����ƽʱ�ɼ��޸�Ϊ:");
		scanf_s("%d", &temp);
		p->normal = temp;
		break;
	case 4:
		printf("��ѧ���Ŀ��Գɼ��޸�Ϊ:");
		scanf_s("%d", &temp);
		p->exam = temp;
		break;
	}
	if (mode == 3 || mode == 4)
	{
		p->score = (float)p->normal * 0.2 + (float)p->exam * 0.8 + 0.5;			//��������
	}
	printf("�޸ĳɹ�\n");
}