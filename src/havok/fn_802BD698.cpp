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
};

struct Obj {
    void* vtable;
    unsigned short type;
    char pad[6];
    Array a;
};

extern "C" Obj* fn_802BD698(Obj* self, int flag) {
    if (self) {
        if (self && self && (unsigned int)self + 0xc && (unsigned int)self + 0xc) {
            if (self->a.isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.raw << 3, 0x15);
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1d);
        }
    }
    return self;
}
