#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(void*, int, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Obj {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3FFFFFFF) * 0xc, 0x15);
    }
};

extern "C" void* __dt__14Class_8032B848Fv(Obj* arg0, int arg1) {
    if (arg0) {
        if (arg0) {
            if (arg0->isOwned())
                arg0->dealloc();
        }
        if (arg1 > 0)
            lbl_805A0EB8->vf5(arg0, 0x18c, 0x15);
    }
    return arg0;
}
