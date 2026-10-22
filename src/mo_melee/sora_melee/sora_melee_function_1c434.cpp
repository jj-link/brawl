#include <types.h>
#pragma force_active on

struct Pad8 {
    s32 x;
    s32 y;
};

class VObj : public Pad8 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void*);
};

struct CounterObj {
    char pad[0x0c];
    s32 m_count;
};

struct InnerObj {
    char pad[0x64];
    CounterObj* m_counter;
    char pad2[0xb8 - 0x68];
    VObj* m_v;
};

struct MidObj {
    char pad[0xd8];
    InnerObj* m_inner;
};

struct OuterObj {
    char pad[0x164];
    u8 m_flag;
    char pad2[3];
    MidObj* m_mid;
};

struct Arg1 {
    s32 m_a;
    f32 m_f1;
    f32 m_f2;
    u8 m_b;
    u8 m_c;
    u8 m_d;
    u8 m_e;
};

extern "C" {
    void fn_27_157DC(OuterObj*, u32, f32, f32, u8, u8, u8, u8);

    void fn_27_1C434(OuterObj* self, Arg1* arg1) {
        self->m_mid->m_inner->m_counter->m_count++;
        self->m_flag |= 8;
        self->m_mid->m_inner->m_v->v7(self->m_mid);
        f32 t2 = arg1->m_f2;
        f32 t1 = arg1->m_f1;
        fn_27_157DC(self, arg1->m_a, t1, t2, arg1->m_b, arg1->m_c, arg1->m_d, arg1->m_e);
        CounterObj* c = self->m_mid->m_inner->m_counter;
        if (c->m_count > 0) {
            c->m_count = c->m_count - 1;
        }
    }
}
