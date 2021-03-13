/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:29 by marvin            #+#    #+#             */
/*   Updated: 2021/03/10 20:51:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_stack(int *a, int argc, char **argv, int *a_b)
{
	int		i;

	i = -1;
	while (++i < argc - 1)
		a[i] = ft_atoi(argv[i + 1]);
	a_b[0] = argc - 1;
	a_b[1] = 0;
}

int		check_command(char *str)
{
	if (ft_memcmp(str, "sa", 3) && ft_memcmp(str, "sb", 3) && ft_memcmp(str, "ss", 3) && ft_memcmp(str, "pa", 3) &&
		ft_memcmp(str, "pb", 3) && ft_memcmp(str, "ra", 3) && ft_memcmp(str, "rb", 3) && ft_memcmp(str, "rr", 3) &&
		ft_memcmp(str, "rra", 4) && ft_memcmp(str, "rrb", 4) && ft_memcmp(str, "rrr", 4))
		return 1;
	return 0;
}

void	show(int *a, int *b, int *a_b)
{
	int i;

	printf("a =");
	i = -1;
	while (++i < a_b[0] && printf(" "))
		printf("%d", a[i]);
	printf("\n");

	printf("b =");
	i = -1;
	while (++i < a_b[1] && printf(" "))
		printf("%d", b[i]);
	printf("\n");
}

int		check_order(int *a, int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}

void	exec_commands(char **commands, int argc, char **argv)
{
	int		i;
	int		a_b[2];
	int		a[argc - 1];
	int		b[argc - 1];

	set_stack(a, argc, argv, a_b);
	i = -1;
	while (commands && commands[++i])
	{
		if (check_command(commands[i]))
			ft_end(commands, 1);
		if (commands[i][0] == 's')
			swap(commands[i][1], a, b, a_b);
		else if (commands[i][0] == 'p')
			push(commands[i][1], a, b, a_b);
		else if (commands[i][0] == 'r' && ft_strlen(commands[i]) == 2)
			rotate(commands[i][1], a, b, a_b);
		else if (commands[i][0] == 'r' && ft_strlen(commands[i]) == 3)
			r_rotate(commands[i][2], a, b, a_b);
	}
	show(a, b, a_b);
	if (check_order(a, argc - 1) && !a_b[1])
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_end(commands, 0);
}

int		main(int argc, char **argv)
{
	char	c;
	char	*str;
	char	**commands;

	if (check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return 1;
	}
	commands = 0;
	while (1)
	{
		str = 0;
		while (read(0, &c, 1) && c != '\n')
			add_char(&str, c);
		if (!ft_strlen(str))
			break ;
		commands = add_str(commands, str);
	}
	exec_commands(commands, argc, argv);
}
