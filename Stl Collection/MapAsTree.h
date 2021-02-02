#ifndef _TreeMap_h
#define _TreeMap_h
#include<string>
using namespace std;

template <typename Valtype>
class MapAsTree
{
public:
	MapAsTree();
	~MapAsTree();
	void add(string key, Valtype value);
	Valtype getValue(string key);
private:
	struct Node
	{
		string key;
		Valtype value;
	    Node *left , *right;
	};
	Node *root;
	Node *treeSearch(Node *t, string key);
	void treeEnter(Node *&t , string key, Valtype value);
};

#endif


template<typename Valtype>
MapAsTree<Valtype>::MapAsTree(){

}
template<typename Valtype>
MapAsTree<Valtype>::~MapAsTree(){

}
template<typename Valtype>
typename MapAsTree<Valtype>::Node MapAsTree<Valtype>::*treeSearch(Node *t , string key){
	if (t == NULL) return NULL;
	if (key == t->key) return t;
	else if (key < t->key) return treeSearch(t->left , key);
	else return treeSearch(t->right , key);
}


