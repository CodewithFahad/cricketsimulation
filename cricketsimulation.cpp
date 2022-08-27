
#include<iostream>
#include<iomanip>
#include<ctime>
#include<stdlib.h>
#include<fstream>
using namespace std;

void game();
void startup();
int select_over(int over);
void teamselect(string *team1_player[], string *team2_player[]);
int toss(int res);
void inning_1(int balls ,int wickets, int team );

void starting_innings(int toss_result,int res);

void display_ining_ind(int bowl_score[5] ,int team , int bat_face_ball[],int six_count[],int four_count[] , int bat_sr[], int bat_score[] , int bowler_ecn[], int bowler_over[], int wickets , int bowl_wick[]);

void display_ining_ind1(int bowl_score[5] ,int team , int bat_face_ball[],int six_count[],int four_count[] , int bat_sr[], int bat_score[] , int bowler_ecn[], int bowler_over[], int wickets , int bowl_wick[] , int t_score, int target_score);


void display_ining_pak(int bowl_score[5] ,int team , int bat_face_ball[],int six_count[],int four_count[] , int bat_sr[], int bat_score[] , int bowler_ecn[], int bowler_over[], int wickets , int bowl_wick[]);

void display_ining_pak1(int bowl_score[5] ,int team , int bat_face_ball[],int six_count[],int four_count[] , int bat_sr[], int bat_score[] , int bowler_ecn[], int bowler_over[], int wickets , int bowl_wick[] , int t_score , int target_score);
void inning_2(int balls , int team , int target_score )	;




int main()
{
	game();							// i am using this sub function in which all the function will be called and return the values
}





// subfunction for the game
void game()
{
	const int n=11;
	int res;
	int overs=0,over=0,balls,wicket,run,ball_play,delivery,team;				// varriable to store values to pass to functions
	float c_over;
	string *team1[n],*team2[n];
	
	startup();																	// function to display manu page
	overs=select_over(over);													// function that take overs from user and also store to file
	balls=6*overs;																// balls store number of ball

	teamselect(team1,team2);													// function for displaying playing 11 of each team
	
	team=toss(res);																// function for toss and store the result in team varriable
	
	inning_1(balls, wicket, team  );											// function for first inning
	

}




void startup()													// function for displaying manu of starting game
{
	for(int i=1; i<=100; i++)									// display first line 
	{
		cout<<"-";
	}
	cout<<endl;
	cout<<setw(20);												// for displaying the block unn which cricket simulation is written
	for(int i=1; i<=60; i++)
	{
		cout<<"-";
	}
	cout<<endl;
	for(int i=1; i<=3;i++)
	
	{
		
		if(i==2)
		{
		
		cout<<setw(20)<<"|"<<setw(40)<<"Cricket simulation"<<setw(19)<<"|"<<endl;
		}
		else
		{
		
		cout<<setw(20)<<"|"<<setw(59)<<"|"<<endl;
		}
	}
	cout<<setw(20);
	for(int i=1; i<=60; i++)
	{
		cout<<"-";
	}
	
	cout<<endl<<endl<<endl;
	
	cout<<setw(10);											// for displaying last line
	for(int i=1;i<=80;i++)
	{
		cout<<"-";
	}
	cout<<endl<<endl;
	
	cout<<setw(70)<<"press enter to continue to the game ";
	cin.get();
	system("CLS");
}


int select_over(int over)														// function to take over from user 
{
//	int over=0;
	cout<<"Enter number of overs to play a match : ";
	cin>>over;
	
	ofstream myfile("over.txt");

  																				
	myfile <<over;													// Write to the file

  	ifstream myfile1("over.txt");
  	myfile1>>over;
  	return over;
  	//cout<<over<<endl;
  	myfile.close();
  
  	
}

void teamselect(string *team1_player[] ,string *team2_player[])										// team players display
{
	//1cin.get();
	//system("CLS");
	const int n=11;
	string team1[n],team2[n];
	cout<<"Press enter to select the final 11 players of each team ";
	cin.get();
	ifstream fin;
	fin.open("player1.txt");

  		cout<<"Indian Team : "<<endl;								// loop for display first team
    	for (int i=0; i<n;i++)
 		{
    		getline (fin,team1[i]);
    
     	 	cout <<i+1<<"\t"<< team1[i] <<endl;
     
   		 }
   		for(int i=0; i<n;i++)										// pointing a pointer to string
   		{
	
   		 team1_player[i]=&team1[i];
   		// cout<<*team[i]<<"\t";
   		}
   		 
   	
    ifstream fin1;
	fin1.open("player2.txt");
    cout<<"Patistan team : "<<endl;									// loop for display 2nd team
    for (int i=0; i<n;i++)
 	{
 		
    	getline (fin1,team2[i]);
    
     	 cout <<i+1<<"\t"<< team2[i] <<endl;
    	
    }
    for(int i=0; i<n;i++)										// pointing a pointer to string
   		{
	
   		 team2_player[i]=&team2[i];
   		// cout<<*team[i]<<"\t";
   		}
    
    
    
	
	cout<<"press Enter to continue.....";
	cin.get();
	system("CLS");
	
	
}






int toss(int res)													// function for toss 
{
	int toss_result;									// res to store input from the user 
	srand(time(0));
	toss_result=rand()%2;									// rand function for generate random value between 0 and 1
	cout<<endl<<"Press enter to proceed to toss.";
	cin.get();
	if(toss_result ==1)
	{
		cout<<"Team India won the toss "<<endl;
		
	
		cout<<"Team India press 1 for bat and 2 for bowl : ";
		cin>>res;
		if(res==1)													// selection for batting or bowling
		{
			cout<<"Team India opted batting first.";
			starting_innings(toss_result,res);
			return res;
		}
		else
		{
			cout<<"Team India opted to bowl first.";
			starting_innings(toss_result,res);
			return res;
		}
		
	}
	else
	{
		cout<<"Team Pakistan won the toss "<<endl;
		cout<<"Team Pakistan press 2 for bat and 1 for bowl : ";
		cin>>res;
		if(res==1)
		{
			cout<<"Team Pakistan opted bowling first.";
			starting_innings(toss_result,res);
			return res;
		}
		else
		{
			cout<<"Team Pakistan opted to batting first.";
			starting_innings(toss_result,res);
			return res;
		}
	}
	

	
	
}




void starting_innings(int toss_result,int res)							// function of displaying first inning scorecard before starting match
{
	string team1[11],team2[11];
	ifstream fin;
	ifstream fin1;														// access to file handling that store players name of each team
	fin.open("player1.txt");
	fin1.open("player2.txt");
	for(int i=0; i<11; i++)												// loop for taking players name and store in string 
	{
		getline(fin,team1[i]);
		
	}
	for(int i=0; i<11; i++)
	{
		getline(fin1,team2[i]);
		
	}
	system("CLS");
	if(toss_result==1 && res==1)
	{
		cout<<endl<<setw(60)<<"Batting line up of India "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<11;i++)
		{
		
			cout<<endl<<team1[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0"<<"\t0";
			
		}
		cout<<endl<<setw(60)<<"Bowling line up of Pakistan"<<endl;
		cout<<endl<<"Bowlers \t\t over \t Runs \t W \t Ecn "<<endl;
		for(int i=0;i<11;i++)
		{
			if(i>5)
			cout<<endl<<team2[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0";
			
		}
	
	}
	else if(toss_result==1 && res==2)
	{
		cout<<endl<<setw(60)<<"Batting line up of Pakistan "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<11;i++)
		{
			cout<<endl<<team2[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0"<<"\t0";
		}
		cout<<endl<<setw(60)<<"Bowling line up of India"<<endl;
		cout<<endl<<"Bowlers \t\t over \t Runs \t W \t Ecn "<<endl;
			for(int i=0;i<11;i++)
		{
			if(i>5)
			cout<<endl<<team1[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0";
			
		}
	}
	else if(toss_result==0 && res==1)
	{
		cout<<endl<<setw(60)<<"Batting line up of India "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<11;i++)
		{
			
		
			cout<<endl<<team1[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0"<<"\t0";
		}
		cout<<endl<<setw(60)<<"Bowling line up of Pakistan"<<endl;
		cout<<endl<<"Bowlers \t\t over \t Runs \t W \t Ecn "<<endl;
			for(int i=0;i<11;i++)
		{
			if(i>5)
			cout<<endl<<team2[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0";
			
		}
	}
	else if(toss_result==0 && res==2)
	{
		cout<<endl<<setw(60)<<"Batting line up of Pakistan "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<11;i++)
		{
		
			cout<<endl<<team2[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0"<<"\t0";
		}
		cout<<endl<<setw(60)<<"Bowling line up of India"<<endl;
		cout<<"Bowlers \t\t over \t Runs \t W \t Ecn "<<endl;
			for(int i=0;i<11;i++)
		{
			if(i>5)
			cout<<endl<<team1[i]<<"\t\t0"<<"\t0"<<"\t0"<<"\t0";
			
		}
		
	}

	
}


















void inning_1(int balls ,int wickets , int team)								// function to display inning one
{
	int ov=0;
	float economy=0;
	int bowler_over[5]={1,1,1,1,1},bowler_ecn[5]={0,0,0,0,0}, bowl_wick[5]={0,0,0,0,0};
	 int num=0,sum=0,face=0,r=0,size=11;						// these varriable are declare size is numbwer of team player which is 11
	int bowl_score[5]={0,0,0,0,0};								// this array is used to store the bowler
	// belowing arrays are used to store number of face ball by a batsman cout sixes and fours 
	int bat_face_ball[size]={0,0,0,0,0,0,0,0,0,0,0} , six_count[size]={0,0,0,0,0,0,0,0,0,0,0},four_count[size]={0,0,0,0,0,0,0,0,0,0,0},bat_sr[size]={0,0,0,0,0,0,0,0,0,0,0};
	int batt_1[size]={0,0,0,0,0,0,0,0,0,0,0};					//  this array is used to store the score of the player
	int score=0, t_score=0;
	srand(time(0));												// to generate random numbers
	cin.ignore();
	cout<<endl<<endl<<"Press enter to continue to the match .....";
	cin.get();
	system("CLS");
	int run=0,ball_face=0,runs=0,six=0,four=0;
	float rate=0.0;
	float strike_rate=0.0;
	int over=0;
	const int n=11;
	string team1[n],team2[n];
	ifstream fin,fin1;
	fin.open("player1.txt");									// accesing the team player name from the file
	fin1.open("player2.txt");
	for(int i=0; i<n; i++)
	{
		getline(fin,team1[i]);
		getline(fin1,team2[i]);
	}
	
	cout<<setw(60)<<"First Inning"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i=0; i<=100;i++)
	cout<<"-";
	cout<<endl;
//	int i=0;
	
	if(team==1)											// this condition is for when team 1 which is india won the toss then this function will be called
	{
		
		for(int j=1; j<=balls; j++)
		{
			static int i=0;
			while(i<n)
			{
			
				
			
				cout<<"player"<<"\t\t"<<"run"<<"\t"<<"ball"<<"\t"<<"strike rate"<<"\t"<<endl;
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<team1[i]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				//<<team1[i+1]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				ball_face=ball_face+1;
				bat_sr[r]=strike_rate;
				batt_1[i]=run;
				if(runs==-1)																// when batsman out then this check will be true and execute to bring next player
				{
					
					bat_face_ball[face]= bat_face_ball[face] + ball_face;
					bowl_wick[ov]=bowl_wick[ov]+1;
					wickets=wickets+1;
					//fin<<run<<endl;
					
					six_count[i]= six; 
					four_count[i]= four; 
					i++;
					r++;
					run=0;
					ball_face=1;
					face=face+1;
					six=0;
					four=0;
				}
				break;	
				
			//	}
			}
			for(int k=0; k<=100; k++)
			cout<<"-";
			cout<<endl;
			cout<<"bowler"<<"\t\t"<<"run"<<"\t"<<"over"<<"\t"<<"ECN"<<"\t"<<"wickets"<<endl;
			
			static int bowler=6;
			
			while(bowler<n)															// condition for the bowler of 2nd team 
			{
					
				
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<"|"<<team2[bowler]<<"\t"<<bowl_score[num]<<"\t"<<bowler_over[ov]<<"\t"<<economy<<"\t"<<bowl_wick[ov]<<"|"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				economy=float(bowl_score[num])/(bowler_over[ov]);
				bowler_ecn[ov]=economy;
				if(j%6==0)																					// if condition for rotating of bowler after over ended
				{
				
					num++;
					bowler_over[ov]=bowler_over[ov]+1;
					ov++;
					bowler++;
					if(bowler==11)
					{
						
						bowler=6;
						ov=0;
						num=0;
					}
				}	
				break;
			}
			over=j/6;																				// to calculate total overs
			static int tis=0;
			if((j-1)%6==0)
			tis=0;
			tis++;
			
			
			 	// to display total score and wickets
			
		
			
			
		cout<<endl<<"-----------------------------------------"<<endl;
			cout<<"|\tTotal Score = " <<t_score<<"\t|"<<endl;
			cout<<"|\tWickets = "<<wickets<<"\t|"<<endl;
			cout<<"|\tovers = "<<over<<"."<<tis-1<<"\t|"<<endl;
			cin.ignore();
			cout<<endl<<"Press enter to next ball "<<endl;
			
			
		
			runs=-1+rand()%6 ;						// generate random function 
			sum=sum+runs;
			if(runs==6)
			{
				six=six+1;
			}
			if(runs==4)
			{
				four=four+1;
			}
			if(runs!=-1)																// calculation of runs that a bowler takes
			{
				bowl_score[num]=bowl_score[num]+runs;
				//sum=sum+runs;
				score=runs;
				t_score=t_score+score;
				run=run+runs;
			}
			rate=float(run)/float(ball_face);
			strike_rate=rate*100;
			cin.get();
			if(i==11)
			break;
			system("CLS");
			
		}
			
		display_ining_ind(bowl_score , team , bat_face_ball , six_count,four_count , bat_sr, batt_1 , bowler_ecn, bowler_over , wickets,bowl_wick);
		inning_2( balls ,  team ,  t_score );	
	}
	else
	{

	for(int j=1; j<=balls; j++)
		{
			static int i=0;
			while(i<n)
			{
			
				
			
				cout<<"player"<<"\t\t"<<"run"<<"\t"<<"ball"<<"\t"<<"strike rate"<<"\t"<<endl;
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<team2[i]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				//<<team1[i+1]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				ball_face=ball_face+1;
				bat_sr[r]=strike_rate;
				batt_1[i]=run;
				if(runs==-1)																// when batsman out then this check will be true and execute to bring next player
				{
					
					bat_face_ball[face]= bat_face_ball[face] + ball_face;
					bowl_wick[ov]=bowl_wick[ov]+1;
					wickets=wickets+1;
					//fin<<run<<endl;
					
					six_count[i]= six; 
					four_count[i]= four; 
					i++;
					r++;
					run=0;
					ball_face=1;
					face=face+1;
					six=0;
					four=0;
				}
				break;	
				
			//	}
			}
			for(int k=0; k<=100; k++)
			cout<<"-";
			cout<<endl;
			cout<<"bowler"<<"\t\t"<<"run"<<"\t"<<"over"<<"\t"<<"ECN"<<"\t"<<"wickets"<<endl;
			
			static int bowler=6;
			
			while(bowler<n)															// condition for the bowler of 2nd team 
			{
					
				
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<"|"<<team1[bowler]<<"\t"<<bowl_score[num]<<"\t"<<bowler_over[ov]<<"\t"<<economy<<"\t"<<bowl_wick[ov]<<"|"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				economy=float(bowl_score[num])/(bowler_over[ov]);
				bowler_ecn[ov]=economy;
				if(j%6==0)																				// rotation of bowler
				{
				
					num++;
					bowler_over[ov]=bowler_over[ov]+1;
					ov++;
					bowler++;
					if(bowler==11)
					{
						
						bowler=6;
						ov=0;
						num=0;
					}
				}	
				break;
			}
			over=j/6;
			static int tis=0;
			if((j-1)%6==0)
			tis=0;
			tis++;
			
			
			 	
			
		
			
			cout<<endl<<"-----------------------------------------"<<endl;
			cout<<"|\tTotal Score = " <<t_score<<"\t|"<<endl;
			cout<<"|\tWickets = "<<wickets<<"\t|"<<endl;
			cout<<"|\tovers = "<<over<<"."<<tis-1<<"\t|"<<endl;
			cin.ignore();
			cout<<endl<<"Press enter to next ball "<<endl;
			
			
		
			runs=-1+rand()%6 ;						// generate random function 
			sum=sum+runs;
			if(runs==6)
			{
				six=six+1;
			}
			if(runs==4)
			{
				four=four+1;
			}
			if(runs!=-1)
			{
				bowl_score[num]=bowl_score[num]+runs;
				//sum=sum+runs;
				score=runs;
				t_score=t_score+score;
				run=run+runs;
			}
			rate=float(run)/float(ball_face);
			strike_rate=rate*100;
			cin.get();
			if(i==11)
			break;
			system("CLS");
			
		}
		
		// calling the sub function for the displaying scores and complete scorecard
		display_ining_pak(bowl_score , team , bat_face_ball , six_count,four_count , bat_sr, batt_1 , bowler_ecn, bowler_over , wickets,bowl_wick);
		inning_2( balls ,  team , t_score );					// calling innig 2 function after displaying final scorecard of inning 1	
	}
}

	










// if india choose batting than this function will be called

void display_ining_ind(int bowl_score[5] , int team , int bat_face_ball[] ,int six_count[],int four_count[] , int bat_sr[] , int bat_score[] , int  bowler_ecn[] , int bowler_over[] , int wickets , int bowl_wick[] )
{
	int size=11;
	int total_score = 0;
//	int bat_score[size]={0,0,0,0,0,0,0,0,0,0,0};
	string team1[size];
	string team2[size];
	ifstream fin;
	ifstream fin1;														// access to file handling that store players name of each team

	fin.open("player1.txt");
	fin1.open("player2.txt");
	
	for(int i=0; i<size; i++)												// loop for taking players name and store in string 
	{
		getline(fin,team1[i]);
		
	}
	for(int i=0; i<size; i++)
	{
		getline(fin1,team2[i]);
		
	}
	
	cout<<endl<<"End of 1st inning "<<endl;
		if(team == 1)
	{
		cout<<endl<<setw(60)<<"Batting  of India "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<size;i++)
		{
		
			cout<<endl<<team1[i]<<"\t\t"<<bat_score[i]<<"\t"<<bat_face_ball[i]<<"\t"<<four_count[i]<<"\t"<<six_count[i]<<"\t"<<bat_sr[i];
			total_score=total_score+bat_score[i];
		}
		cout<<endl<<endl<<"|----------------------------------------|";
		cout<<endl<<"\tTotal Score & wickets = "<<total_score<<" / "<<wickets;
		cout<<endl<<"|----------------------------------------|"<<endl;
		cout<<endl<<setw(60)<<"Bowling of Pakistan"<<endl;
		cout<<endl<<"Bowlers \t\t Runs \t Over \t W \t Ecn "<<endl;
		int j=0;
		for(int i=6;i<size;i++)
		{
			//if(i>5)
			
			cout<<endl<<team2[i]<<"\t\t"<<bowl_score[j]<<"\t"<<bowler_over[j]-1<<"\t"<<bowl_wick[j]<<"\t"<<bowler_ecn[j];
			j++;
		}
	
	}
}



// if Pakistan choose batting fisrt than this will be callled
void display_ining_pak(int bowl_score[5] , int team , int bat_face_ball[] ,int six_count[],int four_count[] , int bat_sr[] , int bat_score[] , int  bowler_ecn[] , int bowler_over[] , int wickets , int bowl_wick[] )
{
	int size=11;
	int total_score = 0;
//	int bat_score[size]={0,0,0,0,0,0,0,0,0,0,0};
	string team1[size];
	string team2[size];
	ifstream fin;
	ifstream fin1;														// access to file handling that store players name of each team

	fin.open("player1.txt");
	fin1.open("player2.txt");
	
	for(int i=0; i<size; i++)												// loop for taking players name and store in string 
	{
		getline(fin,team1[i]);
		
	}
	for(int i=0; i<size; i++)
	{
		getline(fin1,team2[i]);
		
	}
	
	cout<<endl<<"End of 1st inning "<<endl;

		
		cout<<endl<<setw(60)<<"Batting  of Pakistan "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<size;i++)
		{
		
			cout<<endl<<team2[i]<<"\t\t"<<bat_score[i]<<"\t"<<bat_face_ball[i]<<"\t"<<four_count[i]<<"\t"<<six_count[i]<<"\t"<<bat_sr[i];
			total_score=total_score+bat_score[i];
		}
		cout<<endl<<endl<<"|----------------------------------------|";
		cout<<endl<<"\tTotal Score & wickets = "<<total_score<<" / "<<wickets;
		cout<<endl<<"|----------------------------------------|"<<endl;
		cout<<endl<<setw(60)<<"Bowling of India"<<endl;
		cout<<endl<<"Bowlers \t\t Runs \t Over \t W \t Ecn "<<endl;
		int j=0;
		for(int i=6;i<size;i++)
		{
			//if(i>5)
			
			cout<<endl<<team1[i]<<"\t\t"<<bowl_score[j]<<"\t"<<bowler_over[j]-1<<"\t"<<bowl_wick[j]<<"\t"<<bowler_ecn[j];
			j++;
		}
	
	
}


// inning 2 start from here


void inning_2(int balls , int team , int target_score )								// function to display inning one
{
	int wickets=0;
	int ov=0;
	float economy=0;
	int bowler_over[5]={1,1,1,1,1},bowler_ecn[5]={0,0,0,0,0}, bowl_wick[5]={0,0,0,0,0};
	 int num=0,sum=0,face=0,r=0,size=11;						// these varriable are declare size is numbwer of team player which is 11
	int bowl_score[5]={0,0,0,0,0};								// this array is used to store the bowler
	// belowing arrays are used to store number of face ball by a batsman cout sixes and fours 
	int bat_face_ball[size]={0,0,0,0,0,0,0,0,0,0,0} , six_count[size]={0,0,0,0,0,0,0,0,0,0,0},four_count[size]={0,0,0,0,0,0,0,0,0,0,0},bat_sr[size]={0,0,0,0,0,0,0,0,0,0,0};
	int batt_1[size]={0,0,0,0,0,0,0,0,0,0,0};					//  this array is used to store the score of the player
	int score=0, t_score=0;
	srand(time(0));												// to generate random numbers
	cin.ignore();
	cout<<endl<<endl<<"Press enter to continue to the match .....";
	cin.get();
	system("CLS");
	int run=0,ball_face=0,runs=0,six=0,four=0;
	float rate=0.0;
	float strike_rate=0.0;
	int over=0;
	const int n=11;
	string team1[n],team2[n];
	ifstream fin,fin1;
	fin.open("player1.txt");									// accesing the team player name from the file
	fin1.open("player2.txt");
	for(int i=0; i<n; i++)
	{
		getline(fin,team1[i]);
		getline(fin1,team2[i]);
	}
	
	cout<<setw(60)<<"Second Inning"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i=0; i<=100;i++)
	cout<<"-";
	cout<<endl;
//	int i=0;
	
	if(team==1)											// this condition is for when team 1 which is india won the toss then this function will be called
	{
			for(int j=1; j<=balls; j++)
		{
			static int i=0;
			while(i<n)
			{
			
				
			
				cout<<"player"<<"\t\t"<<"run"<<"\t"<<"ball"<<"\t"<<"strike rate"<<"\t"<<endl;
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<team2[i]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				//<<team1[i+1]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				ball_face=ball_face+1;
				bat_sr[r]=strike_rate;
				batt_1[i]=run;
				if(runs==-1)																// when batsman out then this check will be true and execute to bring next player
				{
					
					bat_face_ball[face]= bat_face_ball[face] + ball_face;
					bowl_wick[ov]=bowl_wick[ov]+1;
					wickets=wickets+1;
					//fin<<run<<endl;
					
					six_count[i]= six; 
					four_count[i]= four; 
					i++;
					r++;
					run=0;
					ball_face=1;
					face=face+1;
					six=0;
					four=0;
				}
				break;	
				
			//	}
			}
			for(int k=0; k<=100; k++)
			cout<<"-";
			cout<<endl;
			cout<<"bowler"<<"\t\t"<<"run"<<"\t"<<"over"<<"\t"<<"ECN"<<"\t"<<"wickets"<<endl;
			
			static int bowler=6;
			
			while(bowler<n)															// condition for the bowler of 2nd team 
			{
					
				
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<"|"<<team1[bowler]<<"\t"<<bowl_score[num]<<"\t"<<bowler_over[ov]<<"\t"<<economy<<"\t"<<bowl_wick[ov]<<"|"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				economy=float(bowl_score[num])/(bowler_over[ov]);
				bowler_ecn[ov]=economy;
				if(j%6==0)
				{																// changing the bowler when his over completed
				
					num++;
					bowler_over[ov]=bowler_over[ov]+1;
					ov++;
					bowler++;
					if(bowler==11)
					{
						
						bowler=6;
						ov=0;
						num=0;
					}
				}	
				break;
			}
			over=j/6;																				// calculation of overs 
			static int tis=0;
			if((j-1)%6==0)
			tis=0;
			tis++;
			
			
			 	
			
		
			
			
		    cout<<endl<<"-------------------------------------"<<endl;
			cout<<"|\tTotal Score = " <<t_score<<"\t|"<<endl;
			cout<<"|\tWickets = "<<wickets<<"\t|"<<endl;
			cout<<"|\tovers = "<<over<<"."<<tis-1<<"\t|"<<endl;
			
			
		
			runs=-1+rand()%6 ;						// generate random function 
			sum=sum+runs;
			if(runs==6)
			{
				six=six+1;
			}
			if(runs==4)
			{
				four=four+1;
			}
			if(runs!=-1)
			{
				bowl_score[num]=bowl_score[num]+runs;
				//sum=sum+runs;
				score=runs;
				t_score=t_score+score;
				run=run+runs;
			}
			rate=float(run)/float(ball_face);
			strike_rate=rate*100;
			cin.get();
			if(i==11)
			break;
			if(t_score>target_score)
			break;
			system("CLS");
			
		}
	// calling for displaying final scorecard of innig 2
	display_ining_pak1(bowl_score , team , bat_face_ball , six_count,four_count , bat_sr, batt_1 , bowler_ecn, bowler_over , wickets,bowl_wick , t_score , target_score);	
	
	}	
	// if second inning batting team is india then this will be called
	else
	{
		for(int j=1; j<=balls; j++)
		{
			static int i=0;
			while(i<n)
			{
			
				
				
				cout<<"player"<<"\t\t"<<"run"<<"\t"<<"ball"<<"\t"<<"strike rate"<<"\t"<<endl;
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<team1[i]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				//<<team1[i+1]<<"\t"<<run<<"\t"<<ball_face<<"\t"<<strike_rate<<"\t"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				ball_face=ball_face+1;
				bat_sr[r]=strike_rate;
				batt_1[i]=run;
				if(runs==-1)																// when batsman out then this check will be true and execute to bring next player
				{
					
					bat_face_ball[face]= bat_face_ball[face] + ball_face;
					bowl_wick[ov]=bowl_wick[ov]+1;
					wickets=wickets+1;
					//fin<<run<<endl;
					
					six_count[i]= six; 
					four_count[i]= four; 
					i++;
					r++;
					run=0;
					ball_face=1;
					face=face+1;
					six=0;
					four=0;
				}
				break;	
				
			//	}
			}
			cout<<endl;
			for(int k=0; k<=100; k++)
			cout<<"-";
			cout<<endl;
			cout<<"bowler"<<"\t\t"<<"run"<<"\t"<<"over"<<"\t"<<"ECN"<<"\t"<<"wickets"<<endl;
			
			static int bowler=6;
			
			while(bowler<n)															// condition for the bowler of 2nd team 
			{
					
				cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
				cout<<"|"<<team2[bowler]<<"\t"<<bowl_score[num]<<"\t"<<bowler_over[ov]<<"\t"<<economy<<"\t"<<bowl_wick[ov]<<"|"<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				economy=float(bowl_score[num])/(bowler_over[ov]);
				bowler_ecn[ov]=economy;
				if(j%6==0)
				{
				
					num++;
					bowler_over[ov]=bowler_over[ov]+1;
					ov++;
					bowler++;
					if(bowler==11)
					{
						
						bowler=6;
						ov=0;
						num=0;
					}
				}	
				break;
			}
			over=j/6;					//	for the calculation of overs
			static int tis=0;
			if((j-1)%6==0)
			tis=0;
			tis++;
			
			
			 	
			
		
			
			cout<<endl<<"-------------------------------------"<<endl;
			cout<<"|\tTotal Score = " <<t_score<<"\t|"<<endl;
			cout<<"|\tWickets = "<<wickets<<"\t|"<<endl;
			cout<<"|\tovers = "<<over<<"."<<tis-1<<"\t|"<<endl;
			cin.ignore();
			cout<<endl<<"Press enter to next ball "<<endl;
			
			
		
			runs=-1+rand()%6 ;						// generate random function 
			sum=sum+runs;
			if(runs==6)
			{
				six=six+1;
			}
			if(runs==4)
			{
				four=four+1;
			}
			if(runs!=-1)
			{
				bowl_score[num]=bowl_score[num]+runs;
				//sum=sum+runs;
				score=runs;
				t_score=t_score+score;
				run=run+runs;
			}
			rate=float(run)/float(ball_face);
			strike_rate=rate*100;
			cin.get();
			if(i==11)
			break;
			if(t_score>target_score)
			break;
			system("CLS");
			
		}
		display_ining_ind1(bowl_score , team , bat_face_ball , six_count,four_count , bat_sr, batt_1 , bowler_ecn, bowler_over , wickets,bowl_wick , t_score , target_score);	
	}
	

}

	








// called if india is batting in 2nd inning 



void display_ining_ind1(int bowl_score[5] , int team , int bat_face_ball[] ,int six_count[],int four_count[] , int bat_sr[] , int bat_score[] , int  bowler_ecn[] , int bowler_over[] , int wickets , int bowl_wick[] , int t_score, int target_score )
{
	int size=11;
	int total_score = 0;
//	int bat_score[size]={0,0,0,0,0,0,0,0,0,0,0};
	string team1[size];
	string team2[size];
	ifstream fin;
	ifstream fin1;														// access to file handling that store players name of each team

	fin.open("player1.txt");
	fin1.open("player2.txt");
	
	for(int i=0; i<size; i++)												// loop for taking players name and store in string 
	{
		getline(fin,team1[i]);
		
	}
	for(int i=0; i<size; i++)
	{
		getline(fin1,team2[i]);
		
	}
	
	cout<<endl<<"End of 2nd inning "<<endl;

	
		cout<<endl<<setw(60)<<"Batting  of India "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<size;i++)
		{
		
			cout<<endl<<team1[i]<<"\t\t"<<bat_score[i]<<"\t"<<bat_face_ball[i]<<"\t"<<four_count[i]<<"\t"<<six_count[i]<<"\t"<<bat_sr[i];
			total_score=total_score+bat_score[i];
		}
		cout<<endl<<endl<<"|----------------------------------------|";
		cout<<endl<<"\tTotal Score & wickets = "<<total_score<<" / "<<wickets;
		cout<<endl<<"|----------------------------------------|"<<endl;
		cout<<endl<<setw(60)<<"Bowling of Pakistan"<<endl;
		cout<<endl<<"Bowlers \t\t Runs \t Over \t W \t Ecn "<<endl;
		int j=0;
		for(int i=6;i<size;i++)
		{
			//if(i>5)
			
			cout<<endl<<team2[i]<<"\t\t"<<bowl_score[j]<<"\t"<<bowler_over[j]-1<<"\t"<<bowl_wick[j]<<"\t"<<bowler_ecn[j];
			j++;
		}
	
		cout<<endl<<endl<<"press continue to see match summary ......"<<endl;
		
		cin.ignore();
		cin.get();
		system("CLS");
		
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                         Match Result                        |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		
		if(t_score>=target_score)
		{
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                    India won the Match                      |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		}
		else
		{
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                    Pakistan won the Match                   |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		}
}


// called if pakistan will bat in 2nd inning 

void display_ining_pak1(int bowl_score[5] , int team , int bat_face_ball[] ,int six_count[],int four_count[] , int bat_sr[] , int bat_score[] , int  bowler_ecn[] , int bowler_over[] , int wickets , int bowl_wick[] , int t_score , int target_score )
{
	int size=11;
	int total_score = 0;
//	int bat_score[size]={0,0,0,0,0,0,0,0,0,0,0};
	string team1[size];
	string team2[size];
	ifstream fin;
	ifstream fin1;														// access to file handling that store players name of each team

	fin.open("player1.txt");
	fin1.open("player2.txt");
	
	for(int i=0; i<size; i++)												// loop for taking players name and store in string 
	{
		getline(fin,team1[i]);
		
	}
	for(int i=0; i<size; i++)
	{
		getline(fin1,team2[i]);
		
	}
	
	cout<<endl<<"End of 2nd inning "<<endl;

		
		cout<<endl<<setw(60)<<"Batting  of Pakistan "<<endl;
		cout<<"Players \t\t runs \t Balls \t 4s \t 6s \t S.R "<<endl;
		for(int i=0;i<size;i++)
		{
		
			cout<<endl<<team2[i]<<"\t\t"<<bat_score[i]<<"\t"<<bat_face_ball[i]<<"\t"<<four_count[i]<<"\t"<<six_count[i]<<"\t"<<bat_sr[i];
			total_score=total_score+bat_score[i];
		}
		cout<<endl<<endl<<"|----------------------------------------|";
		cout<<endl<<"\tTotal Score & wickets = "<<total_score<<" / "<<wickets;
		cout<<endl<<"|----------------------------------------|"<<endl;
		cout<<endl<<setw(60)<<"Bowling of India"<<endl;
		cout<<endl<<"Bowlers \t\t Runs \t Over \t W \t Ecn "<<endl;
		int j=0;
		for(int i=6;i<size;i++)
		{
			//if(i>5)
			
			cout<<endl<<team1[i]<<"\t\t"<<bowl_score[j]<<"\t"<<bowler_over[j]-1<<"\t"<<bowl_wick[j]<<"\t"<<bowler_ecn[j];
			j++;
		}
		
			cout<<endl<<endl<<"press continue to see match summary ......"<<endl;
		
		cin.ignore();
		cin.get();
		system("CLS");
		
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                         Match Result                        |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		
		if(t_score>=target_score)
		{
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                    Pakistan won the Match                   |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		}
		else
		{
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"|                                                             |"<<endl;
		cout<<"|                    India won the Match                      |"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		}
	
	
}



