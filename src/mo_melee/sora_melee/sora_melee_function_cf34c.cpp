#pragma force_active on
typedef unsigned int u32;

struct Top6 {
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" {
void fn_27_CF34C(void *p, u32 v) {
    Top6 *w = (Top6 *)((char *)p + 8);
    w->hi = v;
}
}
