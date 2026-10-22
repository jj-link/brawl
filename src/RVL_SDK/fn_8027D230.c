#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

struct Table {
    s32 *unk0;
    s32 unk4;
    s32 unk8;
};

u32 fn_8027D198(void *t, u32 key);

s32 fn_8027D230(void *t, u32 key, s32 *out) {
    s32 temp_r6;
    u32 temp_r3;
    struct Table *tbl = (struct Table *)t;

    temp_r3 = fn_8027D198(t, key);
    temp_r6 = tbl->unk8;
    if ((s8)((u8)((s32)temp_r3 <= temp_r6)) != 0) {
        *out = *(s32 *)((char *)tbl->unk0 + ((temp_r3 + temp_r6 + 1) * 4));
        return 0;
    }
    return 1;
}
