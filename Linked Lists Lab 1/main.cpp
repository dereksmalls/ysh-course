//
//  main.cpp
//  YHS-Assignment c01-01
//
//  Created by ed p on 13/09/2013.
//  Copyright (c) 2013 ed p. All rights reserved.
//

//======================================================================================
// A SIMPLE PROGRAM THAT COLLECTS NAMES, ADDS THEM TO A DIRECTORY LISTING AND PRINTS OUT
//======================================================================================

#include <iostream>
#include <string>

using namespace std;

//Structure - the linked list node is a self referencing structure. Pointer always same data type.

struct People {
    string name;
    People *next;                 //self referencing pointer of type People called next
};

People *AddNode(People *root);      //add a node and return a pointer of the new node

/*
 Prints the list of nodes. Passes in the head value so that the loop can start from that point.
 void means it doesn't return anything.
 */

void Directory(People *root);

//main function

int main(int argc, const char * argv[])
{
    /*
     A pointer variable is declared to maintain the head of the list
     and initialized as NULL to tell the program that the list is empty.
     */
    People *head = NULL;
    
    char selection;
    
    //Print the list menu options to console - do/while 'q' is not entered.
    
    do{
        cout << "Add your name to the directory - type 'a'" << endl;
        cout << "View the directory - type 'v'" << endl;
        cout << "Type q to quit" << endl;
        cin >> selection;
        
        // Switch statement checks values submitted and runs expression
        
        switch(selection)
        {
            case 'a':
                head = AddNode(head);       // calls AddNode.
                break;
            case 'v':
                Directory(head);            // calls void Directory.
                break;
            case 'q':                       // quits the program.
                break;
        }
        
        // ...for as long as 'q' not entered.
        
        
    }while(selection!= 'q');
    
    // If 'q' entered then end program.
    
    return 0;
}
//========================================
//Function to add a new node to the list.
//========================================

People *AddNode(People *root)

//Two conditions - list is empty or list has data members.

{
    //Declaration of temporary variables.
    
    People *NextPtr = NULL;
    People *PrevPtr = NULL;
    
    //Checks to see if the list is empty. If list is not empty go to 'else'.
    
    if(root == NULL)
    {
        
        //Creates a new node of type People and passes the pointer back to root and compares root against NULL, if not NULL we can enter data.
        
        if((root = new People) != NULL)
        {
            
            NextPtr = root; //assign NextPtr root value.
            
            cout << "Enter your name: ";
            cin >> NextPtr->name;  //ask the user to give a value (dynamically = '->') and put data in node.
            
            NextPtr->next = NULL;   //Add the value of NULL in to the NextPtr.
        }
        return NextPtr;
    }
    //From 'if', runs if data is in the list
    else
    {
        //List has at least one data member.
        NextPtr = root;
        
        //While statement loops through list until it reaches the pointer that equals NULL - the end of the list.
        
        while (NextPtr->next != NULL)
        {
            NextPtr = NextPtr->next;
        }
        PrevPtr = NextPtr;          //stores last node address.
        
        if((NextPtr = new People) != NULL)
        {
            PrevPtr->next = NextPtr;
            
            cout << "Name:";
            cin >> NextPtr->name;               //get name input and add to node.
            
            NextPtr->next = NULL;               //Assign NULL to next.
        }
        return root;
    }
}
//==========================================================
// Void function to print the contents of the directory list
//==========================================================

void Directory(People *root)

{
    People *NextPtr;
    NextPtr = root;
    
    while(NextPtr != NULL)
    {
        cout << NextPtr->name << endl;
        NextPtr = NextPtr->next;
    }
}


