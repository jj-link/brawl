#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags;
};

extern "C" {
void fn_72_BF24(Obj *p) {
    p->flags &= 0xFFBFFFFF;
}
}
