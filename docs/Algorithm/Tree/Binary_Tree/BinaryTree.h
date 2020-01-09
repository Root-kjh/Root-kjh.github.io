#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define TRUE 1
#define FALSE 0


typedef int BTData;

typedef struct _btTreeNode
{
	BTData data;
	struct _btTreeNode * left;
	struct _btTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);

BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRighSubTree(BTreeNode * main, BTreeNode * sub);

#endif // !__BINARY_TREE_H__