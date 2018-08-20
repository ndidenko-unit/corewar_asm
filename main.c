#include "asm.h"

int ft_emptyline(char *line)
{
    while (*line)
    {
        if (*line == ' ' || *line == '\t')
            ;
        else if (*line == '#')
            return(1);
        else
            return(0);
        line++;
    }
    return(1);
}

int ft_detect_command_i(char *line)
{
    char *ptr;
    int i;
    int len;
    char *commandsp;

    i = 0;
    ptr = 0;
    
    while (g_operations[i].name)
    {
        commandsp = ft_strjoin(g_operations[i].name, " ");
        ptr = ft_strstr(line, commandsp);
        if (ptr != 0)
        {
            len = ft_strlen(commandsp);
            if (ft_strncmp(ptr, commandsp, len) == 0)
                return(i);
        }
        i++;
        free(commandsp);
    }
    return(-1);
}

char *ft_detect_command(char *line)
{
    char *ptr;
    int i;
    int len;
    char *commandsp;

    i = 0;
    ptr = 0;
    
    while (g_operations[i].name)
    {
        commandsp = ft_strjoin(g_operations[i].name, " ");
        ptr = ft_strstr(line, commandsp);
        if (ptr != 0)
        {
            len = ft_strlen(commandsp);
            if (ft_strncmp(ptr, commandsp, len) == 0)
                return(ptr);
        }
        i++;
        free(commandsp);
    }
    return(0);
}

int ft_detect_label(char *line)
{
    int i;

    i = 0;
    if (ft_strchr(line, LABEL_CHAR) == 0)
        return(0);
    while (*line == ' ' || *line == '\t')
        line++;
    while(*line && *line != '#' && *line != LABEL_CHAR)
    {
        if (ft_strchr(LABEL_CHARS, *line) == 0)
            return(0);
        line++;
        i++;
    }
    if (*line == LABEL_CHAR)
        return(i);
    else 
        return(0);
}

int main (int argc, char **argv)
{
    t_champ	*main_struct;

    if (argc == 1)
        exit(ft_printf("Please add argument\n"));
    main_struct = (t_champ*)malloc(sizeof(t_champ));
    main_struct->name = 0;
    main_struct->comment = 0;
    main_struct->line = 0;
    main_struct->fd = open(argv[1], O_RDONLY);
    if (main_struct->fd == -1)
        exit(ft_printf("ERROR! fd is -1\n"));
    while (get_next_line(main_struct->fd, &main_struct->line))
    {
        if (ft_strlen(main_struct->line) < 1 || ft_emptyline(main_struct->line))
            continue;
        else if (ft_strstr_d(main_struct->line, ".name") && main_struct->name == 0)
            ft_name(&main_struct);
        else if (ft_strstr_d(main_struct->line, ".comment") && main_struct->comment == 0)
            ft_comment(&main_struct);
        else if (ft_detect_command(main_struct->line) != 0 
            || ft_detect_label(main_struct->line) != 0)
        {
            ft_cmd(&main_struct);
            break;
        }

        // else if (ft_detect_label(main_struct->line))
            // printf("detect label\n");
            // ft_cmd_line(&main_struct); // доделать

        free(main_struct->line);
    }
    // system ("leaks -quiet asm");
    return (0);
}
