#pragma force_active on

struct Thing {
    char pad[0x40];
    unsigned char f40;
    char pad41;
    char pad42;
    unsigned char f43;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8008AC5C(void*, void*, int);
extern "C" char lbl_8049DEC8[0x100];

extern "C" void* fn_8009A854(void* a, int b) {
    void* ret = 0;
    Thing* p = *(Thing**)&lbl_8049DEC8[0];
    if (p) {
        unsigned char c;
        if (p->f40)
            c = p->f43;
        else
            c = 0;
        if (c && a) {
            void* obj = __nw__FUlQ25Heaps8HeapType(0xC, 0xD);
            if (obj)
                obj = fn_8008AC5C(obj, a, b);
            ret = obj;
        }
    }
    return ret;
}
