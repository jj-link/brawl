#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void *lbl_80533730[32];
extern s32 lbl_805A0F88;
extern u8 *fn_80374C28(void *);

void *fn_8033ABE8(u32 arg0) {
    s32 i;

    if (lbl_805A0F88 == 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        if (lbl_80533730[i] != 0 && arg0 == fn_80374C28(lbl_80533730[i])[1]) {
            return lbl_80533730[i];
        }
    }
    return 0;
}
