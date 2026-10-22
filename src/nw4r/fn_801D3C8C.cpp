#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

struct In {
    u32 sig;
    u16 bom;
    u16 version;
    u32 size;
    u16 headerSize;
    u16 blocks;
    u32 off10;
    u32 size14;
    u32 off18;
};

struct Out {
    In* p0;
    void* p4;
    void* p8;
};

extern "C" void fn_801D3C8C(Out* __restrict dst, In* __restrict src)
{
    dst->p0 = 0;
    dst->p4 = 0;
    dst->p8 = 0;

    bool valid;
    if (src->sig != 0x52575344)
        valid = false;
    else if (src->version < 0x100)
        valid = false;
    else
        valid = src->version <= 0x102;

    if (valid) {
        void* p4 = (void*)(src->off10 + (u32)src);
        void* p8 = (void*)(src->off18 + (u32)src);
        dst->p0 = src;
        dst->p4 = p4;
        dst->p8 = p8;
    }
}
