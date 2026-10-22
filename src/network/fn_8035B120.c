#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct Obj {
    u32 *unk0;
    u32 unk4;
    u32 unk8;
    s32 (*unkC)(s32, u32);
    u32 unk10;
} Obj;

extern s32 fn_8035A918(u32, s32, u32 *);
extern s32 fn_8035AAD8(u32, s32, u32, s32, s32);

s32 fn_8035B120(Obj *arg0, s32 arg1) {
    s32 off;
    s32 temp_r3;

    if (arg0 == 0) {
        return 0;
    }
    off = arg0->unkC(arg1, arg0->unk4) * 4;
    temp_r3 = fn_8035AAD8(*(u32 *)((u8 *)arg0->unk0 + off), arg1, arg0->unk10, 0, 0);
    if (temp_r3 == -1) {
        return 0;
    }
    fn_8035A918(*(u32 *)((u8 *)arg0->unk0 + off), temp_r3, arg0->unk0);
    return 1;
}
