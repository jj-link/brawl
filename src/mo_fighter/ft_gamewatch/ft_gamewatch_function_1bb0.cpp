#pragma force_active on
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
extern void fn_107_1C0C(void*, short);
}

extern "C" void* fn_107_1BB0(void* array, short release) {
    if (array != 0) {
        fn_107_1C0C(array, 0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
