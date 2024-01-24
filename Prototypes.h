/* implement and draw your board */

void DrawBoard(uint8_t *board);
void UpdateBoard(uint8_t *board,uint8_t Position,uint8_t Value);


/* implement players config */

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
void setPlayerConfig(uint8_t *configArray);
 
 
/* implement selected players move */
void loadAndUpdate(uint8_t playerNumber);

/* implement winning condition check */
void getGameState(uint8_t *board, uint8_t *gameState);

/* implement the main flow */


/* test your main flow */

/*
1. Test the main flow against the wrong symbol choice
2. Test the main flow against repeated symbol choice
3. Test the main flow against X player winning:
- All Rows winning (3)
- All Columns winning (3)
- All Diagonals winning (2)
4. Test the main flow against O player winning: 
- All Rows winning (3) 
- All Columns winning (3) 
- All Diagonals winning (2)
5. Test the main flow against X player draw case at least three draw cases
*/
