#include<stdio.h>

//initializes an array that will be used to store the combinations
int combinations[5] = {0};

//initializes an array that stores the possible scoring methods
int scores[] = {8, 7, 6, 3, 2};

//function to recursively print the possibilities for the score given
//targetscore is the number given by the user, scores[] is the array initialized above
//combinations is the array that will be changed upon each recursion, and i is the index
void recursiveFunc(int targetScore, int scores[], int combinations[], int i){

    //target score gets changed over the course of the recursion to be lowered, and if it equals 0 it
    //represents the additions adding up to users original number
    if (targetScore == 0){
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", combinations[0], combinations[1], combinations[2], combinations[3], combinations[4]);
        return;
    }

    //represents a test case where the score addition goes beyond the users target score
    if (targetScore < 0){
        return;
    }

    //for loop which iterates possible combinations over the different score values
    //(this is why it goes til j < 5)
    // and then recursively calls
    for (int j = i; j < 5; j++){
        combinations[j]++;
        recursiveFunc(targetScore - scores[j], scores, combinations, j);
        combinations[j]--;
    }
}

int main(void)
{
    int number = 0;

    //takes an input from the user
    while (number <= 2){
        printf("Enter a football score greater than 2: ");
        scanf("%d", &number);
    }

    //calls the recursive function for the number
    recursiveFunc(number, scores, combinations, 0);

    //when running the program in a command prompt window it would
    //close instantly before I could read anything and so I
    //added this exit so that the window stays open until a key is pressed
    printf("Press enter to exit"); 
    getchar();
    getchar();

    return 0;

}