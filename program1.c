#include <stdio.h>

struct Student{
    float age;
    int id;
    float marks;
}students[100];
typedef struct Student student;
void input(int i)
{
    student s;
    printf("Enter the age of the student : \n");
    scanf("%f",&(s.age));
    printf("Enter student id : \n");
    scanf("%d",&(s.id));
    printf("Enter marks scored by the student : \n");
    scanf("%f",&(s.marks));
    if((s.age>=20)&&(s.marks>=0&&s.marks<=100))
    {
       students[i].age=s.age;
       students[i].id=s.id;
       students[i].marks=s.marks;
       printf("\nstudent succesfully added to the database\n");
        
    }
    else
    { 
        if(s.age<20)
        printf("\nAge of the student should be more than 20\nPlease Re-enter\n");
        else
        {
            printf("\nMarks should be between 0-100\nPlease Re-enter\n");
        }
        input(i);
    }
}
void display(int i)
{
    for(int j=0;j<i;j++)
    {
        printf("\nStudent #%d\nid : %d\nage : %f\nmarks : %f\n",j,students[j].id,students[j].age,students[j].marks);
        if(students[j].marks>65)
        {
            printf("Eligible for admission\n");
        }
        else 
        {
            printf("Not eligible for admission\n");    
        }
    }
}
int main()
{
    int ch,i=0;
    while(1)
    {
        printf("\n1.Input\n2.Display\n3.Exit\nEnter your choice  : \n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1 : input(i);
           i++;
           break;
           case 2 : display(i);
           break;
           case 3 : return 0;
           default : printf("\nInvalid Entry\n");
        }
    }
    return 0;
}
