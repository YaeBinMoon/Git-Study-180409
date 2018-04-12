#include "BinaryTree.h"

int main(void)
{
	BST_Node* Tree = CreateNode(123);
	BST_Node* Node = NULL;

	InsertNode(Tree, CreateNode(22));
	InsertNode(Tree, CreateNode(9918));
	InsertNode(Tree, CreateNode(424));
	InsertNode(Tree, CreateNode(17));
	InsertNode(Tree, CreateNode(3));
	
	InsertNode(Tree, CreateNode(98));
	InsertNode(Tree, CreateNode(34));
	
	InsertNode(Tree, CreateNode(760));
	InsertNode(Tree, CreateNode(317));
	InsertNode(Tree, CreateNode(1));

	PrintTree(Tree);
	printf("\n");

	printf("Removing 98...\n");
	Node=RemoveNode(Tree,NULL,98);
	DestroyNode(Node);

	PrintTree(Tree);
	printf("\n");

	printf("Inserting 111...\n");
	InsertNode(Tree, CreateNode(111));
	PrintTree(Tree);
	printf("\n");
	
	DestroyTree(Tree);

	return 0;
}
