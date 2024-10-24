// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero");
      else if (sz > MAX_VECTOR_SIZE)
          throw out_of_range("Size of vector is very long");
      pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
      pMem = new T[sz];
      std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) :  sz(v.sz)
  {
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
        pMem[i] = v.pMem[i];
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      v.pMem = nullptr;
      sz = v.sz;
      v.sz = 0;
  }
  ~TDynamicVector(){
     delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v) 
  {
      delete[] pMem;
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
        pMem[i] = v.pMem[i];
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      pMem = v.pMem;
      v.pMem = nullptr;
      sz = v.sz;
      v.sz = 0;
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind < 0 || ind >=sz)
          throw out_of_range("Index out of range");
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind < 0 || ind >= sz)
          throw("Index out of range");
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if ((ind > 0) && (ind < sz)) 
        return pMem[ind];
      else 
        throw ("Index out of range");
  }
  const T& at(size_t ind) const
  {
      if ((ind > 0) && (ind < sz))
        return pMem[ind];
      else
        throw ("Index out of range");
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
        return false;
      for (int i = 0; i < sz; i++)
        if (pMem[i] != v.pMem[i]) 
            return false;
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
        res.pMem[i] = pMem[i] + val;
      return res;
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - val;
      return res;
  }
  TDynamicVector operator*(double val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector res = TDynamicVector(std::max(sz, v.sz));
      for (int i = 0; i < min(sz, v.sz); i++) {
          res[i] = pMem[i] + v.pMem[i];
      }
      if (sz > v.sz) {
          for (int i = v.sz; i < sz; i++) {
              res[i] = pMem[i];
          }
      }
      else {
          for (int i = sz; i < v.sz; i++) {
              res[i] = v.pMem[i];
          }
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector res = TDynamicVector(std::max(sz, v.sz));
      for (int i = 0; i < min(sz, v.sz); i++) {
          res[i] = pMem[i] - v.pMem[i];
      }
      if (sz > v.sz) {
          for (int i = v.sz; i < sz; i++) {
              res[i] = pMem[i];
          }
      }
      else {
          for (int i = sz; i < v.sz; i++) {
              res[i] = -v.pMem[i];
          }
      }
      return res;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      T res = 0;
      for (int i = 0; i < sz; i++) {
          res += pMem[i] * v.pMem[i];
      }
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
  int get_size() {
      return sz;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    if (s > MAX_MATRIX_SIZE) {
       throw out_of_range("Size of matrix very long");
    }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
     if (sz != m.sz)
        return false;
     for (int i = 0; i < sz; i++)
        if (pMem[i] != m.pMem[i])
            return false;
     return true;
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) 
              res[i] += pMem[i][j] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++) {
          res[i] = 0;
          for (int j = 0; j < sz; j++)
              res[i] += pMem[i][j] * v[j];
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix<T> res(std::max(sz, m.sz));
      for (int i = 0; i < std::min(sz, m.sz); i++) {
          for (int j = 0; j < std::min(sz, m.sz); j++) {
              res[i][j] = pMem[i][j] + m[i][j];
          }
      }
      if (sz > m.sz) {
          for (int i = m.sz; i < sz; i++) {
              for (int j = m.sz; j < sz; j++) {
                  res[i][j] = pMem[i][j];
              }
          }
      }
      else {
          for (int i = sz; i < m.sz; i++) {
              for (int j = sz; j < m.sz; j++) {
                  res[i][j] = m[i][j];
              }
          }
      }
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix<T> res(std::max(sz, m.sz));
      for (int i = 0; i < std::min(sz, m.sz); i++) {
          for (int j = 0; j < std::min(sz, m.sz); j++) {
              res[i][j] = pMem[i][j] - m[i][j];
          }
      }
      if (sz > m.sz) {
          for (int i = m.sz; i < sz; i++) {
              for (int j = m.sz; j < sz; j++) {
                  res[i][j] = pMem[i][j];
              }
          }
      }
      else {
          for (int i = sz; i < m.sz; i++) {
              for (int j = sz; j < m.sz; j++) {
                  res[i][j] = m[i][j];
              }
          }
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (m.sz != sz)
          throw ("The sizes of the matrix are different");
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              res.pMem[i][j] = 0;
              for (int t = 0; t < sz; t++)
                  res.pMem[i][j] += pMem[i][t] * m.pMem[t][j];
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          for (size_t i = 0; i < pMem[i].sz; i++)
              istr >> v.pMem[i].pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++) {
          for (size_t j = 0; j < v.sz; j++)
              ostr << v.pMem[i][j] << ' ';
      }
      return ostr;
  }
  int get_size() {
      return this->sz;
  }
};

#endif
