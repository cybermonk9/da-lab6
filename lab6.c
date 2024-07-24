#include <stdio.h>
int max(int a, int b) {
return (a > b) ? a : b;
}
void knapsack(int wt[], int val[], int w, int n) {
int i, j;
int sol[n + 1][w + 1];
for (i = 0; i <= n; i++) {
for (j = 0; j <= w; j++) {
if (i == 0 || j == 0)
sol[i][j] = 0;
else if (wt[i] > j)
sol[i][j] = sol[i - 1][j];
else
sol[i][j] = max(sol[i - 1][j], sol[i - 1][j - wt[i]] + val[i]);
}
}
printf("The optimal solution is %d\n", sol[n][w]);
int selected[n + 1];
for (i = 0; i < n + 1; i++)
selected[i] = 0;
i = n;
j = w;
while (i > 0 && j > 0) {
if (sol[i][j] != sol[i - 1][j]) {
selected[i] = 1;
j = j - wt[i];
}
i--;
}
printf("\nItems selected:\n");
i = 1;
while (i < n + 1) {
if (selected[i] == 1)
printf("%d ", i);
i++;
}
printf("\n");
}
int main() {
int n, w;
int i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int wt[n + 1], val[n + 1];
printf("Enter weight for %d elements:\n", n);
i = 1;
while (i <= n) {
scanf("%d", &wt[i]);
i++;
}
printf("Enter value for %d elements:\n", n);
i = 1;
while (i <= n) {
scanf("%d", &val[i]);
i++;
}
printf("Enter the knapsack weight: ");
scanf("%d", &w);
knapsack(wt, val, w, n);
return 0;
}