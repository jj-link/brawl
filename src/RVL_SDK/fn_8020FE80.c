#pragma force_active on
extern int fn_8020F248(void *p, int v);

unsigned char fn_8020FE80(void) {
    unsigned char sp8;
    if (fn_8020F248(&sp8, 0x20) == 0) {
        sp8 = 1;
    } else if (sp8 != 1) {
        sp8 = 0;
    }
    return sp8;
}
