#pragma force_active on
extern unsigned char lbl_804F9FC0[];

void fn_80228448(int arg0, int arg1) {
    unsigned char *p;
    void (*fn)(int, int);

    p = lbl_804F9FC0 + arg0 * 0x528;
    if (arg1 == 0) {
        if (*(void (**)(int, int))(p + 0x4D8) != 0 && p[0x523] == 0) {
            p[0x523] = 1;
            fn = *(void (**)(int, int))(p + 0x4D8);
            fn(arg0, 1);
            p[0x522] = 0;
        }
    }
    p[0x51F] = 0;
}
