#include "asm.h"

static void	available_args(int command, int index, int *av_args)
{
	if (g_operations[command].args[index] == 3)
	{
		av_args[0] = T_DIR;
		av_args[1] = T_REG;
	}
	else if (g_operations[command].args[index] == 6)
	{
		av_args[0] = T_DIR;
		av_args[1] = T_IND;
	}
	else if (g_operations[command].args[index] == 5)
	{
		av_args[0] = T_REG;
		av_args[1] = T_IND;
	}
	g_operations[command].args[index] == 7 ? av_args[0] = -1 : 0;
	g_operations[command].args[index] == T_DIR ? av_args[0] = T_DIR : 0;
	g_operations[command].args[index] == T_REG ? av_args[0] = T_REG : 0;
	g_operations[command].args[index] == T_IND ? av_args[0] = T_IND : 0;
	av_args[2] = 0;
}

static int	check_valid_arg(char *line, int command, int index)
{
	int		av_args[4];
	int		arg;
	int		i;

	arg = -1;
	available_args(command, index, av_args);
	line[0] == DIRECT_CHAR ? arg = T_DIR : 0;
	line[0] == 'r' ? arg = T_REG : 0;
	ft_isdigit(line[0]) || (line[0] == '-' && ft_isdigit(line[1]))
			|| line[0] == LABEL_CHAR ? arg = T_IND : 0;
	arg == -1 ? exit(ft_printf("ERROR! no valid arg\n")) : 0;
	i = -1;
	while (++i < 3 && av_args[i])
		if (arg == av_args[i] || av_args[0] == -1)
			break ;
	!av_args[i] ? exit(ft_printf("ERROR! command can't contain this arg\n")) : 0;
	return (arg);
}

char *ft_parse_arg(char *line)
{
    char *lined;
    char **args;
    int cmdlen;
    int i;
    int valid;

    i = -1;
    cmdlen = ft_strlen(g_operations[ft_detect_command_i(line)].name);
    lined = ft_strdup_d(line, '#');
    args = ft_strsplit(ft_detect_command(lined) + cmdlen, ',');
    while(args[++i])
    {
        args[i] = ft_strtrim(args[i]);
        valid = check_valid_arg(args[i], ft_detect_command_i(line), i);
        printf("valid =%d\n", valid);
    }

    return(lined);
}