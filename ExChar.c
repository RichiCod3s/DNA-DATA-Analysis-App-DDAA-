#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Functions
int display_menu();
void load_raw_dna_data();
void display_raw_dna_data(struct dna* structArr);
void count_chromosome_records();
int sort_chromsome_data();
void create_chromosome_file(int chromoRequest);
void display_chromosome_data();
void search_rsid();
void compare_control();
void exit_DDAA();

// Globals
int dnaCount = 0; // counter for DNA array
sortCount = 0; // counter for sorted array
struct dna* structArr; // DNA struct array
struct dna* chromosome_data; // Sorted data struct array 
int functionTwoRan = 0;
int functionSixRan = 0; // error handling for function 7

// CREATE STRUCT FOR DNA
typedef struct dna {
    char rsid[50];
    int chromosome;
    long int position;
    char allele1;
    char allele2;
}DNA;

// function main begins program execution
int main(void)
{

    int choice; // switch statement
    int result = 0; // for passing chromoRequest to function 7


     // Function 1 - Display Menu
    while ((choice = display_menu()) != 9)
    {
        switch (choice)
        {
            //Load in data from file to a dynamic array
        case 1:
            load_raw_dna_data();
            break;
            // Displays the raw data - 40 record at a time
        case 2:
            display_raw_dna_data(structArr);
            break;
            // Counts the number of records that have a chromosome value input by user  
        case 3:
            count_chromosome_records();
            break;
            // Displays DNA records that contain a cetain chromosome number input by user by 
        case 4:
            display_chromosome_data();
            break;
            // Sorts records with a certain chromsome value by higgest value of position.
        case 5:
        {
            result = sort_chromsome_data();
            break;
            // Create a file that outputs the data of the selected chromosome in function 6
        }
        case 6:
        {
            create_chromosome_file(result);
            break;
            // Searches if a record with an inputed rsid is in the database
        }
        case 7:
            search_rsid();
            break;
            // Compares three combinations of rsid, allelle 1 & allelle2
        case 8:
            compare_control();
            break;
            // Exits the program
        case 9:
            exit_DDAA();
            break;
            // Displays a message if user enters the wrong choice
        default:
            printf("Incorrect choice, please try again\n");
            break;
        }
    }
}// end of main

//Function 1
// Displays the menu and stores the menu choice
int display_menu()
{
    int menuChoice; // variable used to store users choice

    // display menu options
    printf("************************************\n");
    printf("%15s", " DNA Data Analysis App (DDAA)\n"); // edit title later
    printf("************************************\n");
    printf("\n");

    printf("Select one of the following options:\n");
    printf("\n");
    printf("1. Load RAW DNA data\n");
    printf("2. Display RAW Data\n");
    printf("3. Count Chromosome Records\n");
    printf("4. Display Chromosome Data\n");
    printf("5. Sort Chromosome Data\n"); // edit title later
    printf("6. Create Chromosome Datafile\n");
    printf("7. Search for DNA at Position\n");
    printf("8. Compare Control\n");
    printf("9. Exit System\n");

    scanf("%i", &menuChoice); // example had an "&" pg 493  may be important!

    return (menuChoice);

    return 0;
}

// Function 2
// load in data from file to a dynamic array
//counts lines/ records of the file for the array
void load_raw_dna_data()
{
    char line[100]; // variable the line is stored in

    FILE* fp;
    char rsid[100];
    int chromosome;
    long int position;
    char allele1, allele2;
  
    printf("\n\n");
    printf("Opening file...");
    fp = fopen("dna_data.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist. Please try again.\n");
        exit(1);
    }
    else
    {
        printf("File opened.\nData Loaded\n");
    }

    //Count lines in file
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        dnaCount++;
    }

    rewind(fp);

    structArr = malloc(sizeof(DNA) * dnaCount);

    for (int i = 0; i < dnaCount; i++) {
        fscanf(fp, "%s %d %ld %c %c", rsid, &chromosome, &position, &allele1, &allele2);

        strcpy(structArr[i].rsid, rsid);
        structArr[i].position = position;
        structArr[i].chromosome = chromosome;
        structArr[i].allele1 = allele1;
        structArr[i].allele2 = allele2;
    }

    fclose(fp); // closes file
    printf("\n------------------------------------\n");
    printf("Number of records uploaded: %d\n", dnaCount); // Displays number of records
    printf("------------------------------------\n");
    printf("\n\n");

    functionTwoRan = 1;
    return 0;

}
//Function 3
// Displays the raw data - 40 record at a time
void display_raw_dna_data(struct dna* structArr)
{
    if (functionTwoRan == 1) {
        int i, start = 0;
        char userInput;

        printf("---------------------------------------------------------------------------------------------------------------\n");
        printf("%s\t %s\t %s\t %s\t %s\n", "CUSTOMER", "DNA Position", "Chromosome No.", "Genomic Location", "Customer's Genotype");
        printf("---------------------------------------------------------------------------------------------------------------\n");

        while (start < dnaCount) {
            // Display 40 records
            for (i = start; i < start + 40 && i < dnaCount; i++) {
                printf("%5d:\t %20s\t %8d\t %10ld\t %16c%c\n", i + 1, structArr[i].rsid, structArr[i].chromosome, structArr[i].position, structArr[i].allele1, structArr[i].allele2);
            }
            printf("\n");

            // Prompt user for input
            printf("Enter 'n' for next 40 records or 'q' to quit: ");
            scanf_s(" %c", &userInput);
            if (userInput == 'q') {
                break;
            }

            // Update start index for next iteration
            start += 40;
        }
        printf("\n");
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }

    return 0;
}

//Function 4
//Counts the number of records that have a chromosome value input by user  
void count_chromosome_records() {
    if (functionTwoRan == 1) {
        int chromoRequest = 0; // request from user
        int chromoCount = 0; // count chromosomes

        printf("Please enter chromosome number from 1 to 6:\n");
        do {
            scanf_s("%d", &chromoRequest);
            if (chromoRequest < 1 || chromoRequest >6) {
                printf("Try again, please enter a number from 1-6:\n");
            }
        } while (chromoRequest < 1 || chromoRequest >6);


        for (int i = 0; i < dnaCount; i++) {
            if (structArr[i].chromosome == chromoRequest) {
                chromoCount++;
            }
        }//for end
        printf("\n");
        printf("-------------------------------------------------------------\n");
        printf("The number of chromosomes with number %d is:\ %d\n", chromoRequest, chromoCount);
        printf("-------------------------------------------------------------\n");
        printf("\n");
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }

}

//Function 5
//Displays DNA records that contain a cetain chromosome number input by user by 
void display_chromosome_data() {

    if (functionTwoRan == 1) {
        int chromoRequest = 0; // request from user
        int chromoCount = 0; // count chromosomes


        // get chromo number user wants
        printf("Please enter chromosome number from 1 to 6:  ");
        do {
            scanf_s("%d", &chromoRequest);
            if (chromoRequest < 1 || chromoRequest >6) {
                printf("Try again, please enter a number from 1-6:\n");
            }
        } while (chromoRequest < 1 || chromoRequest >6);

        // Print header 
        printf("---------------------------------------------------------------------------------------------------------------\n");
        printf("%s\t %s\t %s\t %s\t %s\n", "CUSTOMER", "DNA Position", "Chromosome No.", "Genomic Location", "Customer's Genotype");
        printf("---------------------------------------------------------------------------------------------------------------\n");

        // Print requested records by chromosome type
        for (int i = 0; i < dnaCount; i++) {
            if (structArr[i].chromosome == chromoRequest) {
                //printf("");
                printf("%5d:\t %20s\t %8d\t %10ld\t %16c%c\n", i + 1, structArr[i].rsid, structArr[i].chromosome, structArr[i].position, structArr[i].allele1, structArr[i].allele2);
            }
        }
        printf("\n");
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }
    return 0;
}

//Function 6
/* Sorts records with a certain chromsome value by higgest value of position.
It also creates an array that contains the new sorted values */
int sort_chromsome_data()
{
    if (functionTwoRan == 1) {
        int chromoRequest = 0; // request from user
        int chromoCount = 0; // count chromosomes
        size_t j; // unsigend int
        int pass; // pass counter
        struct dna* hold = malloc(sizeof(DNA) * dnaCount);
        struct dna* copyArr = malloc(sizeof(DNA) * dnaCount);// new dna struct to hold data

        // get chromo number user wants
        printf("Please enter chromosome number from 1 to 6:  ");
        do {
            scanf_s("%d", &chromoRequest);
            if (chromoRequest < 1 || chromoRequest >6) {
                printf("Try again, please enter a number from 1-6:\n");
            }
        } while (chromoRequest < 1 || chromoRequest >6);


        // Make a copy of the original array of transactions to perform the sorting function 
        for (int i = 0; i < dnaCount; i++) {

            strcpy(copyArr[i].rsid, structArr[i].rsid);
            copyArr[i].position = structArr[i].position;
            copyArr[i].chromosome = structArr[i].chromosome;
            copyArr[i].allele1 = structArr[i].allele1;
            copyArr[i].allele2 = structArr[i].allele2;

        }

        //sort the chromosome data - the sorted records should be stored in an array named “chromosome_data”
        // loop to control number of passes
        for (pass = 1; pass < dnaCount; ++pass) {

            // loop to control number of comparisons per pass
            for (j = 0; j < dnaCount - 1; ++j) {
                // swap if element is greater
                if (copyArr[j].position < copyArr[j + 1].position) {
                    hold[j] = copyArr[j];
                    copyArr[j] = copyArr[j + 1];
                    copyArr[j + 1] = hold[j];
                }// end if
            }// end inner for
        }// end outer for


      
        sortCount = 0;

        for (int i = 0; i < dnaCount; i++) {
            if (copyArr[i].chromosome == chromoRequest) {

                sortCount++; // increment new array counter
            }
        }

        chromosome_data = malloc(sizeof(DNA) * sortCount); // copy data into array
        sortCount = 0;
        // copy over sorted data to new array
        for (int i = 0; i < dnaCount; i++) {
            if (copyArr[i].chromosome == chromoRequest) {
                //printf("");
                strcpy(chromosome_data[sortCount].rsid, copyArr[i].rsid);
                chromosome_data[sortCount].position = copyArr[i].position;;
                chromosome_data[sortCount].chromosome = copyArr[i].chromosome;
                chromosome_data[sortCount].allele1 = copyArr[i].allele1;
                chromosome_data[sortCount].allele2 = copyArr[i].allele2;

                sortCount++; // increment new array counter
            }
            printf("\n");

        }


        // Print out data by geo location i.e struct.position
        printf("---------------------------------------------------------------------------------------------------------------\n");
        printf("%s\t %s\t %s\t %s\n", "DNA Position", "Chromosome No.", "Genomic Location", "Customer's Genotype");
        printf("---------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < sortCount; i++) {

            //printf("");
            printf("%s\t %8d\t %10ld\t %16c%c\n", chromosome_data[i].rsid, chromosome_data[i].chromosome, chromosome_data[i].position, chromosome_data[i].allele1, chromosome_data[i].allele2);

        }

        functionSixRan = 1; // make sure it ran before function 7

        return chromoRequest;// tried making int a return type and returning chromRequest did not work - more globals
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }
}

//Funtion 7
//Create a file that outputs the data of the selected chromosome in function 6
void create_chromosome_file(int chromoRequest)// issue
{
    if (functionTwoRan == 1) {

        if (functionSixRan == 1) // error handling to ensure function 6 was run
        {
            FILE* outFilePtr;
            char fileName[50];
            // get filename by concatinating 
            sprintf(fileName, "chromosome%d_position_data.txt", chromoRequest);


            // Print Chromsomes to file
            if ((outFilePtr = fopen(fileName, "w")) == NULL) {
                printf("File could not be opened\n");
            } /* end if */

            else {
                fprintf(outFilePtr, "---------------------------------------------------------------------------------------------------\n");
                fprintf(outFilePtr, "%s\t %s\t %s\t %s\n", "DNA Position", "Chromosome No.", "Genomic Location", "Customer's Genotype");
                fprintf(outFilePtr, "--------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < sortCount; i++) {
                  
                        // fprintf prints to file
                        fprintf(outFilePtr, " %s\t %8d\t %10ld\t %16c%c", chromosome_data[i].rsid, chromosome_data[i].chromosome, chromosome_data[i].position, chromosome_data[i].allele1, chromosome_data[i].allele2);
                        fprintf(outFilePtr, "\n");  
                }
                printf("\n\n*** File has been stored in: %s ***\n\n", fileName);// message to user
                fclose(outFilePtr); /* fclose closes file */
            } /* end else */
        }
        else {// end of error handling
            printf("Please sort chromosome data first!\n");
            return 1;
        }

        
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }

    return 0;

}// end function

// Function 8
//Searches if a record with an inputed rsid is in the database
void search_rsid() {
    if (functionTwoRan == 1) {
        char rsidRequest[100] = ""; // request from user


        // get chromo number user wants
        printf("Please enter a rsid value:  ");

        scanf("%s", &rsidRequest);


        // Print requested records by rsid number
        for (int i = 0; i < dnaCount; i++) {
            if (strcmp(rsidRequest, structArr[i].rsid) == 0) {
                printf("Matched option found: %s\n", structArr[i].rsid);
                printf("\n");
                printf("--------------------------------------------------------\n");
                printf("%s\t %s\t %s\n", "CUSTOMER", "DNA Position", "Customer's Genotype");
                printf("--------------------------------------------------------\n");

                printf("%5d:\t %16s %16c%c\n", i + 1, structArr[i].rsid, structArr[i].allele1, structArr[i].allele2);
                printf("\n");
                return 0;
            }
        }


        printf("\n***DNA Position %s does not exist in database*** \n", rsidRequest);
        printf("\n");
    }
    else {
        printf("No data loaded\nPlease load in data\n");
    }

    return 0;

}
//Function 9
// Compares three combinations of rsid, allelle 1 & allelle2
//if they are a match it prints to screen 
void compare_control()
{
    if (functionTwoRan == 1) {
        int compareCount = 0; // if = 3 then all match
        int chromosomeNumber = 0; // gets the assumed chromosome number from first struct 

        // request from user
        char alleRequest1 = "", alleRequest2 = "", alleRequest3 = "", alleRequest4 = "", alleRequest5 = "", alleRequest6 = "";
        char rsidRequest1[100], rsidRequest2[100], rsidRequest3[100];

        printf("Please enter your first rsid value and alle1 and alle 2 combinations :  ");
        scanf("%s %c %c", &rsidRequest1, &alleRequest1, &alleRequest2);
        printf("Please enter your second rsid value and alle1 and alle 2 combinations :  ");
        scanf("%s %c %c", &rsidRequest2, &alleRequest3, &alleRequest4);
        printf("Please enter your third rsid value and alle1 and alle 2 combinations :  ");
        scanf("%s %c %c", &rsidRequest3, &alleRequest5, &alleRequest6);
        printf("\n");
        for (int i = 0; i < dnaCount; i++) {
            if (strcmp(rsidRequest1, structArr[i].rsid) == 0 && alleRequest1 == structArr[i].allele1 && alleRequest2 == structArr[i].allele2) {
                printf("Matched option: %s %c %c\n", structArr[i].rsid, structArr[i].allele1, structArr[i].allele2);

                chromosomeNumber = i; // get the assumed chromosome number
                compareCount++;
            }// end if
        }//end for


        for (int i = 0; i < dnaCount; i++) {
            if (strcmp(rsidRequest2, structArr[i].rsid) == 0 && alleRequest3 == structArr[i].allele1 && alleRequest4 == structArr[i].allele2) {

                printf("Matched option: %s %c %c\n", structArr[i].rsid, structArr[i].allele1, structArr[i].allele2);
                compareCount++;
            }//end if
        }// end for

        for (int i = 0; i < dnaCount; i++) {
            if (strcmp(rsidRequest3, structArr[i].rsid) == 0 && alleRequest5 == structArr[i].allele1 && alleRequest6 == structArr[i].allele2) {

                printf("Matched option: %s %c %c\n", structArr[i].rsid, structArr[i].allele1, structArr[i].allele2);
                compareCount++;
            }// end if 
        }// end for

        // if all match print to screen
        if (compareCount == 3) {
            printf("\n");
            printf("Congratulations! found %c%c%c%c%c%c on Chromosome %d\n", alleRequest1, alleRequest2, alleRequest3, alleRequest4, alleRequest5, alleRequest6, structArr[chromosomeNumber].chromosome);
            printf("\n");
        }
    }
    else {
        printf("No data loaded\nPlease load in data\n");
        printf("\n");
    }

    return 0;
}
//Function 10
// Exits the program
void exit_DDAA()
{
    exit(0);
    // all files are closed within the functions
    // sorted data is saved if option to create file is selected (Function 7)
}







