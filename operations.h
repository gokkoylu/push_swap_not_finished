#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "utils.h"
#include <stddef.h>

void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

#endif