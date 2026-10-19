#pragma force_active on
struct S {
    char pad[0x184];
    unsigned char a;
    int b;
    float c;
};

extern "C" void fn_60_6170(S* s, unsigned char a, int b, float c) {
    s->a = a;
    s->b = b;
    s->c = c;
}
