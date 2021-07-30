#include "Functions.h"
#include<iostream>
#include"Define.h"
#include<time.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;

class Tetris 
{
public:
	int arr[22][12]=
	{
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,0,0,0,0,0,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	};
	int arr1[7][7]= 
	{
		{-1,-1,-1,-1,-1,-1,-1},
		{-1,0,0,0,0,0,-1},
		{-1,0,0,0,0,0,-1},
		{-1,0,0,0,0,0,-1},
		{-1,0,0,0,0,0,-1},
		{-1,0,0,0,0,0,-1},
		{-1,-1,-1,-1,-1,-1,-1},
	};
	int NowBlock;
	int newblock;
	int NextBlock;
	int RandomList[7]= { 0,1,2,3,4,5,6 };
	int RandomCnt = 0;
	clock_t  Tcount;
	int  Ttime;
	int Tscrentimer;
	bool GameOver;
	Blocks blocks;
	int A;
	int B;
	int Line=0;
	int Score = 0;
public:
	void Move_Left(int arr[][12]);
	void Move_Right(int arr[][12]);
	void Move_Down(int arr[][12]);
	void Move_End(int arr[][12]);
	void Checkmate(int arr[][12]);
	void Block_Change(int arr[][12]);
	void ReBlock_Change(int arr[][12]);
	int _NextBlock();
	void FindPointer(int arr[][12]);
	void CheckPoint(int arr[][12]);
	void CheckDIE(int nowblock, int str[][12]);
	void DestoyNextBlock(int str1[][7]);
	void _MakeNowBlock(int str[][12],int NowBlock);
	void DestroyNowBlock(int str[][12]);

};

void PrintTetris(int str[][12], int str1[][7], int NextBlock, int time,int nowblock, int Line, int score)
{
	system("cls");
	switch (NextBlock)
	{
	case BLOCK_0:
		str1[1][1] = 1, str1[1][2] = 1, str1[1][3] = 1, str1[1][4] = 1;
		break;
	case BLOCK_1:
		str1[1][3] = 1, str1[2][1] = 1, str1[2][2] = 1, str1[2][3] = 1;
		break;
	case BLOCK_2:
		str1[1][2] = 1, str1[2][1] = 1, str1[2][2] = 1, str1[2][3] = 1;
		break;
	case BLOCK_3:
		str1[1][1] = 1, str1[1][2] = 1; str1[2][1] = 1; str1[2][2] = 1;
		break;
	case BLOCK_4:
		str1[1][2] = 1, str1[2][2] = 1, str1[2][3] = 1, str1[2][4] = 1;
		break;
	case BLOCK_5:
		str1[1][2] = 1, str1[1][3] = 1, str1[2][1] = 1, str1[2][2] = 1;
		break;
	case BLOCK_6:
		str1[1][1] = 1, str1[1][2] = 1, str1[2][2] = 1, str1[2][3] = 1;
		break;
	}

	cout << '\n' << '\n';
	for (int i = 0; i < 22; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			if (str[i][k] == -1)
			{
				cout << BLOCK ;
			}
			else if (str[i][k] == 0)
			{
				cout << Code_X;
			}
			else if (str[i][k] == 1)
			{
				
				switch (nowblock)
				{
				case BLOCK_0:
					cout << COLOR_CYAN << Code_O << COLOR_RESET ;
					break;
				case BLOCK_1:
					cout << COLOR_ORANGE << Code_O << COLOR_RESET;
					break;
				case BLOCK_2:
					cout << COLOR_MAGENTA << Code_O << COLOR_RESET;
					break;
				case BLOCK_3:
					cout << COLOR_YELLOW << Code_O << COLOR_RESET;
					break;
				case BLOCK_4:
					cout << COLOR_BLUE << Code_O << COLOR_RESET;
					break;
				case BLOCK_5:
					cout << COLOR_GREEN << Code_O << COLOR_RESET;
					break;
				case BLOCK_6:
					cout << COLOR_RED << Code_O << COLOR_RESET;
					break;
				
				}
				
			}
			else if (str[i][k] == 2)
			{
				cout << WALL;
			}
		}
		if (i < 7)
		{
			cout << "  ";
			for (int k = 0; k < 7; k++)
			{
				if (str1[i][k] == -1)
				{
					cout << BLOCK;
				}
				else if (str1[i][k] == 0)
				{
					cout << Code_X;
				}
				else if (str1[i][k] == 1)
				{
					switch (NextBlock)
					{ 
					case BLOCK_0:
						cout << COLOR_CYAN << Code_O << COLOR_RESET;
						break;
					case BLOCK_1:
						cout << COLOR_ORANGE << Code_O << COLOR_RESET;
						break;
					case BLOCK_2:
						cout << COLOR_MAGENTA << Code_O << COLOR_RESET;
						break;
					case BLOCK_3:
						cout << COLOR_YELLOW << Code_O << COLOR_RESET;
						break;
					case BLOCK_4:
						cout << COLOR_BLUE << Code_O << COLOR_RESET;
						break;
					case BLOCK_5:
						cout << COLOR_GREEN << Code_O << COLOR_RESET;
						break;
					case BLOCK_6:
						cout << COLOR_RED << Code_O << COLOR_RESET;
						break;
					}
					
				}
				else if (str1[i][k] == 2)
				{
					cout << WALL;
				}
			}
		}
		if (i == 10)
		{
			cout << "  ";
			cout << "이동 : ↓ ← →, ";
			cout << "↑ : 즉시낙하," << "  ";
			cout << "X : 시계방향회전  Y : 반시계반향 회전" ;
		}
		if (i == 14)
		{
			cout << "  ";
			cout << "Line : " << Line;
		}
		if (i == 15)
		{
			cout << "  ";
			cout << "Score : "<<score;
		}
		if (i == 16)
		{
			cout << "  ";
			cout << "만든이 : 조용준";
		}
		if (i == 20)
		{
			cout << "  ";
			cout << "Time : "<<time;
		}
		cout << '\n';
	}
}
void MainGame()
{
	Tetris TETRIS;
	char c;
	
	
	TETRIS.NextBlock = TETRIS._NextBlock();
	TETRIS.NowBlock = TETRIS.NextBlock;
	TETRIS.newblock = TETRIS.NowBlock;
	TETRIS._MakeNowBlock(TETRIS.arr, TETRIS.NowBlock);
	TETRIS.NextBlock = TETRIS._NextBlock();
	PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock,TETRIS.Line,TETRIS.Score);
	TETRIS.NowBlock = TETRIS.NextBlock;
	
	
	TETRIS.Tcount = clock();
	
	
	TETRIS.Tscrentimer = GetTickCount();
	TETRIS.Ttime = GetTickCount();
	while(1)
	{
		TETRIS.Tcount = clock();
		
		if (TETRIS.GameOver == true)
		{
			break;
		}
		if (GetTickCount() - TETRIS.Tscrentimer >= 1000)
		{
			TETRIS.Move_Down(TETRIS.arr);
			TETRIS.Tscrentimer = GetTickCount();
			PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
		}
		if (GetTickCount() - TETRIS.Ttime >= LEVEL_1)
		{
			TETRIS.Move_End(TETRIS.arr);
			TETRIS.Checkmate(TETRIS.arr);
			TETRIS.CheckPoint(TETRIS.arr);
			TETRIS.CheckDIE(TETRIS.NowBlock, TETRIS.arr);
			TETRIS.newblock = TETRIS.NowBlock;
			TETRIS._MakeNowBlock(TETRIS.arr, TETRIS.NowBlock);
			TETRIS.DestoyNextBlock(TETRIS.arr1);
			TETRIS.NextBlock = TETRIS._NextBlock();
			TETRIS.NowBlock = TETRIS.NextBlock;
			TETRIS.Ttime = GetTickCount();
		}
		if (_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				switch (c)
				{
				case LEFT:
					TETRIS.Move_Left(TETRIS.arr);
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				case RIGHT:
					TETRIS.Move_Right(TETRIS.arr);
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				case UP:
					TETRIS.Move_End(TETRIS.arr);
					TETRIS.Checkmate(TETRIS.arr);
					TETRIS.CheckPoint(TETRIS.arr);
					TETRIS.CheckDIE(TETRIS.NowBlock, TETRIS.arr);
					TETRIS.newblock = TETRIS.NowBlock;
					TETRIS._MakeNowBlock(TETRIS.arr, TETRIS.NowBlock);
					TETRIS.DestoyNextBlock(TETRIS.arr1);
					TETRIS.NextBlock = TETRIS._NextBlock();
					TETRIS.NowBlock = TETRIS.NextBlock;
					TETRIS.Ttime = GetTickCount();
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				case DOWN:
					TETRIS.Move_Down(TETRIS.arr);
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				}
			}
			else
			{
				switch (c)
				{
				case CHANGE:
					TETRIS.Block_Change(TETRIS.arr);
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				case RECHANGE:
					TETRIS.ReBlock_Change(TETRIS.arr);
					PrintTetris(TETRIS.arr, TETRIS.arr1, TETRIS.NextBlock, TETRIS.Tcount / CLOCKS_PER_SEC, TETRIS.newblock, TETRIS.Line, TETRIS.Score);
					break;
				}
			}
		}
	}
	
}

void Tetris::Move_Left(int arr[][12])
{
	bool canmove = false;
	for (int i = 0; i < 22; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			if (arr[i][k] == 1)
			{
				if (arr[i][k - 1] == -1 || arr[i][k - 1] == 2)
				{
					canmove = true;
				}
			}
		}
	}
	if (canmove != true)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int k = 0; k < 12; k++)
			{
				if (arr[i][k] == 1)
				{
					arr[i][k - 1] = 1;
					arr[i][k] = 0;
				}
			}
		}
	}
}

void Tetris::Move_Right(int arr[][12])
{
	bool canmove = false;
	for (int i = 0; i < 22; i++)
	{
		for (int k = 11; k > 0; k--)
		{
			if (arr[i][k] == 1)
			{
				if (arr[i][k + 1] == -1 || arr[i][k + 1] == 2)
				{
					canmove = true;
				}
			}
		}
	}
	if (canmove != true)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int k = 11; k > 0; k--)
			{
				if (arr[i][k] == 1)
				{
					arr[i][k + 1] = 1;
					arr[i][k] = 0;
				}
			}
		}
	}
}

void Tetris::Move_Down(int arr[][12])
{
	bool canmove = false;
	for (int i = 21; i > 0; i--)
	{
		for (int k = 0; k < 12; k++)
		{
			if (arr[i][k] == 1)
			{
				if (arr[i+1][k] == -1 || arr[i+1][k] == 2)
				{
					canmove = true;
				}
			}
		}
	}
	if (canmove != true)
	{
		for (int i = 21; i > 0; i--)
		{
			for (int k = 0; k < 12; k++)
			{
				if (arr[i][k] == 1)
				{
					arr[i+1][k] = 1;
					arr[i][k] = 0;
				}
			}
		}
	}
}

void Tetris::Move_End(int arr[][12])
{
	bool canmove = false;
	while (1)
	{
		for (int i = 21; i > 0; i--)
		{
			for (int k = 0; k < 12; k++)
			{
				if (arr[i][k] == 1)
				{
					if (arr[i + 1][k] == -1 || arr[i + 1][k] == 2)
					{
						canmove = true;
					}
				}
			}
		}
		if (canmove != true )
		{
			Move_Down(arr);
		}
		else if (canmove == true)
		{
			break;
		}
	}
}

void Tetris::Checkmate(int arr[][12])
{
	for (int i = 0; i < 22; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			if (arr[i][k] == 1)
			{
				arr[i][k] = 2;
			}
		}
	}
}

void Tetris::Block_Change(int arr[][12])
{
	FindPointer(arr);
	
	switch (blocks)
	{
	case BLOCK_0_1:
		if (arr[A][B + 2] != -1 && arr[A][B + 2] != 2 && arr[A + 1][B + 2] != -1 && arr[A + 1][B + 2] != 2 && arr[A + 2][B + 2] != -1 && arr[A + 2][B + 2] != 2 && arr[A + 3][B + 2] != -1 && arr[A + 3][B + 2] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 2] = 1, arr[A + 1][B + 2] = 1, arr[A + 2][B + 2] = 1, arr[A + 3][B + 2] = 1;
			blocks = Blocks::BLOCK_0_2;
		}
		break;
	case BLOCK_0_2:
		if (arr[A + 1][B - 2] != -1 && arr[A + 1][B - 2] != 2 && arr[A + 1][B - 1] != -1 && arr[A + 1][B - 1] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 2] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_0_3;
		}
		break;
	case BLOCK_0_3:
		if (arr[A - 1][B + 1] != -1 && arr[A - 1][B + 1] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2 && arr[A + 2][B + 1] != -1 && arr[A + 2][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B + 1] = 1, arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_0_4;
		}
		break;
	case BLOCK_0_4:
		if (arr[A][B - 1] != -1 && arr[A][B - 1] != 2 && arr[A][B] != -1 && arr[A][B] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A][B + 2] != -1 && arr[A][B + 2] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A][B] = 1, arr[A][B + 1] = 1, arr[A][B + 2] = 1;
			blocks = Blocks::BLOCK_0_1;
		}
		break;
	case BLOCK_1_1:
		if (arr[A][B - 1] != -1 && arr[A][B - 1] != 2 && arr[A + 1][B - 1] != -1 && arr[A + 1][B - 1] != 2 && arr[A + 2][B - 1] != -1 && arr[A + 2][B - 1] != 2 && arr[A + 2][B] != -1 && arr[A + 2][B] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 2][B - 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_1_2;
		}
		break;
	case BLOCK_1_2:
		if (arr[A][B] != -1 && arr[A][B] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A][B + 2] != -1 && arr[A][B + 2] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_1_3;
		}
		break;
	case BLOCK_1_3:
		if (arr[A][B] != -1 && arr[A][B] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2 && arr[A + 2][B + 1] != -1 && arr[A + 2][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_1_4;
		}
		break;
	case BLOCK_1_4:
		if (arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B - 1] != -1 && arr[A + 1][B - 1] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_1_1;
		}
		break;
	case BLOCK_2_1:
		if (arr[A][B] != -1 && arr[A][B] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2 && arr[A + 2][B] != -1 && arr[A + 2][B] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_2_2;
		}
		break;
	case BLOCK_2_2:
		if (arr[A + 1][B - 1] != -1 && arr[A + 1][B - 1] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2 && arr[A + 2][B] != -1 && arr[A + 2][B] !=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLCOK_2_3;
		}
		break;
	case BLCOK_2_3:
		if (arr[A][B] != -1 && arr[A][B] != 2 && arr[A - 1][B + 1] != -1 && arr[A - 1][B + 1] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A - 1][B + 1] = 1, arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_2_4;
		}
		break;
	case BLOCK_2_4:
		if (arr[A][B] != -1&& arr[A][B] != 2 && arr[A+1][B-1] != -1 && arr[A+1][B-1] !=2&& arr[A+1][B] !=-1&& arr[A+1][B] !=2 && arr[A+1][B+1] !=-1&& arr[A+1][B+1] !=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_2_1;
		}
		break;
	case BLOCK_4_1:
		if (arr[A][B] != -1 && arr[A][B] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B] != -1 && arr[A + 1][B] != 2 && arr[A + 2][B] != -1 && arr[A + 2][B] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_4_2;
		}
		break;
	case BLOCK_4_2:
		if (arr[A][B - 1] != -1 && arr[A][B - 1] != 2 && arr[A][B] != -1 && arr[A][B] != 2 && arr[A][B + 1] != -1 && arr[A][B + 1] != 2 && arr[A + 1][B + 1] != -1 && arr[A + 1][B + 1] != 2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1,arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLCOK_4_3;
		}
		break;
	case BLCOK_4_3:
		if (arr[A][B + 2] != -1 && arr[A][B + 2] != 2 && arr[A+1][B + 2] != -1 && arr[A + 1][B + 2] !=2 && arr[A + 2][B + 1] !=-1 && arr[A + 2][B + 1]!=2 && arr[A + 2][B + 2]!=-1&& arr[A + 2][B + 2]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 2] = 1, arr[A + 1][B + 2] = 1, arr[A + 2][B + 1] = 1, arr[A + 2][B + 2] = 1;
			blocks = Blocks::BLCOK_4_4;
		}
		break;
	case BLCOK_4_4:
		if (arr[A][B-1]!=-1&& arr[A][B - 1]!=2 && arr[A+1][B - 1]!= -1&& arr[A + 1][B - 1]!=2 && arr[A + 1][B] != -1&& arr[A + 1][B] !=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_4_1;
		}
		break;
	case BLOCK_5_1:
		if (arr[A][B] != -1 && arr[A][B]!=2 && arr[A+1][B] != -1&& arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 2][B + 1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_5_2;
		}
		break;
	case BLOCK_5_2:
		if (arr[A+1][B]!= -1&& arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2 && arr[A + 2][B-1]!=-1&& arr[A + 2][B - 1]!=2&& arr[A + 2][B ]!=-1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B - 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_5_3;
		}
		break;
	case BLOCK_5_3:
		if (arr[A-1][B-1] != -1 && arr[A - 1][B - 1]!= 2 && arr[A][B - 1]!=-1&& arr[A][B - 1]!=2 && arr[A][B]!=-1&& arr[A][B]!=2&& arr[A+1][B]!=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B - 1] = 1, arr[A][B - 1] = 1, arr[A][B] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_5_4;
		}
		break;
	case BLOCK_5_4:
		if (arr[A][B+1]!=-1&& arr[A][B + 1]!=2&& arr[A][B + 2]!=-1&& arr[A][B + 2]!=2&& arr[A+1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_5_1;
		}
		break;
	case BLOCK_6_1:
		if (arr[A][B+2]!= -1 && arr[A][B + 2]!=2&& arr[A+1][B +1]!=-1&& arr[A + 1][B + 1]!=2 && arr[A + 1][B + 2]!=-1&& arr[A + 1][B + 2]!=2&& arr[A + 2][B + 1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 2] = 1, arr[A + 1][B + 1] = 1, arr[A + 1][B + 2] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_6_2;
		}
		break;
	case BLOCK_6_2:
		if (arr[A+1][B-2]!=-1&& arr[A + 1][B - 2]!=2&& arr[A + 1][B - 1]!=-1&& arr[A + 1][B - 1]!=2 && arr[A + 2][B - 1]!=-1&& arr[A + 2][B - 1]!=2&& arr[A + 2][B]!=-1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 2] = 1, arr[A + 1][B - 1] = 1, arr[A + 2][B - 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_6_3;
		}
		break;
	case BLOCK_6_3:
		if (arr[A-1][B+1]!=-1&& arr[A - 1][B + 1]!=2 && arr[A][B]!=-1&& arr[A][B]!=2&& arr[A][B+1]!=-1&& arr[A][B + 1]!=2&& arr[A+1][B]!=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B + 1] = 1, arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_6_4;
		}
		break;
	case BLOCK_6_4:
		if (arr[A][B-1]!=-1&& arr[A][B - 1]!=2&& arr[A][B]!=-1&& arr[A][B]!=2 && arr[A+1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A][B] = 1, arr[A + 1][B] = 1 , arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_6_1;
		}
		break;
	}
}

void Tetris::ReBlock_Change(int arr[][12])
{
	FindPointer(arr);
	switch (blocks)
	{
	case BLOCK_0_1:
		if (arr[A][B + 1] !=-1&& arr[A][B + 1]!=2 && arr[A+1][B + 1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 2][B + 1]!=-1&& arr[A + 2][B + 1]!=2&& arr[A + 3][B + 1]!=-1&& arr[A + 3][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B + 1] = 1, arr[A + 3][B + 1] = 1;
			blocks = Blocks::BLOCK_0_4;
		}
		break;
	case BLOCK_0_2:
		if (arr[A][B - 2] != -1 && arr[A][B - 2]!=2 && arr[A][B - 1]!=-1&& arr[A][B - 1]!=2&& arr[A][B]!=-1&& arr[A][B]!=2&& arr[A][B+1]!=-1&& arr[A][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 2] = 1, arr[A][B - 1] = 1, arr[A][B] = 1, arr[A][B + 1] = 1;
			blocks = Blocks::BLOCK_0_1;
		}
		break;
	case BLOCK_0_3:
		if (arr[A-1][B+2] != -1&& arr[A - 1][B + 2]!=2 && arr[A][B + 2]!=-1&& arr[A][B + 2]!=2 && arr[A+1][B + 2]!=-1&& arr[A + 1][B + 2]!=2&& arr[A + 2][B + 2]!=-1&& arr[A + 2][B + 2]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B + 2] = 1, arr[A][B + 2] = 1, arr[A + 1][B + 2] = 1, arr[A + 2][B + 2] = 1;
			blocks = Blocks::BLOCK_0_2;
		}
		break;
	case BLOCK_0_4:
		if (arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2 && arr[A + 1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 1][B + 2]!=-1&& arr[A + 1][B + 2]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 1][B + 2] = 1;
			blocks = Blocks::BLOCK_0_3;
		}
		break;
	case BLOCK_1_1:
		if (arr[A][B - 1]!=-1&& arr[A][B - 1]!=2&& arr[A][B]!=-1&& arr[A][B]!=2&& arr[A+1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 2][B]!= -1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A][B] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_1_4;
		}
		break;
	case BLOCK_1_2:
		if (arr[A][B+1] != -1 && arr[A][B + 1]!=2 && arr[A+1][B - 1] !=-1 && arr[A + 1][B - 1]!=2 && arr[A + 1][B]!=-1 && arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_1_1;
		}
		break;
	case BLOCK_1_3:
		if (arr[A][B] != -1 && arr[A][B]!=2 && arr[A+1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 2][B]!=-1&& arr[A + 2][B]!=2 && arr[A + 2][B+1] !=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_1_2;
		}
		break;
	case BLOCK_1_4:
		if (arr[A][B]!=-1 && arr[A][B]!=2 && arr[A][B+1]!=-1&& arr[A][B + 1]!=2&& arr[A][B + 2]!=-1&& arr[A][B + 2]!=2 && arr[A+1][B] !=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_1_3;
		}
		break;
	case BLOCK_2_1:
		if (arr[A][B] != -1 && arr[A][B] !=2 && arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2&& arr[A + 1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 2][B]!=-1 && arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_2_4;
		}
		break;
	case BLOCK_2_2:
		if (arr[A][B]!=-1&& arr[A][B]!=2 && arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2&& arr[A + 1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_2_1;
		}
		break;
	case BLCOK_2_3:
		if (arr[A-1][B+1]!=-1 && arr[A - 1][B + 1]!=2 && arr[A][B + 1]!=-1 && arr[A][B + 1]!=2 && arr[A][B + 2]!=-1&& arr[A][B + 2]!=2 && arr[A+1][B + 1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B + 1] = 1, arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_2_2;
		}
		break;
	case BLOCK_2_4:
		if (arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2 && arr[A + 1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2 && arr[A + 2][B]!=-1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLCOK_2_3;
		}
		break;
	case BLOCK_4_1:
		if (arr[A][B+1] !=-1&& arr[A][B+1]!=2 && arr[A+1][B+1]!=-1&& arr[A + 1][B+1]!=2 && arr[A + 2][B]!=-1&& arr[A + 2][B]!=2 && arr[A + 2][B+1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B+1] = 1, arr[A + 1][B+1] = 1, arr[A + 2][B] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLCOK_4_4;
		}
		break;
	case BLOCK_4_2:
		if (arr[A][B]!=-1&& arr[A][B]!=2 && arr[A+1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 1][B + 2]!=-1&& arr[A + 1][B + 2]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 1][B + 2] = 1;
			blocks = Blocks::BLOCK_4_1;
		}
		break;
	case BLCOK_4_3:
		if (arr[A][B+1]!=-1&& arr[A][B + 1]!=2&& arr[A][B + 2]!=-1&& arr[A][B + 2]!=2 && arr[A+1][B + 1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 2][B + 1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_4_2;
		}
		break;
	case BLCOK_4_4:
		if (arr[A][B-2]!=-1&& arr[A][B - 2]!=2 && arr[A][B - 1]!=-1 && arr[A][B - 1]!=2 && arr[A][B]!=-1&& arr[A][B]!=2&& arr[A+1][B]!=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 2] = 1, arr[A][B - 1] = 1, arr[A][B] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLCOK_4_3;
		}
		break;
	case BLOCK_5_1:
		if (arr[A][B-1]!=-1&& arr[A][B - 1]!=2&& arr[A+1][B - 1]!=-1&& arr[A + 1][B - 1]!=2&& arr[A + 1][B]!=-1&& arr[A + 1][B]!=2 && arr[A + 2][B]!=-1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_5_4;
		}
		break;
	case BLOCK_5_2:
		if (arr[A][B]!=-1&& arr[A][B]!=2&& arr[A][B + 1]!=-1&& arr[A][B + 1]!=2 && arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2 && arr[A + 1][B]!=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_5_1;
		}
		break;
	case BLOCK_5_3:
		if (arr[A-1][B]!=-1&& arr[A - 1][B]!=2&& arr[A][B]!=-1&& arr[A][B]!=2&& arr[A][B+1]!=-1&& arr[A][B + 1]!=2&& arr[A+1][B + 1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B] = 1, arr[A][B] = 1, arr[A][B + 1] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_5_2;
		}
		break;
	case BLOCK_5_4:
		if(arr[A+1][B+1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 1][B + 2]!=-1&& arr[A + 1][B + 2]!=2&& arr[A + 2][B ]!=-1&& arr[A + 2][B]!=2&& arr[A + 2][B+1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B + 1] = 1, arr[A + 1][B + 2] = 1, arr[A + 2][B] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_5_3;
		}
		break;
	case BLOCK_6_1:
		if (arr[A][B+1]!=-1&& arr[A][B + 1]!=2 && arr[A+1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 1][B+1]!=-1&& arr[A + 1][B + 1]!=2&& arr[A + 2][B]!=-1&& arr[A + 2][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B + 1] = 1, arr[A + 1][B] = 1, arr[A + 1][B + 1] = 1, arr[A + 2][B] = 1;
			blocks = Blocks::BLOCK_6_4;
		}
		break;
	case BLOCK_6_2:
		if (arr[A][B-2]!=-1&& arr[A][B - 2]!=2&& arr[A][B - 1]!=-1&& arr[A][B - 1]!=2&& arr[A+1][B - 1]!=-1&& arr[A + 1][B - 1]!=2&& arr[A + 1][B]!=-1&& arr[A + 1][B]!=2)
		{
			DestroyNowBlock(arr);
			arr[A][B - 2] = 1, arr[A][B - 1] = 1, arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1;
			blocks = Blocks::BLOCK_6_1;
		}
		break;
	case BLOCK_6_3:
		if (arr[A-1][B+2]!=-1&& arr[A - 1][B + 2]!=2&& arr[A][B + 1]!=-1&& arr[A][B + 1]!=2&& arr[A][B + 2]!=-1&& arr[A][B + 2]!=2&& arr[A+1][B + 1]!=-1&& arr[A + 1][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A - 1][B + 2] = 1, arr[A][B + 1] = 1, arr[A][B + 2] = 1, arr[A + 1][B + 1] = 1;
			blocks = Blocks::BLOCK_6_2;
		}
		break;
	case BLOCK_6_4:
		if (arr[A+1][B-1]!=-1&& arr[A + 1][B - 1]!=2&& arr[A + 1][B]!=-1&& arr[A + 1][B]!=2&& arr[A + 2][B]!=-1&& arr[A + 2][B]!=2&& arr[A + 2][B+1]!=-1&& arr[A + 2][B + 1]!=2)
		{
			DestroyNowBlock(arr);
			arr[A + 1][B - 1] = 1, arr[A + 1][B] = 1, arr[A + 2][B] = 1, arr[A + 2][B + 1] = 1;
			blocks = Blocks::BLOCK_6_3;
		}
		break;
	}
}



int Tetris::_NextBlock()
{
	srand(time(NULL));
	int Random;
	if (RandomCnt >= 7)
	{
		RandomCnt = 0;
		for (int i = 0; i < 7; i++)
		{
			RandomList[i] = i;
		}
	}
	
	while (1)
	{
		Random = rand() % 7;
		if (RandomList[Random] != -1)
		{
			RandomList[Random] = -1;
			RandomCnt++;
			break;
		}
	}
	return Random;
}

void Tetris::FindPointer(int arr[][12])
{
	int i = 0, k = 0;
	while (1)
	{
		if (k == 11)
		{
			k = 0;
			i++;
		}
		if (i > 22)
		{
			break;
		}
		if (arr[i][k] == 1)
		{
			A = i; B = k;
			break;
		}
		k++;
	}
}

void Tetris::CheckPoint(int arr[][12])
{
	int LineCNT = 0;
	for (int i = 1; i < 21; i++)
	{
		if (arr[i][1] == 2 && arr[i][2] == 2 && arr[i][3] == 2 && arr[i][4] == 2 && arr[i][5] == 2 && arr[i][6] == 2 && arr[i][7] == 2 && arr[i][8] == 2 && arr[i][9] == 2 && arr[i][10] == 2)
		{
			LineCNT++;
			Line++;
			for (int j = 1; j < 11; j++)
			{
				arr[i][j] = 0;
			}
			for (int k = i; k > 0; k--)
			{
				for (int j = 1 ;j < 11; j++)
				{
					if (arr[k-1][j] == 2)
					{
						arr[k][j] = 2;
						arr[k - 1][j] = 0;
					}
				}
			}
		}
	}
	if (LineCNT > 0)
	{
		switch (LineCNT)
		{
		case 1:
			Score += 100 * LineCNT;
			break;
		case 2:
			Score += 150 * LineCNT;
			break;
		case 3:
			Score += 200 * LineCNT;
			break;
		case 4:
			Score += 300 * LineCNT;
			break;
		}
	}
}

void Tetris::CheckDIE(int nowblock, int str[][12])
{
	switch (nowblock)
	{
	case BLOCK_0:
		if (str[1][6] == 2 || str[2][6] == 2 || str[3][6] == 2 || str[4][6] == 2)
			GameOver = true;
		break;
	case BLOCK_1:
		if (str[1][5] == 2 || str[2][5] == 2 || str[3][5] == 2 || str[3][6] == 2)
			GameOver = true;
		break;
	case BLOCK_2:
		if (str[1][6] == 2 || str[2][5] == 2 || str[2][6] == 2 || str[3][6] == 2)
			GameOver = true;
		break;
	case BLOCK_3:
		if (str[1][5] == 2 || str[1][6] == 2 || str[2][5] == 2 || str[2][6] == 2)
			GameOver = true;
		break;
	case BLOCK_4:
		if (str[1][6] == 2 || str[2][6] == 2 || str[3][5] == 2 || str[3][6] == 2)
			GameOver = true;
		break;
	case BLOCK_5:
		if (str[1][6] == 2 || str[1][7] == 2 || str[2][5] == 2 || str[2][6] == 2)
			GameOver = true;
		break;
	case BLOCK_6:
		if (str[1][5] == 2 || str[1][6] == 2 || str[2][6] == 2 || str[2][7] == 2)
			GameOver = true;
		break;
	}
}

void Tetris::DestoyNextBlock(int str1[][7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (str1[i][k] == 1)
			{
				str1[i][k] = 0;
			}
		}
	}
}

void Tetris::_MakeNowBlock(int str[][12], int NowBlock)
{
	if (GameOver != true)
	{
		switch (NowBlock)
		{
		case BLOCK_0:
			blocks = Blocks::BLOCK_0_1;
			str[1][4] = 1, str[1][5] = 1, str[1][6] = 1, str[1][7] = 1;
			break;
		case BLOCK_1:
			blocks = Blocks::BLOCK_1_1;
			str[1][6] = 1, str[2][4] = 1, str[2][5] = 1, str[2][6] = 1;
			break;
		case BLOCK_2:
			blocks = Blocks::BLOCK_2_1;
			str[1][5] = 1, str[2][4] = 1, str[2][5] = 1, str[2][6] = 1;
			break;
		case BLOCK_3:
			blocks = Blocks::BLCOK3;
			str[1][5] = 1, str[1][6] = 1, str[2][5] = 1, str[2][6] = 1;
			break;
		case BLOCK_4:
			blocks = Blocks::BLOCK_4_1;
			str[1][5] = 1, str[2][5] = 1, str[2][6] = 1, str[2][7] = 1;
			break;
		case BLOCK_5:
			blocks = Blocks::BLOCK_5_1;
			str[1][5] = 1, str[1][6] = 1, str[2][4] = 1, str[2][5] = 1;
			break;
		case BLOCK_6:
			blocks = Blocks::BLOCK_6_1;
			str[1][4] = 1, str[1][5] = 1, str[2][5] = 1, str[2][6] = 1;
			break;
		}
	}
}

void Tetris::DestroyNowBlock(int str[][12])
{
	for (int i = 0; i < 22; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			if (str[i][k] == 1)
			{
				str[i][k] = 0;
			}
		}
	}
}




