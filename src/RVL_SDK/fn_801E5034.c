#include <types.h>
#include <revolution/EXI/EXIBios.h>
#include <revolution/EXI/EXIHardware.h>
#include <revolution/OS/OSContext.h>

#pragma force_active on
#pragma optimization_level 4
#pragma scheduling off

extern EXIData lbl_804DE270[3];
extern void fn_801D7FCC(void *);
extern void fn_801D81F4(void *);
extern void fn_801DD2A0(u32);

void fn_801E5034(s32 arg0, OSContext *arg1) {
    OSContext sp8;
    EXIData *e;
    s32 idx;
    EXICallback cb;
    u32 top;
    u32 base;
    u32 *regs;

    idx = (arg0 - 10) / 3;
    e = &lbl_804DE270[idx];
    top = 0x80000000U;
    fn_801DD2A0(top >> arg0);

    EXI_CHAN_PARAMS[idx].cpr = (EXI_CHAN_PARAMS[idx].cpr & 0x7F5) | 8;

    cb = e->tcCallback;
    if (cb != 0) {
        e->tcCallback = 0;
        if (e->state & 3) {
            if (e->state & 2) {
                s32 k;
                u8 *p;
                s32 count = e->bytesRead;
                if (count != 0) {
                    u32 data;
                    s32 n;
                    s32 ctr;

                    p = (u8 *)e->buffer;
                    data = EXI_CHAN_PARAMS[idx].data;
                    k = 0;
                    for (k = 0; k < count; k++) {
                        *p++ = (u8)(data >> ((3 - k) * 8));
                    }
                }
            }
            e->state &= ~3U;
        }

        fn_801D81F4(&sp8);
        fn_801D7FCC(&sp8);
        cb(idx, arg1);
        fn_801D81F4(&sp8);
        fn_801D7FCC(arg1);
    }
}
