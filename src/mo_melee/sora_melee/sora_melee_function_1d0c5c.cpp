#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 unk0;
    u32 unk4;
    u32 field : 7;
    u32 rest : 25;
};

extern "C" void fn_27_1D0C5C(void* p, u32 v) {
    FnBits* obj = (FnBits*)p;
    obj->field = v;
}
