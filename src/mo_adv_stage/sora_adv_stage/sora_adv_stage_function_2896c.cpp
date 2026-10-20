#pragma force_active on
struct SadvObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" int fn_40_2896C(SadvObj* p) {
    return (int)((p->flags << 4) & 0xF8000000) >> 28;
}
