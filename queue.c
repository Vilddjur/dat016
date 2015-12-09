#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* Implementera interface från queue.h här */
QueuePtr new_queue(){ 						// Skapar en ny (tom) kö
  QueuePtr result = malloc(sizeof(struct QueueElement));
  if(result == NULL) return NULL;

  result->data = 0;
  result->prio = 0;
  result->next = NULL;

  return result;
}

int size(QueuePtr q){
  int size = 0;
  QueuePtr temp = q;
  while (temp->next) {
    size++;
    temp = temp->next;
  }
  return size;
}

void add(QueuePtr q, int prio, DataPtr d) {

  QueuePtr meow = q;

  QueuePtr res = malloc(sizeof(struct QueueElement));
  res->prio = prio;
  res->data = d;

  while(meow->next && prio <= (meow->next->prio)){
    meow = meow->next;
  }
  if(meow->next){
    QueuePtr nextAfter = meow->next;
    res->next = nextAfter;
    meow->next = res;
  }else{
    meow->next = res;
    res->next = 0;
  }
}

DataPtr get_first(QueuePtr q){
  if(!q->next) return NULL;
  return q->next->data;
}

void remove_first(QueuePtr q){
  QueuePtr first = q->next;
  if(first == NULL) return;
  q->next = q->next->next;
  free(first);
}
void clear(QueuePtr q){
  QueuePtr next, deleteMe;
  deleteMe = q; //HEAD
  while(deleteMe){
    next = deleteMe->next;
    free(deleteMe);
    deleteMe = next;
  }
  q->next = NULL;
}
void delete_queue(QueuePtr q){
  clear(q);
  free(q->next);
  free(q);
}
