#include <types.h>
#pragma force_active on

extern "C" {
s32 OSDisableInterrupts();
void OSRestoreInterrupts(s32);
void* fn_801B77F8();
void fn_801CEB08(void*);
void fn_801CEEF8(void*);
void fn_801D1210(void*, u8);
u32 fn_801D17DC(void*);

void fn_801CE96C(void* self_) {
    u8* self = (u8*)self_;
    u8 flag;
    s32 irq;
    if (self[0xba] != 0 && *(void**)(self + 0x7c0) != 0) {
        if (((u8*)fn_801B77F8())[0x1a] != 0) {
            self[0xc1] = 1;
            irq = OSDisableInterrupts();
            flag = 0;
            if (self[0xbf] != 0) {
                flag = 1;
            }
            if (self[0xc1] != 0) {
                flag = 1;
            }
            if (flag != self[0xc0]) {
                if (*(void**)(self + 0x7c0) != 0) {
                    fn_801D1210(*(void**)(self + 0x7c0), flag);
                }
                self[0xc0] = flag;
            }
            OSRestoreInterrupts(irq);
        }
        if (self[0xc5] == 0 && self[0xc2] == 0 && self[0xc1] == 0) {
            u32 t = fn_801D17DC(*(void**)(self + 0x7c0)) / *(u32*)(self + 0xa0);
            while (*(s32*)(self + 0xf0) != (s32)t) {
                if (self[0xc1] == 0 && *(u32*)(self + 0x128) >= (u32)(*(s32*)(self + 0xdc) - 2)) {
                    self[0xbe] = 1;
                    self[0xc1] = 1;
                    irq = OSDisableInterrupts();
                    flag = 0;
                    if (self[0xbf] != 0) {
                        flag = 1;
                    }
                    if (self[0xc1] != 0) {
                        flag = 1;
                    }
                    if (flag != self[0xc0]) {
                        if (*(void**)(self + 0x7c0) != 0) {
                            fn_801D1210(*(void**)(self + 0x7c0), flag);
                        }
                        self[0xc0] = flag;
                    }
                    OSRestoreInterrupts(irq);
                    return;
                }
                fn_801CEB08(self);
                fn_801CEEF8(self);
            }
        }
    }
}
}
