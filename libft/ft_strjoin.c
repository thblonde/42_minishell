/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:11:46 by thblonde          #+#    #+#             */
/*   Updated: 2024/10/18 17:52:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i] = s2[j];
		j++;
		i++;
	}
	array[i] = '\0';
	return (array);
}
