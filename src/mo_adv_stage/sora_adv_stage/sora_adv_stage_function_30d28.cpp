#pragma force_active on
extern "C" {
struct Fn40Rec {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 5;
    unsigned int b : 5;
    unsigned int c : 22;
};
void fn_40_30D28(Fn40Rec* p, unsigned int x) {
    p->b = x;
}
}
