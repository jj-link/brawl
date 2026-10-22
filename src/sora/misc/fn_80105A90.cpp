#pragma force_active on
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern void* g_sndSystem;
extern char lbl_8059E5C4;

extern "C" void fn_80105A90(char* arg0) {
    int old = *(int*)(arg0 + 0x20);
    unsigned f = *(unsigned*)(arg0 + 0x44);
    int v = old;
    if (f & 2) {
        v = old + 1;
        if (v >= 4) v = 1;
    }
    if (f & 1) {
        v = v - 1;
        if (v < 1) v = 3;
    }
    if (v != old) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        *(int*)(arg0 + 0x20) = v;
        printf__5MuMsgFUlPCce(*(void**)(arg0 + 0xC), 2, &lbl_8059E5C4, v);
    }
}
