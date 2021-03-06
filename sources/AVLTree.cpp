#include <iostream>
#include <vector>
#include <set>
 
namespace AVLTree 
{
    struct Node {
        int   data;
        Node* left;
        Node* right;
    };
} 
 
namespace AVLTree 
{
    class TREE
    { 
    public:
 
        bool CorrectFunction(std::vector<int> a)
        {
            std::set<int> b;
            for (int i=0; i<a.size();++i)
            b.insert(a[i]);
            return (b.size()==a.size());
        }
 
        int ChosenFunction ()
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
        }
    };
}
 
int main(int argc, char* argv[])
{ 
    AVLTree::TREE obj;    
    std::vector<int> a;
    int chosenValue ;
 
    for (int i=1; i<argc; i++)
        a.push_back(atoi(argv[i]));
    if (obj.CorrectFunction(a)==1)
        chosenValue=obj.ChosenFunction();
    else
    {
        std::cout<<"Не все значения уникальны"<<std::endl;
        chosenValue=8;
    }
    return 0;
}