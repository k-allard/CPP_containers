NAME = my_containers

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-std=c++98
FLAGS2 =-Wall -Wextra -Werror
FLAGS3 =-g -fsanitize=address

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing $(NAME)...\x1b[0m"
	clang++ -o $(NAME) $(SRCS) $(FLAGS) $(FLAGS2)
	@echo "\x1b[32m $(NAME) are ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@./my_containers

performance: fclean
	@echo "\x1b[33m Preparing $(NAME)...\x1b[0m"
	clang++ -D PERFORMANCE -o $(NAME) $(SRCS) $(FLAGS) $(FLAGS2)
	@echo "\x1b[32m $(NAME) are ready for performance testing!\x1b[0m"

%.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re
