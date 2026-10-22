#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_8027DD18(s32);
extern "C" s32 fn_8027DD5C(s32, s32);
extern "C" s32 fn_8027DD78(s32, s32);
extern "C" s32 fn_8027DD98(s32, s32);
extern "C" u32 fn_8027DDE0(s32, s32);
extern "C" void fn_8027DDFC(s32, s32, s32);

extern "C" void fn_80332A0C(s32 arg0, s32 arg1) {
    s32 v;
    s32 idx = fn_8027DD18(arg1 + 8);
    while ((signed char)(fn_8027DDE0(arg1 + 8, idx) >> 24) != 0) {
        v = fn_8027DD78(arg1 + 8, idx);
        fn_8027DDFC(arg0 + 8, fn_8027DD5C(arg1 + 8, idx), v);
        idx = fn_8027DD98(arg1 + 8, idx);
    }
}
