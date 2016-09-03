/*
���⣺һ��������1��2��3��̨�ף�����n��̨���ж������߷�

����ʽ��f(n)=f(n-1)+f(n-2)+f(n-3)
1����������n-1��������һ����һ�����ɣ�������f(n-1)���߷� 
2����������n-2��������һ�����������ɣ�������f(n-2)���߷� 
3����������n-3��������һ�����������ɣ�������f(n-3)���߷� 
������������ǲ����ã��������߷�Ϊ�����������֮��
Ϊʲô������n-4���������Ϊ���һ����3����n-4��1,2��3���ֱ��Ӧ��������������Ѿ����������� 

��̬�滮���˷���ʱ�临�Ӷ�O(n) 
*/
#include <iostream>
using namespace std;

//ʹ������������һλ 
int climbStairsWithDP1(int n)
{
	int result,i,a[n];
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(i=4;i<=n;++i){//�ӵ�4����ʼ���ݵ���ʽ���� 
		result=a[i-1]+a[i-2]+a[i-3];
		a[i]=result;
	}
	return result;
}
//ͨ����������������һλ 
int climbStairsWithDP2(int n)
{
	int result=4;
	int pre=2;
	int prepre=1;
	int temp1,temp2;
	for(int i=4;i<=n;++i){
		temp1=result;
		temp2=pre;
		result+=pre+prepre;
		pre=temp1;
		prepre=temp2;
	} 
	
	return result; 
} 

int main()
{
	//����
	int n;
	cout<<"������̨������"<<endl;
	cin>>n;
	
	//������
	cout<<"���е��߷���ʹ�����飩��"<<climbStairsWithDP1(n)<<endl; 
	cout<<"���е��߷���ʹ�ü�����������"<<climbStairsWithDP2(n)<<endl; 
	return 0;
}
