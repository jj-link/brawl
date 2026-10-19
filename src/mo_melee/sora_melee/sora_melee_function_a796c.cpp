#pragma force_active on
typedef unsigned char u8;

struct Pad {
    unsigned char bytes[8];
};

struct Obj : Pad {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();

    unsigned char padC[12];
    u8 flag;
};

extern "C" void fn_27_A796C(Obj* self) {
    self->a5();
    self->flag = 0;
}
