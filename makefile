

shell : shell.c ls.c cat.c date.c mkdir.c rm.c
	gcc shell.c -o shell
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc cat.c -o cat
	gcc ls.c -o ls
	gcc date.c -o date


.PHONY: clean

clean:
	rm -f shell.o
	rm -f cat.o
	rm -f ls.o
	rm -f mkdir.o
	rm -f rm.o
	rm -f date.o
