#include "BinaryTree.h"

extern RBT_Node* Nil;

RBT_Node* CreateNode(ElementType NewData)
{
	RBT_Node* NewNode=(RBT_Node*)malloc(sizeof(RBT_Node));
	NewNode->Data=NewData;
	NewNode->Parent=NULL;
	NewNode->Left=NULL;
	NewNode->Right=NULL;
	NewNode->Color=BLACK;
	
	return NewNode;
}

void DestroyNode(RBT_Node* Node)
{
	free(Node);
}

void DestroyTree(RBT_Node* Tree)
{
	if(Tree->Right!=Nil) DestroyTree(Tree->Right);
	else if(Tree->Left!=Nil) DestroyTree(Tree->Left);
	
	Tree->Left=Nil;
	Tree->Right=Nil;
	DestroyNode(Tree);
}

RBT_Node* SearchNode(RBT_Node* Tree, ElementType Target)
{
	if(Tree==Nil) return NULL;
	if(Target==Tree->Data) return Tree;
	else if(Tree->Data<Target) SearchNode(Tree->Right,Target);
	else SearchNode(Tree->Left,Target);
}

RBT_Node* SearchMinNode(RBT_Node* Tree)
{
	if(Tree==Nil) return Nil;
	if(Tree->Left==Nil) return Tree;
	else SearchMinNode(Tree->Left);
}

void InsertNode(RBT_Node** Tree, RBT_Node* NewNode)
{
	InsertNodeHelper(Tree, NewNode);
	
	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RebuldAfterInsert(Tree, NewNode);
}

void InsertNodeHelper(RBT_Node** Tree, RBT_Node* NewNode)
{
	if((*Tree)==NULL) (*Tree) = NewNode;
	
	if((*Tree)->Data > NewNode->Data)
	{
		if((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else InsertNodeHelper(&((*Tree)->Left), NewNode);
	}
	
	else if((*Tree)->Data < NewNode->Data)
	{
		if((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else InsertNodeHelper(&((*Tree)->Right), NewNode);
	}
}

void RotateRight(RBT_Node** Root, RBT_Node* Parent)
{
	RBT_Node* LeftChild = Parent->Left;

	Parent->Left = Leftchild->Right;
	LeftChild->Parent = Parent->Parent;
	if(LeftChild->Right != Nil) LeftChild->Right->Parent = Parent;

	if(Parent->Parent == NULL) (*Root) = LeftChild;
	else
	{
		if(Parent == Parent->Parent->Left) Parent->Parent->Left = LeftChild;
		else Parent->Parent->Right = LeftChild;
	}
	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}


void RotateLeft(RBT_Node** Root, RBT_Node* Parent)
{
	RBT_Node* RightChild = Parent->Right;

	Parent->Right = Rightchild->Left;
	RightChild->Parent = Parent->Parent;
	if(RightChild->Left != Nil) RightChild->Left->Parent = Parent;

	if(Parent->Parent == NULL) (*Root) = RightChild;
	else
	{
		if(Parent == Parent->Parent->Left) Parent->Parent->Left = RightChild;
		else Parent->Parent->Left = RightChild;
	}
	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}

void RebuidAfterInsert(RBT_Node** Root, RBT_Node* X)
{
	RBT_Node* Uncle = NULL;
	while(X!=(*Root) && X->Parent->Color == RED)
	{
		if( X->Parent == X->Parent->Parent->Left)
		{
			Uncle = X->Parent->Parent->Right;
			if(Uncle->Color == RED)
			{
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;
				X = X->Parent->Parent;
			}
			else
			{
				if(X==X->Parent->Right)
				{
					X = X->Parent;
					RotateLeft( Root, X );
				}
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RotateRight( Root, X->Parent->Parent );
			}
		}
		else
		{
			Uncle = X->Parent->Left;
			
			if(Uncle->Color == RED)
			{
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;
				X = X->Parent->Parent;
			}
			else
			{
				if(X==X->Parent->Left)
				{
					X = X->Parent;
					RotateRight( Root, X );
				}
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RotateLeft( Root, X->Parent->Parent );
		}
	}
	(*Root)->Color = BLACK;
}

RBT_Node* RemoveNode(RBT_Node** Root, ElementType Data)
{
	RBT_Node* Removed = NULL;
	RBT_Node* Successor = NULL;
	RBT_Node* Target = SearchNode((*Root),Data);

	if(Target==NULL) return NULL;
	if(Target->Left==Nil || Target->Right==Nil) Removed=Target;
	else
	{
		Removed=SearchMinNode(Target->Right);
		Target->Data=Removed->Data;
	}
	if(Removed->Left!=Nil) Successor=Removed->Left
	else Successor=Removed->Right;

	Successor->Parent=Removed->Parent;
	if(Removed->Parent==NULL) (*Root)=Successor;
	else
	{
		if(Removed==Removed->Parent->Left)Removed->Parent->Left=Successor;
		else Removed->Parent->Right=Successor;
	}
	if(Removed->Color==BLACK) RebuildAfterRemove(Root,Successor);
	return Removed;
}

void PrintTree(BST_Node* Tree)
{
	if(Tree==NULL) return;

	PrintTree(Tree->Left);
	printf("%d ",Tree->Data);
	PrintTree(Tree->Right);
}
