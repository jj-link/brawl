#include <types.h>
#pragma force_active on

#define DUMMY(n) virtual void v##n()

struct A {
    DUMMY(0);
    virtual s32 getSize();
};

struct NonPoly {
    void* unk0;
    u32 unk4;
};

struct C {
    DUMMY(0); DUMMY(1); DUMMY(2); DUMMY(3); DUMMY(4); DUMMY(5); DUMMY(6); DUMMY(7);
    DUMMY(8); DUMMY(9); DUMMY(10); DUMMY(11); DUMMY(12); DUMMY(13); DUMMY(14); DUMMY(15);
    DUMMY(16); DUMMY(17); DUMMY(18); DUMMY(19);
    virtual void setup(void* a, s32 b, void* out);
};

struct Poly : NonPoly {
    DUMMY(0); DUMMY(1); DUMMY(2); DUMMY(3); DUMMY(4); DUMMY(5); DUMMY(6); DUMMY(7);
    DUMMY(8); DUMMY(9); DUMMY(10); DUMMY(11); DUMMY(12); DUMMY(13); DUMMY(14); DUMMY(15);
    DUMMY(16); DUMMY(17); DUMMY(18); DUMMY(19); DUMMY(20); DUMMY(21); DUMMY(22); DUMMY(23);
    DUMMY(24); DUMMY(25); DUMMY(26); DUMMY(27); DUMMY(28); DUMMY(29); DUMMY(30); DUMMY(31);
    DUMMY(32); DUMMY(33); DUMMY(34); DUMMY(35); DUMMY(36); DUMMY(37); DUMMY(38);
    virtual void* getController();
};

struct Arg : Poly {
    char pad[0x30];
    void* unk3C;
    A* unk40;
};

struct Out {
    u8 pad[0x45];
    u8 flag;
};

extern "C" void fn_27_5EBE0(Arg* arg) {
    Out out;
    s32 val = arg->unk40->getSize();
    C* c = static_cast<C*>(arg->getController());
    c->setup(arg->unk3C, val, &out);
    out.flag &= ~0x20;
}
