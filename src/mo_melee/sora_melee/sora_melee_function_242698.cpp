#pragma force_active on
extern "C" void fn_80073F84(void*, int);
extern void* g_sndSystem;

extern "C" void fn_27_242698(void* self) {
    unsigned char* bytes = (unsigned char*)self;
    void* snd = g_sndSystem;
    if (bytes[0x5d] != 0) {
        fn_80073F84(snd, 0x1e);
        bytes[0x5c] = 0;
        bytes[0x40] = 5;
    }
}
