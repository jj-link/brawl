#pragma force_active on
struct Obj {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int flags;
};

extern "C" void fn_50_6380(Obj* obj) {
    obj->flags |= 0x02000000;
}
