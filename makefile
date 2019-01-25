CC = g++
CFLAGS = -Wall -g -fpic
RM = /bin/rm -f
CP = /bin/cp -f
CHMOD = /bin/chmod
MKDIR = /bin/mkdir -p
PRINT = @echo

all: parseopt
	$(CC) -shared parseopt.o -o libparseopt.so

parseopt: parseopt.h parseopt.cpp
	$(CC) $(CFLAGS) -c parseopt.cpp -o parseopt.o

install:
	$(PRINT) "Creating destination directories..."
	$(MKDIR) /usr/local/include /usr/local/lib
	$(CHMOD) 0755 /usr/local/include /usr/local/lib

	$(PRINT) "Installing library files..."
	$(CP) parseopt.h /usr/local/include
	$(CP) libparseopt.so /usr/local/lib
	$(CHMOD) 0644 /usr/local/include/parseopt.h /usr/local/lib/libparseopt.so

	$(PRINT) "Updating library cache..."
	ldconfig

uninstall:
	$(PRINT) "Uninstalling library files..."
	$(RM) /usr/local/include/parseopt.h /usr/local/lib/libparseopt.so

	$(PRINT) "Updating library cache..."
	ldconfig

clean:
	$(RM) *.o *.so
