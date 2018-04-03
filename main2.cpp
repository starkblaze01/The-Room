#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>


int num,num2,num3;//for switch cases
int *p,*p2;  //for back option 

void dispscore(int i,int j,int s,int a){//display the score
	int score=(i*i+j*j)*100+1000*(3-s)-(a*1);
	printf("\t\t\t SCORE\n");
	printf("\tSCORE %d\t\t\tLIFE %d\n\n\n",score,3-s);	
	}

int  retscore(int i,int j,int s,int a){
	int score=(i*i+j*j)*100+1000*(3-s)-(a*1);
  	return score;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void prntarr(char A[20][20]){//print the array
	int i=0,j=0,s=0;
	system("color 4a");
        while(i<20)
        {	j=0;
         	while(j<20){printf("%c  ",A[i][j]);
                j++;
	}
        i++;
        printf("\n\n");}
        printf("\n\n");
}

void timeconv(int a){//convert sec into HH:MM:SS format
	int sec,min,hour;
	min=a/60;
	hour=a/3600;
	while(a>=60){a=a-60;}
	printf("You Have Taken time %02d:%02d:%d\n\n",hour,min,a);
	}
			               
void chngarr(char A[20][20],int a,int t[3][2][100],int b){//changes '.' to '#' 
	int i=0;
	while(i<b){
		A[t[a][0][i]][t[a][1][i]]='#';
   		i++;
	}
}

void rechngarr(char A[20][20],int a,int t[3][2][100],int b){//changes '#' to '.'
	int i=0;
	while(i<b){
 		A[t[a][0][i]][t[a][1][i]]='.';
   		i++;
	}
}

void instr(){
	printf("\t\t\t\tINSTRUCTIONS\n\n        \t\t1. PRESS- 'W' TO MOVE UP\n        \t\t          'S' TO MOVE DOWN\n        \t\t          'A' TO MOVE LEFT\n        \t\t          'D' TO MOVE RIGHT\n	\t\t2. '.' IS CHANGING INTO '#' AT PARTICULAR TIME INTERVAL\n	\t\t3. YOU LOSE ONE LIFE IF YOU STEPPED ON '#'\n	\t\t4. REACH AT POSITION 'E' TO WIN THE GAME\n        \t\t5. THREE LIVES HAS BEEN GIVEN FOR EACH NEW GAME\n	\t\t6. TO SCORE HIGH- a) COVER MORE DISTANCE\n	\t\t	          b) USE LESS LIVES\n\t\t  		          c) COMPLETE THE GAME IN LESS TIME\n");
   	delay(5000);
}





int main(){
	FILE *b10;//save records
	char A[20][20]={' '};
	char name[100];
	int t[3][2][100],sc[3];// 3D array for delay and sc for leaderboard 
	sc[0]=sc[1]=sc[2]=0;
	int ai=19,aj=0,re;
	time_t a,b,td;//records time and difference 
	int n=1,m=1,o=1;
	char ch,s;
	int i=0,j=0,tstore;
	system("COLOR 4F");
	printf("\n\n\n\n\n\n\n\t\t\t\t---------------------------------------------------\n\t\t\t\t|\t\t\tMENU\t\t\t  |\n\t\t\t\t---------------------------------------------------");
	printf("\n\t\t\t\t|\t\t\t\t\t\t  |\n\t\t\t\t|\t\t    1.Start Game\t\t  |\n\t\t\t\t|\t\t\t\t\t\t  |\n\t\t\t\t|\t\t    2.Leaderboard\t\t  |\n\t\t\t\t|\t\t\t\t\t\t  |\n\t\t\t\t|\t\t    3.Quit\t\t\t  |\n\t\t\t\t|\t\t\t\t\t\t  |\n\t\t\t\t---------------------------------------------------\n\t\t\t\t");

	if(p==NULL){
		scanf("%d",&num);}
		system("cls");

		switch(num)
		{
			case 1: printf("\n\n\t\t\t\t\tDifficulty level\n\n\t\t1.Beginner\n\n\t\t2.Amateur\n\n\t\t3.Advance\n\n\t\t0.Back\n\n\n\t\t");
				if(p2==NULL)
				{
					scanf("%d",&num2);}
		        		system("cls");
		        		switch(num2)
		             		{
		        		case 1:printf("\n\n\t\t\t\t\tSelect Grid Size\n\n\t\t1.10*10\n\n\t\t2.15*15\n\n\t\t3.20*20\n\n\t\t0.BACK\n\n\t\t");
		        	       	if(p2==NULL)
						    {scanf("%d",&num3);}
		        	        system("cls");
		        	        switch(num3)
		        	           {case 1:
		        	           	instr();
		        	           	   ai=9;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<10)
                                		{j=0;
                                  while(j<10){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<8){t[i][0][j]=rand()%10;
                      								t[i][1][j]=rand()%10;
                      						while((t[i][0][j]==0&&t[i][1][j]==9)||(t[i][0][j]==9&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%10;
                             							t[i][1][j]=rand()%10;}
                            								 j++;}
        								 i++;}
								A[0][9]='E';
								A[9][0]='A';

   								 a=b=time(NULL);//assign them both calender value
							     prntarr(A);


								while(!(ai==0&&aj==9))//game starts
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>9){ai=9;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>9){aj=9;}
        		          											 break;}}
    
        		           
		            // time delay paraller for 3 different time units thats why # and . changing each other
												if(b==a+3*n&&n%2!=0)
         											 {chngarr(A,0,t,8);
          											 n++;}
           										else if (b==a+3*n)
               												{rechngarr(A,0,t,8);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,8);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,8);
                    											m++;}
           										if(b==a+7*o&&o%2!=0)
          												{chngarr(A,2,t,8);
           												 o++;}
           										else if(b==a+7*n)
                   											{chngarr(A,2,t,8);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)//out 
			                  												{case 1:system("cls");
			                  												       p=NULL;
			                  												       p2=NULL;
							           										       main();
									   										        break;
							   												 case 2:exit(0);	
							             											break;
																			 case 0 :num=1;
																			         num2=1;
																			         num3=1;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																			 
																		default :exit(0);	
							             											break;		 
																					 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][9]='E';
          										 b=time(NULL);  //assign b real time value
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a; //time difference after game
          										 timeconv(td);
          										 tstore=retscore(9,9,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("beg10.txt","a");//file handling starts
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=NULL;
           											p2=NULL;
           											main();
        											break;//beginner 10*10 ends
        			// just use that code for make many levels 								
        		               case 2:   //beginner 15*15 starts
        		                 instr();
		        	           	   ai=14;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<15)
                                		{j=0;
                                  while(j<15){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<18){t[i][0][j]=rand()%15;
                      								t[i][1][j]=rand()%15;
                      						while((t[i][0][j]==0&&t[i][1][j]==14)||(t[i][0][j]==14&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%15;
                             							t[i][1][j]=rand()%15;}
                            								 j++;}
        								 i++;}
								A[0][14]='E';
								A[14][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==14))//game starts
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>14){ai=14;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>14){aj=14;}
        		          											 break;}}
    
        		           
		            //run 3 type of delay
												if(b==a+3*n&&n%2!=0)
         											 {chngarr(A,0,t,18);
          											 n++;}
           										else if (b==a+3*n)
               												{rechngarr(A,0,t,18);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,18);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,18);
                    											m++;}
           										if(b==a+7*o&&o%2!=0)
          												{chngarr(A,2,t,18);
           												 o++;}
           										else if(b==a+7*n)
                   											{chngarr(A,2,t,18);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=NULL;
			                  												p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=1;
																			         num3=2;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																			default :exit(0);	
							             											break;		 
																					  }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][14]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(14-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(14,14,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("beg15.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break;//beginner 15*15 ends
								 case 3: //beginner 20*20 starts
								 instr();
		        	           	   ai=19;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<20)
                                		{j=0;
                                  while(j<20){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<33){t[i][0][j]=rand()%20;
                      								t[i][1][j]=rand()%20;
                      						while((t[i][0][j]==0&&t[i][1][j]==19)||(t[i][0][j]==19&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%20;
                             							t[i][1][j]=rand()%20;}
                            								 j++;}
        								 i++;}
								A[0][19]='E';
								A[19][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==19))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>19){ai=19;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>19){aj=19;}
        		          											 break;}}
    
        		           
		            
												if(b==a+3*n&&n%2!=0)
         											 {chngarr(A,0,t,33);
          											 n++;}
           										else if (b==a+3*n)
               												{rechngarr(A,0,t,33);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,33);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,33);
                    											m++;}
           										if(b==a+7*o&&o%2!=0)
          												{chngarr(A,2,t,33);
           												 o++;}
           										else if(b==a+7*n)
                   											{chngarr(A,2,t,33);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
							           										p=p2=NULL;
																			  main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=1;
																			         num3=3;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break;
																					 
																			default :exit(0);	
							             											break;			 
																					  		 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][19]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(19,19,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("beg20.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break;//beginner 20*20 ends
													
							case 0:num=1; //back option using pointer
							        p=&num;
							        main();
							        break;						
													}					
													
					// amateur level starts 								
						case 2:printf("\n\n\t\t\t\t\tSelect Grid Size\n\n\t\t1.10*10\n\n\t\t2.15*15\n\n\t\t3.20*20\n\n\t\t0.Back\n\n\t\t");
		        	       if(p2==NULL)
						     {scanf("%d",&num3);}
		        	        system("cls");
		        	        switch(num3)
		        	           {case 1: // amateur 10*10 starts 
		        	           	   instr();
									  ai=9;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<10)
                                		{j=0;
                                  while(j<10){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<17){t[i][0][j]=rand()%10;
                      								t[i][1][j]=rand()%10;
                      						while((t[i][0][j]==0&&t[i][1][j]==9)||(t[i][0][j]==9&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%10;
                             							t[i][1][j]=rand()%10;}
                            								 j++;}
        								 i++;}
								A[0][9]='E';
								A[9][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==9))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>9){ai=9;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>9){aj=9;}
        		          											 break;}}
    
        		           
		            
												if(b==a+2*n&&n%2!=0)
         											 {chngarr(A,0,t,17);
          											 n++;}
           										else if (b==a+2*n)
               												{rechngarr(A,0,t,17);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,17);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,17);
                    											m++;}
           										if(b==a+6*o&&o%2!=0)
          												{chngarr(A,2,t,17);
           												 o++;}
           										else if(b==a+6*n)
                   											{chngarr(A,2,t,17);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=2;
																			         num3=1;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break;
																					  
																			default :exit(0);	
							             											break;			 		 
																					 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][9]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(9,9,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("med10.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break; // amateur 10*10 ends
        		               case 2: // amateur 15*15 starts
        		               instr();
		        	           	   ai=14;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<15)
                                		{j=0;
                                  while(j<15){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<38){t[i][0][j]=rand()%15;
                      								t[i][1][j]=rand()%15;
                      						while((t[i][0][j]==0&&t[i][1][j]==14)||(t[i][0][j]==14&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%15;
                             							t[i][1][j]=rand()%15;}
                            								 j++;}
        								 i++;}
								A[0][14]='E';
								A[14][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==14))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>14){ai=14;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>14){aj=14;}
        		          											 break;}}
    
        		           
		            
												if(b==a+2*n&&n%2!=0)
         											 {chngarr(A,0,t,38);
          											 n++;}
           										else if (b==a+2*n)
               												{rechngarr(A,0,t,38);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,38);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,38);
                    											m++;}
           										if(b==a+6*o&&o%2!=0)
          												{chngarr(A,2,t,38);
           												 o++;}
           										else if(b==a+6*n)
                   											{chngarr(A,2,t,38);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=2;
																			         num3=2;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break;
																				default :exit(0);	
							             											break;		  		 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][14]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(14-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(14,14,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("med15.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break;//amateur 15*15 ends
								 case 3: // amateur 20*20 starts
		        	           	   instr();
									  ai=19;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<20)
                                		{j=0;
                                  while(j<20){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<67){t[i][0][j]=rand()%20;
                      								t[i][1][j]=rand()%20;
                      						while((t[i][0][j]==0&&t[i][1][j]==19)||(t[i][0][j]==19&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%20;
                             							t[i][1][j]=rand()%20;}
                            								 j++;}
        								 i++;}
								A[0][19]='E';
								A[19][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==19))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>19){ai=19;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>19){aj=19;}
        		          											 break;}}
    
        		           
		            
												if(b==a+2*n&&n%2!=0)
         											 {chngarr(A,0,t,67);
          											 n++;}
           										else if (b==a+2*n)
               												{rechngarr(A,0,t,67);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,67);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,67);
                    											m++;}
           										if(b==a+6*o&&o%2!=0)
          												{chngarr(A,2,t,67);
           												 o++;}
           										else if(b==a+6*n)
                   											{chngarr(A,2,t,67);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=2;
																			         num3=3;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																					 
																					default :exit(0);	
							             											break;			 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][19]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(19,19,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("med20.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break; // amateur 20*20 ends
										case 0:num=1; // back option 
							                  p=&num;
							                  main();
							                  break;				
							            
										default :exit(0);	
							             		break;	
													}	
													
							case 3:printf("\n\n\t\t\t\t\tSelect Grid Size\n\n\t\t1.10*10\n\n\t\t2.15*15\n\n\t\t3.20*20\n\n\t\t0.Back\n\n\t\t");//advance level starts
		        	       if(p2==NULL) {scanf("%d",&num3);}
		        	        system("cls");
		        	        switch(num3)
		        	           {case 1://advance 10*10 starts
		        	           instr();
		        	           	   ai=9;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<10)
                                		{j=0;
                                  while(j<10){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<25){t[i][0][j]=rand()%10;
                      								t[i][1][j]=rand()%10;
                      						while((t[i][0][j]==0&&t[i][1][j]==9)||(t[i][0][j]==9&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%10;
                             							t[i][1][j]=rand()%10;}
                            								 j++;}
        								 i++;}
								A[0][9]='E';
								A[9][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==9))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>9){ai=9;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>9){aj=9;}
        		          											 break;}}
    
        		           
		            
												if(b==a+1*n&&n%2!=0)
         											 {chngarr(A,0,t,25);
          											 n++;}
           										else if (b==a+1*n)
               												{rechngarr(A,0,t,25);
                											 n++;}
           										if(b==a+2*m&&m%2!=0)
          												{chngarr(A,1,t,25);
           												 m++;}
           										else if (b==a+2*m)
                  											{rechngarr(A,1,t,25);
                    											m++;}
           										if(b==a+4*o&&o%2!=0)
          												{chngarr(A,2,t,25);
           												 o++;}
           										else if(b==a+4*n)
                   											{chngarr(A,2,t,25);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=3;
																			         num3=1;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																					 default :exit(0);	
							             											break;			 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][9]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(9,9,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("adv10.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break; // advance 10*10 ends;
        											
        		               case 2:  // advance 15*15 starts
		        	           	 instr();  
								 ai=14;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<15)
                                		{j=0;
                                  while(j<15){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<54){t[i][0][j]=rand()%15;
                      								t[i][1][j]=rand()%15;
                      						while((t[i][0][j]==0&&t[i][1][j]==14)||(t[i][0][j]==14&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%15;
                             							t[i][1][j]=rand()%15;}
                            								 j++;}
        								 i++;}
								A[0][14]='E';
								A[14][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==14))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>14){ai=14;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>14){aj=14;}
        		          											 break;}}
    
        		           
		            
												if(b==a+1*n&&n%2!=0)
         											 {chngarr(A,0,t,54);
          											 n++;}
           										else if (b==a+1*n)
               												{rechngarr(A,0,t,54);
                											 n++;}
           										if(b==a+2*m&&m%2!=0)
          												{chngarr(A,1,t,54);
           												 m++;}
           										else if (b==a+2*m)
                  											{rechngarr(A,1,t,54);
                    											m++;}
           										if(b==a+4*o&&o%2!=0)
          												{chngarr(A,2,t,54);
           												 o++;}
           										else if(b==a+4*n)
                   											{chngarr(A,2,t,54);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Restart\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=3;
																			         num3=2;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																					 default :exit(0);	
							             											break;			 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][14]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(14-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(14,14,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("adv15.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break; // advance 15*15 ends
								 case 3: // advance 20*20 starts
		        	           	  instr();
									  ai=19;
		        	           	   aj=0;
		        	           	  s=0;
                                  while(i<20)
                                		{j=0;
                                  while(j<20){A[i][j]='.';
                                              j++;}
                                        i++;}

									i=0;
								srand(time(NULL));
								while(i<3)
        							{j=0;
        								 while(j<100){t[i][0][j]=rand()%20;
                      								t[i][1][j]=rand()%20;
                      						while((t[i][0][j]==0&&t[i][1][j]==19)||(t[i][0][j]==19&&t[i][1][j]==0))
                            							{t[i][0][j]=rand()%20;
                             							t[i][1][j]=rand()%20;}
                            								 j++;}
        								 i++;}
								A[0][19]='E';
								A[19][0]='A';

   								 a=b=time(NULL);
							     prntarr(A);


								while(!(ai==0&&aj==19))
       									 {if(kbhit())
        		 								{ch=getch();
        		 								 switch(ch)
        		 									 {
			     										 case 'w' :A[ai][aj]='.'; 
				  													ai-=1;
			                 									  if(ai<0){ai=0;}
        		          										 break;
        		           
        		  										  case 'a' :A[ai][aj]='.'; 
				  			                                         aj-=1;
        		             										if(aj<0){aj=0;}
        		          											 break;
        		           
        		  										   case 's' :A[ai][aj]='.'; 
				           												 ai+=1;
        		            										  if(ai>19){ai=19;}
        		          											 break;
        		 										   case 'd' : A[ai][aj]='.';
				             											aj+=1;
        		             										 if(aj>19){aj=19;}
        		          											 break;}}
    
        		           
		            
												if(b==a+2*n&&n%2!=0)
         											 {chngarr(A,0,t,100);
          											 n++;}
           										else if (b==a+2*n)
               												{rechngarr(A,0,t,100);
                											 n++;}
           										if(b==a+4*m&&m%2!=0)
          												{chngarr(A,1,t,100);
           												 m++;}
           										else if (b==a+4*m)
                  											{rechngarr(A,1,t,100);
                    											m++;}
           										if(b==a+6*o&&o%2!=0)
          												{chngarr(A,2,t,100);
           												 o++;}
           										else if(b==a+6*n)
                   											{chngarr(A,2,t,100);
                    										 o++;}
            									if(A[ai][aj]=='#'){s++;
                           										if(s==3)
						   											{
						   											printf("You Are Out\n\nPress 1 for GO TO Main Menu\n\nPress 2 for exit\n\n0.Return\n\n");
			                 										scanf("%d",&re);
			                 										switch(re)
			                  												{case 1:system("cls");
			                  												p=p2=NULL;
							           										 main();
									   										 break;
							   												 case 2:exit(0);	
							             											break;
																			case 0 :num=1;
																			         num2=3;
																			         num3=3;
																					 p2=&num2;
																					 p=&num;
																					 
																					 system("cls");
																					 main();
																					 break; 
																					default :exit(0);	
							             											break;			 }}
										 
															       else{printf("You are Out %d life left\n\n",3-s);
								      								 delay(1000); }		 }   
								
          										 A[ai][aj]='A';
          										 A[0][19]='E';
          										 b=time(NULL);
           										 delay(300);
           										 system("cls");
           										 td=b-a;
           										dispscore(19-ai,aj,s,td);
           										prntarr(A);}
          										 td=b-a;
          										 timeconv(td);
          										 tstore=retscore(19,19,s,td);
           										 printf("YOUR FINAL SCORE IS %d\n\n",tstore);
           										b10=fopen("adv20.txt","a");
          										 printf("Enter Your name\t\t");
          										 scanf("%s",name);
          										 fprintf(b10,"%s\t\t%d\n",name,tstore);
           											fclose(b10);
           											printf("\n\nTHANK YOU FOR USING\n\n");
           											delay(2000);
           											system("cls");
           											p=p2=NULL;
           											main();
        											break;
										case 0:num=1;
							                 p=&num;
							                main();
							                break; // advance 20*20 ends				
													
					
													}	
					    case 0 : system("cls");//back option 
					             p=p2=NULL;
						         main();
								 break;							
						default :exit(0);	
							    break;			 	
													}
        		// leaderboard sorting and display									
			case 2: 										
					printf(" \t\t\t\t\tChose Level\n\n\t\t1. Beginner(10*10)\n\n\t\t2. Beginner(15*15)\n\n\t\t3. Beginner(20*20)\n\n\t\t4. Amateur(10*10)\n\n\t\t5. Amateur(15*15)\n\n\t\t6. Amateur(20*20)\n\n\t\t7. Advance(10*10)\n\n\t\t8. Advance(15*15)\n\n\t\t9. Advance(20*20)\n\n\n\t\t0.BACK\n\n\n\t\t");																			
					scanf("%d",&num3);
					system("cls");
					printf("\t\t\tHigh Scores\n\n");
					switch(num3) 
					{case 1:printf("1."); 
				     b10=fopen("beg10.txt","r"); // open file
					 // read and give maximun and stores in sc[0] 
				     fscanf(b10,"%s %d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s %d",name,&tstore);}
					             fclose(b10);//closes file
					// again open the file and find 2 next highest score and store in sc[1] and sc[2]
					 b10=fopen("beg10.txt","r");
					 fscanf(b10,"%s %d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s %d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("beg10.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);//close file
					     // display top 3 maximum score        
					 b10=fopen("beg10.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}//display top 3 leaderboard
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//beginner 10*10 ends , now just use same for 8 others 
			case 2:printf("1.");   // beginner 15*15 starts
				     b10=fopen("beg15.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("beg15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("beg15.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("beg15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
									
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;		// beginner 15*15 ends			
				case 3:printf("1.");// beginner 20*20 starts
				     b10=fopen("beg20.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("beg20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("beg20.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("beg20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;  // beginner 20*20 ends				
				case 4:printf("1."); // amateur 10*10 starts 
				     b10=fopen("med10.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {
									if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med10.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("med10.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med10.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//amateur 10*10 ends						  
										  
					case 5:printf("1.");//amateur 15*15 starts
				     b10=fopen("med15.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("med15.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//amateur 15*15 ends					  	
													
				case 6:printf("1.");//amateur 20*20 starts
				     b10=fopen("med20.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("med20.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("med20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//amateur 20*20 ends									
				case 7:printf("1.");//advance 10*10 starts
				     b10=fopen("adv10.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv10.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("adv10.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv10.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;	//advance 10*10 ends									
				case 8:printf("1.");//advance 15*15 starts
				     b10=fopen("adv15.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("adv15.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv15.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//advance 15*15 ends
				case 9:printf("1.");//advance 20*20 starts
				     b10=fopen("adv20.txt","r");
				     fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]<=tstore){sc[0]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[0]==tstore){printf("%s\t\t%d\n  ",name,sc[0]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10); 
						 for(j=1;j<3;j++)            
								{ printf("\n%d.",j+1); 
								b10=fopen("adv20.txt","r");
								fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]<=tstore&&tstore<sc[j-1]) {sc[j]=tstore;}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);
					 b10=fopen("adv20.txt","r");
					 fscanf(b10,"%s%d",name,&tstore);
					      while(!feof(b10))
					                {if(sc[j]==tstore){printf("%s\t\t%d\n  ",name,sc[j]);}
									fscanf(b10,"%s%d",name,&tstore);}
					             fclose(b10);}
					    printf("\nENTER ANY NUMBER TO GO TO MAIN MENU ");
					    scanf("%d",&s);
					    system("cls");
					    main();
					    break;//advance 20*20 ends	
			//to go back to main menu			
			case 0: system("cls");
			         main();
			         break;			
	        default :exit(0);	
						break;						
						}				
												
											
			//to exit the game									
		case 3 : p=p2=NULL;
		         printf("\t\t\tTHANKS FOR USING\n\n\t\t\t");	
				 exit(0);											
				  break;}
			return 0;
			
				
			}
   

