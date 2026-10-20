#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void* fn_27_385B78(Obj* p, int idx) {
    int n = (p->unk8 >> 22) + idx;
    if (n >= 0x12b) {
        n -= 0x12b;
    }
    return (char*)p + (n << 2) + 0xc;
}
}
