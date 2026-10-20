#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Fn27Obj {
    u8 pad[8];
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_D2B18(Fn27Obj* obj, u32 val) {
    obj->hi = val;
}
