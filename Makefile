all: rtu

rtu: 
	gcc rtu-ai8.c -o rtu-ai8 -lsqlite3 -lmodbus 

clean:
	rm -rf *.o rtu-ai8
