#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_801F69D0(void);
extern int lbl_805A08D8;
s32 fn_801FAA24(void* self, u32 idx, void (*cb)(void), s32 arg);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_801E1790(int* p);

s32 fn_801F6920(s32* self, s32 arg1, s32 arg2) {
    s32 irq;
    u32 total = *(u32*)((char*)self + 0x30) + arg1;

    if (fn_801FAA24(self, total >> 2, fn_801F69D0, arg2) == 0) {
        return -1;
    }
    irq = OSDisableInterrupts();
    for (;;) {
        s32 st = self[3];
        if (st == 0) {
            self = (s32*)0;
            break;
        }
        if (st == -1) {
            self = (s32*)-1;
            break;
        }
        if (st == 10) {
            self = (s32*)-3;
            break;
        }
        fn_801E1790(&lbl_805A08D8);
    }
    OSRestoreInterrupts(irq);
    return (s32)self;
}
