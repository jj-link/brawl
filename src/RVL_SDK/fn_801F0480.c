#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad0[149];
    u32 hi : 28;
    u32 n : 4;
} GXRegA;

extern u32* __GXData;

void GXSetNumTexGens(u32 arg0) {
    u32* gx = __GXData;
    GXRegA* r = (GXRegA*)gx;
    r->n = arg0;
    gx[0x5FC / 4] = gx[0x5FC / 4] | 0x02000000 | 4;
}
