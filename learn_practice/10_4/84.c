// ×óÐý×Ö·û´®
#include <stdio.h>
#include <string.h>
#include <assert.h>

// 0.1
//  void left_revolve(char *arr, int n)
//  {
//      int i = 0;
//      char tmp = 0;
//      for (i = 0; i < n; i++)
//      {
//          tmp = *arr;

//         int j = 0;
//         while (*(arr + 1 + j))
//         {
//             *(arr + j) = *(arr + 1 + j);
//             j++;
//         }

//         *(arr + j) = tmp;
//     }
// }

// 0.2
void reverse(char arr[], int len)
{
    char *left = arr;
    char *right = arr + len - 1;
    assert(left && right);
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main()
{
    char arr[] = "abcdef";
    int len = strlen(arr);
    int n = 0;
    scanf("%d", &n);
    n %= len;
    // left_revolve(arr, n);

    reverse(arr, n);
    reverse(arr + n, len - n);
    reverse(arr, len);
    printf("%s\n", arr);
    return 0;
}