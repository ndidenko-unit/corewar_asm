#include "asm.h"

t_label *ft_create_label(void)
{
	t_label *newlabel;

	newlabel = (t_label*)malloc(sizeof(t_label));
	newlabel->name = NULL;
	newlabel->next = NULL;
	return (newlabel);
}

void	label_in_end(t_label **a, t_label *b)
{
	t_label	*start;

	start = *a;
    if (*a)
	{
		while (start->next)
			start = start->next;
		start->next = b;
		b->next = 0;
	}
	else
	{
		b->next = *a;
		*a = b;
	}
}

// void ft_parse_label(char *line, t_label **label_s)
// {
//     char *tmp;

//     tmp = line;
//     if (ft_detect_command(line) == 0)
//     {
//         while(*tmp != ':') // доделать проверку на пустоту после строки с лейблом и без команды
//             tmp++;
//         tmp++;
//         if (ft_emptyline(tmp) == 0)
//             exit(ft_printf("ERROR in ENDLINE: |%s|\n", line));
//     }
//     if ((*label_s)->name != NULL)
//     {
//         (*label_s) = (*label_s)->next;
//         (*label_s) = ft_create_label();
//     }
//     while (*line == ' ' || *line == '\t')
//         line++;
//     (*label_s)->name = ft_strsub(line, 0, ft_detect_label(line));
//     (*label_s)->next = NULL;
//     // printf("dasd");


// }

void ft_parse_label(char *line, t_label **label_s)
{
    char *tmp;
    t_label *labeltmp;

    tmp = line;
    if (ft_detect_command(line) == 0)
    {
        while(*tmp != ':') // доделать проверку на пустоту после строки с лейблом и без команды
            tmp++;
        tmp++;
        if (ft_emptyline(tmp) == 0)
            exit(ft_printf("ERROR in ENDLINE: |%s|\n", line));
    }
    labeltmp = ft_create_label();
    while (*line == ' ' || *line == '\t')
    line++;
    labeltmp->name = ft_strsub(line, 0, ft_detect_label(line));
    labeltmp->next = NULL;
    label_in_end(&(*label_s), labeltmp);
}


void ft_valid_command_line(char *line, int command)
{
    int len;
    // char *ptr;
    char *msg;

    msg = line;
    if (ft_detect_label(line) != 0)
    {
        while (*line != ':')
            line++;
        line++;
    }
    if (*line == '\0' || *line == '\n')
        return;
    len = ft_strlen(g_operations[command].name);
    // ptr = ft_strstr(line, g_operations[command].name);
    // ptr += ft_strlen(g_operations[command].name);
    // if (ft_strstr(ptr, g_operations[command].name) != 0)
    //     exit(ft_printf("ERROR in line: |%s|\n", msg));
    while (*line == ' ' || *line == '\t')
        line++;
    if (ft_strnequ(line, g_operations[command].name, len) != 1)
        exit(ft_printf("ERROR in line: |%s|\n", msg));

    
}

t_command *ft_parse_cmd(char *line)
{
    t_command *cmd_tmp;
    char *ptr;
    int i;
    int command;

    i = 0;
    command = ft_detect_command_i(line);
    ft_valid_command_line(line, command);
    cmd_tmp = (t_command*)malloc(sizeof(t_command));
    ft_memset(cmd_tmp, 0, sizeof(t_command));
    cmd_tmp->next = NULL;
    if (command != -1)
    {
        ptr = ft_detect_command(line);
        while (*ptr++ != ' ' && *ptr++ != '\t')
            i++;
        cmd_tmp->name = ft_strsub(ft_detect_command(line), 0, i);
        cmd_tmp->inst = 0;
        cmd_tmp->codage = g_operations[command].codage;
        cmd_tmp->opcode = g_operations[command].opcode;
    }
    else
        cmd_tmp->name = ft_strdup("-1");
    return(cmd_tmp);
}

void	cmd_in_end(t_command **a, t_command *b)
{
	t_command	*start;

	start = *a;
    if (*a)
	{
		while (start->next)
			start = start->next;
		start->next = b;
		b->next = 0;
	}
	else
	{
		b->next = *a;
		*a = b;
	}
}

void ft_valid_next_line(t_champ	**main_struct)
{
    while(ft_emptyline((*main_struct)->line))
        get_next_line((*main_struct)->fd, &(*main_struct)->line);
    if (ft_detect_command((*main_struct)->line) == 0 
        && ft_detect_label((*main_struct)->line) == 0)
         exit(ft_printf("ERROR! command not found after label\n"));
}

void ft_cmd(t_champ	**main_struct)
{
    t_command *cmd_s;
    char *arg_s;
    t_label *label_s;
    // ERROR! label not exist: |ardeftgt|
    // diff: champs/examples/fluttershy.cor: No such file or directory

    cmd_s = NULL;
    arg_s = NULL;
    label_s = NULL;
    // label_s = NULL;
    // lbltmp = label_s;
    while (ft_detect_label((*main_struct)->line))
    {
        ft_parse_label((*main_struct)->line, &label_s);
        if (ft_detect_command((*main_struct)->line) != 0)
            break;
        if (!get_next_line((*main_struct)->fd, &(*main_struct)->line))
            break;
        ft_valid_next_line(main_struct);
    }
    // if (ft_detect_command((*main_struct)->line) != 0)
    // {
    cmd_s = ft_parse_cmd((*main_struct)->line);
    // if (label_s->name)
        cmd_s->labels = label_s;
    if (ft_detect_command((*main_struct)->line) != 0)
        arg_s = ft_parse_arg((*main_struct)->line, &cmd_s);
    cmd_in_end(&(*main_struct)->cmds, cmd_s);

    // while (label_s)
    // {
    //     printf("---%s\n", label_s->name);
    //     label_s = label_s->next;
    // }

    // while (cmd_s)
    // {
    //     printf("---%s\n", cmd_s->name);
    //     cmd_s = cmd_s->next;
    // }
    
}