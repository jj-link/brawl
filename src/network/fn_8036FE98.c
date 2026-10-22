#pragma force_active on
typedef int s32;

s32 fn_8036E618(s32, s32, s32);
s32 fn_8036ED64(s32, s32, s32, void **, s32, s32, s32);

s32 fn_8036FE98(s32 arg0, s32 *arg1) {
    void *sp8;
    s32 ret;

    ret = fn_8036ED64(arg0, 2, 0, &sp8, 0, 0, 0);
    if (ret != 0) {
        return ret;
    }
    ret = fn_8036E618(arg0, arg1[3], ((s32 *)sp8)[6]);
    if (ret != 0) {
        return ret;
    }
    arg1[0] = 0x65;
    return 0;
}
