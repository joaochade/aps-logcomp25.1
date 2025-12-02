# Makefile para CoffeeLang Compiler

CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -g

# Arquivos
LEXER = coffee.l
PARSER = coffee.y
LEXER_C = lex.yy.c
PARSER_C = coffee.tab.c
PARSER_H = coffee.tab.h
EXECUTABLE = coffeec

# Arquivos de teste
TEST_INPUT = exemplo.coffee
TEST_OUTPUT = output.asm

all: $(EXECUTABLE)

$(EXECUTABLE): $(LEXER_C) $(PARSER_C)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(PARSER_C) $(LEXER_C) -lfl

$(PARSER_C) $(PARSER_H): $(PARSER)
	$(BISON) -d $(PARSER)

$(LEXER_C): $(LEXER) $(PARSER_H)
	$(FLEX) $(LEXER)

test: $(EXECUTABLE)
	./$(EXECUTABLE) $(TEST_INPUT) $(TEST_OUTPUT)
	@echo "\n=== Código Assembly Gerado ==="
	@cat $(TEST_OUTPUT)

clean:
	rm -f $(EXECUTABLE) $(LEXER_C) $(PARSER_C) $(PARSER_H) $(TEST_OUTPUT) *.o

rebuild: clean all

.PHONY: all clean test rebuild