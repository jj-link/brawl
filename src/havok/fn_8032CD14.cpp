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
    int pad4;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }
};

extern "C" Obj* fn_8032CD14(Obj* arg0, int arg1) {
    if (arg0) {
        if (arg0 && arg0->isOwned())
            fn_8027EABC(lbl_805A0EC8, arg0->data, (arg0->raw & 0x3FFFFFFF) * 0x90, 0x15);
        if (arg1 > 0)
            lbl_805A0EB8->vf5(arg0, 0x1C0, 0x15);
    }
    return arg0;
}
