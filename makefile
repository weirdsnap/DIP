src = ./src
bin = ./bin
build = ./build
inc = ./include
$(bin)/main.exe: $(build)/main.o $(build)/tarray.o
	g++ -I $(inc) $(build)/main.o $(build)/tarray.o -o $(bin)/main.exe

$(build)/main.o: $(src)/main.cpp 
	g++ -I $(inc) -c $(src)/main.cpp -o $(build)/main.o

$(build)/tarray.o: $(inc)/twoDimArray.h $(src)/twoDimArray.cpp
	g++ -I $(inc) -c $(src)/twoDimArray.cpp -o $(build)/tarray.o

run:
	$(bin)/main.exe