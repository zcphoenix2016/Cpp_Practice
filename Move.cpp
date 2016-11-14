#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <utility>
using namespace std;

class String
{
public:
    String():m_data(nullptr)
    {
        cout << "default constructor" << endl;
        m_data = new char[1];
    }
    String(const char * ptr)
    {
        assert(ptr != nullptr);
        int iLength = strlen(ptr);
        m_data = new char[iLength + 1];
        strcpy(m_data, ptr);
    }
    String(const String & other)
    {
        cout << "copy constructor" << endl;
        if(other.m_data != nullptr)
        {
            int iLength = strlen(other.m_data);
            m_data = new char[iLength + 1];
            strcpy(m_data, other.m_data);
        }
    }
    String(String && other)
    {
        cout << "move constructor" << endl;
        if(other.m_data != nullptr)
        {
            m_data = other.m_data;
            other.m_data = nullptr;
        }
    }
    String & operator=(const String & other)
    {
        cout << "copy assignment operator" << endl;
        if(m_data != nullptr)
            delete m_data;
        if(other.m_data != nullptr)
        {
            int iLength = strlen(other.m_data);
            m_data = new char[iLength + 1];
            strcpy(m_data, other.m_data);
        }
        return *this;
    }
    String && operator=(String && other)
    {
        cout << "move assignment operator" << endl;
        if(other.m_data != nullptr)
        {
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return move(*this);
    }
    friend ostream& operator<<(ostream& os, String& obj);
    ~String()
    {
        if(m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }
private:
    char * m_data = nullptr;
};

ostream& operator<<(ostream& os,String& obj)
{
    os << obj.m_data;
    return os;
}

String doCopy(const String& str)
{
    return str;
}

template<typename T>
decltype(auto) myMove(T&& param)
{
    cout << "my move" << endl;
    using ReturnType = typename remove_reference<T>::type&&;
    return static_cast<ReturnType>(param);
}

String && doMyMove(String && str)
{
    return myMove(str);
}

String && doMove(String && str)
{
    return move(str);
}

template<typename T>  
inline T&& myForward(typename std::remove_reference<T>::type& param)   
{
    return static_cast<T&&>(param);
}  
  
template<typename T>  
inline T&& myForward(typename std::remove_reference<T>::type&& param)   
{  
    static_assert(!std::is_lvalue_reference<T>::value, "template argument substituting T is an lvalue reference type");  
    return static_cast<T&&>(param);  
}  

String && doForward(String && str)
{
    return std::forward<String>(str);
}

void display(String & str)
{
    cout << "lvalue" << endl;
}

void display(String && str)
{
    cout << "rvalue" << endl;
}

// void display(String str)
// {
//     cout << "value" << endl;
// }

int main()
{
    String strA("hello");
    display(myMove(strA));
    
    String&& strB = move(strA);
    display(strB);
}

