
CXX = clang++
CXXFLAGS = -Wall -Werror -I /Users/hlriabts/homebrew/Cellar/sfml/2.4.2_1/include
CXXXFLAGS = -Wall -Werror  -lncurses -L /Users/hlriabts/homebrew/Cellar/sfml/2.4.2_1//lib -lsfml-graphics -lsfml-window -lsfml-system
NAME = ft_gkrellm
SRCDIR = src/
SRC =  main.cpp IMonitorModule.cpp CPUModule.cpp ncDisplay.cpp visDisplay.cpp IMonitorDisplay.cpp SystemInfoModule.cpp HostUserModule.cpp TimeModule.cpp RAMModule.cpp NetworkModule.cpp
SRCS = $(addprefix $(SRCDIR), $(SRC))


OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all