#include "libft.h"

void    ft_lstprint(t_list *lst)
{
    while (lst)
    {
        ft_putstr_fd((char *)lst->content, 1);
        write(1, "\n", 1);
        lst = lst->next;
    }
}