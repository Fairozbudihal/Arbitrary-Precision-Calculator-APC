/*Print list*/
#include "apc.h"

void print_list(Dlist *head)
{
    
    if(head == NULL)
    {
        printf("\nINFO : List is Empty\n\n");
        return ;
    }

    printf("Head -> ");
    while (head != NULL)
    {
        printf("%c ", head->data);
        head = head->next;
        if(head != NULL)
            printf("-> ");
    }
        printf("-> Tail\n\n");
}

void print_result(Dlist *head)
{
    //printf("Result : ");
    if(head == NULL)
    {
        printf("\nINFO : List is Empty\n\n");
        return;
    }
    while (head != NULL)
    {

        printf("\033[33m%c\033[0m", head->data);
        head = head->next;
    }
    printf("\n");
}