#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct ArrayHeader {
    void* elements;
    u32 stride;
    u32 capacity;
    void (*destroy)(void*, int);
    u32 count;
};

extern "C" void fn_106_937C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_93DC(ArrayHeader* array, s32 release) {
    if (array != 0) {
        fn_106_937C((char*)array + 8, (short)-1);
        if ((short)release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
