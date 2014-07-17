#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int,string> fun(const string& str)
{
	vector<string> substrs;
	int maxcount=1,count=1;
	string substr;
	int i,len=str.length();
	for(i=0;i<len;++i)
		substrs.push_back(str.substr(i,len-i));
	for(i=0;i<len;++i)
	{
		for(int j=i+1;j<len;++j)
		{
			count=1;

			cout<<"i:"<<i<<",j:"<<j<<endl;
			cout<<"substrs[i]:"<<substrs[i]<<endl;
			cout<<"substrs[i].substr(0,j-1):"<<substrs[i].substr(0,j-1)<<endl;
			cout<<"substrs[j]:"<<substrs[j]<<endl;
			cout<<"substrs[j].substr(0,j-1):"<<substrs[j].substr(0,j-1)<<endl;

			if(substrs[i].substr(0,j-1)==substrs[j].substr(0,j-1)){
				++count;
				for(int k=j+(j-1);k<len;k+=j-i){
					if(substrs[i].substr(0,j-i)==substrs[k].substr(0,j-i))
						++count;
					else
						break;
				}
				if(count>maxcount){
					maxcount=count;
					substr=substrs[i].substr(0,j-1);
				}
			}
		}
	}
	return make_pair(maxcount,substr);
}

int main(){
	string str;
	pair<int,string> rs;
	while(cin>>str){
		rs=fun(str);
		cout<<rs.second<<':'<<rs.first<<'\n';
	}
	return 0;
}