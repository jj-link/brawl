#pragma force_active on
extern void *lbl_805A0F70;
extern int fn_8033891C(void);
extern int fn_80339410(void);
extern int fn_803517BC(int, int);
extern int fn_80368538(void *, int, int *);
extern int fn_803683E8(void *, int, int);

typedef unsigned char u8;

u8 fn_80337AF0(int arg0, int arg1) {
    int sp8;
    int temp;

    sp8 = 0;
    if (lbl_805A0F70 == 0 || fn_80339410() == 0) {
        return 0;
    }
    temp = fn_803517BC(fn_8033891C(), arg0);
    if (temp > 0 && fn_80368538(*(void **)((char *)lbl_805A0F70 + 4), temp, &sp8) != 0) {
        return 0;
    }
    if (temp <= 0 || sp8 == -1) {
        return 0;
    }
    return fn_803683E8(*(void **)((char *)lbl_805A0F70 + 4), sp8, arg1) == 0;
}
