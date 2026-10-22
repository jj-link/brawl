#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

enum _GXTexMapID { GX_TEXMAP0 = 0 };

namespace nw4r {
namespace g3d {
class ScnMdl;
class ResMdl {
public:
    void* GetResMat(const char* name) const;
};
class ResTexObj {
public:
    void* GetTexObj(_GXTexMapID id);
};
class ScnMdl {
public:
    class CopiedMatAccess {
    public:
        CopiedMatAccess(ScnMdl* mdl, unsigned long idx);
        u8 pad[0x34];
    };
};
} // namespace g3d
} // namespace nw4r

extern "C" s32 fn_801AFF4C(nw4r::g3d::ScnMdl::CopiedMatAccess* self, s32 arg);
extern "C" void fn_801F2C9C(s32 a, s32* b, u16* c, u16* d, s32* e, s32* f, s32* g, u8* h);
extern "C" void fn_801F28F0(s32 a, s32 b, u16 c, u16 d, s32 e, s32 f, s32 g, u8 h);

extern "C" {
void fn_800B70D0(u8* self, const char* name, s32 arg2) {
    nw4r::g3d::ScnMdl::CopiedMatAccess sp24(*(nw4r::g3d::ScnMdl**)(self + 0xc),
                                            ((u32*)((nw4r::g3d::ResMdl*)(self + 8))->GetResMat(name))[3]);
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10 = fn_801AFF4C(&sp24, 0);
    s32 tex = (s32)((nw4r::g3d::ResTexObj*)&sp10)->GetTexObj(GX_TEXMAP0);
    u16 spC;
    u16 spA;
    u8 sp8;
    fn_801F2C9C(arg2, &sp20, &spC, &spA, &sp1C, &sp18, &sp14, &sp8);
    fn_801F28F0(tex, sp20, spC, spA, sp1C, sp18, sp14, sp8);
}
}
