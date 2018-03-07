/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libzs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggambino <ggambino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:42:18 by ggambino          #+#    #+#             */
/*   Updated: 2015/09/10 21:42:19 by ggambino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBZS_H
# define LIBZS_H

# include <unistd.h>
# include <stdlib.h>

# define ZBUFFSIZE 4096

int		zstrlen(char *str);
void	zputchar(char c);
void	zputstr(char *str);
void	zputnbr(int nbr);
void	znprint(char *str);

char	*zstralloc(int size);
char	*zstrdup(char *str);
void	zstrcpy(char *str1, char *str2);
void	zstrcat(char *str1, char *str2);
char	*zstrconcat(char *str1, char *str2);

char	*zbuf_addchar(char *buffer, char data, int *byte);
char	*zbuf_addstr(char *buffer, char *str, int *byte);
char	*zbuf_clean(char *buffer);

char	*zsubstr(char *str, int start, int len);
int		zstrncmp(char *str1, char *str2, int n);
int		zstrcmp(char *str1, char *str2);
int		zstrnpos(char *str, char *sub, int offset);
int		zstrpos(char *str, char *sub);

char	*zimplode(char *delimiter, char **list);
char	**zexplode(char *delimiter, char *str);

int		zatoi(char *str);
char	*zitoa(int n);

char	*zencode(char *str);
char	*zdecode(char *str);
void	zencodefd(int source, int destination);
void	zdecodefd(int source, int destination);

char	*zfilegetcontents(int fd, int *eof);
char	*zreadany(int fd, int *eof, char delimiter);
char	*zreadstring(int fd, int *eof);
char	*zreadline(int fd, int *eof);

int		zstrarraylen(char **data);

void	zremovespace(char *data);
void	zucase(char *data);
void	zlcase(char *data);

void	*zmemcpy(void *s1, void *s2, int n);
void	*zmemcpyoffset(void *s1, void *s2, int n, int offset);

#endif
