#pragma force_active on

extern int SOHtoNl(int);
extern short SOHtoNs(unsigned short);
extern void fn_8035B34C(void *);
extern void fn_8035B38C(void *, void *, int);
extern void fn_8035B478(void *, void *);
extern void fn_80361680(void *, void *, void *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern char lbl_80490604[];
extern char lbl_80490638[];
extern char lbl_8059FA6C;

int fn_8037D304(void *unused, unsigned char *ctx, unsigned char *src, int len, unsigned char *dst, int *rem) {
    unsigned char sp20[0x58];
    unsigned char sp10[0x10];
    short sp8;
    int spC;
    unsigned char *obj;
    unsigned char *p;
    int r29;
    int i;

    if (ctx != 0) {
        obj = *(unsigned char **)ctx;
        if (obj == 0 || *(int *)(ctx + 0xC) == 0) {
            if (len > *rem) {
                return 2;
            }
            memcpy(dst, src, len);
            *rem += len;
            goto done;
        }
        sp8 = SOHtoNs((unsigned short)len);
        if (*rem < len + 5) {
            return 2;
        }
        dst[0] = 0x17;
        dst[1] = 3;
        dst[2] = 0;
        fn_8035B34C(sp20);
        fn_8035B38C(sp20, obj + 0x320, *(int *)(obj + 0x388));
        fn_8035B38C(sp20, lbl_80490604, 0x30);
        fn_8035B38C(sp20, obj + 0x310, 8);
        fn_8035B38C(sp20, &lbl_8059FA6C, 1);
        fn_8035B38C(sp20, &sp8, 2);
        fn_8035B38C(sp20, src, len);
        fn_8035B478(sp10, sp20);
        fn_8035B34C(sp20);
        fn_8035B38C(sp20, obj + 0x320, *(int *)(obj + 0x388));
        fn_8035B38C(sp20, lbl_80490638, 0x30);
        fn_8035B38C(sp20, sp10, 0x10);
        fn_8035B478(sp10, sp20);
        fn_80361680(obj + 0x3A0, src, dst + 5, len);
        r29 = len + 5;
        fn_80361680(obj + 0x3A0, sp10, dst + r29, 0x10);
        spC = SOHtoNl(r29 + 0xB);
        memcpy(dst + 3, (unsigned char *)&spC + 2, 2);
        *rem -= r29 + 0x10;
        i = 7;
        do {
            p = obj + i;
            if (p[0x310] == 0xFF) {
                p[0x310] = 0;
                i -= 1;
            } else {
                i = 0;
                p[0x310] = p[0x310] + 1;
            }
        } while (i >= 0);
    }
done:
    return 1;
}
