#include "asm.h"

t_label *ft_create_label(void)
{
	t_label *newlabel;

	newlabel = (t_label*)malloc(sizeof(t_label));
	newlabel->name = NULL;
	newlabel->next = NULL;
	return (newlabel);
}

void ft_parse_label(char *line, t_label **label_s)
{

    if ((*label_s)->name != NULL)
    {
        (*label_s)->next = ft_create_label();
        (*label_s) = (*label_s)->next;
    }
    while (*line == ' ' || *line == '\t')
        line++;
    (*label_s)->name = ft_strsub(line, 0, ft_detect_label(line));
    (*label_s)->next = NULL;
    // printf("dasd");


}

t_command *ft_parse_cmd(char *line)
{
    t_command *cmd_tmp;
    char *ptr;
    int i;
    int command;

    i = 0;
    command = ft_detect_command_i(line);
    cmd_tmp = (t_command*)malloc(sizeof(t_command));
    ft_memset(cmd_tmp, 0, sizeof(t_command));
    cmd_tmp->next = NULL;
    ptr = ft_detect_command(line);
    while (*ptr++ != ' ')
        i++;
    cmd_tmp->name = ft_strsub(ft_detect_command(line), 0, i);
    cmd_tmp->inst = 0;
    cmd_tmp->codage = g_operations[command].codage;
    cmd_tmp->opcode = g_operations[command].opcode;
    return(cmd_tmp);
}


void ft_cmd(t_champ	**main_struct)
{
    t_command *cmd_s;
    char *arg_s;
    t_label *label_s;
    t_label *lbltmp;

    cmd_s = NULL;
    arg_s = NULL;
    label_s = ft_create_label();
    lbltmp = label_s;
    while (ft_detect_label((*main_struct)->line))
    {
        ft_parse_label((*main_struct)->line, &lbltmp);
        if (ft_detect_command((*main_struct)->line) != 0)
            break;
        get_next_line((*main_struct)->fd, &(*main_struct)->line);
    }
    if (ft_detect_command((*main_struct)->line) != 0)
    {
        cmd_s = ft_parse_cmd((*main_struct)->line);
        cmd_s->labels = label_s;
        arg_s = ft_parse_arg((*main_struct)->line);
    }

    while (label_s)
    {
        printf("---%s\n", label_s->name);
        label_s = label_s->next;
    }

    while (cmd_s)
    {
        printf("---%s\n", cmd_s->name);
        cmd_s = cmd_s->next;
    }
    
}