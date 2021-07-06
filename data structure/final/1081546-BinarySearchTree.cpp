#include <iostream>
#include <string>
using namespace std;

struct Student {
	int id;
	int age;
	string name;
};


struct treeNode {
	Student data;
	treeNode* leftChild;
	treeNode* rightChild;
};

class BSTree {
public:
	BSTree();
	~BSTree();
	void addNode(Student &std);
	void deleteNode(int id);
	void search(int id);
	void displayPreorder();
	void displayInorder();
	void displayPostorder();

private:
	// utility functions
	treeNode* insert(Student& std, treeNode* t);
	treeNode* makeEmpty(treeNode* t);
	treeNode* deleteNode(int id, treeNode* t);
	treeNode* findMin(treeNode* t);
	treeNode* findMax(treeNode* t);
	treeNode* find(treeNode* t, int id);
	void preorder(treeNode* t);
	void inorder(treeNode* t);
	void postorder(treeNode* t);

	treeNode* root;
};

// constructor
BSTree::BSTree() :root(0){ }

//destructor
BSTree::~BSTree()
{
	root = makeEmpty(root);
}


void BSTree::deleteNode(int id)
{
	root = deleteNode(id, root);
}

void BSTree::displayPreorder()
{
	preorder(root);
	cout << endl;
}
void BSTree::displayInorder()
{
	inorder(root);
	cout << endl;
}
void BSTree::displayPostorder()
{
	postorder(root);
	cout << endl;
}

void BSTree::search(int id)
{
	root = find(root, id);
}

treeNode* BSTree::makeEmpty(treeNode* t)
{
	if (t == NULL)
		return NULL;
	{
		makeEmpty(t->leftChild);
		makeEmpty(t->rightChild);
		delete t;
	}
	return NULL;
}



void BSTree::addNode(Student &std)
{
	treeNode* y = 0;
	treeNode* x = 0;
	treeNode* newNode = new treeNode;
	newNode->data = std;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	x = this->root;
	while (x != NULL) 
	{
		y = x;
		if (newNode->data.id < x->data.id) 
		{
			x = x->leftChild;
		}
		else if (newNode->data.id > x->data.id) 
		{
			x = x->rightChild;
		}
		else
			break;
	}

	if (y == NULL)
		this->root = newNode;
	else if (newNode->data.id < y->data.id)
		y->leftChild = newNode;
	else if (newNode->data.id > y->data.id)
		y->rightChild = newNode;
	else if (newNode->data.id == y->data.id)
		y->data = newNode->data;
	//root = insert(std, root);//¤èªk¤G
}
treeNode* BSTree::insert(Student& std, treeNode* t)
{
	if (t == NULL)
	{
		t = new treeNode;
		t->data = std;
		t->leftChild = t->rightChild = NULL;
	}
	else if (std.id < t->data.id)
		t->leftChild = insert(std, t->leftChild);
	else if (std.id > root->data.id)
		t->rightChild = insert(std, t->rightChild);
	else if (std.id == t->data.id)
	{
		t->data.age = std.age;
		t->data.name = std.name;
	}
	return t;
}

treeNode* BSTree::findMin(treeNode* t)
{
	if (t == NULL)
		return NULL;
	else if (t->leftChild == NULL)
		return t;
	else
		return findMin(t->leftChild);
}

treeNode* BSTree::findMax(treeNode* t)
{
	if (t == NULL)
		return NULL;
	else if (t->rightChild == NULL)
		return t;
	else
		return findMax(t->rightChild);
}



treeNode* BSTree::deleteNode(int id, treeNode* t)
{
	treeNode* temp;
	if (t == NULL)
		return NULL;
	else if (id < t->data.id)
		t->leftChild = deleteNode(id, t->leftChild);
	else if (id > t->data.id)
		t->rightChild = deleteNode(id, t->rightChild);
	else if (t->leftChild && t->rightChild)
	{
		temp = findMin(t->rightChild);
		t->data = temp->data;
		t->rightChild = deleteNode(t->data.id, t->rightChild);
	}
	else
	{
		temp = t;
		if (t->leftChild == NULL)
			t = t->rightChild;
		else if (t->rightChild == NULL)
			t = t->leftChild;
		delete temp;
	}

	return t;
}




void BSTree::preorder(treeNode* t)
{
	if (t == NULL)
		return;
	cout << "<" << t->data.id << "," << t->data.age << "," << t->data.name << ">" << " ";
	preorder(t->leftChild);
	preorder(t->rightChild);
}

void BSTree::inorder(treeNode* t)
{
	if (t == NULL)
		return;
	inorder(t->leftChild);
	cout << "<" << t->data.id << "," << t->data.age << "," << t->data.name << ">" << " ";
	inorder(t->rightChild);
}

void BSTree::postorder(treeNode* t)
{
	if (t == NULL)
		return;
	postorder(t->leftChild);
	postorder(t->rightChild);
	cout << "<" << t->data.id << "," << t->data.age << "," << t->data.name << ">" << " ";
}

treeNode* BSTree::find(treeNode* t, int id)
{
	if (t == NULL)
		return NULL;
	else if (id < t->data.id)
		return find(t->leftChild, id);
	else if (id > t->data.id)
		return find(t->rightChild, id);
	else
		return t;
}

int main() {
	BSTree tree1;
	
	Student std[7] = { { 103, 19, "Wang" }, { 102, 22, "Lin" }, { 101, 20, "Tsai" }, { 104, 26, "Lee" }, { 106, 24, "Jack" }, { 105, 19, "Pass" }, {103, 25, "Huang"} };

	for (int i = 0; i < 7; ++i) {
		tree1.addNode(std[i]);
		
	}
	cout << "Preorder" << endl;
	tree1.displayPreorder();
	cout << "Inorder" << endl;
	tree1.displayInorder();
	cout << "Postorder" << endl;
	tree1.displayPostorder();
	
	
	tree1.deleteNode(103);
	
	cout << "After delete 103" << endl;
	cout << "Preorder" << endl;
	tree1.displayPreorder();
	cout << "Inorder" << endl;
	tree1.displayInorder();
	cout << "Postorder" << endl;
	tree1.displayPostorder();

	return 0;
}