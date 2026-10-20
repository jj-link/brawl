#pragma force_active on
typedef unsigned int u32;

struct ScBits {
    int unk0;
    u32 unk4;
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" {
void fn_27_385AF4(ScBits* p, u32 v) {
    p->hi = v;
}
}
