LIBFT_PATH = libft

NAME = Push_Swap

SCRS = push_swap.c\
error_msgs.c\
parse_string.c\
stack_node_utils.c\
binary_tree_functions.c\
utils.c\
stack_operations_a.c\
stack_operations_b.c\
stack_operations_combined.c\
sorting_cases.c\
stack_node_utils2.c\
prepare_stack_a.c\
move_a_to_b.c\
prepare_stack_b.c\

OBJS = $(SCRS:.c=.o)

HEADER = push_swap.h

COMPILER = CC
CFLAGS= -Wall -Werror -Wextra
LIBRARY_FLAG = -Llibft -lft -o

RM = rm -rf

all: make-library $(NAME)

make-library:
	$(MAKE) -C $(LIBFT_PATH)

make-library-debug:
	$(MAKE) -C $(LIBFT_PATH) debug

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
debug: make-library-debug $(NAME)