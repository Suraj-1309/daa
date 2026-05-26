#include<stdio.h>
#include<math.h>

#define EPS 0.0001

int main(){
    double a, b;
    int type;
    int k;

    int log_power = 0;
    
    printf("Enter a: ");
    scanf("%lf",&a);

    printf("Enter b: ");
    scanf("%lf",&b);

    if(a <= 0 || b <= 1){
        printf("\n Does not apply (invalid a or b)\n");
        return 0;
    }

    if(a < 1){
        printf("\nDoes not apply (a < 1)\n");
        return 0;
    }

    printf("\n Select f(n) type: \n");
    printf("1. n^k \n");
    printf("2. n^k log n\n");
    printf("3. n^k log^2 n\n");
    printf("Choice: ");
    scanf("%d", &type);

    printf("Enter k (power of n): ");
    scanf("%d", &k);

    if(type == 2) log_power = 1;
    if(type == 3) log_power = 2;

    double logba = log(a) / log(b);

    //case 1
    if(k < logba - EPS){
        printf("\n Case 1 applies\n");
        int power = (int)(logba + 0.5);
        printf("T(n) = Theta(n ^ %d) \n", power);
    }

    // case 2
    else if(fabs(k - logba) < EPS){
        printf("\n Case 2 applies \n");
        printf("T(n) = Theta(n ^ %d ", k);

        if(log_power + 1 == 1){
            printf("log n");
        }
        else{
            printf("log^%d n", log_power + 1);
        }
        printf(")\n");
    }

    //case 3
    else{
        if(type == 1 || type == 2 || type == 3){
            printf("\n Case 3 applies\n");
            printf("T(n) = Theta(n^%d ", k);

            if(log_power == 1){
                printf("log n");
            }
            else if(log_power == 2){
                printf("log^2 n");
            }
            printf(")\n");
        }
        else{
            printf("\n Does not apply\n");
        }
    }

    return 0;
}




















// Time Complexity: Best: O(1), Average: O(1), Worst: O(1)
// Space Complexity: O(1)
// Explanation: This program computes case selection using constant-time math operations
// (log, comparisons). It does not process input sizes iteratively, so complexity is O(1).