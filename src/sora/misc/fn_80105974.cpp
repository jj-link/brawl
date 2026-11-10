#pragma force_active on

extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
extern "C" int fn_800AFA04(int);
extern "C" int fn_800AFA1C(int);
extern void* g_sndSystem;

extern "C" void fn_80105974(char* s) {
    int flags = *(int*)(s + 0x44);
    int old = *(int*)(s + 0x1C);
    int v = old;
    int bits = *(int*)(s + 0x40);
    int count = *(int*)(s + 0x2EC);
    if (flags & 2) {
        v = old + 1;
        if (v >= count) v = 0;
    }
    if (flags & 1) {
        v -= 1;
        if (v < 0) v = count - 1;
    }
    if (v != old) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        *(int*)(s + 0x1C) = v;
        int idx;
        if (v < 0 || v >= *(int*)(s + 0x2EC)) {
            idx = 56;
        } else {
            idx = *(int*)(s + 0xEC + v * 4);
        }
        printIndex__5MuMsgFUlUlPv(*(void**)(s + 0xC), 1, fn_800AFA04(idx), *(void**)(s + 0x10));
    }
    if (bits & 0x100) {
        int cur = *(int*)(s + 0x1C);
        int idx2;
        if (cur < 0 || cur >= *(int*)(s + 0x2EC)) {
            idx2 = 56;
        } else {
            idx2 = *(int*)(s + 0xEC + cur * 4);
        }
        *(int*)(s + 0x2F0) = fn_800AFA1C(idx2);
    }
}
