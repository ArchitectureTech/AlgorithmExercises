/*
���⣺���������ȡ��С�����ݹ���� 
*/ 
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Node{//���Ľṹ�嶨�� 
	int value;
	Node *left;
	Node *right;
}BiNode,*BiTree; //*BiTree��ʾָ��ṹ���ָ�룬BiNode��ʾ����ṹ�� 

//������� 
void preOrderRecursion(BiTree root){
	if(root){
		printf("%d ",root->value);
		preOrderRecursion(root->left);
		preOrderRecursion(root->right);
	}
}

//�������
void inOrderRecursion(BiTree root)
{
	if(root){
		inOrderRecursion(root->left);
		printf("%d ",root->value);
		inOrderRecursion(root->right);
	}
}
//��������
void posOrderRecursion(BiTree root)
{
	if(root){
		posOrderRecursion(root->left);
		posOrderRecursion(root->right);
		printf("%d ",root->value);
	}
} 

/*
		1
	  .	  .
	2		3
  .   .	   
4      5	     
 .    . 
  6  8 	
*/
int i=-1;
//����ݹ齨������������������ͼ 
void createBiTree(BiTree *root)//*ȡ�� 
{
	int a[]={1,2,4,0,6,0,0,5,7,0,0,0,3,0,0};
	++i;
	if(a[i]==0)//Ϊ����ǰ�ڵ�Ϊ�� 
		*root=NULL;
	else{
		*root =(BiNode *)malloc(sizeof(BiNode)); //����һ���ڵ� 
		if(!(*root))//û���뵽�ͷ��� 
			return; 
		(*root)->value=a[i];//����ֵ 
		createBiTree(&(*root)->left);//�ݹ� 
		createBiTree(&(*root)->right);
	}
} 


int main()
{
	BiTree root;
	createBiTree(&root);//&ȡ��ַ 
	printf("������������");
	preOrderRecursion(root);
	printf("\n������������");
	inOrderRecursion(root); 
	printf("\n������������");
	posOrderRecursion(root); 
	return 0;
} 
