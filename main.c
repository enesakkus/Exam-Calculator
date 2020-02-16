#include<stdio.h>

void printArray(size_t student, size_t exams, const int studentGrades[][exams]);
int minimum(size_t student, size_t exams, const int studentGrades[][exams]);
int maximum(size_t student, size_t exams, const int studentGrades[][exams]);
double average(size_t exams, const int studentGrades[][exams], size_t i);

int main(void){

    size_t student, exams;


    printf("Welcome to multidimensional array manipulation program...\n"
           "\nThis program takes several quantities from user.\n"
           "Firstly user should enter the number of student and then the number of\n"
           "exams that taken by each student. Then the program prints grade values of\n"
           "each student, maximum and minimum grade values and average grade values of\n"
           "each student...\n");

    //taking student and exam count from user
    printf("Please enter the number of students:");
    scanf("%u", &student);
    printf("Please enter the number of examination that taken by each student:");
    scanf("%u", &exams);

    int studentGrades[student][exams];
    size_t i, j;

    //Taking exam grades from user
    for(i = 0; i < student; i++){
        for(j = 0; j < exams; j++){
            printf("Please enter the grade value of exam %u of student %u:", j+1, i+1);
            scanf("%d", &studentGrades[i][j]);
        }//end inner for
    }//end outer for

    printArray(student, exams, studentGrades);

    //Printing lowest and highest grade
    printf("\nLowest grade: %d\nHighest grade: %d",
           minimum(student, exams, studentGrades), maximum(student, exams, studentGrades));

    //Printing average grade of each student
    for(i = 0; i < student; i++){
        printf("\nAverage grade for student %u is %.3f", i, average(exams, studentGrades, i));
    }//end for



}

// determine minimum grade
int minimum(size_t student, size_t exams, const int studentGrades[][exams]){

    int lowerGrade = 100;
    size_t i, j;

    //algorithm for determine lower grade
    for(i = 0; i < student; i++){
        for(j = 0; j < exams; j++){
            if(studentGrades[i][j] < lowerGrade){
                lowerGrade = studentGrades[i][j];
            } //end if
        } //end inner for
    } //end outer for
    return lowerGrade;
} //end function minimum

//Determine maximum grade
int maximum(size_t student, size_t exams, const int studentGrades[][exams]){

    int higherGrade = 0;
    size_t i, j;

    //algorithm for determine higher grade
    for(i = 0; i < student; i++){
        for(j = 0; j < exams; j++){
            if(studentGrades[i][j] > higherGrade){
                higherGrade = studentGrades[i][j];
            } //end for
        } //end inner for
    } //end outer for
    return higherGrade;
} //end function maximum

//Determine average grade
double average(size_t exams, const int studentGrades[][exams], size_t i){

    double total = 0;
    size_t j;

    // sum of grades of all students
    for(j = 0; j < exams; j++){
        total += studentGrades[i][j];
    } //end for
    return (double) total / exams; //return average type of double
} //end function average

//Print array
void printArray(size_t student, size_t exams, const int studentGrades[][exams]){

    size_t i, j;


    puts("The array is:\n");
    printf("\t\t\t");
    //Header for exam numbers
    for(i = 0; i < exams; i++){
        printf("[%d]      ",i);

    } //end for
    puts("");

    //Print student grades as matrix format
    for(i = 0; i < student; i++){
        printf("studentGrades[%u] ", i);
        for(j = 0; j < exams; j++){
            printf("%9d", studentGrades[i][j]);
        } //end inner for
        puts("");
    } //end outer for
} //end function printArray


