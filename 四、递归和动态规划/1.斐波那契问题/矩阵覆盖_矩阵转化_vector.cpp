/*
���⣺��n��2*1��С���κ��Ż����Ÿ���2*n�Ĵ���Σ����ж����ַ�����

1�����ǵ�Ϊn-1ʱ�����ŷ�һ�����ɣ�Ϊf(n-1)��
2����Ϊn-2ʱ��Ϊ��n-1���ظ������Ժ��ŷ��������ɣ�Ϊf(n-2)�֣�
3������f(n)=f(n-1)+f(n-2)

Ϊʲôn-3�������ƣ���Ϊn-3ʱ�ٷ�1����2���ͺ�n-2��n-1�ظ��� 

����ת���� 
�f(n),f(n-1)��=(f(n-1),f(n-2))*|a b| 
								  |c d|	�����ݳ�ʼֵ�������abcd����
�������տ��Եõ� (f(n),f(n-1))=	(f(2),f(1))*|a b|^(n-2)
								  			|c d|	
�������n�η����������O(logn)ʱ�临�Ӷȵõ� 
��f(1)=1,f(2)=2,f(3)=3,f(4)=5������Լ�������� 
*/
#include <iostream>
#include <vector>
using namespace std;

//����������� 
vector<vector<int> > muliMatrix(vector<vector<int> > m1,vector<vector<int> > m2)
{
	vector<vector<int> > result(m1.size());//����һ���������Ķ�ά���� 
	int res; //���ڴ洢m1��ÿһ�г���m2��ÿһ�еĽ�������ŵ�result�� 
	
	for(int i=0;i<m1.size();++i)
		for(int j=0;j<m2[0].size();++j){
			res=0;//ÿ�γ���Ϊ0 
			for(int k=0;k<m2.size();++k)
				res+=m1[i][k]*m2[k][j];//������ 
			result[i].push_back(res);//���� 
		}
	
	return result;
}
//�����n�η� 
vector<vector<int> > matrixPower(vector<vector<int> > base,int n)
{
	vector<vector<int> > result(base.size());//����һ���������Ķ�ά���� 
	for(int i=0;i<base.size();++i)//��ʼΪ��λ���� {1,0,0,1} 
		for(int j=0;j<base.size();++j){
			if(i==j)
				result[i].push_back(1);
			else
				result[i].push_back(0);
		}	
	
	vector<vector<int> > tmp(base.size());//����һ����ʱ��ά���� 
	for(int i=0;i<base.size();++i)//��base�����Ŀ��������� 
		for(int j=0;j<base.size();++j){
			tmp[i].push_back(base[i][j]);
		}	
	
	for(;n!=0;n>>=1){//n��Ӧ�Ķ�����һֱ���ƣ�ֱ��Ϊ0
		if(n&1)//n&1��Ϊ0����&��������1��Ϊ1����˵��n�Ķ��������Ϊ1
			result=muliMatrix(result,tmp);//���Լ��������� 
		tmp=muliMatrix(tmp,tmp);//ͬʱtmp����ƽ����ÿ����1λ��tmp��ƽ�� 
	}

	return result;
}
//������ 
int allRectCover(int n)
{
	if(n<1)
		return 0;
	if(n==1 || n==2)
		return n;
	
	vector<vector<int> > result(2);//����result�Ķ�ά������ÿһά��СΪ2 ��ע��vector��������`> >`֮��Ҫ�пո� 
	vector<vector<int> > base(2);

	base[0].push_back(1);//��ʼ��base�����ֵΪ{1,1,1,0} 
	base[0].push_back(1);
	base[1].push_back(1);
	base[1].push_back(0);

	result=matrixPower(base,n-2);//��base��n-2�η� 

	return 2*result[0][0]+result[1][0];	//������ 
}

int main()
{
	//����
	cout<<"������n��ֵ"<<endl;
	int n;
	cin>>n;
	
	cout<<"�ܷ�����Ϊ��"<<allRectCover(n)<<endl; 
	
	return 0;
}
