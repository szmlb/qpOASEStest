CPP = clang++
CFRAGS = -stdlib=libstdc++ -O3 -Wall -lm -g
QPOASES_INCLUDE_DIR = -I/usr/local/include/
QPOASES_LIB_DIR = -L/usr/local/lib -lqpOASES

OBJS_MAIN = main.o

main : $(OBJS_MAIN)
	$(CPP) -o main $(CFLAGS) $(QPOASES_INCLUDE_DIR) $(QPOASES_LIB_DIR) $(OBJS_MAIN)

# main program
main.o: main.cpp
		$(CPP) -c $(CFLAGS) $(QPOASES_INCLUDE_DIR) $(QPOASES_LIB_DIR) main.cpp

clean:
	rm -f main *.o
clean_all:
	rm -f main *.o
