#pragma force_active on

struct S {
    void* f0;
    unsigned short f4;
};

struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void release(void* p, unsigned int size, int heap);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* fn_802BD8D8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        S* s = (S*)arg0;
        lbl_805A0EB8->release(arg0, s->f4, 0x1d);
    }
    return arg0;
}
