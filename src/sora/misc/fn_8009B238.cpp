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
    unsigned char pad41[3];
    unsigned char enabled;
    unsigned char pad45[0x27];
    Vec objects;
};
extern "C" Manager* lbl_8049DEC8[];
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800966EC(void*, void*);
extern "C" void fn_8027CE3C(Vec*, int);
inline void Vec::push(void* value) {
    if (size == (int)(capacity & 0x3FFFFFFF))
        fn_8027CE3C(this, 4);
    data[size++] = value;
}
extern "C" void* fn_8009B238(void* arg) {
    if (lbl_8049DEC8[0]) {
        unsigned char enabled = lbl_8049DEC8[0]->active ? lbl_8049DEC8[0]->enabled : 0;
        if (enabled && lbl_8049DEC8[0] && arg) {
            void* obj = __nw__FUlQ25Heaps8HeapType(0x20, 0xD);
            if (obj)
                obj = fn_800966EC(obj, arg);
            if (obj) {
                lbl_8049DEC8[0]->objects.push(obj);
                return obj;
            }
        }
    }
    return 0;
}