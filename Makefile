# Makefile para Mac M1 (ARM64)
CC = gcc
FLEX = flex
BISON = bison

# Flags para Mac M1
CFLAGS = -Wall -g
LDFLAGS =

# Nome do executável
TARGET = parser

# Arquivos fonte
LEXER = lexer.l
PARSER = parser.y

# Arquivos gerados
LEXER_C = lex.yy.c
PARSER_C = parser.tab.c
PARSER_H = parser.tab.h

# Regra padrão
all: $(TARGET)

# Gera o parser
$(PARSER_C) $(PARSER_H): $(PARSER)
	$(BISON) -d $(PARSER)

# Gera o lexer
$(LEXER_C): $(LEXER) $(PARSER_H)
	$(FLEX) $(LEXER)

# Compila o executável
$(TARGET): $(PARSER_C) $(LEXER_C)
	$(CC) $(CFLAGS) -o $(TARGET) $(PARSER_C) $(LEXER_C) $(LDFLAGS)

# Testa com arquivo de exemplo
test: $(TARGET)
	./$(TARGET) test.txt

# Limpa arquivos gerados
clean:
	rm -f $(TARGET) $(LEXER_C) $(PARSER_C) $(PARSER_H)

# Limpa e recompila
rebuild: clean all

.PHONY: all clean test rebuild