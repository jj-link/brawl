#pragma force_active on
struct Vec {
    void** data;
    int size;
    unsigned int capacity;
    void push(void* value);
};

struct Manager {
    unsigned char pad[0x40];
    unsigned char active;
    unsigned char pad41[2];
    unsigned char enabled;
    unsigned char pad44[0x1C];
    Vec objects;
};

extern "C" Manager* lbl_8049DEC8[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8008AE90(void*, void*, int, int);
extern "C" void fn_8027CE3C(Vec*, int);

inline void Vec::push(void* value) {
    if (size == (int)(capacity & 0x3FFFFFFF))
        fn_8027CE3C(this, 4);
    data[size++] = value;
}

extern "C" void* fn_8009A75C(void* arg0, int arg1, int arg2) {
    void* result = 0;
    if (lbl_8049DEC8[0]) {
        unsigned char enabled = lbl_8049DEC8[0]->active ? lbl_8049DEC8[0]->enabled : 0;
        if (enabled && arg0) {
            void* object = __nw__FUlQ25Heaps8HeapType(0xF4, 0xD);
            if (object)
                object = fn_8008AE90(object, arg0, arg1, arg2);
            result = object;
            lbl_8049DEC8[0]->objects.push(result);
        }
    }
    return result;
}
