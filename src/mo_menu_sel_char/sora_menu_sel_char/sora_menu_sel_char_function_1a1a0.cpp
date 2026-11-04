#include <types.h>
#pragma force_active on
extern "C" const u8 lbl_10_rodata_80C[];
extern "C" const f32 lbl_10_rodata_7D0;

class muSelCharPlayerArea {
public:
    bool isTeamBattle();
    char pad0[0x1B0];
    s32 m1B0;
    char pad1B4[0xC];
    s32 m1C0;
    f32 teamVal() const { return lbl_10_rodata_80C[m1C0]; }
    f32 normVal() const { return lbl_10_rodata_7D0 + m1B0; }
};
class IfaceObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(f32 v);
};
class Self {
public:
    char pad0[0x4C];
    IfaceObj* m4C;
    char pad1[0x9C - 0x50];
    muSelCharPlayerArea* m9C;
};
extern "C" void fn_10_1A1A0(Self* self) {
    f32 v;
    if (self->m9C->isTeamBattle()) {
        v = self->m9C->teamVal();
    } else {
        v = self->m9C->normVal();
    }
    self->m4C->s5(v);
}
