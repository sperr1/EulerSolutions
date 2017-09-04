#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"
class Board
{
public:
	Board();
	~Board();

private:
	int xSize, ySize;
	Cell cellBoard[][];
};

#endif

