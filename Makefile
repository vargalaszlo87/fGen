CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -std=c11
LDFLAGS = -Llib -lm

# =========================================================
# MAIN PROGRAM
# =========================================================

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

BIN = bin/fgen

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAGS)
	chmod +x $(BIN)

obj/%.o: src/%.c
	@mkdir -p obj
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

# =========================================================
# TEST SYSTEM
# =========================================================

TEST_SRC = $(wildcard tests/*.c)

# src/main.c kivétele a teszt buildből
TESTABLE_SRC = $(filter-out src/main.c, $(SRC))

TEST_BIN = bin/tests

test:
	@mkdir -p bin
	$(CC) \
	$(CFLAGS) \
	$(TEST_SRC) \
	$(TESTABLE_SRC) \
	-o $(TEST_BIN) \
	$(LDFLAGS)

	./$(TEST_BIN)

# =========================================================
# CLEAN
# =========================================================

clean:
	rm -rf obj/*.o $(BIN) $(TEST_BIN)

# =========================================================
# RUN
# =========================================================

run: $(BIN)
	./$(BIN)

# =========================================================
# PHONY
# =========================================================

.PHONY: all clean run test
