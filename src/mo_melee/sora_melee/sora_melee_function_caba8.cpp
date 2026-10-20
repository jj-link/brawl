#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    u32 unk0;
    u32 unk4;
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_CABA8(FieldHolder* p, u32 v) {
    p->b = v;
}
