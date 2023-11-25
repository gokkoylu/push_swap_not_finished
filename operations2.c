#include "utils.h"

void ra(t_stack *stack_a)
{
    if (!stack_a->top || !stack_a->top->next)
        return;
    t_node *tmp;
    t_node *last;

    tmp = stack_a->top;
    stack_a->top = stack_a->top->next;
    last = stack_a->top;
    while (last->next)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp->next = NULL;
    write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
    if (!stack_b->top || !stack_b->top->next)
        return;
    t_node *tmp;
    t_node *last;

    tmp = stack_b->top;
    stack_b->top = stack_b->top->next;
    last = stack_b->top;
    while (last->next)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp->next = NULL;
    write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}