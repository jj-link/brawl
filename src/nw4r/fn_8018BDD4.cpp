#pragma force_active on

typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_80210A9C(s32 a, s32 b);
extern "C" s32 fn_80210EEC(s32 a, s32 b);
extern "C" s32 fn_8018BD08(s32 a, s32 b);
extern "C" s32 fn_80210A4C(s32 a, s32 b, s32 c);
extern "C" s32 fn_80210EC8(s32 a);
extern "C" s32 fn_80210EDC(s32 a);
extern "C" void fn_80210EE4(s32 a);
extern "C" char lbl_8059E8DC;

extern "C" s32 fn_8018BDD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    char buf[5];
    char out[12];
    s32 r31 = -1;

    s32 A = fn_80210A9C(arg0, arg1);
    if (A != -1) {
        s32 B = fn_80210EEC(arg0, arg1);
        if (B != 0) {
            if (arg2 == 0) {
                r31 = fn_8018BD08(arg0, arg3);
            } else {
                buf[0] = (char)((u32)arg2 >> 24);
                buf[1] = (char)((u32)arg2 >> 16);
                buf[2] = (char)((u32)arg2 >> 8);
                buf[3] = (char)arg2;
                buf[4] = 0;
                if (fn_80210A9C(arg0, (s32)&buf) == -1) goto bea4;
                if (fn_80210EEC(arg0, (s32)&buf) == 0) goto bea4;
                r31 = fn_80210A9C(arg0, arg3);
                fn_80210EEC(arg0, (s32)&lbl_8059E8DC);
            }
bea4:
            fn_80210EEC(arg0, (s32)&lbl_8059E8DC);
        }
    }
check:
    if (r31 != -1) {
        fn_80210A4C(arg0, r31, (s32)&out);
        s32 E = fn_80210EC8((s32)&out);
        if (arg4 != 0) {
            *(s32*)arg4 = fn_80210EDC((s32)&out);
        }
        fn_80210EE4((s32)&out);
        return E;
    }
    return 0;
}
