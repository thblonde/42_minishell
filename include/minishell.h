#ifndef MINISHELL_H
# define MINISHELL_H

# include "readline/readline.h"
# include "../libft/libft.h"

typedef enum        e_type
{
    WORD,
    PIPE,
    IN,
    HEREDOC,
    OUT,
    APPEND,
    VAR
}                   t_type;

typedef struct      s_token
{
	t_type			type;
	const char		*lexeme;
	struct s_token	*next;
}					t_token;

typedef struct      s_data
{
    t_list          *var;
    t_token         *tok;
}                   t_data;

int                 init(t_data *d, char **env);
int                 tokenizer(t_data *d, char *rline);
void                ft_tokfree(t_token **lst);

#endif