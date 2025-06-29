#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "task.h"
#include "utilis.h"

t_task *create_task(char *name)
{
	t_task *new_task = malloc(sizeof(t_task));
	if(!new_task)
		return NULL;
	new_task->name = malloc(ft_strlen(name)+1);
	if(!new_task->name)
	{
		free(new_task);
		return NULL;
	}

	ft_strcpy(new_task->name,name);
	new_task->next = NULL;

	return new_task;
}

void add_task(t_task **list, t_task *new_task)
{
	if(new_task)
	{
		new_task->next = *list;
		*list = new_task;	
	}
}

void display_task(t_task *list)
{
	t_task *tmp = list;
	int i = 1;
	if(!tmp)
	{
		ft_putstr("aucune tache à afficher\n");
		return;
	}
	while (tmp != NULL)
	{
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr(tmp->name);
		ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
}

void free_tasks(t_task **list)
{
	t_task *tmp ;
	while(*list)
	{
		tmp = (*list)->next;
		free((*list)->name);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
		
