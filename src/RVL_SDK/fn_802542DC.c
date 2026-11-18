#pragma force_active on
extern void fn_80251054(int, unsigned char, unsigned char);
extern unsigned char *fn_80251AD0(int, unsigned char);
extern void fn_80255210(int, int, int, int);
extern void fn_8025648C(void *);

void fn_802542DC(int arg0, int arg1, unsigned char *arg2) {
    if (arg1 != 0) {
        fn_80251054(arg0, arg2[0], arg2[9]);
        fn_80255210(arg0, arg2[0], 0, arg2[9]);
    } else {
        unsigned char *p = fn_80251AD0(arg0, arg2[0]);
        if (p == 0 || !(p[0x69] & 0x10)) {
            return;
        }
        p[0x69] &= ~0x10;
        fn_8025648C(p);
    }
}
