#pragma force_active on
struct Fn27Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int hi : 6;
    unsigned int field : 3;
    unsigned int lo : 23;
};

extern "C" void fn_27_19CDC0(Fn27Obj* p, unsigned int v) {
    p->field = v;
}
