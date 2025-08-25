CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LFLAGS = -lmlx -lX11 -lXext -lm

# Sources and Objects
SRCS = gget_next_line.c floodothers.c ft_ex.c get_next_line_utils.c \
       libfun2.c libfun.c main.c movements.c so_lll.c ft_printf.c

OBJS = $(SRCS:.c=.o)

# Output file

NAME = so_long

# Directory for object files
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Default target
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

# Compiling individual source files
$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Full cleanup (remove both object files and executable)
fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
