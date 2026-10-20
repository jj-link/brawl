#pragma force_active on
struct Fld {
    unsigned int a : 12;
    unsigned int f : 6;
    unsigned int b : 14;
};

extern "C" void fn_27_CF0A0(unsigned char *p, unsigned int v) {
    ((Fld *)(p + 8))->f = v;
}
