# Title:
Malloc Test Suite.

# Description:
A framework for runnning memory tests on malloc. We test by running malloc and free on various input sizes.

Aimed as a framework to supplement our manually written memory allocators

# Usage:

```
g++ -fopenmp -o malloc_test malloc_test.cpp
```

Running the above command will create a executable object. We perform around 100000 memory allocation/deallocation requests in this program.

```
./malloc_test
```

Running the above command will perform the required operationn along with displaying the statistics.