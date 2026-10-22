#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802E8C04(void*, int);
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
        fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3FFFFFFF) * 4, 0x15);
    }
};

struct Object {
    void* vtable;
    unsigned short type;
    char pad06[0x8A];
    Array arr;
};

extern "C" Object* fn_802E7A60(Object* self, int flag) {
    if (self) {
        if ((unsigned)self + 0x90 != 0 && self->arr.isOwned()) {
            self->arr.dealloc();
        }
        fn_802E8C04(self, 0);
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x2F);
        }
    }
    return self;
}
