all: 
	g++ -std=c++11 -O0 *.cpp -o app.app

clean:
	rm -f *.o *.app
