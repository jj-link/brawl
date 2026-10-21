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
    char padDC[0x80];
    unsigned char a15c;
    float a160, a164, a168, a16c, a170, a174, a178;
    u32 a17c, a180, a184;
    char a188[0x48];
    unsigned char a1d0, a1d1;
    u32 a1d4;
    int a1d8;
};

extern "C" Obj* fn_54_2C48(Obj*, const char*);
extern "C" void* memset(void*, int, unsigned long);
extern "C" char lbl_54_data_39E8[];
extern "C" const float lbl_54_rodata_198;

extern "C" Obj* fn_54_F078(Obj* p, const char* name) {
    fn_54_2C48(p, name);
    p->vtable = lbl_54_data_39E8;
    p->a15c = 1;
    p->a160 = lbl_54_rodata_198;
    p->a164 = lbl_54_rodata_198;
    p->a168 = lbl_54_rodata_198;
    p->a16c = lbl_54_rodata_198;
    p->a170 = lbl_54_rodata_198;
    p->a174 = lbl_54_rodata_198;
    p->a178 = lbl_54_rodata_198;
    p->a17c = 0;
    p->a180 = 0;
    p->a184 = 0;
    memset(p->a188, 0, 0x48);
    p->a1d0 = 0;
    p->a1d1 = 0;
    p->a1d4 = 0;
    p->a1d8 = -1;

    Anim* a = &p->anim;
    if (!a)
        return p;

    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 0x10;
    return p;
}
