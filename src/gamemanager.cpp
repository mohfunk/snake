#include "../include/gamemanager.h"


GameManager::GameManager() {
	this->cs = _SPLASH;
	f = new Fruit(100,100);
	s = new Snake(300,300,100);
	score = 0;
}

GameManager::~GameManager() {
	delete f;
	delete s;
}

void GameManager::restart() {
	score = 0;
	s->sbody.clear();
	s->length = 0;
	this->cs = _GAME;
}


// move this to inout manager, subscripe to event system
void GameManager::handleKeyPress(XInfo &xinfo, XEvent &event) {
 
	KeySym key;
	char text[BufferSize];
	// these should be enums
	int i = XLookupString(
	  (XKeyEvent *)&event, 	// the keyboard event
	  text, 					// buffer when text will be written
	  BufferSize, 			// size of the text buffer
	  &key, 					// workstation-independent key symbol
	  NULL );					// pointer to a composeStatus structure (unused)
	if ( i == 1) {
		printf("Got key press -- %c\n", text[0]);
		if (text[0] == 'q') {
			error("Terminating normally.");
		}
		if (text[0] == 'p') {
			if(this->cs == _GAME) {
				this->cs = _PAUSE;
			} else {
				this->cs = _GAME;
			}
		}
		if (text[0] == 'r') {
			if(this->cs == _PAUSE || this->cs == _GAMEOVER) {
				score = 0;
				s->sbody.clear();
				s->length = 0;
				s->hit = false;
				this->cs = _GAME;
			}
		}
	}

	if (key == XK_Up && s->directionY != 1) {
		s->changeDirY(-1);
	}
	if (key == XK_Down && s->directionY != -1) {
		s->changeDirY(1);
	}
	if (key == XK_Right && s->directionX != -1) {
		s->changeDirX(1);
	}
	if (key == XK_Left && s->directionX != 1) {
		s->changeDirX(-1);
	}
}

void GameManager::handleAnimation(XInfo &xinfo, int inside) {
}



// Handle Collusion

void GameManager::checkColl() {

	srand(time(NULL));
	if(s->x == f->getX() && s->y == f->getY()) {
		s->length++;
		int nx = rand() % 800;
		int ny = rand() % 600;
		f->setX( nx - (nx % s->blockSize));
		f->setY( ny - (ny % s->blockSize));
		SnakeChain* sb = new SnakeChain(s->x, s->y, s->directionX, s->directionY);
		score++;
		s->sbody.push_back(sb);
		int randomX = rand() % 100;
		int randomY = rand() % 100;
		if ( randomX >= 20 ) { s->velocity++; }
		if (randomY >= 10 ) { if (s->inv == false) { s->inv = true;} }
	}
	s->move();
	if(s->selfColl() == true) {
		if (s->inv == false) {
		this->cs = _GAMEOVER;
		} else {
			s->inv = false;
		}
	}


}
