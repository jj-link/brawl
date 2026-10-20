#pragma force_active on
struct fn_27_Obj {
    char pad[8];
    int unk8;
};

extern "C" {
void* fn_27_1B0B48(fn_27_Obj* p, int idx) {
    int i = (p->unk8 >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)p + i * 4 + 12;
}
}
