#include<stdio.h>
#include<string.h>

enum state {A,B,C, D};
enum state Delta[4][2] = {{B, A},{A,C}, {A,D}, {A,D}};
int c ; 
char str[100];
int i, L;
enum state q = A;

int main()
{
    /* code */
    L = strlen(str);
    printf("Nhap xau:");
    fflush(stdin); 
    fgets(str, L );
    i = 0;
    c = str[i] - 97;

    while (i < L)       
    {
        if (c== 0  || c == 1)
        {
            q = Delta[q][c];
            i++;
            c = str[i] - 97;
        }
        else
        {
            printf("Xau khong hop le");
            break;
        }
    }
    if (q == L)
    {   
        if (q == D)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        } 
    }

    
    return 0;
}
