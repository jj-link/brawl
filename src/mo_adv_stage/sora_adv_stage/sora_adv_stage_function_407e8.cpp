#pragma force_active on
struct FlagObj {
    int unk0;
    int unk4;
    int unk8;
    unsigned int flags;
};

extern "C" int fn_40_407E8(FlagObj* obj, unsigned int mask) {
    return (obj->flags & mask) != 0;
}
