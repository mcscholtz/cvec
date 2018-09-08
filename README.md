[![Build Status](https://travis-ci.org/mcscholtz/cvec.svg?branch=master)](https://travis-ci.org/mcscholtz/cvec)
# A simple Vector Implementation
## Build
```bash
git clone --recurse-submodules https://github.com/mcscholtz/cvec.git
cd cvec
cmake .
make
ctest
```

## Supported opperations
### push_back
Push an element to the back of the vector. Increasing its size by 1 and allocating more memory if required.
### pop_back
Push an element from the back of the vector. Decreases its size by 1. Does not deallocate memory (call shrink)
### push_at
Push an element to the given index. Moves all elements after it up by 1 and allocating more memory if required.
### pop_at
Pop an element at the given index. Moves all elements after it down by 1. Does not deallocate memory (call shrink)
### reserve
Allocates more memory to the vector.
### shrink
Deallocates all extra memory.
### at
Returns the element at the given index. Does not remove it from the vector.
### front
Returns the element at the front. Does not remove it from the vector.
### back
Returns the element at the back. Does not remove it from the vector.
### erase
Erases the element at the given index. Moves all elements after it down by 1. Does not deallocate memory (call shrink) 

For more examples look at the [tests](https://github.com/mcscholtz/cvec/blob/master/tests/)
