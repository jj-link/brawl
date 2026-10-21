#pragma force_active on
typedef int s32;

extern s32 fn_8035C660(s32 a, s32 b, s32* c, s32 d);

s32 CanSendOnSocket(s32 sock) {
    s32 sp8 = 0;
    if (fn_8035C660(sock, 0, &sp8, 0) == 1) {
        return sp8;
    }
    return 0;
}
