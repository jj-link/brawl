#include <types.h>
#pragma force_active on

struct Node {
    u8 pad[0x1d];
    u8 flags;
};

extern "C" void fn_27_A75D0(void* self, u32 flag, u32 val);

struct Class_90D8_base {
    u8 pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual u32 fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual u32 fn_27_7AF98(s32 idx);
};

class Outer {
public:
    virtual void slot0();
    virtual Node* slot1(s32 idx);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(s32 idx, s32 a, s32 b);

    u8 pad[0x2c];
    Outer* m30;
    u8 pad2[0x4];
    Class_90D8* m38;
};

extern "C" void fn_27_A4374(Outer* self, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 == -1) {
        s32 count = self->m30->slot3();
        for (s32 i = 0; i < count; i++) {
            Node* n = self->m30->slot1(i);
            if ((n->flags >> 6) & 1) {
                self->slot12(i, arg2, arg3);
            }
        }
    } else {
        fn_27_A75D0(self->m30->slot1(arg1), arg2, arg3);
        if (arg2 == 0) {
            if (self->m38->fn_27_7AC38() == 1U) {
                if (self->m38->fn_27_7AF98(arg1) == 1U) {
                    self->m38->fn_27_7AB10();
                }
            }
        }
    }
}
