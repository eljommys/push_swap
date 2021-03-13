/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:14:07 by marvin            #+#    #+#             */
/*   Updated: 2021/03/12 17:14:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_end(char **commands, int ret)
{
	int i;

	i = 0;
	while (commands && commands[i])
		free(commands[i++]);
	if (commands)
		free(commands);
	if (ret)
		write(2, "One of the arguments is invalid!\n", 33);
	exit(ret);
}

int		check_args(int argc, char **argv)
{
	int i;
	int j;
	int a[argc - 1];

	if (argc < 3)
		return 1;
	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (argv[i + 1][++j])
			if ((argv[i + 1][j] < '0' || '9' < argv[i + 1][j]) && argv[i + 1][j] != '-')
				return 1;
		a[i] = ft_atoi(argv[i + 1]);
	}
	i = -1;
	while (++i < argc - 2)
	{
		j = i + 1;
		while (++j < argc - 1)
			if (a[i] == a[j])
				return 1;
	}
	return 0;
}

void	add_char(char **str, char c)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen(*str);
	new = (char *)malloc(sizeof(char) * (len + 2));
	i = -1;
	while (++i < len)
		new[i] = (*str)[i];
	new[i] = c;
	new[i + 1] = 0;
	if (len)
		free(*str);
	*str = new;
}

char	**add_str(char **commands, char *str)
{
	char	**new;
	int		i;
	int		len;

	len = 0;
	while (commands && commands[len])
		len++;
	new = (char **)malloc(sizeof(char *) * (len + 2));
	i = -1;
	while (++i < len)
		new[i] = commands[i];
	new[i] = ft_strdup(str);
	new[i + 1] = 0;
	if (len)
		free(commands);
	if (ft_strlen(str))
		free(str);
	return new;
}
