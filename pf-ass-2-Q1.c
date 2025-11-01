
#include <stdio.h>
#include<string.h>

#define MAX_BOOKS 100
void addNewBook(int isbns[], char titiles[][50], float prices[], int quantities[], int *count)
{
    if(*count>=MAX_BOOKS){
        printf("\nInventroy is full. You cannot add more books.");
        return;
    }
    int n;
    printf("\nEnter number of Books to add: ");
    scanf("%d", &n);
    int newIsbn;
    for (int i = 0; i < n; i++)
    {
        printf("\n--------Enter details of Books %d-------", i + 1);
        printf("\nEnter ISBN: ");
        scanf("%d", &newIsbn);
        for(int i=0;i< *count;i++){
          if(isbns[i]==newIsbn){
            printf("\nDupicate ISBN! Book already exist");
            return;
          }
          
        }
        isbns[*count]=newIsbn;
        printf("\nEnter Book Title: ");
        getchar();
        fgets(titiles[*count],50,stdin);
        titiles[*count][strcspn(titiles[*count], "\n")]='\0';

       
        printf("\nEnter price of the Book: ");
        scanf("%f", &prices[*count]);
        printf("\nEnter Quantities: ");
        scanf("%d", &quantities[*count]);
        (*count)++;
        printf("\n congratulation! Book added sucessfully.");
    }
       
    
}
void saleProcess(int isbns[], char titiles[][50], float prices[] , int quantities[], int count)
{   
    if(count==0){
        printf("\nNo books in inventory.");
        return;
    }
    int saleIsbn, saleQuantity;
    printf("\nEnter ISBN of the book: ");
    scanf("%d", &saleIsbn);
    int found=-1;
    for(int i=0;i<count;i++){
        if(isbns[i]==saleIsbn){
         found=i;
         break;
        }
    }
     if(found==-1){
        printf("\nBook not found");
        return;
    }
    printf("\nEnter the quantity of book: ");
    scanf("%d",&saleQuantity);
    if (saleQuantity >quantities[found]){
        printf("Insufficient Stock , Available=%d",quantities[found]);
        return;

    }
    
        quantities[saleIsbn] -= saleQuantity;
        printf("\nSale processed sucessfully");
    printf("\nRemaining  stocks : %d",quantities[found]);
       
    }
   

void genrateLowStockReport(int isbns[], char titiles[][50], float prices[], int quantities[], int count)
{

    if (count == 0)
    {
        printf("No books AVailable in the inventory");
        return;
    }

    printf("\n------Low Stock Report -----------\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (quantities[i] < 5)
        {
            printf("ISBN: %d, Title: %s, Price: %.2f, Quantity: %d\n", isbns[i], titiles[i], prices[i], quantities[i]);
        }
        found = 1;
    }
    if (!found)
    {
        printf("\nAll Books have sufficient stocks.");
    }
}

int main()
{
    int isbns[MAX_BOOKS];
    char titiles[MAX_BOOKS][50];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int choice;
    int count=0 ;
    do
    {
        printf("\n\t\t**************** Liberty Book Inventory System *****************\t\n");
        printf("1.Add new Books\n");
        printf("2.Process a Sale\n");
        printf("3.Generate Low STock Report\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        printf("\n----------Adding new Book-----------\n");
        addNewBook(isbns, titiles, prices, quantities, &count);
        break;
        case 2:
        printf("\n----------Process a Sale-----------\n");
        saleProcess(isbns, titiles, prices, quantities, count);
        break;
        case 3:
        printf("\n----------Generate Low Stock Report-----------\n");
            genrateLowStockReport(isbns, titiles, prices, quantities, count);
            break;
        case 4:
            printf("\nProgram is exiting.....");
            break;
        default:
            printf("You entered an invalid input. Please try again");
        }
    } while (choice != 4);
    return 0;
}