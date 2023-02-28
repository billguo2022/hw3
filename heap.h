#ifndef HEAP_H
#define HEAP_H

#include <vector> 
#include <functional>
#include <stdexcept> 
#include <algorithm>

#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> heap_vec;
  PComparator comp;
  int ari;

  void heapifup(int index);
  void heapifdown(int index);

  
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  

  ari = m;
  comp = c;

}



template <typename T, typename Comparator>
Heap<T, Comparator>::~Heap() {}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  
    // ================================
    // throw the appropriate exception
    // ================================

   if (empty()) {
    throw std::underflow_error("Heap is empty!");
  }
  return heap_vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty!");
  }
  if(heap_vec.size() == 1){
    heap_vec.pop_back();
    return;
  }
  std::swap(heap_vec[0], heap_vec[heap_vec.size() - 1]);
  
  heap_vec.pop_back();
  heapifdown(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifdown(int index)
{
  int in_r = 2*index +1;
  
  int in_l = 2*index +2;

  
  int next = index;
	int heapsize= heap_vec.size();
  if (in_l < heapsize){
    
    if (comp(heap_vec[in_l], heap_vec[index])){ 
      next= in_l;
    }
  }
  
  if (in_r < heapsize){
    if (comp(heap_vec[in_r], heap_vec[next])){
      next = in_r;
    }
  }

  if (next != index){
    std::swap(heap_vec[index], heap_vec[next]);
    heapifdown(next);
  }
} 


template <typename T, typename Comparator>
void Heap<T, Comparator>::push(const T& item) {
  heap_vec.push_back(item);

  heapifup(heap_vec.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifup(int index)
{
    int in_p = (index-1)/2;

    if (comp(heap_vec[index], heap_vec[in_p])){
      
      std::swap(heap_vec[in_p], heap_vec[index]);
      
      heapifup(in_p);
    }
}



template <typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const {
  return heap_vec.empty();
}

template <typename T, typename Comparator>
size_t Heap<T, Comparator>::size() const {
  return heap_vec.size();
}

#endif






