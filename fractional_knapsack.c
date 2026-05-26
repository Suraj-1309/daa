#include <stdio.h>

// Structure for an item
struct Item {
    int profit;
    int weight;
    float ratio;
};

// Sort items by ratio in descending order
void sortItems(struct Item items[], int n) {
    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}




























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 // Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n log n)
 // Space Complexity: O(n) (to store items)
 // Explanation: Sorting items by value/weight ratio dominates time at O(n log n);
 // the greedy pass is linear. Space is O(n) for the item array (auxiliary space O(1)).

/*
Enter number of items: 3
Enter profit and weight of each item:
60 10
100 20
120 30
Enter knapsack capacity: 50
*/