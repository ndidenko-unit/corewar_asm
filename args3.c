#include "asm.h"

static void	ft_arg_label(char *line, int command, int i, t_command **b)
{
	char	*buff;
	t_arg	*arg;
    char	*start;

	if (i + 1 == g_operations[command].count_args
			&& ft_strchr(line, COMMENT_CHAR))
		buff = ft_strdup_d(line, COMMENT_CHAR);
	else
		buff = ft_strdup(line + 2);
    start = buff;
    while (*start)
	{
		if (!ft_strchr(LABEL_CHARS, *start))
			exit(ft_printf("'%c' is forbidden in label-name\n", *start));
		start++;
	}
	arg = (t_arg*)malloc(sizeof(t_arg));
	arg->size = g_operations[command].label_size;
	arg->name_label = ft_strdup(buff);
	arg->binary = 2;
    arg->value = -1;
	arg_in_end(&(*b)->inst, arg);
	ft_strdel(&buff);
}

void		ft_parse_dir(char *line, int command, int i, t_command **cmd_s)
{
	int		j;
	t_arg	*arg;

	if (line[1] != LABEL_CHAR)
    {
        j = 1;
		if (line[1] != '-' && !ft_isdigit(line[1]))
			exit(ft_printf("% has bad value\n"));
		if (line[1] == '-')
			j++;
		while (line[j] && ft_isdigit(line[j]))
			j++;
		if (i + 1 != g_operations[command].count_args && line[j] != 0)
			exit(ft_printf("ERROR in arg T_DIR\n"));
		arg = (t_arg*)malloc(sizeof(t_arg));
		arg->size = g_operations[command].label_size;
		arg->name_label = 0;
		arg->binary = 2;
        arg->value = atoi_arg(line + 1);
		arg_in_end(&(*cmd_s)->inst, arg);
    }
	else
	    ft_arg_label(line, command, i, cmd_s);
}
