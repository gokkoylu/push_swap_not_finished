#ifndef SORT_H
#define SORT_H

#include "utils.h"
#include <stdlib.h>

t_stack *ft_sort_by_3(t_stack *a);
t_stack *ft_sort(int i, t_stack *a, t_stack *b);
int reach_smallest(t_stack *stack);
int find_smallest(t_stack *stack);
void if_num_atoi(char *str, t_stack *stack);
int ft_isdigit(char c);
void free_stack(t_stack *stack);


#endif