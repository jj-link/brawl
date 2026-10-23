// Destroy constructed array elements in reverse order, then optionally free the header.
typedef unsigned long u32;
struct ArrayHeader {
    char* elements;
    u32 stride;
    u32 capacity;
    void (*destroy)(void*, int);
    u32 count;
};
extern void __dl__FPv(void*);

struct ArrayHeader* __dt__14Class_803F0B20Fv(struct ArrayHeader* array, int release) {
    if (array != 0) {
        if (array->count < array->capacity && array->destroy != 0) {
            char* cursor = array->elements + array->stride * array->count;
            while (array->count != 0) {
                cursor -= array->stride;
                array->destroy(cursor, -1);
                array->count -= 1;
            }
        }
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
