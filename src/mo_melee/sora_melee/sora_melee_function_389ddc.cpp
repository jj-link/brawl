#pragma force_active on
struct FooBits {
    unsigned int pad0[2];
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int rest : 24;
};

extern "C" void fn_27_389DDC(FooBits* p, unsigned int v) {
    p->f = v;
}
