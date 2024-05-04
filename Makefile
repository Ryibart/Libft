# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:30:33 by rtammi            #+#    #+#              #
#    Updated: 2024/05/04 14:47:02 by rtammi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ══| Makefile |══════════════════════════════════════════════════════════════ #
#
# Purpose:    This Makefile is used to automate the compilation and 
#             creation of the "libft.a" library. It defines rules for
#             building the object files, cleaning up intermediate files,
#             and managing the process for normal and bonus builds.
#             
# Primary Targets:
#             all     -- Builds the standard "libft.a" library from the 
#                        source files in `SRCS`.
#             clean   -- Removes all intermediate object files and temporary
#                        files generated during the build process.
#             fclean  -- Performs a full clean, including removal of the 
#                        "libft.a" library.
#             re      -- Rebuilds the library from scratch by calling 
#                        `fclean` followed by `all`.
#
# Usage:	  Use the command `make all` to build the library.
#             To clean the build artifacts, use `make clean`.
#             To completely remove the library, use `make fclean`.
#             To rebuild everything, use `make re`.
#             To include bonus features, use `make bonus`.
#
# Notes:      The Makefile relies on certain assumptions:
#             - The C compiler is specified in `CC`.
#             - The archiver (to create the library) is specified in `AR`.
#             - The `CFLAGS` variable defines the compiler flags.
#             - The `PHONY` declaration ensures make targets are not 
#               mistaken for filenames.
#
# ════════════════════════════════════════════════════════════════════════════ #

NAME	= 	libft.a

AR		= 	ar rcs

CC		= 	cc

CFLAGS 	+=	-Wall -Wextra -Werror

RMF		= 	rm -f

SRCS 	= 	ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_strlen.c			\
			ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strncmp.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strnstr.c		\
			ft_atoi.c			\
			ft_calloc.c			\
			ft_strdup.c			\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_split.c			\
			ft_itoa.c			\
			ft_strmapi.c		\
			ft_striteri.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

clean:
			$(RMF) $(OBJS)

fclean: 	clean
			$(RMF) $(NAME)

re: 		fclean all

$(NAME):	$(OBJS)
			$(AR) $@ $^

%.o : 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all clean fclean re