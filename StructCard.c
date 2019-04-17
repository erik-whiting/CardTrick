#include <stdio.h>
#include <string.h>

struct Card {
	int face;
	int shape;
	int color;
};
// face: 1-13
// shape 1 - diamond, 2 - heart, 3 - spade, 4 - club
// color 1 - red, 2 - black

static struct Card initializeCard(int face, int shape) {
	int color;

	if (face == 1 || face == 2) {
		color = 1;
	} else {
		color = 2;
	}

	struct Card c = {face, shape, color};
	return c;
}

static void SayFace(int face) {
	face++;
	if (face == 1) {
		printf("The Ace of ");
	}
	else if (face <= 10) {
		printf("The %i of ", face);
	} else {
		switch(face) {
			case 11:
				printf("The Jack of ");
			break;
			case 12:
				printf("The Queen of ");
			break;
			case 13:
				printf("The King of ");
			break;
			default:
			printf("AHHH I BROKE ");
		}
	}
}

static void SayShape(int shape) {
	shape++;
	switch(shape) {
		case 1:
			printf("Diamonds \n");
		break;
		case 2:
			printf("Hearts \n");
		break;
		case 3:
			printf("Spades \n");
		break;
		case 4:
			printf("Clubs \n");
		break;
		default:
			printf("AHH I BROKE");
		break;
	}
}

int main() {
	struct Card deck[52];

	for (int i = 0; i < 13; i++) {
		for (int s = 0; s < 4; s++) {
			deck[(i * 4) + s] = initializeCard(i, s);
		}
	}

	for (int x = 0; x < 52; x++) {
		SayFace(deck[x].face);
		SayShape(deck[x].shape);
	}

	return 0;
}
