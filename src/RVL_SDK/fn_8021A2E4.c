#pragma force_active on
extern void *lbl_804F6810[];

void fn_8021A2E4(int arg0, int arg1) {
    unsigned char *obj = (unsigned char *)lbl_804F6810[arg0];
    void (*f)(int, int) = *(void (**)(int, int))(obj + 0x988);

    if (f != 0) {
        f(arg0, arg1);
    }
    *(void **)(obj + 0x988) = 0;
    obj[0x98C] = 0;
}
