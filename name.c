#include "asm.h"

static void ft_valid_1line(char *line)
{
    int count;

    count = 0;
    while (*line != '"')
    {
        if (*line == ' ' || *line == '\t')
            ;
        else
            count++;
        line++;
    }
    if (count != 5)
        exit(ft_printf("ERROR in .name\n"));
}

static void ft_valid_last_line(char *line, int type)
{
    while (*line != '"')
        line++;
    line++;
    if (type == 1)
    {
        while (*line != '"')
            line++;
        line++;
    }
    while(*line)
    {
        if (*line == ' ' || *line == '\t')
            line++;
        else if (*line == '#')
            break;
        else
            exit(ft_printf("ERROR in .name\n"));
    }
}

static void ft_name1(t_champ	**main_struct, int f)
{
    char *tmp;

    // char *tmp2 = (*main_struct)->line + f;
    tmp = ft_memalloc(1);
    tmp = ft_strjoin_n(tmp, (*main_struct)->line + f, 0);
    get_next_line((*main_struct)->fd, &(*main_struct)->line);
    while (!ft_strstr_d((*main_struct)->line, "\""))
    {
        tmp = ft_strjoin_n(tmp, ft_strdup_d((*main_struct)->line, '#'), 1);
        if (!get_next_line((*main_struct)->fd, &(*main_struct)->line))
            exit(ft_printf("ERROR in .name\n"));
    }
    ft_valid_last_line((*main_struct)->line, 0);
    tmp = ft_strjoin_n(tmp, ft_strdup_d((*main_struct)->line, '"'), 1);
    (*main_struct)->name = tmp;
    if (ft_strlen((*main_struct)->name) > 128)
        exit(ft_printf("ERROR! .name more then 128 chars\n"));
    // printf("%s", (*main_struct)->name);
    // free(tmp);
}

void ft_name(t_champ	**main_struct)
{
    int i;
    int count[3];

    i = 0;
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    ft_valid_1line((*main_struct)->line);
    while ((*main_struct)->line[i] && (*main_struct)->line[i] != '#')
    {
        if ((*main_struct)->line[i] == '"')
            count[0]++;
        if (count[0] == 1 && count[1] == 0)
            count[1] = i;
        if (count[0] == 2 && count[2] == 0)
            count[2] = i;
        i++;
    }
    if (count[0] == 2)
    {
        (*main_struct)->name = ft_strsub((*main_struct)->line, count[1] + 1, count[2] - count[1] - 1);
        ft_valid_last_line((*main_struct)->line, 1);        
    }
    else if (count[0] == 1)
        ft_name1(main_struct, count[1] + 1);
    else
        exit(ft_printf("ERROR in .name\n"));
    
}