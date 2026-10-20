#pragma force_active on
typedef unsigned int u32;

struct FnData {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 field : 6;
    u32 lo : 20;
};

extern "C" void fn_27_CED0C(FnData* p, u32 v) {
    p->field = v;
}
