#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    char pad0[0x14];
    s32 unk14;
} StructA;

typedef struct {
    char pad0[6];
    s16 unk6;
} StructB;

extern "C" s32 fn_80111B70(StructA* arg0, StructB* arg1) {
    s16 val = arg1->unk6;
    s32 result = 0;
    if (val >= 0) {
        result = arg0->unk14 + val * 0x12;
    }
    return result;
}
