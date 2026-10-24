#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct GXData {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 pad[0x5F9 - 0x06];
    u8 unk5F9;
    u8 unk5FA;
    u8 pad2;
    u32 gxDirtyFlags;
} GXData;

extern GXData* const __GXData;

void GXSetMisc(s32 token, s32 val)
{
    switch (token) {
    case 0:
        break;
    case 1:
        __GXData->unk4 = val;
        __GXData->unk0 = (val & 0xFFFF) == 0;
        __GXData->unk2 = 1;
        if (val & 0xFFFF)
            __GXData->gxDirtyFlags |= 8;
        break;
    case 2:
        __GXData->unk5F9 = val != 0;
        break;
    case 3:
        __GXData->unk5FA = val != 0;
        break;
    }
}
