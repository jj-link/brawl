#pragma force_active on
typedef unsigned int u32;
typedef struct {
    unsigned char pad0[0x254];
    struct { u32 upper : 16; u32 cull : 2; u32 lower : 14; } genMode;
    unsigned char pad258[0x5FC - 0x258];
    u32 dirtyState;
} GXData;
extern GXData* const __GXData;
void GXSetCullMode(u32 mode) {
    GXData* p = __GXData;
    u32 val = (mode << 1) & 2;
    val |= (mode >> 1) & 1;
    p->genMode.cull = val;
    p->dirtyState |= 4;
}
