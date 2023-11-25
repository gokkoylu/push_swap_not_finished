#include "utils.h"
#include "operations.h"
#include <stdio.h>


int ft_abs(int num) 
{
    if (num < 0) 
        return -num;
    return num;
}

int find_biggest_abs(t_stack *a) 
{
    int max_abs;
    t_node *current;

    max_abs = 0;
    current = a->top;
    while (current) 
    {
        if (ft_abs(current->value) > max_abs) 
        {
            max_abs = ft_abs(current->value);
        }
        current = current->next;
    }
    return max_abs;
}

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        printf("%d", current->value);
        printf("\n");
        current = current->next;
    }
}

int find_smallest(t_stack *stack) 
{

    int min_value;
    t_node *current;

    current = stack->top->next;
    min_value = stack->top->value;
    while (current != NULL) 
    {
        if (current->value < min_value) 
        {
            min_value = current->value;
        }
        current = current->next;
    }
    return (min_value);
}

int find_biggest(t_stack *stack)
{
    int max_value;
    t_node *current;

    current = stack->top->next;
    max_value = stack->top->value;
    while (current != NULL)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
        }
        current = current->next;
    }
    return (max_value);
}

int get_bit(int number, int position)
{
    return (number >> position)&1;
}

int reach_smallest(t_stack *stack) 
{
    t_node *current;
    int min_value;
    int i;

    i = 0;
    current = stack->top;
    min_value = find_smallest(stack);
    while (current != NULL) 
    {
        if (current->value == min_value) 
        {
            return i;
        }
        current = current->next;
        i++;
    }
    return (0);
}

t_stack *ft_sort_by_3(t_stack *a)
{
    if (a->top->value > a->top->next->value) //tepedeki ortadan büyük
    {
        if (a->top->value > a->top->next->next->value) //tepedeki alttan büyük
        {
            if (a->top->next->value > a->top->next->next->value) //ortadaki alttan büyük 3 2 1
            {
                sa(a);
                rra(a);
            }
            else if (a->top->next->value < a->top->next->next->value) //alttaki ortadan büyük 3 1 2
            {
                ra(a);
            }
        }
        else if (a->top->value < a->top->next->next->value) //tepedeki ortadan büyük + tepedeki alttan küçük 2 1 3
        {
            sa(a);
        }
    }
    else if (a->top->value < a->top->next->value) //tepedeki ortadan küçük
    {
        if (a->top->value > a->top->next->next->value) //tepedeki alttan büyük 2 3 1
        {
            rra(a);
        }
        if (a->top->value < a->top->next->next->value)//tepedeki alttan küçük
        {
            if (a->top->next->value > a->top->next->next->value) //alttaki ortadan küçük tepeden büyük 1 3 2
            {
                sa(a);
                ra(a);
            }
        }
    }
    return (a);
}

t_stack *ft_sort_by_4(t_stack *a, t_stack *b)
{
    int rerun;

    rerun = reach_smallest(a);
    if (rerun == 3)
        rra(a);
    else if (rerun == 2 || rerun == 1)
    {
        ra(a);
        if (rerun == 2)
            ra(a);
    }
    pb(a, b);
    ft_sort_by_3(a);
    pa(a, b);
    return (a);
}

t_stack *ft_sort_by_5(t_stack *a, t_stack *b)
{
    int rerun;

    rerun = reach_smallest(a);
    if (rerun == 1 || rerun == 2)
    {
        ra(a);
        if (rerun == 2)
            ra(a);
    }
    else if (rerun == 3 || rerun == 4)
    {
        rra(a);
        if (rerun == 3)
            rra(a);
    }
    pb(a, b);
    ft_sort_by_4(a, b);
    pa(a, b);
    return (a);
}

t_stack *ft_sort_by_radix(int stacksize, t_stack *a, t_stack *b) {
    int max_num;
    int max_bit;
    int i;
    int j;

    i = 0;
    j = 0;
    max_bit = 0;
    max_num = find_biggest_abs(a);
    while (max_num) 
    {
        max_bit++;
        max_num = max_num >> 1;
    }
    
    max_bit++;  
    while (i < max_bit) 
    {
        j = 0;
        while (j < stacksize) {
            
            if (i == max_bit - 1)
            {
                if (get_bit(a->top->value, i) == 1)
                    pb(a, b);  
                else
                    ra(a);  
            } 
            else 
            {
                if (get_bit(a->top->value, i) == 0)
                    pb(a, b);  
                else
                    ra(a);  
            }
            j++;
        }
        while (b->top)
            pa(a, b);
        i++;
    }
    return (a);
}


t_stack *ft_sort(int i, t_stack *a, t_stack *b)
{
    if (i == 2)
    {
        if (a->top->value > a->top->next->value)
            sa(a);
    }
    else if (i == 3)
        ft_sort_by_3(a);
    else if (i == 4)
        ft_sort_by_4(a, b);
    else if (i == 5)
        ft_sort_by_5(a,  b);
    else if (i > 5)
        ft_sort_by_radix(i, a, b);
    return (a);
}