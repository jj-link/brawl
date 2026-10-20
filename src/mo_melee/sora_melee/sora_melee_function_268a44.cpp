#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags;
};

extern "C" {
void fn_27_268A44(Obj* p) {
    p->flags &= 0xFFFEFFFF;
}
}
