#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;
int main()
{
    while(true)
    {
        cout<<"Choose any one"<<endl<<"1. Registration"
    <<endl<<"2. Login"<<endl<<"3. Quit"<<endl;
        int c;
        cout<<"Enter the choice: ";
        cin>>c;
        if(c==1)
        {
           string username,password;
            cout<<"Enter the Username: ";
            cin>>username;
            cout<<"Enter the password: ";
            cin>>password;


            ifstream inputfile("identity.txt");
                string u,p;
                bool found=false;
                while(inputfile>>u>>p)
                {
                    if(u==username)
                    {
                        found=true;
                        break;
                    }
                }
                inputfile.close();
                if(found)
                {
                    cout<<"Error, Username or Password already exist"<<endl;
                }
                else{
                    ofstream outputfile("identity.txt",ios::app);
                    outputfile<<username<<" "<<password<<endl;
                    outputfile.close();
                    cout<<"Registration Complete."<<endl;
                }
        }
        if(c==2)
        {
            string username,password;
            cout<<"Enter the Username: ";
            cin>>username;
            cout<<"Enter the password: ";
            cin>>password;

            ifstream inputfile("identity.txt");
            string u,p;
            bool found=false;
            while(inputfile>>u>>p)
            {
                if(u==username && p==password)
                {
                    found=true;
                    break;
                }
            }
            inputfile.close();
            if(found)
            {
                cout<<"Login Successful"<<endl;
            }
            else{
                cout<<"Error, Username or Password not found"<<endl;
            }
        }
        if(c==3)
        {
            cout<<"Thank you for visiting this project"<<endl;
            break;
        }
    }
    return 0;
}
