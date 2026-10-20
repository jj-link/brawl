#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_1D07A4(Obj* obj) {
    obj->flags &= ~0x00080000;
}
