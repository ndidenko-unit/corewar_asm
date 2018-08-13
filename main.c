#include "asm.h"



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
        if (ft_strlen(main_struct->line) < 1)
            continue;
        else if (ft_strstr_d(main_struct->line, ".name") && main_struct->name == 0)
            ft_name(&main_struct);
        else if (ft_strstr_d(main_struct->line, ".comment") && main_struct->comment == 0)
            ft_comment(&main_struct);
        free(main_struct->line);
    }
    printf("%s", (main_struct)->name);
    printf("%s", (main_struct)->comment);
    // system ("leaks -quiet asm");
    return (0);
}
