#pragma force_active on
struct S {
    unsigned char pad[0x150];
    int a;
    int pad2;
    int b;
};

extern "C" {
void fn_27_150D28(S* p) {
    p->a = p->b - 1;
}
}
