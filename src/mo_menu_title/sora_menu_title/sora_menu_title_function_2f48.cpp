#include <types.h>
#pragma force_active on

class gfPadSystem;
class gfPadStatus;

struct gfPadStatus {
    u8 data[0x40];
};

class gfPadSystem {
public:
    void getSysPadStatus(int port, gfPadStatus* status);
};

extern gfPadSystem* g_gfPadSystem;

extern "C" {
void fn_24_2F48(gfPadStatus* status) {
    gfPadStatus* p = status;
    gfPadStatus* q = status + 4;
    for (int i = 0; i < 4; i++) {
        g_gfPadSystem->getSysPadStatus(i, p);
        g_gfPadSystem->getSysPadStatus(i + 4, q);
        p++;
        q++;
    }
}
}
