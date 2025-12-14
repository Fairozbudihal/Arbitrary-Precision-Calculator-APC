/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,  Dlist **headR, Dlist **tailR)
{
    //fist assign the result head and tail of double linked list with null
    *headR = *tailR = NULL;

    /* Dividing by zero? */
    if ((*head2)->data == '0' && (*head2)->next == NULL)
    {
        printf("ERROR: Division Not posible divided by zero\n");
        return FAILURE;
    }

    /* If dividend < divisor → quotient = 0 */
    if (compare_list(*head1, *head2) < 0)
    {
        dll_insert_end(headR, tailR, '0');
        return SUCCESS;
    }

    Dlist *current = *head1;
    Dlist *block_head = NULL, *block_tail = NULL;

    /* Form initial block >= divisor */
    while (current && (block_head == NULL || compare_list(block_head, *head2) < 0))
    {
        append_digit(&block_head, &block_tail, current->data);
        removeLeadingZeros(&block_head, &block_tail);
        current = current->next;
    }

    /* For Long division */
    while (block_head)
    {
        int qdigit = 0;

        while (compare_list(block_head, *head2) >= 0)
        {
            Dlist *result_head = NULL, *result_tail = NULL;
            subtraction(&block_head, &block_tail, head2, tail2, &result_head, &result_tail);

            block_head = result_head;
            block_tail = result_tail;

            removeLeadingZeros(&block_head, &block_tail);
            qdigit++;
        }

        append_qnode(headR, tailR, qdigit + '0');

        /* Bring next digit */
        if (!current)
            break;

        append_digit(&block_head, &block_tail, current->data);
        removeLeadingZeros(&block_head, &block_tail);
        current = current->next;
    }

    //remove the leading zerosafter division
    removeLeadingZeros(headR, tailR);

    if(*headR == NULL)
        dll_insert_end(headR, tailR, '0');
        
    return SUCCESS;
}