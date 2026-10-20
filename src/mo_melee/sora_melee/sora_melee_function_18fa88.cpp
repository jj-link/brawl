#pragma force_active on
class Obj {
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
};

struct Mid {
    char pad[0x40];
    Obj* obj;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_18FA88(int unused, Outer* p) {
    p->mid->obj->v15();
}
}
