#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>  //windows下Sleep函数库，以毫秒为单位 
#include<time.h>
//#include<unistd.h>  LINUX下的sleep函数库，以秒为单位 
//文件的块读和块写，会把结构体里的指针一起读写进去，而结构体里的指针值并未改变
//所以可能出现对进来的指针值，指向了被占用的区域，所以报错 

#define Format1 "%s %d %d %d %s %s %d %d\n"
#define Format2 "%s %d %d %d %s %s %d %d\n"

typedef struct COMPUTER{
    char Number[20];
	int Brand;
	int Type;
	int Platform;
	char Name[15];
	char Configure[65];
	int Location;
	int Price;
	struct COMPUTER *Next;
}COMPUTER;


COMPUTER *Head=NULL,*End=NULL;
FILE *fp=NULL; 

int menu_brand(void)
{
	printf("  1.Acer\t\t\t2.Alienware\t\t\t3.Apple\t\t\t4.Asus\n");
	printf("  5.Colorful\t\t\t6.Coolpad\t\t\t7.Cube\t\t\t8.Dell\n");
	printf("  9.Gigabyte\t\t\t10.Hasee\t\t\t11.Hipaa\t\t12.Hp\n");
	printf("  13.Huawei\t\t\t14.Lenovo\t\t\t15.Mechrevo\t\t16.MI\n");
	printf("  17.Microsoft\t\t\t18.MSI\t\t\t\t19.Shinelon\t\t20.Sumsung\n");
	printf("  21.Teclast\t\t\t22.TerransForce\t\t\t23.ThinkPad\t\t24.ThinkServer\n");
	printf("  25.ThinkStation\t\t26.Thunderobot\n");
	printf("\nPlease choose 1-26:\t");
}


int menu_type(void)
{
	printf("  1.Server\t\t2.Workstation\t\t3.Game_Laptop\t\t4.Business_Laptop\n");
	printf("  5.Desktop_PC\t\t6.ALL_in_one_PC\t\t7.Tablet_PC\n");
	printf("\nPlease choose 1-7:\t");
}


int menu_platform(void)
{
	printf("  1.X86_64\t2.ARM\n");
	printf("\nPlease choose 1-2:\t");
}


int menu_location(void)
{
	printf("\t1.Low\t2.Standard\t3.High\t4.Top\n");
	printf("\nPlease choose 1-4:\t");
}


int title(void)
{
	printf("\n\t\t\t\t****************************************************\n");
	printf("\t\t\t\t**                                                **\n");
	printf("\t\t\t\t**      (>_<)欢迎使用计算机市场调查系统(>_<)      **\n");
	printf("\t\t\t\t**                                                **\n");
	printf("\t\t\t\t****************************************************\n");
}


int main_menu(void)
{
 	printf("\n\t\t\t\t***************************************************\n");
 	printf("\t\t\t\t**                                               **\n");
 	printf("\t\t\t\t**\t1.录入信息"); 
    printf("\t\t2.显示信息\t **\n"); 
    printf("\t\t\t\t**\t3.查询信息"); 
    printf("\t\t4.插入信息\t **\n"); 
    printf("\t\t\t\t**\t5.修改信息");
    printf("\t\t6.删除信息\t **\n");
	printf("\t\t\t\t**\t7.整理信息");
	printf("\t\t8.数据挖掘\t **\n");
	printf("\t\t\t\t**\t9.价位对比"); 
	printf("\t\t10.输出信息\t **\n");
	printf("\t\t\t\t**\t11.清空界面");
	printf("\t\t12.初始化程序\t **\n");
	printf("\t\t\t\t**\t13.查看文件");
    printf("\t\t14.退出系统\t **\n");
    printf("\t\t\t\t**                                               **\n");
    printf("\t\t\t\t***************************************************\n\n");
    printf("Please choose 1-14:\t");
}


int sub_menu(void)
{
	printf("\n");
	printf("\t\t\t1.信息排序\n");
	printf("\t\t\t2.信息归类\n");
	printf("\t\t\t3.返回上层菜单\n");
	printf("Please choose 1-3:\t");
}


int reflection_brand(int a)
{
	//判断输入是否符合1-26的功能在相应主调函数中 
	switch(a)
	{
		case 1:printf("Acer        ");break;
		case 2:printf("Alienware   ");break;
		case 3:printf("Apple       ");break;
		case 4:printf("Asus        ");break;
		case 5:printf("Colorful    ");break;
		case 6:printf("Coolpad     ");break;
		case 7:printf("Cube        ");break;
		case 8:printf("Dell        ");break;
		case 9:printf("Gigabyte    ");break;
		case 10:printf("Hasee       ");break;
		case 11:printf("Hipaa       ");break;
		case 12:printf("Hp          ");break;
		case 13:printf("Huawei      ");break;
		case 14:printf("Lenovo      ");break;
		case 15:printf("Mechrevo    ");break;
		case 16:printf("MI          ");break;
		case 17:printf("Microsoft   ");break;
		case 18:printf("MSI         ");break;
		case 19:printf("Shinelon    ");break;
		case 20:printf("Sumsung     ");break;
		case 21:printf("Teclast     ");break;
		case 22:printf("TerransForce");break;
		case 23:printf("ThinkPad    ");break;
		case 24:printf("ThinkServer ");break;
		case 25:printf("ThinkStation");break;
		case 26:printf("Thunderobot ");
	}
}


int reflection_type(int a)
{
	//判断输入是否符合1-7的功能在相应主调函数中 
	switch(a)
	{
		case 1:printf("Server         ");break;
		case 2:printf("Workstation    ");break;
		case 3:printf("Game_Laptop    ");break;
		case 4:printf("Business_Laptop");break;
		case 5:printf("Desktop_PC     ");break;
		case 6:printf("ALL_in_one_PC  ");break;
		case 7:printf("Tablet_PC      ");
	}
}


int reflection_platform(int a)
{
	//判断输入是否符合1-2的功能在相应主调函数中 
	switch(a)
	{
		case 1:printf("X86_64");break;
		case 2:printf("ARM   ");
	}
}


int reflection_location(int a)
{
	//判断输入是否符合1-4的功能在相应主调函数中 
	switch(a)
	{
		case 1:printf("Low     ");break;
		case 2:printf("Standard");break;
		case 3:printf("High    ");break;
		case 4:printf("Top     ");
	}
}


int create(void)
{
	extern int end();
	COMPUTER *New=(COMPUTER*)malloc(sizeof(COMPUTER));
    int input;
	
	printf("\n");
	char a[20]="请输入编号:";
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
		Sleep(50);
	}
	printf("\n");
    gets(New->Number);
	
  a:printf("\n");
	char b[20]="请选择计算机品牌:";
	for(int i=0;b[i]!='\0';i++)
	{
		printf("%c",b[i]);
		Sleep(50);
	}
	printf("\n");
 	menu_brand();
	scanf("%d",&input);
	if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7&&input!=8&&input!=9&&input!=10&&input!=11&&input!=12&&input!=13&&input!=14&&input!=15&&input!=16&&input!=17&&input!=18&&input!=19&&input!=20&&input!=21&&input!=22&&input!=23&&input!=24&&input!=25&&input!=26)
	{
		printf("\n输入错误,重新输入...\n");
		goto a;
	}
	New->Brand=input;
	fflush(stdin);
	
  b:printf("\n");
	char c[20]="请选择计算机类型:";
	for(int i=0;c[i]!='\0';i++)
	{
		printf("%c",c[i]);
		Sleep(50);
	}
	printf("\n");
	menu_type();
	scanf("%d",&input);
	if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7)
	{
		printf("\n输入错误,重新输入...\n");
		goto b;
	}
	New->Type=input;
	fflush(stdin);
	
  c:printf("\n");
	char e[20]="请选择架构:";
	for(int i=0;e[i]!='\0';i++)
	{
		printf("%c",e[i]);
		Sleep(50);
	}
	printf("\n");
    menu_platform();
    scanf("%d",&input);
    if(input!=1&&input!=2)
	{
		printf("\n输入错误,重新输入...\n");
		goto c;
	}
	New->Platform=input;
	fflush(stdin);
	
	printf("\n");
	char f[30]="请输入计算机具体型号:";
	for(int i=0;f[i]!='\0';i++)
	{
		printf("%c",f[i]);
		Sleep(50);
	}
	printf("\n");
	gets(New->Name);
	
	printf("\n");
	char g[30]="请输入计算机具体配置:";
	for(int i=0;g[i]!='\0';i++)
	{
		printf("%c",g[i]);
		Sleep(50);
	}
	printf("\n");
	gets(New->Configure);
	
  d:printf("\n");
	char h[20]="请选择当前配置水平:";
	for(int i=0;h[i]!='\0';i++)
	{
		printf("%c",h[i]);
		Sleep(50);
	}
	printf("\n");
	menu_location();
	scanf("%d",&input);
	if(input!=1&&input!=2&&input!=3&&input!=4)
	{
		printf("\n输入错误,重新输入...\n");
		goto d;
	}
	New->Location=input;
	fflush(stdin);
	
	printf("\n");
	char j[20]="请输入价格:";
	for(int i=0;j[i]!='\0';i++)
	{
		printf("%c",j[i]);
		Sleep(50);
	}
	printf("\n");
	scanf("%d",&input);
    New->Price=input;
	fflush(stdin);
	
	fp=fopen("记录信息.txt","a+");
    if(fp==NULL)
	{
		printf("\n程序出错(*_*),即将关闭...\n");
		free(New);
		New=NULL;
		Sleep(3000);
		end();
	}
	fprintf(fp,Format2,New->Number,New->Brand,New->Type,New->Platform,New->Name,New->Configure,New->Location,New->Price);
	fclose(fp);
	End->Next=New;
	New->Next=NULL;
	End=End->Next;
}


int blank(int a,int b)
{
	for(int i=1;i<=a-b;i++)
	printf(" ");
}


int show(void)
{
 	COMPUTER *p;
    p=Head;
    int a,b;
    printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
    while(p!=NULL)
    {
    	printf("\n%s\t",p->Number);
    	reflection_brand(p->Brand);
    	printf("\t");
    	reflection_type(p->Type);
    	printf("\t\t");
    	reflection_platform(p->Platform);
    	printf("\t\t");
    	printf("%s",p->Name);
    	a=sizeof(p->Name);
    	b=strlen(p->Name);
    	blank(a,b);
		printf("%s",p->Configure);
		a=sizeof(p->Configure);
    	b=strlen(p->Configure);
    	blank(a,b);
    	reflection_location(p->Location);
    	printf("\t");
    	printf("%d\n",p->Price ); 
    	p=p->Next;
	}
}


int seek(void)
{
	char index[20];
	COMPUTER *p=Head;
	int a,b,k,m,n,f;
	printf("\n请选择查找方式：1.精确查找 2.模糊查找\n");
	scanf("%d",&m);
	fflush(stdin);
	if(m==1)
	{
	poi:printf("\n1.按编号查找\t2.按型号查找\n");
	    scanf("%d",&k);
	    fflush(stdin);
	    if(k==1)
	    {
		    printf("\n请输入编号:\n");
		    gets(index);
		    while(p!=NULL)
		    {
		 	    if(strcmp(p->Number,index)==0)
			    {
				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
				break;	
			    }
			p=p->Next;
	        }
        }
	    else if(k==2)
	    {
		    printf("\n请输入型号:\n");
		    gets(index);
		    while(p!=NULL)
		    {
			if(strcmp(p->Name,index)==0)
			{
				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
				break;	
			}
			p=p->Next;
		    }
	    }
	    else
	    {
		    printf("\n输入错误，请重新输入:\n");
		    goto poi;
	    }
    }
	else if(m==2)
	{
	ghj:printf("\n请选择首要关键字：1.品牌 2.类型 3.价格\n");
		scanf("%d",&n);
		fflush(stdin);
		if(n==1)
		{
		kkk:printf("\n请选择品牌：\n");
			int c;
			menu_brand();
			scanf("%d",&c);
			fflush(stdin);
			if(c!=1&&c!=2&&c!=3&&c!=4&&c!=5&&c!=6&&c!=7&&c!=8&&c!=9&&c!=10&&c!=11&&c!=12&&c!=13&&c!=14&&c!=15&&c!=16&&c!=17&&c!=18&&c!=19&&c!=20&&c!=21&&c!=22&&c!=23&&c!=24&&c!=25&&c!=26)
	        {
		        printf("\n输入错误,重新输入...\n");
	        	goto kkk;
	        }
		tyu:printf("\n请选择次要关键字：1.类型 2.价格\n");
			scanf("%d",&f);
			fflush(stdin);
			if(f==1)
			{
				int d;
			ggg:menu_type();
				scanf("%d",&d);
				fflush(stdin);
				if(d!=1&&d!=2&&d!=3&&d!=4&&d!=5&&d!=6&&d!=7)
	            {
		            printf("\n输入错误,重新输入...\n");
	        	    goto ggg;
	            }
				while(p!=NULL)
				{
					if(p->Brand==c&&p->Type==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else if(f==2)
			{
				int d;
				printf("\n请输入价格:\n");
				scanf("%d",&d);
				fflush(stdin);
				while(p!=NULL)
				{
					if(p->Brand==c&&p->Price==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else
			{
				printf("\n输入错误，请重新输入....\n");
				goto tyu;
			}
		}
		else if(n==2)
		{
		iii:printf("\n请选择类型：\n");
			int c;
			menu_type();
			scanf("%d",&c);
			fflush(stdin);
			if(c!=1&&c!=2&&c!=3&&c!=4&&c!=5&&c!=6&&c!=7)
	        {
		        printf("\n输入错误,重新输入...\n");
	        	goto iii;
	        }
		ccc:printf("\n请选择次要关键字：1.品牌 2.价格\n");
			scanf("%d",&f);
			fflush(stdin);
			if(f==1)
			{
				int d;
			lll:menu_brand();
				scanf("%d",&d);
				fflush(stdin);
				if(d!=1&&d!=2&&d!=3&&d!=4&&d!=5&&d!=6&&d!=7&&d!=8&&d!=9&&d!=10&&d!=11&&d!=12&&d!=13&&d!=14&&d!=15&&d!=16&&d!=17&&d!=18&&d!=19&&d!=20&&d!=21&&d!=22&&d!=23&&d!=24&&d!=25&&d!=26)
	            {
		            printf("\n输入错误,重新输入...\n");
	        	    goto lll;
	            }
				while(p!=NULL)
				{
					if(p->Type==c&&p->Brand==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else if(f==2)
			{
				int d;
			    printf("\n请输入价格：\n");
				scanf("%d",&d);
				fflush(stdin);
				while(p!=NULL)
				{
					if(p->Type==c&&p->Price==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else
			{
				printf("\n输入错误，请重新输入....\n");
				goto ccc;
			}
		}
		else if(n==3)
		{
		    printf("\n请输入价格：\n");
			int c;
			scanf("%d",&c);
			fflush(stdin);
		hhh:printf("\n请选择次要关键字：1.品牌 2.类型\n");
			scanf("%d",&f);
			fflush(stdin);
			if(f==1)
			{
				int d;
			ooo:menu_brand();
				scanf("%d",&d);
				fflush(stdin);
				if(d!=1&&d!=2&&d!=3&&d!=4&&d!=5&&d!=6&&d!=7&&d!=8&&d!=9&&d!=10&&d!=11&&d!=12&&d!=13&&d!=14&&d!=15&&d!=16&&d!=17&&d!=18&&d!=19&&d!=20&&d!=21&&d!=22&&d!=23&&d!=24&&d!=25&&d!=26)
	            {
		            printf("\n输入错误,重新输入...\n");
	        	    goto ooo;
	            }
				while(p!=NULL)
				{
					if(p->Price==c&&p->Brand==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else if(f==2)
			{
				int d;
			vvv:menu_type();
				scanf("%d",&d);
				fflush(stdin);
				if(d!=1&&d!=2&&d!=3&&d!=4&&d!=5&&d!=6&&d!=7)
	            {
		            printf("\n输入错误,重新输入...\n");
	        	    goto vvv;
	            }
				while(p!=NULL)
				{
					if(p->Price==c&&p->Type==d)
					{
						printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
				        printf("\n%s\t",p->Number);
    	                reflection_brand(p->Brand);
    	                printf("\t");
    	                reflection_type(p->Type);
    	                printf("\t\t");
    	                reflection_platform(p->Platform);
    	                printf("\t\t");
    	                printf("%s",p->Name);
    	                a=sizeof(p->Name);
    	                b=strlen(p->Name);
    	                blank(a,b);
		                printf("%s",p->Configure);
		                a=sizeof(p->Configure);
    	                b=strlen(p->Configure);
    	                blank(a,b);
    	                reflection_location(p->Location);
    	                printf("\t");
    	                printf("%d\n",p->Price );
				        break;	
					}
					p=p->Next;
				}
			}
			else
			{
				printf("\n输入错误,请重新输入....\n");
			    goto hhh;
			}
		}
		else
		{
			printf("\n输入错误,请重新输入....\n");
			goto ghj;
		}
	}
	else
	{
		printf("\n输入错误，重新输入....\n");
		seek();
	}
	
	if(p==NULL)
	printf("\n没有找到相应计算机信息,请确定信息确实存在于数据记录中...\n");
}


int insert(void)
{
	char temp[20];
	COMPUTER *f,*p,*w;
	f=p=Head;
	int input,k;
	printf("\n选择插入的标志类型.  1.编号2.型号\n");
	scanf("%d",&k);
	fflush(stdin);
	if(k==1)
	{
		printf("\n请输入编号:\n");
		gets(temp);
		while(f!=NULL)
		{
			if(strcmp(f->Number,temp)==0)
 	     	{
 			p=f->Next;
 			w=(COMPUTER*)malloc(sizeof(COMPUTER));
 			f->Next=w;
 			w->Next=p;
 			
 			printf("\n");
	        char a[20]="请输入编号:";
	        for(int i=0;a[i]!='\0';i++)
	        {
		        printf("%c",a[i]);
		        Sleep(50);
	        }
	        printf("\n");
            gets(w->Number);
	
 	      e:printf("\n");
	        char b[20]="请选择计算机品牌:";
	        for(int i=0;b[i]!='\0';i++)
	        {
	        	printf("%c",b[i]);
	        	Sleep(50);
	        }
	        printf("\n");
 	        menu_brand();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7&&input!=8&&input!=9&&input!=10&&input!=11&&input!=12&&input!=13&&input!=14&&input!=15&&input!=16&&input!=17&&input!=18&&input!=19&&input!=20&&input!=21&&input!=22&&input!=23&&input!=24&&input!=25&&input!=26)
	        {
		        printf("\n输入错误,重新输入...\n");
	        	goto e;
	        }
	        w->Brand=input;
	        fflush(stdin);
	
	      f:printf("\n");
	        char c[20]="请选择计算机类型:";
	        for(int i=0;c[i]!='\0';i++)
	        {
		        printf("%c",c[i]);
		        Sleep(50);
	        }
	        printf("\n");
	        menu_type();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto f;
	        }
	        w->Type=input;
	        fflush(stdin);
	
	      g:printf("\n");
	        char e[20]="请选择架构:";
	        for(int i=0;e[i]!='\0';i++)
	        {
		        printf("%c",e[i]);
	         	Sleep(50);
            }
	        printf("\n");
            menu_platform();
            scanf("%d",&input);
            if(input!=1&&input!=2)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto g;
	        }
	        w->Platform=input;
	        fflush(stdin);
	
	        printf("\n");
	        char f[30]="请输入计算机具体型号:";
	        for(int i=0;f[i]!='\0';i++)
	        {
		        printf("%c",f[i]);
		        Sleep(50);
	        }
	        printf("\n");
        	gets(w->Name);
	
        	printf("\n");
	        char g[30]="请输入计算机具体配置:";
	        for(int i=0;g[i]!='\0';i++)
	        {
		        printf("%c",g[i]);
		        Sleep(50);
	        }
	        printf("\n");
	        gets(w->Configure);
	
	      h:printf("\n");
	        char h[20]="请选择当前配置水平:";
	        for(int i=0;h[i]!='\0';i++)
	        {
	         	printf("%c",h[i]);
	        	Sleep(50);
	        }
	        printf("\n");
	        menu_location();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto h;
	        }
	        w->Location=input;
	        fflush(stdin);
	
	        printf("\n");
	        char j[20]="请输入价格:";
	        for(int i=0;j[i]!='\0';i++)
        	{
	        	printf("%c",j[i]);
        		Sleep(50);
        	}
         	printf("\n");
	        scanf("%d",&input);
	        w->Price=input;
	        fflush(stdin);
	        
	        break;
	    	}
		f=f->Next;
		}
		
	}
	else if(k==2)
	{
		printf("\n请输入型号:\n");
		gets(temp);
		while(f!=NULL)
		{
			if(strcmp(f->Name,temp)==0)
 	     	{
 			p=f->Next;
 			w=(COMPUTER*)malloc(sizeof(COMPUTER));
 			f->Next=w;
 			w->Next=p;
 			
 			printf("\n");
	        char a[20]="请输入编号:";
	        for(int i=0;a[i]!='\0';i++)
	        {
		        printf("%c",a[i]);
		        Sleep(50);
	        }
	        printf("\n");
            gets(w->Number);
	
 	      i:printf("\n");
	        char b[20]="请选择计算机品牌:";
	        for(int i=0;b[i]!='\0';i++)
	        {
	        	printf("%c",b[i]);
	        	Sleep(50);
	        }
	        printf("\n");
 	        menu_brand();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7&&input!=8&&input!=9&&input!=10&&input!=11&&input!=12&&input!=13&&input!=14&&input!=15&&input!=16&&input!=17&&input!=18&&input!=19&&input!=20&&input!=21&&input!=22&&input!=23&&input!=24&&input!=25&&input!=26)
	        {
		        printf("\n输入错误,重新输入...\n");
	        	goto i;
	        }
	        w->Brand=input;
	        fflush(stdin);
	
	      j:printf("\n");
	        char c[20]="请选择计算机类型:";
	        for(int i=0;c[i]!='\0';i++)
	        {
		        printf("%c",c[i]);
		        Sleep(50);
	        }
	        printf("\n");
	        menu_type();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4&&input!=5&&input!=6&&input!=7)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto j;
	        }
	        w->Type=input;
	        fflush(stdin);
	
	      k:printf("\n");
	        char e[20]="请选择架构:";
	        for(int i=0;e[i]!='\0';i++)
	        {
		        printf("%c",e[i]);
	         	Sleep(50);
            }
	        printf("\n");
            menu_platform();
            scanf("%d",&input);
            if(input!=1&&input!=2)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto k;
	        }
	        w->Platform=input;
	        fflush(stdin);
	
	        printf("\n");
	        char f[30]="请输入计算机具体型号:";
	        for(int i=0;f[i]!='\0';i++)
	        {
		        printf("%c",f[i]);
		        Sleep(50);
	        }
	        printf("\n");
        	gets(w->Name);
	
        	printf("\n");
	        char g[30]="请输入计算机具体配置:";
	        for(int i=0;g[i]!='\0';i++)
	        {
		        printf("%c",g[i]);
		        Sleep(50);
	        }
	        printf("\n");
	        gets(w->Configure);
	
	      l:printf("\n");
	        char h[20]="请选择当前配置水平:";
	        for(int i=0;h[i]!='\0';i++)
	        {
	         	printf("%c",h[i]);
	        	Sleep(50);
	        }
	        printf("\n");
	        menu_location();
	        scanf("%d",&input);
	        if(input!=1&&input!=2&&input!=3&&input!=4)
	        {
		        printf("\n输入错误,重新输入...\n");
		        goto l;
	        }
	        w->Location=input;
	        fflush(stdin);
	
	        printf("\n");
	        char j[20]="请输入价格:";
	        for(int i=0;j[i]!='\0';i++)
        	{
	        	printf("%c",j[i]);
        		Sleep(50);
        	}
         	printf("\n");
	        scanf("%d",&input);
	        w->Price=input;
	        fflush(stdin);
	        
	        break; 
	    	}
		f=f->Next;
		}
	}
	else
	{
		printf("\n输入错误，重新输入:\n");
		insert();
	}
	
	if(f==NULL)
	printf("\n(*_*)信息不存在!\n");
	else
	{
		fp=fopen("记录信息.txt","w");
		f=Head;
	    while(f!=NULL)
	    {
	    	fprintf(fp,Format2,f->Number,f->Brand,f->Type,f->Platform,f->Name,f->Configure,f->Location,f->Price);
	    	f=f->Next;
		}
		fclose(fp);
	}
}


int change(void)
{
	COMPUTER *b;
 	b=Head;
 	int a,k;
 	printf("\n请选择编号或型号:1.编号2.型号\n");
 	scanf("%d",&k);
 	fflush(stdin);
 	if(k==1)
	{
		char temp[20];
		printf("\n请输入编号:\n");
		gets(temp);
		while(b!=NULL)
 	    {
 		    if(strcmp(b->Number,temp)==0)
 		    { 
 		        char fh;
 		        printf("是否修改计算机品牌: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          m:printf("请选择计算机品牌:\n");
 	                menu_brand();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7&&a!=8&&a!=9&&a!=10&&a!=11&&a!=12&&a!=13&&a!=14&&a!=15&&a!=16&&a!=17&&a!=18&&a!=19&&a!=20&&a!=21&&a!=22&&a!=23&&a!=24&&a!=25&&a!=26)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto m;
	                }
	                b->Brand=a;
	                fflush(stdin);
				}
				else;
	            
	            printf("是否修改计算机类型: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          n:printf("\n请选择计算机类型:\n");
	                menu_type();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto n;
	                }
	                b->Type=a;
	                fflush(stdin);
				}
				else;
	            
	            printf("是否修改计算机架构: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          o:printf("\n请选择架构:\n");
                    menu_platform();
                    scanf("%d",&a);
                    if(a!=1&&a!=2)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto o;
	                }
	                b->Platform=a;
	                fflush(stdin);
				}
				else;
	            
	            printf("是否修改计算机具体型号: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		        	printf("\n请输入计算机具体型号:\n");
        	        gets(b->Name);
				}
				else;
	            
	            printf("是否修改计算机具体配置: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		        	printf("\n请输入计算机具体配置:\n");
	                gets(b->Configure);
				}
				else;
        	    
	            printf("是否修改计算机配置水平: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          p:printf("\n请选择当前配置水平:\n");
	                menu_location();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto p;
	                }
	                b->Location=a;
	                fflush(stdin);
				}
				else;
	            
	            printf("是否修改计算机价格: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		        	printf("\n请输入价格:\n");
	                scanf("%d",&a);
	                b->Price=a;
	                fflush(stdin);
				}
				else;
	            
	            
	            break;
		    }
		    b=b->Next; 
		}
	}
	else if(k==2)
	{
		char temp[20];
		printf("\n请输入型号:\n");
		gets(temp);
		while(b!=NULL)
 	    {
 		    if(strcmp(b->Name,temp)==0)
 		    { 
                char fh;
 		        printf("是否修改计算机品牌: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          q:printf("请选择计算机品牌:\n");
 	                menu_brand();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7&&a!=8&&a!=9&&a!=10&&a!=11&&a!=12&&a!=13&&a!=14&&a!=15&&a!=16&&a!=17&&a!=18&&a!=19&&a!=20&&a!=21&&a!=22&&a!=23&&a!=24&&a!=25&&a!=26)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto q;
	                }
	                b->Brand=a;
	                fflush(stdin);
				}
	            
	            printf("是否修改计算机类型: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          r:printf("\n请选择计算机类型:\n");
	                menu_type();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto r;
	                }
	                b->Type=a;
	                fflush(stdin);
				}
	            
	            printf("是否修改计算机架构: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          s:printf("\n请选择架构:\n");
                    menu_platform();
                    scanf("%d",&a);
                    if(a!=1&&a!=2)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto s;
	                }
	                b->Platform=a;
	                fflush(stdin);
				}
	            
	            printf("是否修改计算机具体配置: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		        	printf("\n请输入计算机具体配置:\n");
	                gets(b->Configure);
				}
        	    
	            printf("是否修改计算机配置水平: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		          t:printf("\n请选择当前配置水平:\n");
	                menu_location();
	                scanf("%d",&a);
	                if(a!=1&&a!=2&&a!=3&&a!=4)
	                {
		                printf("\n输入错误,重新输入...\n");
		                goto t;
	                }
	                b->Location=a;
	                fflush(stdin);
				}
	            
	            printf("是否修改计算机价格: Y/else\n");
 		        fh=getchar();
 		        fflush(stdin);
 		        if(fh=='Y'||fh=='y')
 		        {
 		        	printf("\n请输入价格:\n");
	                scanf("%d",&a);
	                b->Price=a;
	                fflush(stdin);
				}
	            
	            
	            break;
		    }
		    b=b->Next; 
		}
	}
	else
	{
		printf("\n输入错误,请重新输入:\n");
		change();
	} 
 	
	if(b==NULL)
	printf("\n(*_*)信息不存在!\n");
	else
	{
		fp=fopen("记录信息.txt","w");
		b=Head;
	    while(b!=NULL)
	    {
	    	fprintf(fp,Format2,b->Number,b->Brand,b->Type,b->Platform,b->Name,b->Configure,b->Location,b->Price);
	    	b=b->Next;
		}
		fclose(fp);
	}
}


int del(void)
{
	char index[20];
	COMPUTER *q=Head,*p=Head,*e;
	int a;
	printf("\n1.按编号查找\t2.按型号查找\n");
	scanf("%d",&a);
	fflush(stdin);
	if(a==1)
	{
		printf("\n请输入编号:\n");
		gets(index);
		while(q!=NULL)
		{
			if(strcmp(q->Number,index)==0&&q==Head)
			{
				e=Head;
 			    Head=Head->Next;
 			    free(e);
				break;	
			}
			if(strcmp(q->Number,index)==0&&q!=Head)
			{
				e=q;
 			    p->Next=q->Next;
 			    free(e);
				break;	
			}
			p=q;
			q=q->Next;
		}
	}
	else if(a==2)
	{
		printf("\n请输入型号:\n");
		gets(index);
		while(q!=NULL)
		{
			if(strcmp(q->Name,index)==0&&q==Head)
			{
				e=Head;
 			    Head=Head->Next;
 			    free(e);
				break;	
			}
			if(strcmp(q->Name,index)==0&&q!=Head)
			{
				e=q;
 			    p->Next=q->Next;
 			    free(e);
				break;
			}
			p=q;
			q=q->Next;
		}
	}
	else
	{
		printf("\n输入错误，请重新输入:\n");
		del();
	}
	
	if(q==NULL)
	printf("\n没有找到相应计算机信息,请确定信息确实存在于数据记录中...\n");
	else
	{
		fp=fopen("记录信息.txt","w");
		q=Head;
	    while(q!=NULL)
	    {
	    	fprintf(fp,Format2,q->Number,q->Brand,q->Type,q->Platform,q->Name,q->Configure,q->Location,q->Price);
	    	q=q->Next;
		}
		fclose(fp);
	}
	printf("\n已删除...按任意键继续.\n");
	getchar();
}


int sort(void)
{
	int a,b;
	printf("\n请选择排序方式:1.按编号2.按价格\n");
	scanf("%d",&a);
	fflush(stdin);
	printf("\n请选择升序还是降序1.升序2.降序\n");
	scanf("%d",&b);
	fflush(stdin);
	if(a==1&&b==1)
	{
		for(COMPUTER *i=Head;i!=NULL;i=i->Next)
		for(COMPUTER *j=i->Next;j!=NULL;j=j->Next)
		{
			if(strcmp(i->Number,j->Number)>0)
			{
				char index[20];
				strcpy(index,j->Number);
				strcpy(j->Number,i->Number);
				strcpy(i->Number,index);
				
				int INDEX=j->Brand;
				j->Brand=i->Brand;
				i->Brand=INDEX;
			
			    INDEX=j->Type;
			    j->Type=i->Type;
				i->Type=INDEX;
			  
				INDEX=j->Platform;
				j->Platform=i->Platform;
				i->Platform=INDEX;
				
	            strcpy(index,j->Name);
	            strcpy(j->Name,i->Name);
	            strcpy(i->Name,index);
	            
	            char Index[100];
	            strcpy(Index,j->Configure);
	            strcpy(j->Configure,i->Configure);
	            strcpy(i->Configure,Index);
	            
	            INDEX=j->Location;
				j->Location=i->Location;
				i->Location=INDEX;
				
	            INDEX=j->Price;
	            j->Price=i->Price;
	            i->Price=INDEX;
			}
		} 
	}
	else if(a==1&&b==2)
	{
		for(COMPUTER *i=Head;i!=NULL;i=i->Next)
		for(COMPUTER *j=i->Next;j!=NULL;j=j->Next)
		{
			if(strcmp(i->Number,j->Number)<0)
			{
				char index[20];
				strcpy(index,j->Number);
				strcpy(j->Number,i->Number);
				strcpy(i->Number,index);
				
				int INDEX=j->Brand;
				j->Brand=i->Brand;
				i->Brand=INDEX;
			
			    INDEX=j->Type;
			    j->Type=i->Type;
				i->Type=INDEX;
			  
				INDEX=j->Platform;
				j->Platform=i->Platform;
				i->Platform=INDEX;
				
	            strcpy(index,j->Name);
	            strcpy(j->Name,i->Name);
	            strcpy(i->Name,index);
	            
	            char Index[100];
	            strcpy(Index,j->Configure);
	            strcpy(j->Configure,i->Configure);
	            strcpy(i->Configure,Index);
	            
	            INDEX=j->Location;
				j->Location=i->Location;
				i->Location=INDEX;
				
	            INDEX=j->Price;
	            j->Price=i->Price;
	            i->Price=INDEX;
			}
		} 
	}
	else if(a==2&&b==1)
	{
		for(COMPUTER *i=Head;i!=NULL;i=i->Next)
		for(COMPUTER *j=i->Next;j!=NULL;j=j->Next)
		{
			if(i->Price>j->Price)
			{
			    char index[20];
				strcpy(index,j->Number);
				strcpy(j->Number,i->Number);
				strcpy(i->Number,index);
				
				int INDEX=j->Brand;
				j->Brand=i->Brand;
				i->Brand=INDEX;
			
			    INDEX=j->Type;
			    j->Type=i->Type;
				i->Type=INDEX;
			  
				INDEX=j->Platform;
				j->Platform=i->Platform;
				i->Platform=INDEX;
				
	            strcpy(index,j->Name);
	            strcpy(j->Name,i->Name);
	            strcpy(i->Name,index);
	            
	            char Index[100];
	            strcpy(Index,j->Configure);
	            strcpy(j->Configure,i->Configure);
	            strcpy(i->Configure,Index);
	            
	            INDEX=j->Location;
				j->Location=i->Location;
				i->Location=INDEX;
				
	            INDEX=j->Price;
	            j->Price=i->Price;
	            i->Price=INDEX;
			}
		} 
	}
	else if(a==2&&b==2)
	{
		for(COMPUTER *i=Head;i!=NULL;i=i->Next)
		for(COMPUTER *j=i->Next;j!=NULL;j=j->Next)
		{
			if(i->Price<j->Price)
			{
			    char index[20];
				strcpy(index,j->Number);
				strcpy(j->Number,i->Number);
				strcpy(i->Number,index);
				
				int INDEX=j->Brand;
				j->Brand=i->Brand;
				i->Brand=INDEX;
			
			    INDEX=j->Type;
			    j->Type=i->Type;
				i->Type=INDEX;
			  
				INDEX=j->Platform;
				j->Platform=i->Platform;
				i->Platform=INDEX;
				
	            strcpy(index,j->Name);
	            strcpy(j->Name,i->Name);
	            strcpy(i->Name,index);
	            
	            char Index[100];
	            strcpy(Index,j->Configure);
	            strcpy(j->Configure,i->Configure);
	            strcpy(i->Configure,Index);
	            
	            INDEX=j->Location;
				j->Location=i->Location;
				i->Location=INDEX;
				
	            INDEX=j->Price;
	            j->Price=i->Price;
	            i->Price=INDEX;
			}
		} 
	}
	else
	{
		printf("\n输入错误，请重新输入:\n");
		sort();
	}
	
	COMPUTER *g;
	fp=fopen("记录信息.txt","w");
	g=Head;
	while(g!=NULL)
	{
	   	fprintf(fp,Format2,g->Number,g->Brand,g->Type,g->Platform,g->Name,g->Configure,g->Location,g->Price);
	   	g=g->Next;
	}
	fclose(fp);
}


int classify(void)
{
	int a,b;
	COMPUTER *h=Head;
	printf("\n请选择分类标准: 1.品牌, 2.类型, 3.架构, 4.价格. \n");
	scanf("%d",&a);
	fflush(stdin);
	printf("\n归类结果以输出到源程序文件夹下，请查看.\n"); 
	if(a==1)
	{
		system("mkdir 归类结果_品牌");
		while(h!=NULL)
		{
			switch(h->Brand)
	        {
		        case 1:
				{
					fp=fopen("归类结果_品牌/Acer.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 2:
				{
					fp=fopen("归类结果_品牌/Alienware.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 3:
				{
					fp=fopen("归类结果_品牌/Apple.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 4:
				{
					fp=fopen("归类结果_品牌/Asus.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 5:
				{
					fp=fopen("归类结果_品牌/Colorful.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 6:
				{
					fp=fopen("归类结果_品牌/Coolpad.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 7:
				{
					fp=fopen("归类结果_品牌/Cube.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 8:
				{
					fp=fopen("归类结果_品牌/Dell.txt","a+");
				    fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 9:
				{
					fp=fopen("归类结果_品牌/Gigabyte.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 10:
				{
					fp=fopen("归类结果_品牌/Hasee.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 11:
				{
					fp=fopen("归类结果_品牌/Hipaa.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 12:
				{
					fp=fopen("归类结果_品牌/Hp.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 13:
				{
					fp=fopen("归类结果_品牌/Huawei.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 14:
				{
					fp=fopen("归类结果_品牌/Lenovo.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
	        	case 15:
				{
					fp=fopen("归类结果_品牌/Mechrevo.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 16:
				{
					fp=fopen("归类结果_品牌/MI.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 17:
				{
					fp=fopen("归类结果_品牌/Microsoft.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 18:
				{
					fp=fopen("归类结果_品牌/MSI.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 19:
				{
					fp=fopen("归类结果_品牌/Shinelon.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 20:
				{
					fp=fopen("归类结果_品牌/Sumsung.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 21:
				{
					fp=fopen("归类结果_品牌/Teclast.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 22:
				{
					fp=fopen("归类结果_品牌/TerransForce.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 23:
				{
					fp=fopen("归类结果_品牌/ThinkPad.txt","a+");
				    fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 24:
				{
					fp=fopen("归类结果_品牌/ThinkServer.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 25:
				{
					fp=fopen("归类结果_品牌/ThinkStation.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 26:
				{
					fp=fopen("归类结果_品牌/Thunderobot.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
				}
		    }
		    h=h->Next;
	    }
    }
	else if(a==2)
	{
		system("mkdir 归类结果_类型");
		while(h!=NULL)
		{
			switch(h->Type)
	        {
		        case 1:
				{
					fp=fopen("归类结果_类型/Server.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 2:
				{
					fp=fopen("归类结果_类型/Workstation.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 3:
				{
					fp=fopen("归类结果_类型/Game_Laptop.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 4:
				{
					fp=fopen("归类结果_类型/Business_Laptop.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 5:
				{
					fp=fopen("归类结果_类型/Desktop_PC.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 6:
				{
					fp=fopen("归类结果_类型/ALL_in_one_PC.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 7:
				{
					fp=fopen("归类结果_类型/Tablet_PC.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
				}
			}
			h=h->Next;
		}
	}
	else if(a==3)
	{
		system("mkdir 归类结果_架构");
		while(h!=NULL)
		{
			switch(h->Type)
	        {
		        case 1:
				{
					fp=fopen("归类结果_架构/X86_64.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
					break;
				}
		        case 2:
				{
					fp=fopen("归类结果_架构/ARM.txt","a+");
					fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
					fclose(fp);
				}
			}
			h=h->Next;
		} 
	}
	else if(a==4)
	{
		int array[5]; 
		printf("\n请由低到高依次输入5个具体界限:\n");
		for(int i=0;i<5;i++)
		{
		asd:scanf("%d",&array[i]);
			if(i!=0&&array[i]<array[i-1])
			{
				printf("\n错误,未按规定输入.重新输入.\n");
				goto asd;
			}
		    fflush(stdin);
		}
		
		system("mkdir 归类结果_价格");
		while(h!=NULL)
		{
			if(h->Price>=0&&h->Price<=array[0])
			{
				fp=fopen("归类结果_价格/1.txt","a+");
				fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else if(h->Price>array[0]&&h->Price<=array[1])
			{
				fp=fopen("归类结果_价格/2.txt","a+");
				fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else if(h->Price>array[1]&&h->Price<=array[2])
			{
				fp=fopen("归类结果_价格/3.txt","a+");
			    fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else if(h->Price>array[2]&&h->Price<=array[3])
			{
				fp=fopen("归类结果_价格/4.txt","a+");
				fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else if(h->Price>array[3]&&h->Price<=array[4])
			{
				fp=fopen("归类结果_价格/5.txt","a+");
				fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else if(h->Price>array[4])
			{
				fp=fopen("归类结果_价格/6.txt","a+");
				fprintf(fp,Format2,h->Number,h->Brand,h->Type,h->Platform,h->Name,h->Configure,h->Location,h->Price);
				fclose(fp);
			}
			else
			{
				printf("\n输入错误!\n");
			}
			h=h->Next;
		}
	}
	else
	{
		printf("\n输入错误，请重新输入:\n");
		classify();
	}
}


int arrange(void)
{
	extern int choice();
	int choose;
	sub_menu();
	scanf("%d",&choose);
	if(choose==1)
	sort();
	else if(choose==2)
	classify();
	else if(choose==3)
	{
		getchar();
		printf("\t按任意键继续....\n");
		choice();
	}
	else
	{
		printf("\n(*_*)输入错误,请重新输入:\n");
		arrange();
	}
 }


int analyse(void)
{
	COMPUTER *q=(COMPUTER*)malloc(sizeof(COMPUTER)),*p=NULL,*m;
	int a,b=0;
	int c,d;
	float ave,sum=0;
	m=p=q;
	p->Next=NULL;
	 
	printf("\n请选择分析类型：\n");
	printf("\t**1.编号-配置\n");
	printf("\t**2.型号-配置\n");
	printf("\t**3.返回上级菜单\n");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
			{   
			    fp=fopen("数据分析/编号-配置.doc","r");
				while(feof(fp)==0)
				{
					fscanf(fp,Format1,p->Number,&p->Brand,&p->Type,&p->Platform,p->Name,p->Configure,&p->Location,&p->Price);
				    p->Next=(COMPUTER*)malloc(sizeof(COMPUTER));
				    m=p;
				    p=p->Next;
				}
				free(p);
				m->Next=NULL;
				
				m=q;
				while(m!=NULL)
				{
					b++;
					sum=sum+m->Price;
					m=m->Next;
				}
				ave=sum/b;
				
				float index[b];
				m=q;
				b=0;
				while(m!=NULL)
				{
					index[b]=((float)m->Price)/ave*100;
					b++;
					m=m->Next;
				}
				
				printf("\n****当前配置：%s\n",q->Configure);
				printf("\n****该配置下的计算机共 %d 款记录在册.\n",b);
				printf("\n****该配置计算机平均价格：%.2f\n",ave);
				m=q;b=0;
				printf("\n\t序号\t品牌\t\t型号\t       价格\t价位比\n");
				while(m!=NULL)
				{
					printf("\n\t%d.",b+1);
    	            reflection_brand(m->Brand);
    	            printf("\t");
    	            printf("%s",m->Name);
    	            c=sizeof(m->Name);
    	            d=strlen(m->Name);
    	            blank(c,d);
    	            printf("\t");
    	            printf("%d\t",m->Price );
    	            printf("%.1f%%\n",index[b]);
    	            b++;
    	            m=m->Next;
				}
				break;
			}
		case 2:
			{
				fp=fopen("数据分析/型号-配置.doc","r");
				while(feof(fp)==0)
				{
					fscanf(fp,Format1,p->Number,&p->Brand,&p->Type,&p->Platform,p->Name,p->Configure,&p->Location,&p->Price);
				    p->Next=(COMPUTER*)malloc(sizeof(COMPUTER));
				    m=p;
				    p=p->Next;
				}
				free(p);
				m->Next=NULL;
				
				m=q;
				while(m!=NULL)
				{
					b++;
					sum=sum+m->Price;
					m=m->Next;
				}
				ave=sum/b;
				
				float index[b];
				m=q;
				b=0;
				while(m!=NULL)
				{
					index[b]=((float)m->Price)/ave*100;
					b++;
					m=m->Next;
				}
				
				printf("\n****当前配置：%s\n",q->Configure);
				printf("\n****该配置下的计算机共 %d 款记录在册.\n",b);
				printf("\n****该配置计算机平均价格：%.2f\n",ave);
				m=q;b=0;
				printf("\n\t序号\t品牌\t\t型号\t       价格\t价位比\n");
				while(m!=NULL)
				{
					printf("\n\t%d.\t",b+1);
    	            reflection_brand(m->Brand);
    	            printf("\t");
    	            printf("%s",m->Name);
    	            c=sizeof(m->Name);
    	            d=strlen(m->Name);
    	            blank(c,d);
    	            printf("%d\t",m->Price );
    	            printf("%.1f%%\n",index[b]);
    	            b++;
    	            m=m->Next;
				}
				break;
			}
		case 3:
			{
				free(q);
				p=q=m=NULL;
				break;
			}
		default:printf("\n输入错误，请重新输入...\n");
		        analyse();
	}
}  
 
 
 
 int dig(void)
 {
 	extern int choice();
 	COMPUTER *p,*q;
 	int a,b,k=0;
 	p=q=Head;
 	
 	printf("\n请选择: 1.编号 2.型号\n");
 	scanf("%d",&a);
 	fflush(stdin);
 	printf("\n请选择功能: 1.相同价位的其他产品 2.相同配置的其他产品\n");
 	scanf("%d",&b);
 	fflush(stdin);
 	if(a==1&&b==1)
 	{
 		char array[20];
 		printf("\n请输入编号:\n");
 		gets(array);
 		fflush(stdin);
 		while(p!=NULL)
 		{
 			if(strcmp(p->Number,array)==0)
 			{
 				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
 				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
    	        printf("\n");
    	        
    	        fp=fopen("数据分析/编号-价位.doc","a+");
    	        fprintf(fp,Format2,p->Number,p->Brand,p->Type,p->Platform,p->Name,p->Configure,p->Location,p->Price);
    	        fclose(fp);
    	        
    	        break;
			}
			p=p->Next;
		}
		if(p==NULL)
		{
			printf("\n没有该项记录,即将返回主界面\n");
			Sleep(2000);
			choice();
		}
		while(q!=NULL)
 		{
 			if(strcmp(q->Number,p->Number)!=0&&q->Price>=p->Price-400&&q->Price<=p->Price+400)
 			{
 				k=1;
 				printf("\n%s\t",q->Number);
    	        reflection_brand(q->Brand);
    	        printf("\t");
    	        reflection_type(q->Type);
    	        printf("\t\t");
    	        reflection_platform(q->Platform);
    	        printf("\t\t");
    	        printf("%s",q->Name);
    	        a=sizeof(q->Name);
    	        b=strlen(q->Name);
    	        blank(a,b);
		        printf("%s",q->Configure);
		        a=sizeof(q->Configure);
    	        b=strlen(q->Configure);
    	        blank(a,b);
    	        reflection_location(q->Location);
    	        printf("\t");
    	        printf("%d\n",q->Price );
    	        
    	        fp=fopen("数据分析/编号-价位.doc","a");
    	        fprintf(fp,Format2,q->Number,q->Brand,q->Type,q->Platform,q->Name,q->Configure,q->Location,q->Price);
    	        fclose(fp);
			}
			q=q->Next;
		}
		if(q==NULL&&k==0)
		printf("\n没有找到符合条件的记录...\n");
		printf("\n按任意键继续...\n");
		char ch=getchar();
	}
	else if(a==1&&b==2)
	{
		char array[20];
 		printf("\n请输入编号:\n");
 		gets(array);
 		fflush(stdin);
 		while(p!=NULL)
 		{
 			if(strcmp(p->Number,array)==0)
 			{
 				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
 				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
    	        printf("\n");
    	        
    	        fp=fopen("数据分析/编号-配置.doc","a+");
    	        fprintf(fp,Format2,p->Number,p->Brand,p->Type,p->Platform,p->Name,p->Configure,p->Location,p->Price);
    	        fclose(fp);
    	        
    	        break;
			}
			p=p->Next;
		}
		if(p==NULL)
		{
			printf("\n没有该项记录,即将返回主界面\n");
			Sleep(2000);
			choice();
		}
		while(q!=NULL)
 		{
 			if(strcmp(q->Number,p->Number)!=0&&strcmp(q->Configure,p->Configure)==0)
 			{
 				k=1;
 				printf("\n%s\t",q->Number);
    	        reflection_brand(q->Brand);
    	        printf("\t");
    	        reflection_type(q->Type);
    	        printf("\t\t");
    	        reflection_platform(q->Platform);
    	        printf("\t\t");
    	        printf("%s",q->Name);
    	        a=sizeof(q->Name);
    	        b=strlen(q->Name);
    	        blank(a,b);
		        printf("%s",q->Configure);
		        a=sizeof(q->Configure);
    	        b=strlen(q->Configure);
    	        blank(a,b);
    	        reflection_location(q->Location);
    	        printf("\t");
    	        printf("%d\n",q->Price );
    	        
    	        fp=fopen("数据分析/编号-配置.doc","a");
    	        fprintf(fp,Format2,q->Number,q->Brand,q->Type,q->Platform,q->Name,q->Configure,q->Location,q->Price);
    	        fclose(fp);
			}
			q=q->Next;
		}
		if(q==NULL&&k==0)
		printf("\n没有找到符合条件的记录...\n");
		printf("\n按任意键继续...\n");
		char ch=getchar();
	}
	else if(a==2&&b==1)
	{
		char array[15];
 		printf("\n请输入型号:\n");
 		gets(array);
 		fflush(stdin);
 		while(p!=NULL)
 		{
 			if(strcmp(p->Name,array)==0)
 			{
 				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
 				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
    	        printf("\n");
    	        
    	        fp=fopen("数据分析/型号-价位.doc","a+");
    	        fprintf(fp,Format2,p->Number,p->Brand,p->Type,p->Platform,p->Name,p->Configure,p->Location,p->Price);
    	        fclose(fp);
    	        
    	        break;
			}
			p=p->Next;
		}
		if(p==NULL)
		{
			printf("\n没有该项记录,即将返回主界面\n");
			Sleep(2000);
			choice();
		}
		while(q!=NULL)
 		{
 			if(strcmp(q->Name,p->Name)!=0&&q->Price>=p->Price-400&&q->Price<=p->Price+400)
 			{
 				k=1;
 				printf("\n%s\t",q->Number);
    	        reflection_brand(q->Brand);
    	        printf("\t");
    	        reflection_type(q->Type);
    	        printf("\t\t");
    	        reflection_platform(q->Platform);
    	        printf("\t\t");
    	        printf("%s",q->Name);
    	        a=sizeof(q->Name);
    	        b=strlen(q->Name);
    	        blank(a,b);
		        printf("%s",q->Configure);
		        a=sizeof(q->Configure);
    	        b=strlen(q->Configure);
    	        blank(a,b);
    	        reflection_location(q->Location);
    	        printf("\t");
    	        printf("%d\n",q->Price );
    	        
    	        fp=fopen("数据分析/型号-价位.doc","a");
    	        fprintf(fp,Format2,q->Number,q->Brand,q->Type,q->Platform,q->Name,q->Configure,q->Location,q->Price);
    	        fclose(fp);
			}
			q=q->Next;
		}
		if(q==NULL&&k==0)
		printf("\n没有找到符合条件的记录...\n");
		printf("\n按任意键继续...\n");
		char ch=getchar();
	}
	else if(a==2&&b==2)
	{
		char array[15];
 		printf("\n请输入型号:\n");
 		gets(array);
 		fflush(stdin);
 		while(p!=NULL)
 		{
 			if(strcmp(p->Name,array)==0)
 			{
 				printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
 				printf("\n%s\t",p->Number);
    	        reflection_brand(p->Brand);
    	        printf("\t");
    	        reflection_type(p->Type);
    	        printf("\t\t");
    	        reflection_platform(p->Platform);
    	        printf("\t\t");
    	        printf("%s",p->Name);
    	        a=sizeof(p->Name);
    	        b=strlen(p->Name);
    	        blank(a,b);
		        printf("%s",p->Configure);
		        a=sizeof(p->Configure);
    	        b=strlen(p->Configure);
    	        blank(a,b);
    	        reflection_location(p->Location);
    	        printf("\t");
    	        printf("%d\n",p->Price );
    	        printf("\n");
    	        
    	        fp=fopen("数据分析/型号-配置.doc","a+");
    	        fprintf(fp,Format2,p->Number,p->Brand,p->Type,p->Platform,p->Name,p->Configure,p->Location,p->Price);
    	        fclose(fp);
    	        
    	        break;
			}
			p=p->Next;
		}
		if(p==NULL)
		{
			printf("\n没有该项记录,即将返回主界面\n");
			Sleep(2000);
			choice();
		}
		while(q!=NULL)
 		{
 			if(strcmp(q->Name,p->Name)!=0&&strcmp(q->Configure,p->Configure)==0)
 			{
 				k=1;
 				printf("\n%s\t",q->Number);
    	        reflection_brand(q->Brand);
    	        printf("\t");
    	        reflection_type(q->Type);
    	        printf("\t\t");
    	        reflection_platform(q->Platform);
    	        printf("\t\t");
    	        printf("%s",q->Name);
    	        a=sizeof(q->Name);
    	        b=strlen(q->Name);
    	        blank(a,b);
		        printf("%s",q->Configure);
		        a=sizeof(q->Configure);
    	        b=strlen(q->Configure);
    	        blank(a,b);
    	        reflection_location(q->Location);
    	        printf("\t");
    	        printf("%d\n",q->Price );
    	        
    	        fp=fopen("数据分析/型号-配置.doc","a");
    	        fprintf(fp,Format2,q->Number,q->Brand,q->Type,q->Platform,q->Name,q->Configure,q->Location,q->Price);
    	        fclose(fp);
			}
			q=q->Next;
		}
		if(q==NULL&&k==0)
		printf("\n没有找到符合条件的记录...\n");
		printf("\n按任意键继续...\n");
		char ch=getchar();
	}
	else
	{
		printf("\n输入错误,请重新输入....\n");
		dig();
	}
	
	printf("\n相关信息已发送到源程序文件夹下的目录《数据分析》中，注意查看.\n\n"); 
 }


int output(void)
{
	extern int choice();
    char array[50],fh;
	COMPUTER *p=Head;
	
	printf("\n");
	char aa[20]="(>.<)友情提示:";
	for(int i=0;aa[i]!='\0';i++)
	{
		printf("%c",aa[i]);
		Sleep(50);
	}
	printf("\n\n");
	char bb[100]="您最好先对数据进行整理后在进行文件输出,以获得美观的信息";
	for(int i=0;bb[i]!='\0';i++)
	{
		printf("%c",bb[i]);
		Sleep(50);
	}
	printf("\n");
	Sleep(2000);
	printf("\n\t按任意键继续....\n");
	getchar();
	printf("\n您确定已经完成了信息整理?  Y/N \n");
qwe:fh=getchar();
	fflush(stdin);
	if(fh=='N'||fh=='n')
	choice();
	else if(fh=='Y'||fh=='y');
	else
	{
		printf("\n(*_*)输入错误，请重新输入:\n");
		goto qwe;
	}
	
	
def:printf("\n请输入具体文件输出路径:\n");
	gets(array);
	fp=fopen(array,"w");
	if(fp==NULL)
	{
		printf("\n路径无效，请确定路径是否正确并重新输入:\n");
		goto def;
	}
	while(p!=NULL)
	{
		fprintf(fp,Format2,p->Number,p->Brand,p->Type,p->Platform,p->Name,p->Configure,p->Location,p->Price);
		p=p->Next; 
	}
	fclose(fp);
}


int clean(void)
{
	system("cls");
	printf("\n按任意键继续...\n");
	getchar(); 
}


int initialize(void)
{
	fflush(stdin);
	extern int choice();
	extern int end();
	printf("\n\t!!!警告!!!\n");
	printf("\n您将失去本程序目录下所有的记录数据,并且程序将初始化为最初的状态!!!\n");
	printf("确定继续?! Y/N \n");
	char ch;
	ch=getchar();
	if(ch=='N'||ch=='n')
	choice();
	else if(ch=='Y'||ch=='y')
	{
		fp=fopen("历史使用记录.dat","wb");
		fputc('n',fp);
		fclose(fp);
		remove("记录信息.txt");
		fp=fopen("记录信息.txt","w");
		fclose(fp);
		remove("用户信息.txt");
		fp=fopen("用户信息.txt","w");
		fclose(fp);
		printf("即将退出程序以完成初始化....\n");
		for(int i=1;i<=55;i++)
		{
			printf("> ");
			Sleep(80);
		}
		end();
	}
	else
	{
		printf("\n输入错误,请重新输入....\n");
		initialize();
	}
}


int watch(void)
{
	char index[40];
	printf("\n请输入文件路径：\n");
	gets(index);
	fflush(stdin);
	
	COMPUTER *A,*B;
	COMPUTER *first=(COMPUTER*)malloc(sizeof(COMPUTER));
	A=B=first;
 	A->Next=NULL;
    fp=fopen(index,"r");
    if(fp==NULL)
	{
		printf("\n\t程序出错(*_*),即将关闭...\n");
		free(first);
		A=B=NULL;
		Sleep(3000);
		exit(0);
	}
	if(feof(fp)==0)
	{
		fscanf(fp,Format1,A->Number,&A->Brand,&A->Type,&A->Platform,A->Name,A->Configure,&A->Location,&A->Price);
        while(feof(fp)==0)
        {
	        B->Next=(COMPUTER*)malloc(sizeof(COMPUTER));
    	    B=B->Next;
    	    fscanf(fp,Format1,B->Number,&B->Brand,&B->Type,&B->Platform,B->Name,B->Configure,&B->Location,&B->Price);
    	    B->Next=NULL;
	    }
        fclose(fp);
	}
	else
	{
		fclose(fp);
		free(first);
		A=B=NULL;
	}
	
	COMPUTER *p;
    p=A;
    int a,b;
    printf("\n编号\t品牌\t\t类型\t\t\t架构\t\t型号\t       配置\t\t\t\t\t\t\t\t\t定位\t\t价格\n");
    while(p!=NULL)
    {
    	printf("\n%s\t",p->Number);
    	reflection_brand(p->Brand);
    	printf("\t");
    	reflection_type(p->Type);
    	printf("\t\t");
    	reflection_platform(p->Platform);
    	printf("\t\t");
    	printf("%s",p->Name);
    	a=sizeof(p->Name);
    	b=strlen(p->Name);
    	blank(a,b);
		printf("%s",p->Configure);
		a=sizeof(p->Configure);
    	b=strlen(p->Configure);
    	blank(a,b);
    	reflection_location(p->Location);
    	printf("\t");
    	printf("%d\n",p->Price ); 
    	p=p->Next;
	}
}


int end(void)
{
	COMPUTER *p;
	p=Head;
	while(Head!=NULL)
	{
		Head=Head->Next;
		free(p);
		p=Head;
	}
	printf("\n\n(>,<)GoodBye!\n");
	exit(0);
}


int choice(void)
{
	int choose;
	main_menu();
	scanf("%d",&choose);
	fflush(stdin); 
	switch(choose)
	{
		case 1:create();choice();
		case 2:show();choice();
		case 3:seek();choice();
		case 4:insert();choice();
		case 5:change();choice();
		case 6:del();choice();
		case 7:arrange();choice();
		case 8:dig();choice();
		case 9:analyse();choice();
		case 10:output();choice();
		case 11:clean();choice();
		case 12:initialize();choice();
		case 13:watch();choice();
		case 14:end();
		default:printf("\n(*_*)输入错误,请重新输入....\n");
		        choice();
	}
	printf("\t");
	char a[20]="按任意键继续";
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
		Sleep(50);
	}
	printf("\n");
    choice();
}


int get_ready(void) 
{
	char ch,sh;
	
	fp=fopen("历史使用记录.dat","rb");
    if(fp==NULL)
    	printf("文件不存在！\n");
    
    ch=fgetc(fp);
    printf("\n\n");
    if(ch=='n')
    {
    	char z[40]="正在为您第一次使用本系统做准备....";
    	for(int i=0;z[i]!='\0';i++)
    	{
    		printf("%c",z[i]);
    		Sleep(30);
		}
	}
	printf("\n");
	fclose(fp);
	printf("\n");
	
	
	COMPUTER *first=(COMPUTER*)malloc(sizeof(COMPUTER));
 	End=Head=first;
 	Head->Next=NULL;
    fp=fopen("记录信息.txt","r");
    if(fp==NULL)
	{
		printf("\n\t程序出错(*_*),即将关闭...\n");
		free(first);
		Head=End=NULL;
		Sleep(3000);
		end();
	}
	if(feof(fp)==0)
	{
		fscanf(fp,Format1,Head->Number,&Head->Brand,&Head->Type,&Head->Platform,Head->Name,Head->Configure,&Head->Location,&Head->Price);
        while(feof(fp)==0)
        {
	        End->Next=(COMPUTER*)malloc(sizeof(COMPUTER));
    	    End=End->Next;
    	    fscanf(fp,Format1,End->Number,&End->Brand,&End->Type,&End->Platform,End->Name,End->Configure,&End->Location,&End->Price);
    	    End->Next=NULL;
	    }
        fclose(fp);
	}
	else
	{
		fclose(fp);
		free(first);
		Head=End=NULL;
	}
	
	
	for(int i=57;i>=1;i--)	
	{
		printf("> ");
	  	Sleep(65);
	}
	Sleep(1500);
	printf("\n\n");
	char a[20]="100% is ready....";
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
		Sleep(50);
	}
	printf("\n");
	Sleep(1000);
	printf("\n");
	char b[20]="程序加载完毕!";
	for(int i=0;b[i]!='\0';i++)
	{
		printf("%c",b[i]);
		Sleep(50);
	}
	printf("\n");
	Sleep(1000);
	printf("\n");
	char c[20]="开始使用?";
	for(int i=0;c[i]!='\0';i++)
	{
		printf("%c",c[i]);
		Sleep(50);
	}
	Sleep(900);
	printf("     Y/N\n");
abc:sh=getchar();
    getchar();
	if(sh=='Y'||sh=='y');
	else if(sh=='N'||sh=='n')
	end();
	else
	{
		printf("输入错误,请重新输入....\n");
		goto abc;
	}
	
	fp=fopen("历史使用记录.dat","rb");
    if(fp==NULL)
    	printf("文件不存在！\n");
    
    ch=fgetc(fp);
    printf("\n\n");
    if(ch=='y')
    { 
	    char User_Name[20];
	    char user_name[20];
	    char User_PassWord[10];
	    char user_password[10];
	    
	    fp=fopen("用户信息.txt","r");
	    fscanf(fp,"%s %s",user_name,user_password);
	    
    zzz:printf("\n请输入用户名：\n");
	    gets(User_Name);
	    printf("\n按任意键确定....\n");
	    getchar();
	    if(strcmp(User_Name,user_name)!=0)
	    {
	      	printf("\n用户名不正确！\n");
	        fclose(fp);
	        goto zzz;
	    } 
    xxx:printf("\n请输入密码：\n");
	    gets(User_PassWord);
	    printf("\n按任意键确定....\n");
	    getchar();
	    for(int i=0;i<strlen(User_PassWord);i++)
		    User_PassWord[i]=User_PassWord[i]+i;

	    if(strcmp(User_PassWord,user_password)==0&&strcmp(User_Name,user_name)==0)
	   	    fclose(fp);
	    else if(strcmp(User_PassWord,user_password)!=0)
	    {
	   	    printf("\n密码错误!\n");
	   	    fclose(fp);
		    goto xxx;
	    }
    }
}


int first_use(void)
{
	char kh;
	fp=fopen("历史使用记录.dat","rb");
    if(fp==NULL)
    	printf("\n\t文件不存在！\n");
    
    kh=fgetc(fp);
    printf("\n");
    if(kh=='y')
    {
	    fclose(fp);
    	return 0;
	}
	fclose(fp);
	printf("\n\t");
	char aa[20]="第一次使用....";
	for(int i=0;aa[i]!='\0';i++)
	{
		printf("%c",aa[i]);
		Sleep(50);
	}
	printf("\n\n");
	
	char User_Name[20];
	char User_PassWord[10];
	printf("\n注册用户：\n");
	printf("\n输入用户名(少于20位英文或10位中文)：\n");
	gets(User_Name);
	printf("\n按任意键确定....\n");
	getchar();
	printf("\n输入密码(少于10位英文或数字)：\n");
	gets(User_PassWord);
	printf("\n按任意键确定....\n");
	getchar();
	for(int i=0;i<strlen(User_PassWord);i++)
		User_PassWord[i]=User_PassWord[i]+i;
	
	fp=fopen("用户信息.txt","a+");
	fprintf(fp,"%s %s",User_Name,User_PassWord);
	fclose(fp);
	
	fp=fopen("记录信息.txt","w");
	COMPUTER *first=(COMPUTER*)malloc(sizeof(COMPUTER));
 	Head=End=first;
 	Head->Next=NULL;
 	
	int input;
	
	printf("\n");
	char a[20]="请输入编号:";
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
		Sleep(50);
	}
	printf("\n");
    gets(Head->Number);
	
	printf("\n");
	char b[20]="请选择计算机品牌:";
	for(int i=0;b[i]!='\0';i++)
	{
		printf("%c",b[i]);
		Sleep(50);
	}
	printf("\n");
 	menu_brand();
	scanf("%d",&input);
	Head->Brand=input;
	fflush(stdin);
	
	printf("\n");
	char c[20]="请选择计算机类型:";
	for(int i=0;c[i]!='\0';i++)
	{
		printf("%c",c[i]);
		Sleep(50);
	}
	printf("\n");
	menu_type();
	scanf("%d",&input);
	Head->Type=input;
	fflush(stdin);
	
	printf("\n");
	char d[20]="请选择架构:";
	for(int i=0;d[i]!='\0';i++)
	{
		printf("%c",d[i]);
		Sleep(50);
	}
	printf("\n");
    menu_platform();
    scanf("%d",&input);
	Head->Platform=input;
	fflush(stdin);
	
	printf("\n");
	char e[30]="请输入计算机具体型号:";
	for(int i=0;e[i]!='\0';i++)
	{
		printf("%c",e[i]);
		Sleep(50);
	}
	printf("\n");
	gets(Head->Name);
	
	printf("\n");
	char f[30]="请输入计算机具体配置:";
	for(int i=0;f[i]!='\0';i++)
	{
		printf("%c",f[i]);
		Sleep(50);
	}
	printf("\n");
	gets(Head->Configure);
	
	printf("\n");
	char g[20]="请选择当前配置水平:";
	for(int i=0;g[i]!='\0';i++)
	{
		printf("%c",g[i]);
		Sleep(50);
	}
	printf("\n");
	menu_location();
	scanf("%d",&input);
	Head->Location=input;
	fflush(stdin);
	
	printf("\n");
	char h[20]="请输入价格:";
	for(int i=0;h[i]!='\0';i++)
	{
		printf("%c",h[i]);
		Sleep(50);
	}
	printf("\n");
	scanf("%d",&input);
	Head->Price=input;
	fflush(stdin);
	
	fprintf(fp,Format2,Head->Number,Head->Brand,Head->Type,Head->Platform,Head->Name,Head->Configure,Head->Location,Head->Price);
	fclose(fp);
	
	fp=fopen("历史使用记录.dat","wb");
	fputc('y',fp);
	fclose(fp);
} 


int main(void)
{
	title();
	get_ready();
	first_use();
	choice();
}


