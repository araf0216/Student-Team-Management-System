// Araf Ahmed - this program assigns and displays students belonging to each of three teams based on given student performance by determining smallest difference in student points and team points level

#include <stdio.h>
#include <stdlib.h>

// function that assigns teams to students and stores assignment in array using pointer arithmetic only
void assign(int *points, int *team_assignment, int n)
{   
    int *p;
    int *q;
    
    // iterating through array using pointers by storing and incrementing the addresses of array elements
    for (p = points, q = team_assignment; p < points + n; p++, q++) {
        // setting distances from student points to team points
        int begin_dist = abs(25 - *p);
        int honor_dist = abs(70 - *p);
        int excel_dist = abs(125 - *p);
        
        // determining team with points at shortest distance from student points and assigning team to corresponding student
        if (begin_dist < honor_dist && begin_dist < excel_dist) {
            *q = 0;
        }
        else if (honor_dist < excel_dist) {
            *q = 1;
        }
        else {
            *q = 2;
        }
    }
    
}

int main()
{
    
    // gathering the number of students
    printf("Enter number of students: ");
    int n;
    scanf("%d", &n);
    
    // initializing team_assignment and points array
    int points[n];
    int team_assignment[n];
    
    // gathering number of points of individual students and storing in points array
    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
    }
    
    // calling function that assigns teams to students
    assign(points, team_assignment, n);
    
    // loop for displaying students belonging to teams
    for (int j = 0; j < 3; j++) {
        // printing name for each team
        switch (j) {
            case 0:
                printf("Beginner team:");
                break;
            
            case 1:
                printf("\nHonor team:");
                break;
                
            case 2:
                printf ("\nExcellence team:");
                break;
        }
        
        printf(" student ");
        
        // nested loop iterating through team_assignment array for each team, identifying and displaying students belonging to corresponding team
        for (int i = 0; i < n; i++) {
            if (team_assignment[i] == j) {
                printf("%d ", i + 1);
            }
        }
    }

    return 0;
}

