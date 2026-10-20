#pragma force_active on
struct Elem {
    int a;
    int b;
    int c;
};

struct Obj {
    char pad[0x18];
    int field;
};

extern "C" Elem* fn_27_2EAC50(Obj* p, int idx) {
    int i = (p->field >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (Elem*)((char*)p + 0x1c + i * 12);
}
