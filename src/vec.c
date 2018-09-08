/* Copyright Marius Scholtz <mc.scholtz@gmail.com> 2018 */
#include "vec.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

//Internal functions
#define VEC_AT(index) ((char*)self->_array + self->_elemsize*(index))
static void vec_realloc(struct vec * self, int size);

//Member functions
static void vec_pushback(struct vec * self, void * elem);
static void vec_popback(struct vec * self, void * elem);
static void vec_reserve(struct vec * self, int size);
static void vec_shrink(struct vec * self);
static void vec_front(struct vec * self, void * elem);
static void vec_back(struct vec * self, void * elem);
static void vec_at(struct vec * self, int index, void * elem);
static void vec_erase(struct vec * self, int index);
static void vec_pop_at(struct vec * self, int index, void * elem);
static void vec_push_at(struct vec * self, int index, void * elem);


struct vec vec_new(int elemsize)
{
    struct vec self;
    self._capacity = 1;
    self._size = 0;
    self._elemsize = elemsize;
    self._array = malloc(elemsize);
    //add methods
    self.push_back = vec_pushback;
    self.push_at = vec_push_at;
    self.pop_back = vec_popback;
    self.pop_at = vec_pop_at;
    self.reserve = vec_reserve;
    self.shrink = vec_shrink;
    self.at = vec_at;
    self.front = vec_front;
    self.back = vec_back;
    self.erase = vec_erase;
    return self;
}

void vec_delete(struct vec * self)
{
    assert(self != NULL);
    assert(self->_array != NULL);
    free(self->_array);
}

static void vec_realloc(struct vec * self, int size)
{
    void * ptr = realloc(self->_array, self->_elemsize*size);
    if(ptr == NULL){
        //manually allocate new block and copy over the old block
        ptr = malloc(self->_elemsize*size);
        assert(ptr != NULL && "Out of memory");
        //copy over existing data
        memcpy(ptr,self->_array,self->_size);
        //free old block
        free(self->_array);
        self->_array = ptr;
    }
    self->_capacity = size;
}

static void vec_pushback(struct vec * self, void * elem)
{
    assert(self != NULL);
    if(self->_capacity == self->_size){
        //realloc
        vec_realloc(self, self->_capacity*2);
    }
    //insert
    memcpy(VEC_AT(self->_size),elem,self->_elemsize);
    self->_size++;
}

static void vec_popback(struct vec * self, void * elem)
{
    assert(self->_size > 0);
    self->_size--;
    memcpy(elem,VEC_AT(self->_size), self->_elemsize);
}

static void vec_reserve(struct vec * self, int size)
{
    assert(self != NULL);
    assert(size > self->_capacity);
    vec_realloc(self, size);
}

static void vec_shrink(struct vec * self)
{
    assert(self != NULL);
    assert(self->_capacity > self->_size);
    assert(self->_size > 0 && "Cannot shrink to size 0");
    void * ptr = realloc(self->_array, self->_size);
    assert(ptr != NULL);
    self->_capacity = self->_size;
}

static void vec_front(struct vec * self, void * elem)
{
    vec_at(self, 0, elem);
}

static void vec_back(struct vec * self, void * elem)
{
    vec_at(self, self->_size-1, elem);
}

static void vec_at(struct vec * self, int index, void * elem)
{
    assert(self != NULL);
    assert(self->_size >= index && "Index out of range");
    memcpy(elem,VEC_AT(index), self->_elemsize);
}

//Delete the element at the given index and shift all other elements up by 1
static void vec_erase(struct vec * self, int index)
{
    assert(self != NULL);
    assert(self->_size >= index && "Index out of range");
    memmove(VEC_AT(index), VEC_AT(index+1), self->_elemsize*(self->_size-index));
    self->_size--;
}

static void vec_pop_at(struct vec * self, int index, void * elem)
{
    vec_at(self, index, elem);
    vec_erase(self, index);
}

//insert an element and move the size of the array up by 1
static void vec_push_at(struct vec * self, int index, void * elem)
{
    assert(self != NULL);
    if(self->_capacity == self->_size){
        vec_realloc(self, self->_capacity*2);
    }
    //move all items up by 1
    self->_size++;
    memmove(VEC_AT(index+1), VEC_AT(index), self->_elemsize*(self->_size-index));
    //copy element to index
    memcpy(VEC_AT(index),elem,self->_elemsize);   
}


