#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern unsigned char lbl_80487AE4[];
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

class Elem {
public:
    virtual void vf0(int);
    unsigned short m04;
    short m06;
};

struct Array {
    void* data;
    int count;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    void dealloc16() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 4, 0x15);
    }
};

struct Obj {
    void* vtable;
    unsigned short type;
    char pad06[0x22];
    Array a28;
    Array a34;
    Array a40;
    Array a4c;
};

extern "C" Obj* fn_802DBD68(Obj* self, int arg1) {
    if (self != 0) {
        self->vtable = lbl_80487AE4;
        for (int i = 0; i < self->a4c.count; i++) {
            Elem* e = ((Elem**)self->a4c.data)[i];
            if (e->m04 != 0) {
                if (--e->m06 == 0 && e != 0) {
                    e->vf0(1);
                }
            }
        }
        if ((unsigned int)self + 0x18 != 0) {
            if ((unsigned int)self + 0x4C != 0 && self->a4c.isOwned()) {
                self->a4c.dealloc();
            }
            if ((unsigned int)self + 0x40 != 0 && self->a40.isOwned()) {
                self->a40.dealloc();
            }
            if ((unsigned int)self + 0x34 != 0 && self->a34.isOwned()) {
                self->a34.dealloc();
            }
            if ((unsigned int)self + 0x28 != 0 && self->a28.isOwned()) {
                self->a28.dealloc16();
            }
        }
        if (arg1 > 0) {
            lbl_805A0EB8->free(self, self->type, 0x2A);
        }
    }
    return self;
}
