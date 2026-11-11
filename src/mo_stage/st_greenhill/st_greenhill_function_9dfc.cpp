#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

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

struct Vec2f {
    float x;
    float y;
};

struct Pair {
    Vec2f a;
    Vec2f b;
};

struct Sub {
    char pad0[0xc];
    u32 c;
    u32 d10;
    u32 d14;
    u16 d18;
    char pad1a[2];
    float f1c;
    float f20;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x68];
    Sub* aA8;
    char padAC[0x24];
    Anim anim;
    char padDC[0x7C];
    float a158;
    float a15C;
    float a160;
    u32 a164;
    char pad168[4];
    unsigned char a16C;
    char pad16D[3];
    float a170;
    unsigned char a174;
    char pad175[3];
    float a178;
    u32 a17C;
    u32 a180;
    u32 a184;
    u32 a188;
    unsigned char a18C;
    unsigned char a18D;
    char pad18E[2];
    u32 a190;
    u32 a194;
    u32 a198;
    u32 a19C;
    u32 a1A0;
};

extern "C" void fn_72_1130(void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void createSoundWork__9grGimmickFUlUl(void*, unsigned long, unsigned long);
extern "C" char lbl_72_data_2900[];
extern "C" const float lbl_72_rodata_80;

extern "C" void* fn_72_9DFC(void* self) {
    Obj* p = (Obj*)self;
    fn_72_1130(self);
    p->vtable = lbl_72_data_2900;
    __ct__14snd3DGeneratorFv((char*)p + 0x1a4);

    float z = lbl_72_rodata_80;
    p->a164 = 0;
    p->a158 = z;
    p->a15C = z;
    p->a160 = z;
    p->a16C = 3;
    p->a170 = z;
    p->a174 = 1;
    p->a178 = z;
    p->a17C = 0;
    p->a180 = 0;
    p->a184 = 0;
    p->a188 = 0;
    p->a18C = 0;
    p->a18D = 0;
    p->a190 = 0;
    p->a194 = 0;
    p->a198 = 0;
    p->a19C = 0;
    p->a1A0 = 0;

    createSoundWork__9grGimmickFUlUl(self, 1, 1);

    float w = lbl_72_rodata_80;
    p->aA8->c = 0x1D19;
    Pair pr;
    pr.a.x = w;
    p->aA8->d10 = 0;
    pr.a.y = w;
    p->aA8->d18 = 0;
    *(u32*)&pr.b.x = *(u32*)&pr.a.x;
    p->aA8->d14 = 0;
    *(u32*)&pr.b.y = *(u32*)&pr.a.y;
    Sub* s = p->aA8;
    s->f1c = pr.b.x;
    s->f20 = pr.b.y;

    Anim* a = &p->anim;
    if (!a) {
        return self;
    }
    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 1;
    return self;
}
