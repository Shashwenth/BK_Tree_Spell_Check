#include<conio.h>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<string>
#include<algorithm>
//#include"Node.h"
#include <chrono>
using namespace std::chrono;
#include"Spelling.h"
using namespace std;


int Count_temp=0;

void searchWord(string word, string WordAtRoot, Node *node){
	int Lev_DIstance;
	Node *temp = new Node;
	Lev_DIstance = Levenshtein_Distance(word,WordAtRoot);
	
	if(Lev_DIstance==0){
		Count_temp++;
	}
	else{
		if(node->i[Lev_DIstance]!=NULL){
			temp = node->i[Lev_DIstance];
			searchWord(word, temp->data, temp);
		}
	}
}

void Sentence_Correct(string sentence_ip, Node *node){
		int i=0;
		transform(sentence_ip.begin(), sentence_ip.end(), sentence_ip.begin(),::toupper);
		int checker;
		string temp_word;
		for(i=0;i<sentence_ip.length();i++){
			if(sentence_ip[i]!=' ' && sentence_ip[i]!='.'){
				temp_word+=sentence_ip[i];
				//cout<<" Inside the first if: "<<temp_word<<"\n";
			}
			else{
		
			    searchWord(temp_word, "AA", node);
			    if(Count_temp==0){
			   		cout<<endl<<temp_word<<"\t\t---\t";
					//cout<<" Inside the else first if: "<<temp_word<<"\n";
			    	Spelling_Find(temp_word,"AA",node);
				}
				else{
					cout<<endl<<temp_word;
					//cout<<" Inside the else else: "<<temp_word<<"\n";
				}
				Count_temp=0;
			    temp_word.clear();
			}
		}
    	
}
