#include <stdio.h>
#include <string.h>

void customerInforamtion(char name[], int *cnic)
{
  printf("\nEnter name of Customer: ");
  scanf(" %[^\n]s", name);
  printf("\nEnter CNIC of Customer: ");
  scanf("%d", cnic);
  printf("\nCustomer Name: %s", name);
  printf("\nCNIC Number: %d", *cnic);
  printf("\n\t-----------------------------------\n");
}

void displayInventory(char productCode[][20], int quantityInStock[], int pricePerProduct[], int n)
{
  printf("%-10s %-10s %-10s\n", "Product Code  ", "Quantity in stock  ", " Price per product");
  for (int i = 0; i < 4; i++)
  {
    printf("%-10s\t %-10d \t\t\t%-10d\n", productCode[i], quantityInStock[i], pricePerProduct[i]);
  }
}

void updateInventory(int quantityInStock, int index, int quantity)
{
  quantityInStock -= quantity;
  printf("\nUpdated sucessfully.\n");
}
void addItemToCart(char cartCode[][20], int cartQuantity[], int *cartCount)
{
  printf("\nEnter cart code to add item: ");
  scanf("%s", cartCode[*cartCount]);
  printf("\nEnter cart quantity: ");
  scanf("%d", &cartQuantity[*cartCount]);
  (*cartCount)++;
  printf("\n wow! Item added sucessfully\n");
}
void displayTotalBill(char cartCode[][20], int cartQty[], int cartCount, char productCode[][20], int pricePerProduct[], int n)
{
  float total = 0;

  printf("%-10s %-10s %-10s\n", "Code", "Qty", "Subtotal");

  for (int i = 0; i < cartCount; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (strcmp(cartCode[i], productCode[j]) == 0)
      {
        float subtotal = cartQty[i] * pricePerProduct[j];
        total += subtotal;
        printf("%-10s %-10d %-10.2f\n", cartCode[i], cartQty[i], subtotal);
      }
    }
  }
  printf("Total Bill = %.2f\n", total);
  printf("-----------------------------------\n");
}
void showInvoice(char name[], int cnic, float total, float discount)
{
  printf("\n---------- SHOW INVOICE ------------");
  printf("\nCustomer Name: %s", name);
  printf("\nCustomer CNIC: %d", cnic);
  printf("\nTotal Bill: %.2f", total);
  printf("\nDiscounted Bill: %.2f", discount);
}

int main()
{
  int choice;
  char name[50];
  int cnic;

  int index;
  int quantity;
  int qantyStock;

  char productCode[5][20] = {"001", "002", "003", "004"};
  int quantityInStock[5] = {50, 10, 20, 8};
  int pricePerProduct[5] = {100, 200, 300, 150};

  char cartCode[20][20];
  int cartQuantity[20];
  int cartCount = 0;

  float total = 0, discount = 0;

  printf("\n\t\t************Supermarket Inventory System***************\t\n");

  do
  {
    printf("\n1.CUSTOMER INFORMATION");
    printf("\n2.DISPLAY INVENTORY");
    printf("\n3.UPDATE INVENTORY");
    printf("\n4.ADD ITEM TO CART");
    printf("\n5.DISPLAY TOTAL BILL");
    printf("\n6.SHOW INVOICE ");
    printf("\n7.EXIT THE SYSTEM ");

    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\n----------CUSTOMER INFORMATION------------");
      customerInforamtion(name, &cnic);
      break;
    case 2:
      printf("\n---------- INVENTORY ------------\n");
      displayInventory(productCode, quantityInStock, pricePerProduct, 4);
      break;
    case 3:
      printf("---------- UPDATE INVENTORY ------------\n");
      updateInventory(qantyStock, 0, 2);
      break;
    case 4:
      printf("\n--------- ADD ITEM TO CART -----------");
      addItemToCart(cartCode, cartQuantity, &cartCount);
      break;
    case 5:
      printf("\n---------- TOTAL BILL ------------\n");
      displayTotalBill(cartCode, cartQuantity, cartCount, productCode, pricePerProduct, 4);
      break;
    case 6:
      printf("\nEnter total bill again to apply discount: ");
      scanf("%f", &total);
      if (total == 0)
      {
        printf("\nPlease calculate total bill first!\n");
        break;
      }
      char code[20];
      printf("Do you have a promocode? (Eid2025 = 25%% off): ");
      scanf("%s", code);
      if (strcmp(code, "Eid2025") == 0)
        discount = total * 0.75;
      else
        discount = total;

      showInvoice(name, cnic, total, discount);

      printf("\n\t************************************\n");
      break;
    case 7:
      printf("\nSYSTEM IS EXITING......\n");
      break;
    default:
      printf("Invalid choice. Please try again\n");
      break;
    }
  } while (choice != 7);

  return 0;
}
