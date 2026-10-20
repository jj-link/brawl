#pragma force_active on
struct S {
    char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char e : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
};

extern "C" bool fn_125_10870(S* s) {
    return s->b;
}
