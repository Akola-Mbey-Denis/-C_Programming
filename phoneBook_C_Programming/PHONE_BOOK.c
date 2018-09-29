
/***********************************************************************/
/***Writtten By:Akola Mbey Denis                                       */
/***Date Written:20-03-2017                                            */
*/                                                                     */
***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{int response;
char *lname[20]={0};
char *fname[20]={0};
char*number[20]={0};
FILE*PWRITE;
FILE*PREAD;
printf("\n\tTHIS IS A PHONE BOOK PROGRAM\n");
printf("INSTRUCTIONS:\n 1:ADD PHONE BOOK ENTRY\n2:PRINT PHONE BOOK\n\n");
printf("SELECT AN OPTION\n");
scanf("%d",&response);
if (response==1)
{
	/*user is adding a new phone book entry */
	/*-get information*/
	
	printf("\nEnter first name:");
	scanf("%s",fname);
	printf("\nEnter the last name:");
	scanf("%s",lname);
	printf("\n enter phone number:");
	scanf("%s",number);
PWRITE=fopen("fileopener.txt","a");
if(PWRITE!=NULL)
{

fprintf(PWRITE,"%s\t%s%\t%s\n",fname,lname,number)	;
fclose(PWRITE);

	
	}
	else{

	goto ERRORH;	//problem encountered;file error	
}
}
else if(response==2)
/*user wants to print the phone book*/
{
PREAD=fopen("fileopener.txt","r");
if(PREAD!=NULL){
	//printf("\n Display phone book enteries\n");
	printf("Name\t\t\tPhone Number");
	while(!feof(PREAD))//BEGINING OF THE WHILE LOOP
	{
		fscanf(PREAD,"%s%s%s",fname,lname,number);	
if(!feof(PREAD))

{
printf("\n%s\t%s\t%s",fname,lname,number);
}//END OF WHILE LOOP
printf("\n");
}
}
else 
goto ERRORH;//THERE IS A FILE I/O ERROR
}
else
{
	printf("\ninvalid selection\n");
}
exit(EXIT_SUCCESS);

ERRORH:
perror("The following error occurred:");
exit(EXIT_FAILURE);
}

