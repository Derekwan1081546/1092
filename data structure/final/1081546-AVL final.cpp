#include <iostream>
#include<stack>
using namespace std;

template <class K, class E> class AVL; \

template <class K, class E>
class AvlNode {
	friend class AVL<K, E>;
public:
	AvlNode(const K& k, const E& e)
	{
		key = k;
		element = e;
		bf = 0;
		leftChild = rightChild = 0;
	}
private:
	K key;
	E element;
	int bf;
	AvlNode<K, E>* leftChild, * rightChild;
};

template <class K, class E>
class AVL {
public:
	AVL() : root(0) {};
	//void inorder(void) const; //請完成這個函數，執行inorder traversal印出key拜訪順序就可
	//E& Search(const K&) const; //請完成這個函數，找到 K值回傳 E 值；找不到回傳-1,我們假設E是一個正整數
	//void Insert(const K&, const E&);

	E& Search(const K&) const;

	void Preorder(AvlNode<K, E>* node) const;
	void Inorder(AvlNode<K, E>* node) const;
	void Postorder(AvlNode<K, E>* node) const;

	void DisplayPreorder() const;
	void DisplayInorder() const;
	void DisplayPostorder() const;

	void Insert(const K&, const E&);
	//	void Delete(const K&);
private:
	AvlNode<K, E>* root;
};

template <class K, class E>
void AVL<K, E>::DisplayPreorder() const
{
	cout << "Preorder:" << endl;
	Preorder(root);
	cout << endl;
}

template <class K, class E>
void AVL<K, E>::DisplayInorder() const
{
	cout << "Inorder:" << endl;
	Inorder(root);
	cout << endl;
}

template <class K, class E>
void AVL<K, E>::DisplayPostorder() const
{
	cout << "Postorder:" << endl;
	Postorder(root);
	cout << endl;
}

template <class K, class E>
void AVL<K, E>::Inorder(AvlNode<K, E>* node) const
{
	stack <AvlNode<K, E>* > s; // declare and initialize stack
	AvlNode<K, E>* currentNode = root;
	while (1)
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		if (s.empty()) return;
		currentNode = s.top();
		s.pop();
		cout << "(" << currentNode->key << "," << currentNode->element << "," << currentNode->bf << ")";//add
		//cout << currentNode;
		currentNode = currentNode->rightChild;
	}
}
//recursive preorder
template <class K, class E>
void AVL<K, E>::Preorder(AvlNode<K, E>* node) const
{
	if (node == NULL)
		return;
	cout << "(" << node->key << "," << node->element << "," << node->bf << ")";
	Preorder(node->leftChild);
	Preorder(node->rightChild);
}
//recursive postorder
template <class K, class E>
void AVL<K, E>::Postorder(AvlNode<K, E>* node) const
{

	if (node == NULL)
		return;
	Postorder(node->leftChild);
	Postorder(node->rightChild);
	cout << "(" << node->key << "," << node->element << "," << node->bf << ")";
}
template <class K, class E>
E& AVL<K, E>::Search(const K& k) const
{
	//AvlNode<K, E>* p = root; // p moves through the tree

	//int level = 1;
	//while (p) {
	//	if (k == p->key) {
	//		cout << "Find " << k << " in Level " << level << endl;
	//		return p->element;
	//	}
	//	else if (k < p->key) {
	//		p = p->leftChild;
	//	}
	//	else {
	//		p = p->rightChild;
	//	}

	//}
	//cout << "Not find " << k << " in AVL tree" << endl;
	//return p->element;
	AvlNode<K, E>* a = root;
	int level = 1;
	while (a)
	{
		if (k < a->key)
		{
			a = a->leftChild;
			//Search(k);
			//return a->element;
		}
		else if (k > a->key)
		{
			a = a->rightChild;
			//Search(k);
			//return a->element;
		}
		else if (k == a->key)
		{
			cout << "Find " << k << " in Level " << level << endl;
			return a->element;
		}
	}
	cout << "Not find " << k << " in AVL tree" << endl;
	return a->element; // miss
}

template <class K, class E>
void AVL<K, E>::Insert(const K& k, const E& e)
{
	cout << "Insert (" << k << ", " << e << ")" << endl;

	// special case: empty tree. Return
	if (root == NULL) {
		root = new AvlNode<K, E>(k, e);
		return;
	}


	// Phase 1: Locate insert in point for e 
	AvlNode<K, E>* a = 0;    // most recent node with bf = ±1
	AvlNode<K, E>* pa = 0; 	 // parent of  a
	AvlNode<K, E>* p = root; // p moves through the tree
	AvlNode<K, E>* pp = 0;	 // parent of p

	while (p) {
		// find most recent node with bf = ±1
		if (p->bf) {
			a = p;
			pa = pp;
		}

		if (k < p->key) { // take left branch
			pp = p;
			p = p->leftChild;
		}
		else if (k > p->key) {
			pp = p;
			p = p->rightChild;
		}
		else { // k already in tree, change e only. Return
			p->element = e;
			return;
		}
	} // end of while


	// Phase 2: Insert and rebalance. K is not  in the tree and may be inserted as the appropriate child of pp.
	AvlNode<K, E>* y = new AvlNode<K, E>(k, e);
	if (k < pp->key) {
		pp->leftChild = y;  // insert as a left child
	}
	else {
		pp->rightChild = y;	// insert as a right child
	}

	// Adjust the balance factor of nodes on path from a to pp. By the definition of a,
	// all nodes on this path presently have a balance factor of 0. Their new
	// balance factor will be ±1. d = +1 implies that k is inserted in the left child of a,
	// d = -1 implies that k is inserted in the right subtree of a.

	int d;
	AvlNode<K, E>* b; // child of a
	AvlNode<K, E>* c; // child of b

	// all bf from a to pp are 0
	// Adjust from root to pp
	if (!a) {
		p = root;
		while (p != y) {
			if (k > p->key) { // height of right child increases 1
				p->bf = -1;
				p = p->rightChild;
			}
			else { // height of left child increases 1
				p->bf = 1;
				p = p->leftChild;
			}
		}
		return;
	}

	// Adjust from a to pp
	if (k > a->key) {
		b = a->rightChild;
		p = a->rightChild;
		d = -1;

	}
	else {
		b = a->leftChild;
		p = a->leftChild;
		d = 1;
	}

	while (p != y) {
		if (k > p->key) { // height of right child increases 1
			p->bf = -1;
			p = p->rightChild;
		}
		else { // height of left child increases 1
			p->bf = 1;
			p = p->leftChild;
		}
	}

	// Is tree balanced?
	if (!(a->bf) || !(a->bf + d)) { // tree still balanced
		a->bf += d;
		return;
	}

	// tree unbalanced, determine rotation type
	if (d == 1) { // left unbalance
		if (b->bf == 1) {// rotate type LL
			cout << "*****LL Rotate" << endl;
			a->leftChild = b->rightChild;
			b->rightChild = a;
			a->bf = 0;
			b->bf = 0;

		}
		else { // rotate type LR
			cout << "*****LR Rotate" << endl;
			c = b->rightChild;
			b->rightChild = c->leftChild;
			a->leftChild = c->rightChild;
			c->leftChild = b;
			c->rightChild = a;
			switch (c->bf) {
			case 1:
				a->bf = -1;
				b->bf = 0;
				break;
			case -1:
				b->bf = 1;
				a->bf = 0;
				break;
			case 0:
				b->bf = 0;
				a->bf = 0;
				break;
			}
			c->bf = 0;
			b = c; // b is the new root
		}// end of LR
	} // end of left imbalanced
	else {  // right imbalanced: this is symmetric to the left imbalance
		if (b->bf == -1) {// rotate type RR
			cout << "*****RR Rotate" << endl;
			a->rightChild = b->leftChild;
			b->leftChild = a;
			a->bf = 0;
			b->bf = 0;
		}
		else { // rotate type RL
			cout << "*****RL Rotate" << endl;
			c = b->leftChild;
			b->leftChild = c->rightChild;
			a->rightChild = c->leftChild;
			c->rightChild = b;
			c->leftChild = a;
			switch (c->bf) {
			case 1:
				a->bf = 0;
				b->bf = -1;
				break;
			case -1:
				b->bf = 0;
				a->bf = 1;
				break;
			case 0:
				b->bf = 0;
				a->bf = 0;
				break;
			}
			c->bf = 0;
			b = c; // b is the new root
		}// end of LR
	}

	// Subtree with root b has been rebalanced.
	if (!pa) {
		root = b;
	}
	else if (a == pa->leftChild) {
		pa->leftChild = b;
	}
	else {
		pa->rightChild = b;
	}

	return;
} // end of AVL::Insert

void main()
{
	int element[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int key[12] = { 132, 136, 142, 15, 11, 101, 43, 103, 62, 107, 152, 193 };
	AVL<int, int> avlT1;

	//下面的 key 可測課本範例
	//string key[12] = { "MAR", "MAY", "NOV", "AUG", "APRIL", "JAN", "DEC", "JULY", "FEB", "JUNE", "OCT", "SEP" };
	//AVL<string, int> avlT1;

	for (int i = 0; i < 12; ++i) {
		avlT1.Insert(key[i], element[i]);
		avlT1.DisplayInorder();

		cout << endl;
	}
	avlT1.DisplayInorder();

	avlT1.Search(193);
	avlT1.Search(194);
	/*AVL<int, int> avlT1;

	avlT1.Insert(10, 1);
	avlT1.Insert(15, 2);
	avlT1.Insert(12, 3);
	avlT1.Insert(4, 4);
	avlT1.Insert(22, 5);

	avlT1.inorder();
	avlT1.Search(12);

	cout << "AVL tree" << endl;*/
}
