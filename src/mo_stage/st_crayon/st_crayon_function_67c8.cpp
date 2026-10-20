#pragma force_active on
struct UnkStruct {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int flags;
};

extern "C" void fn_56_67C8(UnkStruct* p) {
    p->flags |= 0x80000;
}
