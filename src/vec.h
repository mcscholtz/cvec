#ifndef __VEC_H
#define __VEC_H

//basically write a dynamic array

struct vec {
    //Adds an item to the next index, increment the index, possible rezie the array
    void (*push_back)(struct vec * self, void * elem);
    //Return the item at the back, decrement the index,remove element from array
    // (possible shrink the array)
    void (*pop_back)(struct vec * self, void * elem);
    //Push an item to the given index, if the index is greater than capacity, 
    // resize to increase capacity
    void (*push_at)(struct vec * self, int index, void * elem);
    //Return the item at the index, if the item is in the middle, we need to 
    // copy the bottom half upwards
    void (*pop_at)(struct vec * self, int index, void * elem);
    //view the element in th back
    void (*back)(struct vec * self, void * elem);
    //view the element at the front
    void (*front)(struct vec * self, void * elem);
    //Get the element at the given index
    void (*at)(struct vec * self, int index, void * elem);
    //delete the element at the given index
    void (*erase)(struct vec * self, int index);
    //Simply allocate more memory   
    void (*reserve)(struct vec * self, int size);
    //release memory till there is no extra memory
    void (*shrink)(struct vec * self);
    int _capacity;
    int _size;
    int _elemsize;
    void * _array;
};

struct vec vec_new(int elemsize);
void vec_delete(struct vec * self);

#endif