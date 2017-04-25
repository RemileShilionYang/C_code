#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	extern void choose_menu();
	extern void _scanf();
	extern void _printf();
	extern void search();
	extern void insert();
	extern void change();
	extern void del();
	extern void _exit(); 
    int a; 
    choose_menu();
    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        _scanf();
        else if(a==2)
        _printf();
        else if(a==3)
        search();
        else if(a==4)
        insert();
        else if(a==5)
        change();
        else if(a==6)
        del(); 
        else if(a==7) 
        _exit();
        else 
		printf("输入错误，请重新输入:\t");
        printf("\t按任意键继续\n");
        choose_menu();
    }
}

 
void choose_menu()
{
 	printf("\t\t\t欢迎进入学生成绩系统\n");
 	printf("\n");
 	printf("\t\t1.录入成绩\n"); 
    printf("\t\t2.显示成绩\n"); 
    printf("\t\t3.查询成绩\n"); 
    printf("\t\t4.添加成绩\n"); 
    printf("\t\t5.修改成绩\n");
    printf("\t\t6.删除成绩\n"); 
    printf("\t\t7.退出系统\n"); 
    printf("\t\t----------------------------\n"); 
    printf("Please choise 1-7:\t"); 
    putchar(10);
}


struct stu{
    char num[20];
    char name[10];
    float grade;
    }student;


void _scanf() 
{
    char ch; 
    FILE *fp;
    if((fp=fopen("成绩.dat","wb+"))==NULL)
    {
        printf("Failure to open\n");
        exit(0); 
    } 
    do
    {
        printf("请输入学号:\t");
        getchar();
        gets(student.num);
        printf("姓名:\t");
        gets(student.name); 
        printf("成绩:\t");
        scanf("%f",&student.grade);
        if(fwrite(&student,sizeof(struct stu),1,fp)!=1)
        {
            printf("Error\n");
            exit(0);
        } 
        printf("继续输入?Y or N ?\t");
        getchar();
        ch=getchar();
    }while(ch=='y'||ch=='Y'); 
    fclose(fp); 
}


void _printf() 
{
    FILE *fp;
    if((fp=fopen("成绩.dat","rb"))==NULL)
    {
        printf("Failure to open\n");
        return ; 
    } 
    printf("学号\t姓名\t成绩\n");
    while(fread(&student,sizeof(struct stu),1,fp)==1)
    printf("%s\t%s\t%.3f\n",student.num,student.name,student.grade); 
    fclose(fp); 
}


void search() 
{ 
    int a,b=0;
    char ch[20]; 
    FILE *fp;
    if((fp=fopen("成绩.dat","rb"))==NULL)
    {
        printf("Failure to open\n");
        exit(0); 
    } 
    printf("请输入要查询的方式\n\t1.学号 2.姓名:\n\t请选择 1 or 2 \t");
    scanf("%d",&a); 
    if(a==1)
    { 
	    getchar();
        printf("请输入学号:\t");
        gets(ch);
        while(fread(&student,sizeof(struct stu),1,fp)==1)
        if(strcmp(student.num,ch)==0)
        { 
            b++;
            printf("学号\t姓名\t成绩\n");
            printf("%s\t%s\t%.3f\n",student.num,student.name,student.grade);
        }
        if(b==0) 
		printf("没有相关信息:\n");
    }
    else if(a==2)
    { 
	    printf("请输入成绩的姓名:\t");
        getchar();
        gets(ch);
        while(fread(&student,sizeof(struct stu),1,fp)==1)
        if(strcmp(student.name,ch)==0)
        {
            b++;
            printf("学号\t姓名\t成绩\n");
            printf("%s\t%s\t%.3f\n",student.num,student.name,student.grade);
        } 
        if(b==0) 
		printf("Error!\n"); 
    }
    fclose(fp); 
}


void insert() 
{
    char ch; 
    FILE *fp;
    if((fp=fopen("成绩.dat","ab"))==NULL)
    {
        printf("Failure to open\n");
        exit(0); 
    } 
    do
    {
        printf("请输入要添加成绩学生的学号:\t");
        getchar();
        gets(student.num);
        printf("姓名:\t");
        gets(student.name); 
        printf("成绩:\t");
        scanf("%f",&student.grade);
        if(fwrite(&student,sizeof(struct stu),1,fp)!=1)
        {
            printf("Error\n");
            exit(0);
        } 
        printf("是否继续输入Y or N ?\t");
        getchar();
        ch=getchar();
    }while(ch=='y'||ch=='Y'); 
    fclose(fp); 
}


void change()
{  
    struct stu{  
        char num[20];
        char name[10];
        float grade;
        }student; 
    FILE *fp2;
    int a,b=0,c=0,n=0;
    char ch[20],i; 
    FILE *fp;
    do
	{ 
        if((fp=fopen("成绩.dat","rb"))==NULL)
        {
            printf("Failuer to open\n");
            exit(0); 
        } 
        if((fp2=fopen("成绩副本.dat","wb"))==NULL)
        {
            printf("Failuer to open\n");
            exit(0); 
        } 
        printf("请输入要修改成绩学生的学号:\t");
        scanf("%s",ch);
        n++;
        while(fread(&student,sizeof(struct stu),1,fp)==1)
        { 
        if((strcmp(student.num,ch)==0))
        { 
            b++; 
            printf("学号\t姓名\t成绩\n");
            printf("%s\t%s\t%.3f\n",student.num,student.name,student.grade);
            getchar();
            printf("请输入学生的学号:\t");
            gets(student.num);
            printf("请输入学生的姓名:\t");
            gets(student.name);
            printf("请输入学生的成绩:\t");
            scanf("%f",&student.grade);
            getchar(); 
            fwrite(&student,sizeof(struct stu),1,fp2); 
        } 
        if(strcmp(student.num,ch)!=0)
        fwrite(&student,sizeof(struct stu),1,fp2); 
        }
        if(b==0) 
        { 
            printf("\t没有找到相关信息!\n");
            getchar();
        }
    rewind(fp); 
    printf("是否继续修改?enter 'Y' or 'N' \t");
    i=getchar(); 
    fclose(fp);
    fclose(fp2);
    remove("成绩.dat");
    rename("成绩副本.dat","成绩.dat"); 
    }while(i=='y'||i=='Y');
    if(b!=0)  
    printf("\t修改成功！\n");
} 


void del()
{  
    FILE *fp2;
    int a,b=0,c=0,n=0;
    char ch[20],i; 
    FILE *fp;
    do 
	{
        if((fp=fopen("成绩.dat","rb"))==NULL)
        {
            printf("Failure to open\n");
            exit(0); 
        } 
        if((fp2=fopen("成绩副本.dat","wb"))==NULL)
        {
            printf("Failure to open\n");
            exit(0); 
        } 
        printf("请输入要删除成绩学生的学号:\t");
        scanf("%s",ch);
        n++;
        while(fread(&student,sizeof(struct stu),1,fp)==1)
        { 
            if((strcmp(student.num,ch)==0))
            { 
                b++;  
                printf("学号\t姓名\t成绩\n");
                printf("%s\t%s\t%.3f\n",student.num,student.name,student.grade);
            } 
            else if(strcmp(student.num,ch)!=0)
            fwrite(&student,sizeof(struct stu),1,fp2); 
        }
        if(b==0) 
        { 
            printf("\t没有找到信息!\n");
            //getchar();
        }
        rewind(fp);
        getchar();
        getchar();
        printf("删除成功!"); 
        printf("是否继续删除?enter 'y' or 'n' \t");
		getchar();
        i=getchar(); 
        fclose(fp);
        fclose(fp2);
        remove("成绩.dat");
        rename("成绩副本.dat","成绩.dat"); 
    }while(i=='y'||i=='Y');
    if(b!=0)  
    printf("\t保存成功！\n");
}
 
 
void _exit()
{
    int a;
    char ch;
    printf("\t确定退出?请选择 Y or N: ");
    getchar();
    ch=getchar();
    if(ch=='y'||ch=='Y') 
	exit(0);
    else
    choose_menu();
}
