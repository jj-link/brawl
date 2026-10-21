#pragma force_active on
struct S {
    int x;
    char pad[0x54];
};

struct Obj {
    char pad[0xc8];
    S e[8];
};

extern "C" void fn_11_7B5C(Obj* obj) {
    S* p = obj->e;
    for (int i = 0; i < 8; i++) {
        if (p->x == 1) {
            p->x = 0;
        }
        ++p;
    }
}
