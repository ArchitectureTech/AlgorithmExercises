/*
���⣺����n�����������������С��k�� 

һ��ⷨ������O(nlogn)����ά������Ϊk�����飨O(n*k)������ά��һ��k��Ԫ�صĶѣ�O(n*logk)�� 

�������BFPRT�㷨���

 
*/
#include <iostream>
using namespace std;

void quickSelect(int *a,int k,int low,int high)
{
	int i,j,pivot;
	
	if(lw)
}

int main()
{
	//���� 
	int *a,n=0,data,k;
	cout<<"���������ݣ���-1��β����"<<endl; 
	while(cin>>data && data!=-1){
		a[n++]=data;
	} 
	cout<<"������Kֵ��"<<endl;
	cin>>k;
	
	//������
	cout<<"��С��"<<k<<"�����ֱ�Ϊ��";
	quickSelect(a,k,0,n-1); 
	
	return 0;
}
