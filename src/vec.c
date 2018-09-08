#include "vec.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Internal functions
static void vec_realloc(struct vec * self, int size);

//Member functions
static void vec_pushback(struct vec * self, void * elem);
static void vec_popback(struct vec * self, void * elem);
static void vec_reserve(struct vec * self, int size);
static void vec_shrink(struct vec * self);

struct vec vec_new(int elemsize)
{
    struct vec self;
    self._capacity = 1;
    self._size = 0;
    self._elemsize = elemsize;
    self._array = malloc(elemsize);
    //add methods
    self.push_back = vec_pushback;
    self.pop_back = vec_popback;
    self.reserve = vec_reserve;
    self.shrink = vec_shrink;
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
    memcpy((char*)self->_array + self->_elemsize*self->_size,elem,self->_elemsize);
    self->_size++;
}

static void vec_popback(struct vec * self, void * elem)
{
    assert(self->_size > 0);
    self->_size--;
    memcpy(elem,(char*)self->_array + self->_elemsize*self->_size, self->_elemsize);
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