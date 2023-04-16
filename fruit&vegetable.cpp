#include <stdio.h>
#include <string.h>
struct products{
	char product_name[20];
	int product_quantity;
	float price;
};
struct login{
	char username[20];
	char password[10];
};
struct cart{
	char itemname[20];
	int quantity;
	int c = -1;
};

int main()
{
	int option, k=0, choice = -1, test=0, quantity, check, op, i=0;
	float total=0;
	char temp[20], clear[20];
	FILE *accounts, *fruits, *vegetables, *temp1, *temp2;
	login user, account[4];
	products fruit[10], vegetable[10], addition, addition1;
	cart checkout[10];
	accounts = fopen("accounts.txt","r+");
	printf("Select Login Type:\n1. Vendor\n2. Customer\n --> ");
	scanf("%d",&option);
	if(option == 1)
	{
		printf("Enter Username: ");
		scanf("%s",user.username);
		printf("Enter Password: ");
		scanf("%s",user.password);
		while(fread(&account[k], sizeof(struct login), 1, accounts))
		{
			if(strcmp(user.username, account[k].username) == 0 && strcmp(user.password, account[k].password) == 0)
			{
				test = 1;
			}
			k++;
		}
		if(test == 1)
		{	
			printf("\nLogin Successful");
			while(choice!=0){
				printf("\n\nSelect Option:\n1. Product Information\n2. Stock Update\n3. Price Update\n4. Add New Product\n5. Delete a Product\n6. Exit Program\n\nYour Choice: ");
				scanf("%d",&choice);
				if(choice == 1)
				{
					k = 0;
					fruits = fopen("fruits.txt","r+");
					printf("\t\t\t--------------------Fruits------------------\n\n");
					while(fread(&fruit[k], sizeof(struct products), 1, fruits))
					{
						printf("\t\tName: %s\t\tQuantity: %d\t\tPrice: $%0.2f\n",fruit[k].product_name,fruit[k].product_quantity,fruit[k].price);
						k++;
					}
					fclose(fruits);
					k = 0;
					vegetables = fopen("vegetables.txt","r+");
					printf("\n\n\t\t\t--------------------Vegetables------------------\n\n");
					while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
					{
						printf("\t\tName: %s\t\tQuantity: %d\t\tPrice: $%0.2f\n",vegetable[k].product_name,vegetable[k].product_quantity,vegetable[k].price);
						k++;
					}
					fclose(vegetables);
				}
				else if(choice == 2)
				{
					printf("Enter Product Name: ");
					scanf("%s",&temp);
					fruits = fopen("fruits.txt","r+");
					vegetables = fopen("vegetables.txt","r+");
					temp1 = fopen("temp1.txt","w+");
					temp2 = fopen("temp2.txt","w+");
					k=0;
					while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
					{
						if(strcmp(temp, vegetable[k].product_name) == 0)
						{
							check = 1;
							printf("Enter New Quantity: ");
							scanf("%d",&vegetable[k].product_quantity);
						}
						fwrite(&vegetable[k], sizeof(struct products), 1, temp1);
					}
					while(fread(&fruit[k], sizeof(struct products), 1, fruits))
					{
						if(strcmp(temp, fruit[k].product_name) == 0)
						{
							check = 2;
							printf("Enter New Quantity: ");
							scanf("%d",&fruit[k].product_quantity);
						}
						fwrite(&fruit[k], sizeof(struct products), 1, temp2);
					}
					fclose(vegetables);
					fclose(fruits);
					fclose(temp1);
					fclose(temp2);
					if(check == 1)
					{
						printf("Stock Updated !!");
						k = 0;
						vegetables = fopen("vegetables.txt","w+");
						temp1 = fopen("temp1.txt","r+");
						k=0;
						while(fread(&vegetable[k], sizeof(struct products), 1, temp1))
						{	
							fwrite(&vegetable[k], sizeof(struct products), 1, vegetables);
							k++;
						}
					}
					else if(check == 2)
					{
						printf("Stock Updated !!");
						k = 0;
						fruits = fopen("fruits.txt","w+");
						temp2 = fopen("temp2.txt","r+");
						k=0;
						while(fread(&fruit[k], sizeof(struct products), 1, temp2))
						{	
							fwrite(&fruit[k], sizeof(struct products), 1, fruits);
							k++;
						}
					}
					else
					{
						printf("Product Not Found !!");
					}
					check = 0;
					fclose(temp1);
					fclose(temp2);
					fclose(vegetables);
					fclose(fruits);
				}
				else if(choice == 3)
				{
					printf("Enter Product Name to Update: ");
					scanf("%s",&temp);
					fruits = fopen("fruits.txt","r+");
					vegetables = fopen("vegetables.txt","r+");
					temp1 = fopen("temp1.txt","w+");
					temp2 = fopen("temp2.txt","w+");
					k=0;
					while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
					{
						if(strcmp(temp, vegetable[k].product_name) == 0)
						{
							check = 1;
							printf("Enter New Price: ");
							scanf("%f",&vegetable[k].price);
						}
						fwrite(&vegetable[k], sizeof(struct products), 1, temp1);
					}
					while(fread(&fruit[k], sizeof(struct products), 1, fruits))
					{
						if(strcmp(temp, fruit[k].product_name) == 0)
						{
							check = 2;
							printf("Enter New Price: ");
							scanf("%f",&fruit[k].price);
						}
						fwrite(&fruit[k], sizeof(struct products), 1, temp2);
					}
					fclose(vegetables);
					fclose(fruits);
					fclose(temp1);
					fclose(temp2);
					if(check == 1)
					{
						printf("Stock Updated !!");
						k = 0;
						vegetables = fopen("vegetables.txt","w+");
						temp1 = fopen("temp1.txt","r+");
						k=0;
						while(fread(&vegetable[k], sizeof(struct products), 1, temp1))
						{	
							fwrite(&vegetable[k], sizeof(struct products), 1, vegetables);
							k++;
						}
					}
					else if(check == 2)
					{
						printf("Stock Updated !!");
						k = 0;
						fruits = fopen("fruits.txt","w+");
						temp2 = fopen("temp2.txt","r+");
						k=0;
						while(fread(&fruit[k], sizeof(struct products), 1, temp2))
						{	
							fwrite(&fruit[k], sizeof(struct products), 1, fruits);
							k++;
						}
					}
					else
					{
						printf("\nProduct Not Found !!");
					}
					check = 0;
					fclose(temp1);
					fclose(temp2);
					fclose(vegetables);
					fclose(fruits);
				}
				else if(choice == 4)
				{
					printf("Select Product to Add:\n 1. Vegetable\n 2. Fruit\n Your Choice: ");
					scanf("%d",&op);
					printf("\nProduct Added !!\n");
					if(op == 1)
					{
						vegetables = fopen("vegetables.txt","a");
						printf("Name: ");
						scanf("%s",&addition.product_name);
						printf("Quantity: ");
						scanf("%d",&addition.product_quantity);
						printf("Price: ");
						scanf("%f",&addition.price);
						fwrite(&addition, sizeof(struct products), 1, vegetables);
						fclose(vegetables);
					}
					else if(op == 2)
					{
						fruits = fopen("fruits.txt","a");
						printf("Name: ");
						scanf("%s",&addition1.product_name);
						printf("Quantity: ");
						scanf("%d",&addition1.product_quantity);
						printf("Price: ");
						scanf("%f",&addition1.price);
						fwrite(&addition1, sizeof(struct products), 1, fruits);
						fclose(fruits);
					}
					else
					{
						printf("\nInvalid Option Entered !\n");
					}
				}
				else if(choice == 5)
				{
					printf("Enter Product Name to Delete: ");
					scanf("%s",&temp);
					fruits = fopen("fruits.txt","r+");
					vegetables = fopen("vegetables.txt","r+");
					temp1 = fopen("temp1.txt","w+");
					temp2 = fopen("temp2.txt","w+");
					k=0;
					while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
					{
						if(strcmp(temp, vegetable[k].product_name) == 0)
						{
							check = 1;
						}
						else
						{
							fwrite(&vegetable[k], sizeof(struct products), 1, temp1);
						}
						k++;
					}
					while(fread(&fruit[k], sizeof(struct products), 1, fruits))
					{
						if(strcmp(temp, fruit[k].product_name) == 0)
						{
							check = 1;
						}
						else
						{
							fwrite(&fruit[k], sizeof(struct products), 1, temp2);
						}
						k++;
					}
					fclose(vegetables);
					fclose(fruits);
					fclose(temp1);
					fclose(temp2);
					
					if(check == 1)
					{
						printf("Product Deleted !!");
						k = 0;
						vegetables = fopen("vegetables.txt","w+");
						temp1 = fopen("temp1.txt","r+");
						k=0;
						while(fread(&vegetable[k], sizeof(struct products), 1, temp1))
						{	
							fwrite(&vegetable[k], sizeof(struct products), 1, vegetables);
							k++;
						}
						fruits = fopen("fruits.txt","w+");
						temp2 = fopen("temp2.txt","r+");
						k=0;
						while(fread(&fruit[k], sizeof(struct products), 1, temp2))
						{	
							fwrite(&fruit[k], sizeof(struct products), 1, fruits);
							k++;
						}
					}
					else
					{
						printf("Product Not Found !!\n");
					}
					check = 0;
					fclose(vegetables);
					fclose(fruits);
					fclose(temp1);
					fclose(temp2);
				}
				else if(choice == 6){
					printf("\nProgram Terminated!");
					break;
				}
			}
		}
	}
	else if(option == 2)
	{
		choice = 0;
		while(choice != 4)
		{
			printf("\n1. Product Information\n2. Add Products to Cart\n3. Checkout\n4. Exit\nYour Choice: ");
			scanf("%d",&choice);
			if(choice == 1)
			{
				k = 0;
				fruits = fopen("fruits.txt","r+");
				printf("\t\t\t--------------------Fruits------------------\n\n");
				while(fread(&fruit[k], sizeof(struct products), 1, fruits))
				{
					printf("\t\tName: %s\t\tQuantity: %d\t\tPrice: $%0.2f\n",fruit[k].product_name,fruit[k].product_quantity,fruit[k].price);
					k++;
				}
				fclose(fruits);
				k = 0;
				vegetables = fopen("vegetables.txt","r+");
				printf("\n\n\t\t\t--------------------Vegetables------------------\n\n");
				while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
				{
					printf("\t\tName: %s\t\tQuantity: %d\t\tPrice: $%0.2f\n",vegetable[k].product_name,vegetable[k].product_quantity,vegetable[k].price);
					k++;
				}
				fclose(vegetables);
			}
			else if(choice == 2)
			{
				op = 0;
				k = 0;
				
				while(op!=2)
				{
					k=0;
					printf("\nEnter Item Name: ");
					scanf("%s",&temp);
					printf("Enter Quantity: ");
					scanf("%d",&quantity);
					vegetables = fopen("vegetables.txt","r+");
					fruits = fopen("fruits.txt","r+");
					while(fread(&vegetable[k], sizeof(struct products), 1, vegetables))
					{	
						if(strcmp(temp, vegetable[k].product_name) == 0)
						{
							strcpy(checkout[i].itemname, vegetable[k].product_name);
							checkout[i].quantity = quantity;
							checkout[i].c = 1;
							total = total + (vegetable[k].price * quantity);
							i++;
						}
						k++;
					}
					while(fread(&fruit[k], sizeof(struct products), 1, fruits))
					{	
						if(strcmp(temp, fruit[k].product_name) == 0)
						{
							strcpy(checkout[i].itemname, fruit[k].product_name);
							checkout[i].quantity = quantity;
							checkout[i].c = 1;
							total = total + (fruit[k].price * quantity);
							i++;
						}
						k++;
					}
					printf("\nBuy Another Item?\n1. Yes\n2. No\nYour Choice: ");
					scanf("%d",&op);
					fclose(fruits);
					fclose(vegetables);
				}
			}
			else if(choice == 3)
			{
				i = 0;
				while(checkout[i].c != -1)
				{
					printf("\nProduct %d: %s ",i+1,checkout[i].itemname);
					i++;
				}
				op = 0;
				printf("\nTotal Items = %d\nTotal Amount = %.2f",i,total);
				printf("\nConfirm Checkout?\n1. Yes\n2. No, Clear Cart\nYour Choice: ");
				scanf("%d",&op);
				if(op == 1)
				{
					printf("Items Purchased Successfully !!\n");
					total = 0;
					i = 0;
					k = 0;
					while(checkout[i].c != -1)
					{
						strcpy(checkout[i].itemname, clear);
						checkout[i].quantity = 0;
						checkout[i].c = -1;
						i++;
					}
					i=0;
				}
				else if(op ==2)
				{
					printf("Cart Cleared !!\n");
					i = 0;
					k = 0;
					total = 0;
					while(checkout[i].c != -1)
					{
						strcpy(checkout[i].itemname, clear);
						checkout[i].quantity = 0;
						checkout[i].c = -1;
						i++;
					}
					i=0;\
					
				}
				else
				{
					printf("Invalid Option Entered !!\n");
				}
			}
			else if(choice == 4)
			{
				printf("Program Terminated !!");
				break;
			}
			else
			{
				printf("Invalid Option Entered !\n");
			}
		}
	}
}