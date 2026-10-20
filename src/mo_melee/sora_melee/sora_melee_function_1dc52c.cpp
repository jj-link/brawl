#pragma force_active on
struct S1 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    float d;
};

struct S2 {
    unsigned int a;
    float b;
};

extern "C" void fn_27_1DC52C(S1* p, S2* q) {
    p->d = p->d * q->b;
}
