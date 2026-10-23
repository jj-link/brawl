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

void fn_802692BC(Buf *obj, u8 val) {
    u32 dist;
    u8 *next;
    u8 *start;
    u8 *ptr;
    ptr = obj->unk4;
    *ptr = val;
    next = ptr + 1;
    start = obj->unk0;
    dist = next - start;
    obj->unk4 = next;
    if (dist >= obj->unk10) {
        obj->unkC = 1;
        obj->unk14 += dist;
        obj->unk4 = start;
    }
    obj->unk4[0] = 0;
}
