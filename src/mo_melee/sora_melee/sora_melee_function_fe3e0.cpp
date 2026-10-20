#pragma force_active on
typedef unsigned int u32;

struct FlagObject {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_FE3E0(FlagObject* obj) {
    obj->flags |= 0x02000000;
}
