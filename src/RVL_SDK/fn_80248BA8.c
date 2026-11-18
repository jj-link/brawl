#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 lbl_8052C9B8[0x408];
extern u8 lbl_80482490[];
extern void fn_802319E4(int, u8 *);
extern void fn_802319FC(int, u8 *, u32);
extern void fn_80240250(void *, u32, u32, u32, int, void (*)(void *, u8 *, int), void *);
extern void fn_8024A8F4(u32, u8 *);
extern void fn_8024AA7C(u16);
extern void fn_80248994(void *, u8 *, int);
#define SLOT_HIT(i) (tbl[(u8)(i) * 52] != 0 && tbl[(u8)(i) * 52 + 0x10] != 0 && (arg0 == *(u16 *)(tbl + (u8)(i) * 52 + 0x14) || arg0 == *(u16 *)(tbl + (u8)(i) * 52 + 0x16)))
void fn_80248BA8(u32 arg0, int arg1) {
    u8 *str = lbl_80482490;
    u8 *obj = 0;
    u8 *tbl = lbl_8052C9B8;
    u8 *base = 0;
    u8 idx = 0;
    int ctr;
    u8 *ent;
    for (ctr = 4; ctr > 0; ctr--) {
        if (SLOT_HIT(idx)) goto found;
        idx++;
        if (SLOT_HIT(idx)) goto found;
        idx++;
        if (SLOT_HIT(idx)) goto found;
        idx++;
        if (SLOT_HIT(idx)) goto found;
        idx++;
    }
found:
    if (idx != 0x10) {
        base = lbl_8052C9B8 + (u8)idx * 52;
        obj = base + 0x10;
    }
    if (obj == 0 || !(obj[1] & 1) || (arg0 == *(u16 *)(obj + 4) && obj[0] != 1) || (arg0 == *(u16 *)(obj + 6) && obj[0] != 2)) {
        if (lbl_8052C9B8[0x401] >= 2) fn_802319FC(0x1E0001, str + 0x1BC, arg0);
    } else {
        if (arg1 != 0) {
            if (arg0 == *(u16 *)(obj + 4)) *(u16 *)(obj + 4) = 0;
            else *(u16 *)(obj + 6) = 0;
            ent = lbl_8052C9B8 + (u8)idx * 52;
            if (lbl_8052C9B8[0x401] >= 4) fn_802319E4(0x1E0003, str + 0x44);
            if (*(u16 *)(ent + 0x14) != 0 || *(u16 *)(ent + 0x16) != 0) {
                ent[0x10] = 5;
                if (*(u16 *)(ent + 0x16) != 0) fn_8024AA7C(*(u16 *)(ent + 0x16));
                if (*(u16 *)(ent + 0x14) != 0) fn_8024AA7C(*(u16 *)(ent + 0x14));
            } else ent[0x10] = 0;
            (*(void (**)(int, int, int, int))(lbl_8052C9B8 + 0x340))(idx, 1, arg1 | 0x100, 0);
            return;
        }
        if (arg0 == *(u16 *)(obj + 4)) {
            obj[0] = 6;
            *(u16 *)(obj + 0xA) = 0x100;
            fn_80240250(base + 1, 0x11, 1, 6, -((*(u16 *)(base + 8) >> 15) & 1) + 2U, fn_80248994, base);
        } else obj[0] = 3;
        fn_8024A8F4(arg0, lbl_8052C9B8 + 0x344);
        if (lbl_8052C9B8[0x401] >= 4) fn_802319FC(0x1E0003, str + 0x1E8, arg0);
    }
}