#include<bits/stdc++.h> 
#include<queue>
#include<vector>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int d):data(d),left(NULL),right(NULL){
		}
};
node* InsertInBst(node* root,int data){
	if(root==NULL){
		root=new node(data);
		return root;
	}
	if(root->data<=data){
		root->right=InsertInBst(root->right,data);
	}
	else{
		root->left=InsertInBst(root->left,data);
	}
	return root;
}
node* CreateTree(vector<int>v){
	node* root=NULL;
	for(int i=0;i<v.size();i++){
		root=InsertInBst(root,v[i]);
	}
	return root;
}
node* SearchInBst(node* root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	else if(root->data>key){
		return SearchInBst(root->left,key);
	}
	else{
		return SearchInBst(root->right,key);
	}
}
class item{
	string brand;
	int price;
	public:
		item(string s,int p){
			brand=s;
			price=p;
		}
		string getbrand(){
			return brand;
		}
		int getprice(){
			return price;
		}
};
void Print(queue<item>q){
	while(!q.empty()){
		item i=q.front();
		cout<<i.getbrand()<<"-->"<<i.getprice()<<endl;
		q.pop();
	}
	cout<<endl;
}
void clean(queue<item>q){
	while(!q.empty()){
		q.pop();
	}
}
//void PrintOriginal(vector<item>v){
//	for (auto it = v.begin(); it != v.end(); it++){
//        cout << *it <<" "; 
//	}
//	cout<<endl;
//}
int assign(string key){
	if(key=="Titan"){
		return 1;
	}
	else if(key=="Timex"){
		return 2;
	}
	else if(key=="Fastrack"){
		return 3;
	}
	else if(key=="Casio"){
		return 4;
	}
	else if(key=="Fossil"){
		return 5;
	}
}
class Selection{
	queue<item>desired;
    queue<item>undesired;
	queue<item>no_change;
	public:
	void select_brand(vector<item>original,vector<int>v1,int n,int prec,string choice,node* root){
        if(choice=="NO"){
        	cout<<"THIS BRAND AVAILABE RELATED TO THE OBJECTS : "<<endl;
        	for(int i=0;i<n;i++){
        		no_change.push(original[i]);
			}
			Print(no_change);
		}
		if(choice=="YES"){
			node* temp=SearchInBst(root,prec);
			for(int i=0;i<n;i++){
        	    if(temp->data==v1[i]){
        		    desired.push(original[i]);
			    }
			    else{
				    undesired.push(original[i]);
			    }
		    }
		    clean(undesired);
		    cout<<"SELECTED BRAND : "<<endl; 
		    Print(desired);
	    }
	}		
};
int main(){
	item i1("Titan",100);
	item i2("Timex",300);
	item i3("Titan",200);
	item i4("Timex",500);
	item i5("Titan",400);
	item i6("Timex",700);
	item i7("Fastrack",600);
	item i8("Timex",900);
	item i9("Titan",800);
	item i10("Timex",1100);
	item i11("Fastrack",1000);
	item i12("Casio",1300);
	item i13("Timex",1200);
	item i14("Titan",1500);
	item i15("Timex",1400);
	item i16("Titan",1700);
	item i17("Fastrack",1600);
	item i18("Timex",1900);
	item i19("Titan",1800);
	item i20("Timex",2100);
	item i21("Casio",2000);
	item i22("Casio",2300);
	item i23("Fossil",2200);
	item i24("Fossil",2500);
	vector<item>original;
	original.push_back(i1);
	original.push_back(i2);
	original.push_back(i3);
	original.push_back(i4);
	origina l.push_back(i5);
	original.push_back(i6);
	original.push_back(i7);
	original.push_back(i8);
	original.push_back(i9);
	original.push_back(i10);
	original.push_back(i11);
	original.push_back(i12);
	original.push_back(i13);
	original.push_back(i14);
	original.push_back(i15);
	original.push_back(i16);
	original.push_back(i17);
	original.push_back(i18);
	original.push_back(i19);
	original.push_back(i20);
	original.push_back(i21);
	original.push_back(i22);
	original.push_back(i23);
	original.push_back(i24); 
	vector<int>v1;
	for(int i=0;i<24;i++){
		int t=assign(original[i].getbrand());
		v1.push_back(t);
	}
	node* root=CreateTree(v1);
	Selection s1;
	string s="Titan";
	int p=assign(s);
	int r=original.size();
    s1.select_brand(original,v1,r,p,"YES",root);
	return 0;
}
