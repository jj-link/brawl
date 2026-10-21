#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class Obj2AAC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(u32 arg);
};

class Obj3A68 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int a, int b, int c);
};

class Obj3AB4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Outer {
    char pad0[0x2AAC];
    Obj2AAC a;
    char pad1[0x3A68 - 0x2AB0];
    Obj3A68 b;
    char pad2[0x3AB4 - 0x3A6C];
    Obj3AB4 c;
    char pad3[0x3C68 - 0x3AB8];
    u8 flag;
};

extern "C" void fn_27_289040(Outer* self, int arg1) {
    if (self->c.v3() > 2) {
        self->flag = (u8)arg1;
        if ((u8)arg1 != 0 && self->a.v4(0x1000000A) > 0) {
            self->b.v12(2, 0, -1);
            return;
        }
        self->b.v12(2, self->flag, -1);
    }
}
