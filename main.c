#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "task.h"
#include "utilis.h"
#define TAILLE_MAX 100

int main(void)
{
	char choix[TAILLE_MAX];
	char buffer[TAILLE_MAX];
	t_task *list = NULL;
	while(1)	
{
	menu();
	get_input(choix,TAILLE_MAX);

	if(ft_strcmp(choix,"1")==0)
	{
		get_input(buffer,TAILLE_MAX);
		t_task *new_task = create_task(buffer);
		add_task(&list,new_task);
	}
	else if(ft_strcmp(choix,"2")==0)
	{
		ft_putstr("nom de la tache à supprimer\n");
		get_input(buffer, TAILLE_MAX);
		t_task *task_to_remove=find_task(list,buffer);
		
		if(task_to_remove)
			remove_task(&list,task_to_remove);
		else
			ft_putstr("Tache introuvable");
	}
	else if(ft_strcmp(choix,"3")==0)
	{
		display_task(list);
	}
	else if(ft_strcmp(choix,"4")==0)
		break;
	else
	{
		ft_putstr("choix inconnu\n");
		continue;
	}
}
	
	
	free_tasks(&list);
	return 0;
}
