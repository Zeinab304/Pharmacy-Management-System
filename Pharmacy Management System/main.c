#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int id;
    float price;
    int quantity;
} Medicine;

Medicine *pharmacy;

int capacity = 5;
int count = 0;
int ID = 101;

void seedData();
void addMedicine();
int findMedicineIndex(int id);
void searchMedicine();
void sellMedicine();
void updateMedicine();
void deleteMedicine();
void displayInventory();
void freeMemory();
void lowStockReport();

int main()
{
    seedData();

    int choice;
    printf("\n----- Pharmacy Management System -----\n");
    do
    {
        printf("\n--\nWhat would you like to do?\n");
        printf("1. Add New Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine by ID\n");
        printf("4. Sell Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Delete Medicine\n");
        printf("7. Low Stock Report\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addMedicine();
            break;
        case 2:
            displayInventory();
            break;
        case 3:
            searchMedicine();
            break;
        case 4:
            sellMedicine();
            break;
        case 5:
            updateMedicine();
            break;
        case 6:
            deleteMedicine();
            break;
        case 7:
            lowStockReport();
            break;
        case 8:
            printf("\n[^-^] Thanks for your time.\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    }
    while(choice!=8);

    freeMemory();
    return 0;
}

void seedData()
{

    pharmacy = (Medicine*) malloc(capacity * sizeof(Medicine));

    pharmacy[0].id = ID++;
    pharmacy[0].name = (char*) malloc(strlen("Panadol_Advance") + 1);
    strcpy(pharmacy[0].name, "Panadol_Advance");
    pharmacy[0].price = 25.50;
    pharmacy[0].quantity = 50;


    pharmacy[1].id = ID++;
    pharmacy[1].name = (char*) malloc(strlen("Augmentin_1g") + 1);
    strcpy(pharmacy[1].name, "Augmentin_1g");
    pharmacy[1].price = 89.00;
    pharmacy[1].quantity = 20;


    pharmacy[2].id = ID++;
    pharmacy[2].name = (char*) malloc(strlen("Catafast_50mg") + 1);
    strcpy(pharmacy[2].name, "Catafast_50mg");
    pharmacy[2].price = 45.00;
    pharmacy[2].quantity = 35;


    pharmacy[3].id = ID++;
    pharmacy[3].name = (char*) malloc(strlen("Brufen_400mg") + 1);
    strcpy(pharmacy[3].name, "Brufen_400mg");
    pharmacy[3].price = 31.00;
    pharmacy[3].quantity = 15;


    pharmacy[4].id = ID++;
    pharmacy[4].name = (char*) malloc(strlen("Antinal_Capsules") + 1);
    strcpy(pharmacy[4].name, "Antinal_Capsules");
    pharmacy[4].price = 21.50;
    pharmacy[4].quantity = 40;

    count = 5;
}

void addMedicine()
{

    if (count == capacity)
    {
        capacity *= 2;

        pharmacy = (Medicine*) realloc(pharmacy, capacity * sizeof(Medicine));

        printf("\n[System] Inventory expanded to %d slots.\n", capacity);
    }

    printf("\n------Add Medicine------\n");

    pharmacy[count].id = ID++;
    printf("\nID: %d",pharmacy[count].id);

    char temp[100];
    printf("\nEnter Name (use _ instead of space): ");
    scanf("%s",temp);
    pharmacy[count].name = (char*) malloc(strlen(temp) + 1);
    strcpy(pharmacy[count].name,temp);

    printf("Enter Price: ");
    scanf("%f",&pharmacy[count].price);

    printf("Enter Quantity: ");
    scanf("%d",&pharmacy[count].quantity);

    count++;
    printf("\nMedicine added successfully!\n");
}

int findMedicineIndex(int id)
{
    for (int i = 0; i < count; i++)
    {
        if (pharmacy[i].id == id) return i;
    }
    return -1;
}

void searchMedicine()
{
    printf("\n------Search Medicine------\n");
    int id;
    printf("\nEnter ID: ");
    scanf("%d",&id);

    int index = findMedicineIndex(id);

    if (index != -1)
    {
        printf("\nMedicine Found");
        printf("\n .ID: %d", pharmacy[index].id);
        printf("\n .Name: %s", pharmacy[index].name);
        printf("\n .Price: %.2f", pharmacy[index].price);
        printf("\n .Quantity: %d\n", pharmacy[index].quantity);
    }
    else
    {
        printf("\n[Error]: Medicine not found.\n");
    }
}

void sellMedicine()
{

    printf("\n------Sell Medicine------\n");
    int id,requestedQty;
    printf("\nEnter ID: ");
    scanf("%d",&id);

    int index = findMedicineIndex(id);

    if (index == -1)
    {
        printf("\n[Sorry], this medicine is not in our system.\n");
    }
    else
    {

        if (pharmacy[index].quantity > 0)
        {
            printf("Medicine Found: %s", pharmacy[index].name);
            printf("\nPrice: %.2f EGP", pharmacy[index].price);

            printf("\nEnter quantity to sell: ");
            scanf("%d", &requestedQty);

            if (requestedQty <= pharmacy[index].quantity && requestedQty > 0)
            {

                float totalPrice = requestedQty * pharmacy[index].price;

                pharmacy[index].quantity -= requestedQty;

                printf("\nSuccessfully sold %d units of %s.\n", requestedQty, pharmacy[index].name);
                printf("Total Bill: %.2f EGP\n", totalPrice);
                printf("Remaining quantity in stock: %d\n", pharmacy[index].quantity);
            }
            else if (requestedQty <= 0)
            {
                printf("\nInvalid quantity! Must be greater than 0.\n");
            }
            else
            {
                printf("\n[Error]: Not enough stock!");
                printf("\nYou requested %d, but we only have %d units left.\n", requestedQty, pharmacy[index].quantity);
            }
        }
        else
        {
            printf("\n[Sorry]:Out of stock! Cannot sell %s.\n", pharmacy[index].name);
        }
    }
}

void updateMedicine()
{

    printf("\n------Update Medicine------\n");

    int id;
    printf("\nEnter Medicine ID to update: ");
    scanf("%d", &id);

    int index = findMedicineIndex(id);

    if (index != -1)
    {
        int choice;
        printf("\nUpdating: %s", pharmacy[index].name);
        printf("\n1. Update Price\n2. Add to Stock (Quantity)\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter new price: ");
            scanf("%f", &pharmacy[index].price);
        }
        else if (choice == 2)
        {
            int newQty;
            printf("Enter quantity to add: ");
            scanf("%d", &newQty);
            pharmacy[index].quantity += newQty;
        }
        printf("\nUpdated successfully!\n");
    }
    else
    {
        printf("\nMedicine not found!!\n");
    }
}

void deleteMedicine()
{

    printf("\n------Delete Medicine------\n");

    int id;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    int index = findMedicineIndex(id);
    if (index != -1)
    {

        free(pharmacy[index].name);

        for (int i = index; i < count - 1; i++)
        {
            pharmacy[i] = pharmacy[i + 1];
        }

        count--;
        printf("\nMedicine deleted successfully.\n");
    }
    else
    {
        printf("\nMedicine not found!!\n");
    }
}

void lowStockReport()
{
    int found = 0;
    printf("\n--- Low Stock Alert (Less than 5 units) ---\n");
    printf("%-10s %-20s %-10s\n", "ID", "Name", "Quantity");

    for (int i = 0; i < count; i++)
    {
        if (pharmacy[i].quantity < 5)
        {
            printf("%-10d %-20s %-10d\n",
                   pharmacy[i].id, pharmacy[i].name, pharmacy[i].quantity);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nAll medicines are in good supply!\n");
    }
}

void displayInventory()
{
    if (count == 0)
    {
        printf("\n[!!]Inventory is empty.\n");
        return;
    }
    printf("\n\n-------- Inventory ---------\n");
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-10d %-20s %-10.2f %-10d\n",
               pharmacy[i].id, pharmacy[i].name, pharmacy[i].price, pharmacy[i].quantity);
    }
}

void freeMemory()
{
    for (int i = 0; i < count; i++)
    {
        free(pharmacy[i].name);
    }
    free(pharmacy);
}

