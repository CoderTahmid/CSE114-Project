#include <stdio.h>

void movieSearchFunction()
{
    printf("Movie search function is running\n");
}

void showRatedMoviesAndRating()
{
    printf("Rated movies and rating function running\n");
}

void databaseEditingFunction()
{
    printf("Database editing function is running\n");
}

void movieRecommendation()
{
    printf("Movi recommendation function running\n");
}

void statisticsAndSummaryFunction()
{
    printf("showing statistics and summary\n");
}

int main()
{
    int userChoice;

    printf("==================================================================================\n");
    printf("                   Welcome to movie rating and recommendation system\n");
    printf("==================================================================================\n");
    printf("1) Search for movies\n");
    printf("2) Show rated movies and rating\n");
    printf("3) Edit you database\n");
    printf("4) Movie recommendation\n");
    printf("5) Movie statistics summary\n");
    printf("\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1)
        {
            movieSearchFunction();
        }
        else if (userChoice == 2)
        {
            showRatedMoviesAndRating();
        }
        else if (userChoice == 3)
        {
            databaseEditingFunction();
        }
        else if (userChoice == 4)
        {
            movieRecommendation();
        }
        else if (userChoice == 5)
        {
            statisticsAndSummaryFunction();
        } else {
            printf("Invalid choice\n");

        }
    }
}