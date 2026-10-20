#pragma force_active on
struct FlagObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_2960E0(FlagObj* obj) {
    obj->flags |= 0x2000;
}
