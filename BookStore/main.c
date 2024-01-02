#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product
{
    float Price ;
    int Quantity ;
    char  Name[20] ;
};
typedef struct Product  Product;

struct Catogery
{
    char Name[20];
    int ProCount;
    Product *products ;

};
struct invoice
{
    char ProName[20];
    int Quantity ;
    float price;
    float TotalPrice;

};
typedef struct invoice invoice;

typedef struct Catogery Catogery ;


struct BookStore
{

    Catogery categories[20];
    int CatCount ;

};
typedef struct BookStore BookStore ;



void Initialize(BookStore *bookstore)
{
    bookstore->CatCount=0;
    //category 1
    strcpy(bookstore->categories[0].Name, "Biographies");
    bookstore->categories[0].ProCount = 2;

    bookstore->categories[0].products = malloc(10* sizeof(Product));

    strcpy(bookstore->categories[0].products[0].Name, "Ethnic_culture ");
    bookstore->categories[0].products[0].Price = 200;
    bookstore->categories[0].products[0].Quantity = 10;


    strcpy(bookstore->categories[0].products[1].Name, "Europ_culture ");
    bookstore->categories[0].products[1].Price = 290;
    bookstore->categories[0].products[1].Quantity = 5;
    //increse array of category
    bookstore->CatCount+=1;

    // Category 2
    strcpy(bookstore->categories[1].Name, "Arts & Music");
    bookstore->categories[1].ProCount = 3;


    bookstore->categories[1].products = malloc(10 * sizeof(Product) );

    strcpy(bookstore->categories[1].products[0].Name, "Calligraphy");
    bookstore->categories[1].products[0].Price = 900;
    bookstore->categories[1].products[0].Quantity = 5;

    strcpy(bookstore->categories[1].products[1].Name, "Drawing ");
    bookstore->categories[1].products[1].Price = 400;
    bookstore->categories[1].products[1].Quantity = 20;

    strcpy(bookstore->categories[1].products[2].Name, "Painting ");
    bookstore->categories[1].products[2].Price = 250;
    bookstore->categories[1].products[2].Quantity = 9;



//increse array of category
    bookstore->CatCount +=1;

}
void DisplayBookStore(BookStore *bookstore)
{
    printf("--------------------------The Categories  and Products in BookStore------------------------------\n");
    if(bookstore->CatCount > 0)
    {
        for(int i=0; i<bookstore->CatCount; i++)
        {

            printf("=> %s\n\n\n",bookstore->categories[i].Name);
            printf("\t#\tProduct Name\tPrice\t\tQuantity\t\n");
            printf("------------------------------------------------------------------------\n");
            if(bookstore->categories[i].ProCount >0)
            {
                for(int j=0; j<bookstore->categories[i].ProCount; j++)
                {
                    printf("\t%d\t%s\t%f\t%d\t\n",j+1,bookstore->categories[i].products[j].Name,bookstore->categories[i].products[j].Price,bookstore->categories[i].products[j].Quantity
                          );


                }
            }
            else
            {
                printf("\t\tNot Found Product in This Category \n ");

            }
            printf("------------------------------------------------------------------------\n");


        }
    }
    else
    {
        printf("Not Found any Category ..");
    }


}

//Add category
void AddCategory(BookStore *bookstore)
{
    char ch='Y';
    while(ch != 'N')
    {

        if(bookstore->CatCount < 20)
        {
            printf("=> Enter The Name of Category : ");
            char NewCat[20];
            scanf("%s",NewCat);

            int IsExists = 0;
            for(int i=0; i<bookstore->CatCount; i++)
            {
                if(strcmp(NewCat, bookstore->categories[i].Name) == 0)
                {
                    printf("The Name of Category is Exists\n");
                    IsExists = 1;
                    break;

                }

            }

            if(IsExists == 0)
            {

                strcpy( bookstore->categories[bookstore->CatCount].Name,NewCat);
                bookstore->categories[bookstore->CatCount].ProCount=0;
                bookstore->categories[bookstore->CatCount].products = malloc(10 * sizeof(Product));

                bookstore->CatCount++;
                printf("The Category has been Added successfully\n");


            }



        }
        else
        {
            printf("=> You Can`t Add New Category \n");
        }
        printf("Would you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }
}
void RemoveCategory(BookStore *bookstore)
{
    char ch='Y';
    while(ch != 'N')
    {

        printf("\n\n---------- The Categories in BookStore ---------\n\n");
        if(bookstore->CatCount > 0)
        {
            for(int i=0; i<bookstore->CatCount; i++)
            {

                printf("%d - %s (products = %d)\n\n",i+1, bookstore->categories[i],bookstore->categories[i].ProCount);
            }
            printf("=> Enter The Number  of Category you want to remove : ");
            int Num;
            scanf("%d",&Num);
            if(Num >=1 && Num <= bookstore->CatCount )
            {
                Num--;

                //free the Products
                free(bookstore->categories[Num].products);

                for(int i=Num; i<=bookstore->CatCount - 1; i++)
                {
                    bookstore->categories[i]=bookstore->categories[i+1];
                }

                bookstore->CatCount --;
                printf("=> The Category Is Removed Successfully \n");
            }
            else
            {
                printf("=> Please  Enter The Valid Number ?\n");

            }
        }
        else
        {
            printf("=> Not Found any category \n");
        }
        printf("Would you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }


}
void AddProduct(BookStore *bookstore)
{
    char ch='Y';
    while(ch != 'N')
    {

        char ProName[20] ;
        float price ;
        int  Quantity ;
        printf("Enter The Name of Product ? ");
        scanf("%s",ProName);
        //check if product is exists or not
        int ProIndex = -1;
        for(int i=0; i<bookstore->CatCount; i++)
        {
            for(int j=0; j<bookstore->categories[i].ProCount; j++)
            {
                if(strcmp(bookstore->categories[i].products[j].Name,ProName)==0)
                {
                    ProIndex = j;
                    break;
                }

            }
        }
        if(ProIndex != -1)
        {
            printf("The Product is Exists \n");
        }
        else
        {
            printf("Enter The Price Of Product ? ");
            scanf("%f",&price);
            printf("Enter The Quantity of Product ? ");
            scanf("%d",&Quantity);



            //display the category
            for(int i=0; i<bookstore->CatCount; i++)
            {

                printf("%d - %s (products = %d)\n\n",i+1, bookstore->categories[i],bookstore->categories[i].ProCount);
            }

            printf("\nChoose The Number of Category \n");
            int CatNum;
            scanf("%d",&CatNum);



            if(CatNum >= 1 && CatNum <= bookstore->CatCount )
            {
                CatNum--;
                bookstore->categories[CatNum].ProCount+=1;

                if(bookstore->categories[CatNum].ProCount > 3){

                    bookstore->categories[CatNum].ProCount-=1;

                    printf("The Array is Full \n");


                }
                else{


                strcpy(bookstore->categories[CatNum].products[bookstore->categories[CatNum].ProCount -1].Name, ProName );
                bookstore->categories[CatNum].products[bookstore->categories[CatNum].ProCount -1].Price = price;
                bookstore->categories[CatNum].products[bookstore->categories[CatNum].ProCount -1].Quantity = Quantity;
                printf("The product has been added successfully\n");
                }

            }
            else
            {
                printf("Enter The Valid Number\n");
            }

                }



        printf("Would you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }

}
void RemoveProduct(BookStore *bookstore)
{
    char ch='Y';
    while(ch != 'N')
    {

        for(int i=0; i<bookstore->CatCount; i++)
        {

            printf("%d - %s (products = %d)\n\n",i+1, bookstore->categories[i],bookstore->categories[i].ProCount);
        }

        printf("\nChoose The Number of Category \n");
        int CatNum;
        scanf("%d",&CatNum);


        if(CatNum >= 1 && CatNum <= bookstore->CatCount  )
        {
            CatNum--;
            if(bookstore->categories[CatNum].ProCount > 0)
            {
            printf("\n\n---------- The Products in This Category ---------\n\n");

                for(int i=0 ; i<bookstore->categories[CatNum].ProCount ; i++)
                {

                    printf("%d - %s\n",i+1,bookstore->categories[CatNum].products[i].Name);

                }
                //if(bookstore->categories[CatNum].ProCount >0){

                printf("\nChoose The Number of Product Will Delete \n");

                int ProNum;
                scanf("%d",&ProNum);

                if(ProNum >= 1 && ProNum <= bookstore->categories[CatNum].ProCount  )
                {
                    ProNum--;

                    for(int i=ProNum ; i<bookstore->categories[CatNum].ProCount -1 ; i++)
                    {

                        bookstore->categories[CatNum].products[i]= bookstore->categories[CatNum].products[i+1];
                    }
                    bookstore->categories[CatNum].ProCount--;


                    printf("The product has been Deleted Successfully\n");

                }
                else
                {
                    printf("Enter The Valid Number \n ");

                }
            }
            else
            {

                printf("Not Found Product in This Category \n ");

            }

        }
        else
        {
            printf("Enter The Valid Number \n ");
        }

        printf("Would you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }

}
void MoveProduct(BookStore *bookstore)
{
    char ch='Y';
    while(ch != 'N')
    {
//1-Enter the product will Move
        char ProName[20];
        printf("Enter The Product Will Move ? ");
        scanf("%s",ProName);
        int OldCatIndex =-1, ProIndex = -1;

        for(int i=0; i<bookstore->CatCount; i++)
        {
            for(int j=0; j<bookstore->categories[i].ProCount; j++)
            {
                if(strcmp(bookstore->categories[i].products[j].Name,ProName)==0)
                {
                    OldCatIndex = i;
                    ProIndex = j;
                    break;
                }

            }
        }

    //If product is found
    if(ProIndex != -1){

//2- Enter the Category
        char CatName[20];
        int NewCatIndex = -1;
        printf("Enter The Category Will Move To  ? ");
        scanf("%s",CatName);
        for(int i=0; i<bookstore->CatCount; i++)
        {
            if(strcmp(bookstore->categories[i].Name,CatName)==0)
            {

                NewCatIndex = i;
                break;
            }

        }

        if(NewCatIndex == -1 || ProIndex == -1)
        {
            printf("The Category is Not Exists \n");
        }
        else
        {
            int ProCount = bookstore->categories[NewCatIndex].ProCount;
            printf("ProCount = %s",bookstore->categories[OldCatIndex].products[ProIndex].Name);

// add the Product to the New category
            bookstore->categories[NewCatIndex].products[ProCount] = bookstore->categories[OldCatIndex].products[ProIndex];
            bookstore->categories[NewCatIndex].ProCount ++;

//shifting the product in old Category
            for(int i=ProIndex; i<bookstore->categories[OldCatIndex].ProCount -1 ; i++)
            {

                bookstore->categories[OldCatIndex].products[i] = bookstore->categories[OldCatIndex].products[i+1];

            }
            bookstore->categories[OldCatIndex].ProCount --;

            printf("The Product Is Moved To Another Category \n");

        }
    }
    else{
        //if Product Not Found
        printf("The Product / Category is Not Exists \n");

    }
        printf("Would you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }
}

void Sell(BookStore *bookstore)
{
    char ch='Y';
    int i=0;
    float TotalPriceAll =0;
    invoice MyInvoice[10];
    while(ch != 'N')
    {

        //display the category
        for(int i=0; i<bookstore->CatCount; i++)
        {

            printf("%d - %s (products = %d)\n\n",i+1, bookstore->categories[i],bookstore->categories[i].ProCount);
        }

        printf("\nChoose The Number of Category \n");
        int CatNum;
        scanf("%d",&CatNum);



        if(CatNum >= 1 && CatNum <= bookstore->CatCount )
        {
            //display Product in category
            CatNum--;
            if(bookstore->categories[CatNum].ProCount > 0)
            {
                for(int j=0; j<bookstore->categories[CatNum].ProCount; j++)
                {
                    printf("%d- %s\n",j+1,bookstore->categories[CatNum].products[j].Name);
                }

                printf("Choose The Number of Product You want  \n");
                int ProNum;
                scanf("%d",&ProNum)  ;
                if(ProNum >=1 && ProNum <= bookstore->categories[CatNum].ProCount)
                {
                    ProNum--;
                    int NewQuentity ;
                    float TotalPrice = 0;

                    printf("Enter The Quantity You want ? ");
                    scanf("%d",&NewQuentity);
                    if(NewQuentity > bookstore->categories[CatNum].products[ProNum].Quantity)
                    {
                        printf("The Quantity of Product is %d Only \n",bookstore->categories[CatNum].products[ProNum].Quantity) ;
                    }
                    else
                    {
                        // update the Quantity of product and calculate the Total Price
                        bookstore->categories[CatNum].products[ProNum].Quantity -= NewQuentity;
                        //if Quantity is 0 remove the product from category
                        if(bookstore->categories[CatNum].products[ProNum].Quantity == 0)
                        {

                            for(int i=ProNum ; i<bookstore->categories[CatNum].ProCount-1 ; i++)
                            {

                                bookstore->categories[CatNum].products[i]=bookstore->categories[CatNum].products[i+1];

                            }
                            bookstore->categories[CatNum].ProCount --;

                        }
                        TotalPrice += bookstore->categories[CatNum].products[ProNum].Price * NewQuentity ;
                        TotalPriceAll +=bookstore->categories[CatNum].products[ProNum].Price * NewQuentity ;

                        //array  to store the invoice
                        strcpy(MyInvoice[i].ProName,bookstore->categories[CatNum].products[ProNum].Name);
                        MyInvoice[i].price =bookstore->categories[CatNum].products[ProNum].Price;
                        MyInvoice[i].TotalPrice = TotalPrice;
                        MyInvoice[i].Quantity = NewQuentity ;
                        printf("Product Name -  Price  - Quantity -  Total Price  \n");

                        for(int j=0; j<=i; j++)
                        {
                            printf("%s   %f$    %d    %f$\n",MyInvoice[j].ProName,MyInvoice[j].price, MyInvoice[j].Quantity, MyInvoice[j].TotalPrice);
                        }

                        printf("\t\t\t\tTotalQuantity = %f$\n",TotalPriceAll);
                        //
                        i++;




                    }
                }
                else
                {

                    printf("Not Found Product in This Category \n ");

                }
            }
            else
            {
                printf("Enter The Vaild Number \n");
            }

        }
        else
        {
            printf("Enter The Vaild Number\n");
        }

        printf("Woud you want to Continue Y | N ?\n");
        scanf("%s",&ch);

    }
}

int main()
{
    BookStore bookstore;
    printf("\n\n\t\t* BookStore - Best place to learn *\n\n\n");
    Initialize(&bookstore);
    int choice;
    while(1)
    {

        printf("\t 1. Display BookStore  \n");
        printf("\t 2. Add Category       \n");
        printf("\t 3. Add Product \n");
        printf("\t 4. Remove Category     \n");
        printf("\t 5. Remove Product     \n");
        printf("\t 6. Move  Product     \n");
        printf("\t 7. Sell  Product     \n");
        printf("\t 8. Exit               \n\n\n\n");
        printf("=> Enter your choice :  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");

            DisplayBookStore(&bookstore);
            break;
        case 2:
            system("cls");

            AddCategory(&bookstore);
            break;
        case 3:
            system("cls");
            AddProduct(&bookstore);
            break;
        case 4:
            system("cls");

            RemoveCategory(&bookstore);
            break;
        case 5:
            system("cls");

            RemoveProduct(&bookstore);
            break;
        case 6:
            system("cls");

            MoveProduct(&bookstore);
            break;

        case 7:
            system("cls");

            Sell(&bookstore);
            break;
        case 8:
            exit(0);
        default:
            printf("=> Enter The Valid Number From menu \n");

        }



    }


    return 0;
}



