#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 1000

struct Movie {
    char title[100];
    char genre[50];
    int year;
    float totalRating;
    int numRatings;
};

struct Movie movies[MAX_MOVIES];
int movieCount = 0;

// Helper: lowercase compare
int strCaseCmp(const char *a, const char *b) {
    while (*a && *b) {
        char c1 = tolower((unsigned char)*a);
        char c2 = tolower((unsigned char)*b);
        if (c1 != c2) return c1 - c2;
        a++;
        b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

// 1. Highest rated movie of a year
void highestRatedByYear(int year) {
    float maxRating = -1;
    int index = -1;

    for (int i = 0; i < movieCount; i++) {
        if (movies[i].year == year && movies[i].numRatings > 0) {
            float avg = movies[i].totalRating / movies[i].numRatings;
            if (avg > maxRating) {
                maxRating = avg;
                index = i;
            }
        }
    }

    if (index != -1)
        printf("\nHighest rated movie of %d: %s (%.2f)\n", year, movies[index].title, maxRating);
    else
        printf("\nNo movies found for that year.\n");
}

// 2. Highest rated movie by genre
void highestRatedByGenre(char *genre) {
    float maxRating = -1;
    int index = -1;

    for (int i = 0; i < movieCount; i++) {
        if (strCaseCmp(movies[i].genre, genre) == 0 && movies[i].numRatings > 0) {
            float avg = movies[i].totalRating / movies[i].numRatings;
            if (avg > maxRating) {
                maxRating = avg;
                index = i;
            }
        }
    }

    if (index != -1)
        printf("\nHighest rated %s movie: %s (%.2f)\n", genre, movies[index].title, maxRating);
    else
        printf("\nNo movies found for genre '%s'.\n", genre);
}

// 3. Favourite movies (top 10 by rating)
void favouriteMovies() {
    int idx[MAX_MOVIES];
    for (int i = 0; i < movieCount; i++) idx[i] = i;

    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = i + 1; j < movieCount; j++) {
            float avgI = (movies[idx[i]].numRatings > 0) ? 
                         movies[idx[i]].totalRating / movies[idx[i]].numRatings : 0;
            float avgJ = (movies[idx[j]].numRatings > 0) ? 
                         movies[idx[j]].totalRating / movies[idx[j]].numRatings : 0;

            if (avgJ > avgI) {
                int temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
    }

    printf("\nYour Favourite Movies (Top 10 by rating):\n");
    int shown = 0;
    for (int i = 0; i < movieCount && shown < 10; i++) {
        if (movies[idx[i]].numRatings > 0) {
            float avg = movies[idx[i]].totalRating / movies[idx[i]].numRatings;
            printf("%d. %s (%.2f)\n", shown + 1, movies[idx[i]].title, avg);
            shown++;
        }
    }

    if (shown == 0) {
        printf("No movies have been rated yet.\n");
    }
}

// Statistics Summary Menu
void statisticsMenu() {
    int choice;
    do {
        printf("\n===== Statistics Summary =====\n");
        printf("1. Highest rated movie of a year\n");
        printf("2. Highest rated movie by genre\n");
        printf("3. Your favourite movies (Top 10)\n");
        printf("4. Back to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        if (choice == 1) {
            int year;
            printf("Enter year: ");
            scanf("%d", &year);
            highestRatedByYear(year);
        } 
        else if (choice == 2) {
            char genre[50];
            printf("Enter genre: ");
            fgets(genre, sizeof(genre), stdin);
            genre[strcspn(genre, "\n")] = 0;
            highestRatedByGenre(genre);
        } 
        else if (choice == 3) {
            favouriteMovies();
        } 
        else if (choice != 4) {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);
}

// Sample data for testing
void loadSampleMovies() {
    strcpy(movies[0].title, "Inception");
    strcpy(movies[0].genre, "Sci-Fi");
    movies[0].year = 2010;
    movies[0].totalRating = 45;
    movies[0].numRatings = 5;

    strcpy(movies[1].title, "The Dark Knight");
    strcpy(movies[1].genre, "Action");
    movies[1].year = 2008;
    movies[1].totalRating = 48;
    movies[1].numRatings = 5;

    strcpy(movies[2].title, "Interstellar");
    strcpy(movies[2].genre, "Sci-Fi");
    movies[2].year = 2014;
    movies[2].totalRating = 50;
    movies[2].numRatings = 5;

    movieCount = 3;
}

int main() {
    loadSampleMovies(); // sample data for demo
    statisticsMenu();   // run Zulfiqar's part
    return 0;
}
