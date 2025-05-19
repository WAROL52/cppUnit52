NAME	=	a.out

FILES	=	*.cpp

OBJ			=	$(FILES:.cpp=.o)
CC			=	g++
AR			=	ar -rcs
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
CFLAGS_RUN	=	-g $(CFLAGS)
RM				=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "make $(NAME): OK!"

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "delete *.o: OK!"

fclean: clean
	@$(RM) $(NAME)
	@echo "delete $(NAME): OK!"

re:	fclean all


run:$(OBJ)
	clear
	@$(CC) $(CFLAGS_RUN) $(OBJ) -o $(NAME)
	@echo "make $(NAME): OK!"
	valgrind --leak-check=full  ./$(NAME)

.PHONY: all, clean, fclean, re