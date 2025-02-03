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

float moadel() {
    	float moadel1 = 0;
        int vahedha = 0, soorat = 0;
        for (int i = 0; i < crs.size(); i++) {
            vahedha += crs[i].v;        
            soorat += crs[i].v * crs[i].nomre;
        }
           moadel1=soorat / vahedha;
        return (moadel1);
    }
};
    
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
            cout<<"it was successfully =)"<<"\n";
            return;
        }
    }
    cout << "EERROR!!!!! not found!!!!!" << "\n";
}
void menu() {
    cout << "1- add a student" << "\n";
    cout << "2- add a course" << "\n";
    cout << "3- list students (by moadel)" << "\n";
    cout << "4- student report" << "\n";
    cout << "5- remove a student" << "\n";
    cout << "6- find a student" << "\n";
    cout << "7- edit student" <<"\n";
    cout << "8- Exit" << "\n";
}
// list std
void listStds() {
    if (stds.size()==0) {
    cout << "EERROR!!!!! not found!!!!!" << "\n";
        return;
    }
    int which;
    cout<<"do you want to filter student by their major?"<<"\n"<<"1- yes"<<"\n"<<"2- no"<<"\n";
    cin>>which;
    if(which == 2)
    {
    	for (int i=0; i < stds.size(); i++) {
        for (int j=i+1; j<stds.size(); j++)
		{
            if (stds[i].moadel() < stds[j].moadel())
			{
                Std temp;
				temp = stds[i];
                stds[i] = stds[j];
                stds[j] = temp;
            }
        }
    }

    cout << ">>>>>>> students list (by moadel) <<<<<<<" <<"\n";
    for (int i=0; i< stds.size(); i++) {
        cout << "name: " << stds[i].n;
		cout << "\t" << "| id: " << stds[i].id;
		cout << "\t" << "| major: " << stds[i].m;
		cout << "\t" << "| moadel: " << stds[i].moadel() << "\n";
        cout << "------------------------------" << "\n";
    }
	}
	if(which == 1)
	{
		cout<<"name majore :";
		string which1;
		cin.ignore();
		getline(cin,which1);
		cout << ">>>>>>> students list (by moadel) <<<<<<<" <<"\n";
		for(int i=0; i< stds.size(); i++)
		          if(stds[i].m == which1)
		                {
		                      cout << "name: " << stds[i].n;
		                      cout << "\t" << "| id: " << stds[i].id;
	                          cout << "\t" << "| major: " << stds[i].m;
		                      cout << "\t" << "| moadel: " << stds[i].moadel() << "\n";
                              cout << "------------------------------" << "\n";
						}
		
	}
}
// remove std
void removstd() {
    int q;
    cout << ">< student id to remove ><";
    cin>>q;

    for (int i = 0; i < stds.size(); i++) {
        if (stds[i].id == q) {
            stds.erase(stds.begin() + i);
            cout << "it was successfully =)" << q << "\n";
            return;
        }
    }
    cout << "EERROR!!!!! not found!!!!!"  << "\n";
}

// search
void findStd() {
    int a;
    cout << "OO student id to find: OO";
    cin>>a;

    for (int i = 0; i < stds.size(); i++) {
        if (stds[i].id == a) {
            cout << ">> it is:";
            cout << "\t" << "name: " << stds[i].n;
			cout << "\t" << "id: " << stds[i].id;
			cout << "\t" << "major: " << stds[i].m;
			cout << "\t" << "moadel: " << stds[i].moadel() << "\n";
            return;
        }
    }
    cout << "EERROR!!!!! not found!!!!!" << "\n";
}

//edit std
void editstd()
{
	int d;
	cout<<"id :";
    cin>>d;
    for(int j =0; j< stds.size(); j++)
    {
    	if( d == stds[j].id)
  	   {
    	   	cout<<"you want to edit which?"<<"\n";
    	   	cout<<"1- name"<<"\n";
    	   	cout<<"2- id" << "\n";
    	   	cout<<"3- major" <<"\n";
    	   	cout<<"4- Exit" <<"\n";
    	   	int s, f1;
    	   	string f;
    	   	cin.ignore();
    	   	cin>>s;
    	   	cin.ignore();
    	   	switch(s)
    	   	{
    	   		case 1: cout<<"enter name: "; cin.ignore(); cin>>f; stds[j].n=f; break;
    	   		case 2: cout<<"enter id: "; cin.ignore(); cin>>f1; stds[j].id=f1; break;
    	   		case 3: cout<<"enter majore: "; cin.ignore(); cin>>f; stds[j].m=f; break;
    	   		case 4: break;
		    }
		    return;
	   }
    }
    }

//report
void report() {
    int e;
    cout << "student id to report: ";
    cin>>e;

    for (int i = 0; i < stds.size(); i++) {
        if (stds[i].id == e) {
            cout << ">>>>> report <<<<<";
            cout << "\n" << "name: " << stds[i].n;
			cout << "\t" << "id: " << stds[i].id;
			cout << "\t" << "major: " << stds[i].m;
			cout << "\t" << "moadel: " << stds[i].moadel() << "\n";
            cout << "------------------------------\n";
            cout << "cours|" << "\t" <<"vahed|" << "\t" <<"nomre|" << "\n";
            cout << "------------------------------\n";
            for (int j = 0; j < stds[i].crs.size(); j++) {
                cout << stds[i].crs[j].n;
				cout << "\t" << stds[i].crs[j].v;
				cout << "\t" << stds[i].crs[j].nomre << "\n";
            }
            cout << "------------------------------\n";
            return;
        }
    }
    cout << "EERROR!!!!! not found!!!!!" << "\n";
}

int main()
{
	Std s;
	int ch=0;
	cout<< "choose a number please"<<"\n";
	while(ch!=8)
	{
		menu();
        cin>>ch;
		switch (ch) {
            case 1: readstd(); break;
            case 2: readCrs(); break;
            case 3: listStds(); break;
            case 4: report(); break;
            case 5: removstd(); break;
            case 6: findStd(); break;
            case 7: editstd(); break;
        }
	}
}
