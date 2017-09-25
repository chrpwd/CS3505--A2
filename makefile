#Christian Purdy
#U0728219
#A2

#Define HaruLib include
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
LIBHARU = './libharu'
ENDTAGS = -lhpdfs -lz

SpiralPDF : haruPDF.o Spiral.o spiralPDF.cpp
		$(CXX) $(CXXFLAGS) -o SpiralPDF Spiral.o haruPDF.o spiralPDF.cpp  -L$(LIBHARU)/src -I$(LIBHARU)/include $(ENDTAGS)

haruPDF.o : haruPDF.cpp haruPDF.h
		$(CXX) $(CXXFLAGS) -c haruPDF.cpp -L$(LIBHARU)/src -I$(LIBHARU)/include  $(ENDTAGS)

Spiral.o : Spiral.cpp Spiral.h
		$(CXX) $(CXXFLAGS) -c Spiral.cpp $(ENDTAGS)

clean:
	rm SpiralPDF *.o


test:
	./SpiralPDF "Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. Its not a story the Jedi would tell you"
