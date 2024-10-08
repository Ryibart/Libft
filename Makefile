# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:30:33 by rtammi            #+#    #+#              #
#    Updated: 2024/10/08 15:55:23 by rtammi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ══| Makefile |══════════════════════════════════════════════════════════════ #
#
# Purpose:    This Makefile is used to automate the compilation and 
#             creation of the "libft.a" library. It defines rules for
#             building the object files, cleaning up intermediate files,
#             and managing the process for builds.
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
#
# ════════════════════════════════════════════════════════════════════════════ #

NAME        := libft.a

CC          := cc

CFLAGS      := -Wall -Wextra -Werror
DEPSFLAGS   := -MMD -MP
HEADERFLAG  := -I includes/
ECHOFLAG	:= 

AR          := ar rcs
RM          := rm -rf

# Directories
OBJ_DEP_DIR	:= objects_and_dependencies
LIB_DIR     := library

# Source directories
SRC_DIRS    := ft_printf gnl fd is lst mem str misc
SRC_DIRS_OBJ := $(addprefix $(OBJ_DEP_DIR)/, $(SRC_DIRS))

# Source files
FT_PRINTF	:= 	ft_printf.c						\
				utilities.c 					\
				print_functions/print_char.c	\
				print_functions/print_hex.c		\
				print_functions/print_nbr.c		\
				print_functions/print_ptr.c		\
				print_functions/print_str.c		\
				print_functions/print_uint.c

GNL			:= 	get_next_line.c					\
				get_next_line_utils.c

FD			:= 	ft_putchar_fd.c					\
				ft_putstr_fd.c					\
				ft_putendl_fd.c					\
				ft_putnbr_fd.c

IS			:= 	ft_isalpha.c					\
				ft_isdigit.c					\
				ft_isalnum.c					\
				ft_isascii.c					\
				ft_isprint.c					\
				ft_isspace.c

LST			:= 	ft_lstnew.c						\
				ft_lstadd_front.c				\
				ft_lstsize.c					\
				ft_lstlast.c					\
				ft_lstadd_back.c				\
				ft_lstdelone.c					\
				ft_lstclear.c					\
				ft_lstiter.c					\
				ft_lstmap.c

MEM			:= 	ft_calloc.c						\
				ft_memchr.c						\
				ft_memcmp.c						\
				ft_memset.c						\
				ft_bzero.c						\
				ft_memcpy.c						\
				ft_memmove.c

STR			:= 	ft_strmapi.c					\
				ft_striteri.c					\
				ft_strdup.c						\
				ft_substr.c						\
				ft_strjoin.c					\
				ft_strtrim.c					\
				ft_strchr.c						\
				ft_strrchr.c					\
				ft_strncmp.c					\
				ft_strnstr.c					\
				ft_strlcpy.c					\
				ft_strlcat.c					\
				ft_strlen.c						\
				ft_strtol.c

MISC		:= 	ft_atoi.c						\
				ft_split.c						\
				ft_itoa.c						\
				ft_toupper.c					\
				ft_tolower.c

VEC			:=	vector_append.c					\
				vector_clear.c					\
				vector_copy.c					\
				vector_filter.c					\
				vector_find.c					\
				vector_free.c					\
				vector_from.c					\
				vector_get.c					\
				vector_insert.c					\
				vector_iter.c					\
				vector_map.c					\
				vector_new.c					\
				vector_pop_first.c				\
				vector_pop_last.c				\
				vector_prepend.c				\
				vector_push_first.c				\
				vector_push_last.c				\
				vector_reduce.c					\
				vector_remove.c					\
				vector_resize.c					\
				vector_sort.c					\
				vector_typecast.c

SRCS        := $(addprefix ft_printf/, $(FT_PRINTF)) \
               $(addprefix gnl/, $(GNL)) \
               $(addprefix fd/, $(FD)) \
               $(addprefix is/, $(IS)) \
               $(addprefix lst/, $(LST)) \
               $(addprefix mem/, $(MEM)) \
               $(addprefix str/, $(STR)) \
               $(addprefix misc/, $(MISC)) \
			   $(addprefix vec/, $(VEC))

# Object and Dependency Files
OBJS        := $(SRCS:%.c=$(OBJ_DEP_DIR)/%.o)

# Color and Style Codes
YELLOW      := \033[33m
GREEN       := \033[32m
BLUE        := \033[34m
RED         := \033[31m
BOLD        := \033[1m
NC          := \033[0m

# Message Helpers
linking_message      	= @echo $(ECHOFLAG) "$(YELLOW)🔗 Linking $1...$(NC)"
build_success_message	= @echo $(ECHOFLAG) "$(GREEN)🥳 $(BOLD)$1 built successfully!$(NC)"
compile_message    		= @echo $(ECHOFLAG) "$(BLUE)🤔 Compiling $<...$(NC)"
compile_success_message	= @echo $(ECHOFLAG) "$(GREEN)🥳 $(BOLD)Compiled $< successfully!$(NC)"
compile_fail_message 	= @echo $(ECHOFLAG) "$(RED)💥 $(BOLD)Failed to compile $<!$(NC)"
clean_message        	= @echo $(ECHOFLAG) "$(YELLOW)🚮 Cleaning up...$(NC)"
clean_success_message	= @echo $(ECHOFLAG) "$(GREEN)🧹 $(BOLD)Cleaned up object and dependency files!$(NC)"
fclean_message        	= @echo $(ECHOFLAG) "$(YELLOW)😱 Removing library...$(NC)"
fclean_success_message	= @echo $(ECHOFLAG) "$(GREEN)🫡 $(BOLD)Library removed!$(NC)"

# Rules
all: create_dirs $(LIB_DIR)/$(NAME)

$(LIB_DIR)/$(NAME): $(OBJS)
	$(call linking_message,$@)
	@$(AR) $@ $^
	$(call build_success_message,$@)

# Create directories
create_dirs:
	@mkdir -p $(OBJ_DEP_DIR) $(LIB_DIR)

# Compile source files to object files
$(OBJ_DEP_DIR)/%.o: %.c
	$(call compile_message)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPSFLAGS) $(HEADERFLAG) -c $< -o $@ || { $(call compile_fail_message); exit 1; }
	$(call compile_success_message)

clean:
	$(call clean_message)
	@$(RM) $(OBJ_DEP_DIR)
	$(call clean_success_message)

fclean: clean
	$(call fclean_message)
	@$(RM) $(LIB_DIR)
	$(call fclean_success_message)

re: fclean all
# Check dependencies and rebuild if necessary
redeps: $(DEPS)
	@$(MAKE) -s all

-include $(DEPS)

.PHONY: all clean fclean re create_dirs