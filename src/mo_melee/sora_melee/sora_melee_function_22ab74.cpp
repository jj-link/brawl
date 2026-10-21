#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct S {
    u8 pad0[0x40];
    u8* f40;
    u8* f44;
    u8* f48;
    u8* f4c;
    u32 count;
};

extern "C" void fn_27_22AB74(S* p) {
    {
        u32 off;
        u32 i;
        for (i = 0, off = 0; i < p->count; i++, off += 0x24) {
            *(s32*)(p->f40 + off) = 0;
        }
    }
    {
        u32 off;
        u32 i;
        for (i = 0, off = 0; i < p->count; i++, off += 0x24) {
            *(s32*)(p->f44 + off) = 0;
        }
    }
    {
        u32 off;
        u32 i;
        for (i = 0, off = 0; i < p->count; i++, off += 0x14) {
            *(s32*)(p->f48 + off) = 0;
        }
    }
    {
        u32 off;
        u32 i;
        for (i = 0, off = 0; i < p->count; i++, off += 0x10) {
            *(s32*)(p->f4c + off) = 0;
        }
    }
}
