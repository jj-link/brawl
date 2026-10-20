#pragma force_active on
struct fnRec {
    char pad[8];
    int unk8;
};

extern "C" {
void* fn_27_1B023C(fnRec* p, int n) {
    int idx = (p->unk8 >> 26) + n;
    if (idx >= 0x19) {
        idx -= 0x19;
    }
    return (char*)p + (idx << 4) + 0xc;
}
}
