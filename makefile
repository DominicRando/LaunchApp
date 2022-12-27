debug = -g

app:	Date.o Time.o app.cpp Launch.o
		g++ -static-libstdc++ -o app Date.o Time.o app.cpp Launch.o $(debug)

Launch.o:	Launch.cpp Launch.h Date.o Time.o
		g++ -c Launch.cpp $(debug)

Date.o: Date.cpp Date.h
		g++ -c Date.cpp $(debug)

Time.o: Time.cpp Time.h
		g++ -c Time.cpp $(Debug)

clean:
		\rm -f *.o app
