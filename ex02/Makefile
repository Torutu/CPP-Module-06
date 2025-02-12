NAME = identify
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp Base.cpp Identify.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Color codes for output
RED = \033[31m
GREEN = \033[32m
MAGENTA = \033[35m
RESET = \033[0m

SHELL := /bin/bash

all: $(NAME)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ echo -ne "$(MAGENTA)Building $(NAME)"
	@ ( \
        trap 'echo -e "$(RED)Build interrupted by user $(RESET)"; exit 1' INT; \
        $(CC) $(CFLAGS) -o $(NAME) $(OBJ) & \
        PID=$$!; \
        while kill -0 $$PID 2>/dev/null; do \
            echo -n "."; \
            sleep 0.4; \
            echo -n "."; \
            sleep 0.6; \
            echo -n "."; \
            sleep 0.2; \
        done; \
        wait $$PID; \
    )
	@ echo -e "\n$(GREEN)Build complete!$(RESET)"

# Compile .cpp to .o and store in obj directory
$(OBJ_DIR)/%.o: %.cpp
	@ echo -e "$(MAGENTA)Compiling $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ echo -e "$(RED)Cleaning object files and directories...$(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ echo -e "$(RED)Cleaning binary: $(NAME)$(RESET)"
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re