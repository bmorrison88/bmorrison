// Brandon Morrison
// CS 438 - Artificial Intelligence
// Assignment 4: Reversi
// Performance summary: (a) The program performs legal moves all the time.
//                      (b) The probability of how many times my agent wins is completely random.
//							I have it set up where it can play the game all the way to the end but,
//							I couldn't figure out how to put it all together in time. The heuristic
//							function is there, but I couldn't think of a way integrate it with the move.
//The program to run is called "sample.exe"

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "gamecomm.h"


using namespace std;

const int SIZE = 8;
const int maxturn = 1;
const int minturn = -1;
const int maxsucc = 40;
const int VS = -1000000;
const int VL = 1000000;

int numMoves = 0;
int maxIndex, minIndex = 0;
int nodecount = 0;
typedef int stateType;

stateType best = NULL;


struct board
{
	int m[SIZE][SIZE];	// 1, 0, -1
	int r, c, turn;	// the move that gets to this board
	board(int n[][SIZE], int row = SIZE, int column = SIZE, int t = 1)
	{
		for (int k = 0;k<SIZE;k++)
			for (int l = 0;l<SIZE;l++)
				m[k][l] = n[k][l];
		r = row;c = column; turn = t;
	}
};

typedef board *state_t;

//Class Move includes functions that set up our move list
class Move {
public:
	int x, y;
	Move();
	void setMove(int row, int col);
};

Move maxMoves[maxsucc]; //Max player's moves
Move minMoves[maxsucc]; //Min player's moves

//Adds move to move list
void addMove(int row, int col, int player) {
	Move move;
	move.setMove(row, col);
	if (player == maxturn) {
		maxMoves[maxIndex] = move;
		maxIndex++;
	}
	else if (player == minturn) {
		minMoves[minIndex] = move;
		minIndex++;
	}
}

Move::Move()
{
	x = 0;
	y = 0;
}

void Move::setMove(int row, int col)
{
	x = row;
	y = col;
}

//Next 8 functions test the direction a player can move
//Function name representation
	// m = move; u = up; d = down; l = left; r = right
bool mu(int row) {
	return(row - 2 >= 0);
}

bool md(int row) {
	return(row + 2 < SIZE);
}

bool ml(int col) {
	return(col - 2 >= 0);
}

bool mr(int col) {
	return(col + 2 < SIZE);
}

bool mul(int row, int col) {
	return(row - 2 >= 0 && col - 2 >= 0);
}

bool mur(int row, int col) {
	return (row - 2 >= 0 && col + 2 < SIZE);
}

bool mdr(int row, int col) {
	return (row + 2 < SIZE && col + 2 < SIZE);
}

bool mdl(int row, int col) {
	return(row + 2 < SIZE && col - 2 >= 0);
}

//The next 8 functions test for the current player's adjacencies
//Function name representation
//a = adjacent
bool al(state_t board, int row, int col, int player) {
	return (board->m[row][col - 1] == -player);
}

bool ar(state_t board, int row, int col, int player) {
	return (board->m[row][col + 1] == -player);
}

bool au(state_t board, int row, int col, int player) {
	return (board->m[row - 1][col] == -player);
}

bool ad(state_t board, int row, int col, int player) {
	return (board->m[row + 1][col] == -player);
}

bool aul(state_t board, int row, int col, int player) {
	return (board->m[row - 1][col - 1] == -player);
}

bool aur(state_t board, int row, int col, int player) {
	return (board->m[row - 1][col + 1] == -player);
}

bool adl(state_t board, int row, int col, int player) {
	return (board->m[row + 1][col - 1] == -player);
}

bool adr(state_t board, int row, int col, int player) {
	return (board->m[row + 1][col + 1] == -player);
}

//Test whether a piece can move
bool canMove(state_t board, int row, int col) {
	if (board->m[row][col] == 0 && mu(row) || md(row) || ml(col) || mr(col) || mul(row, col) || mur(row, col) || mdr(row, col) || mdl(row, col)) return true;
	else return false;
}

//Test if a move is valid and if it is, add it to the move list of that player
bool isValid(state_t board, int row, int col, int player) {
	int endCol = col;
	int endRow = row;

	if (board->m[row][col] == player && canMove(board, row, col) && (al(board, row, col, player) || ar(board, row, col, player) || au(board, row, col, player) || ad(board, row, col, player)
		|| aul(board, row, col, player) || aur(board, row, col, player) || adl(board, row, col, player) || adr(board, row, col, player))) {

		if (al(board, row, col, player)) {
			endCol--;
			while (endCol >= 0 && board->m[row][endCol] == -player) //While I'm in bounds and the adjacent piece is the opposite of the current player
			{
				endCol--;
			}
			if (board->m[row][endCol] == 0 && endCol > -1) {
				addMove(row, endCol, player);
				numMoves++;
			}
			endCol = col;
		}

		if (ar(board, row, col, player)) {				
			endCol++; //Need to move right one, since we know that next piece opp color
			while (endCol < 8 && board->m[row][endCol] == -player) {
				endCol++;
			}
			if (board->m[row][endCol] == 0 && endCol < 8) {
				addMove(row, endCol, player);
				numMoves++;
			}											
			endCol = col; //Resets endCol to col so others can use it
		}

		if (au(board, row, col, player)) {
			endRow--;
			while (endRow >= 0 && board->m[endRow][col] == -player)
			{
				endRow--;
			}
			if (board->m[endRow][col] == 0 && endRow > -1)
			{
				addMove(endRow, col, player);
				numMoves++;
			}
			endRow = row;
		}

		if (ad(board, row, col, player)) {
			endRow++;
			while (endRow < 8 && board->m[endRow][col] == -player)
			{
				endRow++;
			}
			if (board->m[endRow][col] == 0 && endRow < 8)
			{
				addMove(endRow, col, player);
				numMoves++;
			}
			endRow = row;
		}

		if (aul(board, row, col, player)) {
			endRow--;
			endCol--;
			while (endRow >= 0 && endCol >= 0 && board->m[endRow][endCol] == -player)
			{
				endRow--;
				endCol--;
			}
			if (board->m[endRow][endCol] == 0 && endRow > -1 && endCol > -1)
			{
				addMove(endRow, endCol, player);
				numMoves++;
			}
			endRow = row;
			endCol = col;
		}
		if (aur(board, row, col, player)) {
			endRow--;
			endCol++;
			while (endRow >= 0 && endCol < 8 && board->m[endRow][endCol] == -player)
			{
				endRow--;
				endCol++;
			}
			if (board->m[endRow][endCol] == 0 && endRow > -1 && endCol < 8)
			{
				addMove(endRow, endCol, player);
				numMoves++;
			}
			endRow = row;
			endCol = col;
		}

		if (adr(board, row, col, player)) {
			endRow++;
			endCol++;
			while (endRow < 8 && endCol < 8 && board->m[endRow][endCol] == -player)
			{
				endRow++;
				endCol++;
			}
			if (board->m[endRow][endCol] == 0 && endRow < 8 && endCol < 8)
			{
				addMove(endRow, endCol, player);
				numMoves++;
			}
			endRow = row;
			endCol = col;
		}

		if (adl(board, row, col, player)) {
			endRow++;
			endCol--;
			while (endRow < 8 && endCol >= 0 && board->m[endRow][endCol] == -player)
			{
				endRow++;
				endCol--;
			}
			if (board->m[endRow][endCol] == 0 && endRow < 8 && endCol > -1)
			{
				addMove(endRow, endCol, player);
				numMoves++;
			}
			endRow = row;
			endCol = col;
		}
		return true;
	}
	else return false;
}

//Returns the number of possible moves for a player
int possibleMoves(state_t board, int player) {
	numMoves = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			isValid(board, i, j, player);
		}
	}
	return numMoves;
}

//Determines if a state is terminal
bool isterminal(stateType state)
{
	return (state >= 14 && state <= 40);
}
//Helper function to swap integers
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/*Where the next move was calculated but I couldn't 
  figure out how a way to return the move that was the best next move 
*/

state_t nextMove(state_t s, Move moveList, int player) {
	state_t nextBoard = s;
	int endRow = moveList.x;
	int endCol = moveList.y;

	//au is the valid move
	if (ad(nextBoard, moveList.x, moveList.y, player)) {
		nextBoard->m[endRow][endCol] = player;
		endRow++;
		while (endRow < SIZE && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow++;
		}
		endRow = moveList.x;
	}
	//ad is the valid move
	if (au(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endRow--;
		while (endRow >= 0 && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow--;
		}
		endRow = moveList.x;
	}

	//al is the valid move
	if (ar(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endCol++;
		while (endCol < SIZE && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endCol++;
		}
		endCol = moveList.y;
	}

	//ar is valid move
	if (al(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endCol--;
		while (endCol >= 0 && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endCol--;
		}
		endCol = moveList.y;
	}
	//aul is valid move
	if (adr(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endRow++;
		endCol++;
		while (endRow < SIZE && endCol < SIZE && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow++;
			endCol++;
		}
		endRow = moveList.x;
		endCol = moveList.y;
	}

	//aur is valid move
	if (adl(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endRow++;
		endCol--;
		while (endRow < SIZE && endCol >= 0 && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow++;
			endCol--;
		}
		endRow = moveList.x;
		endCol = moveList.y;
	}

	//adr is valid move
	if (aul(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endRow--;
		endCol--;
		while (endRow >= 0 && endCol >= 0 && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow--;
			endCol--;
		}
		endRow = moveList.x;
		endCol = moveList.y;
	}
	//adl is valid move
	if (aur(nextBoard, moveList.x, moveList.y, player))
	{
		nextBoard->m[endRow][endCol] = player;
		endRow--;
		endCol++;
		while (endRow >= 0 && endCol < SIZE && nextBoard->m[endRow][endCol] == -player)
		{
			nextBoard->m[endRow][endCol] = player;
			endRow--;
			endCol++;
		}
		endRow = moveList.x;
		endCol = moveList.y;
	}

	return nextBoard;
}

/*Expands the current state , but I couldn't figure out the heap corruption error.*/

//void expand(state_t s, state_t successor[], int &sn, int turn)
//{
//	state_t init = (state_t)malloc(sizeof(state_t));
//
//	sn = possibleMoves(s, turn); //Number of successors
//	for (int i = 0; i < sn; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//		{
//			for (int k = 0; k < SIZE; k++) {
//				init->m[j][k] = s->m[j][k];
//			}
//		}
//		successor[i] = (state_t)malloc(sizeof(state_t)); //generates a new pointer to the array at i
//		for (int x = 0; x < SIZE;x++) {
//			for (int y = 0; y < SIZE; y++) {
//				successor[i]->m[x][y] = nextMove(init, maxMoves[i], turn)->m[x][y];
//			}
//		}
//	}
//}

int max(int a, int b)
{
	return a>b ? a : b;
}

int min(int a, int b)
{
	return a>b ? b : a;
}

// I used the possible moves of each player for the heuristic where I wanted to maximize the Max player moves
// while minimizing the Min player moves
int eval(state_t t, int player)
{
	int hvalue;
	int maxPossibleMoves = possibleMoves(t, player);
	int minPossibleMoves = possibleMoves(t, -player);

	if (maxPossibleMoves + minPossibleMoves != 0)
		hvalue = 100 * (maxPossibleMoves - minPossibleMoves) / (maxPossibleMoves + minPossibleMoves);
	else
		hvalue = 0;

	return hvalue;
}
/* I figured out how to use the alpha beta search but I couldn't figure out how I would get the best possible move
   to be in sync with the hvalue. Now that I think about it, I could have a hvalue as a member of a move in the Move class
*/

//int alphabeta(state_t s, int maxDepth, int curDepth, int alpha, int beta, state_t successfulBoard)
//{
//	nodecount++;
//	//cout << "entetring " << state << endl;
//	if (curDepth == maxDepth) // CUTOFF test  || isterminal(state)
//	{
//		int UtilV = eval(s, s->turn);
//		//cout << state << " [" << UtilV << "]\n";
//		return UtilV;  // eval returns the heuristic value of state
//	}
//	state_t successor[maxsucc]; //Board array with 40 possible moves
//	int succnum, turn;
//	if (curDepth % 2 == 0) // This is a MAX node 
//						   // since MAX has depth of: 0, 2, 4, 6, ...
//		turn = maxturn;
//	else
//		turn = minturn;
//	expand(s, successor, succnum, turn); // find all successors of state
//
//	if (turn == maxturn) // This is a MAX node 
//						 // since MAX has depth of: 0, 2, 4, 6, ...
//	{
//		alpha = VS; // initialize to some very small value 
//		for (int k = 0;k<succnum;k++)
//		{
//			// recursively find the value of each successor
//			int curvalue = alphabeta(s, successor[k], maxDepth, curDepth + 1, alpha, beta);
//			//alpha = max(alpha,curvalue); // update alpha
//			if (curvalue>alpha || curvalue == alpha && time(0) % 2 == 0)
//			{
//				alpha = curvalue;
//				if (curDepth == 0)
//					best = successor[k];
//			}
//			if (alpha >= beta) return alpha; // best = successor[k];
//		}
//		//cout << state << " [" << alpha << "]\n";
//		return alpha;
//	}
//	else // A MIN node
//	{
//		beta = VL;  // initialize to some very large value
//		for (int k = 0;k<succnum;k++)
//		{
//			// recursively find the value of each successor
//			int curvalue = alphabeta(s,successor[k], maxDepth, curDepth + 1, alpha, beta);
//			beta = min(beta, curvalue); // update beta
//			if (alpha >= beta) return beta;
//		}
//		//cout << state << " [" << beta << "]\n";
//		return beta;
//	}
//}

void main()
{
	int n[SIZE][SIZE];
	getGameBoard(n);
	state_t s = new board(n);

	//Alphabeta testing
	//int value = alphabeta(s, 1, 3, 0, VS, VL);

	int max = possibleMoves(s, maxturn);
	int min = possibleMoves(s, minturn);
	int ran;

	srand(time(NULL));
	ran = rand() % max;

	//Prints out each move
	/*cout << "Number of moves for MAX: " << max << endl;
	for (int i = 0; i < max; i++)
	{
		cout << "Row: " << maxMoves[i].x << " Col: " << maxMoves[i].y << endl;
	}

	cout << "Number of moves for MIN: " << min << endl;
	for (int i = 0; i < min; i++)
	{
		cout << "Row: " << minMoves[i].x << " Col: " << minMoves[i].y << endl;
	}*/
	
	putMove(maxMoves[ran].x, maxMoves[ran].y);
}