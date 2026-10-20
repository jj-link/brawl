#pragma force_active on
struct F {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_CAB7C(const F *p) {
    return p->c >> 26;
}
