# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = matrixMultiplicationRun
CLASS1 = matrix
MAIN = matrixTest

all: $(TARGET)

$(TARGET): $(CLASS1).o    $(MAIN).o
	$(CC) $(CFLAGS) -o $(TARGET) $(CLASS1).o  $(MAIN).o

$(CLASS1).o: $(CLASS1).cc $(CLASS1).h
	$(CC) $(CFLAGS) -c $(CLASS1).cc

$(MAIN).o: $(MAIN).cc $(CLASS1).h
	$(CC) $(CFLAGS) -c $(MAIN).cc

clean:
	$(RM) -f $(TARGET) $(CLASS1).o  $(MAIN).o  
