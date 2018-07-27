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
        Akinator()
            {
//            save = saveTemp;
//            if ( save == true )
//                {
//                dataStorage = "";
//                }
                
            currentNode = root;
            }
            
        void start()
            {
            init();
            }
    
    private:
        bool save = false;
//        std::string dataStorage = "";
        std::string currentAnswer = "";
        std::string difference = "";
        bool toContinue = true;
    
        Node* root = new Node;
        Node* currentNode = nullptr;
        
        void init()
            {
            root->data = "Cat";
            
            
            
            
            while ( toContinue )
                {
                while ( currentNode->no != nullptr && currentNode->yes != nullptr )
                    {
                    printf ( "It is %s?\n", currentNode->data.c_str() );
//                    scanf ( "%s", &currentAnswer );
                    std::cin >> currentAnswer;
                    
                    if ( checkAnswer ( currentAnswer ) )
                        {
                        currentNode = currentNode->yes;
                        }
                    else
                        {
                        currentNode = currentNode->no;
                        }
                    }
                
//                printf ( "It %s?", currentNode->data.c_str() );
//                scanf ( "%s", &currentAnswer );
                
                if ( checkAnswer ( currentAnswer ) )
                    {
                    printf ( "Finished.\n" );
                    toContinue = false;
                    }
                else
                    {
                    currentNode->no = new Node;
                    currentNode->yes = new Node;
                    
                    printf ( "Who is it?\n" );
//                    scanf ( "%s", &currentAnswer );
                    std::cin >> currentAnswer;
                    
                    currentNode->yes->data = currentAnswer;
                    
                    printf ( "What is difference between %s and %s?\n", currentNode->data.c_str(), currentAnswer.c_str() );
//                    scanf ( "%s", &difference );
                    std::cin >> difference;
                    
                    currentNode->no->data = currentNode->data;
                    currentNode->data = currentAnswer;
                    
                    exit();
                    }
                
                }
            
            }
            
        bool checkAnswer ( std::string answer )
            {
            if ( currentAnswer == "y" || currentAnswer == "yes" || currentAnswer == "1" )
                {
                return true;
                }
            else
                {
                return false;
                }
            }
            
        void exit()
            {
            std::cout << "Play again?\n";
            
            std::cin >> currentAnswer;
            if ( checkAnswer ( currentAnswer ) )
                {
                currentNode = root;
                }
            else
                {
                toContinue = false;
                }
            
            }
        
        
    };


int main() 
    {
    Akinator game;
    game.start();
    
    return 0;
    }


