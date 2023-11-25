#include "operations.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char **input;
    int i;
    int value;

    i = 0;
    stack_a.top = NULL;
    stack_b.top = NULL;
    //input ve error input handlela

    //printf("%s", argv[1]);
    if (argc == 2) //bu bi fonksiyon belki
    {
        check_argv1(argv[1]);
        input = ft_split(argv[1], ' ');
        while (input[i])
        {
                if_num_atoi(input[i], &stack_a);
                value = ft_atoi(input[i]);
                ft_lstadd_back(&stack_a, value);
                i++;
        }
        if_double(&stack_a);
        ft_sort(i, &stack_a, &stack_b);
    }
    else if (argc >= 3) //bu bi fonksiyon belki************
    {
        i = 1;
        while (i < argc)
        {
            if_num_atoi(argv[i], &stack_a);
            value = ft_atoi(argv[i]);
            ft_lstadd_back(&stack_a, value);
            i++;
        }
        if_double(&stack_a);
        ft_sort(i - 1, &stack_a, &stack_b);
    }
    //printf("%s", *input);
    
    //print_stack(&stack_a);
    //printf("%d", i);
    //ft_sort(i, &stack_a, &stack_b);

    // print_stack(&stack_a);
    free_stack(&stack_a);
    return (0);
}
