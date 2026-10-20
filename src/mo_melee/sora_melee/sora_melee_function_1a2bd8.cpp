#pragma force_active on
struct S27Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
};

struct S27 {
    int pad0;
    int pad1;
    struct S27Bits word8;
};

extern "C" {
void fn_27_1A2BD8(struct S27* s, unsigned int v)
{
    s->word8.b = v;
}
}
