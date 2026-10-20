#pragma force_active on
typedef signed char s8;

struct S {
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char pad[0xb];
    s8 c;
    s8 d;
};

extern "C" void fn_27_9F52C(S* p) {
    p->flag = 0;
    p->c = -1;
    p->d = -1;
}
