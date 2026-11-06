#pragma force_active on
typedef int s32;
typedef unsigned int u32;

s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
s32 fn_801FAD94(void* block, void (*cb)(void));
void fn_801FB1D4(void);
void fn_801E1790(int* p);
extern int lbl_805A08D8;

s32 fn_801FB0F8(void* arg0) {
    s32 irq;
    s32 st;
    u32 t;

    if (fn_801FAD94(arg0, fn_801FB1D4) == 0) {
        return -1;
    }
    irq = OSDisableInterrupts();
    for (;;) {
        st = *(s32*)((char*)arg0 + 0xc);
        if (st == 0 || st == -1 || st == 10) {
            break;
        }
        if (st == 3) {
            t = *(u32*)((char*)arg0 + 8);
            if (t == 4 || t == 5 || t == 0xD || t == 0x21 || t == 0x22 || t == 0x29 || t == 0x2A || t == 0xF || t == 0x25) {
                break;
            }
        }
        fn_801E1790(&lbl_805A08D8);
    }
    OSRestoreInterrupts(irq);
    return 0;
}
