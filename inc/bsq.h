/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:44 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:40:10 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 5000000

typedef struct	s_grid
{
	char		*content;
	int			contentlength;
	int			width;
	int			height;
	char		obstacle_char;
	char		empty_char;
	char		square_char;
	int			grid_start_index;
}				t_grid;

t_grid			creategrid(int file_desc);
void			freegrid(t_grid board);
int				checkvalidchars(t_grid board);
int				checklinewidth(t_grid board);
int				isvalidgrid(t_grid board);
void			processfile(int file_desc);

char			*sub_str(char *str, int start, int end);
int				ft_strlen(char *str);
char			*ft_strcat(char *strd, char *stra, int olds, int adds);

char			*file_to_str(int fd);
int				ft_atoi(char *str);
int				indexof(char *str, char tofind, int start);
int				nindexof(char *str, char tofind, int hit);
int				ft_min(int a, int b);
int				ft_min2(int a, int b, int c);
int				countchar(char *str, char token);

int				lineindex(int linenumber, t_grid board);
int				indexat(int x, int y, t_grid board);
char			getat(int x, int y, t_grid board);
void			setat(int x, int y, t_grid board);
int				maxsquaresize(t_grid board);
int				hasobstacles(int x, int y, int size, t_grid board);
void			printgridcontent(t_grid board);
void			printgridinfo(t_grid board);

int				findsquareposition(int size, t_grid board, int square[]);
void			findbiggestsquare(t_grid board, int square[]);
void			printsquare(t_grid board, int square[]);
void			drawsquare(t_grid board, int square[]);
int				*buildmemboard(int width, int height);
void			buildargs(int args[], int arg1, int arg2, int arg3);
void			findmaxsquarefrommemo(int mem[], int wid, int heig, int sqr[]);

void			populateleftline(t_grid board, int *memo);
void			populateat(int i, int j, t_grid board, int *memo);
void			populateall(t_grid board, int *memo);
void			populatetopline(t_grid board, int *memo);

char			getmemoat(int x, int y, int width, int boardcontent[]);
char			setmemoat(int square[], int boardcontent[], int val);

#endif
