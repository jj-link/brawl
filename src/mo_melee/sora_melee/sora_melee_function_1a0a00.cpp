#pragma force_active on
struct FooBits {
    unsigned int pad[2];
    unsigned int field : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_1A0A00(FooBits* p, unsigned int v) {
    p->field = v;
}
