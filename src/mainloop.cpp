#include "../include/mainloop.h"
MainLoop::MainLoop() {
	rl = new Renderer();
	gm = new GameManager();
	debug = false;
}



void MainLoop::mLoop(XInfo &xinfo, int a, int b) {
	rl->insertToDis(gm->s);
	rl->insertToDis(gm->f);
	gm->s->velocity = b * 5;

	XEvent event;
	unsigned long lastRepaint = 0;
	unsigned long lastAni = 0;
	int inside = 0;

	while( true ) {
		if (XPending(xinfo.display) > 0) {
			XNextEvent( xinfo.display, &event );
			std::cout << "event.type=" << event.type << "\n";
			switch( event.type ) {
			case KeyPress:
				gm->handleKeyPress(xinfo, event);
				break;
			case EnterNotify:
				inside = 1;
				break;
			case LeaveNotify:
				inside = 0;
				break;
			}
		}
		if (gm->cs == _SPLASH) {
			std::string text("SNAKE");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 30, height / 2, text.c_str(), text.length());
			std::string text1("Mohammed Alharbi ( 20551341 )");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 150, (height / 2) + 50, text1.c_str(), text1.length());
			std::string text2("Press P to Play/Pause - Arrow keys to move");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 250, (height / 2) + 100, text2.c_str(), text2.length());

		} else if (gm->cs == _GAMEOVER) {	
			std::string text("GAME OVER");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 30, height / 2, text.c_str(), text.length());
			std::string text1("Press R to restart or Q to quit");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 150, (height / 2)+ 50, text1.c_str(), text1.length());
		} else if (gm->cs == _PAUSE) {	
			std::string text("PAUSED");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 30, height / 2, text.c_str(), text.length());
			std::string text1("Press P to continue R to restart or Q to quit");
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 200, (height / 2)+ 50, text1.c_str(), text1.length());
		} else {
			std::string text(std::to_string(gm->score));
			XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
			  (width / 2) - 10, 50, text.c_str(), text.length());
			unsigned long end = now();
			if (end - lastRepaint > 1000000 /a) {
				XSetForeground(xinfo.display, xinfo.gc[0], WhitePixel(xinfo.display, DefaultScreen(xinfo.display)));
				XFillRectangle(xinfo.display, xinfo.buffer, xinfo.gc[0], 0,0, xinfo.width, xinfo.height);

				if (end - lastAni > 1000000 /gm->s->velocity) {
					gm->checkColl();
					lastAni = now();
				} 
				if(debug == true) {
					std::string text(std::to_string(end - lastRepaint));
					XDrawImageString( xinfo.display, xinfo.window, xinfo.gc[0],
					  200, 500, text.c_str(), text.length());
				}
				XCopyArea(xinfo.display, xinfo.buffer, xinfo.window, xinfo.gc[0], 0,0, xinfo.width, xinfo.height, 0,0);
				usleep(1000000/a);
				rl->repaint(xinfo, debug);
				lastRepaint = now();
			}
		}
	}
}

void MainLoop::tick(int argc, char *argv[]) {
	if (argc == 1) {
	initX(argc, argv, xinfo);
	mLoop(xinfo, 30, 5);
	} else if (argc == 3) {
		int f = std::stoi(argv[1]);
		int sp = std::stoi (argv[2]);
		initX(argc, argv, xinfo);
		mLoop(xinfo, f, sp);
	}

}
