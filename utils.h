#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <stddef.h>


typedef struct s_node
{
int value;
struct s_node *next;
} t_node;

typedef struct s_stack
{
t_node *top;
} t_stack;

t_node *ft_lstnew(int value);
void ft_swap(int *a, int *b);
void ft_lstadd_back(t_stack *stack, int value);
int ft_atoi(const char *str);
char **ft_split(char *string, char delimiter);
void print_stack(t_stack *stack);
void if_double(t_stack *a);
void check_argv1(char *str);
int ft_error();
void free_stack(t_stack *stack);

#endif