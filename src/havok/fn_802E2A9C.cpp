#pragma force_active on

extern "C" void fn_802E1558(void*, int);

struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void free(void* p, unsigned short type, int size);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* fn_802E2A9C(void* p, int n) {
    if (p) {
        fn_802E1558(p, 0);
        if (n > 0) {
            lbl_805A0EB8->free(p, *(unsigned short*)((char*)p + 4), 0x2b);
        }
    }
    return p;
}