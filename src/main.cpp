//#include"Node.h"
#include"head.h"

int main(){
	
	Node *root = new Node;	
	int choice;
	string w_1, word_ip, sentence_ip;
	Insert_In_Root("AA", root);
	ifstream my_file ("words.txt");
	  if (my_file.is_open()){
    	while ( getline (my_file,w_1)){
      	Insert_In_Tree(w_1, root->data, root);
    	}
    	my_file.close();
  	}

  		else{
			 cout << "Unable to open the file"; 
		}
	while(true){
		cout<<"Select one option :\n1. Check if word exists in the dictionary";
		cout<<"\n2. Correct a Word\n3. Correct a sentence\n4. Exit\n\n Enter Your Choice : ";
		cin>>choice;

        if(choice==1){
			auto start = high_resolution_clock::now();
            cout<<"\nEnter the word to search : ";
				cin>>word_ip;
				transform(word_ip.begin(), word_ip.end(), word_ip.begin(),::toupper);
				Count_temp=0;
				searchWord(word_ip,"AA",root);
					if(Count_temp!=0)
						cout<<endl<<"This word is present"<<endl;
					else
						cout<<endl<<"This word is not available"<<endl;
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
        }
        else if(choice==2){
			auto start = high_resolution_clock::now();
            cout<<"\nEnter the word to be corrected : ";
				cin>>word_ip;
				transform(word_ip.begin(), word_ip.end(), word_ip.begin(),::toupper);
				Count_temp=0;
				searchWord(word_ip,"AA",root);
				if(Count_temp==0){
				cout<<"The suggestions: \n\n";
					Spelling_Find(word_ip,"AA",root);
				}
				else
					cout<<"The word already exists ";
					
				if(c1==0){
						cout<<endl<<"No Suggestions";
					}
				auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "\n\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
				
        }

        else if(choice==3){
			auto start = high_resolution_clock::now();
              fflush(stdin);
				cout<<"Enter the sentence (Terminate with a full stop) : ";
				fflush(stdin);
				getline(cin,sentence_ip);
				Sentence_Correct(sentence_ip, root);
				auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
				   
        }

        else if(choice==4){
			
                exit(0);
        }
        else{
            cout<<"Enter a Valid option";
        }
		
    
		cout<<"\n\n";	
        continue;
	}
	
	getch();
	return 0;
}