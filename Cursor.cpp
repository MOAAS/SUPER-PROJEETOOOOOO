#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor() {
	this->x = 0;
	this->y = 0;
	this->dir = 'H';
}

Cursor::Cursor(int x, int y, char dir) {
	this->x = x;
	this->y = y;
	this->dir = dir;
}

void Cursor::moveTo(int x, int y) {
	this->x = x;
	this->y = y;
}

void Cursor::moveTo(int x, int y, char dir) {
	this->x = x;
	this->y = y;
	this->dir = dir;
}

void Cursor::moveTo(string coords) {
	x = LCDtoPosX(coords);
	y = LCDtoPosY(coords);
	dir = LCDtoDir(coords);
}

void Cursor::changeDir(char dir) {
	this->dir = dir;
}

Cursor Cursor::operator++(int unused) {
	switch (dir) {
	case 'H': x++; break;
	case 'V': y++; break;
	}
	return *this;
}

Cursor Cursor::operator--(int unused) {
	switch (dir) {
	case 'H': x--; break;
	case 'V': y--; break;
	}
	return *this;
}

int Cursor::MainCoord()
{
	if (dir == 'H')
		return x;
	else return y;
}

int LCDtoPosX(string LcD) {
	return LcD[1] - 'a';
}

int LCDtoPosY(string LcD) {
	return LcD[0] - 'A';
}

char LCDtoDir(string LcD) {
	return LcD[2];
}
