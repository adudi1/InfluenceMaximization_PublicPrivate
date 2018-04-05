#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
srand(time(NULL));
long nodes=0;
long edges=0;
string fn = "";
int percent = 0;
cout<<"enter filename, nodes, edges, \% private"<<endl;
cin >> fn;
cin >> nodes;
cin >> edges;
cin >> percent;

ofstream myfile;
myfile.open(fn);
unordered_map<long, unordered_set<long> > adjList;
unordered_map<long, unordered_map<long, unordered_set<long> > > privategraphs;

long edgeCount = edges;
while(edges){
	long u = rand()%nodes+1;
	long v = rand()%nodes+1;
	if(u==v || adjList[u].find(v) != adjList[u].end())
 		continue;
    	adjList[u].insert(v);
	//myfile <<u<<" "<<v<<"\n";
	edges--; 
}
/*
long x = nodes*0.4;
for(long i = 0; i < x; i++){
	long u = rand()%nodes+1;
	if(adjList.find(u) != adjList.end())
	for(unordered_set<long>::iterator it = adjList[u].begin(); it != adjList[u].end();it++){
		double d = (double)rand()/RAND_MAX;
		if(d < 0.75){
			privategraphs[u][u].insert(*it);
			privategraphs[*it][u].insert(*it);
			if((double)rand()/(double)RAND_MAX < 0.4){
				if(adjList.find(*it) != adjList.end() && !adjList[*it].empty())
				{	
					unordered_set<long>::iterator iter = adjList[*it].begin();
					privategraphs[u][*it].insert(*iter);
					privategraphs[*it][*it].insert(*iter);
					adjList[*it].erase(iter);
					edgeCount--;			
				}
			}
			unordered_set<long>::iterator it1 = it++;	
			adjList[u].erase(it1);
			edgeCount--;
		}else{
                	it++;
		}
		cout<<"forend"<<endl;	
	}

}

myfile<<nodes<<" "<<edgeCount<<"\n";

for(long i=1;i <= nodes;i++){
	if(adjList.find(i) != adjList.end())
	for(unordered_set<long>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
		myfile<<*it<<" ";	
	}
	myfile<<"\n";
}

myfile.close();

ofstream myfilepriv;
myfilepriv.open("private"+fn);
for(long i=1;i <= nodes;i++){
	myfilepriv<<"#"<<i<<"\n";
	if(privategraphs.find(i) != privategraphs.end())
        for(unordered_map<long, unordered_set<long> >::iterator it = privategraphs[i].begin(); it != privategraphs[i].end(); it++){
                myfilepriv<<it->first<<" ";
		for(unordered_set<long>::iterator iter = it->second.begin(); iter != it->second.end(); iter++){
			myfilepriv<<*iter<<" ";
		}
		myfilepriv<<"\n";
        }
        //if(adjList[i].empty())
        myfilepriv<<"\n";
}
myfilepriv.close();
return 0;
------------------------------------------------------------------------
*/

std::random_device rd;
std::mt19937 g(rd());
vector<long> s(nodes);
std::iota( std::begin(s), std::end(s), 1);
shuffle(s.begin(), s.end(), g);

double p = (double)percent/100.0;
long x = (double)nodes*p;
for(long i = 0; i < x; i++){
	long u = s[i];
	if(adjList.find(u) != adjList.end())
	for(unordered_set<long>::iterator it = adjList[u].begin(); it != adjList[u].end();){
		double d = (double)rand()/RAND_MAX;
		if(d <=0.75){
			privategraphs[u][u].insert(*it);
			privategraphs[*it][u].insert(*it);
			if((double)rand()/(double)RAND_MAX <=0.9){
				if(adjList.find(*it) != adjList.end() && !adjList[*it].empty())
				{	
					unordered_set<long>::iterator iter = adjList[*it].begin();
					privategraphs[u][*it].insert(*iter);
					privategraphs[*it][*it].insert(*iter);
					adjList[*it].erase(iter);
					edgeCount--;			
				}
			}
		unordered_set<long>::iterator it1 = it++;	
			adjList[u].erase(it1);
			edgeCount--;
		}
		else{
			it++;
		}
		
	}

}

myfile<<nodes<<" "<<edgeCount<<"\n";

for(long i=1;i <= nodes;i++){
	if(adjList.find(i) != adjList.end())
	for(unordered_set<long>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++){
		myfile<<*it<<" ";	
	}
	myfile<<"\n";
}

myfile.close();

ofstream myfilepriv;
myfilepriv.open("private"+fn);
for(long i=1;i <= nodes;i++){
	myfilepriv<<"#"<<i<<"\n";
	if(privategraphs.find(i) != privategraphs.end())
        for(unordered_map<long, unordered_set<long> >::iterator it = privategraphs[i].begin(); it != privategraphs[i].end(); it++){
                myfilepriv<<it->first<<" ";
		for(unordered_set<long>::iterator iter = it->second.begin(); iter != it->second.end(); iter++){
			myfilepriv<<*iter<<" ";
		}
		myfilepriv<<"\n";
        }
        //if(adjList[i].empty())
        myfilepriv<<"\n";
}
myfilepriv.close();
return 0;

}
