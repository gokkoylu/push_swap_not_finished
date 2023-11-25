#include "utils.h"
#include "operations.h"
#include "sort.h"

int ft_isdigit(char c)
{
    if ((c >= '0') && (c <= '9'))
        return (1);
    else
        return (0);
}

void if_num_atoi(char *str, t_stack *a)
{
    int i;

    i = 0;
    if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
        {
            if (a->top)
                free_stack(a);
            ft_error();
        }
        i++;
    }
}

void if_double(t_stack *a)
{
    t_node *current;
    t_node *runner;

    current = a->top;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (runner->value == current->value)
            {
                free_stack(a);
                ft_error();
            }
            runner = runner->next;   
        }
        current = current->next;
    }
}

void check_argv1(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]) && (str[i] != ' '))
            ft_error(1);
        if (str[i] == ' ' && str[i + 1] == ' ')
            ft_error(1);
        i++;   
    }
}

int ft_error()
{
    write(STDERR_FILENO, "Error\n", 6);
    exit (1);
}
