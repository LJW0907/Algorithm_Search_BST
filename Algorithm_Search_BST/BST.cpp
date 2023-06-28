#pragma once
#include "BST.h"

extern Node *head;

Node* Tree_Minimum(Node* node);
Node* BST_Successor(Node* node);


Node* BST_SearchNode(Node* x, int target)
{
	if (x == NULL || target == x->data)
		return x;
	
	if (target < x->data)
		BST_SearchNode(x->left, target);
	else
		BST_SearchNode(x->right, target);
}

void BST_InsertNode(Node* tree, Node* node)
{
	Node *y = NULL;
	Node *x = tree;

	while (x != NULL) {
		y = x;

		if (node->data < x->data) 
			x = x->left;
		else 
			x = x->right;
	}

	if (y == NULL) { //tree�� ����ִ� ���
		head = node;
		return;
	}
	else if (y->data > node->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}
	node->p = y;
}

Node* BST_DeleteNode(Node* tree, Node* node) {
	Node* x;
	Node* y; //������ �������� ��带 ����Ŵ

	if (node->left == NULL && node->right == NULL) { //������� ��� �ڽ� ����
		y = node;

		if (y->p == NULL) { //y�� ��Ʈ�� ��
			head = NULL;
		}

		if (y == y->p->left)
			y->p->left = NULL;
		else
			y->p->right = NULL;

		return y;
	}
	else if (node->left == NULL || node->right == NULL) { //������� ��尡 �ڽ� �ϳ� ����
		y = node;

		if (y->left != NULL) //y�� ���� �ڽ� ���� ��
			x = y->left;
		else //y�� ������ �ڽ� ���� ��
			x = y->right;

		if (y->p == NULL) { //y�� ��Ʈ�� ��
			head = x;
		}

		x->p = y->p;

		if (y == y->p->left)
			y->p->left = x;
		else
			y->p->right = x;

		return y;
	}
	else { //������� ��尡 �ڽ� 2��
		y = BST_Successor(node);

		node->data = y->data;

		if (y == y->p->left) { //successor y�� �����ڽĳ���϶�
			y->p->left = y->right;

			if (y->right != NULL) //y�� �������ڽ� ���� ��
				y->right->p = y->p;
		}
		else //y�� ������ ����� �� �ڽ��� ���� �� ����
			y->p->right = NULL;

		return y;
	}
}

Node* BST_Successor(Node* node) {
	Node* y;

	if (node->right != NULL) //node�� ������ ��Ʈ���� �ִٸ�
		return Tree_Minimum(node->right);

	y = node->p;

	while (y != NULL && node == y->right) {
		node = y;
		y = y->p;
	}

	return y;
}

Node* Tree_Minimum(Node* node) { //Tree �� �ּڰ� ã��
	while (node->left != NULL) 
		node = node->left;
		
	return node;
}

void BST_PreOrder(Node* tree) { //������ ��ȸ
	if (tree == NULL)
		return;

	std::cout << tree->data << " ";
	BST_PreOrder(tree->left);
	BST_PreOrder(tree->right);
}

void BST_InOrder(Node* tree) { //���� ��ȸ
	if (tree == NULL)
		return;

	BST_InOrder(tree->left);
	std::cout << tree->data << " ";
	BST_InOrder(tree->right);
}

void BST_PostOrder(Node* tree){ //�ļ��� ��ȸ
	if (tree == NULL)
		return;

	BST_PostOrder(tree->left);
	BST_PostOrder(tree->right);
	std::cout << tree->data << " ";
}