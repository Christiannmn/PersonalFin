#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <ctime>
#include <cstring>  

using namespace std;
// Classes

class Transaction{
    //Changes from private to public because of line 36
    public:
        string amount;
        string date;
        string currency;
        string vendor;

    public:
    // Constructor
        Transaction() {};
        Transaction(string tempAmount, string tempDate, string tempCurrency, string tempVendor): amount(tempAmount), date(tempDate), currency(tempCurrency), vendor(tempVendor) {} 
};


class FileInterfacer{

    public:
        int i;
        ofstream outFile;
        string dateFormat;
        int dateChecker;

        // Constructor
        FileInterfacer(string tempdateFormat): dateFormat(tempdateFormat) {} 

        int getdataFormat() {
        return dateChecker;
            }

        // Creates a file 
        void createFile(string tempFileName, vector<Transaction> tempRecord){

            // Adds file type
            tempFileName += ".txt";

            // Creates file
            ofstream MyFile(tempFileName);
            

            // Making now a "saver" of currentTime
            time_t now = time(0);
            // convert now to string 
            char* dt = ctime(&now);

            cout << "Please choose existing date format" << "\n" << "1. ddMMyy" << "\n" << "2. MMddyyy" << "\n" << "3. Mdyy" << "\n" << "4. dddMMMyyyy" << "\n";
            cin >> dateChecker;

        for (int i = 0; i < tempRecord.size(); i++){
            if (dateChecker == 2){
               // splitting string up
               string month = tempRecord[i].date.substr(0,2);
               string day = tempRecord[i].date.substr(3,2);
               string year = tempRecord[i].date.substr(6,2);

                tempRecord[i].date = day + '.' + month + '.' + year;
    
            }

            else if(dateChecker == 3){
                string month = tempRecord[i].date.substr(0, 1);
                string day = tempRecord[i].date.substr(2, 2);
                string year = tempRecord[i].date.substr(5, 2);

                tempRecord[i].date = day + '.' + month + '.' + year;
                
            }

            else if(dateChecker == 4){
                string day = tempRecord[i].date.substr(0,3);
                string month = tempRecord[i].date.substr(3,3);
                string year = tempRecord[i].date.substr(6,4);
                // I need to account for days (LUT?) This may be removed due to scope 

                if (month == "Jan") {
                    month = "01";
                }
                else if (month == "Feb") {
                    month = "02";
                } 
                else if (month == "Mar") {
                    month = "03";
                } 
                else if (month == "Apr") {
                    month = "04";
                } 
                else if (month == "May") {
                    month = "05";
                }
                else if (month == "Jun") {
                    month = "06";
                } 
                else if (month == "Jul") {
                    month = "07";
                } 
               else if (month == "Aug") {
                    month = "08";
                } 
                else if (month == "Sep") {
                    month = "09";
                } 
                else if (month == "Oct") {
                    month = "10";
                } 
                else if (month == "Nov") {
                    month = "11";
                }
                else if (month == "Dec") {
                    month = "12";
                } 
              else {
            month = "Unknown";
            }
            tempRecord[i].date = day + '.' + month + '.' + year;

            }
        }
            MyFile << "This document was created:" << dt << endl;
            
            /* Has to be removed 
            for(i = 0; i < tempRecord.size(); i++){
                MyFile << tempRecord[i].amount << ",";
               MyFile << tempRecord[i].date << ",";
                MyFile << tempRecord[i].currency << ",";
                MyFile << tempRecord[i].vendor << "\n" ;
            }
            */

            MyFile.close();
    
        }
        
};

class TransactionRecord{

    public:
        vector<Transaction> transrecord;
        
        void addnewTransaction(Transaction tempObject){
            transrecord.push_back(tempObject);
        }

        void showTransactions(){
            for(int i = 0; i < transrecord.size(); i++){
                cout << transrecord[i].amount << " " << transrecord[i].date << " " << transrecord[i].currency << " " << transrecord[i].vendor << "\n"; 
            }
        }

        void calculateintegerDate(string tempDate){
             // Algorithm that finds total amount of days between our record and a given date. We are going to use this in our filter, to see if our records are <= a number
            int day = 0, month = 0, year = 0;
            vector<int> vecofdays;

            const int monthDays[12] = { 31, 28, 31, 30, 31, 30,  
            31, 31, 30, 31, 30, 31 }; 

        // Checks for a string with the given date and assigns it day, month and year.
        for(int i = 0; i < transrecord.size(); i++){

            //cout << "This is the transrecord " << transrecord[i].date;
            // cout << "This is the given date " << tempDate;

            if(transrecord[i].date == tempDate){
            int day = stoi(transrecord[i].date.substr(0,2));
            int month = stoi(transrecord[i].date.substr(6,2));
            int year = 2000 + 5;
            //stoi(transrecord[i].date.substr(4,2));
            break;
        }
        else{
            cout << "There are no records pertaining to this date";
        }
            }
            cout << "Hello" << "\n";
        }


void filterdateInterval(string startDate, string endDate) {
    //FIlters date
    Transaction key;

    int startDay = stoi(startDate.substr(0, 2));
    int startMonth = stoi(startDate.substr(3, 2));
    int startYear = stoi(startDate.substr(6, 2)) + 2000;

    int endDay = stoi(endDate.substr(0, 2));
    int endMonth = stoi(endDate.substr(3, 2));
    int endYear = stoi(endDate.substr(6, 2)) + 2000;

    int startDateNum = startYear * 10000 + startMonth * 100 + startDay;
    int endDateNum = endYear * 10000 + endMonth * 100 + endDay;

    vector<Transaction> filteredTransactions;

    for (int i = 0; i < transrecord.size(); i++) {
        int keyDay = stoi(transrecord[i].date.substr(0, 2));
        int keyMonth = stoi(transrecord[i].date.substr(3, 2));
        int keyYear = stoi(transrecord[i].date.substr(6, 2)) + 2000;

        int keyDateNum = keyYear * 10000 + keyMonth * 100 + keyDay;

        if (keyDateNum >= startDateNum && keyDateNum <= endDateNum) {
            filteredTransactions.push_back(transrecord[i]);
        }
    }

    for (int i = 0; i < filteredTransactions.size(); i++) {
        cout << filteredTransactions[i].date << " ";
    }
}


        void filterCurrency(string tempCurrency){
            bool checker = false;
            vector<Transaction> tempfilteredVector;

            for(int i = 0; i < transrecord.size(); i++){
                if(tempCurrency == transrecord[i].currency){

                    checker = true;
                    // I will need to put this into its own 
                    
                    tempfilteredVector.push_back(transrecord[i]); 
                    cout << tempfilteredVector.back().amount << " " << tempfilteredVector.back().currency;
                    
                }
            }
            
            if(!checker){
                // This needs to come up on the "UI terminal"
                cout << "There are no transactions with the currency: " << tempCurrency;
            }

        }
};


class FileFilter{

    public:
        void checkifSorted(){

        }
        // We will do this today
        void filterThis(vector<Transaction> tempRecord, string tempdateStart, string tempdateEnd){
            
        }
  
};


class FileReader{
    public:
       void readmyFile(string tempFile){
            // temporary
            cout << "readFile initialize" << "\n";
            
            fstream f(tempFile, ios::in);
            string line;

            // I need to implement system in which it reads and STORES the the values as instances

            if (f.is_open()){
                getline(f,line);
                    while(f){
                        cout << line << endl;
                        getline(f,line);
                    }
                f.close();
            }

            else{
                cout << "Failure reading file";
            }

       }
};


int main(){

Transaction T1("200", "02.26.19","DKK","Netto");

Transaction T2("500","30.06.02", "DKK", "LIDL");


TransactionRecord record;
FileInterfacer fileinterface("MMddyyy");
FileReader fileread;

record.addnewTransaction(T1);
record.addnewTransaction(T2);

// record.showTransactions();
// record.calculateintegerDate("30.06.02");

fileinterface.createFile("Test", record.transrecord);
// fileread.readmyFile("Hello.txt");

record.filterCurrency("DKK");

record.filterdateInterval("30.08.02","30.19.02");

return 0;

}