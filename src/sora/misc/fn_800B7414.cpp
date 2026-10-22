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
extern "C" void fn_801F28F0(s32 t, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, u8 g);
extern "C" void fn_801F2FB0(s32 a, s32 b);

extern "C" void fn_800B7414(u8* self, const char* name, s32 a, s32 b, s32 c) {
    s32 sp8 = 0;
    nw4r::g3d::ScnMdl::CopiedMatAccess spC(*(nw4r::g3d::ScnMdl**)(self + 0xc),
                                           ((u32*)((nw4r::g3d::ResMdl*)(self + 8))->GetResMat(name))[3]);
    sp8 = fn_801AFF4C(&spC, 0);
    s32 tex = (s32)((nw4r::g3d::ResTexObj*)&sp8)->GetTexObj(GX_TEXMAP0);
    fn_801F28F0(tex, a, b, c, 6, 0, 0, 0);
    fn_801F2FB0(tex, 0);
}
