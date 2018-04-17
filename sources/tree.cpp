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

	~Node()
	{
		delete left;
		delete right;
	}

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
			tree->print("pre");
		else if (choseOrder == "b")
			tree->print("in");
		else if (choseOrder == "c")
			tree->print("post");
		else
		{
			std::cout << "Неверный входной символ";
		}

		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 3:
	{
		int insertValue;
		std::cout << "Введите значение для нового узла:"
				  << " ";
		std::cin >> insertValue;
		bool isInsert = tree->insert(insertValue);
		if (!isInsert)
		{
			std::cout << "Узел уже существует в дереве" << std::endl;
		}
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 7:
	{
		int searchValue;
		std::cout << "Введите значение для поиска:"
				  << " ";
		std::cin >> searchValue;
		std::cout << std::endl;
		bool isExist = tree->exists(searchValue);
		if (isExist)
		{
			std::cout << "Узел найден 💃" << std::endl;
		}
		else
		{
			std::cout << "Узел не найден 🙇‍" << std::endl;
		}
		int chosenValue = this->ChosenFunction();
		this->MakeDecisionTree(chosenValue, tree);
		break;
	}
	case 8:
	{
		std::cout << "Вы уверены, что хотите выйти из программы ? (Да|Нет)" << std::endl;
		std::string answer;
		std::cin >> answer;
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		if (answer == "да" || answer == "Да" || answer == "yes")
		{
			std::cout << "Quit!" << std::endl;
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
		std::cout << "Error" << std::endl;
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
	delete root;
	//delete treeVector;
};

//вставка в дерево (приватная функция)
bool Tree::insert(Node *&root, int value)
{
	if (root == nullptr)
		root = new Node(value);
	else if (value < root->data)
		insert(root->left, value);
	else
		insert(root->right, value);
	return true;
}

// вставка значения (вызов из вне)
bool Tree::insert(int value)
{
	bool isExist = exists(value);
	if (isExist)
		return false;
	return this->insert(this->root, value);
}

//удаление узла из дерева (приватная функция)
// bool Tree::remove(Node *&root, int value)
// {

// }
//удаление (глобальная)
// bool Tree::remove(int value)
// {
// 	this->deleteNode(this->root, value);
// }

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
	this->exists(this->root, value);
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

//размер правой ветки
int Tree::size(Node *root, int counter)
{
	if (root->right != nullptr)
	{
		++counter;
		counter = size(root->right, counter);
	}
	return counter;
}

int Tree::rightSize()
{
	int counter = 1;
	return size(this->root, counter);
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
}
