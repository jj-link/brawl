#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
struct In {
    u32 magic;
    u16 pad4;
    u16 version;
    u32 pad8[2];
    u32 off10;
    u32 pad14;
    u32 off18;
};
struct Out {
    In* file;
    void* a;
    void* b;
};
static inline int valid(const In* in) {
    if (in->magic != 0x52424E4BU)
        return 0;
    u32 version = in->version;
    if (version < 0x100U)
        return 0;
    return version <= 0x101U;
}
extern "C" void fn_801BBF58(Out* __restrict out, In* __restrict in) {
    out->file = 0;
    out->a = 0;
    out->b = 0;
    if (valid(in)) {
        out->file = in;
        out->a = (void*)(in->off10 + (u32)in);
        out->b = (void*)(in->off18 + (u32)in);
    }
}