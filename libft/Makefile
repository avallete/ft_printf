SRC:=*.c
INCF:=	includes/libft.h\
		includes/get_next_line.h
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(INCF)
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) -c $(CFLAGS) $(SRC) -I includes/
	@echo "${LBLUE}ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${ORANGE}ranlib $(NAME)${NC}"
	@ranlib $(NAME)
	@rm -f $(OBJ)

clean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ)

fclean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ)
	@echo "${CYAN}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

re: fclean all clean
