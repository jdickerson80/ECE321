#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>


/* Doubly linked lists */

typedef struct DListNode_tag {
   int data;
   struct DListNode_tag * next;
   struct DListNode_tag * prev;
} DListNode;


/* Type dlist */

typedef struct {
   DListNode * first;
   DListNode * last;
} dlist;


/* Empty list */

const dlist dlistEmpty = { NULL, NULL };


/* Check if a list is empty */

int dlistIsEmpty (dlist l)
{
   return l.first == NULL;
}


/* Insert as last */

void dlistInsertLast (dlist * lp, int t)
{
   DListNode * n = (DListNode *) malloc(sizeof(DListNode));

   /* Check if malloc succeeded */
      
   if (n == NULL) {
      fprintf(stderr, "Out of memory\n");
      exit(1);
   }

   /* Copy the data */

   n->data = t;

   /* If the list was empty, insert just this element */ 

   if (lp->first == NULL) {
      n->prev = n->next = NULL;
      lp->first = lp->last = n;
   }

   /* Else, insert as last element */
   
   else {
      n->prev = lp->last;
      n->next = NULL;
      lp->last->next = n;
      lp->last = n;
   }
}


/* Declare any other function that you might need */






/* Main program */

int main ()
{
   FILE * fin, * fout;
   dlist l = dlistEmpty;

//put your code here


}
