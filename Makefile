ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME := libft_malloc_$(HOSTTYPE).so
SYMLINK := libft_malloc.so

CC := cc
DEBUG ?= 0
BASE_CFLAGS := -Wall -Wextra -Werror -fPIC #-fno-builtin-malloc
CFLAGS := $(BASE_CFLAGS)
LDFLAGS := -shared
INCLUDES := -Iinc -Ilibft

SRC_DIR := src
OBJ_DIR := obj
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

TEST_DIR := test
TEST_NAME := $(TEST_DIR)/test_debug
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(TEST_SRCS))
TEST_DEPS := $(TEST_OBJS:.o=.d)
TEST_LDFLAGS := -L. -lft_malloc -Wl,-rpath,'$$ORIGIN/..'

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

RM := rm -f

ifeq ($(DEBUG),1)
CFLAGS += -g -O0
endif

all: $(NAME) $(SYMLINK)

$(NAME): libft $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@

$(SYMLINK): $(NAME)
	ln -sf $(NAME) $(SYMLINK)

libft:
	$(MAKE) -C $(LIBFT_DIR) DEBUG=$(DEBUG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(OBJ_DIR)/test_%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(TEST_NAME)

$(TEST_NAME): $(SYMLINK) $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(TEST_LDFLAGS) -o $@

test_debug:
	$(MAKE) fclean DEBUG=1
	$(MAKE) test DEBUG=1

clean:
	$(RM) -r $(OBJ_DIR) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) clean DEBUG=$(DEBUG)

fclean: clean
	$(RM) $(NAME) $(SYMLINK)
	$(MAKE) -C $(LIBFT_DIR) fclean DEBUG=$(DEBUG)

re: fclean all

debug:
	$(MAKE) re DEBUG=1

-include $(DEPS) $(TEST_DEPS)

.PHONY: all clean fclean re debug libft test test_debug
