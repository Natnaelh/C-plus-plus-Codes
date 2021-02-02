#ifndef _bst_h
#define _bst_h
#include <iostream>
#include<string>
using namespace std;

template <typename Mytype>
class bst
{

private:
	struct TreeNode
	{
		Mytype value;
		struct TreeNode *left, *right;
		
	};
	TreeNode *root;

public:
	bst();
	~bst();

	void destroySubtree();
	void deleteNode(Mytype , TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInorder(TreeNode *);
	void displayPreorder(TreeNode *);
	void displayPostOrder(TreeNode *);
	void showNodesInorder();
	void showNodesPreorder();
	void showNodesPostorder();
	void insertNode(Mytype);
	void searchNode(Mytype);
	void remove(Mytype);
	
};

#endif

template <typename Mytype>
bst<Mytype>::bst(){
	root = NULL;
}

template <typename Mytype>
bst<Mytype>::~bst(){
	// destroySubtree(root);
}

template <typename Mytype>
void bst<Mytype>::insertNode(Mytype n){
	TreeNode *newNode = new TreeNode;
	TreeNode *nodeptr;
	newNode -> value = n;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	if (root == NULL){
		root = newNode;
	}
	else{
		nodeptr = root;
		while (nodeptr != NULL){
			if (nodeptr->value > n){
				if (nodeptr->left){
					nodeptr-> left = newNode;
					break;
				}
			}
			else if(nodeptr->value < n){
				if (nodeptr-> right){
					nodeptr->right = newNode;
					break;
				}
			} 
			else{
				cerr<<" Value aready Exists! "<<endl;
			}

			}
		}
	}



template <typename Mytype>
void bst<Mytype>::displayInorder(TreeNode *r){
	if (r != NULL){
		displayInorder(r->left);
		cout<<r->value<< " ";
		displayInorder(r->right);
	}

}

template<typename Mytype>

void bst<Mytype>::showNodesInorder(){
	displayInorder(root);
}


template <typename Mytype>
void bst<Mytype>::displayPreorder(TreeNode *r){
	if (r != NULL){
		cout<<r->value<< " ";
		displayPreorder(r->left);
		displayPreorder(r->right);
	}

}

template<typename Mytype>

void bst<Mytype>::showNodesPreorder(){
	displayPreorder(root);
}

template <typename Mytype>
void bst<Mytype>::displayPostOrder(TreeNode *r){
	if (r != NULL){
		displayPostOrder(r->left);
		displayPostOrder(r->right);
		cout<<r->value<< " ";
	}

}

template<typename Mytype>

void bst<Mytype>::showNodesPostorder(){
	displayPostOrder(root);
}












