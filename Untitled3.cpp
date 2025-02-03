#include <iostream>
#include <vector>
#include <string>
using namespace std;

//get course
struct Crs {
    string n;
    int v;
    float nomre;
};

// get student
struct Std {
    string n;
    int id;
    string m;
    vector<Crs> crs;

};
float moadel() {
	    Crs C;
    	float moadel1 = 0;
        int vahedha = 0, soorat = 0;
        for (int i = 0; i < 4; i++) {
            vahedha += C.v;        
            soorat += C.v * C.nomre;
        }
           moadel1=soorat / vahedha;
        return (moadel1);
    }
    
vector<Std> stds;
void readstd() {
    Std s;
    cout << "student name: ";
    getline(cin, s.n);
    
    cout << "student id: ";
    cin>>s.id;
    cin.ignore();
    
    cout << "major: ";
    getline(cin, s.m);
    
    stds.push_back(s);
    cout<<"it was successfully =)"<<"\n";
}
void readCrs() {
    int id;
    cout << "the id: ";
    cin>>id;
    cin.ignore();
    
    for (int i = 0; i < stds.size(); i++)
	{
        if (stds[i].id == id)
		{
            Crs c;
            cout << "course name: ";
            getline(cin, c.n);
            cout << "course vahed: ";
            cin >> c.v;
            cout << "course nomre: ";
            cin >> c.nomre;
            cin.ignore();
            stds[i].crs.push_back(c);
            cout<<"successful"<<"\n";
            return;
        }
    }
    cout << "not found!!!!!" << "\n";
}
void menu() {
    cout << "1- add a student" << "\n";
    cout << "2- add a cours" << "\n";
    cout << "3- Exit" << "\n";
}

int main()
{
	Std s;
	int ch=0;
	cout<< "choose a number please"<<"\n";
	while(ch!=2)
	{
		menu();
        cin>>ch;
		if(ch == 1)
		{
    	readstd();
		}
		if( ch == 2)
		{
		readCrs();
		}
	}
}
