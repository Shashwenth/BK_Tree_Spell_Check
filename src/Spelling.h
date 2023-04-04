#include"Levenshtein_Distance.h"
void Spelling_Find(string word, string WordAtRoot, Node *node){
	int Lev_DIstance;
	Lev_DIstance = Levenshtein_Distance(word,WordAtRoot);
	if(Lev_DIstance==0){
		c1++;
		if(c1==1){
			c2++;
		}
		cout<<WordAtRoot<<"\t";
	}
	
	else if(Lev_DIstance==1){
		Node *temp = new Node;
		Node *temp2 = new Node;
		c1++;
		if(c1==1){
			c2++;
		}
		cout<<WordAtRoot<<"\t";
		
		if(node->i[1]!=NULL){
            if(node->i[2]!=NULL)
            {
			temp = node->i[1];
			temp2 = node->i[2];
			Spelling_Find(word, temp->data, temp);
			counter++;
			Spelling_Find(word, temp2->data, temp2);
			counter++;	
            }
            else{
            temp = node->i[1];
			Spelling_Find(word, temp->data, temp);
			counter++; 
            }
		}
		else if(node->i[1]==NULL && node->i[2]!=NULL){
			temp2 = node->i[2];
			Spelling_Find(word, temp2->data, temp2);	
			counter++;
		}
	}
	
	else{
		Node *temp1 = new Node;
		Node *temp2 = new Node;
		Node *temp3 = new Node;
		
		if(node->i[Lev_DIstance-1]!=NULL){
            if(node->i[Lev_DIstance]!=NULL)
            {	
			    if(node->i[Lev_DIstance+1]!=NULL){
                temp1=node->i[Lev_DIstance-1];
			    temp2=node->i[Lev_DIstance];
			    temp3=node->i[Lev_DIstance+1];
			    Spelling_Find(word, temp1->data, temp1);
			    counter++;
			    Spelling_Find(word, temp2->data, temp2);
			    counter++;
			    Spelling_Find(word, temp3->data, temp3);
			    counter++;
            }
            else if(node->i[Lev_DIstance+1]==NULL){
                temp1=node->i[Lev_DIstance-1];
			    temp2=node->i[Lev_DIstance];
			    Spelling_Find(word, temp1->data, temp1);
			    counter++;
			    Spelling_Find(word, temp2->data, temp2);
			    counter++;
            }
            }
            else if(node->i[Lev_DIstance]==NULL){
                if(node->i[Lev_DIstance+1]!=NULL){
                    temp1=node->i[Lev_DIstance-1];
			        temp3=node->i[Lev_DIstance+1];
			        Spelling_Find(word, temp1->data, temp1);
			        counter++;
			        Spelling_Find(word, temp3->data, temp3);
			        counter++;
                }
                else if(node->i[Lev_DIstance+1]==NULL){
                    temp1=node->i[Lev_DIstance-1];
			        Spelling_Find(word, temp1->data, temp1);
			        counter++;
                }
            }
		}
        else if(node->i[Lev_DIstance-1]==NULL){
            if(node->i[Lev_DIstance]!=NULL){
                if(node->i[Lev_DIstance+1]!=NULL){
                    temp2=node->i[Lev_DIstance];
			        temp3=node->i[Lev_DIstance+1];
			        Spelling_Find(word, temp2->data, temp2);
			        counter++;
			        Spelling_Find(word, temp3->data, temp3);
			        counter++;
                }
                else if(node->i[Lev_DIstance+1]==NULL){
                    temp2=node->i[Lev_DIstance];
			        Spelling_Find(word, temp2->data, temp2);
			        counter++;
                }
            }
            else if(node->i[Lev_DIstance]==NULL){
                if(node->i[Lev_DIstance+1]!=NULL){
                    temp3=node->i[Lev_DIstance+1];
			        Spelling_Find(word, temp3->data, temp3);
			        counter++;
                }
            }
        }
	}
	
}
