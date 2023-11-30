#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void Add();
void Edit();
void Delete();
void Search();
void Sell();
void Purchase();
void View_product();
void Dashboard();

struct product 
{
    char name[60];
    float price;
    int qty;
    char date[50];
    char code[100];
    };

void main()

{
    printf(" \t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t\t\t\t\t       Inventory Management System \n");
printf("\n\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");    
    
    // login part 
    int i=0;
	char ch;
    char username[30];
    char password[20];
    char defpassword[20]="hello";
    
    printf("\n\n\t\t\t\t\t       Enter your username: ");
    scanf(" %s",username);
    login:
    printf("\n\n\t\t\t\t\t       Enter your password: ");
    //scanf(" %s",password);
    	while((ch = _getch()) !=13)
	{
		password[i] = ch;
		i++;
		printf("*");
		
	}
    
    if( strcmp(password,defpassword)==0)
    {
        
        
            Dashboard();
            
      }
    else
    {
        goto login;
    }

getch();

}
//ending of main function
//start of dashboard
void Dashboard()
{
    system("cls");
            char opt[20];
            int option;
          
        printf("\t\t\t\t***********************************************\n");
		printf("\t\t\t\t*********   	Welcome            ************\n");
		printf("\t\t\t\t*********   	  To               ************\n");
		printf("\t\t\t\t*********   	Inventory          ************\n");
		printf("\t\t\t\t*********   	 System            ************\n");
		printf("\t\t\t\t***********************************************\n");
           
          belal:
    
            printf(" \n\t\t\t\t\t\t 1. Add product ");
            printf(" \n\t\t\t\t\t\t 2. Edit product ");
            printf(" \n\t\t\t\t\t\t 3. Delete product ");
            printf(" \n\t\t\t\t\t\t 4. Search product ");
            printf(" \n\t\t\t\t\t\t 5. Purchase product ");
            printf(" \n\t\t\t\t\t\t 6. Sell product ");
            printf(" \n\t\t\t\t\t\t 7. View product ");
            printf(" \n\t\t\t\t\t\t choose option from 1 to 7: ");
            scanf(" %d",&option);        
            system("cls");
            switch(option)
            {
            		
                case 1:
                
                           do{
						   Add();
                           
                        printf(" \n\t\t\t\t Do you want to add more? (y/n): ");
                        scanf("%s",opt);}
	                    while(strcmp(opt,"y")==0);
	    
	    	            Dashboard();
     
                 case 2:
                           Edit();
                           break;
                 case 3:
                          Delete();
                          break;
                 case 4:
                          Search();
                          break;
                 case 5:
                          Purchase();
                 
                 
                          break;
                 case 6:
                         Sell();
                         break;
                 
                 case 7:
                         View_product();
                         break;
                 default:
                        goto belal;
                  
                
                }
        
        
    
    }
    void Add()
    { 
    
    system("cls");
    int y;
   	FILE *fp;
	fp= fopen("product.dat", "ab");
    
    struct product p;
    printf(" \n Add Product details ____\n\n");
    
    printf(" \n Name of product: ");
    scanf("%s", p .name);
    printf("\n  Qty of product:");
    scanf("%d", &p.qty);
    printf(" \n Enter price of product: ");
    
    scanf("%f", &p.price);
    printf(" \n Enter date (dd/mm/yy): ");
    scanf("%s", p.date);
    printf(" \n Enter code:");
    scanf("%s", p.code);
    
    printf(" \n Product Added Successfully\n");
    
	fwrite(&p, sizeof(p), 1, fp);
	fclose(fp);
  }
        
        
        
   void Edit()
  {
  	system("cls");
  	FILE *fp1;
  	fp1 = fopen("product.dat","rb+");
  	char code[100];
  	
  	
  	  struct product p;
  	  struct product p1;
  	  belal1:
  	  printf("Enter code of product to Edit: \n");
  	  scanf("%s", code);
  	  while(fread(&p,sizeof(p),1,fp1)>=1)
  	  {
  	  	if(strcmp(code, p.code)==0)
  	  	{
  	  		 printf(" \n Name of product: ");
            scanf("%s", p1.name);
            printf("\n  Qty of product:");
            scanf("%d", &p1.qty);
            printf(" \n Enter price of product: ");
    
            scanf("%f", &p1.price);
            printf(" \n Enter date (dd/mm/yy): ");
            scanf("%s", p1.date);
            printf(" \n Enter code:");
            scanf("%s", p1.code);
            fseek(fp1, -sizeof(p), SEEK_CUR);
            fwrite(&p1,sizeof(p1),1,fp1);
     
            break;
            
			}
			    else
                  { 
                   goto belal1;
			      }
		}
  	  
  
      fclose(fp1);
      printf("Press emter to goto Dashboard");
      getch();
      Dashboard();
      
      }
    void Delete()
    {
    int f;
	system("cls");
	char name[100];
	struct product p;
	long int size = sizeof(p);
	FILE *fp1;
	FILE *fp2;
	
	fp1=fopen("product.dat","rb");
	fp2=fopen("temp.dat", "wb");
	
	printf("\n\t\t\t<--------Delete product Details---------");
	printf("\n which  product you want to delete ::");
    scanf("%s",name);
    while(fread(&p, sizeof(p), 1, fp1)==1)
    {
    	if(strcmp(p.name,name)==0)
    	{
    		f=1;
		}
		else{
			fwrite(&p, sizeof(p), 1, fp2);
		}
	}
	if(f==1)
	{
		printf("\n\tDelete Success");
	}else{
	    printf("\n\t Sorry ! Record Not Found !");
	}
    
	fclose(fp1);
	fclose(fp2);
	
	remove("product.dat");
	rename("temp.dat","product.dat");
	
	printf("\n\t Press Enter to go Dashboard...........");
	getch();
	
	Dashboard();
	
    }
    
    void Search()
    {
    system("cls");
    int f=0;
	struct product p;
	char name[100];
	FILE *fp;
	fp=fopen("product.dat", "rb");
	long int size = sizeof(p); 
	
	printf("\n\t\t\t<-------Search Product Details------>");
	printf("\n Enter the product name whcih you want to search:");
	scanf("%s",name);
	      
	while (fread(&p, sizeof(p), 1, fp) == 1)
	 {
		if(strcmp(p.name,name) == 0)
		{ 
		f=1;
	    break;
		}
      }
      if(f==1)
      {
      	printf("\n");
        printf("\n-------------------------------------------------------------------------------------------------------------");
        printf(" \n Name of product:    \t Quantity:         \t Price:           \t Date:              \t Code: ");
        printf("\n-------------------------------------------------------------------------------------------------------------");
        printf("\n");
        printf("  %s",p.name);
        printf("\t\t\t   %d",p.qty);
	    printf("\t\t\t  %f",p.price);
        printf("     \t %s",p.date);
        printf("   \t \t%s\n\n",p.code); 
	  }
	  else
	  {
	  	printf("product not found:");
	  }

    getch();
    Dashboard();
    }
   void Purchase()
    {
    	
      system("cls");
      FILE *fp;
	  fp = fopen("product.dat","ab+");
	  int pur,option,price,qty;
	  char name[100];
	  struct product p;
	  long int size = sizeof(p);
	  start:
	  if(fp==NULL)
	  {
	  printf("Invalid");
	  
		} 
		else{
				printf("\n\t\t\t<----Purchase Details of product ----> ");
	printf("\n\n\t1. Do you want to purchase old or new ? for old = 0 and for new = 1: ");
	scanf("%d",pur);
	if(pur==1)
	{
		 printf(" \n Name of product: ");
            scanf("%s", p.name);
            printf("\n  Qty of product:");
            scanf("%d", &p.qty);
            printf(" \n Enter price of product: ");
    
            scanf("%f", &p.price);
            printf(" \n Enter date (dd/mm/yy): ");
            scanf("%s", p.date);
            printf(" \n Enter code:");
            fwrite(&p,size,1,fp);
            
		
	}
	else if(pur==0)
	 {
			 printf(" \n Name of product: ");
            scanf("%s", p.name);
		  printf("\n  Qty of product:");
            scanf("%d", &p.qty);
            while(fread(&p,sizeof(p),1,fp)==1)
            {
            	if(strcmp(name,p.name)==0)
            	{p.qty=p.qty+qty;
            	printf("\n Quantity =%d",p.qty);
            	fseek(fp, -sizeof(p),SEEK_CUR);
            	fwrite(&p,sizeof(p),1,fp);
            	break;
				}
			}
	 }
	printf("\n\n\n\n\n\nDo you want to re-purchase  '1'else '2' to Dashboard ");
	scanf("%d",&option);
	
	}

	if(option==1){
		goto start;	
	}
	
	else
	fclose(fp);
	Dashboard();
	
				               
                   
}
   void Sell()
   {
      
    system("cls");
	FILE *fp;
	fp=fopen("product.dat","rb+");
    int sel;
	int option;
	int qty;
	int price;
	char name[100];
	struct product p;
	long int size = sizeof(p);
		start:
	if(fp==NULL)
	{
		printf("invalid");
	exit(0);
	}else{
	printf("\n\t\t\t<----sell of product Details----> ");
	printf("\n\n\t Which Product you Want to sell:");
	scanf("%d",&sel);
	
	
	//	printf("\nEnter product name: ");
	//	scanf("%s",p.name);
	//	printf("\nEnter product code: ");
	//	scanf("%s",p.code);
		printf("Enter product Qty: ");
		scanf("%d",&p.qty);
		printf("Enter product price: ");
		scanf("%f",&p.price);
		fwrite(&p,size,1,fp);	

		while (fread(&p, sizeof(p), 1, fp) == 1) {
			
			if(strcmp(name,p.name) == 0){
				p.qty= p.qty - qty;
				printf("\n Quantity = %d",p.qty);
				fseek(fp,-size,SEEK_CUR);
				fwrite(&p,size,1,fp);
				break;
			}
		}
     }
	
	printf("\n\n\n\n\n\nDo you want to re-purchase  '1'else '2' to Dashboard ");
	scanf("%d",&option);
	

	if(option==1)
	{
	goto start;
	}
		
	else
	Dashboard();
	
	fclose(fp);
	
   }
   // view Product Details
  void View_product()
  {
 	 FILE *fp;
  struct product p;
 
  fp=fopen("product.dat","rb+");
  
  printf(" \t\t \t  The details of the product:");
  printf("\n");
  printf("\n-------------------------------------------------------------------------------------------------------------");
  printf(" \n Name of product:    \t Quantity:         \t Price:           \t Date:              \t Code: ");
  printf("\n-------------------------------------------------------------------------------------------------------------");
    while(fread(&p,sizeof(p),1,fp)==1)
    {
    
    	printf("\n");
printf(" \n%s                  \t%d                \t%.2f               \t%s            \t%s",p.name,p.qty,p.price,p.date,p.code);
    	printf("\n");
    	
	}
   	
	fclose(fp);
	printf("\n\n \t\t \t Press Enter to go Dashboard\n");
	getch();
	Dashboard();    
      
 }
        
