#include<iostream>
using namespace std;
#include "CreditCard.h"
int main(){
    CreditCard cc("5321711934640027","Sherlock", "Holmes", 221,"Baker Street", "London","NW1 6XE", "Lane no 6", 7, 2014, 6, 2014, 441);
    cout << "\n";cc.print();cout << "\n\n";
    cc.setHolder(Name("David", "Cameron"));
    cc.setAddress(Address(10,"Downing Street","London","SW1A 2AA"));
    cc.setIssueDate(Date(1, 7, 2017));
    cc.setExpiryDate(Date(4,8,2023));
    cc.setCVV(127);
    cout << "\n";cc.print();cout << "\n\n";
}
    //  Construction of data members  & object 
    5321711934640027 Sherlock Holmes 221 Baker Street London NW1 6XE 7/Jan/2014 6/Jun/2014 441
    //  Construction & destruction of temporary objects 
    same file 
    // Destruction of data members & object
        // > We could change address, issue date, expiry date and cvv, this is fine 
        // > We could change the name of the holder ! This should not be allowed 