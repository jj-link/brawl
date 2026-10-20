#pragma force_active on
struct fn_27_1A65BC_Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int hi : 20;
    unsigned int f : 10;
    unsigned int lo : 2;
};

extern "C" {
void fn_27_1A65BC(fn_27_1A65BC_Obj* p, unsigned int v) {
    p->f = v;
}
}
