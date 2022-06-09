/*
 * 파일이름 : BoundCheckArray.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 08] 파일버전 0.10
 */
#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "Account.h"

//typedef Account * ACCOUNT_PTR;
template <typename T>
class BoundCheckArray
{
    private:
        T * arr;
        int arrlen;
        BoundCheckArray(const BoundCheckArray& arr) { }
        BoundCheckArray& operator=(const BoundCheckArray& arr) { }
    public:
        BoundCheckArray(int len = 100);
        T& operator[] (int idx);
        T operator[] (int idx) const;
        int GetArrLen() const;
        ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len = 100)
    : arrlen(len)
{
    arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
    if(idx < 0 || idx >= arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
    if(idx < 0 || idx >= arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
    return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
    delete []arr;
}

#endif