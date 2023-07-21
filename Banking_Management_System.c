#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char name[20];
int account_number, amount = 10000, noOfSuccessTransactions = 0, noOfFailTransactions = 0;

void divider()
{
    for (int i = 0; i < 50; i++)
        printf("-");
}

void menu()
{
    system("cls");
    printf("************** MAIN MENU **************\n");
    divider();
    printf("\n1) Deposit Money\n2) Withdraw Money\n3) Transfer Money\n4) Account Details\n5) Transaction Details\n6) Exit\n");
}

void depositMoney()
{
    int diposit_amount;
    time_t tm;
    time(&tm);
    FILE *fp = fopen("Account.txt", "a");
    printf("************** DEPOSITING MONEY **************\n");
    divider();
    printf("\nPrevious Account Balance :- $%d\n", amount);
    printf("Enter the amount you want to Deposit : ");
    scanf("%d", &diposit_amount);
    amount += diposit_amount;
    printf("Money Deposited Successfully....\nCurrent Account Balance : $%d\n", amount);
    noOfSuccessTransactions++;
    fprintf(fp, "$%d has been deposited to your account\n", diposit_amount);
    fprintf(fp, "Date/Time of the Transaction is %s\n", ctime(&tm));
    fclose(fp);
}

void withdrawMoney()
{
    int withdraw_amount;
    time_t tm;
    time(&tm);
    FILE *fp = fopen("Account.txt", "a");
    printf("************** WITHDRAWING MONEY **************\n");
    divider();
    printf("\nEnter the amount you want to Withdraw : ");
    scanf("%d", &withdraw_amount);
    if ((withdraw_amount > amount) || (withdraw_amount < 0))
    {
        noOfFailTransactions++;
        printf("Insufficient Balanced or Invalid Input.\n");
        fprintf(fp, "$%d hasn't been withdrawed from your account due to insufficient balanced or invalid input entered\n", withdraw_amount);
        fprintf(fp, "Date/Time of the Transaction is %s\n", ctime(&tm));
    }
    else
    {
        amount -= withdraw_amount;
        noOfSuccessTransactions++;
        printf("Money Withdraw Successfully....Please Collect your Cash :)\nCurrent Account Balance : $%d\n", amount);
        fprintf(fp, "$%d has been withdrawed from your account\n", withdraw_amount);
        fprintf(fp, "Date/Time of the Transaction is %s\n", ctime(&tm));
    }
    fclose(fp);
}
void transferMoney()
{
    int transfer_amount, transfer_account;
    time_t tm;
    time(&tm);
    FILE *fp = fopen("Account.txt", "a");
    printf("************** TRANSFERING MONEY **************\n");
    divider();
    printf("\nEnter the amount you want to Transfer : ");
    scanf("%d", &transfer_amount);
    printf("Enter the Account Number in which you want to Transfer the Money : ");
    scanf("%d", &transfer_account);
    if ((transfer_amount > amount) || (transfer_amount < 0))
    {
        noOfFailTransactions++;
        printf("Insufficient Balanced or Invalid Input.\n");
        fprintf(fp, "$%d hasn't been transferred from your account to the account number %d due to insufficient balanced or invalid input entered\n", transfer_amount, transfer_account);
        fprintf(fp, "Date/Time of the Transaction is %s\n", ctime(&tm));
    }
    else
    {
        amount -= transfer_amount;
        noOfSuccessTransactions++;
        printf("Money Transferred Successfully....\nCurrent Account Balance : $%d\n", amount);
        fprintf(fp, "$%d has been Transferred from your account to the account number %d\n", transfer_amount, transfer_account);
        fprintf(fp, "Date/Time of the Transaction is %s\n", ctime(&tm));
    }
    fclose(fp);
}

void accountDetails()
{
    printf("************** ACCOUNT DETAILS **************\n\n");
    divider();
    printf("\nName of the account holder :- %s\n", name);
    printf("Account Number of the account holder named \"%s\" :- %d\n", name, account_number);
    printf("Total Current Balance of the account number \"%d\" :- %d\n", account_number, amount);
    printf("Total Number of Successfull Transactions done from the account number \"%d\" :- %d\n", account_number, noOfSuccessTransactions);
}

void transactionDetails()
{
    printf("************** TRANSACTIONS DETAILS **************\n\n");
    divider();
    printf("\nTotal Number of Successfull Transactions :- %d\n\nTotal Number of Unsuccessfull Transactions :- %d\n\n", noOfSuccessTransactions, noOfFailTransactions);
    FILE *fp = fopen("Account.txt", "r");
    char c = fgetc(fp);
    if (c != EOF)
    {
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(fp);
        }
    }
    else
        printf("\nNo Recent Transactions\n");
}

void lastDetails()
{
    printf("************** DETAILS **************\n\n");
    divider();
    printf("\nName :- %s\n", name);
    printf("Account Number :- %d\n", account_number);
    printf("Current Balance :- %d\n", amount);
}

int main()
{
    int choice;
    printf("Enter your Name : ");
    gets(name);

    printf("Enter your Account Number : ");
    scanf("%d", &account_number);
    while (1)
    {
        menu();
        divider();
        printf("\nEnter your Choice from the MENU given above : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            depositMoney();
            printf("\nPress any Key to Continue..............");
            getch();
            break;
        case 2:
            system("cls");
            withdrawMoney();
            printf("\nPress any Key to Continue..............");
            getch();
            break;
        case 3:
            system("cls");
            transferMoney();
            printf("\nPress any Key to Continue..............");
            getch();
            break;
        case 4:
            system("cls");
            accountDetails();
            printf("\nPress any Key to Continue..............");
            getch();
            break;
        case 5:
            system("cls");
            transactionDetails();
            printf("\nPress any Key to Continue..............");
            getch();
            break;
        case 6:
            system("cls");
            lastDetails();
            printf("\nPress any Key to Continue..............");
            getch();
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}