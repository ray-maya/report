```cpp
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
    float moadel() const {
      	float moadel1 = 0;
        float vahedha = 0, soorat = 0;
        for (int i = 0; i < crs.size(); i++) {
            vahedha += crs[i].v;        
            soorat += crs[i].v * crs[i].nomre;
        }
        if(vahedha > 0)
           moadel1=soorat / vahedha;
        return (moadel1);
    }
};
```
<br>در این قسمت برای اضافه کردن دانشجو ساختمان داده داریم.
<br>در ساختمان درس ها n اسم درس، v واحد، nomre نمره درس است که برای دانشجویان متفاوت است
<br>در ساختمان دانشجووها، n اسم دانشجو، id شماره دانشجویی، m رشته است، crs لیستی از دروس که دانشجو در آنهاست
<br>تابع moadel نیز معدل را این شکلی حساب می کند: با حلقه فور در درس ها می گردیم واحد هارا جمع می کنیم در vahedha میریزیم
<br>و هم واحد هارا در نمره درس ها ضرب می کنیم تا طبق واحد ها ارزش گذاری شوند سپس آنها را در متغیری برای صورت میریزیم، بعد صورت را بر مخرج تقسیم میکنیم
```cpp
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

// read structuer of cours
void readCrs() {
    int id;
    cout << "student id: ";
    cin>>id;
    cin.ignore();
    
    for (int i = 0; i < stds.size(); i++) {
        if (stds[i].id == id) {
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
```
<br>در void readstd اسم کاربر شماره دانشجویی، رشته را دریافت می کنیم
<br>در void readcrs اطلاعات درس را میگیریم، اول شماره دانشجویی را دریافت می کنیم، در لیست دانشجویان می گردیم تا شماره را پیدا کنیم
<br>بعد اسم، واحد، نمره درس را دریافت می کنیم پیام موفیت آمیز بودن ارسال می شود، اگر شماره دانشجویی وجود نداشت not found ارسال می شود
```cpp
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
    	for (int i = 0; i < stds.size(); i++) {
        for (int j = i + 1; j < stds.size(); j++) {
            if (stds[i].moadel() < stds[j].moadel()) {
                Std temp = stds[i]; // جابجایی اطلاعات
                stds[i] = stds[j];
                stds[j] = temp;
            }
        }
    }

    cout << ">>>>>>> students list (by moadel) <<<<<<<" <<"\n";
    for (int i = 0; i < stds.size(); i++) {
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
		vector<Std> filtered;
		cout << ">>>>>>> students list (by moadel) <<<<<<<" <<"\n";
		for(int i=0; i <= stds.size(); i++)
		          if(stds[i].m == which1)
		          filtered.push_back(stds[i]);
		                {
		                	 for (int i = 0; i < filtered.size(); i++) {
                                   for (int j = i + 1; j < filtered.size(); j++) {
                                      if (filtered[i].moadel() < filtered[j].moadel()) {
                                                Std temp = filtered[i];
                                                filtered[i] = filtered[j];
                                                filtered[j] = temp;
                }
            }
        }
                              for (int i = 0; i < filtered.size(); i++) {
		                      cout << "name: " << filtered[i].n;
		                      cout << "\t" << "| id: " << filtered[i].id;
	                          cout << "\t" << "| major: " << filtered[i].m;
		                      cout << "\t" << "| moadel: " << filtered[i].moadel() << "\n";
                              cout << "------------------------------" << "\n";
						}
		
	}
}
}
```
<br>از 
<br>نمایش لیست به این صورت است که از کاربر می پرسد لیست کردن کاربران عادی صورت بگیرد بر اساس معدل
<br>یا فقط رشته ی خاصی را فیلتر کند، اگر بر اساس رشته خاصی بود، برنامه با حلقه فور در لیست می گردد تا دانشجویان آن رشته را انتخاب کند
<br>و آن هارا در یک لیست جدید میریزد سپس اعضای آن لیست که دانشجویان آن رشته هستند را بر اساس معدل باهم مقایسه می کند تا به ترتیب معدل نمایش دهد
```cpp
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
    cout << "EERROR!!!!! not found!!!!!" << "\n";
}
```
<br>شماره دانشجویی را می گیرد، دانشجو را پیدا و با تابع earse آن را دیلیت می کند


```cpp
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
```
<br>آیدی دانشجو را می گیرد، دانشجو را پیدا میکند اطلاعات را نمایش می دهد
```cpp
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
```
<br>آیدی دانشجو را میگیرد، اطلاعات کارنامه یعنی اطلاعات خود دانشجو، و درس های گذرانده شده و معدل نمرات را نمایش میدهد
```cpp
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
```
<br>آیدی دانشجو را میگیرد، منو به کاربر نشان میدهد که کدام اطلاعات دانشجورا میخواهیم عوض کنیم
<br>بعد از انتخاب عدد با توجه به عدد انتخاب شده میتوانیم اسم، شماره دانشجویی رشته را تغییر دهیم در اینجا از سیچچ کیس استفاده شده
```cpp
int search(int d) {
    for (int j = 0; j < stds.size(); j++) {
        if (stds[j].id == d)
            return 1;
    }
    return 0;
}

void editcr() {
    cout << "course name: ";
    string getc;
    getline(cin, getc);

    for (int i = 0; i < stds.size(); i++) {
        for (int j = 0; j < stds[i].crs.size(); j++)
		{
            if (stds[i].crs[j].n == getc)
			{
    	 cout<<"you want to edit which?"<<"\n";
	     cout<<"1- nomre"<<"\n";
 	     cout<<"2- vahed"<<"\n";
	     cout<<"3- name"<<"\n";
         int w;
                cin >> w;
                cin.ignore();

                float f1, d;
                string f;

                switch (w) {
                    case 1:cout << "student id: ";
                        cin >> d;
                        if (search(d)) {
                            cout << "Nomre: ";
                            cin >> f1;
                            stds[i].crs[j].nomre = f1;
                        } else {
                            cout << "EERROR!!!!! not found!!!!!" << "\n";
                        }
                        break;
                    case 2: cout << "vahed: "; cin >> f1; stds[i].crs[j].v = f1; break;
                    case 3: cout << "name: "; cin.ignore(); getline(cin, f); stds[i].crs[j].n = f; break;
                    default: cout << "can you choose again? i couldnt undrestand :/" << "\n"; break;
                }

                    cout<<"it was successfully =)"<<"\n";
                return;
            }
        }
    }

    cout << "EERROR!!!!! not found!!!!!" << "\n";
}
```
<br>در قسمت void برای تغییر اطلاعات درس اول اسم درس را دریافت می کند سپس با فور بین اطلاعات اسم درس ها می گردد تا درس هارا پیدا کند
<br>منو را چاپ میکند انتخاب می کنیم که اسم واحد یا نمره درس را میخواهیم تغییر دهیم
<br>اگر نمره را بخواهیم تغییر دهیم شماره دانشجو را دریافت میکنیم سپس در قسمت تابع بالای void اول شماره را تطبیق داده و پیدا میکنیم بعد هم نمره را تغییر میدهیم
<br>اما برای تغییر اسم یا واحد ها فقط قسمت داخل وید اجرا می شود می توانیم آنهارا تغییر دهیم
```cpp
int main() {
    int ch=0;
    cout << "hi welcome =)))))" << "\n" << "you can click a num: " << "\n";
    while (ch != 9)
    {
        menu();
        cin >> ch;
        cin.ignore();

        switch (ch) {
            case 1: readstd(); break;
            case 2: readCrs(); break;
            case 3: listStds(); break;
            case 4: report(); break;
            case 5: removstd(); break;
            case 6: findStd(); break;
            case 7: editstd(); break;
            case 8: editcr(); break;
            case 9: cout << "Exit"; break;
            default: cout << "can you choose again? i couldnt undrestand :/" << "\n"; break;
        }
    }

    return 0;
}
```
<br>این تابع اصلی است منو را نمایش میدهد سپس عددی دریافت می کند، با استفاده از سیچچ کیس هر ویدی که مرتبط باشد را اجرا میکند
<br>در قسمت پایین کد منو نوشته
```cpp
void menu() {
    cout << "1- add a student" << "\n";
    cout << "2- add a course" << "\n";
    cout << "3- list students (by moadel)" << "\n";
    cout << "4- student report" << "\n";
    cout << "5- remove a student" << "\n";
    cout << "6- find a student" << "\n";
    cout << "7- edit student" <<"\n";
    cout << "8- edit course" <<"\n";
    cout << "9- Exit" << "\n";
}
```
