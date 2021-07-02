#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

/*前序遍历*/
void PreOrder(BiTree T)
{
	if(T==NULL)
		return;
	
	cout<<(T->data)<<' ';
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	
}
/*中序遍历*/
void InOrder(BiTree T)
{
	if(T==NULL)
		return;
	InOrder(T->lchild);
	cout<<(T->data)<<' ';
	InOrder(T->rchild);	
}
/*后序遍历*/
void PostOrder(BiTree T)
{
	if(T==NULL)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);	
	cout<<T->data<<' ';
}

 //先序建立二叉树

BiTree CreateBiTree()
{

    int ch;
    BiTree T;
    scanf("%d",&ch);
    if(ch==0)T=NULL;

    else{

        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }

    return T;//返回根节点
}

int main()
{
	BiTree T;
	T = CreateBiTree();
	cout<<"Create success"<<endl;
	PostOrder(T);
}