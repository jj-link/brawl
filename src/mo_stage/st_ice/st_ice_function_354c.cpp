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
    char padDC[0x7c];
    unsigned char a158;
    char pad159[3];
    u32 a15C, a160, a164, a168;
    unsigned char a16C;
    unsigned char a16D;
    char pad16E[2];
    float a170, a174, a178, a17C, a180;
    u32 a184, a188, a18C, a190, a194, a198, a19C, a1A0, a1A4, a1A8, a1AC, a1B0;
    unsigned char a1B4;
    unsigned char a1B5;
    char pad1B6[2];
    u32 a1B8;
    char generator[0x8];
    int a1C4;
    int a1C8;
    unsigned char a1CC;
    char pad1CD[3];
    float a1D0;
};

extern "C" void fn_62_2C84(void*, const char*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" char lbl_62_data_1328[];
extern "C" const float lbl_62_rodata_80;

extern "C" void* fn_62_354C(void* self, const char* name) {
    Obj* p = (Obj*)self;
    fn_62_2C84(p, name);
    p->vtable = lbl_62_data_1328;
    __ct__14snd3DGeneratorFv((char*)p + 0x1BC);

    Anim* a = &p->anim;

    p->a158 = 0;
    p->a15C = 0;
    p->a160 = 0;
    p->a164 = 0;
    p->a168 = 0;
    p->a16C = 0xE;
    p->a16D = 0;
    p->a170 = lbl_62_rodata_80;
    p->a174 = lbl_62_rodata_80;
    p->a178 = lbl_62_rodata_80;
    p->a17C = lbl_62_rodata_80;
    p->a180 = lbl_62_rodata_80;
    p->a184 = 0;
    p->a188 = 0;
    p->a18C = 0;
    p->a190 = 0;
    p->a194 = 0;
    p->a198 = 0;
    p->a19C = 0;
    p->a1A0 = 0;
    p->a1A4 = 0;
    p->a1A8 = 0;
    p->a1AC = 0;
    p->a1B0 = 0;
    p->a1B4 = 0;
    p->a1B5 = 0;
    p->a1B8 = 0;

    if (!a)
        return self;

    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 0x10;

    p->a1C4 = -1;
    p->a1C8 = -1;
    p->a1CC = 0xE;
    p->a1D0 = lbl_62_rodata_80;

    return self;
}
