#pragma force_active on
#include <string.h>
#include <gf/gf_pad_system.h>

extern "C" int fn_800BA3D8(void*);

struct PadStatusBuf {
    unsigned int w[16];
};

extern "C" void fn_40_3F2B8(PadStatusBuf* out, void* base, int index) {
    PadStatusBuf status;
    int port = fn_800BA3D8((char*)base + index * 0x150 + 0x970);
    if (port >= 0) {
        g_gfPadSystem->getSysPadStatus(port, (gfPadStatus*)&status);
    } else {
        memset(&status, 0, 0x40);
    }
    *out = status;
}
