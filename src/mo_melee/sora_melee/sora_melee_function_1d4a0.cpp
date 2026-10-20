#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int flag : 2;
};

extern "C" void fn_27_1D4A0(Obj* p, unsigned int v) {
    p->flag = v;
}
