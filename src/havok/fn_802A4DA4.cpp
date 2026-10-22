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
};

extern "C" void* dtor_802A4DA4(void* arg0, int arg1) {
    Array* self = (Array*)arg0;
    if (arg0 != 0) {
        if (arg0 != 0 && self->isOwned()) {
            self->dealloc();
        }
        if (arg1 > 0) {
            lbl_805A0EB8->vf5(arg0, 0x20C, 0x15);
        }
    }
    return arg0;
}
