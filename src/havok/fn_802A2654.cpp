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

class Class_802A2654 {
public:
    inline void operator delete(void* p) {
        lbl_805A0EB8->release(p, 8, 0x1d);
    }
    ~Class_802A2654();
};

Class_802A2654::~Class_802A2654() {
}
