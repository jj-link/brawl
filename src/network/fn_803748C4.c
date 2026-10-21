#pragma force_active on
typedef int s32;

extern s32 fn_80376DF4(void);
extern s32 fn_803786FC(s32);
extern void fn_80378748(s32);

void fn_803748C4(s32 arg0) {
    if (fn_80376DF4() != 0) {
        if (fn_803786FC(arg0) != 0) {
            fn_80378748(arg0);
        }
    }
}
