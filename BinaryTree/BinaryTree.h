#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct BST_tag
{
	struct BST_tag* Left;
	struct BST_tag* Right;
	ElementType Data;
}BST_Node;

BST_Node* CreateNode(ElementType NewData);
void DestroyNode(BST_Node* Node);
void DestroyTree(BST_Node* Tree);

BST_Node* SearchNode(BST_Node* Tree, ElementType Target);
BST_Node* SearchMinNode(BST_Node* Tree);
void InsertNode(BST_Node* Tree, BST_Node* child);
BST_Node* RemoveNode(BST_Node* Tree, BST_Node* parent, ElementType Target);
void PrintTree(BST_Node* Tree);

#endif
