#include<stdio.h>
struct tourist
{
    char name[30];
    char destination[20];
    int duration;
    int amount;
}t;
void Record()
{
    FILE *ptr;
    printf("\nEnter the tourist Name\n:");
    scanf("%s",t.name);
    printf("\nEnter the tourist Destination\n:");
    scanf("%s",t.destination);
    printf("\nEnter the Numbers of days spent\n:");
    scanf("%d",&t.duration);
    printf("\nEnter the  amount paid\n :");
    scanf("%d",&t.amount);
    ptr=fopen("Tourists.txt","a");
    fprintf(ptr,"\n%s\t%s\t%d\t%d",t.name,t.destination,t.duration,t.amount);
    fclose(ptr);
}
void Display()
{
    FILE *ptr;
    printf("\nNAME\t\tDESTINATION\tDURATION\tAMOUNT\n****\t\t***********\t********\t******");
    ptr=fopen("Tourists.txt","r");
    while(!feof(ptr))
    {
        fscanf(ptr,"\n%s\t%s\t%d\t%d",t.name,t.destination,&t.duration,&t.amount);
        printf("\n%s\t\t%s\t\t%d\t\t%d",t.name,t.destination,t.duration,t.amount);
    }
    fclose(ptr);
}

void billing()
{
    FILE *ptr;
    char destination[20];
    int totalAmount = 0;

    printf("\nEnter the destination: ");
    scanf("%s", destination);

    ptr = fopen("Tourists.txt", "r");
    if (ptr != NULL)
    {
        while (fscanf(ptr, "\n%s\t%s\t%d\t%d", t.name, t.destination, &t.duration, &t.amount) != EOF)
        {
            if (strcmp(t.destination, destination) == 0)
            {
                totalAmount += t.amount;
            }
        }
        fclose(ptr);

        printf("\nTotal amount spent in %s: $%d\n", destination, totalAmount);
    }
    else
    {
        printf("Unable to open the file.\n");
    }
}


   void main()
   {
       int o;
       printf("\n\t\t\t...WELCOME TO RWANDA TOURISM...");
       do
       {
           printf("\n\t\tOPTIONS\n\t\t=======\n\n\t\t1. RECORD\n\t\t2. DISPLAY\n\t\t3. AMOUNT/DESTINATION\n\t\t0. EXIT\n\t\t\t\nMake your Choice...");
           scanf("%d",&o);
           switch(o)
           {
           case 1:
            Record();
            break;
           case 2:
            Display();
            break;
            case 3 :
            billing();
            break;
           case 0:
            printf("THANK YOU FOR YOUR VISIT. SEE YOU !");
           default:
            printf("INVALID OPTION, TRY AGAIN !");
           }
       }
       while(o!=0);
   }


