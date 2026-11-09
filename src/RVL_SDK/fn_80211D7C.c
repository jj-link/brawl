#pragma force_active on
typedef unsigned int u32;
typedef int s32;
extern void fn_801E187C(void *);
extern u32 fn_80211AC0(s32);
extern void fn_80211AD0(s32, u32);
extern void fn_80211B24(s32, s32);
extern void fn_80213ACC(void);
typedef struct Q { u32 unk0, unk4, unk8, unkC; s32 *unk10[4]; } Q;
extern Q lbl_804F6540;
extern s32 lbl_8059ECC8, lbl_805A0BF0;
extern s32 *lbl_805A0BF4;
void fn_80211D7C(s32 arg0, s32 arg1) {
    s32 r31; u32 t, u0; s32 *e; u32 a, b; s32 d;
    if ((fn_80211AC0(1) & 0x14) == 0x14) fn_80211B24(arg0, arg1);
    if ((fn_80211AC0(1) & 0x22) == 0x22) {
        fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 2);
        *(u32 *)0xCD000030 = 0x40000000;
        r31 = lbl_8059ECC8;
        if (r31 < 1) { r31 += 1; lbl_8059ECC8 = r31; fn_80213ACC(); }
        if (r31 > 0) {
            if (lbl_805A0BF0 != 0) {
                lbl_805A0BF4[1] = 0;
                lbl_805A0BF0 = 0;
                fn_801E187C((char *)lbl_805A0BF4 + 0x2C);
                fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 8);
            }
            if (lbl_804F6540.unk4 < lbl_804F6540.unk0) {
                d = lbl_804F6540.unk4 - lbl_804F6540.unk0;
            } else {
                d = (lbl_804F6540.unk4 - lbl_804F6540.unk0) == 0;
            }
            if (d == 0) {
                e = lbl_804F6540.unk10[lbl_804F6540.unk8];
                if (e != 0) {
                    if (e[10] != 0) lbl_8059ECC8 -= 1;
                    fn_80211AD0(0, (u32)e + 0x80000000);
                    lbl_804F6540.unk8 = (lbl_804F6540.unk8 + 1) & 0xF;
                    lbl_804F6540.unk0++;
                    lbl_8059ECC8--;
                    fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 1);
                }
            }
        }
    }
}