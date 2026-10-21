#pragma force_active on
typedef unsigned char u8;

extern u8 *fn_80374C28(void *);

u8 fn_8033AC84(void *p) {
    return fn_80374C28(p)[1];
}
