#pragma force_active on
typedef unsigned int u32;

struct Holder {
    u32 unk0;
    u32 unk4;
    u32 hi : 2;
    u32 rest : 30;
};

extern "C" void fn_27_19C288(Holder* p, u32 v) {
    p->hi = v;
}
