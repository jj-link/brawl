#pragma force_active on
extern "C" int fn_800C9DF4(void* a, void* b);
extern "C" void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);

extern "C" void* g_muWifiInterfaceTask;
extern "C" void* g_sndSystem;

extern "C" int fn_2_3955C(void* self) {
    char* p = (char*)self;
    int result = fn_800C9DF4(g_muWifiInterfaceTask, p + 0x12c);
    if (result != 1) {
        *(int*)(p + 0x128) = 1;
        if (result == 2) {
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2050, -1, 0, 0, -1);
            *(int*)(p + 0x128) = 0;
        }
        return 6;
    }
    return *(int*)(p + 0x138);
}
