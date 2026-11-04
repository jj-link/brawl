#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <GX.h>
#pragma force_active on
using namespace nw4r::g3d;
union ColorWord { GXColor c; u32 w; };
struct Access { ScnMdl::CopiedMatAccess value; char pad[4]; Access(ScnMdl* obj, u32 id) : value(obj, id) {} };
extern "C" {
extern char lbl_66_data_2CD0[];
void fn_80190A3C(ResMatTevColor*, bool);
}
extern "C" void fn_66_F97C(unsigned char* self) {
    ResMdl mdl;
    ResMat mat;
    ResMatTevColor tev;
    ColorWord colA;
    ColorWord colB;
    colA.w = 0xffffffff;
    colB.w = 0xffffffff;
    ScnMdl* obj = **(ScnMdl***)(self + 0x44);
    if (!obj) return;
    mdl = ResMdl(*(void**)((unsigned char*)obj + 0xe8));
    if (!mdl.IsValid()) return;
    mat = mdl.GetResMat(lbl_66_data_2CD0);
    if (!mat.IsValid()) return;
    Access access(obj, mat.ptr()->m_id);
    tev = access.value.GetResMatTevColor(false);
    if (!tev.IsValid()) return;
    switch (*(unsigned char*)(*(unsigned char**)(self + 0x188) + 0xa)) {
    case 0:
        colA.c.r = 0x80; colA.c.g = 0; colA.c.b = 0; colA.c.a = 0xff;
        colB.c.r = 0x80; colB.c.g = 0; colB.c.b = 0; colB.c.a = 0xff;
        break;
    case 1:
        colA.c.r = 0; colA.c.g = 0; colA.c.b = 0x80; colA.c.a = 0xff;
        colB.c.r = 0; colB.c.g = 0; colB.c.b = 0x80; colB.c.a = 0xff;
        break;
    case 2:
        colA.c.r = 0x80; colA.c.g = 0x64; colA.c.b = 0; colA.c.a = 0xff;
        colB.c.r = 0x80; colB.c.g = 0x64; colB.c.b = 0; colB.c.a = 0xff;
        break;
    }
    tev.GXSetTevColor(1, colA.c);
    tev.GXSetTevColor(2, colB.c);
    fn_80190A3C(&tev, false);
    mat.DCStore(false);
}