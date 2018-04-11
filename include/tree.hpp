#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

namespace AVLTree
{
struct Node;

//enum class traversal_order {pre, in, post};
class Tree
{
public:
	Tree();
	Tree(std::vector<int> treeList);
	Tree(std::initializer_list<int> list);
	//	Tree(const Tree& tree);
	//	Tree(Tree&& tree);
	void insert(int value);
	//	bool exists(int value);
	//	bool remove(int value);
	//	bool save(const string& path);
	//	bool load(const string& path);
	void print(std::string order, Node *root);
	void print(std::string order);
	void show(); //	auto friend operator<<(ostream& stream, const Tree&) -> ostream& stream;
	//	auto operator=(const Tree&) -> Tree&;
	//	auto operator=(Tree&&) -> Tree&;

	~Tree();

private:
	int size(Node *root, int counter);
	bool insert(Node *&root, int value);
	int rightSize();
	void showTree(Node *root, int size);

	Node *root;

	std::vector<int> treeVector;
};

class TUI
{
public:
	std::vector<int> CorrectFunction(std::vector<int> a);
	int ChosenFunction();
	void MakeDecisionTree(int chosenValue, Tree *tree);
};
}
