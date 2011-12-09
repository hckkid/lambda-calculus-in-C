#ifndef MEMORY_H
#define MEMORY_H
#include "datastorer.h"
#include "list.h"
dtstr * func0read(list *mem,node *nd);
dtstr * func1write(list *mem,node *nd,dtstr *dt);
node * func2seekp(list *mem,node *nd);
node * func3seekn(list *mem,node *nd);
dtstr * func4addaftr(list *mem,node *nd,dtstr *dt);
dtstr * func5addbfr(list *mem,node *nd,dtstr *dt);
dtstr * func7deletebfr(list *mem,node *nd);
dtstr * func6deleteaftr(list *mem,node *nd);
#endif
