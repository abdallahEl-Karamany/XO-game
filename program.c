#include<stdio.h>
#include<conio.h>

/*
***********************************
**********Macros*******************
***********************************
*/

typedef unsigned char uint8_t;

/*
***********************************
**********Global Variables*********
***********************************
*/

uint8_t Board[9]={'1','2','3','4','5','6','7','8','9'};

uint8_t ConfigArray[2];
int position;
uint8_t gameState=2;
uint8_t player;

/*
***********************************
**********Prototypes***************
***********************************
*/

void DrawBoard(uint8_t *board);

void UpdateBoard(uint8_t *board,uint8_t Position,uint8_t Value);

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol);

void setPlayerConfig(uint8_t *config_Array);

void loadAndUpdate(uint8_t playerNumber);

void getGameState(uint8_t *board, uint8_t *gameState);

/*
***********************************
**********main function***************
***********************************
*/

int main()
{
	uint8_t i;

	setPlayerConfig(ConfigArray);
	printf("player1 symbol is: %c \n",ConfigArray[0]);
	printf("player2 symbol is: %c \n",ConfigArray[1]);
	DrawBoard(Board);

	for(i=1;i<=9;i++)
	{
		if(i%2!=0)
		{
			printf("player1 turn %c \n",ConfigArray[0]);
			player=1;
			loadAndUpdate(player);
			getGameState(Board,&gameState);
			if(gameState==0)
			{
				printf("Congraaaats Player1, you are the Winner \n");
			}

		}
		else
		{
			printf("player2 turn %c \n",ConfigArray[1]);
			player=2;
			loadAndUpdate(player);
			getGameState(Board,&gameState);

			if(gameState==0)
			{
				printf("Congraaaats Player2, you are the Winner \n");
			}

		}

		if(gameState==0)
		{
			break;
		}


	}

	if(gameState==2)
	{
		printf("game Draw, no winner no loser");

	}


}



/************************************
*************************************
************************************/

void DrawBoard(uint8_t *board)
{
	system("cls");
	uint8_t i;
	for(i=0;i<9;i++)
	{
		if(i%3==0)
		{
			printf("\n");
		}
	printf("%c	",board[i]);

	}
	printf("\n \n");

}

/************************************
*************************************
************************************/

void UpdateBoard(uint8_t *board,uint8_t Position,uint8_t Value)
{
	board[Position-1]=Value;
	DrawBoard(board);

}

/************************************
*************************************
************************************/

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol)
{
	if(playerNumber== 1)
	{
		if(symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
		{
			return 0;
		}
		else
		{
			printf("wrong symbol,please choose X or O \n");

			return 1;
		}


	}

	else
	{
	if(playerNumber== 2)
	{
		if(symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
		{
			if(symbol[playerNumber-1]!=symbol[playerNumber-2])
			{
			return 0;
			}
			else
			{
				printf("duplicate symbol, please choose another one \n");
				return 1;
			}
		}
		else
		{
			printf("wrong symbol,please choose X or O \n");

			return 1;
		}

	}

	}

}

/************************************
*************************************
************************************/

void setPlayerConfig(uint8_t *config_Array)
{

	uint8_t status=1;

	while(status==1)
	{
		printf("player 1 please choose X or O \n");
		scanf(" %c",&config_Array[0]);
		status= getPlayerSymbol(1,config_Array);

	}

	status=1;

	while(status==1)
	{
		printf("player 2 please choose X or O \n");
		scanf(" %c", &config_Array[1]);
		status= getPlayerSymbol(2,config_Array);

	}

	//printf("%c",config_Array[0]);
	//printf("%c",config_Array[1]);

}

/************************************
*************************************
************************************/

void loadAndUpdate(uint8_t playerNumber)
{
	uint8_t playerConfig;
	playerConfig=ConfigArray[playerNumber-1];
	printf("please enter the position you want to play in \n");
	scanf("%d",&position);
	if(Board[position-1]=='X' || Board[position-1]=='O')
	{
		printf("wrong position was taken before please choose a free one \n \n");
		loadAndUpdate(playerNumber);

	}
	UpdateBoard(Board,position,playerConfig);

}

/************************************
*************************************
************************************/

void getGameState(uint8_t *board, uint8_t *gameState)
{

	if(Board[0]==Board[1] && Board[1]==Board[2])
	{
		*gameState=0;
	}

	else if(Board[3]==Board[4] && Board[4]==Board[5])
	{
		*gameState=0;
	}

	else if(Board[6]==Board[7] && Board[7]==Board[8])
	{
		*gameState=0;
	}

	else if(Board[0]==Board[3] && Board[3]==Board[6])
	{
		*gameState=0;
	}

	else if(Board[1]==Board[4] && Board[4]==Board[7])
	{
		*gameState=0;
	}

	else if(Board[2]==Board[5] && Board[5]==Board[8])
	{
		*gameState=0;
	}

	else if(Board[0]==Board[4] && Board[4]==Board[8])
	{
		*gameState=0;
	}

	else if(Board[2]==Board[4] && Board[4]==Board[6])
	{
		*gameState=0;
	}

	else
	{
		*gameState=2;
	}


}
