#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void __dt__6gfTaskFv(void*, int);
extern "C" void __dl__FPv(void*);

extern void* lbl_805A0EC8;
extern void* lbl_8049DEC8[3];

struct Array {
    void* data;
    int size;
    unsigned int raw;

    unsigned int rawValue() const {
        return raw;
    }
};

struct Object {
    char pad[0x60];
    Array a;
    Array b;
};

extern "C" Object* fn_8009A1E0(Object* self, int flag) {
    if (self) {
        if ((unsigned int)self + 0x6c != 0 && !(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x60 != 0 && !(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x40 != 0) {
            lbl_8049DEC8[0] = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
