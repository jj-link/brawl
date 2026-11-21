#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1(int, void*, void*);
};

struct Self {
    u8 pad0[0xE8];
    u32 unkE8;
    u8 pad1[0x4C];
    Object_vptr_0* unk138;
    u32 unk13C;
    u32 unk140;
    u32 unk144;
    u8 pad2[0x30];
    u32* unk178;
    u32* unk17C;
    u32* unk180;
    u32 unk184;
};

extern "C" {
u32 fn_8018EF78(s32* p);
u32 fn_8018EF24(s32* p, u32 i);
u32 fn_8018F0A4(s32* p);
u32 fn_8018F050(s32* p, u32 i);
u32 fn_8018F1D0(s32* p);
u32 fn_8018F17C(s32* p, u32 i);
void fn_80192784(u32* p, u32 value);
void fn_80192854(u32* p, u32 value);
void fn_80192930(u32* p, u32 value);
s32 fn_801AF6C0(Self* a, Object_vptr_0* b);
}

extern "C" s32 fn_801B3050(Self* arg0, Object_vptr_0* arg1) {
    Self* self = (Self*)arg0;
    u32 sp28, sp24, sp20;
    s32 sp1C, sp18, sp14, sp10, spC, sp8;
    u32 i, n;

    if (arg1 == 0) {
        return 0;
    }

    Object_vptr_0* obj = self->unk138;
    if (arg1 == obj) {
        obj->slot1(0x10003, 0, self);
        self->unk138 = 0;

        if ((self->unk184 & 1) == 0) {
            self->unk144 |= 1;
            return 1;
        }

        if (self->unk178 != 0) {
            sp1C = self->unkE8;
            n = fn_8018EF78(&sp1C);
            for (i = 0; i < n; i++) {
                sp18 = self->unkE8;
                sp28 = fn_8018EF24(&sp18, i);
                if (sp28 != self->unk178[i]) {
                    fn_80192784(&sp28, self->unk178[i]);
                }
            }
        }

        if (self->unk17C != 0) {
            sp14 = self->unkE8;
            n = fn_8018F0A4(&sp14);
            for (i = 0; i < n; i++) {
                sp10 = self->unkE8;
                sp24 = fn_8018F050(&sp10, i);
                if (sp24 != self->unk17C[i]) {
                    fn_80192854(&sp24, self->unk17C[i]);
                }
            }
        }

        if (self->unk180 != 0) {
            spC = self->unkE8;
            n = fn_8018F1D0(&spC);
            for (i = 0; i < n; i++) {
                sp8 = self->unkE8;
                sp20 = fn_8018F17C(&sp8, i);
                if (sp20 != self->unk180[i]) {
                    fn_80192930(&sp20, self->unk180[i]);
                }
            }
        }

        return 1;
    }

    return fn_801AF6C0(arg0, arg1);
}
