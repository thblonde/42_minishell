#include "../include/minishell.h"

int main()
{
    char    *rline;

    (void)rline;
    while (1)
    {
        rline = readline("$  ");
    }
    return (0);
}
