#include <iostream>
#include<string>
#include <fstream>
#include <cstring>
#include<ctime>
#include<map>
using namespace std;

	
void createAccount();
int login();
int Users();
int main();
int Admin();
int get_route();
void viewinfo();
void Admin_Operations();
// void viewpassenger();
void addtrain();
void deletetrain();
void deletetrain();
void bookticket_write();
void bookticket();

int u = 0;

//------------------Struct Train----------------
struct Train{
	
	char train_number[20];
	string train_name;
	string Leaving ;
	string destination;
	double price;
	int seat;
	string time;
	Train*next=NULL;
	//Train*prev=NULL;
}add[1000];

Train *firsttrain=NULL;

Train *lasttrain=NULL;
//---------Add Train method------------------
void addtrain(){
    int i;
    Train*temp = new Train;
    cout<<"\nEnter Train name: ";
    cin>>temp->train_name;
    // cout<<"\nEnter Train number: ";
    // cin>>temp1->train_number;
    cout<<"\nLeaving At: ";
	cin>>temp->Leaving;
    cout<<"\nDestination At: ";
	cin>>temp->destination;
    cout<<"\nprice: ";
	cin>>temp->price;
    cout<<"\nTime : ";
	cin>>temp->time;
    cout<<"\nSeat: ";
	cin>>temp->seat;
	cout<<"\nTrain is added successfully!";
     //----------INSERTION OCCURS-------------
      if(firsttrain == NULL){
          firsttrain = lasttrain = temp;
          add[i++];
      }
      else{
          lasttrain->next = temp;
          lasttrain = temp;
          add[i++];
      }
}
//------------------Display the train method---------------
void displayTrain(){
	Train  *t1=new Train;
	Train  *t2=new Train;
	Train  *t3=new Train;
	cout<<"Train Details\n";
	t1->train_name="ShaheenExpress\n";
	t1->Leaving="Islamabad\n";
	t1->destination="Faisalabad\n";
	t1->price= 456;
	t1->time="10:30\n";
	t1->seat=67;
    add[1];
	
	t2->train_name="Iqbal Express\n";
	t2->Leaving="Islamabad\n";
	t2->destination="Faisalabad\n";
	t2->price=456;
	t2->time="10:30\n";
	t2->seat=67;
    add[2];
	
	t3->train_name="Tezgam\n";
	t3->Leaving="Islamabad\n";
	t3->destination="Faisalabad\n";
	t3->price=456;
	t3->time="10:30\n";
	t3->seat=67;
    add[3];
	if(firsttrain==NULL){
		firsttrain=lasttrain=t1;
		lasttrain->next=t2;
		t1->next=t2;
		t2->next=t3;
		lasttrain=t3;
	}
	else {
		lasttrain->next=t1;
		t1->next=t2;
		t2->next=t3;
		lasttrain=t3;
		lasttrain->next=NULL;
	}
    int i = 0;
    Train*temp1 = new Train;
    temp1=firsttrain;
    cout<<"TRAIN DETAILS\n";
    while(temp1!=NULL){
    	i++;
    	cout<<"-----------------------------------"<<endl;
            cout<<"\nTrain Name: "<<temp1->train_name;
            cout<<"\nTrain number: "<<i++;
            cout<<"\nLeaving Place: "<<temp1->Leaving;
            cout<<"\nDestination : "<<temp1->destination;
            cout<<"\nprice: "<<temp1->price;
            cout<<"\nTime : "<<temp1->time;
            cout<<"\nSeat: "<<temp1->seat;
            cout<<"\n-----------------------------------"<<endl;
 temp1 = temp1->next;
	}
    
}
//------------Delete the train method--------------
void deleteTrain(int trainNo){
    int i;
    Train *ptr, *prevNode;
 
    if(firsttrain == NULL){
        cout<<"No train that will be deleted";
    }
    else{
        ptr = firsttrain;
        prevNode = firsttrain;
        for(i=2; i<=trainNo; i++){
            prevNode = ptr;
            ptr = ptr->next;
            if(ptr == NULL){
                cout<<"Train is deleted Successfully!";
                break;
            }
        }
        if(ptr != NULL){
            if(ptr == firsttrain){
                firsttrain = firsttrain->next;
            }
            prevNode->next = ptr->next;
            ptr->next = NULL;
            //free(ptr);
            delete ptr;
            cout<<"Train is deleted Successfully!";
        }
        else{
            cout<<" Deletion can not be possible from that position";
        }
    }
}

void deletetrain(){
	Train*ptr;
	//when there is no train
	if(firsttrain==NULL)
		cout<<"No train that will be deleted";
	
	//if list has only one node.
 if(firsttrain->next==NULL){
  ptr=firsttrain;
  firsttrain=NULL;
  delete ptr;
  cout<<"Train is deleted Successfully!";
 }
 //Traversing the list.
 else{ 
  Train *prev;
  ptr=firsttrain;
  while(ptr->next!=NULL){
   prev=ptr;
   ptr=ptr->next;
  }
  prev->next=NULL;
  delete ptr;
cout<<"Train is deleted Successfully!";
 }
//	else{
//		Train *ptr=firsttrain;
//		firsttrain=firsttrain->next;
//		delete ptr;
//	}
}


//////////////GLOBALLY DECLARE VARIABLE//////////
int k=0;

/////////////////////CREATE ACCOUNT///////////////////
void createAccount() 
{
   string username;
   string password;
   
   cout << "//// PLEASE ENTER THE FOLLOWING DETAIL TO MAKE YOU ACCOUNT \\\\ " << endl;
   cout << "Please create a username: " << endl;
   cin >> username;
   cout << "Please create a password" << endl;
   cin >> password;
   
   ofstream createaccount;
   createaccount.open("accounts.txt"); 
                       // Will store the users information.
   createaccount << username << " " << password << endl;
   createaccount.close();
   
   cout << "Your Account has been created successfully!" << endl;
   int option;
            cout<< "Enter 1 to go to Admin Block:" ;

            cin>>option;
            if(option == 1){
            	Admin();
        }

}
//---------------------USER FEEDBACK---------------
int rating(){
	cout<<"========================================================\n";
cout<<"                    USER FEEDBACK                       \n";                         
cout<<"========================================================\n";
int total=0;
string q1,q2,q3,q4;
cout<<"Give the answers in yes or no format!!";
cout<<endl;
cout<<"Was the ticket available upto your requirment? : ";
cin>>q1;
if (q1=="yes"){
	total+=1;
}
cout<<"Was the Train on time? : ";
cin>>q2;
if (q2=="yes"){
	total+=1;
}
cout<<"Are you satisfy with overall management? : ";
cin>>q3;
if (q3=="yes"){
	total+=1;
}
cout<<"Do you plan to come again here to avail our services? : ";
cin>>q4;
if (q4=="yes"){
	total+=1;
}
string  suggestion;
switch (total) {
	case 4:
	cout<<("Customer rating: * * * * * \n");
    cout<<(" ===EXCELLENT JOB=== ");
	break;	
	case 3:
    cout<<("Customer rating: * * * * \n");
    cout<<("===SATISFACTORY===\n");
    cin.ignore();
    cout<<("How can we make our experience better? \n");
    getline(cin,suggestion);
    
    break;
    case 2:
    cout<<("Customer rating: * *  \n");
    cout<< (" ===SOMEWHAT SATISFACTORY=== \n");
    cin.ignore();
    cout<<("How can we make our experience better?\n");
    getline(cin,suggestion);
    
    break;
    case 1:
    cout<<("Customer rating: * \n");
    cout<<(" ===DISAPPOINTING=== \n");
    cout<<("Sorry for your experience\n");
    cin.ignore();
    cout<<("How can we make our experience better?\n");	
    getline(cin,suggestion);
    break;
    default:
    cout<<("Customer rating: WORST EXPERINCE \n");
    cout<<("-Sorry for your experience- \n");
    cin.ignore();
	cout<<("How can we make our experience better?\n");	
   // std::getline(std::cin,suggestion);
    getline(cin,suggestion);
    //<<suggestion;
   // getline(cin,suggestion);
   //cin.getline()>>suggestion;
	break;	
	
}
cout<<endl;
cout<<("-------------------------We are glad you visited our--------------------------------------\n");
cout<<"                          RAILWAY MANAGMENT SYSTEM!";
main();
while(!total==0);
 //main();
return 0;
 // main();

}
/////////////////////USER BLOCK////////////////////
int Users()
{
	int ch;

	cout<<("\n\t\t\t**********************\n");
	cout<<("\t\t\tWELCOME TO USER BLOCK\n");
	cout<<("\t\t\t***********************\n");

	cout<<("\n\n\t\t\t\t     MAIN MENU\n");
	//cout<<("\t\t\t   ");
	cout<<endl;
    cout<<("      [1] VIEW TRAIN INFORMATION\n");
	cout<<("      [2] BOOK TICKET\n");
	cout<<("      [3] CHECK ROUTE\n");
	cout<<("      [4] CANCEL TICKET\n");
	cout<<("      [5] GO BACK -> MENU\n");
	cout<<("      [6] EXIT\n");
	
	cout<<(" ");
	cout<<("\n PLEASE ENTER YOUR CHOICE: ");
    cin>>ch;
	switch(ch)
	{
		case 1:
			viewinfo();
			break;
			case 2:
                // seatReservation();
                main();
				break;
			case 3:
				get_route();
			//	main();
				break;
			case 4:
			//	cancelticket();
				break;
			case 5:
		    	main();
				break;
				case 6:
					exit(6);
					break;
		
			default:
					cout<<("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
			cout<<("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
			 main();
							
	}
	return 0;

}

////////////////////////ADMIN BLOCK//////////////////////
int Admin()
{
	
	int ch;
	
	
	cout<<("\n\t\t\t**********************\n");
	cout<<("\t\t\tWELCOME TO ADMIN BLOCK\n");
	cout<<("\t\t\t***********************\n");

	cout<<("\n\n\t\t\t\t  MENU\n");
	cout<<("\t\t\t   ");
    cout<<("[1] Login\n");
	cout<<("[2] Create Account\n");
	cout<<("[3] GO BACK -> MENU\n");
	cout<<("[4] EXIT\n");
	
	cout<<(" ");
	cout<<("\n\t\t\t PLEASE ENTER YOUR CHOICE: ");
    cin>>ch;
	switch(ch)
	{
		case 1:
			login();
			break;
			
			case 2:
				createAccount();
				break;
				
			case 3:
				main();
				break;
		
		case 4:
			exit(4);
				break;
		
		
			default:
				cout<<("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
				cout<<("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
				main();
	}
	return 0;

}


/////////////////////////LOGIN///////////////////////////
int login ()
{
	
    string username;
    string password;
    
    int loginAttempt = 0;

   ifstream savedaccount;
   savedaccount.open("accounts.txt"); // accounts.txt will verify user information
   while (loginAttempt <=3 ) {
   
   cout << "Enter your username:" << endl;
   cin >> username;
   cout << "Enter your password:" << endl;
   cin >> password;
   
   string username2, password2;
   
   savedaccount >> username2 >> password2;
   savedaccount.close();
   
    if(username == username2 && password == password2)
	                                // Achieved by using accounts.txt match
    {
       cout << "Thank you for logging in\n";
       Admin_Operations();
       break;
    }
    else if (username != username2 || password != password2){
	
    cout << "Incorrect login! Create new account or try again." << endl;
    loginAttempt++;
   }
}

   if (loginAttempt == 4)
    {
            cout << "Too many login attempts! Please Go back and create your account ";
            int opt;
            cout<< "Enter 5 to go back:" ;

            cin>>opt;
            if(opt == 5)
			{
            	Admin();
        }
            return 0;
    }

  
}
void Admin_Operations(){
	int choice;
do{
	cout<<("\n     ==================================================================");
	cout<<("\n                             RAILWAY RESERVATION SYSTEM");
	cout<<("\n     ====================================================================");
	cout<<endl; 
	cout<<("                                WELCOME IN ADMIN BLOCK\n");
	cout<<endl;
	cout<<("CHOOSE YOUR OPERATION       \n");
	cout<<("--------------------------  \n");
	cout<<("  [1] VIEW PASSENGERS       \n");
	cout<<("  [2] ADD TRAIN             \n");
	cout<<("  [3] DELETE TRAIN          \n");
	cout<<("  [4] DISPLAY TRAIN         \n");
	cout<<("  [5] BACK TO MAIN MENU         \n");
	cout<<("  [0] TO EXIT.              \n");
	cout<<("\nENTER YOUR CHOICE: ");
	
	cin>>choice;

	switch(choice)
	{
		case 1:
			//  viewpassenger();
			break;
			case 2:
		    addtrain();
			break;
			case 3:
            int trainNo;
            cout<<"Enter the train no you want to delete"<<endl;
            cin>>trainNo;
            deleteTrain(trainNo);
			// deletetrain();
			break;
			case 4:
		    displayTrain();
			break; 
			case 5:
				main();
			default:
			cout<<("\nInvalid Entry!please try again");
		    break;
			//main();
	}
}
while(!choice==0);
}

////////////////////////view information function///////////////////////////
void viewinfo()
{
	cout<<("\n\t\t     ************");
	cout<<("\n\t\t         RAILWAY RESERVATION SYSTEM");
	cout<<("\n\t\t     ************");
	int i = 1;
    
    if(firsttrain == NULL){
        cout<<"\n No Train registered!";
        
        Users();
    }
    else{
        Train*temp1 = firsttrain;
        while(temp1!=NULL){
            cout<<"-----------------------------------"<<endl;
            cout<<"\nTrain Name: "<<temp1->train_name;
            cout<<"\nTrain number: "<<i++;
            cout<<"\nLeaving Place: "<<temp1->Leaving;
            cout<<"\nDestination : "<<temp1->destination;
            cout<<"\nprice: "<<temp1->price;
            cout<<"\nTime : "<<temp1->time;
            cout<<"\nSeat: "<<temp1->seat;
            cout<<"\n-----------------------------------"<<endl;


            temp1 = temp1->next;
        }
        
    }

}
struct bookticket
{
	char train_number[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
}book[1000];

void bookticket(){
	int c,j,n,i;
    int found = -1;
	char v;
    char train_number[10];
	system ("cls");
	// aread();
	cout<<"\n\n\t\t\t============================================";
	cout<<"\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n";
	cout<<"\t\t\t==================================================";
	cout<<"How Many Ticket do you Want to Buy: ";
	scanf("%d",&n);
	for(j=u;j<u+n;j++){
	cout<<"Enter train number: ";
	scanf("%s", book[j].train_number);
	for(i=0;i<k;i++){
	    if(strcmp(book[j].train_number,add[i].train_number)==0){
	        if(add[i].seat==0){
		        printf("\n\n\t\t\tnot available seat");
		        system("cls");
		        main();
	        }
	        else{
	            found=1;
                printf("\n\t\t\tenter book %d no ticket: ",j+1);
                printf("\n\t\t\tenter date: ");
                scanf("%s",book[j].date);
                printf("\n\t\t\tenter your name: ");
                scanf("%s",book[j].name);
                printf("\n\t\t\tenter your phone number: ");
                scanf("%s",book[j].phone);
                printf("\n\t\t\tseat number : %d",add[i].seat );
                book[j].seat=add[i].seat;
                bookticket_write();
                add[i].seat--;
		        // awrite();
		    }
	    }
    }
	if(found==-1)
	{
		printf("\n\n\t\t\ttrain not found!!!");
		system("cls");
		main();
	}

	}
		u=j;
		bookticket_write();
		cout<<"\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
		scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				main();
			}
			if(c!=1)
			{
				exit;
			}			
}

void bookticket_write(){
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}

////---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{

int i;
    bookticket *ptr, *prevNode;
 
    if(head == NULL){
        cout<<"No train that will be deleted";
    }
    else{
        ptr = head;
        prevNode = head;
        for(i=2; i<=name; i++){
            prevNode = ptr;
            ptr = ptr->next;
            if(ptr == NULL){
                cout<<"Ticket is deleted Successfully!";
                break;
            }
        }
        if(ptr != NULL){
            if(ptr == head){
                head = head->next;
            }
            prevNode->next = ptr->next;
            ptr->next = NULL;
            //free(ptr);
            delete ptr;
            cout<<"Ticket is deleted Successfully!";
        }
        else{
            cout<<" Deletion can not be possible from that position";
        }
    }
}

   char pnnmbr[100];
   int location = -1,e;
   cout<< ("\n\n\t\t\tenter phone number: ");
   cin>>pnnmbr;
   for (e=0;e<u;e++)
   {
       if (strcmp(pnnmbr,book[e].phone)==0)
       {
           location=e;
           break;
       }
   }
   if (location==-1)
   {
       cout ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
       
       main();
   }
   else
   {
       for (e=location;e<u;e++)
       {
           strcpy(book[e].date,book[e+1].date);
           strcpy(book[e].train_number,book[e+1].train_number);
           strcpy(book[e].name,book[e+1].name);
           strcpy(book[e].phone,book[e+1].phone);
           bookticket_write();
       }
       u--;
       printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
      
       main();
   }
}


Get Route function
//#define n 10
#define inf 999
int n = 10;
int getNearest(int dist[], bool visited[]){
	
    int minnode = 0 ; 
    int minvalue = inf ; 
//   int dist[n];
//    bool visited[n];
    for(int i=0;i < n ; i++){
        if(!visited[i] && dist[i]<minvalue){
            minvalue = dist[i] ; 
            minnode = i ; 
        }
    }
    return minnode ; 
}

void printPath(int parent[], int j)
{
    map<int,string>cities_1;
    
    cities_1[0]="Islamabad";
    cities_1[1]="Rawalpindi";
    cities_1[2]="Quetta";
    cities_1[3]="Lahore";
    cities_1[4]="Karachi";
    cities_1[5]="Peshawar";
    cities_1[6]="Multan";
    cities_1[7]="Gilgit Baltistan";
    cities_1[8]="Sargodha";
    cities_1[9]="Parachinar";
    
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    cout<<" "<<cities_1[j];
}

int printSolution(int dist[], int n, int parent[],int src, int ch)
{
    map<int,string>cities_1;
    cities_1[0]="Islamabad";
    cities_1[1]="Rawalpindi";
    cities_1[2]="Quetta";
    cities_1[3]="Lahore";
    cities_1[4]="Karachi";
    cities_1[5]="Peshawar";
    cities_1[6]="Multan";
    cities_1[7]="Gilgit Baltistan";
    cities_1[8]="Sargodha";
    cities_1[9]="Parachinar";
   
    if(ch==1)
	{
        cout<<"Distance\tPath";
        
    }
	else
	{
        cout<<"Cost\t\tPath";
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"\n"<<dist[i]<<"\t\t"<<cities_1[src]<<" ";
        printPath(parent, i);
    }
}

void dijkstra(int graph[10][10], int src, int ch)
{
    int dist[n];
    bool visited[n];
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n-1; count++)
    {
        int u = getNearest(dist, visited);
        visited[u] = true;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, n, parent,src, ch);
    
    
}
int get_route()
{
    int graph1[10][10]={{0,450,0,0,0,0,0,0,0,0},
                        {450,0,497,0,0,1415,784,0,0,0},
                        {0,497,0,100,0,0,0,0,0,0},
                        {0,0,1000,0,0,1992,0,0,0,1669},
                        {0,0,0,0,0,523,584,0,0,0},
                        {0,115,0,142,523,0,0,0,983,0},
                        {0,784,0,0,584,0,0,850,0,0},
                        {0,0,0,0,0,0,850,0,0,0},
                        {0,0,0,0,0,983,0,0,0,346},
                        {0,0,0,1669,0,0,0,0,346,0}};
                        // distance
    int graph[10][10]={{0,970,0,0,0,0,0,0,0,0},
                        {970,0,855,0,0,2765,1765,0,0,0},
                        {0,855,0,1628,0,0,0,0,0,0},
                        {0,0,1628,0,0,3470,0,0,0,2565},
                        {0,0,0,0,0,1005,950,0,0,0},
                        {0,2765,0,3470,1005,0,0,0,2065,0},
                        {0,1765,0,0,950,0,0,1720,0,0},
                        {0,0,0,0,0,0,1720,0,1690,0},
                        {0,0,0,0,0,2065,0,1690,0,815},
                        {0,0,0,2565,0,0,0,0,815,0}};
                        // cost

    map<string,int>city;
    
    city["Islamabad"]=0;
    city["Rawalpindi"]=1;
    city["Quetta"]=2;
    city["Lahore"]=3;
    city["Karachi"]=4;
    city["Peshawar"]=5;
    city["Multan"]=6;
    city["Gilgit Baltistan"]=7;
    city["Sargodha"]=8;
    city["Parachinar"]=9;
    
    int ch;
    cout<<"1.BY DISTANCE\n2.BY MONEY"<<endl;
    cin>>ch;
    cout<<"Enter the source node\n";
    int src;
    
    string city_name=" ";
    cin>>city_name;
    cout<<"\n\n\n\n\n";
    src=city[city_name];
   switch (ch){
   	case 1:
   	dijkstra(graph, src, ch);
       get_route();
		break;
		case 2:
		dijkstra(graph1, src, ch);
      main();
	   break;
	   default:
	   cout<<"Route out of our access! ";	
	   main();
	   break;
	} while(ch==0);
	main();
	return 0;
    if(ch==1){
	
        dijkstra(graph, src, ch);
        Users();
    }
    else if(ch==2){
	
        dijkstra(graph1, src, ch);
       Users();
    }
  

   	main();
}

////////////////////////MAIN MENU////////////////////////
int main()
{
	int choice;
	
	cout<<("\n\t\t\t*****************************************\n");
	cout<<("\t\t\t       RAILWAY RESERVATION SYSTEM\n");
	cout<<("\t\t\t******************************************\n");

	cout<<("\n\n\t\t\t\t     MAIN MENU\n");
	cout<<("\t\t\t   ");
    cout<<("\n\t\t\t[1] ADMIN BLOCK");
	cout<<("\n\t\t\t[2] USER BLOCK");
	cout<<("\n\t\t\t[3] USER FEEDBACK");
	cout<<("\n\t\t\t[4] EXIT\n");
	cout<<(" ");
	cout<<("\n\t\t\tENTER YOUR CHOICE: ");

    cin>>choice;
    
	switch(choice)
	{
		case 1:
			Admin();
			break;
		case 2:
			Users();
			break;
		case 3:
		    rating();
			break;	
		case 4:
		    exit(0);
			break;
			
	    default:
	    	
	   		cout<<("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
			cout<<("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
			 main();
	}
	return 0;
}

