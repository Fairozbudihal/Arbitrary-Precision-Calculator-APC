/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    //fist assign the result head and tail of double linked list with null
    *headR = *tailR = NULL;

    int compare;
    compare = compare_list(*head1, *head2);

    /* Case: numbers are equal → result = 0 */
    if (compare == 0)
    {
        dll_insert_end(headR, tailR, '0');
        return SUCCESS;
    }

    /* Determine which is larger for correct subtraction */
    Dlist *BigH, *BigT, *SmallH, *SmallT;
    int negative = 0;
    //check the operands if the operand 1 has greater value then operand 2 the assign them to bigH and bigT;
    if (compare > 0)
    {
        BigH = *head1;  BigT = *tail1;
        SmallH = *head2; SmallT = *tail2;
    }
    else
    {
        //check the operands if the operand 2 has less value then operand 1 the assign them to smallH and smallT;
        BigH = *head2;  BigT = *tail2;
        SmallH = *head1; SmallT = *tail1;
        negative = 1;
    }

    //take two variables then assign the tail's of both the operand to it
    Dlist *p = BigT;
    Dlist *q = SmallT;
    //borrow
    int borrow = 0;

    /* Perform subtraction from tail backward */
    //run the loop until both the both the pointers point to null
    while (p)
    {
        int digit1 = p->data - '0';
        int digit2;
		if(q != NULL)
		{
			digit2 = q->data - '0';
		}
		else
			digit2 = 0;

        //perform substraction
        int dif = digit1 - digit2 - borrow;
        //check the difference
        if (dif < 0)
        {
            dif += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        //allocate memory for the node
        Dlist *NEW = malloc(sizeof(Dlist));
        //check the memory is allocated or not
		if(NEW == NULL)
		{
			printf("\n ! The Malloc Memory Allocation is Failed !\n\n");
			return FAILURE;
		}
		
        //create the node for add the number
		NEW->data = dif + '0';
		NEW->prev = NULL;
		NEW->next = *headR;
        
        //insert at last
		if(*headR != NULL)
		{
			(*headR)->prev = NEW;
		}
		else
			*tailR = NEW;

		*headR = NEW;
        p = p->prev;
        if(q) 
            q = q->prev;
    }

    
    //remove the leading zero's
    removeLeadingZeros(headR, tailR);
    
    //check if still the head of result is pointing to null
    if(*headR == NULL)
        dll_insert_end(headR, tailR, '0');
        
    return SUCCESS;
}
