#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    u8 *unk0;
    u8 *unk4;
    u8 *unk8;
    u8 unkC;
    char padD[3];
    u32 unk10;
    u32 unk14;
} Buf;

void fn_80269394(Buf *obj, u8 *src, int count) {
    int i;
    for (i = 0; i < count; i++) {
        u8 *start = obj->unk0;
        u32 dist = obj->unk4 - start;
        if (dist >= obj->unk10) {
            obj->unkC = 1;
            obj->unk14 += dist;
            obj->unk4 = start;
        }
        *obj->unk4 = *src++;
        obj->unk4++;
    }
    *obj->unk4 = 0;
}