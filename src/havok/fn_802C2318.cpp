#pragma force_active on

typedef unsigned int u32;

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
    void* vtable;
    unsigned short type;
    char pad[6];
    void* data;
    char pad2[4];
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 3, 0x15);
    }
};

extern "C" void* fn_802C2318(Obj* self, int flag) {
    if (self) {
        if ((u32)self && (u32)self && (u32)self + 0xc && (u32)self + 0xc && self->isOwned()) {
            self->dealloc();
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1d);
        }
    }
    return self;
}
