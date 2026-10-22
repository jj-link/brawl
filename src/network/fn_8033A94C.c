#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad[0x668];
    u32 unk668;
} NetState;

extern NetState *lbl_805A0F88;
extern void *lbl_80533730[32];
extern u8 *fn_80374C28(void *);

s32 fn_8033A94C(u32 arg0) {
    s32 i;
    void **p;

    if (lbl_805A0F88 == 0) {
        return 0;
    }
    if (!(lbl_805A0F88->unk668 & (1u << arg0))) {
        return 0;
    }
    i = 0;
    p = lbl_80533730;
    while (1) {
        if (*p != 0 && arg0 == fn_80374C28(*p)[1]) {
            return 1;
        }
        i++;
        p++;
        if (i >= 0x20) {
            break;
        }
    }
    return 0;
}
