CC=g++
exe=prog

$(exe): Pokemon.o driver.cpp
	$(CC) Pokemon.o driver.cpp -o $(exe)

student_db.o: Pokemon.cpp Pokemon.h
	$(CC) -c Pokemon.cpp

Clean:
	rm -f *.o $(exe)