//ѧ������ϵͳ							BY:AngryBeast		2019.6
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
void AdminAccount(char Account[], char Password[]);	//Admin�˺Ŷ�ȡ
void TravelList(struct Student* pHead);				//��������
void Admin_Choose();								//����Աѡ����
void Singe_print(struct Student* p);				//������ӡѧ����Ϣ
void FreeAll(struct Student* p);					//ɾ������
void Add_stu(struct Student* pHead);				//����ѧ��
struct Student Search_name(struct Student* p);		//��������
void Search_num(struct Student* p);					//����ѧ��
void Search_classname(struct Student* p);			//�����γ�����
void Excellent_rate(struct Student* pHead);			//�����ʡ���������
struct Student FileR(struct Student* pHead);		//�ļ���ȡ
struct Student Cheak(struct Student* p);			//����Ƿ������뵽�ڴ�
void Search_classname_LandH(struct Student* p);		//�����γ���߷���ͷ�
void Score_sort(struct Student* pHead);				//�ܷ�����
void Same_class_score(struct Student* p);			//ͬ�γ�ͬ��
void Modify_information(struct Student* p);			//�޸�ѧ����Ϣ
void Delete_stu(struct Student* p);					//ɾ��ѧ����Ϣ
void FileW(struct Student* pHead);					//д���ļ�
void Exam_sort(struct Student* pHead);				//�����Գɼ���������
void Choose();										//ѡ����
void Delete_data();									//ɾ�������ļ�
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
	admin = 1;
	lenth = sizeof(Student);
	system("color f0");		//����������������ɫ
	pHead = (struct Student*)malloc(lenth);
	Cheak(pHead);
	pHead->next = (struct Student*)NULL;
	while (1)
	{
		while (!admin)			//�ǹ���Աģʽ
		{
			system("color f0");
			FunctionList();		//��ӡ�����б�
			Choose();			//���������
			printf("\n\n\n");
		}
		while (admin)					//�й���ԱȨ��ʱ
		{
			system("color f5");
			Admin_FunctionList();		//��ӡ�����б�
			Admin_Choose();				//���������
			printf("\n\n\n");
		}
	}
}
void FunctionList()					//��ӡ�����б���
{
	printf("*******************************************************************\n");
	printf("*              *****  ѧ���ɼ�����ϵͳ  *****                     *\n");
	printf("*               ****    BY:AngryBeast   ****                      *\n");
	printf("*               ====     �޹���ԱȨ��   ====                      *\n");
	printf("*                         0���˳�����                             *\n");
	printf("*                         1�����ļ���ȡѧ����Ϣ                   *\n");
	printf("*                         2����ѯ��                               *\n");
	printf("*                         3�����ֽܷ�������                       *\n");
	printf("*                         4�������Գɼ���������                   *\n");
	printf("*                         5���鿴�༶�����ʡ���������             *\n");
	printf("*                         6���鿴��ǰ����ѧ���ĳɼ�               *\n");
	printf("*                         7�����տγ���������߷���ͷ�           *\n");
	printf("*                         8�����ҿγ��µķ���                     *\n");
	printf("*                         9���������Աģʽ                       *\n");
	printf("*                         99������                                *\n");
	printf("*******************************************************************\n");
}

void Admin_FunctionList()
{
	//printf_s("*******************************************************************\n");
	//printf_s("              *****  ѧ���ɼ�����ϵͳ  *****\n");
	//printf_s("              =======   Admin mode    ========\n");
	//printf("                         0���˳�����\n");
	//printf("                         1�����ļ���ȡѧ����Ϣ\n");
	//printf("                         2����ѯ��\n");
	//printf("                         3��������\n");
	//printf("                         4�����Ƴɼ�\n");
	//printf("                         5���鿴�༶������\n");
	//printf("                         6������ѧ����Ϣ\n");
	//printf("                         7���޸�ѧ����Ϣ\n");
	//printf("                         8���ӵ�ǰϵͳɾ��ѧ����Ϣ\n");
	//printf("                         9���鿴��ǰ����ѧ���ĳɼ�\n");
	//printf("                         99���˳�����Աģʽ\n");
	printf("*******************************************************************\n");
	printf("*              *****  ѧ���ɼ�����ϵͳ  *****                     *\n");
	printf("*               ****    BY:AngryBeast   ****                      *\n");
	printf("*              =======   Admin mode    ========                   *\n");
	printf("*                         0���˳�����                             *\n");
	printf("*                         1�����ļ���ȡѧ����Ϣ                   *\n");
	printf("*                         2����ѯ��                               *\n");
	printf("*                         3�����ֽܷ�������                       *\n");
	printf("*                         4�������Գɼ���������                   *\n");
	printf("*                         5���鿴�༶�����ʡ���������             *\n");
	printf("*                         6���鿴��ǰ����ѧ���ĳɼ�               *\n");
	printf("*                         7�����տγ���������߷���ͷ�           *\n");
	printf("*                         8�����ҿγ��µķ���                     *\n");
	printf("*                         9������ѧ����Ϣ                         *\n");
	printf("*                         10���ӵ�ǰϵͳɾ��ѧ����Ϣ              *\n");
	printf("*                         11���޸�ѧ����Ϣ                        *\n");
	printf("*                         12��д���ļ�                            *\n");
	printf("*                         13���˳�����Աģʽ                      *\n");
	printf("*                         99������                                *\n");
	printf("*                         998��ɾ�������ļ�                       *\n");
	printf("*******************************************************************\n");
}

void Login()
{
	char account[16] = { "AngryBeast" };			//����Ա�˻�
	char password[16] = { "Admin111" };				//����Ա����
	char buffer_Account[16] = { 0 };
	char buffer_Password[16] = { 0 };
	int flag1, flag2, i;
	flag1 = flag2 = -1;
	i = 0;
	printf_s("�����˺�:");
	rewind(stdin);
	gets_s(buffer_Account);
	flag1 = strcmp(buffer_Account, account);
	printf_s("��������:");
	rewind(stdin);									//��ջ�����
	gets_s(buffer_Password);
	flag2 = strcmp(buffer_Password, password);

	if (flag1 == 0 || flag2 == 0)					//����Ƿ��ǳ�������Ա
	{
		admin = 1;
		return;
	}
	AdminAccount(buffer_Account, buffer_Password);	//����Ƿ��ǹ���Ա
	if (admin == 0)
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

struct Student FileR(struct Student* pHead)
{
	int temp_normal, temp_exam, temp_score, i;
	char buffer[16];					//������
	FILE* fpRead = NULL;
	struct Student* p, * tail;
	errno_t err;						//��fopen���
	if ((err = fopen_s(&fpRead, "Student.txt", "r")) != NULL)		//�ɹ�����0�����ɹ����ط�0
	{
		printf("δ�ҵ�Student.txt�ļ�\n");
		system("pause");
		exit(-1);
	}
	while (pHead->next)						//����ֱ�������ĩβ
	{
		pHead = pHead->next;
	}
	tail = pHead;							//��¼βָ��
	while (!feof(fpRead))
	{
		p = (struct Student*)malloc(lenth);
		Cheak(p);
		p->next = NULL;
		fgets(buffer, sizeof(buffer), fpRead);							//��ȡѧ������	
		buffer[strlen(buffer) - 1] = 0;									//�������з�
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
	return *pHead;
}

void TravelList(struct Student* pHead)					//��������
{
	struct Student* p;
	int count = 0;
	p = pHead->next;
	printf("ѧ������                ");
	printf("�γ�����                ");
	printf("�༶            ");
	printf("ѧ��        ");
	printf("ƽʱ�ɼ�  ");
	printf("���Գɼ�  ");
	printf("�ܷ�\n");
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


		printf("%-16s\t", p->name);
		printf("%-16s\t", p->lessonname);
		printf("%-6d\t", p->classroom);
		printf("%-6d\t", p->number);
		printf("%-6d\t", p->normal);
		printf("%-6d\t", p->exam);
		printf("%-6d\t", p->score);
		printf("\n");
		count++;
		p = p->next;
	}
	printf("\n\t**����%d���ɼ���Ϣ**", count);
	return;
}

void Admin_Choose()
{
	int operation1, operation2;
	struct Student* temp = NULL;
	if (pHead->next == NULL)
	{
		printf("                *********************************\n");
		printf("                *\tϵͳ����ѧ����Ϣ\t*\n");
		printf("                *********************************\n");
	}
	printf("\n                    �����������:");
	scanf_s("%d", &operation1);
	printf("\n\n");
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
		case 2:Search_num(pHead); break;
		case 3:
			Search_classname(pHead);
			break;
		default:printf("��Ч������\n");
		}
		break;
	case 3:Score_sort(pHead); break;
		//printf("1���ܳɼ��ɸߵ���\n");
		//printf("2���ܳɼ��ɵ͵���\n");
		//printf("3�����Գɼ��ɵ͵���\n");
		//printf("4�����Գɼ��ɵ͵���\n");
		//scanf_s("%d", &operation2);
		//switch (operation2)
		//{
		//case 1:break;
		//case 2:break;
		//case 3:break;
		//case 4:break;
		//}
	case 4:Exam_sort(pHead); break;
	case 5:Excellent_rate(pHead); break;
	case 6:TravelList(pHead); break;
	case 7:Search_classname_LandH(pHead); break;
	case 8:Same_class_score(pHead); break;
	case 9:Add_stu(pHead); break;
	case 10:Delete_stu(pHead); break;
	case 11:Modify_information(pHead); break;
	case 12:FileW(pHead); break;
	case 13:admin = 0; break;
	case 99:system("cls"); break;
	case 998:Delete_data(); break;
	default:
		printf("��Ч�Ĳ�����\n");
		printf("�����������:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d", &operation1);
		system("pause");
	}
}

void Search_num(struct Student* p)
{
	int temp;
	int found = 0;
	rewind(stdin);						//��ջ�����
	printf("������Ҫ������ѧ��:");
	scanf_s("%d", &temp);
	while (p)
	{
		if (p->number == temp)
		{
			Singe_print(p);
			found = 1;
		}
		p = p->next;
		if (p == NULL && !found)
		{
			printf("δ�ҵ���ѧ��ѧ���ĳɼ�\n");
		}
	}
}

void Singe_print(struct Student* p)
{
	printf("*****************************************************************\n");
	printf("����     �γ�����      �༶           ѧ��          ƽʱ�ɼ�      ���Գɼ�      �ܷ�\n");
	printf("%s", p->name);
	printf("\t%s", p->lessonname);
	printf("\t   %d\t", p->classroom);
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
	int found = 0;				//�ж��Ƿ��ҵ���ѧ��
	int i = 0;
	rewind(stdin);			//��ջ�����
	printf("������Ҫ��ѯѧ��������:");
	gets_s(buffer);
	while (p)
	{
		flag = strcmp(buffer, p->name);
		if (flag == 0)
		{
			if (found == 0)
				printf("\n���ҵ�ѧ��%s\n\n", buffer);
			Singe_print(p);
			flag = 1;
			found = 1;
			//return *p;
		}
		p = p->next;
		if (p == NULL && !found)
		{
			printf("δ�ҵ�ѧ��%s\n", buffer);
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

void Score_sort(struct Student* pHead)			//�ܳɼ�����
{
	//struct Student* temp, * sort, * head, * in;			//�½�����ı������½������ͷ��ԭ����������������
	//pHead = pHead->next;
	//sort = pHead;
	//sort->next = (struct Student*)NULL;
	//printf("pHead = %d\t", pHead->score);
	//while (pHead)
	//{
	//	in = pHead;
	//	temp = (struct Student*)malloc(lenth);
	//	printf("temp= %d\t", temp->score);
	//	while (temp->next != NULL && temp->next->score < in->score)		//Ѱ�Ҳ����λ��
	//	{
	//		printf("%d\t",temp->score);
	//		temp = temp->next;
	//	}
	//	in->next = temp->next;
	//	temp->next = in;
	//	printf("head = %d\t", pHead->score);
	//	printf("head->next = %d",pHead->next->score);
	//	system("pause");
	//	printf("head = %d\t", pHead->score);
	//	pHead = pHead->next;
	//}

	//struct Student* temp, * sort, * in;
	//pHead = pHead->next;
	//while (pHead)
	//{
	//	sort = (struct Student*)malloc(lenth);
	//	temp = pHead;
	//	while (sort->next != NULL && sort->next->score < temp->score)
	//	{
	//		printf("sort->");
	//		sort = sort->next;

	//	}
	//	temp->next = sort->next;
	//	sort->next = temp;
	//	pHead = pHead->next;
	//}
	struct Student* p, * q, * tail;
	tail = NULL;
	while ((pHead->next->next) != tail)
	{
		p = pHead;
		q = pHead->next;
		while (q->next != tail)
		{
			if ((q->score) > (q->next->score))
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = p->next;
			}
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	printf("\t\t���ִܷ�С��������ɹ�\n");
}

void Excellent_rate(struct Student* pHead)					//������
{
	int classnum[32][5] = { 0 };		//[32]�༶����  [5]��һλ���,�ڶ�λ������������λ��������������λ����������
	struct Student* p;
	int i, j, flag, temp;
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
				/*printf("\n");*/
				break;
			}
		}
		p = p->next;
	}
	i = 0;
	printf("1�������༶��ѯ\n2��ȫ���༶\n�����������:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d", &flag);
	switch (flag)
	{
	case 1:
		printf("������Ҫ���ҵİ༶:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d", &temp);
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
			strcpy(p->name, buffer);
			printf("������Ҫ�����ѧ���Ŀγ�����:");
			rewind(stdin);			//��ջ�����
			gets_s(buffer);
			strcpy(p->lessonname, buffer);
			printf("������Ҫ�����ѧ���İ༶:");
			rewind(stdin);			//��ջ�����
			scanf_s("%d", &p->classroom);
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
			scanf_s("%c", &operation);
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
	//buffer[i] = '\n';				//������һλ�Ļ��з�
	buffer[i] = 0;				//�����ַ���������
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
		printf("High error\n");
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
		printf("Low error\n");
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
	scanf_s("%d", &temp_score);
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
	scanf_s("%d", &temp_num);
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
	int mode, temp, tmep_score;
	temp = mode = -1;
	printf("1���޸�ѧ���İ༶\n");
	printf("2���޸�ѧ����ѧ��\n");
	printf("3���޸�ѧ����ƽʱ�ɼ�\n");
	printf("4���޸�ѧ���Ŀ��Գɼ�\n");
	printf("ѡ����:");
	rewind(stdin);			//��ջ�����
	scanf_s("%d", &mode);
	if (mode >= 1 && mode <= 4)
	{
		printf("��ѧ����ѧ����:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d", &temp);
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
		scanf_s("%d", &temp);
		p->classroom = temp;
		break;
	case 2:
		printf("��ѧ���µ�ѧ����:");
		scanf_s("%d", &temp);
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

void FileW(struct Student* pHead)
{
	char buffer[16];					//����������
	struct Student* p;
	FILE* fpWrite = NULL;

	errno_t err;						//��fopen���
	if ((err = fopen_s(&fpWrite, "Student.txt", "w")) != NULL)		//�ɹ�����0�����ɹ����ط�0
	{
		printf("δ�ҵ�Student.txt�ļ�\n");
		system("pause");
		exit(-1);
	}
	p = pHead->next;
	while (p)
	{
		strcpy(buffer, p->name);			//д������
		strcat(buffer, "\n");
		fputs(buffer, fpWrite);
		strcpy(buffer, p->lessonname);		//д��γ�����
		strcat(buffer, "\n");
		fputs(buffer, fpWrite);
		fprintf(fpWrite, "%d", p->classroom);
		fputc('\0', fpWrite);				//��Ϊ���ݵĸ���
		fprintf(fpWrite, "%d", p->number);
		fputc('\0', fpWrite);
		fprintf(fpWrite, "%d", p->normal);
		fputc('\0', fpWrite);
		fprintf(fpWrite, "%d", p->exam);
		if (p->next)
			fputs("\n", fpWrite);
		p = p->next;
	}
	fclose(fpWrite);
}

void AdminAccount(char Account[], char Password[])
{
	char buffer_Account[16];
	char buffer_Password[16];
	int flag = -1;
	FILE* fpRead;
	errno_t err;						//��fopen���
	//puts(Account);
	//puts(Password);
	if ((err = fopen_s(&fpRead, "Account.txt", "r")) != NULL)		//�ɹ�����0�����ɹ����ط�0
	{
		printf("δ�ҵ�Account.txt�ļ�\n");
		system("pause");
		exit(-1);
	}
	while (!feof(fpRead))
	{
		fgets(buffer_Account, sizeof(buffer_Account), fpRead);				//��ȡAdmin�˺�	
		//puts(buffer_Account);
		buffer_Account[strlen(buffer_Account) - 1] = 0;						//�������з�
		flag = strcmp(buffer_Account, Account);
		if (flag != 0)
			continue;
		fgets(buffer_Password, sizeof(buffer_Password), fpRead);			//��ȡAdmin����
		//puts(buffer_Password);
		buffer_Password[strlen(buffer_Password) - 1] = 0;					//�������з�
		flag = strcmp(buffer_Password, Password);
		if (flag != 0)
			continue;
		admin = 1;
		return;
	}
	printf("�˺��������\n");
	system("pause");
	return;
}

void Exam_sort(struct Student* pHead)			//�ܳɼ�����
{
	struct Student* p, * q, * tail;
	tail = NULL;
	while ((pHead->next->next) != tail)
	{
		p = pHead;
		q = pHead->next;
		while (q->next != tail)
		{
			if ((q->exam) > (q->next->exam))
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = p->next;
			}
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	printf("\t\t�����Գɼ���С��������ɹ�\n");
}

void Choose()
{
	int operation1, operation2;
	struct Student* temp = NULL;
	if (pHead->next == NULL)
	{
		printf("                *********************************\n");
		printf("                *\tϵͳ����ѧ����Ϣ\t*\n");
		printf("                *********************************\n");
	}
	printf("\n                    �����������:");
	scanf_s("%d", &operation1);
	printf("\n\n");
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
		case 2:Search_num(pHead); break;
		case 3:
			Search_classname(pHead);
			break;
		default:printf("��Ч������\n");
		}
		break;
	case 3:Score_sort(pHead); break;
		//printf("1���ܳɼ��ɸߵ���\n");
		//printf("2���ܳɼ��ɵ͵���\n");
		//printf("3�����Գɼ��ɵ͵���\n");
		//printf("4�����Գɼ��ɵ͵���\n");
		//scanf_s("%d", &operation2);
		//switch (operation2)
		//{
		//case 1:break;
		//case 2:break;
		//case 3:break;
		//case 4:break;
		//}
	case 4:Exam_sort(pHead); break;
	case 5:Excellent_rate(pHead); break;
	case 6:TravelList(pHead); break;
	case 7:Search_classname_LandH(pHead); break;
	case 8:Same_class_score(pHead); break;
	case 9:Login(); break;
	case 99:system("cls"); break;
	default:
		printf("��Ч�Ĳ�����\n");
		printf("�����������:");
		rewind(stdin);			//��ջ�����
		scanf_s("%d", &operation1);
		system("pause");
	}
}

void Delete_data()
{
	char key = 0;
	printf("ȷ��Ҫɾ����·�� Y/N  \n");
	rewind(stdin);			//��ջ�����
	scanf_s("%c", &key);
	if (key == 'Y')
	{
		if (_unlink("Student.txt") == 0)
			printf("�ɹ�ɾ�⣬�Ͻ���·��\n");
		system("pause");
	}
}