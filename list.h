#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#ifndef NODE
#define NODE
typedef struct node{
	void *data;
	struct node *next;
	struct node *prev;
}node;
#endif
#ifndef LIST
#define LIST
typedef struct list {
	node *front;
	node *back;
}list;
#endif
char printList(list *lst,void (printIt)(void *dt));
char validateNode(node *nd,list *lst);
char addFirst(void *dt,list *lst);
char addLast(void *dt,list *lst);
char addBeforeData(void *dt,void *dt2,list *lst,char (comp)(void *dt1,void *dt2));
char addAfterData(void *dt,void *dt2,list *lst,char (comp)(void *dt1,void *dt2));
char addBeforeNode(void *dt,node *nd,list *lst);
char addAfterNode(void *dt,node *nd,list *lst);
node * searchDataNode(void *dt,list *lst,char (comp)(void *dt1,void *dt2));
char deleteFirst(list *lst);
char deleteLast(list *lst);
char deleteBeforeData(void *dt2,list *lst,char (comp)(void *dt1,void *dt2));
char deleteAfterData(void *dt2,list *lst,char (comp)(void *dt1,void *dt2));
char deleteBeforeNode(node *nd,list *lst);
char deleteAfterNode(node *nd,list *lst);
char deleteNode(node *nd,list *lst);
char deleteData(void *dt,list *lst,char (comp)(void *dt1,void *dt2));
#endif
