#pragma force_active on
typedef signed short s16;

extern void fn_80252784(void*, s16, s16*);

void fn_80254568(void* arg1, s16 arg2) {
    s16 sp8;

    sp8 = arg2;
    fn_80252784(arg1, 7, &sp8);
}
