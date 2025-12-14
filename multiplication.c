/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	int add_zero = 0; //add zero for multiplication for each new number

	if((*head1)->data == '0' && (*head1)->next ==NULL)
	{
		dll_insert_end(headR, tailR, '0');
		return SUCCESS;
	}
	if((*head2)->data == '0' && (*head2)->next ==NULL)
	{
		dll_insert_end(headR, tailR, '0');
		return SUCCESS;
	}

	while(temp2 != NULL)
	{
		int digit2 = temp2->data - '0';

		Dlist *row_head = NULL, *row_tail = NULL;

		int carry = 0;
		
		temp1 = *tail1;

		while(temp1 != NULL)
		{
			int digit1 = temp1->data - '0';

			int mul = digit1 * digit2 + carry;
			carry = mul / 10;
			mul = mul % 10;

			Dlist *NEW = malloc(sizeof(Dlist));
			if(NEW == NULL)
			{
				printf("\n! The Malloc Memory Allocation Is Failed !\n\n");
				return FAILURE;
			}
		
			NEW->data = mul+ '0';
			NEW->prev = NULL;
			NEW->next = row_head;
			
			if(row_head != NULL)
			{
				row_head->prev = NEW;
			}
			else
				row_tail = NEW;
			
			row_head = NEW;

			temp1 = temp1->prev;
		}
		if(carry > 0)
		{
			Dlist *NEW = malloc(sizeof(Dlist));
			if(NEW == NULL)
			{
				printf("\nThe Memory Allocation Is Failed\n\n");
				return FAILURE;
			}
		
			NEW->data = carry + '0';
			NEW->prev = NULL;
			NEW->next = row_head;

			if(row_head != NULL)
			{
				row_head->prev = NEW;
			}
			else
				row_tail= NEW;
			
			row_head = NEW;
		}
		for(int i = 0; i < add_zero; i++)
		{
			Dlist *NEW = malloc(sizeof(Dlist));
			// check the memory alloction 
			if(NEW == NULL)
			{
				printf("\nThe Memory Allocation Is Failed\n\n");
				return FAILURE;
			}

			NEW->data = '0';
			NEW->next = NULL;
			NEW->prev = row_tail;

			row_tail->next = NEW;
			row_tail = NEW;
		}
		if(*headR == NULL)
		{
			*headR = row_head;
			*tailR = row_tail;
		}
		else{
			addition(headR, tailR, &row_head, &row_tail, headR, tailR);
		}

		add_zero++;
		temp2 = temp2->prev;
	}
	
	//remove the leading zero's 
	removeLeadingZeros(headR, tailR);

    if(*headR == NULL)
    {
		dll_insert_end(headR, tailR, '0');
	}
        
    return SUCCESS;

}
