#pragma force_active on
extern "C" void __dla__FPv(void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_51_3C30(void*, short);
extern "C" char lbl_51_data_5940[];

struct Obj {
    char pad0[0x3c];
    void* f3c;
    char pad1[0x180 - 0x40];
    void* a180;
    void* a184;
    void* a188;
    void* a18c;
    void* s190;
};

extern "C" {
Obj* fn_51_F910(Obj* self, int flags);
}

Obj* fn_51_F910(Obj* self, int flags) {
    if (self) {
        self->f3c = lbl_51_data_5940;
        if (self->a180 && self->a180) {
            __dla__FPv((char*)self->a180 - 0x10);
        }
        self->a180 = 0;
        if (self->a184 && self->a184) {
            __dla__FPv((char*)self->a184 - 0x10);
        }
        self->a184 = 0;
        if (self->a188 && self->a188) {
            __dla__FPv((char*)self->a188 - 0x10);
        }
        self->a188 = 0;
        if (self->a18c && self->a18c) {
            __dla__FPv((char*)self->a18c - 0x10);
        }
        self->a18c = 0;
        if (self->s190) {
            __dl__FPv(self->s190);
        }
        self->s190 = 0;
        fn_51_3C30(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
