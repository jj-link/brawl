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

struct Obj {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (raw * 2) & 0x7FFFFFFE, 0x15);
    }
};

extern "C" {
Obj* __dt__14Class_802B4774Fv(Obj* self, int flag) {
    if (self) {
        if (self->isOwned()) {
            self->dealloc();
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, 0xC, 0x15);
        }
    }
    return self;
}
}
