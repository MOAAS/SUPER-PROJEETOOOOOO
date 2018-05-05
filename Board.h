
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <map>
#include "Cursor.h"

using namespace std;

class Board
{
public:
	Board(int size_x, int size_y);
	void display();
	void getWord();
	bool Verify(int posX, int posY, char direction, string palavra);
	bool Verify(string coords, string palavra);//Ve se pode por a palavra
	void Insert(int posX, int posY, char direction, string palavra);
	void Insert(string coords, string palavra);//mete
	void InsertAll();
	bool Delete(string coords);
	void ChangeChar(char letra); //altera no board a letra com base na posicao do cursor
	char ShowChar() const; //ve que letra esta na posicao do cursor
	int CoordLimit() const; //da a coordenada maxima do board na direcao atual (usa o cursor)
	bool isFull() const;
	void clear();
	void reset(); // Limpa o board (Não usado de momento)
	void reset(int size_x, int size_y); // Limpa o board, altera o tamanho.
	void Fill();
	void saveFile(string file_path);
	void loadFile(string file_path);
	vector<string> getPlacedWords() const;
private:
	vector<vector<char>> board;
	int size_x, size_y;
	map<string, string> placedWordsCoords; // "LCD", "Palavra"
	Cursor Cursor;
};

int LCDtoPosX(string LCD); // recebe string da forma "LinhaColunaDireçao" devolve a coordenada X correspondente.
int LCDtoPosY(string LCD); // recebe string da forma "LinhaColunaDireçao" devolve a coordenada Y correspondente.
char LCDtoDir(string LCD); // recebe string da forma "LinhaColunaDireçao" devolve a direçao correspondente.
