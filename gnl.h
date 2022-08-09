#ifndef GETNL_H
# define GETNL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	ft_reapp_instruct(char *line, t_stack **stacka, t_stack **stackb);
char	*getnl(int fd);
void	sa(t_stack *stacka);
void	pa(t_stack **stacka, t_stack **stackb, int index);
void	ra(t_stack **stacka);
void	rra(t_stack **stacka);
void	rr(t_stack **stacka, t_stack **stackb);
void	rrr(t_stack **stacka, t_stack **stackb);
void	ss(t_stack *stacka, t_stack *stackb);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_stack_issorted(t_stack *stacka);
t_stack	*ft_fill_stack1(int argc, char **argv);
t_stack	*ft_lstnew(int content, int index);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int		ft_lstsize(t_stack *lst);
int		check_arg(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strtrim(char const *s1, char const *set);

#endif