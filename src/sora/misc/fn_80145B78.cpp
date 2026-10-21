#pragma force_active on
struct FnObj3E {
    char pad[0x3e];
    unsigned char flags;
};

extern "C" void fn_80145B78(FnObj3E* obj) {
    obj->flags |= 0x40;
}
