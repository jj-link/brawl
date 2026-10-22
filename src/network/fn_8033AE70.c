#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void *lbl_80533730[32];
extern u8 *fn_80374C28(void *);

s32 fn_8033AE70(u32 arg0) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (lbl_80533730[i] != 0 && arg0 == fn_80374C28(lbl_80533730[i])[1]) {
            return 1;
        }
    }
    return 0;
}
