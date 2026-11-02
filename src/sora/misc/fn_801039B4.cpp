#pragma force_active on
extern "C" void fn_80016900(void* app, unsigned int flag, unsigned int value);
extern "C" void fn_80103A7C(void* self);
extern "C" int fn_801063BC(void);
extern "C" int fn_80106548(void);
extern "C" void setBGMVol__9sndSystemFbf(void* sys, bool on, float vol);
extern "C" void* g_gfApplication;
extern "C" void* g_sndSystem;
extern "C" float lbl_805A2794;

extern "C" void fn_801039B4(unsigned char* self) {
    if (self[0x1B5] != 0) {
        if ((*(unsigned int*)((unsigned char*)g_gfApplication + 0xEC) >> 27) != 0) {
            unsigned char b;
            unsigned char* p = *(unsigned char**)(self + 0x32C);
            b = p[0x100];
            if (!((b >> 7) & 1)) {
                if (!((b >> 6) & 1)) {
                    fn_80016900(g_gfApplication, 0, 0);
                    setBGMVol__9sndSystemFbf(g_sndSystem, true, lbl_805A2794);
                } else {
                    int r;
                    if (p == 0 || ((b >> 7) & 1) || !((b >> 6) & 1)) {
                        r = 0;
                    } else {
                        fn_801063BC();
                        r = fn_80106548();
                    }
                    if (r != 0) {
                        fn_80016900(g_gfApplication, 0, 0);
                    }
                }
            }
        }
        fn_80103A7C(self);
    }
}
