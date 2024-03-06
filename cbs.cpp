#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <ctime>

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
        Transaction(string tempAmount, string tempDate, string tempCurrency, string tempVendor): amount(tempAmount), date(tempDate), currency(tempCurrency), vendor(tempVendor) {} 
};


class TransactionRecord{

    public:
        vector<Transaction> transrecord;
        
        void addnewTransaction(Transaction tempObject){
            transrecord.push_back(tempObject);
        }

        void showTransactions(){
            for(int i = 0; i <= sizeof(transrecord); i++){
                cout << transrecord[i].amount << " " << transrecord[i].date << " " << transrecord[i].currency << " " << transrecord[i].vendor << "\n"; 
            }
        }

};



class FileInterfacer{

    public:
        int i;
        ofstream outFile;


        // Creates a file 
        void createFile(string tempFileName, vector<Transaction> tempRecord){
            
            // Adds file type
            tempFileName += ".txt";

            // Creates file
            ofstream MyFile(tempFileName);
            
            // Temporary to find size of list
            cout << tempRecord.size()<<"\n";

            // Making now a "saver" of currentTime
            time_t now = time(0);
            // convert now to string 
            char* dt = ctime(&now);

            MyFile << "This document was created:" << dt << endl;
            
            // Has to be removed 
            for(i = 0; i < tempRecord.size(); i++){
                MyFile << tempRecord[i].amount << ",";
               MyFile << tempRecord[i].date << ",";
                MyFile << tempRecord[i].currency << ",";
                MyFile << tempRecord[i].vendor << "\n" ;
            }

            MyFile.close();

        }
        
};


class FileSorter{

    public:
        void checkifSorted(){
            // Command that checks if it is sorted (by date??) 
        }

        void sortThis(){

        }
  
};


class FileReader{
    public:
       void readmyFile(string tempFile){
            // temporary
            cout << "readFile initialize" << "\n";
            
            fstream f(tempFile, ios::in);
            string line;

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

Transaction T1("200", "02.06.30","DKK","Netto");
Transaction T2("500","06.30.09", "DKK", "LIDL");

TransactionRecord record;
FileInterfacer fileinterface;
FileReader fileread;


record.addnewTransaction(T1);
record.addnewTransaction(T2);

//record.showTransactions();

fileinterface.createFile("Test", record.transrecord);
fileread.readmyFile("Hello.txt");

return 0;

}