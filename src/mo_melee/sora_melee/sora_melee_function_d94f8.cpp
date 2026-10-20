#pragma force_active on
struct FooHeader {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" char* fn_27_D94F8(FooHeader* p, int idx) {
    int v = (p->unk8 >> 26) + idx;
    if (v >= 25) {
        v -= 25;
    }
    return (char*)p + 0xC + v * 0x30;
}
