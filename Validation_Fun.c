#include "apc.h"

/*Insert at last function*/
int dll_insert_end(Dlist **head, Dlist **tail, char ch)
{
	/*creating a double linked list*/
	Dlist *new = malloc(sizeof(Dlist));

	//check if the memory is allocated or not
	if(new == NULL)
	{
		printf("\nMemory Allocation Failed\n\n");
		return FAILURE;
	}

	new->data = ch; //or do ch - '0' to store the digit as integer; 
	new->prev = NULL;
	new->next = NULL;

	if(*head == NULL)
	{
		*head = *tail = new;
		return SUCCESS;
	}

	
	new->prev = *tail;
	(*tail)->next = new;
	*tail = new;
	
	return SUCCESS;

}

/*compare both the operands*/
int compare_list(Dlist *head1, Dlist *head2) 
{
	//check if both the list are pointing to null
	if(head1 == NULL && head2 == NULL )
		return 0;
	if(head1 == NULL)
		return -1;
	else if(head2 == NULL)
		return 1;

	//measure the length of each operand
	int len1 = 0, len2 = 0;
	Dlist *temp1 = head1, *temp2 = head2;

	while(temp1 != NULL)
	{
		len1++;
		temp1 = temp1->next;
	}

	while(temp2 != NULL)
	{
		len2++;
		temp2 = temp2->next;
	}

	//compare the length 
	if(len1 < len2) 
		return -1;
	else if(len1 > len2)
		return 1;

	//if both the length of the operands are equal then comapre the operands digit by digit
	while(head1 && head2)
	{
		if(head1->data > head2->data)
			return 1;
		if(head1->data < head2->data)
			return -1;

		head1 = head1->next;
		head2 = head2->next;
	}
	return 0;
}

/*remove the leading zeros after every operation*/
void removeLeadingZeros(Dlist **head, Dlist **tail)
{
	while(*head && (*head)->data == '0' && (*head)->next != NULL)
	{
		Dlist *del = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
	if(!*head)
		*tail = NULL;
}

/*append */
void append_qnode(Dlist **headR, Dlist **tailR, char ch)
{
    Dlist *new = malloc(sizeof(Dlist));
	if(!new)
	{
		printf("Merory Error\n");
		exit(1);
	}
    new->data = ch;
    new->next = NULL;
    new->prev = *tailR;

    if (*tailR)
        (*tailR)->next = new;
    else
        *headR = new;

    *tailR = new;
}

//append the digit
void append_digit(Dlist **head, Dlist **tail, char ch)
{
    Dlist *new = malloc(sizeof(Dlist));
	if(!new)
	{
		printf("Merory Error\n");
		exit(1);
	}
    new->data = ch;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
}

/*Validate the operand*/
int validate(char *str)
{
	int start = 0;
	if(str[0] == '-' || str[0] == '+')
	{
		start = 1;
	}
	else
		start = 0;
	//check the operand that it only should contain digit's 
	for(int i = start; str[i] != '\0'; i++)
	{
		if((str[i] < '0' || str[i] > '9'))
		{
			printf("\n\033[31mError : \033[0m");
			printf("Invalid Character '%c' in operand 1\n",str[i]);
			printf("operand should contain only numbers(0...9)..!!!\n\n");
			return 0;		
		}
	}
	
	return 1;
	
}

/*remove the zero's from the operand*/
void remove_zero(char *s)
{
	int sign = 0;
	int i = 0, j = 0;
	if(s[0] == '-' || s[0] == '+')
	{
		sign = s[0];
		i = 1;
	}
	while(s[i] == '0')
		i++;

	if(s[i] == '0')
	{
		s[0] = '0';
		s[1] = '\0';
		return;
	}

	if(sign)
	{
		s[j++] = sign;
	}
	while(s[i] != '\0')
	{
		s[j++] = s[i++];
	}

	s[j] = '\0';
}