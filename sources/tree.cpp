#include <tree.hpp>

namespace AVLTree
{
    struct Node {
        int   data;
        Node* left;
        Node* right;
    };
    
    std::vector<int> TUI::CorrectFunction(std::vector<int> a)
    {
        std::set<int> b;
        for (int i=0; i<a.size();++i)
        b.insert(a[i]);
        if (b.size()==a.size()) {
            return a;
        } 
        else {
            a.clear();
            std::for_each(b.begin(), b.end(), [&a](int const& n){ a.push_back(n); });  
            return a;          
        }
    };

    int TUI::ChosenFunction ()
    {
        int chosenValue;
        std::cout<<"Выберите одну из операций:"<<std::endl;
        std::cout<<"1. Вывести дерево на экран"<<std::endl;
        std::cout<<"2. Вывести список узлов дерева" <<std::endl;
        std::cout<<"3. Добавить узел в дерево"<<std::endl;
        std::cout<<"4. Удалить узел из дерева"<<std::endl;
        std::cout<<"5. Сохранить дерево в файл"<<std::endl;
        std::cout<<"6. Загрузить дерево из файла"<<std::endl;
        std::cout<<"7. Проверить наличие узла"<<std::endl;
        std::cout<<"8. Завершить работу программы"<<std::endl;
        std::cin >> chosenValue;
        return chosenValue;
    };
}

