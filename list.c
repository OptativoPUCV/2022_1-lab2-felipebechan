#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
  Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *lista = (List *) calloc(1,sizeof(List));
    lista -> head = NULL;
    lista -> tail = NULL;
    lista -> current = NULL;
    return lista;
}

void * firstList(List * list) {
    //
     if(list->head && list->head->data){
        list->current = list->head;
        return list->head->data;
    }
    //
    return NULL;
}

void * nextList(List * list) {
    //
    if(list->current && list->current->next){
        list->current = list->current->next;
        return list->current->data;
    }
    //
    return NULL;
}

void * lastList(List * list) {
    //
    if(list->tail && list->tail->data){
        list->current = list->tail;
        return list->tail->data;
      //
    }
    return NULL;
}

void * prevList(List * list) {
    //
    if( list->current && list->current->prev){
        list->current = list->current->prev;
        return list->current->data;
    }
    //
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *node = createNode(data);
    //node->next = list->head;
    //list->tail = node;
    if (list->head == NULL){
        list->head = node;
        list->tail = list->head;
        }
    else if(list->head != NULL){
    list->head->prev = node;
       node->next = list->head;
       list->head = node;
    }

}

void pushBack(List * list, void * data) {

    list->current = list->tail;
    pushCurrent(list,data );

}

void pushCurrent(List * list, void * data) {
    Node *node = createNode(data);
    if(list != NULL){
     
      if(list->current == list->tail){

        list->current->next = node;
        node->prev = list->current;
        list->tail = node;

      }
      else{

        node->next = list->current->next;
        list->current->next->prev = node;
        node->prev = list->current;
        list->current->next = node;

      }
    }
    else{
     list->head = node;
     list->tail = node;
    }
    }


void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    //
    //
     if(list->current->next != NULL){
        list->current->next->prev = list->current->prev;
    }
    else{
        list->current->prev->next = NULL;
        list->tail = list->current->prev;
        
    } 
    //
    if( list->current->prev != NULL ){
        list->current->prev->next = list->current->next;
        return list->current->data;
    }
    else {
        list->head = list->current->next;
        return list->current->data;
    }
    //
    return list->current->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}