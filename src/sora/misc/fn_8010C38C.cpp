#pragma force_active on
typedef unsigned char u8;

class Container {
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
    virtual void call(void* arg);
};

extern Container* lbl_805A033C;

struct Obj {
    unsigned char pad0[0x158];
    void* m158;
    unsigned char pad1[0x361 - 0x15C];
    u8 m361;
};

extern "C" {
void fn_8010C38C(Obj* self) {
    lbl_805A033C->call(self->m158);
    self->m361 = 0;
}
}
