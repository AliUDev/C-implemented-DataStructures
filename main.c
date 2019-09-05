#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"
#include <time.h>
int main() {
	/*
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	initTree(tree);
	addNode(tree, &tree->root, 10);
	addNode(tree, &tree->root, 2);
	addNode(tree, &tree->root, 12);
	addNode(tree, &tree->root, 1);
	addNode(tree, &tree->root, 8);
	levelOrder(tree);
	free(tree);
	//inOrder(tree->root);
	*/


    srand(time(NULL));
    int randomNum = rand() % 11;
    int userInput;
    int isFinished = 0;
    
	printf("Welcome to random number guessing game \n");
	printf("Please guess a number between 1 - 10 \n");
	scanf("%d", &userInput);
	while (isFinished == 0)
    {
		
		
        if (userInput > randomNum)
        {
            printf("Your number is high \n");
            scanf("%d", &userInput);
        }
        else if (userInput < randomNum)
        {
            printf("Your number is low \n");
            scanf("%d", &userInput);
        }
        else
        {
            printf("Your guessed it correct \n");
            printf("The number was %d \n", randomNum);
            printf("Do you want to play again? (y/n) \n");
            char playAgain;
            scanf(" %c", &playAgain);
            if (playAgain == 'y')
            {
                randomNum = rand() % 11; 
                // generate new random number
				printf("Welcome to random number guessing game \n");
				printf("Please guess a number between 1 - 10 \n");
				scanf("%d", &userInput);
            }
            else
            {
                isFinished = 1;
                //end the game
            }
        }
	}

	return 0;
}
