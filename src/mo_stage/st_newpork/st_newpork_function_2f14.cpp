#pragma force_active on
struct S {
    char pad[0x6c];
    unsigned char a : 4;
    unsigned char b : 1;
    unsigned char c : 3;
};

extern "C" unsigned int fn_69_2F14(S* s) {
    return s->b;
}
