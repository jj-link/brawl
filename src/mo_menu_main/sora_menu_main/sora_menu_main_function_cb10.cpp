#pragma force_active on
extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" void Init__Q34nw4r3g3d7ResFileFPv(void*);
extern "C" void fn_2_A108(void*, int, int, void*);
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern "C" void release__14gfFileIOHandleFv(void*);
extern void* g_sndSystem;

extern "C" int fn_2_CB10(void* self) {
    char* p = (char*)self;
    if (!isReady__14gfFileIOHandleCFv(p + 0x290)) return 5;

    int i = *(int*)(p + 0x244);
    char* q = p + i * 4;
    int x = *(int*)(q + 0x2A0);
    *(int*)(q + 0xC4) = x;

    i = *(int*)(p + 0x244);
    q = p + i * 4;
    Init__Q34nw4r3g3d7ResFileFPv(q + 0xC4);

    i = *(int*)(p + 0x244);
    fn_2_A108(self, i, *(int*)(p + 0x248), p + i * 4 + 0xC4);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EE6, -1, 0, 0, -1);
    release__14gfFileIOHandleFv(p + 0x290);
    return 3;
}
