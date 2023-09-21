#include <bits/stdc++.h>
using namespace std;
#define DBG ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
//**********************************************************************************************************************
// Global variables Part
//**********************************************************************************************************************
const int specialization = 21 ;
const int patient = 6 ;
        string names [specialization][patient];
        int status [specialization][patient];
        int number_of_patient [specialization] {0};
//**********************************************************************************************************************
// Check Part
//**********************************************************************************************************************
bool check_patient_forGet (int spc=0){
    if (number_of_patient[spc]==0)
        return true;
    else
        return false;
}
bool check_patient_forAdd (int spc=0){
    if (number_of_patient[spc]==5)
        return true;
    else
        return false;
        
}
//**********************************************************************************************************************
// Shift Part
//**********************************************************************************************************************
void forGet (int spc=0){
    for (int pos = 0; pos < number_of_patient[spc]-1 ; ++pos) {
        names[spc][pos]=names[spc][pos+1];
        status[spc][pos]=status[spc][pos+1];
    }
    number_of_patient[spc]--;
}
void forAdd (int spc=0){
    for (int pos = number_of_patient[spc]-1; pos >= 0 ; --pos) {
        names[spc][pos+1]=names[spc][pos];
        status[spc][pos+1]=status[spc][pos];
    }
}
//**********************************************************************************************************************
// Action Part
//**********************************************************************************************************************
void Add_New_Patient (){
    string name;
    int stat,spc;
    cout << "Enter specialization , Name and statues pls :"<<endl;
    cin>> spc >> name >> stat;
    if (check_patient_forAdd(spc))
    {
        cout << " Sorry we Cant Add More Patient for this Specialization " <<endl;
        return;
    }
    int positionofpatient = number_of_patient[spc];
    if (stat == 0) {
        names[spc][positionofpatient] = name;
        status[spc][positionofpatient] = stat;
        number_of_patient[spc]++;
    }
    else if (stat == 1){
        forAdd(spc);
        names[spc][0] = name;
        status[spc][0] = stat;
        number_of_patient[spc]++;

    }
}
void Print_All_Patient (){
    for (int spc = 0; spc < specialization; ++spc) {
        if (number_of_patient[spc]>0)
            cout << "there are "<< number_of_patient[spc] << " patient in specialization "<< spc <<endl;

        for (int spc1 = 0; spc1 < number_of_patient[spc]; ++spc1) {
            if (status[spc][spc1]==0)
                cout << names[spc][spc1] << " regular"  <<endl;
            else if (status[spc][spc1]==1)
                cout << names[spc][spc1] << " urgent"  <<endl;

        }
    }
}
void Get_Next_Patient (){
    cout << "Enter Specialization " <<endl;
    int spc ;cin>>spc;
    if (check_patient_forGet(spc))
    {
        cout << "There is no Patient for this Specialization " <<endl;
        return;
    }
    cout << names[spc][0]<< " Pls Go With the Dr "<<endl;
    names[spc][0]=" ";
    status [spc][0]=0;
    forGet(spc);
}
//**********************************************************************************************************************
// Properties Part
//**********************************************************************************************************************
int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nEnter your choice:"<<endl;
        cout << "1) Add new patient"<<endl;
        cout << "2) Print all patients"<<endl;
        cout << "3) Get next patient"<<endl;
        cout << "4) Exit"<<endl;

        cin >> choice;

        if (!(1 <= choice && choice <= 4)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}
void hospitalSystem() {
    while (true) {
        int choice = menu();

        if (choice == 1)
            Add_New_Patient();
        else if (choice == 2)
            Print_All_Patient();
        else if (choice == 3)
            Get_Next_Patient();
        else
            break;
    }
}
//**********************************************************************************************************************
int main() {
    DBG
    hospitalSystem();
  return 0;
}
