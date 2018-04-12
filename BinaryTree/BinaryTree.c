#include "BinaryTree.h"

BST_Node* CreateNode(ElementType NewData)
{
	BST_Node* NewNode=(BST_Node*)malloc(sizeof(BST_Node));
	NewNode->Data=NewData;
	NewNode->Left=NULL;
	NewNode->Right=NULL;
	
	return NewNode;
}

void DestroyNode(BST_Node* Node)
{
	free(Node);
}

void DestroyTree(BST_Node* Tree)
{
	if(Tree->Right!=NULL) DestroyTree(Tree->Right);
	else if(Tree->Left!=NULL) DestroyTree(Tree->Left);
	
	Tree->Left=NULL;
	Tree->Right=NULL;
	DestroyNode(Tree);
}

BST_Node* SearchNode(BST_Node* Tree, ElementType Target)
{
	if(Tree==NULL) return NULL;
	if(Target==Tree->Data) return Tree;
	else if(Tree->Data<Target) SearchNode(Tree->Right,Target);
	else SearchNode(Tree->Left,Target);
}

BST_Node* SearchMinNode(BST_Node* Tree)
{
	if(Tree==NULL) return NULL;
	if(Tree->Left==NULL) return Tree;
	else SearchMinNode(Tree->Left);
}

void InsertNode(BST_Node* Tree, BST_Node* child)
{
	if(Tree->Data>child->Data)
	{
		if(Tree->Left==NULL)Tree->Left=child;
		else InsertNode(Tree->Left, child);
	}
	else if(Tree->Data<child->Data)
	{
		if(Tree->Right==NULL)Tree->Right=child;
		else InsertNode(Tree->Right, child);
	}
}

BST_Node* RemoveNode(BST_Node* Tree, BST_Node* parent, ElementType Target)
{
	BST_Node* Removed=NULL;
	if(Tree==NULL) return NULL;
	if(Tree->Data>Target) Removed=RemoveNode(Tree->Left,Tree,Target);
	else if(Tree->Data<Target) Removed=RemoveNode(Tree->Right,Tree,Target);
	else
	{
		Removed=Tree;
		if(Tree->Left==NULL && Tree->Right==NULL)
		{	
			if(parent->Left==Tree) parent->Left=NULL;
			else parent->Right=NULL;
		}
		else if(Tree->Left!=NULL && Tree->Right!=NULL)
		{
			BST_Node* MinNode=SearchMinNode(Tree->Right);
			MinNode=RemoveNode(Tree,NULL,MinNode->Data);
			Tree->Data=MinNode->Data;
		}
		else
		{
			if(Tree->Left!=NULL)
			{
				if(parent->Left==Tree) parent->Left=Tree->Left;
				else parent->Right=Tree->Left;
			}
			else
			{
				if(parent->Left==Tree) parent->Left=Tree->Right;
				else parent->Right=Tree->Right;
			}
		}
	}
	return Removed;
}

void PrintTree(BST_Node* Tree)
{
	if(Tree==NULL) return;

	PrintTree(Tree->Left);
	printf("%d ",Tree->Data);
	PrintTree(Tree->Right);
}
