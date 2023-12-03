// Structures

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    int roll;
    int marks;
    int sem;
};

void create_student(struct student *s, char sn[0], int r, int m, int se)
{
    int l = strlen(sn);
    int a = 0;
    while (a < l)
    {
        s->name[a] = sn[a];
        a++;
    }
    s->roll = r;
    s->marks = m;
    s->sem = se;
}

int main()
{
    struct student s[10];
    int x = 0;
    create_student(&s[x], "one", 1, 40, 1);
    x++;

    while (1)
    {
        printf("MENU:\n1. Enter Student Detail\n2. Display all records\n3. Search Student by Roll\n4. Search Student by name\n5. Display Topper Student Detail\n6. Exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter info in this format:\nName Roll_No Marks Semester\n");
            scanf("%s %d %d %d", &s[x].name, &s[x].roll, &s[x].marks, &s[x].sem);
            x++;
            break;
        }
        case 2:
        {
            int count = 0;
            printf("Name\tRoll_No\tMarks\tSem\n");
            while (count < x)
            {
                printf("%s\t%d\t%d\t%d\n", s[count].name, s[count].roll, s[count].marks, s[count].sem);
                count++;
            }
            break;
        }
        case 3:
        {
            printf("Enter the Students Roll No.: ");
            int r;
            scanf("%d", &r);
            int c = 0;
            while (c < x)
            {
                // printf("Run %d", c);
                if (s[c].roll == r)
                {
                    printf("Students Detail: %s\t%d\t%d\t%d\n", s[c].name, s[c].roll, s[c].marks, s[c].sem);
                    break;
                }
                c++;
            }
            if (c >= x)
                printf("Student with Roll %d not found.\n", r);
            break;
        }
        case 4:
        {
            printf("Enter the Students Name: ");
            char nm[20];
            scanf("%s", &nm);
            int c = 0;
            while (c < x)
            {
                if (strcmp(nm, s[c].name) == 0)
                {
                    printf("Students Detail: %s\t%d\t%d\t%d\n", s[c].name, s[c].roll, s[c].marks, s[c].sem);
                    break;
                }
                c++;
            }
            if (c >= x)
                printf("Student with Name %s not found.\n", nm);
            break;
        }
        case 5:
        {
            int c = 0;
            int m = 0;
            int store;
            while (c < x)
            {
                if (m < s[c].marks)
                {
                    m = s[c].marks;
                    store = c;
                }
                c++;
            }
            printf("Students Detail: %s\t%d\t%d\t%d\n", s[store].name, s[store].roll, s[store].marks, s[store].sem);
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        default:
        {
            printf("Wrong Input");
            break;
        }
        }
    }
}