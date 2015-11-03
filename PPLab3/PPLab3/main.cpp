#include <iostream>
#include <time.h>
#include <iomanip>

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *root;
void InsertTree(Node **aNode, int data){
	if (!(*aNode)){		// додаємо новий елемент
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else{
	if (data < (*aNode)->value) InsertTree(&(*aNode)->left,data);
	else InsertTree(&(*aNode)->right, data);
	}
	return;
}

void PrintTree(Node *aNode){
	if (aNode){
		PrintTree(aNode->left);
		printf("%d   ",aNode->value);
		PrintTree(aNode->right);
	}
	return;
}

int main(){
	InsertTree(&root, 20);
	InsertTree(&root, 0);
	InsertTree(&root, 21);
	InsertTree(&root, 5);
	InsertTree(&root, 3);
	InsertTree(&root, 2);
	InsertTree(&root, 14);
	PrintTree(root);
	system("pause");
	return 0;
}





