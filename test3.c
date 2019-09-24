#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int writeToarr (int a[])
{
	int i=0,n,j=0;
	FILE *fp;//定义文件指针
	if((fp=fopen("123.txt","r"))==NULL)//如果文件名不存在
	{
		printf("cantfind the file!");
	}//则输出没有找到文件
	while(!feof(fp))//当不为文件结尾时
	{
		fscanf(fp,"%d",&a[i++]);//逐个将文件中的数据放入数组中
	}
	printf("保存成功！\n");
	fclose(fp);//关闭文件
}
void writeToTxt(int a[])
{
	FILE *fp;
	int i,b[100];
	fp=fopen("123.txt","w");//打开文件以便写入数据
	for (i = 0; i < 100; i++) 
	{ //准备要写入文件的数组
		b[i]=a[i];
	}
	for (i = 0; i < 100; i++) 
	{ //将a数组中的整数写入fp指向的123.txt文件
		fprintf(fp,"%d\n",b[i]);
	}
	fclose(fp); //写入完毕，关闭文件
} 
void sort(int * a, int len) {//排序函数 
    if( len <= 1 ) return;
    int i=0, j=len-1, t, temp = a[0];
    while( i<j ) {
        while( a[j]>temp && j>i ) j--; a[i] = a[j];
        while( a[i]<=temp && i<j ) i++; a[j] = a[i];
    }
    a[i] = temp;
    sort(a, i);
    sort(a+i+1, len-i-1);
    return;
}
int main()
{
	int begintime,endtime;
	int i = 0;
	//up all for the timeline
	int h, a[100];
  	srand((unsigned int)time(NULL));//设置当前时间为种子
    for (i = 0; i < 100; ++i){
        a[i] = rand()%1000+1;//产生1~1000的随机数
    }
    writeToarr(a);//读取文件到数组a[]中 
    printf("排序前数据读入数组中成功！\n");
	begintime=clock();	//计时开始   	
	sort(a, 100);
    for(h=0; h<100; h++) {
        printf("%d   ", a[h]);
    }
    writeToTxt(a);
	printf("\n排序后数组写入文件成功!\n");
	endtime = clock();	//计时结束	
	printf("\n\nRunning Time：%dms\n", endtime-begintime);
	printf("计时结束！");
    return 0;
}

