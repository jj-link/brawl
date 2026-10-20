#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int flags : 6;
} Obj;

extern "C" void fn_27_122B28(Obj* p, unsigned int v) {
    p->flags = v;
}
