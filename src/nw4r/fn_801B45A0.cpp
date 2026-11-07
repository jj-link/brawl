#include <types.h>
#pragma force_active on

struct Self;
class Dc_obj;
class E8_obj;
class D4_obj;
class Arg3_obj;

extern u8 lbl_8046648C[0x2C];
extern "C" void fn_801ABA14(void*, u32, s32, void*);

class Dc_obj {
public:
    virtual void s0();
    virtual void s1(u32, s32, void*);
};

class E8_obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(void*, void*);
    virtual void s6(void*);
    virtual void s7(void*);
};

class D4_obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4(s32, Self*, s32, void*);
    virtual void s5(s32, Self*, s32, void*);
};

struct Sub {
    void* a;
    void* b;
};

class Arg3_obj {
public:
    virtual void s0();
    virtual void s1(Self*, u32, u32);
    Sub* unk4;
};

struct Self {
    u8 pad0[0xcc];
    u32 mask;
    u8 pad1[0xd4 - 0xd0];
    D4_obj* d4;
    u8 b_d8;
    u8 pad2;
    u16 hw_da;
    Dc_obj** dc;
    u8 pad3[0xe4 - 0xe0];
    u32 count;
    E8_obj* e8;
};

struct Local {
    void* a;
    void* b;
    void* c;
};

extern "C" void fn_801B45A0(Self* self, u32 arg1, s32 arg2, Arg3_obj* arg3) {
    s32 masked;
    if (arg1 < 9U && ((1U << (arg1 - 1)) & self->mask)) {
        masked = 1;
    } else {
        masked = 0;
    }
    if (masked != 0) {
        return;
    }

    switch ((s32)arg1) {
    case 0x5: {
        Local local;
        u32 mask = self->mask;
        arg3->s1(self, !(mask & 0x20000000), !(mask & 0x40000000));
        self->e8->s2();
        E8_obj* e8 = self->e8;
        u32 off;
        u32 i;
        i = 0;
        local.a = lbl_8046648C;
        off = 0;
        local.b = arg3;
        local.c = e8;
        while (i < self->count) {
            Dc_obj* o = *(Dc_obj**)((u8*)self->dc + off);
            o->s1(arg1, arg2, &local);
            off += 4;
            i++;
        }
        break;
    }
    case 0x10004:
        switch (arg2) {
        case 0:
            self->e8->s3();
            break;
        case 1:
            self->e8->s4();
            break;
        case 2: {
            Sub* sub = arg3->unk4;
            self->e8->s5(sub->a, sub->b);
            break;
        }
        }
        fn_801ABA14(self, arg1, arg2, arg3);
        break;
    case 0x6: {
        D4_obj* d4 = self->d4;
        if (d4 != 0 && (self->hw_da & 0x10) && (self->b_d8 & 1)) {
            d4->s4(1, self, arg2, arg3);
        }
        self->e8->s6(arg3);
        d4 = self->d4;
        if (d4 != 0 && (self->hw_da & 0x10) && (self->b_d8 & 4)) {
            d4->s4(4, self, arg2, arg3);
        }
        break;
    }
    case 0x7: {
        D4_obj* d4 = self->d4;
        if (d4 != 0 && (self->hw_da & 0x20) && (self->b_d8 & 1)) {
            d4->s5(1, self, arg2, arg3);
        }
        self->e8->s7(arg3);
        d4 = self->d4;
        if (d4 != 0 && (self->hw_da & 0x20) && (self->b_d8 & 4)) {
            d4->s5(4, self, arg2, arg3);
        }
        break;
    }
    default:
        fn_801ABA14(self, arg1, arg2, arg3);
        break;
    }
}
