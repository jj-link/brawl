#pragma force_active on

typedef int s32;

extern int SORecvFrom(int, s32, s32, s32, s32, s32);

void fn_803A75BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    SORecvFrom(0, arg0, arg1, arg2, arg3, arg4);
}
