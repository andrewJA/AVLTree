#include <tree.hpp>
namespace AVLTree 
{
    struct Node 
	{ 
        Node(int value){
	        this->data = value;
	        this->left = NULL;
	        this->right = NULL;
	    }
        int   data;
        Node* left;
        Node* right;
	};


       
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


    int TUI::ChosenFunction () {
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

	void TUI::MakeDecision(int chosenValue, std::vector<int> a)
	{
        Tree tree(a);
		switch(chosenValue)
		{
			case 1:
			{
				tree.show();
				break;
			}
			case 2:
			{
				std::string choseOrder;
				std::cout<<"a. Прямой обход"<<std::endl;
        		        std::cout<<"b. Поперечный обход"<<std::endl;
                		std::cout<<"c. Обратный обход"<<std::endl;
                		std::cin >> choseOrder;
				if (choseOrder == "a")
					tree.print("pre");
				else if (choseOrder == "b")
					tree.print("in");
				else if (choseOrder == "c")
					tree.print("post");

				break;
			}
			default:
			{
				std::cout<<"Error"<<std::endl;
				break;
			}
		}
	}
	
	Tree::Tree(){};

    Tree::Tree(std::vector<int> treeList){
        for (int i = 0; i<treeList.size(); ++i){
             this->treeVector.push_back(treeList[i]);       
        }
        this->root = NULL;
    	std::for_each(treeList.begin(), treeList.end(), [&](int const& val){
    		 this->insert(this->root, val);
    	})  ; 
    };

    Tree::Tree(std::initializer_list<int> list){
    		    this->root = NULL;
    		    std::for_each(list.begin(), list.end(), [&](int const& val){
    		        this->insert(this->root, val);
    		    })  ; 
    		};

    Tree::~Tree(){ };
	
	    bool Tree::insert(Node* &root, int value)
		    {
    		    if (root == NULL)
    		        root = new Node(value);
    		    else if (value < root->data)
    		        insert(root->left, value);
    		    else 
    		        insert(root->right, value);
    		    return true;
    		}
    
    void Tree::print(std::string order, Node* root ){
 
    	            if (order == "pre")
    	                if ( root != NULL ) { 
                            std::cout << root->data << " ";      
                            print( order, root->left );    
                            print( order, root->right );   
                        }
 
                    if (order == "in")
                        if ( root != NULL ) 
			{  
                            print( order, root->left );    
                            std::cout << root->data << " ";   
                            print( order, root->right );   
                        }
 
                    if (order == "post")
                        if ( root != NULL ) 
			{  
                            print( order, root->left );    
                            print( order, root->right );   
                            std::cout << root->data << " ";   
                        }
     	    }
 
    	    void Tree::print(std::string order){
    	        print(order, this->root);
    	    }	

		int Tree:: size(Node* root, int counter){
    	        if (root->right != NULL) {
    	            ++counter;
    	            counter = size(root->right, counter);
    	        }
    	        return counter;
    	    }
		 int Tree::rightSize(){
    	        int counter = 1;
    	        return size(this->root, counter);
    	    }
	void Tree::showTree(Node* root, int size)
        {
            if( root == nullptr ) return;
		    showTree( root->right, size + 1 );
		    for( int i = 0; i < size; ++i ) std::cout << "   ";
		    if (size != 0 )	std::cout << "   ";
		    std::cout  << root->data << std::endl;
		    showTree( root->left, size + 1 );
        }

	
		
		void Tree::show()
		{
    		int sizeTree = this->rightSize();
    		this->showTree(this->root, sizeTree);
    	}
}
