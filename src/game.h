#ifndef GAME_H_
#define GAME_H_
#include "arrays.h"
#include "tools.h"
#include "linked_lists.h"
#include "globals.h"


typedef struct player{
	char name[15];
	bool ai;
	array bet_cards;
	array run_cards;
	int score;
}player;

typedef struct players{
	player *player;
	int n_players;
}players;

typedef struct deck{
	list card_list;
	array totals;
}deck;

/// Funzioni principali
int newGame(players *, array *, deck *, array *);

int loadGame(array *winners, array *played, players *p, deck * deck, array *run, int *saved_turn);

int settings(players *);

int rules(void);

int saveGame(array *winners, array *played, players *p, deck * deck, array *run, int *saved_turn);

/// Funzioni essenziali del gioco
deck shuffleDeck(deck *);

players createPlayers(players *);

players namePlayers(players *);

int GetCard(deck *);

players firstBetCard(players *);

int secondBetCard(player , deck *, array *);

array playerGetCard(player *, array *, int , array *);

int checkPlayedCards(array *);

int play(players *p, array *, deck *, array *, array * , bool loaded, int *saved_turn);

int playerTurn(players *, array *,deck *, array *, int );

bool runPhase(players *, array *, array *, array *);

void StandPositions(array *run, array *);

int getMaxScore(players *p);

void sortScore( players *p );

void scores(players *players, array *winners);
/// Funzioni di gestione
void errorHandle(int error);

int initConsole(void);

#endif /* GAME_H_ */

