
#include <tree.hpp>

using namespace AVLTree;

int main(int argc, char* argv[])
{ 
    AVLTree::TUI obj;    
    std::vector<int> a;
    int chosenValue ;

    for (int i=1; i<argc; i++) a.push_back(atoi(argv[i]));
        
    a = obj.CorrectFunction(a);
    // for_each(a.begin(), a.end(), [&a](int const& i){ std::cout << i << " "; });//для проверки 
    chosenValue=obj.ChosenFunction();
}

