/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:36:28 by masoares          #+#    #+#             */
/*   Updated: 2023/10/26 19:02:48 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	search_temp(char *temp)
{
	int	i;

	i = 0;
	if (temp == NULL)
		return (0);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		return (1);
	return (0);
}

char	*add_to_line(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (!*temp)
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	str = ft_calloc(1, (i + 2));
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			str[i] = '\n';
			i++;
			break ;
		}
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_calloc(size_t size, int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (NULL);
	i = 0;
	str = (char *) malloc (size * (n));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_freeing(char **buffer, char **temp)
{
	free(*temp);
	free(*buffer);
	*temp = NULL;
	return (NULL);
}
