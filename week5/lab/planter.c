#include <stdio.h>

#define GARDEN_ROWS 5
#define GARDEN_COLS 5
#define TRUE 1
#define FALSE 0

/*
Provided enum flowers
DO NOT MODIFY THIS ENUM
*/
enum flowers {
    EMPTY,
    DAISY,
    ROSE,
    TULIP
};

/*
Provided struct garden
DO NOT MODIFY THIS STRUCT
*/
struct garden {
    enum flowers flower;
    int bloom_countdown;
    int is_gardener;
};

/*
provided function prototypes
DO NOT MODIFY THESE FUNCTION PROTOTYPES
*/
void print_garden(struct garden garden[GARDEN_ROWS][GARDEN_COLS]);
int grow_garden(struct garden garden[GARDEN_ROWS][GARDEN_COLS]);

int main(void) {

    printf("Welcome to the planter!\n");
    // TODO SECOND: IMPLEMENT THE MAIN FUNCTION
    struct garden garden[GARDEN_ROWS][GARDEN_COLS] = {0};
    int i = 0;
    int choice = 0;
    while (i < GARDEN_ROWS) {
        garden[i][0].is_gardener = TRUE;
        print_garden(garden);

        printf(
            "0. Nothing\n"
            "1. Daisy\n"
            "2. Rose\n"
            "3. Tulip\n"
            "Which flower would you like to plant in this row? "
        );
        scanf("%d", &choice);

        grow_garden(garden);

        if (choice != 0) {
            int j = 0;
            while (j < GARDEN_COLS) {
                garden[i][j].flower = choice;
                garden[i][j].bloom_countdown = 3;
                j++;
            }
        }
        garden[i][0].is_gardener = FALSE;
        i++;
    }

    print_garden(garden);
    while (grow_garden(garden)) {
        printf("Waiting for flowers to bloom...\n");
        print_garden(garden);
    }
    return 0;
}

/*
    Decreases the bloom_countdown for all flowers in the garden
    Parameters:
        garden: a 2D array of struct garden
    Returns:
        int: returns 1 if a flower has grown, 0 otherwise
*/
int grow_garden(struct garden garden[GARDEN_ROWS][GARDEN_COLS]) {
    // TODO FIRST: decrease bloom_countdown for all flowers in the garden
    int flower_found = FALSE;
    int i = 0;
    while (i < GARDEN_ROWS) {

        int j = 0;
        while (j < GARDEN_COLS) {
            if (garden[i][j].bloom_countdown > 0) {
                garden[i][j].bloom_countdown -= 1;
                flower_found = TRUE;
            }
            j++;
        }
        i++;
    }
    return flower_found;
}


////////////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT MODIFY ANYTHING BELOW THIS LINE ////////////////////
////////////////////////////////////////////////////////////////////////////////

/*
    Prints the garden to the terminal
    Parameters:
        garden: a 2D array of struct garden
    Returns:
        void
*/
void print_garden(struct garden garden[GARDEN_ROWS][GARDEN_COLS]) {
    printf("\n");
    for (int i = 0; i < GARDEN_ROWS; i++) {
        for (int j = 0; j < GARDEN_COLS; j++) {
            if (garden[i][j].is_gardener) {
                printf("# ");
            } else if (garden[i][j].flower == EMPTY) {
                printf(". ");
            } else if (garden[i][j].bloom_countdown > 0) {
                printf("%d ", garden[i][j].bloom_countdown);
            } else if (garden[i][j].flower == DAISY) {
                printf("D ");
            } else if (garden[i][j].flower == ROSE) {
                printf("R ");
            } else if (garden[i][j].flower == TULIP) {
                printf("T ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
