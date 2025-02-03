#include <iostream>
#include <vector>
#include <string>
using namespace std;

//get course
struct Crs {
    string n;
    int v;
    int nomre;
};

// get student
struct Std {
    string n;
    int id;
    string m;
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
Std readstd() {
	Std s;
    cout << "name: "; getline(cin, s.n);    
    cout << "id: "; cin>>s.id;
    cout << "major: "; getline(cin, s.m);
	
	cout<<"successful";
    return s;
}
int main()
{
	Std s;
	s=readstd();
}
