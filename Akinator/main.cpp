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

enum questionModes
    {
    sign, 
    object, 
    game,
    askForSign,
    askForObject
    };

struct Node 
    {
    std::string data = "";
    
    Node* yes = nullptr;
    Node* no = nullptr;
    
    void initBranches()
        {
        yes = new Node;
        no = new Node;
        }
    
    };

class Akinator  
    {
    public:
        Akinator ( std::string baseElementTemp = "Cat" )
            {
//            save = saveTemp;
//            if ( save == true )
//                {
//                dataStorage = "";
//                }
                
            currentNode = root;
            baseElement = baseElementTemp;
            }
            
        void start()
            {
            init();
            }
    
    private:
        bool save = false;
//        std::string dataStorage = "";
        std::string currentAnswer = "";
        bool toContinue = true;
        
        std::string baseElement = "";
    
        Node* root = new Node;
        Node* currentNode = root;
        
        
        
        void init()
            {
            currentNode->data = baseElement;
        
            while ( toContinue )  
                {
                if ( ( currentNode->yes == nullptr ) && ( currentNode->no == nullptr ) )
                    {
                    if ( askQuestion ( object ) )
                        {
                        if ( askQuestion ( game ) )
                            {
                            currentNode = root;
                            }
                        else
                            {
                            return;
                            }
                        }
                    else
                        {
                        currentNode->initBranches();
                        
                        currentNode->no->data = currentNode->data;
                        currentNode->yes->data = askString ( askForObject );
        
                        currentNode->data = askString ( askForSign );
                        
                        if ( askQuestion ( game ) )
                            {
                            currentNode = root;
                            }
                        else
                            {
                            return;
                            }
                        }
                    }
                else
                    {
                    if ( askQuestion ( sign ) )
                        {
                        currentNode = currentNode->yes;
                        }
                    else
                        {
                        currentNode = currentNode->no;
                        }
                    }
                
                
                }
            
            
            }
            
//        void goThroughtTree()
//            {
//            
//            }
        
//        void init()
//            {
//            root->data = "Cat";
////            root->yes = new Node;
////            root->no = new Node;
////            
////            root->yes->data = "Dog";
////            root->no->data = "Cat";
////            
//            
//            
//            while ( toContinue )
//                {                
////                printf ( "It %s?", currentNode->data.c_str() );
////                scanf ( "%s", &currentAnswer );
//                
//                printf ( "It is %s?\n", currentNode->data.c_str() );
//                std::cin >> currentAnswer;
//                
//                if ( checkAnswer ( currentAnswer ) )
//                    {
//                    printf ( "Finished.\n" );
//                    toContinue = false;
//                    }
//                else
//                    {
//                    currentNode->no = new Node;
//                    currentNode->yes = new Node;
//                    
//                    printf ( "Who is it?\n" );
////                    scanf ( "%s", &currentAnswer );
//                    std::cin >> currentAnswer;
//                    
//                    currentNode->yes->data = currentAnswer;
//                    
//                    printf ( "What is difference between %s and %s?\n", currentNode->data.c_str(), currentAnswer.c_str() );
////                    scanf ( "%s", &difference );
//                    std::cin >> difference;
//                    
//                    currentNode->no->data = currentNode->data;
//                    currentNode->data = currentAnswer;
//                    
//                    exit();
//                    }
//                
//                }
//                
//            while ( currentNode->no != nullptr && currentNode->yes != nullptr )
//                    {
//                    printf ( "It is %s?\n", currentNode->data.c_str() );
////                    scanf ( "%s", &currentAnswer );
//                    std::cin >> currentAnswer;
//                    
//                    if ( checkAnswer ( currentAnswer ) )
//                        {
//                        currentNode = currentNode->yes;
//                        }
//                    else
//                        {
//                        currentNode = currentNode->no;
//                        }
//                    }
//                
//            }

        
            
        bool checkAnswer()
            {
            std::string currentAnswer = "";
            
            std::cin >> currentAnswer;
            
            if ( currentAnswer == "y" || currentAnswer == "yes" || currentAnswer == "1" )
                {
                return true;
                }
            else
                {
                return false;
                }
            }
            
        bool askQuestion ( int mode = object )
            {
            std::string currentData = currentNode->data.c_str();
            

            if ( mode == sign )
                {
                printf ( "Does it %s?\n", currentData.c_str() );
                return checkAnswer();
                }
            if ( mode == object )
                {
                printf ( "Is it %s?\n", currentData.c_str() );
                return checkAnswer();
                }
            if ( mode == game )
                {
                printf ( "Play again?\n" );
                return checkAnswer();
                }
                
            return false;
            }
            
        std::string askString ( int mode = askForSign )
            {
            std::string answer = "";
            
            if ( mode == askForSign )
                {
                std::string predicatedData = currentNode->data.c_str();
                std::string realData = currentNode->yes->data.c_str();
                
                printf ( "What are differents between %s and %s?\n", predicatedData.c_str(), realData.c_str() );
                
                std::cin >> answer;
                return answer;
                }
            
            if ( mode == askForObject )
                {
                printf ( "What is it?" );
                
                std::cin >> answer;
                return answer;
                }
            
            return "";
            }
            
        void exit()
            {
            std::cout << "Play again?\n";
            
            std::cin >> currentAnswer;
            if ( checkAnswer() )
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


