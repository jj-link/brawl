#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void** getInstance__12ntFriendInfoFv(void* self);

extern "C" u8 fn_800D21D0(void* arg0, s32 arg1) {
    u8 var_r3;

    var_r3 = ((u8*)(*getInstance__12ntFriendInfoFv(arg0)) + arg1 * 0x89)[0x609];
    if ((s32)var_r3 == 0) {
        var_r3 += 1;
    }
    return var_r3;
}
