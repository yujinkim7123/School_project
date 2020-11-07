INSTDIR = /home/kimyujin/new
TARGET = main
OBJECTS = main.o sub.o mul.o add.o
CC = gcc

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

main.o: main.c
	$(CC) -c main.c

sub.o: sub.c
	$(CC) -c sub.c

mul.o: mul.c
	$(CC) -c mul.c

add.o: add.c
	$(CC) -c add.c

clean:
	rm -f $@ $(OBJECTS) $(INSTDIR)/main.o $(INSTDIR)/sub.o $(INSTDIR)/add.o $(INSTDIR)/mul.o $(INSTDIR)/main

install: main  
		@if [ -d $(INSTDIR) ]; \
		then \
		cp main $(INSTDIR);\
		cp $(OBJECTS) $(INSTDIR);\
		echo "installed"; \
	else \
	 echo "not installed";\
	fi


	
	
