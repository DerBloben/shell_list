#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "task.h"
#include "utilis.h"
#define TAILLE_MAX 100

int main(void)
{
	char buffer[TAILLE_MAX];
	t_task *list = NULL;
	while(1)
	{
	ft_putstr("Quelle tache souhaitez vous ajouter?");
	ft_putchar('\n');
	
	get_input(buffer,TAILLE_MAX);
	
	if (ft_strcmp(buffer,"exit")==0)
		break;
	
	else
	{
		t_task *new_task = create_task(buffer);
		if (new_task == NULL)
		{
			ft_putstr("erreur d'allocation de mémoire\n");
			break;
		}	
		add_task(&list,new_task);
		display_task(list);
	}
	}
	free_tasks(&list);
	return 0;
}
