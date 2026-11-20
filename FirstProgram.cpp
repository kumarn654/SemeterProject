#include<iostream>
#include<cstdlib> // just to use exit(0) thats why this library is included
#include<string>
using namespace std;
int count = 0;
class Node{
    public:
    string data;
    int weight;
    Node* next;
    

};
const int v = 6;
const int MAX = 100;
string cities[v] = {"Karachi","Makli","Hyderbad","Thana Bula Khan","Thatta","Mithi"};
Node* adj[v]= {NULL};


// void userDetails(){
//     system("cls");
//     cout<<"User Details"<<endl;
//     // The purpose of the user detaisl is to get user route history
//     int id;
//     string password;
//     string confiromPassword;

//     cout<<"Enter the user id:";
//     cin>>id;
//     cout<<endl;
//     cout<<"Password:";
//     cin>>password;
//     cout<<endl;
//     cout<<"Confirom Password:";
//     cin>>confiromPassword;
//     if(password == confiromPassword){
//         showMenu();
//     }else{
//         cout<<"Wrong Password! Enter Again"<<endl;
//         userDetails();
//     }

// }


void BuildGraph(int u,int  v,int weight){
    Node* newNode = new Node;
    newNode->data = cities[u];
    newNode->weight = weight;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void insert(int u,int v,int weight){
    BuildGraph(u,v,weight);
    
    BuildGraph(v,u,weight);
}
void addEdge(){
    insert(0,1,70);
    insert(1,2,100);
    insert(1,4,3);
    insert(4,5,250);
    insert(0,3,100);
    insert(2,3,50);

}
void removeEdge(int vertex,string value){
    Node* temp = adj[vertex];
    Node* prev = NULL;
    
    while(temp!=NULL && temp->data!=value){
        prev = temp;
        temp = temp->next;

    }

    if(temp == NULL){
        return;
    }

    if(prev == NULL){
        adj[vertex] = temp->next;
    }else{
        prev->next = temp->next;
    }

    delete temp;
}

void displayAllCityRoutes(){
    for(int i=0;i<v;i++){
        cout<<cities[i]<<":";

        Node* temp = adj[i];
        while(temp!=NULL){
            cout<<temp->data<<" "<<temp->weight<<" Km -> ";
            temp = temp->next;
        }
        cout<<" NULL"<<endl;

        
    }
}

// void showMenu(){
//     system("cls");
//     cout<<"City Route Planner"<<endl;

    // cout<<"Menu of City Route"<<endl;

    // cout<<"1: Location of City"<<endl;
    // cout<<"2: Search City"<<endl;
    // cout<<"3: Display All Cities"<<endl;
    // cout<<"4: Logout"<<endl;


//     int num;
//     cout<<"Enter the Choice:";
//     cin>>num;
//     cout<<endl;

//     if(num < 0 && num > 5){
//         cout<<"Invalid Choice!"<<endl;
//     }

//     if(num == 1){
//         shortest distance  dijakis algorithms
//     }else if(num == 2){
//         // hamza part
//         // search city 
//     }


// }


int main(){
        addEdge();
        AllPossibleRoutes(0,1);
    
//     cout<<"City Route PLanner"<<endl;
//     cout<<endl;
//     cout<<"Uset Authentification"<<endl;
//     cout<<endl;
//     int num;

//     cout<<"1: Login the Sytem"<<endl;
//     cout<<"2: Route History"<<endl;
//     cout<<"3: Exit"<<endl;
    
//     cout<<"Enter the number:";
//     cin>>num;
//     if(num < 0 && num < 4){
//         if(num == 1){
//            userDetails(); 
           

//         }else if(num == 2){
//             // kabeer Part
//             // routeHistory();
//         }else if(num == 3){
//             cout<<"Exit the Program"<<endl;
//             exit(0);
//         }else{
//             cout<<"No Service is available"<<endl;
//         }
//     }else{
//         cout<<"Invalid Choice!"<<endl;
//     }




    

    return 0;
}