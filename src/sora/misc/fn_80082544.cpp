#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* fn_80116F0C(char*, int);
extern "C" void __dl__FPv(void*);
extern void* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int raw;
    unsigned int rawValue() const { return raw; }
};
struct Child {
    char pad[0x1a];
    unsigned short value;
};
struct Object {
    Array a;
    int unkC;
    Child* child;
    char pad[0xc];
    Array b;
    Array c;
};
extern "C" Object* fn_80082544(Object* self, int flag) {
    if (self) {
        self->child->value = 0;
        if (self->child) {
            fn_80116F0C((char*)self->child, 1);
            self->child = 0;
        }
        if (!(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, (self->a.rawValue() & 0x3fffffff) * 12, 0x15);
        }
        self->a.data = 0;
        self->a.size = 0;
        self->a.raw = (self->a.raw & 0x40000000) | 0x80000000;
        if (!(self->c.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->c.data, self->c.rawValue() << 2, 0x15);
        }
        self->c.data = 0;
        self->c.size = 0;
        self->c.raw = (self->c.raw & 0x40000000) | 0x80000000;
        if (!(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        self->b.data = 0;
        self->b.size = 0;
        self->b.raw = (self->b.raw & 0x40000000) | 0x80000000;
        if ((unsigned int)self + 0x2c != 0 && !(self->c.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->c.data, self->c.rawValue() << 2, 0x15);
        }
        if ((unsigned int)self + 0x20 != 0 && !(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 2, 0x15);
        }
        if (self != 0 && !(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, (self->a.rawValue() & 0x3fffffff) * 12, 0x15);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
