#pragma force_active on
typedef unsigned int u32;

struct Obj1A6894 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A6894(Obj1A6894* p) {
    p->flags &= 0xFFFFFFFDu;
}
