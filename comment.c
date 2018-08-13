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
    if (count != 8)
        exit(ft_printf("ERROR in .comment\n"));
}

static void ft_valid_last_line(char *line)
{
    while (*line != '"')
        line++;
    line++;
    while(*line)
    {
        if (*line == ' ' || *line == '\t')
            line++;
        else if (*line == '#')
            break;
        else
            exit(ft_printf("ERROR in .comment\n"));
    }
}

static void ft_comment1(t_champ	**main_struct, int f)
{
    char *tmp;
    // char *tmp2 = (*main_struct)->line + f;
    tmp = ft_memalloc(1);
    tmp = ft_strjoin_n(tmp, (*main_struct)->line + f, 0);
    get_next_line((*main_struct)->fd, &(*main_struct)->line);
    while (!ft_strstr_d((*main_struct)->line, "\""))
    {
        tmp = ft_strjoin_n(tmp, ft_strdup_d((*main_struct)->line, '#'), 1);
        get_next_line((*main_struct)->fd, &(*main_struct)->line);
    }
    ft_valid_last_line((*main_struct)->line);
    tmp = ft_strjoin_n(tmp, ft_strdup_d((*main_struct)->line, '"'), 1);
    (*main_struct)->comment = tmp;
    if (ft_strlen((*main_struct)->comment) > 2048)
        exit(ft_printf("ERROR! .comment more then 2048 chars\n"));
    // free(tmp);
}

void ft_comment(t_champ	**main_struct)
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
        (*main_struct)->comment = ft_strsub((*main_struct)->line, count[1] + 1, count[2] - count[1] - 1);
    else if (count[0] == 1)
        ft_comment1(main_struct, count[1] + 1);
    else
        exit(ft_printf("ERROR in .comment\n"));
}