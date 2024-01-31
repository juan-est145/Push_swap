LIBFT_PATH = libft

NAME = Push_Swap

SCRS = push_swap.c\
error_msgs.c\
parse_string.c\

OBJS = $(SCRS:.c=.o)

HEADER = push_swap.h

COMPILER = CC
CFLAGS= -Wall -Werror -Wextra
LIBRARY_FLAG = -Llibft -lft -o

RM = rm -rf

all: make-library $(NAME)

make-library:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(HEADER)
	$(COMPILER) $(CFLAGS) $(LIBRARY_FLAG) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

debug: CFLAGS += -g
debug: all