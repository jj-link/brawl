#pragma force_active on
typedef unsigned int u32;

struct FlagWord {
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" void fn_27_CECEC(void* p, u32 v) {
    FlagWord* w = (FlagWord*)((char*)p + 8);
    w->hi = v;
}
