#include <iostream>
#include "leveldb/db.h"

int main(int argc,char *argv[]){
	using std::cout;
	using std::endl;
	using std::cerr;
	
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);
	if (!s.ok()) cerr << s.ToString() << endl;
	if (s.ok()) s = db->Put(leveldb::WriteOptions(),"testkey1", "testvalue1");
	if (!s.ok()) cerr << s.ToString() << endl;	
	std::string value;
	if (s.ok()) s=db->Get(leveldb::ReadOptions(), "testkey1", &value);
	if (!s.ok()) cerr << s.ToString() << endl;	

	cout<<"get key testkey1:"<<value<<endl;
}












