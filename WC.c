#include "stdio.h"
#include "stdlib.h"

int CharCount(FILE *fp)  //计算文件中字符数 
{
char ch;  //变量ch用来存储文件中取出的字符 
int charCounts=0;

while((ch=fgetc(fp))!=EOF)
{

charCounts++;
}
return charCounts;  //返回字符数 
}
//count所有字符
int LineCount(FILE *fp) //计算文件中行数 
{
char ch;
int lineCounts=0;

while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')  //用数换行符的方式计算文件中的行数 
lineCounts++;   
}

return lineCounts; //换行符的数目加1为行数
}//count行数 

int WordCount(FILE*fp){ //计算文件中词数 
	
	char ch;
	int wordCounts=0,pd=0;//pd为0时表示不是词，pd为1时表示是词 

	while((ch=fgetc(fp))!=EOF) {
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) {
			if(pd==0)pd=1;
		} else {
			if(pd==1) {
				wordCounts++;
				pd=0;
			}
		}
	}



	return wordCounts;
}

void main() {
while(1){	FILE *fp;
	int counts,c;//c为控制命令的输入变量 

	if((fp=fopen("D:\\test.c","r"))==0) { // D盘下test.c为该程序测试文件 
		printf("文件读取失败！\n");      
		exit(0);
	}
	
	
	printf("WC程序功能: 1.-c   2.-w   3.-l  0.exit\n请选择您要进行的操作:1 or 2 or 3 or 0\n操作序号: ");
	scanf("%d",&c);
	printf("\n");
	do{
	
	switch(c){
		case 1: counts=CharCount(fp);printf("文件中的字符数为%d。\n",counts);break;
		case 2: counts=WordCount(fp);printf("文件中的词数为%d。\n",counts);break;
		case 3: counts=LineCount(fp);printf("文件中的行数为%d。\n",counts);break;
			default:if(c==0)exit(0);printf("输入错误，请重新输入!\n操作序号: ");scanf("%d",&c);break;
	} 
}while(c!=1&&c!=2&&c!=3&&c!=0);
printf("\n\n");
	fclose(fp);}
}
