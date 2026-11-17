#include <types.h>
#pragma force_active on

typedef struct Data {
    s32 w[12];
} Data;

typedef struct State {
    u8 pad[0x8BC];
    s32 status;
    u8 flag;
    u8 pad2[2];
    u8 id;
    u8 pad3[0x44];
    s64 time;
    u8 done;
} State;

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern u64 fn_801E1B54(void);
extern void fn_8021DA28(s32, Data);
extern void *fn_8022E1E4(u32);
extern void fn_80239968(void *);
extern s64 fn_803F1470(s64, s64);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, s32, u32);
extern State *lbl_804F6810[];
extern u8 lbl_805A0C7A;

s32 fn_80217018(s32 arg0, Data arg1)
{
    u8 addr[6];
    State *st;
    s32 result;
    s32 flag;
    int enabled;
    State *other;
    void *p;

    st = lbl_804F6810[arg0];
    enabled = OSDisableInterrupts();
    result = st->status;
    OSRestoreInterrupts(enabled);

    if (result == 0) {
        enabled = OSDisableInterrupts();
        flag = st->flag;
        OSRestoreInterrupts(enabled);
        if (flag != 0) {
            result = -2;
        } else {
            fn_8021DA28(arg0, arg1);
        }
    } else if (result != -2 && result == -3) {
        enabled = OSDisableInterrupts();
        st->status = 0;
        OSRestoreInterrupts(enabled);
    }

    if (result == -2) {
        if ((s32)fn_803F1470(fn_801E1B54() - st->time,
                             (u32)(*(u32 *)0x800000F8 >> 2)) > 1 &&
            lbl_805A0C7A != 0) {
            if (st->done == 0) {
                st->time = fn_801E1B54();
                other = lbl_804F6810[arg0];
                enabled = OSDisableInterrupts();
                flag = other->status;
                OSRestoreInterrupts(enabled);
                if (flag != -1) {
                    other = lbl_804F6810[arg0];
                    enabled = OSDisableInterrupts();
                    flag = other->id;
                    OSRestoreInterrupts(enabled);
                    p = fn_8022E1E4(flag);
                    if (p) {
                        memcpy(addr, p, 6);
                    } else {
                        memset(addr, 0, 6);
                    }
                    fn_80239968(addr);
                }
            } else {
                enabled = OSDisableInterrupts();
                st->status = -3;
                OSRestoreInterrupts(enabled);
            }
        }
    }

    return result;
}
