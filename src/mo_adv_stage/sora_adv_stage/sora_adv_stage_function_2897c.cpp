#pragma force_active on
extern "C" void fn_40_2897C(unsigned int* p, unsigned int v) {
    struct Bits {
        unsigned int hi : 4;
        unsigned int f : 4;
        unsigned int lo : 24;
    };
    ((Bits*)&p[2])->f = v;
}
