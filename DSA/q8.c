#include<stdio.h>
struct book{
    char title[40];
    char author[40];
    float price;
}b;
int main(){
    printf("Enter the title of the book: ");
    gets(b.title);
    printf("Enter the author's name: ");
    gets(b.author);
    printf("Enter the price of the book: ");
    scanf("%f",&b.price);
    printf("The details of the book are:\n");
    printf("Title of the book: %s\nAuthor's name: %s\nPrice of the book: %f",b.title,b.author,b.price); 
}