#pragma force_active on
extern "C" {
struct Flags32 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};
}

extern "C" unsigned int fn_27_198688(Flags32* obj) {
    return (obj->flags >> 0x13) & 1;
}
