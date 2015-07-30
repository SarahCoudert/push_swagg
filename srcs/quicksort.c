void swap(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int arr[], int beg, int end)
{
    int piv;
    int l;
    int r;

    l = 0;
    r = 0;
    piv = 0;
    if (end > beg + 1)
    {
        piv = arr[beg];
        l = beg + 1;
        r = end;
        while (l < r)
        {
          if (arr[l] <= piv)
            l++;
          else
            swap(&arr[l], &arr[--r]);
        }
        swap(&arr[--l], &arr[beg]);
        sort(arr, beg, l);
        sort(arr, r, end);
    }
}