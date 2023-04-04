#include<string>
#include<iostream>
#include<stdio.h>
int counter=0, c1=0, c2=0;
using namespace std;

struct Node{
	string data;
	struct Node *i[11] = {NULL};
};



int mini(int a, int b, int c){
		if(a<=b && a<=c) return a;
        else if(b<=a && b<=c) return b;
		return c;
}


void Insert_In_Root(string word, Node *root){
	root->data = word;
}

