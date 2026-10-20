#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void* fn_27_1B078C(Obj* p, int n) {
    int i = (p->unk8 >> 29) + n;
    if (i >= 3) {
        i -= 3;
    }
    return (char*)p + i * 0x24 + 0xC;
}
}
