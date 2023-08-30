


#include "stack.h"
#include "stdio.h"
#define NULL (void *)0
static stack_state_t stack_full(stack_t *stack)
{
      return_state_t ret = R_OK;
      if ((stack->stack_ptr == STACK_MAX_SIZE - 1))
      {
            return STACK_FULL;
      }
      else
      {
            return STACK_NOT_FULL;
      }
}
static stack_state_t stack_empty(stack_t *stack)
{
      return_state_t ret = R_OK;
      if ((stack->stack_ptr == -1))
      {
            return STACK_EMPTY;
      }
      else
      {
            return STACK_NOT_FULL;
      }
}

return_state_t stack_intialize(stack_t *stack)
{
      return_state_t ret = R_OK;
      if ((NULL == stack))
      {
            ret = R_NOT_OK;
      }
      else
      {
            stack->stack_ptr = -1;
      }
      return ret;
}
return_state_t stack_push(stack_t *stack,uint32_t value){
       return_state_t ret = R_OK;
      if ((NULL == stack)||(STACK_FULL==stack_full(stack)))
      {
            ret = R_NOT_OK;
            #ifdef STACK_DEBUG
            printf("Error the value %d is not pushed into stack \n",value);
            #endif
      }
      else
      {
            stack->stack_ptr++;
            stack->data[stack->stack_ptr]=value;
            printf("%d\n",stack->data[stack->stack_ptr]);
            #ifdef STACK_DEBUG
            printf("The value %d is pushed into stack \n",value);
            #endif
      }
      return ret;
}
return_state_t stack_pop(stack_t*stack,uint32_t *value){
        return_state_t ret = R_OK;
      if ((NULL == stack)||(NULL==value)||(STACK_EMPTY==stack_empty(stack)))
      {
            ret = R_NOT_OK;
            #ifdef STACK_DEBUG
            printf("Error the value %d is not poped from stack \n",*value);
            #endif
      }
      else
      {
            *value=stack->data[stack->stack_ptr];
            stack->stack_ptr--;
            #ifdef STACK_DEBUG
            printf("The value %d is puped from stack \n",*value);
            #endif

      }
      return ret;
}
return_state_t stack_top(stack_t *stack,uint32_t *value){
        return_state_t ret = R_OK;
      if ((NULL == stack)||(NULL==value)||(STACK_EMPTY==stack_empty(stack)))
      {
            ret = R_NOT_OK;
            #ifdef STACK_DEBUG
            printf("Error the top value %d is not poped from stack \n",value);
            #endif
      }
      else
      {
            *value=stack->data[stack->stack_ptr];
            #ifdef STACK_DEBUG
            printf("The top value %d is puped from stack \n",value);
            #endif
      }
      return ret;
}
return_state_t stack_size(stack_t *stack,uint32_t *size){
        return_state_t ret = R_OK;
      if ((NULL == stack)||(NULL==size))
      {
            ret = R_NOT_OK;

      }
      else
      {
            *size=stack->stack_ptr+1;

      }
      return ret;
}
return_state_t stack_disp(stack_t *stack){
  return_state_t ret = R_OK;
  sint8_t l_counter=0;
      if ((NULL == stack)||(STACK_EMPTY==stack_empty(stack)))
      {
            ret = R_NOT_OK;
      }
      else
      {
            for(l_counter=stack->stack_ptr;l_counter>=0;l_counter--){
                  printf("Stack elemnt is %d \n",stack->data[l_counter]);
            }
            printf("\n");
      }
      return ret;
}
