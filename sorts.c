// SPDX-FileCopyrightText: 2026 Nathanael Steven
// SPDX-License-Identifier: MIT

static int SIZE = 15;

void bubble(int *array) {
  int swapped;
  for (int i=0; i < SIZE-1; i++) {
    swapped = 0;
    for (int j=0; j < SIZE-i-1; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        swapped = 1;
      }
    }
    if (!swapped) break;
  }
}

void insertion(int *array) {
  for (int i=0; i < SIZE; i++) {
    int val = array[i];
    int j = i-1;
    while (j >= 0 && array[j] > val) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = val;
  }
}

void selection(int *array) {
  for (int i=0; i < SIZE-1; i++) {
    int min = i;
    for (int j=i+1; j < SIZE; j++)
      if (array[j] < array[min])
        min = j;
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

void merge_combine(int *p, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = p[l + i];
  for (int j = 0; j < n2; j++) R[j] = p[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) { p[k] = L[i]; i++; }
    else { p[k] = R[j]; j++; }
    k++;
  }
  while (i < n1) { p[k] = L[i]; i++; k++; }
  while (j < n2) { p[k] = R[j]; j++; k++; }
}

void merge_sort_recursive(int *p, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort_recursive(p, l, m);
    merge_sort_recursive(p, m + 1, r);
    merge_combine(p, l, m, r);
  }
}

void merge(int *p, int n) {
  merge_sort_recursive(p, 0, n - 1);
}
