#pragma force_active on
extern void fn_80255484(void *, unsigned char, unsigned char);
extern void fn_802548F4(void *, unsigned char, unsigned char);
extern void fn_802319E4(unsigned int, const char *);
extern unsigned char lbl_8052D5A8[];
extern char lbl_804842E0[];

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_80251C84(void *arg0, unsigned char arg1, unsigned int arg2) {
    u8 *s = (u8 *)arg0;
    u8 *temp_r6 = *(u8 **)(s + 0x6C);
    u16 r4;
    u16 r0;
    u16 r3;

    if (temp_r6 != 0) {
        if (temp_r6[0x72] == 2) {
            if (arg1 != 0) {
                r0 = *(u16 *)(s + 0x9A);
                if (arg2 > r0) {
                    *(u16 *)(s + 0x9A) = 0;
                } else {
                    *(u16 *)(s + 0x9A) = (u16)(r0 - arg2);
                }
                r4 = *(u16 *)(s + 0x9A);
                if (r4 <= *(u16 *)(s + 0x9E) && s[0x3D] == 0) {
                    r0 = *(u16 *)(s + 0x9C);
                    if (r0 > r4) {
                        fn_80255484(*(void **)(s + 0x6C), s[0xD], (u8)(r0 - r4));
                        r3 = *(u16 *)(s + 0x9C);
                        s[0x3C] = 0;
                        *(u16 *)(s + 0x9A) = r3;
                    }
                }
            } else {
                if (*(int *)(s + 0x94) != 0) {
                    s[0x3C] = 1;
                    return;
                }
                if (*(u16 *)(s + 0x38) >= *(u16 *)(s + 0x9C)) {
                    s[0x3C] = 1;
                }
            }
        } else if (arg1 != 0) {
            if (s[0x3C] != 0 && *(u32 *)(s + 0x40) < 0x1388 && *(u16 *)(s + 0x38) < 8) {
                s[0x3C] = 0;
                if (s[0x3D] == 0) {
                    fn_802548F4(temp_r6, s[0xD], 1);
                }
            }
        } else {
            if (*(int *)(s + 0x94) != 0) {
                s[0x3C] = 1;
                fn_802548F4(temp_r6, s[0xD], 0);
                return;
            }
            if ((*(u32 *)(s + 0x40) > 0x1F40 || *(u16 *)(s + 0x38) > 0x10) && s[0x3C] == 0) {
                if (lbl_8052D5A8[0x414] >= 4) {
                    fn_802319E4(0x90003, lbl_804842E0);
                }
                s[0x3C] = 1;
                fn_802548F4(*(void **)(s + 0x6C), s[0xD], 0);
            }
        }
    }
}
