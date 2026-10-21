#pragma force_active on
typedef void (*Fn1)(int);

extern Fn1 lbl_805A0E68;
extern unsigned char lbl_805A0E70;

void fn_8025F99C(void) {
    Fn1 func = lbl_805A0E68;

    lbl_805A0E70 = 1;

    if (func) {
        func(0);
    }
}
