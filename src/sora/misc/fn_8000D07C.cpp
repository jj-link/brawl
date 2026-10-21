#pragma force_active on
struct S {
    unsigned char pad[0x464];
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
};

extern "C" void fn_8000D07C(S* s, int v) {
    s->b0 = (v == 0);
}
