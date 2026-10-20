#pragma force_active on
extern "C" int fn_27_1922CC(void* accesser, unsigned long value);

struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(int frame, unsigned long id);
};

struct Mid {
    char pad[0x64];
    ObjA* obj;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_34E174(void* unused, Outer* p) {
    ObjA* obj = p->mid->obj;
    obj->v7(fn_27_1922CC(p, 0x5dc0) * 30, 0x20000001);
}
}
