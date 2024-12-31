#include "../include/minishell.h"

void    ft_tokprint(t_token **lst)
{
    t_token *current;

    current = *lst;
    while (current)
    {
        printf("%s [%d]\n", current->lexeme, current->type);
        current = current->next;
    }
}

void    ft_tokfree(t_token **lst)
{
    t_token  *tmp;

    while (*lst != NULL)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
}

t_token *ft_toklast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_tokadd_back(t_token **lst, t_token *new)
{
	t_token	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_toklast(*lst);
	last->next = new;
}

t_token	*ft_toknew(t_type type, const char *lexeme, int *i)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
    new->lexeme = lexeme;
	new->next = NULL;
    if (type == HEREDOC || type == APPEND)
        (*i)++;
	return (new);
}

void    special_char(t_token **tok, char *rline, int *i)
{
    if (rline[*i] == '|')
        ft_tokadd_back(tok, ft_toknew(PIPE, "|", i));
    else if (rline[*i] == '<' && rline[*i + 1] == '<')
        ft_tokadd_back(tok, ft_toknew(HEREDOC, "<<", i));
    else if (rline[*i] == '<')
        ft_tokadd_back(tok, ft_toknew(IN, "<", i));
    else if (rline[*i] == '>' && rline[*i + 1] == '>')
        ft_tokadd_back(tok, ft_toknew(APPEND, ">>", i));
    else if (rline[*i] == '>')
        ft_tokadd_back(tok, ft_toknew(OUT, ">", i));
}

void    word(t_token **tok, char *rline, int *i)
{
    t_token *word;
    char    *tmp;
	int		j;

	j = *i;
	while (rline[j] && rline[j] != ' ' && rline[j] != '\t' && rline[j] != '|' && rline[j] != '<'
		&& rline[j] != '>')
		j++;
	tmp = ft_substr(rline, *i, j - *i);
    if (rline[*i] == '$')
        word = ft_toknew(VAR, tmp, i);
    else
	    word = ft_toknew(WORD, tmp, i);
    ft_tokadd_back(tok, word);
	*i = j - 1;
}

int tokenizer(t_data *d, char *rline)
{
    int i;

    i = 0;
    while (rline[i])
    {
        while (rline[i] && (rline[i] == ' ' || rline[i] == '\t'))
            i++;
        if (rline[i] == '|' || rline[i] == '<' || rline[i] == '>')
            special_char(&d->tok, rline, &i);
        else
            word(&d->tok, rline, &i);
        i++;
    }
    //ft_tokprint(&d->tok);
    return (0);
}