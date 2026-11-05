#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802E3ECC(void*);
extern "C" void fn_802E56A8(void*, int);
extern char lbl_80487E08[];
extern char lbl_804885E8[];
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

class Ref {
public:
    virtual void destroy(int);
    unsigned short active;
    short count;
};

struct Arr {
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
    char pad6[0x16];
    Ref* ref1c;
    char pad20[0x20];
    Arr a40;
    Arr a4c;
    char pad58[0x10];
    Ref* ref68;
    Arr a6c;
    Arr a78;
    Arr a84;
    char pad90[0x124];
    Arr a1b4;
    Arr a1c0;
    Arr a1cc;
    Arr a1d8;
};

extern "C" Obj* fn_802E1558(Obj* self, int flag) {
    if (self) {
        self->vtable = lbl_80487E08;
        fn_802E3ECC(self);

        Ref* ref = self->ref68;
        if (ref) {
            if (ref->active != 0) {
                ref->count -= 1;
                if (ref->count == 0) {
                    if (ref != 0) ref->destroy(1);
                }
            }
        }
        if ((unsigned int)self + 0x1d8) {
            if (self->a1d8.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a1d8.data, self->a1d8.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0x1cc) {
            if (self->a1cc.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a1cc.data, self->a1cc.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0x1c0) {
            if (self->a1c0.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a1c0.data, self->a1c0.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0x1b4) {
            if (self->a1b4.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a1b4.data, self->a1b4.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0xa0) {
            fn_802E56A8((char*)self + 0xa0, 0);
        }
        if ((unsigned int)self + 0x84) {
            if (self->a84.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a84.data, self->a84.raw & 0x3FFFFFFF, 0x15);
        }
        if ((unsigned int)self + 0x78) {
            if (self->a78.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a78.data, self->a78.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0x6c) {
            if (self->a6c.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a6c.data, (self->a6c.raw & 0x3FFFFFFF) * 0x24, 0x15);
        }
        if (self) {
            Ref* ref2 = self->ref1c;
            self->vtable = lbl_804885E8;
            if (ref2) {
                if (ref2->active != 0) {
                    ref2->count -= 1;
                    if (ref2->count == 0) {
                        if (ref2 != 0) ref2->destroy(1);
                    }
                }
            }
            if ((unsigned int)self + 0x4c) {
                if (self->a4c.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a4c.data, self->a4c.raw << 4, 0x15);
            }
            if ((unsigned int)self + 0x1c) {
                if ((unsigned int)self + 0x40 && self->a40.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a40.data, self->a40.raw << 3, 0x15);
            }
        }
        if (flag > 0) lbl_805A0EB8->free(self, self->type, 0x2B);
    }
    return self;
}
