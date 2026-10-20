#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int unk8;
};

extern "C" {
int fn_27_D3104(Obj* p) {
    unsigned int x = p->unk8;
    unsigned int r = (x << 2) | (x >> 30);
    return ((int)(r & 0xE0000000)) >> 30;
}
}
