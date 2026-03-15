#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);
  int arr[100];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Find zero
  int zero = -1001;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      zero = arr[i];
      break;
    }
  }
  int S3[100] = {zero};
  int s3_size = 1;

  // Find a negative number
  int neg1 = 1001;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      neg1 = arr[i];
      break;
    }
  }
  int S1[1] = {neg1};
  int s1_size = 1;

  // Collect positive numbers
  int poss[100];
  int poss_size = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      poss[poss_size++] = arr[i];
    }
  }

  // Form S2 with positives or two negatives
  int S2[100];
  int s2_size = 0;
  if (poss_size > 0)
  {
    for (int i = 0; i < poss_size; i++)
    {
      S2[s2_size++] = poss[i];
    }
  }
  else
  {
    int remaining_neg[100];
    int remaining_neg_size = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] < 0 && arr[i] != neg1)
      {
        remaining_neg[remaining_neg_size++] = arr[i];
      }
    }
    if (remaining_neg_size >= 2)
    {
      S2[s2_size++] = remaining_neg[0];
      S2[s2_size++] = remaining_neg[1];
    }
  }

  // Place remaining numbers in S3
  int used[2001] = {0}; // Increased to 2001 to cover -1000 to 1000
  used[zero + 1000] = 1;
  used[neg1 + 1000] = 1;
  for (int i = 0; i < s2_size; i++)
  {
    used[S2[i] + 1000] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    if (used[arr[i] + 1000] == 0)
    {
      S3[s3_size++] = arr[i];
      used[arr[i] + 1000] = 1;
    }
  }

  // Print the sets
  printf("%d", s1_size);
  for (int i = 0; i < s1_size; i++)
  {
    printf(" %d", S1[i]);
  }
  printf("\n");

  printf("%d", s2_size);
  for (int i = 0; i < s2_size; i++)
  {
    printf(" %d", S2[i]);
  }
  printf("\n");

  printf("%d", s3_size);
  for (int i = 0; i < s3_size; i++)
  {
    printf(" %d", S3[i]);
  }
  printf("\n");

  return 0;
}