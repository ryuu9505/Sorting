#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10000

void counting_sort (int list[], int sorted[], int count[], int cumulative_sum[], int n)
{
	int i;

	for (i = 1; i <= n; i++)
		count[list[i]]++;

	cumulative_sum[0] = count[0];
	for (i = 1; i <= MAX_NUM; i++)
		cumulative_sum[i] = count[i] + cumulative_sum[i - 1];

	for (i = n; i > 0; i--)
		sorted[cumulative_sum[list[i]]--] = list[i];
}

int main()
{
	int i;
	int n, max_num = 0;
	int count[MAX_NUM + 1];
	int cumulative_sum[MAX_NUM + 1];

	scanf("%d", &n);
	int* list = malloc(sizeof(int) * (n+1));
	int* sorted = malloc(sizeof(int) * (n+1));

	for (i = 1; i <= n; i++)
		scanf("%d", &list[i]);

	for (i = 0; i <= max_num; i++)
		count[i] = 0;

	count_sort(list, sorted, count, cumulative_sum, n);

	for (i = 1; i <= n; i++)
		printf("%d\n", sorted[i]);

	free(list);
	free(sorted);
}
