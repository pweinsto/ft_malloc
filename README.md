# ft_malloc
## malloc()
Allocates “size” bytes of memory and returns a pointer to the allocated memory.
## realloc()
Tries to change the size of the allocation pointed to by “ptr” to “size”, and returns “ptr”. If there is not enough room to enlarge the memory allocation pointed to by ptr, realloc() creates a new allocation, copies as much of the old data pointed to by “ptr” as will fit to the new allocation, frees the old allocation, and returns a pointer to the allocated memory.
## free()
Deallocates the memory allocation pointed to by “ptr”. If “ptr” is a NULL pointer, no operation is performed.
## show_alloc_mem_ex()
Displays an hexa dump of the allocated zones.
