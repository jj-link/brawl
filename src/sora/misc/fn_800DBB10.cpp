#pragma force_active on

extern "C" {
void* fn_800B03F0(void*, int);
void* fn_80015DB4(void*, int, int, int, unsigned short);
void* fn_80015E34(void*, int, int, int, int*, unsigned short);
}

struct Obj {
    char pad0[4];
    int state;
    char pad8[0x14];
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    void* f40;
    char pad44[4];
    void* f48;
    char pad4c[0x30];
    void* f7c;
    void* f80;
    void* f84;
    char pad88[8];
    void* f90;
    char pad94[4];
    void* f98;
    char pad9c[0x24];
    void* resource;
};

extern "C" void fn_800DBB10(Obj* self) {
    self->f1c = fn_800B03F0(self->resource, 0x1e);
    if (self->state == 0 || self->state == 5 || self->state == 1 ||
        self->state == 4 || self->state == 7 || self->state == 9) {
        self->f20 = fn_800B03F0(self->resource, 0x28);
    } else {
        self->f20 = fn_800B03F0(self->resource, 0x32);
    }
    self->f48 = fn_80015DB4(self->resource, 0, 1, 0x8c, 0xfffe);
    self->f28 = fn_800B03F0(self->resource, 0xa);
    self->f2c = fn_800B03F0(self->resource, 0xb);
    if (self->state == 2 || self->state == 6 || self->state == 9) {
        self->f24 = fn_800B03F0(self->resource, 0x6e);
    }
    if (self->state == 1) {
        self->f34 = fn_800B03F0(self->resource, 0x46);
    }
    if (self->state == 5) {
        self->f38 = fn_800B03F0(self->resource, 0x50);
        self->f7c = fn_80015DB4(self->resource, 0, 1, 0x96, 0xfffe);
        self->f80 = fn_80015DB4(self->resource, 0, 1, 0x82, 0xfffe);
        self->f84 = fn_80015E34(self->resource, 0, 1, 0x14, (int*)((char*)self + 0x88), 0xfffe);
    }
    if (self->state == 7) {
        self->f40 = fn_800B03F0(self->resource, 0x3c);
        self->f98 = fn_80015DB4(self->resource, 0, 1, 0x78, 0xfffe);
    }
    self->f90 = fn_80015DB4(self->resource, 0, 1, 0xa0, 0xfffe);
    self->f3c = fn_800B03F0(self->resource, 0x64);
    self->f30 = fn_800B03F0(self->resource, 0x5a);
}
