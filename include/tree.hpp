#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

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
	bool insert(int value);
	bool exists(int value);
	bool remove(int value);
	void makeOutput(Node *root);
	bool save(std::string path);
	bool load(std::string path);
	void print(std::string order);
	bool fileExist(std::string path);
	void show(); //	auto friend operator<<(ostream& stream, const Tree&) -> ostream& stream;
	//	auto operator=(const Tree&) -> Tree&;
	//	auto operator=(Tree&&) -> Tree&;

	~Tree();

  private:
	bool insert(Node *&root, int value);
	void print(std::string order, Node *root);
	Node *remove(Node *&root, int value);
	Node *getMin(Node *&node);
	bool exists(Node *&root, int value);
	void showTree(Node *root, int size);
	Node *clear(Node *&currNode);

	Node *root;
	std::string output;
	std::vector<int> treeVector;
};

class TUI
{
  public:
	std::vector<int> CorrectFunction(std::vector<int> a);
	int ChosenFunction();
	void MakeDecisionTree(int chosenValue, Tree *tree);
	void outStars();
};
}
