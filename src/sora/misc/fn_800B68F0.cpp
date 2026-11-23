#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_resnode.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <nw4r/math/math_arithmetic.h>
#include <ut/ut_nw.h>
#pragma force_active on

struct Owner {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* scn;
};

extern "C" void nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(Vec3f*, const nw4r::g3d::ScnMdlSimple*, u32);

inline f32 upper(f32 by, f32 ay) {
    return nw4r::math::FSelect(by - ay, by, ay);
}
inline f32 lower(f32 by, f32 ay) {
    return nw4r::math::FSelect(by - ay, ay, by);
}

inline void setBounds(f32* out, const Vec3f& b, const Vec3f& a) {
    f32 ax = a.m_x;
    f32 bx = b.m_x;
    f32 by = b.m_y;
    out[0] = nw4r::math::FSelect(ax - bx, bx, ax);
    out[1] = nw4r::math::FSelect(ax - bx, ax, bx);
    out[2] = upper(by, a.m_y);
    out[3] = lower(by, a.m_y);
}

extern "C" void fn_800B68F0(Owner* arg0, f32* arg1, const char* arg2, const char* arg3) {
    nw4r::g3d::ResMdl mdl = arg0->scn->m_resMdl;
    nw4r::g3d::ResNode nodeA = mdl.GetResNode(arg2);
    nw4r::g3d::ResNode nodeB = mdl.GetResNode(arg3);
    u32 idxB = nodeB.IsValid() ? nodeB->m_nodeIndex : 0;
    Vec3f tmpB;
    Vec3f tmpA;
    Vec3f b;
    Vec3f a;
    nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(&tmpA, arg0->scn, nodeA.IsValid() ? nodeA->m_nodeIndex : 0);
    a = tmpA;
    nwSMGetGlobalPosition__FPCQ34nw4r3g3d12ScnMdlSimpleUl(&tmpB, arg0->scn, idxB);
    b = tmpB;
    setBounds(arg1, b, a);
}
