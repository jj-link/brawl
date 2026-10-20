#pragma force_active on
struct Elem {
    int a;
    int b;
    int c;
};

struct Obj {
    char pad[0x18];
    int flags;
    Elem table[30];
};

extern "C" {
Elem* fn_27_294980(Obj* p, int idx) {
    int i = (p->flags >> 26) + idx;
    if (i >= 30) {
        i -= 30;
    }
    return &p->table[i];
}
}
