#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Anim {
    void* vtable;
    Flags* data;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Anim anim;
    char padD8[0x8c];
    float a164;
    float a168;
    float a16c;
    u32 a170;
    u32 a174;
    unsigned char a178;
    unsigned char a179;
    char pad17a[2];
    float a17c;
    unsigned char a180;
    char pad181[3];
    float a184;
    float a188;
};

extern "C" Obj* fn_46_44B4(Obj*, const char*);
extern const float lbl_46_rodata_110;
extern unsigned char lbl_46_data_1AE0[];

extern "C" Obj* fn_46_5798(Obj* self, const char* name) {
    fn_46_44B4(self, name);
    self->vtable = lbl_46_data_1AE0;
    self->a164 = lbl_46_rodata_110;
    self->a168 = lbl_46_rodata_110;
    self->a16c = lbl_46_rodata_110;
    self->a170 = 0;
    self->a174 = 0;
    self->a178 = 3;
    self->a179 = 13;
    self->a17c = lbl_46_rodata_110;
    self->a180 = 1;
    self->a184 = lbl_46_rodata_110;
    self->a188 = lbl_46_rodata_110;

    Anim* a = &self->anim;
    if (!a)
        return self;
    a->data->flags |= 0x10;
    return self;
}
