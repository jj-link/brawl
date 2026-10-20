#pragma force_active on
typedef unsigned int u32;

struct ObjField {
    char pad[8];
    u32 hi : 14;
    u32 mid : 7;
    u32 lo : 11;
};

extern "C" void fn_27_D0558(ObjField* obj, u32 v) {
    obj->mid = v;
}
