#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: dron
	./dron

dron: obj/main.o obj/Obiekt3D.o obj/Prostopadloscian.o obj/Wirnik.o obj/Powierzchnia.o obj/Tafla.o obj/Dno.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dron.o obj/Interfejs.o obj/Przeszkoda.o obj/Przesz_Prostopad.o obj/Dr3D_gnuplot_api.o
	g++ -Wall -pedantic -o dron obj/main.o obj/Obiekt3D.o obj/Prostopadloscian.o obj/Wirnik.o obj/Powierzchnia.o obj/Tafla.o obj/Dno.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dron.o obj/Interfejs.o obj/Przeszkoda.o obj/Przesz_Prostopad.o obj/Dr3D_gnuplot_api.o -lpthread

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Wirnik.hh inc/Powierzchnia.hh inc/Tafla.hh inc/Dno.hh inc/Obiekt3D.hh inc/MacierzOb.hh inc/Macierz.hh inc/Wektor.hh inc/Dron.hh inc/Interfejs.hh inc/Przeszkoda.hh inc/Przesz_Prostopad.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/Prostopadloscian.hh inc/Wirnik.hh inc/Interfejs.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Przesz_Prostopad.o: src/Przesz_Prostopad.cpp inc/Przesz_Prostopad.hh inc/Prostopadloscian.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Przesz_Prostopad.o src/Przesz_Prostopad.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ ${CPPFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Interfejs.o: src/Interfejs.cpp inc/Interfejs.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Interfejs.o src/Interfejs.cpp

obj/Dno.o: src/Dno.cpp inc/Dno.hh inc/Powierzchnia.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Dno.o src/Dno.cpp

obj/Tafla.o: src/Tafla.cpp inc/Tafla.hh inc/Powierzchnia.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh inc/Przeszkoda.hh
	g++ ${CPPFLAGS} -o obj/Tafla.o src/Tafla.cpp

obj/Powierzchnia.o: src/Powierzchnia.cpp inc/Powierzchnia.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Powierzchnia.o src/Powierzchnia.cpp

obj/Wirnik.o: src/Wirnik.cpp inc/Wirnik.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wirnik.o src/Wirnik.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Obiekt3D.o: src/Obiekt3D.cpp inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Obiekt3D.o src/Obiekt3D.cpp

obj/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/MacierzOb.o src/MacierzOb.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clean:
	rm -f obj/*.o dron