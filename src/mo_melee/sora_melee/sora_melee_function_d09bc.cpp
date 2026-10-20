#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int hi : 7;
    unsigned int mid : 7;
    unsigned int lo : 18;
};

extern "C" void fn_27_D09BC(Obj *o, unsigned int v) {
    o->mid = v;
}
