/***************************************************************
 *
 * file:    dynamic_array.cxx
 * author:  Ken Zyma
 *
 * This file contains the implementation for the templated dynamic
 * array class.
 *
 * Modification history:
 *      created: January, 2014
 ***************************************************************/

/*value semantics */
template<class T>
DynamicArray<T>::DynamicArray(const std::size_t capacity):size(0),capacity(capacity),array(new T[capacity]){
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original){
    this->capacity = original.capacity;
    this->size = original.size;
    this->array = new T[capacity];

    for (size_t i=0; i<(this->size); i++) {
        array[i]=original[i];
    }
}

template<class T>
DynamicArray<T> DynamicArray<T>::operator =(const DynamicArray<T>& rhs){
    //check if both occupy same memory address
    if (this==&rhs) {
        return *this;
    }
    
    delete[] array;
    this->capacity=rhs.capacity;
    this->size=rhs.size;
    array=new T[capacity];
    
    for (size_t i=0; i<(rhs.size); i++) {
        array[i]=rhs[i];
    }
    
    return *this;
}

template<class T>
DynamicArray<T>::~DynamicArray(){
    delete[] array;
    array = nullptr;
}

template<class T>
void DynamicArray<T>::resize(){
    size_t newCapacity = this->capacity*2;
    T* newArray = new T[newCapacity];
    
    for (size_t i=0; i<(this->size); i++) {
        newArray[i]=array[i];
    }
    
    this->capacity=newCapacity;
    delete [] array;
    array = newArray;
}

//capacity functions
template<class T>
std::size_t DynamicArray<T>::getSize() const{
    return this->size;
}

template<class T>
std::size_t DynamicArray<T>::getCapacity() const{
    return this->capacity;
}

template<class T>
bool DynamicArray<T>::isEmpty() const{
    if (this->size==0){
        return true;
    }else{
        return false;
    }
}

template<class T>
void DynamicArray<T>::shrinkToFit(){
    T* newArray = new T[this->size];
    this->capacity=this->size;
    for (std::size_t i=0; i<this->size; i++) {
        newArray[i]=array[i];
    }
    array= newArray;
}

//element access
template<class T>
T const& DynamicArray<T>::operator[](size_t position) const{
    if (position<this->size) {
        return array[position];
    }else{
        throw std::out_of_range("Error: index out of range");
    }
}

template<class T>
T DynamicArray<T>::front() const{
    return this->array[0];
}

template<class T>
T DynamicArray<T>::back() const{
    return this->array[size-1];
}

//modifiers
template<class T>
void DynamicArray<T>::insert(T item){
    if (size==capacity) {
        this->resize();
    }
    this->array[size]=item;
    size++;
}

template<class T>
void DynamicArray<T>::insert(T item, std::size_t index){
    if (size==capacity) {
        this->resize();
    }
    
    for (std::size_t i=size; i>=index; i--) {
        this->array[i+1]=this->array[i];
    }
    
    this->array[index]=item;
    size++;
}

template<class T>
void DynamicArray<T>::erase(std::size_t index){
    for (std::size_t i=index; i<size; i++) {
        this->array[i]=this->array[i+1];
    }
    size--;
}

template<class T>
void DynamicArray<T>::clear(){
    this->size=0;
}






