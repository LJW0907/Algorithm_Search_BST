#include "BST.h"

Node* head = NULL; //첫 노드 주소를 담을 헤드

int main() {
	Node *n1 = new Node(5);
	Node *n2 = new Node(1);
	Node *n3 = new Node(7);
	Node *n4 = new Node(2);
	Node *n5 = new Node(3);
	Node *n6 = new Node(4);
	Node *n7 = new Node(6);
	Node *n8 = new Node(8);
	Node *n10;

	BST_InsertNode(head, n1);
	BST_InsertNode(head, n2);
	BST_InsertNode(head, n3);
	BST_InsertNode(head, n4);
	BST_InsertNode(head, n5);
	BST_InsertNode(head, n6);
	BST_InsertNode(head, n7);
	BST_InsertNode(head, n8);

	BST_PreOrder(head);
	std::cout << std::endl;
	BST_InOrder(head);
	std::cout << std::endl;
	BST_PostOrder(head);
	std::cout << std::endl;

	BST_DeleteNode(head, n1);

	std::cout << head->data << std::endl;

	BST_PreOrder(head);
	std::cout << std::endl;
	BST_InOrder(head);
	std::cout << std::endl;
	BST_PostOrder(head);
	std::cout << std::endl;

	BST_DeleteNode(head, n2);
	BST_PreOrder(head);
	std::cout << std::endl;
	BST_InOrder(head);
	std::cout << std::endl;
	BST_PostOrder(head);
	std::cout << std::endl;

	BST_DeleteNode(head, n5);
	BST_PreOrder(head);
	std::cout << std::endl;
	BST_InOrder(head);
	std::cout << std::endl;
	BST_PostOrder(head);
	std::cout << std::endl;

	BST_DeleteNode(head, n6);
	BST_PreOrder(head);
	std::cout << std::endl;
	BST_InOrder(head);
	std::cout << std::endl;
	BST_PostOrder(head);
	std::cout << std::endl;
}