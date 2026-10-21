#pragma force_active on
typedef unsigned int u32;

typedef struct GXData {
    unsigned char pad0[0x254];
    unsigned int unused : 25;
    unsigned int numChans : 3;
    unsigned int low : 4;
    unsigned char pad258[0x5FC - 0x258];
    u32 dirtyState;
} GXData;

extern GXData* const __GXData;

void GXSetNumChans(unsigned char nChans) {
    __GXData->numChans = nChans;
    __GXData->dirtyState |= 0x01000004;
}
