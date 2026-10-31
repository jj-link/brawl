#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

extern "C" {
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
}

struct Obj {
    void* vtable;
    unsigned short type;
    char pad[6];
    void* data;
    unsigned int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (raw * 2) & 0x7FFFFFFE, 0x15);
    }
};

extern "C" Obj* fn_802BAB24(Obj* self, int flag) {
    if (self) {
        if (self && self && (unsigned int)self + 0xC &&
            (unsigned int)self + 0xC) {
            if (self->isOwned()) {
                self->dealloc();
            }
        }

        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1D);
        }
    }

    return self;
}
