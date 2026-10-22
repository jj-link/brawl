#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A45C4;

struct Mtx {
    float m[3][4];
    float v[4];
};

struct Obj {
    unsigned char pad[0x20];
    Mtx in;
    unsigned char pad2[0x60];
    float row3[4];
    float row4[4];
};

extern "C" void fn_803063A4(Obj* o)
{
    const float* t = o->in.v;
    const float* r0 = o->in.m[0];
    const float* r1 = o->in.m[1];
    const float* r2 = o->in.m[2];

    o->row3[0] = t[0];
    o->row3[1] = t[1];
    o->row3[2] = t[2];
    o->row3[3] = t[3];
    o->row4[0] = t[2] * r0[2] + (t[0] * r0[0] + t[1] * r0[1]);
    o->row4[1] = t[2] * r1[2] + (t[0] * r1[0] + t[1] * r1[1]);
    o->row4[2] = t[2] * r2[2] + (t[0] * r2[0] + t[1] * r2[1]);
    o->row4[3] = lbl_805A45C4;
}
