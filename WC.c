#include "stdio.h"
#include "stdlib.h"

int CharCount(FILE *fp)  //�����ļ����ַ��� 
{
char ch;  //����ch�����洢�ļ���ȡ�����ַ� 
int charCounts=0;

while((ch=fgetc(fp))!=EOF)
{

charCounts++;
}
return charCounts;  //�����ַ��� 
}
//count�����ַ�
int LineCount(FILE *fp) //�����ļ������� 
{
char ch;
int lineCounts=0;

while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')  //�������з��ķ�ʽ�����ļ��е����� 
lineCounts++;   
}

return lineCounts; //���з�����Ŀ��1Ϊ����
}//count���� 

int WordCount(FILE*fp){ //�����ļ��д��� 
	
	char ch;
	int wordCounts=0,pd=0;//pdΪ0ʱ��ʾ���Ǵʣ�pdΪ1ʱ��ʾ�Ǵ� 

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
	int counts,c;//cΪ���������������� 

	if((fp=fopen("D:\\test.c","r"))==0) { // D����test.cΪ�ó�������ļ� 
		printf("�ļ���ȡʧ�ܣ�\n");      
		exit(0);
	}
	
	
	printf("WC������: 1.-c   2.-w   3.-l  0.exit\n��ѡ����Ҫ���еĲ���:1 or 2 or 3 or 0\n�������: ");
	scanf("%d",&c);
	printf("\n");
	do{
	
	switch(c){
		case 1: counts=CharCount(fp);printf("�ļ��е��ַ���Ϊ%d��\n",counts);break;
		case 2: counts=WordCount(fp);printf("�ļ��еĴ���Ϊ%d��\n",counts);break;
		case 3: counts=LineCount(fp);printf("�ļ��е�����Ϊ%d��\n",counts);break;
			default:if(c==0)exit(0);printf("�����������������!\n�������: ");scanf("%d",&c);break;
	} 
}while(c!=1&&c!=2&&c!=3&&c!=0);
printf("\n\n");
	fclose(fp);}
}
