#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <GX.h>
#pragma force_active on

using namespace nw4r::g3d;
struct Access { ScnMdl::CopiedMatAccess value; char pad[4]; Access(ScnMdl* obj, u32 id) : value(obj, id) {} };
extern "C" {
extern const GXColor lbl_72_rodata_74;
extern const GXColor lbl_72_rodata_78;
extern const char lbl_72_data_AB0[];
void fn_80190A3C(ResMatTevColor*, bool);
}
inline GXColor getColor(const GXColor& c) {
    GXColor result = c;
    return result;
}
extern "C" void fn_72_3158(void* self, int arg1) {
    ResMdl res;
    ResMat mat;
    ResMatTevColor tev;
    ScnMdl* obj = **(ScnMdl***)((char*)self + 0x44);
    if (!obj) return;
    res = ResMdl(*(void**)((char*)obj + 0xe8));
    if (!res.IsValid()) return;
    mat = res.GetResMat(lbl_72_data_AB0);
    if (!mat.IsValid()) return;
    Access access(obj, mat.ptr()->m_id);
    tev = access.value.GetResMatTevColor(false);
    if (!tev.IsValid()) return;
    GXColor color;
    switch (arg1) {
    case 0: color = getColor(lbl_72_rodata_74); break;
    case 1: color = getColor(lbl_72_rodata_78); break;
    }
    tev.GXSetTevColor(1, color);
    fn_80190A3C(&tev, false);
    mat.DCStore(false);
}