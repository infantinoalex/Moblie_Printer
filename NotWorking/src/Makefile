
CC = g++

Printer: Controller.o ColorImageConverter.o Image.o Helper.o Motor.o PrinterHead.o main.o
	$(CC) -o botball_user_program main.o Motor.o PrinterHead.o Image.o Helper.o ColorImageConverter.o Controller.o -lwallaby

main.o: main.cpp
	$(CC) -c main.cpp

Controller.o: Controller/Controller.cpp Controller/Controller.hpp Image/Image.hpp
	$(CC) -c Controller/Controller.cpp

ColorImageConverter.o: ColorImageConverter.cpp ../includes/ColorImageConverter.hpp ../includes/ImageConverter.hpp ../includes/Image.hpp
	$(CC) -c Image/ColorImageConverter.cpp

Image.o: Image.cpp ../includes/Image.hpp
	$(CC) -c Image/Image.cpp

Helper.o: Helper.cpp
	$(CC) -c Helper.cpp

Motor.o: Motor.cpp ..inbcludes//Motor.hpp
	$(CC) -c PrinterHead/Motor.cpp

PrinterHead.o: PrinterHead.cpp ../includes//PrinterHead.hpp ../includes/Motor.hpp
	$(CC) -c PrinterHead/PrinterHead.cpp


clean:
	rm botball_user_program *.o
