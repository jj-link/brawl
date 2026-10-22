#pragma force_active on
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern void* g_sndSystem;
extern char lbl_8059E5C4;

extern "C" void fn_80105C1C(char* arg0) {
    int cur = *(int*)(arg0 + 0x28);
    int flags = *(int*)(arg0 + 0x44);
    int v = cur;
    if (flags & 2) {
        v = cur + 1;
        if (v >= 1000) {
            v = 0;
        }
    }
    if (flags & 1) {
        v -= 1;
        if (v < 0) {
            v = 999;
        }
    }
    if (v != cur) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        *(int*)(arg0 + 0x28) = v;
        printf__5MuMsgFUlPCce(*(void**)(arg0 + 0xC), 4, &lbl_8059E5C4, v);
    }
}
