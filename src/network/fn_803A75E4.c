#pragma force_active on
typedef int s32;
extern int SORecvFrom(int, s32, s32, s32, s32, int);

void fn_803A75E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    SORecvFrom(0, arg0, arg1, arg2, arg3, 0);
}
