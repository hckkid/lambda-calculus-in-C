#include "list.h"
char printList(list *lst,void (printIt)(void *dt))
{
	node *tracker;
	if(lst==NULL)
		return '1';
	else if (lst->front==NULL || lst->back==NULL)
		return '2';
	else
	{
		tracker=lst->front;
		while(tracker != NULL )
		{
			printIt(tracker->data);
			tracker=tracker->next;
		}
	}
	return '0';
}
node * searchDataNode(void *dt,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tracker;
	if(lst==NULL)
		return NULL;
	else if (lst->front==NULL || lst->back==NULL)
		return NULL;
	else
	{
		tracker=lst->front;
		while(tracker != NULL )
		{
			if(comp(dt,tracker->data)=='1')
			{
				return tracker;
			}
			tracker=tracker->next;
		}
	}
	return NULL;
}
char validateNode(node *nd,list *lst)
{
	node *tracker;
	if(lst==NULL)
		return '1';
	else if (lst->front==NULL || lst->back==NULL)
		return '2';
	else
	{
		tracker=lst->front;
		while(tracker != NULL )
		{
			if(tracker==nd)
			{
				return '1';
			}
			tracker=tracker->next;
		}
	}
	return '0';
}
char addFirst(void *dt,list *lst)
{
	node *nw=(node*)malloc(sizeof(node));
	nw->data=dt;
	if(lst==NULL)
	{
		free(nw);
		return '1';
	}
	else if(lst->front==NULL || lst->back==NULL)
	{
		nw->next=NULL;
		nw->prev=NULL;
		lst->front=nw;
		lst->back=nw;
	}
	else if(lst->front==lst->back)
	{
		nw->next=lst->front;
		nw->prev=NULL;
		lst->front->prev=nw;
		lst->front=nw;
	}
	else
	{
		nw->next=lst->front;
		lst->front->prev=nw;
		lst->front=nw;
	}
	return '0';
}
char addLast(void *dt,list *lst)
{
	node *nw=(node*)malloc(sizeof(node));
	nw->data=dt;
	if(lst==NULL)
	{
		free(nw);
		return '1';
	}
	else if(lst->front==NULL || lst->back==NULL)
	{
		nw->next=NULL;
		nw->prev=NULL;
		lst->front=nw;
		lst->back=nw;
	}
	else if(lst->front==lst->back)
	{
		nw->prev=lst->back;
		nw->next=NULL;
		lst->back->next=nw;
		lst->back=nw;
	}
	else
	{
		nw->prev=lst->back;
		lst->back->next=nw;
		lst->back=nw;
	}
	return '0';
}
char addBeforeNode(void *dt,node *nd,list *lst)
{
	if(nd==NULL)
	{
		return '1';
	}
	if(validateNode(nd,lst)=='0')
	{
		return '2';
	}
	else
	{
		node *nw=(node*)malloc(sizeof(node));
		nw->data=dt;
		nw->next=nd;
		node *tmp=nd->prev;
		nw->prev=tmp;
		if(tmp==NULL)
			lst->front=nw;
		else
			tmp->next=nw;
		nd->prev=nw;
	}
	return '0';
}
char addAfterNode(void *dt,node *nd,list *lst)
{
	if(nd==NULL)
	{
		return '1';
	}
	if(validateNode(nd,lst)=='0')
	{
		return '2';
	}
	else
	{
		node *nw=(node*)malloc(sizeof(node));
		nw->data=dt;
		nw->prev=nd;
		node *tmp=nd->next;
		nw->next=tmp;
		if(tmp==NULL)
			lst->back=nw;
		else
			tmp->prev=nw;
		nd->next=nw;
	}
	return '0';
}
char addBeforeData(void *dt,void *dt2,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tmpnd=searchDataNode(dt2,lst,comp);
	if(validateNode(tmpnd,lst)=='1')
	{
		addBeforeNode(dt,tmpnd,lst);
		return '0';
	}
	else
		return '1';
}
char addAfterData(void *dt,void *dt2,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tmpnd=searchDataNode(dt2,lst,comp);
	if(validateNode(tmpnd,lst)=='1')
	{
		addAfterNode(dt,tmpnd,lst);
		return '0';
	}
	else
		return '1';
}
char deleteFirst(list *lst)
{
	if(lst==NULL)
		return '1';
	else if(lst->front==NULL || lst->back==NULL)
		return '2';
	else if(lst->front==lst->back)
	{
		node *nd=lst->front;
		free(nd);
		lst->front=NULL;
		lst->back=NULL;
	}
	else
	{
		node *nd=lst->front;
		lst->front=lst->front->next;
		lst->front->prev=NULL;
		free(nd);
	}
	return '0';
}
char deleteLast(list *lst)
{
	if(lst==NULL)
		return '1';
	else if(lst->front==NULL || lst->back==NULL)
		return '2';
	else if(lst->front==lst->back)
	{
		node *nd=lst->back;
		free(nd);
		lst->front=NULL;
		lst->back=NULL;
	}
	else
	{
		node *nd=lst->back;
		lst->back=nd->prev;
		lst->back->next=NULL;
		free(nd);
	}
	return '0';
}
char deleteBeforeNode(node *nd,list *lst)
{
	if(nd==NULL)
		return '1';
	else if(lst==NULL)
		return '2';
	else if(validateNode(nd,lst)=='0')
		return '3';
	else if(nd->prev==NULL)
		return '4';
	else
	{
		node *tmpnod=nd->prev;
		node *tmpnd2=tmpnod->prev;
		nd->prev=tmpnd2;
		if(tmpnd2==NULL)
			lst->front=nd;
		else
			tmpnd2->next=nd;
		free(tmpnod);
	}
	return '0';
}
char deleteAfterNode(node *nd,list *lst)
{
	if(nd==NULL)
		return '1';
	else if(lst==NULL)
		return '2';
	else if(validateNode(nd,lst)=='0')
		return '3';
	else if(nd->next==NULL)
		return '4';
	else
	{
		node *tmpnod=nd->next;
		node *tmpnd2=tmpnod->next;
		nd->next=tmpnd2;
		if(tmpnd2==NULL)
			lst->back=nd;
		else
			tmpnd2->prev=nd;
		free(tmpnod);
	}
	return '0';
}
char deleteBeforeData(void *dt2,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tmpnd=searchDataNode(dt2,lst,comp);
	if(validateNode(tmpnd,lst)=='1')
	{
		deleteBeforeNode(tmpnd,lst);
		return '0';
	}
	else
		return '1';
}
char deleteAfterData(void *dt2,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tmpnd=searchDataNode(dt2,lst,comp);
	if(validateNode(tmpnd,lst)=='1')
	{
		deleteAfterNode(tmpnd,lst);
		return '0';
	}
	else
		return '1';
}
char deleteNode(node *nd,list *lst)
{
	if(nd==NULL)
		return '1';
	else if(lst==NULL)
		return '2';
	else if(lst->front==NULL || lst->back==NULL)
		return '3';
	else if(validateNode(nd,lst)=='0')
		return '4';
	else if(lst->front==lst->back)
	{
		node *tmpnd=lst->front;
		lst->front=NULL;
		lst->back=NULL;
		free(tmpnd);
	}
	else if(nd==lst->front)
	{
		lst->front=nd->next;
		lst->front->prev=NULL;
		node *tmp=nd;
		free(tmp);
	}
	else if(nd==lst->back)
	{
		lst->back=nd->prev;
		lst->back->next=NULL;
		node *tmp=nd;
		free(tmp);
	}
	else
	{
		node *tmp1,*tmp2,*tmp3;
		tmp3=nd;
		tmp2=nd->next;
		tmp1=nd->prev;
		tmp1->next=tmp2;
		tmp2->prev=tmp1;
		free(tmp3);
	}
	return '0';
}
char deleteData(void *dt,list *lst,char (comp)(void *dt1,void *dt2))
{
	node *tmpnd=searchDataNode(dt,lst,comp);
	if(validateNode(tmpnd,lst)=='1')
	{
		deleteNode(tmpnd,lst);
		return '0';
	}
	else
		return '1';
}
