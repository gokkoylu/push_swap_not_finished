#include "utils.h"
#include <stdlib.h>

void free_stack(t_stack *stack) 
{
    t_node *temp;

    if (!stack)
        return ;
    while (stack->top != NULL) 
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

t_node *ft_lstnew(int value)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return NULL;
    new->value = value;
    new->next = NULL;

    return (new);
}

void ft_lstadd_back(t_stack *stack, int value)
{
    t_node *move;
    t_node *new_node;

    if (!stack)
        return;

    new_node = ft_lstnew(value);
    if (!new_node)
        return;

    move = stack->top;

    if (!move)
    {
        stack->top = new_node;
        return;
    }

    while (move->next)
        move = move->next;
    
    move->next = new_node;
}

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }

    return (res * sign);
}

void    ft_free_local_2m(char **data)
{
    int    i;

    if (!data)
        return ;
    i = -1;
    while (data[++i])
        free(data[i]);
    free(data);
}

int word_counter(char *string_for_counter, char delimiter_for_counter)
{
    int count;
    int is_word;
    int i;

    i = 0;
    is_word = 0;
    count = 0;

    while(string_for_counter[i] != '\0')
    {
        if ((string_for_counter[i] != delimiter_for_counter) && is_word == 0) //Cümleye girince countu 1 kere arttırıyoruz, is_word 1'de kalıyor.
        {
            count++;
            is_word = 1;
        }
        else if ((string_for_counter[i] == delimiter_for_counter) && is_word == 1) //Cümleden çıkarken is_word 1'de kalmaya devam ediyor, delimitera denk gelindiğinde is_word reset.
            is_word = 0;
        i++;
    }

    return (count);
}

char *split_words(char *string_for_splitter, int start_for_splitter, int end_for_splitter)
{
    int word_length;
    int i;
    int j;
    char *mallocd_char_for_splitter;
    
    i = start_for_splitter;
    j = 0;

    word_length = end_for_splitter - start_for_splitter;
    mallocd_char_for_splitter = malloc((word_length + 1) * sizeof(char));
    while(i < end_for_splitter)
    {
        mallocd_char_for_splitter[j] = string_for_splitter[i];
        j++;
        i++;
    }
    mallocd_char_for_splitter[j] = '\0'; //İstenen yeri kapatıyoruz. '\0' idi, NULL'a çevirdim.

    return (mallocd_char_for_splitter);
}

char **ft_split(char *string, char delimiter)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = 0;
    int word_count;
    char **mallocd_string;

    word_count = word_counter(string, delimiter);
    mallocd_string = malloc((word_count + 1) * sizeof(char*));
    if (!mallocd_string)
        return NULL;

    while (string[i] != '\0')
    {
        if (string[i] != delimiter)
        {
            start = i;
            while (string[i] != '\0' && string[i] != delimiter)
                i++;
            end = i;
            mallocd_string[j] = split_words(string, start, end);
            if (!mallocd_string[j])
            {
                ft_free_local_2m(mallocd_string);
                return NULL;
            }
            j++;
        }
        else
            i++;
    }
    mallocd_string[j] = NULL; 

    return (mallocd_string);
}