#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int field : 10;
};

extern "C" {
void fn_27_1A6330(Obj* p, unsigned int v) {
    p->field = v;
}
}
