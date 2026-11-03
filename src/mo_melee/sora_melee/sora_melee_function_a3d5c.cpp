#include <types.h>
#pragma force_active on

struct FtOuter {
    u8 pad[0x1D];
    u8 flags;
};

struct Arr {
    virtual void isNull();
    virtual FtOuter* at(s32 i);
    virtual FtOuter* atC(s32 i) const;
    virtual s32 size() const;
};

struct Notify {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void update();
};

struct Other {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void update();
};

class Self {
public:
    virtual void isNull();
    virtual void vA3704();
    virtual void vA3D5C();
    virtual void vA3E88();
    virtual void vA403C();
    virtual void vA40F4();
    virtual void vA42D0();
    virtual void vA38D8();
    virtual void vA39E4();
    virtual void vA3B6C();
    virtual void fn_27_A3F40(bool flag);
    virtual void vA4340();
    virtual void vA4374();
    virtual void vA44A4();
    virtual void vA4530();
    virtual void vA4600();
    virtual void vA4644();
    virtual void vA4688();
    virtual void vA46DC();
    virtual void vA4730();
    virtual void vA4774();
    virtual void vA47BC();
    virtual void vA47C0();
    virtual void vA47F4();
    virtual void vA487C();
    virtual void vA48B0();
    virtual void vA4978();
    virtual void vA4A28();
    virtual void vA6918();
    virtual void vA6908();
    virtual void fn_27_A4DF8(s32 v);
    u8 pad4[0x2C];
    Arr* m_arr;
    Notify* m_notify;
    Other* m_other;
    u8 pad3C[0x0C];
    s32 m_field48;
};

extern "C" void fn_27_A6C74(void* a, s32 b);
extern "C" void fn_27_A6C80(void* a, s32 b);

extern "C" void fn_27_A3D5C(Self* self, s32 arg) {
    s32 count = self->m_arr->size();
    for (s32 i = 0; i < count; i++) {
        if ((self->m_arr->at(i)->flags >> 6) & 1U) {
            fn_27_A6C74(self->m_arr->at(i), arg);
            fn_27_A6C80(self->m_arr->at(i), self->m_field48);
        }
    }
    self->m_notify->update();
    self->m_other->update();
    self->fn_27_A3F40(true);
    self->fn_27_A4DF8(-1);
}
