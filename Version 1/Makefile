# this is a makefile
# where we will defining 
# scanner and clean as target elements
# main.c and scan.c are recipies
# below lines will just expand the recipies


scanner: main.c scan.c
	cc -o scanner -g main.c scan.c

clean:
	rm -f scanner *.o
