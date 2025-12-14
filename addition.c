/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	// take 2 temporary variable's
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	// fist assign the result head and tail of double linked list with null
	*headR = NULL;
	*tailR = NULL;

	// carry
	int carry = 0;

	// loop to run's until both the linked list points to null
	/* Perform addition from tail backward */
	while (temp1 != NULL || temp2 != NULL || carry > 0)
	{
		int digit1 = 0, digit2 = 0;

		// get the value from the list and assign to a variable
		if (temp1 != NULL)
		{
			digit1 = temp1->data - '0'; // convert characte to int
			temp1 = temp1->prev;
		}

		// get the value from the list and assign to a variable
		if (temp2 != NULL)
		{
			digit2 = temp2->data - '0'; // convert characte to int
			temp2 = temp2->prev;
		}

		// add the the values from the 2 list
		int SUM = digit1 + digit2 + carry;

		// check the carry
		carry = SUM / 10;
		SUM = SUM % 10;

		// allocate memory in heap
		Dlist *NEW = malloc(sizeof(Dlist));

		// check if the memory is allocated or not
		if (NEW == NULL)
		{
			printf("\n! The Malloc Memory Allocation Is Failed !\n\n");
			return FAILURE;
		}

		// update the result linked list with the result sum
		NEW->data = SUM + '0';
		NEW->prev = NULL;
		NEW->next = *headR;

		// logic for adding the sum to the double linked list
		if (*headR != NULL)
		{
			(*headR)->prev = NEW;
		}
		else
			*tailR = NEW;

		*headR = NEW;
	}
	// if any leading zero's present then remove
	removeLeadingZeros(headR, tailR);

	return SUCCESS;
}
