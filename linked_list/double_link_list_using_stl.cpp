#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 
  
//function for printing the elements in a list 
void showlist(list <int> double__list) 
{ 
    list <int> :: iterator it; 
    for(it = double__list.begin(); it != double__list.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
  
    list <int> double__list1, double__list2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        double__list1.push_back(i * 2); 
        double__list2.push_front(i * 3); 
    } 
    cout << "\nList 1 (double__list1) is : "; 
    showlist(double__list1); 
  
    cout << "\nList 2 (double__list2) is : "; 
    showlist(double__list2); 
  
    cout << "\ndouble__list1.front() : " << double__list1.front(); 
    cout << "\ndouble__list1.back() : " << double__list1.back(); 
  
    cout << "\ndouble__list1.pop_front() : "; 
    double__list1.pop_front(); 
    showlist(double__list1); 
  
    cout << "\ndouble__list2.pop_back() : "; 
    double__list2.pop_back(); 
    showlist(double__list2); 
  
    cout << "\ndouble__list1.reverse() : "; 
    double__list1.reverse(); 
    showlist(double__list1); 
  
    cout << "\ndouble__list2.sort(): "; 
    double__list2.sort(); 
    showlist(double__list2); 
  
    return 0; 
  
} 
