#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WHEELS 3
#define SYMBOLS 10
#define CHERRIES 7
#define PREMIUM 3
#define PREMIUM_PAYOUT 10
#define TWO_PREMIUM_PAYOUT 50
#define THREE_PREMIUM_PAYOUT 100
#define TWO_MATCHING_PAYOUT 10
#define THREE_MATCHING_PAYOUT 50
#define PLAYS 1000

int main() {
    int i, j, k, symbol, count_premium, count_cherries, count_match, payout, house_wins, player_wins;
    double house_payout, player_payout;
    srand(time(NULL)); // seed the random number generator with the current time

    // House wins seed
    house_wins = 0;
    for (i = 0; i < PLAYS; i++) {
        count_premium = 0;
        count_cherries = 0;
        for (j = 0; j < WHEELS; j++) {
            symbol = rand() % SYMBOLS;
            if (symbol == CHERRIES || symbol == PREMIUM) {
                count_premium++;
            }
            if (symbol == CHERRIES) {
                count_cherries++;
            }
        }
        if (count_premium == 1) {
            payout = PREMIUM_PAYOUT;
        }
        else if (count_premium == 2) {
            payout = TWO_PREMIUM_PAYOUT;
        }
        else if (count_premium == WHEELS) {
            payout = THREE_PREMIUM_PAYOUT;
        }
        else {
            payout = 0;
        }
        house_wins += (payout == 0);
    }
    house_payout = (double)house_wins / PLAYS;
    player_payout = 1 - house_payout;
    printf("House wins seed:\n");
    printf("House payout: %.2f%%\n", house_payout * 100);
    printf("Player payout: %.2f%%\n\n", player_payout * 100);

    // Player wins seed
    player_wins = 0;
    for (i = 0; i < PLAYS; i++) {
        count_premium = 0;
        count_cherries = 0;
        count_match = 0;
        for (j = 0; j < WHEELS; j++) {
            symbol = rand() % SYMBOLS;
            if (symbol == CHERRIES || symbol == PREMIUM) {
                count_premium++;
            }
            if (symbol == CHERRIES) {
                count_cherries++;
            }
            for (k = j + 1; k < WHEELS; k++) {
                if (symbol == (rand() % SYMBOLS)) {
                    count_match++;
                }
            }
        }
        if (count_match == WHEELS - 1) {
            payout = TWO_MATCHING_PAYOUT;
        }
        else if (count_match == WHEELS * (WHEELS - 1) / 2) {
            payout = THREE_MATCHING_PAYOUT;
        }
        else if (count_premium == 1) {
            payout = PREMIUM_PAYOUT;
        }
        else if (count_premium == 2) {
            payout = TWO_PREMIUM_PAYOUT;
        }
        else if (count_premium == WHEELS) {
            payout = THREE_PREMIUM_PAYOUT;
        }
        else {
            payout = 0;
        }
        player_wins += (payout > 0);
    }

	player_payout = (double)player_wins / PLAYS;
	house_payout = 1 - player_payout;
	printf("Player wins seed:\n");
	printf("Player payout: %.2f%%\n", house_payout * 100);
	printf("House payout: %.2f%%\n\n", player_payout * 100);

}
