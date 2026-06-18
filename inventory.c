#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PRODUCTS 100

typedef struct
{
    int id;
    char name[50];
    int quantity;
    float price;
}Product;
Product products[MAX_PRODUCTS];
int productCount = 0;
float totalSales = 0;
void addProduct();
void viewProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void sellProduct();
void salesReport();
void inventoryValue();
void perItemValue();
void loadProducts();





int main()
{
    loadProducts();
    int choice;

    do
    {
        printf("\n======= Inventory Management System =======\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Sell Product\n");
        printf("7. Sales Report\n");
        printf("8. Inventory Value in PHP\n");
        printf("9. View per Item Value\n");
        printf("10. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct();
            saveProducts();
            break;
        case 2:
            viewProducts();
            saveProducts();
            break;
        case 3:
             searchProduct();
             saveProducts();
             break;
        case 4: 
             updateProduct();
             saveProducts();
             break;
        case 5:
             deleteProduct();
             saveProducts();
             break;
        case 6: 
             sellProduct();
             saveProducts();
             break;
         case 7:
            salesReport();
            break;
        case 8: 
            inventoryValue();
            break;
        case 9:
            perItemValue();
            break;
        case 10:
            printf("Thank you!");
            break;
        default:
            break;
        }
    
    }while(choice != 7);

    return 0;
}

void addProduct()
{
    if(productCount >= MAX_PRODUCTS)
    {
        printf("INVENTORY ALREADY FULL!");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &products[productCount].id);
    while(getchar() != '\n');
    printf("Enter Product Name: ");
    fgets(products[productCount].name, sizeof(products[productCount].name), stdin);
    products[productCount].name[strcspn(products[productCount].name, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &products[productCount].quantity);

    printf("Enter Price: ");
    scanf("%f", &products[productCount].price);

    productCount++;
    printf("Product added successfully!");
}
void viewProducts()
{
    if(productCount == 0)
    {
        printf("No products added\n");
        return;
    }

    printf("\n=========== INVENTORY ===========\n");
    printf("%-8s %-15s %-8s %-10s\n", "ID", "Name", "Qty", "Price");
    for(int i = 0 ; i < productCount ; i++)
    {
        printf("%-8d %-15s %-8d %-10.2f\n",
                products[i].id,
                products[i].name,
                products[i].quantity,
                products[i].price);
    }
}
void searchProduct()
{
    int searchID;
    int found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &searchID);

    for(int i = 0 ; i < productCount ; i++)
    {
        if(products[i].id == searchID)
        {
            printf("============Item found!============\n");
            printf("%-8s %-15s %-8s %-10s\n", "ID", "Name", "Qty", "Price");
            printf("%-8d %-15s %-8d %-10.2f\n",
                products[i].id,
                products[i].name,
                products[i].quantity,
                products[i].price);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("No item found!");
    }

}
void updateProduct()
{
    int searchID;
    viewProducts();
    printf("Enter ID to update: ");
    scanf("%d", &searchID);

    for (int i = 0; i < productCount; i++)
    {
        if(products[productCount].id == searchID)
        {
            printf("%-8s %-15s %-8s %-10s\n", "ID", "Name", "Qty", "Price");
            printf("%-8d %-15s %-8d %-10.2f\n",
                products[i].id,
                products[i].name,
                products[i].quantity,
                products[i].price);

            while(getchar() != '\n');
            printf("Enter Product Name: ");
            fgets(products[productCount].name, sizeof(products[productCount].name), stdin);
            products[productCount].name[strcspn(products[productCount].name, "\n")] = '\0';

            printf("Enter New Quantity: ");
            scanf("%d", &products[productCount].quantity);

            printf("Enter New Price: ");
            scanf("%f", &products[productCount].price);

            printf("Product updated successfully!");
        }


    }
    
}

void deleteProduct()
{
    int searchID;
    printf("Enter Product ID to delete: ");
    scanf("%d", &searchID);

    for(int i = 0; i < productCount; i++)
    {
        if(products[i].id == searchID)
        {
            for(int j = i; j < productCount - 1; j++)
            {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}
void sellProduct()
{
    int searchID;
    int amount;

    printf("Enter Product ID to sell: ");
    scanf("%d", &searchID);

    for(int i  = 0 ; i < productCount ; i++)
    {
        if(products[i].id == searchID)
        {
            printf("Product Found: %s\n", products[i].name);
            printf("Available Stock: %d\n", products[i].quantity);
            printf("Enter Quantity to sell: ");
            scanf("%d", &amount);

            if(amount > products[i].quantity)
            {
                printf("Not enough stock!\n");
                return;
            }

            products[i].quantity -=  amount;
            float saleAmount = products[i].price * amount;
            totalSales += saleAmount;
            printf("Sold successfully!\n");
            printf("Remaining stock: %d\n", products[i].quantity);

            printf("Sale Amount: PHP %.2f\n", saleAmount);
            printf("Total Sales: PHP %.2f\n", totalSales);
            return;
        }
    }
    printf("Product not found!\n");
}

void salesReport()
{
    printf("\n===== SALES REPORT =====\n");

    printf("Total Products: %d\n", productCount);

    printf("Total Revenue: PHP %.2f\n", totalSales);

    printf("========================\n");
}

void inventoryValue()
{
    float totalValue = 0; 

    for(int  i = 0 ; i < productCount ; i++)
    {
        totalValue += products[i].quantity * products[i].price;
    }

    printf("\nInventory value: PHP %.2f\n", totalValue);
}

void perItemValue()
{
    float totalItemPrice = 0;
    int searchID;

    printf("Enter item ID to look total value: ");
    scanf("%d", &searchID);

    for(int i = 0 ; i < productCount ; i++){
        if(products[i].id == searchID)
        {
            totalItemPrice = products[i].quantity * products[i].price;
            printf("Product: %s | totalvalue of item: %.2f", products[i].name, totalItemPrice);
            return;
        }
    }
}

void saveProducts()
{
    FILE *fp;

    fp = fopen("inventory.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < productCount; i++)
    {
        fprintf(fp,
                "%d,%s,%d,%.2f\n",

                products[i].id,
                products[i].name,
                products[i].quantity,
                products[i].price),
                totalSales;
    }

    fclose(fp);
}

void loadProducts()
{
    FILE *fp;

    fp = fopen("inventory.txt", "r");

    if(fp == NULL)
    {
        return;
    }

    while(
        fscanf(fp,
               "%d,%99[^,],%d,%f\n",

               &products[productCount].id,
               products[productCount].name,
               &products[productCount].quantity,
               &products[productCount].price,
            totalSales)

        == 5
    )
    {
        productCount++;
    }

    fclose(fp);
}