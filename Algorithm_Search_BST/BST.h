#pragma once
#include <iostream>
#include <string.h>

class Node
{
public:
	int data;
	Node* p = NULL;
	Node* left = NULL;
	Node* right = NULL;

	Node()
	{ }

	Node(int _data)
		:data(_data)
	{ }
};

Node* BST_SearchNode(Node* tree, int target);
void BST_InsertNode(Node* tree, Node* node);
Node* BST_DeleteNode(Node* tree, Node* node);

void BST_PreOrder(Node* tree);
void BST_InOrder(Node* tree); //중순위 순회
void BST_PostOrder(Node* tree);