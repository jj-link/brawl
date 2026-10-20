#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 10;
    u32 mid : 10;
    u32 lo : 12;
};

extern "C" {
void fn_27_1A6B70(Obj* obj, u32 val) {
    obj->mid = val;
}
}
