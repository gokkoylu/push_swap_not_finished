#include "utils.h"

void rra(t_stack *stack_a)
{
    t_node *tmp;
    t_node *second_last;

    if (!stack_a->top || !stack_a->top->next)
        return;
    second_last = stack_a->top;
    while (second_last->next && second_last->next->next)
        second_last = second_last->next;
    tmp = second_last->next;
    second_last->next = NULL;
    tmp->next = stack_a->top;
    stack_a->top = tmp;
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
    t_node *tmp;
    t_node *second_last;
    
    if (!stack_b->top || !stack_b->top->next)
        return;
    second_last = stack_b->top;
    while (second_last->next && second_last->next->next)
        second_last = second_last->next;
    tmp = second_last ->next;
    second_last->next = NULL;
    tmp->next = stack_b->top;
    stack_b->top = tmp;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}
