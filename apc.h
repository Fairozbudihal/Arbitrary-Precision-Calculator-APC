/*main*/
#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define SUCCESS 0
#define FAILURE -1



typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int validate(char *str);
int dll_insert_end(Dlist **head, Dlist **tail, char ch);
void print_list(Dlist *head);
void print_result(Dlist *head);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int compare_list(Dlist *head1, Dlist *head2);
void removeLeadingZeros(Dlist **head, Dlist **tail);
void remove_zero(char *s);

void append_digit(Dlist **head, Dlist **tail, char ch);
void append_qnode(Dlist **headR, Dlist **tailR, char ch);

#endif

//use this command for execution
/*use make for compilation*/
/* ./APC.exe for execution*/