#include "asm.h"

void		ft_write_bytes(int fd, int c, int bytes)
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

int		ft_botsize(t_champ *main_struct)
{

	int			res;
	t_arg		*arg;
	t_command	*command;

	res = 0;
	command = main_struct->cmds;

	while (command)
	{
		if (!ft_strequ(command->name, "-1"))
		{
			res = res + 1;
			if (command->codage)
				res = res + 1;
			arg = command->inst;
			while (arg)
			{
				res = res + arg->size;
				arg = arg->next;
			}
		}
		command = command->next;
	}
	return (res);
}

static void		ft_write_name(int fd, t_champ *main_struct)
{
	int		i;
	int bot_size;

	bot_size = ft_botsize(main_struct);

	i = 0;
	ft_write_bytes(fd, COREWAR_EXEC_MAGIC, 4);
	while (main_struct->name[i])
	{
		ft_write_bytes(fd, main_struct->name[i], 1);
		i++;
	}
	while (i < 132)
	{
		ft_write_bytes(fd, 0, 1);
		i++;
	}
	ft_write_bytes(fd, bot_size, 4);
}

static void ft_write_comment(int fd, t_champ *main_struct)
{
	int i;
	
	i = 0;
	while (main_struct->comment[i])
	{
		ft_write_bytes(fd, main_struct->comment[i], 1);
		i++;
	}
	i++;
	while (i < 2053)
	{
		ft_write_bytes(fd, 0, 1);
		i++;
	}

}

static void		ft_write_cmd(int fd, t_champ *main_struct)
{
	t_arg		*arg;

	while (main_struct->cmds)
	{
		if (!ft_strequ(main_struct->cmds->name, "-1"))
		{
			arg = main_struct->cmds->inst;
			ft_write_bytes(fd, main_struct->cmds->opcode, 1);
			if (main_struct->cmds->codage)
				ft_write_bytes(fd, main_struct->cmds->codage, 1);
			while (arg)
			{
				ft_write_bytes(fd, arg->value, arg->size);
				arg = arg->next;
			}
		}
		main_struct->cmds = main_struct->cmds->next;
	}
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
	ft_write_cmd(main_struct->fd, main_struct);
	ft_printf("Writing output program to %s\n", file_name);
	close(main_struct->fd);

    


    


}