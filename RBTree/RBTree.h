#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct RBT_tag
{
	struct RBT_tag* Left;
	struct RBT_tag* Right;
	struct RBT_tag* Parent;

	enum { RED, BLACK } Color;
	
	ElementType Data;
}RBT_Node;

void DestroyTree(RBT_Node* Tree);

RBT_Node* CreateNode(ElementType NewData);
void DestroyNode(RBT_Node* Node);

RBT_Node* SearchNode(RBT_Node* Tree, ElementType Target);
RBT_Node* SearchMinNode(RBT_Node* Tree);

void InsertNode(RBT_Node** Tree, RBT_Node* NewNode);
void InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);

RBT_Node* RemoveNode(RBT_Node** Root, RBT_Node* X);

void RebuildAfterInsert(RBT_Node** Tree, RBT_Node* NewNode);
void RebuildAfterRemove(RBT_Node** Root, RBT_Node* X);

void PrintTree(RBT_Node* Node, int Depth, int BlackCount);
void RotateLeft(RBT_Node** Root, RBT_Node* Parent);
void RotateRight(RBT_Node** Root, RBT_Node* Parent);

#endif
