#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *root;
int *minEl = new int(1000);
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

void searchMinEl(Node *aNode){
	if (aNode){
		searchMinEl(aNode->left);
		if(aNode->value > 0){
			if(aNode->value < *minEl){
				*minEl = aNode->value;
			}
		}
		searchMinEl(aNode->right);
	}
	return;
}

int main(){
	for(int i = 0; i<10; i++){
		InsertTree(&root, rand() % 100 - 50);
	}
	printf("Elements: ");
	PrintTree(root);
	searchMinEl(root);
	printf("\nminimal positive: %d \n", *minEl);
	system("pause");
	return 0;
}





