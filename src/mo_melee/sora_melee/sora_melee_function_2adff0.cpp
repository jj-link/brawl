#pragma force_active on
struct S {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    unsigned char pad[7];
    signed char a;
    signed char b;
};

extern "C" void fn_27_2ADFF0(S* s) {
    s->b0 = 0;
    s->a = -1;
    s->b = -1;
}
