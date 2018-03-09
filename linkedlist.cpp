/* The following code shows an example of a linked list and how
to traverse it.  Based on sample approach described in Chapter 2
of Data Structures, Algorithms and Software Principles in C by
Thomas Standish */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

//Use the standard namespace
using namespace std;


//Main function
int main (void) {


// creates representation for 3 character airport codes
// Need one extra element to make room for the NULL character
// at the end of the character sequence, which indicates the
// end of the string.
typedef char AirportCode[4];


// structure type for list nodes, called Node.
// It's illegal for a struct to contain itself as a member BUT
// it's ok to have a MEMBER of the struct be a pointer to structs of
// the same type, which is why Node is used.
struct Node {

AirportCode Airport; // component with airport code data.
struct Node *Link; // component with pointer to the next Node
};


//Create three Node pointers for the linked list.
//The first node, a node to be insterted and a temporary node
//used to add nodes to the end of the list.
Node *First, *Inserted, *temp;


// Create a pointer to a new node, first.
First = new Node;

//In First node's airport member, place "YYZ" airport code.
strcpy(First->Airport, "YYZ");

//Assign first node's internal pointer to the next node to the temp Node pointer.
First->Link=NULL; // Assign the internal pointer of first node to NULL.


//Create and initialize a new temporary Node.
temp=new Node;
strcpy(temp->Airport, "PAR");

//Have the internal next pointer in the first node point to this new temporary node
//structure that is currently in memory.
First->Link = temp;

//Create another new temporary node in a different memory block and initialize.
temp= new Node;
strcpy(temp->Airport, "ZRH");

//Assign the internal next pointer of the 2nd node to poin to this new 3rd temporary node.
First->Link->Link = temp;

//Make sure that the internal next pointer of the last node (currently temp) is pointed to NULL.
temp->Link = NULL;


// insert second node after the first node
//Create this new 2nd node in memory and initialize its data.
Inserted=new Node;
strcpy(Inserted->Airport, "BRU");

//The next pointer in this new added 2nd element is initialized to the memory
//location that First->Link points to.
Inserted->Link = First->Link;

//Finally, the next pointer in the first node should point to
//this inserted second node.
First->Link = Inserted;

//Create a new node to traverse all the other nodes in the list.
Node *conductor;

//Set the traversing node to the first node.
conductor = First;

//Traverse each node in the list and print out the airport value in each node
//one at a time.
while ( conductor != NULL ) {
    cout << "Airport: " << conductor->Airport << endl;
    conductor = conductor->Link;
}


return 0;
}
