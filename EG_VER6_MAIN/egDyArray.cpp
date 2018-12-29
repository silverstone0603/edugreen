#include "stdafx.h"
#include "egDyArray.h"

egDyArray::egDyArray() : m_size(1), m_used(0)
{
    m_array = new int[m_size];
}
 
egDyArray::egDyArray(int size) : m_size(size), m_used(0)
{
    m_array = new int[m_size];
}
 
egDyArray::~egDyArray() 
{
    delete[] m_array;
}
 
 
void egDyArray::popBack()
{
    if (m_used == 0) return;
 
    m_used--;
    int* temp = new int[m_used];
 
    for (int i = 0; i < m_used; i++)
        temp[i] = m_array[i];
 
    delete[] m_array;
    m_array = new int[m_size];
 
    for (int j = 0; j < m_used; j++)
        temp[j] = m_array[j];
 
    delete[] temp;
    return;
}
 
void egDyArray::pushBack(int data)
{
    if (m_size > m_used)
    {
        m_array[m_used] = data;
        m_used++;
        return;
    }
 
    int* temp = new int[m_size];
 
    for (int i = 0; i < m_used; i++)
        temp[i] = m_array[i];
 
    delete[] m_array;
 
    m_size *= 2;
 
    m_array = new int[m_size];
    
    for (int j = 0; j < m_used; j++)
        m_array[j] = temp[j];
 
    m_array[m_used] = data;
    m_used++;
 
    delete[] temp;
 
    return;
}
 
void egDyArray::print()
{
    for(int i=0; i<this->m_used; i++)
        printf("%d ",this->m_array[i]);
    printf("\n");
}
 
int& egDyArray::operator[](int index)
{
    return this->m_array[index];
}
