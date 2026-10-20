#pragma force_active on
typedef struct Obj {
    int pad[2];
    int field8;
} Obj;

extern "C" char* fn_27_1E7E9C(Obj* p, int idx) {
    int i = (p->field8 >> 28) + idx;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)p + i * 12 + 12;
}
