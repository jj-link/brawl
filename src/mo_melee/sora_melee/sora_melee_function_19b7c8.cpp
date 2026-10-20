#pragma force_active on
struct FnObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_19B7C8(FnObj* obj) {
    obj->flags &= ~0x2000;
}
}
