#pragma force_active on
extern void *fn_80251AD0(void);
extern void fn_80250D00(void *, int, int, int);
extern void fn_802552C0(void *, int, int, int, int);
extern void fn_8025640C(void *, int);

void fn_80254774(unsigned char *arg0, int arg1, int arg2) {
    unsigned char *temp;

    temp = (unsigned char *)fn_80251AD0();
    if (arg0[0x6C] != 5) {
        fn_80250D00(arg0, arg1, 0, 1);
        return;
    }
    if (arg2 == 0) {
        temp[0x69] = temp[0x69] | 2;
    } else {
        temp[0x69] = temp[0x69] | 4;
    }
    fn_802552C0(arg0, arg1, 1, arg2, 0x3F7F);
    fn_8025640C(temp, 0x3C);
}
