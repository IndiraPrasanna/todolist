#include <iostream>
#include<unistd.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<map>

using namespace std;

//for STRUCTURE

class Data{

public:

string task;
};

// FUNCTION

int add_new(){
  
  sleep(1);
  cout<<""<<endl;
  cout<<endl;
  // creating object for class
  Data obj;

  ofstream fout;
  fout.open("first.txt",ios::app);

  sleep(1);
  cout<<"ENTER THE TASK ";
  cout<<"\n\t";
  cin.get();
  getline(cin,obj.task);    // for user input
  
  fout<<obj.task<<"\n";
  
  fout.close();
  cout<<endl;
  sleep(1);
  cout<<"\t \t TASK ADDED SUCCESSFULLY"<<endl;
  cout<<"\n";
  sleep(1);
  cout<<""<<endl;
  return 1;  
}

int view(){

  // object for class
  Data obj;
  
  fstream fin;
  fin.open("first.txt",ios::in);

  sleep(1);
  while (1) {                    
    if(fin.eof())          
      break;              
    string line;
    while(getline(fin,line)){
      cout<<line<<endl;
    }
  }  
  fin.close();
  sleep(1);
  return 1;
}

int complete(){

  sleep(1);
  cout<<""<<endl;
  cout<<endl;
  int re=view();
  cout<<endl;
  sleep(1);
  cout<<"ENTER THE LINE NUMBER YOU WANTED TO BE MARKED AS COMPLETED ";
  int complete_line;
  cin>>complete_line;

  ifstream realfile;
  realfile.open("first.txt",ios::in);

  ofstream copyfile;
  copyfile.open("copy.txt",ios::app);

  int line=1;
  string c;
  char single;
  
  while(realfile.get(single)){

    if(single == '\n'){
      line++;
    }

    copyfile<<single;
    if(line == complete_line+1 && single=='\n'){    
      copyfile<<" COMPLETED ->  \t";
    } 
    // dont know how but still program runs for line_number+1
  }

  copyfile.close();
  realfile.close();
  
  remove("first.txt");
  rename("copy.txt","first.txt");

  sleep(1);
  cout<<endl;
  cout<<"\t\t TASK UPDATED SUCCESSFULLY"<<endl;
  sleep(1);
  cout<<""<<endl;
  return 1;
    
}

int remove(){

  sleep(1);
  cout<<""<<endl;
  cout<<endl;
  sleep(1);
  int re=view();

  cout<<endl;
  
  cout<<"ENTER THE LINE NUMBER TO DELETE ";
  int line_number;
  cin>>line_number;

  ifstream realfile;
  realfile.open("first.txt",ios::in);

  ofstream copyfile;
  copyfile.open("copy.txt",ios::app);

  int line=1;
  string c;
  char single;
  
  while(realfile.get(single)){

    if(single == '\n'){
      line++;
    }
    
    if(line != line_number+1){    
      copyfile<<single;
    } 
    // dont know how but still program runs for line_number+1
  }

  copyfile.close();
  realfile.close();
  
  remove("first.txt");
  rename("copy.txt","first.txt");

  cout<<endl;
  sleep(1);
  cout<<"\t\t TASK DELETED SUCCESSFULLY"<<endl;
  cout<<endl;
  sleep(1);
  cout<<""<<endl;
  return 1;
  
}


int main() {
  
  cout<<endl;
  cout<<"\t\t\t WELCOME TO YOUR TODO LIST"<<endl;
  cout<<endl;
  cout<<"\n ";
  sleep(1);
  
  if_wrong:

  cout<<"\n \n";
  cout<<"CHOOSE A OPTION "<<endl;
  cout<<endl;
  
  sleep(1);
  cout<<"1. ADD NEW TASK"<<endl;
  cout<<"2. VIEW TASK"<<endl;
  cout<<"3. COMPLETE THE TASK"<<endl;
  cout<<"4. REMOVE TASK"<<endl;
  cout<<"0. EXIT"<<endl;
  cout<<endl;
  sleep(1);
  int option;
  cout<<"ENTER YOUR CHOICE "<<endl;
  cin>>option;

  
  int result=0;
  switch(option){
    
    case 1:
    result=add_new();
    break;

    case 2:
    result=view();
    break;

    case 3:
    result=complete();
    break;

    case 4:
    result=remove();
    break;

    case 0:
    break;

    default:
    cout<<"WRONG INPUT \n PLEASE FILL VALID INPUT"<<endl;
    cout<<"_"<<endl;
    cout<<endl;
    goto if_wrong;    // if input is wrong go to line 18
  }

  if(result ==1){
    goto if_wrong;
  }
  
  cout<<"\t\t\t YOUR TODO LIST HAS BEEN UPDATED SUCCESSFULLY";

}
