#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int search(account *accounts, int num_accounts, int account_num) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].num == account_num) {
            printf("id already exists :\n");
            return i; // Return the index of the found account
        }
    }
    return -1; // Return -1 if not found
}

void signIn(account *accounts, int num_accounts, float balance, char *name, int *position){
    if (*position < num_accounts){
        accounts[*position].num = *position + 1; //Assign a new account based on it's position
        accounts[*position].balance = balance;
        snprintf(accounts[*position].holder, sizeof(accoounts[*position].holder),"%s", name);
    }
    else {
        printf("No more accounts can be created.\n");
    }
    printf("Account created successfully: %d - %s - %.2f\n", accounts[*position].num, accounts[*position].holder, accounts[*position].balance);
}

int main(){

struct account{
    int num = 0;
    char holder[35];
    float balance;
} acc, num_account[15];
}


















