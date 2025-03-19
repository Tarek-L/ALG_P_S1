#include <stdio.h>
#include <stdlib.h>

typedef struct node {

  int data;
  struct node *next;

} node;

void insertNewNode(node **head, int value){

  node *newNode = malloc(sizeof(node));

  if (newNode == NULL) {
    printf("allocation failed\n");
    return ;
  }
  else {
    newNode -> next = NULL;
    newNode -> data = value;
  }

  if (*head == NULL) {
    *head = newNode;
    return ;
  }

  node *pList = *head;

  while (pList -> next != NULL) {
    pList = pList -> next;
  }

  pList -> next = newNode;

}

void printList(node *head){

  node *pList = head;

  while (pList != NULL) {

    printf("| %d |",pList -> data);
    pList = pList -> next;

  }

  printf("\n");

}

node* createList(){

  int val;
  char end = 'n';
  node* head = NULL;

  while (end != 'y') {

    printf("insert a value : \n");
    scanf("%d",&val);
    insertNewNode(&head,val);

    printf("are you finished [ y / n ]\n");

    do {
      scanf("%c",&end);
    } while (end != 'y' && end != 'n');

  }

  return head;

}

int listLength(node **head){

  if (*head == NULL) {
    return 0;
  }

  node *pList = *head;
  int length = 1;

  while (pList -> next != NULL) {
    
    length ++;
    pList = pList -> next;

  }

  return length;

}

int mostOccurrences(node **head){

  if (*head == NULL) {
    return -1;
  }

  int most_occurrences = -1, most_occurred_element;
  node *pList1 = *head, *pList2 = NULL;

  while (pList1 -> next != NULL) {
    
    int occurrence_counter = 1; 
    pList2 = pList1;

    while (pList2 -> next != NULL) {

      pList2 = pList2 -> next;

      if (pList2 -> data == pList1 -> data) {
        occurrence_counter ++;
      }
    }

    if (occurrence_counter > most_occurrences) {
      most_occurrences = occurrence_counter;
      most_occurred_element = pList1 -> data;
    }

    pList1 = pList1 -> next;

  }
  
  return most_occurred_element;

}

node* accessByVal(node **head, int value){

  if (*head == NULL) {
    return NULL;
  }

  node *pList = *head;

  while (pList != NULL && pList -> data != value) {
    pList = pList -> next;
  }

  return pList;

}

node* accessByPosition(node **head, int position){

  if (*head == NULL) {
    return NULL;
  }

  node *pList = *head;

  for (int i = 0; pList != NULL && i < position; i++) {
    pList = pList -> next;
  }

  return pList;

}

void deleteByValue(node **head, int value){

  if (*head == NULL) {
    return ;
  }

  node *pList = *head, *tmp = NULL;

  while (pList -> next != NULL && (pList -> next) -> data != value) {
    pList = pList -> next;
  }

  tmp = pList -> next;
  pList -> next = (pList -> next) -> next;

  free(tmp);

}

void deleteByPosition(node **head, int position){

  if (*head == NULL) {
    return ;
  }

  node *tmp1 = accessByPosition(head, position - 1), *tmp2 = accessByPosition(head, position);

  tmp1 -> next = tmp2 -> next;

  free(tmp2);

}

void swapNode (node *element1, node *element2){

  int temp = element1 -> data;

  element1 -> data = element2 -> data;

  element2 -> data = temp;

}

void selection_sort_llist(node **head){

  if (*head == NULL) {
    return ;
  }

  node *pList1 = *head, *pList2 = NULL, *min = NULL;

  while (pList1 != NULL) {

    pList2 = pList1;
    min = pList1;

    while (pList2 != NULL) {

      if (pList2 -> data < min -> data) {
        min = pList2;
      }

      pList2 = pList2 -> next;
    }

    swapNode(pList1, min);

    pList1 = pList1 -> next;

  }

}

int main(int argc, char *argv[])
{

  node *head = NULL;

  for (int i = 0; i < 6; i++) {
    insertNewNode(&head,9);
  }
  for (int i = 0; i < 9; i++) {
    insertNewNode(&head,2);
  }
  for (int i = 0; i < 11; i++) {
    insertNewNode(&head,4);
  }
  for (int i = 0; i < 3; i++) {
    insertNewNode(&head,3);
  }

  printList(head);
  printf("length = %d\n",listLength(&head));
  printf("most Occurrences = %d\n",mostOccurrences(&head));

  selection_sort_llist(&head);
  printList(head);

  free(head);

  return 0;
}












