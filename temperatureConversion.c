#include<stdio.h>
#include<string.h>

//Converts fahrenheit to celcius
float convertToCelcius(float num){
    float result = ((5.0/9.0)*(num-32));
    return result;
}

//Converts celcius to fahrenheit
float convertToFahrenheit(float num){
    float result = ((9.0/5.0)*num + 32);
    return result;
}

//when given a temperature and type, it categorizes the weather and gives a recommendation
void categorizeWeather(float num, char target[20]){
    if (strcmp(target, "C") != 0){

        if (strcmp(target, "K") == 0){
            num = (num - 273.15);
        }
        
        else if (strcmp(target, "F") == 0){
            num = convertToCelcius(num);
        }
    }

    if ((num >= 0) && (num <= 10)){
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a coat\n");
    }

    else if ((num < 0)){
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Stay indoors\n");
    }

    else if ((num >= 10) && (num <= 25)){
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: You should feel comfortable\n");
    }

    else if ((num >= 25) && (num <= 35)){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Wear a t-shirt\n");
    }

    else if (num > 35){
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors\n");
    }
}

int main(void)
{
    //declares the variables
    int validInput = 0;
    float userInput;
    char scale[20];
    char target[20];

    //While loop which will continue til all valid inputs have been given
    while (validInput == 0) {

        //While loop which checks for a valid temperature input
        while (1) {
            printf("Enter a temperature value: ");
            if (scanf("%f", &userInput) != 1) {
                printf("Enter a valid number\n");
                while (getchar() != '\n'); //This is apparently called clearing the buffer. I couldn't figure out why my loops didn't work and the internet told me to do this. I guess its some C thing I don't understand.
                continue;
            }
            break;
        }

        //While loop which checks for a valid scale input
        while (1) {
            printf("Enter a temperature scale of your value (enter F, C, or K): ");
            scanf("%s", scale);
            if (strcmp(scale, "F") == 0 || strcmp(scale, "C") == 0 || strcmp(scale, "K") == 0) {
                break;
            }
            while (getchar() != '\n'); 
            printf("Please enter a valid scale\n"); 
        }

        //While loop which checks for a valid conversion target
        while (1) {
            printf("Enter the conversion target (enter F, C, or K): ");
            scanf("%s", target);
            if (strcmp(target, "F") == 0 || strcmp(target, "C") == 0 || strcmp(target, "K") == 0) {
                break;
            }
            while (getchar() != '\n');
            printf("Invalid target. Please enter F, C, or K.\n");
        }

        //Checks if the kelvin value is negative
        if (strcmp(scale, "K") == 0) {
            if (userInput < 0) {
                printf("Kelvin cannot be negative. Please enter a valid temperature value.\n");
                continue;
            }
        }
        
        //Exits the loop if everything is valid
        validInput = 1;
    }
    

    //Converts Fahrenheit to Celcius
    if ((strcmp(scale, "F") == 0) && (strcmp(target, "C") == 0)){
        float result = convertToCelcius(userInput);
        printf("Converted temperature: %f degrees Celcius\n", result);
    }

    //Converts Fahrenheit to Kelvin
    else if ((strcmp(scale, "F") == 0) && (strcmp(target, "K") == 0)){
        float result = (convertToCelcius(userInput) + 273.15);
        printf("Converted temperature: %f degrees Kelvin\n", result);
    }

    //Converts Celcius to Fahrenheit
    else if ((strcmp(scale, "C") == 0) && (strcmp(target, "F") == 0)){
        float result = convertToFahrenheit(userInput);
        printf("Converted temperature: %f degrees Fahrenheight\n", result);
    }

    //Converts Celcius to Kelvin
    else if ((strcmp(scale, "C") == 0) && (strcmp(target, "K") == 0)){
        float result = (userInput + 273.15);
        printf("Converted temperature: %f degrees Kelvin\n", result);
    }

    //Converts Kelvin to Celcius
    else if ((strcmp(scale, "K") == 0) && (strcmp(target, "C") == 0)){
        float result = (userInput - 273.15);
        printf("Converted temperature: %f degrees Celcius\n", result);
    }

    //Converts Kelvin to Fahrenheit
    else if ((strcmp(scale, "K") == 0) && (strcmp(target, "F") == 0)){
        float result = convertToFahrenheit(userInput-273.15);
        printf("Converted temperature: %f degrees Fahrenheight\n", result);
    }

    categorizeWeather(userInput, scale);

    //when running the program in a command prompt window it would
    //close instantly before I could read anything and so I
    //added this exit so that the window stays open until a key is pressed
    printf("Press enter to exit"); 
    getchar();
    getchar();
}