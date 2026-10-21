#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class Obj {
public:
    u8 pad0[0x0c];
    u32 hi : 8;
    u32 lo : 24;
    u8 pad1[0x38];

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

extern "C" void fn_8005A99C(Obj* self) {
    self->hi = 3;
    self->v5();
}
