#include <iostream>
#include <string>
#include <vector> 
#include <map>

using namespace std;
// Classes


class Transaction{
    //Changes from private to public because of line 36
    public:
        string amount;
        string date;
        string valuta;
        string vendor;

    public:
    // Constructor
        Transaction(string tempAmount, string tempDate, string tempValuta, string tempVendor): amount(tempAmount), date(tempDate), valuta(tempValuta), vendor(tempVendor) {} 
};




class TransactionRecord{
    private:
        vector<Transaction> transrecord;

    public:
        
        map<int, string> monthMap { {1, "Jan" },{2, "Feb" },{3, "March"},
                                {4, "April"}, {5, "May"}, {6, "June"},
                                {7, "July"}, {8, "Aug."}, {9, "Sept."},
                                {10, "Oct."}, {11, "Nov."}, {12, "Dec."}
        };


        void addnewTransaction(Transaction tempObject){
            transrecord.push_back(tempObject);
        }

        void showTransactions(){
            cout << "Transactions for " << endl;

            for(int i = 0; i < transrecord.size(); i++){
                cout << transrecord[i].amount << " " << transrecord[i].date << " " << transrecord[i].valuta << " " << transrecord[i].vendor << "\n"; 
            }
        }

        double getBalance(){
            double tempBalance = 0;

            for(int i = 0; i < transrecord.size(); i++){
                tempBalance = tempBalance + stod(transrecord[i].amount);
            }
            
            return tempBalance;
        }

        void showBalance(){
            double balance = getBalance();

            cout << "The balance for this month is: " ;
            cout << balance << endl; 
        }
};


int main(){


Transaction T1("200", "6","DKK","Netto");
Transaction T2("400.23", "6","DKK","Netto");

TransactionRecord record;

record.addnewTransaction(T1);
record.addnewTransaction(T2);

record.showTransactions();

record.getBalance();

record.showBalance();


return 0;

}