#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void __dl__FPv(void*);
extern void* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int raw;
    unsigned int rawValue() const { return raw; }
};

struct Object {
    char pad[8];
    Array a;
    Array b;
    Array c;
};

extern "C" Object* fn_80080868(Object* self, int flag) {
    if (self) {
        if ((unsigned int)self + 0x20 != 0 && !(self->c.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->c.data, self->c.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x14 != 0 && !(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 8 != 0 && !(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}