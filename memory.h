#ifndef MEMORY_H
#define MEMORY_H
#include "datastorer.h"
#include "list.h"
dtstr * func0read(list *mem,node *nd);
dtstr * func1write(list *mem,node *nd,dtstr *dt);
dtstr * func3addaftr(list *mem,node *nd,dtstr *dt);
dtstr * func2addaftrnseek(list *mem,node *nd,dtstr *dt);
dtstr * func5addbfr(list *mem,node *nd,dtstr *dt);
dtstr * func4addbfrnseek(list *mem,node *nd,dtstr *dt);
dtstr * func7deletebfr(list *mem,node *nd);
dtstr * func6deleteaftr(list *mem,node *nd);
#endif
