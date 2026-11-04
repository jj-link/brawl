#pragma force_active on

class SoHeapAllocator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void release(void* p, unsigned int size, int heap);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" void* __dt__14Class_802A38DCFv(void* p, int flag) {
    if (p && flag > 0) {
        lbl_805A0EB8->release(p, 8, 0x1d);
    }
    return p;
}