#pragma force_active on
struct Obj {
    unsigned char pad[4];
    unsigned short a;
    short b;
};

extern "C" {
void fn_802F064C(struct Obj* p) {
    if (p->a != 0) {
        p->b = p->b + 1;
    }
}
}
