#include<stdio.h>

#define BACKGROUND_PIXEL 0
#define IMAGE_PIXEL 1
#define COUNTED 2

int cells[][8]{
	{0,0,1,0,0,0,0,1},
    {1,1,0,0,0,1,0,0},
    {0,0,1,0,1,0,1,0},
    {0,0,0,0,0,1,0,0},
    {0,1,0,1,0,1,0,0},
    {0,1,0,1,0,1,0,0},
    {1,0,0,0,1,1,0,0},
    {0,1,1,0,0,0,1,1}
};



int countCells(int x, int y) {
	
	int count = 0;

	if (cells[x][y] == BACKGROUND_PIXEL)
		return 0; 
	if (cells[x][y] == COUNTED)
		return 0;
	if (x < 0 || x >= 8 || y < 0 || y >= 8)
		return 0;

	count++;

	cells[x][y] = COUNTED;

		count = count + countCells(x - 1, y) + countCells(x - 1, y + 1) + countCells(x, y + 1) + countCells(x + 1, y + 1) + 
		countCells(x , y - 1) + countCells(x - 1, y - 1) + countCells(x + 1, y) + countCells(x + 1, y - 1);
	    

		return count;

}

int main() {


	printf("%d", countCells(5, 3));
}