//
//  main.cpp
//  Akinator
//
//  Created by Эльдар Дамиров on 01.07.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <string>
#include "fileIO.h"

struct Node 
    {
    std::string data = "";
    
    Node* yes = nullptr;
    Node* no = nullptr;
    };

class Akinator  
    {
    public:
        Akinator ( bool saveTemp )
            {
            save = saveTemp;
            if ( save == true )
                {
                dataStorage = "";
                }
                
            currentNode = root;
            }
            
        void start()
            {
            init();
            }
    
    private:
        bool save = false;
        std::string dataStorage = NULL;
    
        Node* root = nullptr;
        Node* currentNode = nullptr;
        
        void init()
            {
            bool toContinue = false;
            
            while ( toContinue )
                {
                while ( currentNode->no != nullptr && currentNode->yes != nullptr )
                    {
                    printf ( "It %s?", currentNode->data.c_str() );
                    }
                }
            
            }
        
        
    };


int main() 
    {
    
    
    return 0;
    }


