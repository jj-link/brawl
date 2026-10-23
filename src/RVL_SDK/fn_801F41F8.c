#pragma force_active on
typedef unsigned int u32;

typedef struct {
    unsigned char pad0[0x254];
    u32 genMode;
    unsigned char pad258[0x5FC - 0x258];
    u32 dirtyState;
} GXData;

extern GXData* const __GXData;

void GXSetNumTevStages(int num) {
    GXData* p = __GXData;
    int n = num - 1;
    p->genMode = __rlwimi(p->genMode, n, 10, 18, 21);
    p->dirtyState |= 4;
}
