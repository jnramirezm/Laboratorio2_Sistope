FLAGS = -Wall -lm

all: lab2 broker worker

lab2: lab2.c fbroker.o funciones.o StructData.o fworker.o
	gcc $(FLAGS) -o lab2 lab2.c fbroker.o funciones.o StructData.o fworker.o

broker: broker.c fbroker.o funciones.o StructData.o
	gcc $(FLAGS) -o broker broker.c fbroker.o funciones.o StructData.o
 
worker: worker.c fbroker.o StructData.o funciones.o fworker.o
	gcc $(FLAGS) -o worker worker.c fbroker.o StructData.o funciones.o fworker.o

fbroker.o: fbroker.c
	gcc -c $(FLAGS) fbroker.c

fworker.o: fworker.c
	gcc -c $(FLAGS) fworker.c

StructData.o: StructData.c
	gcc -c $(FLAGS) StructData.c

funciones.o: funciones.c
	gcc -c $(FLAGS) funciones.c

clear:
	rm -f *.o lab2 intermedio.csv *.txt broker worker 