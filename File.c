#include <stdio.h> // Include the standard I/O library

// Function prototype declaration
void mergeFiles(FILE *sourceFile1, FILE *sourceFile2, FILE *destinationFile);

int main() {
    // Attempt to open the first source file for reading
    FILE *file1 = fopen("source1.txt", "r");
    
    // Attempt to open the second source file for reading
    FILE *file2 = fopen("source2.txt", "r");

    // Check if either of the source files failed to open
    if (!file1 || !file2) {
        // If so, print an error message and exit the program with status code 1
        printf("Error opening source files.\n");
        return 1;
    }

    // Attempt to open the destination file for writing
    FILE *destFile = fopen("destination.txt", "w");
    
    // Check if the destination file failed to open
    if (!destFile) {
        // If so, print an error message, close the source files, and exit the program with status code 1
        printf("Error opening destination file.\n");
        fclose(file1);
        fclose(file2); // Ensure source files are closed even if destination fails to open
        return 1;
    }

    // Call the mergeFiles function to merge the contents of the source files into the destination file
    mergeFiles(file1, file2, destFile);

    // Close the source and destination files after merging
    fclose(file1);
    fclose(file2);
    fclose(destFile);

    // Print a success message indicating the merge operation was successful
    printf("Merge completed successfully.\n");
    return 0; // Indicate successful execution of the program
}

// Function definition
void mergeFiles(FILE *sourceFile1, FILE *sourceFile2, FILE *destinationFile) {
    int ch; // Variable to hold each character read from the source files

    // Read characters from sourceFile1 and write them to destinationFile until EOF (End Of File)
    while ((ch = fgetc(sourceFile1)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Reset the position of sourceFile2 to the beginning of the file
    fseek(sourceFile2, 0, SEEK_SET);

    // Read characters from sourceFile2 and write them to destinationFile until EOF
    while ((ch = fgetc(sourceFile2)) != EOF) {
        fputc(ch, destinationFile);
    }
}