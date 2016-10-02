/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:57:21 by vrybalko          #+#    #+#             */
/*   Updated: 2016/10/02 20:00:13 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_i;
int		g_j;
int		g_st;
int		g_width;

int		ft_putchar(char c);

int		count_width(int size, int width, int st_height, int jump)
{
	int i;

	i = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		if ((i + 1) % 2 == 0)
			jump = jump + 1;
		if (i + 1 == 1)
		{
			width = width + (st_height + 1);
		}
		else
		{
			width = width + jump * 2 + (st_height + i + 1) * 2;
		}
		i++;
	}
	return (width);
}

int		count_height(int i, int size, int height)
{
	while (i < size)
	{
		height = height + (3 + i);
		i++;
	}
	return (height);
}

void	print_line(int *spaces, int line_width, int door_size, int is_lock)
{
	g_i = 0;
	g_st = *spaces + (line_width / 2) + 1;
	while (g_i <= line_width + *spaces)
	{
		if (g_i <= *spaces)
			ft_putchar(' ');
		if (g_i == *spaces + 1)
			ft_putchar('/');
		if (g_i > *spaces + 1 && g_i < *spaces + line_width)
		{
			if (door_size > 0 && g_i > g_st - (door_size / 2 + 1) &&
					g_i < g_st + (door_size / 2 + 1))
			{
				if (is_lock && g_i == g_st + (door_size / 2 + 1) - 2)
					ft_putchar('$');
				else
					ft_putchar('|');
			}
			else
				ft_putchar('*');
		}
		g_i++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_block(int block_num, int *spaces, int door_size, int i)
{
	int	block_h;
	int	line_width;

	block_h = count_height(0, block_num, 0) - count_height(0, block_num - 1, 0);
	if (block_num == 1)
		line_width = 3;
	else
		line_width = count_width(block_num, 3, 3, 0) - (block_h - 1) * 2;
	while (i <= block_h)
	{
		if (i > (block_h - door_size))
		{
			if (i == (door_size / 2) + 1 + (block_h - door_size) &&
					door_size >= 5)
				print_line(spaces, line_width, door_size, 1);
			else
				print_line(spaces, line_width, door_size, 0);
		}
		else
			print_line(spaces, line_width, 0, 0);
		line_width = line_width + 2;
		*spaces = *spaces - 1;
		i++;
	}
}

void	sastantua(int size)
{
	int	spaces;
	int	*sp;
	int	jump;
	int	door_size;

	g_width = count_width(size, 3, 3, 0);
	g_j = 0;
	jump = 1;
	spaces = (g_width - 3) / 2;
	sp = &spaces;
	if (size % 2 == 0)
		door_size = size - 1;
	else
		door_size = size;
	while (g_j <= size)
	{
		if (g_j == size)
			print_block(g_j, sp, door_size, 1);
		else
			print_block(g_j, sp, 0, 1);
		g_j++;
		if (g_j % 2 == 0)
			jump = jump + 1;
		*sp = *sp - jump;
	}
}
