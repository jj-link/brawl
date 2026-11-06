#include <types.h>
#pragma force_active on

extern "C" int fn_27_1922CC(void*, unsigned long);

class Kind {
    char pad[0x3c];

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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual s32 getKind();
};

class Obj8 {
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
    virtual void v12();
    virtual void v13();
    virtual float getFloat(u32);
};

class Obj50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual s32 call4(s32, s32, s32, s32);
};

class Work {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual s32 getInt(u32);
    virtual void setInt(s32, u32);
};

struct Inner {
    char pad0[8];
    Obj8* o8;
    char pad1[0x44];
    Obj50* o50;
    char pad2[0x10];
    Work* work;
};

struct Outer {
    char pad0[8];
    Kind* kind;
    char pad1[0xcc];
    Inner* inner;
};

extern "C" void fn_27_3A1BBC(void* unused, Outer* self) {
    s32 val;
    if (self->kind->getKind() == 5) {
        val = (s32)self->inner->o8->getFloat(0x293);
    } else {
        val = (s32)self->inner->o8->getFloat(0x1cf);
    }
    Work* work = self->inner->work;
    s32 prod = val * fn_27_1922CC(self, 0x5dc0);
    u32 base = 0x20000000;
    work->setInt(prod, base + 1);
    s32 r = self->inner->o50->call4(0x1712, 0, 0, 0);
    self->inner->work->setInt(r, base + 4);
    self->inner->work->setInt(1, base + 3);
}
