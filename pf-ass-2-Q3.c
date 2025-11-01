#include <stdio.h>
#define POWER_BIT 0
#define OVERLOAD_BIT 1
#define MAIN_BIT 2

void updateSector(int gird[3][3],int row,int col,int bit,int value);
void querySector(int grid[3][3],int row ,int col);
void runDiagnostic(int grid[3][3]);

int main()
{
    int grid[3][3]={0};
    int choice, row,col, bit,value;

    printf("\n-------------********* IESCO GRID MONTORING SYSTEM *********----------------\n");
    do
    {
        printf("\n****-----------------------------------------------------------------****\n");
        printf("\nMENU:");
        printf("\n1.Update Sector Status");
        printf("\n2.Query Sector Status");
        printf("\n3.Run System Diagnostic:");
        printf("\n4.Exit the System");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter coordinate row (0-2): ");
            scanf("%d", &row);
            printf("\nEnter coordinate column (0-2): ");
            scanf("%d", &col);
            printf("\nEnter flag number to update (0-2) ");
            printf("\n0 - Power Status\n1 - Overload Warning\n2 - Maintenance Required\n");
            scanf("%d", &bit);
            printf("\nEnter value (1 = Set / 0 = Clear): ");
            scanf("%d", &value);
            updateSector(grid, row, col, bit, value);
            break;
        case 2:
            printf("\nEnter sector coordinate row(0-2):");
            scanf("%d", &row);
            printf("\nEnter sector coordinate column(0-2):");
            scanf("%d", &col);
            querySector(grid, row, col);
            break;
        case 3:
            printf("\n");
            runDiagnostic(grid);
            break;
        case 4:
            printf("\nExiting the system.........");
            break;
        default:
            printf("\nInvalid choice. Please enter correct c]hoice to proceed.\n");
            break;
        }
    } while (choice != 4);
}

void updateSector(int grid[3][3], int row, int col, int bit, int value)
{
    if(value==1){
        grid[row][col]|=(1<< bit);
    }
    else{
        grid[row][col] &= ~(1<<bit);
    }
    printf("\nSector [%d][%d] updated sucessfully.",row,col);
    printf("\n---------------------------------------------\n");
}
void querySector(int grid[3][3], int row, int col)
{
    int status=grid[row][col];
    printf("\nSector [%d][%d] Status Report: ",row,col);
    printf("\npower: %s",(status &(1<<POWER_BIT))? "ON" : "OFF");
    printf("\nOverload Warning: %s",(status & (1<<OVERLOAD_BIT))? "Overloaded": "Normal");
    printf("\nMaintenance Required: %s",(status &(1<<MAIN_BIT))? "Yes":"No");
    printf("\n---------------------------------------------\n");
   
}
void runDiagnostic(int grid[3][3])
{
    int maintenance=0;
    int overload=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int status =grid[i][j];
            if(status & (1<<OVERLOAD_BIT))
             overload++;
            if(status & (1<<MAIN_BIT))
             maintenance++;
        }
        
    }
    
    printf("\nDiagnostic System Report\n");
    printf("\nTotal Overloaded Sectors: %d\n",overload);
    printf("\nTotal Maintenance Required Sectors: %d\n",maintenance);
    printf("\n---------------------------------------------\n");
  
}




