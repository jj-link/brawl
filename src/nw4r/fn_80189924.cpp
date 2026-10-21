#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    char pad[0x38];
    u32 unk38;
    char pad2[4];
    u32 unk40;
} Obj;

extern "C" {
int fn_80189924(Obj* arg0) {
    u32 temp_r0 = arg0->unk38;
    u32 base = arg0->unk40;
    u32 a = (temp_r0 >> 0x18U) & 0xF;
    u32 b = temp_r0 >> 0x1CU;
    return (base + (a * 0x14)) + (b * 0x1C);
}
}
