#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<string, float> mapType;
    mapType populationMap;

    populationMap.insert(pair<string, float>("Maharashtra", 12));
    populationMap.insert(pair<string, float>("Goa", 8));
    populationMap.insert(pair<string, float>("Uttar Pradesh", 15));
    populationMap.insert(pair<string, float>("Bengal", 4));
	
	mapType::iterator iter= --populationMap.end();
	//populationMap.erase(iter);	

    for (iter = populationMap.begin(); iter != populationMap.end(); iter++)
    {
        cout << iter->first << "\t : " << iter->second << endl;
    }


	string state;
	cout<<"Enter name of state: ";
	cin >> state;
	iter=populationMap.find(state);
	if(iter != populationMap.end()){
		cout<<"Population of " << state << " is " << iter->second <<endl;
	}
	else
			cout<<"State not found in the list! :( "<<endl;


    return 0;
}
