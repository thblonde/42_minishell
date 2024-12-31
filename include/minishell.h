#ifndef MINISHELL_H
# define MINISHELL_H

# include "readline/readline.h"
# include "../libft/libft.h"

typedef struct      s_data
{
    t_list          *var;
}                   t_data;

int                 init(t_data *d, char **env);

#endif