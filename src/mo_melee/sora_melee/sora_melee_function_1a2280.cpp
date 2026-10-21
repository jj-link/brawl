#pragma force_active on

struct Obj {
    unsigned int pad[2];
    unsigned int field : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_1A2280(Obj* p, unsigned v) {
    p->field = v;
}
