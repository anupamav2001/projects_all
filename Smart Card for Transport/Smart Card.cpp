#include<iostream>
#include<string.h>
using namespace std;
class user{                                             //class of customer
    char userid[5], name[20], phoneno[15], email[30];
    public:
        void getuserdetails();      //get user details
        void upduser();                 //update a users details
};



/*
float function(finaldest of the customer whos on the bus)
{

    totalprice=0;
    while(strcmp(linkedlist->busstand,fd)!=0)
    
   {
       if not ==0               so each bus stand has a distance to next stand
        i++                                                                 A->B = 5km formula 5/2*bp+10; ??   
        totalprice+=distance*bp*sadasdnada ?? idk the formula :D
        ll->next;
        
        
   }
        if ==0 
        i++ 
        break; 
    i=stops that u went thru
    then basepay*i = price of travel ?
    
    means stops are equal in price
    or
    ll->distance
    formula
    
    return totalprice;
}
*/


class bus{
    
    char busid[8]; 
    int capacity;
    float bp;                                   //base price of bus
    
struct route
{                               //structure of route linked list
  char busstand[20];                   
   float dist;
   struct route *next;
    }*start=NULL;                   //starting bus stop=null


    
    
    public:
            void addbus();                  //get bus details
        /*
            void updroutedetails();                //update a route's details
            void updbusdetails();
    */
    
    
    
    
void insert(struct route **start, char newstop[], float distance) 
{                                                                                           //insert function for route 

   struct route* new_node = (struct route*) malloc(sizeof(struct route));
   strcpy(new_node->busstand,newstop);
   new_node->dist=distance;
   new_node->next = NULL;
     if((*start)==NULL)                      //
     {
        (*start) = new_node;                
     }
     else
     {
          struct route* temp = (struct route*) malloc(sizeof(struct route));
          temp=(*start);
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=new_node;
          
     }
   
}

void display(struct route **head)                           // testing linked list of route
{
    if((*head)==NULL)
    printf("\nRoute is empty\n");
    else                                                //displaying all elements in sll
    {
        struct route* temp=(struct route*)malloc(sizeof(struct route));
        temp=(*head);                               
        while(temp!=NULL)
        {
            printf("\n%s\n%f\n",temp->busstand,temp->dist);
            temp=temp->next;
        }
    }
}                                                   
    
    
    
    
    
};          //end of class bus




/* class payment : private user, private route{
  char cno[16],cname[15],cvv[5],expiry[8];
  float price;
  public:
        void calcpay();                     //calculate the payment price
        void getpaydetails();               //get payment details for each user
    
};
*/



void user::getuserdetails(){
    cout<<"Enter the details of the card holder\n";
    cout<<"Enter id: ";
    cin>>userid;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter phone number: ";
    cin>>phoneno;
    cout<<"Enter email: ";
    cin>>email;
    cout<<"\n\nUser added!\n";
}


void bus::addbus(){
    cout<<"Enter the details of the bus\n";
    cout<<"Enter bus id: ";
    cin>>busid;
    cout<<"Enter capacity of the bus: ";
    cin>>capacity;
    cout<<"Enter base price of bus: ";
    cin>>bp;
    int no;
    cout<<"Enter no. of bus stops";
    cin>>no;
    for(int i=0;i<no;i++)
    {
        char busstop[20];
        float distance;
        cin>>busstop>>distance;
        insert(&start,busstop,distance);
    }
    display(&start);
    
     cout<<"\n\nBus and route added!\n";
}




int main(){
    user u[3];
    bus b[3];
    char j;
    
    /*
    fstream user;
    fstream bus;
    user.open("user_details.txt", ios::binary | ios::app); 
    bus.open("bus_details.txt", ios::binary | ios::app);
    
    */
    
    
    int ui=0,bi=0,ch;
    do{
        cout<<"1. Add user details\n";
        cout<<"2. Add bus and route details\n";
        cout<<"3. Add payment details of user\n";    
        cout<<"Choose an option: ";
        cin>>ch;
        switch(ch){
            case 1: u[ui].getuserdetails();          //to get customer details
                      
             /*      
                    user.write(&u[ui], sizeof(class user));
                     
                    
            */      ui++; 
                    break;
           
            case 2: b[bi].addbus();                 //to get bus details
                    
                    
          /*
          
                     bus.write(&b[bi], sizeof(class bus)); 
          
          
          */        bi++;
                    break;
             /*
            case 3: payment 
            case 4: 
            case 5:
            case 6:
            */
            default: cout<<"Wrong option\n";       
        }
        
        cout<<"Do you want to continue?(y/n)";
        cin>>j;
    }while(j=='y');                             //infinite loop until stopped
    
    
    user.close();
    bus.close();
    return 0;
}