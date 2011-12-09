#include "memory.h"
dtstr * func0read(list *mem,node *nd)
{
	if(validateNode(nd,mem)=='1')
	{
		return nd->data;
	}
	return NULL;
}
dtstr * func1write(list *mem,node *nd,dtstr *dt)
{
	if(validateNode(nd,mem)=='1')
	{
		free(nd->data);
		nd->data=dt;
		return nd;
	}
	return NULL;
}
node * func2seekp(list *mem,node *nd)
{
	if(validateNode(nd,mem)=='1')
	{
		return nd->next;
	}
	return NULL;
}
node * func3seekn(list *mem,node *nd)
{
	if(validateNode(nd,mem)=='1')
	{
		return nd->prev;
	}
	return NULL;
}
dtstr * func4addaftr(list *mem,node *nd,dtstr *dt)
{
	if(validateNode(nd,mem)=='1')
	{
		addAfterNode(dt,nd,mem);
		return nd;
	}
	return NULL;
}
dtstr * func5addbfr(list *mem,node *nd,dtstr *dt)
{
	if(validateNode(nd,mem)=='1')
	{
		addBeforeNode(dt,nd,mem);
		return nd;
	}
	return NULL;
}
dtstr * func7deletebfr(list *mem,node *nd)
{
	if(validateNode(nd,mem)=='1')
	{
		deleteBeforeNode(nd,mem);
		return nd;
	}
	return NULL;
}
dtstr * func6deleteaftr(list *mem,node *nd)
{
	if(validateNode(nd,mem)=='1')
	{
		deleteAfterNode(nd,mem);
		return nd;
	}
	return NULL;
}
