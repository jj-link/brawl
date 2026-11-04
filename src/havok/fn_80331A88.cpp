#pragma force_active on

extern "C" void fn_80331F60(void*, int);

struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void free(void* p, unsigned short type, int size);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* fn_80331A88(void* self, int flag) {
    if (self) {
        fn_80331F60(self, 0);
        if (flag > 0) {
            lbl_805A0EB8->free(self, *(unsigned short*)((char*)self + 4), 0x13);
        }
    }
    return self;
}
