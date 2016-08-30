/*
���⣺תȦ��ӡ����

1����topRow,topCol����¼���Ͻ�Ԫ��λ�ã���downRow,downCol����¼���½�Ԫ��λ��
2��ÿ�δ�ӡһȦ�� topRow++,topCol++�� downRow--,downCol--
3���������Ͻ������ܵ����½��������棬���ӡ��� 
*/ 
#include <iostream>
using namespace std;

//��ӡ�Ӿ����һȦ 
void printCircle(int a[][4],int topRow,int topCol,int downRow,int downCol)
{
	if(topRow==downRow)
		for(int i=topCol;i<=downCol;++i)
			cout<<a[topRow][i]<<" ";
	else if(topCol==downCol)
		for(int i=topRow;i<=downRow;++i)
			cout<<a[i][topCol]<<" ";
	else{
		int curCol=topCol;
		int curRow=topRow;
		while(curCol!=downCol)
			cout<<a[topRow][curCol++]<<" ";
		while(curRow!=downRow)
			cout<<a[curRow++][downCol]<<" "; 
		while(curCol!=topCol)
			cout<<a[downRow][curCol--]<<" "; 
		while(curRow!=topRow)
			cout<<a[curRow--][topCol]<<" "; 
	}
}
//������ 
void spiralOrderPrint(int a[][4],int rowCount,int colCount)
{
	int topRow=0;
	int topCol=0;
	int downRow=rowCount-1;
	int downCol=colCount-1;
	while(topRow<=downRow && topCol<=downCol)
		printCircle(a,topRow++,topCol++,downRow--,downCol--);
}

int main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	cout<<"����Ϊ��"<<endl;
	int rowCount=sizeof(a)/sizeof(a[0]);//������ 
	int colCount=sizeof(a[0])/sizeof(int);//������ 
	//��ʾ���� 
	for(int i=0;i<rowCount;++i){
		for(int j=0;j<colCount;++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	} 
	//������
	cout<<"���Ϊ��"<<endl;
	spiralOrderPrint(a,rowCount,colCount);
	 
	return 0;
}
