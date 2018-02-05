all:
	g++ -c main.cpp -o main.o
	g++ -o light_trailer main.o -lopencv_core -lopencv_imgproc -lopencv_highgui

clean:
	rm light_trailer *.o
