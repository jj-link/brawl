#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 4;
    signed int v : 2;
    unsigned int rest : 26;
};

extern "C" {
int fn_40_24A44(Obj* obj) {
    return obj->v;
}
}
