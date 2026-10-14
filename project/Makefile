NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES =  -Isrc/analyzer \
			-Isrc/checker \
			-Isrc/parser \
			-Isrc/solver \
			-Isrc/stacker \
			-Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_INCLUDE = -I$(LIBFT_DIR)/

SRC =   src/main \
		src/analyzer/analyzer \
		src/parser/parser \
		src/parser/parser_utils \
		src/stacker/stacker \
		src/stacker/stack_utils \
		src/stacker/stack_operations 


SRCS = $(addsuffix .c, $(SRC))

OBJ_DIR = objs
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled succesfully!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning project objects..."
	$(RM) $(OBJ_DIR)
	@echo "Cleaning libft completed!"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Deep cleaning project executable..."
	$(RM) $(NAME)
	@echo "Deep cleaning libft archive..."
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "Rebuilding project..."

.PHONY: all clean fclean re
