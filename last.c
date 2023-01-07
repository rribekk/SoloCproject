#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char name[25];
	int roll;
		struct subject{
			float math;
			float eng;
			float sci;
			float soc;
			float nep;
		}sub;
};

void add();
void bulk();
void list();
void search();
void select();
void astrik(){
	int i, n=120;	
	printf("\n\n");
	for(i=0;i<n;i++){
		printf("*");
	}
}
	//lets start//
		
int main(){
	int patt;
	char choice[2];
	do{
		printf("\n\n");
		for(patt=0;patt<45;patt++)
		{
			printf("**");
		}	
	printf("\n\n");
	printf("1. Add a record\n");
	printf("2. Add bulk records\n");
	printf("3. List students\n");
	printf("4. Search Student\n");
	printf("5. Quit\n");
	printf("What is your choice?:\n");
	scanf("%[^\n]",choice);
	fflush(stdin);
	select(choice);
    } while(strcmp(choice,"5")!=0);
	
	return 0;
}
	
//After choice selection.
void select(char chc[2])
{
	if(strcmp(chc,"1")==0)
	{
		add();
	}
	else if(strcmp(chc,"2")==0)
	{
		bulk();
	}
	else if(strcmp(chc,"3")==0)
	{
		list();
	}
	else if(strcmp(chc,"4")==0)
	{
		search();
	}
	else if(strcmp(chc,"5")==0)
	{
		exit(0);
	}
	else if(strcmp(strupr(chc),"CLS")==0)
	{
		system("cls");
	}
	else
	{
		printf("wrong input!(1-5)");
	}
}

// adding record//
void add()
{
	int n;
	n=1;
	struct student s[n];
	
	int j;
	int patt;
	printf("\n\n");
		for(patt=0;patt<45;patt++)
		{
			printf("**");
		}
	FILE *fp;
	fp=fopen("stdata.txt","a");
	for(j=0;j<n;j++)
	{
		printf("\n\n");
		printf("\nEnter the information for student no.%d :",j+1);
			fflush(stdin);
		printf("\nEnter name : ");
		scanf("%[^\n]",s[j].name);
			fflush(stdin);
		printf("\nEnter Roll No.: ");
		scanf("%d",&s[j].roll);
			fflush(stdin);
		printf("\nEnter Marks in Mathematics : ");
		scanf("%f",&s[j].sub.math);
			fflush(stdin);
			printf("\nEnter Marks in Science : ");
		scanf("%f",&s[j].sub.sci);
			fflush(stdin);
			printf("\nEnter Marks in English : ");
		scanf("%f",&s[j].sub.eng);
			fflush(stdin);
			printf("\nEnter Marks in Nepali : ");
		scanf("%f",&s[j].sub.nep);
			fflush(stdin);
			printf("\nEnter Marks in Social : ");
		scanf("%f",&s[j].sub.soc);
			fflush(stdin);
		fwrite(&s[j],sizeof(struct student),1,fp);
	}
		fclose(fp);
}

//Adds bulk records.
void addBulk()
{
	int n;	
	int j;
	int patt;
	printf("\n\n");
		for(patt=0;patt<45;patt++)
		{
			printf("**");
		}
	
	printf("\n Enter the number of Students:");
	scanf("%d",&n);
	struct student s[n];
	FILE *fp;
	fp=fopen("stdata.txt","a");
	for(j=0;j<n;j++)
	{
		printf("\n\n");
		printf("\nEnter the information for student no.%d :",j+1);
			fflush(stdin);
		printf("\nEnter name : ");
		scanf("%[^\n]",s[j].name);
			fflush(stdin);
		printf("\nEnter Roll No. : ");
		scanf("%d",&s[j].roll);
			fflush(stdin);
		printf("\nEnter Marks in Mathematics : ");
		scanf("%f",&s[j].sub.math);
			fflush(stdin);
			printf("\nEnter Marks in Science : ");
		scanf("%f",&s[j].sub.sci);
			fflush(stdin);
			printf("\nEnter Marks in English : ");
		scanf("%f",&s[j].sub.eng);
			fflush(stdin);
			printf("\nEnter Marks in Nepali : ");
		scanf("%f",&s[j].sub.nep);
			fflush(stdin);
			printf("\nEnter Marks in Social : ");
		scanf("%f",&s[j].sub.soc);
			fflush(stdin);
		fwrite(&s[j],sizeof(struct student),1,fp);
	}
		fclose(fp);
}

//providing list of data
void list()
{
	int patt;
	FILE *fp;
	fp=fopen("studentData.txt","r");
	struct student s;
	
		printf("\n\n");
		for(pattern=0;pattern<45;pattern++)
		{
			printf("**");
		}
		printf("\nRoll\t Name");
	while(fread(&s,sizeof(struct student),1,fp))
	{
		printf("\n%-4d\t %-20s",s.rN,s.name);
	}
	
	fclose(fp);	
}

//searching data
void search2();
void search()
{
	int pattern;
	int rollN;
	FILE *fp;
	int found=0;
	fp=fopen("studentData.txt","r");
	struct student s;
	
		printf("\n\n");
		for(pattern=0;pattern<45;pattern++)
		{
			printf("**");
		}
		
		printf("\n\n");
		printf("\nEnter Roll No: ");
		scanf("%d",&rollN);
		fflush(stdin);
		
		while(fread(&s,sizeof(struct student),1,fp))
		{
			if(rollN==s.rN)
			{
				found=1;
				for(pattern=0;pattern<45;pattern++)
				{
					printf("**");
				}
				printf("\n\n");
				printf("Record Found:");
				printf("\nStudent Name: %s",s.name);
				search2(rollN);
			}
		}
		if(!found)
		{
			for(pattern=0;pattern<45;pattern++)
			{
				printf("**");
			}
			printf("\n\nRecord Not Found! ");
		}
	
	fclose(fp);		
}
void markSheet();
void edit();
void del();

//Options for searched data.
void search2(int rN2)
{
	char choice[2];
	int pattern;
	printf("\n\n");
	for(pattern=0;pattern<45;pattern++)
	{
		printf("**");
	}	
	do
	{
		printf("\n\n");
		printf("\n1.Edit Record");
		printf("\n2.Delete Record");
		printf("\n3.View Marksheet");
		printf("\n4.Quit");
		printf("\nWhat is your choice? : ");
		scanf("%[^\n]",choice);
		fflush(stdin);
		if(strcmp(choice,"1")==0)
		{
			edit(rN2);
			main();
		}
		else if(strcmp(choice,"2")==0)
		{
			del(rN2);
			main();
		}
		else if(strcmp(choice,"3")==0)
		{
			markSheet(rN2);
			main();
		}
		else if(strcmp(choice,"4")==0)
		{
			main();
		}
		else
		{
			printf("WRONG INPUT!(1-4)");
		}
	}while(strcmp(choice,"4")!=0);
}

//editing data
void edit(int rN2)
{
	int pattern;
	printf("\n\n");
	for(pattern=0;pattern<45;pattern++)
	{
		printf("**");
	}
	
	struct student s;
	FILE *fp,*f;
	fp= fopen("studentData.txt","r");
	f= fopen("temp.txt","w");
	while(fread(&s,sizeof(struct student),1,fp))
	{
		if(rN2==s.rN)
		{	
			fflush(stdin);
			printf("\nEnter name : ");
			scanf("%[^\n]",s.name);
			fflush(stdin);
			printf("Enter Marks in Mathematics : ");
			scanf("%f",&s.sub.math);
			fflush(stdin);
			printf("Enter Marks in Science : ");
			scanf("%f",&s.sub.sci);
			fflush(stdin);
			printf("Enter Marks in English : ");
			scanf("%f",&s.sub.eng);
			fflush(stdin);
			printf("Enter Marks in Nepali : ");
			scanf("%f",&s.sub.nep);
			fflush(stdin);
			printf("Enter Marks in Social : ");
			scanf("%f",&s.sub.soc);
			fflush(stdin);
		}
		
		fwrite(&s,sizeof(struct student),1,f);
	}
	fclose(fp);
	fclose(f);
	
	printf("\n\n");
	for(pattern=0;pattern<45;pattern++)
	{
		printf("**");
	}

		fp= fopen("studentData.txt","w");
		f= fopen("temp.txt","r");
		
		while(fread(&s,sizeof(struct student),1,f))
		{
			fwrite(&s,sizeof(struct student),1,fp);
		}
			printf("\nRecord Updated! !");
		fclose(fp);
		fclose(f);
}

//Delete the data.
void del(int rN3)
{
	struct student s;
	int pattern;
	FILE *fp,*f;
	int found=0;
	printf("\n\n");
	for(pattern=0;pattern<45;pattern++)
	{
		printf("**");
	}		

	fp= fopen("studentData.txt","r");
	f= fopen("temp.txt","w");
	while(fread(&s,sizeof(struct student),1,fp))
	{
		if(rN3==s.rN)
		{
			found=1;
		}
		else
		fwrite(&s,sizeof(struct student),1,f);
	}
	fclose(fp);
	fclose(f);
	
	fp= fopen("studentData.txt","w");
	f= fopen("temp.txt","r");
	
	if(found)
	{
		while(fread(&s,sizeof(struct student),1,f))
		{
			fwrite(&s,sizeof(struct student),1,fp);
			
		}
		fclose(fp);
		fclose(f);
			printf("\n\n");
			for(pattern=0;pattern<45;pattern++)
			{
				printf("**");
			}
			printf("\nRecord Deleted! !");
			getch();
			main();	
	}			
}

void markSheet(int rN2)
{
	stars();
	FILE *fp;
	struct student s;
	fp=fopen("studentData.txt","r");
	
	while(fread(&s,sizeof(struct student),1,fp))
	{
		if(rN2==s.rN)
		{
			printf("\nST.XAVIER'S COLLEGE");
			printf("\nSECOND TERM EXAMINATION");
			stars();
			printf("\n|\tNAME : %s",s.name);
			printf("\n|\tROLL : %d",s.rN);
			stars();
			printf("\n|\tS.N\t| \t\tSubjects\t| \tMarks");
			stars();
			printf("\n|\t1.\t| \t\tMathematics\t| \t%.2f",s.sub.math);
			printf("\n|\t2.\t| \t\tScience\t\t| \t%.2f",s.sub.sci);
			printf("\n|\t3.\t| \t\tEnglish\t\t| \t%.2f",s.sub.eng);
			printf("\n|\t4.\t| \t\tNepali\t\t| \t%.2f",s.sub.nep);
			printf("\n|\t5.\t| \t\tSocial\t\t| \t%.2f",s.sub.soc);
			stars();
			float sum;
			sum=s.sub.math+s.sub.sci+s.sub.eng+s.sub.nep+s.sub.soc;
			float per;
			per=sum/5;
			printf("\n|\t\t| \t\tPercentage\t| \t%%%.2f",per);
			char div[20];
			if(per>=80)
			{
				strcpy(div,"DISTINCTION");
			}
			else if(per>=70&& per<80)
			{
			strcpy(div,"FIRST");
			}
			else if(per>=40&&per<70)
			{
				strcpy(div,"SECOND");
			}
			else
			{
			strcpy(div,"FAILED");
			}
			printf("\n|\t\t| \t\tDivision\t| \t%s",div);
		}
	}
	
	fclose(fp);
	
}  
