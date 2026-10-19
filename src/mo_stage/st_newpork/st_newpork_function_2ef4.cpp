#pragma force_active on
struct S {
    char pad[0x6c];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

extern "C" void fn_69_2EF4(S* s) {
    s->b4 = 0;
}
