#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Player
{
	int JerseyNumber;
	char name[100];
	int Runs;
	int Wickets;
	int Matchesplayed;
}Player;

int size=7;

void displayplayers(Player* parr,int size)
{
	printf("JerseyNumber         name            Runs          Wickets         Matchesplayed\n");
        for(int i=0;i<size;i++)
	       {
		
		        printf("   %d        ",parr[i].JerseyNumber);
		        printf("      %s     ", parr[i].name);
		        printf("      %d     ", parr[i].Runs);
		        printf("      %d     ", parr[i].Wickets);
		        printf("      %d     \n", parr[i].Matchesplayed);
	       }
}


int searchByJerseyNumber(Player* parr,int size,int JerseyNumber)
{
	for(int i=0;i<size;i++)
	{
		if(parr[i].JerseyNumber==JerseyNumber)
			return i;
	}
	return -1;
			
}

int searchByname(Player* parr,int size,char name[])
{
    for(int i=0;i<size;i++)
    {
        if(strcasecmp(parr[i].name,name)==0)
        {
            return i;
        }
    }

    return -1;
}

void storeHardCoded(Player* parr,int* currindex)
{
	parr[0].JerseyNumber=45;
strcpy(parr[0].name,"RohitSharma");
parr[0].Runs=10866;
parr[0].Wickets=9;
parr[0].Matchesplayed=265;

parr[1].JerseyNumber=18;
strcpy(parr[1].name,"ViratKohali");
parr[1].Runs=14941;
parr[1].Wickets=5;
parr[1].Matchesplayed=314;

parr[2].JerseyNumber=77;
strcpy(parr[2].name,"ShubhamanGill");
parr[2].Runs=4598;
parr[2].Wickets=0;
parr[2].Matchesplayed=144;

parr[3].JerseyNumber=33;
strcpy(parr[3].name,"HardikPandya");
parr[3].Runs=1904;
parr[3].Wickets=91;
parr[3].Matchesplayed=94;

parr[4].JerseyNumber=10;
strcpy(parr[4].name,"SachineTendulkar");
parr[4].Runs=18426;
parr[4].Wickets=154;
parr[4].Matchesplayed=463;
	
	*currindex=5;
}

void storePlayer(Player* parr,int size)
{
	printf("Enter player details");
	for(int i=0;i<size;i++)
	{
		printf("Enter detail of player %d",i+1);
		scanf("%d",&parr[i].JerseyNumber);
		scanf("%s",parr[i].name);
		scanf("%d",&parr[i].Runs);
		if(parr[i].Runs < 0)
        {
            printf("Runs cannot be negative\n");
            i--;
            continue;
            
            
        }
		scanf("%d",&parr[i].Wickets);
		if(parr[i].Wickets < 0)
        {
            printf("Wickets cannot be negative\n");
            i--;
            continue;
        }
		scanf("%d",&parr[i].Matchesplayed);
		if(parr[i].Matchesplayed < 0)
        {
            printf("Matchesplayed cannot be negative\n");
            i--;
            continue;
        }
	}
}




void deletePlayerByJerseyNumber(Player* parr,int* currindex, int JerseyNumber)
{
	int index=searchByJerseyNumber(parr,*currindex,JerseyNumber);
	if(index!=-1)
	{
		for(int i=index;i<*currindex-1;i++)
			parr[i]=parr[i+1];
			
		(*currindex)--;
		printf("Deleted successfully\n");
	}
	else
		printf("Player not found\n");
	
}
Player* addPlayer(Player* parr,int* currindex,Player* play)
{
	if (*currindex >= size)
    {
    	printf("Array full and realloaction started");
        int newsize = size * 2;
        parr = (Player*)realloc(parr,sizeof(Player) * newsize);
        size = newsize;
    }

	parr[*currindex]=*play;
	(*currindex)++;
	return parr;
}

void updatePlayer(Player* parr,int currindex,int JerseyNumber)
{
	int index=searchByJerseyNumber(parr,currindex,JerseyNumber);
	if(index!=-1)
	{
		while(1)
		{
		int subchoice;
		printf("Enter 1 to update Runs 2 to update Wickets 3 to update Matchesplayed 4 to exit");
		scanf("%d",&subchoice);
		if(subchoice==1)
		{
			printf("Enter new Runs");
			int Runs;
			scanf("%d",&Runs);
			if(Runs>=0)
			{
			parr[index].Runs=parr[index].Runs+Runs;
		    }
		    else
		    {
		    	printf("Runs cannot be negative");
			}
		}
		else if(subchoice==2)
		{
			printf("Enter new Wickets");
			int Wickets;
			scanf("%d",&Wickets);
			if(Wickets>=0)
			{
			parr[index].Wickets=parr[index].Wickets+Wickets;
		    }
		    else
		    {
		    	printf("Wickets cannot be negative");
			}
		}
		else if(subchoice==3)
		{
		    printf("Enter new Matchesplayed");
			int Matchesplayed;
			scanf("%d",&Matchesplayed);
			if(Matchesplayed>=0)
			{
			parr[index].Matchesplayed=parr[index].Matchesplayed+Matchesplayed;
		    }
		    else
		    {
		    	printf("Matchesplayed cannot be negative");
			}	
		}
		else if(subchoice==4)
			break;
		else
			printf("Invalid choice");
		}
	}
	else
		printf("Record no found");
}


void top3Players(Player *parr,int currindex)
{
    Player temp[currindex];

    for(int i=0;i<currindex;i++)
    {
        temp[i]=parr[i];
    }

    Player t;

    for(int i=0;i<currindex-1;i++)
    {
        for(int j=i+1;j<currindex;j++)
        {
            if(temp[i].Runs < temp[j].Runs)
            {
                t=temp[i];
                temp[i]=temp[j];
                temp[j]=t;
            }
        }
    }

    printf("Top 3 Players (By Runs)\n");
    printf("Jersey       Name       Runs         Wickets       Matches\n");

    int limit = (currindex < 3) ? currindex : 3;

    for(int i=0;i<limit;i++)
    {
        printf("   %d        ",temp[i].JerseyNumber);
		printf("   %s     ", temp[i].name);
		printf("      %d     ", temp[i].Runs);
		printf("      %d     ", temp[i].Wickets);
		printf("      %d     \n", temp[i].Matchesplayed);
    }
    
}

void displaySortedPlayers(Player *parr, int currindex, int choice)
{
    Player temp[currindex];

    for(int i=0;i<currindex;i++)
    {
        temp[i]=parr[i];
    }

    Player t;

    for(int i=0;i<currindex-1;i++)
    {
        for(int j=0;j<currindex-1-i;j++)
        {
            if(choice==1)      // Minimum Runs
            {
                if(temp[j].Runs > temp[j+1].Runs)
                {
                    t=temp[j];
                    temp[j]=temp[j+1];
                    temp[j+1]=t;
                }
            }
            else if(choice==2) // Maximum Runs
            {
                if(temp[j].Runs < temp[j+1].Runs)
                {
                    t=temp[j];
                    temp[j]=temp[j+1];
                    temp[j+1]=t;
                }
            }
            else if(choice==3) // Minimum Wickets
            {
                if(temp[j].Wickets > temp[j+1].Wickets)
                {
                    t=temp[j];
                    temp[j]=temp[j+1];
                    temp[j+1]=t;
                }
            }
            else if(choice==4) // Maximum Wickets
            {
                if(temp[j].Wickets < temp[j+1].Wickets)
                {
                    t=temp[j];
                    temp[j]=temp[j+1];
                    temp[j+1]=t;
                }
            }
        }
    }

    printf("\nSorted Players\n");
    displayplayers(temp,currindex);
}

void main()
{
	
//	 Player parr[size];
	Player* parr=malloc(sizeof(Player)*size);
	
	int currindex;
	
//	printf("Enter how many player you want to add");
//	scanf("%d",&currindex);
//	storePlayer(parr,currindex);
	
	storeHardCoded(parr,&currindex);
	
	///////////////////////////////////////////////
	int exit;
	do
	{
	
		printf("Enter 1 to display\n");
		printf("Enter 2 to search\n");
		printf("Enter 3 to add player\n");
		printf("Enter 4 to delete player\n");
		printf("Enter 5 to update player\n");
		printf("Enter 6 to display Top 3 Players\n");
		printf("Enter 7 to Display Sorted Players\n");
		
	   int choice;
       int JerseyNumber;
       scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:
		
					printf("Player details are:\n");
					displayplayers(parr,currindex);
				break;
					
			case 2:
				    printf("Enter 1 to search by JerseyNumber\n");
					printf("Enter 2 to search by name\n");
					int subchoice;
					scanf("%d",&subchoice);
					
					if(subchoice==1)
					{
						printf("Enter JerseyNumber you want to search by");	
						int JerseyNumber;
						scanf("%d",&JerseyNumber);
			
						int index=searchByJerseyNumber(parr,currindex,JerseyNumber);
						
						
						if(index!=-1)
						{
							printf("\nPlayer Found\n");
                            printf("Jersey Number   : %d\n", parr[index].JerseyNumber);
                            printf("Name            : %s\n", parr[index].name);
                            printf("Runs            : %d\n", parr[index].Runs);
                            printf("Wickets         : %d\n", parr[index].Wickets);
                            printf("Matches Played  : %d\n", parr[index].Matchesplayed);
                        }
						else
							printf("not found");
				    }
				    else if(subchoice==2)
				    {
				    	printf("Enter name you want to search");
	                    char name[100];
	                    scanf("%s",name);
	                    
	                    int index=searchByname(parr,currindex,name);
	                    
	                    if(index!=-1)
	                    {
		                    printf("\nPlayer Found\n");
                            printf("Jersey Number   : %d\n", parr[index].JerseyNumber);
                            printf("Name            : %s\n", parr[index].name);
                            printf("Runs            : %d\n", parr[index].Runs);
                            printf("Wickets         : %d\n", parr[index].Wickets);
                            printf("Matches Played  : %d\n", parr[index].Matchesplayed);
                        }
                        else
                	    printf("not found");
	                    
					}
					
				break;
				
			case 3:
				{
				
				Player play;

                printf("Enter Jersey Number: ");
                scanf("%d",&play.JerseyNumber);

                if(play.JerseyNumber <= 0)
                {
                   printf("Jersey Number must be greater than 0\n");
                   break;
                }

                printf("Enter Name: ");
                scanf("%s",play.name);

                printf("Enter Runs: ");
                scanf("%d",&play.Runs);

                if(play.Runs < 0)
                {
                    printf("Runs cannot be negative\n");
                    break;
                }

                printf("Enter Wickets: ");
                scanf("%d",&play.Wickets);

                if(play.Wickets < 0)
                {
                    printf("Wickets cannot be negative\n");
                    break;
                }

                printf("Enter Matches Played: ");
                scanf("%d",&play.Matchesplayed);

                if(play.Matchesplayed < 0)
                {
                    printf("Matches Played cannot be negative\n");
                    break;
                }

                parr=addPlayer(parr,&currindex,&play);
			
			    }
			    break;
			case 4: printf("Enter JersyNumber you want to delete");
					
					scanf("%d",&JerseyNumber);
					deletePlayerByJerseyNumber(parr,&currindex,JerseyNumber);
					break;
					
			case 5: printf("Enter JerseyNumber of player you want to update");
					scanf("%d",&JerseyNumber);
					updatePlayer(parr,currindex,JerseyNumber);
					break;
					
			case 6:
                   top3Players(parr,currindex);
                   break;
				   		
			        default:printf("Invalid choice");
			
			case 7:
                    {
                    int sortChoice;

                    printf("enter 1 Minimum Runs");
                    printf("enter 2 Maximum Runs");
                    printf("enter 3 Minimum Wickets");
                    printf("enter 4 Maximum Wickets");

                    printf("\nEnter your choice : ");
                    scanf("%d",&sortChoice);

                    displaySortedPlayers(parr,currindex,sortChoice);
                    break;
                    }
			
			
		}
		printf("\nDo you want to continue 1/0......");
		scanf("%d",&exit);
	}while(exit==1);
}//main ends here