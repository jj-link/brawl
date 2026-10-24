#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct AnimBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);
};

struct Anim : AnimBase {
    Flags* data;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Anim anim;
    char padDC[0x7C];
    unsigned char a158;
    char pad159[3];
    float a15C;
    float a160;
    float a164;
    float a168;
    unsigned char a16C;
    unsigned char a16D;
    unsigned char a16E;
    char pad16F;
    float a170;
    unsigned char a174;
    unsigned char a175;
    unsigned char a176;
    char pad177;
    u32 a178;
    u32 a17C;
    u32 a180;
    u32 a184;
    unsigned char a188;
    unsigned char a189;
    char pad18A[2];
    u32 a18C;
    u32 a190;
    u32 a194;
    u32 a198;
    u32 a19C;
    char pad1A0[8];
    u32 a1A8;
    unsigned char a1AC;
    unsigned char a1AD;
    char pad1AE[2];
    u32 a1B0;
    float a1B4;
    float a1B8;
    float a1BC;
};

extern "C" void* fn_68_2398(void* self, const char* name);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" const float lbl_68_rodata_D0;
extern "C" char lbl_68_data_2198[];

extern "C" void* fn_68_A004(void* self, const char* name) {
    Obj* p = (Obj*)self;
    fn_68_2398(self, name);
    p->vtable = lbl_68_data_2198;
    __ct__14snd3DGeneratorFv((char*)p + 0x1a0);

    Anim* a = &p->anim;

    p->a158 = 0;
    p->a15C = lbl_68_rodata_D0;
    p->a160 = lbl_68_rodata_D0;
    p->a164 = lbl_68_rodata_D0;
    p->a168 = lbl_68_rodata_D0;
    p->a16C = 0;
    p->a16D = 1;
    p->a16E = 0;
    p->a170 = lbl_68_rodata_D0;
    p->a174 = 1;
    p->a175 = 0;
    p->a176 = 0;
    p->a178 = 0;
    p->a17C = 0;
    p->a180 = 0;
    p->a184 = 0;
    p->a188 = 0;
    p->a189 = 0;
    p->a18C = 0;
    p->a190 = 0;
    p->a194 = 0;
    p->a198 = 0;
    p->a19C = 0;

    if (!a)
        return self;

    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 1;
    a->data->flags |= 2;
    a->data->flags |= 4;

    p->a1A8 = 0;
    p->a1AC = 0;
    p->a1AD = 0;
    p->a1B0 = -1;
    p->a1B4 = lbl_68_rodata_D0;
    p->a1B8 = lbl_68_rodata_D0;
    p->a1BC = lbl_68_rodata_D0;

    return self;
}
