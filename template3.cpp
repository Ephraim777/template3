#include<iostream>
using namespace std;

template<typename T>
class MyClassVector
{

T*m_array;

int m_capacity;

int m_size;

using reference = T&;

public:

MyClassVector(T num, int count): m_capacity(count),m_size(count)
{

m_array = new T[count];

for(int i =0; i<count; i++)
{ 
m_array[i] = num;
}

}

MyClassVector(): m_capacity(0), m_size(0), m_array(nullptr){}


~MyClassVector()
{

delete [] m_array;

m_array = nullptr;

}

 int Size() const
 {

 return m_size;

 }
 
 int Capacity() const
 {

 return m_capacity;

 }
 
 void push_back( T value)
 {

 if (m_size == m_capacity)

 {

 if(!m_capacity)

 m_capacity = 1;

 m_capacity = m_capacity*2;

 T* new_array = new T[m_capacity];

 if(m_array!= nullptr)
 {

 for(int i = 0; i < m_size; i++)
 {

 new_array[i]=m_array[i];

 }
 
 delete [] m_array;

 }

 m_array = new_array;

 new_array = nullptr;

 }
 
 m_array[m_size] = value;

 m_size++;

 }
 
 reference at(int index)
  {

  if(index >= m_size)

  {

  throw std::out_of_range("error index");

  }

  return m_array[index];

  }
  
 reference operator [] (int index)
  {
  
  return m_array[index];

  }

};

int main()
{
    
    MyClassVector<int> v;
    v.push_back(1);

    std::cout << "Size: " << v.Size() << std::endl;
    std::cout << "Capacity: "<< v.Capacity() << std::endl;

    v.push_back(2);

    std::cout << "Size: " << v.Size() << std::endl;
    std::cout << "Capacity: "<< v.Capacity() << std::endl;

    v.push_back(3);

    std::cout << "Size: " << v.Size() << std::endl;
    std::cout << "Capacity: "<< v.Capacity() << std::endl;

    for (int i = 0; i < v.Size(); i++)
    {

    std:: cout << v[i] << " "; 

    }

    std::cout<< std::endl;

    v.at(1) = 7;

    for (int i = 0; i < v.Size(); i++)
    {

    std:: cout << v[i] << " "; 

    }
    
    return 0;
}
