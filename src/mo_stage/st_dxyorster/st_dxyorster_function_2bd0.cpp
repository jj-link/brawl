#pragma force_active on
extern "C" void __dl__FPv(void*);

// Contiguous-array header allocated by the Array construct helper:
// payload pointer, element stride, capacity, element destructor, live count.
struct ArrayHeader {
    char* elements;
    unsigned long stride;
    unsigned long capacity;
    void (*destroy)(void*, int);
    unsigned long count;
};

// Destructor helper for contiguous arrays: hand back the array pointer and,
// when the caller asks for it (release > 0), release the block that was
// obtained for the array itself.
extern "C" ArrayHeader* fn_76_2BD0(ArrayHeader* array, int release) {
    if (array != 0) {
        if (release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
