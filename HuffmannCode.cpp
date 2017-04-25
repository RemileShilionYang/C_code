#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<String.h>
#define N 8
#define M 10

typedef struct huffmannList{
	char value;
	int weight;
}huffmannList;

typedef struct huffmannNode{
	char value;
	int weight;
	int pre;
	int left;
	int right;
	int flag;
}huffmannNode;

typedef struct ele{
	char value;
	char* code;
}ele;

huffmannList data[N];
huffmannNode tree[2*N];
static int index = N+2;
ele chara[N] = {NULL};

int init(void);
int create(void);
int print(void);
int coded(void);

int main(void){
	init();
	create();
	coded();
	print();
}

int init(void){
	for(int i=0;i<N;i++){
		printf("请输入字符及相应权值: ");
		scanf("%c%d",&data[i].value,&data[i].weight);
		fflush(stdin);
	}
	tree[0] = {'\0',65535,65535,65535,65535,65535};
	for(int i=1;i<=N;i++){
		tree[i].value = data[i-1].value;
		tree[i].weight = data[i-1].weight;
		tree[i].pre = 0;
		tree[i].left = 0;
		tree[i].right = 0;
		tree[i].flag = 0;
	}
	for(int i=N+1;i<2*N;i++){
		tree[i].value = '\0';
		tree[i].weight = 0;
		tree[i].pre = 0;
		tree[i].left = 0;
		tree[i].right = 0;
		tree[i].flag = 0;
	}
	return 0;
}

int create(void){
	int k,p,q;
	for(int i=N+1;i<2*N;i++){
	    k=1;p=0;q=0;
	    while(k<i){
		    if(tree[k].pre!=0) k++;
		    else{
		    	if(tree[p].weight>tree[k].weight){
		    		q=p;
		    		p=k;
				}
		        else if(tree[p].weight<=tree[k].weight&&tree[q].weight>tree[k].weight)
				    q=k;
		        k++;
			}
	    }
	    tree[i].weight = tree[p].weight+tree[q].weight;
	    tree[i].left = p;
	    tree[i].right = q;
	    tree[p].pre = i;
	    tree[q].pre = i;
	}
	return 0; 
}

int print(void){
	for(int i=0;i<N;i++){
		printf("%c:%s\n",chara[i].value,chara[i].code);
	}
	char input[M];
	gets(input);
	fflush(stdin);
	FILE* fp;
	fp=fopen("a.txt","w+");
	int i=0;
	while(input[i]!='\0'){
		for(int j=0;j<N;j++){
			if(input[i]==chara[j].value){
				printf("%s",chara[j].code);
				fprintf(fp,"%s\n",chara[j].code);
				break;
			}
		}
		i++;
	}
	fclose(fp);
	printf("\n");
	fp=fopen("a.txt","r");
	char a[10];
	int b=1;
	while(feof(fp)==0){
		fscanf(fp,"%s",a);
	    for(int j=0;j<N;j++){
		    if(strcmp(chara[j].code,a)==0)
		    {
		    	printf("%c",chara[j].value);b++;
		    	break;
			}
	    }
	}
	printf("\b ");
	fclose(fp);
	return 0;
}

int coded(void){
	int sum = 0;
	int lip = 0;
	int temp;
	for(int i=0;i<N;i++){
		sum = 0;
		chara[i].value = data[i].value;
		temp = i+1;
		while(tree[temp].pre != 0){
			temp = tree[temp].pre;
			sum++;
		}
		chara[i].code = (char*)malloc(sizeof(char)*(sum+1));
		chara[i].code[sum] = '\0';
		temp = i+1;
		lip = sum-1;
		while(tree[temp].pre != 0){
			if(tree[tree[temp].pre].left == temp){
				chara[i].code[lip] = '0';
				lip--;
			}
			else{
				chara[i].code[lip] = '1';
				lip--;
			}
			temp = tree[temp].pre;
		}
	}
	return 0;
}






