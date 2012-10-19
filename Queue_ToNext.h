#ifndef QUEUE_TONEXT_H
#define QUEUE_TONEXT_H

#include<iostream>
#include<string>
//#include""
using namespace std;

typedef struct QNode
{
    string  current;
    int index;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
   QueuePtr front;
   QueuePtr rear;
  int count;
}LinkQueue;

void InitQueue (LinkQueue *L);
bool EnQueue(LinkQueue *L,string curr,int ind);
bool DelQueue(LinkQueue *L,string *a,int &ind);

#endif //QUEUE_TONEXT_H
