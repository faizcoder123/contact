#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 	
	
	bool isterminal; 
    map<char,Node*> child;
	Node() 
	{ 
	  for (char i = 'a'; i <= 'z'; i++) 
			child[i] = NULL; 

		isterminal = false; 
	
	} 
}; 

Node *root = NULL; 



void display(Node *cur, string s) 
{ 

	if (cur->isterminal) {
	
		cout << s << "\n";
		
  }

	
	for (char i = 'a'; i <= 'z'; i++) 
	{ 
		Node *nextNode = cur->child[i]; 
		if (nextNode != NULL) 
			display(nextNode, s + (char)i); 
	} 
} 


void displayContacts(string s) 
{ 
	Node *cur= root; 
		 
	int i; 
	int flag=0;
	Node *next =NULL;
	for (i=0; i<s.length(); i++) 
	{ 
		next = cur->child[s[i]]; 		 
		if (next == NULL) 
		{   flag=1;
		    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			cout << "No Results Found for this contact --"<<s<< "\n"; 
			cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<"\n";
			break; 
		} 
		cur=next;
     }   
	 if(!flag){
		cout<<"=====================================================\n";
		cout << "Suggestions based on this contact"<<s<<"are----"<<"\n"; 
		display(next, s); 
		cout<<"=====================================================\n";
	
	   } 	
}


void insert(string s) 
{ 
	
	Node *itr = root; 
	
	for (int i = 0; i < s.length(); i++) 
	{ 
		
		Node *nextNode = itr->child[s[i]]; 
		if (nextNode == NULL) 
		{ 
			nextNode = new Node(); 

			itr->child[s[i]] = nextNode; 
		} 

		  itr = nextNode; 
    }
	
		  itr->isterminal = true; 
} 
 


void insertIntoTrie(string contacts[],int n) 
{ 
	for (int i = 0; i < n; i++) 
		insert(contacts[i]); 
} 
 
int main() 
{ 
    root=new Node();
    cout<<"------------------------------------------------------------"<<"\n";
    cout<<"\n\n";
	int n;
	cout<<"No. Of Contact Want To Insert"<<"\n";
	cin>>n;
	string contacts[n+1];
	cout<<"============================================================="<<"\n";
	cout<<"Insert All Contacts Want To Add \n";
	for(int i=0;i<n;i++){
//	     cin.ignore();
//	     getline(cin,contacts[i]);
          cin>>contacts[i];
        // cout<<contacts[i]<<"\n";
		}  
		
	insertIntoTrie(contacts, n); 
	
	 int q;
     cout<<"============================================================="<<"\n";	
     cout<<"N0. of queries\n";
     cin>>q;
	 cout<<"============================================================="<<"\n";
    while(q--){
	    string search;
//	    getline(cin,search);
        cin>>search;
	    displayContacts(search);
	    cout<<"========================================================\n";
      }
	return 0; 
} 

