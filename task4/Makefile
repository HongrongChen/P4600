OBJ = main.o statistics.o
TARGET = program



#This complies each c fil into a object file
%.o: %.c
	gcc -c -o $@ $<


#This links the object into an exectuable
$(TARGET): $(OBJ)
	gcc -o $@ $^