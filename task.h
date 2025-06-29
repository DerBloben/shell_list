#ifndef TASK_H
#define TASK_H

typedef struct s_task{
char *name;
int done;
struct s_task *next;
}t_task;


t_task *create_task(char *name);

void add_task(t_task **list, t_task *new_task);

void display_task(t_task *list);
void free_tasks(t_task **list);
int remove_task(t_task **list, t_task *task);
t_task *find_task(t_task *list,char *name);

#endif


