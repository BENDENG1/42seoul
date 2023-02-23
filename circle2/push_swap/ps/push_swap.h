/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:06:04 by gyroh             #+#    #+#             */
/*   Updated: 2023/02/23 13:24:13 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*top_a;
	t_node	*bottom_a;
	t_node	*top_b;
	t_node	*bottom_b;
	int		size;
	int		size_a;
	int		size_b;
	int		*arr;
	int		*sorted;
	int		cnt;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rra1;
	int		location;
	int		min;
	int		tmp;
	int		idx;
}	t_deque;

void	ft_print_error(void);
void	ft_putnum(int **ret, int *j, char *av);
int		*make_arr(int ac, char **av, int size);
void	parsing(int ac, char **av, t_deque *info);
int		ft_isspace(char c);
void	ft_check_minus(char *str);
int		ft_check_array(char *str);
int		figures(int ac, char **av);
int		ft_wordc(const char *s, char c);
void	quick(int *arr, int L, int R);
void	ft_check_array2(char *str);
void	ft_check_array3(char *str);
void	error_overlap(int *arr, int size);
void	ft_check(int ac, char **av);
void	ft_a(t_deque *info);
void	ft_sa(t_deque *info);
void	insert_tail_a(t_deque *info, int i);
void	insert_head_a(t_deque *info, int i);
void	insert_head_b(t_deque *info, int i);
void	ft_pb(t_deque *info);
void	ft_b(t_deque *info);
void	ft_ra(t_deque *info);
void	ft_rra(t_deque *info);
void	ft_sb(t_deque *info);
void	ft_pa(t_deque *info);
void	ft_rb(t_deque *info);
void	ft_rrb(t_deque *info);
void	case_num3_a(t_deque *info);
void	case_num5_a(t_deque *info);
void	make_a(t_deque *info);
void	ft_stack(t_deque *info);
void	sort1(t_deque *info);
void	sort2(t_deque *info);
void	sort(t_deque *info);
int		ft_high(t_deque *info);
void	exec_op(t_deque *info);
void	find_min_op(t_deque *info);
void	calculate_op(int val, int idx, t_deque *info);
void	cal_op1(t_deque *info, int *ra, int *rb, int *rrb);
void	cal_op2(t_deque *info, int *ra, int *rb, int *rrb);
void	finish(t_deque *info);
void	finish1(t_deque *info, int idx, int min, t_node *p_node);
void	ft_swap(int *x, int *y);

#endif
