#include "../include/minishell.h"

void    reinit(t_data *d)
{
    ft_memset(d->tok, 0, sizeof(t_token));
    ft_tokfree(&d->tok);
}

int main(int argc, char *argv[], char **env)
{
    char    *rline;
    t_data  d;

    (void)argc;
    (void)argv;
    if (init(&d, env))
        return (1);
    while (1)
    {
        rline = readline("$  ");
        if (tokenizer(&d, rline))
            return (1);
        reinit(&d);
    }
    return (0);
}
