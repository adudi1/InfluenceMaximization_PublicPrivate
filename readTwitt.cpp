#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
string rf = "";
string wf = "";
cout<<"enter read filename"<<endl;
getline(cin, rf);
wf = "use"+rf;
ofstream myfile;
myfile.open(wf);

ifstream readfile;
readfile.open(rf);
unordered_map<long long, long long> mapping;
string sfrom="";
long long from =0;
long long to = 0;
  if (readfile.is_open())
    {
      while(readfile>>from) //getline(readfile, sfrom))
        {
		readfile >> to;
		if(mapping.find(from)== mapping.end()){
			mapping[from] = mapping.size()+1;
		}
		if(mapping.find(to)== mapping.end()){
                        mapping[to] = mapping.size()+1;
		}
		if(readfile.peek()=='\n')
            		readfile.ignore(10,'\n');
		if(from != to)	
			myfile<<mapping[from]<<" "<<mapping[to]<<"\n"; 	
        }
      readfile.close();
    }
  else
    {
      cout << "Error opening file";
    }
	myfile.close();

return 0;


}

