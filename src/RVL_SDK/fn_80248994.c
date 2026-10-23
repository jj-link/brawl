#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_802319E4(int, u8 *);
extern u16 fn_8024A530(int, u8 *);
extern void fn_8024AA7C(u16);
extern u8 lbl_80482490[];
extern u8 lbl_8052C9B8[];

void fn_80248994(void *unused, u8 *p, int flag) {
    u8 *str;
    u8 idx;
    u8 *e;
    u16 result;

    str = lbl_80482490;
    idx = (u8)((p - lbl_8052C9B8) / 52);

    if (flag == 0 && p[0x10] == 6) {
        if (lbl_8052C9B8[0x401] >= 4) {
            fn_802319E4(0x1E0003, str + 0x180);
        }
        *(u16 *)(p + 0x1A) = 0;
        e = lbl_8052C9B8 + idx * 52;
        result = fn_8024A530(0x13, e + 1);
        *(u16 *)(p + 0x16) = result;
        if (result == 0) {
            if (lbl_8052C9B8[0x401] >= 2) {
                fn_802319E4(0x1E0001, str + 0x1A0);
            }
            if (lbl_8052C9B8[0x401] >= 4) {
                fn_802319E4(0x1E0003, str + 0x44);
            }
            if (*(u16 *)(e + 0x14) != 0 || *(u16 *)(e + 0x16) != 0) {
                e[0x10] = 5;
                if (*(u16 *)(e + 0x16) != 0) {
                    fn_8024AA7C(*(u16 *)(e + 0x16));
                }
                if (*(u16 *)(e + 0x14) != 0) {
                    fn_8024AA7C(*(u16 *)(e + 0x14));
                }
            } else {
                e[0x10] = 0;
            }
            (*(void (**)(int, int, int, int))(lbl_8052C9B8 + 0x340))(idx, 1, 0x200, 0);
            return;
        }
        p[0x10] = 2;
    }

    if (flag != 0 && p[0x10] == 6) {
        *(u16 *)(p + 0x1A) = 0xF;
        e = lbl_8052C9B8 + idx * 52;
        if (lbl_8052C9B8[0x401] >= 4) {
            fn_802319E4(0x1E0003, str + 0x44);
        }
        if (*(u16 *)(e + 0x14) != 0 || *(u16 *)(e + 0x16) != 0) {
            e[0x10] = 5;
            if (*(u16 *)(e + 0x16) != 0) {
                fn_8024AA7C(*(u16 *)(e + 0x16));
            }
            if (*(u16 *)(e + 0x14) != 0) {
                fn_8024AA7C(*(u16 *)(e + 0x14));
            }
        } else {
            e[0x10] = 0;
        }
    }
}
