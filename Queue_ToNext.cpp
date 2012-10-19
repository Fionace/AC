#include"Queue_ToNext.h"

void InitQueue(LinkQueue *L)
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
     L->front=s;
     s->current="";
     s->index=255;
     s->next=NULL;
     L->rear=s;
     L->count=0;
    return;
}

bool EnQueue(LinkQueue *L,string curr,int ind)
{
   QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
   if(!s)
      return -1;
   s->current=curr;
   s->index=ind;
   s->next=NULL;
   L->rear.next=s;
   L->rear=s;
  L->count++;
   return true;
}
bool DelQueue(LinkQueue *L,string *a,int &ind)
{
     if(L->front=L->rear)
         return false;

      QueuePtr p=L->front->next;
     L->front->next=p->next;
     a=p->current;
     ind=p->index;
     free(p);
     L->count--;
     return true;
      
}
