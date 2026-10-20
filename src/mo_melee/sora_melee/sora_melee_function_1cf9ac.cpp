#pragma force_active on
struct Fn27Obj {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int top : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_1CF9AC(Fn27Obj* p, unsigned int v) {
    p->top = v;
}
