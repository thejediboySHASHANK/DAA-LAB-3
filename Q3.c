// Aim of the experiment : Guess Game
// A and B are playing a guessing game where B first thinks up an integer X (positive, negative, or zero, and could be of arbitrarily large magnitude) and A tries to guess it. In Response to A's guess, B gives exactly one of the following three replies : 

// a) Try a bigger number
// b) Try a smaller number or 
// c) You got it

// Write a program by defining an efficient algorithm to minimize the number of guesses A has to make. An example (not necessarily an efficient one) below : 
// Assume B thinks up the number 35.
// A's guess B's response
// 10 Try a bigger number
// 20 Try a bigger number
// 30 Try a bigger number
// 40 Try a smaller number
// 35 You got it


#include <stdio.h>

int main() {
    int n;
    printf ("B, Enter the number you are thinking of : ");
    scanf ("%d", &n);

    int x = -100;
    printf("A, Enter the number : ");

    while (x != n) {
        scanf ("%d", &x);
        
        if (x > n) {
            printf("Try a smaller number : ");
        } else if (x < n) {
            printf ("Enter a bigger number : ");
        } else {
            printf ("You got it!");
            break;
        }
    }
    return 0;
}
