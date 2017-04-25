#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define N 256
#define src "HuffmannCode.cpp"
#define bin "HuffmannDecode.doc"

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
int codeTxt(void);
int coded(void);

int main(void){
	init();
	create();
	coded();
	codeTxt();
}

int codeTxt(void){
	FILE *fp=NULL;
	FILE *tp=NULL;
	fp = fopen(src,"r");
	tp = fopen(bin,"w+");
	char s;
	while(feof(fp)==0){
		s=fgetc(fp);
		for(int i=0;i<N;i++)
			if(s==chara[i].value) fprintf(tp,"%s",chara[i].code);
	}
	fclose(tp);
	fclose(fp);
	printf("编码完成!\n");
}

int init(void){
	for(int i=0;i<N;i++){
		data[i].value = i;
		data[i].weight = i+1;
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






