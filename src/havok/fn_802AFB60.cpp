#pragma force_active on
typedef signed int s32;

extern "C" void fn_802AF7D0(s32, s32, s32, s32);

extern "C" void fn_802AFB60(s32 unused, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_802AF7D0(arg1, arg2, arg3, arg4);
}
