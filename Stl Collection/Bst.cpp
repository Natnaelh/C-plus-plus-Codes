#include<iostream>
#include "bst.h"

using namespace std;

int main(){

	bst<int> mytree;
	mytree.insertNode(10);
	mytree.insertNode(15);
	mytree.insertNode(7);
	mytree.insertNode(13);
	mytree.insertNode(16);
	mytree.insertNode(5);
	mytree.insertNode(6);
	mytree.showNodesInorder();





}