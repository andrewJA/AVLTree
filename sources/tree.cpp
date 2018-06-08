#include <tree.hpp>

namespace AVLTree
{

//паблик класс узел
struct Node
{
	Node(int value)
	{
		this->data = value;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node() {}

	int data;
	Node *left;
	Node *right;
};

//функция, убирающая повторяющиеся значения
std::vector<int> TUI::CorrectFunction(std::vector<int> a)
{
	std::vector<int> uniques;
	for (int value : a)
	{
		if (std::find(uniques.begin(), uniques.end(), value) == uniques.end())
			uniques.push_back(value);
	}

	return uniques;
};

//вывод информации по взаимодействию
int TUI::ChosenFunction()
{
	int chosenValue;
	std::cout << "Выберите одну из операций:" << std::endl;
	std::cout << "1. Вывести дерево на экран" << std::endl;
	std::cout << "2. Вывести список узлов дерева" << std::endl;
	std::cout << "3. Добавить узел в дерево" << std::endl;
	std::cout << "4. Удалить узел из дерева" << std::endl;
	std::cout << "5. Сохранить дерево в файл" << std::endl;
	std::cout << "6. Загрузить дерево из файла" << std::endl;
	std::cout << "7. Проверить наличие узла" << std::endl;
	std::cout << "8. Завершить работу программы" << std::endl;
	std::cin >> chosenValue;
	return chosenValue;
}

void TUI::outStars()
{
	std::cout << "******************" << std::endl;
}

//взаимодействие с пользователем
void TUI::MakeDecisionTree(int chosenValue, Tree *tree)
{
	switch (chosenValue)
	{
	case 1:
	{
		tree->show();

		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 2:
	{
		std::string choseOrder;
		std::cout << "a. Прямой обход" << std::endl;
		std::cout << "b. Поперечный обход" << std::endl;
		std::cout << "c. Обратный обход" << std::endl;
		std::cin >> choseOrder;
		if (choseOrder == "a")
		{
			outStars();
			tree->print("pre");
			outStars();
		}
		else if (choseOrder == "b")
		{
			outStars();
			tree->print("in");
			outStars();
		}
		else if (choseOrder == "c")
		{
			outStars();
			tree->print("post");
			outStars();
		}
		else
		{
			outStars();
			std::cout << "Неверный входной символ";
			outStars();
		}

		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 3:
	{
		int insertValue;
		outStars();
		std::cout << "Введите значение для нового узла:"
				  << " ";
		std::cin >> insertValue;
		outStars();
		bool isInsert = tree->insert(insertValue);
		if (!isInsert)
		{
			outStars();
			std::cout << "Узел уже существует в дереве" << std::endl;
			outStars();
		}
		else
		{
			outStars();
			std::cout << "Узел успешно добавлен!" << std::endl;
			outStars();
		}
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 4:
	{
		int removeValue;
		outStars();
		std::cout << "Введите значение для удаляемого узла:"
				  << " ";
		std::cin >> removeValue;
		outStars();
		bool isDelete = tree->remove(removeValue);
		if (!isDelete)
		{
			outStars();
			std::cout << "Узел не был найден в дереве" << std::endl;
			outStars();
		}
		else
		{
			outStars();
			std::cout << "Узел был успещно удален" << std::endl;
			outStars();
		}
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 5:
	{
		tree->save("");
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 6:
	{
		tree->load("");
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 7:
	{
		int searchValue;
		outStars();
		std::cout << "Введите значение для поиска:"
				  << " ";
		std::cin >> searchValue;
		outStars();
		bool isExist = tree->exists(searchValue);
		if (isExist)
		{
			outStars();
			std::cout << "Узел найден 💃" << std::endl;
			outStars();
		}
		else
		{
			outStars();
			std::cout << "Узел не найден 🙇‍" << std::endl;
			outStars();
		}
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 8:
	{
		outStars();
		std::cout << "Вы уверены, что хотите выйти из программы ? (Да|Нет)" << std::endl;
		std::string answer;
		std::cin >> answer;
		outStars();
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		if (answer == "да" || answer == "Да" || answer == "yes")
		{
			outStars();
			std::cout << "Quit!" << std::endl;
			outStars();
			return;
		}
		else
		{
			int chosenValue = this->ChosenFunction();
			this->MakeDecisionTree(chosenValue, tree);
		}
		break;
	}
	default:
	{
		outStars();
		std::cout << "Error" << std::endl;
		outStars();
		break;
	}
	}
}

//конструктор по умолчанию
Tree::Tree(){};

//конструктор через вектор
Tree::Tree(std::vector<int> treeList)
{
	for (int i = 0; i < treeList.size(); ++i)
	{
		this->treeVector.push_back(treeList[i]);
	}
	this->root = nullptr;
	std::for_each(treeList.begin(), treeList.end(), [&](int const &val) {
		this->insert(this->root, val);
	});
};

//конструктор через входной список { 1,2,... }
Tree::Tree(std::initializer_list<int> list)
{
	this->root = nullptr;
	std::for_each(list.begin(), list.end(), [&](int const &val) {
		this->insert(this->root, val);
	});
};

//деструктор
Tree::~Tree()
{
	clear(root);
	//delete treeVector;
};

//вставка в дерево (приватная функция)
bool Tree::insert(Node *&root, int value)
{
	if (root == nullptr)
		root = new Node(value);
	else if (value < root->data)
	{
		this->insert(root->left, value);
	}
	else
	{
		this->insert(root->right, value);
	}
	return true;
}

// вставка значения (вызов из вне)
bool Tree::insert(int value)
{
	if (this->exists(value))
		return false;
	return this->insert(root, value);
}

Node *Tree::getMin(Node *&root)
{
	if (root == nullptr)
	{
		return root;
	}
	if (root->left == nullptr)
	{
		return root;
	}
	else
	{
		return getMin(root->left);
	}
}

//удаление узла из дерева (приватная функция)
Node *Tree::remove(Node *&root, int value)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (value == root->data)
	{
		if (root->left != nullptr && root->right != nullptr)
		{
			//Find Minimum from Right Tree OR find Maximum from Left Tree.
			root->data = this->getMin(root->right)->data;
			root->right = remove(root->right, root->data);
		}
		else if (root->left == nullptr)
		{
			return root->right;
		}
		else
		{
			return root->left;
		}
	}
	else if (value > root->data)
	{
		root->right = remove(root->right, value);
	}
	else
	{
		root->left = remove(root->left, value);
	}
	return root;
}

//удаление (глобальная)
bool Tree::remove(int value)
{
	Node *deletedNode = this->remove(this->root, value);
	std::cout << deletedNode->data << std::endl;
	if (deletedNode == nullptr)
		return false;
	else
		return true;
}

Node *Tree::clear(Node *&currNode)
{
	if (currNode == nullptr)
	{
		return nullptr;
	}
	else
	{
		this->clear(currNode->left);
		this->clear(currNode->right);
		delete currNode;
	}
	return nullptr;
}

//поиск узла в дереве (приватная функция)
bool Tree::exists(Node *&root, int value)
{
	if (root->data == value)
	{
		return true;
	}
	else if ((root->data > value) && (root->left != nullptr))
	{
		return exists(root->left, value);
	}
	else if ((root->data < value) && (root->right != nullptr))
	{
		return exists(root->right, value);
	}
	else
	{
		return false;
	}
}

//поиск (глобальная)
bool Tree::exists(int value)
{
	return this->exists(this->root, value);
}

//вывод дерева в различных прядках (III этап) (private)
void Tree::print(std::string order, Node *root)
{
	if (order == "pre")
	{
		if (root != nullptr)
		{
			std::cout << root->data << " ";
			print(order, root->left);
			print(order, root->right);
		}
	}

	if (order == "in")
	{
		if (root != nullptr)
		{
			print(order, root->left);
			std::cout << root->data << " ";
			print(order, root->right);
		}
	}

	if (order == "post")
	{
		if (root != nullptr)
		{
			print(order, root->left);
			print(order, root->right);
			std::cout << root->data << " ";
		}
	}
}

//вывод дерева в различных прядках (III этап) (public)
void Tree::print(std::string order)
{
	if (this->root == nullptr)
	{
		std::cout << "Дерево пусто" << std::endl;
		return;
	}
	print(order, this->root);
	std::cout << "\n";
}

//вывод дерева на экран (private)
void Tree::showTree(Node *root, int size)
{
	if (root == nullptr)
		return;
	showTree(root->right, size + 1);
	for (int i = 0; i < size; ++i)
		std::cout << " --";
	if (size != 0)
		std::cout << " --";
	std::cout << root->data << std::endl;
	showTree(root->left, size + 1);
}

// вывод дерева на экран (public)
void Tree::show()
{
	int sizeTree = 2;
	if (this->root == nullptr)
	{
		std::cout << "Дерево пусто" << std::endl;
	}
	else
	{
		this->showTree(this->root, sizeTree);
	}
}

void Tree::makeOutput(Node *root)
{
	if (root != nullptr)
	{
		this->output = this->output + std::to_string(root->data) + " ";
		makeOutput(root->left);
		makeOutput(root->right);
	}
}

//с параметром path
bool Tree::save(std::string input_path)
{
	std::string path = input_path;
	if (path == "")
	{
		std::cout << "Введите путь к файлу" << std::endl;
		std::cin >> path;
	}

	std::ofstream file;
	std::ifstream filecheck;
	filecheck.open(path);

	if (!filecheck)
	{
		file.open(path);
		this->output = "";
		this->makeOutput(this->root);
		file << this->output;
		file.close();
		std::cout << "Сообщение было успешно сохранено" << std::endl;
	}
	else
	{
		file.open(path);
		this->output = "";
		this->makeOutput(this->root);
		file << this->output;
		file.close();
		std::cout << "Сообщение было успешно сохранено" << std::endl;
		filecheck.close();
	}
	return true;
}

bool Tree::load(std::string input_path)
{
	std::string path = input_path;
	if (path == "")
	{
		std::cout << "Введите путь к файлу" << std::endl;
		std::cin >> path;
	}

	std::ifstream file;
	file.open(path);
	if (!file)
	{
		std::cout << "Файл c заданным путем не существует" << std::endl;
		return false;
	}
	else
	{
		if (root != nullptr)
			clear(root);

		int element;
		while (file >> element)
		{
			this->insert(root, element);
		}
		std::cout << "Файл успешно считан" << std::endl;
		return true;
	}
}

//есть ли файл
bool Tree::fileExist(std::string path)
{
	std::ifstream file(path);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}
}
