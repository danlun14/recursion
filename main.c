#include <stdio.h>
int sum_array_rec(int *arr, int n)
{
    int num_id = n - 1;
    if (n == 0)
    {
        return 0;
    }

    return sum_array_rec(arr, n - 1) + arr[num_id];
}

int sum_array_iter(int arr[], int num, int sum)
{
    if (num == 0)
    {
        return sum;
    }
    sum += arr[num - 1];
    return (sum_array_iter(arr, num - 1, sum));
}

int fib_rec(int n)
{

    if ((n == 2) || (n == 1))
    {
        return 1;
    }
    if (n > 2)
    {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
    return -1;
}

int fib_iter(int n, int cur_num, int pre_num, int count)
{
    if (count == n)
    {
        return cur_num;
    }
    if (count > 1)
    {
        return fib_iter(n, cur_num + pre_num, cur_num, count + 1);
    }
    return -1;
}

int int_to_str(int num, char *out, int cur_id)
{

    if ((num % 10) > 0)
    {
        int mo = num % 10;
        out[cur_id] = mo + 48;
    }
    if (cur_id == 0)
    {
        return 0;
    }
    return int_to_str(num / 10, out, cur_id - 1);
}

int main()
{
    int a = 0;
    int mas[5] = {11, 12, 13, 14, 20};
    printf("sum_array:\n");
    a = sum_array_rec(mas, 5);
    printf("rec - %d\n", a);
    a = 0;
    a = sum_array_iter(mas, 5, a);
    printf("iter - %d\n", a);
    a = 0;
    printf("fib:\n");
    a = fib_rec(6);
    printf("rec - %d\n", a);
    a = 0;
    a = fib_iter(6, 1, 1, 2);
    printf("iter - %d\n", a);
    a = 34667;
    char b[5];
    int_to_str(a, b, 4);
    printf("int to str - %c%c%c%c%c\n", b[0], b[1], b[2], b[3], b[4]);
}