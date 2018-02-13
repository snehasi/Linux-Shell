

shell : shell.c ls.c cat.c date.c mkdir.c rm.c
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc cat.c -o cat
	gcc ls.c -o ls
	gcc date.c -o date

.PHONY : all
all : rm cat mkdir date ls shell

shell : shell.o
				gcc shell.c -o shell

rm : rm.o
				gcc rm.c -o rm

ls : ls.o
				gcc ls.c -o ls

cat : cat.o
				gcc cat.c -o cat

date : date.o
				gcc date.c -o date

mkdir : mkdir.o
				gcc mkdir.c -o mkdir


.PHONY: clean



clean:
	-rm shell cat ls mkdir date rm shell.o cat.o ls.o mkdir.o date.o rm.o
