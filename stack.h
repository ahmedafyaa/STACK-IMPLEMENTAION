
#ifndef _STACK_H
#define _STACK_H
#include "std_types.h"
#define STACK_MAX_SIZE     5
#define STACK_DEBUG

typedef enum
{
      STACK_EMPTY,
      STACK_FULL,
      STACK_NOT_FULL
} stack_state_t;

typedef struct
{
      uint32_t stack_ptr;
      uint32_t data[STACK_MAX_SIZE];

} stack_t;

return_state_t stack_intialize(stack_t *stack);
return_state_t stack_push(stack_t *stack,uint32_t value);
return_state_t stack_pop(stack_t*stack,uint32_t *vlaue);
return_state_t stack_top(stack_t *stack,uint32_t *value);
return_state_t stack_size(stack_t *stack,uint32_t *size);
return_state_t stack_disp(stack_t *stack);

#endif
