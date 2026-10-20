#pragma force_active on
struct Fn27Bits {
    unsigned char pad[8];
    unsigned int top : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_124DB0(Fn27Bits* p, unsigned int v) {
    p->top = v;
}
