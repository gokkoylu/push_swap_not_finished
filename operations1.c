#include "utils.h"


void sa(t_stack *stack_a)
{
    if (!stack_a->top)
        return;
    if (!stack_a->top->next)
        return;
    ft_swap(&stack_a->top->value, &stack_a->top->next->value);
    write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
    if (!stack_b->top)
        return;
    if (!stack_b->top->next)
        return;
    ft_swap(&stack_b->top->value, &stack_b->top->next->value);
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp;

    if (!stack_b->top)  // If stack_b is empty, no operation needed.
        return;

    tmp = stack_b->top; // Store the top element of stack_b.
    stack_b->top = tmp->next; // Update the top of stack_b to its next node.

    tmp->next = stack_a->top; // Set the next of tmp (previously top of stack_b) to top of stack_a.
    stack_a->top = tmp; // Make tmp the new top of stack_a.
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp;

    if (!stack_a->top)  // If stack_a is empty, no operation needed.
        return;

    tmp = stack_a->top; // Store the top element of stack_a.
    stack_a->top = tmp->next; // Update the top of stack_a to its next node.

    tmp->next = stack_b->top; // Set the next of tmp (previously top of stack_a) to top of stack_b.
    stack_b->top = tmp; // Make tmp the new top of stack_b.
    write(1, "pb\n", 3);
}