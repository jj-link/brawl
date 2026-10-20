#pragma force_active on
struct S {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" {
void fn_27_A1B28(unsigned char* self, unsigned int v) {
    S* s = (S*)(self + 8);
    s->b = v;
}
}
