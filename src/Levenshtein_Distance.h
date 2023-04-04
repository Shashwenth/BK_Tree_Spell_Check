#include"Node.h"
int Levenshtein_Distance(string String_1, string String_2){
	
	
	int x = String_1.size();
	int y = String_2.size();
	
	int Leven_Matrix[x+1][y+1];
	
	
    int i=0;
    while(i<=x){
        Leven_Matrix[i][0]=i;
        i++;
    }
    int j=0;
    while(j<=y){
        Leven_Matrix[0][j]=j;
        j++;
    }
	i=1;	
	while(i<=x){
        j=1;
		while(j<=y){
			if(String_1[i-1]==String_2[j-1]){
			Leven_Matrix[i][j]=mini(Leven_Matrix[i-1][j-1],Leven_Matrix[i-1][j],Leven_Matrix[i][j-1]);
			}
			else{
			Leven_Matrix[i][j]=(mini(Leven_Matrix[i-1][j-1],Leven_Matrix[i][j-1],Leven_Matrix[i-1][j])+1);	
			}
            j++;
			
		}
        i++;
	}	
	return Leven_Matrix[x][y];
}


void Insert_In_Tree(string word, string WordAtRoot, Node *node){
	int Lev_DIstance;
	Node *temp = new Node;
	Lev_DIstance = Levenshtein_Distance(word,WordAtRoot);
	
	if(node->i[Lev_DIstance]==NULL){
			Node *nWord = new Node;
			node->i[Lev_DIstance]=nWord;
			nWord->data=word;
			}
		else{
			temp=node->i[Lev_DIstance];
			Insert_In_Tree(word, temp->data, temp);		
			}
	
}
