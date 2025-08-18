#include <stdio.h>
#include <string.h>

struct RatedMovies {
    char name[100];
    float rate;
};

void movieSearchFunction() { printf("Movie search function is running\n"); }

void showRatedMoviesAndRating() {
    printf("Rated movies and rating function running\n");
}

void showRatedMovies() {
    FILE *movieDB;
    movieDB = fopen("movieDB.txt", "r");
    if (movieDB == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), movieDB)) {
        char movieName[1000];
        float rate;
        if (sscanf(line, "%[^,], %f", movieName, &rate) == 2) {
            printf("Movie name: %s\tRating: %.1f\n", movieName, rate);
        }
    }
}

void databaseEditingFunction() {
    // Tahmid's part
    printf("1) View rated movies\n");
    printf("2) Rate new movies\n");
    printf("3) Update current list\n");
    printf("\n");

    while (1) {
        int userChoice;
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        printf("\n");

        if (userChoice == 1) {
            showRatedMovies();
            printf("\n");
            break;
        } else if (userChoice == 2) {
            printf("Rate new movies function will activate\n");
            printf("\n");
        } else if (userChoice == 3) {
            printf("Database update function will be activate\n");
            printf("\n");
        }
    }
}

void movieRecommendation() {
    // Mahadi's part
    printf("Movi recommendation function running\n");
}

void statisticsAndSummaryFunction() {
    // Zulfikar's part
    printf("showing statistics and summary\n");
}

int main() {
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

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 1) {
            movieSearchFunction();
        } else if (userChoice == 2) {
            showRatedMoviesAndRating();
        } else if (userChoice == 3) {
            databaseEditingFunction();
            break;
        } else if (userChoice == 4) {
            movieRecommendation();
        } else if (userChoice == 5) {
            statisticsAndSummaryFunction();
        } else {
            printf("Invalid choice\n");
        }
    }
}