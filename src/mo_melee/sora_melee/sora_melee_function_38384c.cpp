#pragma force_active on
typedef unsigned int u32;

struct SubA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct SubB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32 a, void* b);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
};

struct SubC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(u32 a, void* b);
    virtual void v5(u32 a, u32 b);
};

struct Mid {
    char pad0[0x14];
    SubA* s1;
    char pad1[0x64 - 0x18];
    SubC* s3;
    char pad2[0x70 - 0x68];
    SubB* s2;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Top {
    char pad[0x60];
    Obj* obj;
};

extern "C" {
void fn_27_38384C(Top* self) {
    Obj* o = self->obj;
    if (o->mid->s1->v3() != 5) {
        if (o->mid->s2->v16() == 0x119) {
            if (o->mid->s3->v4(0x10000042, o->mid) == 0) {
                o->mid->s3->v5(0x1EA, 0x20000000);
                o->mid->s2->v3(0x122, o);
            }
        }
    }
}
}
