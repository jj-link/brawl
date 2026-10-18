#pragma force_active on
struct Obj {
    char pad[0x58];
    float a;
    float b;
    float c;
    float d;
};

extern float lbl_40_bss_170[4];

extern "C" {
float* fn_40_6FF4(Obj* o) {
    float d;
    float t;
    float* p = lbl_40_bss_170;
    float c;

    p[0] = o->a;
    p[1] = o->b;
    c = o->c;
    p[2] = c;
    d = o->d;
    t = c - d;
    p[2] = c + t;
    p[3] = d - t;
    return p;
}
}
