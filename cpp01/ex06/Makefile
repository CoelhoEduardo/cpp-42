NAME	=	replace

SRCS	=	main.cpp 

OBJS	= $(SRCS:.cpp=.o)

RM	= rm -f

FLAGS	=	-Wall -Wextra -Werror -std=c++98

COMPILER	= c++

.cpp.o:
				${COMPILER} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
				${COMPILER} ${FLAGS} ${OBJS} -o $(NAME)

all: $(NAME)

fclean: clean
				$(RM) $(NAME)

clean:
				$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

test: $(NAME)
				@echo "🧪 Test 1 - simple test"
				@echo "Hello world. Hello again." > input1.txt
				@echo -e "input1.txt\nHello\nHi" | ./$(NAME)
				@diff input1.txt.replace <(echo "Hi world. Hi again.") && echo "✓ OK" || echo "✗ Failed"

				@echo "\n🧪 Test 2 - no occurs"
				@echo "No match here." > input2.txt
				@echo -e "input2.txt\nHello\nHi" | ./$(NAME)
				@diff input2.txt.replace input2.txt && echo "✓ OK" || echo "✗ Failed"

				@echo "\n🧪 Test 3 - consecutive replacement"
				@echo "abcabcabc" > input3.txt
				@echo -e "input3.txt\nabc\nx" | ./$(NAME)
				@diff input3.txt.replace <(echo "xxx") && echo "✓ OK" || echo "✗ Failed"

				@$(RM) input*.txt input*.txt.replace

.PHONY: all clean fclean re test .cpp.o
