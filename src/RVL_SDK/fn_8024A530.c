#pragma force_active on
#include <types.h>
extern u8 lbl_8052CDC0[];
extern u8 lbl_80482878[];
extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, s32);
extern void fn_80231A74(s32, void *, s32, s32, s32, s32, s32, s32);
extern u8 fn_8023A5A4(void);
extern void fn_8024AED0(void *, s32, void *);
extern s32 fn_8024E568(u8 *);
extern s32 fn_8024E73C(u8 *);
extern s32 fn_8024F968(s32);
extern s32 fn_8024FCD0(s32);
extern u8 fn_802500CC(void);
u16 fn_8024A530(s32 arg0, u8 *arg1)
{
    u8 *base = lbl_80482878;
    s32 r29 = arg0;
    s32 r30;
    void *p;
    if (lbl_8052CDC0[0] >= 3) fn_802319FC(0x80002, base + 0x110, r29);
    if (lbl_8052CDC0[0] >= 3) fn_80231A74(0x80002, base + 0x130, (s32)arg1[0], (s32)arg1[1], (s32)arg1[2], (s32)arg1[3], (s32)arg1[4], (s32)arg1[5]);
    if (fn_8023A5A4() == 0) {
        if (lbl_8052CDC0[0] >= 2) fn_802319E4(0x80001, base + 0x168);
        return 0;
    }
    r30 = fn_8024FCD0(r29);
    if (r30 == 0) {
        if (lbl_8052CDC0[0] >= 2) fn_802319FC(0x80001, base + 0x18C, r29);
        return 0;
    }
    r29 = fn_8024E73C(arg1);
    if (r29 == 0) {
        r29 = fn_8024E568(arg1);
        if (r29 == 0) {
            if (lbl_8052CDC0[0] >= 2) fn_802319E4(0x80001, base + 0x1BC);
            return 0;
        }
        if (fn_802500CC() == 0) return 0;
    }
    if (*(s32 *)((u8 *)r29 + 4) == 5) {
        if (lbl_8052CDC0[0] >= 3) fn_802319E4(0x80002, base + 0x1E0);
        return 0;
    }
    p = (void *)fn_8024F968(r29);
    if (p == 0) {
        if (lbl_8052CDC0[0] >= 2) fn_802319E4(0x80001, base + 0x218);
        return 0;
    }
    *(s32 *)((u8 *)p + 0x30) = r30;
    if (*(s32 *)((u8 *)r29 + 4) == 4) fn_8024AED0(p, 0x14, 0);
    if (lbl_8052CDC0[0] >= 3) fn_802319FC(0x80002, base + 0x23C, *(u16 *)((u8 *)p + 0x14));
    return *(u16 *)((u8 *)p + 0x14);
}