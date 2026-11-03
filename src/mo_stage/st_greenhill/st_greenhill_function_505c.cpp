#pragma force_active on
struct FnObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" unsigned int fn_72_505C(const FnObj *obj) {
    return (obj->flags >> 25) & 1u;
}
