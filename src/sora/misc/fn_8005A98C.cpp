#pragma force_active on
struct FnObj {
    char pad[0xd];
    unsigned char flags;
};

extern "C" void fn_8005A98C(FnObj* obj) {
    obj->flags |= 0x80;
}
