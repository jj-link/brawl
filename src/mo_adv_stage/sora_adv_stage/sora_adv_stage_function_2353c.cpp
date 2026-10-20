#pragma force_active on
struct FnObj40 {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_40_2353C(FnObj40* obj) {
    obj->flags |= 2;
}
