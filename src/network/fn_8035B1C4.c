#pragma force_active on
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 *unk0;
    s32 unk4;
    s32 unk8;
    s32 (*unkC)(s32, s32);
    s32 unk10;
} S_8035B1C4;

s32 fn_8035A598(s32, s32);
s32 fn_8035AAD8(s32, s32, s32, s32, s32);

s32 fn_8035B1C4(S_8035B1C4 *arg0, s32 arg1) {
    s32 off;
    s32 ret;

    if (arg0 == 0) {
        return 0;
    }
    off = arg0->unkC(arg1, arg0->unk4) * 4;
    ret = fn_8035AAD8(*(s32 *)((u8 *)arg0->unk0 + off), arg1, arg0->unk10, 0, 0);
    if (ret == -1) {
        return 0;
    }
    return fn_8035A598(*(s32 *)((u8 *)arg0->unk0 + off), ret);
}
