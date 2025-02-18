#include<iostream>
using namespace std;
int main(){
    int n;
    string choice;
    do{
    
    
    cout<<"bta bhai konsi table likhwana chahta h? ";
    cin>>n;
    cout<<"le bhai..."<<endl;
    
    for(int i=1;i<=10;i++){
        
        cout<<i*n<<endl;
    }
    cout<<"orr bta bhai ,or kosi krwani ho toh ? krwani h toh likh 'haa' :";
    cin>>choice;
    if(choice=="haa"){
        cout<<"";
    }
    else if(choice=="naa"){
        break;
    }
    else{
        cout<<"haa ya naa likh bs ";
    }
    

}
while(choice=="haa");}
