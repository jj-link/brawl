#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" void* fn_8018F340(void*, unsigned long);

nw4r::g3d::ScnMdl::CopiedMatAccess::CopiedMatAccess(ScnMdl* mdl, u32 idx) {
    u32* out = reinterpret_cast<u32*>(this);
    u32* model = reinterpret_cast<u32*>(mdl);
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 0;
    out[7] = 0;
    out[8] = 0;
    out[9] = 0;
    out[10] = 0;
    out[11] = 0;
    out[12] = 0;
    s32 found = 0;
    if (mdl != 0) {
        ResMdl resource = mdl->m_resMdl;
        if (fn_8018F340(&resource, idx) != 0) {
            found = 1;
        }
    }
    if (found != 0) {
        m_scnMdl = mdl;
        m_MatID = idx;
        u32 p0 = model[83];
        if (p0 != 0) {
            out[2] = p0 + idx * 260;
        } else {
            out[2] = 0;
        }
        u32 p1 = model[84];
        if (p1 != 0) {
            out[3] = p1 + idx * 100;
        } else {
            out[3] = 0;
        }
        u32 p2 = model[85];
        if (p2 != 0) {
            out[4] = p2 + idx * 584;
        } else {
            out[4] = 0;
        }
        u32 p3 = model[86];
        if (p3 != 0) {
            out[5] = p3 + idx * 40;
        } else {
            out[5] = 0;
        }
        u32 p4 = model[87];
        if (p4 != 0) {
            out[6] = p4 + idx * 8;
        } else {
            out[6] = 0;
        }
        u32 p5 = model[88];
        if (p5 != 0) {
            out[7] = p5 + idx * 12;
        } else {
            out[7] = 0;
        }
        u32 p6 = model[89];
        if (p6 != 0) {
            out[8] = p6 + idx * 32;
        } else {
            out[8] = 0;
        }
        u32 p7 = model[90];
        if (p7 != 0) {
            out[9] = p7 + idx * 128;
        } else {
            out[9] = 0;
        }
        u32 p8 = model[91];
        if (p8 != 0) {
            out[10] = p8 + idx * 64;
        } else {
            out[10] = 0;
        }
        u32 p9 = model[92];
        if (p9 != 0) {
            out[11] = p9 + idx * 160;
        } else {
            out[11] = 0;
        }
        u32 p10 = model[93];
        if (p10 != 0) {
            out[12] = p10 + idx * 512;
        } else {
            out[12] = 0;
        }
    } else {
        m_MatID = idx;
        m_scnMdl = 0;
        out[2] = 0;
        out[3] = 0;
        out[4] = 0;
        out[5] = 0;
        out[6] = 0;
        out[7] = 0;
        out[8] = 0;
        out[9] = 0;
        out[10] = 0;
        out[11] = 0;
        out[12] = 0;
    }
}
