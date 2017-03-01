
#include "doublylinkednode.h"

int
main()
{
   typedef doublylinkednode<int>       int_doublylinkednode;
 
   int_doublylinkednode::link link = new int_doublylinkednode(0, NULL, NULL);

   return 0;
}

