// Hans Caclda
// November 14, 2024
/* Purpose: Displays all the records, asks the user which record they want to edit,
            asks the user what fields to change in that record, and then change only
            those particular fields.  */

// header files
#include <stdio.h>
#include <string.h>
#include "student.h"
#include "stringinput.h"
#include "getdouble.h"

// function prototypes

// function to display all student records from the file
void displayAllRecords(FILE *filePointer);
// function to edit the student record
void editRecord(FILE *filePointer);
// function to print a single student record in the formatted form
void printStudent(const Student *student);

int main()
{

    // open the "students.data" file for reading and writing in binary mode
    FILE *filePointer = fopen("students.data", "rb+");

    // Check if the file could not be opened
    //  just in case the file does not exist or we do not have the right oermission
    if (filePointer == NULL)
    {
        // error message if the file cannot be opened
        printf("Error: Could not open file.\n");
        // non-zero value indicates an error occurred during program execution
        return 1;
    }

    // variable declarition and holds user input for editing
    char continueEditing[MAX_STRING];

    // do-while loop to display and edit records until the user chooses to stop
    do
    {
        // function call to display all records currently in the file
        displayAllRecords(filePointer);
        // function call to allow the user to edit a record
        editRecord(filePointer);

        // prompt the user to decide whether they want to continue editing records.
        printf("\nKeep editing records? Yes(y) or No(n)? ");
        // reads the user input for continuing or stopping the editing loop
        getstring(continueEditing, MAX_STRING);

        // user inputs y or Y the loop continues
    } while (continueEditing[0] == 'y' || continueEditing[0] == 'Y');

    // close the file after all editing and displaying operations are completed
    fclose(filePointer);
    // prompt a confirmation message after the file is successfully closed
    printf("\nFile successfully updated.\n");

    // indicate that the program has finished successfully
    return 0;
}

void displayAllRecords(FILE *filePointer)
{

    // declare student variable to temporarily hold each record as it is read from the file
    Student student;

    // move the file pointer back to the start of the file
    rewind(filePointer);

    // prompt the column headers for the student data
    printf("\nNumber   FirstName    LastName  Age  GPA\n");
    printf("------   ---------    --------  ---  ---\n");

    // while loop that reads each student record from student.data and displays it
    // tries to read one student record at a time from the file
    while (fread(&student, sizeof(Student), 1, filePointer) == 1)
    {
        // checks if the number is valid
        if (student.number != -1)
        {
            // call function to display student.data
            printStudent(&student);
        }
    }
}

void editRecord(FILE *filePointer)
{
    // declare a student variable to hold the record the user wants to edit
    Student student;
    // declare a string variable to store the input for choosing which field to edit
    char input[MAX_STRING];
    // declare an integer variable to store the record number that the user wants to edit
    int recordNum;

    // prompt the user to enter the number of the record they want to edit
    printf("\nEnter the record number to edit: ");
    // reads the record number input from the user
    recordNum = (int)getdouble();

    // checks if the entered record number is negative = invalid
    if (recordNum < 0)
    {
        // display an error message if the record number is invalid
        printf("ERROR: No negative records exist.\n");
        // exit the function early as negative records dont exist
        return;
    }

    // moves the file pointer back to the beginning of the file
    rewind(filePointer);
    // declare a variable to track if the record is found
    int found = 0;
    // declare a variable to keep track of the current record
    int currentRecord = 0;

    // loop through each record in the file, looking for the specified record number
    // => reads each student record one by one from the file
    while (fread(&student, sizeof(Student), 1, filePointer) == 1)
    {

        // if the current record number matches the input = mark the record as found
        if (currentRecord == recordNum)
        {
            found = 1;

            // exits the loop since the record was found
            break;
        }
        // increments the current record number to move on to the next record
        currentRecord++;
    }

    // if the record was not found after reading through the file = prints an error message indicating the record was not found
    if (!found)
    {
        printf("ERROR: Record #%d does not exist.\n", recordNum);

        // exits the function early because it doesnt exist
        return;
    }

    // if the record is found display it so the we can see the current values
    printf("\nEditing record #%d:\n", recordNum);

    // call the function to show the current details of the record to be edited
    printStudent(&student);

    // prompt the user to select which field they want to edit => first name, last name, age, or GPA
    printf("Edit first name (f), last name (l), age (a), or GPA (g): ");

    // get the choice for which field to edit
    getstring(input, MAX_STRING);

    // switch statement to handle the user's choice of which field to edit
    switch (input[0])

    // switch on the first character of the users input
    {
    case 'f':
        printf("Enter first name: ");
        getstring(student.first, MAX_STRING);
        break;

    case 'l':
        printf("Enter last name: ");
        getstring(student.last, MAX_STRING);

    case 'a':
        printf("Enter age: ");
        student.age = (int)getdouble();
        break;

    case 'g':
        printf("Enter GPA: ");
        student.gpa = (float)getdouble();
        break;

    default:
        // error handling if none of the user input matches the switch cases
        printf("ERROR: Invalid choice.\n");
        return;
    }

    // rewind the file to the beginning for the update => pointer to the start of the file
    rewind(filePointer);
    currentRecord = 0;

    // loops through the file to overwrite it with the updated values
    while (fread(&student, sizeof(Student), 1, filePointer) == 1)
    {
        // read each student record again
        if (currentRecord == recordNum)
        {
            // if the current record matches the record number to edit => write the updated student record back to the file
            fseek(filePointer, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, filePointer);

            // prompts a success message confirming the update
            printf("Record #%d updated successfully.\n", recordNum);

            // exit after successful update
            return;
        }
        // increments the current record number to move
        currentRecord++;
    }

    // exit the loop without finding the record => display an error message indicating failure to update
    printf("ERROR: Failed to update record #%d.\n", recordNum);
}

void printStudent(const Student *student)
{
    // format print
    printf("%6d  %10s  %10s  %3d  %3.1f\n",
           student->number, student->first, student->last, student->age, student->gpa);
}
