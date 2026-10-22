#pragma force_active on

struct PadStatusBuf {
    unsigned int w[16];
};

extern "C" void* g_gfPadSystem;
extern "C" void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, int port, PadStatusBuf* status);

extern "C" void fn_800F0250(PadStatusBuf* dst, unsigned char* src)
{
    PadStatusBuf sp;
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, src[0x48], &sp);
    *dst = sp;
}
