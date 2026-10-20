#pragma force_active on
typedef unsigned int u32;

struct FE43CObj {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" {
void fn_27_FE43C(FE43CObj* obj, u32 val) {
    obj->b = val;
}
}
