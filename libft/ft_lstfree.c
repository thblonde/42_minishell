#include "libft.h"

void    ft_lstfree(t_list **lst)
{
    t_list  *tmp;

    while (*lst != NULL)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
}
