#include "asm.h"

int ft_emptyline(char *line)
{
    while (*line)
    {
        if (*line == ' ' || *line == '\t')
            ;
        else if (*line == '#' || *line == ';')
            return(1);
        else
            return(0);
        line++;
    }
    return(1);
}

void ft_init(t_champ	**main_struct, int argc, char **argv)
{
    if (argc == 1)
        exit(ft_printf("Please add argument\n"));
    (*main_struct) = (t_champ*)malloc(sizeof(t_champ));
    (*main_struct)->name = 0;
    (*main_struct)->comment = 0;
    (*main_struct)->line = 0;
    (*main_struct)->cmds = 0;
    (*main_struct)->fd = open(argv[1], O_RDONLY);
    if ((*main_struct)->fd == -1)
        exit(ft_printf("ERROR! fd is -1\n"));
}

int main (int argc, char **argv)
{
    t_champ	*main_struct;

    // if (argc == 1)
    //     exit(ft_printf("Please add argument\n"));
    // main_struct = (t_champ*)malloc(sizeof(t_champ));
    // main_struct->name = 0;
    // main_struct->comment = 0;
    // main_struct->line = 0;
    // main_struct->cmds = 0;
    // main_struct->fd = open(argv[1], O_RDONLY);
    // if (main_struct->fd == -1)
    //     exit(ft_printf("ERROR! fd is -1\n"));
    ft_init(&main_struct, argc, argv);
    while (get_next_line(main_struct->fd, &main_struct->line))
    {
        if (ft_strlen(main_struct->line) < 1 || ft_emptyline(main_struct->line))
        {
            free(main_struct->line);
            continue;
        }
        else if (ft_strstr_d(main_struct->line, ".name") && main_struct->name == 0)
            ft_name(&main_struct);
        else if (ft_strstr_d(main_struct->line, ".comment") && main_struct->comment == 0)
            ft_comment(&main_struct);
        else if (ft_detect_command(main_struct->line) != 0 || ft_detect_command(main_struct->line) != 0
            || ft_detect_label(main_struct->line) != 0)
            ft_cmd(&main_struct);
        else
            exit(ft_printf("ERROR! not valid line: |%s|\n", main_struct->line));
        free(main_struct->line);
    }
    ft_set_value(&main_struct);
    close(main_struct->fd);
    ft_write_in_file(argv[1], main_struct);
    // while(main_struct->cmds)
    // {
    //     printf("cmds->name = %s\n", main_struct->cmds->name);
    //     printf("cmds->codage = %d\n", main_struct->cmds->codage);
    //     printf("cmds->count_args = %d\n", main_struct->cmds->count_args);
    //     printf("cmds->label_size = %d\n", main_struct->cmds->label_size);
    //     printf("cmds->opcode = %d\n", main_struct->cmds->opcode);
    //     printf("cmds->number_byte = %d\n", main_struct->cmds->number_byte);
    //     if (main_struct->cmds->labels)
    //     {
    //         while (main_struct->cmds->labels)
    //         {
    //             printf("cmds->labels = %s\n", main_struct->cmds->labels->name);
    //             main_struct->cmds->labels = main_struct->cmds->labels->next;
    //         }
    //     }
    //     if (main_struct->cmds->inst)
    //     {
    //         while (main_struct->cmds->inst)
    //         {
    //             printf("args namelabel = %s, binary =%d, size =%d value =%d\n", main_struct->cmds->inst->name_label,
    //                      main_struct->cmds->inst->binary, main_struct->cmds->inst->size, main_struct->cmds->inst->value);
    //             main_struct->cmds->inst = main_struct->cmds->inst->next;
    //         }
    //     }
    //     main_struct->cmds = main_struct->cmds->next;
    //     printf("\n---------------\n");
    // }
    // system ("leaks -quiet asm");
    return (0);
}
