#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int mode : 4;
    unsigned int rest : 28;
};

extern "C" void fn_40_2895C(Obj* obj, unsigned int v) {
    obj->mode = v;
}
