#pragma force_active on
struct Obj57 {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_57_3A6C(Obj57* obj) {
    obj->flags |= 8;
}
