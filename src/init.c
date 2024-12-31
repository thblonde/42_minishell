#include "../include/minishell.h"

int dup_env(t_list  **var, char **env)
{
    t_list  *new;

    while (*env)
    {
        new = ft_lstnew((char *)(*env));
        if (new == NULL)
            return (ft_lstfree(var), 1);
        ft_lstadd_back(var, new);
        env++;
    }
    return (0);
}

int init(t_data *d, char **env)
{
    ft_memset(d, 0, sizeof(t_data));
    if (dup_env(&d->var, env))
        return (1);
    return (0);
}