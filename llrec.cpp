#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if (head == NULL){
        //if the given head is null
        larger = NULL;
        
        smaller = NULL;
        return;
    }
    Node* n = head->next;
    //if it's smaller than the pivot num
    if(head->val <= pivot){
		
        smaller = head;
		
        smaller->next = NULL;
		
        head = NULL;
		llpivot(n, smaller->next, larger, pivot);
		
	}
    //if it's larger than the pivot num
	else{
		larger = head;
		
        larger->next = NULL;
		
        head = NULL;
		
        llpivot(n, smaller, larger->next, pivot);
		
	}
}
