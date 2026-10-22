#include <types.h>
#pragma force_active on

struct gfPadSystem {
    u8 pad0[0x35];
    u8 unk35;
    u8 pad36[0xB14];
    u16 unkB4A;
    u8 padB4C[0xC];
    u16 unkB58;
};

extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

extern "C" void startMotor__11gfPadSystemFiUs(gfPadSystem* self, int arg0, unsigned short arg1) {
    if (((self->unk35 >> 6) & 1) && !(self->unkB4A & (1 << arg0))) {
        if (arg0 < 4) {
            fn_802162A4(arg0, 1);
        } else if (*(int*)((char*)self + (arg0 << 6) + 0x480) != 1) {
            fn_8021A558(arg0 - 4, 1);
        }
        *(u16*)((char*)self + (arg0 << 1) + 0xB58) = arg1;
    }
}
