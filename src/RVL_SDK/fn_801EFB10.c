#pragma force_active on
typedef unsigned int u32;

typedef struct GXData {
    unsigned char pad0[0x14];
    u32 vcdLoReg;
    u32 vcdHiReg;
    unsigned char pad1[0x524 - 0x1C];
    unsigned char normal;
    unsigned char binormal;
    unsigned char pad2[0x5FC - 0x526];
    u32 gxDirtyFlags;
} GXData;

extern GXData *const __GXData;

void fn_801EFB10(void)
{
    __GXData->vcdLoReg = 0;
    __GXData->vcdLoReg = __rlwimi(__GXData->vcdLoReg, 1, 9, 21, 22);
    __GXData->vcdHiReg = 0;
    __GXData->normal = 0;
    __GXData->binormal = 0;
    __GXData->gxDirtyFlags |= 8;
}
