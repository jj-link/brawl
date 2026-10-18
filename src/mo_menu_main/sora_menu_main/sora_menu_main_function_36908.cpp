#pragma force_active on
struct J2DPan_0298 { int v[2]; };

struct Unknown_0169 { J2DPan_0298* pan; };

extern "C" int fn_2_36908(Unknown_0169* arg0)
{
    J2DPan_0298* p = *(J2DPan_0298**)((char*)arg0 + 0x48);
    return p->v[1];
}
