#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionaryBTS.h"
// << ���� Ž�� Ʈ�� ���� ���� : [���� 7-4] ���� >>
// ������ p�� ����Ű�� ���� ���Ͽ� �׸� key�� �����ϴ� ����([���� 7-4] ����)
treeNode* insertKey(treeNode* p, element key) {
	treeNode* newNode;
	int compare;

	// ������ �ڸ��� �� ��带 �����Ͽ� ����
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	// ���� Ʈ������ ������ �ڸ� Ž��
	else {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0)      p->left = insertKey(p->left, key);
		else if (compare > 0)  p->right = insertKey(p->right, key);
		else  printf("\n �̹� ���� �ܾ �ֽ��ϴ�! \n");
		return p;  // ������ �ڸ� ��ȯ
	}
}

void insertWord(treeNode** root, element key) {
	*root = insertKey(*root, key);
}

// root ������ Ž���Ͽ� key�� ���� ��带 ã�� �����ϴ� ����
void deleteWord(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (strcmp(p->key.word, key.word) != 0)) {
		parent = p;
		if (strcmp(key.word, p->key.word) < 0)  p = p->left;
		else  p = p->right;
	}
	// ������ ��尡 ���� ���
	if (p == NULL) {
		printf("\n ������ �ܾ ������ �����ϴ�!!");
		return;
	}
	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else  child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else  parent->right = child;
		}
		else root = child;
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else {
		succ_parent = p;
		succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent->left == succ)
			succ_parent->left = succ->right;
		else   succ_parent->right = succ->right;

		p->key = succ->key;
		p = succ;
	}
	free(p);
}

// ���� Ž�� Ʈ������ Ű���� key�� ��� ��ġ�� Ž���ϴ� ����
treeNode* searchDic(treeNode* root, element key) {
	treeNode* p;
	int compare;
	p = root;

	while (p != NULL) {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0)      p = p->left;
		else if (compare > 0)  p = p->right;
		else {
			printf("\nã�� �ܾ� : %s", p->key.word);
			return p;
		}
	}
	return p;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
void displayDic(treeNode* root) {
	if (root) {
		displayDic(root->left);
		printf("\n%s : %s", root->key.word, root->key.mean);
		displayDic(root->right);
	}
}

// ���� ���� �޴�
void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : ���");
	printf("\n\t2 : �Է�");
	printf("\n\t3 : ����");
	printf("\n\t4 : �˻�");
	printf("\n\t5 : ����");
	printf("\n*---------------------------*\n  ");
}