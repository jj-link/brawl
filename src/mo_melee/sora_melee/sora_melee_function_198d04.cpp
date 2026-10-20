#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int mode : 3;
    unsigned int rest : 29;
};

extern "C" {
void fn_27_198D04(Obj* p, unsigned int v) {
    p->mode = v;
}
}
