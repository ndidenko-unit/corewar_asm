#include "asm.h"

void		write_bytes(int fd, int c, int bytes)
{
	int				j;
	unsigned char	mass[bytes];

	j = bytes;
	while (bytes)
	{
		bytes--;
		mass[bytes] = (unsigned char)c;
		c >>= 8;
	}
	while (bytes < j)
    {
		write(fd, &mass[bytes], 1);
        bytes++;
    }
}

int		ft_botsize(t_champ *a)
{

	int			res;
	t_champ	*command;
	t_arg		*arg;

	res = 0;
	command = a;

	while (command->cmds)
	{
		if (ft_strcmp(command->cmds->name, "-1") != 0)
		{
			res++;
			if (command->cmds->codage)
				res++;
			arg = command->cmds->inst;
			while (arg)
			{
				res = res + arg->size;
				arg = arg->next;
			}
		}
		command->cmds = command->cmds->next;
	}
	return (res);
}

static void		ft_write_name(int fd, t_champ *a)
{
	int		i;
	int bot_size;

	bot_size = ft_botsize(a);

	i = 0;
	write_bytes(fd, COREWAR_EXEC_MAGIC, 4);
	while (a->name[i])
	{
		write_bytes(fd, a->name[i], 1);
		i++;
	}
	while (i < 132)
	{
		write_bytes(fd, 0, 1);
		i++;
	}
	write_bytes(fd, bot_size, 4);
}

static void ft_write_comment(int fd, t_champ *a)
{
	int i;
	
	i = -1;
	while (a->comment[++i])
		write_bytes(fd, a->comment[i], 1);
	while (++i < 2053)
		write_bytes(fd, 0, 1);
}

void ft_write_in_file(char *argv, t_champ	*main_struct)
{
    char *file_name;
    int argv_len = ft_strlen(argv);

    if (argv[argv_len - 2] != '.' || argv[argv_len - 1] != 's')
        exit(ft_printf("ERROR! is not .s file!\n"));
    file_name = ft_strsub(argv, 0, argv_len - 2);
    file_name = ft_strjoin_n(file_name, ".cor", 0);
    file_name[ft_strlen(file_name) - 1] = '\0';
    main_struct->fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	ft_write_name(main_struct->fd, main_struct);
	ft_write_comment(main_struct->fd, main_struct);
	ft_printf("Writing output program to %s\n", file_name);
	close(main_struct->fd);

    


    


}