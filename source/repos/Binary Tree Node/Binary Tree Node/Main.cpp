#include "BinaryTree.cpp"
#include <filesystem>
#include <iostream>
#include <string>
using namespace std;
namespace fs = std::experimental::filesystem;


int main(int argc, char** argv)
{
	/*
	fs::path p = argv[1];
	
	string d[6];

	d[0] = p.generic_string();
	for (auto& e : p)

	
	cout << d[0] << endl << d[1] << endl << d[2];*/

	string d[6] = { "Example", "Ex 1", "Ex 2", "S1.txt", "S2.txt", "S3.txt" };

	BinaryTree<string> t;
	BinaryTree<string>::Position p = t.root();
	p = t.root();

	for (int i = 0; i < 6; i++)
		t.insert(d[i], p);

	BinaryTree<string>::PositionList list = t.Positions();
	for (BinaryTree<string>::PositionList::Iterator i = list.begin(); i != list.end(); ++i)
		cout << **i << endl;

	return 0;
}