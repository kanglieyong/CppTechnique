template <typename T>
class Pointer
{
 public:
  Pointer(T* inPtr);
  virtual ~Pointer();
  // Dereference operators will go here.
  const T* operator->() const;
  const T& operator*() const;

  T* operator->();
  T& operator*();

 protected:
  T* mPtr;

 private:
  // Prevent assignment and pass by value.
  Pointer(const Pointer<T>& src);
  Pointer<T>& operator=(const Pointer<T>& rhs);
};

template <typename T>
Pointer<T>::Pointer(T* inPtr)
{
  mPtr = inPtr;
}

template <typename T>
Pointer<T>::~Pointer()
{
  delete mPtr;
  mPtr = nullptr;
}

template <typename T>
const T* Pointer<T>::operator->() const
{
  return mPtr;
}

template <typename T>
const T& Pointer<T>::operator*() const
{
  return *mPtr;
}

template <typename T>
T* Pointer<T>::operator->()
{
  return mPtr;
}

template <typename T>
T& Pointer<T>::operator*()
{
  return *mPtr;
}
