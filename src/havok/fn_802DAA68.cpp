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
    virtual void free(void*, unsigned short, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Array {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    ~Array() {
        if (isOwned())
            dealloc();
    }
};

extern "C" Array* fn_802DAA68(Array* arg1, int arg2) {
    if (arg1) {
        if (arg1) {
            if (arg1->isOwned())
                arg1->dealloc();
        }
        if (arg2 > 0)
            lbl_805A0EB8->free(arg1, 0x8C, 0x15);
    }
    return arg1;
}
