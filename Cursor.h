#pragma once
#include <string>

using namespace std;

class Cursor {
public:
	friend class Board;
	Cursor();
	Cursor(int x, int y, char dir);
	void moveTo(int x, int y);
	void moveTo(int x, int y, char dir);
	void moveTo(string coords);
	void changeDir(char dir);
	Cursor operator++(int unused);
	Cursor operator--(int unused);
	int MainCoord(); //da a coordenada principal na direcao atual
private:
	int x, y;
	char dir; // Direção. H / V
};
