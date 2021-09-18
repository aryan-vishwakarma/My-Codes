#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
struct poly
{
    int coeff;
    int pow;
    struct poly *next;
};
void inputPoly(struct poly **p)
{
    struct poly *current, *new_node;
    current = *p;
    int n;
    printf("Enter the order: ");
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        new_node = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &new_node->coeff);
        new_node->pow = i;
        new_node->next = NULL;
        if (*p == NULL)
        {
            current = new_node;
            *p = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    printPoly(*p);
}
void create_node(int x, int y, struct poly **temp)
{
    struct poly *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (struct poly *)malloc(sizeof(struct poly));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct poly *)malloc(sizeof(struct poly));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct poly *)malloc(sizeof(struct poly));
        r = r->next;
        r->next = NULL;
    }
}
void printPoly(struct poly *node)
{
    struct poly *current = node;
    while (current->next != NULL)
    {
        printf("%dx^%d", current->coeff, current->pow);
        current = current->next;
        if (current->coeff >= 0)
        {
            printf("+");
        }
    }
    printf("%d\n", current->coeff);
}
void polyadd(struct poly *poly1, struct poly *poly2, struct poly **poly)
{
    struct poly *current, *new_node;
    current = *poly;
    while (poly1 && poly2)
    {
        new_node = (struct poly *)malloc(sizeof(struct poly));
        new_node->next = NULL;
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->pow > poly2->pow)
        {
            new_node->pow = poly1->pow;
            new_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->pow < poly2->pow)
        {
            new_node->pow = poly2->pow;
            new_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else
        {
            new_node->pow = poly1->pow;
            new_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (*poly == NULL)
        {
            *poly = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = current->next;
        }
    }
    while (poly1 || poly2)
    {
        new_node = (struct poly *)malloc(sizeof(struct poly));
        new_node->next = NULL;
        if (poly1)
        {
            new_node->pow = poly1->pow;
            new_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2)
        {
            new_node->pow = poly2->pow;
            new_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        current->next = new_node;
        current = current->next;
    }
}
int main()
{
    struct poly *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    inputPoly(&poly1);
    inputPoly(&poly2);
    printPoly(poly1);
    printPoly(poly2);
    polyadd(poly1, poly2, &poly);
    //printPoly(poly1);
    //printPoly(poly2);
    printPoly(poly);
    /*create_node(5, 2, &poly1);
    create_node(4, 1, &poly1);
    create_node(2, 0, &poly1);
    create_node(-5, 1, &poly2);
    create_node(-5, 0, &poly2);
    printf("1st Number: ");
    printPoly(poly1);
 
    printf("\n2nd Number: ");
    printPoly(poly2);
 
    poly = (struct poly*)malloc(sizeof(struct poly));
 
    // Function add two polynomial numbers
    polyadd(poly1, poly2, poly);
 
    // Display resultant List
    printf("\nAdded polynomial: ");
    printPoly(poly);*/

    return 0;
}