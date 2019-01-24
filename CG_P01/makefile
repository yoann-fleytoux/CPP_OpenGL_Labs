SHELL = /bin/sh

## Working directory #########################################################
OBJDIR = ./obj
HEADERDIR = ./header
SRCDIR = ./src

## Specifies a path containing the source files (.cpp and .hpp) ##############
VPATH = $(SRCDIR):$(HEADERDIR)

## Compileur #################################################################
CC = g++ 
WARNINGS :=-Wall  -Werror 
CFLAGS =-g
LDFLAGS =-lm -lGL -lGLU -lglut 

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

EXEC = main.out

## Command ###################################################################
MKDIR = @mkdir -p
RM = @rm -rf

## First target: the default goal is 'all' ###################################
all: $(OBJ) $(EXEC)

## Rules to create the targets files #########################################
.PHONY: all
$(EXEC): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(LDFLAGS)

## Rule to create objects from source ########################################
$(OBJDIR)/%.o: %.cpp
	$(MKDIR) $(OBJDIR)
	$(CC) $(FLAGS) -o $@ -c $<

## Clean command #############################################################
.PHONY: clean distclean
clean:
	$(RM)  $(OBJDIR)/*.o
	$(RM) ./*~
distclean: clean
	$(RM) $(EXEC)
