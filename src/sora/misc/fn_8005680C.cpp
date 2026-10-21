#pragma force_active on

typedef unsigned short u16;
typedef int s32;

extern u16 lbl_8042D5C0[];
extern s32 lbl_8059CE44;

extern "C" s32 fn_8005680C(s32 arg0)
{
    u16 i;

    if (arg0 < 0) {
        return -1;
    }
    for (i = 0; (s32)i < lbl_8059CE44; i++) {
        if (arg0 == (s32)((lbl_8042D5C0[i] >> 6) & 0x3FF)) {
            return (u16)i;
        }
    }
    return -1;
}
