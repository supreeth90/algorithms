#include <iostream>


using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int data);
};

Node::Node(int data) {
	this->data=data;
}

Node* arrToBST(int arr[],int start,int end){
	if (start > end) {
		return NULL;
	}
	int mid=(start+end)/2;
	Node *root=new Node(arr[mid]);
	root->left=arrToBST(arr,start,mid-1);
	root->right=arrToBST(arr,mid+1,end);
	return root;
}

void preOrder(Node *root){
	if(root == NULL) {
		return ;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root){
	if(root == NULL) {
		return ;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(Node *root){
	if(root == NULL) {
		return ;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

int main() {
	int arr[6];
	arr[0]=4;
	arr[1]=6;
	arr[2]=8;
	arr[3]=9;
	arr[4]=10;
	arr[5]=12;
	Node *root;
	root=arrToBST(arr,0,5);
	preOrder(root);
	cout << "----" << endl;
	inOrder(root);
	cout << "----" << endl;
	postOrder(root);
	return 1;
}