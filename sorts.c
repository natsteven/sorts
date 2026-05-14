// SPDX-FileCopyrightText: 2026 Nathanael Steven
// SPDX-License-Identifier: MIT

#include <stdlib.h>

static int SIZE = 16;

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

void merge_combine(int *array, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = array[l + i];
  for (int j = 0; j < n2; j++) R[j] = array[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) { array[k] = L[i]; i++; }
    else { array[k] = R[j]; j++; }
    k++;
  }
  while (i < n1) { array[k] = L[i]; i++; k++; }
  while (j < n2) { array[k] = R[j]; j++; k++; }
}

void merge_sort_recursive(int *array, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort_recursive(array, l, m);
    merge_sort_recursive(array, m + 1, r);
    merge_combine(array, l, m, r);
  }
}

void merge(int *array, int n) {
  merge_sort_recursive(array, 0, n - 1);
}

void unsort(int *array) {
  for (int i=0; i < SIZE; i++) {
    int j = rand() % SIZE;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
