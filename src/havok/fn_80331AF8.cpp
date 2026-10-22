#pragma force_active on
extern "C" void fn_8027DC80(void*, int);

struct SoHeapAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void free(void* p, unsigned short type, int size);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* fn_80331AF8(void* self, int flag) {
    if (self) {
        void* sub = (char*)self + 8;
        if (sub) {
            fn_8027DC80(sub, -1);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, *(unsigned short*)((char*)self + 4), 0x13);
        }
    }
    return self;
}
