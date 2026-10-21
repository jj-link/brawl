#pragma force_active on
struct FnObj {
    int unk0;
    int unk4;
    int unk8;
    unsigned int flags;
};

extern "C" unsigned int fn_8019DA84(FnObj* obj, unsigned int mask) {
    unsigned int x = obj->flags & mask;
    return ((0u - x) | x) >> 31;
}
