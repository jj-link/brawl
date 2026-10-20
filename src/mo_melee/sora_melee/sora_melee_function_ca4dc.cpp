#pragma force_active on
struct Bits {
    unsigned long pad0;
    unsigned long pad1;
    unsigned long hi : 5;
    unsigned long f : 5;
    unsigned long rest : 22;
};

extern "C" void fn_27_CA4DC(Bits* p, unsigned long v) {
    p->f = v;
}
