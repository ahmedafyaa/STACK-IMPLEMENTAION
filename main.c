#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
stack_t stack;

int main()
{
        uint32_t value;
        uint32_t a=22;
      int ret=stack_intialize(&stack);
      printf("ret value is %d\n",ret);
      ret=stack_push(&stack, a);
      printf("ret value is %d\n",ret);
      stack_push(&stack, 12);
      stack_push(&stack, 78);
      stack_pop(&stack,&value);
      printf("The value poped from stack is %d\n",value);
      stack_disp(&stack);
}
