all:
	gcc -Wall -Wextra -Werror *.c -I includes/ -L libft/ -lft
nf:
	gcc -w *.c -I includes/ -L libft/ -lft
