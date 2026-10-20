#pragma force_active on
struct S {
    char pad[0x45];
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

extern "C" void fn_41_27740(S* s, int v) {
    s->b0 = v;
}
