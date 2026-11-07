#include <types.h>
#pragma force_active on

extern u32 lbl_805A1210;
extern u32 lbl_805A1220;
extern int lbl_805A1214;
extern void *fn_803C1668(s8);
extern void fn_803C13C8(void *);
extern int fn_803C2AB0(void);
extern int fn_803C2A2C(int, int);
extern void fn_803C7D64(s32, s32);

int fn_803C5428(u32 arg0, int arg1) {
    void *ptr;
    int result;

    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        ptr = (void *)(lbl_805A1220 + arg0 * 0x140);
    } else {
        ptr = 0;
    }

    if (ptr != 0) {
        void *tmp = fn_803C1668(*(s8 *)((u8 *)ptr + 0x14));
        if (tmp != 0) {
            fn_803C13C8(tmp);
            result = 0;
        } else {
            int r = fn_803C2AB0();
            if (r == 0) {
                result = -1;
            } else {
                result = r;
            }
        }
    } else {
        result = 0xB003;
    }

    if (result == 0) {
        void *ptr2;
        int ret;
        if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
            ptr2 = (void *)(lbl_805A1220 + arg0 * 0x140);
        } else {
            ptr2 = 0;
        }
        if (ptr2 != 0 && ptr2 != 0) {
            int field8 = *(int *)((u8 *)ptr2 + 8);
            if (field8 != 0) {
                fn_803C7D64(field8, 0);
            }
        }
        ret = fn_803C2A2C(arg1, 0);
        if (ret == 0) {
            int r = fn_803C2AB0();
            if (r != 0) {
                lbl_805A1214 = r;
            }
        }
        return ret;
    }
    if (result != 0) {
        lbl_805A1214 = result;
    }
    return 0;
}
