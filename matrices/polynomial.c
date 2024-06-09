#include <stdio.h>
#include <stdlib.h> // for malloc function

struct Term {
    int coeff;          // stores the coeffiecient of a polynomial term
    int exponent;       // stores the exponent of the term
};

struct Polynomial {
    int n; // number of non-zero terms;
    struct Term *terms; // a pointer to dynamically create the needed number of terms;
};

void createPoly(struct Polynomial *p){
    int i;
    printf("Enter number of terms: ");
    scanf("%d", &p->n);
    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term));

    printf("Enter terms: Coefficient Exponent \n");
    for(i=0; i<p->n; i++)
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exponent);
}

void displayPoly(struct Polynomial p){
    int i;
    printf("\n");
    for(i=0; i<p.n; i++)
        printf("%dx^%d + ", p.terms[i].coeff, p.terms[i].exponent);
    printf("\n");
}

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2){
    int i, j, k;
    struct Polynomial *sum;
    sum = (struct Polynomial*)malloc(sizeof(struct Polynomial));

    sum->terms = (struct Term*)malloc((p1->n + p2->n)*sizeof(struct Term));
    i=j=k=0;

    while(i<p1->n && j<p2->n){
        if(p1->terms[i].exponent > p2->terms[j].exponent)
            sum->terms[k++] = p1->terms[i++];               // we don't need to copy coeff and exponents individually as copying a struct copies all it's members
        else if(p1->terms[i].exponent < p2->terms[j].exponent)
            sum->terms[k++] = p2->terms[j++];               // we do a post assignment increment of k and j;
        else {
            sum->terms[k].exponent = p1->terms[i].exponent;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    //  if the loop terminates because one of the polynomials have a shorter length,
    //  then we must make sure the remaining elements are copied into the sum polynomial

    for(; i<p1->n; i++) sum->terms[k++] = p1->terms[i];
    for(; j<p2->n; j++) sum->terms[k++] = p2->terms[j];

    sum->n = k;
    
    return sum;
}

int main(){

    struct Polynomial p1, p2, *p3;
    createPoly(&p1);
    createPoly(&p2);
    displayPoly(p1);
    displayPoly(p2);

    p3 = add(&p1, &p2);
    displayPoly(*p3);

    return 0;
}