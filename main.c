#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <ctype.h>

stack_t *top = 0;

/**
 * main - main function
 * Return: 0 on success
 */
int main(void)
{
	push(1);
	push(2);
	push(3);
	pall();
	return (0);
}

/**
 * push - function that pushes elements to the stack
 * @x: element to be pushed to stack
 */
void push(int n)
{
        stack_t *new_node;

        new_node = (stack_t*)malloc(sizeof(stack_t));
	if(!new_node)
	{
		printf("Stack overflow");
		exit(1);
	}
        new_node->n = n;
        new_node->next = top;
        top = new_node;
}

/**
 * pall - function that print elements on stack
 */
void pall(void)
{
        stack_t *temp;

        if(top == NULL)
        {
                printf("Stack underflow");
		exit(1);
        }
	else
	{
		temp = top;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * pop - function that delertes/removes the top element
 */
void pop(void)
{
	stack_t *temp;

	temp = top;
	top = top->next;
	free(temp);
}
