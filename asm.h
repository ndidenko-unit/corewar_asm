#ifndef ASM_H
# define ASM_H

# include "libft/libft.h"
# include "op.h"
# include <stdio.h>

typedef struct			s_label
{
	char				*name;
	struct s_label		*next;
}						t_label;

typedef struct			s_arg
{
	int					binary;
	int					size;
	unsigned int		value;
	char				*name_label;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_command
{
	char				*name;
	int					codage;
	int					count_args;
	int					label_size;
	int					args[3];
	int					opcode;
	t_label				*labels;
	int					number_byte;
	t_arg				*inst;
	struct s_command	*next;
}						t_command;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	char                *line;
	int					fd;
	t_command			*cmds;
	struct s_champ		*next;
}						t_champ;

char	*ft_strstr_d(char *str, char *to_find);
void	ft_putstr_d(char const *s);
char	*ft_strjoin_n(char *line, char *line2, int flag);
char	*ft_strdup_d(const char *string, char d);
void ft_name(t_champ	**main_struct);
void ft_comment(t_champ	**main_struct);

#endif