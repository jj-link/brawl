#pragma force_active on
struct S50 {
    unsigned char a : 4;
    unsigned char b : 1;
    unsigned char c : 3;
};

extern "C" void fn_41_2B894(S50* p, int v) {
    p[0x50].b = v;
}
