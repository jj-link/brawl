#pragma force_active on
extern "C" {
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_67_20BC(void*, int);
extern char lbl_67_data_2A20[];
}

struct Palutena {
    char pad0[0x3C];
    void* f3c;
    char pad40[0x15C - 0x40];
    void* f15c;
    void* f160;
    char pad164[4];
    void* f168;
};

extern "C" Palutena* fn_67_B448(Palutena* self, int flags) {
    if (self) {
        self->f3c = lbl_67_data_2A20;
        if (self->f15c && self->f15c)
            __dla__FPv((char*)self->f15c - 0x10);
        self->f15c = 0;
        if (self->f160)
            __dla__FPv(self->f160);
        self->f160 = 0;
        if (self->f168)
            __dla__FPv(self->f168);
        self->f168 = 0;
        fn_67_20BC(self, 0);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
