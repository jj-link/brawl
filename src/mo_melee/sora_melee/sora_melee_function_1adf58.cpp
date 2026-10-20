#pragma force_active on
struct Obj27 {
    char pad[0x18];
    int unk18;
};

extern "C" {
void* fn_27_1ADF58(Obj27* p, int idx) {
    int i = (p->unk18 >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return (char*)p + i * 12 + 0x1c;
}
}
