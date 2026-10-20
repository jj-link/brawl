#pragma force_active on
extern "C" {
struct Rec {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};
void fn_27_198104(Rec *r, unsigned int v) {
    r->b = v;
}
}
