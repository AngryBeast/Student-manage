//学生管理系统					BY:AngryBeast		2019.6
#define _CRT_SECURE_NO_DEPRECATE					//与fopen_s,fscanf_s相关
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int admin;										//admin模式   1开启  0关闭
int lenth;
struct Student* pHead;
void FunctionList();							//打印功能列表函数
void Admin_FunctionList();						//admin功能列表
void Login();									//登陆admin
void TravelList(struct Student* pHead);			//遍历链表
void Choose();									//选择功能
void Singe_print(struct Student* p);			//单个打印学生信息
void FreeAll(struct Student* p);				//删除所有
struct Student Search_name(struct Student* p);	//搜索姓名
struct Student Search_num(struct Student* p);	//搜索学号
struct Student FileR(struct Student* pHead);	//文件读取
struct Student Cheak(struct Student* p);		//检查是否能申请到内存
struct Student
{
	char name[16];				//姓名
	char lessonname[16];		//课程名称
	int classroom;				//班级
	int number;					//学号
	int normal;					//平时成绩
	int exam;					//考试成绩
	int score;					//总分
	struct Student* next;
};
int main()
{
	int in1, in2;					// 从键盘输入的数
	admin = 0;
	lenth = sizeof(Student);
	system("color f5");		//调整背景和字体颜色
	pHead = (struct Student*)malloc(lenth);
	Cheak(pHead);
	pHead->next = NULL;
	while (!admin)			//非管理员模式
	{
		FunctionList();		//打印功能列表
		Choose();
		printf("\n\n\n");
	}
	while (admin)					//有管理员权限时
	{
		system("color 1c");
		Admin_FunctionList();
		scanf_s("%d", &in1);
		printf("\n\n\n");
	}

}
void FunctionList()					//打印功能列表函数
{
	printf_s("*******************************************************************\n");
	printf_s("\t\t\t***  学生成绩管理系统  ***\n");
	printf_s("\t\t无管理员权限\n");
	printf("0、退出程序\n");
	printf("1、从文件读取学生信息\n");
	printf("2、查询类\n");
	printf("3、排序类\n");
	printf("4、单科成绩\n");
	printf("5、查看班级优秀率、不及格率\n");
	printf("6、查看当前所有学生的成绩\n");
	printf("9、进入管理员模式\n");
}

void Admin_FunctionList()
{
	printf_s("*******************************************************************\n");
	printf_s("\t\t\t***  学生成绩管理系统  ***\n");
	printf_s("\t\t=======Admin mode========\n");
	printf("0、退出程序\n");
	printf("1、从文件读取学生信息\n");
	printf("2、查询类\n");
	printf("3、排序类\n");
	printf("4、单科成绩\n");
	printf("5、查看班级优秀率\n");
	printf("6、输入学生信息\n");
	printf("7、修改学生信息\n");
	printf("8、删除学生信息\n");
	printf("9、查看当前所有学生的成绩\n");
	printf("99、退出管理员模式\n");
}

void Login()
{
	char account[16] = { "AngryBeast" };			//管理员账户
	char password[16] = { "Admin111" };			//管理员密码
	char buffer[16] = { 0 };
	int flag1, flag2, i;
	flag1 = flag2 = -1;
	i = 0;
	printf_s("输入账号:");
	rewind(stdin);
	gets_s(buffer);
	flag1 = strcmp(buffer, account);
	printf_s("输入密码:");
	rewind(stdin);								//清空缓冲区
	gets_s(buffer);
	flag2 = strcmp(buffer, password);
	if (flag1 == 0 || flag2 == 0)
		admin = 1;
	else
		printf_s("用户名或密码输入错误\n");
	return;
}

struct Student Cheak(struct Student* p)
{
	if (p == NULL)
	{
		printf_s("error  无法申请到内存\n");
		system("pause");
		exit(-1);
	}
}

struct Student FileR(struct Student *pHead)
{
	int temp_normal,temp_exam,temp_score;
	char buffer[16];					//缓冲区
	FILE* fpRead = NULL;
	struct Student* p,* ptemp;
	errno_t err;						//与fopen相关
	if ((err = fopen_s(&fpRead, "stu.txt", "r")) != NULL)		//成功返回0，不成功返回非0
	{
		printf("未找到stu.txt文件\n");
		system("pause");
		exit(-1);
	}
	ptemp = pHead;
	while (!feof(fpRead))
	{
		p = (struct Student*)malloc(lenth);
		Cheak(p);
		p->next = NULL;
		fgets(p->name, sizeof(buffer), fpRead);									//读取学生名字	
		fgets(p->lessonname, sizeof(buffer), fpRead);							//读取课程名     
		fscanf(fpRead, "%d", &p->classroom);									//读取班级
		fscanf(fpRead, "%d", &p->number);										//读取学号
		fscanf(fpRead, "%d", &temp_normal);										//将平时分取出
		fscanf(fpRead, "%d", &temp_exam);										//将考试分数取出
		fgets(buffer, sizeof(buffer), fpRead);									//清除回车
		temp_score = (int)((0.20 * temp_normal) + (0.80 * temp_exam)+0.5);		//计算并四舍五入
		p->normal = temp_normal;
		p->exam = temp_exam;
		p->score = temp_score;

		ptemp->next = p;				//创建链表
		ptemp = p;
		//printf("%s",p->name);							//测试用，输出
		//printf("%s", p->lessonname);
		//printf("\t%d\t", p->classroom);
		//printf("%d\t", p->number);
		//printf("%d\t", p->normal);
		//printf("%d\t", p->exam);
		//printf("%d\t", p->score);
		//printf("\n");

	}
	fclose(fpRead);
	printf("成功读取文件\n");
	system("pause");
	return *pHead;
}

void TravelList(struct Student* pHead)					//遍历链表
{
	struct Student * p;
	p = pHead->next;
	while (p)
	{
		printf("%s",p->name);							//测试用，输出
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
	FileR(pHead);								//调试用
	TravelList(pHead);							//调试用
	char templessonname[32];
	int operation1, operation2;
	struct Student* temp = NULL;
	Search_name(pHead);
	printf("请输入操作数:");
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
		printf("1、按姓名查询学生信息\n");
		printf("2、按学号查询学生信息\n");
		printf("3、按课程名称查询学生信息\n");
		printf("4、按平时成绩查询学生信息\n");
		scanf_s("%d", &operation2);
		switch (operation2)
		{
		case 1:
			Search_name(pHead);
			break;
		case 2:
			temp = &Search_num(pHead);
			Singe_print(temp);
			break;
		case 3:break;
		case 4:break;
		}
		break;
	case 3:
		printf("1、总成绩由高到低\n");
		printf("2、总成绩由低到高\n");
		printf("3、考试成绩由低到高\n");
		printf("4、考试成绩由低到高\n");
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
		printf("请输入想要查询的课程名称:  ");
		gets_s(templessonname);
		//



		break;
	case 5:
		printf("请输入要查询的班级：  ");
		break;
	case 6:
		TravelList(pHead);
		break;
	case 7:break;
	case 8:break;
	case 9:Login(); break;
	default:
		printf("无效的操作数\n");
		system("pause");
	}
}

struct Student Search_num(struct Student *p)
{
	int temp;
	rewind(stdin);						//清空缓冲区
	printf("请输入要搜索的学号:");
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
			printf("未找到该学号学生的成绩\n");
		}
	}
	return *pHead;
}

void Singe_print(struct Student* p)
{
	printf("*****************************************************************\n");
	printf("姓名   课程名称    班级           学号          平时成绩      考试成绩      总分\n");
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
	int flag = 1;
	rewind(stdin);			//清空缓冲区
	printf("请输入要查询学生的姓名:");
	gets_s(buffer);
	/*scanf_s("%s", buffer);*/
	printf("1");
	//p = p->next;
	while (p)
	{
		flag = strcmp(buffer, p->name);
		if (!flag)
		{
			return *p;
		}
		p = p->next;
		if (p == NULL)
		{
			printf("未找到学生%s", buffer);
			system("pause");
		}
	}
	return *pHead;
}