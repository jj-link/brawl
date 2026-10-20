#pragma force_active on
typedef struct Obj {
    int f0;
    int f4;
    int f8;
} Obj;

extern "C" {
void* fn_27_1B0A58(Obj* p, int idx) {
    int i = (p->f8 >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (char*)p + i * 20 + 12;
}
}
