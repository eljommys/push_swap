CHK =	checker/main.c\
		checker/commands.c\
		checker/utils.c

LIB =	minilibft.c

FLG =	-Wall -Werror -Wextra -g3 -fsanitize=address

MSG =	default commit message

all:
	@echo "Available commands:\n\tchecker\n\tpush\n\tgit"

checker:
	gcc $(FLG) $(CHK) $(LIB) -o checker

git:
	git add .
	git commit -m "$(MSG)"
	git push
