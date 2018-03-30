#include <tree.hpp>

using namespace AVLTree;

int main(int argc, char* argv[])
{ 
	TUI obj;    
    	std::vector<int> a;
    	int chosenValue ;
	//Tree tree = {3,4,2,6,5,7};

    	for (int i=1; i<argc; i++)
        	a.push_back(atoi(argv[i]));

    	a=obj.CorrectFunction(a);
  
        chosenValue=obj.ChosenFunction();
	obj.MakeDecision(chosenValue, a);	
}
