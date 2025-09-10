#include <stdio.h>

struct Student {
    int id;
    char name[100];
    float gpa_cse103, gpa_mat101, gpa_eng101;
    float cgpa;
};

// Calculate CGPA
float calculateCGPA(float cse103, float mat101, float eng101) {
    return ((cse103 * 4.5) + (mat101 * 3.0) + (eng101 * 3.0)) / 10.5;
}

int main() {
    FILE *inputFile, *outputFile;
    struct Student students[100];
    int n, i;

    inputFile = fopen("student_input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL) {
        printf("File not Found!\n");
        return 1;
    }

    // Read n number of students
    fscanf(inputFile, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &students[i].id);
        fscanf(inputFile, "%s", students[i].name);
        fscanf(inputFile, "%f", &students[i].gpa_cse103);
        fscanf(inputFile, "%f", &students[i].gpa_mat101);
        fscanf(inputFile, "%f", &students[i].gpa_eng101);

        students[i].cgpa = calculateCGPA(
            students[i].gpa_cse103,
            students[i].gpa_mat101,
            students[i].gpa_eng101
        );
    }
    fclose(inputFile);

    //Output
    fprintf(outputFile, "ID\tName\tCSE103\tMAT101\tENG101\tCGPA\n");
    fprintf(outputFile, "---------------------------------------------\n");

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
                students[i].id, students[i].name,
                students[i].gpa_cse103, students[i].gpa_mat101,
                students[i].gpa_eng101, students[i].cgpa);
    }
    fclose(outputFile);
    return 0;
}
