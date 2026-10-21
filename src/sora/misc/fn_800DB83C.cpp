#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct IfMngr {
    u8 flags;
    u8 pad[3];
    u32 x04, x08, x0C, x10, x14, x18;
    u32 x1C, x20, x24, x28, x2C, x30, x34, x38, x3C, x40;
    u32 x44, x48;
    u8 x4C[0x1C];
    u8 x68[7];
    u8 x6F;
    u32 x70, x74, x78, x7C, x80, x84, x88, x8C;
    u32 x90, x94, x98, x9C, xA0, xA4;
    u8 xA8, xA9;
    u8 padAA[2];
    u32 xAC, xB0, xB4, xB8, xBC, xC0, xC4;
};

extern IfMngr* g_IfMngr;
extern "C" void* memset(void*, int, unsigned int);

extern "C" IfMngr* fn_800DB83C(IfMngr* p) {
    p->x04 = 0;
    p->x08 = 0;
    p->flags = (p->flags | 0x80) & ~0x40;
    p->x0C = 0;
    p->x10 = 0;
    p->x14 = 0;
    p->x18 = 0;
    p->x44 = 0;
    p->x48 = 0;
    p->x70 = 0;
    p->x74 = 0;
    p->x78 = 0;
    p->x7C = 0;
    p->x80 = 0;
    p->x84 = 0;
    p->x88 = 0;
    p->x8C = 0;
    p->x90 = 0;
    p->x94 = 0;
    p->x98 = 0;
    p->x9C = 0;
    p->xA0 = 0;
    p->xA4 = 0;
    p->xA8 = 0;
    p->xA9 = 0;
    p->xAC = 0;
    p->xB0 = 0;
    p->xB4 = 0;
    p->xB8 = 0;
    p->xBC = 0;
    p->xC0 = 0;
    p->xC4 = 0;
    p->x1C = 0;
    p->x20 = 0;
    p->x24 = 0;
    p->x28 = 0;
    p->x2C = 0;
    p->x30 = 0;
    p->x34 = 0;
    p->x38 = 0;
    p->x3C = 0;
    p->x40 = 0;
    memset(p->x4C, 0, 0x1C);
    memset(p->x68, 0, 7);
    g_IfMngr = p;
    return p;
}
