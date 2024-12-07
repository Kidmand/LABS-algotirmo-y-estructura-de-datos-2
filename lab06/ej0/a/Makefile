#cflags = gcc -Wall -Werror -Wextra -pedantic -std=c99 -g
#source = -c queue.c main.c queue_helpers.c
#source.o = main.o queue.o queue_helpers.o -o queue
#objects = $(source:.c=.o)

#.PHONY: clean

#clean:
#	rm -f queue.o queue_helpers.o main.o
#all: compilar

#compilar: $(objects) 
#	$(cflags) -o queue $(objects) $(LFLAGS) $(LIBS)

#.c.o:
#	$(cflags) -c $< -o $@ 

#compilar: 
#	$(cflags) $(source)

#objeto: 
#	$(cflags) $(source.o)

#run: 
#	./queue ../input/example-easy.in 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = main.o queue.o queue_helpers.o 
OBJECTS = $(SOURCES:.c=.o)
TARGET = queue

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	 $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	 $(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJECTS) $(TARGET)

run:
	./queue ../input/example-easy.in

