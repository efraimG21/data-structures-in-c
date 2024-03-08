# Data Structures in C

Welcome to the "Data Structures in C" project, a comprehensive collection of essential data structures implemented in C. Explore the world of Vectors, Stacks, and the Abstract Data Type for Errors (ADTErr) to build a solid foundation in data structure concepts.

## Introduction

Understanding data structures is fundamental to efficient algorithm design, playing a pivotal role in writing robust and scalable software. This project serves as a resource for those looking to explore and implement essential data structures in the C programming language.

## Vector

### Overview

The **Vector** is a dynamic array implementation that facilitates dynamic addition, deletion, and retrieval of elements. It provides automatic memory management and resizing capabilities, making it a versatile tool for managing sequences of data.

### Operations and Runtime Complexities

1. **VectorCreate(size_t size, size_t blockSize):**
   - Creates a new vector with an initial size and block size for reallocation.
   - **Time Complexity:** O(1)

2. **VectorAdd(Vector_t* vector, int item):**
   - Adds an item to the end of the vector. Resizes if needed.
   - **Time Complexity:** O(1) amortized

3. **VectorDelete(Vector_t* vector, int* item):**
   - Deletes the last item from the vector. Shrinks if needed.
   - **Time Complexity:** O(1) amortized

4. **VectorPrint(Vector_t* vector):**
   - Prints details and items of the vector.
   - **Time Complexity:** O(n), where n is the number of items.

## Stack

### Overview

The **Stack** is a fundamental data structure built on top of the Vector. It follows the Last In, First Out (LIFO) principle, making it suitable for scenarios where the order of processing matters.

### Operations and Runtime Complexities

1. **StackCreate(size_t size, size_t blockSize):**
   - Creates a new stack with an initial size and block size for reallocation.
   - **Time Complexity:** O(1)

2. **StackPush(Stack_t* stack, int item):**
   - Pushes an item onto the stack using VectorAdd.
   - **Time Complexity:** O(1) amortized

3. **StackPop(Stack_t* stack, int* item):**
   - Pops an item from the stack using VectorDelete.
   - **Time Complexity:** O(1) amortized

4. **StackReverse(Stack_t* stack):**
   - Reverses the order of items in the stack.
   - **Time Complexity:** O(n), where n is the number of items in the stack.

## ADTErr

### Overview

**ADTErr** is an Abstract Data Type for error handling within the data structures. It provides a standardized set of error codes and corresponding descriptions to assist developers in identifying and addressing issues in their code.

### Usage

1. **Include "ADTErr.h" in your project.**
2. Use the provided error codes in your data structure operations.
3. Handle errors using the `HandleErr` function in "ADTErr.c."

### Examples
```c
// Example usage of ADTErr
ADTErr result = performOperation();
HandleErr(result, "Error occurred during the operation");
```

## Contributing

Feel free to contribute to the project by opening issues or pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

This revised README provides a bit more context about why understanding data structures is important, introduces each data structure, and outlines their key operations and runtime complexities. Adjustments can be made based on your project's specific goals and audience.
