#pragma force_active on
extern "C" {
struct ArrayHeader {
    void* elements;
    unsigned stride;
    unsigned capacity;
    void (*destroy)(void*, int);
    unsigned count;
};

extern void fn_109_1ACC(ArrayHeader*, short);
extern void __dl__FPv(void*);

ArrayHeader* fn_109_1CFC(ArrayHeader* array, short release) {
    if (array != 0) {
        fn_109_1ACC(array, (short)0);
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
}
