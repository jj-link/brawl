#pragma force_active on
typedef unsigned long u32;

struct ArrayHeader {
    void* elements;
    u32 stride;
    u32 capacity;
    void (*destroy)(void*, int);
    u32 count;
};

extern "C" {
extern void __dl__FPv(void*);
ArrayHeader* fn_27_C944C(ArrayHeader* array, int release);
}

ArrayHeader* fn_27_C944C(ArrayHeader* array, int release) {
    if (array != 0 && release > 0) {
        __dl__FPv(array);
    }
    return array;
}
