NAME = snake
MAC_OPT = -I/opt/X11/include
all:
	 @echo "Compiling..."
	 g++ -o $(NAME) src/*.cpp -L/opt/X11/lib -lX11 -lstdc++ $(MAC_OPT)

run: all
	@echo "Running..."
	./$(NAME}

clean:
	-rm *.o
	-rm animation clipping doublebuffer drawing drawing.min
	-rm eventloop eventloop.min hello.min null null.min openwindow openwindow.min
	










