#include <vector>

// Sorting interfaces
void insertion_sort(std::vector<int> &);
void selection_sort(std::vector<int> &);
void merge_sort(std::vector<int> &,int , int);
void heap_sort(std::vector<int> &);

// Sorting helper interfaces
void merge(std::vector<int> &, int , int , int);

void max_heapify(std::vector<int> &, int );
bool is_max_heap(std::vector<int> &, int );