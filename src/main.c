#include "../include/minishell.h"

int main(int argc, char *argv[], char **env)
{
    char    *rline;
    t_data  d;

    (void)argc;
    (void)argv;
    (void)rline;
    if (init(&d, env))
        return (1);
    while (1)
        rline = readline("$  ");
    return (0);
}
