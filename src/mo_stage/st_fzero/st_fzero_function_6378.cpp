#pragma force_active on

typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);

    Flags* data;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Part part;
    char paddc[0x7c];
    u32 a158;
    u32 a15c;
    u32 a160;
    u32 a164;
    u32 a168;
    float a16c;
    float a170;
    float a174;
    u32 a178;
    unsigned char a17c;
    float a180;
};

extern "C" Obj* fn_61_2320(Obj*, const char*);
extern const float lbl_61_rodata_F8;
extern char lbl_61_data_1BD0[];

extern "C" Obj* fn_61_6378(Obj* self, const char* name) {
    fn_61_2320(self, name);
    self->vtable = lbl_61_data_1BD0;
    self->a158 = 0;
    self->a160 = 0;
    self->a164 = 0;
    self->a168 = 0;
    self->a16c = lbl_61_rodata_F8;
    self->a170 = lbl_61_rodata_F8;
    self->a174 = lbl_61_rodata_F8;
    self->a178 = 0;
    self->a17c = 2;
    self->a180 = lbl_61_rodata_F8;

    Part* p = &self->part;
    if (!p)
        return self;

    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 8;
    return self;
}
