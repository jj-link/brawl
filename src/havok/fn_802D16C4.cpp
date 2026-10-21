#pragma force_active on

struct SVec {
    float v[4];
};

struct Owner {
    char pad[0x30];
    SVec* v;
};

extern const float lbl_805A40B8;

extern "C" void fn_802D16C4(Owner* o, float* out) {
    out[0] = o->v[0].v[0];
    out[1] = o->v[1].v[0];
    out[2] = o->v[2].v[0];
    out[3] = lbl_805A40B8;
}
