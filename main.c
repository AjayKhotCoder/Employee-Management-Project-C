#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lp1 = 1;
int n = 0, i = 0, empid = 0, ch = 0, a;
int choice = 0;
double newSalary;
char newName[20];

struct Employee
{
    int emplid;
    char name[20];
    double salary;
} e[100];

int main()
{

    printf("\n***** Welcome to Khot Employee Management System *****\n");

    while (lp1)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addempData();
                break;
            case 2:
                show();
                break;
            case 3:
                update();
                break;
            case 4:
                search();
                break;

            case 0:
                lp1 = 0; // stop looping
                printf("\nThank you for your business! We look forward to working with you again.\n\n");
                break;
            default:
                break;
        }
    }


}


void menu()
{
    int choice = 0;
    printf("\n ::: MENU :::\n");
    printf("\n----------------------------------------\n");
    printf("1. | Add Employee Data     \t \n");
    printf("2. | Show All Employee Data  \t \n");
    printf("3. | Update Employee Data  \t \n");
    printf("4. | Search Employee  Data  \t \n");
    printf("0. | Exit\n");

    printf("\nEnter your choice : ");
}
void addempData()
{
    printf("Enter the number of Employee : ");
    scanf("%d", &n);
    printf("\nOk..");

    for (i = 0 ; i<n; i++)
    {
        printf("\nEnter employee %d data\n", i + 1);
        printf("Employee Id: ");
        scanf("%d", &e[i].emplid);
        printf("Name of Employee: ");
        scanf("%s", &e[i].name);
        printf("Enter the Salary of employee:");
        scanf("%lf",&e[i].salary);

    }
    printf("\nOkay...Done Your All Data Saved!\n");
}

void show()
{

    printf("\n ******************** All Student Data ******************** \n");
    printf("\n--------------------------------------------------------------\n");
    printf("\nEmployee ID  |\t Name \t\t|\t Salary \n");
    for (i = 0 ; i < n ; i++){
    printf("\n%d.      |\t %s   \t|\t %lf    \n", e[i].emplid, e[i].name, e[i].salary);
    }
    printf("\n");
}



void update()
{
    long int emplId;
    printf("\nEnter Employee Id : ");
    scanf("%ld", &emplId);
    for (i = 0; i < n; i++)
    {
        if (e[i].emplid == emplId)
        {
            printf("\n\n :: UPDATE MENU ::\n");
            printf("\n----------------------------------------\n");
            printf("1. | Change Name     \t \n");
            printf("2. | Change Salary  \t \n");

            printf("\nEnter your choice : ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("\nDo you really want to Change Name ?\n");
                printf("1. Yes\n2. No\n Choice : ");
                scanf("%d", &ch);

                switch (ch)
                {
                    case 1:
                        printf("Please Enter Correct Name ?\n");
                        scanf("%s", &newName);
                        printf("\nOkay..\nYour Old Name is %s", e[i].name);
                        printf("\nNow, Your New Name is %s", newName);

                        printf("\nDo you really want to Update ?\n");
                        printf("1. Yes\n2. No\n Choice : ");
                        scanf("%d", &ch);

                        switch (ch)
                        {
                        case 1:
                            strcpy(e[i].name, newName);
                            printf("\nData Updated Succesfully...\n");
                            break;
                        case 2:
                            printf("Okay");

                            break;
                        default:
                            printf("\nSorry Invalid....\n");
                            break;
                        }
                        break;
                    case 2:
                        printf("Okay..No Problem\n\n");

                        break;
                    default:
                        printf("Invalid");
                        break;
                }
                break;
            case 2:
                printf("\nDo you really want to update your salary ?\n");
                printf("1. Yes\n2. No\n Choice : ");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("Please Enter updated salary ?\n");
                    scanf("%lf", &newSalary);
                    printf("\nOkay..\nYour Old salary  is %lf", e[i].salary);
                    printf("\nNow, Your New salary is %lf", newSalary);

                    printf("\nDo you really want to Update ?\n");
                    printf("1. Yes\n2. No\n Choice : ");
                    scanf("%d", &ch);

                    switch (ch)
                    {
                    case 1:
                        e[i].salary = newSalary;
                        printf("\nData Updated Succesfully...\n");
                        break;
                    case 2:
                        printf("Okay");

                        break;
                    default:
                        printf("\nSorry Invalid....\n");
                        break;
                    }
                    break;
                case 2:
                    printf("Okay..No Problem");

                default:
                    printf("Invalid");
                    break;
                }
                break;

    }
        }
    }
}


void search()
{
    a=0;
    printf("\nEnter Employee Id : ");
    scanf("%d", &empid);
    for (i = 0; i < n; i++)
    {
        if (empid == e[i].emplid)
        {
            printf("\nRoll No  |\t Name \t\t|\t Salary \n");
            printf("\n%d      |\t %s   \t|\t %lf \n", e[i].emplid, e[i].name, e[i].salary);
        }
        else
        {
            a++;
        }
    }
    if (a == n)
    {
        printf("\n\n Sorry.. This employee id   Not Exist. Please Check!!\n");
        a = 0;
    }
    return 0;
}










