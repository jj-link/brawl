#pragma force_active on

typedef signed char s8;
typedef signed int s32;

extern "C" {
    s32 fn_803517BC(s32, s32);
    char* getFriendInfo__12ntFriendInfoFv(void*);
    void* getInstance__12ntFriendInfoFv();
    extern s32 g_NtAIDBitmap;
    extern s32 g_muWifiInterfaceTask;
}

extern "C" s32 fn_8014859C(void* arg0, unsigned int arg1) {
    s32 task = g_muWifiInterfaceTask;
    s32 friendInfo = (s32)getFriendInfo__12ntFriendInfoFv(getInstance__12ntFriendInfoFv());

    if (arg1 > 4) {
        return -1;
    }
    if (!(g_NtAIDBitmap & (1 << arg1))) {
        return -1;
    }

    task += arg1 * 0x218;
    s32 val248 = *(s32*)(task + 0x248);
    s32 val24c = *(s32*)(task + 0x24c);

    s32 ptr1 = friendInfo + 0x10;
    s32 ptr2 = friendInfo + 0x50;
    s32 i = 0;

    do {
        s32 result = fn_803517BC(ptr1, ptr2);
        s32 signBit = (s32)(result >> 31);
        if (((result ^ val24c) | (signBit ^ val248)) == 0) {
            break;
        }
        i++;
        ptr2 += 0xC;
    } while (i < 0x40);

    if (i >= 0x40) {
        i = -1;
    }
    *(s8*)(task + 0x281) = (s8)i;
    return i;
}