#pragma once
#ifndef CELL_H_
#define CELL_H_
class Cell
{
public:
	Cell();
	~Cell();

private:
	bool living;
	int coord[];
};

#endif

