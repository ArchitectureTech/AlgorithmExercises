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
using namespace std;

class Matrix{//����һ�����ṹ�壬���㷵�ؾ������ 
	public://�����ҽ����Զ���Ϊpublic���ˣ�����ֱ�Ӳ��� 
		int m[2][2];
		int row;
		int col;
};

//����������� 
Matrix muliMatrix(Matrix m1,Matrix m2) 
{
	Matrix result;
	result.row=m1.row;
	result.col=m2.col;//��������������������������
	//�������е�ֵ��ʼ��Ϊ0 
	for(int i=0;i<result.row;++i)
		for(int j=0;j<result.col;++j)
			result.m[i][j]=0;
	//�����������		
	for(int i=0;i<m1.row;++i){//����m1���� 
		for(int j=0;j<m2.col;++j){//����m2���� 
			for(int k=0;k<m2.row;++k){//����m1���л���m2���� 
				result.m[i][j]+=m1.m[i][k]*m2.m[k][j];//��Ӧ������ 
			}
		}
	}
	return result;
}

Matrix matrixPower(Matrix base,int n)
{
	//��ʼ������Ϊһ����λ���� 
	Matrix result;
	result.col=base.col;
	result.row=base.row; 
	for(int i=0;i<result.row;++i)
		result.m[i][i]=1;
	//��ʼ���ݴ����Ϊ���ݹ���Ҫ�����base���� 
	Matrix tmp;
	tmp.row=base.row;
	tmp.col=base.col;
	for(int i=0;i<tmp.row;++i)
		for(int j=0;j<tmp.col;++j)
			tmp.m[i][j]=base.m[i][j];
			
	//����base��n�η���������洢��result��
	for(;n!=0;n >>= 1){//n��Ӧ�Ķ�����һֱ���ƣ�ֱ��Ϊ0 
		if(n&1)//n&1��Ϊ0����&��������1��Ϊ1����˵��n�Ķ��������Ϊ1 
			result=muliMatrix(result,tmp);//���Լ��������� 
		
		tmp=muliMatrix(tmp,tmp);//ͬʱtmp����ƽ����ÿ����1λ��tmp��ƽ�� 
	}
	return result;
}

int allRectCover(int n)
{
	if(n<1)
		return 0;
	if(n==1 || n==2)
		return n;
	//���þ���ĳ�ʼֵΪ{1,1,1,0} 
	Matrix base;
	base.row=2;
	base.col=2;
	base.m[0][0]=1;base.m[0][1]=1;base.m[1][0]=1;base.m[1][1]=0;
	
	Matrix result;
	result.row=2;
	result.col=2;
	
	result=matrixPower(base,n-2);//��base��n-2�η� 
	//���Ϊ��f(n),f(n-1)��=��f(2),f(1)��=(2,1)*base^(n-2) 
	return 2*result.m[0][0]+result.m[1][0];
}

int main()
{
	//���� 
	int n;
	cout<<"������n��ֵ"<<endl;
	cin>>n;
	//��� 
	cout<<"�ܸ��Ƿ�����Ϊ��"<<allRectCover(n)<<endl;
	return 0;
} 
