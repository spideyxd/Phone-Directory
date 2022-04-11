#include<bits/stdc++.h>
#include<conio.h>
#define endl "\n"
using namespace std;

    class structure
    {
        public: 

            long long Phone_No;
            structure* albhabets[26];
            bool EndOfName;

    };

    structure* getNode(){
        structure* temp=new structure;
        for (int i = 0; i < 26; i++)
        temp->albhabets[i]=NULL;

        temp->EndOfName=false;        

        return temp;
    }

    vector< pair <string,int> > vect;

    void insert(structure* root,string name,long long phone){

        structure* temp=root;

        for (int i = 0; i < name.length(); i++)
        {
            int index=name[i]-'a';
            if(!temp->albhabets[index])
            temp->albhabets[index]=getNode();

            temp=temp->albhabets[index];

        }
        temp->Phone_No=phone;
        temp->EndOfName=true;    

    }

    bool isEmpty(structure* root)                  
{ 
    for (int i = 0; i < 26; i++) {
    	
        if (root->albhabets[i]) {
            return false; 
        }
    }
    return true; 
}

    structure* deleteWord(structure* root, string word, int depth){
	
	if(root == NULL){
		return NULL;			
	}

	if(depth == word.size()){                    
		if(root->EndOfName){
			root->EndOfName = false;
        }
		if(isEmpty(root)){                       
			delete(root);
			root = NULL;
		}

		return root;
	}
	
	int index = word[depth] - 'a';               
	
	root->albhabets[index] = deleteWord(root->albhabets[index], word, depth+1); 
	
	if(isEmpty(root) && root->EndOfName == false){   
		delete (root);                           
		root = NULL;                             
	}
	
	return root;		
}


    void search(structure* root,string name,int a){

        structure* temp=root;

        for (int i = 0; i < name.length(); i++)
        {
            int index=name[i]-'a';
            if(temp->albhabets[index])
            temp=temp->albhabets[index];

        }
        if(temp->EndOfName){
        cout<<"\n"<<name<<"'s Phone No : "<<temp->Phone_No<<endl;
        if(a==4)
        {cout<<"\n\nPress enter to continue"<<endl;
        getch();
        system("CLS");
        return;}
        else if(a==5)
        {
            cout<<"\nEnter new phone number: ";cin>>temp->Phone_No;
            cout<<"changes saved successfully";
            cout<<"\n\nPress enter to continue"<<endl;
            getch();
            system("CLS");
        }
        else
        {
        deleteWord(root,name,0);

        vector< pair <string,int> > ::iterator itr;
        for( itr=vect.begin(); itr!=vect.end();itr++)
        {
            if((*itr).first==name)
            vect.erase(itr);
        }
        cout<<"deletion done successfully";
            cout<<"\n\nPress enter to continue"<<endl;
            getch();
            system("CLS");
        }
        }
        else
        {
            cout<<"\nNo such Name present"<<endl;
            cout<<"\n\nPress enter to continue"<<endl;
            getch();
            system("CLS");
        }
    }

string generate_captcha(){
    int n=6;
 srand(time(0));
string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string captcha;

while(n--){

captcha.push_back(s[rand()%62]);

}

return captcha;
}

bool verifying_captcha(){
     string captcha,ver_captcha;
        ver_captcha=generate_captcha();
        cout<<"\n\nCaptcha : "<<ver_captcha<<endl;
        cout<<"\nEnter Captcha : ";
        getline(cin,captcha);
return (captcha==ver_captcha?true:false);

}
bool verifying_email(){

string email,ver_email="abc@gmail.com";

cout<<"\nEnter Email : "; getline(cin,email);

return(email==ver_email?true:false);

}
bool verifying_pass(){

string password,ver_password="pass@123";
char pwd;
while (!password.empty())
  {

    password.pop_back();
  }
cout<<"\nEnter Password : ";

     pwd = getch();
   if(pwd>=32 && pwd<=126)
   {
        while(pwd != 13)
        {
                 if(pwd>=32 && pwd<=126)
                 {
                    password.push_back(pwd);
                    cout << '*';
                    pwd = getch();
                 }
                else if(pwd==8)
                {
                    if(!password.empty())
                    {
                        cout << '\b' << " " << '\b';
                        password.pop_back();
                        pwd=getch();
                    }
                    else
                    {
                        pwd=getch();
                    }
  
                }

                else
                {
                    pwd = getch();
                }   
        }
    }

return(password==ver_password?true:false);

}
void load(int a)
{   int v;
    for(int h=0;h<a;h++)
    {v=0;}}
void loading()
{   cout<<"LOADING";
    for(int j=0;j<11;j++)
    {   load(9999999);
        cout<<" .";}
    cout<<"\n";
    system("cls");
    
    }
int Login(){

    bool alt_email=verifying_email();
    while (!alt_email)
    {
        cout<<"Incorrect Email , Try Again"<<endl;
        alt_email=verifying_email();
    }


    bool alt_password=verifying_pass();
    while (!alt_password)
    {
        cout<<"\nIncorrect Password , Try Again"<<endl;
        alt_password=verifying_pass();
    }


    bool alt_captcha=verifying_captcha();
    while(!alt_captcha)
    {
        cout<<"Incorrect Captcha , Try Again"<<endl;
        alt_captcha=verifying_captcha();
    }

return 1;
}

void insertion(structure *root)
{
    int size; string name;long long ph_no;
    cout<<"Number of Entries you wanna insert : ";cin>>size;

for (int i = 0; i < size; i++)
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\nEnter Name : ";getline(cin,name);
    cout<<"Enter Phone No : ";cin>>ph_no;
    vect.push_back( make_pair(name,ph_no) );
    insert(root,name,ph_no);
    cout<<"\n\n\t\t\t\tEntry Added Successfully"<<endl;
}

cout<<"\n\n\t\t\tAll the Entries Added Successfully"<<endl<<endl;

}

void searching(structure *root,int a){
string name;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"\n\nEnter Name of Person : ";getline(cin,name);
search(root,name,a);

}
void display(structure* root, char str[],int index){

if(root->EndOfName){
    str[index]='\0';
    cout<<"\n"<<str<<"\t\t";
    cout<<root->Phone_No;

}

for (int i = 0; i < 26; i++)
{
    if(root->albhabets[i]){
    str[index]= i+'a';
    display(root->albhabets[i],str,index+1);
    }
}
}
void sortthroughdate()
{
    cout<<"Contacts starting from the oldest to the newest:"<<endl<<endl;
    for(auto itr :vect)
    {
        cout<<itr.first<<"\t"<<itr.second<<endl;
    }
}

int main(){
    
structure* root=getNode();
Login();
system("CLS");
cout<<"< ----------------------- LOGIN SUCCESFULL ------------------------ >"<<endl;
cout<<"Press enter to continue"<<endl;
getch();
loading();
system("CLS");
int choice;
while(choice!=0)
{
loading();
cout<<"Press 1 to add new contacts\nPress 2 to display contacts lexicographically\nPress 3 to display contacts oldest to newest\nPress 4 to search a contact\nPress 5 to edit phone number of an existing contact\nPress 6 to delete a contact\nPress 0 to exit"<<endl<<endl;
cout<<"Enter Choice: ";cin>>choice;
char str[20];int index=0;
switch(choice)
{
    case 1:insertion(root);
    system("CLS");
    break;
    case 2:
    display(root,str,index);
    cout<<"\n\nPress enter to continue"<<endl;
    getch();
    system("CLS");
    break;
    case 3:sortthroughdate();
    cout<<"\n\nPress enter to continue"<<endl;
    getch();
    system("CLS");
    break;
    case 4:searching(root,4);
    system("CLS");
    break;
    case 5:searching(root,5);
    system("CLS");
    break;
    case 6:searching(root,6);
    system("CLS");
    break;
}}
getch();
return 0;
}