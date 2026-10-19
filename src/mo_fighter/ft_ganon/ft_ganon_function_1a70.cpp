#pragma force_active on
// Destroy constructed array elements in reverse order, then optionally free the header.
typedef unsigned long u32;
struct ArrayHeader {
    char* elements;
    u32 stride;
    u32 capacity;
    void (*destroy)(void*, int);
    u32 count;
};

extern "C" {
extern void __dl__FPv(void*);
extern void fn_109_1ACC(ArrayHeader*, short);
extern ArrayHeader* fn_109_1A70(ArrayHeader*, short);
}

ArrayHeader* fn_109_1A70(ArrayHeader* array, short release) {
    if (array != 0) {
        fn_109_1ACC(array, (short)0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
