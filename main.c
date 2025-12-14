/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"
//int dll_insert_end(Dlist **head, Dlist **tail, char ch);
int main(int argc, char* argv[])
{
	//check if all the arguments are passed or not(print)
	if(argc < 2 || argc < 3 || argc < 4)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("||          I N V A L I D    A R G U M E N T S  !        ||");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		//printf("\nINFO              : 	Invalid Arguments\n");
		printf("\nAddtion           : 	./a.out operand1  + operand1\n");
		printf("\nSubstraction      : 	./a.out  operand1 - operand1\n");
		printf("\nMultiplication    : 	./a.out  operand1 * operand1\n");
		printf("\nDivision          : 	./a.out  operand1 / operand1\n\n");
		exit(1);
	}
    /* Declare the pointers */
    /* Initialize the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL,  *tailR = NULL;

	//charater to assign the operator
	char operator;
	//the size of operator should be 1 ('+, -, *, /')
	if(strlen(argv[2]) != 1)
	{
		printf("\n\033[31mError : \033[0m");
		printf("Invalid operator.\n");
		printf("\noperator should be '+, -, *, /'.\n\n");
		exit(1);
	}
	//assign the operator to the variable 
	/* extract the operator */
	operator = argv[2][0]; 
	//check the operator is '+, -, *, /' if not print error
	if(!(operator == '+' || operator == '-' || operator == '*' || operator == '/'))
	{
		printf("\n\033[31mError : \033[0m");
		printf("Invalid operator.\n");
		printf("\noperator should be '+, -, *, /'.\n\n");
		exit(1);
	}
	//print the operator
	printf("\n ==========================================================================\n");
	printf("|       A R B I T R A R Y   P R E C I S I O N   C A L CU L A T O R         |");
	printf("\n ==========================================================================\n");
	printf("\n\033[33mOperator is\033[0m ");
	printf("'%c'\n", operator);

	/*declare 2 string to take the command line arguments to string*/
	char s1[100], s2[100];

	//copy the arguments to the string
	strcpy(s1, argv[1]);
	strcpy(s2, argv[3]);

	//if the sizeof the operand is 0 we have not send the operand in terminal
	if(strlen(s1) == 0 || strlen(s2) == 0)
	{
		printf("\n\033[31mError : \033[0m");
		printf("Empty operand\n");
		printf("\nOperand 1 = %s\n", s1);
		printf("\nOperand 2 = %s\n", s2);
	}

	//remove the zero's from the both operands 
	remove_zero(s1);
	remove_zero(s2);

	//print the operands of string
	printf("\nOperand 1 = %s\n", s1);
	printf("\nOperand 2 = %s\n", s2);
	
	//to check wheather the operand is holding negative value
	int both_neg = 0, s1_neg = 0, s2_neg  = 0;

	//check if both the operand is negative
	if(s1[0] == '-' && s2[0] == '-')
	{
		both_neg = 1;
	}
	
	//if the operand 1 is negative 
	if(s1[0] == '-' || s1[0] == '+')
	{
		if(s1[0] == '-' )
			s1_neg = 1;

		int i = 0;
		while(s1[i] != '\0')
		{
			s1[i] = s1[i+1];
			i++;
		}
	}
	//if the operand 1 is negative 
	if(s2[0] == '-' || s2[0] == '+')
	{

		if(s2[0] == '-')
		s2_neg = 1;
		int i = 0;
		while(s2[i] != '\0')
		{
			s2[i] = s2[i+1];
			i++;
		}
	}
	

    //validate the operand wheather it contain 0-9 
	if(!validate(s1))
		exit(1);
	if(!validate(s2))
	 	exit(1);
		

	//converting the argument to list
	for(int i = 0; s1[i] != '\0'; i++)
	{
		if(dll_insert_end(&head1, &tail1, s1[i]) == FAILURE) /* function to convert CLA to list */
			printf("\nInsertion Failed\n\n");
	}
	
	//converting the argument to list
	for(int i = 0; s2[i] != '\0'; i++)
	{
		if(dll_insert_end(&head2, &tail2, s2[i]) == FAILURE)/* function to convert CLA to list */
			printf("\nInsertion Failed\n\n");
	}
	

	//check which type of operation need to performed
    switch (operator)
    {
	case '+':
	    /* call the function to perform the addition operation */
		printf("\nOperation is Addition\n\n");
		//check if both pointer are not pointing to null
		if(head1 == NULL || head2 == NULL)
		{
			printf("\nINFO : Syntax error need 2 operands\n\n");
			exit(1);
		}

		if(both_neg == 1)
		{
			/*if both the operands contains a negative sign the add adn print the answer with negative sign*/
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : -");
			print_result(headR);
		}
		else if(s1_neg == 1)/*if operand 1 is neagtive*/
		{
			
			/*comapre the operand*/
			int compare = compare_list(head2, head1);
			if(compare >= 0)
			{
				subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR); //if operand1 is greater then operand2 then perform subtraction
				printf("Result : ");
			}
			else
			{
				//else if operand2 is greater than operand1 then print the result with negative(-) sign
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				printf("Result : -");
			}
			print_result(headR); //printf the result
		}
		else if(s2_neg == 1)/*if operand 2 is neagtive*/
		{
			/*comapre the operand*/
			int compare = compare_list(head1, head2);
			if(compare >= 0)
			{
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);//if operand1 is greater then operand2 then perform subtraction
				printf("Result : ");
			}
			else
			{
				//else if operand2 is greater than operand1 then print the result with negative(-) sign
				subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				printf("Result : -"); 
			}
			print_result(headR); //printf the result
		}
		else
		{ /*if both the operand are positive then perform addition*/
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : ");
			print_result(headR); //print the result
		}
		break;

	case '-':	
		/* call the function to perform the subtraction operation */
		printf("\nOperation is Subtraction\n\n");
	    
		//check if both pointer are not pointing to null
		if(head1 == NULL || head2 == NULL)
		{
			printf("\nSyntax error need 2 operands!\n\n");
			exit(1);
		}
		/*if both operand are having a negative sign*/
		if(both_neg == 1)
		{
			/*comapre the operand*/
			int compare = compare_list(head2, head1);
			if(compare >= 0)
			{
				//if operand 1 is less than the operand 2 print without negative (-) sign
				subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				printf("Result : ");
			}
			else
			{
				//if operand 1 is greater than the operand 2 print with negative (-) sign
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				printf("Result : -");
			}
			print_result(headR); //print the result
		}
		else if(s1_neg == 1)
		{
			//if operand1 is negative the perform addition operation and print with negative symbol
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : -");
			print_result(headR);//print the result
		}
		else if(s2_neg == 1)
		{
			//if operand2 is negative the perform addition operation and print without negative symbol
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : ");
			print_result(headR);//print the result
		}
		else
		{
			//if both the operands are postive 
			/*comapre the operand*/
			int compare = compare_list(head1, head2);
			if(compare >= 0)
			{
				//after comparison check if operand1 greater than operand2 then the result is positive
				subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				printf("Result : ");
			}
			else
			{
				//after comparison check if operand1 less than operand2 then the result is negative
				subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				printf("Result : -");
			}
			print_result(headR);//print the result
		}
	    break;

	case '*':	
		 /* call the function to perform the multiplication operation */
		printf("\nOperation is Multiplication\n\n");
	   
		//check if both pointer are not pointing to null
		if(head1 == NULL || head2 == NULL)
		{
			printf("\nSyntax error need 2 operands !\n\n");
			exit(1);
		}
		
		if(head2 == NULL )
		{	
			printf("\nSyntax error need 2 operands !\n\n");
			exit(1);
		}

		//check if both of the operand's are neagative then result is positive
		if(both_neg)
		{
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : ");
			print_result(headR);//print the result
		}
		else if((s1_neg == 1 && s2_neg == 0) ||(s1_neg == 0 && s2_neg == 1))
		{
			//check if any of the operand is neagative then result is negative
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : -");
			print_result(headR); //print the result
			
		}
		else
		{
			//check if both of the operand's are positive then result is positive
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result : ");
			print_result(headR);//print the result
		}
	    break;

	case '/':
	 /* call the function to perform the division operation */	
		printf("\nOperation is Division\n\n");
	   
		//check if both pointer are not pointing to null
		if(head1 == NULL || head2 == NULL)
		{
			printf("\nINFO : Syntax error need 2 operands\n\n");
			exit(1);
		}
		//while dividing check if any of the 2 oprand are non zero's
		if(head2->data == '0' && head2->next == NULL)
		{
			printf("\n\033[31mError : \033[0m");
			printf("While dividing both the operand should be non zeros !\n\n");
		exit(1);
		}
		
		
		int compare;
		compare = compare_list(head1, head2);
		if(compare < 0)
		{
			printf("Result : ");
			printf("0\n");
			exit(1);
		}
		
		printf("Result : ");
		division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(both_neg)
			print_result(headR);                    //print the result
		else if(s1_neg || s2_neg)
		{
			printf("-");
			print_result(headR);                   //print the result
		}
		else
			print_result(headR);                   //print the result
	    break;
	default:
	    printf("! Invalid Input Try again...\n");
    }

    return 0;
}
